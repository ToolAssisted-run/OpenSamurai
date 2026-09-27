// The battle's simulation, from BATTLE.EXE (445.03): collision geometry (1000:1658-1E30), movement and
// orders (2546-2CFC), the units' autonomous behaviour (2D8E-3818 and the state handlers), damage and morale
// (07F0, 0A1C, 2338-2424), the player's orders (3920-3D0E) and the body of the battle loop in main. Drawing
// and sound are left out; the few drawing routines that also change the state (the per-step unit pass
// 1000:49C8, the cursor's check of the selected unit in 4FA4) are kept for those effects.
#include "battle.h"

#include <stdlib.h>
#include <string.h>

typedef BattleState S;
typedef BattleUnit U;

uint16_t battle_rand(S *b);

// ---------------------------------------------------------------- small helpers

static int16_t clamp16(int v, int lo, int hi)
{
  if (v < lo) v = lo;
  if (hi < v) v = hi;
  return (int16_t)v;
}

// |v| of a 16-bit value, as the unsigned result of the code's cwd/xor/sub idiom
static uint16_t uabs(int v)
{
  int16_t s = (int16_t)v;
  return (uint16_t)(s < 0 ? -s : s);
}

// v / 2^n rounded towards zero (the code's sign-preserving shift)
static int16_t sshr(int v, int n)
{
  int16_t s = (int16_t)v;
  return (int16_t)(s < 0 ? -((int16_t)-s >> n) : s >> n);
}

static int side(const U *u) { return u->flags & 8; }
static int type(const U *u) { return u->flags & 7; }
static int16_t type_word(int t, int k) { return battle_t16(0x1502 + 12 * t + k); }
#define T_SPEED 0
#define T_TURN 2
#define T_FIRE 4
#define T_MORALE 6
#define T_MPF 10
static int figures(const U *u)
{
  int mpf = type_word(type(u), T_MPF);
  return (int16_t)(u->men + mpf - 1) / mpf;
}
static int16_t ext(int table, int n) { return battle_t16(table + 2 * n); }
#define EXT_XMIN 0x157A
#define EXT_XMAX 0x158C
#define EXT_YMIN 0x159E
#define EXT_YMAX 0x15B0
#define CENTRE_X 0x1556
#define CENTRE_Y 0x1568
#define FIG_X 0x15C2
#define FIG_Y 0x15D2

static int8_t terr_get(S *b, int px, int py)
{
  unsigned c = (unsigned)(uint16_t)((px >> 2) + 2), r = (unsigned)(uint16_t)((py >> 2) + 2);
  if (c < BATTLE_MAP_W && r < BATTLE_MAP_H) return b->terrain[r * BATTLE_MAP_W + c];
  return -1;
}

static int8_t vis_get(S *b, int px, int py)
{
  unsigned c = (unsigned)(uint16_t)((px >> 2) + 2), r = (unsigned)(uint16_t)((py >> 2) + 2);
  if (c < BATTLE_MAP_W && r < BATTLE_MAP_H) return (int8_t)b->visible[r * BATTLE_MAP_W + c];
  return -1;
}

// the angle from one point to another; -1 (0xFFFF) if they coincide (1000:149E)
static int16_t angle_to(int x0, int y0, int x1, int y1)
{
  if ((int16_t)(x1 - x0) == 0 && (int16_t)(y1 - y0) == 0) return -1;
  return (int16_t)battle_atan2((int16_t)(x1 - x0), (int16_t)(y1 - y0));
}

// ---------------------------------------------------------------- collision geometry

// B's centre and corners in A's frame, and both boxes (1000:1658)
static void collide_prepare(S *b, const U *a, const U *o)
{
  int n = figures(a) * 2 / 2;
  b->boxA[0] = (int16_t)(ext(EXT_XMIN, n) << 4);
  b->boxA[2] = (int16_t)(ext(EXT_XMAX, n) << 4);
  b->boxA[1] = (int16_t)(ext(EXT_YMIN, n) << 4);
  b->boxA[3] = (int16_t)(ext(EXT_YMAX, n) << 4);
  n = figures(o);
  b->boxB[0] = (int16_t)(ext(EXT_XMIN, n) << 4);
  b->boxB[2] = (int16_t)(ext(EXT_XMAX, n) << 4);
  b->boxB[1] = (int16_t)(ext(EXT_YMIN, n) << 4);
  b->boxB[3] = (int16_t)(ext(EXT_YMAX, n) << 4);
  int16_t dx = (int16_t)(o->x - a->x), dy = (int16_t)(o->y - a->y), df = (int16_t)(o->facing - a->facing);
  uint16_t na = (uint16_t)-a->facing;
  b->centreX = (int16_t)(battle_cos_mul(dx, na) - battle_sin_mul(dy, na));
  b->centreY = (int16_t)(battle_sin_mul(dx, na) + battle_cos_mul(dy, na));
  // corners (xmax,ymax), (xmax,ymin), (xmin,ymin), (xmin,ymax) of B, rotated by df, around B's centre
  static const int cx[4] = { 2, 2, 0, 0 }, cy[4] = { 3, 1, 1, 3 };
  for (int k = 0; k < 4; k++)
  {
    int16_t lx = b->boxB[cx[k]], ly = b->boxB[cy[k]];
    b->corners[k] = (int16_t)(battle_cos_mul(lx, (uint16_t)df) - battle_sin_mul(ly, (uint16_t)df) + b->centreX);
    b->corners[4 + k] = (int16_t)(battle_sin_mul(lx, (uint16_t)df) + battle_cos_mul(ly, (uint16_t)df) + b->centreY);
  }
}
// corners[] maps the original's scattered words: x 26B4 26B6 26BA 26BE, y 26B8 26BC 26C0 26C2
#define CX(k) b->corners[k]
#define CY(k) b->corners[4 + (k)]

static int outcode(S *b, int x, int y)
{
  int c = x < b->boxA[0];
  if (b->boxA[2] < x) c |= 2;
  if (y < b->boxA[1]) c |= 4;
  if (b->boxA[3] < y) c |= 8;
  return c;
}

// does the segment cross A's box (one clipping step, 1000:18D6)
static int segment_hits(S *b, int x1, int y1, int x2, int y2)
{
  int c1 = outcode(b, x1, y1), c2 = outcode(b, x2, y2);
  if (c1 & c2) return 0;
  if (c1 == 0 || c2 == 0) return 1;
  if (c1 & 8)
  {
    int dy = (int16_t)(y2 - y1);
    x1 = (int16_t)((int32_t)(int16_t)(x2 - x1) * (int16_t)(b->boxA[3] - y2) / dy + x2);
    y1 = b->boxA[3];
  }
  else if (c1 & 4)
  {
    int dy = (int16_t)(y2 - y1);
    x1 = (int16_t)((int32_t)(int16_t)(x2 - x1) * (int16_t)(b->boxA[1] - y2) / dy + x2);
    y1 = b->boxA[1];
  }
  else if (c1 & 2)
  {
    int dx = (int16_t)(x2 - x1);
    y1 = (int16_t)((int32_t)(int16_t)(y2 - y1) * (int16_t)(b->boxA[2] - x2) / dx + y2);
    x1 = b->boxA[2];
  }
  else if (c1 & 1)
  {
    int dx = (int16_t)(x2 - x1);
    y1 = (int16_t)((int32_t)(int16_t)(y2 - y1) * (int16_t)(b->boxA[0] - x2) / dx + y2);
    x1 = b->boxA[0];
  }
  return outcode(b, x1, y1) == 0;
}

static int in_boxA(S *b, int x, int y) { return b->boxA[0] <= x && x <= b->boxA[2] && b->boxA[1] <= y && y <= b->boxA[3]; }

// the first of B's corners inside A (1..4), with the point (1000:1A54)
static int corner_inside(S *b, const U *a, const U *o, int16_t *px, int16_t *py)
{
  collide_prepare(b, a, o);
  static const int order[4] = { 0, 1, 2, 3 };
  for (int k = 0; k < 4; k++)
    if (in_boxA(b, CX(order[k]), CY(order[k])))
    {
      *px = CX(order[k]);
      *py = CY(order[k]);
      return k + 1;
    }
  return 0;
}

// do A and B overlap; the contact point in A's frame (1000:1B46)
static int overlap(S *b, const U *a, const U *o, int16_t *px, int16_t *py)
{
  int k = corner_inside(b, o, a, px, py);  // one of A's corners inside B: the contact is that corner of A
  if (k == 0)
  {
    if (corner_inside(b, a, o, px, py)) return 1;
    *px = 0;
    *py = 0;
    return segment_hits(b, CX(0), CY(0), CX(2), CY(2)) || segment_hits(b, CX(1), CY(1), CX(3), CY(3));
  }
  // B's box in its own frame is boxB here (A and B swapped): the corner of A as A sees it
  if (k == 1) { *px = b->boxB[2]; *py = b->boxB[3]; }
  else if (k == 2) { *px = b->boxB[2]; *py = b->boxB[1]; }
  else if (k == 3) { *px = b->boxB[0]; *py = b->boxB[1]; }
  else if (k == 4) { *px = b->boxB[0]; *py = b->boxB[3]; }
  return 1;
}

static int near44(const U *a, const U *o)
{
  return (int16_t)uabs(a->x - o->x) < 0x2C1 && (int16_t)uabs(a->y - o->y) < 0x2C1;
}

// the unit u collides with: the previous enemy blocker first, then enemies, then friends (1000:1BDA)
static int find_collision(S *b, U *u)
{
  int16_t px, py;
  if (u->blocker != 0)
  {
    U *o = &b->u[u->blocker];
    if (o->state != 0 && o->state < 10 && side(u) != side(o) && overlap(b, u, o, &px, &py))
    {
      u->contactX = px;
      u->contactY = py;
      return 1;
    }
  }
  for (int pass = 0; pass < 2; pass++)
    for (int i = 1; i <= b->units; i++)
    {
      U *o = &b->u[i];
      if (o == u || (side(u) != side(o)) != (pass == 0) || o->state == 0 || !near44(u, o)) continue;
      if (overlap(b, u, o, &px, &py))
      {
        u->contactX = px;
        u->contactY = py;
        u->blocker = (int16_t)i;
        return 1;
      }
    }
  u->blocker = 0;
  return 0;
}

// B stands square in front of A, facing it (1000:1D66)
static int frontal_contact(S *b, const U *a, const U *o)
{
  if (((uint16_t)(a->facing - o->facing + 0x71C) & 0x3FFF) >= 0xE39) return 0;
  collide_prepare(b, a, o);
  int ymin = b->boxA[1], ymax = b->boxA[3], front = b->boxA[2];
  int anyBelow = ymin <= CY(0) || ymin <= CY(1) || ymin <= CY(2) || ymin <= CY(3);
  int anyAbove = CY(0) <= ymax || CY(1) <= ymax || CY(2) <= ymax || CY(3) <= ymax;
  int atFront = 0;
  for (int k = 0; k < 4; k++)
    if (front - 0x20 <= CX(k) && CX(k) <= front + 0x20) atFront = 1;
  return anyBelow && anyAbove && atFront;
}

static int find_frontal(S *b, const U *u)
{
  for (int i = 1; i <= b->units; i++)
  {
    U *o = &b->u[i];
    if (o->state != 0 && side(u) != side(o) && near44(u, o) && frontal_contact(b, u, o)) return i;
  }
  return 0;
}

// the cursor inside the unit's rectangle (1000:15C2)
static int contains_point(S *b, int x, int y, const U *u)
{
  int n = figures(u);
  int16_t dx = (int16_t)(x - u->x), dy = (int16_t)(y - u->y);
  uint16_t na = (uint16_t)-u->facing;
  int lx = (int16_t)(battle_cos_mul(dx, na) - battle_sin_mul(dy, na));
  int ly = (int16_t)(battle_sin_mul(dx, na) + battle_cos_mul(dy, na));
  (void)b;
  return (ext(EXT_XMIN, n) << 4) < lx && lx < (ext(EXT_XMAX, n) << 4) && (ext(EXT_YMIN, n) << 4) < ly && ly < (ext(EXT_YMAX, n) << 4);
}

// ---------------------------------------------------------------- movement

static void destroy(U *u)
{
  u->state = 0;
  u->x = u->y = u->destX = u->destY = 0;
}

static int on_map(const U *u) { return (uint16_t)u->x < 0x1401 && (uint16_t)u->y < 0xC81; }

// stop where it is (1000:2C86); refused for fleeing units already off the map
static void stop(U *u)
{
  if ((u->state != 11 && u->state != 10) || on_map(u))
  {
    u->state = 2;
    u->counter = 0;
    u->destX = u->x;
    u->destY = u->y;
    u->destFacing = u->facing;
    u->reactMen = u->men;
    if (u->projectile != -1) u->target = 0;
  }
}

// the step's velocity towards the destination, never overshooting it (1000:2546)
static void velocity(S *b, const U *u, int16_t *vx, int16_t *vy)
{
  int16_t spd = u->state == 4 ? b->groupSpeed : u->speed;
  uint16_t a = (uint16_t)angle_to(u->x, u->y, u->destX, u->destY);
  *vx = battle_cos_mul(spd, a);
  *vy = battle_sin_mul(spd, a);
  if (u->state == 11)
  {
    *vx = (int16_t)((int16_t)(*vx * 3) >> 1);
    *vy = (int16_t)((int16_t)(*vy * 3) >> 1);
  }
  int16_t rx = (int16_t)(u->destX - u->x), ry = (int16_t)(u->destY - u->y);
  if ((int16_t)uabs(rx) < (int16_t)uabs(*vx)) *vx = rx;
  if ((int16_t)uabs(ry) < (int16_t)uabs(*vy)) *vy = ry;
}

// a charging unit yields to a friend nearer to their common target (1000:2A5E)
static int yields(S *b, const U *u, const U *o)
{
  const U *t = &b->u[u->target];
  if (u->state == 12 && o->state == 12 && u->target == o->target)
  {
    int dO = battle_distance((int16_t)(o->x - t->x), (int16_t)(o->y - t->y), 0);
    int dU = battle_distance((int16_t)(u->x - t->x), (int16_t)(u->y - t->y), 0);
    if ((int16_t)dO >> 4 < (int16_t)dU >> 4) return 1;
  }
  return 0;
}

// move and turn, undone if it collides (friends may pass or be side-stepped) (1000:260C)
static int try_move(S *b, U *u, int16_t dx, int16_t dy, int16_t turn)
{
  if (dx == 0 && dy == 0 && turn == 0) return 0;
  u->x += dx;
  u->y += dy;
  u->facing += turn;
  if (!find_collision(b, u)) return 1;
  U *o = &b->u[u->blocker];
  if (side(u) == side(o) && u->state == 2 && o->state == 2) return 1;  // two idle friends may overlap
  if (side(u) == side(o))
  {
    if (u->state == 11 || u->state == 10) return 1;
    int t = type(o);
    if (t == 3 || t == 4)
    {
      o->open = 1;  // walking through shooters: they open their ranks
      return 1;
    }
  }
  u->x -= dx;
  u->y -= dy;
  u->facing -= turn;
  if (side(u) == side(o) && !yields(b, u, o))
  {
    int16_t a = (int16_t)(u->facing + (u->contactY < 1 ? 0x471C : -0x471C));
    int16_t sx = battle_cos_mul(0x10, (uint16_t)a), sy = battle_sin_mul(0x10, (uint16_t)a);
    u->x += sx;
    u->y += sy;
    if (!find_collision(b, u)) return 1;
    u->x -= sx;
    u->y -= sy;
  }
  return 0;
}

static int step_forward(S *b, U *u)
{
  return try_move(b, u, battle_cos_mul(0x10, (uint16_t)u->facing), battle_sin_mul(0x10, (uint16_t)u->facing), 0);
}

static int step_back(S *b, U *u)
{
  return try_move(b, u, (int16_t)-battle_cos_mul(4, (uint16_t)u->facing), (int16_t)-battle_sin_mul(4, (uint16_t)u->facing), 0);
}

// turn towards the destination facing, then march; halve the step until it fits (1000:2802)
static int move_toward(S *b, U *u)
{
  int16_t d = (int16_t)(u->destFacing - u->facing);
  int16_t vx = 0, vy = 0;
  if (uabs(d) < 0x222) velocity(b, u, &vx, &vy);
  int16_t t = clamp16(d, -u->turnRate, u->turnRate);
  if (try_move(b, u, vx, vy, t)) return 1;
  int16_t blocker = u->blocker, tt = t, yy = vy;
  if (t != 0 && blocker != 0 && side(&b->u[blocker]) == side(u))
  {
    velocity(b, u, &vx, &vy);
    if (try_move(b, u, sshr(vx, 2), sshr(vy, 2), 0)) return 1;
    tt = t;
    yy = vy;
  }
  while (vx != 0 || yy != 0 || tt != 0)
  {
    vx = (int16_t)(vx / 2);
    try_move(b, u, vx, (int16_t)(yy / 2), (int16_t)(tt / 2));
    tt = (int16_t)(tt / 2);
    yy = (int16_t)(yy / 2);
  }
  if (u->blocker == 0) u->blocker = blocker;
  return 0;
}

// ---------------------------------------------------------------- seeing and choosing

// a ray through the visibility map in 4-pixel steps up to 88 px: the distance to the first other unit
// (its id in *id), 999 if none or off the map (1000:2D8E)
static int16_t ray(S *b, int x, int y, uint16_t a, int8_t *id)
{
  int8_t self = *id;
  int16_t dx = battle_cos_mul(0x40, a), dy = battle_sin_mul(0x40, a);
  int dist = 0;
  do
  {
    x = (int16_t)(x + dx);
    y = (int16_t)(y + dy);
    int8_t c = vis_get(b, (int16_t)x >> 4, (int16_t)y >> 4);
    *id = c;
    if (c == -1) return 999;
    if (c != self)
    {
      if (c != 0) return (int16_t)dist;
      dist += 4;
    }
  } while (dist < 0x5B);
  return 999;
}

// nine rays from the centre over the front half; the enemy that is nearest and most ahead (1000:2E1A)
static int16_t fan_scan(S *b, U *u, int16_t *angle, int8_t *id)
{
  int16_t a = (int16_t)(u->facing - 0x2000);
  if (u->state == 2) a += battle_t16(0x1688 + 2 * (u->counter & 3));
  *id = 0;
  int best = 999, bestDist = 999;
  for (int k = 0; k < 9; k++)
  {
    int8_t hit = (int8_t)u->id;
    ray(b, u->x, u->y, (uint16_t)a, &hit);
    if (hit != -1 && side(&b->u[(uint8_t)hit]) != side(u))
    {
      const U *o = &b->u[(uint8_t)hit];
      int d = (int16_t)battle_distance((int16_t)(u->x - o->x), (int16_t)(u->y - o->y), 0) >> 4;
      int cost = (k - 4 < 0 ? 4 - k : k - 4) * 3 + d;
      if (cost < best)
      {
        *id = hit;
        *angle = a;
        best = cost;
        bestDist = d;
      }
    }
    a += 0x800;
  }
  return (int16_t)bestDist;
}

// archers and musketeers: shoot at an enemy in range and in front, or turn towards it (1000:2F26)
static int acquire(S *b, U *u)
{
  int16_t ang = 0;
  int8_t id;
  int d = fan_scan(b, u, &ang, &id);
  if (id != 0 && id != -1)
  {
    if (type(u) == 3) d -= 0x40;
    if (type(u) == 4) d -= 0x30;
    if (d < 1)
    {
      if (uabs(u->facing - ang) < 0x444)
      {
        u->state = 14;
        u->target = id;
        u->destX = u->x;
        u->destY = u->y;
        u->counter = type_word(type(u), T_FIRE);
        return 1;
      }
      u->state = 5;
      u->destFacing = ang;
    }
  }
  return 0;
}

// five rays from the side the unit looks at (front, left, right, back by turns when idle) (1000:2FCE)
static void scan(S *b, U *u)
{
  unsigned dir = (u->state == 2 || u->state == 1) ? (u->counter & 3) : 0;
  int16_t f = u->facing;
  int n = figures(u);
  int x0 = ext(EXT_XMIN, n) * 16 + 0x30, x1 = ext(EXT_XMAX, n) * 16 - 0x30;
  int y0 = ext(EXT_YMIN, n) * 16 + 0x30, y1 = ext(EXT_YMAX, n) * 16 - 0x30;
  int ax, ay, bx, by;
  if (dir == 0) { ax = x1; ay = y0; bx = x1; by = y1; }       // front
  else if (dir == 1) { ax = x0; ay = y0; bx = x1; by = y0; }  // left
  else if (dir == 2) { ax = x1; ay = y1; bx = x0; by = y1; }  // right
  else { ax = x0; ay = y1; bx = x0; by = y0; }                // back
  int p1x = (int16_t)(u->x + battle_cos_mul((int16_t)ax, (uint16_t)f) - battle_sin_mul((int16_t)ay, (uint16_t)f));
  int p1y = (int16_t)(u->y + battle_sin_mul((int16_t)ax, (uint16_t)f) + battle_cos_mul((int16_t)ay, (uint16_t)f));
  int p2x = (int16_t)(u->x + battle_cos_mul((int16_t)bx, (uint16_t)f) - battle_sin_mul((int16_t)by, (uint16_t)f));
  int p2y = (int16_t)(u->y + battle_sin_mul((int16_t)bx, (uint16_t)f) + battle_cos_mul((int16_t)by, (uint16_t)f));
  int16_t a = (int16_t)(f + battle_t16(0x1688 + 2 * dir));
  for (int k = 0; k < 5; k++) b->rayId[k] = (int8_t)u->id;
  b->rayDist[0] = ray(b, p1x, p1y, (uint16_t)(a - 0x2000), &b->rayId[0]);
  b->rayDist[1] = ray(b, p1x, p1y, (uint16_t)a, &b->rayId[1]);
  b->rayDist[2] = ray(b, (p1x + p2x) / 2, (p1y + p2y) / 2, (uint16_t)a, &b->rayId[2]);
  b->rayDist[3] = ray(b, p2x, p2y, (uint16_t)a, &b->rayId[3]);
  b->rayDist[4] = ray(b, p2x, p2y, (uint16_t)(a + 0x2000), &b->rayId[4]);
}

static void seek(S *b, U *u);

// charge (or, when defending, face) an enemy seen by the last scan if strong enough (1000:3226)
static void charge_decision(S *b, U *u)
{
  if (u->effMorale <= 2) return;
  int pick = 0, best = 999;
  for (int k = 0; k < 5; k++)
  {
    int id = b->rayId[k];
    if (id <= 0) continue;
    const U *o = &b->u[id];
    if (side(o) != side(u) && o->men != 0 && (int16_t)(u->men * 3) / (int16_t)(o->men << 1) != 0 && b->rayDist[k] + battle_t16(0x1690 + 2 * k) < best)
    {
      pick = id;
      best = b->rayDist[k] + battle_t16(0x1690 + 2 * k);
    }
  }
  if (pick == 0) return;
  if (u->state == 1 && best < 0x20)
  {
    u->destX = u->x;
    u->destY = u->y;
    u->destFacing = angle_to(u->x, u->y, b->u[pick].x, b->u[pick].y);
    move_toward(b, u);
    u->counter--;
    return;
  }
  if (u->state == 2 && best < 0x30)
  {
    u->state = 12;
    u->target = (int16_t)pick;
  }
}

// the nearest enemy other than the current target: march 16 px towards it (1000:3818)
static void seek(S *b, U *u)
{
  int pick = 0, best = 999;
  for (int i = 1; i <= b->units; i++)
  {
    const U *o = &b->u[i];
    if (side(o) != side(u) && o->state != 0 && u->target != i)
    {
      int d = (int16_t)battle_distance((int16_t)(u->x - o->x), (int16_t)(u->y - o->y), 0x400) >> 4;
      if (d < best)
      {
        best = d;
        pick = i;
      }
    }
  }
  int16_t a = pick == 0 ? (int16_t)(u->facing + 0x8000) : angle_to(u->x, u->y, b->u[pick].x, b->u[pick].y);
  u->state = 5;
  u->destX = (int16_t)(u->x + battle_cos_mul(0x100, (uint16_t)a));
  u->destY = (int16_t)(u->y + battle_sin_mul(0x100, (uint16_t)a));
  u->destFacing = a;
  u->target = (int16_t)pick;
}

// state 12: run at the target (1000:3544)
static void charge(S *b, U *u)
{
  U *t = &b->u[u->target];
  if (on_map(u) && t->state != 0)
  {
    u->destX = t->x;
    u->destY = t->y;
    u->destFacing = angle_to(u->x, u->y, t->x, t->y);
    if (!move_toward(b, u)) stop(u);
  }
  else
    seek(b, u);
}

// ---------------------------------------------------------------- the idle states

// wheel against an enemy met at an angle, keeping the contact point (1000:2AF4)
static void wheel(S *b, U *u)
{
  int16_t s = u->contactY < 0 ? -1 : 1;
  int diff = (uint16_t)(b->u[u->blocker].facing - u->facing) & 0x3FFF;
  int16_t turn = (int16_t)(s * u->turnRate);
  if (diff < u->turnRate) turn = (int16_t)diff;
  if (0x4000 - diff < u->turnRate) turn = (int16_t)-(0x4000 - diff);
  int16_t ncy = (int16_t)-u->contactY, ncx = (int16_t)-u->contactX;
  uint16_t f0 = (uint16_t)u->facing, f1 = (uint16_t)(u->facing + turn);
  int16_t dx = (int16_t)(((battle_cos_mul(ncx, f1) - battle_sin_mul(ncy, f1)) - battle_cos_mul(ncx, f0)) + battle_sin_mul(ncy, f0));
  int16_t dy = (int16_t)(((battle_sin_mul(ncx, f1) + battle_cos_mul(ncy, f1)) - battle_sin_mul(ncx, f0)) - battle_cos_mul(ncy, f0));
  int16_t oldContactY = u->contactY;
  int k = 0;
  for (;;)
  {
    if (try_move(b, u, dx, dy, turn))
    {
      while (u->blocker == 0 && k < 11)
      {
        step_forward(b, u);
        k++;
      }
      break;
    }
    if (!step_back(b, u) || ++k >= 11) break;
  }
  int s1 = oldContactY < 0 ? -1 : 1, s2 = u->contactY < 0 ? -1 : 1;
  if (s2 != s1 && (int16_t)uabs(u->contactY - oldContactY) < 0x10) u->contactY = oldContactY;
}

// something is in the way: push a friend, wheel against an enemy met at an angle (1000:2CFC)
static int blocked(S *b, U *u)
{
  if (u->blocker == 0) return 0;
  U *o = &b->u[u->blocker];
  if (side(u) == side(o)) return step_forward(b, u);
  if ((side(u) == 0 || o->blocker != u->id || o->contactX < 0x10) && u->contactX > 0xF &&
      ((uint16_t)(u->facing - o->facing + 0x71C) & 0x3FFF) > 0xE38)
  {
    wheel(b, u);
    return 1;
  }
  return 0;
}

static void retreat_all(S *b);

// join a melee, turn to an attacker, answer shooters (1000:3354)
static int engage(S *b, U *u)
{
  int e = find_frontal(b, u);
  if (e != 0)
  {
    U *o = &b->u[e];
    u->state = 13;
    u->target = (int16_t)e;
    u->counter = (int16_t)side(o);
    if (o->state == 13) o->counter = (int16_t)side(u);
    if (o->state == 14) stop(o);
    return 1;
  }
  for (int i = 1; i <= b->units; i++)
  {
    U *o = &b->u[i];
    if (side(o) != side(u) && o->target == u->id && o->state == 13)
    {
      u->state = 8;
      u->target = o->id;
      u->pendingTurn = 0;
      return 1;
    }
  }
  if (u->men <= u->reactMen)
    for (int i = 1; i <= b->units; i++)
    {
      U *o = &b->u[i];
      if (side(u) != side(o) && o->target == u->id && o->state == 14)
      {
        if (type(u) == 3 || type(u) == 4) return acquire(b, u);
        u->state = 12;
        u->target = o->id;
        charge(b, u);
      }
    }
  return 0;
}

// states 1, 2 and 3 (1000:34D6)
static void idle(S *b, U *u)
{
  if (blocked(b, u) || engage(b, u)) return;
  if (type(u) == 3 || type(u) == 4)
    acquire(b, u);
  else
  {
    scan(b, u);
    charge_decision(b, u);
  }
  u->counter++;
  if (u->state == 2 && b->retreat != 0 && side(u) == 0) retreat_all(b);
}

// ---------------------------------------------------------------- damage

// the damage of one attack (1000:07F0); r = range in pixels, 0 in melee
static int16_t damage(S *b, U *a, U *d, int r)
{
  if (d->state == 0) return 0;
  int v = (side(a) == 0 ? b->difficultyBonus : -b->difficultyBonus) + 4;
  int ratio = d->men < a->men ? a->men / d->men - 1 : -(d->men / a->men - 1);
  v += sshr(a->men - 0x40, 3) + ratio;
  v += sshr(a->morale - 0x40, 4) + sshr(b->generalship[side(a) != 0] - 0x40, 4);
  int16_t df = (int16_t)(a->facing - d->facing);
  if (uabs(df) < 0x222) v += 8;                        // from behind
  if (uabs(df + 0xC000) < 0x222) v += 6;               // on a flank
  if (uabs(df + 0x4000) < 0x222) v += 6;
  int ta = type(a), td = type(d);
  if (ta == 3 && 0x40 < r && r < 0x81) v -= 3;
  if (ta == 4 && 0x40 < r && r < 0x81) v -= 5;
  if (ta == 4 && 0 < r && r < 0x21) v += 4;
  if (ta == 4 && td == 2) v += 2;
  if (ta == 2 && td == 1) v += 2;
  if (ta == 1 && td == 4) v += 2;
  if (a->state == 13) v += a->terrainMod;
  if (v < 0) v = 0;
  if (0xC < v) v = 0xC;
  v += (int)(battle_rand(b) & 7);
  int dmg = 0;
  if (ta == 1 || ta == 3) dmg = battle_t16(0x15E2 + 2 * v);
  else if (ta == 2 || ta == 4) dmg = battle_t16(0x160A + 2 * v);
  if (b->units < 5) dmg <<= 1;
  return (int16_t)((dmg + 2) / 3);
}

// try a slightly different facing where no enemy is (1000:0BE0)
static int try_turn(S *b, U *u, int delta)
{
  u->facing += (int16_t)delta;
  if (find_collision(b, u) && side(&b->u[u->blocker]) != side(u))
  {
    u->facing -= (int16_t)delta;
    return 0;
  }
  return 1;
}

// apply the damage gathered this step (1000:0A1C)
static void damage_apply(S *b, U *u)
{
  if (u->projectile == -1)
  {
    if (u->state != 2) return;  // a volley that landed hands its damage over
    u->state = 0;
    U *t = &b->u[u->target];
    t->damage += u->damage;
    damage_apply(b, t);
    return;
  }
  if (u->damage == 0) return;
  int16_t men = (int16_t)(u->men - u->damage);
  u->damage = 0;
  if (men <= 0)
  {
    u->men = 0;
    destroy(u);
    return;
  }
  int lost = (int16_t)(u->men * 10) / u->initialMen - (int16_t)(men * 10) / u->initialMen;
  u->morale -= (int16_t)(lost * 10);  // 10 points for every tenth of the original strength
  int mpf = type_word(type(u), T_MPF);
  int oldFig = (int16_t)(u->men + mpf - 1) / mpf;
  u->men = men;
  int newFig = (int16_t)(men + mpf - 1) / mpf;
  if (newFig > 4 || newFig == oldFig) return;
  // the smaller block is centred differently: keep it in place
  int16_t ox = (int16_t)((ext(CENTRE_X, oldFig) - ext(CENTRE_X, newFig)) << 4);
  int16_t oy = (int16_t)((ext(CENTRE_Y, oldFig) - ext(CENTRE_Y, newFig)) << 4);
  int16_t dx = (int16_t)(battle_cos_mul(ox, (uint16_t)u->facing) - battle_sin_mul(oy, (uint16_t)u->facing));
  int16_t dy = (int16_t)(battle_cos_mul(oy, (uint16_t)u->facing) + battle_sin_mul(ox, (uint16_t)u->facing));
  u->x -= dx;
  u->y -= dy;
  u->destX -= dx;
  u->destY -= dy;
  if (try_turn(b, u, 0)) return;
  for (int d = 1; (unsigned)d < 0x444; d <<= 2)
    if (try_turn(b, u, d) || try_turn(b, u, -d)) return;
  destroy(u);
}

// ---------------------------------------------------------------- the active states

// state 4: along the formation's route, then find an enemy (1000:2974); state 5: an ordered march (2998)
static void march(S *b, U *u)
{
  if (u->state == 4 && u->facing == u->destFacing && u->x == u->destX && u->y == u->destY)
  {
    u->destX = u->wp2X;  // the second waypoint
    u->destY = u->wp2Y;
    u->destFacing = u->wp2Facing;
  }
  if (!move_toward(b, u))
  {
    stop(u);
    return;
  }
  if (u->men <= u->reactMen)
  {
    if (type(u) == 3 || type(u) == 4) acquire(b, u);
    u->counter++;
  }
}

static void route(S *b, U *u)
{
  march(b, u);
  if (u->state == 2 && u->blocker == 0) seek(b, u);
}

// state 6: a volley flies to where the target stood (1000:29F4)
static void projectile(S *b, U *u)
{
  if ((((uint16_t)u->x & 0xFFF0) != ((uint16_t)u->destX & 0xFFF0) || ((uint16_t)u->y & 0xFFF0) != ((uint16_t)u->destY & 0xFFF0)) &&
      (type(u) != 6 || u->counter++ == 0))
  {
    int16_t vx, vy;
    velocity(b, u, &vx, &vy);
    u->x += vx;
    u->y += vy;
    return;
  }
  stop(u);
}

// state 8: turn to face the unit attacking in melee (1000:36D2)
static void face_attacker(S *b, U *u)
{
  U *a = &b->u[u->target];
  if (a->state != 13 || a->target != u->id)
  {
    stop(u);
    return;
  }
  int16_t need = (int16_t)((int16_t)(a->facing - u->facing) - u->pendingTurn);
  int16_t t = (int16_t)(need + 0x8000);
  if (uabs(t) > 0x221)
  {
    u->pendingTurn += t < 0 ? -0x400 : 0x400;
    return;
  }
  u->facing = (int16_t)(a->facing + 0x8000);
  do
  {
    if (step_forward(b, u))
    {
      for (int k = 0; u->blocker == 0 && k < 0x15; k++) step_forward(b, u);
      engage(b, u);
      return;
    }
    u->men--;
  } while (u->men > 0);
  destroy(u);
}

// state 10: archers fall back from an enemy that came too close (1000:35BE)
static void fall_back(S *b, U *u)
{
  u->destX = (int16_t)(u->x - battle_cos_mul(0x40, (uint16_t)u->facing));
  u->destY = (int16_t)(u->y - battle_sin_mul(0x40, (uint16_t)u->facing));
  if (move_toward(b, u))
  {
    if (u->blocker != 0) return;
    scan(b, u);
    // a ray that left the field has id -1: the original then reads the zeroed bytes below record 0
    for (int k = 1; k <= 3; k++)
    {
      int id = b->rayId[k], s = id >= 0 && id < BATTLE_RECORDS ? side(&b->u[id]) : 0;
      if (s != side(u) && b->rayDist[k] < 0x19) return;
    }
  }
  stop(u);
}

// state 11: flee straight ahead (1000:3686)
static void rout(S *b, U *u)
{
  u->destX = (int16_t)(u->x + battle_cos_mul(0x80, (uint16_t)u->facing));
  u->destY = (int16_t)(u->y + battle_sin_mul(0x80, (uint16_t)u->facing));
  if (!move_toward(b, u)) stop(u);
}

// state 13: melee (1000:05D4)
static void melee(S *b, U *u)
{
  U *t = &b->u[u->target];
  if (t->state == 0)
  {
    seek(b, u);
    return;
  }
  if (!frontal_contact(b, u, t))
  {
    stop(u);
    return;
  }
  if ((int16_t)uabs(b->centreY) >= 0x10)  // slide sideways to line up with the enemy
  {
    int16_t a = (int16_t)(u->facing + (b->centreY < 0 ? -0x4000 : 0x4000));
    try_move(b, u, battle_cos_mul(0x10, (uint16_t)a), battle_sin_mul(0x10, (uint16_t)a), 0);
  }
  if (++u->counter >= battle_t16(0x1512))
  {
    u->counter = 0;
    t->damage += damage(b, u, t, 0);
  }
}

// state 14: shoot (1000:069C)
static void shoot(S *b, U *u)
{
  U *t = &b->u[u->target];
  if (t->state != 0)
  {
    int16_t ang = angle_to(u->x, u->y, t->x, t->y);
    if (u->facing != ang)
    {
      u->destFacing = ang;
      if (!move_toward(b, u) && uabs(u->facing - ang) > 0x1FFF) goto giveUp;
    }
    int8_t hit = (int8_t)u->id;
    int d = ray(b, u->x, u->y, (uint16_t)ang, &hit);
    if (d < 0x41 && (uint16_t)u->target == (uint8_t)hit && d != 0)
    {
      if (type(u) == 3 && d < 0x10)
      {
        u->state = 10;
        return;
      }
      if (++u->counter < type_word(type(u), T_FIRE)) return;
      if (u->open != 0) return;
      u->counter = 0;
      U *p = &b->u[u->projectile];
      if (p->state != 0) return;
      p->state = 6;
      p->counter = 0;
      p->target = u->target;
      p->x = u->x;
      p->y = u->y;
      p->destX = t->x;
      p->destY = t->y;
      p->facing = ang;
      p->destFacing = ang;
      p->damage = damage(b, u, t, d);
      return;
    }
  }
giveUp:
  stop(u);
}

// R: the whole army turns south and flees (1000:37AA)
static void retreat_all(S *b)
{
  for (int i = 1; i <= b->units; i++)
  {
    U *u = &b->u[i];
    if (side(u) != 0 || u->state == 0) continue;
    u->state = 11;
    u->morale = 0;
    u->facing = 0x4000;
    u->destFacing = 0x4000;
    while (!step_forward(b, u))
      if (--u->men < 1)
      {
        destroy(u);
        return;
      }
  }
}

static void run_state(S *b, U *u)
{
  switch (u->state)
  {
  case 1: case 2: case 3: idle(b, u); break;
  case 4: route(b, u); break;
  case 5: march(b, u); break;
  case 6: projectile(b, u); break;
  case 7: wheel(b, u); break;
  case 8: face_attacker(b, u); break;
  case 10: fall_back(b, u); break;
  case 11: rout(b, u); break;
  case 12: charge(b, u); break;
  case 13: melee(b, u); break;
  case 14: shoot(b, u); break;
  default: break;
  }
}

// ---------------------------------------------------------------- morale

// situational modifiers on top of the unit's morale (1000:234A)
static void morale_mods(S *b, U *u)
{
  U *t = &b->u[u->target];
  if (u->state == 10) u->effMorale -= 0x1E;
  if (u->state > 11)
  {
    if (t->state == 11) u->effMorale += 0x1E;
    if ((int16_t)(t->men * 2) <= u->men) u->effMorale += 0x14;
    if (type(u) == 2 && type(t) == 1) t->effMorale -= 0xF;
    if (type(u) == 2 && type(t) == 3) t->effMorale -= 0x1E;
    int16_t df = (int16_t)(u->facing - t->facing);
    if (uabs(df) < 0x222) t->effMorale -= 0x28;
    if (uabs(df + 0xC000) < 0x222) t->effMorale -= 0x14;
    if (uabs(df + 0x4000) < 0x222) t->effMorale -= 0x14;
  }
}

// rally a routed unit that got away, rout a beaten one (1000:2424)
static void rout_check(S *b, U *u)
{
  if (u->target == 0) return;
  U *t = &b->u[u->target];
  if (u->effMorale > 0 && u->state == 11 && t->target != u->id && u->blocker == 0 &&
      ((int16_t)battle_distance((int16_t)(u->x - t->x), (int16_t)(u->y - t->y), 0) >> 4) > 0x32)
    stop(u);
  if (u->effMorale < 0 && u->state != 11 && u->state != 10 && u->state != 14 && t->state > 11)
  {
    u->state = 11;
    u->facing = t->facing;
    u->destFacing = t->facing;
    do
    {
      if (step_forward(b, u)) return;
      u->men--;
    } while (u->men > 0);
    destroy(u);
  }
}

// ---------------------------------------------------------------- the per-step unit pass

static int8_t terrain_divisor(S *b, int t, int px, int py)
{
  if (t == 6 || t == 5) return 1;
  int8_t c = terr_get(b, px, py);
  if (c == -9) return t == 2 ? 2 : 1;
  if (c == -7) return t == 2 ? 8 : 4;
  if (c == -3 || c == -2) return 2;
  return 1;
}

// marching sideways or backwards (an ordered move without turning, off the facing by > 15 degrees) (22E4)
static int sideways(const U *u)
{
  if (u->state == 5 && u->facing == u->destFacing)
  {
    int16_t a = angle_to(u->x, u->y, u->destX, u->destY);
    if (a != -1 && uabs(u->facing - a) > 0xAA9) return 1;
  }
  return 0;
}

// the drawing pass's effects on a unit: its footprint in the visibility map, the terrain it fights on,
// its speed, destruction when it left the field (1000:49C8)
static void unit_pass(S *b, U *u)
{
  int divisor = 1, offGrid = 1;
  if ((u->state == 13 || u->state == 8) && ++u->phase > 7) u->phase = 0;
  int sum = 0, cells = 0;
  int n = figures(u);
  for (int f = 0; f < n; f++)
  {
    int lx = battle_t16(FIG_X + 2 * f) - ext(CENTRE_X, n), ly = battle_t16(FIG_Y + 2 * f) - ext(CENTRE_Y, n);
    int px = (int16_t)(((int16_t)u->x >> 4) + battle_cos_mul((int16_t)lx, (uint16_t)u->facing) - battle_sin_mul((int16_t)ly, (uint16_t)u->facing));
    int py = (int16_t)(((int16_t)u->y >> 4) + battle_cos_mul((int16_t)ly, (uint16_t)u->facing) + battle_sin_mul((int16_t)lx, (uint16_t)u->facing));
    unsigned c0 = (uint16_t)(((int16_t)(px - 5) >> 2) + 2), c1 = (uint16_t)(((int16_t)(px + 4) >> 2) + 2);
    unsigned r0 = (uint16_t)(((int16_t)(py - 5) >> 2) + 2), r1 = (uint16_t)(((int16_t)(py + 4) >> 2) + 2);
    if (c0 >= BATTLE_MAP_W || r0 >= BATTLE_MAP_H) continue;
    if (c1 > 0x53) c1 = 0x53;
    if (r1 > 0x35) r1 = 0x35;
    offGrid = 0;
    int draw = 1;
    if (type(u) != 6 && type(u) != 5)
    {
      int woods = 0;
      for (unsigned r = r0; r <= r1; r++)
        for (unsigned c = c0; c <= c1; c++)
        {
          int8_t t = b->terrain[r * BATTLE_MAP_W + c];
          if (u->state == 13 || u->state == 8)
          {
            cells++;
            if (t == -7 || t == -2) sum -= 2;
            else if (t == -3) sum -= 1;
          }
          else if (t == -9)
            woods++;
          else
            woods--;
        }
      if (woods < 1)
      {
        for (unsigned r = r0; r <= r1; r++)
          for (unsigned c = c0; c <= c1; c++) b->visible[r * BATTLE_MAP_W + c] = (uint8_t)u->id;
      }
      else if (side(u) != 0)
        draw = 0;  // an enemy hidden in the woods
    }
    if (draw)
    {
      // the figure's drawn position (spread when fleeing or opened, jittering in melee) is where the
      // terrain divisor is sampled
      if (u->state == 11 || u->state == 10 || u->open != 0)
      {
        lx += battle_t16(FIG_X + 2 * f) >> 1;
        ly += battle_t16(FIG_Y + 2 * f) >> 1;
        px = (int16_t)(((int16_t)u->x >> 4) + battle_cos_mul((int16_t)lx, (uint16_t)u->facing) - battle_sin_mul((int16_t)ly, (uint16_t)u->facing));
        py = (int16_t)(((int16_t)u->y >> 4) + battle_cos_mul((int16_t)ly, (uint16_t)u->facing) + battle_sin_mul((int16_t)lx, (uint16_t)u->facing));
      }
      if (u->state == 13 || u->state == 8)
      {
        lx += battle_t16(0x16CE + 2 * (u->phase + f));
        ly += battle_t16(0x16EE + 2 * (u->phase + f));
        px = (int16_t)(((int16_t)u->x >> 4) + battle_cos_mul((int16_t)lx, (uint16_t)u->facing) - battle_sin_mul((int16_t)ly, (uint16_t)u->facing));
        py = (int16_t)(((int16_t)u->y >> 4) + battle_cos_mul((int16_t)ly, (uint16_t)u->facing) + battle_sin_mul((int16_t)lx, (uint16_t)u->facing));
      }
    }
    int dv = terrain_divisor(b, type(u), px, py);
    if (divisor < dv) divisor = dv;
  }
  if (offGrid)
  {
    destroy(u);
    return;
  }
  if (cells != 0) u->terrainMod = (int16_t)((sum << 3) / cells);
  if (sideways(u)) divisor = 4;
  u->speed = (int16_t)(type_word(type(u), T_SPEED) / divisor);
  u->open = 0;
}

// ---------------------------------------------------------------- the player's orders

static void render_logic(S *b)
{
  // the cursor is drawn unless blinking: the selection is dropped when its unit is gone (1000:4FA4)
  int old = b->cursorBlink;
  if (b->cursorBlink == 0 || (b->cursorBlink--, (old & 1) == 0))
    if (b->u[b->selected].state == 0) b->selected = 0;
}

static void cursor_move(S *b, int dx, int dy)
{
  b->cursorX = clamp16(b->cursorX + dx * 4, 8, 0x13A);
  b->cursorY = clamp16(b->cursorY + dy * 4, 3, 0xBF);
  render_logic(b);
}

// a unit in melee or turning to an attacker refuses (the cursor blinks) (1000:3CEC)
static int refuses(S *b, U *u)
{
  if (u->state != 13 && u->state != 8) return 0;
  b->cursorBlink = 10;
  return 1;
}

static int16_t order_facing(S *b, U *u)
{
  int16_t a = angle_to(u->x, u->y, b->cursorX, b->cursorY);
  if (a != -1 && ((int16_t)battle_distance((int16_t)(u->x - b->cursorX), (int16_t)(u->y - b->cursorY), 0) >> 4) > 1) return a;
  return u->facing;
}

static int nearest_to_cursor(S *b)
{
  int pick = 0, best = 999;
  for (int i = 1; i <= b->units; i++)
  {
    const U *u = &b->u[i];
    if (side(u) == 0 && u->state != 0 && on_map(u))
    {
      int d = (int16_t)battle_distance((int16_t)(u->x - b->cursorX), (int16_t)(u->y - b->cursorY), 0x400) >> 4;
      if (d < best)
      {
        best = d;
        pick = i;
      }
    }
  }
  return pick;
}

// one key, as the input handler 1000:3920 treats it
static void battle_key(S *b, uint16_t key)
{
  if (key == 0 || key == 0x1000 || key == 0x2400 || key == 0x2F00) return;  // Alt-Q/J/V: not simulated
  static const int8_t mx[] = { -1, 0, 1, 0, -1, 0, 1, 0, -1, 0, 1 }, my[] = { -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1 };
  int scan = key >> 8;
  if (scan == 0x47 || scan == 0x48 || scan == 0x49 || scan == 0x4B || scan == 0x4D || scan == 0x4F || scan == 0x50 || scan == 0x51)
  {
    cursor_move(b, mx[scan - 0x47], my[scan - 0x47]);
    return;
  }
  int ascii = key & 0xFF;
  b->cursorX = (int16_t)(b->cursorX << 4);
  b->cursorY = (int16_t)(b->cursorY << 4);
  U *s = &b->u[b->selected];
  int order = 0;  // 1 march, 2 march without turning, 3 turn in place
  if (ascii == 0x2D) order = 2;
  else if (ascii == 0x2B || ascii == 0x3D) order = 1;
  else if (ascii == 0x2A) order = 3;
  if (order != 0)
  {
    if (b->selected != 0 && !refuses(b, s))
    {
      if (order == 3) stop(s);
      s->state = 5;
      s->counter = 0;
      if (order != 3)
      {
        s->destX = b->cursorX;
        s->destY = b->cursorY;
      }
      s->destFacing = order == 2 ? s->facing : order_facing(b, s);
      b->selected = 0;
    }
  }
  else if (ascii >= 0x30 && ascii <= 0x39)
  {
    int n = ascii - 0x30;
    if (n != 0 || b->selected == 0)
    {
      if (n == 0) n = nearest_to_cursor(b);
      U *u = &b->u[n];
      if (n <= b->units && side(u) == 0 && u->state != 0 && on_map(u))
      {
        b->selected = (int16_t)n;
        u->state = 3;
        u->reactMen = (int16_t)(u->men - sshr(u->initialMen, 3));
        b->cursorX = u->x;
        b->cursorY = u->y;
      }
    }
  }
  else if (ascii == 0x52 || ascii == 0x72)
  {
    b->retreat = 1;
    retreat_all(b);
  }
  else if (ascii == 0x0D)
  {
    for (int i = 1; i <= b->units; i++)
    {
      U *u = &b->u[i];
      if (side(u) == 0 && u->state != 0 && contains_point(b, b->cursorX, b->cursorY, u))
      {
        b->selected = (int16_t)i;
        b->cursorX = u->x;
        b->cursorY = u->y;
        break;
      }
    }
  }
  else if (ascii == 0x1B)
    b->selected = 0;
  b->cursorX = (int16_t)(b->cursorX >> 4);
  b->cursorY = (int16_t)(b->cursorY >> 4);
}

// ---------------------------------------------------------------- the battle loop

uint16_t battle_rand(S *b)
{
  b->rng = b->rng * 0x343FDu + 0x269EC3u;
  return (uint16_t)((b->rng >> 16) & 0x7FFF);
}

static void keys_after(S *b, const BattleKeys *keys, int pass)
{
  for (int i = 0; i < keys->count; i++)
    if (keys->k[i].pass == pass) battle_key(b, keys->k[i].key);
}

static int men_of(S *b, int enemy)
{
  int m = 0;
  for (int i = 1; i <= b->units; i++)
    if ((b->u[i].flags & 8) == (enemy ? 8 : 0)) m += b->u[i].men;
  return (int16_t)m;
}

// the status jingle's band (1000:47C4)
static void jingle(S *b)
{
  if (b->sharedSound != 0) return;
  int d = (int)((uint16_t)(men_of(b, 0) * 100) / (uint16_t)b->playerMen) - (int)((uint16_t)(men_of(b, 1) * 100) / (uint16_t)b->enemyMen);
  int band = (d > 1) + (d > 3) - (d < -1) - (d < -3);
  if (band != 0 && band != b->jingleBand) b->jingleBand = (int16_t)band;
}

// one side has no unit left (1000:13A6)
static int battle_over(S *b)
{
  if (b->over != 0) return 1;
  int sides = 0;
  for (int i = 1; i <= b->units; i++)
  {
    if (b->u[i].state != 0) sides |= (b->u[i].flags & 8) == 0 ? 1 : 2;
    if (sides == 3) return 0;
  }
  b->playerHasUnits = (int16_t)(sides & 1);
  b->enemyHasUnits = (int16_t)(sides & 2);
  b->over = 1;
  return 0;
}

int battle_step(S *b, const BattleKeys *keys)
{
  memset(b->visible, 0, sizeof b->visible);
  for (int i = 1; i <= b->units; i++) b->u[i].terrainMod = 0;
  for (int i = 1; i <= b->records; i++)
    if (b->u[i].state != 0) unit_pass(b, &b->u[i]);
  render_logic(b);
  // the formation's route units march at the pace of the slowest
  b->groupSpeed = 0x630;
  for (int i = 1; i <= b->units; i++)
    if (b->u[i].state == 4 && b->u[i].speed != 0 && b->u[i].speed < b->groupSpeed) b->groupSpeed = b->u[i].speed;
  for (int i = 1; i <= b->records; i++)
    if (b->u[i].state != 0) run_state(b, &b->u[i]);
  keys_after(b, keys, 0);
  for (int i = 1; i <= b->records; i++)
    if (b->u[i].state != 0) damage_apply(b, &b->u[i]);
  keys_after(b, keys, 1);
  for (int i = 1; i <= b->units; i++)
    if (b->u[i].state != 0) b->u[i].effMorale = b->u[i].morale;
  keys_after(b, keys, 2);
  for (int i = 1; i <= b->units; i++)
    if (b->u[i].state != 0) morale_mods(b, &b->u[i]);
  keys_after(b, keys, 3);
  for (int i = 1; i <= b->units; i++)
    if (b->u[i].state != 0) rout_check(b, &b->u[i]);
  keys_after(b, keys, 4);
  keys_after(b, keys, 5);
  jingle(b);
  battle_over(b);
  return b->over;
}
