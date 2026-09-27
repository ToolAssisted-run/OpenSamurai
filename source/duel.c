// The duel's simulation, from DUEL.EXE's duel loop (1000:0594) and wound routine (1000:1624). Drawing and
// sound are left out; everything that decides what happens is here, in the original order.
#include "duel.h"

#include <stdlib.h>

enum { PLAYER = 0, ENEMY = 1 };

static int clampi(int v, int lo, int hi)
{
  if (v < lo) v = lo;
  if (hi < v) v = hi;
  return v;
}

static int sgn(int v) { return v > 0 ? 1 : v < 0 ? -1 : 0; }

// wound(i), 1000:1624: an over-the-shoulder swing wounds twice half of the time
static void wound(DuelState *d, int i)
{
  if (d->wounds[i] >= 4) return;
  if (d->overshoulder[1 - i] != 0 && msrand_random(&d->rng, 2) != 0 && d->wounds[i] < 3) d->wounds[i]++;
  d->wounds[i]++;
  if (d->wounds[i] > 3)
  {
    d->state[i] = DUEL_FALL;
    d->wounds[i] = 4;
  }
  if (d->wounds[i] < 4)
  {
    d->state[i] = DUEL_KNOCKBACK;
    d->y[i] += i == PLAYER ? 8 : -8;
  }
}

void duel_start(DuelState *d, int skill, int aggressionBias, int startWounded, uint32_t seed)
{
  *d = (DuelState){ 0 };
  d->skill = (int16_t)skill;
  d->aggressionBias = (int16_t)aggressionBias;
  msrand_seed(&d->rng, seed);
  d->x[PLAYER] = d->x[ENEMY] = 0xA0;
  d->y[PLAYER] = 0x78;
  d->y[ENEMY] = 0x50;
  d->prev[PLAYER] = d->prev[ENEMY] = -1;
  d->state[PLAYER] = d->state[ENEMY] = DUEL_RAISED_CENTRE;
  if (startWounded) wound(d, PLAYER);  // the wound from the melee before
  for (int k = 0; k < 16; k++) d->history[PLAYER][k] = d->history[ENEMY][k] = 0x3E;
  d->aiMode = (int16_t)msrand_random(&d->rng, 8);
}

// The state machine step (LAB_1000_0E91) for fighter i with direction dir
static void step_machine(DuelState *d, int i, int dir)
{
  d->prev[i] = d->state[i];
  const DuelStateEntry *e = &duel_states[d->state[i]];
  if (e->autoNext == -1 || (d->button[i] == 1) != (e->autoNext < 0))
    d->state[i] = e->next[dir];
  else
    d->state[i] = (int16_t)abs(e->autoNext);
  if (d->state[i] == -2) d->state[i] = d->prev[i] + 1;
  if (d->state[i] == -3) d->state[i] = d->prev[i];
}

// The AI's choice of controls for a target state (LAB_1000_0DBB): the direction whose transition reaches
// the target (the last one that does), else the first that advances, else centre
static void ai_controls(DuelState *d, int i, int parry)
{
  const DuelStateEntry *e = &duel_states[d->state[i]];
  int dir = -1;
  for (int k = 0; k < 9; k++)
  {
    if (e->next[k] == d->target[i]) dir = k;
    if ((e->next[k] == d->state[i] + 1 || e->next[k] == -2) && dir == -1) dir = k;
  }
  if (dir == -1) dir = 4;
  int sword = d->target[i] < 8 || d->target[i] > 0x3D;
  d->button[i] = 0;
  if (sword) d->button[i] = 1;
  if (parry) d->button[i] = 2;
  step_machine(d, i, dir);
}

int duel_frame(DuelState *d, const DuelInput *in)
{
  if (d->state[PLAYER] == DUEL_DOWN) d->result = 1;
  if (d->state[ENEMY] == DUEL_DOWN) d->result = 2;
  d->frame++;
  d->history[PLAYER][d->frame & 15] = d->state[PLAYER];
  d->history[ENEMY][d->frame & 15] = d->state[ENEMY];

  // A fighter that entered a new state moves (the drawing happens here too in the original)
  if (d->prev[PLAYER] != d->state[PLAYER] || d->prev[ENEMY] != d->state[ENEMY])
  {
    if (d->prev[PLAYER] != d->state[PLAYER])
      for (int r = 0; duel_moves[r].state != -1; r++)
        if (duel_moves[r].state == d->state[PLAYER])
        {
          d->x[PLAYER] += duel_moves[r].dx;
          d->y[PLAYER] -= duel_moves[r].dy;
        }
    if (d->prev[ENEMY] != d->state[ENEMY])
      for (int r = 0; duel_moves[r].state != -1; r++)
        if (duel_moves[r].state == d->state[ENEMY])
        {
          d->x[ENEMY] -= duel_moves[r].dx;
          d->y[ENEMY] += duel_moves[r].dy;
        }
    d->x[PLAYER] = (int16_t)clampi(d->x[PLAYER], 0x30, 0x114);
    d->x[ENEMY] = (int16_t)clampi(d->x[ENEMY], 0x30, 0x114);
    int enemyBottom;
    if (d->y[PLAYER] < 0x6E)
    {
      d->y[PLAYER] = (int16_t)clampi(d->y[PLAYER], d->y[ENEMY] + 0x10, 0xA0);
      enemyBottom = 999;
    }
    else
    {
      d->y[PLAYER] = (int16_t)clampi(d->y[PLAYER], 0x3C, 0xA0);
      enemyBottom = d->y[PLAYER] - 0x10;
    }
    d->y[ENEMY] = (int16_t)clampi(d->y[ENEMY], 0x3C, enemyBottom);
    if (d->y[PLAYER] == 0xA0 && ++d->retreatFrames > 0x20) d->result = 3;
  }

  int dx = d->x[ENEMY] - d->x[PLAYER];
  int dy = d->y[PLAYER] - d->y[ENEMY];
  int parried = 0;
  // lane = (dx + 8) / 16 truncated towards zero, one less left of -8
  d->lane = (int16_t)((dx + 8) / 16);
  if (dx < -8) d->lane--;
  int near = dy < 0x18;
  int xdir = 0;

  for (int i = 0; i < 2; i++)
  {
    int canRecoil = 1;
    if (parried) continue;
    int parryChosen = 0;  // local_62 on the AI's path
    if (i == PLAYER && d->aiControlsPlayer == 0)
    {
      int xr = in->x - 0x80, yr = in->y - 0x80;
      d->button[i] = 0;
      if (in->sword)
      {
        d->button[i] = 1;
        if (d->y[i] == 0xA0) d->y[i]--;  // off the retreat line
      }
      if (in->parry) d->button[i] = 2;
      xdir = abs(xr) < 0x51 ? 0 : sgn(xr);
      int ydir = abs(yr) < 0x41 ? 0 : sgn(yr);
      step_machine(d, i, ydir * 3 + xdir + 4);
    }
    else
    {
      if ((d->frame & 15) == 0)
      {
        d->aiMode = (int16_t)clampi(msrand_random(&d->rng, 4) - d->aggressionBias, 0, 3);
        if (msrand_random(&d->rng, 2) != 0) d->aiMode += 4;
      }
      // the player's state as seen a random reaction delay ago
      int delay = msrand_random(&d->rng, clampi(10 - d->skill * 2, 0, 15));
      int seen = d->history[PLAYER][(d->frame - delay) & 15];
      int lane = clampi(d->lane, -2, 2);
      int col = (lane & 1) == 0 ? lane * 2 + (d->aiMode & 3) + 4 : lane * 2 + d->aiMode + 2;
      col += (!near || abs(dx) > 0x17) ? 12 : 0;
      int row = 0, best = 999;
      for (int r = 0; duel_ai[r].key != -1; r++)
      {
        int diff = seen - duel_ai[r].key;
        if (diff >= 0 && diff < best)
        {
          d->target[i] = duel_ai[r].col[col];
          row = r;
          best = diff;
        }
      }
      if (abs(dy) < 0x18 && (d->target[i] == 0x10 || d->target[i] == 0x18 || d->target[i] == 0x1F)) d->target[i] = 0;
      if (d->target[i] != 0 || d->overshoulder[1 - i] != 0 || d->overshoulder[i] != 0)
        ai_controls(d, i, 0);
      else
      {
        // guard against the player's attack, on the side it comes from
        parryChosen = 1;
        int key = duel_ai[row].key;
        int side = (key == 0x55 || key == 0x5A || key == 0x71 || key == 0x66) ? 1 : (key == 0x4A || key == 0x4F || key == 0x6C || key == 0x60) ? -1 : 0;
        side += d->lane;
        d->target[i] = side > 0 ? DUEL_GUARD_RIGHT : side < 0 ? DUEL_GUARD_LEFT : DUEL_GUARD_CENTRE;
        if (d->overshoulder[PLAYER] == 0)
          d->button[i] = 2;
        else
          d->target[i] = 0x26;
        if (d->wounds[i] > 3)
          ai_controls(d, i, parryChosen);
        else if ((duel_noparry_masks[d->skill / 2] & ((int)d->frame >> 4)) != 0)
        {
          d->target[i] = d->x[i] < 0xA0 ? 8 : 0xC;  // the "won't parry" window: slide towards the centre
          ai_controls(d, i, parryChosen);
        }
        else
        {
          d->prev[i] = d->state[i];  // the guard is instantaneous
          d->state[i] = d->target[i];
        }
      }
    }

    if (d->button[i] == 2 && i == PLAYER && d->aiControlsPlayer == 0 && d->wounds[PLAYER] < 4)
    {
      d->state[PLAYER] = xdir < 0 ? DUEL_GUARD_LEFT : xdir == 0 ? DUEL_GUARD_CENTRE : DUEL_GUARD_RIGHT;
      d->hold[PLAYER] = 0;
    }
    if (d->button[i] != 2 && i == PLAYER) canRecoil = 0;
    if (d->hold[i] < 1)
    {
      d->hold[i] += duel_states[d->state[i]].hold;
      int s = d->state[i];
      if (i != PLAYER && (s == DUEL_CHACK_START || s == DUEL_RHACK_START || s == DUEL_LHACK_START || s == DUEL_RSLASH_TELE || s == DUEL_LSLASH_TELE))
        d->hold[i] += (int16_t)clampi(5 - d->skill, 0, 7);  // the opponent telegraphs his attacks
    }
    else
    {
      d->hold[i]--;
      d->state[i] = d->prev[i];
    }

    if (d->wounds[i] < 4)
    {
      int guard = 99, pose = 0;
      if (d->button[i] == 2)
      {
        if (d->state[i] == DUEL_GUARD_CENTRE) { guard = 0; pose = 0x76; }
        if (d->state[i] > DUEL_GUARD_CENTRE) { guard = -1; pose = 0x78; }
        if (d->state[i] > DUEL_GUARD_LEFT) { guard = 1; pose = 0x7A; }
      }
      if (d->prev[i] + 1 == d->state[i] && (d->state[i] == DUEL_CHACK_START || d->state[i] == DUEL_LHACK_START || d->state[i] == DUEL_RHACK_START))
        d->overshoulder[i] = 1;  // the swing started from the shoulder
      guard -= d->lane;
      int o = 1 - i;
      int so = d->state[o];
      if (abs(so - DUEL_CHACK_IMPACT) < 1 && abs(guard) < 1 && d->overshoulder[o] == 0)
      {
        d->state[i] = (int16_t)pose;
        d->overshoulder[o] = 0;
        if (canRecoil) { d->state[o] = DUEL_CHACK_RECOIL; d->hold[o] = 4; d->hold[i] = 2; parried = 1; }
      }
      else if (so == DUEL_CHACK_IMPACT)
      {
        if (near && abs(d->lane) < 2) wound(d, i);
        d->overshoulder[o] = 0;
      }
      so = d->state[o];
      if ((so == DUEL_RHACK_IMPACT || so == DUEL_RSLASH_IMPACT) && abs(guard + 1) < 1 && d->overshoulder[o] == 0)
      {
        d->state[i] = (int16_t)pose;
        d->overshoulder[o] = 0;
        if (canRecoil) { d->state[o] = DUEL_RHACK_RECOIL; d->hold[o] = 4; d->hold[i] = 2; parried = 1; }
      }
      else if (so == DUEL_RHACK_IMPACT || so == DUEL_RSLASH_IMPACT)
      {
        if (near && d->lane >= 0 && d->lane < 2) wound(d, i);
        d->overshoulder[o] = 0;
      }
      so = d->state[o];
      if ((so == DUEL_LHACK_IMPACT || so == DUEL_LSLASH_IMPACT) && abs(guard - 1) < 1 && d->overshoulder[o] == 0)
      {
        d->state[i] = (int16_t)pose;
        d->overshoulder[o] = 0;
        if (canRecoil) { d->state[o] = DUEL_LHACK_RECOIL; d->hold[o] = 4; d->hold[i] = 2; parried = 1; }
      }
      else if (so == DUEL_LHACK_IMPACT || so == DUEL_LSLASH_IMPACT)
      {
        if (near && d->lane < 1 && d->lane > -2) wound(d, i);
        d->overshoulder[o] = 0;
      }
    }
    else
      d->state[i] = d->prev[i] + 1;  // the fall advances every frame
  }
  return d->result;
}
