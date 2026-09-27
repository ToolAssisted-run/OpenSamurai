// The emulated 8086's state for the recompiled functions (asm2c.h) and what they cannot do by themselves.
#include "asm2c.h"

#include <stdio.h>
#include <stdlib.h>

Regs R;
bool g_asmCall;

// a divide error: the INT 0 vector (0000:0000) says whose handler runs. RP's drawing routines (the assembly
// module) catch the overflows of their slope divisions: their handlers (168c:0305 lines, 168c:04DA polygons, at the
// loaded segment 2E58) return +-7F00h by the sign of the dividend and a sign word the faulting division picks
void asm_divide_error(u16 ip)
{
  u16 off = *(u16a *)far_ptr(0, 0), seg = *(u16a *)far_ptr(0, 2);
  if (seg == 0x2E58 && (off == 0x0305 || off == 0x04DA))
  {
    u16 w = off == 0x0305 ? (ip == 0x0296 ? *P16(0x2c99) : *P16(0x2c97)) : (ip == 0x0454 ? *P16(0x2ca7) : *P16(0x2ca5));
    u16 d = R.dx ^ w;
    R.ax = (d & 0x8000) ? (u16)-0x7F00 : 0x7F00;
    R.dx = 0;
    return;
  }
  fprintf(stderr, "asm2c: divide error at %04X (no handler)\n", ip);
  abort();
}

// the VGA: the status register (3DA: the retrace and display-enable bits toggle, so that the waits for them end)
// and the DAC (3C8 index, 3C9 red, green, blue): the palette the frontend shows
u8 asm_dac[256][3];
static u8 dacIndex, dacPart;
u16 asm_port_in(u16 port)
{
  static u8 status;
  if (port == 0x3DA) return status ^= 0x09;
  return 0;
}

void asm_port_out(u16 port, u16 value)
{
  if (port == 0x3C8) { dacIndex = (u8)value; dacPart = 0; }
  else if (port == 0x3C9)
  {
    asm_dac[dacIndex][dacPart] = (u8)(value & 0x3F);
    if (++dacPart == 3) { dacPart = 0; dacIndex++; }
  }
}

// the BIOS and DOS services the drivers use: INT 10h (mode 13h, the DAC) and INT 21h (memory: the DOS arena of
// the program, asm2c_dos_*)
u16 asm2c_dos_alloc(u16 paragraphs, u16 *largest);
bool asm2c_dos_free(u16 seg);
bool asm2c_dos_resize(u16 seg, u16 paragraphs, u16 *largest);
static u8 videoMode = 3;
void asm_int(u8 n)
{
  u8 ah = (u8)(R.ax >> 8), al = (u8)R.ax;
  if (n == 0x10)
  {
    if (ah == 0x00) videoMode = al & 0x7F;
    else if (ah == 0x0F) R.ax = (u16)(0x2800 | videoMode), R.bx &= 0x00FF;
    else if (ah == 0x10 && al == 0x12)  // a block of DAC registers from ES:DX
      for (u16 k = 0; k < R.cx; k++)
        for (int c = 0; c < 3; c++) asm_dac[(R.bx + k) & 0xFF][c] = *far_ptr(R.es, (u16)(R.dx + 3 * k + c)) & 0x3F;
    else if (ah == 0x10 && al == 0x10)
      asm_dac[R.bx & 0xFF][0] = (u8)(R.dx >> 8) & 0x3F, asm_dac[R.bx & 0xFF][1] = (u8)(R.cx >> 8) & 0x3F, asm_dac[R.bx & 0xFF][2] = (u8)R.cx & 0x3F;
    return;
  }
  if (n == 0x21)
  {
    u16 largest = 0;
    if (ah == 0x48)
    {
      u16 seg = asm2c_dos_alloc(R.bx, &largest);
      if (seg) { R.ax = seg; R.cf = 0; }
      else { R.ax = 8; R.bx = largest; R.cf = 1; }
      return;
    }
    if (ah == 0x49) { R.cf = !asm2c_dos_free(R.es); if (R.cf) R.ax = 9; return; }
    if (ah == 0x4A)
    {
      R.cf = !asm2c_dos_resize(R.es, R.bx, &largest);
      if (R.cf) { R.ax = 8; R.bx = largest; }
      return;
    }
  }
  fprintf(stderr, "asm2c: int %02X AX=%04X\n", n, R.ax);
}

void asm_unknown_call(u16 seg, u16 off)
{
  fprintf(stderr, "asm2c: call to %04X:%04X, which is not known\n", seg, off);
  abort();
}

void asm_bad_switch(void)
{
  fprintf(stderr, "asm2c: a jump table index out of range\n");
  abort();
}
