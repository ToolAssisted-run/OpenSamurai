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
#include "dos.h"
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

void start_entry(uint16_t psp, uint16_t ss, uint16_t sp)
{
  R = (Regs){ 0 };
  R.ds = R.es = psp;
  R.ss = ss;
  R.sp = g_sp = sp;
  R.cs = START_CS;
  exitArmed = true;
  if (!setjmp(exitJump)) st_crt0_body();
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
  if (slot >= 100 && slot <= 106 && asm_sound_slot && asm_sound_slot(slot - 100)) return;  // the sound driver loaded
  if (slot >= 95 && slot <= 97 && asm_misc_slot && asm_misc_slot(slot)) return;  // the joystick
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
                                 0x426c, 0x494e, 0x181e, 0x4c2e, 0x2f23, true, st_lzw_palette, st_far_call };

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

// int86(n, in, out): it builds its INT instruction on the stack (asm2c's emulation, with START's errno)
i16 st_int86(i16 n, i16 in, i16 out)
{
  FN(0x1000560C);
  static const MscErrno stErrno = { 0x2002, 0x1FFF, 0x2140, 0x1FF7 };
  return (i16)asm_msc_int86((u8)n, (u16)in, (u16)out, &stErrno);
}

// ---------------------------------------------------------------- DOS and the BIOS (dos.c)

static uint32_t dos_answer(void *ctx, int ah)
{
  (void)ctx;
  return host && host->dos ? host->dos(host->ctx, ah) : 0;
}

static void dos_exit(int code) { st_exit((i16)code); }

static bool start_int(u8 n)
{
  u8 ah = (u8)(R.ax >> 8);
  if (n == 0x1A && ah == 0x00)  // the BIOS tick count
  {
    R.cx = 0;
    R.dx = host && host->biosTicks ? host->biosTicks(host->ctx) : 0;
    R.ax &= 0xFF00;
    return true;
  }
  if (n != 0x21) return false;
  static DosHost dh = { NULL, dos_answer, dos_exit, NULL };
  dh.gameDir = host ? host->gameDir : NULL;
  dos_attach(&dh);
  return dos_int21();
}
