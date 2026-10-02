// The battle (BATTLE.EXE) as the program the launcher runs: recompiled whole (battleexe_core.c) over an image of its
// data segment. (battle.c is the battle's simulation, reconstructed readably; this is the whole program.)
#ifndef OPENSAMURAI_BATTLEEXE_H
#define OPENSAMURAI_BATTLEEXE_H

#include <stdint.h>

// What the program takes from the outside world while it runs
typedef struct
{
  // the answers: DOS (2Ah date, 2Ch time: CX << 16 | DX; 0Bh kbhit: AL), the BIOS (0x1600 + AH: INT 16h's AX
  // (AH 1: 0 if no key); 0x1100: INT 11h's AX; 0x1A00: the tick count, CX << 16 | DX), MISC's slots (90 key waiting,
  // 91 the key, 95 a button, 96/97 the axes)
  uint32_t (*answer)(void *ctx, int what);
  // the frame counter DS:1B44 (the timer's) read (1000:681E: the waits read it in a loop, polling the keys): its
  // value then
  uint16_t (*frames)(void *ctx);
  // a simulation step begins (the counter reset, 1000:6822)
  void (*step)(void *ctx);
  void (*exit)(void *ctx, int code);  // exit() (1 back to RP, 0 quit, 99 a file error): may return
  const char *gameDir;
  void *ctx;
  // the random generator's seed (1000:51DE: the BIOS's tick count, before each battlefield): its value (NULL: the
  // tick count's)
  uint32_t (*seed)(void *ctx);
} BattleHost;

#define BATTLE_DS 0x3109  // the data segment in the oracle's layout (Ghidra's 193D)

void battle_attach(uint8_t *ds, uint16_t sharedSeg, const BattleHost *host);
// from the entry (1000:6F18, the C library's start-up) as DOS starts it: DS = ES = the PSP, the header's stack
void battle_entry(uint16_t psp, uint16_t ss, uint16_t sp);
// from main (1000:0012) with the registers SP BP SI DI ES AX BX CX DX there
void battle_main(const uint16_t regs[9]);

extern void (*battle_trace)(uint32_t addr);
// the cheats' hook (cheats.c), at the same function entries
extern void (*battle_cheat)(uint32_t addr);

#endif
