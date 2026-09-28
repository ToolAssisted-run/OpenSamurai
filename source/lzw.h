// The picture and data decompressor of the programs (lzw.c)
#ifndef OPENSAMURAI_LZW_H
#define OPENSAMURAI_LZW_H

#include "dsimage.h"

// Where a program keeps the decoder's state in its data segment (offsets), and its hooks
typedef struct
{
  u16 table;   // the string table, 3 bytes a code: prefix word, last byte (0x800 codes)
  u16 sp;      // the decoder's stack pointer: its stack (below spTop) holds the bytes of the current string, a word each
  u16 spTop;
  u16 count;   // bytes left in the current call
  u16 run;     // RLE: run length, then its byte
  u16 width;   // code width, then its maximum
  u16 mask;    // the code mask
  u16 next;    // the next code
  u16 bits;    // the bit buffer (word), then the bits left in it (byte)
  u16 nibble;  // two pixels a byte
  u16 prev;    // the previous code (word), then its first byte
  u16 header;  // the picture's width, height, the data's length
  u16 readPtr, readEnd;  // the input stream's read pointer and end (near)
  u16 refill;            // the far pointer to the stream's refill function
  u16 refillSeg;         // the decoder's code segment (the return address pushed for the refill)
  void (*palette)(u16 at);  // a picture's palette at DS:at (graphics slot 25)
  void (*farCall)(u16 seg, u16 off);  // the program's far calls through a pointer (the refill)
} LzwLayout;

u16 lzw_pic_header(const LzwLayout *L);
u16 lzw_dat_header(const LzwLayout *L);
// decodes n bytes (pixels) to far memory
void lzw_decode(const LzwLayout *L, u16 dstoff, u16 dstseg, u16 n);

#endif
