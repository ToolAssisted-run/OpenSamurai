// The 1 KB block the original launcher allocates once and every program finds through 0040:00F0: the
// programs talk to each other through it (drivers, options, the encounter parameters, the results). In
// OpenSamurai it is one C object with the same layout, so the reconstructed programs keep addressing it by
// offset while their fields are worked out (docs/FINDINGS.md lists the known ones).
#ifndef OPENSAMURAI_SHARED_H
#define OPENSAMURAI_SHARED_H

#include <stdint.h>

#define SHARED_SIZE 0x400

typedef struct
{
  uint8_t b[SHARED_SIZE];
} SharedBlock;

extern SharedBlock shared;

static inline uint16_t shared_w(int off) { return (uint16_t)(shared.b[off] | (shared.b[off + 1] << 8)); }
static inline int16_t shared_i(int off) { return (int16_t)shared_w(off); }
static inline void shared_set_w(int off, uint16_t v)
{
  shared.b[off] = (uint8_t)v;
  shared.b[off + 1] = (uint8_t)(v >> 8);
}

// Known offsets
enum
{
  SH_GRAPHICS_DRIVER = 0x00,   // ASCIIZ, 13 bytes
  SH_SOUND_DRIVER    = 0x0D,   // ASCIIZ, 13 bytes
  SH_VIDEO_MODE      = 0x22,   // 0 CGA, 1 Tandy, 2 EGA, 3 MCGA, 4 VGA, 5 Hercules
  SH_NO_TITLE        = 0x26,   // /NT
  SH_JOYSTICK        = 0x34,
  SH_DUEL_PLAYER_WON = 0x4C,
  SH_DUEL_PLAYER_FELL = 0x4E,
  SH_WOUNDED         = 0x54,   // the player carries a wound (melee -> duel -> RP)
  SH_DUEL_BACKGROUND = 0x5C,   // 0 village, 1 outside, 2 inside
  SH_DUEL_RETREATED  = 0x62,
  SH_SOUND_MODE      = 0x310,  // 0 music and effects, 1 effects, 2 silent (Alt-V cycles it)
};

#endif
