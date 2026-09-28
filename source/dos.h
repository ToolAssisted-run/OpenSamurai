// DOS (INT 21h) for the recompiled programs (dos.c)
#ifndef OPENSAMURAI_DOS_H
#define OPENSAMURAI_DOS_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  const char *gameDir;  // the game's files
  // the answers DOS gives from the outside world: 2Ah the date (CX << 16 | DX), 2Ch the time (CX << 16 | DX), 0Bh
  // a character waiting (AL), 07h/08h the next character (AL)
  uint32_t (*answer)(void *ctx, int ah);
  void (*exit)(int code);  // 4Ch
  void *ctx;
} DosHost;

void dos_attach(const DosHost *host);
// INT 21h with the registers in R: true if served
bool dos_int21(void);
// the program ended: its files are closed
void dos_close_all(void);

#endif
