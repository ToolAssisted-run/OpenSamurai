// The Microsoft C 5.1 run-time library's rand(): every program of the game uses it (through rand() or the
// game's random(n) = (rand() * n) >> 15), each with its own seed.
#ifndef OPENSAMURAI_MSRAND_H
#define OPENSAMURAI_MSRAND_H

#include <stdint.h>

typedef struct
{
  uint32_t holdrand;  // the library's 32-bit state, a DWORD in the program's data segment
} MsRand;

static inline void msrand_seed(MsRand *r, uint32_t seed) { r->holdrand = seed; }

// rand(): 0..32767
static inline int msrand_next(MsRand *r)
{
  r->holdrand = r->holdrand * 214013u + 2531011u;
  return (int)((r->holdrand >> 16) & 0x7FFF);
}

// The game's random(n) = (rand() * n) >> 15 with a 32-bit product: 0..n-1 (random(0) = 0 still advances)
static inline int msrand_random(MsRand *r, int n) { return (int)(((int32_t)msrand_next(r) * (int32_t)(int16_t)n) >> 15); }

#endif
