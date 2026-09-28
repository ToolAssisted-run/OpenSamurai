// DOS executables (MZ, and Microsoft EXEPACK's compressed ones, as all of the game's programs are) loaded into
// the emulated megabyte as DOS loads them: the image at a segment, its relocations applied for it.
#include "exe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dsimage.h"

static uint16_t rd16(const uint8_t *p) { return (uint16_t)(p[0] | (p[1] << 8)); }

static uint8_t *read_file(const char *path, size_t *len)
{
  FILE *f = fopen(path, "rb");
  if (!f) return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *d = n > 0 ? malloc((size_t)n) : NULL;
  if (d && fread(d, 1, (size_t)n, f) != (size_t)n)
  {
    free(d);
    d = NULL;
  }
  fclose(f);
  *len = d ? (size_t)n : 0;
  return d;
}

static void relocate(uint16_t seg, uint16_t off, uint16_t relSeg, uint16_t base)
{
  uint8_t *p = far_ptr((uint16_t)(base + relSeg), off);
  uint16_t v = (uint16_t)(rd16(p) + base);
  p[0] = (uint8_t)v;
  p[1] = (uint8_t)(v >> 8);
  (void)seg;
}

// EXEPACK: the packed image is undone from its end backwards (runs of one byte, runs copied), the relocations
// follow the unpacker's code as 16 lists of offsets, one for each 64 KB of the image
static bool unpack(const uint8_t *img, size_t imgLen, uint16_t cs, uint16_t seg, ExeInfo *info)
{
  size_t ep = (size_t)cs * 16;
  if (ep + 18 > imgLen) return false;
  const uint8_t *h = img + ep;
  if (h[16] != 'R' || h[17] != 'B') return false;
  uint16_t realIp = rd16(h), realCs = rd16(h + 2), exepackSize = rd16(h + 6), realSp = rd16(h + 8), realSs = rd16(h + 10);
  uint16_t destLen = rd16(h + 12);
  (void)exepackSize;
  size_t si = ep;
  while (si > 0 && img[si - 1] == 0xFF) si--;  // the padding
  size_t outLen = (size_t)destLen * 16, di = outLen;
  uint8_t *out = calloc(1, outLen);
  for (;;)
  {
    if (si < 3) goto bad;
    uint8_t cmd = img[--si];
    size_t len = (size_t)img[si - 1] << 8;
    len |= img[si - 2];
    si -= 2;
    if ((cmd & 0xFE) == 0xB0)  // fill
    {
      if (si < 1 || di < len) goto bad;
      uint8_t b = img[--si];
      di -= len;
      memset(out + di, b, len);
    }
    else if ((cmd & 0xFE) == 0xB2)  // copy
    {
      if (si < len || di < len) goto bad;
      di -= len;
      si -= len;
      memmove(out + di, img + si, len);
    }
    else goto bad;
    if (cmd & 1) break;
  }
  if (di != si) goto bad;
  memcpy(out, img, si);  // the rest is as it was
  // the relocation lists follow the unpacker's error message
  static const char msg[] = "Packed file is corrupt";
  size_t p = ep;
  while (p + sizeof msg - 1 <= imgLen && memcmp(img + p, msg, sizeof msg - 1)) p++;
  if (p + sizeof msg - 1 > imgLen) goto bad;
  p += sizeof msg - 1;
  for (uint32_t k = 0; k < outLen; k++) *far_ptr((uint16_t)(seg + (k >> 4)), (uint16_t)(k & 15)) = out[k];
  for (int s = 0; s < 16; s++)
  {
    if (p + 2 > imgLen) goto bad;
    uint16_t n = rd16(img + p);
    p += 2;
    for (uint16_t k = 0; k < n; k++, p += 2)
    {
      if (p + 2 > imgLen) goto bad;
      relocate(seg, rd16(img + p), (uint16_t)(s * 0x1000), seg);
    }
  }
  free(out);
  info->cs = (uint16_t)(realCs + seg);
  info->ip = realIp;
  info->ss = (uint16_t)(realSs + seg);
  info->sp = realSp;
  info->imageParagraphs = destLen;
  return true;
bad:
  free(out);
  return false;
}

bool exe_load(const char *path, uint16_t seg, ExeInfo *info)
{
  size_t len;
  uint8_t *d = read_file(path, &len);
  if (!d) return false;
  bool ok = false;
  if (len >= 0x1C && d[0] == 'M' && d[1] == 'Z')
  {
    uint16_t lastPage = rd16(d + 2), pages = rd16(d + 4), nrel = rd16(d + 6), hdrPar = rd16(d + 8);
    size_t hdr = (size_t)hdrPar * 16, total = (size_t)pages * 512 - (lastPage ? 512 - lastPage : 0);
    if (total > len) total = len;
    if (hdr <= total)
    {
      const uint8_t *img = d + hdr;
      size_t imgLen = total - hdr;
      info->minAlloc = rd16(d + 10);
      info->maxAlloc = rd16(d + 12);
      uint16_t cs = rd16(d + 0x16);
      if (nrel == 0 && (size_t)cs * 16 + 18 <= imgLen && img[cs * 16 + 16] == 'R' && img[cs * 16 + 17] == 'B')
        ok = unpack(img, imgLen, cs, seg, info);
      else
      {
        for (size_t k = 0; k < imgLen; k++) *far_ptr((uint16_t)(seg + (k >> 4)), (uint16_t)(k & 15)) = img[k];
        size_t r = rd16(d + 0x18);
        for (uint16_t k = 0; k < nrel && r + 4 * k + 4 <= len; k++)
          relocate(seg, rd16(d + r + 4 * k), rd16(d + r + 4 * k + 2), seg);
        info->cs = (uint16_t)(cs + seg);
        info->ip = rd16(d + 0x14);
        info->ss = (uint16_t)(rd16(d + 0x0E) + seg);
        info->sp = rd16(d + 0x10);
        info->imageParagraphs = (uint16_t)((imgLen + 15) / 16);
        ok = true;
      }
    }
  }
  free(d);
  return ok;
}

bool raw_load(const char *path, uint16_t seg, uint32_t *bytes)
{
  size_t len;
  uint8_t *d = read_file(path, &len);
  if (!d) return false;
  for (size_t k = 0; k < len; k++) *far_ptr((uint16_t)(seg + (k >> 4)), (uint16_t)(k & 15)) = d[k];
  free(d);
  if (bytes) *bytes = (uint32_t)len;
  return true;
}
