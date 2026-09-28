// What meleeexe_core.c (MELEE.EXE recompiled) calls outside its machine code: meleeexe_rt.c
#ifndef OPENSAMURAI_MELEEEXE_RT_H
#define OPENSAMURAI_MELEEEXE_RT_H

#include "dsimage.h"
#include "meleeexe.h"

#define FN(addr) \
  do { \
    if (meleeexe_trace) meleeexe_trace(addr); \
  } while (0)

void ml_driver(int slot);
void ml_far_call(u16 seg, u16 off);
void ml_near_call(u16 off);
u16 ml_ticks(u16 site);
u8 ml_kbd_poll(u16 site);
void ml_crt0_body(void);
void ml_main_body(void);

u16 ml_PicHeader(void);
void ml_LzwDecodeRow(i16 dst);
void ml_exit(i16 code);

#endif
