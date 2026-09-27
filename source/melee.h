// The melee (MELEE.EXE): one samurai against guards, ninja, bandits in castles of 1-3 floors, villages and
// rice paddies, from above. Its program keeps everything in parallel arrays at fixed places of its data
// segment (7 entities, 154 cells per floor, 77x98 tiles, 77 countdown timers at 60 Hz), and so does the
// reconstruction: melee_core.c works on an image of that segment, which keeps it next to the original and
// makes its state directly comparable with the real game's.
#ifndef OPENSAMURAI_MELEE_H
#define OPENSAMURAI_MELEE_H

#include <stdint.h>

#define MELEE_DS_SIZE 0x10000

// Controls, as the keyboard hook leaves them (DS:398C-398F): x and y axes -127..127, Enter, Backspace held
typedef struct { int8_t x, y; uint8_t enter, backspace; } MeleeInput;

// What the program takes from the outside world while it runs
typedef struct
{
  MeleeInput (*direction)(void *ctx);         // the player's direction is read (1000:9F8A)
  MeleeInput (*fire)(void *ctx);              // the fire button is read (1000:9F4E)
  uint16_t (*clockSeed)(void *ctx);           // the DOS clock's hundredths * 10, a random seed (ftime)
  void (*seeded)(void *ctx, uint16_t seed);   // srand() was called (a replay checks the order)
  void *ctx;
} MeleeHost;

// Use this data segment image and host for the calls below (the image must be MELEE_DS_SIZE bytes)
void melee_attach(uint8_t *ds, const MeleeHost *host);

// One whole pass of the game loop (1000:006A-00A7): entities, path maps, projectiles, (drawing), the clock
// advanced by the given ticks, music, reinforcements, alerts, keys. Returns nonzero when the loop ends.
int melee_pass(int elapsedTicks);

// For replays of captures taken at the timer routine (1000:07C2): the pass split there. melee_pass_start
// runs a pass up to its first timer decrement (the tick counter DS:0053 must already hold the new value);
// melee_pass_finish runs the rest of a pass that stopped there.
void melee_pass_start(void);
void melee_pass_finish(void);

// Called with the original address (1000:XXXX) of every function of the program as it is entered, when set
extern void (*melee_trace)(uint16_t addr);

#endif
