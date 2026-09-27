// Support for the modules reconstructed over an image of their original data segment (the melee, and
// the programs of the role-playing game): the original's 16-bit types, pointers into the image, and the
// helpers the decompilation of 16-bit code needs. One image is active at a time (g_ds), as one program
// was loaded at a time.
#ifndef OPENSAMURAI_DSIMAGE_H
#define OPENSAMURAI_DSIMAGE_H

#include <stdbool.h>
#include <stdint.h>

#include "shared.h"

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
// element types of pointers into the image (any alignment, any aliasing, as on the 8086)
typedef uint8_t __attribute__((may_alias)) u8a;
typedef int8_t __attribute__((may_alias)) i8a;
typedef uint16_t __attribute__((may_alias, aligned(1))) u16a;
typedef int16_t __attribute__((may_alias, aligned(1))) i16a;
typedef uint32_t __attribute__((may_alias, aligned(1))) u32a;
typedef int32_t __attribute__((may_alias, aligned(1))) i32a;

extern uint8_t *g_ds;  // the active data segment image (64 KB)
#define DSP(x) (g_ds + (u16)(x))
#define P8(x) ((u8a *)DSP(x))
#define PS8(x) ((i8a *)DSP(x))
#define P16(x) ((u16a *)DSP(x))
#define PS16(x) ((i16a *)DSP(x))
#define P32(x) ((u32a *)DSP(x))
#define PS32(x) ((i32a *)DSP(x))
// the shared block, which the programs reach through a far pointer (offset 0)
#define SHP(x) (shared.b + (u16)(x))
#define SH8(x) ((u8a *)SHP(x))
#define SHS8(x) ((i8a *)SHP(x))
#define SH16(x) ((u16a *)SHP(x))
#define SHS16(x) ((i16a *)SHP(x))
#define SH32(x) ((u32a *)SHP(x))
#define SHS32(x) ((i32a *)SHP(x))
// far memory: a far pointer's segment picks the block (the data segment, the shared block, a buffer the program
// allocated); F16(ADDR, off) is the word at off from the far pointer stored at DS:ADDR
extern u16 g_dsSeg, g_sharedSeg;  // the segments the active program's DS and the shared block have
u8 *far_ptr(u16 seg, u16 off);
#define FARP(a, off) far_ptr(*(u16a *)DSP((a) + 2), (u16)(*(u16a *)DSP(a) + (off)))
#define F8(a, off) ((u8a *)FARP(a, off))
#define FS8(a, off) ((i8a *)FARP(a, off))
#define F16(a, off) ((u16a *)FARP(a, off))
#define FS16(a, off) ((i16a *)FARP(a, off))
#define F32(a, off) ((u32a *)FARP(a, off))
#define FS32(a, off) ((i32a *)FARP(a, off))
// Ghidra's flag operations: carry and signed overflow of a 16-bit addition, signed overflow of a subtraction
#define CARRY2(a, b) ((u32)(u16)(a) + (u16)(b) > 0xFFFF)
#define SCARRY2(a, b) ((i32)(i16)(a) + (i16)(b) != (i16)((i16)(a) + (i16)(b)))
#define SBORROW2(a, b) ((i32)(i16)(a) - (i16)(b) != (i16)((i16)(a) - (i16)(b)))
#define CONCAT11(a, b) ((u16)((((u16)(u8)(a)) << 8) | (u8)(b)))
#define CONCAT22(a, b) ((u32)((((u32)(u16)(a)) << 16) | (u16)(b)))
#define CONCAT12(a, b) ((u32)((((u32)(u8)(a)) << 16) | (u16)(b)))

// the stack, in the data segment as on the 8086 (SS = DS): a function whose locals need data segment addresses
// (arrays, locals whose address is taken) takes its frame below g_sp and gives it back when it returns
extern u16 g_sp;
#define DS_FRAME(n) \
  u16 sp_in_ = g_sp, sp0 = g_sp; \
  g_sp = (u16)(sp0 - (n))
// the same, for a function whose parameters live in the stack (their addresses are taken): the caller's pushed
// arguments (a bytes) and the far return address go below the caller's stack pointer first
#define DS_FRAME_ARGS(n, a) \
  u16 sp_in_ = g_sp, sp0 = (u16)(g_sp - 4 - (a)); \
  g_sp = (u16)(sp0 - (n))
#define DS_RETURN(x) \
  do { \
    __auto_type r_ = (x); \
    g_sp = sp_in_; \
    return r_; \
  } while (0)

// driver calls (graphics, sound, joystick): nothing the simulation depends on
static inline u16 drv_(int dummy, ...) { (void)dummy; return 0; }
#define DRV(...) drv_(0, ##__VA_ARGS__)

// the BIOS data area words the programs read (0000:04F0 = the shared block segment)
extern u16 g_bios[0x300];
#define BIOS16(a) (*(u16a *)((u8 *)g_bios + (a)))

#endif
