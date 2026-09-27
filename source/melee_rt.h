// What melee_core.c calls outside the game's own code: the Microsoft C 5.0 run-time library functions it
// uses, the program's two assembly segments (1FE7: overlays, timer and keyboard hooks, line helpers; 2095:
// the picture decoder) and the host (controls, clock). Declared without parameter lists as the program
// called them with whatever it pushed.
#ifndef OPENSAMURAI_MELEE_RT_H
#define OPENSAMURAI_MELEE_RT_H

#include "dsimage.h"
#include "melee.h"

// C run-time library (1000:E022-FE93)
u16 f_e19a();  // exit
u16 f_e5b4();  // printf
u16 f_f5a0();  // strcpy
u16 f_f72c();  // perror
u16 f_f7aa();  // kbhit
u16 f_f7d6();  // DOS call wrapper
u16 f_f854();  // intdos
u16 f_f89c();  // memmove
u16 f_f8ba();  // ftime
u16 f_fc42();  // strnicmp
u16 f_fcfa();  // srand
u16 f_fd0c();  // rand
u16 f_fd32();  // DOS close
u16 f_fd47();  // DOS open
u16 f_fd60();  // DOS creat
u16 f_fd78();  // DOS read
u16 f_fd7f();  // DOS write

// assembly segments
u16 FUN_1fe7_0004();
u16 FUN_1fe7_0049();
u16 FUN_1fe7_0088();
u16 FUN_1fe7_00e0();
u16 FUN_1fe7_0216();
u16 FUN_1fe7_0254();
u16 FUN_1fe7_0492();
u16 FUN_1fe7_058b();
u16 FUN_1fe7_0620();
u16 FUN_1fe7_06e8();
u16 FUN_2095_000c();
u16 FUN_2095_008d();

// function entries, for comparing the flow with the original's instruction traces (tests)
#define FN(addr) \
  do { \
    if (melee_trace) melee_trace(addr); \
  } while (0)

// the host of the running melee (melee_rt.c)
extern const MeleeHost *melee_host;
void melee_read_controls(int fire);  // puts the host's controls into DS:398C-398F

#endif
