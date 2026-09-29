// What MELEE.EXE (recompiled: meleeexe_core.c) needs outside its machine code: the drivers (its EGRAPHIC.MEL and,
// for the end's message, MGRAPHIC, recompiled; MISC's answers from the host; the no-sound driver), DOS (dos.c; the
// clock from the host), the BIOS (the host's answers), the tick counter and the keyboard joystick (the host), the
// picture decoder (lzw.c) and exit().
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#include "asm2c.h"
#include "dos.h"
#include "dosmem.h"
#include "meleeexe.h"
#include "meleeexe_rt.h"
#include "lzw.h"

#define MELEE_CS 0x27CC
#define MELEE_PSP 0x27BC

static const MeleeExeHost *host;
void (*meleeexe_trace)(uint32_t addr);
static jmp_buf exitJump;
static bool exitArmed;

static bool meleeexe_int(u8 n);

void meleeexe_attach(uint8_t *ds, uint16_t sharedSeg, const MeleeExeHost *h)
{
  g_ds = ds;
  g_dsSeg = MELEE_DS;
  g_sharedSeg = sharedSeg;
  host = h;
  asm_int_hook = meleeexe_int;
  dos_owner = MELEE_PSP;
}

static uint32_t answer(int what) { return host && host->answer ? host->answer(host->ctx, what) : 0; }

void meleeexe_entry(uint16_t psp, uint16_t ss, uint16_t sp)
{
  R = (Regs){ 0 };
  R.ds = R.es = psp;
  R.ss = ss;
  R.sp = g_sp = sp;
  R.cs = MELEE_CS;
  exitArmed = true;
  if (!setjmp(exitJump)) ml_crt0_body();
  exitArmed = false;
}

void meleeexe_main(const uint16_t regs[9])
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
  R.ds = R.ss = MELEE_DS;
  R.cs = MELEE_CS;
  exitArmed = true;
  if (!setjmp(exitJump))
  {
    ml_main_body();
    ml_exit((i16)R.ax);  // main returned: the start-up's exit(main's value)
  }
  exitArmed = false;
}

void ml_exit(i16 code)
{
  FN(0x1000E19A);
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
  PUSH(MELEE_CS);
  PUSH(0);
  mg_slot(slot);
  R.sp = sp;
}

void eg_slot(int slot);
void ml_driver(int slot)
{
  if (slot < 48)
  {
    // the stub says which graphics driver: its own (EGRAPHIC.MEL at 4887) or the launcher's (MGRAPHIC, bound again
    // for the end's message)
    if (*P16((u16)(0x46CC + 5 * slot + 3)) == 0x19BD) mg_slot(slot);
    else eg_slot(slot);
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

// the tick counter as the program reads it (the interrupt's): its memory too
u16 ml_ticks(u16 site)
{
  if (host && host->ticks) *P16(0x53) = host->ticks(host->ctx, site);
  return *P16(0x53);
}

// a seed (1000:4E5C): the host's, else the clock's
u8 ml_seed(u8 fromClock) { return host && host->seed ? host->seed(host->ctx) : fromClock; }

void ml_step(void)
{
  if (host && host->step) host->step(host->ctx);
}

u8 ml_kbd_poll(u16 site)
{
  if (host && host->keyboardPoll) host->keyboardPoll(host->ctx, site);
  return *P8(site == 0x9F4F ? 0x398F : 0x398D);
}

// ---------------------------------------------------------------- the picture decoder (2095): lzw.c

static void ml_lzw_palette(u16 at) { gfx_call(25, 0, at); }
// DS:5548 the string table, 6D4C-6D5E the decoder's variables, its stack below DS:6F5F, 6D48/6D4A width, height;
// the input: the stream at DS:8738 (end DS:4E00), refilled through the far pointer at DS:9BB2. The older version:
// pictures only, the 16-byte palette
static const LzwLayout baLzw = { 0x5548, 0x6d4c, 0x6f5f, 0x6d4e, 0x6d50, 0x6d52, 0x6d54, 0x6d56, 0x6d58, 0x6d5b, 0x6d5c,
                                 0x6d48, 0x8738, 0x4e00, 0x9bb2, 0x3861, false, ml_lzw_palette, ml_far_call };

u16 ml_PicHeader(void)
{
  FN(0x2095000C);
  return lzw_pic_header(&baLzw);
}

void ml_LzwDecodeRow(i16 dst)
{
  FN(0x2095008D);
  lzw_decode(&baLzw, (u16)dst, g_dsSeg, *P16(0x6D48));
}

// ---------------------------------------------------------------- DOS and the BIOS

static uint32_t dos_answer(void *ctx, int ah)
{
  (void)ctx;
  return answer(ah);
}

static void dos_exit(int code) { ml_exit((i16)code); }

static bool meleeexe_int(u8 n)
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
