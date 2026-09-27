#include "dsimage.h"

#include <stdlib.h>

uint8_t *g_ds;
u16 g_bios[0x300];
u16 g_dsSeg, g_sharedSeg;
u16 g_sp = 0xFFFE;

// The rest of the 8086's megabyte, for the buffers the programs allocate: a segment addresses it directly
static uint8_t *memory;

u8 *far_ptr(u16 seg, u16 off)
{
  if (seg == g_dsSeg && g_ds) return g_ds + off;
  if (seg == g_sharedSeg) return shared.b + (off & (SHARED_SIZE - 1));
  if (!memory) memory = calloc(1, 0x110000);
  return memory + ((uint32_t)seg << 4) + off;
}
