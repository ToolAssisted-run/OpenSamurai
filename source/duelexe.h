// The duel (DUEL.EXE) as the program the launcher runs: recompiled whole (duelexe_core.c) over an image of its data
// segment. (duel.c is the duel's simulation, reconstructed readably; this is the whole program, its screens too.)
#ifndef OPENSAMURAI_DUELEXE_H
#define OPENSAMURAI_DUELEXE_H

#include <stdint.h>

// What the program takes from the outside world while it runs
typedef struct
{
  // the answers: DOS (2Ah date, 2Ch time: CX << 16 | DX; 0Bh kbhit: AL), the BIOS (0x1600 + AH: INT 16h's AX
  // (AH 1: 0 if no key); 0x1100: INT 11h's AX; 0x1A00: the tick count, CX << 16 | DX), MISC's slots (90 key waiting,
  // 91 the key, 95 a button, 96/97 the axes)
  uint32_t (*answer)(void *ctx, int what);
  // the frame wait (the duel loop until 7 ticks have passed, 1000:1514): the host sets the frame timer's bytes
  // DS:22A6-22C8 as they are when the wait ends
  void (*framePoll)(void *ctx);
  // the keyboard joystick's bytes DS:22F2-22FB (the INT 9 handler's) as the frame reads them (1000:0A3E, 109D)
  void (*keyboardPoll)(void *ctx, int site);
  void (*exit)(void *ctx, int code);  // exit() (1 back to RP, 0 quit, 99 a file error): may return
  const char *gameDir;
  void *ctx;
  // the random generator's seed (main's srand(time() & 0x7FFF), 1000:200A): its value, 0..7FFFh (NULL: time()'s)
  uint16_t (*seed)(void *ctx);
} DuelHost;

#define DUEL_DS 0x2DF6  // the data segment in the oracle's layout (Ghidra's 162A)

void duel_attach(uint8_t *ds, uint16_t sharedSeg, const DuelHost *host);
// from the entry (1000:35BE, the C library's start-up) as DOS starts it: DS = ES = the PSP, the header's stack
void duel_entry(uint16_t psp, uint16_t ss, uint16_t sp);
// from main (1000:0010) with the registers SP BP SI DI ES AX BX CX DX there
void duel_main(const uint16_t regs[9]);

extern void (*duel_trace)(uint32_t addr);
// the cheats' hook (cheats.c), at the same function entries: 1 = the function is skipped (the hook popped its
// return address)
extern int (*duel_cheat)(uint32_t addr);

#endif
