// What duelexe_core.c (DUEL.EXE recompiled) calls outside its machine code: duelexe_rt.c
#ifndef OPENSAMURAI_DUELEXE_RT_H
#define OPENSAMURAI_DUELEXE_RT_H

#include "dsimage.h"
#include "duelexe.h"

// (the functions are void, and FN is their first statement: a skipped one returns at once)
#define FN(addr) \
  do { \
    if (duel_trace) duel_trace(addr); \
    if (duel_cheat && duel_cheat(addr)) return; \
  } while (0)

void du_driver(int slot);
void du_far_call(u16 seg, u16 off);
u16 du_frame_poll(u16 site);
u8 du_kbd_poll(u16 site);
void du_crt0_body(void);
void du_main_body(void);

u16 du_PicHeader(void);
u16 du_DatHeader(void);
void du_LzwDecodeFar(u16 off, u16 seg, u16 n);
void du_LzwDecodeRow(i16 dst);
void du_exit(i16 code);
u16 du_seed(u16 fromTime);

#endif
