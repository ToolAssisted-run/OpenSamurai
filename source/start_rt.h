// What start_core.c (START.EXE recompiled) calls outside the program's machine code: start_rt.c
#ifndef OPENSAMURAI_START_RT_H
#define OPENSAMURAI_START_RT_H

#include <setjmp.h>

#include "dsimage.h"
#include "start.h"

// function entries, for comparing the flow with the original's instruction traces (tests)
#define FN(addr) \
  do { \
    if (start_trace) start_trace(addr); \
  } while (0)

// a far call through a driver stub (DS:1BD0 + 5 slot), with the caller's far return address on the stack
void start_driver(int slot);
// a far call through a pointer (start_core.c)
void st_far_call(u16 seg, u16 off);
// a frame wait's poll of the timer's frame counter DS:1BA8 (the loop at 1000:site)
u8 st_frame_poll(u16 site);
// setjmp() with its buffer at DS:buf (the recompiled one filled it): the host's buffer that goes with it;
// longjmp() (the recompiled one restored the registers): back to the setjmp
jmp_buf *st_jmpbuf(u16 buf);
void st_longjmp(u16 buf);
// main's body (start_core.c)
void st_main_body(void);
// the start-up (start_core.c)
void st_crt0_body(void);

// kept in C: the picture decoder (1757), int86(), exit()
u16 st_PicHeader(void);
u16 st_DatHeader(void);
void st_LzwDecodeFar(u16 off, u16 seg, u16 n);
void st_LzwDecodeRow(i16 dst);
i16 st_int86(i16 n, i16 in, i16 out);
void st_exit(i16 code);

#endif
