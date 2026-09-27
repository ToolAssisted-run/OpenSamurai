// The run-time library functions, assembly helpers, DOS and drivers rp_core.c needs, over the data segment image,
// the shared block and the rest of the megabyte (far_ptr). What the simulation depends on is real: strings,
// arithmetic, the random numbers (the library's seed at DS:34FC), files (the game's catalogs, read from the game
// directory), memory (DOS's arena, first fit, so that the program's buffers get the segments they got in the real
// game), the clock, the keyboard. Drawing and sound belong to the frontend and do nothing here.
#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rp.h"
#include "rp_rt.h"
#include "asm2c.h"

// the host's C library below (rp_rt.h maps the program's library names to the rp_ functions defined here)
#undef exit
#undef fclose
#undef fopen
#undef fread
#undef fwrite
#undef strcat
#undef strcpy
#undef strlen
#undef itoa
#undef perror
#undef intdos
#undef int86
#undef movedata
#undef time
#undef stricmp
#undef strnicmp
#undef strupr
#undef memmove
#undef memcpy
#undef srand
#undef rand
#undef close
#undef read
#undef write
#undef unlink
#undef strncpy
#undef getenv
#undef strncmp
#undef atoi

static const RpHost *host;
#define RP_PSP 0x27BC  // RP's program segment prefix in the oracle (its code at 27CC): the owner of its blocks
u8 rp_tickEntry, rp_tickArmed;
jmp_buf rp_resume;
u8 rp_resumeArmed;
void (*rp_trace)(uint32_t addr);

void rp_attach(uint8_t *ds, uint16_t dsSeg, uint16_t sharedSeg, const RpHost *h)
{
  g_ds = ds;
  g_dsSeg = dsSeg;
  g_sharedSeg = sharedSeg;
  host = h;
}

// ---------------------------------------------------------------- strings and memory (near: data segment offsets)

#define NEAR(x) ((char *)DSP(x))

















i16 rp_getenv(i16 name)
{
  (void)name;
  return 0;
}

// ---------------------------------------------------------------- arithmetic


// ---------------------------------------------------------------- random numbers and the clock



i32 rp_time(i16 p)
{
  u32 t = host && host->time ? host->time(host->ctx) : 0;
  if (p) *P32((u16)p) = t;
  return (i32)t;
}

u16 BiosTicks(void) { return host && host->biosTicks ? host->biosTicks(host->ctx) : 0; }

u8 rp_frame_poll(void)
{
  if (host && host->framePoll) host->framePoll(host->ctx, *P8(0x3038));
  return *P8(0x3038);
}

void rp_delay_frames(int n)
{
  *P8(0x3038) = (u8)(*P8(0x3038) + n);
  *P8(0x303a) = (u8)(*P8(0x303a) + n);
}

// exit: 1-3 after the hibernation (23bb:0222) start a sub-game; RP then runs again and restores itself
// (RestoreContext), which here is: the sub-game, the saved data segment back, and on after SaveContext
static u16 contextSeg;
static void free_owner(u16 owner);
static u16 largest_free(void);
void rp_exit(i16 code)
{
  if (code >= 1 && code <= 3 && rp_resumeArmed && host && host->subgame)
  {
    host->subgame(host->ctx, code);
    free_owner(RP_PSP);  // RP ended (DOS freed its blocks) and runs again (it allocates them anew)
    RestoreContext(contextSeg);
    longjmp(rp_resume, 1);
  }
  if (host && host->exit) host->exit(host->ctx, code);
  exit(code);
}

// ---------------------------------------------------------------- files: the game directory, read only

typedef struct { FILE *f; } DosFile;
static DosFile files[20];

static FILE *open_game_file(const char *name)
{
  const char *dir = host && host->gameDir ? host->gameDir : ".";
  DIR *d = opendir(dir);
  if (!d) return NULL;
  struct dirent *e;
  FILE *f = NULL;
  while ((e = readdir(d)))
    if (!strcasecmp(e->d_name, name))
    {
      char path[1024];
      snprintf(path, sizeof path, "%s/%s", dir, e->d_name);
      f = fopen(path, "rb");
      break;
    }
  closedir(d);
  return f;
}

static int debugFiles = -1;
#define DEBUG_FILES (debugFiles < 0 ? (debugFiles = getenv("RP_DEBUG_FILES") != NULL) : debugFiles)

i16 _dos_open(i16 name, i16 mode, i16 ph)
{
  (void)mode;
  FILE *f = open_game_file(NEAR((u16)name));
  if (DEBUG_FILES) fprintf(stderr, "rp: open %s -> %s\n", NEAR((u16)name), f ? "ok" : "not found");
  if (!f) return 2;
  for (int h = 5; h < 20; h++)
    if (!files[h].f)
    {
      files[h].f = f;
      *P16((u16)ph) = (u16)h;
      return 0;
    }
  fclose(f);
  return 4;
}

i16 _dos_close(i16 h)
{
  if (h < 0 || h >= 20 || !files[h].f) return 6;
  fclose(files[h].f);
  files[h].f = NULL;
  return 0;
}

i16 _dos_read(i16 h, u16 off, u16 seg, u16 n, i16 pn)
{
  if (DEBUG_FILES) fprintf(stderr, "rp: read %d %04X:%04X %u%s\n", h, seg, off, n, h < 0 || h >= 20 || !files[h].f ? " (not open)" : "");
  if (h < 0 || h >= 20 || !files[h].f) return 6;
  u16 k = 0;
  for (; k < n; k++)
  {
    int c = fgetc(files[h].f);
    if (c == EOF) break;
    *far_ptr(seg, (u16)(off + k)) = (u8)c;
  }
  *P16((u16)pn) = k;
  return 0;
}

// saving: the reconstruction's tests do not write files (the frontend will)
i16 _dos_creat(i16 name, i16 attr, i16 ph)
{
  (void)name;
  (void)attr;
  *P16((u16)ph) = 19;
  return 0;
}

i16 _dos_write(i16 h, u16 off, u16 seg, u16 n, i16 pn)
{
  (void)h;
  (void)off;
  (void)seg;
  *P16((u16)pn) = n;
  return 0;
}

// intdos: the DOS calls the catalog module makes (42h seek), with the REGS structure in the data segment
i16 rp_intdos(i16 in, i16 out)
{
  u16 i = (u16)in, o = (u16)out;
  for (int k = 0; k < 14; k++) *P8(o + k) = *P8(i + k);
  u8 ah = *P8(i + 1);
  if (DEBUG_FILES) fprintf(stderr, "rp: intdos %02X bx=%d\n", ah, *P16(i + 2));
  u16 ax = *P16(i), bx = *P16(i + 2), cx = *P16(i + 4), dx = *P16(i + 6);
  *P16(o + 12) = 0;  // cflag
  if (ah == 0x42 && bx < 20 && files[bx].f)
  {
    long pos = (long)(((u32)cx << 16) | dx);
    fseek(files[bx].f, pos, (ax & 0xff) == 0 ? SEEK_SET : (ax & 0xff) == 1 ? SEEK_CUR : SEEK_END);
    long now = ftell(files[bx].f);
    *P16(o) = (u16)now;
    *P16(o + 6) = (u16)(now >> 16);
  }
  else if (ah != 0x42)
    fprintf(stderr, "rp: intdos AH=%02X\n", ah);
  return (i16)*P16(o);
}

i16 rp_int86(i16 n, i16 in, i16 out)
{
  (void)n;
  for (int k = 0; k < 14; k++) *P8((u16)out + k) = *P8((u16)in + k);
  *P16((u16)out + 12) = 0;
  return (i16)*P16((u16)out);
}

// the C library's stream functions (the scroll of honour, the saved game): not in the tests yet
i16 rp_fopen(i16 name, i16 mode) { (void)mode; fprintf(stderr, "rp: fopen %s\n", NEAR((u16)name)); return 0; }
i16 rp_fclose(i16 f) { (void)f; return 0; }
i16 rp_fread(i16 buf, i16 size, i16 n, i16 f) { (void)buf; (void)size; (void)n; (void)f; return 0; }
i16 rp_fwrite(i16 buf, i16 size, i16 n, i16 f) { (void)buf; (void)size; (void)f; return n; }
i16 _filbuf(i16 f) { (void)f; return -1; }
i16 _flsbuf(i16 c, i16 f) { (void)f; return c; }
i16 rp_close(i16 h) { return _dos_close(h); }
i16 rp_read(i16 h, i16 buf, u16 n)
{
  if (h < 0 || h >= 20 || !files[h].f) return -1;
  u16 k = 0;
  for (int c; k < n && (c = fgetc(files[h].f)) != EOF; k++) *P8((u16)buf + k) = (u8)c;
  return (i16)k;
}
i16 rp_write(i16 h, i16 buf, u16 n) { (void)h; (void)buf; return (i16)n; }
i16 rp_unlink(i16 name) { (void)name; return 0; }
void rp_perror(i16 s) { fprintf(stderr, "rp: %s\n", NEAR((u16)s)); }

// ---------------------------------------------------------------- DOS memory: the arena, first fit

typedef struct { u16 seg, size; bool used; u16 owner; } Mcb;  // seg = the block's paragraph (the MCB is the one before)
static Mcb arena[256];
static int nArena;

void rp_set_arena(uint16_t first, uint16_t end)
{
  nArena = 1;
  arena[0] = (Mcb){ (u16)(first + 1), (u16)(end - first - 1), false };
}

// the arena as DOS has it in memory: the chain of memory control blocks ('M'/'Z', owner, paragraphs) from the
// first one at or above paragraph `from` that chains consistently to the last ('Z') below `to`
void rp_arena_from_memory(uint16_t from, uint16_t to)
{
  for (u32 p = from; p < to; p++)
  {
    u32 q = p;
    int n = 0, ok = 0;
    Mcb tmp[256];
    while (q < to && n < 256)
    {
      u8 *m = far_ptr((u16)q, 0);
      if (m[0] != 'M' && m[0] != 'Z') break;
      u16 owner = (u16)(m[1] | (m[2] << 8)), size = (u16)(m[3] | (m[4] << 8));
      tmp[n++] = (Mcb){ (u16)(q + 1), size, owner != 0, owner };
      if (m[0] == 'Z') { ok = n >= 2; break; }
      q += 1u + size;
    }
    if (ok)
    {
      memcpy(arena, tmp, sizeof(Mcb) * (size_t)n);
      nArena = n;
      return;
    }
  }
}

static void merge_free(void)
{
  for (int k = 0; k + 1 < nArena; k++)
    if (!arena[k].used && !arena[k + 1].used)
    {
      arena[k].size = (u16)(arena[k].size + 1 + arena[k + 1].size);
      memmove(&arena[k + 1], &arena[k + 2], sizeof(Mcb) * (size_t)(nArena - k - 2));
      nArena--;
      k--;
    }
}

u16 rp_dos_alloc(u16 paragraphs)
{
  merge_free();
  for (int k = 0; k < nArena; k++)
    if (!arena[k].used && arena[k].size >= paragraphs)
    {
      if (arena[k].size > paragraphs)
      {
        memmove(&arena[k + 2], &arena[k + 1], sizeof(Mcb) * (size_t)(nArena - k - 1));
        nArena++;
        arena[k + 1] = (Mcb){ (u16)(arena[k].seg + paragraphs + 1), (u16)(arena[k].size - paragraphs - 1), false };
        arena[k].size = paragraphs;
      }
      arena[k].used = true;
      arena[k].owner = RP_PSP;
      return arena[k].seg;
    }
  return 0;
}

// the program ends: DOS frees its blocks
static void free_owner(u16 owner)
{
  for (int k = 0; k < nArena; k++)
    if (arena[k].used && arena[k].owner == owner) arena[k].used = false;
  merge_free();
}

void rp_dos_free(u16 seg)
{
  for (int k = 0; k < nArena; k++)
    if (arena[k].seg == seg) arena[k].used = false;
}

bool rp_dos_resize(u16 seg, u16 paragraphs)
{
  merge_free();
  for (int k = 0; k < nArena; k++)
    if (arena[k].seg == seg)
    {
      if (paragraphs <= arena[k].size)
      {
        if (paragraphs < arena[k].size)
        {
          memmove(&arena[k + 2], &arena[k + 1], sizeof(Mcb) * (size_t)(nArena - k - 1));
          nArena++;
          arena[k + 1] = (Mcb){ (u16)(seg + paragraphs + 1), (u16)(arena[k].size - paragraphs - 1), false };
          arena[k].size = paragraphs;
          merge_free();
        }
        return true;
      }
      if (k + 1 < nArena && !arena[k + 1].used && arena[k].size + 1 + arena[k + 1].size >= paragraphs)
      {
        arena[k].size = (u16)(arena[k].size + 1 + arena[k + 1].size);
        memmove(&arena[k + 1], &arena[k + 2], sizeof(Mcb) * (size_t)(nArena - k - 2));
        nArena--;
        return rp_dos_resize(seg, paragraphs);
      }
      return false;
    }
  return false;
}

// DOS memory for recompiled code (INT 21h 48h/49h/4Ah)
u16 asm2c_dos_alloc(u16 paragraphs, u16 *largest)
{
  u16 seg = rp_dos_alloc(paragraphs);
  if (!seg) *largest = largest_free();
  return seg;
}

bool asm2c_dos_free(u16 seg)
{
  rp_dos_free(seg);
  return true;
}

bool asm2c_dos_resize(u16 seg, u16 paragraphs, u16 *largest)
{
  if (rp_dos_resize(seg, paragraphs)) return true;
  *largest = largest_free();
  return false;
}

void rp_fatal_memory(i16 name, i16 suffix)
{
  fprintf(stderr, "Insufficient system memory - %s%s\n", NEAR((u16)name), NEAR((u16)suffix));
  rp_exit(0);
}

// ---------------------------------------------------------------- the assembly module (168c)

i16 FileOnDisk(i16 name, i16 disk) { (void)name; (void)disk; return 1; }
// the hibernation: the data segment (DS:0000-975F: data, BSS, stack) at seg:0004, the stack pointer at seg:0000
void SaveContext(u16 seg)
{
  contextSeg = seg;
  for (u16 k = 0; k < 0x9760; k++) *far_ptr(seg, (u16)(4 + k)) = *P8(k);
  *(u16a *)far_ptr(seg, 0) = g_sp;
}

void RestoreContext(u16 seg)
{
  for (u16 k = 0; k < 0x9760; k++) *P8(k) = *far_ptr(seg, (u16)(4 + k));
}
i16 NotOriginalDisk(void) { return 0; }
void DosPrint(i16 s) { (void)s; }
void InstallTimer(void) { *P8(0x303f) = 1; }
void RestoreTimer(void) {}
void SaveVectors(void) {}
void RestoreVectors(void) {}
void RegisterOverlay(u16 seg) { (void)seg; }
void HookKeyboard(void) {}
void UnhookKeyboard(void) {}

// ---------------------------------------------------------------- the drivers

// the graphics driver's fonts (FONTS.SAM: four proportional bitmap fonts; see docs/FINDINGS.md): what the text
// layout depends on -- the widths and heights
static uint8_t *fonts;
static long fontsSize;

static const uint8_t *font_header(int font)  // the byte after the 8-byte header, i.e. the bitmap
{
  if (!fonts)
  {
    FILE *f = open_game_file("FONTS.SAM");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    fontsSize = ftell(f);
    fseek(f, 0, SEEK_SET);
    fonts = malloc((size_t)fontsSize);
    if (fread(fonts, 1, (size_t)fontsSize, f) != (size_t)fontsSize) fontsSize = 0;
    fclose(f);
  }
  if (font < 1 || font > 4 || fontsSize < 10) return NULL;
  u16 off = (u16)(fonts[2 * font] | (fonts[2 * font + 1] << 8));
  return off >= 16 && off < fontsSize ? fonts + off : NULL;
}

static int char_width(int font, int ch)
{
  const uint8_t *h = font_header(font);
  if (!h) return 0;
  int first = h[-8], last = h[-7];
  if (ch < first || ch > last) return 0;
  if (h[-5]) return h[-5] + h[-3];
  return h[-9 - (last - first) + (ch - first)] + h[-3];
}

static u16 largest_free(void)
{
  u16 best = 0;
  for (int k = 0; k < nArena; k++)
    if (!arena[k].used && arena[k].size > best) best = arena[k].size;
  return best;
}

// a driver call from recompiled code: the stub's far jump, with the caller's return address on the stack --
// the graphics driver (MGRAPHIC, recompiled whole: mgraphic.c) or the host's keyboard and sound
void mg_slot(int slot);
void rp_driver(int slot)
{
  if (slot < 48)
  {
    mg_slot(slot);
    return;
  }
  u16 sp = R.sp;
  R.ax = rp_drv(slot, M16(SS, sp + 4), M16(SS, sp + 6), M16(SS, sp + 8), M16(SS, sp + 10), M16(SS, sp + 12), M16(SS, sp + 14), M16(SS, sp + 16), M16(SS, sp + 18));
  R.sp = (u16)(sp + 4);
}

u16 rp_drv(int slot, ...)
{
  va_list ap;
  va_start(ap, slot);
  int a[8];
  for (int k = 0; k < 8; k++) a[k] = va_arg(ap, int);
  va_end(ap);
  if (slot < 48)
  {
    // from C (the picture decoder's palette): the arguments and a return address pushed, then the driver
    u16 sp = R.sp;
    R.sp = g_sp;
    for (int k = 7; k >= 0; k--) PUSH(a[k]);
    PUSH(0x27CC);
    PUSH(0);
    mg_slot(slot);
    R.sp = sp;
    return R.ax;
  }
  switch (slot)
  {
  case 0:  // page_alloc(n): 0 the screen, else a 64000-byte page from DOS
    return a[0] == 0 ? 0xA000 : rp_dos_alloc(0xFA0);
  case 1:  // the largest free DOS block, paragraphs
    return largest_free();
  case 5:  // char_width(font, ch)
    return (u16)char_width(a[0], a[1] & 0xFF);
  case 11:  // line_height(font)
  {
    const uint8_t *h = font_header(a[0]);
    return h ? (u16)(h[-4] + h[-2]) : 0;
  }
  case 14:  // info(k): the MCGA driver's 0,1,0,0,0 (k = 6: 640-wide mode, 8: doubled x)
    return a[0] == 2 ? 1 : 0;
  case 19:  // text(win, x, y, str): the end x (the text's width past x) in the window's font
  {
    int font = (i16)*P16((u16)a[0] + 0x10), x = (i16)a[1];
    for (u16 p = (u16)a[3]; *P8(p); p++) x += char_width(font, *P8(p));
    return (u16)x;
  }
  case 90:  // key waiting: 0 yes, -1 no (INT 16h/01)
    return host && host->keyWaiting && host->keyWaiting(host->ctx) ? 0 : 0xFFFF;
  case 91:  // read a key (INT 16h/00: the grey keys' E0 comes back as 00, as DOSBox-X's BIOS does)
  {
    u16 k = host && host->readKey ? host->readKey(host->ctx) : 0;
    if ((k & 0xFF) == 0xE0 && (k >> 8)) k &= 0xFF00;
    return k;
  }
  case 102:  // NSOUND tick() -> 0
  case 105:  // NSOUND hw_init() -> 0
    return 0;
  default:  // the no-sound driver's other slots and the drawing ones leave AX as it was (retf)
    return R.ax;
  }
}
