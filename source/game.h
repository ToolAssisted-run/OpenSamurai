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
  void (*present)(void *ctx);                  // a video frame is complete: show VRAM (A000) through the DAC (asm_dac)
  uint64_t (*now)(void *ctx);                  // the time: microseconds, from any origin
  void (*sleepUntil)(void *ctx, uint64_t t);   // wait until then (the frontend takes the keyboard's events meanwhile)
  int (*keyWaiting)(void *ctx);
  uint16_t (*readKey)(void *ctx);  // the next key (the BIOS's: scan code << 8 | ASCII), called when one is waiting
  GameClock start;                 // the date and time when the game starts: the clock runs on with now()
  const char *gameDir;
  bool noTitle;  // /NT: no title sequence
  void *ctx;
  char sound;    // the setup's sound driver (its name's letter, as the setup's /A<letter>): 'I' the IBM speaker, 'T'
                 // Tandy's, 'A' the AdLib, 'R' the Roland MT-32 (its MIDI to midi), else none
  // the speaker's sound, as each frame ends: 44100 samples a second, mono (NULL: not wanted)
  void (*audio)(void *ctx, const int16_t *samples, int n);
  // the MT-32's MIDI (sound 'R'), a byte at a time, with its time in the audio's samples (NULL: not wanted)
  void (*midi)(void *ctx, uint8_t byte, uint64_t sample);
} GameHost;

// The video frames (70.086 a second, the VGA's): their count so far
extern uint64_t game_frames;

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
  // a sound driver the setup chose: a segment of its own above the video memory (the real game has it where the
  // no-sound driver is, and everything after it higher by its size)
  GAME_SOUND_DRIVER_SEG = 0xD000,
};

// The launcher's work before the first program: the drivers and fonts loaded, the shared block as the launcher and
// the setup leave it. False if a file is missing
bool game_setup(const GameHost *host);

// A key pressed or released (the PC's scan code, set 1; extended: the grey keys, E0-prefixed), for the programs
// that read the keyboard's port themselves (their INT 9 handlers). The BIOS's keys go through keyWaiting/readKey.
void game_key(uint8_t scan, bool extended, bool pressed);

// Runs the game from the start-up program on; returns when the player quits
int game_run(const GameHost *host);

#endif
