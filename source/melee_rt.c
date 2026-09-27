// The run-time library functions, assembly helpers and host hooks melee_core.c needs. Only what the
// simulation depends on is real: the random numbers (the library's seed words at DS:51AC), the clock seed,
// the controls. Files, drivers, interrupts belong to the frontend and do nothing here.
#include "melee_rt.h"

const MeleeHost *melee_host;
void (*melee_trace)(uint16_t addr);

// rand(): the Microsoft C generator, its 32-bit state at DS:51AC
u16 f_fd0c(void)
{
  u32 s = *P32(0x51AC) * 214013u + 2531011u;
  *P32(0x51AC) = s;
  return (u16)((s >> 16) & 0x7FFF);
}

// srand(seed): the state's low word = seed, high word 0. The host sees every seeding (the replay checks
// the order and the values against the real game's)
u16 f_fcfa(int seed)
{
  if (melee_host && melee_host->seeded) melee_host->seeded(melee_host->ctx, (uint16_t)seed);
  *P16(0x51AC) = (u16)seed;
  *P16(0x51AE) = 0;
  return 0;
}

// ftime(): only its millitm (hundredths of a second * 10) is used, as the random seed (1000:4E5C)
u16 f_f8ba(int ptr)
{
  u16 ms = melee_host && melee_host->clockSeed ? melee_host->clockSeed(melee_host->ctx) : 0;
  *P32(ptr) = 0;
  *P16(ptr + 4) = ms;
  *P16(ptr + 6) = 0;
  *P16(ptr + 8) = 0;
  return 0;
}

void melee_read_controls(int fire)
{
  MeleeInput in = { 0, 0, 0, 0 };
  if (melee_host && (fire ? melee_host->fire : melee_host->direction)) in = (fire ? melee_host->fire : melee_host->direction)(melee_host->ctx);
  *PS8(0x398C) = in.x;
  *PS8(0x398D) = in.y;
  *P8(0x398E) = in.enter;
  *P8(0x398F) = in.backspace;
}

// the rest: no effect on the simulation
u16 f_e19a(void) { return 0; }
u16 f_e5b4(void) { return 0; }
u16 f_f5a0(void) { return 0; }
u16 f_f72c(void) { return 0; }
u16 f_f7aa(void) { return 0; }
u16 f_f7d6(void) { return 0; }
u16 f_f854(void) { return 0; }
u16 f_f89c(void) { return 0; }
u16 f_fc42(void) { return 0; }
u16 f_fd32(void) { return 0; }
u16 f_fd47(void) { return 0xFFFF; }
u16 f_fd60(void) { return 0xFFFF; }
u16 f_fd78(void) { return 0; }
u16 f_fd7f(void) { return 0; }
u16 FUN_1fe7_0004(void) { return 0; }
u16 FUN_1fe7_0049(void) { return 0; }
u16 FUN_1fe7_0088(void) { return 0; }
u16 FUN_1fe7_00e0(void) { return 0; }
u16 FUN_1fe7_0216(void) { return 0; }
u16 FUN_1fe7_0254(void) { return 0; }
u16 FUN_1fe7_0492(void) { return 0; }
u16 FUN_1fe7_058b(void) { return 0; }
u16 FUN_1fe7_0620(void) { return 0; }
u16 FUN_1fe7_06e8(void) { return 0; }
u16 FUN_2095_000c(void) { return 0; }
u16 FUN_2095_008d(void) { return 0; }
