// The battle's set-up, from BATTLE.EXE: the parameters from the shared block (1000:01FE), the battlefield
// generator (1000:51DE-62A2: only what it writes into the terrain map and draws from the random numbers;
// the drawing itself belongs to the renderer), the army placement from the formation tables (3EF0-43C8)
// and the enemy general's choice of formation (3E52, 446E).
#include "battle.h"

#include <string.h>

typedef BattleState S;
typedef BattleUnit U;

uint16_t battle_rand(S *b);

static int16_t clamp16(int v, int lo, int hi)
{
  if (v < lo) v = lo;
  if (hi < v) v = hi;
  return (int16_t)v;
}

static uint16_t uabs(int v)
{
  int16_t s = (int16_t)v;
  return (uint16_t)(s < 0 ? -s : s);
}

static int16_t sshr(int v, int n)
{
  int16_t s = (int16_t)v;
  return (int16_t)(s < 0 ? -((int16_t)-s >> n) : s >> n);
}

static int8_t terr_get(S *b, int px, int py)
{
  unsigned c = (uint16_t)((px >> 2) + 2), r = (uint16_t)((py >> 2) + 2);
  if (c < BATTLE_MAP_W && r < BATTLE_MAP_H) return b->terrain[r * BATTLE_MAP_W + c];
  return -1;
}

static void terr_set(S *b, int px, int py, int8_t v)
{
  unsigned c = (uint16_t)((px >> 2) + 2), r = (uint16_t)((py >> 2) + 2);
  if (c < BATTLE_MAP_W && r < BATTLE_MAP_H) b->terrain[r * BATTLE_MAP_W + c] = v;
}

static int16_t angle_to(int x0, int y0, int x1, int y1)
{
  if ((int16_t)(x1 - x0) == 0 && (int16_t)(y1 - y0) == 0) return -1;
  return (int16_t)battle_atan2((int16_t)(x1 - x0), (int16_t)(y1 - y0));
}

// ---------------------------------------------------------------- parameters

// the formation variant for the army's rank, size and column (1000:03D8)
static int16_t variant(int rank, int size, int column)
{
  int base = 0x6C + rank * 0x40 + column * 0x20, k = 0;
  if (size < battle_t16(base))
    do k++;
    while (size < battle_t16(base + 4 * k));
  return (int16_t)(battle_t16(base + 4 * k + 2) - 1);
}

// men on the field: size * scale / 128 (1000:0526)
static int16_t men_on_field(S *b, int enemy)
{
  int size = enemy ? b->enemySize : b->playerSize, rank = enemy ? b->enemyRank : b->rank, column = enemy ? b->enemyColumn : b->playerColumn;
  return (int16_t)((int32_t)battle_t16(0x60 + rank * 4 + column * 2) * size / 0x80);
}

void battle_read_parameters(S *b, const BattleParameters *p)
{
  int t = p->battleType;
  b->rank = (int16_t)(clamp16(p->rank, 1, 3) - 1);
  b->playerGeneralship = clamp16(p->playerGeneralship, 1, 0x80);
  b->playerSize = clamp16(p->playerSize, 1, 0x80);
  b->playerColumn = 1;
  b->playerMirror = 0;
  b->playerVariant = variant(b->rank, b->playerSize, 1);
  b->enemyRank = b->rank;
  b->difficultyBonus = (int16_t)(2 - p->difficulty);
  int g;
  if (t < 0 || (3 < t && t != 7))
    g = (int16_t)(p->enemyGeneralship - (int16_t)(p->enemyGeneralship * b->difficultyBonus * 0x14) / 100);
  else
    g = p->difficulty * 0x10 + 0x20;
  b->enemyGeneralship = clamp16(g, 1, 0x80);
  b->enemySize = clamp16(p->enemySize, 1, 0x80);
  b->enemyColumn = (int16_t)(1 - (t == 3) - (t == 7));
  b->enemyMirror = 1;
  b->enemyVariant = variant(b->enemyRank, b->enemySize, b->enemyColumn);
  b->generalship[0] = b->playerGeneralship;
  b->generalship[1] = b->enemyGeneralship;
  b->playerMen = men_on_field(b, 0);
  b->enemyMen = men_on_field(b, 1);
  b->playerFormation = (t == 4 || t == 7 || t == 9) ? 0 : 3;
  b->enemyFormation = b->playerFormation == 0 ? 3 : 0;
  b->castle = t == 4 ? 1 : (t == 0 || t == 5 || t == 6) ? 2 : 0;
  b->retreat = b->playerHasUnits = b->enemyHasUnits = b->over = 0;
  b->cga = p->cga;
  b->sharedSound = p->soundMode;
}

// ---------------------------------------------------------------- the battlefield

static int free_run(S *b, const int16_t *p);

// one step of a stream: its banks go into the terrain map, and its slopes (1000:5706 and helpers)
static void slope(S *b, const int16_t *p, int s)
{
  if (b->branchSide != 0 && s == b->branchSide) return;
  if (b->slopeWobble != b->wobbleTarget) b->slopeWobble += b->slopeStep;
  int16_t dist = (int16_t)(b->slopeDistance + b->slopeWobble);
  int16_t a = battle_sin_mul(dist, (uint16_t)p[2]), c = battle_cos_mul(dist, (uint16_t)p[2]);
  int16_t ox = (int16_t)-a, oy = c;
  if (s < 0) { oy = (int16_t)-c; ox = a; }
  int cx = (int16_t)(p[0] + ox) >> 4, cy = (int16_t)(p[1] + oy) >> 4;
  int16_t n = b->slopeCounter++;
  if (n % 5 == 0)
  {
    if (b->slopeWobble == b->wobbleTarget)
    {
      b->wobbleTarget = (int16_t)(((int16_t)((uint16_t)b->rng << 3) % 7) << 4);
      b->slopeStep = b->wobbleTarget < b->slopeWobble ? -1 : 1;
    }
    int16_t a2 = battle_sin_mul((int16_t)(dist - 0x80), (uint16_t)p[2]), c2 = battle_cos_mul((int16_t)(dist - 0x80), (uint16_t)p[2]);
    int16_t ox2 = (int16_t)-a2, oy2 = c2;
    if (s < 0) { oy2 = (int16_t)-c2; ox2 = a2; }
    int fx = (int16_t)(p[0] + ox2) >> 4, fy = (int16_t)(p[1] + oy2) >> 4;
    if (terr_get(b, cx, cy) != -11)
    {
      terr_set(b, cx, cy, -6);  // the crest
      terr_set(b, (cx + fx) / 2, (cy + fy) / 2, -3);
      terr_set(b, fx, fy, -3);  // the face down to the bank
    }
  }
  else if (terr_get(b, cx, cy) != -11)
    terr_set(b, cx, cy, -6);
}

static void bank_slopes(S *b, const int16_t *p)
{
  if (b->bankSlope[0] != 0) slope(b, p, 1);
  if (b->bankSlope[1] != 0) slope(b, p, -1);
  if ((b->bankCounter++ & 0x1F) == 0)
  {
    int r = ((int16_t)battle_rand(b) >> 8) % 10;
    if (r == 3) b->bankSlope[0] = b->bankSlope[0] == 0;
    if (r == 7) b->bankSlope[1] = b->bankSlope[1] == 0;
  }
}

static int stream_step(S *b, int16_t *p)
{
  if (b->streamWidth == 0)
  {
    memcpy(b->streamEnd, p, 4 * sizeof *p);  // dried up: where a marsh may form
    return 0;
  }
  if (free_run(b, p) > 0x27 && terr_get(b, p[0] >> 4, p[1] >> 4) != -1)
  {
    bank_slopes(b, p);
    int16_t s = battle_sin_mul(b->streamWidth, (uint16_t)p[2]), c = battle_cos_mul(b->streamWidth, (uint16_t)p[2]);
    terr_set(b, (int16_t)(p[0] - s) >> 4, (int16_t)(p[1] + c) >> 4, -2);
    terr_set(b, (int16_t)(p[0] + s) >> 4, (int16_t)(p[1] - c) >> 4, -2);
    return 1;
  }
  return 0;
}

// open cells ahead along the heading, up to 100 px; 999 unless a stream or the castle stops it (58F2)
static int free_run(S *b, const int16_t *p)
{
  int x = p[0], y = p[1];
  int16_t dx = battle_cos_mul(0x40, (uint16_t)p[2]), dy = battle_sin_mul(0x40, (uint16_t)p[2]);
  int d = 0;
  int8_t prev = -2, c;
  do
  {
    c = terr_get(b, (int16_t)x >> 4, (int16_t)y >> 4);
    if (c != -2 && prev != -2) break;
    x = (int16_t)(x + dx);
    y = (int16_t)(y + dy);
    d += 4;
    prev = c;
  } while (d < 100);
  while (d < 100 && (c = terr_get(b, (int16_t)x >> 4, (int16_t)y >> 4)) == 0)
  {
    x = (int16_t)(x + dx);
    y = (int16_t)(y + dy);
    d += 4;
  }
  if (c != -2 && c != -11) return 999;
  return d;
}

// would turning 15 degrees the other way leave a longer run (only once a branch exists) (5890)
static int turn_better(S *b, int16_t *p, int curv)
{
  if (b->branches == 0) return 0;
  int r0 = free_run(b, p);
  if (r0 == 999) return 0;
  int16_t t = curv < 1 ? -0xAAA : 0xAAA;
  p[2] += t;
  int r1 = free_run(b, p);
  p[2] -= t;
  return r1 < r0;
}

static void stream_walk(S *b, int16_t *state);

// one tributary, curving away, then running on as a normal stream (55F0)
static void branch(S *b, int16_t *p, int n, int curv)
{
  if (!(b->branches < 1 && n > 0x3B && b->streamWidth > 0xF && uabs(p[3] - p[2]) < 0x2000)) return;
  b->branches++;
  b->branchSide = curv < 0 ? -1 : 1;
  curv = curv < 1 ? curv + 400 : curv - 400;
  int16_t q[4] = { p[0], p[1], p[2], 0 };
  q[3] = (int16_t)((int16_t)(curv * n) / 2 + q[2]);
  int16_t width = b->streamWidth, wobble = b->slopeWobble, step = b->slopeStep, target = b->wobbleTarget;
  while (n > 0 && stream_step(b, q))
  {
    q[2] = (int16_t)(q[2] + curv);
    q[0] = (int16_t)(q[0] + battle_cos_mul(0xE, (uint16_t)q[2]));
    q[1] = (int16_t)(q[1] + battle_sin_mul(0xE, (uint16_t)q[2]));
    n--;
  }
  stream_walk(b, q);
  b->streamWidth = width;
  b->slopeWobble = wobble;
  b->slopeStep = step;
  b->wobbleTarget = target;
  b->branchSide = curv < 0 ? -1 : 1;
}

// a stream, 14/16 px per step, changing its curvature every so often (5516)
static void stream_walk(S *b, int16_t *state)
{
  int16_t p[4];
  memcpy(p, state, sizeof p);
  int16_t count = 0, curv = 0;
  while (stream_step(b, p))
  {
    if (count-- == 0)
    {
      b->branchSide = 0;
      int16_t r = (int16_t)battle_rand(b);
      int16_t c = (int16_t)((int16_t)(r << 7) >> 7);  // the low 9 bits, signed
      count = (int16_t)(r >> 9);
      curv = c > 0 ? (int16_t)(c + 0x14) : (int16_t)(c - 0x14);
      if (turn_better(b, p, curv)) curv = (int16_t)-curv;
      branch(b, p, count, curv);
      if (b->streamWidth >= 2) b->streamWidth -= 2;
    }
    p[2] = (int16_t)(p[2] + curv);
    p[0] = (int16_t)(p[0] + battle_cos_mul(0xE, (uint16_t)p[2]));
    p[1] = (int16_t)(p[1] + battle_sin_mul(0xE, (uint16_t)p[2]));
    if (uabs(p[2] - p[3]) >= 0x4000) curv = (int16_t)-curv;  // turn back towards the start direction
  }
}

// the stream's start on one edge of the field (545C)
static void stream_start(S *b, int16_t *p)
{
  b->branches = 0;
  b->streamWidth = (int16_t)(((int16_t)battle_rand(b) >> 5) % 0x10 + 0x10);
  b->slopeDistance = 0x140;
  b->bankCounter = b->slopeCounter = 0;
  b->bankSlope[0] = b->bankSlope[1] = 0;
  b->slopeStep = b->wobbleTarget = b->slopeWobble = 0;
  uint16_t r = battle_rand(b);
  if ((r & 0x200) == 0)
  {
    p[1] = (int16_t)((int16_t)r % 0x88 + 0x20);
    if ((r & 0x100) == 0) { p[0] = 0x13F; p[3] = (int16_t)0x8000; }
    else { p[0] = 0; p[3] = 0; }
  }
  else
  {
    p[0] = (int16_t)((int16_t)r % 0x100 + 0x20);
    if ((r & 0x100) == 0) { p[1] = 199; p[3] = (int16_t)-0x4000; }
    else { p[1] = 0; p[3] = 0x4000; }
  }
  p[2] = p[3];
  p[0] = (int16_t)(p[0] << 4);
  p[1] = (int16_t)(p[1] << 4);
}

// woods: a 12x12 blob (5D28), grown 4-ways in 8-px steps (5C8C)
static void woods_blob(S *b, int x, int y)
{
  x &= 0xFFFC;
  y &= 0xFFFC;
  for (int r = 0; r < 12; r++)
  {
    int yy = (int16_t)(y - 4 + r), hw = battle_t16(0x1828 + 2 * r);
    for (int xx = (int16_t)(hw + (x - 4)); xx < (int16_t)((x - 4) - hw + 12); xx++) terr_set(b, xx, yy, -9);
  }
}

static void woods_fill(S *b, int x, int y)
{
  if (b->depth < 0xB && ((b->depth != 0 && b->depth < 5) || (battle_rand(b) & 1) == 0))
  {
    int c = terr_get(b, x, y);
    if (c != -9 && c != -11 && c != -1)
    {
      b->depth++;
      woods_blob(b, x, y);
      woods_fill(b, x + 8, y);
      woods_fill(b, x - 8, y);
      woods_fill(b, x, y + 8);
      woods_fill(b, x, y - 8);
      b->depth--;
    }
  }
}

// cells of the same kind two steps apart get the one between filled (6078)
static void fill_gaps(S *b, int8_t code)
{
  for (int y = 0; y < 200; y += 4)
  {
    int last = -99;
    for (int x = 0; x < 0x140; x += 4)
    {
      int8_t c = terr_get(b, x, y);
      if (c == code)
      {
        if (last + 8 == x) terr_set(b, (x - 4) & 0xFFFC, y & 0xFFFC, code);
        last = x;
      }
      else if (c != 0)
        last = -99;
    }
  }
  for (int x = 0; x < 0x140; x += 4)
  {
    int last = -99;
    for (int y = 0; y < 200; y += 4)
    {
      int8_t c = terr_get(b, x, y);
      if (c == code)
      {
        if (last + 8 == y) terr_set(b, x & 0xFFFC, (y - 4) & 0xFFFC, code);
        last = y;
      }
      else if (c != 0)
        last = -99;
    }
  }
}

static void woods(S *b)
{
  int x = (int16_t)battle_rand(b) % 0x140, y = (int16_t)battle_rand(b) % 200;
  b->depth = 0;
  woods_fill(b, x, y);
  if (terr_get(b, x, y) == -9)
  {
    x = (int16_t)battle_rand(b) % 0x140;
    y = (int16_t)battle_rand(b) % 200;
    b->depth = 0;
    woods_fill(b, x, y);
    fill_gaps(b, -9);
  }
}

// a marsh where a stream dried up (5E82, 5EBA)
static void marsh_fill(S *b, int x, int y)
{
  if (b->depth >= 0x1F) return;
  if (b->depth > 4 && (battle_rand(b) & 0x200) != 0) return;
  if (b->depth > 0 && terr_get(b, x, y) != 0) return;
  b->depth++;
  terr_set(b, x & 0xFFFC, y & 0xFFFC, -7);
  marsh_fill(b, x + 4, y);
  marsh_fill(b, x - 4, y);
  marsh_fill(b, x, y + 4);
  marsh_fill(b, x, y - 4);
  b->depth--;
}

void battle_generate_terrain(S *b, uint32_t seed)
{
  b->rng = seed;
  if (b->cga == 0)
  {
    uint16_t r = battle_rand(b);
    b->season = (r & 2) == 0 ? 10 : (int16_t)(r & 0xF);
    b->cursorColour = b->season < 0xE ? 0xF : 8;
    b->slopeColour = (b->season & 8) == 0 ? 8 : 7;
    b->tuftColour = 2;
    b->background = 0;
    b->woodsColour = 9;
    b->marshColour = 2;
    b->streamCentre = 1;
    b->streamLine = 9;
    if (b->season == 10) b->season = 0;
  }
  else
  {
    uint16_t r = battle_rand(b) & 3;
    b->season = r == 0 ? 0 : r == 1 ? 0xB : 0xD;
    b->cursorColour = 0xF;
    b->background = 0;
    b->slopeColour = b->season == 0xB ? 0 : 0xF;
    b->marshColour = b->season == 0xB ? 0 : 0xB;
    b->woodsColour = 0xF;
    b->streamCentre = 0xB;
    b->tuftColour = 0;
    b->streamLine = 0xB;
  }
  memset(b->terrain, 0, sizeof b->terrain);
  if (b->castle != 0)
  {
    int x = (battle_rand(b) & 0x800) == 0 ? 0x120 : 0, y = b->castle == 2 ? 0 : 0xB4;
    if (x != 0) x -= 4;
    if (y != 0) y -= 4;
    for (int dy = 0; dy < 0x15; dy += 4)
      for (int dx = 0; dx < 0x21; dx += 4) terr_set(b, x + dx, y + dy, -11);
  }
  stream_start(b, b->streamEnd);
  stream_walk(b, b->streamEnd);
  woods(b);
  if (b->streamEnd[2] != b->streamEnd[3])
  {
    b->depth = 0;
    marsh_fill(b, b->streamEnd[0] >> 4, b->streamEnd[1] >> 4);
    fill_gaps(b, -7);
  }
  for (int k = 0; k < 0x32; k++)  // grass tufts: drawing only, but they draw random numbers
  {
    battle_rand(b);
    battle_rand(b);
  }
}

// ---------------------------------------------------------------- the armies

static void clamp_route(U *u)
{
  if (u->state != 4) return;
  int16_t dx = (int16_t)(u->destX - u->x), dy = (int16_t)(u->destY - u->y);
  if (u->destY > 0x960)
  {
    u->wp2Y = 0x960;
    u->destY = 0x960;
    u->destX = (int16_t)((int32_t)(int16_t)(0x960 - u->y) * dx / dy + u->x);
    u->wp2X = u->destX;
  }
  dx = (int16_t)(u->wp2X - u->destX);
  dy = (int16_t)(u->wp2Y - u->destY);
  if (u->wp2Y > 0x960)
  {
    u->wp2Y = 0x960;
    u->wp2X = (int16_t)((int32_t)(int16_t)(0x960 - u->destY) * dx / dy + u->destX);
  }
}

// one unit from a formation table entry (1000:4056)
static void place_unit(S *b, int enemy, int attack, int mirror, int idx, int entry)
{
  U *u = &b->u[idx];
  u->id = (int16_t)idx;
  u->flags = (int16_t)((enemy ? 8 : 0) | battle_t16(entry));
  u->x = (int16_t)(battle_t16(entry + 2) << 4);
  u->y = (int16_t)(battle_t16(entry + 4) << 4);
  u->facing = 0x4000;
  int t = u->flags & 7;
  u->speed = battle_t16(0x1502 + 12 * t);
  u->turnRate = battle_t16(0x1504 + 12 * t);
  u->morale = battle_t16(0x1508 + 12 * t);
  u->state = attack ? 4 : 1;
  u->spriteBase = battle_t16(0x16A0 + 2 * u->flags);
  u->men = u->initialMen = u->target = u->blocker = u->damage = u->projectile = u->counter = u->phase = u->pendingTurn = 0;
  int g = b->generalship[enemy];
  if (g < 0x19) u->morale -= 10;
  if (g < 0x31) u->morale -= 5;
  if (0x47 < g) u->morale += 5;
  if (0x60 < g) u->morale += 10;
  if (t == 0) b->general[enemy] = (int16_t)idx;
  if (!attack)
  {
    u->destX = u->wp2X = u->x;
    u->destY = u->wp2Y = u->y;
    u->destFacing = u->wp2Facing = u->facing;
  }
  else
  {
    u->destX = (int16_t)(battle_t16(entry + 6) * 0x10 + u->x);
    u->destY = (int16_t)(battle_t16(entry + 8) * 0x10 + u->y);
    u->wp2X = (int16_t)(battle_t16(entry + 10) * 0x10 + u->destX);
    u->wp2Y = (int16_t)(battle_t16(entry + 12) * 0x10 + u->destY);
    u->destFacing = angle_to(u->x, u->y, u->destX, u->destY);
    u->wp2Facing = angle_to(u->destX, u->destY, u->wp2X, u->wp2Y);
    if (u->wp2Facing == -1) u->wp2Facing = u->destFacing;
  }
  clamp_route(u);
  if (!enemy)  // the tables are written for the army at the top: the player's is turned round
  {
    u->y = (int16_t)(0xC70 - u->y);
    u->destY = (int16_t)(0xC70 - u->destY);
    u->wp2Y = (int16_t)(0xC70 - u->wp2Y);
    u->facing = (int16_t)-u->facing;
    u->destFacing = (int16_t)-u->destFacing;
    u->wp2Facing = (int16_t)-u->wp2Facing;
  }
  if (mirror)
  {
    u->x = (int16_t)(0x1400 - u->x);
    u->destX = (int16_t)(0x1400 - u->destX);
    u->wp2X = (int16_t)(0x1400 - u->wp2X);
    u->facing = (int16_t)(-0x8000 - u->facing);
    u->destFacing = (int16_t)(-0x8000 - u->destFacing);
    u->wp2Facing = (int16_t)(-0x8000 - u->wp2Facing);
  }
}

// share the men out round-robin in figure-sized chunks (infantry two figures at a time) (1000:4332)
static void distribute(S *b, int enemy, int men)
{
  int s = enemy ? 8 : 0;
  while (men > 0)
  {
    if (b->units < 1) return;
    for (int i = 1; i <= b->units; i++)
    {
      U *u = &b->u[i];
      if ((u->flags & 8) != s) continue;
      int q = battle_t16(0x150C + 12 * (u->flags & 7));
      if ((u->flags & 7) == 1) q <<= 1;
      if (men < q) q = men;
      u->men += (int16_t)q;
      men -= q;
      if (men < 1) break;
    }
  }
}

// an army from a formation table: skip to the variant, then up to 9 units (1000:3F9E)
static void place_army(S *b, int enemy, int men, int formation, int var, int mirror)
{
  int entry = battle_t16(0x14A0 + 2 * formation), size = 2 * ((formation / 3) * 4 + 3);
  for (; var > 0; var--)
    do entry += size;
    while (battle_t16(entry) != 0);
  for (int k = 0; k < 9; k++)
  {
    entry += size;
    if (k != 0 && battle_t16(entry) == 0) break;
    b->units++;
    place_unit(b, enemy, formation / 3, mirror, b->units, entry);
  }
  distribute(b, enemy, men);
}

// the terrain under the front and back of every figure (1000:446E); -999: cavalry in a marsh
static int score_terrain(S *b)
{
  int score = 0, last = 1;
  for (int i = 1; i <= b->units; i++)
  {
    U *u = &b->u[i];
    last = i;
    int mpf = battle_t16(0x150C + 12 * (u->flags & 7)), n = (int16_t)(u->men + mpf - 1) / mpf;
    for (int f = 0; f < n; f++)
    {
      int lx = battle_t16(0x15C2 + 2 * f) - battle_t16(0x1556 + 2 * n), ly = battle_t16(0x15D2 + 2 * f) - battle_t16(0x1568 + 2 * n);
      for (int side = -4; side <= 4; side += 8)
      {
        int16_t sx = (int16_t)(lx + side);
        int px = (int16_t)(((int16_t)u->x >> 4) + battle_cos_mul(sx, (uint16_t)u->facing) - battle_sin_mul((int16_t)ly, (uint16_t)u->facing));
        int py = (int16_t)(((int16_t)u->y >> 4) + battle_sin_mul(sx, (uint16_t)u->facing) + battle_cos_mul((int16_t)ly, (uint16_t)u->facing));
        int8_t c = terr_get(b, px, py);
        if (c == -9) score += 2;
        else if (c == -7)
        {
          if ((u->flags & 7) == 2) return -999;
          score -= 3;
        }
        else if (c == -6) score += 1;
        else if (c == -4 || c == -2) score -= 2;
        else if (c == -3) score -= 1;
      }
    }
  }
  score /= 2;
  if ((b->u[last].flags & 7) == 1) score /= 2;
  return score;
}

int battle_choose_enemy_formation(S *b)
{
  int best = -999, pick = -1;
  b->enemyFormation = b->playerFormation < 3 ? 3 : 0;
  for (int c = 0; c < 6; c++)
  {
    b->units = 0;
    place_army(b, 1, b->enemyMen, c / 2 + b->enemyFormation, b->enemyVariant, c % 2);
    int s = score_terrain(b);
    if (best < s)
    {
      best = s;
      pick = c;
    }
  }
  b->enemyFormation = (int16_t)(b->enemyFormation + pick / 2);
  b->enemyMirror = (int16_t)(pick % 2);
  return pick != -1;
}

void battle_place_armies(S *b)
{
  b->units = 0;
  place_army(b, 0, b->playerMen, b->playerFormation, b->playerVariant, b->playerMirror);
  place_army(b, 1, b->enemyMen, b->enemyFormation, b->enemyVariant, b->enemyMirror);
  b->records = b->units;
  for (int i = 1; i <= b->units; i++)
  {
    U *u = &b->u[i];
    u->initialMen = u->reactMen = u->men;
    if (u->state == 1) u->reactMen = (int16_t)(u->reactMen - sshr(u->men, 4));  // defenders react to the first losses
    int t = u->flags & 7;
    if (t == 3 || t == 4)  // a volley record for every shooting unit
    {
      b->records++;
      U *p = &b->u[b->records];
      p->flags = t == 3 ? 5 : 6;
      p->state = 0;
      p->men = 1;
      p->speed = battle_t16(0x1502 + 12 * p->flags);
      p->spriteBase = battle_t16(0x16A0 + 2 * p->flags);
      p->projectile = -1;
      p->pendingTurn = 0;
      u->projectile = b->records;
    }
  }
}

// the formation choice keys (1000:3D68): up/down cycle within the role's three formations, left/right
// mirror; Enter or + confirms (returns 1)
int battle_setup_key(S *b, uint16_t key)
{
  if (key == 0 || key == 0x1000 || key == 0x2400 || key == 0x2F00) return 0;
  int scan = sshr((int16_t)key, 8), ascii = key & 0xFF;
  if (ascii == 0x0D || ascii == 0x2B) return 1;
  if (scan == 0x48) b->playerFormation++;
  else if (scan == 0x4B || scan == 0x4D) b->playerMirror ^= 1;
  else if (scan == 0x50) b->playerFormation--;
  if (b->playerFormation == 2 && scan == 0x50) b->playerFormation = 5;
  if (b->playerFormation == 3 && scan == 0x48) b->playerFormation = 0;
  if (b->playerFormation < 0) b->playerFormation = 2;
  if (5 < b->playerFormation) b->playerFormation = 3;
  return 0;
}
