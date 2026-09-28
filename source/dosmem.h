// DOS's memory arena for the programs (dosmem.c): allocations as DOS makes them, first fit
#ifndef OPENSAMURAI_DOSMEM_H
#define OPENSAMURAI_DOSMEM_H

#include <stdbool.h>

#include "dsimage.h"

extern u16 dos_owner;  // the running program's PSP: the owner of the blocks it allocates

// one free block from paragraph first (its control block) to end
void dos_set_arena(u16 first, u16 end);
// the arena as DOS keeps it in memory (its chain of control blocks) between paragraphs from and to
void dos_arena_from_memory(u16 from, u16 to);
u16 dos_alloc(u16 paragraphs);  // the block's segment, 0 if none is large enough
void dos_free(u16 seg);
bool dos_resize(u16 seg, u16 paragraphs);
void dos_free_owner(u16 owner);  // the program ended: DOS frees its blocks
u16 dos_largest_free(void);

#endif
