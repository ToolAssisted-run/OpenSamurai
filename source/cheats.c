// Cheats (cheats.h): what each does to the original programs, at the places docs/FINDINGS.md (5.14) and the
// workspace's reports describe. The hooks run at a function's entry, before its first instruction: SS:SP points at
// the return address, the arguments above it (the programs' functions are C, their callers pop the arguments).
#include "cheats.h"

#include "asm2c.h"

uint8_t *far_ptr(uint16_t seg, uint16_t off);

GameCheats game_cheats = { .walkMap = 1, .walkMelee = 1, .fasterTroops = 1 };

static uint16_t rd16(uint16_t seg, uint16_t off)
{
  const uint8_t *p = far_ptr(seg, off);
  return (uint16_t)(p[0] | p[1] << 8);
}
static void wr16(uint16_t seg, uint16_t off, uint16_t v)
{
  uint8_t *p = far_ptr(seg, off);
  p[0] = (uint8_t)v, p[1] = (uint8_t)(v >> 8);
}
static uint32_t rd32(uint16_t seg, uint16_t off) { return rd16(seg, off) | (uint32_t)rd16(seg, (uint16_t)(off + 2)) << 16; }
static void wr32(uint16_t seg, uint16_t off, uint32_t v) { wr16(seg, off, (uint16_t)v), wr16(seg, (uint16_t)(off + 2), (uint16_t)(v >> 16)); }
static uint16_t arg(int k) { return rd16(R.ss, (uint16_t)(R.sp + 2 + 2 * k)); }  // a near function's argument k

// ---------------------------------------------------------------- RP (DS 41E2)

// the character records (0x60 bytes; the player is record 0): RP keeps a master block and a working block and copies
// one to the other around its turns; +02 age (tenths of a year), +0E honor, +10 troops, +12 swordsmanship,
// +14 generalship, +16 land, +18 four family words (bits 13+: the member's age, tenths of a year)
enum { RP_DS = 0x41E2, RP_MASTER = 0x653E, RP_WORKING = 0x7CE8 };

// the attributes held at their caps: troops, swordsmanship, generalship and land 1..128 at every rank (1568:05BC,
// 05E8, 0614, 0590); honor 1..112 before the family's bonuses (1568:0434: wife 4, heir 8, the other children 2 each),
// 128 at most. In both blocks, at every frame RP shows
void cheats_rp_frame(void)
{
  const struct { int on; uint16_t off; } held[] = {
    { game_cheats.maxHonor, 0x0E }, { game_cheats.maxTroops, 0x10 }, { game_cheats.maxSwordsmanship, 0x12 },
    { game_cheats.maxGeneralship, 0x14 }, { game_cheats.maxLand, 0x16 },
  };
  for (unsigned k = 0; k < sizeof held / sizeof *held; k++)
    if (held[k].on)
    {
      wr16(RP_DS, (uint16_t)(RP_MASTER + held[k].off), 128);
      wr16(RP_DS, (uint16_t)(RP_WORKING + held[k].off), 128);
    }
}

// the ageing (1568:013E, every turn): for characters 0..4 of the master block, each of the first n family words
// (n = the record's non-empty family words in the working block, 1568:000A) + 0x2000, the age + 1, and on a whole
// year (age % 10 == 0) the year's changes (the old age's losses, the player's "too old" at 90). Stopped for the player
// by taking back, at its entry, the tick it is about to add: the age stays, and a year never comes round (an age on a
// whole year is let through one tick first, so that the next is not)
// the travel encounters: every few seconds the walking loop rolls one (2706:0C0A: random(100) < 50, then the tile's
// row of types, random(8)), and offers it unless the trip's count of accepted encounters, DS:3DB4 (zeroed when the
// walk starts, 2706:0006), has reached 3. Without encounters, the roll finds that count at 3: the dice are thrown as
// before, nothing is offered. The count it had is put back when the cheat goes off during the walk
static int savedEncounters = -1;
static void rp_encounters(uint32_t addr)
{
  if (addr == 0x27060000) savedEncounters = -1;  // (a new walk: the game zeroes the count)
  if (addr != 0x27060C0A) return;
  if (game_cheats.noEncounters)
  {
    if (savedEncounters < 0) savedEncounters = rd16(RP_DS, 0x3DB4);
    wr16(RP_DS, 0x3DB4, 3);
  }
  else if (savedEncounters >= 0)
  {
    wr16(RP_DS, 0x3DB4, (uint16_t)savedEncounters);
    savedEncounters = -1;
  }
}

void cheats_rp_fn(uint32_t addr)
{
  rp_encounters(addr);
  if (addr != 0x1568013E || !game_cheats.stopAgeing) return;
  uint16_t age = rd16(RP_DS, RP_MASTER + 0x02);
  if (age % 10 != 0) wr16(RP_DS, RP_MASTER + 0x02, (uint16_t)(age - 1));
  int n = 0;
  for (int j = 0; j < 4; j++)
    if (rd32(RP_DS, (uint16_t)(RP_WORKING + 0x18 + 4 * j))) n++;
  for (int j = 0; j < n; j++)
  {
    uint32_t w = rd32(RP_DS, (uint16_t)(RP_MASTER + 0x18 + 4 * j));
    if (w >> 13) wr32(RP_DS, (uint16_t)(RP_MASTER + 0x18 + 4 * j), w - 0x2000);
  }
}

// the travel map's walking loop (2706:0000) waits for its timer byte DS:3038 to pass 2 (three frames) before each
// step; walking k times as fast, k - 1 of every k steps go without the wait. The loop is known by its frame: its
// caller's return address, 3DE7:0214 (261B:0136's call), at BP + 2
int cheats_rp_walk_step(void)
{
  static unsigned steps;
  int k = game_cheats.walkMap;
  if (k <= 1 || rd16(R.ss, (uint16_t)(R.bp + 2)) != 0x0214 || rd16(R.ss, (uint16_t)(R.bp + 4)) != 0x3DE7) return 0;
  if (*far_ptr(RP_DS, 0x3038) != 0) return 0;  // (the wait already under way: it goes on)
  if (++steps % (unsigned)k == 0) return 0;
  *far_ptr(RP_DS, 0x3038) = 3;
  return 1;
}

// ---------------------------------------------------------------- DUEL

// wound(fighter) (1000:1624, a near function): one wound (two for half the over-the-shoulder hacks), the knock-back,
// the fall at four (the fighters' counts DS:4DB8 + 2 × fighter). Invulnerable: for the player (0) it does not happen.
// One-blow kills: the opponent (1) enters it with three, so that this wound is his fourth
int cheats_duel_fn(uint32_t addr)
{
  if (addr != 0x10001624) return 0;
  if (arg(0) == 1 && game_cheats.oneBlowKills && (int16_t)rd16(R.ds, 0x4DBA) < 3) wr16(R.ds, 0x4DBA, 3);
  if (!game_cheats.invulnerableDuel || arg(0) != 0) return 0;
  R.sp = (uint16_t)(R.sp + 2);  // (the near return)
  return 1;
}

// ---------------------------------------------------------------- BATTLE

// the unit records (64 bytes, near pointers): +02 state (11 routed), +04 flags (bit 3: the enemy's), +2A the damage
// gathered this step, +30 the step's morale, +38 -1 for a volley. The damage pass (1000:0A1C(unit)) applies a unit's
// damage (a volley hands its damage to its target and applies it there): for the player's units there is none. The rout
// check (1000:2424(unit)) routs a unit whose morale is below 0 under attack: the player's units' morale is lifted to 0
// first. A routed unit (R's retreat, or a rout before the cheat) is left alone: the check would rally it at a morale
// above 0.
// Every unit's movement is one routine (1000:2802(unit)): it turns by at most +22, the turn rate (the type's, DS:1504 +
// 12 × type, set once), and when facing its way marches by the step's velocity: +20, the speed (the drawing pass
// 1000:49C8(unit) recomputes it every step from the type and the terrain), or for the formation's route (state 4)
// DS:26D8, the slowest route unit's speed (both armies'). Faster, the player's units enter it with the speed and the
// turn rate multiplied (the speed once a step) and the route's pace multiplied; the enemy's with the route's pace back
static int8_t speedScaled[25];
static int16_t routePace = -1;
static int fasterUsed;  // (until the cheat is first on, the movement is left alone)
void cheats_battle_fn(uint32_t addr)
{
  if (addr == 0x100049C8)  // (a new step: the speeds are recomputed, then the route's pace)
  {
    uint16_t i = (uint16_t)((arg(0) - 0x5E2A) >> 6);
    if (i < 25) speedScaled[i] = 0;
    routePace = -1;
    return;
  }
  if (addr != 0x10000A1C && addr != 0x10002424 && addr != 0x10002802) return;
  uint16_t u = arg(0);
  int enemy = (rd16(R.ds, (uint16_t)(u + 0x04)) & 8) != 0;
  if (addr == 0x10002802)
  {
    if (game_cheats.fasterTroops > 1) fasterUsed = 1;
    if (!fasterUsed) return;
    int k = enemy ? 1 : game_cheats.fasterTroops;
    if (routePace < 0) routePace = (int16_t)rd16(R.ds, 0x26D8);
    wr16(R.ds, 0x26D8, (uint16_t)(routePace * (rd16(R.ds, (uint16_t)(u + 0x02)) == 4 ? k : 1)));
    if (enemy) return;
    uint16_t i = (uint16_t)((u - 0x5E2A) >> 6);
    wr16(R.ds, (uint16_t)(u + 0x22), (uint16_t)(rd16(R.ds, (uint16_t)(0x1504 + 12 * (rd16(R.ds, (uint16_t)(u + 0x04)) & 7))) * k));
    if (k > 1 && i < 25 && !speedScaled[i])
    {
      wr16(R.ds, (uint16_t)(u + 0x20), (uint16_t)(rd16(R.ds, (uint16_t)(u + 0x20)) * k));
      speedScaled[i] = 1;
    }
    return;
  }
  if (enemy) return;
  if (addr == 0x10000A1C)
  {
    if (game_cheats.invulnerableTroops && rd16(R.ds, (uint16_t)(u + 0x38)) != 0xFFFF) wr16(R.ds, (uint16_t)(u + 0x2A), 0);
  }
  else if (game_cheats.troopsNeverRout && rd16(R.ds, (uint16_t)(u + 0x02)) != 11 && (int16_t)rd16(R.ds, (uint16_t)(u + 0x30)) < 0)
    wr16(R.ds, (uint16_t)(u + 0x30), 0);
}

// ---------------------------------------------------------------- MELEE

// The wound (1000:A7CC(entity, ...)) adds the blow's wounds (1 or 2, DS:235E) to the entity's count DS:9E18 + e,
// unless the entity is the player and the debug switch DS:3567 is set (its only other write clears it at the start,
// 1000:98D6): invulnerable is that switch. An entity dies at 2 wounds (1000:13B8, each pass): with one-blow kills
// any other entity enters the wound with one, so that this blow is its last.
// The walk: an entity's move timer (DS:0058 + 2e, ticks) reloads with the step delay (1000:1792: DS:2330, 2 ticks,
// times the terrain, the turn and the wounds) and the sub-step (1000:876E(e)) takes DS:3564 (1, a slow machine's 2)
// off the tile move's four (DS:AEFC + e). For the player that sub-step is made 2 or 4 (dividing what is left of the
// tile), and the rest of the speed comes from a shorter delay; for the others it stays the game's
static uint8_t meleeStep, meleeWritten;
void cheats_melee_fn(uint32_t addr)
{
  if (addr == 0x1000A7CC)
  {
    *far_ptr(R.ds, 0x3567) = game_cheats.invulnerableMelee ? 1 : 0;
    uint8_t e = (uint8_t)arg(0), *wounds = far_ptr(R.ds, (uint16_t)(0x9E18 + e));
    if (e != 0 && e < 7 && game_cheats.oneBlowKills && *wounds < 1) *wounds = 1;
    return;
  }
  if (addr != 0x1000876E) return;
  uint8_t *step = far_ptr(R.ds, 0x3564);
  if (*step != meleeWritten || !meleeStep) meleeStep = *step;  // (the game's own: 1, or 2)
  int e = (uint8_t)arg(0), want = meleeStep, s = meleeStep;
  if (e == 0 && game_cheats.walkMelee > 1)
  {
    want = meleeStep * game_cheats.walkMelee;
    uint8_t left = *far_ptr(R.ds, 0xAEFC);
    for (s = 4; s > meleeStep && (s > want || left % s); s /= 2) {}
    if (want / s > 1)
    {
      uint16_t t = (uint16_t)(rd16(R.ds, 0x0058) / (want / s));
      wr16(R.ds, 0x0058, t ? t : 1);
    }
  }
  *step = meleeWritten = (uint8_t)s;
}
