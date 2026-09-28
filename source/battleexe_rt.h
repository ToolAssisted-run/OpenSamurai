// What battleexe_core.c (BATTLE.EXE recompiled) calls outside its machine code: battleexe_rt.c
#ifndef OPENSAMURAI_BATTLEEXE_RT_H
#define OPENSAMURAI_BATTLEEXE_RT_H

#include "dsimage.h"
#include "battleexe.h"

#define FN(addr) \
  do { \
    if (battle_trace) battle_trace(addr); \
  } while (0)

void ba_driver(int slot);
void ba_far_call(u16 seg, u16 off);
void ba_near_call(u16 off);
u16 ba_frames(void);
void ba_step(void);
// the BIOS tick count read at 0040:006C (the terrain's seed): AX low, DX high
void ba_bios_ticks(void);
void ba_crt0_body(void);
void ba_main_body(void);

u16 ba_PicHeader(void);
u16 ba_DatHeader(void);
void ba_LzwDecodeFar(u16 off, u16 seg, u16 n);
void ba_LzwDecodeRow(i16 dst);
void ba_exit(i16 code);

#endif
