// The duel (DUEL.EXE): two fighters driven by one animation state machine, the player by the controls and
// the opponent by a table-driven AI. One call of duel_frame() is one iteration of the original duel loop
// (1000:0594), i.e. one game frame of 7 video frames.
#ifndef OPENSAMURAI_DUEL_H
#define OPENSAMURAI_DUEL_H

#include <stdint.h>

#include "msrand.h"

#define DUEL_STATE_COUNT 133

// Animation states named in the text (full table: duel_tables.c)
enum
{
  DUEL_RAISED_CENTRE = 0x02,
  DUEL_KNOCKBACK     = 0x27,  // the step-back state a wound jumps to
  DUEL_CHACK_START   = 0x43,  // centre hack swing (+4 = impact 0x47)
  DUEL_CHACK_IMPACT  = 0x47,
  DUEL_CHACK_RECOIL  = 0x48,
  DUEL_RHACK_START   = 0x4F,
  DUEL_RHACK_IMPACT  = 0x53,
  DUEL_RHACK_RECOIL  = 0x54,
  DUEL_LHACK_START   = 0x5A,
  DUEL_LHACK_IMPACT  = 0x5E,
  DUEL_LHACK_RECOIL  = 0x5F,
  DUEL_RSLASH_TELE   = 0x6D,
  DUEL_RSLASH_IMPACT = 0x6F,
  DUEL_LSLASH_TELE   = 0x72,
  DUEL_LSLASH_IMPACT = 0x74,
  DUEL_GUARD_CENTRE  = 0x7C,
  DUEL_GUARD_LEFT    = 0x7D,
  DUEL_GUARD_RIGHT   = 0x7E,
  DUEL_FALL          = 0x7F,
  DUEL_DOWN          = 0x84,
};

typedef struct
{
  int16_t tops, legs;   // sprite indices
  int16_t hold;         // extra frames the state lasts
  int16_t xoff, yoff;   // sprite offset
  int16_t unusedA, unusedC;
  int8_t  autoNext;     // -1: always next[dir]; <0: |auto| while the sword button is held; >0: |auto| when released
  int8_t  next[9];      // by direction 0..8 (forward-left .. back-right); -2 advance, -3 stay
} DuelStateEntry;

typedef struct { int16_t state, dx, dy; } DuelMove;          // applied on entering the state
typedef struct { int16_t key; int16_t col[24]; } DuelAiRow;  // key = first state of a class of player states

extern const DuelStateEntry duel_states[DUEL_STATE_COUNT];
extern const DuelMove duel_moves[];
extern const DuelAiRow duel_ai[];
extern const uint16_t duel_noparry_masks[4];

// Everything the duel loop carries from one frame to the next: the program's globals and the loop's locals.
typedef struct
{
  // DS globals: [0] the player (bottom), [1] the opponent (top)
  int16_t x[2], y[2];
  int16_t state[2];
  int16_t wounds[2];
  int16_t overshoulder[2];  // an over-the-shoulder (unparryable) swing is in flight
  int16_t target[2];        // the AI's target state (only [1] is used)
  int16_t lane;             // horizontal offset in 16-pixel lanes
  int16_t retreatFrames;    // frames the player spent on the retreat line
  int16_t result;           // 0 running, 1 the player fell, 2 the opponent fell, 3 the player retreated
  int16_t skill;            // 0..7
  int16_t aggressionBias;   // -1 or 0
  int16_t aiControlsPlayer; // a dead feature (never set)
  MsRand  rng;
  // the loop's locals that live across frames
  uint16_t frame;
  int16_t prev[2];          // the state before this frame's transition
  int16_t hold[2];
  int16_t aiMode;           // 0..7, re-rolled every 16 frames
  int16_t button[2];        // 0 none, 1 sword, 2 parry
  int16_t history[2][16];   // states by frame & 15: [0] the player, [1] the opponent
} DuelState;

// The virtual joystick the keyboard hook maintains (x, y centred at 0x80; buttons 0 or 0xFF)
typedef struct { uint8_t x, y, sword, parry; } DuelInput;

// The loop's set-up (1000:0594 before its first iteration); skill and bias come from the encounter.
void duel_start(DuelState *d, int skill, int aggressionBias, int startWounded, uint32_t seed);

// One iteration of the duel loop. Returns d->result.
int duel_frame(DuelState *d, const DuelInput *in);

#endif
