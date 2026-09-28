// The emulated 8086's state for the recompiled functions (asm2c.h) and what they cannot do by themselves.
#include "asm2c.h"

#include <stdio.h>
#include <stdlib.h>

Regs R;
bool g_asmCall;

// a divide error: the INT 0 vector (0000:0000) says whose handler runs. The drawing routines of RP and START (their
// assembly modules; DUEL's, MELEE's) catch the overflows of their slope divisions: their handlers return +-7F00h by the sign of the
// dividend and a sign word the faulting division picks, and resume after the division (a 4-byte idiv)
static const struct { u16 seg, off, ip, wordAt, wordElse; } divHandlers[] = {
  { 0x2E58, 0x0305, 0x0296, 0x2c99, 0x2c97 },  // RP 168c:0305, the lines
  { 0x2E58, 0x04DA, 0x0454, 0x2ca7, 0x2ca5 },  // RP 168c:04DA, the polygons
  { 0x2E60, 0x01BD, 0x014E, 0x1809, 0x1807 },  // START 1694:01BD
  { 0x2CFF, 0x083F, 0x07D0, 0x26AF, 0x26AD },  // DUEL 1533:083F
  { 0x37B3, 0x0ACB, 0x0A5C, 0x4DF5, 0x4DF3 },  // MELEE 1FE7:0ACB
};
void asm_divide_error(u16 ip)
{
  u16 off = *(u16a *)far_ptr(0, 0), seg = *(u16a *)far_ptr(0, 2);
  for (unsigned k = 0; k < sizeof divHandlers / sizeof *divHandlers; k++)
    if (divHandlers[k].seg == seg && divHandlers[k].off == off)
    {
      u16 w = *P16(ip == divHandlers[k].ip ? divHandlers[k].wordAt : divHandlers[k].wordElse);
      R.ax = ((R.dx ^ w) & 0x8000) ? (u16)-0x7F00 : 0x7F00;
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
u16 (*asm_port_hook)(u16 port);
u16 asm_port_in(u16 port)
{
  static u8 status;
  if (port == 0x3DA) vga_status_read();
  if (asm_port_hook) return asm_port_hook(port);
  if (port == 0x3DA) return status ^= 0x09;
  return 0;
}

bool (*asm_port_out_hook)(u16 port, u8 value);
bool (*asm_sound_slot)(int slot);
void asm_port_out(u16 port, u16 value)
{
  if (asm_port_out_hook && asm_port_out_hook(port, (u8)value)) return;
  if (vga_port_out(port, (u8)value)) return;
  if (port == 0x3C8) { dacIndex = (u8)value; dacPart = 0; }
  else if (port == 0x3C9)
  {
    asm_dac[dacIndex][dacPart] = (u8)(value & 0x3F);
    if (++dacPart == 3) { dacPart = 0; dacIndex++; }
  }
}

// the BIOS and DOS services the drivers use: INT 10h (mode 13h, the DAC) and INT 21h (memory: the DOS arena of
// the program, asm2c_dos_*; the interrupt vectors)
u16 asm2c_dos_alloc(u16 paragraphs, u16 *largest);
bool asm2c_dos_free(u16 seg);
bool asm2c_dos_resize(u16 seg, u16 paragraphs, u16 *largest);
static u8 videoMode = 3;
bool (*asm_int_hook)(u8 n);
void asm_int(u8 n)
{
  if (asm_int_hook && asm_int_hook(n)) return;
  u8 ah = (u8)(R.ax >> 8), al = (u8)R.ax;
  if (n == 0x10)
  {
    if (ah == 0x00)
    {
      videoMode = al & 0x7F;
      vga_set_mode(al & 0x7F);
      if (vga.planar)  // the BIOS's DAC for the EGA's modes: the 64 colours (rgbRGB: primary 2/3, secondary 1/3)
        for (int k = 0; k < 64; k++)
        {
          asm_dac[k][0] = (u8)(42 * ((k >> 2) & 1) + 21 * ((k >> 5) & 1));
          asm_dac[k][1] = (u8)(42 * ((k >> 1) & 1) + 21 * ((k >> 4) & 1));
          asm_dac[k][2] = (u8)(42 * (k & 1) + 21 * ((k >> 3) & 1));
        }
    }
    else if (ah == 0x10 && al == 0x00) vga_attribute(R.bx & 0xFF, (u8)(R.bx >> 8));
    else if (ah == 0x10 && al == 0x01) vga_attribute(0x11, (u8)(R.bx >> 8));
    else if (ah == 0x10 && al == 0x02)
      for (int k = 0; k < 17; k++) vga_attribute(k < 16 ? (u8)k : 0x11, *far_ptr(R.es, (u16)(R.dx + k)));
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
    if (ah == 0x25)  // set an interrupt vector (the handlers are the host's: the divide error's are emulated)
    {
      *(u16a *)far_ptr(0, (u16)(al * 4)) = R.dx;
      *(u16a *)far_ptr(0, (u16)(al * 4 + 2)) = R.ds;
      return;
    }
    if (ah == 0x35)  // get one
    {
      R.bx = *(u16a *)far_ptr(0, (u16)(al * 4));
      R.es = *(u16a *)far_ptr(0, (u16)(al * 4 + 2));
      return;
    }
    if (ah == 0x4A)
    {
      R.cf = !asm2c_dos_resize(R.es, R.bx, &largest);
      if (R.cf) { R.ax = 8; R.bx = largest; }
      return;
    }
  }
  fprintf(stderr, "asm2c: int %02X AX=%04X\n", n, R.ax);
}

// MS C 5.1's int86(n, in, out): it builds "int n; retf" on the stack and calls it with the registers of the REGS
// structure at DS:in (ax bx cx dx si di), stores them at DS:out (and cflag); the carry is the one its own
// compare leaves (set for n < 25h) unless the service sets it (the BIOS's keep the flags); with it,
// _dosmaperr(AL) sets _doserrno and errno (by the library's table, DOS 3 or later's codes) and the result is
// out.ax
u16 asm_msc_int86(u8 n, u16 in, u16 out, const MscErrno *e)
{
  Regs saved = R;
  R.ax = *P16(in);
  R.bx = *P16(in + 2);
  R.cx = *P16(in + 4);
  R.dx = *P16(in + 6);
  R.si = *P16(in + 8);
  R.di = *P16(in + 10);
  R.cf = n < 0x25;
  asm_int(n);
  *P16(out) = R.ax;
  *P16(out + 2) = R.bx;
  *P16(out + 4) = R.cx;
  *P16(out + 6) = R.dx;
  *P16(out + 8) = R.si;
  *P16(out + 10) = R.di;
  bool cf = R.cf;
  R = saved;
  *P16(out + 12) = cf;
  if (cf)
  {
    u8 al = (u8)*P16(out);
    *P8(e->doserrno) = al;
    if (*P8(e->osmajor) >= 3 && al >= 0x20 && al < 0x22) al = 5;
    else if (al > 0x13) al = 0x13;
    *P16(e->errno_) = (u16)(i16)(i8)*P8((u16)(e->table + al));
  }
  return *P16(out);
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
