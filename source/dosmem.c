// DOS's memory arena for the programs (first fit, as DOS allocates), so that their buffers get the segments they
// got in the real game: the drivers and programs keep far pointers into them in their data
#include "dosmem.h"

#include <string.h>

#include "asm2c.h"

u16 dos_owner = 0x27BC;  // the program's PSP (its code at 27CC in the oracle)

typedef struct { u16 seg, size; bool used; u16 owner; } Mcb;  // seg = the block's paragraph (the MCB is the one before)
static Mcb arena[256];
static int nArena;

void dos_set_arena(u16 first, u16 end)
{
  nArena = 1;
  arena[0] = (Mcb){ (u16)(first + 1), (u16)(end - first - 1), false };
}

// the arena as DOS has it in memory: the chain of memory control blocks ('M'/'Z', owner, paragraphs) from the
// first one at or above paragraph `from` that chains consistently to the last ('Z') below `to`
void dos_arena_from_memory(u16 from, u16 to)
{
  for (u32 p = from; p < to; p++)
  {
    u32 q = p;
    int n = 0, ok = 0;
    Mcb tmp[256];
    while (q < to && n < 256)
    {
      u8 *m = far_ptr((u16)q, 0);
      if (m[0] != 'M' && m[0] != 'Z') break;
      u16 owner = (u16)(m[1] | (m[2] << 8)), size = (u16)(m[3] | (m[4] << 8));
      tmp[n++] = (Mcb){ (u16)(q + 1), size, owner != 0, owner };
      if (m[0] == 'Z') { ok = n >= 2; break; }
      q += 1u + size;
    }
    if (ok)
    {
      memcpy(arena, tmp, sizeof(Mcb) * (size_t)n);
      nArena = n;
      return;
    }
  }
}

static void merge_free(void)
{
  for (int k = 0; k + 1 < nArena; k++)
    if (!arena[k].used && !arena[k + 1].used)
    {
      arena[k].size = (u16)(arena[k].size + 1 + arena[k + 1].size);
      memmove(&arena[k + 1], &arena[k + 2], sizeof(Mcb) * (size_t)(nArena - k - 2));
      nArena--;
      k--;
    }
}

u16 dos_alloc(u16 paragraphs)
{
  merge_free();
  for (int k = 0; k < nArena; k++)
    if (!arena[k].used && arena[k].size >= paragraphs)
    {
      if (arena[k].size > paragraphs)
      {
        memmove(&arena[k + 2], &arena[k + 1], sizeof(Mcb) * (size_t)(nArena - k - 1));
        nArena++;
        arena[k + 1] = (Mcb){ (u16)(arena[k].seg + paragraphs + 1), (u16)(arena[k].size - paragraphs - 1), false };
        arena[k].size = paragraphs;
      }
      arena[k].used = true;
      arena[k].owner = dos_owner;
      return arena[k].seg;
    }
  return 0;
}

// the program ends: DOS frees its blocks
void dos_free_owner(u16 owner)
{
  for (int k = 0; k < nArena; k++)
    if (arena[k].used && arena[k].owner == owner) arena[k].used = false;
  merge_free();
}

void dos_free(u16 seg)
{
  for (int k = 0; k < nArena; k++)
    if (arena[k].seg == seg) arena[k].used = false;
}

bool dos_resize(u16 seg, u16 paragraphs)
{
  merge_free();
  for (int k = 0; k < nArena; k++)
    if (arena[k].seg == seg)
    {
      if (paragraphs <= arena[k].size)
      {
        if (paragraphs < arena[k].size)
        {
          memmove(&arena[k + 2], &arena[k + 1], sizeof(Mcb) * (size_t)(nArena - k - 1));
          nArena++;
          arena[k + 1] = (Mcb){ (u16)(seg + paragraphs + 1), (u16)(arena[k].size - paragraphs - 1), false };
          arena[k].size = paragraphs;
          merge_free();
        }
        return true;
      }
      if (k + 1 < nArena && !arena[k + 1].used && arena[k].size + 1 + arena[k + 1].size >= paragraphs)
      {
        arena[k].size = (u16)(arena[k].size + 1 + arena[k + 1].size);
        memmove(&arena[k + 1], &arena[k + 2], sizeof(Mcb) * (size_t)(nArena - k - 2));
        nArena--;
        return dos_resize(seg, paragraphs);
      }
      return false;
    }
  return false;
}

// DOS memory for recompiled code (INT 21h 48h/49h/4Ah)
u16 asm2c_dos_alloc(u16 paragraphs, u16 *largest)
{
  u16 seg = dos_alloc(paragraphs);
  if (!seg) *largest = dos_largest_free();
  return seg;
}

bool asm2c_dos_free(u16 seg)
{
  dos_free(seg);
  return true;
}

bool asm2c_dos_resize(u16 seg, u16 paragraphs, u16 *largest)
{
  if (dos_resize(seg, paragraphs)) return true;
  *largest = dos_largest_free();
  return false;
}


u16 dos_largest_free(void)
{
  u16 best = 0;
  for (int k = 0; k < nArena; k++)
    if (!arena[k].used && arena[k].size > best) best = arena[k].size;
  return best;
}
