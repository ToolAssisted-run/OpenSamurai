// The role-playing game (RP.EXE): the strategy layer, where the samurai's life and career happen between the
// action games. Its program keeps its state in its data segment (the characters, the provinces, the clans, the
// messages) and the shared block, and so does the reconstruction: rp_core.c works on an image of that segment,
// which keeps it next to the original and makes its state directly comparable with the real game's.
#ifndef OPENSAMURAI_RP_H
#define OPENSAMURAI_RP_H

#include <stdbool.h>
#include <stdint.h>

#define RP_DS_SIZE 0x10000

// What the program takes from the outside world while it runs
typedef struct
{
  uint32_t (*time)(void *ctx);         // time(): seconds
  int (*keyWaiting)(void *ctx);        // a key is in the keyboard buffer (MISC slot 90)
  uint16_t (*readKey)(void *ctx);      // the next key, scan code << 8 | ASCII (MISC slot 91)
  // the program waits for the timer interrupt's frame flag (DS:3038): the host lets the frames pass, setting
  // the bytes the interrupt handlers keep (DS:3038-303F timer, DS:3398-339F keyboard, DS:6EF0-6EF1 joystick)
  // as they are when the wait ends, if the flag (current value given) is not what the program waits for
  void (*framePoll)(void *ctx, uint8_t flag);
  void (*seeded)(void *ctx, uint16_t seed);  // srand() was called
  uint16_t (*biosTicks)(void *ctx);          // the BIOS tick count (the random seed at start-up)
  void (*exit)(void *ctx, int code);         // exit(): does not return
  // a sub-game (1 duel, 2 battle, 3 melee) with the parameters in the shared block, which it leaves its results in;
  // with restart, it does not return: the host runs RP again from main (rp_main), whose resume (RestoreContext)
  // goes back to where RP hibernated
  void (*subgame)(void *ctx, int code);
  const char *gameDir;                       // the game's files
  void *ctx;
  bool restart;  // the host restarts RP after a sub-game (see subgame); else RP resumes at once (the tests)
  bool writeFiles;  // the saved games (TALLTALE.DAT) are written to gameDir (else the writes succeed without a file)
  // delay(n) (29F7:0048: it spins until the timer's frame count DS:3038 has gone n further): the host lets the n
  // frames pass (NULL: the counts are advanced at once, without the time; the tests)
  void (*delay)(void *ctx, int frames);
} RpHost;

// Use this data segment image (RP_DS_SIZE bytes) and host for the calls below; dsSeg and sharedSeg are the
// segments of the data segment and of the shared block (the far pointers in the data hold them)
void rp_attach(uint8_t *ds, uint16_t dsSeg, uint16_t sharedSeg, const RpHost *host);

// The first free paragraph of the DOS memory arena (where the program's buffers are allocated) and its end
void rp_set_arena(uint16_t first, uint16_t end);
// ... or the arena as DOS keeps it in memory (its chain of control blocks) between paragraphs from and to
void rp_arena_from_memory(uint16_t from, uint16_t to);

// One tick of the main loop (from its top, 106a:0048, to its next pass there): the next character's turn,
// ageing, events. regs: SP BP SI DI ES AX BX CX DX there (the loop keeps nothing in SI and DI, but the program
// pushes them before it sets them: their values stay in the stack); SP is DS:9736 once the game runs
void rp_tick(const uint16_t regs[9]);

// The program ended: its files closed (DOS closes them)
void rp_close_files(void);

// RP from main (1000:0000) as the C library's start-up calls it (regs as rp_tick's: its far return address and
// main's arguments on the stack), until exit()
void rp_main(const uint16_t regs[9]);
// Called at every pass of the main loop's top (106a:0048), if set
extern void (*rp_tickHook)(void);

// Called with the original address (seg << 16 | off, Ghidra's segments) of every function as it is entered
extern void (*rp_trace)(uint32_t addr);
// the cheats' hook (cheats.c), at the same function entries
extern void (*rp_cheat)(uint32_t addr);

#endif
