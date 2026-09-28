// The VGA's planar memory and its registers (vga.c), for the EGA's 16-colour modes
#ifndef OPENSAMURAI_VGA_H
#define OPENSAMURAI_VGA_H

#include <stdbool.h>

#include "dsimage.h"

typedef struct
{
  bool planar;  // a planar mode: A000-AFFF goes through vga_read/vga_write
  u8 mode;
  u8 plane[4][0x10000];
  u8 latch[4];
  u8 seq[8], gc[16], crtc[32], attr[32];
  u8 seqIndex, gcIndex, crtcIndex, attrIndex;
  bool attrData, attrVideo;
} VgaState;

extern VgaState vga;

void vga_set_mode(u8 mode);  // INT 10h's mode set
u8 vga_read(u16 seg, u16 off);
void vga_write(u16 seg, u16 off, u8 v);
bool vga_port_out(u16 port, u8 v);  // true for the VGA's registers
void vga_status_read(void);         // 3DAh read: the attribute controller's flip-flop back to its index
void vga_attribute(u8 index, u8 v); // INT 10h 10h 00h: a palette register
// the screen as shown in mode 0Dh: 320x200 DAC indexes
void vga_render(u8 *out, const u8 dac[256][3]);

#endif
