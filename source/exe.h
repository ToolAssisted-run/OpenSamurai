// DOS executables loaded into the emulated megabyte (exe.c)
#ifndef OPENSAMURAI_EXE_H
#define OPENSAMURAI_EXE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  uint16_t cs, ip, ss, sp;       // the entry and the stack, as loaded
  uint16_t minAlloc, maxAlloc;   // the paragraphs the program wants beyond its image (the header's)
  uint16_t imageParagraphs;      // the image's size once unpacked
} ExeInfo;

// Loads an MZ executable (EXEPACK-compressed or not) at segment seg, relocated for it (as INT 21h 4B00/4B03 do)
bool exe_load(const char *path, uint16_t seg, ExeInfo *info);
// Loads a file as it is at segment seg
bool raw_load(const char *path, uint16_t seg, uint32_t *bytes);

#endif
