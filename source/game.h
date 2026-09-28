// The game as its launcher (SAMURAI.COM) runs it, in one program: the drivers loaded, the setup's choices, then
// START, the role-playing game and the action games, each as the launcher would start it. The frontend gives the
// screen, the keyboard and the clock (game.c).
#ifndef OPENSAMURAI_GAME_H
#define OPENSAMURAI_GAME_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  int year, month, day, hour, minute, second, hundredths;
} GameClock;

typedef struct
{
  // a video frame ends (70 Hz): show the screen (VRAM at A000, the palette asm_dac) and wait for its time; the
  // keyboard's events are taken here
  void (*frame)(void *ctx);
  int (*keyWaiting)(void *ctx);
  uint16_t (*readKey)(void *ctx);  // the next key (the BIOS's: scan code << 8 | ASCII), called when one is waiting
  void (*clock)(void *ctx, GameClock *c);  // the local date and time
  uint32_t (*biosTicks)(void *ctx);         // 18.2 Hz ticks since midnight
  const char *gameDir;
  bool noTitle;  // /NT: no title sequence
  void *ctx;
} GameHost;

// The segments the launcher gives the pieces in the real game (VGA, no sound): the layout is the original's, so
// that every pointer the programs keep is the same
enum
{
  GAME_SHARED_SEG = 0x1942,   // the 1 KB shared block
  GAME_MISC_SEG = 0x1983,     // MISC.EXE (keyboard, joystick)
  GAME_SOUND_SEG = 0x19AA,    // the sound driver (NSOUND.SAM)
  GAME_GRAPHICS_SEG = 0x19BD, // MGRAPHIC.EXE, FONTS.SAM right after its image
  GAME_BUFFER_SEG = 0x1C72,   // the launcher's 44 KB picture buffer
  GAME_ENV_SEG = 0x2773,      // a program's environment
  GAME_PSP_SEG = 0x27BC,      // its program segment prefix; the program at +10h
};

// The launcher's work before the first program: the drivers and fonts loaded, the shared block as the launcher and
// the setup leave it. False if a file is missing
bool game_setup(const GameHost *host);

// Runs the game from the start-up program on; returns when the player quits
int game_run(const GameHost *host);

#endif
