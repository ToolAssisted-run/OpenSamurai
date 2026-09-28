// What BATTLE.EXE (recompiled: battleexe_core.c) needs outside its machine code: the drivers (MGRAPHIC recompiled;
// MISC's answers from the host; the no-sound driver), DOS (dos.c; the clock and kbhit from the host), the BIOS
// (keyboard, equipment, ticks: the host's answers), the frame counter (the host), the picture decoder (lzw.c) and
// exit().
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#include "asm2c.h"
#include "dos.h"
#include "dosmem.h"
#include "battleexe.h"
#include "battleexe_rt.h"
#include "lzw.h"

#define BATTLE_CS 0x27CC
#define BATTLE_PSP 0x27BC

static const BattleHost *host;
void (*battle_trace)(uint32_t addr);
static jmp_buf exitJump;
static bool exitArmed;

static bool battle_int(u8 n);

void battle_attach(uint8_t *ds, uint16_t sharedSeg, const BattleHost *h)
{
  g_ds = ds;
  g_dsSeg = BATTLE_DS;
  g_sharedSeg = sharedSeg;
  host = h;
  asm_int_hook = battle_int;
  dos_owner = BATTLE_PSP;
}

static uint32_t answer(int what) { return host && host->answer ? host->answer(host->ctx, what) : 0; }

void battle_entry(uint16_t psp, uint16_t ss, uint16_t sp)
{
  R = (Regs){ 0 };
  R.ds = R.es = psp;
  R.ss = ss;
  R.sp = g_sp = sp;
  R.cs = BATTLE_CS;
  exitArmed = true;
  if (!setjmp(exitJump)) ba_crt0_body();
  exitArmed = false;
}

void battle_main(const uint16_t regs[9])
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
  R.ds = R.ss = BATTLE_DS;
  R.cs = BATTLE_CS;
  exitArmed = true;
  if (!setjmp(exitJump))
  {
    ba_main_body();
    ba_exit((i16)R.ax);  // main returned: the start-up's exit(main's value)
  }
  exitArmed = false;
}

void ba_exit(i16 code)
{
  FN(0x1000708E);
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
  PUSH(BATTLE_CS);
  PUSH(0);
  mg_slot(slot);
  R.sp = sp;
}

void ba_driver(int slot)
{
  if (slot < 48)
  {
    mg_slot(slot);
    return;
  }
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

u16 ba_frames(void) { return host && host->frames ? host->frames(host->ctx) : *P16(0x1B44); }

void ba_bios_ticks(void)
{
  u32 t = answer(0x1A00);
  R.ax = (u16)t;
  R.dx = (u16)(t >> 16);
  *(u16a *)far_ptr(0x40, 0x6C) = R.ax;
  *(u16a *)far_ptr(0x40, 0x6E) = R.dx;
}

void ba_step(void)
{
  if (host && host->step) host->step(host->ctx);
}

// ---------------------------------------------------------------- the picture decoder (1911): lzw.c

static void ba_lzw_palette(u16 at) { gfx_call(25, 0, at); }
// DS:3014 the string table, 481A-482C the decoder's variables, its stack below DS:4A2D, 4814/4816/4818 width,
// height, length; the input: the stream at DS:6470 (end DS:2216), refilled through the far pointer at DS:668E
static const LzwLayout baLzw = { 0x3014, 0x481a, 0x4a2d, 0x481c, 0x481e, 0x4820, 0x4822, 0x4824, 0x4826, 0x4829, 0x482a,
                                 0x4814, 0x6470, 0x2216, 0x668e, 0x30dd, true, ba_lzw_palette, ba_far_call };

u16 ba_PicHeader(void)
{
  FN(0x1911000A);
  return lzw_pic_header(&baLzw);
}

u16 ba_DatHeader(void)
{
  FN(0x1911009A);
  return lzw_dat_header(&baLzw);
}

void ba_LzwDecodeFar(u16 off, u16 seg, u16 n)
{
  FN(0x191100E2);
  lzw_decode(&baLzw, off, seg, n);
}

void ba_LzwDecodeRow(i16 dst)
{
  FN(0x191100FC);
  lzw_decode(&baLzw, (u16)dst, g_dsSeg, *P16(0x4814));
}

// ---------------------------------------------------------------- DOS and the BIOS

static uint32_t dos_answer(void *ctx, int ah)
{
  (void)ctx;
  return answer(ah);
}

static void dos_exit(int code) { ba_exit((i16)code); }

static bool battle_int(u8 n)
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
