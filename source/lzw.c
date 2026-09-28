// The picture and data decompressor the programs link (RP 2965, START 1757): LZW, 9 to 12-bit codes, over an RLE
// (0x90 escape), optionally two pixels a byte. A stack-switching coroutine in the original, written in C with the
// original's state in the program's data segment (LzwLayout), so that the state stays comparable with the game's.
#include "lzw.h"

#include "asm2c.h"

static u16 lzw_word(const LzwLayout *L, u16 *si)
{
  if (*si >= *P16(L->readEnd))
  {
    // call far [7F46], as the original: a return address on the stack (the callee's retf takes it)
    u16 sp = R.sp;
    R.sp = g_sp;
    PUSH(L->refillSeg);
    PUSH(0);
    L->farCall(*P16(L->refill + 2), *P16(L->refill));
    R.sp = sp;
    *si = *P16(L->readPtr);
  }
  u16 w = *P16(*si);
  *si += 2;
  return w;
}

static void lzw_reset_table(const LzwLayout *L)
{
  *P8(L->width) = 9;
  *P16(L->mask) = 0x1ff;
  *P16(L->next) = 0x100;
  for (u16 k = 0, bx = 0; k < 0x800; k++, bx += 3) *P16(bx + L->table) = 0xffff;
  for (u16 k = 0, bx = 0; k < 0x100; k++, bx += 3) *P8(bx + L->table + 2) = (u8)k;
}

static void lzw_init(const LzwLayout *L)
{
  u16 si = *P16(L->readPtr);
  *P8(L->run) = 0;
  *P8(L->run + 1) = 0;
  *P16(L->sp) = L->spTop;
  u16 w = lzw_word(L, &si);
  *P16(L->readPtr) = si;
  u8 max = (u8)w > 0xb ? 0xb : (u8)w;
  *P8(L->width + 1) = max;
  *P16(L->bits) = (u16)((w & 0xff00) | max);
  *P8(L->bits + 2) = 8;
  lzw_reset_table(L);
}

// the next byte of the decompressed stream: the string of the next code goes onto the decoder's
// stack, last byte first, and comes off one byte a call
static u8 lzw_byte(const LzwLayout *L, u16 *si, u16 *dx)
{
  u16 sp = *P16(L->sp);
  if (sp == L->spTop)
  {
    u16 bx = *P16(L->bits);
    u8 have = *P8(L->bits + 2);
    bx >>= (16 - have) & 31;
    u8 cl = have;
    while ((i8)cl < (i8)*P8(L->width))
    {
      u16 w = lzw_word(L, si);
      *P16(L->bits) = w;
      bx |= (u16)(w << (cl & 31));
      cl += 0x10;
    }
    cl -= *P8(L->width);
    *P8(L->bits + 2) = cl;
    u16 code = bx & *P16(L->mask), cx = code, ax = code;
    if ((i16)code >= (i16)*dx)
    {  // KwKwK: the previous string and its first byte
      cx = *dx;
      ax = *P16(L->prev);
      bx = (u16)((bx & 0xff00) | *P8(L->prev + 2));
      sp -= 2; *P16(sp) = bx;
    }
    for (;;)
    {
      bx = (u16)(ax * 3);
      ax = *P16(bx + L->table);
      if (ax == 0xffff) break;
      bx = (u16)((bx & 0xff00) | *P8(bx + L->table + 2));
      sp -= 2; *P16(sp) = bx;
    }
    u8 first = *P8(bx + L->table + 2);
    *P8(L->prev + 2) = first;
    sp -= 2; *P16(sp) = first;  // push ax: AH = 0 (the prefix was 0xFFFF + 1)
    bx = (u16)(*dx * 3);
    *P8(bx + L->table + 2) = first;
    *P16(bx + L->table) = *P16(L->prev);
    ++*dx;
    if ((i16)*dx > (i16)*P16(L->mask))
    {
      ++*P8(L->width);
      *P16(L->mask) = (u16)((*P16(L->mask) << 1) | 1);
    }
    if ((i8)*P8(L->width) > (i8)*P8(L->width + 1)) { lzw_reset_table(L); *dx = *P16(L->next); }
    *P16(L->prev) = cx;
  }
  u8 b = *P8(sp);
  *P16(L->sp) = (u16)(sp + 2);
  return b;
}

// decodes n bytes to far memory (dst = offset, segment), RLE and nibbles as the flags say
void lzw_decode(const LzwLayout *L, u16 dstoff, u16 dstseg, u16 n)
{
  u16 si = *P16(L->readPtr);
  if (*P8(L->nibble)) n = (u16)((n + 1) >> 1);
  *P16(L->count) = n;
  u16 dx = *P16(L->next);
  do
  {
    u8 al;
    if (*P8(L->run) == 0)
    {
      al = lzw_byte(L, &si, &dx);
      if (al != 0x90) *P8(L->run + 1) = al;
      else
      {
        al = lzw_byte(L, &si, &dx);
        if (al == 0) { al = 0x90; *P8(L->run + 1) = al; }
        else { *P8(L->run) = (u8)(al - 1); al = *P8(L->run + 1); --*P8(L->run); }
      }
    }
    else
    {
      al = *P8(L->run + 1);
      --*P8(L->run);
    }
    if (*P8(L->nibble))
    {
      *far_ptr(dstseg, dstoff) = al & 0xf;
      *far_ptr(dstseg, (u16)(dstoff + 1)) = al >> 4;
      dstoff += 2;
    }
    else *far_ptr(dstseg, dstoff++) = al;
  } while (--*P16(L->count) != 0);
  *P16(L->next) = dx;
  *P16(L->readPtr) = si;
}

// PicHeader: flags (bit 0 nibbles, bit 3 a 16-byte palette, bit 4 a 128-byte one: to graphics slot 25), width,
// height; then the decoder starts. Returns the height
u16 lzw_pic_header(const LzwLayout *L)
{
  u16 si = *P16(L->readPtr);
  u16 flags = lzw_word(L, &si);
  *P8(L->nibble) = flags & 1;
  *P16(L->header) = lzw_word(L, &si);
  *P16(L->header + 2) = lzw_word(L, &si);
  *P16(L->readPtr) = si;
  if (flags & 0x8) { L->palette(si); *P16(L->readPtr) = (u16)(si + 0x10); }
  else if (flags & 0x10) { L->palette(si); *P16(L->readPtr) = (u16)(si + 0x80); }
  lzw_init(L);
  return *P16(L->header + 2);
}

// DatHeader: flags (bit 0 nibbles), length; the decoder starts. Returns the length
u16 lzw_dat_header(const LzwLayout *L)
{
  u16 si = *P16(L->readPtr);
  *P8(L->nibble) = lzw_word(L, &si) & 1;
  *P16(L->header + 4) = lzw_word(L, &si);
  *P16(L->readPtr) = si;
  lzw_init(L);
  return *P16(L->header + 4);
}
