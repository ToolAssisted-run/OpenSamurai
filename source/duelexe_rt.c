// What DUEL.EXE (recompiled: duelexe_core.c) needs outside its machine code: the drivers (MGRAPHIC recompiled;
// MISC's answers from the host; the no-sound driver), DOS (dos.c; the clock and kbhit from the host), the BIOS
// (keyboard, equipment, ticks: the host's answers), the frame timer's and the keyboard joystick's bytes at the
// frame (the host), the picture decoder (lzw.c) and exit().
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#include "asm2c.h"
#include "dos.h"
#include "dosmem.h"
#include "duelexe.h"
#include "duelexe_rt.h"
#include "lzw.h"

// (the run-time's own functions are traced but never skipped: some return a value)
#undef FN
#define FN(addr) \
  do { \
    if (duel_trace) duel_trace(addr); \
  } while (0)

#define DUEL_CS 0x27CC
#define DUEL_PSP 0x27BC

static const DuelHost *host;
void (*duel_trace)(uint32_t addr);
int (*duel_cheat)(uint32_t addr);
static jmp_buf exitJump;
static bool exitArmed;

static bool duel_int(u8 n);

void duel_attach(uint8_t *ds, uint16_t sharedSeg, const DuelHost *h)
{
  g_ds = ds;
  g_dsSeg = DUEL_DS;
  g_sharedSeg = sharedSeg;
  host = h;
  asm_int_hook = duel_int;
  dos_owner = DUEL_PSP;
}

static uint32_t answer(int what) { return host && host->answer ? host->answer(host->ctx, what) : 0; }

void duel_entry(uint16_t psp, uint16_t ss, uint16_t sp)
{
  R = (Regs){ 0 };
  R.ds = R.es = psp;
  R.ss = ss;
  R.sp = g_sp = sp;
  R.cs = DUEL_CS;
  exitArmed = true;
  if (!setjmp(exitJump)) du_crt0_body();
  exitArmed = false;
}

void duel_main(const uint16_t regs[9])
{
  R = (Regs){ 0 };
  R.sp = g_sp = regs[0];
  R.bp = regs[1];
  R.si = regs[2];
  R.di = regs[3];
  R.es = regs[4];
  R.ax = regs[5];
  R.bx = regs[6];
  R.cx = regs[7];
  R.dx = regs[8];
  R.ds = R.ss = DUEL_DS;
  R.cs = DUEL_CS;
  exitArmed = true;
  if (!setjmp(exitJump))
  {
    du_main_body();
    du_exit((i16)R.ax);  // main returned: the start-up's exit(main's value)
  }
  exitArmed = false;
}

void du_exit(i16 code)
{
  FN(0x10003734);
  dos_close_all();
  if (host && host->exit) host->exit(host->ctx, code);
  if (exitArmed) longjmp(exitJump, 1);
  exit(code);
}

// ---------------------------------------------------------------- the drivers

void mg_slot(int slot);

static void gfx_call(int slot, u16 a0, u16 a1)
{
  u16 sp = R.sp;
  R.sp = g_sp;
  PUSH(a1);
  PUSH(a0);
  PUSH(DUEL_CS);
  PUSH(0);
  mg_slot(slot);
  R.sp = sp;
}

void du_driver(int slot)
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
  case 90:
  case 91:
  case 95:
  case 96:
  case 97:
    R.ax = (u16)answer(slot);
    break;
  case 102:  // the no-sound driver: its tick asks for no fast timer
  case 105:  // its hardware check: present
    R.ax = 0;
    break;
  default:
    break;
  }
  R.sp += 4;
}

u16 du_frame_poll(u16 site)
{
  (void)site;
  if (host && host->framePoll) host->framePoll(host->ctx);
  return *P16(0x22C2);
}

u8 du_kbd_poll(u16 site)
{
  if (host && host->keyboardPoll) host->keyboardPoll(host->ctx, site);
  return *P8(0x22F2);
}

// ---------------------------------------------------------------- the picture decoder (15ff): lzw.c

void du_far_call(u16 seg, u16 off);
static void du_lzw_palette(u16 at) { gfx_call(25, 0, at); }
// DS:3046 the string table, 484C-485E the decoder's variables, its stack below DS:4A5F, 4846/4848/484A width,
// height, length; the input: the stream at DS:4DBC (end DS:26C4), refilled through the far pointer at DS:61EA.
// DUEL's version knows only the 16-byte palette
static const LzwLayout duLzw = { 0x3046, 0x484c, 0x4a5f, 0x484e, 0x4850, 0x4852, 0x4854, 0x4856, 0x4858, 0x485b, 0x485c,
                                 0x4846, 0x4dbc, 0x26c4, 0x61ea, 0x2dcb, false, du_lzw_palette, du_far_call };

u16 du_PicHeader(void)
{
  FN(0x15FF000C);
  return lzw_pic_header(&duLzw);
}

u16 du_DatHeader(void)
{
  FN(0x15FF008D);
  return lzw_dat_header(&duLzw);
}

void du_LzwDecodeFar(u16 off, u16 seg, u16 n)
{
  FN(0x15FF00D5);
  lzw_decode(&duLzw, off, seg, n);
}

void du_LzwDecodeRow(i16 dst)
{
  FN(0x15FF00EF);
  lzw_decode(&duLzw, (u16)dst, g_dsSeg, *P16(0x4846));
}

// ---------------------------------------------------------------- DOS and the BIOS

static uint32_t dos_answer(void *ctx, int ah)
{
  (void)ctx;
  return answer(ah);
}

static void dos_exit(int code) { du_exit((i16)code); }

static bool duel_int(u8 n)
{
  u8 ah = (u8)(R.ax >> 8);
  if (n == 0x1A && ah == 0x00)  // the BIOS tick count
  {
    u32 t = answer(0x1A00);
    R.cx = (u16)(t >> 16);
    R.dx = (u16)t;
    R.ax &= 0xFF00;
    return true;
  }
  if (n == 0x16)  // the BIOS keyboard: 0 the next key, 1 a key waiting (ZF clear) and which
  {
    u32 v = answer(0x1600 + ah);
    R.ax = (u16)v;
    if (ah == 1 || ah == 0x11) R.zf = (v >> 16) != 0;
    return true;
  }
  if (n == 0x11)  // the equipment
  {
    R.ax = (u16)answer(0x1100);
    return true;
  }
  if (n != 0x21) return false;
  static DosHost dh = { NULL, dos_answer, dos_exit, NULL };
  dh.gameDir = host ? host->gameDir : NULL;
  dos_attach(&dh);
  return dos_int21();
}

// main's seed (1000:200A): the host's, else time()'s
u16 du_seed(u16 fromTime) { return host && host->seed ? (u16)(host->seed(host->ctx) & 0x7FFF) : fromTime; }
