// The start-up program (START.EXE): the title, the credits, the crest quiz (the copy protection), the career
// menu, the samurai's name, province, difficulty and family advantage; it leaves them in the shared block for the
// role-playing game. Recompiled from the floppy's program (start_core.c) over an image of its data segment.
#ifndef OPENSAMURAI_START_H
#define OPENSAMURAI_START_H

#include <stdint.h>

#define START_DS_SIZE 0x10000

// What the program takes from the outside world while it runs
typedef struct
{
  // DOS's answers: INT 21h 2Ah the date (CX year, DH month, DL day), 2Ch the time (CH hours, CL minutes, DH
  // seconds, DL hundredths): CX << 16 | DX; 0Bh (kbhit) a character is waiting: AL
  uint32_t (*dos)(void *ctx, int ah);
  // the MISC driver's answers: 90 a key is waiting (0 yes, FFFF no), 91 the next key (scan code << 8 | ASCII),
  // 95 a joystick button (1 pressed), 96 and 97 the axes
  uint16_t (*input)(void *ctx, int slot);
  // the program waits for the frame timer (its interrupt handler counts the frames at DS:1BA8, the loop at
  // START 1000:site polls it): the host lets the frames pass, setting the handler's bytes DS:1BA8-1BC7 as they
  // are when the wait ends
  void (*framePoll)(void *ctx, int site);
  uint16_t (*biosTicks)(void *ctx);  // the BIOS tick count (INT 1Ah: the random seed)
  void (*exit)(void *ctx, int code);  // exit(): does not return (1 on to the role-playing game, 0 quit, 99 a file error)
  const char *gameDir;                // the game's files
  void *ctx;
} StartHost;

// Use this data segment image (START_DS_SIZE bytes) and host; dsSeg and sharedSeg are the segments of the data
// segment and of the shared block
void start_attach(uint8_t *ds, uint16_t dsSeg, uint16_t sharedSeg, const StartHost *host);

// Runs the program from main (1000:0010) with the registers SP BP SI DI ES AX BX CX DX there, until exit()
void start_main(const uint16_t regs[9]);

// Called with the original address (seg << 16 | off, Ghidra's segments) of every function as it is entered
extern void (*start_trace)(uint32_t addr);

#endif
