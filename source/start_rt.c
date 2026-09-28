// What START.EXE (recompiled: start_core.c) needs outside its machine code: the drivers (MGRAPHIC recompiled; the
// keyboard and joystick of MISC from the host; the no-sound driver), DOS (files from the game
// directory, read only; memory: dosmem.c; interrupt vectors; the clock; exit), the BIOS clock, and the functions kept in C:
// the picture decoder (lzw.c), int86(), exit().
#include <dirent.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "asm2c.h"
#include "dosmem.h"
#include "lzw.h"
#include "start.h"
#include "start_rt.h"

#define START_CS 0x27CC   // START's code segment in the oracle (Ghidra's 1000)
#define START_PSP 0x27BC  // its program segment prefix: the owner of its memory blocks

static const StartHost *host;
void (*start_trace)(uint32_t addr);
static jmp_buf exitJump;
static bool exitArmed;

static bool start_int(u8 n);

void start_attach(uint8_t *ds, uint16_t dsSeg, uint16_t sharedSeg, const StartHost *h)
{
  g_ds = ds;
  g_dsSeg = dsSeg;
  g_sharedSeg = sharedSeg;
  host = h;
  asm_int_hook = start_int;
  dos_owner = START_PSP;
}

void start_main(const uint16_t regs[9])
{
  R.sp = g_sp = regs[0];
  R.bp = regs[1];
  R.si = regs[2];
  R.di = regs[3];
  R.es = regs[4];
  R.ax = regs[5];
  R.bx = regs[6];
  R.cx = regs[7];
  R.dx = regs[8];
  R.ds = R.ss = g_dsSeg;
  R.cs = START_CS;
  exitArmed = true;
  if (!setjmp(exitJump)) st_main_body();  // main's return address (crt0's) is on the stack
  exitArmed = false;
}

void st_exit(i16 code)
{
  if (host && host->exit) host->exit(host->ctx, code);
  if (exitArmed) longjmp(exitJump, 1);
  exit(code);
}

// setjmp() and longjmp(): the title's skip (a key ends it from the waits deep inside)
static struct { u16 buf; jmp_buf jb; } jumps[4];
static int nJumps;

jmp_buf *st_jmpbuf(u16 buf)
{
  int k = 0;
  while (k < nJumps && jumps[k].buf != buf) k++;
  if (k == nJumps)
  {
    if (nJumps == 4) { fprintf(stderr, "start: too many setjmp buffers\n"); abort(); }
    jumps[nJumps++].buf = buf;
  }
  return &jumps[k].jb;
}

void st_longjmp(u16 buf)
{
  for (int k = 0; k < nJumps; k++)
    if (jumps[k].buf == buf) longjmp(jumps[k].jb, 1);
  fprintf(stderr, "start: longjmp to DS:%04X without its setjmp\n", buf);
  abort();
}

// ---------------------------------------------------------------- the drivers

void mg_slot(int slot);

// a graphics slot called from C: the arguments and a far return address pushed, then the driver
static void gfx_call(int slot, u16 a0, u16 a1)
{
  u16 sp = R.sp;
  R.sp = g_sp;
  PUSH(a1);
  PUSH(a0);
  PUSH(START_CS);
  PUSH(0);
  mg_slot(slot);
  R.sp = sp;
}

void start_driver(int slot)
{
  if (slot < 48)
  {
    mg_slot(slot);
    return;
  }
  switch (slot)
  {
  case 90:  // MISC: a key is waiting, the key, a joystick button, the axes
  case 91:
  case 95:
  case 96:
  case 97:
    R.ax = host && host->input ? host->input(host->ctx, slot) : (slot == 90 ? 0xFFFF : 0);
    break;
  case 102:  // the no-sound driver: its tick asks for no fast timer
  case 105:  // its hardware check: present
    R.ax = 0;
    break;
  default:  // the no-sound driver's other slots and MISC's unused ones leave AX as it was (retf)
    break;
  }
  R.sp += 4;
}

// the frame waits: the host brings the timer interrupt's bytes to the wait's end
u8 st_frame_poll(u16 site)
{
  if (host && host->framePoll) host->framePoll(host->ctx, site);
  return *P8(0x1ba8);
}

// ---------------------------------------------------------------- the picture decoder (1757): lzw.c

static void st_lzw_palette(u16 at) { gfx_call(25, 0, at); }
// DS:2A6C the string table, 4272-4284 the decoder's variables, its stack DS:4285-4484, 426C/426E/4270 width,
// height, length; the input: the stream at DS:494E (end DS:181E), refilled through the far pointer at DS:4C2E
static const LzwLayout stLzw = { 0x2a6c, 0x4272, 0x4485, 0x4274, 0x4276, 0x4278, 0x427a, 0x427c, 0x427e, 0x4281, 0x4282,
                                 0x426c, 0x494e, 0x181e, 0x4c2e, 0x2f23, st_lzw_palette, st_far_call };

u16 st_PicHeader(void)
{
  FN(0x1757000C);
  return lzw_pic_header(&stLzw);
}

u16 st_DatHeader(void)
{
  FN(0x1757009C);
  return lzw_dat_header(&stLzw);
}

void st_LzwDecodeFar(u16 off, u16 seg, u16 n)
{
  FN(0x175700E4);
  lzw_decode(&stLzw, off, seg, n);
}

void st_LzwDecodeRow(i16 dst)
{
  FN(0x175700FE);
  lzw_decode(&stLzw, (u16)dst, g_dsSeg, *P16(0x426c));
}

// ---------------------------------------------------------------- the library functions kept in C

// int86(n, in, out): the registers from and to the REGS structures (ax bx cx dx si di cflag) in the data segment
i16 st_int86(i16 n, i16 in, i16 out)
{
  FN(0x1000560C);
  Regs saved = R;
  u16 i = (u16)in, o = (u16)out;
  R.ax = *P16(i);
  R.bx = *P16(i + 2);
  R.cx = *P16(i + 4);
  R.dx = *P16(i + 6);
  R.si = *P16(i + 8);
  R.di = *P16(i + 10);
  R.cf = 0;
  asm_int((u8)n);
  *P16(o) = R.ax;
  *P16(o + 2) = R.bx;
  *P16(o + 4) = R.cx;
  *P16(o + 6) = R.dx;
  *P16(o + 8) = R.si;
  *P16(o + 10) = R.di;
  *P16(o + 12) = R.cf ? 1 : 0;
  u16 ax = R.ax;
  R = saved;
  return (i16)ax;
}

// ---------------------------------------------------------------- DOS and the BIOS

static FILE *files[20];
static int debugFiles = -1;
#define DEBUG_FILES (debugFiles < 0 ? (debugFiles = getenv("START_DEBUG_FILES") != NULL) : debugFiles)

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

static void dos_error(u16 code)
{
  R.ax = code;
  R.cf = 1;
}

static bool start_int(u8 n)
{
  u8 ah = (u8)(R.ax >> 8), al = (u8)R.ax;
  if (n == 0x1A && ah == 0x00)  // the BIOS tick count
  {
    R.cx = 0;
    R.dx = host && host->biosTicks ? host->biosTicks(host->ctx) : 0;
    R.ax &= 0xFF00;
    return true;
  }
  if (n != 0x21) return false;
  switch (ah)
  {
  case 0x09:  // a '$' message
    if (DEBUG_FILES)
    {
      for (u16 k = R.dx; *far_ptr(R.ds, k) != '$'; k++) fputc(*far_ptr(R.ds, k), stderr);
      fputc('\n', stderr);
    }
    return true;
  case 0x2A:  // the date and the time (time())
  case 0x2C:
  {
    u32 v = host && host->dosClock ? host->dosClock(host->ctx, ah) : 0;
    R.cx = (u16)(v >> 16);
    R.dx = (u16)v;
    return true;
  }
  case 0x25:  // set an interrupt vector (the timer's, Ctrl-Break's: their handlers are the host's)
    *(u16a *)far_ptr(0, (u16)(al * 4)) = R.dx;
    *(u16a *)far_ptr(0, (u16)(al * 4 + 2)) = R.ds;
    return true;
  case 0x35:  // get one
    R.bx = *(u16a *)far_ptr(0, (u16)(al * 4));
    R.es = *(u16a *)far_ptr(0, (u16)(al * 4 + 2));
    return true;
  case 0x3D:  // open
  {
    char name[80];
    int k = 0;
    for (; k < 79 && *far_ptr(R.ds, (u16)(R.dx + k)); k++) name[k] = (char)*far_ptr(R.ds, (u16)(R.dx + k));
    name[k] = 0;
    FILE *f = open_game_file(name);
    if (DEBUG_FILES) fprintf(stderr, "start: open %s -> %s\n", name, f ? "ok" : "not found");
    if (!f)
    {
      dos_error(2);
      return true;
    }
    for (int h = 5; h < 20; h++)
      if (!files[h])
      {
        files[h] = f;
        R.ax = (u16)h;
        R.cf = 0;
        return true;
      }
    fclose(f);
    dos_error(4);
    return true;
  }
  case 0x3E:  // close
    if (R.bx >= 20 || !files[R.bx])
    {
      if (R.bx >= 5) dos_error(6);
      else R.cf = 0;
      return true;
    }
    fclose(files[R.bx]);
    files[R.bx] = NULL;
    R.cf = 0;
    return true;
  case 0x3F:  // read
  {
    if (R.bx >= 20 || !files[R.bx])
    {
      dos_error(6);
      return true;
    }
    u16 k = 0;
    for (int c; k < R.cx && (c = fgetc(files[R.bx])) != EOF; k++) *far_ptr(R.ds, (u16)(R.dx + k)) = (u8)c;
    if (DEBUG_FILES) fprintf(stderr, "start: read %d %04X:%04X %u -> %u\n", R.bx, R.ds, R.dx, R.cx, k);
    R.ax = k;
    R.cf = 0;
    return true;
  }
  case 0x40:  // write: the console's messages (the tests write no files)
    if (DEBUG_FILES && R.bx < 5)
      for (u16 k = 0; k < R.cx; k++) fputc(*far_ptr(R.ds, (u16)(R.dx + k)), stderr);
    R.ax = R.cx;
    R.cf = 0;
    return true;
  case 0x42:  // seek
  {
    if (R.bx >= 20 || !files[R.bx])
    {
      dos_error(6);
      return true;
    }
    long pos = (long)(((u32)R.cx << 16) | R.dx);
    fseek(files[R.bx], pos, al == 0 ? SEEK_SET : al == 1 ? SEEK_CUR : SEEK_END);
    long now = ftell(files[R.bx]);
    R.ax = (u16)now;
    R.dx = (u16)(now >> 16);
    R.cf = 0;
    return true;
  }
  case 0x44:  // device information: the console for the standard handles, a file on C: for the others
    if (al == 0x00)
    {
      R.dx = R.bx < 5 ? 0x80D3 : 0x0002;
      R.ax = R.dx;
      R.cf = 0;
      return true;
    }
    break;
  case 0x4C:  // the end
    st_exit(al);
    return true;
  default:
    break;
  }
  return false;
}
