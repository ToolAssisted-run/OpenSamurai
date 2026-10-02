// Cheats (the frontend's menu sets them, game.c applies them). Each acts on the original programs at a known place,
// through the recompiled programs' function entries (FN) or the frames, and changes nothing while it is off. None of
// them touches the copy protection or its consequences (the crest quiz, the lord's reign: shared+2E, RP's DS:812E and
// DS:7F34).
#ifndef OPENSAMURAI_CHEATS_H
#define OPENSAMURAI_CHEATS_H

#include <stdint.h>

typedef struct
{
  int invulnerableMelee;   // MELEE: the player takes no wound (its own debug switch DS:3567, at the wound 1000:A7CC)
  int invulnerableDuel;    // DUEL: the player's wound (1000:1624: the wound, the knock-back, the fall) does not happen
  int oneBlowKills;        // DUEL, MELEE: the player's first blow fells the opponent (the wound routines' counts)
  int invulnerableTroops;  // BATTLE: the player's units lose no men to damage (1000:0A1C applies none)
  int troopsNeverRout;     // BATTLE: the player's units never rout on their own (1000:2424); R's retreat still works
  int fasterTroops;        // BATTLE: the player's units march and turn 1, 2, 4 or 8 times as fast (1000:2802)
  int walkMap;             // RP: the travel map's walk 1, 2, 4 or 8 times as fast (the walking loop 2706:0000)
  int noEncounters;        // RP: no encounters on the travel map (the roll 2706:0C0A finds the trip's three used)
  int walkMelee;           // MELEE: the player walks 1, 2, 4 or 8 times as fast (the sub-step 1000:876E)
  int stealth;             // MELEE: while the alarm is off (castles, manors), nobody notices the player (1000:AA12, 6AC8)
  int stopAgeing;          // RP: the player and his family do not age (the ageing 1568:013E)
  int maxHonor;            // RP: the player's honor held at 128 (112, the honor routine's cap, plus the family's 16)
  int maxTroops;           // RP: the player's troops held at 128 (the troops routine's cap)
  int maxLand;             // RP: land held at 128
  int maxSwordsmanship;    // RP: swordsmanship held at 128
  int maxGeneralship;      // RP: generalship held at 128
} GameCheats;

extern GameCheats game_cheats;

// the hooks (game.c installs them): a function entry of each program; DUEL's and MELEE's return 1 when the function
// is skipped (its return address popped)
void cheats_rp_fn(uint32_t addr);
int cheats_duel_fn(uint32_t addr);
void cheats_battle_fn(uint32_t addr);
int cheats_melee_fn(uint32_t addr);
// RP's video frames (while RP runs): the attributes held
void cheats_rp_frame(void);
// RP's frame wait (DS:3038): 1 when the travel map's walking loop takes this step without waiting for its frames
int cheats_rp_walk_step(void);

#endif
