// The melee (MELEE.EXE) as the program the launcher runs: recompiled whole (meleeexe_core.c) over an image of its data
// segment, with its own graphics driver (EGRAPHIC.MEL recompiled: egraphic.c). (melee_core.c is the melee
// translated readably and verified; this is the whole program.)
#ifndef OPENSAMURAI_MELEEEXE_H
#define OPENSAMURAI_MELEEEXE_H

#include <stdint.h>

// What the program takes from the outside world while it runs
typedef struct
{
  // the answers: DOS (2Ah date, 2Ch time: CX << 16 | DX; 0Bh kbhit: AL), the BIOS (0x1600 + AH: INT 16h's AX
  // (AH 1: 0 if no key); 0x1100: INT 11h's AX; 0x1A00: the tick count, CX << 16 | DX), MISC's slots (90 key waiting,
  // 91 the key, 95 a button, 96/97 the axes)
  uint32_t (*answer)(void *ctx, int what);
  // the 60 Hz tick counter DS:53 (the timer interrupt's) read at 1000:site (072B the speed calibration's loop,
  // 3BC2 each pass of the main loop): its value then
  uint16_t (*ticks)(void *ctx, int site);
  // the keyboard joystick's bytes DS:398C-398F (the INT 9 handler's) as they are when read (9F4F the button, 9F8A
  // the direction)
  void (*keyboardPoll)(void *ctx, int site);
  // an elapsed tick's timer decrement begins (1000:07C2): a checkpoint
  void (*step)(void *ctx);
  void (*exit)(void *ctx, int code);  // exit() (1 back to RP, 0 quit, 99 a file error): may return
  const char *gameDir;
  void *ctx;
  // the random generator's seeds (1000:4E5C's srand of ftime()'s milliseconds' low byte, at each of its calls): the
  // byte (NULL: the clock's)
  uint8_t (*seed)(void *ctx);
} MeleeExeHost;

#define MELEE_DS 0x3886  // the data segment in the oracle's layout (Ghidra's 20BA)

void meleeexe_attach(uint8_t *ds, uint16_t sharedSeg, const MeleeExeHost *host);
// from the entry (1000:E022, the C library's start-up) as DOS starts it: DS = ES = the PSP, the header's stack
void meleeexe_entry(uint16_t psp, uint16_t ss, uint16_t sp);
// from main (1000:0010) with the registers SP BP SI DI ES AX BX CX DX there
void meleeexe_main(const uint16_t regs[9]);

extern void (*meleeexe_trace)(uint32_t addr);

#endif
