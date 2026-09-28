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
#include "dosmem.h"

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
void (*rp_tickHook)(void);
jmp_buf rp_resume;
u8 rp_resumeArmed;
void (*rp_trace)(uint32_t addr);

void rp_attach(uint8_t *ds, uint16_t dsSeg, uint16_t sharedSeg, const RpHost *h)
{
  g_ds = ds;
  g_dsSeg = dsSeg;
  g_sharedSeg = sharedSeg;
  host = h;
  asm_int_hook = NULL;
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
  // the library's time() sets the time zone from the environment once (tzset: no TZ, the defaults stay)
  if (!*P16(0x5BB4)) *P16(0x5BB4) = 1;
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
void rp_exit(i16 code)
{
  if (code >= 1 && code <= 3 && rp_resumeArmed && host && host->subgame)
  {
    host->subgame(host->ctx, code);  // (with restart it does not return)
    dos_free_owner(RP_PSP);  // RP ended (DOS freed its blocks) and runs again (it allocates them anew)
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

void rp_close_files(void)
{
  for (int h = 0; h < 20; h++)
    if (files[h].f) fclose(files[h].f), files[h].f = NULL;
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

// saving: the saved games, when the host lets RP write (the frontend); the tests' writes succeed without a file
i16 _dos_creat(i16 name, i16 attr, i16 ph)
{
  (void)attr;
  if (!host || !host->writeFiles)
  {
    *P16((u16)ph) = 19;
    return 0;
  }
  // the file as DOS names it (upper case), or the one of that name in any case already there
  char upper[80];
  const char *n = NEAR((u16)name);
  int k = 0;
  for (; n[k] && k < 79; k++) upper[k] = (char)(n[k] >= 'a' && n[k] <= 'z' ? n[k] - 32 : n[k]);
  upper[k] = 0;
  const char *dir = host->gameDir ? host->gameDir : ".";
  char path[1024];
  snprintf(path, sizeof path, "%s/%s", dir, upper);
  DIR *d = opendir(dir);
  if (d)
  {
    struct dirent *e;
    while ((e = readdir(d)))
      if (!strcasecmp(e->d_name, upper)) snprintf(path, sizeof path, "%s/%s", dir, e->d_name);
    closedir(d);
  }
  FILE *f = fopen(path, "wb");
  if (DEBUG_FILES) fprintf(stderr, "rp: create %s -> %s\n", path, f ? "ok" : "failed");
  if (!f) return 5;
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

i16 _dos_write(i16 h, u16 off, u16 seg, u16 n, i16 pn)
{
  if (host && host->writeFiles && h >= 5 && h < 20 && files[h].f)
  {
    u16 k = 0;
    for (; k < n; k++)
      if (fputc(*far_ptr(seg, (u16)(off + k)), files[h].f) == EOF) break;
    *P16((u16)pn) = k;
    return 0;
  }
  *P16((u16)pn) = n;
  return 0;
}

// intdos: the DOS calls the catalog module makes (42h seek), with the REGS structure in the data segment
i16 rp_intdos(i16 in, i16 out)
{
  u16 i = (u16)in, o = (u16)out;
  for (int k = 0; k < 14; k++) *P8(o + k) = *P8(i + k);
  u8 ah = *P8(i + 1);
  if (DEBUG_FILES) fprintf(stderr, "rp: intdos AX=%04X bx=%d cx:dx=%04X:%04X\n", *P16(i), *P16(i + 2), *P16(i + 4), *P16(i + 6));
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
  static const MscErrno rpErrno = { 0x34C6, 0x34C3, 0x3504, 0x34BB };
  return (i16)asm_msc_int86((u8)n, (u16)in, (u16)out, &rpErrno);
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

// ---------------------------------------------------------------- DOS memory: the arena (dosmem.c)

void rp_set_arena(uint16_t first, uint16_t end) { dos_set_arena(first, end); }
void rp_arena_from_memory(uint16_t from, uint16_t to) { dos_arena_from_memory(from, to); }
u16 rp_dos_alloc(u16 paragraphs) { return dos_alloc(paragraphs); }
void rp_dos_free(u16 seg) { dos_free(seg); }
bool rp_dos_resize(u16 seg, u16 paragraphs) { return dos_resize(seg, paragraphs); }

void rp_fatal_memory(i16 name, i16 suffix)
{
  fprintf(stderr, "Insufficient system memory - %s%s\n", NEAR((u16)name), NEAR((u16)suffix));
  rp_exit(0);
}

// ---------------------------------------------------------------- the assembly module (168c)

// is the file on the disk in the drive (168c:0002)? It saves the critical-error vector (DS:05D2 segment, 05D4
// offset) and puts its own, parses the name into the FCB at DS:05D7 (INT 21h 29h) and looks for it (11h), asking
// for the other drive if not; here the game's files are all there: 0. Then it puts the vector back -- with the
// offset read after DS became the saved segment (mov ds, [05D2]; mov dx, [05D4]): the word at that segment's 05D4
// (DUEL's and BATTLE's disk checks do the same with theirs)
i16 FileOnDisk(i16 name, i16 disk)
{
  (void)disk;
  *P16(0x5D2) = *(u16a *)far_ptr(0, 0x92);
  *P16(0x5D4) = *(u16a *)far_ptr(0, 0x90);
  const char *s = NEAR((u16)name);
  u8 *fcb = P8(0x5D7);
  fcb[0] = 0;
  memset(fcb + 1, ' ', 11);
  int k = 0;
  for (; *s && *s != '.' && k < 8; s++) fcb[1 + k++] = (u8)(*s >= 'a' && *s <= 'z' ? *s - 32 : *s);
  while (*s && *s != '.') s++;
  if (*s == '.') s++;
  for (k = 0; *s && k < 3; s++) fcb[9 + k++] = (u8)(*s >= 'a' && *s <= 'z' ? *s - 32 : *s);
  u16 seg = *P16(0x5D2);
  *(u16a *)far_ptr(0, 0x90) = *(u16a *)far_ptr(seg, 0x5D4);
  *(u16a *)far_ptr(0, 0x92) = seg;
  return 0;
}
// the hibernation: the data segment (DS:0000-975F: data, BSS, stack) at seg:0004, the stack pointer at seg:0000
void SaveContext(u16 seg)
{
  contextSeg = seg;
  for (u16 k = 0; k < 0x9760; k++) *far_ptr(seg, (u16)(4 + k)) = *P8(k);
  *(u16a *)far_ptr(seg, 0) = g_sp;
}

// the resume (168c:00EE, from main when shared+2C says RP hibernated): the data segment back, and on where it
// hibernated (the host's C stack still has it: the sub-game and this run of RP ran inside RP's exit)
void RestoreContext(u16 seg)
{
  for (u16 k = 0; k < 0x9760; k++) *P8(k) = *far_ptr(seg, (u16)(4 + k));
  if (host && host->restart && rp_resumeArmed) longjmp(rp_resume, 1);
}
// is this not the original disk (168c:0120)? It looks for the drive's volume label (an FCB search) and compares it
// with the original disk's: 0 the original (the saves and the Scroll of Honor are refused); the game's directory is
// not it: the label is not found, AX = 11FFh (AH still the search's function)
i16 NotOriginalDisk(void) { return 0x11FF; }
void DosPrint(i16 s) { (void)s; }
// the timer (168c:0958; the MicroProse library's, as START's 1694:0810 is): its bytes at DS:3040 (B) --
// B+0 the ticks' sum for the BIOS's tick (dword), +4 the count for the channel, +6 the count it has, +8 the times
// it was set, +A the interrupts a frame (1, or the sound's fast rate), +C the interrupts until the next setting
// (byte), +D the fast rate, +F a frame's length in PIT ticks, +13 in step with the retrace (byte), +14 the
// interrupts until the frame's routine, +16 the lines it last waited; B-1 hooked (byte)
#define TB 0x3040
// the PIT's channel 0 at the start of a vertical retrace (168c:0B59): 0 if the retrace does not come
static u16 retrace_count(void)
{
  u16 bx = 0;
  do if (!--bx) return 0;
  while (asm_port_in(0x3DA) & 8);
  bx = 0;
  do if (!--bx) return 0;
  while (!(asm_port_in(0x3DA) & 8));
  asm_port_out(0x43, 0);
  u16 lo = asm_port_in(0x40) & 0xFF;
  return (u16)(lo | (asm_port_in(0x40) & 0xFF) << 8);
}
// the frame's length (168c:0AB4): the counts at 17 retraces; a mode 3 count goes down by 2 a tick. A length
// that does not make 4-6 fast interrupts of about 3977 ticks is not a VGA's: the timer runs at 60 Hz on its own
static void measure_frame(void)
{
  *P8(TB + 0xC) = 1;
  *P8(TB + 0x13) = 1;
  u32 sum = 0;
  u16 bx = retrace_count();
  for (int k = 0; k < 16; k++)
  {
    u16 ax = retrace_count();
    sum += (u16)(bx - ax);
    bx = ax;
  }
  u32 acc = (u32)*P16(TB) | (u32)*P16(TB + 2) << 16;
  acc += sum;
  *P16(TB) = (u16)acc, *P16(TB + 2) = (u16)(acc >> 16);
  u16 len = (u16)((sum / 16) >> 1);
  u16 fast = (u16)((u16)(len + (len >> 4)) / 0xF89);
  if (fast < 4 || fast > 6)
  {
    *P8(TB + 0x13) = 0;
    len = 0x4DAE;
    fast = 5;
  }
  *P16(TB + 0xF) = len;
  *P16(TB + 0x11) = (u16)(sum >> 16);
  *P16(TB + 0xD) = fast;
  if (*P16(TB + 0xA) != 1) *P16(TB + 0xA) = fast;
  *P16(TB + 6) = *P16(TB + 4) = (u16)(len / *P16(TB + 0xA));
}
// the handler hooked (INT 8: its address at 168c:09E1, the old one kept at 168c:0A49)
void InstallTimer(void)
{
  *P16(TB + 0xA) = 1;
  *P16(TB + 0x14) = 1;
  *P16(TB) = 0, *P16(TB + 2) = 0;
  measure_frame();
  memcpy(far_ptr(0x2E58, 0x0A49), far_ptr(0, 0x20), 4);
  memcpy(far_ptr(0, 0x20), far_ptr(0x2E58, 0x09E1), 4);
  *P8(TB - 1) = 1;
}
// the BIOS's 18.2 Hz back, and its handler (168c:0996)
void RestoreTimer(void)
{
  asm_port_out(0x43, 0x36);
  asm_port_out(0x40, 0);
  asm_port_out(0x40, 0);
  memcpy(far_ptr(0, 0x20), far_ptr(0x2E58, 0x0A49), 4);
  *P8(TB - 1) = 0;
}
void SaveVectors(void) {}
void RestoreVectors(void) {}
// a driver's entries into the stubs (168c:0CE7): the overlay header's first slot (+2E), count (+30), offsets
// (+32) and code segment (+28), into the far jumps at DS:3060 + 5 slot
void RegisterOverlay(u16 seg)
{
  u16 stub = (u16)(0x3060 + (u8)*far_ptr(seg, 0x2E) * 5), n = *(u16a *)far_ptr(seg, 0x30), cs = *(u16a *)far_ptr(seg, 0x28);
  for (u16 k = 0; k < n; k++, stub += 5)
  {
    *P16(stub + 1) = *(u16a *)far_ptr(seg, (u16)(0x32 + 2 * k));
    *P16(stub + 3) = cs;
  }
}
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
  if (slot >= 100 && slot <= 106 && asm_sound_slot && asm_sound_slot(slot - 100)) return;  // the sound driver loaded
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
    return dos_largest_free();
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
