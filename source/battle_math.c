// BATTLE.EXE's fixed-point geometry (1000:207E-20D0, 1000:6393-6568): angles are 16-bit (0x10000 = a full
// turn, 0 = east, 0x4000 = south), sines come from a 257-entry table with linear interpolation, and every
// rounding step is kept as the 16-bit code did it.
#include "battle.h"

// sin(a) * 0x8000: the table entry for the high byte plus the interpolated low byte (1000:63E5)
static int16_t sin_interp(uint16_t a)
{
  int hi = a >> 8, lo = a & 0xFF;
  int16_t s0 = battle_t16(0x18B2 + 2 * hi), s1 = battle_t16(0x18B4 + 2 * hi);
  int32_t prod = (int32_t)(int16_t)(s1 - s0) * lo;
  return (int16_t)(s0 + (int16_t)(prod >> 8) + ((prod >> 7) & 1));
}

// v * sin(a) and v * cos(a), rounded (1000:63AF, 1000:6393)
static int16_t mul_round(int16_t s, int16_t v)
{
  int32_t prod = (int32_t)s * v;
  return (int16_t)((prod >> 15) + ((prod >> 14) & 1));
}

int16_t battle_sin_mul(int16_t v, uint16_t a) { return mul_round(sin_interp(a), v); }
int16_t battle_cos_mul(int16_t v, uint16_t a) { return mul_round(sin_interp((uint16_t)(a + 0x4000)), v); }

// atan2 (1000:6404): the angle of (x, y); a polynomial approximation on the octant
uint16_t battle_atan2(int16_t x, int16_t y)
{
  if (y == 0) return x > 0 ? 0 : 0x8000;
  if (x == 0) return y > 0 ? 0x4000 : 0xC000;
  int ax = x < 0 ? -x : x, ay = y < 0 ? -y : y;
  int32_t num;
  int den, steep;
  if (ay > ax) { num = (int32_t)ax << 14; den = ay; steep = 1; }
  else { num = (int32_t)ay << 14; den = ax; steep = 0; }
  int16_t q = (int16_t)(num / den);
  int d = 0x1333 - q;
  if (d < 0) d = -d;
  int32_t t = ((int32_t)d * 0xB00) >> 14;
  int16_t r = (int16_t)(((0x2800 - t) * (int32_t)q) >> 14);
  if (y > 0)
  {
    if (x > 0) return (uint16_t)(steep ? 0x4000 - r : r);
    return (uint16_t)(steep ? r + 0x4000 : 0x8000 - r);
  }
  if (x > 0) return (uint16_t)(steep ? r + 0xC000 : -r);
  return (uint16_t)(steep ? 0xC000 - r : r + 0x8000);
}

// sqrt(x*x + y*y) by Newton's method from a power-of-two estimate (1000:20D0)
uint16_t battle_hypot(int16_t x, int16_t y)
{
  int32_t v = (int32_t)y * y + (int32_t)x * x;
  if (v <= 0) return 0;
  uint32_t u = (uint32_t)v;
  int n;
  uint16_t w;
  if ((u >> 16) != 0) { n = 32; w = (uint16_t)(u >> 16); }
  else { n = 16; w = (uint16_t)u; }
  int top;
  do
  {
    top = (w & 0x8000) != 0;
    w = (uint16_t)(w << 1);
    n--;
  } while (!top);
  uint32_t shifted = u >> (n >> 1);
  uint16_t est = (uint16_t)shifted, prev;
  do
  {
    prev = est;
    uint16_t quo = (uint16_t)(u / prev);
    est = (uint16_t)(((uint32_t)quo + prev) >> 1);
  } while (est < prev);
  return prev;
}

// The approximate distance max + min/4 (+ a correction near the diagonal), exact only below the given
// threshold (1000:207E)
uint16_t battle_distance(int16_t x, int16_t y, uint16_t exactBelow)
{
  uint16_t a = (uint16_t)(x < 0 ? -x : x), b = (uint16_t)(y < 0 ? -y : y);
  uint16_t hi = a, lo = b;
  if (a < b) { hi = b; lo = a; }
  uint16_t d = (uint16_t)((lo >> 2) + hi);
  int16_t diag = (int16_t)(lo * 2 - hi);
  if (hi <= (uint16_t)(lo * 2) && diag != 0) d = (uint16_t)(d + ((uint16_t)(diag * 3) >> 4));
  d = (uint16_t)(d - (d >> 5));
  if (exactBelow <= d) return d;
  return battle_hypot(x, y);
}
