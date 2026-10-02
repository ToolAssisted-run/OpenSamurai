// The VGA's planar memory, for the drivers that draw in the EGA's 16-colour modes (the melee's EGRAPHIC.MEL, mode
// 0Dh: 320x200, 4 planes): the memory at A000-AFFF goes through the graphics controller (write modes 0-2, the bit
// mask, the data rotate and function, set/reset, the latches, read modes 0 and 1) and the sequencer's map mask;
// the CRTC's start address (the hardware scrolling) and the attribute controller's palette say what is shown.
#include "vga.h"

#include <string.h>

VgaState vga;

static const u8 egaPalette[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x14, 0x07, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F };

void vga_set_mode(u8 mode)
{
  vga.planar = mode == 0x0D || mode == 0x0E || mode == 0x10 || mode == 0x12;
  vga.mode = mode;
  memset(vga.seq, 0, sizeof vga.seq);
  memset(vga.gc, 0, sizeof vga.gc);
  vga.seq[2] = 0x0F;  // all planes written
  vga.seq[4] = 0x06;
  vga.gc[5] = 0x00;
  vga.gc[6] = 0x05;
  vga.gc[7] = 0x0F;
  vga.gc[8] = 0xFF;
  // the palette registers the BIOS sets: in the 200-line modes (0Dh, 0Eh) the CGA's colours, bit 4 the intensity
  // (00-07, 10-17); in the others the EGA's 64-colour defaults
  if (mode == 0x0D || mode == 0x0E)
    for (int k = 0; k < 8; k++) vga.attr[k] = (u8)k, vga.attr[k + 8] = (u8)(k + 0x10);
  else
    memcpy(vga.attr, egaPalette, 16);
  vga.attr[0x10] = 0x01;
  vga.attr[0x12] = 0x0F;
  vga.attr[0x14] = 0x00;
  vga.crtc[0x0C] = vga.crtc[0x0D] = 0;
  vga.crtc[0x13] = mode == 0x0D ? 20 : 40;  // words a line
  if (vga.planar)
  {
    memset(vga.plane, 0, sizeof vga.plane);
    memset(vga.latch, 0, sizeof vga.latch);
  }
}

u8 vga_read(u16 seg, u16 off)
{
  u32 a = ((u32)(seg - 0xA000) << 4) + off;
  if (a >= 0x10000) return 0xFF;
  for (int p = 0; p < 4; p++) vga.latch[p] = vga.plane[p][a];
  if (vga.gc[5] & 0x08)  // read mode 1: the planes' bits that match the colour compare (where they count)
  {
    u8 r = 0;
    for (int b = 0; b < 8; b++)
    {
      bool match = true;
      for (int p = 0; p < 4; p++)
        if ((vga.gc[7] >> p) & 1)
          if (((vga.latch[p] >> b) & 1) != ((vga.gc[2] >> p) & 1)) match = false;
      if (match) r |= (u8)(1 << b);
    }
    return r;
  }
  return vga.latch[vga.gc[4] & 3];
}

static u8 alu(u8 v, u8 latch)
{
  switch ((vga.gc[3] >> 3) & 3)
  {
  case 1: return v & latch;
  case 2: return v | latch;
  case 3: return v ^ latch;
  default: return v;
  }
}

void vga_write(u16 seg, u16 off, u8 v)
{
  u32 a = ((u32)(seg - 0xA000) << 4) + off;
  if (a >= 0x10000) return;
  u8 mask = vga.gc[8], rot = vga.gc[3] & 7;
  u8 planes = vga.seq[2] & 0x0F;
  switch (vga.gc[5] & 3)
  {
  case 0:  // the byte rotated, set/reset for the enabled planes, the function with the latches, the bit mask
  {
    v = (u8)((v >> rot) | (v << (8 - rot)));
    for (int p = 0; p < 4; p++)
    {
      if (!((planes >> p) & 1)) continue;
      u8 d = (vga.gc[1] >> p) & 1 ? ((vga.gc[0] >> p) & 1 ? 0xFF : 0x00) : v;
      d = alu(d, vga.latch[p]);
      vga.plane[p][a] = (u8)((d & mask) | (vga.latch[p] & ~mask));
    }
    break;
  }
  case 1:  // the latches
    for (int p = 0; p < 4; p++)
      if ((planes >> p) & 1) vga.plane[p][a] = vga.latch[p];
    break;
  case 2:  // the byte's low four bits a colour, each plane's bit spread over the byte
    for (int p = 0; p < 4; p++)
    {
      if (!((planes >> p) & 1)) continue;
      u8 d = (v >> p) & 1 ? 0xFF : 0x00;
      d = alu(d, vga.latch[p]);
      vga.plane[p][a] = (u8)((d & mask) | (vga.latch[p] & ~mask));
    }
    break;
  default:  // 3 (the VGA's): the byte rotated and masked by the bit mask, set/reset's colour
  {
    v = (u8)((v >> rot) | (v << (8 - rot)));
    u8 m = v & mask;
    for (int p = 0; p < 4; p++)
    {
      if (!((planes >> p) & 1)) continue;
      u8 d = (vga.gc[0] >> p) & 1 ? 0xFF : 0x00;
      d = alu(d, vga.latch[p]);
      vga.plane[p][a] = (u8)((d & m) | (vga.latch[p] & ~m));
    }
    break;
  }
  }
}

// the registers' ports: the sequencer (3C4/3C5), the graphics controller (3CE/3CF), the CRTC (3D4/3D5), the
// attribute controller (3C0, its index and data in turn; reading 3DA resets the turn)
bool vga_port_out(u16 port, u8 v)
{
  switch (port)
  {
  case 0x3C4: vga.seqIndex = v; return true;
  case 0x3C5: if (vga.seqIndex < sizeof vga.seq) vga.seq[vga.seqIndex] = v; return true;
  case 0x3CE: vga.gcIndex = v; return true;
  case 0x3CF: if (vga.gcIndex < sizeof vga.gc) vga.gc[vga.gcIndex] = v; return true;
  case 0x3D4: vga.crtcIndex = v; return true;
  case 0x3D5: if (vga.crtcIndex < sizeof vga.crtc) vga.crtc[vga.crtcIndex] = v; return true;
  case 0x3C0:
    if (!vga.attrData) vga.attrIndex = v & 0x1F, vga.attrVideo = (v & 0x20) != 0;
    else if (vga.attrIndex < sizeof vga.attr) vga.attr[vga.attrIndex] = v;
    vga.attrData = !vga.attrData;
    return true;
  default: return false;
  }
}

void vga_status_read(void) { vga.attrData = false; }

void vga_attribute(u8 index, u8 v)
{
  if (index < sizeof vga.attr) vga.attr[index] = v;
}

// the screen as shown: DAC indexes, 320x200 (mode 0Dh)
void vga_render(u8 *out, const u8 dac[256][3])
{
  (void)dac;
  u32 start = ((u32)vga.crtc[0x0C] << 8) | vga.crtc[0x0D];
  u32 pitch = (u32)vga.crtc[0x13] * 2;
  if (!pitch) pitch = 40;
  u8 cs = vga.attr[0x14] & 0x0F;
  for (int y = 0; y < 200; y++)
    for (int x = 0; x < 320; x++)
    {
      u32 a = (start + (u32)y * pitch + (u32)(x >> 3)) & 0xFFFF;
      int b = 7 - (x & 7);
      u8 c = 0;
      for (int p = 0; p < 4; p++) c |= (u8)(((vga.plane[p][a] >> b) & 1) << p);
      c &= vga.attr[0x12] & 0x0F;
      u8 pal = vga.attr[c];
      // the DAC's index: the palette register's six bits, the colour select's high bits
      out[y * 320 + x] = (u8)((vga.attr[0x10] & 0x80) ? ((pal & 0x0F) | ((cs & 3) << 4)) | ((cs & 0x0C) << 4) : (pal & 0x3F) | ((cs & 0x0C) << 4));
    }
}
