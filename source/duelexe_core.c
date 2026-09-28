// DUEL.EXE (the duel), recompiled from its machine code (asm2c.py, the workspace's work/duel_rec.sh): generated,
// do not edit. What it calls outside itself is in duelexe_rt.c: the drivers (du_driver), DOS and the BIOS
// (asm_int), the picture decoder, exit().
#include <setjmp.h>

#include "asm2c.h"
#include "duelexe_rt.h"

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-label"

// ---- recompiled bodies
static void a_1000_0010(void);
static void a_1000_02a0(void);
static void a_1000_02cc(void);
static void a_1000_0338(void);
static void a_1000_0361(void);
static void a_1000_0594(void);
static void a_1000_154c(void);
static void a_1000_1624(void);
static void a_1000_1774(void);
static void a_1000_17aa(void);
static void a_1000_17c0(void);
static void a_1000_18c0(void);
static void a_1000_1ba4(void);
static void a_1000_1bc2(void);
static void a_1000_1be2(void);
static void a_1000_1e20(void);
static void a_1000_1e40(void);
static void a_1000_1e90(void);
static void a_1000_1ebe(void);
static void a_1000_1f80(void);
static void a_1000_1fdf(void);
static void a_1000_200a(void);
static void a_1000_202d(void);
static void a_1000_2069(void);
static void a_1000_20a0(void);
static void a_1000_20a4(void);
static void a_1000_20e6(void);
static void a_1000_2170(void);
static void a_1000_2260(void);
static void a_1000_236e(void);
static void a_1000_243c(void);
static void a_1000_245a(void);
static void a_1000_249e(void);
static void a_1000_24c6(void);
static void a_1000_24e8(void);
static void a_1000_2518(void);
static void a_1000_2548(void);
static void a_1000_256e(void);
static void a_1000_260a(void);
static void a_1000_2a04(void);
static void a_1000_32d2(void);
static void a_1000_331f(void);
static void a_1000_3351(void);
static void a_1000_342d(void);
static void a_1000_3492(void);
static void a_1000_34d2(void);
static void a_1000_34fd(void);
static void a_1000_3545(void);
static void a_1000_35be(void);
static void a_1000_3670(void);
static void a_1000_37bd(void);
static void a_1000_37cc(void);
static void a_1000_37e0(void);
static void a_1000_383e(void);
static void a_1000_39cc(void);
static void a_1000_3a3a(void);
static void a_1000_3a65(void);
static void a_1000_3a8e(void);
static void a_1000_3af0(void);
static void a_1000_3af6(void);
static void a_1000_434c(void);
static void a_1000_43f2(void);
static void a_1000_4474(void);
static void a_1000_4720(void);
static void a_1000_4748(void);
static void a_1000_4782(void);
static void a_1000_47da(void);
static void a_1000_4838(void);
static void a_1000_48ba(void);
static void a_1000_4cee(void);
static void a_1000_4d36(void);
static void a_1000_4d54(void);
static void a_1000_4d62(void);
static void a_1000_4db4(void);
static void a_1000_4dc4(void);
static void a_1000_4e74(void);
static void a_1000_4f3e(void);
static void a_1000_5054(void);
static void a_1000_50d8(void);
static void a_1000_50ee(void);
static void a_1000_5100(void);
static void a_1000_5126(void);
static void a_1000_513a(void);
static void a_1000_5168(void);
static void a_1000_5180(void);
static void a_1000_5240(void);
static void a_1533_0121(void);
static void a_1533_0170(void);
static void a_1533_01ae(void);
static void a_1533_02c7(void);
static void a_1533_035c(void);
static void a_1533_0394(void);
static void a_1533_045c(void);
static void a_1533_04e4(void);
static void a_1533_0692(void);
static void a_1533_081e(void);
static void a_1533_0a36(void);
static void a_15e6_000e(void);
static void a_15e6_0066(void);
// ---- end of recompiled bodies

// Recompiled from the machine code by the workspace's work/asm2c.py (the decompilation of these functions
// failed); see asm2c.h.

// 1000:0010 FUN_1000_0010  FIX: recompiled from the machine code (asm2c)
static void a_1000_0010(void)
{
  FN(0x10000010);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 0010 push bp
  R.bp = (u16)(R.sp);                                          // 0011 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0xa));                              // 0013 sub sp, 0xa
  PUSH(R.di);                                                  // 0017 push di
  PUSH(R.si);                                                  // 0018 push si
  R.ax = (u16)(0x0);                                           // 0019 mov ax, 0
  W16(DS, (u16)(0x4dba), R.ax);                                // 001c mov word ptr [0x4dba], ax
  W16(DS, (u16)(0x4db8), R.ax);                                // 001f mov word ptr [0x4db8], ax
  W16(SS, (u16)(R.bp + 0xfffc), 0x0);                          // 0022 mov word ptr [bp - 4], 0
  W16(SS, (u16)(R.bp + 0xfffa), 0x4f0);                        // 0027 mov word ptr [bp - 6], 0x4f0
  { u16 a_ = (u16)(R.bp + 0xfffa); R.bx = (u16)(M16(SS, a_)); R.es = M16(SS, (u16)(a_ + 2)); } // 002c les bx, ptr [bp - 6]
  R.ax = (u16)(M16(ES, (u16)(R.bx)));                          // 002f mov ax, word ptr es:[bx]
  W16(DS, (u16)(0x6208), R.ax);                                // 0032 mov word ptr [0x6208], ax
  W16(DS, (u16)(0x6206), 0x0);                                 // 0035 mov word ptr [0x6206], 0
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 003b les bx, ptr [0x6206]
  R.ax = (u16)(M16(ES, (u16)(R.bx + 0x36)));                   // 003f mov ax, word ptr es:[bx + 0x36]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0043 shl ax, 1
  W16(DS, (u16)(0x1e62), R.ax);                                // 0045 mov word ptr [0x1e62], ax
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0048 les bx, ptr [0x6206]
  R.ax = (u16)(M16(ES, (u16)(R.bx + 0x6a)));                   // 004c mov ax, word ptr es:[bx + 0x6a]
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0050 les bx, ptr [0x6206]
  R.ax = (u16)(SUB16(R.ax, M16(ES, (u16)(R.bx + 0x68))));      // 0054 sub ax, word ptr es:[bx + 0x68]
  SETL(R.cx, 0x4);                                             // 0058 mov cl, 4
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 005a shr ax, cl
  W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 005c mov word ptr [bp - 0xa], ax
L_005f:   SUB16(M16(SS, (u16)(R.bp + 0xfff6)), 0x0);                   // 005f cmp word ptr [bp - 0xa], 0
  if (!R.zf) goto L_0068;                                      // 0063 jne 0x68
  goto L_0084;                                                 // 0065 jmp 0x84
L_0068:   PUSH(M16(SS, (u16)(R.bp + 0xfff6)));                         // 0068 push word ptr [bp - 0xa]
  PUSH(0x006e); a_1000_1ba4();                                 // 006b call 0x1ba4
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 006e add sp, 2
  W16(DS, (u16)(0x1e62), ADD16(M16(DS, (u16)(0x1e62)), R.ax)); // 0071 add word ptr [0x1e62], ax
  R.cx = (u16)(0x2);                                           // 0075 mov cx, 2
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfff6)));                 // 0078 mov ax, word ptr [bp - 0xa]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 007b cdq
  IDIV16(R.cx, 0x007c);                                        // 007c idiv cx
  W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 007e mov word ptr [bp - 0xa], ax
  goto L_005f;                                                 // 0081 jmp 0x5f
L_0084:   R.ax = (u16)(0x7);                                           // 0084 mov ax, 7
  PUSH(R.ax);                                                  // 0087 push ax
  R.ax = (u16)(0x0);                                           // 0088 mov ax, 0
  PUSH(R.ax);                                                  // 008b push ax
  PUSH(M16(DS, (u16)(0x1e62)));                                // 008c push word ptr [0x1e62]
  PUSH(0x0093); a_1000_2069();                                 // 0090 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 0093 add sp, 6
  W16(DS, (u16)(0x1e62), R.ax);                                // 0096 mov word ptr [0x1e62], ax
  R.ax = (u16)(0x0);                                           // 0099 mov ax, 0
  PUSH(R.ax);                                                  // 009c push ax
  R.ax = (u16)(0xffff);                                        // 009d mov ax, 0xffff
  PUSH(R.ax);                                                  // 00a0 push ax
  R.ax = (u16)(M16(DS, (u16)(0x1e62)));                        // 00a1 mov ax, word ptr [0x1e62]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 00a4 cdq
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 00a5 sub ax, dx
  R.ax = (u16)(SAR16(R.ax, 0x1));                              // 00a7 sar ax, 1
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 00a9 les bx, ptr [0x6206]
  R.cx = (u16)(M16(ES, (u16)(R.bx + 0x312)));                  // 00ad mov cx, word ptr es:[bx + 0x312]
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 00b2 add cx, ax
  R.cx = (u16)(DEC16(R.cx));                                   // 00b4 dec cx
  PUSH(R.cx);                                                  // 00b5 push cx
  PUSH(0x00b9); a_1000_2069();                                 // 00b6 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 00b9 add sp, 6
  W16(DS, (u16)(0x4dbe), R.ax);                                // 00bc mov word ptr [0x4dbe], ax
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 00bf les bx, ptr [0x6206]
  R.ax = (u16)(M16(ES, (u16)(R.bx + 0x5c)));                   // 00c3 mov ax, word ptr es:[bx + 0x5c]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 00c7 mov word ptr [bp - 2], ax
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 00ca les bx, ptr [0x6206]
  R.ax = (u16)(M16(ES, (u16)(R.bx + 0x54)));                   // 00ce mov ax, word ptr es:[bx + 0x54]
  W16(DS, (u16)(0x4db8), R.ax);                                // 00d2 mov word ptr [0x4db8], ax
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 00d5 les bx, ptr [0x6206]
  R.ax = (u16)(M16(ES, (u16)(R.bx + 0x34)));                   // 00d9 mov ax, word ptr es:[bx + 0x34]
  W16(DS, (u16)(0x61ee), R.ax);                                // 00dd mov word ptr [0x61ee], ax
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 00e0 les bx, ptr [0x6206]
  PUSH(M16(ES, (u16)(R.bx + 0x1a)));                           // 00e4 push word ptr es:[bx + 0x1a]
  PUSH(0x27cc); PUSH(0x00ed); a_1533_0121();                   // 00e8 lcall 0x533, 0x121
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 00ed add sp, 2
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 00f0 les bx, ptr [0x6206]
  PUSH(M16(ES, (u16)(R.bx + 0x1e)));                           // 00f4 push word ptr es:[bx + 0x1e]
  PUSH(0x27cc); PUSH(0x00fd); a_1533_0121();                   // 00f8 lcall 0x533, 0x121
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 00fd add sp, 2
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0100 les bx, ptr [0x6206]
  PUSH(M16(ES, (u16)(R.bx + 0x1c)));                           // 0104 push word ptr es:[bx + 0x1c]
  PUSH(0x27cc); PUSH(0x010d); a_1533_0121();                   // 0108 lcall 0x533, 0x121
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 010d add sp, 2
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 0110 mov bx, word ptr [0x1f6a]
  W16(DS, (u16)(R.bx + 0x10), 0x3);                            // 0114 mov word ptr [bx + 0x10], 3
  R.ax = (u16)(0x0);                                           // 0119 mov ax, 0
  PUSH(R.ax);                                                  // 011c push ax
  PUSH(0x27cc); PUSH(0x0122); du_driver(33);   /* driver slot 33 */ // 011d lcall 0x62a, 0x2011
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0122 add sp, 2
  W16(SS, (u16)(R.bp + 0xfff8), 0x0);                          // 0125 mov word ptr [bp - 8], 0
  goto L_0130;                                                 // 012a jmp 0x130
L_012d:   W16(SS, (u16)(R.bp + 0xfff8), INC16(M16(SS, (u16)(R.bp + 0xfff8)))); // 012d inc word ptr [bp - 8]
L_0130:   SUB16(M16(SS, (u16)(R.bp + 0xfff8)), 0x4);                   // 0130 cmp word ptr [bp - 8], 4
  if (R.sf != R.of) goto L_0139;                               // 0134 jl 0x139
  goto L_0153;                                                 // 0136 jmp 0x153
L_0139:   PUSH(M16(SS, (u16)(R.bp + 0xfff8)));                         // 0139 push word ptr [bp - 8]
  PUSH(0x27cc); PUSH(0x0141); du_driver(0);   /* driver slot 0 */ // 013c lcall 0x62a, 0x1f6c
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0141 add sp, 2
  PUSH(R.ax);                                                  // 0144 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfff8)));                         // 0145 push word ptr [bp - 8]
  PUSH(0x27cc); PUSH(0x014d); du_driver(23);   /* driver slot 23 */ // 0148 lcall 0x62a, 0x1fdf
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 014d add sp, 4
  goto L_012d;                                                 // 0150 jmp 0x12d
L_0153:   R.ax = (u16)(0x42);                                          // 0153 mov ax, 0x42
  PUSH(R.ax);                                                  // 0156 push ax
  PUSH(0x015a); a_1000_2518();                                 // 0157 call 0x2518
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 015a add sp, 2
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 015d mov ax, word ptr [bp - 2]
  goto L_0199;                                                 // 0160 jmp 0x199
L_0163:   R.ax = (u16)(0x3);                                           // 0163 mov ax, 3
  PUSH(R.ax);                                                  // 0166 push ax
  R.ax = (u16)(0x4b);                                          // 0167 mov ax, 0x4b
  PUSH(R.ax);                                                  // 016a push ax
  PUSH(0x016e); a_1000_236e();                                 // 016b call 0x236e
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 016e add sp, 4
  goto L_01b3;                                                 // 0171 jmp 0x1b3
L_0174:   R.ax = (u16)(0x3);                                           // 0174 mov ax, 3
  PUSH(R.ax);                                                  // 0177 push ax
  R.ax = (u16)(0x57);                                          // 0178 mov ax, 0x57
  PUSH(R.ax);                                                  // 017b push ax
  PUSH(0x017f); a_1000_236e();                                 // 017c call 0x236e
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 017f add sp, 4
  goto L_01b3;                                                 // 0182 jmp 0x1b3
L_0185:   R.ax = (u16)(0x3);                                           // 0185 mov ax, 3
  PUSH(R.ax);                                                  // 0188 push ax
  R.ax = (u16)(0x63);                                          // 0189 mov ax, 0x63
  PUSH(R.ax);                                                  // 018c push ax
  PUSH(0x0190); a_1000_236e();                                 // 018d call 0x236e
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0190 add sp, 4
  goto L_01b3;                                                 // 0193 jmp 0x1b3
L_0199:   R.ax = (u16)(OR16(R.ax, R.ax));                              // 0199 or ax, ax
  if (!R.zf) goto L_01a0;                                      // 019b jne 0x1a0
  goto L_0163;                                                 // 019d jmp 0x163
L_01a0:   SUB16(R.ax, 0x1);                                            // 01a0 cmp ax, 1
  if (!R.zf) goto L_01a8;                                      // 01a3 jne 0x1a8
  goto L_0174;                                                 // 01a5 jmp 0x174
L_01a8:   SUB16(R.ax, 0x2);                                            // 01a8 cmp ax, 2
  if (!R.zf) goto L_01b0;                                      // 01ab jne 0x1b0
  goto L_0185;                                                 // 01ad jmp 0x185
L_01b0:   goto L_01b3;                                                 // 01b0 jmp 0x1b3
L_01b3:   PUSH(0x01b6); a_1000_1be2();                                 // 01b3 call 0x1be2
  PUSH(0x01b9); a_1000_200a();                                 // 01b6 call 0x200a
  R.ax = (u16)(0x1dc0);                                        // 01b9 mov ax, 0x1dc0
  PUSH(R.ax);                                                  // 01bc push ax
  R.ax = (u16)(0x3);                                           // 01bd mov ax, 3
  PUSH(R.ax);                                                  // 01c0 push ax
  PUSH(0x27cc); PUSH(0x01c6); du_driver(15);   /* driver slot 15 */ // 01c1 lcall 0x62a, 0x1fb7
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 01c6 add sp, 4
  R.ax = (u16)(0x1dd2);                                        // 01c9 mov ax, 0x1dd2
  PUSH(R.ax);                                                  // 01cc push ax
  R.ax = (u16)(0x2);                                           // 01cd mov ax, 2
  PUSH(R.ax);                                                  // 01d0 push ax
  PUSH(0x27cc); PUSH(0x01d6); du_driver(15);   /* driver slot 15 */ // 01d1 lcall 0x62a, 0x1fb7
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 01d6 add sp, 4
  R.ax = (u16)(0x3);                                           // 01d9 mov ax, 3
  PUSH(R.ax);                                                  // 01dc push ax
  PUSH(0x27cc); PUSH(0x01e2); du_driver(4);   /* driver slot 4 */ // 01dd lcall 0x62a, 0x1f80
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 01e2 add sp, 2
  PUSH(0x27cc); PUSH(0x01ea); a_1533_0170();                   // 01e5 lcall 0x533, 0x170
  PUSH(0x27cc); PUSH(0x01ef); du_driver(100);   /* driver slot 100 */ // 01ea lcall 0x62a, 0x2160
  PUSH(0x27cc); PUSH(0x01f4); a_15e6_000e();                   // 01ef lcall 0x5e6, 0xe
L_01f4:   PUSH(0x01f7); a_1000_0594();                                 // 01f4 call 0x594
  SUB16(M16(DS, (u16)(0x61f4)), 0x0);                          // 01f7 cmp word ptr [0x61f4], 0
  if (!R.zf) goto L_0201;                                      // 01fc jne 0x201
  goto L_01f4;                                                 // 01fe jmp 0x1f4
L_0201:   PUSH(0x27cc); PUSH(0x0206); a_15e6_0066();                   // 0201 lcall 0x5e6, 0x66
  PUSH(0x27cc); PUSH(0x020b); a_1533_01ae();                   // 0206 lcall 0x533, 0x1ae
  PUSH(0x020e); a_1000_2548();                                 // 020b call 0x2548
  SUB16(M16(DS, (u16)(0x61f4)), 0x2);                          // 020e cmp word ptr [0x61f4], 2
  if (R.zf) goto L_0218;                                       // 0213 je 0x218
  goto L_021e;                                                 // 0215 jmp 0x21e
L_0218:   R.ax = (u16)(0x1);                                           // 0218 mov ax, 1
  goto L_0221;                                                 // 021b jmp 0x221
L_021e:   R.ax = (u16)(0x0);                                           // 021e mov ax, 0
L_0221:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0221 les bx, ptr [0x6206]
  W16(ES, (u16)(R.bx + 0x4c), R.ax);                           // 0225 mov word ptr es:[bx + 0x4c], ax
  SUB16(M16(DS, (u16)(0x61f4)), 0x3);                          // 0229 cmp word ptr [0x61f4], 3
  if (R.zf) goto L_0233;                                       // 022e je 0x233
  goto L_0239;                                                 // 0230 jmp 0x239
L_0233:   R.ax = (u16)(0x1);                                           // 0233 mov ax, 1
  goto L_023c;                                                 // 0236 jmp 0x23c
L_0239:   R.ax = (u16)(0x0);                                           // 0239 mov ax, 0
L_023c:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 023c les bx, ptr [0x6206]
  W16(ES, (u16)(R.bx + 0x62), R.ax);                           // 0240 mov word ptr es:[bx + 0x62], ax
  SUB16(M16(DS, (u16)(0x61f4)), 0x1);                          // 0244 cmp word ptr [0x61f4], 1
  if (R.zf) goto L_024e;                                       // 0249 je 0x24e
  goto L_0254;                                                 // 024b jmp 0x254
L_024e:   R.ax = (u16)(0x1);                                           // 024e mov ax, 1
  goto L_0257;                                                 // 0251 jmp 0x257
L_0254:   R.ax = (u16)(0x0);                                           // 0254 mov ax, 0
L_0257:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0257 les bx, ptr [0x6206]
  W16(ES, (u16)(R.bx + 0x4e), R.ax);                           // 025b mov word ptr es:[bx + 0x4e], ax
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 025f les bx, ptr [0x6206]
  SUB16(M16(DS, (u16)(0x4db8)), 0x1);                          // 0263 cmp word ptr [0x4db8], 1
  R.ax = (u16)(SBB16(R.ax, R.ax));                             // 0268 sbb ax, ax
  R.ax = (u16)(INC16(R.ax));                                   // 026a inc ax
  W16(ES, (u16)(R.bx + 0x54), R.ax);                           // 026b mov word ptr es:[bx + 0x54], ax
  PUSH(0x0272); a_1000_0361();                                 // 026f call 0x361
  PUSH(0x27cc); PUSH(0x0277); du_driver(21);   /* driver slot 21 */ // 0272 lcall 0x62a, 0x1fd5
  R.ax = (u16)(0x0);                                           // 0277 mov ax, 0
  PUSH(R.ax);                                                  // 027a push ax
  PUSH(0x27cc); PUSH(0x0280); du_driver(4);   /* driver slot 4 */ // 027b lcall 0x62a, 0x1f80
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0280 add sp, 2
  PUSH(M16(DS, (u16)(0x6202)));                                // 0283 push word ptr [0x6202]
  CALL_BEGIN(4); du_exit((i16)ARG(0)); CALL_END();             // 0287 call 0x3734
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 028a add sp, 2
  SUB16(M16(DS, (u16)(0x6202)), 0x0);                          // 028d cmp word ptr [0x6202], 0
  if (R.zf) goto L_0297;                                       // 0292 je 0x297
  goto L_0297;                                                 // 0294 jmp 0x297
L_0297:   PUSH(0x029a); a_1000_1fdf();                                 // 0297 call 0x1fdf
  R.si = POP();                                                // 029a pop si
  R.di = POP();                                                // 029b pop di
  R.sp = (u16)(R.bp);                                          // 029c mov sp, bp
  R.bp = POP();                                                // 029e pop bp
  R.sp += 2; goto L_ret;                                       // 029f ret
L_ret:
  return;
}

static u16 f_1000_0010(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_0010();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:02A0 FUN_1000_02a0  FIX: recompiled from the machine code (asm2c)
static void a_1000_02a0(void)
{
  FN(0x100002A0);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 02a0 push bp
  R.bp = (u16)(R.sp);                                          // 02a1 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 02a3 sub sp, 0
  PUSH(R.di);                                                  // 02a7 push di
  PUSH(R.si);                                                  // 02a8 push si
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 02a9 les bx, ptr [0x6206]
  SUB16(M16(ES, (u16)(R.bx + 0x310)), 0x2);                    // 02ad cmp word ptr es:[bx + 0x310], 2
  if (R.zf) goto L_02b8;                                       // 02b3 je 0x2b8
  goto L_02bb;                                                 // 02b5 jmp 0x2bb
L_02b8:   goto L_02c6;                                                 // 02b8 jmp 0x2c6
L_02bb:   PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 02bb push word ptr [bp + 4]
  PUSH(0x27cc); PUSH(0x02c3); du_driver(101);   /* driver slot 101 */ // 02be lcall 0x62a, 0x2165
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 02c3 add sp, 2
L_02c6:   R.si = POP();                                                // 02c6 pop si
  R.di = POP();                                                // 02c7 pop di
  R.sp = (u16)(R.bp);                                          // 02c8 mov sp, bp
  R.bp = POP();                                                // 02ca pop bp
  R.sp += 2; goto L_ret;                                       // 02cb ret
L_ret:
  return;
}

static u16 f_1000_02a0(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_02a0();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:02CC FUN_1000_02cc  FIX: recompiled from the machine code (asm2c)
static void a_1000_02cc(void)
{
  FN(0x100002CC);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 02cc push bp
  R.bp = (u16)(R.sp);                                          // 02cd mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 02cf sub sp, 0
  PUSH(R.di);                                                  // 02d3 push di
  PUSH(R.si);                                                  // 02d4 push si
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 02d5 les bx, ptr [0x6206]
  W16(ES, (u16)(R.bx + 0x310), INC16(M16(ES, (u16)(R.bx + 0x310)))); // 02d9 inc word ptr es:[bx + 0x310]
  SUB16(M16(ES, (u16)(R.bx + 0x310)), 0x2);                    // 02de cmp word ptr es:[bx + 0x310], 2
  if (!R.cf && !R.zf) goto L_02e9;                             // 02e4 ja 0x2e9
  goto L_02f4;                                                 // 02e6 jmp 0x2f4
L_02e9:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 02e9 les bx, ptr [0x6206]
  W16(ES, (u16)(R.bx + 0x310), 0x0);                           // 02ed mov word ptr es:[bx + 0x310], 0
L_02f4:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 02f4 les bx, ptr [0x6206]
  SUB16(M16(ES, (u16)(R.bx + 0x310)), 0x0);                    // 02f8 cmp word ptr es:[bx + 0x310], 0
  if (R.zf) goto L_0303;                                       // 02fe je 0x303
  goto L_0319;                                                 // 0300 jmp 0x319
L_0303:   R.ax = (u16)(0x4e);                                          // 0303 mov ax, 0x4e
  PUSH(R.ax);                                                  // 0306 push ax
  PUSH(0x030a); a_1000_02a0();                                 // 0307 call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 030a add sp, 2
  R.ax = (u16)(0x2);                                           // 030d mov ax, 2
  PUSH(R.ax);                                                  // 0310 push ax
  PUSH(0x27cc); PUSH(0x0316); du_driver(104);   /* driver slot 104 */ // 0311 lcall 0x62a, 0x2174
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0316 add sp, 2
L_0319:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0319 les bx, ptr [0x6206]
  SUB16(M16(ES, (u16)(R.bx + 0x310)), 0x1);                    // 031d cmp word ptr es:[bx + 0x310], 1
  if (R.zf) goto L_0328;                                       // 0323 je 0x328
  goto L_0332;                                                 // 0325 jmp 0x332
L_0328:   R.ax = (u16)(0x2);                                           // 0328 mov ax, 2
  PUSH(R.ax);                                                  // 032b push ax
  PUSH(0x032f); a_1000_02a0();                                 // 032c call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 032f add sp, 2
L_0332:   R.si = POP();                                                // 0332 pop si
  R.di = POP();                                                // 0333 pop di
  R.sp = (u16)(R.bp);                                          // 0334 mov sp, bp
  R.bp = POP();                                                // 0336 pop bp
  R.sp += 2; goto L_ret;                                       // 0337 ret
L_ret:
  return;
}

static u16 f_1000_02cc(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_02cc();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:0338 FUN_1000_0338  FIX: recompiled from the machine code (asm2c)
static void a_1000_0338(void)
{
  FN(0x10000338);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 0338 push bp
  R.bp = (u16)(R.sp);                                          // 0339 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 033b sub sp, 0
  PUSH(R.di);                                                  // 033f push di
  PUSH(R.si);                                                  // 0340 push si
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 0341 push word ptr [bp + 4]
  PUSH(0x27cc); PUSH(0x0349); du_driver(27);   /* driver slot 27 */ // 0344 lcall 0x62a, 0x1ff3
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0349 add sp, 2
  R.si = POP();                                                // 034c pop si
  R.di = POP();                                                // 034d pop di
  R.sp = (u16)(R.bp);                                          // 034e mov sp, bp
  R.bp = POP();                                                // 0350 pop bp
  R.sp += 2; goto L_ret;                                       // 0351 ret
L_ret:
  return;
}

static u16 f_1000_0338(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_0338();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:0361 FUN_1000_0361  FIX: recompiled from the machine code (asm2c)
static void a_1000_0361(void)
{
  FN(0x10000361);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 0361 push bp
  R.bp = (u16)(R.sp);                                          // 0362 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4a));                             // 0364 sub sp, 0x4a
  PUSH(R.di);                                                  // 0368 push di
  PUSH(R.si);                                                  // 0369 push si
  R.ax = (u16)(0x0);                                           // 036a mov ax, 0
  PUSH(R.ax);                                                  // 036d push ax
  PUSH(0x27cc); PUSH(0x0373); du_driver(27);   /* driver slot 27 */ // 036e lcall 0x62a, 0x1ff3
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0373 add sp, 2
  R.ax = (u16)(0x0);                                           // 0376 mov ax, 0
  PUSH(R.ax);                                                  // 0379 push ax
  R.ax = (u16)(0xc8);                                          // 037a mov ax, 0xc8
  PUSH(R.ax);                                                  // 037d push ax
  R.ax = (u16)(0x140);                                         // 037e mov ax, 0x140
  PUSH(R.ax);                                                  // 0381 push ax
  R.ax = (u16)(0x0);                                           // 0382 mov ax, 0
  PUSH(R.ax);                                                  // 0385 push ax
  R.ax = (u16)(0x0);                                           // 0386 mov ax, 0
  PUSH(R.ax);                                                  // 0389 push ax
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 038a push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x0393); a_1533_045c();                   // 038e lcall 0x533, 0x45c
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 0393 add sp, 0xc
  PUSH(0x27cc); PUSH(0x039b); du_driver(22);   /* driver slot 22 */ // 0396 lcall 0x62a, 0x1fda
L_039b:   R.ax = (u16)(0x0);                                           // 039b mov ax, 0
  PUSH(R.ax);                                                  // 039e push ax
  R.ax = (u16)(0x1de3);                                        // 039f mov ax, 0x1de3
  PUSH(R.ax);                                                  // 03a2 push ax
  PUSH(0x27cc); PUSH(0x03a8); a_1533_0394();                   // 03a3 lcall 0x533, 0x394
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 03a8 add sp, 4
  R.ax = (u16)(INC16(R.ax));                                   // 03ab inc ax
  if (R.zf) goto L_03b1;                                       // 03ac je 0x3b1
  goto L_058e;                                                 // 03ae jmp 0x58e
L_03b1:   R.ax = (u16)(0x0);                                           // 03b1 mov ax, 0
  PUSH(R.ax);                                                  // 03b4 push ax
  R.ax = (u16)(0xc8);                                          // 03b5 mov ax, 0xc8
  PUSH(R.ax);                                                  // 03b8 push ax
  R.ax = (u16)(0x140);                                         // 03b9 mov ax, 0x140
  PUSH(R.ax);                                                  // 03bc push ax
  R.ax = (u16)(0x0);                                           // 03bd mov ax, 0
  PUSH(R.ax);                                                  // 03c0 push ax
  R.ax = (u16)(0x0);                                           // 03c1 mov ax, 0
  PUSH(R.ax);                                                  // 03c4 push ax
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 03c5 push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x03ce); a_1533_045c();                   // 03c9 lcall 0x533, 0x45c
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 03ce add sp, 0xc
  R.ax = (u16)(0x1dea);                                        // 03d1 mov ax, 0x1dea
  PUSH(R.ax);                                                  // 03d4 push ax
  R.ax = (u16)((u16)(R.bp + 0xffda));                          // 03d5 lea ax, [bp - 0x26]
  PUSH(R.ax);                                                  // 03d8 push ax
  PUSH(0x03dc); a_1000_32d2();                                 // 03d9 call 0x32d2
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 03dc add sp, 4
  R.ax = (u16)(0x1dff);                                        // 03df mov ax, 0x1dff
  PUSH(R.ax);                                                  // 03e2 push ax
  R.ax = (u16)((u16)(R.bp + 0xffb6));                          // 03e3 lea ax, [bp - 0x4a]
  PUSH(R.ax);                                                  // 03e6 push ax
  PUSH(0x03ea); a_1000_32d2();                                 // 03e7 call 0x32d2
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 03ea add sp, 4
  R.ax = (u16)((u16)(R.bp + 0xffb6));                          // 03ed lea ax, [bp - 0x4a]
  PUSH(R.ax);                                                  // 03f0 push ax
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 03f1 push word ptr [0x1e2c]
  PUSH(0x03f8); a_1000_2a04();                                 // 03f5 call 0x2a04
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 03f8 add sp, 4
  W16(SS, (u16)(R.bp + 0xffd4), R.ax);                         // 03fb mov word ptr [bp - 0x2c], ax
  R.ax = (u16)(0x140);                                         // 03fe mov ax, 0x140
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xffd4))));    // 0401 sub ax, word ptr [bp - 0x2c]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 0404 cdq
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 0405 sub ax, dx
  R.ax = (u16)(SAR16(R.ax, 0x1));                              // 0407 sar ax, 1
  W16(SS, (u16)(R.bp + 0xffd6), R.ax);                         // 0409 mov word ptr [bp - 0x2a], ax
  R.ax = (u16)(0x4);                                           // 040c mov ax, 4
  PUSH(R.ax);                                                  // 040f push ax
  R.ax = (u16)(0x1b);                                          // 0410 mov ax, 0x1b
  PUSH(R.ax);                                                  // 0413 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffd4)));                 // 0414 mov ax, word ptr [bp - 0x2c]
  R.ax = (u16)(ADD16(R.ax, 0xa));                              // 0417 add ax, 0xa
  PUSH(R.ax);                                                  // 041a push ax
  R.ax = (u16)(0x57);                                          // 041b mov ax, 0x57
  PUSH(R.ax);                                                  // 041e push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffd6)));                 // 041f mov ax, word ptr [bp - 0x2a]
  R.ax = (u16)(SUB16(R.ax, 0x5));                              // 0422 sub ax, 5
  PUSH(R.ax);                                                  // 0425 push ax
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 0426 push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x042f); a_1533_045c();                   // 042a lcall 0x533, 0x45c
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 042f add sp, 0xc
  R.bx = (u16)(M16(DS, (u16)(0x1e2c)));                        // 0432 mov bx, word ptr [0x1e2c]
  W16(DS, (u16)(R.bx + 0xc), 0xf);                             // 0436 mov word ptr [bx + 0xc], 0xf
  R.ax = (u16)((u16)(R.bp + 0xffb6));                          // 043b lea ax, [bp - 0x4a]
  PUSH(R.ax);                                                  // 043e push ax
  R.ax = (u16)(0x65);                                          // 043f mov ax, 0x65
  PUSH(R.ax);                                                  // 0442 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xffd6)));                         // 0443 push word ptr [bp - 0x2a]
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 0446 push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x044f); du_driver(19);   /* driver slot 19 */ // 044a lcall 0x62a, 0x1fcb
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 044f add sp, 8
  R.ax = (u16)((u16)(R.bp + 0xffda));                          // 0452 lea ax, [bp - 0x26]
  PUSH(R.ax);                                                  // 0455 push ax
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 0456 push word ptr [0x1e2c]
  PUSH(0x045d); a_1000_2a04();                                 // 045a call 0x2a04
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 045d add sp, 4
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0460 mov word ptr [bp - 2], ax
  R.ax = (u16)(0x140);                                         // 0463 mov ax, 0x140
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xfffe))));    // 0466 sub ax, word ptr [bp - 2]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 0469 cdq
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 046a sub ax, dx
  R.ax = (u16)(SAR16(R.ax, 0x1));                              // 046c sar ax, 1
  W16(SS, (u16)(R.bp + 0xffd8), R.ax);                         // 046e mov word ptr [bp - 0x28], ax
  R.ax = (u16)((u16)(R.bp + 0xffda));                          // 0471 lea ax, [bp - 0x26]
  PUSH(R.ax);                                                  // 0474 push ax
  R.ax = (u16)(0x5b);                                          // 0475 mov ax, 0x5b
  PUSH(R.ax);                                                  // 0478 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xffd8)));                         // 0479 push word ptr [bp - 0x28]
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 047c push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x0485); du_driver(19);   /* driver slot 19 */ // 0480 lcall 0x62a, 0x1fcb
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 0485 add sp, 8
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffd6)));                 // 0488 mov ax, word ptr [bp - 0x2a]
  R.ax = (u16)(SUB16(R.ax, 0x4));                              // 048b sub ax, 4
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 048e mov word ptr [bp - 2], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffd6)));                 // 0491 mov ax, word ptr [bp - 0x2a]
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xffd4))));    // 0494 add ax, word ptr [bp - 0x2c]
  R.ax = (u16)(ADD16(R.ax, 0x4));                              // 0497 add ax, 4
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 049a mov word ptr [bp - 4], ax
  W16(SS, (u16)(R.bp + 0xfffa), 0x58);                         // 049d mov word ptr [bp - 6], 0x58
  W16(SS, (u16)(R.bp + 0xfff8), 0x70);                         // 04a2 mov word ptr [bp - 8], 0x70
  R.ax = (u16)(0xc);                                           // 04a7 mov ax, 0xc
  PUSH(R.ax);                                                  // 04aa push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffa)));                         // 04ab push word ptr [bp - 6]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 04ae push word ptr [bp - 4]
  PUSH(M16(SS, (u16)(R.bp + 0xfffa)));                         // 04b1 push word ptr [bp - 6]
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 04b4 push word ptr [bp - 2]
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 04b7 push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x04c0); a_1533_0a36();                   // 04bb lcall 0x533, 0xa36
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 04c0 add sp, 0xc
  R.ax = (u16)(0xc);                                           // 04c3 mov ax, 0xc
  PUSH(R.ax);                                                  // 04c6 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfff8)));                         // 04c7 push word ptr [bp - 8]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 04ca push word ptr [bp - 4]
  PUSH(M16(SS, (u16)(R.bp + 0xfffa)));                         // 04cd push word ptr [bp - 6]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 04d0 push word ptr [bp - 4]
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 04d3 push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x04dc); a_1533_0a36();                   // 04d7 lcall 0x533, 0xa36
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 04dc add sp, 0xc
  R.ax = (u16)(0xc);                                           // 04df mov ax, 0xc
  PUSH(R.ax);                                                  // 04e2 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfff8)));                         // 04e3 push word ptr [bp - 8]
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 04e6 push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfff8)));                         // 04e9 push word ptr [bp - 8]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 04ec push word ptr [bp - 4]
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 04ef push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x04f8); a_1533_0a36();                   // 04f3 lcall 0x533, 0xa36
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 04f8 add sp, 0xc
  R.ax = (u16)(0xc);                                           // 04fb mov ax, 0xc
  PUSH(R.ax);                                                  // 04fe push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffa)));                         // 04ff push word ptr [bp - 6]
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0502 push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfff8)));                         // 0505 push word ptr [bp - 8]
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0508 push word ptr [bp - 2]
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 050b push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x0514); a_1533_0a36();                   // 050f lcall 0x533, 0xa36
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 0514 add sp, 0xc
  PUSH(0x27cc); PUSH(0x051c); du_driver(22);   /* driver slot 22 */ // 0517 lcall 0x62a, 0x1fda
L_051c:   PUSH(0x27cc); PUSH(0x0521); du_driver(90);   /* driver slot 90 */ // 051c lcall 0x62a, 0x212e
  SUB16(R.ax, 0x0);                                            // 0521 cmp ax, 0
  if (R.zf) goto L_0529;                                       // 0524 je 0x529
  goto L_0543;                                                 // 0526 jmp 0x543
L_0529:   PUSH(0x27cc); PUSH(0x052e); du_driver(91);   /* driver slot 91 */ // 0529 lcall 0x62a, 0x2133
  SUB16(R.ax, 0x1000);                                         // 052e cmp ax, 0x1000
  if (R.zf) goto L_0536;                                       // 0531 je 0x536
  goto L_0540;                                                 // 0533 jmp 0x540
L_0536:   R.ax = (u16)(0x0);                                           // 0536 mov ax, 0
  PUSH(R.ax);                                                  // 0539 push ax
  CALL_BEGIN(4); du_exit((i16)ARG(0)); CALL_END();             // 053a call 0x3734
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 053d add sp, 2
L_0540:   goto L_056b;                                                 // 0540 jmp 0x56b
L_0543:   { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 0543 les bx, ptr [0x6206]
  SUB16(M16(ES, (u16)(R.bx + 0x34)), 0x1);                     // 0547 cmp word ptr es:[bx + 0x34], 1
  if (R.zf) goto L_0551;                                       // 054c je 0x551
  goto L_0568;                                                 // 054e jmp 0x568
L_0551:   R.ax = (u16)(0x0);                                           // 0551 mov ax, 0
  PUSH(R.ax);                                                  // 0554 push ax
  PUSH(0x27cc); PUSH(0x055a); du_driver(95);   /* driver slot 95 */ // 0555 lcall 0x62a, 0x2147
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 055a add sp, 2
  SUB16(R.ax, 0x1);                                            // 055d cmp ax, 1
  if (R.zf) goto L_0565;                                       // 0560 je 0x565
  goto L_0568;                                                 // 0562 jmp 0x568
L_0565:   goto L_056b;                                                 // 0565 jmp 0x56b
L_0568:   goto L_051c;                                                 // 0568 jmp 0x51c
L_056b:   R.ax = (u16)(0x0);                                           // 056b mov ax, 0
  PUSH(R.ax);                                                  // 056e push ax
  R.ax = (u16)(0xc8);                                          // 056f mov ax, 0xc8
  PUSH(R.ax);                                                  // 0572 push ax
  R.ax = (u16)(0x140);                                         // 0573 mov ax, 0x140
  PUSH(R.ax);                                                  // 0576 push ax
  R.ax = (u16)(0x0);                                           // 0577 mov ax, 0
  PUSH(R.ax);                                                  // 057a push ax
  R.ax = (u16)(0x0);                                           // 057b mov ax, 0
  PUSH(R.ax);                                                  // 057e push ax
  PUSH(M16(DS, (u16)(0x1e2c)));                                // 057f push word ptr [0x1e2c]
  PUSH(0x27cc); PUSH(0x0588); a_1533_045c();                   // 0583 lcall 0x533, 0x45c
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 0588 add sp, 0xc
  goto L_039b;                                                 // 058b jmp 0x39b
L_058e:   R.si = POP();                                                // 058e pop si
  R.di = POP();                                                // 058f pop di
  R.sp = (u16)(R.bp);                                          // 0590 mov sp, bp
  R.bp = POP();                                                // 0592 pop bp
  R.sp += 2; goto L_ret;                                       // 0593 ret
L_ret:
  return;
}

static u16 f_1000_0361(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_0361();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:0594 FUN_1000_0594  FIX: recompiled from the machine code (asm2c)
static void a_1000_0594(void)
{
  FN(0x10000594);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 0594 push bp
  R.bp = (u16)(R.sp);                                          // 0595 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x8a));                             // 0597 sub sp, 0x8a
  PUSH(R.di);                                                  // 059b push di
  PUSH(R.si);                                                  // 059c push si
  W16(SS, (u16)(R.bp + 0xfff8), 0x0);                          // 059d mov word ptr [bp - 8], 0
  R.ax = (u16)(0xa0);                                          // 05a2 mov ax, 0xa0
  W16(DS, (u16)(0x4fc6), R.ax);                                // 05a5 mov word ptr [0x4fc6], ax
  W16(DS, (u16)(0x4fc4), R.ax);                                // 05a8 mov word ptr [0x4fc4], ax
  W16(DS, (u16)(0x4fce), 0x78);                                // 05ab mov word ptr [0x4fce], 0x78
  W16(DS, (u16)(0x4fd0), 0x50);                                // 05b1 mov word ptr [0x4fd0], 0x50
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 05b7 sub ax, ax
  W16(DS, (u16)(0x2ce6), R.ax);                                // 05b9 mov word ptr [0x2ce6], ax
  W16(DS, (u16)(0x2ce4), R.ax);                                // 05bc mov word ptr [0x2ce4], ax
  W16(DS, (u16)(0x2ce2), R.ax);                                // 05bf mov word ptr [0x2ce2], ax
  W16(DS, (u16)(0x2ce0), R.ax);                                // 05c2 mov word ptr [0x2ce0], ax
  R.ax = (u16)(0x13f);                                         // 05c5 mov ax, 0x13f
  W16(DS, (u16)(0x2cea), R.ax);                                // 05c8 mov word ptr [0x2cea], ax
  W16(DS, (u16)(0x2ce8), R.ax);                                // 05cb mov word ptr [0x2ce8], ax
  R.ax = (u16)(0xc7);                                          // 05ce mov ax, 0xc7
  W16(DS, (u16)(0x2cee), R.ax);                                // 05d1 mov word ptr [0x2cee], ax
  W16(DS, (u16)(0x2cec), R.ax);                                // 05d4 mov word ptr [0x2cec], ax
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 05d7 mov bx, word ptr [0x1f6a]
  W16(DS, (u16)(R.bx), 0x0);                                   // 05db mov word ptr [bx], 0
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 05df sub ax, ax
  PUSH(R.ax);                                                  // 05e1 push ax
  PUSH(R.ax);                                                  // 05e2 push ax
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 05e3 push word ptr [0x1f6a]
  R.ax = (u16)(0xc8);                                          // 05e7 mov ax, 0xc8
  PUSH(R.ax);                                                  // 05ea push ax
  R.ax = (u16)(0x140);                                         // 05eb mov ax, 0x140
  PUSH(R.ax);                                                  // 05ee push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 05ef sub ax, ax
  PUSH(R.ax);                                                  // 05f1 push ax
  PUSH(R.ax);                                                  // 05f2 push ax
  PUSH(M16(DS, (u16)(0x1e48)));                                // 05f3 push word ptr [0x1e48]
  PUSH(0x27cc); PUSH(0x05fc); du_driver(18);   /* driver slot 18 */ // 05f7 lcall 0x62a, 0x1fc6
  R.sp = (u16)(ADD16(R.sp, 0x10));                             // 05fc add sp, 0x10
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 05ff mov bx, word ptr [0x1f6a]
  W16(DS, (u16)(R.bx), 0x1);                                   // 0603 mov word ptr [bx], 1
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0607 sub ax, ax
  PUSH(R.ax);                                                  // 0609 push ax
  PUSH(R.ax);                                                  // 060a push ax
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 060b push word ptr [0x1f6a]
  R.ax = (u16)(0xc8);                                          // 060f mov ax, 0xc8
  PUSH(R.ax);                                                  // 0612 push ax
  R.ax = (u16)(0x140);                                         // 0613 mov ax, 0x140
  PUSH(R.ax);                                                  // 0616 push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0617 sub ax, ax
  PUSH(R.ax);                                                  // 0619 push ax
  PUSH(R.ax);                                                  // 061a push ax
  PUSH(M16(DS, (u16)(0x1e48)));                                // 061b push word ptr [0x1e48]
  PUSH(0x27cc); PUSH(0x0624); du_driver(18);   /* driver slot 18 */ // 061f lcall 0x62a, 0x1fc6
  R.sp = (u16)(ADD16(R.sp, 0x10));                             // 0624 add sp, 0x10
  W16(DS, (u16)(0x1e5e), 0x1);                                 // 0627 mov word ptr [0x1e5e], 1
  R.ax = (u16)(0xffff);                                        // 062d mov ax, 0xffff
  W16(SS, (u16)(R.bp + 0xff94), R.ax);                         // 0630 mov word ptr [bp - 0x6c], ax
  W16(SS, (u16)(R.bp + 0xff92), R.ax);                         // 0633 mov word ptr [bp - 0x6e], ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0636 sub ax, ax
  W16(SS, (u16)(R.bp + 0xff7e), R.ax);                         // 0638 mov word ptr [bp - 0x82], ax
  W16(SS, (u16)(R.bp + 0xff7c), R.ax);                         // 063c mov word ptr [bp - 0x84], ax
  R.ax = (u16)(0x2);                                           // 0640 mov ax, 2
  W16(DS, (u16)(0x61f2), R.ax);                                // 0643 mov word ptr [0x61f2], ax
  W16(DS, (u16)(0x61f0), R.ax);                                // 0646 mov word ptr [0x61f0], ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0649 sub ax, ax
  W16(DS, (u16)(0x4fca), R.ax);                                // 064b mov word ptr [0x4fca], ax
  W16(DS, (u16)(0x4fc8), R.ax);                                // 064e mov word ptr [0x4fc8], ax
  W16(SS, (u16)(R.bp + 0xffac), R.ax);                         // 0651 mov word ptr [bp - 0x54], ax
  W16(SS, (u16)(R.bp + 0xffaa), R.ax);                         // 0654 mov word ptr [bp - 0x56], ax
  W16(SS, (u16)(R.bp + 0xff9a), R.ax);                         // 0657 mov word ptr [bp - 0x66], ax
  W16(DS, (u16)(0x1e60), R.ax);                                // 065a mov word ptr [0x1e60], ax
  W16(DS, (u16)(0x4a74), R.ax);                                // 065d mov word ptr [0x4a74], ax
  W16(DS, (u16)(0x6202), 0x1);                                 // 0660 mov word ptr [0x6202], 1
  R.ax = (u16)(0x4e);                                          // 0666 mov ax, 0x4e
  PUSH(R.ax);                                                  // 0669 push ax
  PUSH(0x066d); a_1000_02a0();                                 // 066a call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 066d add sp, 2
  R.ax = (u16)(0x2);                                           // 0670 mov ax, 2
  PUSH(R.ax);                                                  // 0673 push ax
  PUSH(0x27cc); PUSH(0x0679); du_driver(104);   /* driver slot 104 */ // 0674 lcall 0x62a, 0x2174
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0679 add sp, 2
  SUB16(M16(DS, (u16)(0x4db8)), 0x0);                          // 067c cmp word ptr [0x4db8], 0
  if (R.zf) goto L_0692;                                       // 0681 je 0x692
  W16(DS, (u16)(0x4db8), 0x0);                                 // 0683 mov word ptr [0x4db8], 0
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0689 sub ax, ax
  PUSH(R.ax);                                                  // 068b push ax
  PUSH(0x068f); a_1000_1624();                                 // 068c call 0x1624
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 068f add sp, 2
L_0692:   W16(SS, (u16)(R.bp + 0xff9e), 0x0);                          // 0692 mov word ptr [bp - 0x62], 0
L_0697:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0697 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 069a shl si, 1
  R.si = (u16)(ADD16(R.si, R.bp));                             // 069c add si, bp
  R.ax = (u16)(0x3e);                                          // 069e mov ax, 0x3e
  W16(DS, (u16)(R.si + 0xffd6), R.ax);                         // 06a1 mov word ptr [si - 0x2a], ax
  W16(DS, (u16)(R.si + 0xffb6), R.ax);                         // 06a4 mov word ptr [si - 0x4a], ax
  W16(SS, (u16)(R.bp + 0xff9e), INC16(M16(SS, (u16)(R.bp + 0xff9e)))); // 06a7 inc word ptr [bp - 0x62]
  SUB16(M16(SS, (u16)(R.bp + 0xff9e)), 0x10);                  // 06aa cmp word ptr [bp - 0x62], 0x10
  if (R.sf != R.of) goto L_0697;                               // 06ae jl 0x697
  R.ax = (u16)(0x8);                                           // 06b0 mov ax, 8
  PUSH(R.ax);                                                  // 06b3 push ax
  PUSH(0x06b7); a_1000_202d();                                 // 06b4 call 0x202d
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 06b7 add sp, 2
  W16(SS, (u16)(R.bp + 0xff80), R.ax);                         // 06ba mov word ptr [bp - 0x80], ax
L_06bd:   PUSH(0x06c0); a_1000_20a4();                                 // 06bd call 0x20a4
  SUB16(M16(DS, (u16)(0x61f0)), 0x84);                         // 06c0 cmp word ptr [0x61f0], 0x84
  if (!R.zf) goto L_06d9;                                      // 06c6 jne 0x6d9
  W16(DS, (u16)(0x61f4), 0x1);                                 // 06c8 mov word ptr [0x61f4], 1
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 06ce sub ax, ax
  PUSH(R.ax);                                                  // 06d0 push ax
  PUSH(0x27cc); PUSH(0x06d6); du_driver(104);   /* driver slot 104 */ // 06d1 lcall 0x62a, 0x2174
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 06d6 add sp, 2
L_06d9:   SUB16(M16(DS, (u16)(0x61f2)), 0x84);                         // 06d9 cmp word ptr [0x61f2], 0x84
  if (!R.zf) goto L_06f3;                                      // 06df jne 0x6f3
  W16(DS, (u16)(0x61f4), 0x2);                                 // 06e1 mov word ptr [0x61f4], 2
  R.ax = (u16)(0x5);                                           // 06e7 mov ax, 5
  PUSH(R.ax);                                                  // 06ea push ax
  PUSH(0x27cc); PUSH(0x06f0); du_driver(104);   /* driver slot 104 */ // 06eb lcall 0x62a, 0x2174
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 06f0 add sp, 2
L_06f3:   W16(SS, (u16)(R.bp + 0xfff8), INC16(M16(SS, (u16)(R.bp + 0xfff8)))); // 06f3 inc word ptr [bp - 8]
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xfff8)));                 // 06f6 mov si, word ptr [bp - 8]
  R.si = (u16)(AND16(R.si, 0xf));                              // 06f9 and si, 0xf
  R.si = (u16)(SHL16(R.si, 0x1));                              // 06fc shl si, 1
  R.si = (u16)(ADD16(R.si, R.bp));                             // 06fe add si, bp
  R.ax = (u16)(M16(DS, (u16)(0x61f0)));                        // 0700 mov ax, word ptr [0x61f0]
  W16(DS, (u16)(R.si + 0xffd6), R.ax);                         // 0703 mov word ptr [si - 0x2a], ax
  R.ax = (u16)(M16(DS, (u16)(0x61f2)));                        // 0706 mov ax, word ptr [0x61f2]
  W16(DS, (u16)(R.si + 0xffb6), R.ax);                         // 0709 mov word ptr [si - 0x4a], ax
  R.ax = (u16)(M16(DS, (u16)(0x61f0)));                        // 070c mov ax, word ptr [0x61f0]
  SUB16(M16(SS, (u16)(R.bp + 0xff92)), R.ax);                  // 070f cmp word ptr [bp - 0x6e], ax
  if (!R.zf) goto L_071f;                                      // 0712 jne 0x71f
  R.ax = (u16)(M16(DS, (u16)(0x61f2)));                        // 0714 mov ax, word ptr [0x61f2]
  SUB16(M16(SS, (u16)(R.bp + 0xff94)), R.ax);                  // 0717 cmp word ptr [bp - 0x6c], ax
  if (!R.zf) goto L_071f;                                      // 071a jne 0x71f
  goto L_09ea;                                                 // 071c jmp 0x9ea
L_071f:   R.ax = (u16)(M16(DS, (u16)(0x61f0)));                        // 071f mov ax, word ptr [0x61f0]
  SUB16(M16(SS, (u16)(R.bp + 0xff92)), R.ax);                  // 0722 cmp word ptr [bp - 0x6e], ax
  if (R.zf) goto L_0767;                                       // 0725 je 0x767
  W16(SS, (u16)(R.bp + 0xff9e), 0x0);                          // 0727 mov word ptr [bp - 0x62], 0
L_072c:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 072c mov ax, word ptr [bp - 0x62]
  R.cx = (u16)(R.ax);                                          // 072f mov cx, ax
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0731 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0733 add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0735 shl ax, 1
  R.si = (u16)(R.ax);                                          // 0737 mov si, ax
  R.ax = (u16)(M16(DS, (u16)(0x61f0)));                        // 0739 mov ax, word ptr [0x61f0]
  SUB16(M16(DS, (u16)(R.si + 0x1704)), R.ax);                  // 073c cmp word ptr [si + 0x1704], ax
  if (!R.zf) goto L_0752;                                      // 0740 jne 0x752
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x1706)));                 // 0742 mov ax, word ptr [si + 0x1706]
  W16(DS, (u16)(0x4fc4), ADD16(M16(DS, (u16)(0x4fc4)), R.ax)); // 0746 add word ptr [0x4fc4], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x1708)));                 // 074a mov ax, word ptr [si + 0x1708]
  W16(DS, (u16)(0x4fce), SUB16(M16(DS, (u16)(0x4fce)), R.ax)); // 074e sub word ptr [0x4fce], ax
L_0752:   W16(SS, (u16)(R.bp + 0xff9e), INC16(M16(SS, (u16)(R.bp + 0xff9e)))); // 0752 inc word ptr [bp - 0x62]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0755 mov bx, word ptr [bp - 0x62]
  R.ax = (u16)(R.bx);                                          // 0758 mov ax, bx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 075a shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 075c add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 075e shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x1704)), 0xffff);                // 0760 cmp word ptr [bx + 0x1704], -1
  if (!R.zf) goto L_072c;                                      // 0765 jne 0x72c
L_0767:   R.ax = (u16)(M16(DS, (u16)(0x61f2)));                        // 0767 mov ax, word ptr [0x61f2]
  SUB16(M16(SS, (u16)(R.bp + 0xff94)), R.ax);                  // 076a cmp word ptr [bp - 0x6c], ax
  if (R.zf) goto L_07af;                                       // 076d je 0x7af
  W16(SS, (u16)(R.bp + 0xff9e), 0x0);                          // 076f mov word ptr [bp - 0x62], 0
L_0774:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0774 mov ax, word ptr [bp - 0x62]
  R.cx = (u16)(R.ax);                                          // 0777 mov cx, ax
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0779 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 077b add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 077d shl ax, 1
  R.si = (u16)(R.ax);                                          // 077f mov si, ax
  R.ax = (u16)(M16(DS, (u16)(0x61f2)));                        // 0781 mov ax, word ptr [0x61f2]
  SUB16(M16(DS, (u16)(R.si + 0x1704)), R.ax);                  // 0784 cmp word ptr [si + 0x1704], ax
  if (!R.zf) goto L_079a;                                      // 0788 jne 0x79a
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x1706)));                 // 078a mov ax, word ptr [si + 0x1706]
  W16(DS, (u16)(0x4fc6), SUB16(M16(DS, (u16)(0x4fc6)), R.ax)); // 078e sub word ptr [0x4fc6], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x1708)));                 // 0792 mov ax, word ptr [si + 0x1708]
  W16(DS, (u16)(0x4fd0), ADD16(M16(DS, (u16)(0x4fd0)), R.ax)); // 0796 add word ptr [0x4fd0], ax
L_079a:   W16(SS, (u16)(R.bp + 0xff9e), INC16(M16(SS, (u16)(R.bp + 0xff9e)))); // 079a inc word ptr [bp - 0x62]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 079d mov bx, word ptr [bp - 0x62]
  R.ax = (u16)(R.bx);                                          // 07a0 mov ax, bx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 07a2 shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 07a4 add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 07a6 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x1704)), 0xffff);                // 07a8 cmp word ptr [bx + 0x1704], -1
  if (!R.zf) goto L_0774;                                      // 07ad jne 0x774
L_07af:   R.ax = (u16)(0x114);                                         // 07af mov ax, 0x114
  PUSH(R.ax);                                                  // 07b2 push ax
  R.ax = (u16)(0x30);                                          // 07b3 mov ax, 0x30
  PUSH(R.ax);                                                  // 07b6 push ax
  PUSH(M16(DS, (u16)(0x4fc4)));                                // 07b7 push word ptr [0x4fc4]
  PUSH(0x07be); a_1000_2069();                                 // 07bb call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 07be add sp, 6
  W16(DS, (u16)(0x4fc4), R.ax);                                // 07c1 mov word ptr [0x4fc4], ax
  R.ax = (u16)(0x114);                                         // 07c4 mov ax, 0x114
  PUSH(R.ax);                                                  // 07c7 push ax
  R.ax = (u16)(0x30);                                          // 07c8 mov ax, 0x30
  PUSH(R.ax);                                                  // 07cb push ax
  PUSH(M16(DS, (u16)(0x4fc6)));                                // 07cc push word ptr [0x4fc6]
  PUSH(0x07d3); a_1000_2069();                                 // 07d0 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 07d3 add sp, 6
  W16(DS, (u16)(0x4fc6), R.ax);                                // 07d6 mov word ptr [0x4fc6], ax
  R.si = (u16)(M16(DS, (u16)(0x4fd0)));                        // 07d9 mov si, word ptr [0x4fd0]
  R.si = (u16)(ADD16(R.si, 0x10));                             // 07dd add si, 0x10
  SUB16(M16(DS, (u16)(0x4fce)), R.si);                         // 07e0 cmp word ptr [0x4fce], si
  if (R.sf == R.of) goto L_07ec;                               // 07e4 jge 0x7ec
  R.ax = (u16)(0x1);                                           // 07e6 mov ax, 1
  goto L_07ee;                                                 // 07e9 jmp 0x7ee
L_07ec:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 07ec sub ax, ax
L_07ee:   W16(SS, (u16)(R.bp + 0xffb2), R.ax);                         // 07ee mov word ptr [bp - 0x4e], ax
  SUB16(M16(DS, (u16)(0x4fce)), 0x6e);                         // 07f1 cmp word ptr [0x4fce], 0x6e
  if (R.sf == R.of) goto L_0810;                               // 07f6 jge 0x810
  R.ax = (u16)(0xa0);                                          // 07f8 mov ax, 0xa0
  PUSH(R.ax);                                                  // 07fb push ax
  PUSH(R.si);                                                  // 07fc push si
  PUSH(M16(DS, (u16)(0x4fce)));                                // 07fd push word ptr [0x4fce]
  PUSH(0x0804); a_1000_2069();                                 // 0801 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 0804 add sp, 6
  W16(DS, (u16)(0x4fce), R.ax);                                // 0807 mov word ptr [0x4fce], ax
  R.ax = (u16)(0x3e7);                                         // 080a mov ax, 0x3e7
  goto L_0828;                                                 // 080d jmp 0x828
L_0810:   R.ax = (u16)(0xa0);                                          // 0810 mov ax, 0xa0
  PUSH(R.ax);                                                  // 0813 push ax
  R.ax = (u16)(0x3c);                                          // 0814 mov ax, 0x3c
  PUSH(R.ax);                                                  // 0817 push ax
  PUSH(M16(DS, (u16)(0x4fce)));                                // 0818 push word ptr [0x4fce]
  PUSH(0x081f); a_1000_2069();                                 // 081c call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 081f add sp, 6
  W16(DS, (u16)(0x4fce), R.ax);                                // 0822 mov word ptr [0x4fce], ax
  R.ax = (u16)(SUB16(R.ax, 0x10));                             // 0825 sub ax, 0x10
L_0828:   PUSH(R.ax);                                                  // 0828 push ax
  R.ax = (u16)(0x3c);                                          // 0829 mov ax, 0x3c
  PUSH(R.ax);                                                  // 082c push ax
  PUSH(M16(DS, (u16)(0x4fd0)));                                // 082d push word ptr [0x4fd0]
  PUSH(0x0834); a_1000_2069();                                 // 0831 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 0834 add sp, 6
  W16(DS, (u16)(0x4fd0), R.ax);                                // 0837 mov word ptr [0x4fd0], ax
  SUB16(M16(DS, (u16)(0x4fce)), 0xa0);                         // 083a cmp word ptr [0x4fce], 0xa0
  if (!R.zf) goto L_0853;                                      // 0840 jne 0x853
  W16(DS, (u16)(0x4a70), INC16(M16(DS, (u16)(0x4a70))));       // 0842 inc word ptr [0x4a70]
  SUB16(M16(DS, (u16)(0x4a70)), 0x20);                         // 0846 cmp word ptr [0x4a70], 0x20
  if (R.zf || R.sf != R.of) goto L_0853;                       // 084b jle 0x853
  W16(DS, (u16)(0x61f4), 0x3);                                 // 084d mov word ptr [0x61f4], 3
L_0853:   SUB16(M16(DS, (u16)(0x2cfe)), 0x0);                          // 0853 cmp word ptr [0x2cfe], 0
  if (R.zf) goto L_0860;                                       // 0858 je 0x860
  W16(DS, (u16)(0x2cfe), 0x0);                                 // 085a mov word ptr [0x2cfe], 0
L_0860:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0860 sub ax, ax
  PUSH(R.ax);                                                  // 0862 push ax
  PUSH(0x27cc); PUSH(0x0868); du_driver(14);   /* driver slot 14 */ // 0863 lcall 0x62a, 0x1fb2
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0868 add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 086b or ax, ax
  if (R.zf) goto L_087d;                                       // 086d je 0x87d
  W8(DS, (u16)(0x1e5e), XOR8(M8(DS, (u16)(0x1e5e)), 0x1));     // 086f xor byte ptr [0x1e5e], 1
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 0874 mov bx, word ptr [0x1f6a]
  R.ax = (u16)(M16(DS, (u16)(0x1e5e)));                        // 0878 mov ax, word ptr [0x1e5e]
  W16(DS, (u16)(R.bx), R.ax);                                  // 087b mov word ptr [bx], ax
L_087d:   R.si = (u16)(M16(DS, (u16)(0x1e5e)));                        // 087d mov si, word ptr [0x1e5e]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0881 shl si, 1
  PUSH(M16(DS, (u16)(R.si + 0x2ce4)));                         // 0883 push word ptr [si + 0x2ce4]
  PUSH(M16(DS, (u16)(R.si + 0x2ce0)));                         // 0887 push word ptr [si + 0x2ce0]
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 088b push word ptr [0x1f6a]
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x2cec)));                 // 088f mov ax, word ptr [si + 0x2cec]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x2ce4))));    // 0893 sub ax, word ptr [si + 0x2ce4]
  PUSH(R.ax);                                                  // 0897 push ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x2ce8)));                 // 0898 mov ax, word ptr [si + 0x2ce8]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x2ce0))));    // 089c sub ax, word ptr [si + 0x2ce0]
  PUSH(R.ax);                                                  // 08a0 push ax
  PUSH(M16(DS, (u16)(R.si + 0x2ce4)));                         // 08a1 push word ptr [si + 0x2ce4]
  PUSH(M16(DS, (u16)(R.si + 0x2ce0)));                         // 08a5 push word ptr [si + 0x2ce0]
  PUSH(M16(DS, (u16)(0x1e48)));                                // 08a9 push word ptr [0x1e48]
  PUSH(0x27cc); PUSH(0x08b2); du_driver(18);   /* driver slot 18 */ // 08ad lcall 0x62a, 0x1fc6
  R.sp = (u16)(ADD16(R.sp, 0x10));                             // 08b2 add sp, 0x10
  R.si = (u16)(M16(DS, (u16)(0x1e5e)));                        // 08b5 mov si, word ptr [0x1e5e]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 08b9 shl si, 1
  R.ax = (u16)(0x270f);                                        // 08bb mov ax, 0x270f
  W16(DS, (u16)(R.si + 0x2ce4), R.ax);                         // 08be mov word ptr [si + 0x2ce4], ax
  W16(DS, (u16)(R.si + 0x2ce0), R.ax);                         // 08c2 mov word ptr [si + 0x2ce0], ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 08c6 sub ax, ax
  W16(DS, (u16)(R.si + 0x2cec), R.ax);                         // 08c8 mov word ptr [si + 0x2cec], ax
  W16(DS, (u16)(R.si + 0x2ce8), R.ax);                         // 08cc mov word ptr [si + 0x2ce8], ax
  SUB16(M16(DS, (u16)(0x1e60)), R.ax);                         // 08d0 cmp word ptr [0x1e60], ax
  if (R.zf) goto L_0901;                                       // 08d4 je 0x901
  R.ax = (u16)(0x2);                                           // 08d6 mov ax, 2
  PUSH(R.ax);                                                  // 08d9 push ax
  R.ax = (u16)(0x20);                                          // 08da mov ax, 0x20
  PUSH(R.ax);                                                  // 08dd push ax
  R.ax = (u16)(0x78);                                          // 08de mov ax, 0x78
  PUSH(R.ax);                                                  // 08e1 push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 08e2 sub ax, ax
  PUSH(R.ax);                                                  // 08e4 push ax
  PUSH(R.ax);                                                  // 08e5 push ax
  PUSH(0x08e9); a_1000_1f80();                                 // 08e6 call 0x1f80
  R.sp = (u16)(ADD16(R.sp, 0xa));                              // 08e9 add sp, 0xa
  PUSH(M16(DS, (u16)(0x4fcc)));                                // 08ec push word ptr [0x4fcc]
  PUSH(M16(SS, (u16)(R.bp + 0xffaa)));                         // 08f0 push word ptr [bp - 0x56]
  PUSH(M16(DS, (u16)(0x61f0)));                                // 08f3 push word ptr [0x61f0]
  PUSH(M16(DS, (u16)(0x61f2)));                                // 08f7 push word ptr [0x61f2]
  PUSH(0x08fe); a_1000_17c0();                                 // 08fb call 0x17c0
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 08fe add sp, 8
L_0901:   R.ax = (u16)(0x18);                                          // 0901 mov ax, 0x18
  IMUL16(M16(DS, (u16)(0x61f0)));                              // 0904 imul word ptr [0x61f0]
  R.bx = (u16)(R.ax);                                          // 0908 mov bx, ax
  R.ax = (u16)(M16(DS, (u16)(0x4fce)));                        // 090a mov ax, word ptr [0x4fce]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.bx + 0xa94))));     // 090d sub ax, word ptr [bx + 0xa94]
  W16(SS, (u16)(R.bp + 0xff78), R.ax);                         // 0911 mov word ptr [bp - 0x88], ax
  R.ax = (u16)(0x18);                                          // 0915 mov ax, 0x18
  IMUL16(M16(DS, (u16)(0x61f2)));                              // 0918 imul word ptr [0x61f2]
  R.bx = (u16)(R.ax);                                          // 091c mov bx, ax
  R.ax = (u16)(M16(DS, (u16)(0x4fd0)));                        // 091e mov ax, word ptr [0x4fd0]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.bx + 0xa94))));     // 0921 sub ax, word ptr [bx + 0xa94]
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0925 mov word ptr [bp - 4], ax
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff78)));                 // 0928 mov si, word ptr [bp - 0x88]
  R.si = (u16)(SUB16(R.si, R.ax));                             // 092c sub si, ax
  SUB16(R.si, 0x8);                                            // 092e cmp si, 8
  if (R.sf == R.of) goto L_0949;                               // 0931 jge 0x949
  W16(SS, (u16)(R.bp + 0xff84), R.si);                         // 0933 mov word ptr [bp - 0x7c], si
  R.ax = (u16)(0x8);                                           // 0936 mov ax, 8
  R.ax = (u16)(SUB16(R.ax, R.si));                             // 0939 sub ax, si
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 093b cdq
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 093c sub ax, dx
  R.ax = (u16)(SAR16(R.ax, 0x1));                              // 093e sar ax, 1
  R.di = (u16)(R.ax);                                          // 0940 mov di, ax
  W16(SS, (u16)(R.bp + 0xff78), ADD16(M16(SS, (u16)(R.bp + 0xff78)), R.di)); // 0942 add word ptr [bp - 0x88], di
  W16(SS, (u16)(R.bp + 0xfffc), SUB16(M16(SS, (u16)(R.bp + 0xfffc)), R.di)); // 0946 sub word ptr [bp - 4], di
L_0949:   PUSH(0x094c); a_1000_1774();                                 // 0949 call 0x1774
  R.ax = (u16)(0x18);                                          // 094c mov ax, 0x18
  IMUL16(M16(DS, (u16)(0x61f2)));                              // 094f imul word ptr [0x61f2]
  R.si = (u16)(R.ax);                                          // 0953 mov si, ax
  R.ax = (u16)(0x1);                                           // 0955 mov ax, 1
  PUSH(R.ax);                                                  // 0958 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0959 push word ptr [bp - 4]
  R.ax = (u16)(M16(DS, (u16)(R.si + 0xa92)));                  // 095c mov ax, word ptr [si + 0xa92]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x4fc6))));           // 0960 add ax, word ptr [0x4fc6]
  PUSH(R.ax);                                                  // 0964 push ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0xa8e)));                  // 0965 mov ax, word ptr [si + 0xa8e]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x2cfa))));           // 0969 add ax, word ptr [0x2cfa]
  PUSH(R.ax);                                                  // 096d push ax
  PUSH(0x0971); a_1000_154c();                                 // 096e call 0x154c
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 0971 add sp, 8
  R.ax = (u16)(0x18);                                          // 0974 mov ax, 0x18
  IMUL16(M16(DS, (u16)(0x61f2)));                              // 0977 imul word ptr [0x61f2]
  R.si = (u16)(R.ax);                                          // 097b mov si, ax
  R.ax = (u16)(0x1);                                           // 097d mov ax, 1
  PUSH(R.ax);                                                  // 0980 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0981 push word ptr [bp - 4]
  R.ax = (u16)(M16(DS, (u16)(R.si + 0xa92)));                  // 0984 mov ax, word ptr [si + 0xa92]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x4fc6))));           // 0988 add ax, word ptr [0x4fc6]
  PUSH(R.ax);                                                  // 098c push ax
  PUSH(M16(DS, (u16)(R.si + 0xa8c)));                          // 098d push word ptr [si + 0xa8c]
  PUSH(0x0994); a_1000_154c();                                 // 0991 call 0x154c
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 0994 add sp, 8
  R.ax = (u16)(0x18);                                          // 0997 mov ax, 0x18
  IMUL16(M16(DS, (u16)(0x61f0)));                              // 099a imul word ptr [0x61f0]
  R.si = (u16)(R.ax);                                          // 099e mov si, ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 09a0 sub ax, ax
  PUSH(R.ax);                                                  // 09a2 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xff78)));                         // 09a3 push word ptr [bp - 0x88]
  R.ax = (u16)(M16(DS, (u16)(0x4fc4)));                        // 09a7 mov ax, word ptr [0x4fc4]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0xa92))));     // 09aa sub ax, word ptr [si + 0xa92]
  PUSH(R.ax);                                                  // 09ae push ax
  PUSH(M16(DS, (u16)(R.si + 0xa8c)));                          // 09af push word ptr [si + 0xa8c]
  PUSH(0x09b6); a_1000_154c();                                 // 09b3 call 0x154c
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 09b6 add sp, 8
  R.ax = (u16)(0x18);                                          // 09b9 mov ax, 0x18
  IMUL16(M16(DS, (u16)(0x61f0)));                              // 09bc imul word ptr [0x61f0]
  R.si = (u16)(R.ax);                                          // 09c0 mov si, ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 09c2 sub ax, ax
  PUSH(R.ax);                                                  // 09c4 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xff78)));                         // 09c5 push word ptr [bp - 0x88]
  R.ax = (u16)(M16(DS, (u16)(0x4fc4)));                        // 09c9 mov ax, word ptr [0x4fc4]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0xa92))));     // 09cc sub ax, word ptr [si + 0xa92]
  PUSH(R.ax);                                                  // 09d0 push ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0xa8e)));                  // 09d1 mov ax, word ptr [si + 0xa8e]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x2cfa))));           // 09d5 add ax, word ptr [0x2cfa]
  PUSH(R.ax);                                                  // 09d9 push ax
  PUSH(0x09dd); a_1000_154c();                                 // 09da call 0x154c
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 09dd add sp, 8
  PUSH(M16(DS, (u16)(0x1e5e)));                                // 09e0 push word ptr [0x1e5e]
  PUSH(0x09e7); a_1000_0338();                                 // 09e4 call 0x338
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 09e7 add sp, 2
L_09ea:   R.ax = (u16)(M16(DS, (u16)(0x4fc6)));                        // 09ea mov ax, word ptr [0x4fc6]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(0x4fc4))));           // 09ed sub ax, word ptr [0x4fc4]
  W16(SS, (u16)(R.bp + 0xff8a), R.ax);                         // 09f1 mov word ptr [bp - 0x76], ax
  R.ax = (u16)(M16(DS, (u16)(0x4fce)));                        // 09f4 mov ax, word ptr [0x4fce]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(0x4fd0))));           // 09f7 sub ax, word ptr [0x4fd0]
  W16(SS, (u16)(R.bp + 0xff86), R.ax);                         // 09fb mov word ptr [bp - 0x7a], ax
  W16(SS, (u16)(R.bp + 0xffa2), 0x0);                          // 09fe mov word ptr [bp - 0x5e], 0
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff8a)));                 // 0a03 mov ax, word ptr [bp - 0x76]
  R.ax = (u16)(ADD16(R.ax, 0x8));                              // 0a06 add ax, 8
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 0a09 cdq
  R.ax = (u16)(XOR16(R.ax, R.dx));                             // 0a0a xor ax, dx
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 0a0c sub ax, dx
  R.cx = (u16)(0x4);                                           // 0a0e mov cx, 4
  R.ax = (u16)(SAR16(R.ax, (u8)R.cx));                         // 0a11 sar ax, cl
  R.ax = (u16)(XOR16(R.ax, R.dx));                             // 0a13 xor ax, dx
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 0a15 sub ax, dx
  W16(DS, (u16)(0x4fc2), R.ax);                                // 0a17 mov word ptr [0x4fc2], ax
  SUB16(M16(SS, (u16)(R.bp + 0xff8a)), 0xfff8);                // 0a1a cmp word ptr [bp - 0x76], -8
  if (R.sf == R.of) goto L_0a24;                               // 0a1e jge 0xa24
  W16(DS, (u16)(0x4fc2), DEC16(M16(DS, (u16)(0x4fc2))));       // 0a20 dec word ptr [0x4fc2]
L_0a24:   SUB16(M16(SS, (u16)(R.bp + 0xff86)), 0x18);                  // 0a24 cmp word ptr [bp - 0x7a], 0x18
  if (R.sf == R.of) goto L_0a30;                               // 0a28 jge 0xa30
  R.ax = (u16)(0x1);                                           // 0a2a mov ax, 1
  goto L_0a32;                                                 // 0a2d jmp 0xa32
L_0a30:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0a30 sub ax, ax
L_0a32:   W16(SS, (u16)(R.bp + 0xffae), R.ax);                         // 0a32 mov word ptr [bp - 0x52], ax
  W16(SS, (u16)(R.bp + 0xff9e), 0x0);                          // 0a35 mov word ptr [bp - 0x62], 0
  goto L_1033;                                                 // 0a3a jmp 0x1033
L_0a3e:   SETL(R.ax, du_kbd_poll(0x0a3e));                           // 0a3e mov al, byte ptr [0x22f2]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0a41 sub ah, ah
  R.ax = (u16)(SUB16(R.ax, 0x80));                             // 0a43 sub ax, 0x80
  W16(SS, (u16)(R.bp + 0xff88), R.ax);                         // 0a46 mov word ptr [bp - 0x78], ax
  SETL(R.ax, M8(DS, (u16)(0x22f3)));                           // 0a49 mov al, byte ptr [0x22f3]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0a4c sub ah, ah
  R.ax = (u16)(SUB16(R.ax, 0x80));                             // 0a4e sub ax, 0x80
  W16(SS, (u16)(R.bp + 0xff84), R.ax);                         // 0a51 mov word ptr [bp - 0x7c], ax
  SETL(R.ax, M8(DS, (u16)(0x22f4)));                           // 0a54 mov al, byte ptr [0x22f4]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0a57 sub ah, ah
  W16(SS, (u16)(R.bp + 0xffa8), R.ax);                         // 0a59 mov word ptr [bp - 0x58], ax
  SETL(R.ax, M8(DS, (u16)(0x22f5)));                           // 0a5c mov al, byte ptr [0x22f5]
L_0a5f:   W16(SS, (u16)(R.bp + 0xffa0), R.ax);                         // 0a5f mov word ptr [bp - 0x60], ax
L_0a62:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0a62 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0a65 shl si, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xffaa)));          // 0a67 mov ax, word ptr [bp + si - 0x56]
  W16(SS, (u16)(R.bp + 0xffb4), R.ax);                         // 0a6a mov word ptr [bp - 0x4c], ax
  W16(SS, (u16)(R.bp + R.si + 0xffaa), 0x0);                   // 0a6d mov word ptr [bp + si - 0x56], 0
  SUB16(M16(SS, (u16)(R.bp + 0xffa8)), 0x0);                   // 0a72 cmp word ptr [bp - 0x58], 0
  if (R.zf) goto L_0a89;                                       // 0a76 je 0xa89
  W16(SS, (u16)(R.bp + R.si + 0xffaa), 0x1);                   // 0a78 mov word ptr [bp + si - 0x56], 1
  SUB16(M16(DS, (u16)(R.si + 0x4fce)), 0xa0);                  // 0a7d cmp word ptr [si + 0x4fce], 0xa0
  if (!R.zf) goto L_0a89;                                      // 0a83 jne 0xa89
  W16(DS, (u16)(R.si + 0x4fce), DEC16(M16(DS, (u16)(R.si + 0x4fce)))); // 0a85 dec word ptr [si + 0x4fce]
L_0a89:   SUB16(M16(SS, (u16)(R.bp + 0xffa0)), 0x0);                   // 0a89 cmp word ptr [bp - 0x60], 0
  if (R.zf) goto L_0a99;                                       // 0a8d je 0xa99
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0a8f mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0a92 shl si, 1
  W16(SS, (u16)(R.bp + R.si + 0xffaa), 0x2);                   // 0a94 mov word ptr [bp + si - 0x56], 2
L_0a99:   PUSH(M16(SS, (u16)(R.bp + 0xff88)));                         // 0a99 push word ptr [bp - 0x78]
  PUSH(0x0a9f); a_1000_50d8();                                 // 0a9c call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0a9f add sp, 2
  SUB16(R.ax, 0x50);                                           // 0aa2 cmp ax, 0x50
  if (R.zf || R.sf != R.of) goto L_0ab6;                       // 0aa5 jle 0xab6
  PUSH(M16(SS, (u16)(R.bp + 0xff88)));                         // 0aa7 push word ptr [bp - 0x78]
  PUSH(0x0aad); a_1000_1ba4();                                 // 0aaa call 0x1ba4
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0aad add sp, 2
  W16(SS, (u16)(R.bp + 0xff88), R.ax);                         // 0ab0 mov word ptr [bp - 0x78], ax
  goto L_0abb;                                                 // 0ab3 jmp 0xabb
L_0ab6:   W16(SS, (u16)(R.bp + 0xff88), 0x0);                          // 0ab6 mov word ptr [bp - 0x78], 0
L_0abb:   PUSH(M16(SS, (u16)(R.bp + 0xff84)));                         // 0abb push word ptr [bp - 0x7c]
  PUSH(0x0ac1); a_1000_50d8();                                 // 0abe call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0ac1 add sp, 2
  SUB16(R.ax, 0x40);                                           // 0ac4 cmp ax, 0x40
  if (R.zf || R.sf != R.of) goto L_0ad8;                       // 0ac7 jle 0xad8
  PUSH(M16(SS, (u16)(R.bp + 0xff84)));                         // 0ac9 push word ptr [bp - 0x7c]
  PUSH(0x0acf); a_1000_1ba4();                                 // 0acc call 0x1ba4
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0acf add sp, 2
  W16(SS, (u16)(R.bp + 0xff84), R.ax);                         // 0ad2 mov word ptr [bp - 0x7c], ax
  goto L_0add;                                                 // 0ad5 jmp 0xadd
L_0ad8:   W16(SS, (u16)(R.bp + 0xff84), 0x0);                          // 0ad8 mov word ptr [bp - 0x7c], 0
L_0add:   SUB16(R.bp, 0x56);                                           // 0add cmp bp, 0x56
  if (!R.zf) goto L_0af3;                                      // 0ae0 jne 0xaf3
  SUB16(M16(SS, (u16)(R.bp + 0xffb2)), 0x0);                   // 0ae2 cmp word ptr [bp - 0x4e], 0
  if (R.zf) goto L_0af3;                                       // 0ae6 je 0xaf3
  SUB16(M16(SS, (u16)(R.bp + 0xff84)), 0x0);                   // 0ae8 cmp word ptr [bp - 0x7c], 0
  if (R.sf == R.of) goto L_0af3;                               // 0aec jge 0xaf3
  W16(SS, (u16)(R.bp + 0xff84), 0x0);                          // 0aee mov word ptr [bp - 0x7c], 0
L_0af3:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff84)));                 // 0af3 mov ax, word ptr [bp - 0x7c]
  R.cx = (u16)(R.ax);                                          // 0af6 mov cx, ax
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0af8 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0afa add ax, cx
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xff88))));    // 0afc add ax, word ptr [bp - 0x78]
  R.ax = (u16)(ADD16(R.ax, 0x4));                              // 0aff add ax, 4
  W16(SS, (u16)(R.bp + 0xff98), R.ax);                         // 0b02 mov word ptr [bp - 0x68], ax
  goto L_0e91;                                                 // 0b05 jmp 0xe91
L_0b08:   AND8(M8(SS, (u16)(R.bp + 0xfff8)), 0xf);                     // 0b08 test byte ptr [bp - 8], 0xf
  if (!R.zf) goto L_0b3f;                                      // 0b0c jne 0xb3f
  R.ax = (u16)(0x3);                                           // 0b0e mov ax, 3
  PUSH(R.ax);                                                  // 0b11 push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0b12 sub ax, ax
  PUSH(R.ax);                                                  // 0b14 push ax
  R.ax = (u16)(0x4);                                           // 0b15 mov ax, 4
  PUSH(R.ax);                                                  // 0b18 push ax
  PUSH(0x0b1c); a_1000_202d();                                 // 0b19 call 0x202d
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b1c add sp, 2
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(0x4dbe))));           // 0b1f sub ax, word ptr [0x4dbe]
  PUSH(R.ax);                                                  // 0b23 push ax
  PUSH(0x0b27); a_1000_2069();                                 // 0b24 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 0b27 add sp, 6
  W16(SS, (u16)(R.bp + 0xff80), R.ax);                         // 0b2a mov word ptr [bp - 0x80], ax
  R.ax = (u16)(0x2);                                           // 0b2d mov ax, 2
  PUSH(R.ax);                                                  // 0b30 push ax
  PUSH(0x0b34); a_1000_202d();                                 // 0b31 call 0x202d
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b34 add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0b37 or ax, ax
  if (R.zf) goto L_0b3f;                                       // 0b39 je 0xb3f
  W16(SS, (u16)(R.bp + 0xff80), ADD16(M16(SS, (u16)(R.bp + 0xff80)), 0x4)); // 0b3b add word ptr [bp - 0x80], 4
L_0b3f:   R.ax = (u16)(0xf);                                           // 0b3f mov ax, 0xf
  PUSH(R.ax);                                                  // 0b42 push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0b43 sub ax, ax
  PUSH(R.ax);                                                  // 0b45 push ax
  R.ax = (u16)(M16(DS, (u16)(0x1e62)));                        // 0b46 mov ax, word ptr [0x1e62]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0b49 shl ax, 1
  R.ax = (u16)(SUB16(R.ax, 0xa));                              // 0b4b sub ax, 0xa
  R.ax = (u16)(NEG16(R.ax));                                   // 0b4e neg ax
  PUSH(R.ax);                                                  // 0b50 push ax
  PUSH(0x0b54); a_1000_2069();                                 // 0b51 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 0b54 add sp, 6
  PUSH(R.ax);                                                  // 0b57 push ax
  PUSH(0x0b5b); a_1000_202d();                                 // 0b58 call 0x202d
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b5b add sp, 2
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xfff8)));                 // 0b5e mov si, word ptr [bp - 8]
  R.si = (u16)(SUB16(R.si, R.ax));                             // 0b61 sub si, ax
  R.si = (u16)(AND16(R.si, 0xf));                              // 0b63 and si, 0xf
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0b66 shl si, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0b68 mov ax, word ptr [bp - 0x62]
  SETL(R.cx, 0x5);                                             // 0b6b mov cl, 5
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 0b6d shl ax, cl
  R.si = (u16)(ADD16(R.si, R.ax));                             // 0b6f add si, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xffb6)));          // 0b71 mov ax, word ptr [bp + si - 0x4a]
  W16(SS, (u16)(R.bp + 0xff8e), R.ax);                         // 0b74 mov word ptr [bp - 0x72], ax
  R.ax = (u16)(0x2);                                           // 0b77 mov ax, 2
  PUSH(R.ax);                                                  // 0b7a push ax
  R.ax = (u16)(0xfffe);                                        // 0b7b mov ax, 0xfffe
  PUSH(R.ax);                                                  // 0b7e push ax
  PUSH(M16(DS, (u16)(0x4fc2)));                                // 0b7f push word ptr [0x4fc2]
  PUSH(0x0b86); a_1000_2069();                                 // 0b83 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 0b86 add sp, 6
  W16(SS, (u16)(R.bp + 0xff7a), R.ax);                         // 0b89 mov word ptr [bp - 0x86], ax
  AND8(M8(SS, (u16)(R.bp + 0xff7a)), 0x1);                     // 0b8d test byte ptr [bp - 0x86], 1
  if (!R.zf) goto L_0ba4;                                      // 0b92 jne 0xba4
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0b94 shl ax, 1
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xff80)));                 // 0b96 mov cx, word ptr [bp - 0x80]
  R.cx = (u16)(AND16(R.cx, 0x3));                              // 0b99 and cx, 3
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0b9c add ax, cx
  R.ax = (u16)(ADD16(R.ax, 0x4));                              // 0b9e add ax, 4
  goto L_0bb0;                                                 // 0ba1 jmp 0xbb0
L_0ba4:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff7a)));                 // 0ba4 mov ax, word ptr [bp - 0x86]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ba8 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xff80))));    // 0baa add ax, word ptr [bp - 0x80]
  R.ax = (u16)(ADD16(R.ax, 0x2));                              // 0bad add ax, 2
L_0bb0:   W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 0bb0 mov word ptr [bp - 0xa], ax
  SUB16(M16(SS, (u16)(R.bp + 0xffae)), 0x0);                   // 0bb3 cmp word ptr [bp - 0x52], 0
  if (R.zf) goto L_0bcc;                                       // 0bb7 je 0xbcc
  PUSH(M16(SS, (u16)(R.bp + 0xff8a)));                         // 0bb9 push word ptr [bp - 0x76]
  PUSH(0x0bbf); a_1000_50d8();                                 // 0bbc call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0bbf add sp, 2
  SUB16(R.ax, 0x18);                                           // 0bc2 cmp ax, 0x18
  if (R.sf == R.of) goto L_0bcc;                               // 0bc5 jge 0xbcc
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0bc7 sub ax, ax
  goto L_0bcf;                                                 // 0bc9 jmp 0xbcf
L_0bcc:   R.ax = (u16)(0xc);                                           // 0bcc mov ax, 0xc
L_0bcf:   W16(SS, (u16)(R.bp + 0xfff6), ADD16(M16(SS, (u16)(R.bp + 0xfff6)), R.ax)); // 0bcf add word ptr [bp - 0xa], ax
  W16(SS, (u16)(R.bp + 0xff96), 0x0);                          // 0bd2 mov word ptr [bp - 0x6a], 0
  W16(SS, (u16)(R.bp + 0xff82), 0x0);                          // 0bd7 mov word ptr [bp - 0x7e], 0
  W16(SS, (u16)(R.bp + 0xffb0), 0x3e7);                        // 0bdc mov word ptr [bp - 0x50], 0x3e7
  goto L_0c1b;                                                 // 0be1 jmp 0xc1b
L_0be4:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff8e)));                 // 0be4 mov ax, word ptr [bp - 0x72]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x17b2))));    // 0be7 sub ax, word ptr [si + 0x17b2]
  W16(SS, (u16)(R.bp + 0xff9c), R.ax);                         // 0beb mov word ptr [bp - 0x64], ax
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0bee or ax, ax
  if (R.sf != R.of) goto L_0c18;                               // 0bf0 jl 0xc18
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffb0)));                 // 0bf2 mov ax, word ptr [bp - 0x50]
  SUB16(M16(SS, (u16)(R.bp + 0xff9c)), R.ax);                  // 0bf5 cmp word ptr [bp - 0x64], ax
  if (R.sf == R.of) goto L_0c18;                               // 0bf8 jge 0xc18
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfff6)));                 // 0bfa mov bx, word ptr [bp - 0xa]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0bfd shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + R.si + 0x17b4)));          // 0bff mov ax, word ptr [bx + si + 0x17b4]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0c03 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c06 shl bx, 1
  W16(DS, (u16)(R.bx + 0x61fe), R.ax);                         // 0c08 mov word ptr [bx + 0x61fe], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff9c)));                 // 0c0c mov ax, word ptr [bp - 0x64]
  W16(SS, (u16)(R.bp + 0xffb0), R.ax);                         // 0c0f mov word ptr [bp - 0x50], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff96)));                 // 0c12 mov ax, word ptr [bp - 0x6a]
  W16(SS, (u16)(R.bp + 0xff82), R.ax);                         // 0c15 mov word ptr [bp - 0x7e], ax
L_0c18:   W16(SS, (u16)(R.bp + 0xff96), INC16(M16(SS, (u16)(R.bp + 0xff96)))); // 0c18 inc word ptr [bp - 0x6a]
L_0c1b:   R.ax = (u16)(0x32);                                          // 0c1b mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff96)));                       // 0c1e imul word ptr [bp - 0x6a]
  R.si = (u16)(R.ax);                                          // 0c21 mov si, ax
  SUB16(M16(DS, (u16)(R.si + 0x17b2)), 0xffff);                // 0c23 cmp word ptr [si + 0x17b2], -1
  if (!R.zf) goto L_0be4;                                      // 0c28 jne 0xbe4
  W16(SS, (u16)(R.bp + 0xffa0), 0x0);                          // 0c2a mov word ptr [bp - 0x60], 0
  PUSH(M16(SS, (u16)(R.bp + 0xff86)));                         // 0c2f push word ptr [bp - 0x7a]
  PUSH(0x0c35); a_1000_50d8();                                 // 0c32 call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0c35 add sp, 2
  SUB16(R.ax, 0x18);                                           // 0c38 cmp ax, 0x18
  if (R.sf == R.of) goto L_0c60;                               // 0c3b jge 0xc60
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0c3d mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c40 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61fe)));                 // 0c42 mov si, word ptr [bx + 0x61fe]
  SUB16(R.si, 0x10);                                           // 0c46 cmp si, 0x10
  if (R.zf) goto L_0c55;                                       // 0c49 je 0xc55
  SUB16(R.si, 0x18);                                           // 0c4b cmp si, 0x18
  if (R.zf) goto L_0c55;                                       // 0c4e je 0xc55
  SUB16(R.si, 0x1f);                                           // 0c50 cmp si, 0x1f
  if (!R.zf) goto L_0c60;                                      // 0c53 jne 0xc60
L_0c55:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0c55 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c58 shl bx, 1
  W16(DS, (u16)(R.bx + 0x61fe), 0x0);                          // 0c5a mov word ptr [bx + 0x61fe], 0
L_0c60:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0c60 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0c63 shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x61fe)), 0x0);                   // 0c65 cmp word ptr [si + 0x61fe], 0
  if (R.zf) goto L_0c6f;                                       // 0c6a je 0xc6f
  goto L_0dbb;                                                 // 0c6c jmp 0xdbb
L_0c6f:   R.bx = (u16)(0x1);                                           // 0c6f mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 0c72 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c75 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x4fc8)), 0x0);                   // 0c77 cmp word ptr [bx + 0x4fc8], 0
  if (R.zf) goto L_0c81;                                       // 0c7c je 0xc81
  goto L_0dbb;                                                 // 0c7e jmp 0xdbb
L_0c81:   SUB16(M16(DS, (u16)(R.si + 0x4fc8)), 0x0);                   // 0c81 cmp word ptr [si + 0x4fc8], 0
  if (R.zf) goto L_0c8b;                                       // 0c86 je 0xc8b
  goto L_0dbb;                                                 // 0c88 jmp 0xdbb
L_0c8b:   W16(SS, (u16)(R.bp + 0xff8c), 0x0);                          // 0c8b mov word ptr [bp - 0x74], 0
  W16(SS, (u16)(R.bp + 0xffa0), 0x1);                          // 0c90 mov word ptr [bp - 0x60], 1
  R.ax = (u16)(0x32);                                          // 0c95 mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0c98 imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0c9b mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x55);                  // 0c9d cmp word ptr [bx + 0x17b2], 0x55
  if (!R.zf) goto L_0ca9;                                      // 0ca2 jne 0xca9
  W16(SS, (u16)(R.bp + 0xff8c), 0x1);                          // 0ca4 mov word ptr [bp - 0x74], 1
L_0ca9:   R.ax = (u16)(0x32);                                          // 0ca9 mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0cac imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0caf mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x5a);                  // 0cb1 cmp word ptr [bx + 0x17b2], 0x5a
  if (!R.zf) goto L_0cbd;                                      // 0cb6 jne 0xcbd
  W16(SS, (u16)(R.bp + 0xff8c), 0x1);                          // 0cb8 mov word ptr [bp - 0x74], 1
L_0cbd:   R.ax = (u16)(0x32);                                          // 0cbd mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0cc0 imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0cc3 mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x71);                  // 0cc5 cmp word ptr [bx + 0x17b2], 0x71
  if (!R.zf) goto L_0cd1;                                      // 0cca jne 0xcd1
  W16(SS, (u16)(R.bp + 0xff8c), 0x1);                          // 0ccc mov word ptr [bp - 0x74], 1
L_0cd1:   R.ax = (u16)(0x32);                                          // 0cd1 mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0cd4 imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0cd7 mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x66);                  // 0cd9 cmp word ptr [bx + 0x17b2], 0x66
  if (!R.zf) goto L_0ce5;                                      // 0cde jne 0xce5
  W16(SS, (u16)(R.bp + 0xff8c), 0x1);                          // 0ce0 mov word ptr [bp - 0x74], 1
L_0ce5:   R.ax = (u16)(0x32);                                          // 0ce5 mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0ce8 imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0ceb mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x4a);                  // 0ced cmp word ptr [bx + 0x17b2], 0x4a
  if (!R.zf) goto L_0cf9;                                      // 0cf2 jne 0xcf9
  W16(SS, (u16)(R.bp + 0xff8c), 0xffff);                       // 0cf4 mov word ptr [bp - 0x74], 0xffff
L_0cf9:   R.ax = (u16)(0x32);                                          // 0cf9 mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0cfc imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0cff mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x4f);                  // 0d01 cmp word ptr [bx + 0x17b2], 0x4f
  if (!R.zf) goto L_0d0d;                                      // 0d06 jne 0xd0d
  W16(SS, (u16)(R.bp + 0xff8c), 0xffff);                       // 0d08 mov word ptr [bp - 0x74], 0xffff
L_0d0d:   R.ax = (u16)(0x32);                                          // 0d0d mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0d10 imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0d13 mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x6c);                  // 0d15 cmp word ptr [bx + 0x17b2], 0x6c
  if (!R.zf) goto L_0d21;                                      // 0d1a jne 0xd21
  W16(SS, (u16)(R.bp + 0xff8c), 0xffff);                       // 0d1c mov word ptr [bp - 0x74], 0xffff
L_0d21:   R.ax = (u16)(0x32);                                          // 0d21 mov ax, 0x32
  IMUL16(M16(SS, (u16)(R.bp + 0xff82)));                       // 0d24 imul word ptr [bp - 0x7e]
  R.bx = (u16)(R.ax);                                          // 0d27 mov bx, ax
  SUB16(M16(DS, (u16)(R.bx + 0x17b2)), 0x60);                  // 0d29 cmp word ptr [bx + 0x17b2], 0x60
  if (!R.zf) goto L_0d35;                                      // 0d2e jne 0xd35
  W16(SS, (u16)(R.bp + 0xff8c), 0xffff);                       // 0d30 mov word ptr [bp - 0x74], 0xffff
L_0d35:   R.ax = (u16)(M16(DS, (u16)(0x4fc2)));                        // 0d35 mov ax, word ptr [0x4fc2]
  W16(SS, (u16)(R.bp + 0xff8c), ADD16(M16(SS, (u16)(R.bp + 0xff8c)), R.ax)); // 0d38 add word ptr [bp - 0x74], ax
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0d3b mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0d3e shl si, 1
  R.si = (u16)(ADD16(R.si, 0x61fe));                           // 0d40 add si, 0x61fe
  W16(DS, (u16)(R.si), 0x7c);                                  // 0d44 mov word ptr [si], 0x7c
  SUB16(M16(SS, (u16)(R.bp + 0xff8c)), 0x0);                   // 0d48 cmp word ptr [bp - 0x74], 0
  if (R.zf || R.sf != R.of) goto L_0d52;                       // 0d4c jle 0xd52
  W16(DS, (u16)(R.si), 0x7e);                                  // 0d4e mov word ptr [si], 0x7e
L_0d52:   SUB16(M16(SS, (u16)(R.bp + 0xff8c)), 0x0);                   // 0d52 cmp word ptr [bp - 0x74], 0
  if (R.sf == R.of) goto L_0d63;                               // 0d56 jge 0xd63
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0d58 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0d5b shl bx, 1
  W16(DS, (u16)(R.bx + 0x61fe), 0x7d);                         // 0d5d mov word ptr [bx + 0x61fe], 0x7d
L_0d63:   SUB16(M16(DS, (u16)(0x4fc8)), 0x0);                          // 0d63 cmp word ptr [0x4fc8], 0
  if (R.zf) goto L_0d78;                                       // 0d68 je 0xd78
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0d6a mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0d6d shl bx, 1
  W16(DS, (u16)(R.bx + 0x61fe), 0x26);                         // 0d6f mov word ptr [bx + 0x61fe], 0x26
  goto L_0d82;                                                 // 0d75 jmp 0xd82
L_0d78:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0d78 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0d7b shl si, 1
  W16(SS, (u16)(R.bp + R.si + 0xffaa), 0x2);                   // 0d7d mov word ptr [bp + si - 0x56], 2
L_0d82:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0d82 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0d85 shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x4db8)), 0x4);                   // 0d87 cmp word ptr [si + 0x4db8], 4
  if (R.sf == R.of) goto L_0dbb;                               // 0d8c jge 0xdbb
  R.ax = (u16)(M16(DS, (u16)(0x1e62)));                        // 0d8e mov ax, word ptr [0x1e62]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 0d91 cdq
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 0d92 sub ax, dx
  R.ax = (u16)(SAR16(R.ax, 0x1));                              // 0d94 sar ax, 1
  R.bx = (u16)(R.ax);                                          // 0d96 mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0d98 shl bx, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfff8)));                 // 0d9a mov ax, word ptr [bp - 8]
  SETL(R.cx, 0x4);                                             // 0d9d mov cl, 4
  R.ax = (u16)(SAR16(R.ax, (u8)R.cx));                         // 0d9f sar ax, cl
  AND16(M16(DS, (u16)(R.bx + 0x1e64)), R.ax);                  // 0da1 test word ptr [bx + 0x1e64], ax
  if (R.zf) goto L_0dc8;                                       // 0da5 je 0xdc8
  SUB16(M16(DS, (u16)(R.si + 0x4fc4)), 0xa0);                  // 0da7 cmp word ptr [si + 0x4fc4], 0xa0
  if (R.sf == R.of) goto L_0db4;                               // 0dad jge 0xdb4
  R.ax = (u16)(0x8);                                           // 0daf mov ax, 8
  goto L_0db7;                                                 // 0db2 jmp 0xdb7
L_0db4:   R.ax = (u16)(0xc);                                           // 0db4 mov ax, 0xc
L_0db7:   W16(DS, (u16)(R.si + 0x61fe), R.ax);                         // 0db7 mov word ptr [si + 0x61fe], ax
L_0dbb:   W16(SS, (u16)(R.bp + 0xff98), 0xffff);                       // 0dbb mov word ptr [bp - 0x68], 0xffff
  W16(SS, (u16)(R.bp + 0xff96), 0x0);                          // 0dc0 mov word ptr [bp - 0x6a], 0
  goto L_0ddf;                                                 // 0dc5 jmp 0xddf
L_0dc8:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0dc8 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0dcb shl si, 1
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x61f0)));                 // 0dcd mov ax, word ptr [si + 0x61f0]
  W16(SS, (u16)(R.bp + R.si + 0xff92), R.ax);                  // 0dd1 mov word ptr [bp + si - 0x6e], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x61fe)));                 // 0dd4 mov ax, word ptr [si + 0x61fe]
  goto L_0f31;                                                 // 0dd8 jmp 0xf31
L_0ddc:   W16(SS, (u16)(R.bp + 0xff96), INC16(M16(SS, (u16)(R.bp + 0xff96)))); // 0ddc inc word ptr [bp - 0x6a]
L_0ddf:   SUB16(M16(SS, (u16)(R.bp + 0xff96)), 0x9);                   // 0ddf cmp word ptr [bp - 0x6a], 9
  if (R.sf == R.of) goto L_0e3e;                               // 0de3 jge 0xe3e
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0de5 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0de8 shl si, 1
  R.ax = (u16)(0x18);                                          // 0dea mov ax, 0x18
  IMUL16(M16(DS, (u16)(R.si + 0x61f0)));                       // 0ded imul word ptr [si + 0x61f0]
  R.di = (u16)(R.ax);                                          // 0df1 mov di, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff96)));                 // 0df3 mov bx, word ptr [bp - 0x6a]
  SETL(R.ax, M8(DS, (u16)(R.bx + R.di + 0xa9b)));              // 0df6 mov al, byte ptr [bx + di + 0xa9b]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0dfa cwde
  SUB16(R.ax, M16(DS, (u16)(R.si + 0x61fe)));                  // 0dfb cmp ax, word ptr [si + 0x61fe]
  if (!R.zf) goto L_0e06;                                      // 0dff jne 0xe06
  R.ax = (u16)(R.bx);                                          // 0e01 mov ax, bx
  W16(SS, (u16)(R.bp + 0xff98), R.ax);                         // 0e03 mov word ptr [bp - 0x68], ax
L_0e06:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0e06 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0e09 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 0e0b mov si, word ptr [bx + 0x61f0]
  R.ax = (u16)(0x18);                                          // 0e0f mov ax, 0x18
  IMUL16(R.si);                                                // 0e12 imul si
  R.di = (u16)(R.ax);                                          // 0e14 mov di, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff96)));                 // 0e16 mov bx, word ptr [bp - 0x6a]
  SETL(R.ax, M8(DS, (u16)(R.bx + R.di + 0xa9b)));              // 0e19 mov al, byte ptr [bx + di + 0xa9b]
  W8(SS, (u16)(R.bp + 0xff76), (u8)R.ax);                      // 0e1d mov byte ptr [bp - 0x8a], al
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0e21 cwde
  R.cx = (u16)((u16)(R.si + 0x1));                             // 0e22 lea cx, [si + 1]
  SUB16(R.ax, R.cx);                                           // 0e25 cmp ax, cx
  if (R.zf) goto L_0e30;                                       // 0e27 je 0xe30
  SUB8(M8(SS, (u16)(R.bp + 0xff76)), 0xfe);                    // 0e29 cmp byte ptr [bp - 0x8a], 0xfe
  if (!R.zf) goto L_0ddc;                                      // 0e2e jne 0xddc
L_0e30:   SUB16(M16(SS, (u16)(R.bp + 0xff98)), 0xffff);                // 0e30 cmp word ptr [bp - 0x68], -1
  if (!R.zf) goto L_0ddc;                                      // 0e34 jne 0xddc
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff96)));                 // 0e36 mov ax, word ptr [bp - 0x6a]
  W16(SS, (u16)(R.bp + 0xff98), R.ax);                         // 0e39 mov word ptr [bp - 0x68], ax
  goto L_0ddc;                                                 // 0e3c jmp 0xddc
L_0e3e:   SUB16(M16(SS, (u16)(R.bp + 0xff98)), 0xffff);                // 0e3e cmp word ptr [bp - 0x68], -1
  if (!R.zf) goto L_0e49;                                      // 0e42 jne 0xe49
  W16(SS, (u16)(R.bp + 0xff98), 0x4);                          // 0e44 mov word ptr [bp - 0x68], 4
L_0e49:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0e49 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0e4c shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61fe)));                 // 0e4e mov si, word ptr [bx + 0x61fe]
  SUB16(R.si, 0x8);                                            // 0e52 cmp si, 8
  if (R.sf != R.of) goto L_0e64;                               // 0e55 jl 0xe64
  SUB16(R.si, 0x3e);                                           // 0e57 cmp si, 0x3e
  if (R.sf == R.of) goto L_0e64;                               // 0e5a jge 0xe64
  W16(SS, (u16)(R.bp + 0xffa8), 0x0);                          // 0e5c mov word ptr [bp - 0x58], 0
  goto L_0e69;                                                 // 0e61 jmp 0xe69
L_0e64:   W16(SS, (u16)(R.bp + 0xffa8), 0x1);                          // 0e64 mov word ptr [bp - 0x58], 1
L_0e69:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0e69 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0e6c shl si, 1
  R.si = (u16)(ADD16(R.si, R.bp));                             // 0e6e add si, bp
  R.si = (u16)(SUB16(R.si, 0x56));                             // 0e70 sub si, 0x56
  W16(DS, (u16)(R.si), 0x0);                                   // 0e73 mov word ptr [si], 0
  SUB16(M16(SS, (u16)(R.bp + 0xffa8)), 0x0);                   // 0e77 cmp word ptr [bp - 0x58], 0
  if (R.zf) goto L_0e81;                                       // 0e7b je 0xe81
  W16(DS, (u16)(R.si), 0x1);                                   // 0e7d mov word ptr [si], 1
L_0e81:   SUB16(M16(SS, (u16)(R.bp + 0xffa0)), 0x0);                   // 0e81 cmp word ptr [bp - 0x60], 0
  if (R.zf) goto L_0e91;                                       // 0e85 je 0xe91
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0e87 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0e8a shl si, 1
  W16(SS, (u16)(R.bp + R.si + 0xffaa), 0x2);                   // 0e8c mov word ptr [bp + si - 0x56], 2
L_0e91:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0e91 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0e94 shl si, 1
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x61f0)));                 // 0e96 mov ax, word ptr [si + 0x61f0]
  W16(SS, (u16)(R.bp + R.si + 0xff92), R.ax);                  // 0e9a mov word ptr [bp + si - 0x6e], ax
  R.ax = (u16)(0x18);                                          // 0e9d mov ax, 0x18
  IMUL16(M16(DS, (u16)(R.si + 0x61f0)));                       // 0ea0 imul word ptr [si + 0x61f0]
  R.di = (u16)(R.ax);                                          // 0ea4 mov di, ax
  SUB8(M8(DS, (u16)(R.di + 0xa9a)), 0xff);                     // 0ea6 cmp byte ptr [di + 0xa9a], 0xff
  if (!R.zf) goto L_0ebc;                                      // 0eab jne 0xebc
L_0ead:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff98)));                 // 0ead mov bx, word ptr [bp - 0x68]
  SETL(R.ax, M8(DS, (u16)(R.bx + R.di + 0xa9b)));              // 0eb0 mov al, byte ptr [bx + di + 0xa9b]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0eb4 cwde
  W16(DS, (u16)(R.si + 0x61f0), R.ax);                         // 0eb5 mov word ptr [si + 0x61f0], ax
  goto L_0f0e;                                                 // 0eb9 jmp 0xf0e
L_0ebc:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0ebc mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0ebf shl si, 1
  R.ax = (u16)(0x18);                                          // 0ec1 mov ax, 0x18
  IMUL16(M16(DS, (u16)(R.si + 0x61f0)));                       // 0ec4 imul word ptr [si + 0x61f0]
  R.di = (u16)(R.ax);                                          // 0ec8 mov di, ax
  SUB8(M8(DS, (u16)(R.di + 0xa9a)), 0x0);                      // 0eca cmp byte ptr [di + 0xa9a], 0
  if (R.sf == R.of) goto L_0ed6;                               // 0ecf jge 0xed6
  R.ax = (u16)(0x1);                                           // 0ed1 mov ax, 1
  goto L_0ed8;                                                 // 0ed4 jmp 0xed8
L_0ed6:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0ed6 sub ax, ax
L_0ed8:   W16(SS, (u16)(R.bp + 0xff76), R.ax);                         // 0ed8 mov word ptr [bp - 0x8a], ax
  SUB16(M16(SS, (u16)(R.bp + R.si + 0xffaa)), 0x1);            // 0edc cmp word ptr [bp + si - 0x56], 1
  if (!R.zf) goto L_0ee8;                                      // 0ee0 jne 0xee8
  R.ax = (u16)(0x1);                                           // 0ee2 mov ax, 1
  goto L_0eea;                                                 // 0ee5 jmp 0xeea
L_0ee8:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0ee8 sub ax, ax
L_0eea:   SUB16(R.ax, M16(SS, (u16)(R.bp + 0xff76)));                  // 0eea cmp ax, word ptr [bp - 0x8a]
  if (!R.zf) goto L_0ead;                                      // 0eee jne 0xead
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0ef0 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0ef3 shl si, 1
  R.si = (u16)(ADD16(R.si, 0x61f0));                           // 0ef5 add si, 0x61f0
  R.ax = (u16)(0x18);                                          // 0ef9 mov ax, 0x18
  IMUL16(M16(DS, (u16)(R.si)));                                // 0efc imul word ptr [si]
  R.bx = (u16)(R.ax);                                          // 0efe mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xa9a)));                     // 0f00 mov al, byte ptr [bx + 0xa9a]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0f04 cwde
  PUSH(R.ax);                                                  // 0f05 push ax
  PUSH(0x0f09); a_1000_50d8();                                 // 0f06 call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0f09 add sp, 2
  W16(DS, (u16)(R.si), R.ax);                                  // 0f0c mov word ptr [si], ax
L_0f0e:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f0e mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0f11 shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0xfffe);                // 0f13 cmp word ptr [si + 0x61f0], -2
  if (!R.zf) goto L_0f22;                                      // 0f18 jne 0xf22
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xff92)));          // 0f1a mov ax, word ptr [bp + si - 0x6e]
  R.ax = (u16)(INC16(R.ax));                                   // 0f1d inc ax
  W16(DS, (u16)(R.si + 0x61f0), R.ax);                         // 0f1e mov word ptr [si + 0x61f0], ax
L_0f22:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f22 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0f25 shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0xfffd);                // 0f27 cmp word ptr [si + 0x61f0], -3
  if (!R.zf) goto L_0f35;                                      // 0f2c jne 0xf35
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xff92)));          // 0f2e mov ax, word ptr [bp + si - 0x6e]
L_0f31:   W16(DS, (u16)(R.si + 0x61f0), R.ax);                         // 0f31 mov word ptr [si + 0x61f0], ax
L_0f35:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f35 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0f38 shl si, 1
  SUB16(M16(SS, (u16)(R.bp + R.si + 0xffaa)), 0x2);            // 0f3a cmp word ptr [bp + si - 0x56], 2
  if (!R.zf) goto L_0f8d;                                      // 0f3e jne 0xf8d
  SUB16(M16(SS, (u16)(R.bp + 0xff9e)), 0x0);                   // 0f40 cmp word ptr [bp - 0x62], 0
  if (!R.zf) goto L_0f8d;                                      // 0f44 jne 0xf8d
  SUB16(M16(DS, (u16)(0x4a74)), 0x0);                          // 0f46 cmp word ptr [0x4a74], 0
  if (!R.zf) goto L_0f8d;                                      // 0f4b jne 0xf8d
  SUB16(M16(DS, (u16)(R.si + 0x4db8)), 0x4);                   // 0f4d cmp word ptr [si + 0x4db8], 4
  if (R.sf == R.of) goto L_0f8d;                               // 0f52 jge 0xf8d
  SUB16(M16(SS, (u16)(R.bp + 0xff88)), 0x0);                   // 0f54 cmp word ptr [bp - 0x78], 0
  if (R.sf == R.of) goto L_0f60;                               // 0f58 jge 0xf60
  W16(DS, (u16)(R.si + 0x61f0), 0x7d);                         // 0f5a mov word ptr [si + 0x61f0], 0x7d
L_0f60:   SUB16(M16(SS, (u16)(R.bp + 0xff88)), 0x0);                   // 0f60 cmp word ptr [bp - 0x78], 0
  if (!R.zf) goto L_0f71;                                      // 0f64 jne 0xf71
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f66 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0f69 shl bx, 1
  W16(DS, (u16)(R.bx + 0x61f0), 0x7c);                         // 0f6b mov word ptr [bx + 0x61f0], 0x7c
L_0f71:   SUB16(M16(SS, (u16)(R.bp + 0xff88)), 0x0);                   // 0f71 cmp word ptr [bp - 0x78], 0
  if (R.zf || R.sf != R.of) goto L_0f82;                       // 0f75 jle 0xf82
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f77 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0f7a shl bx, 1
  W16(DS, (u16)(R.bx + 0x61f0), 0x7e);                         // 0f7c mov word ptr [bx + 0x61f0], 0x7e
L_0f82:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f82 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0f85 shl si, 1
  W16(SS, (u16)(R.bp + R.si + 0xff7c), 0x0);                   // 0f87 mov word ptr [bp + si - 0x84], 0
L_0f8d:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0f8d mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0f90 shl si, 1
  SUB16(M16(SS, (u16)(R.bp + R.si + 0xffaa)), 0x2);            // 0f92 cmp word ptr [bp + si - 0x56], 2
  if (R.zf) goto L_0fa3;                                       // 0f96 je 0xfa3
  SUB16(M16(SS, (u16)(R.bp + 0xff9e)), 0x0);                   // 0f98 cmp word ptr [bp - 0x62], 0
  if (!R.zf) goto L_0fa3;                                      // 0f9c jne 0xfa3
  W16(SS, (u16)(R.bp + 0xfffa), 0x0);                          // 0f9e mov word ptr [bp - 6], 0
L_0fa3:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0fa3 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0fa6 shl si, 1
  SUB16(M16(SS, (u16)(R.bp + R.si + 0xff7c)), 0x0);            // 0fa8 cmp word ptr [bp + si - 0x84], 0
  if (R.zf || R.sf != R.of) goto L_0fbc;                       // 0fad jle 0xfbc
  W16(SS, (u16)(R.bp + R.si + 0xff7c), DEC16(M16(SS, (u16)(R.bp + R.si + 0xff7c)))); // 0faf dec word ptr [bp + si - 0x84]
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xff92)));          // 0fb3 mov ax, word ptr [bp + si - 0x6e]
  W16(DS, (u16)(R.si + 0x61f0), R.ax);                         // 0fb6 mov word ptr [si + 0x61f0], ax
  goto L_1019;                                                 // 0fba jmp 0x1019
L_0fbc:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 0fbc mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0fbf shl si, 1
  R.ax = (u16)(0x18);                                          // 0fc1 mov ax, 0x18
  IMUL16(M16(DS, (u16)(R.si + 0x61f0)));                       // 0fc4 imul word ptr [si + 0x61f0]
  R.bx = (u16)(R.ax);                                          // 0fc8 mov bx, ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xa90)));                  // 0fca mov ax, word ptr [bx + 0xa90]
  W16(SS, (u16)(R.bp + R.si + 0xff7c), ADD16(M16(SS, (u16)(R.bp + R.si + 0xff7c)), R.ax)); // 0fce add word ptr [bp + si - 0x84], ax
  SUB16(M16(SS, (u16)(R.bp + 0xff9e)), 0x0);                   // 0fd2 cmp word ptr [bp - 0x62], 0
  if (R.zf) goto L_1019;                                       // 0fd6 je 0x1019
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x43);                  // 0fd8 cmp word ptr [si + 0x61f0], 0x43
  if (R.zf) goto L_0ffb;                                       // 0fdd je 0xffb
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x4f);                  // 0fdf cmp word ptr [si + 0x61f0], 0x4f
  if (R.zf) goto L_0ffb;                                       // 0fe4 je 0xffb
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x5a);                  // 0fe6 cmp word ptr [si + 0x61f0], 0x5a
  if (R.zf) goto L_0ffb;                                       // 0feb je 0xffb
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x6d);                  // 0fed cmp word ptr [si + 0x61f0], 0x6d
  if (R.zf) goto L_0ffb;                                       // 0ff2 je 0xffb
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x72);                  // 0ff4 cmp word ptr [si + 0x61f0], 0x72
  if (!R.zf) goto L_1019;                                      // 0ff9 jne 0x1019
L_0ffb:   R.ax = (u16)(0x7);                                           // 0ffb mov ax, 7
  PUSH(R.ax);                                                  // 0ffe push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0fff sub ax, ax
  PUSH(R.ax);                                                  // 1001 push ax
  R.ax = (u16)(0x5);                                           // 1002 mov ax, 5
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(0x1e62))));           // 1005 sub ax, word ptr [0x1e62]
  PUSH(R.ax);                                                  // 1009 push ax
  PUSH(0x100d); a_1000_2069();                                 // 100a call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 100d add sp, 6
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1010 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 1013 shl si, 1
  W16(SS, (u16)(R.bp + R.si + 0xff7c), ADD16(M16(SS, (u16)(R.bp + R.si + 0xff7c)), R.ax)); // 1015 add word ptr [bp + si - 0x84], ax
L_1019:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1019 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 101c shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x4db8)), 0x4);                   // 101e cmp word ptr [si + 0x4db8], 4
  if (R.sf == R.of) goto L_1028;                               // 1023 jge 0x1028
  goto L_10e0;                                                 // 1025 jmp 0x10e0
L_1028:   R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xff92)));          // 1028 mov ax, word ptr [bp + si - 0x6e]
  R.ax = (u16)(INC16(R.ax));                                   // 102b inc ax
  W16(DS, (u16)(R.si + 0x61f0), R.ax);                         // 102c mov word ptr [si + 0x61f0], ax
L_1030:   W16(SS, (u16)(R.bp + 0xff9e), INC16(M16(SS, (u16)(R.bp + 0xff9e)))); // 1030 inc word ptr [bp - 0x62]
L_1033:   SUB16(M16(SS, (u16)(R.bp + 0xff9e)), 0x2);                   // 1033 cmp word ptr [bp - 0x62], 2
  if (R.sf != R.of) goto L_103c;                               // 1037 jl 0x103c
  goto L_1514;                                                 // 1039 jmp 0x1514
L_103c:   R.ax = (u16)(0x1);                                           // 103c mov ax, 1
  W16(SS, (u16)(R.bp + 0xfffa), R.ax);                         // 103f mov word ptr [bp - 6], ax
  W16(SS, (u16)(R.bp + 0xffa4), R.ax);                         // 1042 mov word ptr [bp - 0x5c], ax
  SUB16(M16(SS, (u16)(R.bp + 0xffa2)), 0x0);                   // 1045 cmp word ptr [bp - 0x5e], 0
  if (!R.zf) goto L_1030;                                      // 1049 jne 0x1030
  SUB16(M16(SS, (u16)(R.bp + 0xff9e)), 0x0);                   // 104b cmp word ptr [bp - 0x62], 0
  if (R.zf) goto L_1054;                                       // 104f je 0x1054
  goto L_0b08;                                                 // 1051 jmp 0xb08
L_1054:   SUB16(M16(DS, (u16)(0x4a74)), 0x0);                          // 1054 cmp word ptr [0x4a74], 0
  if (R.zf) goto L_105e;                                       // 1059 je 0x105e
  goto L_0b08;                                                 // 105b jmp 0xb08
L_105e:   SUB16(M16(DS, (u16)(0x61ee)), 0x0);                          // 105e cmp word ptr [0x61ee], 0
  if (!R.zf) goto L_1068;                                      // 1063 jne 0x1068
  goto L_0a3e;                                                 // 1065 jmp 0xa3e
L_1068:   R.ax = (u16)((u16)(R.bp + 0xff84));                          // 1068 lea ax, [bp - 0x7c]
  PUSH(R.ax);                                                  // 106b push ax
  R.ax = (u16)((u16)(R.bp + 0xff88));                          // 106c lea ax, [bp - 0x78]
  PUSH(R.ax);                                                  // 106f push ax
  PUSH(0x1073); a_1000_1e20();                                 // 1070 call 0x1e20
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1073 add sp, 4
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 1076 sub ax, ax
  PUSH(R.ax);                                                  // 1078 push ax
  PUSH(0x107c); a_1000_1e40();                                 // 1079 call 0x1e40
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 107c add sp, 2
  W16(SS, (u16)(R.bp + 0xffa8), R.ax);                         // 107f mov word ptr [bp - 0x58], ax
  R.ax = (u16)(0x1);                                           // 1082 mov ax, 1
  PUSH(R.ax);                                                  // 1085 push ax
  PUSH(0x1089); a_1000_1e40();                                 // 1086 call 0x1e40
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1089 add sp, 2
  W16(SS, (u16)(R.bp + 0xffa0), R.ax);                         // 108c mov word ptr [bp - 0x60], ax
  PUSH(M16(SS, (u16)(R.bp + 0xff88)));                         // 108f push word ptr [bp - 0x78]
  PUSH(0x1095); a_1000_50d8();                                 // 1092 call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1095 add sp, 2
  SUB16(R.ax, 0x50);                                           // 1098 cmp ax, 0x50
  if (!R.zf && R.sf == R.of) goto L_10a8;                      // 109b jg 0x10a8
  SETL(R.ax, du_kbd_poll(0x109d));                           // 109d mov al, byte ptr [0x22f2]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 10a0 sub ah, ah
  R.ax = (u16)(SUB16(R.ax, 0x80));                             // 10a2 sub ax, 0x80
  W16(SS, (u16)(R.bp + 0xff88), R.ax);                         // 10a5 mov word ptr [bp - 0x78], ax
L_10a8:   PUSH(M16(SS, (u16)(R.bp + 0xff84)));                         // 10a8 push word ptr [bp - 0x7c]
  PUSH(0x10ae); a_1000_50d8();                                 // 10ab call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 10ae add sp, 2
  SUB16(R.ax, 0x40);                                           // 10b1 cmp ax, 0x40
  if (!R.zf && R.sf == R.of) goto L_10c1;                      // 10b4 jg 0x10c1
  SETL(R.ax, M8(DS, (u16)(0x22f3)));                           // 10b6 mov al, byte ptr [0x22f3]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 10b9 sub ah, ah
  R.ax = (u16)(SUB16(R.ax, 0x80));                             // 10bb sub ax, 0x80
  W16(SS, (u16)(R.bp + 0xff84), R.ax);                         // 10be mov word ptr [bp - 0x7c], ax
L_10c1:   SUB16(M16(SS, (u16)(R.bp + 0xffa8)), 0x0);                   // 10c1 cmp word ptr [bp - 0x58], 0
  if (!R.zf) goto L_10cf;                                      // 10c5 jne 0x10cf
  SETL(R.ax, M8(DS, (u16)(0x22f4)));                           // 10c7 mov al, byte ptr [0x22f4]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 10ca sub ah, ah
  W16(SS, (u16)(R.bp + 0xffa8), R.ax);                         // 10cc mov word ptr [bp - 0x58], ax
L_10cf:   SUB16(M16(SS, (u16)(R.bp + 0xffa0)), 0x0);                   // 10cf cmp word ptr [bp - 0x60], 0
  if (R.zf) goto L_10d8;                                       // 10d3 je 0x10d8
  goto L_0a62;                                                 // 10d5 jmp 0xa62
L_10d8:   SETL(R.ax, M8(DS, (u16)(0x22f5)));                           // 10d8 mov al, byte ptr [0x22f5]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 10db sub ah, ah
  goto L_0a5f;                                                 // 10dd jmp 0xa5f
L_10e0:   W16(SS, (u16)(R.bp + 0xff8c), 0x63);                         // 10e0 mov word ptr [bp - 0x74], 0x63
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 10e5 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 10e8 shl si, 1
  SUB16(M16(SS, (u16)(R.bp + R.si + 0xffaa)), 0x2);            // 10ea cmp word ptr [bp + si - 0x56], 2
  if (!R.zf) goto L_112d;                                      // 10ee jne 0x112d
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x7c);                  // 10f0 cmp word ptr [si + 0x61f0], 0x7c
  if (!R.zf) goto L_1101;                                      // 10f5 jne 0x1101
  W16(SS, (u16)(R.bp + 0xff8c), 0x0);                          // 10f7 mov word ptr [bp - 0x74], 0
  W16(SS, (u16)(R.bp + 0xfffe), 0x76);                         // 10fc mov word ptr [bp - 2], 0x76
L_1101:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1101 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1104 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x61f0)), 0x7d);                  // 1106 cmp word ptr [bx + 0x61f0], 0x7d
  if (R.sf != R.of) goto L_1117;                               // 110b jl 0x1117
  W16(SS, (u16)(R.bp + 0xff8c), 0xffff);                       // 110d mov word ptr [bp - 0x74], 0xffff
  W16(SS, (u16)(R.bp + 0xfffe), 0x78);                         // 1112 mov word ptr [bp - 2], 0x78
L_1117:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1117 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 111a shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x61f0)), 0x7e);                  // 111c cmp word ptr [bx + 0x61f0], 0x7e
  if (R.sf != R.of) goto L_112d;                               // 1121 jl 0x112d
  W16(SS, (u16)(R.bp + 0xff8c), 0x1);                          // 1123 mov word ptr [bp - 0x74], 1
  W16(SS, (u16)(R.bp + 0xfffe), 0x7a);                         // 1128 mov word ptr [bp - 2], 0x7a
L_112d:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 112d mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 1130 shl si, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si + 0xff92)));          // 1132 mov ax, word ptr [bp + si - 0x6e]
  R.ax = (u16)(INC16(R.ax));                                   // 1135 inc ax
  SUB16(R.ax, M16(DS, (u16)(R.si + 0x61f0)));                  // 1136 cmp ax, word ptr [si + 0x61f0]
  if (!R.zf) goto L_116d;                                      // 113a jne 0x116d
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x43);                  // 113c cmp word ptr [si + 0x61f0], 0x43
  if (!R.zf) goto L_1149;                                      // 1141 jne 0x1149
  W16(DS, (u16)(R.si + 0x4fc8), 0x1);                          // 1143 mov word ptr [si + 0x4fc8], 1
L_1149:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1149 mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 114c shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x5a);                  // 114e cmp word ptr [si + 0x61f0], 0x5a
  if (!R.zf) goto L_115b;                                      // 1153 jne 0x115b
  W16(DS, (u16)(R.si + 0x4fc8), 0x1);                          // 1155 mov word ptr [si + 0x4fc8], 1
L_115b:   R.si = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 115b mov si, word ptr [bp - 0x62]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 115e shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x61f0)), 0x4f);                  // 1160 cmp word ptr [si + 0x61f0], 0x4f
  if (!R.zf) goto L_116d;                                      // 1165 jne 0x116d
  W16(DS, (u16)(R.si + 0x4fc8), 0x1);                          // 1167 mov word ptr [si + 0x4fc8], 1
L_116d:   R.ax = (u16)(M16(DS, (u16)(0x4fc2)));                        // 116d mov ax, word ptr [0x4fc2]
  W16(SS, (u16)(R.bp + 0xff8c), SUB16(M16(SS, (u16)(R.bp + 0xff8c)), R.ax)); // 1170 sub word ptr [bp - 0x74], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1173 mov bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1176 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 1178 mov si, word ptr [bx + 0x61f0]
  SUB16(R.si, 0x45);                                           // 117c cmp si, 0x45
  if (R.zf) goto L_1195;                                       // 117f je 0x1195
  SUB16(R.si, 0x51);                                           // 1181 cmp si, 0x51
  if (R.zf) goto L_1195;                                       // 1184 je 0x1195
  SUB16(R.si, 0x5c);                                           // 1186 cmp si, 0x5c
  if (R.zf) goto L_1195;                                       // 1189 je 0x1195
  SUB16(R.si, 0x6e);                                           // 118b cmp si, 0x6e
  if (R.zf) goto L_1195;                                       // 118e je 0x1195
  SUB16(R.si, 0x73);                                           // 1190 cmp si, 0x73
  if (!R.zf) goto L_119f;                                      // 1193 jne 0x119f
L_1195:   R.ax = (u16)(0x1c);                                          // 1195 mov ax, 0x1c
  PUSH(R.ax);                                                  // 1198 push ax
  PUSH(0x119c); a_1000_02a0();                                 // 1199 call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 119c add sp, 2
L_119f:   R.bx = (u16)(0x1);                                           // 119f mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 11a2 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 11a5 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 11a7 mov ax, word ptr [bx + 0x61f0]
  R.ax = (u16)(SUB16(R.ax, 0x47));                             // 11ab sub ax, 0x47
  PUSH(R.ax);                                                  // 11ae push ax
  PUSH(0x11b2); a_1000_50d8();                                 // 11af call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 11b2 add sp, 2
  SUB16(R.ax, 0x1);                                            // 11b5 cmp ax, 1
  if (R.sf == R.of) goto L_1214;                               // 11b8 jge 0x1214
  PUSH(M16(SS, (u16)(R.bp + 0xff8c)));                         // 11ba push word ptr [bp - 0x74]
  PUSH(0x11c0); a_1000_50d8();                                 // 11bd call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 11c0 add sp, 2
  SUB16(R.ax, 0x1);                                            // 11c3 cmp ax, 1
  if (R.sf == R.of) goto L_1214;                               // 11c6 jge 0x1214
  R.ax = (u16)(0x1);                                           // 11c8 mov ax, 1
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xff9e))));    // 11cb sub ax, word ptr [bp - 0x62]
  R.si = (u16)(R.ax);                                          // 11ce mov si, ax
  R.si = (u16)(SHL16(R.si, 0x1));                              // 11d0 shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x4fc8)), 0x0);                   // 11d2 cmp word ptr [si + 0x4fc8], 0
  if (!R.zf) goto L_1214;                                      // 11d7 jne 0x1214
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 11d9 mov di, word ptr [bp - 0x62]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 11dc shl di, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 11de mov ax, word ptr [bp - 2]
  W16(DS, (u16)(R.di + 0x61f0), R.ax);                         // 11e1 mov word ptr [di + 0x61f0], ax
  W16(DS, (u16)(R.si + 0x4fc8), 0x0);                          // 11e5 mov word ptr [si + 0x4fc8], 0
  SUB16(M16(SS, (u16)(R.bp + 0xfffa)), 0x0);                   // 11eb cmp word ptr [bp - 6], 0
  if (R.zf) goto L_124f;                                       // 11ef je 0x124f
  W16(DS, (u16)(R.si + 0x61f0), 0x48);                         // 11f1 mov word ptr [si + 0x61f0], 0x48
  W16(SS, (u16)(R.bp + R.si + 0xff7c), 0x4);                   // 11f7 mov word ptr [bp + si - 0x84], 4
  W16(SS, (u16)(R.bp + R.di + 0xff7c), 0x2);                   // 11fd mov word ptr [bp + di - 0x84], 2
  W16(SS, (u16)(R.bp + 0xffa2), 0x1);                          // 1203 mov word ptr [bp - 0x5e], 1
  PUSH(M16(SS, (u16)(R.bp + 0xff9e)));                         // 1208 push word ptr [bp - 0x62]
  PUSH(0x120e); a_1000_17aa();                                 // 120b call 0x17aa
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 120e add sp, 2
  goto L_124f;                                                 // 1211 jmp 0x124f
L_1214:   R.bx = (u16)(0x1);                                           // 1214 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 1217 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 121a shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x61f0)), 0x47);                  // 121c cmp word ptr [bx + 0x61f0], 0x47
  if (!R.zf) goto L_124f;                                      // 1221 jne 0x124f
  SUB16(M16(SS, (u16)(R.bp + 0xffae)), 0x0);                   // 1223 cmp word ptr [bp - 0x52], 0
  if (R.zf) goto L_1241;                                       // 1227 je 0x1241
  PUSH(M16(DS, (u16)(0x4fc2)));                                // 1229 push word ptr [0x4fc2]
  PUSH(0x1230); a_1000_50d8();                                 // 122d call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1230 add sp, 2
  SUB16(R.ax, 0x2);                                            // 1233 cmp ax, 2
  if (R.sf == R.of) goto L_1241;                               // 1236 jge 0x1241
  PUSH(M16(SS, (u16)(R.bp + 0xff9e)));                         // 1238 push word ptr [bp - 0x62]
  PUSH(0x123e); a_1000_1624();                                 // 123b call 0x1624
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 123e add sp, 2
L_1241:   R.bx = (u16)(0x1);                                           // 1241 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 1244 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1247 shl bx, 1
  W16(DS, (u16)(R.bx + 0x4fc8), 0x0);                          // 1249 mov word ptr [bx + 0x4fc8], 0
L_124f:   R.bx = (u16)(0x1);                                           // 124f mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 1252 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1255 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 1257 mov si, word ptr [bx + 0x61f0]
  SUB16(R.si, 0x53);                                           // 125b cmp si, 0x53
  if (R.zf) goto L_1265;                                       // 125e je 0x1265
  SUB16(R.si, 0x6f);                                           // 1260 cmp si, 0x6f
  if (!R.zf) goto L_12c0;                                      // 1263 jne 0x12c0
L_1265:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff8c)));                 // 1265 mov ax, word ptr [bp - 0x74]
  R.ax = (u16)(INC16(R.ax));                                   // 1268 inc ax
  PUSH(R.ax);                                                  // 1269 push ax
  PUSH(0x126d); a_1000_50d8();                                 // 126a call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 126d add sp, 2
  SUB16(R.ax, 0x1);                                            // 1270 cmp ax, 1
  if (R.sf == R.of) goto L_12c0;                               // 1273 jge 0x12c0
  R.ax = (u16)(0x1);                                           // 1275 mov ax, 1
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xff9e))));    // 1278 sub ax, word ptr [bp - 0x62]
  R.si = (u16)(R.ax);                                          // 127b mov si, ax
  R.si = (u16)(SHL16(R.si, 0x1));                              // 127d shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x4fc8)), 0x0);                   // 127f cmp word ptr [si + 0x4fc8], 0
  if (!R.zf) goto L_12c0;                                      // 1284 jne 0x12c0
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1286 mov di, word ptr [bp - 0x62]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 1289 shl di, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 128b mov ax, word ptr [bp - 2]
  W16(DS, (u16)(R.di + 0x61f0), R.ax);                         // 128e mov word ptr [di + 0x61f0], ax
  W16(DS, (u16)(R.si + 0x4fc8), 0x0);                          // 1292 mov word ptr [si + 0x4fc8], 0
  SUB16(M16(SS, (u16)(R.bp + 0xfffa)), 0x0);                   // 1298 cmp word ptr [bp - 6], 0
  if (R.zf) goto L_1301;                                       // 129c je 0x1301
  W16(DS, (u16)(R.si + 0x61f0), 0x54);                         // 129e mov word ptr [si + 0x61f0], 0x54
  W16(SS, (u16)(R.bp + R.si + 0xff7c), 0x4);                   // 12a4 mov word ptr [bp + si - 0x84], 4
  W16(SS, (u16)(R.bp + R.di + 0xff7c), 0x2);                   // 12aa mov word ptr [bp + di - 0x84], 2
  W16(SS, (u16)(R.bp + 0xffa2), 0x1);                          // 12b0 mov word ptr [bp - 0x5e], 1
  PUSH(M16(SS, (u16)(R.bp + 0xff9e)));                         // 12b5 push word ptr [bp - 0x62]
  PUSH(0x12bb); a_1000_17aa();                                 // 12b8 call 0x17aa
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 12bb add sp, 2
  goto L_1301;                                                 // 12be jmp 0x1301
L_12c0:   R.bx = (u16)(0x1);                                           // 12c0 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 12c3 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 12c6 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 12c8 mov si, word ptr [bx + 0x61f0]
  SUB16(R.si, 0x53);                                           // 12cc cmp si, 0x53
  if (R.zf) goto L_12d6;                                       // 12cf je 0x12d6
  SUB16(R.si, 0x6f);                                           // 12d1 cmp si, 0x6f
  if (!R.zf) goto L_1301;                                      // 12d4 jne 0x1301
L_12d6:   SUB16(M16(SS, (u16)(R.bp + 0xffae)), 0x0);                   // 12d6 cmp word ptr [bp - 0x52], 0
  if (R.zf) goto L_12f3;                                       // 12da je 0x12f3
  SUB16(M16(DS, (u16)(0x4fc2)), 0x0);                          // 12dc cmp word ptr [0x4fc2], 0
  if (R.sf != R.of) goto L_12f3;                               // 12e1 jl 0x12f3
  SUB16(M16(DS, (u16)(0x4fc2)), 0x2);                          // 12e3 cmp word ptr [0x4fc2], 2
  if (R.sf == R.of) goto L_12f3;                               // 12e8 jge 0x12f3
  PUSH(M16(SS, (u16)(R.bp + 0xff9e)));                         // 12ea push word ptr [bp - 0x62]
  PUSH(0x12f0); a_1000_1624();                                 // 12ed call 0x1624
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 12f0 add sp, 2
L_12f3:   R.bx = (u16)(0x1);                                           // 12f3 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 12f6 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 12f9 shl bx, 1
  W16(DS, (u16)(R.bx + 0x4fc8), 0x0);                          // 12fb mov word ptr [bx + 0x4fc8], 0
L_1301:   R.bx = (u16)(0x1);                                           // 1301 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 1304 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1307 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 1309 mov si, word ptr [bx + 0x61f0]
  SUB16(R.si, 0x5e);                                           // 130d cmp si, 0x5e
  if (R.zf) goto L_1317;                                       // 1310 je 0x1317
  SUB16(R.si, 0x74);                                           // 1312 cmp si, 0x74
  if (!R.zf) goto L_1372;                                      // 1315 jne 0x1372
L_1317:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xff8c)));                 // 1317 mov ax, word ptr [bp - 0x74]
  R.ax = (u16)(DEC16(R.ax));                                   // 131a dec ax
  PUSH(R.ax);                                                  // 131b push ax
  PUSH(0x131f); a_1000_50d8();                                 // 131c call 0x50d8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 131f add sp, 2
  SUB16(R.ax, 0x1);                                            // 1322 cmp ax, 1
  if (R.sf == R.of) goto L_1372;                               // 1325 jge 0x1372
  R.ax = (u16)(0x1);                                           // 1327 mov ax, 1
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xff9e))));    // 132a sub ax, word ptr [bp - 0x62]
  R.si = (u16)(R.ax);                                          // 132d mov si, ax
  R.si = (u16)(SHL16(R.si, 0x1));                              // 132f shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x4fc8)), 0x0);                   // 1331 cmp word ptr [si + 0x4fc8], 0
  if (!R.zf) goto L_1372;                                      // 1336 jne 0x1372
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xff9e)));                 // 1338 mov di, word ptr [bp - 0x62]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 133b shl di, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 133d mov ax, word ptr [bp - 2]
  W16(DS, (u16)(R.di + 0x61f0), R.ax);                         // 1340 mov word ptr [di + 0x61f0], ax
  W16(DS, (u16)(R.si + 0x4fc8), 0x0);                          // 1344 mov word ptr [si + 0x4fc8], 0
  SUB16(M16(SS, (u16)(R.bp + 0xfffa)), 0x0);                   // 134a cmp word ptr [bp - 6], 0
  if (R.zf) goto L_13b3;                                       // 134e je 0x13b3
  W16(DS, (u16)(R.si + 0x61f0), 0x5f);                         // 1350 mov word ptr [si + 0x61f0], 0x5f
  W16(SS, (u16)(R.bp + R.si + 0xff7c), 0x4);                   // 1356 mov word ptr [bp + si - 0x84], 4
  W16(SS, (u16)(R.bp + R.di + 0xff7c), 0x2);                   // 135c mov word ptr [bp + di - 0x84], 2
  W16(SS, (u16)(R.bp + 0xffa2), 0x1);                          // 1362 mov word ptr [bp - 0x5e], 1
  PUSH(M16(SS, (u16)(R.bp + 0xff9e)));                         // 1367 push word ptr [bp - 0x62]
  PUSH(0x136d); a_1000_17aa();                                 // 136a call 0x17aa
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 136d add sp, 2
  goto L_13b3;                                                 // 1370 jmp 0x13b3
L_1372:   R.bx = (u16)(0x1);                                           // 1372 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 1375 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1378 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x61f0)));                 // 137a mov si, word ptr [bx + 0x61f0]
  SUB16(R.si, 0x5e);                                           // 137e cmp si, 0x5e
  if (R.zf) goto L_1388;                                       // 1381 je 0x1388
  SUB16(R.si, 0x74);                                           // 1383 cmp si, 0x74
  if (!R.zf) goto L_13b3;                                      // 1386 jne 0x13b3
L_1388:   SUB16(M16(SS, (u16)(R.bp + 0xffae)), 0x0);                   // 1388 cmp word ptr [bp - 0x52], 0
  if (R.zf) goto L_13a5;                                       // 138c je 0x13a5
  SUB16(M16(DS, (u16)(0x4fc2)), 0x0);                          // 138e cmp word ptr [0x4fc2], 0
  if (!R.zf && R.sf == R.of) goto L_13a5;                      // 1393 jg 0x13a5
  SUB16(M16(DS, (u16)(0x4fc2)), 0xfffe);                       // 1395 cmp word ptr [0x4fc2], -2
  if (R.zf || R.sf != R.of) goto L_13a5;                       // 139a jle 0x13a5
  PUSH(M16(SS, (u16)(R.bp + 0xff9e)));                         // 139c push word ptr [bp - 0x62]
  PUSH(0x13a2); a_1000_1624();                                 // 139f call 0x1624
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 13a2 add sp, 2
L_13a5:   R.bx = (u16)(0x1);                                           // 13a5 mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0xff9e))));    // 13a8 sub bx, word ptr [bp - 0x62]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 13ab shl bx, 1
  W16(DS, (u16)(R.bx + 0x4fc8), 0x0);                          // 13ad mov word ptr [bx + 0x4fc8], 0
L_13b3:   W16(SS, (u16)(R.bp + 0xff90), 0xffff);                       // 13b3 mov word ptr [bp - 0x70], 0xffff
  PUSH(0x27cc); PUSH(0x13bd); du_driver(90);   /* driver slot 90 */ // 13b8 lcall 0x62a, 0x212e
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 13bd or ax, ax
  if (R.zf) goto L_13c4;                                       // 13bf je 0x13c4
  goto L_1030;                                                 // 13c1 jmp 0x1030
L_13c4:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 13c4 sub ax, ax
  PUSH(R.ax);                                                  // 13c6 push ax
  PUSH(0x13ca); a_1000_5126();                                 // 13c7 call 0x5126
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 13ca add sp, 2
  W16(SS, (u16)(R.bp + 0xff90), R.ax);                         // 13cd mov word ptr [bp - 0x70], ax
  SUB16(R.ax, 0x1000);                                         // 13d0 cmp ax, 0x1000
  if (!R.zf) goto L_13d8;                                      // 13d3 jne 0x13d8
  goto L_14ce;                                                 // 13d5 jmp 0x14ce
L_13d8:   SUB16(R.ax, 0x2400);                                         // 13d8 cmp ax, 0x2400
  if (!R.zf) goto L_13e0;                                      // 13db jne 0x13e0
  goto L_1502;                                                 // 13dd jmp 0x1502
L_13e0:   SUB16(R.ax, 0x2f00);                                         // 13e0 cmp ax, 0x2f00
  if (!R.zf) goto L_13e8;                                      // 13e3 jne 0x13e8
  goto L_14c8;                                                 // 13e5 jmp 0x14c8
L_13e8:   SUB16(R.ax, 0x3920);                                         // 13e8 cmp ax, 0x3920
  if (R.zf) goto L_13f0;                                       // 13eb je 0x13f0
  goto L_1030;                                                 // 13ed jmp 0x1030
L_13f0:   R.ax = (u16)(0x2);                                           // 13f0 mov ax, 2
  PUSH(R.ax);                                                  // 13f3 push ax
  PUSH(0x13f7); a_1000_02a0();                                 // 13f4 call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 13f7 add sp, 2
  R.ax = (u16)(0x2);                                           // 13fa mov ax, 2
  PUSH(R.ax);                                                  // 13fd push ax
  PUSH(0x27cc); PUSH(0x1403); du_driver(4);   /* driver slot 4 */ // 13fe lcall 0x62a, 0x1f80
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1403 add sp, 2
  R.ax = (u16)(0xf);                                           // 1406 mov ax, 0xf
  PUSH(R.ax);                                                  // 1409 push ax
  R.ax = (u16)(0x14);                                          // 140a mov ax, 0x14
  PUSH(R.ax);                                                  // 140d push ax
  R.ax = (u16)(0x78);                                          // 140e mov ax, 0x78
  PUSH(R.ax);                                                  // 1411 push ax
  R.ax = (u16)(0x5a);                                          // 1412 mov ax, 0x5a
  PUSH(R.ax);                                                  // 1415 push ax
  R.ax = (u16)(0x64);                                          // 1416 mov ax, 0x64
  PUSH(R.ax);                                                  // 1419 push ax
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 141a push word ptr [0x1f6a]
  PUSH(0x27cc); PUSH(0x1423); a_1533_045c();                   // 141e lcall 0x533, 0x45c
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 1423 add sp, 0xc
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 1426 mov bx, word ptr [0x1f6a]
  W16(DS, (u16)(R.bx + 0xe), 0xf);                             // 142a mov word ptr [bx + 0xe], 0xf
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 142f sub ax, ax
  PUSH(R.ax);                                                  // 1431 push ax
  R.ax = (u16)(0x60);                                          // 1432 mov ax, 0x60
  PUSH(R.ax);                                                  // 1435 push ax
  R.ax = (u16)(0x8c);                                          // 1436 mov ax, 0x8c
  PUSH(R.ax);                                                  // 1439 push ax
  R.ax = (u16)(0x1e2e);                                        // 143a mov ax, 0x1e2e
  PUSH(R.ax);                                                  // 143d push ax
  PUSH(0x1441); a_1000_1e90();                                 // 143e call 0x1e90
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 1441 add sp, 8
  PUSH(M16(DS, (u16)(0x1e5e)));                                // 1444 push word ptr [0x1e5e]
  PUSH(0x144b); a_1000_0338();                                 // 1448 call 0x338
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 144b add sp, 2
L_144e:   PUSH(0x1451); a_1000_48ba();                                 // 144e call 0x48ba
  SUB16(R.ax, 0x20);                                           // 1451 cmp ax, 0x20
  if (!R.zf) goto L_144e;                                      // 1454 jne 0x144e
  R.ax = (u16)(0x5a);                                          // 1456 mov ax, 0x5a
  PUSH(R.ax);                                                  // 1459 push ax
  R.ax = (u16)(0x64);                                          // 145a mov ax, 0x64
  PUSH(R.ax);                                                  // 145d push ax
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 145e push word ptr [0x1f6a]
  R.ax = (u16)(0x14);                                          // 1462 mov ax, 0x14
  PUSH(R.ax);                                                  // 1465 push ax
  R.ax = (u16)(0x78);                                          // 1466 mov ax, 0x78
  PUSH(R.ax);                                                  // 1469 push ax
  R.ax = (u16)(0x5a);                                          // 146a mov ax, 0x5a
  PUSH(R.ax);                                                  // 146d push ax
  R.ax = (u16)(0x64);                                          // 146e mov ax, 0x64
  PUSH(R.ax);                                                  // 1471 push ax
  PUSH(M16(DS, (u16)(0x1e48)));                                // 1472 push word ptr [0x1e48]
  PUSH(0x27cc); PUSH(0x147b); du_driver(18);   /* driver slot 18 */ // 1476 lcall 0x62a, 0x1fc6
  R.sp = (u16)(ADD16(R.sp, 0x10));                             // 147b add sp, 0x10
  R.ax = (u16)(0x3);                                           // 147e mov ax, 3
  PUSH(R.ax);                                                  // 1481 push ax
  PUSH(0x27cc); PUSH(0x1487); du_driver(4);   /* driver slot 4 */ // 1482 lcall 0x62a, 0x1f80
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1487 add sp, 2
  { u16 a_ = (u16)(0x6206); R.bx = (u16)(M16(DS, a_)); R.es = M16(DS, (u16)(a_ + 2)); } // 148a les bx, ptr [0x6206]
  SUB16(M16(ES, (u16)(R.bx + 0x310)), 0x0);                    // 148e cmp word ptr es:[bx + 0x310], 0
  if (R.zf) goto L_1499;                                       // 1494 je 0x1499
  goto L_1030;                                                 // 1496 jmp 0x1030
L_1499:   R.ax = (u16)(0x4e);                                          // 1499 mov ax, 0x4e
  PUSH(R.ax);                                                  // 149c push ax
  PUSH(0x14a0); a_1000_02a0();                                 // 149d call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14a0 add sp, 2
  R.ax = (u16)(0x4);                                           // 14a3 mov ax, 4
  PUSH(R.ax);                                                  // 14a6 push ax
  R.ax = (u16)(0x1);                                           // 14a7 mov ax, 1
  PUSH(R.ax);                                                  // 14aa push ax
  R.ax = (u16)(M16(DS, (u16)(0x4dba)));                        // 14ab mov ax, word ptr [0x4dba]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(0x4db8))));           // 14ae sub ax, word ptr [0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0x2));                              // 14b2 add ax, 2
  PUSH(R.ax);                                                  // 14b5 push ax
  PUSH(0x14b9); a_1000_2069();                                 // 14b6 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 14b9 add sp, 6
  PUSH(R.ax);                                                  // 14bc push ax
  PUSH(0x27cc); PUSH(0x14c2); du_driver(104);   /* driver slot 104 */ // 14bd lcall 0x62a, 0x2174
L_14c2:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14c2 add sp, 2
  goto L_1030;                                                 // 14c5 jmp 0x1030
L_14c8:   PUSH(0x14cb); a_1000_02cc();                                 // 14c8 call 0x2cc
  goto L_1030;                                                 // 14cb jmp 0x1030
L_14ce:   PUSH(0x27cc); PUSH(0x14d3); du_driver(106);   /* driver slot 106 */ // 14ce lcall 0x62a, 0x217e
  PUSH(0x27cc); PUSH(0x14d8); a_15e6_0066();                   // 14d3 lcall 0x5e6, 0x66
  PUSH(0x27cc); PUSH(0x14dd); a_1533_01ae();                   // 14d8 lcall 0x533, 0x1ae
  PUSH(0x14e0); a_1000_2548();                                 // 14dd call 0x2548
  W8(DS, (u16)(0x5153), 0x0);                                  // 14e0 mov byte ptr [0x5153], 0
  W8(DS, (u16)(0x5152), 0x3);                                  // 14e5 mov byte ptr [0x5152], 3
  R.ax = (u16)(0x5152);                                        // 14ea mov ax, 0x5152
  PUSH(R.ax);                                                  // 14ed push ax
  PUSH(R.ax);                                                  // 14ee push ax
  R.ax = (u16)(0x10);                                          // 14ef mov ax, 0x10
  PUSH(R.ax);                                                  // 14f2 push ax
  PUSH(0x14f6); a_1000_342d();                                 // 14f3 call 0x342d
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 14f6 add sp, 6
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 14f9 sub ax, ax
  PUSH(R.ax);                                                  // 14fb push ax
  CALL_BEGIN(4); du_exit((i16)ARG(0)); CALL_END();             // 14fc call 0x3734
  goto L_14c2;                                                 // 14ff jmp 0x14c2
L_1502:   SUB16(M16(DS, (u16)(0x61ee)), 0x0);                          // 1502 cmp word ptr [0x61ee], 0
  if (!R.zf) goto L_150c;                                      // 1507 jne 0x150c
  goto L_1030;                                                 // 1509 jmp 0x1030
L_150c:   PUSH(0x27cc); PUSH(0x1511); du_driver(96);   /* driver slot 96 */ // 150c lcall 0x62a, 0x214c
  goto L_1030;                                                 // 1511 jmp 0x1030
L_1514:   PUSH(0x1517); a_1000_20a0();                                 // 1514 call 0x20a0
  R.si = (u16)(R.ax);                                          // 1517 mov si, ax
  SUB16(M16(SS, (u16)(R.bp + 0xff9a)), 0x0);                   // 1519 cmp word ptr [bp - 0x66], 0
  if (R.zf) goto L_1524;                                       // 151d je 0x1524
  R.ax = (u16)(0x1e);                                          // 151f mov ax, 0x1e
  goto L_1527;                                                 // 1522 jmp 0x1527
L_1524:   R.ax = (u16)(0x7);                                           // 1524 mov ax, 7
L_1527:   SUB16(R.ax, R.si);                                           // 1527 cmp ax, si
  if (!R.zf && R.sf == R.of) goto L_1514;                      // 1529 jg 0x1514
  SUB16(M16(SS, (u16)(R.bp + 0xff90)), 0x1b);                  // 152b cmp word ptr [bp - 0x70], 0x1b
  if (R.zf) goto L_153b;                                       // 152f je 0x153b
  SUB16(M16(DS, (u16)(0x61f4)), 0x0);                          // 1531 cmp word ptr [0x61f4], 0
  if (!R.zf) goto L_153b;                                      // 1536 jne 0x153b
  goto L_06bd;                                                 // 1538 jmp 0x6bd
L_153b:   R.ax = (u16)(0x78);                                          // 153b mov ax, 0x78
  PUSH(R.ax);                                                  // 153e push ax
  PUSH(0x1542); a_1000_1ebe();                                 // 153f call 0x1ebe
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1542 add sp, 2
  R.si = POP();                                                // 1545 pop si
  R.di = POP();                                                // 1546 pop di
  R.sp = (u16)(R.bp);                                          // 1547 mov sp, bp
  R.bp = POP();                                                // 1549 pop bp
  R.sp += 2; goto L_ret;                                       // 154a ret
L_ret:
  return;
}

static u16 f_1000_0594(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_0594();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:154C FUN_1000_154c  FIX: recompiled from the machine code (asm2c)
static void a_1000_154c(void)
{
  FN(0x1000154C);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 154c push bp
  R.bp = (u16)(R.sp);                                          // 154d mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0xa));                              // 154f sub sp, 0xa
  PUSH(R.di);                                                  // 1552 push di
  PUSH(R.si);                                                  // 1553 push si
  SUB16(M16(SS, (u16)(R.bp + 0xa)), 0x0);                      // 1554 cmp word ptr [bp + 0xa], 0
  if (!R.zf) goto L_1560;                                      // 1558 jne 0x1560
  R.ax = (u16)(M16(DS, (u16)(0x2cfc)));                        // 155a mov ax, word ptr [0x2cfc]
  W16(SS, (u16)(R.bp + 0x4), ADD16(M16(SS, (u16)(R.bp + 0x4)), R.ax)); // 155d add word ptr [bp + 4], ax
L_1560:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1560 mov ax, word ptr [bp + 4]
  R.cx = (u16)(R.ax);                                          // 1563 mov cx, ax
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1565 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 1567 add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1569 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 156b add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 156d shl ax, 1
  R.si = (u16)(R.ax);                                          // 156f mov si, ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x74)));                   // 1571 mov ax, word ptr [si + 0x74]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x70))));      // 1575 sub ax, word ptr [si + 0x70]
  R.ax = (u16)(INC16(R.ax));                                   // 1579 inc ax
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 157a mov word ptr [bp - 2], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x76)));                   // 157d mov ax, word ptr [si + 0x76]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x72))));      // 1581 sub ax, word ptr [si + 0x72]
  R.ax = (u16)(INC16(R.ax));                                   // 1585 inc ax
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 1586 mov word ptr [bp - 4], ax
  SUB16(M16(SS, (u16)(R.bp + 0xa)), 0x0);                      // 1589 cmp word ptr [bp + 0xa], 0
  if (!R.zf) goto L_159d;                                      // 158d jne 0x159d
  R.ax = (u16)(R.cx);                                          // 158f mov ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1591 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 1593 add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1595 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 1597 add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1599 shl ax, 1
  R.si = (u16)(R.ax);                                          // 159b mov si, ax
L_159d:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 159d mov ax, word ptr [bp + 6]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x78))));      // 15a0 sub ax, word ptr [si + 0x78]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(R.si + 0x70))));      // 15a4 add ax, word ptr [si + 0x70]
  W16(SS, (u16)(R.bp + 0x6), R.ax);                            // 15a8 mov word ptr [bp + 6], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 15ab mov ax, word ptr [bp + 8]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(R.si + 0x7a))));      // 15ae sub ax, word ptr [si + 0x7a]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(R.si + 0x72))));      // 15b2 add ax, word ptr [si + 0x72]
  W16(SS, (u16)(R.bp + 0x8), R.ax);                            // 15b6 mov word ptr [bp + 8], ax
  PUSH(R.ax);                                                  // 15b9 push ax
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 15ba push word ptr [bp + 6]
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 15bd push word ptr [bp + 4]
  PUSH(0x15c3); a_1000_1bc2();                                 // 15c0 call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 15c3 add sp, 6
  R.si = (u16)(M16(DS, (u16)(0x1e5e)));                        // 15c6 mov si, word ptr [0x1e5e]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 15ca shl si, 1
  R.si = (u16)(ADD16(R.si, 0x2ce0));                           // 15cc add si, 0x2ce0
  R.ax = (u16)(M16(DS, (u16)(R.si)));                          // 15d0 mov ax, word ptr [si]
  SUB16(M16(SS, (u16)(R.bp + 0x6)), R.ax);                     // 15d2 cmp word ptr [bp + 6], ax
  if (R.sf == R.of) goto L_15dc;                               // 15d5 jge 0x15dc
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 15d7 mov ax, word ptr [bp + 6]
  W16(DS, (u16)(R.si), R.ax);                                  // 15da mov word ptr [si], ax
L_15dc:   R.si = (u16)(M16(DS, (u16)(0x1e5e)));                        // 15dc mov si, word ptr [0x1e5e]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 15e0 shl si, 1
  R.si = (u16)(ADD16(R.si, 0x2ce4));                           // 15e2 add si, 0x2ce4
  R.ax = (u16)(M16(DS, (u16)(R.si)));                          // 15e6 mov ax, word ptr [si]
  SUB16(M16(SS, (u16)(R.bp + 0x8)), R.ax);                     // 15e8 cmp word ptr [bp + 8], ax
  if (R.sf == R.of) goto L_15f2;                               // 15eb jge 0x15f2
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 15ed mov ax, word ptr [bp + 8]
  W16(DS, (u16)(R.si), R.ax);                                  // 15f0 mov word ptr [si], ax
L_15f2:   R.si = (u16)(M16(DS, (u16)(0x1e5e)));                        // 15f2 mov si, word ptr [0x1e5e]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 15f6 shl si, 1
  R.si = (u16)(ADD16(R.si, 0x2ce8));                           // 15f8 add si, 0x2ce8
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 15fc mov di, word ptr [bp + 6]
  R.di = (u16)(ADD16(R.di, M16(SS, (u16)(R.bp + 0xfffe))));    // 15ff add di, word ptr [bp - 2]
  SUB16(M16(DS, (u16)(R.si)), R.di);                           // 1602 cmp word ptr [si], di
  if (R.sf == R.of) goto L_1608;                               // 1604 jge 0x1608
  W16(DS, (u16)(R.si), R.di);                                  // 1606 mov word ptr [si], di
L_1608:   R.si = (u16)(M16(DS, (u16)(0x1e5e)));                        // 1608 mov si, word ptr [0x1e5e]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 160c shl si, 1
  R.si = (u16)(ADD16(R.si, 0x2cec));                           // 160e add si, 0x2cec
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 1612 mov di, word ptr [bp + 8]
  R.di = (u16)(ADD16(R.di, M16(SS, (u16)(R.bp + 0xfffc))));    // 1615 add di, word ptr [bp - 4]
  SUB16(M16(DS, (u16)(R.si)), R.di);                           // 1618 cmp word ptr [si], di
  if (R.sf == R.of) goto L_161e;                               // 161a jge 0x161e
  W16(DS, (u16)(R.si), R.di);                                  // 161c mov word ptr [si], di
L_161e:   R.si = POP();                                                // 161e pop si
  R.di = POP();                                                // 161f pop di
  R.sp = (u16)(R.bp);                                          // 1620 mov sp, bp
  R.bp = POP();                                                // 1622 pop bp
  R.sp += 2; goto L_ret;                                       // 1623 ret
L_ret:
  return;
}

static u16 f_1000_154c(u16 p0, u16 p1, u16 p2, u16 p3)
{
  ASM_ENTER();
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_154c();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1624 FUN_1000_1624  FIX: recompiled from the machine code (asm2c)
static void a_1000_1624(void)
{
  FN(0x10001624);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1624 push bp
  R.bp = (u16)(R.sp);                                          // 1625 mov bp, sp
  PUSH(R.si);                                                  // 1627 push si
  W16(DS, (u16)(0x2cfe), 0x1);                                 // 1628 mov word ptr [0x2cfe], 1
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 162e mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1631 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x4db8)), 0x4);                   // 1633 cmp word ptr [bx + 0x4db8], 4
  if (R.sf != R.of) goto L_163d;                               // 1638 jl 0x163d
  goto L_1770;                                                 // 163a jmp 0x1770
L_163d:   R.bx = (u16)(0x1);                                           // 163d mov bx, 1
  R.bx = (u16)(SUB16(R.bx, M16(SS, (u16)(R.bp + 0x4))));       // 1640 sub bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1643 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x4fc8)), 0x0);                   // 1645 cmp word ptr [bx + 0x4fc8], 0
  if (R.zf) goto L_166a;                                       // 164a je 0x166a
  R.ax = (u16)(0x2);                                           // 164c mov ax, 2
  PUSH(R.ax);                                                  // 164f push ax
  PUSH(0x1653); a_1000_202d();                                 // 1650 call 0x202d
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1653 add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 1656 or ax, ax
  if (R.zf) goto L_166a;                                       // 1658 je 0x166a
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 165a mov si, word ptr [bp + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 165d shl si, 1
  R.si = (u16)(ADD16(R.si, 0x4db8));                           // 165f add si, 0x4db8
  SUB16(M16(DS, (u16)(R.si)), 0x3);                            // 1663 cmp word ptr [si], 3
  if (R.sf == R.of) goto L_166a;                               // 1666 jge 0x166a
  W16(DS, (u16)(R.si), INC16(M16(DS, (u16)(R.si))));           // 1668 inc word ptr [si]
L_166a:   R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 166a mov si, word ptr [bp + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 166d shl si, 1
  W16(DS, (u16)(R.si + 0x4db8), INC16(M16(DS, (u16)(R.si + 0x4db8)))); // 166f inc word ptr [si + 0x4db8]
  SUB16(M16(DS, (u16)(R.si + 0x4db8)), 0x4);                   // 1673 cmp word ptr [si + 0x4db8], 4
  if (R.sf != R.of) goto L_1686;                               // 1678 jl 0x1686
  W16(DS, (u16)(R.si + 0x61f0), 0x7f);                         // 167a mov word ptr [si + 0x61f0], 0x7f
  W16(DS, (u16)(R.si + 0x4db8), 0x4);                          // 1680 mov word ptr [si + 0x4db8], 4
L_1686:   R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1686 mov si, word ptr [bp + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 1689 shl si, 1
  SUB16(M16(DS, (u16)(R.si + 0x4db8)), 0x4);                   // 168b cmp word ptr [si + 0x4db8], 4
  if (R.sf == R.of) goto L_16ab;                               // 1690 jge 0x16ab
  W16(DS, (u16)(R.si + 0x61f0), 0x27);                         // 1692 mov word ptr [si + 0x61f0], 0x27
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 1698 cmp word ptr [bp + 4], 0
  if (R.zf) goto L_16a4;                                       // 169c je 0x16a4
  R.ax = (u16)(0xfff8);                                        // 169e mov ax, 0xfff8
  goto L_16a7;                                                 // 16a1 jmp 0x16a7
L_16a4:   R.ax = (u16)(0x8);                                           // 16a4 mov ax, 8
L_16a7:   W16(DS, (u16)(R.si + 0x4fce), ADD16(M16(DS, (u16)(R.si + 0x4fce)), R.ax)); // 16a7 add word ptr [si + 0x4fce], ax
L_16ab:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 16ab cmp word ptr [bp + 4], 0
  if (R.zf) goto L_16fa;                                       // 16af je 0x16fa
  R.ax = (u16)(0x2);                                           // 16b1 mov ax, 2
  PUSH(R.ax);                                                  // 16b4 push ax
  R.ax = (u16)(0x10e);                                         // 16b5 mov ax, 0x10e
  PUSH(R.ax);                                                  // 16b8 push ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 16b9 mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 16bc shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4db8)));                 // 16be mov ax, word ptr [bx + 0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0xb7));                             // 16c2 add ax, 0xb7
  PUSH(R.ax);                                                  // 16c5 push ax
  PUSH(0x16c9); a_1000_1bc2();                                 // 16c6 call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 16c9 add sp, 6
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 16cc mov bx, word ptr [0x1f6a]
  W8(DS, (u16)(R.bx), XOR8(M8(DS, (u16)(R.bx)), 0x1));         // 16d0 xor byte ptr [bx], 1
  R.ax = (u16)(0x2);                                           // 16d3 mov ax, 2
  PUSH(R.ax);                                                  // 16d6 push ax
  R.ax = (u16)(0x10e);                                         // 16d7 mov ax, 0x10e
  PUSH(R.ax);                                                  // 16da push ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 16db mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 16de shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4db8)));                 // 16e0 mov ax, word ptr [bx + 0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0xb7));                             // 16e4 add ax, 0xb7
  PUSH(R.ax);                                                  // 16e7 push ax
  PUSH(0x16eb); a_1000_1bc2();                                 // 16e8 call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 16eb add sp, 6
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 16ee mov bx, word ptr [0x1f6a]
  W8(DS, (u16)(R.bx), XOR8(M8(DS, (u16)(R.bx)), 0x1));         // 16f2 xor byte ptr [bx], 1
  R.ax = (u16)(0x16);                                          // 16f5 mov ax, 0x16
  goto L_173b;                                                 // 16f8 jmp 0x173b
L_16fa:   R.ax = (u16)(0x2);                                           // 16fa mov ax, 2
  PUSH(R.ax);                                                  // 16fd push ax
  PUSH(R.ax);                                                  // 16fe push ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 16ff mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1702 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4db8)));                 // 1704 mov ax, word ptr [bx + 0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0xbb));                             // 1708 add ax, 0xbb
  PUSH(R.ax);                                                  // 170b push ax
  PUSH(0x170f); a_1000_1bc2();                                 // 170c call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 170f add sp, 6
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 1712 mov bx, word ptr [0x1f6a]
  W8(DS, (u16)(R.bx), XOR8(M8(DS, (u16)(R.bx)), 0x1));         // 1716 xor byte ptr [bx], 1
  R.ax = (u16)(0x2);                                           // 1719 mov ax, 2
  PUSH(R.ax);                                                  // 171c push ax
  PUSH(R.ax);                                                  // 171d push ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 171e mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1721 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4db8)));                 // 1723 mov ax, word ptr [bx + 0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0xbb));                             // 1727 add ax, 0xbb
  PUSH(R.ax);                                                  // 172a push ax
  PUSH(0x172e); a_1000_1bc2();                                 // 172b call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 172e add sp, 6
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 1731 mov bx, word ptr [0x1f6a]
  W8(DS, (u16)(R.bx), XOR8(M8(DS, (u16)(R.bx)), 0x1));         // 1735 xor byte ptr [bx], 1
  R.ax = (u16)(0x1a);                                          // 1738 mov ax, 0x1a
L_173b:   PUSH(R.ax);                                                  // 173b push ax
  PUSH(0x173f); a_1000_02a0();                                 // 173c call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 173f add sp, 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1742 mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1745 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x4db8)), 0x4);                   // 1747 cmp word ptr [bx + 0x4db8], 4
  if (R.sf == R.of) goto L_1770;                               // 174c jge 0x1770
  R.ax = (u16)(0x4);                                           // 174e mov ax, 4
  PUSH(R.ax);                                                  // 1751 push ax
  R.ax = (u16)(0x1);                                           // 1752 mov ax, 1
  PUSH(R.ax);                                                  // 1755 push ax
  R.ax = (u16)(M16(DS, (u16)(0x4dba)));                        // 1756 mov ax, word ptr [0x4dba]
  R.ax = (u16)(SUB16(R.ax, M16(DS, (u16)(0x4db8))));           // 1759 sub ax, word ptr [0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0x2));                              // 175d add ax, 2
  PUSH(R.ax);                                                  // 1760 push ax
  PUSH(0x1764); a_1000_2069();                                 // 1761 call 0x2069
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 1764 add sp, 6
  PUSH(R.ax);                                                  // 1767 push ax
  PUSH(0x27cc); PUSH(0x176d); du_driver(104);   /* driver slot 104 */ // 1768 lcall 0x62a, 0x2174
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 176d add sp, 2
L_1770:   R.si = POP();                                                // 1770 pop si
  R.bp = POP();                                                // 1771 pop bp
  R.sp += 2; goto L_ret;                                       // 1772 ret
L_ret:
  return;
}

static u16 f_1000_1624(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1624();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1774 FUN_1000_1774  FIX: recompiled from the machine code (asm2c)
static void a_1000_1774(void)
{
  FN(0x10001774);
  R.cs = 0x27cc;
  SUB16(M16(DS, (u16)(0x4dba)), 0x0);                          // 1774 cmp word ptr [0x4dba], 0
  if (R.zf) goto L_1790;                                       // 1779 je 0x1790
  R.ax = (u16)(0x2);                                           // 177b mov ax, 2
  PUSH(R.ax);                                                  // 177e push ax
  R.ax = (u16)(0x10e);                                         // 177f mov ax, 0x10e
  PUSH(R.ax);                                                  // 1782 push ax
  R.ax = (u16)(M16(DS, (u16)(0x4dba)));                        // 1783 mov ax, word ptr [0x4dba]
  R.ax = (u16)(ADD16(R.ax, 0xb7));                             // 1786 add ax, 0xb7
  PUSH(R.ax);                                                  // 1789 push ax
  PUSH(0x178d); a_1000_1bc2();                                 // 178a call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 178d add sp, 6
L_1790:   SUB16(M16(DS, (u16)(0x4db8)), 0x0);                          // 1790 cmp word ptr [0x4db8], 0
  if (R.zf) goto L_17a9;                                       // 1795 je 0x17a9
  R.ax = (u16)(0x2);                                           // 1797 mov ax, 2
  PUSH(R.ax);                                                  // 179a push ax
  PUSH(R.ax);                                                  // 179b push ax
  R.ax = (u16)(M16(DS, (u16)(0x4db8)));                        // 179c mov ax, word ptr [0x4db8]
  R.ax = (u16)(ADD16(R.ax, 0xbb));                             // 179f add ax, 0xbb
  PUSH(R.ax);                                                  // 17a2 push ax
  PUSH(0x17a6); a_1000_1bc2();                                 // 17a3 call 0x1bc2
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 17a6 add sp, 6
L_17a9:   R.sp += 2; goto L_ret;                                       // 17a9 ret
L_ret:
  return;
}

static u16 f_1000_1774(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_1774();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:17AA FUN_1000_17aa  FIX: recompiled from the machine code (asm2c)
static void a_1000_17aa(void)
{
  FN(0x100017AA);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 17aa push bp
  R.bp = (u16)(R.sp);                                          // 17ab mov bp, sp
  R.ax = (u16)(0x12);                                          // 17ad mov ax, 0x12
  PUSH(R.ax);                                                  // 17b0 push ax
  PUSH(0x17b4); a_1000_02a0();                                 // 17b1 call 0x2a0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 17b4 add sp, 2
  W16(DS, (u16)(0x2cfe), 0x1);                                 // 17b7 mov word ptr [0x2cfe], 1
  R.bp = POP();                                                // 17bd pop bp
  R.sp += 2; goto L_ret;                                       // 17be ret
L_ret:
  return;
}

static u16 f_1000_17aa(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_17aa();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:17C0 FUN_1000_17c0  FIX: recompiled from the machine code (asm2c)
static void a_1000_17c0(void)
{
  FN(0x100017C0);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 17c0 push bp
  R.bp = (u16)(R.sp);                                          // 17c1 mov bp, sp
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 17c3 mov bx, word ptr [0x1f6a]
  W16(DS, (u16)(R.bx + 0xe), 0x2);                             // 17c7 mov word ptr [bx + 0xe], 2
  R.ax = (u16)(0x1e6c);                                        // 17cc mov ax, 0x1e6c
  PUSH(R.ax);                                                  // 17cf push ax
  R.ax = (u16)(0x4a76);                                        // 17d0 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 17d3 push ax
  PUSH(0x17d7); a_1000_32d2();                                 // 17d4 call 0x32d2
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 17d7 add sp, 4
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 17da push word ptr [bp + 4]
  PUSH(0x17e0); a_1000_18c0();                                 // 17dd call 0x18c0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 17e0 add sp, 2
  R.ax = (u16)(0xf);                                           // 17e3 mov ax, 0xf
  PUSH(R.ax);                                                  // 17e6 push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 17e7 sub ax, ax
  PUSH(R.ax);                                                  // 17e9 push ax
  R.ax = (u16)(0x50);                                          // 17ea mov ax, 0x50
  PUSH(R.ax);                                                  // 17ed push ax
  R.ax = (u16)(0x4a76);                                        // 17ee mov ax, 0x4a76
  PUSH(R.ax);                                                  // 17f1 push ax
  PUSH(0x17f5); a_1000_1e90();                                 // 17f2 call 0x1e90
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 17f5 add sp, 8
  R.ax = (u16)(0x1e74);                                        // 17f8 mov ax, 0x1e74
  PUSH(R.ax);                                                  // 17fb push ax
  R.ax = (u16)(0x4a76);                                        // 17fc mov ax, 0x4a76
  PUSH(R.ax);                                                  // 17ff push ax
  PUSH(0x1803); a_1000_32d2();                                 // 1800 call 0x32d2
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1803 add sp, 4
  PUSH(M16(DS, (u16)(0x6200)));                                // 1806 push word ptr [0x6200]
  PUSH(0x180d); a_1000_18c0();                                 // 180a call 0x18c0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 180d add sp, 2
  R.ax = (u16)(0xf);                                           // 1810 mov ax, 0xf
  PUSH(R.ax);                                                  // 1813 push ax
  R.ax = (u16)(0x8);                                           // 1814 mov ax, 8
  PUSH(R.ax);                                                  // 1817 push ax
  R.ax = (u16)(0x50);                                          // 1818 mov ax, 0x50
  PUSH(R.ax);                                                  // 181b push ax
  R.ax = (u16)(0x4a76);                                        // 181c mov ax, 0x4a76
  PUSH(R.ax);                                                  // 181f push ax
  PUSH(0x1823); a_1000_1e90();                                 // 1820 call 0x1e90
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 1823 add sp, 8
  R.ax = (u16)(0x1e7a);                                        // 1826 mov ax, 0x1e7a
  PUSH(R.ax);                                                  // 1829 push ax
  R.ax = (u16)(0x4a76);                                        // 182a mov ax, 0x4a76
  PUSH(R.ax);                                                  // 182d push ax
  PUSH(0x1831); a_1000_32d2();                                 // 182e call 0x32d2
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1831 add sp, 4
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 1834 push word ptr [bp + 6]
  PUSH(0x183a); a_1000_18c0();                                 // 1837 call 0x18c0
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 183a add sp, 2
  R.ax = (u16)(0xf);                                           // 183d mov ax, 0xf
  PUSH(R.ax);                                                  // 1840 push ax
  R.ax = (u16)(0x10);                                          // 1841 mov ax, 0x10
  PUSH(R.ax);                                                  // 1844 push ax
  R.ax = (u16)(0x50);                                          // 1845 mov ax, 0x50
  PUSH(R.ax);                                                  // 1848 push ax
  R.ax = (u16)(0x4a76);                                        // 1849 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 184c push ax
  PUSH(0x1850); a_1000_1e90();                                 // 184d call 0x1e90
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 1850 add sp, 8
  R.ax = (u16)(0x1e82);                                        // 1853 mov ax, 0x1e82
  PUSH(R.ax);                                                  // 1856 push ax
  R.ax = (u16)(0x4a76);                                        // 1857 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 185a push ax
  PUSH(0x185e); a_1000_32d2();                                 // 185b call 0x32d2
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 185e add sp, 4
  R.ax = (u16)(0xa);                                           // 1861 mov ax, 0xa
  PUSH(R.ax);                                                  // 1864 push ax
  R.ax = (u16)(0x2cf0);                                        // 1865 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1868 push ax
  PUSH(M16(SS, (u16)(R.bp + 0x8)));                            // 1869 push word ptr [bp + 8]
  PUSH(0x186f); a_1000_3492();                                 // 186c call 0x3492
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 186f add sp, 6
  PUSH(R.ax);                                                  // 1872 push ax
  R.ax = (u16)(0x4a76);                                        // 1873 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1876 push ax
  PUSH(0x187a); a_1000_3351();                                 // 1877 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 187a add sp, 4
  R.ax = (u16)(0x1e89);                                        // 187d mov ax, 0x1e89
  PUSH(R.ax);                                                  // 1880 push ax
  R.ax = (u16)(0x4a76);                                        // 1881 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1884 push ax
  PUSH(0x1888); a_1000_3351();                                 // 1885 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1888 add sp, 4
  R.ax = (u16)(0xa);                                           // 188b mov ax, 0xa
  PUSH(R.ax);                                                  // 188e push ax
  R.ax = (u16)(0x2cf0);                                        // 188f mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1892 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xa)));                            // 1893 push word ptr [bp + 0xa]
  PUSH(0x1899); a_1000_3492();                                 // 1896 call 0x3492
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 1899 add sp, 6
  PUSH(R.ax);                                                  // 189c push ax
  R.ax = (u16)(0x4a76);                                        // 189d mov ax, 0x4a76
  PUSH(R.ax);                                                  // 18a0 push ax
  PUSH(0x18a4); a_1000_3351();                                 // 18a1 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 18a4 add sp, 4
  R.ax = (u16)(0xf);                                           // 18a7 mov ax, 0xf
  PUSH(R.ax);                                                  // 18aa push ax
  R.ax = (u16)(0x18);                                          // 18ab mov ax, 0x18
  PUSH(R.ax);                                                  // 18ae push ax
  R.ax = (u16)(0x50);                                          // 18af mov ax, 0x50
  PUSH(R.ax);                                                  // 18b2 push ax
  R.ax = (u16)(0x4a76);                                        // 18b3 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 18b6 push ax
  PUSH(0x18ba); a_1000_1e90();                                 // 18b7 call 0x1e90
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 18ba add sp, 8
  R.bp = POP();                                                // 18bd pop bp
  R.sp += 2; goto L_ret;                                       // 18be ret
L_ret:
  return;
}

static u16 f_1000_17c0(u16 p0, u16 p1, u16 p2, u16 p3)
{
  ASM_ENTER();
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_17c0();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:18C0 FUN_1000_18c0  FIX: recompiled from the machine code (asm2c)
static void a_1000_18c0(void)
{
  FN(0x100018C0);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 18c0 push bp
  R.bp = (u16)(R.sp);                                          // 18c1 mov bp, sp
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x7a);                     // 18c3 cmp word ptr [bp + 4], 0x7a
  if (R.sf != R.of) goto L_18fa;                               // 18c7 jl 0x18fa
  R.ax = (u16)(0x1e8b);                                        // 18c9 mov ax, 0x1e8b
  PUSH(R.ax);                                                  // 18cc push ax
  R.ax = (u16)(0x4a76);                                        // 18cd mov ax, 0x4a76
  PUSH(R.ax);                                                  // 18d0 push ax
  PUSH(0x18d4); a_1000_3351();                                 // 18d1 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 18d4 add sp, 4
  R.ax = (u16)(0xa);                                           // 18d7 mov ax, 0xa
  PUSH(R.ax);                                                  // 18da push ax
  R.ax = (u16)(0x2cf0);                                        // 18db mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 18de push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 18df mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x7a));                             // 18e2 sub ax, 0x7a
L_18e5:   PUSH(R.ax);                                                  // 18e5 push ax
  PUSH(0x18e9); a_1000_3492();                                 // 18e6 call 0x3492
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 18e9 add sp, 6
  PUSH(R.ax);                                                  // 18ec push ax
  R.ax = (u16)(0x4a76);                                        // 18ed mov ax, 0x4a76
  PUSH(R.ax);                                                  // 18f0 push ax
  PUSH(0x18f4); a_1000_3351();                                 // 18f1 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 18f4 add sp, 4
  R.bp = POP();                                                // 18f7 pop bp
  R.sp += 2; goto L_ret;                                       // 18f8 ret
L_18fa:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x78);                     // 18fa cmp word ptr [bp + 4], 0x78
  if (R.sf != R.of) goto L_191e;                               // 18fe jl 0x191e
  R.ax = (u16)(0x1e95);                                        // 1900 mov ax, 0x1e95
  PUSH(R.ax);                                                  // 1903 push ax
  R.ax = (u16)(0x4a76);                                        // 1904 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1907 push ax
  PUSH(0x190b); a_1000_3351();                                 // 1908 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 190b add sp, 4
  R.ax = (u16)(0xa);                                           // 190e mov ax, 0xa
  PUSH(R.ax);                                                  // 1911 push ax
  R.ax = (u16)(0x2cf0);                                        // 1912 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1915 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1916 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x78));                             // 1919 sub ax, 0x78
  goto L_18e5;                                                 // 191c jmp 0x18e5
L_191e:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x76);                     // 191e cmp word ptr [bp + 4], 0x76
  if (R.sf != R.of) goto L_1942;                               // 1922 jl 0x1942
  R.ax = (u16)(0x1e9f);                                        // 1924 mov ax, 0x1e9f
  PUSH(R.ax);                                                  // 1927 push ax
  R.ax = (u16)(0x4a76);                                        // 1928 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 192b push ax
  PUSH(0x192f); a_1000_3351();                                 // 192c call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 192f add sp, 4
  R.ax = (u16)(0xa);                                           // 1932 mov ax, 0xa
  PUSH(R.ax);                                                  // 1935 push ax
  R.ax = (u16)(0x2cf0);                                        // 1936 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1939 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 193a mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x76));                             // 193d sub ax, 0x76
  goto L_18e5;                                                 // 1940 jmp 0x18e5
L_1942:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x66);                     // 1942 cmp word ptr [bp + 4], 0x66
  if (R.sf != R.of) goto L_1968;                               // 1946 jl 0x1968
  R.ax = (u16)(0x1ea9);                                        // 1948 mov ax, 0x1ea9
  PUSH(R.ax);                                                  // 194b push ax
  R.ax = (u16)(0x4a76);                                        // 194c mov ax, 0x4a76
  PUSH(R.ax);                                                  // 194f push ax
  PUSH(0x1953); a_1000_3351();                                 // 1950 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1953 add sp, 4
  R.ax = (u16)(0xa);                                           // 1956 mov ax, 0xa
  PUSH(R.ax);                                                  // 1959 push ax
  R.ax = (u16)(0x2cf0);                                        // 195a mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 195d push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 195e mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x66));                             // 1961 sub ax, 0x66
  goto L_18e5;                                                 // 1964 jmp 0x18e5
L_1968:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x60);                     // 1968 cmp word ptr [bp + 4], 0x60
  if (R.sf != R.of) goto L_198e;                               // 196c jl 0x198e
  R.ax = (u16)(0x1eb1);                                        // 196e mov ax, 0x1eb1
  PUSH(R.ax);                                                  // 1971 push ax
  R.ax = (u16)(0x4a76);                                        // 1972 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1975 push ax
  PUSH(0x1979); a_1000_3351();                                 // 1976 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1979 add sp, 4
  R.ax = (u16)(0xa);                                           // 197c mov ax, 0xa
  PUSH(R.ax);                                                  // 197f push ax
  R.ax = (u16)(0x2cf0);                                        // 1980 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1983 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1984 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x60));                             // 1987 sub ax, 0x60
  goto L_18e5;                                                 // 198a jmp 0x18e5
L_198e:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x55);                     // 198e cmp word ptr [bp + 4], 0x55
  if (R.sf != R.of) goto L_19b4;                               // 1992 jl 0x19b4
  R.ax = (u16)(0x1eb9);                                        // 1994 mov ax, 0x1eb9
  PUSH(R.ax);                                                  // 1997 push ax
  R.ax = (u16)(0x4a76);                                        // 1998 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 199b push ax
  PUSH(0x199f); a_1000_3351();                                 // 199c call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 199f add sp, 4
  R.ax = (u16)(0xa);                                           // 19a2 mov ax, 0xa
  PUSH(R.ax);                                                  // 19a5 push ax
  R.ax = (u16)(0x2cf0);                                        // 19a6 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 19a9 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 19aa mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x55));                             // 19ad sub ax, 0x55
  goto L_18e5;                                                 // 19b0 jmp 0x18e5
L_19b4:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x4a);                     // 19b4 cmp word ptr [bp + 4], 0x4a
  if (R.sf != R.of) goto L_19da;                               // 19b8 jl 0x19da
  R.ax = (u16)(0x1ec0);                                        // 19ba mov ax, 0x1ec0
  PUSH(R.ax);                                                  // 19bd push ax
  R.ax = (u16)(0x4a76);                                        // 19be mov ax, 0x4a76
  PUSH(R.ax);                                                  // 19c1 push ax
  PUSH(0x19c5); a_1000_3351();                                 // 19c2 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 19c5 add sp, 4
  R.ax = (u16)(0xa);                                           // 19c8 mov ax, 0xa
  PUSH(R.ax);                                                  // 19cb push ax
  R.ax = (u16)(0x2cf0);                                        // 19cc mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 19cf push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 19d0 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x4a));                             // 19d3 sub ax, 0x4a
  goto L_18e5;                                                 // 19d6 jmp 0x18e5
L_19da:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x3e);                     // 19da cmp word ptr [bp + 4], 0x3e
  if (R.sf != R.of) goto L_1a00;                               // 19de jl 0x1a00
  R.ax = (u16)(0x1ec7);                                        // 19e0 mov ax, 0x1ec7
  PUSH(R.ax);                                                  // 19e3 push ax
  R.ax = (u16)(0x4a76);                                        // 19e4 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 19e7 push ax
  PUSH(0x19eb); a_1000_3351();                                 // 19e8 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 19eb add sp, 4
  R.ax = (u16)(0xa);                                           // 19ee mov ax, 0xa
  PUSH(R.ax);                                                  // 19f1 push ax
  R.ax = (u16)(0x2cf0);                                        // 19f2 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 19f5 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 19f6 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x3e));                             // 19f9 sub ax, 0x3e
  goto L_18e5;                                                 // 19fc jmp 0x18e5
L_1a00:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x36);                     // 1a00 cmp word ptr [bp + 4], 0x36
  if (R.sf != R.of) goto L_1a26;                               // 1a04 jl 0x1a26
  R.ax = (u16)(0x1ece);                                        // 1a06 mov ax, 0x1ece
  PUSH(R.ax);                                                  // 1a09 push ax
  R.ax = (u16)(0x4a76);                                        // 1a0a mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1a0d push ax
  PUSH(0x1a11); a_1000_3351();                                 // 1a0e call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1a11 add sp, 4
  R.ax = (u16)(0xa);                                           // 1a14 mov ax, 0xa
  PUSH(R.ax);                                                  // 1a17 push ax
  R.ax = (u16)(0x2cf0);                                        // 1a18 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1a1b push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1a1c mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x36));                             // 1a1f sub ax, 0x36
  goto L_18e5;                                                 // 1a22 jmp 0x18e5
L_1a26:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x2e);                     // 1a26 cmp word ptr [bp + 4], 0x2e
  if (R.sf != R.of) goto L_1a4c;                               // 1a2a jl 0x1a4c
  R.ax = (u16)(0x1ed5);                                        // 1a2c mov ax, 0x1ed5
  PUSH(R.ax);                                                  // 1a2f push ax
  R.ax = (u16)(0x4a76);                                        // 1a30 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1a33 push ax
  PUSH(0x1a37); a_1000_3351();                                 // 1a34 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1a37 add sp, 4
  R.ax = (u16)(0xa);                                           // 1a3a mov ax, 0xa
  PUSH(R.ax);                                                  // 1a3d push ax
  R.ax = (u16)(0x2cf0);                                        // 1a3e mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1a41 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1a42 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x2e));                             // 1a45 sub ax, 0x2e
  goto L_18e5;                                                 // 1a48 jmp 0x18e5
L_1a4c:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x26);                     // 1a4c cmp word ptr [bp + 4], 0x26
  if (R.sf != R.of) goto L_1a72;                               // 1a50 jl 0x1a72
  R.ax = (u16)(0x1edc);                                        // 1a52 mov ax, 0x1edc
  PUSH(R.ax);                                                  // 1a55 push ax
  R.ax = (u16)(0x4a76);                                        // 1a56 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1a59 push ax
  PUSH(0x1a5d); a_1000_3351();                                 // 1a5a call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1a5d add sp, 4
  R.ax = (u16)(0xa);                                           // 1a60 mov ax, 0xa
  PUSH(R.ax);                                                  // 1a63 push ax
  R.ax = (u16)(0x2cf0);                                        // 1a64 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1a67 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1a68 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x26));                             // 1a6b sub ax, 0x26
  goto L_18e5;                                                 // 1a6e jmp 0x18e5
L_1a72:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x1f);                     // 1a72 cmp word ptr [bp + 4], 0x1f
  if (R.sf != R.of) goto L_1a98;                               // 1a76 jl 0x1a98
  R.ax = (u16)(0x1ee3);                                        // 1a78 mov ax, 0x1ee3
  PUSH(R.ax);                                                  // 1a7b push ax
  R.ax = (u16)(0x4a76);                                        // 1a7c mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1a7f push ax
  PUSH(0x1a83); a_1000_3351();                                 // 1a80 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1a83 add sp, 4
  R.ax = (u16)(0xa);                                           // 1a86 mov ax, 0xa
  PUSH(R.ax);                                                  // 1a89 push ax
  R.ax = (u16)(0x2cf0);                                        // 1a8a mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1a8d push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1a8e mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x1f));                             // 1a91 sub ax, 0x1f
  goto L_18e5;                                                 // 1a94 jmp 0x18e5
L_1a98:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x18);                     // 1a98 cmp word ptr [bp + 4], 0x18
  if (R.sf != R.of) goto L_1abe;                               // 1a9c jl 0x1abe
  R.ax = (u16)(0x1eeb);                                        // 1a9e mov ax, 0x1eeb
  PUSH(R.ax);                                                  // 1aa1 push ax
  R.ax = (u16)(0x4a76);                                        // 1aa2 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1aa5 push ax
  PUSH(0x1aa9); a_1000_3351();                                 // 1aa6 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1aa9 add sp, 4
  R.ax = (u16)(0xa);                                           // 1aac mov ax, 0xa
  PUSH(R.ax);                                                  // 1aaf push ax
  R.ax = (u16)(0x2cf0);                                        // 1ab0 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1ab3 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1ab4 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x18));                             // 1ab7 sub ax, 0x18
  goto L_18e5;                                                 // 1aba jmp 0x18e5
L_1abe:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x10);                     // 1abe cmp word ptr [bp + 4], 0x10
  if (R.sf != R.of) goto L_1ae4;                               // 1ac2 jl 0x1ae4
  R.ax = (u16)(0x1ef3);                                        // 1ac4 mov ax, 0x1ef3
  PUSH(R.ax);                                                  // 1ac7 push ax
  R.ax = (u16)(0x4a76);                                        // 1ac8 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1acb push ax
  PUSH(0x1acf); a_1000_3351();                                 // 1acc call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1acf add sp, 4
  R.ax = (u16)(0xa);                                           // 1ad2 mov ax, 0xa
  PUSH(R.ax);                                                  // 1ad5 push ax
  R.ax = (u16)(0x2cf0);                                        // 1ad6 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1ad9 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1ada mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x10));                             // 1add sub ax, 0x10
  goto L_18e5;                                                 // 1ae0 jmp 0x18e5
L_1ae4:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0xc);                      // 1ae4 cmp word ptr [bp + 4], 0xc
  if (R.sf != R.of) goto L_1b0a;                               // 1ae8 jl 0x1b0a
  R.ax = (u16)(0x1efb);                                        // 1aea mov ax, 0x1efb
  PUSH(R.ax);                                                  // 1aed push ax
  R.ax = (u16)(0x4a76);                                        // 1aee mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1af1 push ax
  PUSH(0x1af5); a_1000_3351();                                 // 1af2 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1af5 add sp, 4
  R.ax = (u16)(0xa);                                           // 1af8 mov ax, 0xa
  PUSH(R.ax);                                                  // 1afb push ax
  R.ax = (u16)(0x2cf0);                                        // 1afc mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1aff push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1b00 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0xc));                              // 1b03 sub ax, 0xc
  goto L_18e5;                                                 // 1b06 jmp 0x18e5
L_1b0a:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x8);                      // 1b0a cmp word ptr [bp + 4], 8
  if (R.sf != R.of) goto L_1b30;                               // 1b0e jl 0x1b30
  R.ax = (u16)(0x1f03);                                        // 1b10 mov ax, 0x1f03
  PUSH(R.ax);                                                  // 1b13 push ax
  R.ax = (u16)(0x4a76);                                        // 1b14 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1b17 push ax
  PUSH(0x1b1b); a_1000_3351();                                 // 1b18 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1b1b add sp, 4
  R.ax = (u16)(0xa);                                           // 1b1e mov ax, 0xa
  PUSH(R.ax);                                                  // 1b21 push ax
  R.ax = (u16)(0x2cf0);                                        // 1b22 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1b25 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1b26 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x8));                              // 1b29 sub ax, 8
  goto L_18e5;                                                 // 1b2c jmp 0x18e5
L_1b30:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x6);                      // 1b30 cmp word ptr [bp + 4], 6
  if (R.sf != R.of) goto L_1b56;                               // 1b34 jl 0x1b56
  R.ax = (u16)(0x1f0b);                                        // 1b36 mov ax, 0x1f0b
  PUSH(R.ax);                                                  // 1b39 push ax
  R.ax = (u16)(0x4a76);                                        // 1b3a mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1b3d push ax
  PUSH(0x1b41); a_1000_3351();                                 // 1b3e call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1b41 add sp, 4
  R.ax = (u16)(0xa);                                           // 1b44 mov ax, 0xa
  PUSH(R.ax);                                                  // 1b47 push ax
  R.ax = (u16)(0x2cf0);                                        // 1b48 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1b4b push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1b4c mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x6));                              // 1b4f sub ax, 6
  goto L_18e5;                                                 // 1b52 jmp 0x18e5
L_1b56:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x4);                      // 1b56 cmp word ptr [bp + 4], 4
  if (R.sf != R.of) goto L_1b7c;                               // 1b5a jl 0x1b7c
  R.ax = (u16)(0x1f13);                                        // 1b5c mov ax, 0x1f13
  PUSH(R.ax);                                                  // 1b5f push ax
  R.ax = (u16)(0x4a76);                                        // 1b60 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1b63 push ax
  PUSH(0x1b67); a_1000_3351();                                 // 1b64 call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1b67 add sp, 4
  R.ax = (u16)(0xa);                                           // 1b6a mov ax, 0xa
  PUSH(R.ax);                                                  // 1b6d push ax
  R.ax = (u16)(0x2cf0);                                        // 1b6e mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1b71 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1b72 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x4));                              // 1b75 sub ax, 4
  goto L_18e5;                                                 // 1b78 jmp 0x18e5
L_1b7c:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x2);                      // 1b7c cmp word ptr [bp + 4], 2
  if (R.sf != R.of) goto L_1ba2;                               // 1b80 jl 0x1ba2
  R.ax = (u16)(0x1f1b);                                        // 1b82 mov ax, 0x1f1b
  PUSH(R.ax);                                                  // 1b85 push ax
  R.ax = (u16)(0x4a76);                                        // 1b86 mov ax, 0x4a76
  PUSH(R.ax);                                                  // 1b89 push ax
  PUSH(0x1b8d); a_1000_3351();                                 // 1b8a call 0x3351
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1b8d add sp, 4
  R.ax = (u16)(0xa);                                           // 1b90 mov ax, 0xa
  PUSH(R.ax);                                                  // 1b93 push ax
  R.ax = (u16)(0x2cf0);                                        // 1b94 mov ax, 0x2cf0
  PUSH(R.ax);                                                  // 1b97 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1b98 mov ax, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, 0x2));                              // 1b9b sub ax, 2
  goto L_18e5;                                                 // 1b9e jmp 0x18e5
L_1ba2:   R.bp = POP();                                                // 1ba2 pop bp
  R.sp += 2; goto L_ret;                                       // 1ba3 ret
L_ret:
  return;
}

static u16 f_1000_18c0(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_18c0();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1BA4 FUN_1000_1ba4  FIX: recompiled from the machine code (asm2c)
static void a_1000_1ba4(void)
{
  FN(0x10001BA4);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1ba4 push bp
  R.bp = (u16)(R.sp);                                          // 1ba5 mov bp, sp
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 1ba7 cmp word ptr [bp + 4], 0
  if (R.zf || R.sf != R.of) goto L_1bb2;                       // 1bab jle 0x1bb2
  R.ax = (u16)(0x1);                                           // 1bad mov ax, 1
  R.bp = POP();                                                // 1bb0 pop bp
  R.sp += 2; goto L_ret;                                       // 1bb1 ret
L_1bb2:   SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 1bb2 cmp word ptr [bp + 4], 0
  if (R.sf == R.of) goto L_1bbe;                               // 1bb6 jge 0x1bbe
  R.ax = (u16)(0xffff);                                        // 1bb8 mov ax, 0xffff
  R.bp = POP();                                                // 1bbb pop bp
  R.sp += 2; goto L_ret;                                       // 1bbc ret
L_1bbe:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 1bbe sub ax, ax
  R.bp = POP();                                                // 1bc0 pop bp
  R.sp += 2; goto L_ret;                                       // 1bc1 ret
L_ret:
  return;
}

static u16 f_1000_1ba4(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1ba4();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1BC2 FUN_1000_1bc2  FIX: recompiled from the machine code (asm2c)
static void a_1000_1bc2(void)
{
  FN(0x10001BC2);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1bc2 push bp
  R.bp = (u16)(R.sp);                                          // 1bc3 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1bc5 mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1bc8 shl bx, 1
  PUSH(M16(DS, (u16)(R.bx + 0x4fd2)));                         // 1bca push word ptr [bx + 0x4fd2]
  PUSH(M16(SS, (u16)(R.bp + 0x8)));                            // 1bce push word ptr [bp + 8]
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 1bd1 push word ptr [bp + 6]
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 1bd4 push word ptr [0x1f6a]
  PUSH(0x27cc); PUSH(0x1bdd); du_driver(28);   /* driver slot 28 */ // 1bd8 lcall 0x62a, 0x1ff8
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 1bdd add sp, 8
  R.bp = POP();                                                // 1be0 pop bp
  R.sp += 2; goto L_ret;                                       // 1be1 ret
L_ret:
  return;
}

static u16 f_1000_1bc2(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1bc2();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1BE2 FUN_1000_1be2  FIX: recompiled from the machine code (asm2c)
static void a_1000_1be2(void)
{
  FN(0x10001BE2);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1be2 push bp
  R.bp = (u16)(R.sp);                                          // 1be3 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x16));                             // 1be5 sub sp, 0x16
  PUSH(R.si);                                                  // 1be8 push si
  W16(DS, (u16)(0x2cfc), 0xffff);                              // 1be9 mov word ptr [0x2cfc], 0xffff
  PUSH(0x27cc); PUSH(0x1bf4); du_driver(16);   /* driver slot 16 */ // 1bef lcall 0x62a, 0x1fbc
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 1bf4 sub ax, ax
  W16(SS, (u16)(R.bp + 0xffec), R.ax);                         // 1bf6 mov word ptr [bp - 0x14], ax
  W16(SS, (u16)(R.bp + 0xffea), R.ax);                         // 1bf9 mov word ptr [bp - 0x16], ax
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 1bfc mov word ptr [bp - 2], ax
  W16(SS, (u16)(R.bp + 0xffee), 0xffff);                       // 1bff mov word ptr [bp - 0x12], 0xffff
L_1c04:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xffea)));                 // 1c04 mov bx, word ptr [bp - 0x16]
  R.ax = (u16)(R.bx);                                          // 1c07 mov ax, bx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1c09 shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 1c0b add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1c0d shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 1c0f add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1c11 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x6e)));                   // 1c13 mov si, word ptr [bx + 0x6e]
  SUB16(M16(SS, (u16)(R.bp + 0xffee)), R.si);                  // 1c17 cmp word ptr [bp - 0x12], si
  if (R.zf) goto L_1c77;                                       // 1c1a je 0x1c77
  W16(SS, (u16)(R.bp + 0xffee), R.si);                         // 1c1c mov word ptr [bp - 0x12], si
  R.ax = (u16)(R.si);                                          // 1c1f mov ax, si
  SUB16(R.ax, 0x2);                                            // 1c21 cmp ax, 2
  if (!R.zf) goto L_1c29;                                      // 1c24 jne 0x1c29
  goto L_1d5a;                                                 // 1c26 jmp 0x1d5a
L_1c29:   SUB16(R.ax, 0x3);                                            // 1c29 cmp ax, 3
  if (!R.zf) goto L_1c31;                                      // 1c2c jne 0x1c31
  goto L_1d6e;                                                 // 1c2e jmp 0x1d6e
L_1c31:   SUB16(R.ax, 0x4);                                            // 1c31 cmp ax, 4
  if (R.zf) goto L_1c40;                                       // 1c34 je 0x1c40
  SUB16(R.ax, 0x5);                                            // 1c36 cmp ax, 5
  if (!R.zf) goto L_1c3e;                                      // 1c39 jne 0x1c3e
  goto L_1d40;                                                 // 1c3b jmp 0x1d40
L_1c3e:   goto L_1c77;                                                 // 1c3e jmp 0x1c77
L_1c40:   PUSH(0x27cc); PUSH(0x1c45); du_driver(8);   /* driver slot 8 */ // 1c40 lcall 0x62a, 0x1f94
  PUSH(0x27cc); PUSH(0x1c4a); du_driver(16);   /* driver slot 16 */ // 1c45 lcall 0x62a, 0x1fbc
  R.ax = (u16)(0x2);                                           // 1c4a mov ax, 2
  PUSH(R.ax);                                                  // 1c4d push ax
  R.ax = (u16)(0x1f23);                                        // 1c4e mov ax, 0x1f23
L_1c51:   PUSH(R.ax);                                                  // 1c51 push ax
  PUSH(0x1c55); a_1000_236e();                                 // 1c52 call 0x236e
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1c55 add sp, 4
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 1c58 sub ax, ax
  PUSH(R.ax);                                                  // 1c5a push ax
  R.ax = (u16)(0xe);                                           // 1c5b mov ax, 0xe
  PUSH(R.ax);                                                  // 1c5e push ax
  R.ax = (u16)(0xc8);                                          // 1c5f mov ax, 0xc8
  PUSH(R.ax);                                                  // 1c62 push ax
  R.ax = (u16)(0x140);                                         // 1c63 mov ax, 0x140
  PUSH(R.ax);                                                  // 1c66 push ax
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 1c67 sub ax, ax
  PUSH(R.ax);                                                  // 1c69 push ax
  PUSH(R.ax);                                                  // 1c6a push ax
  PUSH(M16(DS, (u16)(0x1e5c)));                                // 1c6b push word ptr [0x1e5c]
  PUSH(0x27cc); PUSH(0x1c74); du_driver(3);   /* driver slot 3 */ // 1c6f lcall 0x62a, 0x1f7b
  R.sp = (u16)(ADD16(R.sp, 0xe));                              // 1c74 add sp, 0xe
L_1c77:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffea)));                 // 1c77 mov ax, word ptr [bp - 0x16]
  R.cx = (u16)(R.ax);                                          // 1c7a mov cx, ax
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1c7c shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 1c7e add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1c80 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 1c82 add ax, cx
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1c84 shl ax, 1
  R.si = (u16)(R.ax);                                          // 1c86 mov si, ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x70)));                   // 1c88 mov ax, word ptr [si + 0x70]
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 1c8c mov word ptr [bp - 4], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x72)));                   // 1c8f mov ax, word ptr [si + 0x72]
  W16(SS, (u16)(R.bp + 0xfff8), R.ax);                         // 1c93 mov word ptr [bp - 8], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x74)));                   // 1c96 mov ax, word ptr [si + 0x74]
  W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 1c9a mov word ptr [bp - 0xa], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x76)));                   // 1c9d mov ax, word ptr [si + 0x76]
  W16(SS, (u16)(R.bp + 0xfff4), R.ax);                         // 1ca1 mov word ptr [bp - 0xc], ax
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xfff8))));    // 1ca4 sub ax, word ptr [bp - 8]
  R.ax = (u16)(DEC16(R.ax));                                   // 1ca7 dec ax
  PUSH(R.ax);                                                  // 1ca8 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfff6)));                 // 1ca9 mov ax, word ptr [bp - 0xa]
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xfffc))));    // 1cac sub ax, word ptr [bp - 4]
  R.ax = (u16)(DEC16(R.ax));                                   // 1caf dec ax
  PUSH(R.ax);                                                  // 1cb0 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfff8)));                 // 1cb1 mov ax, word ptr [bp - 8]
  R.ax = (u16)(INC16(R.ax));                                   // 1cb4 inc ax
  PUSH(R.ax);                                                  // 1cb5 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 1cb6 mov ax, word ptr [bp - 4]
  R.ax = (u16)(INC16(R.ax));                                   // 1cb9 inc ax
  PUSH(R.ax);                                                  // 1cba push ax
  R.ax = (u16)(0x2);                                           // 1cbb mov ax, 2
  PUSH(R.ax);                                                  // 1cbe push ax
  PUSH(0x27cc); PUSH(0x1cc4); du_driver(2);   /* driver slot 2 */ // 1cbf lcall 0x62a, 0x1f76
  R.sp = (u16)(ADD16(R.sp, 0xa));                              // 1cc4 add sp, 0xa
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1cc7 mov bx, word ptr [bp - 2]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1cca shl bx, 1
  W16(DS, (u16)(R.bx + 0x4fd2), R.ax);                         // 1ccc mov word ptr [bx + 0x4fd2], ax
  W16(SS, (u16)(R.bp + 0xffea), INC16(M16(SS, (u16)(R.bp + 0xffea)))); // 1cd0 inc word ptr [bp - 0x16]
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 1cd3 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xffea)));                 // 1cd6 mov bx, word ptr [bp - 0x16]
  R.ax = (u16)(R.bx);                                          // 1cd9 mov ax, bx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1cdb shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 1cdd add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1cdf shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 1ce1 add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1ce3 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x6e)), 0x2);                     // 1ce5 cmp word ptr [bx + 0x6e], 2
  if (!R.zf) goto L_1cfc;                                      // 1cea jne 0x1cfc
  SUB16(M16(DS, (u16)(0x2cfc)), 0xffff);                       // 1cec cmp word ptr [0x2cfc], -1
  if (!R.zf) goto L_1cfc;                                      // 1cf1 jne 0x1cfc
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1cf3 mov ax, word ptr [bp - 2]
  W16(DS, (u16)(0x2cfc), R.ax);                                // 1cf6 mov word ptr [0x2cfc], ax
  W16(SS, (u16)(R.bp + 0xffec), INC16(M16(SS, (u16)(R.bp + 0xffec)))); // 1cf9 inc word ptr [bp - 0x14]
L_1cfc:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xffea)));                 // 1cfc mov bx, word ptr [bp - 0x16]
  R.ax = (u16)(R.bx);                                          // 1cff mov ax, bx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1d01 shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 1d03 add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1d05 shl bx, 1
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 1d07 add bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1d09 shl bx, 1
  SUB16(M16(DS, (u16)(R.bx + 0x6e)), 0xffff);                  // 1d0b cmp word ptr [bx + 0x6e], -1
  if (R.zf) goto L_1d15;                                       // 1d10 je 0x1d15
  goto L_1c04;                                                 // 1d12 jmp 0x1c04
L_1d15:   R.ax = (u16)(0xe);                                           // 1d15 mov ax, 0xe
  PUSH(R.ax);                                                  // 1d18 push ax
  R.ax = (u16)(0xf);                                           // 1d19 mov ax, 0xf
  PUSH(R.ax);                                                  // 1d1c push ax
  R.ax = (u16)(0x25);                                          // 1d1d mov ax, 0x25
  PUSH(R.ax);                                                  // 1d20 push ax
  R.ax = (u16)(0xc5);                                          // 1d21 mov ax, 0xc5
  PUSH(R.ax);                                                  // 1d24 push ax
  R.ax = (u16)(0xa2);                                          // 1d25 mov ax, 0xa2
  PUSH(R.ax);                                                  // 1d28 push ax
  R.ax = (u16)(0x7a);                                          // 1d29 mov ax, 0x7a
  PUSH(R.ax);                                                  // 1d2c push ax
  PUSH(M16(DS, (u16)(0x1e5c)));                                // 1d2d push word ptr [0x1e5c]
  PUSH(0x27cc); PUSH(0x1d36); du_driver(3);   /* driver slot 3 */ // 1d31 lcall 0x62a, 0x1f7b
  R.sp = (u16)(ADD16(R.sp, 0xe));                              // 1d36 add sp, 0xe
  W16(SS, (u16)(R.bp + 0xfffa), 0x0);                          // 1d39 mov word ptr [bp - 6], 0
  goto L_1d85;                                                 // 1d3e jmp 0x1d85
L_1d40:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffea)));                 // 1d40 mov ax, word ptr [bp - 0x16]
  W16(DS, (u16)(0x2cfa), R.ax);                                // 1d43 mov word ptr [0x2cfa], ax
  PUSH(0x27cc); PUSH(0x1d4b); du_driver(8);   /* driver slot 8 */ // 1d46 lcall 0x62a, 0x1f94
  PUSH(0x27cc); PUSH(0x1d50); du_driver(16);   /* driver slot 16 */ // 1d4b lcall 0x62a, 0x1fbc
  R.ax = (u16)(0x2);                                           // 1d50 mov ax, 2
  PUSH(R.ax);                                                  // 1d53 push ax
  R.ax = (u16)(0x1f30);                                        // 1d54 mov ax, 0x1f30
  goto L_1c51;                                                 // 1d57 jmp 0x1c51
L_1d5a:   PUSH(0x27cc); PUSH(0x1d5f); du_driver(8);   /* driver slot 8 */ // 1d5a lcall 0x62a, 0x1f94
  PUSH(0x27cc); PUSH(0x1d64); du_driver(16);   /* driver slot 16 */ // 1d5f lcall 0x62a, 0x1fbc
  R.ax = (u16)(0x2);                                           // 1d64 mov ax, 2
  PUSH(R.ax);                                                  // 1d67 push ax
  R.ax = (u16)(0x1f3d);                                        // 1d68 mov ax, 0x1f3d
  goto L_1c51;                                                 // 1d6b jmp 0x1c51
L_1d6e:   PUSH(0x27cc); PUSH(0x1d73); du_driver(8);   /* driver slot 8 */ // 1d6e lcall 0x62a, 0x1f94
  PUSH(0x27cc); PUSH(0x1d78); du_driver(16);   /* driver slot 16 */ // 1d73 lcall 0x62a, 0x1fbc
  R.ax = (u16)(0x2);                                           // 1d78 mov ax, 2
  PUSH(R.ax);                                                  // 1d7b push ax
  R.ax = (u16)(0x1f4a);                                        // 1d7c mov ax, 0x1f4a
  goto L_1c51;                                                 // 1d7f jmp 0x1c51
L_1d82:   W16(SS, (u16)(R.bp + 0xfffa), INC16(M16(SS, (u16)(R.bp + 0xfffa)))); // 1d82 inc word ptr [bp - 6]
L_1d85:   SUB16(M16(SS, (u16)(R.bp + 0xfffa)), 0x4);                   // 1d85 cmp word ptr [bp - 6], 4
  if (R.sf == R.of) goto L_1db8;                               // 1d89 jge 0x1db8
  R.ax = (u16)(0x25);                                          // 1d8b mov ax, 0x25
  PUSH(R.ax);                                                  // 1d8e push ax
  R.ax = (u16)(0x2d);                                          // 1d8f mov ax, 0x2d
  PUSH(R.ax);                                                  // 1d92 push ax
  R.ax = (u16)(0xa2);                                          // 1d93 mov ax, 0xa2
  PUSH(R.ax);                                                  // 1d96 push ax
  R.ax = (u16)(0x2e);                                          // 1d97 mov ax, 0x2e
  IMUL16(M16(SS, (u16)(R.bp + 0xfffa)));                       // 1d9a imul word ptr [bp - 6]
  R.ax = (u16)(ADD16(R.ax, 0x7a));                             // 1d9d add ax, 0x7a
  PUSH(R.ax);                                                  // 1da0 push ax
  R.ax = (u16)(0x2);                                           // 1da1 mov ax, 2
  PUSH(R.ax);                                                  // 1da4 push ax
  PUSH(0x27cc); PUSH(0x1daa); du_driver(2);   /* driver slot 2 */ // 1da5 lcall 0x62a, 0x1f76
  R.sp = (u16)(ADD16(R.sp, 0xa));                              // 1daa add sp, 0xa
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 1dad mov bx, word ptr [bp - 6]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1db0 shl bx, 1
  W16(DS, (u16)(R.bx + 0x5142), R.ax);                         // 1db2 mov word ptr [bx + 0x5142], ax
  goto L_1d82;                                                 // 1db6 jmp 0x1d82
L_1db8:   R.ax = (u16)(0x5);                                           // 1db8 mov ax, 5
  PUSH(R.ax);                                                  // 1dbb push ax
  R.ax = (u16)(0x4);                                           // 1dbc mov ax, 4
  PUSH(R.ax);                                                  // 1dbf push ax
  R.ax = (u16)(0x25);                                          // 1dc0 mov ax, 0x25
  PUSH(R.ax);                                                  // 1dc3 push ax
  R.ax = (u16)(0xc5);                                          // 1dc4 mov ax, 0xc5
  PUSH(R.ax);                                                  // 1dc7 push ax
  R.ax = (u16)(0xa2);                                          // 1dc8 mov ax, 0xa2
  PUSH(R.ax);                                                  // 1dcb push ax
  R.ax = (u16)(0x7a);                                          // 1dcc mov ax, 0x7a
  PUSH(R.ax);                                                  // 1dcf push ax
  PUSH(M16(DS, (u16)(0x1e5c)));                                // 1dd0 push word ptr [0x1e5c]
  PUSH(0x27cc); PUSH(0x1dd9); du_driver(3);   /* driver slot 3 */ // 1dd4 lcall 0x62a, 0x1f7b
  R.sp = (u16)(ADD16(R.sp, 0xe));                              // 1dd9 add sp, 0xe
  W16(SS, (u16)(R.bp + 0xfffa), 0x0);                          // 1ddc mov word ptr [bp - 6], 0
L_1de1:   R.ax = (u16)(0x25);                                          // 1de1 mov ax, 0x25
  PUSH(R.ax);                                                  // 1de4 push ax
  R.ax = (u16)(0x2d);                                          // 1de5 mov ax, 0x2d
  PUSH(R.ax);                                                  // 1de8 push ax
  R.ax = (u16)(0xa2);                                          // 1de9 mov ax, 0xa2
  PUSH(R.ax);                                                  // 1dec push ax
  R.ax = (u16)(0x2e);                                          // 1ded mov ax, 0x2e
  IMUL16(M16(SS, (u16)(R.bp + 0xfffa)));                       // 1df0 imul word ptr [bp - 6]
  R.ax = (u16)(ADD16(R.ax, 0x7a));                             // 1df3 add ax, 0x7a
  PUSH(R.ax);                                                  // 1df6 push ax
  R.ax = (u16)(0x2);                                           // 1df7 mov ax, 2
  PUSH(R.ax);                                                  // 1dfa push ax
  PUSH(0x27cc); PUSH(0x1e00); du_driver(2);   /* driver slot 2 */ // 1dfb lcall 0x62a, 0x1f76
  R.sp = (u16)(ADD16(R.sp, 0xa));                              // 1e00 add sp, 0xa
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 1e03 mov bx, word ptr [bp - 6]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1e06 shl bx, 1
  W16(DS, (u16)(R.bx + 0x514a), R.ax);                         // 1e08 mov word ptr [bx + 0x514a], ax
  W16(SS, (u16)(R.bp + 0xfffa), INC16(M16(SS, (u16)(R.bp + 0xfffa)))); // 1e0c inc word ptr [bp - 6]
  SUB16(M16(SS, (u16)(R.bp + 0xfffa)), 0x4);                   // 1e0f cmp word ptr [bp - 6], 4
  if (R.sf != R.of) goto L_1de1;                               // 1e13 jl 0x1de1
  PUSH(0x27cc); PUSH(0x1e1a); du_driver(8);   /* driver slot 8 */ // 1e15 lcall 0x62a, 0x1f94
  R.si = POP();                                                // 1e1a pop si
  R.sp = (u16)(R.bp);                                          // 1e1b mov sp, bp
  R.bp = POP();                                                // 1e1d pop bp
  R.sp += 2; goto L_ret;                                       // 1e1e ret
L_ret:
  return;
}

static u16 f_1000_1be2(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_1be2();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1E20 FUN_1000_1e20  FIX: recompiled from the machine code (asm2c)
static void a_1000_1e20(void)
{
  FN(0x10001E20);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1e20 push bp
  R.bp = (u16)(R.sp);                                          // 1e21 mov bp, sp
  PUSH(0x27cc); PUSH(0x1e28); du_driver(97);   /* driver slot 97 */ // 1e23 lcall 0x62a, 0x2151
  W16(DS, (u16)(0x4a72), R.ax);                                // 1e28 mov word ptr [0x4a72], ax
  SETL(R.ax, M8(DS, (u16)(0x4a72)));                           // 1e2b mov al, byte ptr [0x4a72]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1e2e cwde
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1e2f mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx), R.ax);                                  // 1e32 mov word ptr [bx], ax
  SETL(R.ax, M8(DS, (u16)(0x4a73)));                           // 1e34 mov al, byte ptr [0x4a73]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1e37 cwde
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 1e38 mov bx, word ptr [bp + 6]
  W16(DS, (u16)(R.bx), R.ax);                                  // 1e3b mov word ptr [bx], ax
  R.bp = POP();                                                // 1e3d pop bp
  R.sp += 2; goto L_ret;                                       // 1e3e ret
L_ret:
  return;
}

static u16 f_1000_1e20(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1e20();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1E40 FUN_1000_1e40  FIX: recompiled from the machine code (asm2c)
static void a_1000_1e40(void)
{
  FN(0x10001E40);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1e40 push bp
  R.bp = (u16)(R.sp);                                          // 1e41 mov bp, sp
  R.ax = (u16)(0x201);                                         // 1e43 mov ax, 0x201
  PUSH(R.ax);                                                  // 1e46 push ax
  PUSH(0x1e4a); a_1000_4d54();                                 // 1e47 call 0x4d54
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1e4a add sp, 2
  SETL(R.cx, M8(SS, (u16)(R.bp + 0x4)));                       // 1e4d mov cl, byte ptr [bp + 4]
  SETL(R.cx, ADD8((u8)R.cx, 0x4));                             // 1e50 add cl, 4
  R.ax = (u16)(SAR16(R.ax, (u8)R.cx));                         // 1e53 sar ax, cl
  SETL(R.ax, AND8((u8)R.ax, 0x1));                             // 1e55 and al, 1
  SUB8((u8)R.ax, 0x1);                                         // 1e57 cmp al, 1
  if (!R.zf) goto L_1e60;                                      // 1e59 jne 0x1e60
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 1e5b sub ax, ax
  R.bp = POP();                                                // 1e5d pop bp
  R.sp += 2; goto L_ret;                                       // 1e5e ret
L_1e60:   R.ax = (u16)(0x1);                                           // 1e60 mov ax, 1
  R.bp = POP();                                                // 1e63 pop bp
  R.sp += 2; goto L_ret;                                       // 1e64 ret
L_ret:
  return;
}

static u16 f_1000_1e40(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1e40();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1E90 FUN_1000_1e90  FIX: recompiled from the machine code (asm2c)
static void a_1000_1e90(void)
{
  FN(0x10001E90);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1e90 push bp
  R.bp = (u16)(R.sp);                                          // 1e91 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 1e93 sub sp, 0
  PUSH(R.di);                                                  // 1e97 push di
  PUSH(R.si);                                                  // 1e98 push si
  R.bx = (u16)(M16(DS, (u16)(0x1f6a)));                        // 1e99 mov bx, word ptr [0x1f6a]
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 1e9d mov ax, word ptr [bp + 0xa]
  W16(DS, (u16)(R.bx + 0xc), R.ax);                            // 1ea0 mov word ptr [bx + 0xc], ax
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 1ea3 push word ptr [bp + 4]
  PUSH(M16(SS, (u16)(R.bp + 0x8)));                            // 1ea6 push word ptr [bp + 8]
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 1ea9 push word ptr [bp + 6]
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 1eac push word ptr [0x1f6a]
  PUSH(0x27cc); PUSH(0x1eb5); du_driver(19);   /* driver slot 19 */ // 1eb0 lcall 0x62a, 0x1fcb
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 1eb5 add sp, 8
  R.si = POP();                                                // 1eb8 pop si
  R.di = POP();                                                // 1eb9 pop di
  R.sp = (u16)(R.bp);                                          // 1eba mov sp, bp
  R.bp = POP();                                                // 1ebc pop bp
  R.sp += 2; goto L_ret;                                       // 1ebd ret
L_ret:
  return;
}

static u16 f_1000_1e90(u16 p0, u16 p1, u16 p2, u16 p3)
{
  ASM_ENTER();
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1e90();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1EBE FUN_1000_1ebe  FIX: recompiled from the machine code (asm2c)
static void a_1000_1ebe(void)
{
  FN(0x10001EBE);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1ebe push bp
  R.bp = (u16)(R.sp);                                          // 1ebf mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 1ec1 sub sp, 0
  PUSH(R.di);                                                  // 1ec5 push di
  PUSH(R.si);                                                  // 1ec6 push si
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 1ec7 cmp word ptr [bp + 4], 0
  if (R.zf) goto L_1ed0;                                       // 1ecb je 0x1ed0
  goto L_1ed3;                                                 // 1ecd jmp 0x1ed3
L_1ed0:   goto L_1f0c;                                                 // 1ed0 jmp 0x1f0c
L_1ed3:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1ed3 mov ax, word ptr [bp + 4]
  W16(SS, (u16)(R.bp + 0x4), DEC16(M16(SS, (u16)(R.bp + 0x4)))); // 1ed6 dec word ptr [bp + 4]
  SUB16(R.ax, 0x0);                                            // 1ed9 cmp ax, 0
  if (!R.zf) goto L_1ee1;                                      // 1edc jne 0x1ee1
  goto L_1f0c;                                                 // 1ede jmp 0x1f0c
L_1ee1:   R.ax = (u16)(0x3da);                                         // 1ee1 mov ax, 0x3da
  PUSH(R.ax);                                                  // 1ee4 push ax
  PUSH(0x1ee8); a_1000_4d54();                                 // 1ee5 call 0x4d54
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1ee8 add sp, 2
  AND8((u8)R.ax, 0x8);                                         // 1eeb test al, 8
  if (R.zf) goto L_1ef2;                                       // 1eed je 0x1ef2
  goto L_1ef5;                                                 // 1eef jmp 0x1ef5
L_1ef2:   goto L_1ee1;                                                 // 1ef2 jmp 0x1ee1
L_1ef5:   R.ax = (u16)(0x3da);                                         // 1ef5 mov ax, 0x3da
  PUSH(R.ax);                                                  // 1ef8 push ax
  PUSH(0x1efc); a_1000_4d54();                                 // 1ef9 call 0x4d54
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1efc add sp, 2
  AND8((u8)R.ax, 0x8);                                         // 1eff test al, 8
  if (!R.zf) goto L_1f06;                                      // 1f01 jne 0x1f06
  goto L_1f09;                                                 // 1f03 jmp 0x1f09
L_1f06:   goto L_1ef5;                                                 // 1f06 jmp 0x1ef5
L_1f09:   goto L_1ed3;                                                 // 1f09 jmp 0x1ed3
L_1f0c:   R.si = POP();                                                // 1f0c pop si
  R.di = POP();                                                // 1f0d pop di
  R.sp = (u16)(R.bp);                                          // 1f0e mov sp, bp
  R.bp = POP();                                                // 1f10 pop bp
  R.sp += 2; goto L_ret;                                       // 1f11 ret
L_ret:
  return;
}

static u16 f_1000_1ebe(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1ebe();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1F80 FUN_1000_1f80  FIX: recompiled from the machine code (asm2c)
static void a_1000_1f80(void)
{
  FN(0x10001F80);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1f80 push bp
  R.bp = (u16)(R.sp);                                          // 1f81 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 1f83 sub sp, 0
  PUSH(R.di);                                                  // 1f87 push di
  PUSH(R.si);                                                  // 1f88 push si
  PUSH(M16(SS, (u16)(R.bp + 0xc)));                            // 1f89 push word ptr [bp + 0xc]
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 1f8c mov ax, word ptr [bp + 0xa]
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0x6))));       // 1f8f sub ax, word ptr [bp + 6]
  R.ax = (u16)(INC16(R.ax));                                   // 1f92 inc ax
  PUSH(R.ax);                                                  // 1f93 push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 1f94 mov ax, word ptr [bp + 8]
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0x4))));       // 1f97 sub ax, word ptr [bp + 4]
  R.ax = (u16)(INC16(R.ax));                                   // 1f9a inc ax
  PUSH(R.ax);                                                  // 1f9b push ax
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 1f9c push word ptr [bp + 6]
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 1f9f push word ptr [bp + 4]
  PUSH(M16(DS, (u16)(0x1f6a)));                                // 1fa2 push word ptr [0x1f6a]
  PUSH(0x27cc); PUSH(0x1fab); a_1533_045c();                   // 1fa6 lcall 0x533, 0x45c
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 1fab add sp, 0xc
  R.si = POP();                                                // 1fae pop si
  R.di = POP();                                                // 1faf pop di
  R.sp = (u16)(R.bp);                                          // 1fb0 mov sp, bp
  R.bp = POP();                                                // 1fb2 pop bp
  R.sp += 2; goto L_ret;                                       // 1fb3 ret
L_ret:
  return;
}

static u16 f_1000_1f80(u16 p0, u16 p1, u16 p2, u16 p3, u16 p4)
{
  ASM_ENTER();
  PUSH((u16)p4);
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_1f80();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:1FDF FUN_1000_1fdf  FIX: recompiled from the machine code (asm2c)
static void a_1000_1fdf(void)
{
  FN(0x10001FDF);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 1fdf push bp
  R.bp = (u16)(R.sp);                                          // 1fe0 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 1fe2 sub sp, 0
  PUSH(R.di);                                                  // 1fe6 push di
  PUSH(R.si);                                                  // 1fe7 push si
  W8(DS, (u16)(0x5153), 0x0);                                  // 1fe8 mov byte ptr [0x5153], 0
  W8(DS, (u16)(0x5152), 0x3);                                  // 1fed mov byte ptr [0x5152], 3
  R.ax = (u16)(0x5152);                                        // 1ff2 mov ax, 0x5152
  PUSH(R.ax);                                                  // 1ff5 push ax
  R.ax = (u16)(0x5152);                                        // 1ff6 mov ax, 0x5152
  PUSH(R.ax);                                                  // 1ff9 push ax
  R.ax = (u16)(0x10);                                          // 1ffa mov ax, 0x10
  PUSH(R.ax);                                                  // 1ffd push ax
  PUSH(0x2001); a_1000_342d();                                 // 1ffe call 0x342d
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 2001 add sp, 6
  R.si = POP();                                                // 2004 pop si
  R.di = POP();                                                // 2005 pop di
  R.sp = (u16)(R.bp);                                          // 2006 mov sp, bp
  R.bp = POP();                                                // 2008 pop bp
  R.sp += 2; goto L_ret;                                       // 2009 ret
L_ret:
  return;
}

static u16 f_1000_1fdf(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_1fdf();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:200A FUN_1000_200a  FIX: recompiled from the machine code (asm2c)
static void a_1000_200a(void)
{
  FN(0x1000200A);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 200a push bp
  R.bp = (u16)(R.sp);                                          // 200b mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 200d sub sp, 0
  PUSH(R.di);                                                  // 2011 push di
  PUSH(R.si);                                                  // 2012 push si
  R.ax = (u16)(0x0);                                           // 2013 mov ax, 0
  PUSH(R.ax);                                                  // 2016 push ax
  PUSH(0x201a); a_1000_4d62();                                 // 2017 call 0x4d62
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 201a add sp, 2
  R.ax = (u16)(AND16(R.ax, 0x7fff));                           // 201d and ax, 0x7fff
  PUSH(R.ax);                                                  // 2020 push ax
  PUSH(0x2024); a_1000_50ee();                                 // 2021 call 0x50ee
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2024 add sp, 2
  R.si = POP();                                                // 2027 pop si
  R.di = POP();                                                // 2028 pop di
  R.sp = (u16)(R.bp);                                          // 2029 mov sp, bp
  R.bp = POP();                                                // 202b pop bp
  R.sp += 2; goto L_ret;                                       // 202c ret
L_ret:
  return;
}

static u16 f_1000_200a(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_200a();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:202D FUN_1000_202d  FIX: recompiled from the machine code (asm2c)
static void a_1000_202d(void)
{
  FN(0x1000202D);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 202d push bp
  R.bp = (u16)(R.sp);                                          // 202e mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 2030 sub sp, 0
  PUSH(R.di);                                                  // 2034 push di
  PUSH(R.si);                                                  // 2035 push si
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 2036 mov ax, word ptr [bp + 4]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 2039 cdq
  PUSH(R.dx);                                                  // 203a push dx
  PUSH(R.ax);                                                  // 203b push ax
  PUSH(0x203f); a_1000_5100();                                 // 203c call 0x5100
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 203f cdq
  PUSH(R.dx);                                                  // 2040 push dx
  PUSH(R.ax);                                                  // 2041 push ax
  PUSH(0x2045); a_1000_5240();                                 // 2042 call 0x5240
  SETL(R.cx, 0xf);                                             // 2045 mov cl, 0xf
  SUB8((u8)R.cx, 0x0);                                         // 2047 cmp cl, 0
  if (!R.zf) goto L_204f;                                      // 204a jne 0x204f
  goto L_2060;                                                 // 204c jmp 0x2060
L_204f:   R.dx = (u16)(SAR16(R.dx, 0x1));                              // 204f sar dx, 1
  R.ax = (u16)(RCR16(R.ax, 0x1));                              // 2051 rcr ax, 1
  SETL(R.cx, DEC8((u8)R.cx));                                  // 2053 dec cl
  SUB8((u8)R.cx, 0x0);                                         // 2055 cmp cl, 0
  if (!R.zf) goto L_205d;                                      // 2058 jne 0x205d
  goto L_2060;                                                 // 205a jmp 0x2060
L_205d:   goto L_204f;                                                 // 205d jmp 0x204f
L_2060:   goto L_2063;                                                 // 2060 jmp 0x2063
L_2063:   R.si = POP();                                                // 2063 pop si
  R.di = POP();                                                // 2064 pop di
  R.sp = (u16)(R.bp);                                          // 2065 mov sp, bp
  R.bp = POP();                                                // 2067 pop bp
  R.sp += 2; goto L_ret;                                       // 2068 ret
L_ret:
  return;
}

static u16 f_1000_202d(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_202d();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:2069 FUN_1000_2069  FIX: recompiled from the machine code (asm2c)
static void a_1000_2069(void)
{
  FN(0x10002069);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 2069 push bp
  R.bp = (u16)(R.sp);                                          // 206a mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x0));                              // 206c sub sp, 0
  PUSH(R.di);                                                  // 2070 push di
  PUSH(R.si);                                                  // 2071 push si
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 2072 mov ax, word ptr [bp + 6]
  SUB16(M16(SS, (u16)(R.bp + 0x4)), R.ax);                     // 2075 cmp word ptr [bp + 4], ax
  if (R.sf != R.of) goto L_207d;                               // 2078 jl 0x207d
  goto L_2083;                                                 // 207a jmp 0x2083
L_207d:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 207d mov ax, word ptr [bp + 6]
  W16(SS, (u16)(R.bp + 0x4), R.ax);                            // 2080 mov word ptr [bp + 4], ax
L_2083:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 2083 mov ax, word ptr [bp + 8]
  SUB16(M16(SS, (u16)(R.bp + 0x4)), R.ax);                     // 2086 cmp word ptr [bp + 4], ax
  if (!R.zf && R.sf == R.of) goto L_208e;                      // 2089 jg 0x208e
  goto L_2094;                                                 // 208b jmp 0x2094
L_208e:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 208e mov ax, word ptr [bp + 8]
  W16(SS, (u16)(R.bp + 0x4), R.ax);                            // 2091 mov word ptr [bp + 4], ax
L_2094:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 2094 mov ax, word ptr [bp + 4]
  goto L_209a;                                                 // 2097 jmp 0x209a
L_209a:   R.si = POP();                                                // 209a pop si
  R.di = POP();                                                // 209b pop di
  R.sp = (u16)(R.bp);                                          // 209c mov sp, bp
  R.bp = POP();                                                // 209e pop bp
  R.sp += 2; goto L_ret;                                       // 209f ret
L_ret:
  return;
}

static u16 f_1000_2069(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_2069();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:20A0 FUN_1000_20a0  FIX: recompiled from the machine code (asm2c)
static void a_1000_20a0(void)
{
  FN(0x100020A0);
  R.cs = 0x27cc;
  R.ax = (u16)(du_frame_poll(0x20a0));                        // 20a0 mov ax, word ptr [0x22c2]
  R.sp += 2; goto L_ret;                                       // 20a3 ret
L_ret:
  return;
}

static u16 f_1000_20a0(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_20a0();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:20A4 FUN_1000_20a4  FIX: recompiled from the machine code (asm2c)
static void a_1000_20a4(void)
{
  FN(0x100020A4);
  R.cs = 0x27cc;
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 20a4 xor ax, ax
  W16(DS, (u16)(0x22c2), R.ax);                                // 20a6 mov word ptr [0x22c2], ax
  R.sp += 2; goto L_ret;                                       // 20a9 ret
L_ret:
  return;
}

static u16 f_1000_20a4(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_20a4();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:20E6 FUN_1000_20e6  FIX: recompiled from the machine code (asm2c)
static void a_1000_20e6(void)
{
  FN(0x100020E6);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 20e6 push bp
  R.bp = (u16)(R.sp);                                          // 20e7 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x1a));                             // 20e9 sub sp, 0x1a
  R.ax = (u16)((u16)(R.bp + 0xffe6));                          // 20ec lea ax, [bp - 0x1a]
  PUSH(R.ax);                                                  // 20ef push ax
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 20f0 push word ptr [bp + 4]
  PUSH(0x20f6); a_1000_256e();                                 // 20f3 call 0x256e
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 20f6 add sp, 4
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 20f9 or ax, ax
  if (R.zf) goto L_2122;                                       // 20fb je 0x2122
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 20fd push word ptr [bp - 4]
  PUSH(M16(SS, (u16)(R.bp + 0xfffa)));                         // 2100 push word ptr [bp - 6]
  PUSH(M16(DS, (u16)(0x26c6)));                                // 2103 push word ptr [0x26c6]
  PUSH(0x210a); a_1000_260a();                                 // 2107 call 0x260a
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 210a add sp, 6
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 210d or ax, ax
  if (R.zf) goto L_211a;                                       // 210f je 0x211a
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 2111 push word ptr [bp + 4]
  PUSH(0x2117); a_1000_24c6();                                 // 2114 call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2117 add sp, 2
L_211a:   R.ax = (u16)(M16(DS, (u16)(0x26c6)));                        // 211a mov ax, word ptr [0x26c6]
  R.sp = (u16)(R.bp);                                          // 211d mov sp, bp
  R.bp = POP();                                                // 211f pop bp
  R.sp += 2; goto L_ret;                                       // 2120 ret
L_2122:   R.ax = (u16)((u16)(R.bp + 0xfffe));                          // 2122 lea ax, [bp - 2]
  PUSH(R.ax);                                                  // 2125 push ax
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 2126 push word ptr [bp + 6]
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 2129 push word ptr [bp + 4]
  PUSH(0x212f); a_1000_5168();                                 // 212c call 0x5168
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 212f add sp, 6
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 2132 or ax, ax
  if (R.zf) goto L_213f;                                       // 2134 je 0x213f
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 2136 push word ptr [bp + 4]
  PUSH(0x213c); a_1000_24c6();                                 // 2139 call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 213c add sp, 2
L_213f:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 213f mov ax, word ptr [bp - 2]
  R.sp = (u16)(R.bp);                                          // 2142 mov sp, bp
  R.bp = POP();                                                // 2144 pop bp
  R.sp += 2; goto L_ret;                                       // 2145 ret
L_ret:
  return;
}

static u16 f_1000_20e6(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_20e6();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:2170 FUN_1000_2170  FIX: recompiled from the machine code (asm2c)
static void a_1000_2170(void)
{
  FN(0x10002170);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 2170 push bp
  R.bp = (u16)(R.sp);                                          // 2171 mov bp, sp
  R.ax = (u16)(M16(DS, (u16)(0x26c6)));                        // 2173 mov ax, word ptr [0x26c6]
  SUB16(M16(SS, (u16)(R.bp + 0x4)), R.ax);                     // 2176 cmp word ptr [bp + 4], ax
  if (R.zf) goto L_2191;                                       // 2179 je 0x2191
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 217b push word ptr [bp + 4]
  PUSH(0x2181); a_1000_513a();                                 // 217e call 0x513a
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2181 add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 2184 or ax, ax
  if (R.zf) goto L_2191;                                       // 2186 je 0x2191
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 2188 sub ax, ax
  PUSH(R.ax);                                                  // 218a push ax
  PUSH(0x218e); a_1000_24c6();                                 // 218b call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 218e add sp, 2
L_2191:   R.bp = POP();                                                // 2191 pop bp
  R.sp += 2; goto L_ret;                                       // 2192 ret
L_ret:
  return;
}

static u16 f_1000_2170(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_2170();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:2260 FUN_1000_2260  FIX: recompiled from the machine code (asm2c)
static void a_1000_2260(void)
{
  FN(0x10002260);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 2260 push bp
  R.bp = (u16)(R.sp);                                          // 2261 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 2263 sub sp, 4
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 2266 sub ax, ax
  PUSH(R.ax);                                                  // 2268 push ax
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 2269 push word ptr [bp + 6]
  PUSH(0x226f); a_1000_20e6();                                 // 226c call 0x20e6
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 226f add sp, 4
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 2272 mov word ptr [bp - 4], ax
  PUSH(R.ax);                                                  // 2275 push ax
  PUSH(0x2279); a_1000_243c();                                 // 2276 call 0x243c
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2279 add sp, 2
  CALL_BEGIN(4); R.ax = (u16)du_PicHeader(); CALL_END();       // 227c lcall 0x5ff, 0xc
  W16(SS, (u16)(R.bp + 0xfffe), 0x0);                          // 2281 mov word ptr [bp - 2], 0
  goto L_22ad;                                                 // 2286 jmp 0x22ad
L_2288:   R.ax = (u16)(0x2f00);                                        // 2288 mov ax, 0x2f00
  PUSH(R.ax);                                                  // 228b push ax
  CALL_BEGIN(4); du_LzwDecodeRow((i16)ARG(0)); CALL_END();     // 228c lcall 0x5ff, 0xef
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2291 add sp, 2
  PUSH(M16(DS, (u16)(0x4846)));                                // 2294 push word ptr [0x4846]
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 2298 push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 229b push word ptr [bp + 4]
  R.ax = (u16)(0x2f00);                                        // 229e mov ax, 0x2f00
  PUSH(R.ax);                                                  // 22a1 push ax
  PUSH(0x27cc); PUSH(0x22a7); du_driver(17);   /* driver slot 17 */ // 22a2 lcall 0x62a, 0x1fc1
  R.sp = (u16)(ADD16(R.sp, 0x8));                              // 22a7 add sp, 8
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 22aa inc word ptr [bp - 2]
L_22ad:   R.ax = (u16)(M16(DS, (u16)(0x4848)));                        // 22ad mov ax, word ptr [0x4848]
  SUB16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax);                  // 22b0 cmp word ptr [bp - 2], ax
  if (R.sf != R.of) goto L_2288;                               // 22b3 jl 0x2288
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 22b5 push word ptr [bp - 4]
  PUSH(0x22bb); a_1000_2170();                                 // 22b8 call 0x2170
  R.sp = (u16)(R.bp);                                          // 22bb mov sp, bp
  R.bp = POP();                                                // 22bd pop bp
  R.sp += 2; goto L_ret;                                       // 22be ret
L_ret:
  return;
}

static u16 f_1000_2260(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_2260();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:236E FUN_1000_236e  FIX: recompiled from the machine code (asm2c)
static void a_1000_236e(void)
{
  FN(0x1000236E);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 236e push bp
  R.bp = (u16)(R.sp);                                          // 236f mov bp, sp
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 2371 push word ptr [bp + 4]
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 2374 push word ptr [bp + 6]
  PUSH(0x237a); a_1000_2260();                                 // 2377 call 0x2260
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 237a add sp, 4
  R.bp = POP();                                                // 237d pop bp
  R.sp += 2; goto L_ret;                                       // 237e ret
L_ret:
  return;
}

static u16 f_1000_236e(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_236e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:243C FUN_1000_243c  FIX: recompiled from the machine code (asm2c)
static void a_1000_243c(void)
{
  FN(0x1000243C);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 243c push bp
  R.bp = (u16)(R.sp);                                          // 243d mov bp, sp
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 243f mov ax, word ptr [bp + 4]
  W16(DS, (u16)(0x3040), R.ax);                                // 2442 mov word ptr [0x3040], ax
  R.ax = (u16)(M16(DS, (u16)(0x26c4)));                        // 2445 mov ax, word ptr [0x26c4]
  W16(DS, (u16)(0x4dbc), R.ax);                                // 2448 mov word ptr [0x4dbc], ax
  W16(DS, (u16)(0x61ea), 0x249e);                              // 244b mov word ptr [0x61ea], 0x249e
  W16(DS, (u16)(0x61ec), 0x27cc /* segment */);                // 2451 mov word ptr [0x61ec], 0
  R.bp = POP();                                                // 2457 pop bp
  R.sp += 2; goto L_ret;                                       // 2458 ret
L_ret:
  return;
}

static u16 f_1000_243c(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_243c();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:245A FUN_1000_245a  FIX: recompiled from the machine code (asm2c)
static void a_1000_245a(void)
{
  FN(0x1000245A);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 245a push bp
  R.bp = (u16)(R.sp);                                          // 245b mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 245d sub sp, 4
  R.ax = (u16)(0x2d00);                                        // 2460 mov ax, 0x2d00
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 2463 mov word ptr [bp - 4], ax
  W16(SS, (u16)(R.bp + 0xfffe), R.ds);                         // 2466 mov word ptr [bp - 2], ds
  R.ax = (u16)(0x200);                                         // 2469 mov ax, 0x200
  PUSH(R.ax);                                                  // 246c push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 246d push word ptr [bp - 4]
  PUSH(R.ds);                                                  // 2470 push ds
  PUSH(M16(DS, (u16)(0x3042)));                                // 2471 push word ptr [0x3042]
  PUSH(M16(DS, (u16)(0x3044)));                                // 2475 push word ptr [0x3044]
  PUSH(0x247c); a_1000_4d36();                                 // 2479 call 0x4d36
  W16(DS, (u16)(0x4dbc), 0x2d00);                              // 247c mov word ptr [0x4dbc], 0x2d00
  W8(DS, (u16)(0x3043), ADD8(M8(DS, (u16)(0x3043)), 0x2));     // 2482 add byte ptr [0x3043], 2
  R.ax = (u16)(0x200);                                         // 2487 mov ax, 0x200
  R.sp = (u16)(R.bp);                                          // 248a mov sp, bp
  R.bp = POP();                                                // 248c pop bp
  R.sp += 4; goto L_ret;                                       // 248d retf
L_ret:
  return;
}

static u16 f_1000_245a(void)
{
  ASM_ENTER();
  PUSH(0x27cc); PUSH(0);  // the return address (far)
  a_1000_245a();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:249E FUN_1000_249e  FIX: recompiled from the machine code (asm2c)
static void a_1000_249e(void)
{
  FN(0x1000249E);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 249e push bp
  R.bp = (u16)(R.sp);                                          // 249f mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 24a1 sub sp, 2
  R.ax = (u16)((u16)(R.bp + 0xfffe));                          // 24a4 lea ax, [bp - 2]
  PUSH(R.ax);                                                  // 24a7 push ax
  R.ax = (u16)(0x200);                                         // 24a8 mov ax, 0x200
  PUSH(R.ax);                                                  // 24ab push ax
  R.ax = (u16)(0x2d00);                                        // 24ac mov ax, 0x2d00
  PUSH(R.ds);                                                  // 24af push ds
  PUSH(R.ax);                                                  // 24b0 push ax
  PUSH(M16(DS, (u16)(0x3040)));                                // 24b1 push word ptr [0x3040]
  PUSH(0x24b8); a_1000_5180();                                 // 24b5 call 0x5180
  W16(DS, (u16)(0x4dbc), 0x2d00);                              // 24b8 mov word ptr [0x4dbc], 0x2d00
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 24be mov ax, word ptr [bp - 2]
  R.sp = (u16)(R.bp);                                          // 24c1 mov sp, bp
  R.bp = POP();                                                // 24c3 pop bp
  R.sp += 4; goto L_ret;                                       // 24c4 retf
L_ret:
  return;
}

static u16 f_1000_249e(void)
{
  ASM_ENTER();
  PUSH(0x27cc); PUSH(0);  // the return address (far)
  a_1000_249e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:24C6 FUN_1000_24c6  FIX: recompiled from the machine code (asm2c)
static void a_1000_24c6(void)
{
  FN(0x100024C6);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 24c6 push bp
  R.bp = (u16)(R.sp);                                          // 24c7 mov bp, sp
  R.ax = (u16)(0x3);                                           // 24c9 mov ax, 3
  PUSH(R.ax);                                                  // 24cc push ax
  PUSH(0x24d0); a_1000_24e8();                                 // 24cd call 0x24e8
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 24d0 add sp, 2
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 24d3 push word ptr [bp + 4]
  PUSH(0x24d9); a_1000_4838();                                 // 24d6 call 0x4838
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 24d9 add sp, 2
  R.ax = (u16)(0x63);                                          // 24dc mov ax, 0x63
  PUSH(R.ax);                                                  // 24df push ax
  CALL_BEGIN(4); du_exit((i16)ARG(0)); CALL_END();             // 24e0 call 0x3734
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 24e3 add sp, 2
  R.bp = POP();                                                // 24e6 pop bp
  R.sp += 2; goto L_ret;                                       // 24e7 ret
L_ret:
  return;
}

static u16 f_1000_24c6(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_24c6();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:24E8 FUN_1000_24e8  FIX: recompiled from the machine code (asm2c)
static void a_1000_24e8(void)
{
  FN(0x100024E8);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 24e8 push bp
  R.bp = (u16)(R.sp);                                          // 24e9 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x10));                             // 24eb sub sp, 0x10
  R.ax = (u16)(M16(DS, (u16)(0x2751)));                        // 24ee mov ax, word ptr [0x2751]
  W16(SS, (u16)(R.bp + 0xfff0), R.ax);                         // 24f1 mov word ptr [bp - 0x10], ax
  W8(SS, (u16)(R.bp + 0xfff3), 0x0);                           // 24f4 mov byte ptr [bp - 0xd], 0
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 24f8 mov al, byte ptr [bp + 4]
  W8(SS, (u16)(R.bp + 0xfff2), (u8)R.ax);                      // 24fb mov byte ptr [bp - 0xe], al
  R.ax = (u16)((u16)(R.bp + 0xfff2));                          // 24fe lea ax, [bp - 0xe]
  PUSH(R.ax);                                                  // 2501 push ax
  R.ax = (u16)((u16)(R.bp + 0xfff2));                          // 2502 lea ax, [bp - 0xe]
  PUSH(R.ax);                                                  // 2505 push ax
  R.ax = (u16)(0x10);                                          // 2506 mov ax, 0x10
  PUSH(R.ax);                                                  // 2509 push ax
  PUSH(0x250d); a_1000_342d();                                 // 250a call 0x342d
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfff0)));                 // 250d mov ax, word ptr [bp - 0x10]
  W16(DS, (u16)(0x2751), R.ax);                                // 2510 mov word ptr [0x2751], ax
  R.sp = (u16)(R.bp);                                          // 2513 mov sp, bp
  R.bp = POP();                                                // 2515 pop bp
  R.sp += 2; goto L_ret;                                       // 2516 ret
L_ret:
  return;
}

static u16 f_1000_24e8(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_24e8();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:2518 FUN_1000_2518  FIX: recompiled from the machine code (asm2c)
static void a_1000_2518(void)
{
  FN(0x10002518);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 2518 push bp
  R.bp = (u16)(R.sp);                                          // 2519 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 251b sub sp, 2
  R.ax = (u16)((u16)(R.bp + 0xfffe));                          // 251e lea ax, [bp - 2]
  PUSH(R.ax);                                                  // 2521 push ax
  R.ax = (u16)(0x8000);                                        // 2522 mov ax, 0x8000
  PUSH(R.ax);                                                  // 2525 push ax
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 2526 push word ptr [bp + 4]
  PUSH(0x252c); a_1000_5168();                                 // 2529 call 0x5168
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 252c add sp, 6
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 252f or ax, ax
  if (R.zf) goto L_253a;                                       // 2531 je 0x253a
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 2533 sub ax, ax
  R.sp = (u16)(R.bp);                                          // 2535 mov sp, bp
  R.bp = POP();                                                // 2537 pop bp
  R.sp += 2; goto L_ret;                                       // 2538 ret
L_253a:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 253a mov ax, word ptr [bp - 2]
  W16(DS, (u16)(0x26c6), R.ax);                                // 253d mov word ptr [0x26c6], ax
  R.ax = (u16)(0x1);                                           // 2540 mov ax, 1
  R.sp = (u16)(R.bp);                                          // 2543 mov sp, bp
  R.bp = POP();                                                // 2545 pop bp
  R.sp += 2; goto L_ret;                                       // 2546 ret
L_ret:
  return;
}

static u16 f_1000_2518(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_2518();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:2548 FUN_1000_2548  FIX: recompiled from the machine code (asm2c)
static void a_1000_2548(void)
{
  FN(0x10002548);
  R.cs = 0x27cc;
  SUB16(M16(DS, (u16)(0x26c6)), 0xffff);                       // 2548 cmp word ptr [0x26c6], -1
  if (R.zf) goto L_256c;                                       // 254d je 0x256c
  PUSH(M16(DS, (u16)(0x26c6)));                                // 254f push word ptr [0x26c6]
  PUSH(0x2556); a_1000_513a();                                 // 2553 call 0x513a
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2556 add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 2559 or ax, ax
  if (R.zf) goto L_2566;                                       // 255b je 0x2566
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 255d sub ax, ax
  PUSH(R.ax);                                                  // 255f push ax
  PUSH(0x2563); a_1000_24c6();                                 // 2560 call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2563 add sp, 2
L_2566:   W16(DS, (u16)(0x26c6), 0xffff);                              // 2566 mov word ptr [0x26c6], 0xffff
L_256c:   R.sp += 2; goto L_ret;                                       // 256c ret
L_ret:
  return;
}

static u16 f_1000_2548(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_2548();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:256E FUN_1000_256e  FIX: recompiled from the machine code (asm2c)
static void a_1000_256e(void)
{
  FN(0x1000256E);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 256e push bp
  R.bp = (u16)(R.sp);                                          // 256f mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 2571 sub sp, 4
  SUB16(M16(DS, (u16)(0x26c6)), 0xffff);                       // 2574 cmp word ptr [0x26c6], -1
  if (!R.zf) goto L_2582;                                      // 2579 jne 0x2582
L_257b:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 257b sub ax, ax
  R.sp = (u16)(R.bp);                                          // 257d mov sp, bp
  R.bp = POP();                                                // 257f pop bp
  R.sp += 2; goto L_ret;                                       // 2580 ret
L_2582:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 2582 sub ax, ax
  PUSH(R.ax);                                                  // 2584 push ax
  PUSH(R.ax);                                                  // 2585 push ax
  PUSH(M16(DS, (u16)(0x26c6)));                                // 2586 push word ptr [0x26c6]
  PUSH(0x258d); a_1000_260a();                                 // 258a call 0x260a
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 258d add sp, 6
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 2590 or ax, ax
  if (R.zf) goto L_259d;                                       // 2592 je 0x259d
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 2594 sub ax, ax
  PUSH(R.ax);                                                  // 2596 push ax
  PUSH(0x259a); a_1000_24c6();                                 // 2597 call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 259a add sp, 2
L_259d:   R.ax = (u16)((u16)(R.bp + 0xfffe));                          // 259d lea ax, [bp - 2]
  PUSH(R.ax);                                                  // 25a0 push ax
  R.ax = (u16)(0x2);                                           // 25a1 mov ax, 2
  PUSH(R.ax);                                                  // 25a4 push ax
  R.ax = (u16)((u16)(R.bp + 0xfffc));                          // 25a5 lea ax, [bp - 4]
  PUSH(R.ss);                                                  // 25a8 push ss
  PUSH(R.ax);                                                  // 25a9 push ax
  PUSH(M16(DS, (u16)(0x26c6)));                                // 25aa push word ptr [0x26c6]
  PUSH(0x25b1); a_1000_5180();                                 // 25ae call 0x5180
  R.sp = (u16)(ADD16(R.sp, 0xa));                              // 25b1 add sp, 0xa
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 25b4 or ax, ax
  if (R.zf) goto L_25c1;                                       // 25b6 je 0x25c1
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 25b8 sub ax, ax
  PUSH(R.ax);                                                  // 25ba push ax
  PUSH(0x25be); a_1000_24c6();                                 // 25bb call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 25be add sp, 2
L_25c1:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 25c1 mov ax, word ptr [bp - 4]
  W16(SS, (u16)(R.bp + 0xfffc), DEC16(M16(SS, (u16)(R.bp + 0xfffc)))); // 25c4 dec word ptr [bp - 4]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 25c7 or ax, ax
  if (R.zf) goto L_257b;                                       // 25c9 je 0x257b
  R.ax = (u16)((u16)(R.bp + 0xfffe));                          // 25cb lea ax, [bp - 2]
  PUSH(R.ax);                                                  // 25ce push ax
  R.ax = (u16)(0x18);                                          // 25cf mov ax, 0x18
  PUSH(R.ax);                                                  // 25d2 push ax
  PUSH(R.ds);                                                  // 25d3 push ds
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 25d4 push word ptr [bp + 6]
  PUSH(M16(DS, (u16)(0x26c6)));                                // 25d7 push word ptr [0x26c6]
  PUSH(0x25de); a_1000_5180();                                 // 25db call 0x5180
  R.sp = (u16)(ADD16(R.sp, 0xa));                              // 25de add sp, 0xa
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 25e1 or ax, ax
  if (R.zf) goto L_25ee;                                       // 25e3 je 0x25ee
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 25e5 sub ax, ax
  PUSH(R.ax);                                                  // 25e7 push ax
  PUSH(0x25eb); a_1000_24c6();                                 // 25e8 call 0x24c6
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 25eb add sp, 2
L_25ee:   R.ax = (u16)(0xc);                                           // 25ee mov ax, 0xc
  PUSH(R.ax);                                                  // 25f1 push ax
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 25f2 push word ptr [bp + 4]
  PUSH(M16(SS, (u16)(R.bp + 0x6)));                            // 25f5 push word ptr [bp + 6]
  PUSH(0x25fb); a_1000_5054();                                 // 25f8 call 0x5054
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 25fb add sp, 6
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 25fe or ax, ax
  if (!R.zf) goto L_25c1;                                      // 2600 jne 0x25c1
  R.ax = (u16)(0x1);                                           // 2602 mov ax, 1
  R.sp = (u16)(R.bp);                                          // 2605 mov sp, bp
  R.bp = POP();                                                // 2607 pop bp
  R.sp += 2; goto L_ret;                                       // 2608 ret
L_ret:
  return;
}

static u16 f_1000_256e(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_256e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:260A FUN_1000_260a  FIX: recompiled from the machine code (asm2c)
static void a_1000_260a(void)
{
  FN(0x1000260A);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 260a push bp
  R.bp = (u16)(R.sp);                                          // 260b mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0xe));                              // 260d sub sp, 0xe
  W16(SS, (u16)(R.bp + 0xfff2), 0x4200);                       // 2610 mov word ptr [bp - 0xe], 0x4200
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 2615 mov ax, word ptr [bp + 4]
  W16(SS, (u16)(R.bp + 0xfff4), R.ax);                         // 2618 mov word ptr [bp - 0xc], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 261b mov ax, word ptr [bp + 8]
  W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 261e mov word ptr [bp - 0xa], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 2621 mov ax, word ptr [bp + 6]
  W16(SS, (u16)(R.bp + 0xfff8), R.ax);                         // 2624 mov word ptr [bp - 8], ax
  R.ax = (u16)((u16)(R.bp + 0xfff2));                          // 2627 lea ax, [bp - 0xe]
  PUSH(R.ax);                                                  // 262a push ax
  R.ax = (u16)((u16)(R.bp + 0xfff2));                          // 262b lea ax, [bp - 0xe]
  PUSH(R.ax);                                                  // 262e push ax
  PUSH(0x2632); a_1000_4cee();                                 // 262f call 0x4cee
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 2632 add sp, 4
  SUB16(M16(SS, (u16)(R.bp + 0xfffe)), 0x0);                   // 2635 cmp word ptr [bp - 2], 0
  if (!R.zf) goto L_2642;                                      // 2639 jne 0x2642
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 263b sub ax, ax
  R.sp = (u16)(R.bp);                                          // 263d mov sp, bp
  R.bp = POP();                                                // 263f pop bp
  R.sp += 2; goto L_ret;                                       // 2640 ret
L_2642:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfff2)));                 // 2642 mov ax, word ptr [bp - 0xe]
  R.sp = (u16)(R.bp);                                          // 2645 mov sp, bp
  R.bp = POP();                                                // 2647 pop bp
  R.sp += 2; goto L_ret;                                       // 2648 ret
L_ret:
  return;
}

static u16 f_1000_260a(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_260a();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:2A04 FUN_1000_2a04  FIX: recompiled from the machine code (asm2c)
static void a_1000_2a04(void)
{
  FN(0x10002A04);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 2a04 push bp
  R.bp = (u16)(R.sp);                                          // 2a05 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x6));                              // 2a07 sub sp, 6
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 2a0a mov ax, word ptr [bp + 6]
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 2a0d mov word ptr [bp - 4], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 2a10 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x10)));                   // 2a13 mov ax, word ptr [bx + 0x10]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 2a16 mov word ptr [bp - 2], ax
  W16(SS, (u16)(R.bp + 0xfffa), 0x0);                          // 2a19 mov word ptr [bp - 6], 0
  goto L_2a39;                                                 // 2a1e jmp 0x2a39
L_2a20:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 2a20 mov bx, word ptr [bp - 4]
  W16(SS, (u16)(R.bp + 0xfffc), INC16(M16(SS, (u16)(R.bp + 0xfffc)))); // 2a23 inc word ptr [bp - 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 2a26 mov al, byte ptr [bx]
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 2a28 sub ah, ah
  PUSH(R.ax);                                                  // 2a2a push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 2a2b push word ptr [bp - 2]
  PUSH(0x27cc); PUSH(0x2a33); du_driver(5);   /* driver slot 5 */ // 2a2e lcall 0x62a, 0x1f85
  R.sp = (u16)(ADD16(R.sp, 0x4));                              // 2a33 add sp, 4
  W16(SS, (u16)(R.bp + 0xfffa), ADD16(M16(SS, (u16)(R.bp + 0xfffa)), R.ax)); // 2a36 add word ptr [bp - 6], ax
L_2a39:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 2a39 mov bx, word ptr [bp - 4]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 2a3c cmp byte ptr [bx], 0
  if (!R.zf) goto L_2a20;                                      // 2a3f jne 0x2a20
  R.ax = (u16)(0x8);                                           // 2a41 mov ax, 8
  PUSH(R.ax);                                                  // 2a44 push ax
  PUSH(0x27cc); PUSH(0x2a4a); du_driver(14);   /* driver slot 14 */ // 2a45 lcall 0x62a, 0x1fb2
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 2a4a add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 2a4d or ax, ax
  if (R.zf) goto L_2a54;                                       // 2a4f je 0x2a54
  W16(SS, (u16)(R.bp + 0xfffa), SHR16(M16(SS, (u16)(R.bp + 0xfffa)), 0x1)); // 2a51 shr word ptr [bp - 6], 1
L_2a54:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 2a54 mov ax, word ptr [bp - 6]
  R.sp = (u16)(R.bp);                                          // 2a57 mov sp, bp
  R.bp = POP();                                                // 2a59 pop bp
  R.sp += 2; goto L_ret;                                       // 2a5a ret
L_ret:
  return;
}

static u16 f_1000_2a04(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_2a04();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:32D2 FUN_1000_32d2  FIX: recompiled from the machine code (asm2c)
static void a_1000_32d2(void)
{
  FN(0x100032D2);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 32d2 push bp
  R.bp = (u16)(R.sp);                                          // 32d3 mov bp, sp
  PUSH(R.si);                                                  // 32d5 push si
L_32d6:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 32d6 mov bx, word ptr [bp + 4]
  W16(SS, (u16)(R.bp + 0x4), INC16(M16(SS, (u16)(R.bp + 0x4)))); // 32d9 inc word ptr [bp + 4]
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 32dc mov si, word ptr [bp + 6]
  W16(SS, (u16)(R.bp + 0x6), INC16(M16(SS, (u16)(R.bp + 0x6)))); // 32df inc word ptr [bp + 6]
  SETL(R.ax, M8(DS, (u16)(R.si)));                             // 32e2 mov al, byte ptr [si]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 32e4 mov byte ptr [bx], al
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 32e6 or al, al
  if (!R.zf) goto L_32d6;                                      // 32e8 jne 0x32d6
  R.si = POP();                                                // 32ea pop si
  R.bp = POP();                                                // 32eb pop bp
  R.sp += 2; goto L_ret;                                       // 32ec ret
L_ret:
  return;
}

static u16 f_1000_32d2(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_32d2();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:331F FUN_1000_331f  FIX: recompiled from the machine code (asm2c)
static void a_1000_331f(void)
{
  FN(0x1000331F);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 331f push bp
  R.bp = (u16)(R.sp);                                          // 3320 mov bp, sp
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3322 mov ax, word ptr [bp + 4]
L_3325:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3325 mov bx, word ptr [bp + 4]
  W16(SS, (u16)(R.bp + 0x4), INC16(M16(SS, (u16)(R.bp + 0x4)))); // 3328 inc word ptr [bp + 4]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 332b cmp byte ptr [bx], 0
  if (!R.zf) goto L_3325;                                      // 332e jne 0x3325
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3330 mov bx, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, R.bx));                             // 3333 sub ax, bx
  R.ax = (u16)((u16)~R.ax);                                    // 3335 not ax
  R.sp = (u16)(R.bp);                                          // 3337 mov sp, bp
  R.bp = POP();                                                // 3339 pop bp
  R.sp += 2; goto L_ret;                                       // 333a ret
L_ret:
  return;
}

static u16 f_1000_331f(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_331f();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3351 FUN_1000_3351  FIX: recompiled from the machine code (asm2c)
static void a_1000_3351(void)
{
  FN(0x10003351);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 3351 push bp
  R.bp = (u16)(R.sp);                                          // 3352 mov bp, sp
  PUSH(R.si);                                                  // 3354 push si
L_3355:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3355 mov bx, word ptr [bp + 4]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 3358 cmp byte ptr [bx], 0
  if (R.zf) goto L_3368;                                       // 335b je 0x3368
  W16(SS, (u16)(R.bp + 0x4), INC16(M16(SS, (u16)(R.bp + 0x4)))); // 335d inc word ptr [bp + 4]
  goto L_3355;                                                 // 3360 jmp 0x3355
L_3362:   W16(SS, (u16)(R.bp + 0x4), INC16(M16(SS, (u16)(R.bp + 0x4)))); // 3362 inc word ptr [bp + 4]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3365 mov bx, word ptr [bp + 4]
L_3368:   R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 3368 mov si, word ptr [bp + 6]
  W16(SS, (u16)(R.bp + 0x6), INC16(M16(SS, (u16)(R.bp + 0x6)))); // 336b inc word ptr [bp + 6]
  SETL(R.ax, M8(DS, (u16)(R.si)));                             // 336e mov al, byte ptr [si]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 3370 mov byte ptr [bx], al
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 3372 or al, al
  if (!R.zf) goto L_3362;                                      // 3374 jne 0x3362
  R.si = POP();                                                // 3376 pop si
  R.bp = POP();                                                // 3377 pop bp
  R.sp += 2; goto L_ret;                                       // 3378 ret
L_ret:
  return;
}

static u16 f_1000_3351(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_3351();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:342D FUN_1000_342d  FIX: recompiled from the machine code (asm2c)
static void a_1000_342d(void)
{
  FN(0x1000342D);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 342d push bp
  R.bp = (u16)(R.sp);                                          // 342e mov bp, sp
  PUSH(R.si);                                                  // 3430 push si
  PUSH(R.di);                                                  // 3431 push di
  PUSH(R.ax);                                                  // 3432 push ax
  PUSH(R.bx);                                                  // 3433 push bx
  PUSH(R.cx);                                                  // 3434 push cx
  PUSH(R.dx);                                                  // 3435 push dx
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 3436 mov di, word ptr [bp + 6]
  R.ax = (u16)(M16(DS, (u16)(R.di)));                          // 3439 mov ax, word ptr [di]
  R.bx = (u16)(M16(DS, (u16)(R.di + 0x2)));                    // 343b mov bx, word ptr [di + 2]
  R.cx = (u16)(M16(DS, (u16)(R.di + 0x4)));                    // 343e mov cx, word ptr [di + 4]
  R.dx = (u16)(M16(DS, (u16)(R.di + 0x6)));                    // 3441 mov dx, word ptr [di + 6]
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x10);                     // 3444 cmp word ptr [bp + 4], 0x10
  if (R.zf) goto L_345f;                                       // 3448 je 0x345f
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x21);                     // 344a cmp word ptr [bp + 4], 0x21
  if (R.zf) goto L_3464;                                       // 344e je 0x3464
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x16);                     // 3450 cmp word ptr [bp + 4], 0x16
  if (R.zf) goto L_3469;                                       // 3454 je 0x3469
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x1a);                     // 3456 cmp word ptr [bp + 4], 0x1a
  if (R.zf) goto L_346e;                                       // 345a je 0x346e
  goto L_3473;                                                 // 345c jmp 0x3473
L_345f:   ASM_INT(0x10);                                               // 345f int 0x10
  goto L_347a;                                                 // 3461 jmp 0x347a
L_3464:   ASM_INT(0x21);                                               // 3464 int 0x21
  goto L_347a;                                                 // 3466 jmp 0x347a
L_3469:   ASM_INT(0x16);                                               // 3469 int 0x16
  goto L_347a;                                                 // 346b jmp 0x347a
L_346e:   ASM_INT(0x1a);                                               // 346e int 0x1a
  goto L_347a;                                                 // 3470 jmp 0x347a
L_3473:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 3473 sub ax, ax
  R.ax = (u16)((u16)~R.ax);                                    // 3475 not ax
  goto L_3488;                                                 // 3477 jmp 0x3488
L_347a:   R.di = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 347a mov di, word ptr [bp + 8]
  W16(DS, (u16)(R.di), R.ax);                                  // 347d mov word ptr [di], ax
  W16(DS, (u16)(R.di + 0x2), R.bx);                            // 347f mov word ptr [di + 2], bx
  W16(DS, (u16)(R.di + 0x4), R.cx);                            // 3482 mov word ptr [di + 4], cx
  W16(DS, (u16)(R.di + 0x6), R.dx);                            // 3485 mov word ptr [di + 6], dx
L_3488:   R.dx = POP();                                                // 3488 pop dx
  R.cx = POP();                                                // 3489 pop cx
  R.bx = POP();                                                // 348a pop bx
  R.ax = POP();                                                // 348b pop ax
  R.di = POP();                                                // 348c pop di
  R.si = POP();                                                // 348d pop si
  R.sp = (u16)(R.bp);                                          // 348e mov sp, bp
  R.bp = POP();                                                // 3490 pop bp
  R.sp += 2; goto L_ret;                                       // 3491 ret
L_ret:
  return;
}

static u16 f_1000_342d(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_342d();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3492 FUN_1000_3492  FIX: recompiled from the machine code (asm2c)
static void a_1000_3492(void)
{
  FN(0x10003492);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 3492 push bp
  R.bp = (u16)(R.sp);                                          // 3493 mov bp, sp
  PUSH(R.si);                                                  // 3495 push si
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 3496 mov bx, word ptr [bp + 6]
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 3499 mov ax, word ptr [bp + 8]
  SUB16(R.ax, 0xa);                                            // 349c cmp ax, 0xa
  if (R.zf) goto L_34ae;                                       // 349f je 0x34ae
  SUB16(R.ax, 0x2);                                            // 34a1 cmp ax, 2
  if (R.zf) goto L_34ba;                                       // 34a4 je 0x34ba
  SUB16(R.ax, 0x10);                                           // 34a6 cmp ax, 0x10
  if (R.zf) goto L_34b4;                                       // 34a9 je 0x34b4
  goto L_34c0;                                                 // 34ab jmp 0x34c0
L_34ae:   PUSH(0x34b1); a_1000_34d2();                                 // 34ae call 0x34d2
  goto L_34ca;                                                 // 34b1 jmp 0x34ca
L_34b4:   PUSH(0x34b7); a_1000_34fd();                                 // 34b4 call 0x34fd
  goto L_34ca;                                                 // 34b7 jmp 0x34ca
L_34ba:   PUSH(0x34bd); a_1000_3545();                                 // 34ba call 0x3545
  goto L_34ca;                                                 // 34bd jmp 0x34ca
L_34c0:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 34c0 mov bx, word ptr [bp + 6]
  W16(DS, (u16)(R.bx), 0x0);                                   // 34c3 mov word ptr [bx], 0
  R.ax = (u16)(0x0);                                           // 34c7 mov ax, 0
L_34ca:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 34ca mov ax, word ptr [bp + 6]
  R.si = POP();                                                // 34cd pop si
  R.sp = (u16)(R.bp);                                          // 34ce mov sp, bp
  R.bp = POP();                                                // 34d0 pop bp
  R.sp += 2; goto L_ret;                                       // 34d1 ret
L_ret:
  return;
}

static u16 f_1000_3492(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_3492();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:34D2 FUN_1000_34d2  FIX: recompiled from the machine code (asm2c)
static void a_1000_34d2(void)
{
  FN(0x100034D2);
  R.cs = 0x27cc;
  R.cx = (u16)(SUB16(R.cx, R.cx));                             // 34d2 sub cx, cx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 34d4 mov ax, word ptr [bp + 4]
  R.si = (u16)(0xa);                                           // 34d7 mov si, 0xa
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 34da or ax, ax
  if (!R.sf) goto L_34e4;                                      // 34dc jns 0x34e4
  W8(DS, (u16)(R.bx), 0x2d);                                   // 34de mov byte ptr [bx], 0x2d
  R.bx = (u16)(INC16(R.bx));                                   // 34e1 inc bx
  R.ax = (u16)(NEG16(R.ax));                                   // 34e2 neg ax
L_34e4:   R.dx = (u16)(SUB16(R.dx, R.dx));                             // 34e4 sub dx, dx
  DIV16(R.si, 0x34e6);                                         // 34e6 div si
  R.dx = (u16)(ADD16(R.dx, 0x30));                             // 34e8 add dx, 0x30
  PUSH(R.dx);                                                  // 34eb push dx
  R.cx = (u16)(INC16(R.cx));                                   // 34ec inc cx
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 34ed or ax, ax
  if (!R.zf) goto L_34e4;                                      // 34ef jne 0x34e4
  R.ax = (u16)(R.cx);                                          // 34f1 mov ax, cx
L_34f3:   R.dx = POP();                                                // 34f3 pop dx
  W8(DS, (u16)(R.bx), (u8)R.dx);                               // 34f4 mov byte ptr [bx], dl
  R.bx = (u16)(INC16(R.bx));                                   // 34f6 inc bx
  if (--R.cx != 0) goto L_34f3;                                // 34f7 loop 0x34f3
  W8(DS, (u16)(R.bx), 0x0);                                    // 34f9 mov byte ptr [bx], 0
  R.sp += 2; goto L_ret;                                       // 34fc ret
L_ret:
  return;
}

static u16 f_1000_34d2(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_34d2();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:34FD FUN_1000_34fd  FIX: recompiled from the machine code (asm2c)
static void a_1000_34fd(void)
{
  FN(0x100034FD);
  R.cs = 0x27cc;
  R.cx = (u16)(0x4);                                           // 34fd mov cx, 4
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3500 mov ax, word ptr [bp + 4]
  SETH(R.ax, AND8((u8)(R.ax >> 8), 0xf0));                     // 3503 and ah, 0xf0
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 3506 mov al, ah
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 3508 sub ah, ah
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 350a shr ax, cl
  R.ax = (u16)(ADD16(R.ax, 0x30));                             // 350c add ax, 0x30
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 350f mov byte ptr [bx], al
  R.bx = (u16)(INC16(R.bx));                                   // 3511 inc bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3512 mov ax, word ptr [bp + 4]
  SETH(R.ax, AND8((u8)(R.ax >> 8), 0xf));                      // 3515 and ah, 0xf
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 3518 mov al, ah
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 351a sub ah, ah
  R.ax = (u16)(ADD16(R.ax, 0x30));                             // 351c add ax, 0x30
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 351f mov byte ptr [bx], al
  R.bx = (u16)(INC16(R.bx));                                   // 3521 inc bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3522 mov ax, word ptr [bp + 4]
  SETL(R.ax, AND8((u8)R.ax, 0xf0));                            // 3525 and al, 0xf0
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 3527 sub ah, ah
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 3529 shr ax, cl
  R.ax = (u16)(ADD16(R.ax, 0x30));                             // 352b add ax, 0x30
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 352e mov byte ptr [bx], al
  R.bx = (u16)(INC16(R.bx));                                   // 3530 inc bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3531 mov ax, word ptr [bp + 4]
  SETL(R.ax, AND8((u8)R.ax, 0xf));                             // 3534 and al, 0xf
  SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 3536 sub ah, ah
  R.ax = (u16)(ADD16(R.ax, 0x30));                             // 3538 add ax, 0x30
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 353b mov byte ptr [bx], al
  R.bx = (u16)(INC16(R.bx));                                   // 353d inc bx
  W8(DS, (u16)(R.bx), 0x0);                                    // 353e mov byte ptr [bx], 0
  R.ax = (u16)(0x4);                                           // 3541 mov ax, 4
  R.sp += 2; goto L_ret;                                       // 3544 ret
L_ret:
  return;
}

static u16 f_1000_34fd(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_34fd();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3545 FUN_1000_3545  FIX: recompiled from the machine code (asm2c)
static void a_1000_3545(void)
{
  FN(0x10003545);
  R.cs = 0x27cc;
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3545 mov dx, word ptr [bp + 4]
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 3548 sub ax, ax
  SETH(R.ax, 0x80);                                            // 354a mov ah, 0x80
L_354c:   AND16(R.ax, R.dx);                                           // 354c test ax, dx
  if (!R.zf) goto L_3557;                                      // 354e jne 0x3557
  W8(DS, (u16)(R.bx), 0x30);                                   // 3550 mov byte ptr [bx], 0x30
  R.bx = (u16)(INC16(R.bx));                                   // 3553 inc bx
  goto L_355b;                                                 // 3554 jmp 0x355b
L_3557:   W8(DS, (u16)(R.bx), 0x31);                                   // 3557 mov byte ptr [bx], 0x31
  R.bx = (u16)(INC16(R.bx));                                   // 355a inc bx
L_355b:   R.ax = (u16)(SHR16(R.ax, 0x1));                              // 355b shr ax, 1
  if (!R.cf) goto L_354c;                                      // 355d jae 0x354c
  W8(DS, (u16)(R.bx), 0x0);                                    // 355f mov byte ptr [bx], 0
  R.ax = (u16)(0x10);                                          // 3562 mov ax, 0x10
  R.sp += 2; goto L_ret;                                       // 3565 ret
L_ret:
  return;
}

static u16 f_1000_3545(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_3545();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:35BE FUN_1000_35be  FIX: recompiled from the machine code (asm2c)
static void a_1000_35be(void)
{
  FN(0x100035BE);
  R.cs = 0x27cc;
  SETH(R.ax, 0x30);                                            // 35be mov ah, 0x30
  ASM_INT(0x21);                                               // 35c0 int 0x21
  SUB8((u8)R.ax, 0x2);                                         // 35c2 cmp al, 2
  if (!R.cf) goto L_35c8;                                      // 35c4 jae 0x35c8
  ASM_INT(0x20);                                               // 35c6 int 0x20
L_35c8:   R.di = (u16)(0x2df6 /* segment */);                          // 35c8 mov di, 0x62a
  R.si = (u16)(M16(DS, (u16)(0x2)));                           // 35cb mov si, word ptr [2]
  R.si = (u16)(SUB16(R.si, R.di));                             // 35cf sub si, di
  SUB16(R.si, 0x1000);                                         // 35d1 cmp si, 0x1000
  if (R.cf) goto L_35da;                                       // 35d5 jb 0x35da
  R.si = (u16)(0x1000);                                        // 35d7 mov si, 0x1000
L_35da:                                                                // 35da cli
  R.ss = (u16)(R.di);                                          // 35db mov ss, di
  R.sp = (u16)(ADD16(R.sp, 0x640e));                           // 35dd add sp, 0x640e
  // 35e1 sti 
  if (!R.cf) goto L_35f4;                                      // 35e2 jae 0x35f4
  PUSH(R.ss);                                                  // 35e4 push ss
  R.ds = POP();                                                // 35e5 pop ds
  PUSH(0x35e9); a_1000_37e0();                                 // 35e6 call 0x37e0
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 35e9 xor ax, ax
  PUSH(R.ax);                                                  // 35eb push ax
  PUSH(0x35ef); a_1000_3a65();                                 // 35ec call 0x3a65
  R.ax = (u16)(0x4cff);                                        // 35ef mov ax, 0x4cff
  ASM_INT(0x21);                                               // 35f2 int 0x21
L_35f4:   R.sp = (u16)(AND16(R.sp, 0xfffe));                           // 35f4 and sp, 0xfffe
  W16(SS, (u16)(0x26e6), R.sp);                                // 35f7 mov word ptr ss:[0x26e6], sp
  W16(SS, (u16)(0x26e2), R.sp);                                // 35fc mov word ptr ss:[0x26e2], sp
  R.ax = (u16)(R.si);                                          // 3601 mov ax, si
  SETL(R.cx, 0x4);                                             // 3603 mov cl, 4
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 3605 shl ax, cl
  R.ax = (u16)(DEC16(R.ax));                                   // 3607 dec ax
  W16(SS, (u16)(0x26e0), R.ax);                                // 3608 mov word ptr ss:[0x26e0], ax
  R.si = (u16)(ADD16(R.si, R.di));                             // 360c add si, di
  W16(DS, (u16)(0x2), R.si);                                   // 360e mov word ptr [2], si
  R.bx = (u16)(R.es);                                          // 3612 mov bx, es
  R.bx = (u16)(SUB16(R.bx, R.si));                             // 3614 sub bx, si
  R.bx = (u16)(NEG16(R.bx));                                   // 3616 neg bx
  SETH(R.ax, 0x4a);                                            // 3618 mov ah, 0x4a
  ASM_INT(0x21);                                               // 361a int 0x21
  W16(SS, (u16)(0x2757), R.ds);                                // 361c mov word ptr ss:[0x2757], ds
  PUSH(R.ss);                                                  // 3621 push ss
  R.es = POP();                                                // 3622 pop es
  R.df = 0;                                                    // 3623 cld
  R.di = (u16)(0x2cd6);                                        // 3624 mov di, 0x2cd6
  R.cx = (u16)(0x6410);                                        // 3627 mov cx, 0x6410
  R.cx = (u16)(SUB16(R.cx, R.di));                             // 362a sub cx, di
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 362c xor ax, ax
  REPSTOSB();                                                  // 362e rep stosb byte ptr es:[di], al
  PUSH(R.ss);                                                  // 3630 push ss
  R.ds = POP();                                                // 3631 pop ds
  PUSH(0x3635); a_1000_3670();                                 // 3632 call 0x3670
  PUSH(R.ss);                                                  // 3635 push ss
  R.ds = POP();                                                // 3636 pop ds
  PUSH(0x363a); a_1000_39cc();                                 // 3637 call 0x39cc
  PUSH(0x363d); a_1000_383e();                                 // 363a call 0x383e
  R.bp = (u16)(XOR16(R.bp, R.bp));                             // 363d xor bp, bp
  PUSH(M16(DS, (u16)(0x2778)));                                // 363f push word ptr [0x2778]
  PUSH(M16(DS, (u16)(0x2776)));                                // 3643 push word ptr [0x2776]
  PUSH(M16(DS, (u16)(0x2774)));                                // 3647 push word ptr [0x2774]
  PUSH(0x364e); a_1000_0010();                                 // 364b call 0x10
  PUSH(R.ax);                                                  // 364e push ax
  CALL_BEGIN(4); du_exit((i16)ARG(0)); CALL_END();             // 364f call 0x3734
  R.ax = (u16)(0x2df6 /* segment */);                          // 3652 mov ax, 0x62a
  R.ds = (u16)(R.ax);                                          // 3655 mov ds, ax
  R.ax = (u16)(0x3);                                           // 3657 mov ax, 3
  W16(SS, (u16)(0x26e4), 0x3734);                              // 365a mov word ptr ss:[0x26e4], 0x3734
L_3661:   PUSH(R.ax);                                                  // 3661 push ax
  PUSH(0x3665); a_1000_37e0();                                 // 3662 call 0x37e0
  PUSH(0x3668); a_1000_3a65();                                 // 3665 call 0x3a65
  R.ax = (u16)(0xff);                                          // 3668 mov ax, 0xff
  PUSH(R.ax);                                                  // 366b push ax
  ASM_INDIRECT_CALL(M16(DS, (u16)(0x26e4))); /* call word ptr [0x26e4] */ // 366c call word ptr [0x26e4]
L_3670:   FN(0x10003670); SETH(R.ax, 0x30);                            // 3670 mov ah, 0x30
  ASM_INT(0x21);                                               // 3672 int 0x21
  W16(DS, (u16)(0x2759), R.ax);                                // 3674 mov word ptr [0x2759], ax
  R.ax = (u16)(0x3500);                                        // 3677 mov ax, 0x3500
  ASM_INT(0x21);                                               // 367a int 0x21
  W16(DS, (u16)(0x2745), R.bx);                                // 367c mov word ptr [0x2745], bx
  W16(DS, (u16)(0x2747), R.es);                                // 3680 mov word ptr [0x2747], es
  PUSH(R.cs);                                                  // 3684 push cs
  R.ds = POP();                                                // 3685 pop ds
  R.ax = (u16)(0x2500);                                        // 3686 mov ax, 0x2500
  R.dx = (u16)(0x3652);                                        // 3689 mov dx, 0x3652
  ASM_INT(0x21);                                               // 368c int 0x21
  PUSH(R.ss);                                                  // 368e push ss
  R.ds = POP();                                                // 368f pop ds
  R.cx = (u16)(M16(DS, (u16)(0x2bf0)));                        // 3690 mov cx, word ptr [0x2bf0]
  if (R.cx == 0) goto L_36c4;                                  // 3694 jcxz 0x36c4
  R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 3696 mov es, word ptr [0x2757]
  R.si = (u16)(M16(ES, (u16)(0x2c)));                          // 369a mov si, word ptr es:[0x2c]
  { u16 a_ = (u16)(0x2bf2); R.ax = (u16)(M16(DS, a_)); R.ds = M16(DS, (u16)(a_ + 2)); } // 369f lds ax, ptr [0x2bf2]
  R.dx = (u16)(R.ds);                                          // 36a3 mov dx, ds
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 36a5 xor bx, bx
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36ac); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36a7 lcall ss:[0x2bee]
  if (!R.cf) goto L_36b3;                                      // 36ac jae 0x36b3
  PUSH(R.ss);                                                  // 36ae push ss
  R.ds = POP();                                                // 36af pop ds
  goto L_3800;                                                 // 36b0 jmp 0x3800
L_36b3:   { u16 a_ = (u16)(0x2bf6); R.ax = (u16)(M16(SS, a_)); R.ds = M16(SS, (u16)(a_ + 2)); } // 36b3 lds ax, ptr ss:[0x2bf6]
  R.dx = (u16)(R.ds);                                          // 36b8 mov dx, ds
  R.bx = (u16)(0x3);                                           // 36ba mov bx, 3
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36c2); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36bd lcall ss:[0x2bee]
  PUSH(R.ss);                                                  // 36c2 push ss
  R.ds = POP();                                                // 36c3 pop ds
L_36c4:   R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 36c4 mov es, word ptr [0x2757]
  R.cx = (u16)(M16(ES, (u16)(0x2c)));                          // 36c8 mov cx, word ptr es:[0x2c]
  if (R.cx == 0) goto L_3705;                                  // 36cd jcxz 0x3705
  R.es = (u16)(R.cx);                                          // 36cf mov es, cx
  R.di = (u16)(XOR16(R.di, R.di));                             // 36d1 xor di, di
L_36d3:   SUB8(M8(ES, (u16)(R.di)), 0x0);                              // 36d3 cmp byte ptr es:[di], 0
  if (R.zf) goto L_3705;                                       // 36d7 je 0x3705
  R.cx = (u16)(0xc);                                           // 36d9 mov cx, 0xc
  R.si = (u16)(0x2738);                                        // 36dc mov si, 0x2738
  REPECMPSB();                                                 // 36df repe cmpsb byte ptr [si], byte ptr es:[di]
  if (R.zf) goto L_36ee;                                       // 36e1 je 0x36ee
  R.cx = (u16)(0x7fff);                                        // 36e3 mov cx, 0x7fff
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 36e6 xor ax, ax
  REPNESCASB();                                                // 36e8 repne scasb al, byte ptr es:[di]
  if (!R.zf) goto L_3705;                                      // 36ea jne 0x3705
  goto L_36d3;                                                 // 36ec jmp 0x36d3
L_36ee:   PUSH(R.es);                                                  // 36ee push es
  PUSH(R.ds);                                                  // 36ef push ds
  R.es = POP();                                                // 36f0 pop es
  R.ds = POP();                                                // 36f1 pop ds
  R.si = (u16)(R.di);                                          // 36f2 mov si, di
  R.di = (u16)(0x2760);                                        // 36f4 mov di, 0x2760
  LODSB();                                                     // 36f7 lodsb al, byte ptr [si]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 36f8 cwde
  { u16 t_ = R.cx; R.cx = (u16)(R.ax); R.ax = (u16)(t_); }     // 36f9 xchg cx, ax
L_36fa:   LODSB();                                                     // 36fa lodsb al, byte ptr [si]
  SETL(R.ax, INC8((u8)R.ax));                                  // 36fb inc al
  if (R.zf) goto L_3700;                                       // 36fd je 0x3700
  R.ax = (u16)(DEC16(R.ax));                                   // 36ff dec ax
L_3700:   STOSB();                                                     // 3700 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_36fa;                                // 3701 loop 0x36fa
  PUSH(R.ss);                                                  // 3703 push ss
  R.ds = POP();                                                // 3704 pop ds
L_3705:   R.bx = (u16)(0x4);                                           // 3705 mov bx, 4
L_3708:   W8(DS, (u16)(R.bx + 0x2760), AND8(M8(DS, (u16)(R.bx + 0x2760)), 0xbf)); // 3708 and byte ptr [bx + 0x2760], 0xbf
  R.ax = (u16)(0x4400);                                        // 370d mov ax, 0x4400
  ASM_INT(0x21);                                               // 3710 int 0x21
  if (R.cf) goto L_371e;                                       // 3712 jb 0x371e
  AND8((u8)R.dx, 0x80);                                        // 3714 test dl, 0x80
  if (R.zf) goto L_371e;                                       // 3717 je 0x371e
  W8(DS, (u16)(R.bx + 0x2760), OR8(M8(DS, (u16)(R.bx + 0x2760)), 0x40)); // 3719 or byte ptr [bx + 0x2760], 0x40
L_371e:   R.bx = (u16)(DEC16(R.bx));                                   // 371e dec bx
  if (!R.sf) goto L_3708;                                      // 371f jns 0x3708
  R.si = (u16)(0x2bfa);                                        // 3721 mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 3724 mov di, 0x2bfa
  PUSH(0x372a); a_1000_37cc();                                 // 3727 call 0x37cc
  R.si = (u16)(0x2bfa);                                        // 372a mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 372d mov di, 0x2bfa
  PUSH(0x3733); a_1000_37bd();                                 // 3730 call 0x37bd
  R.sp += 2; goto L_ret;                                       // 3733 ret
L_3800:   R.ax = (u16)(0x2);                                           // 3800 mov ax, 2
  goto L_3661;                                                 // 3803 jmp 0x3661
L_ret:
  return;
}

static u16 f_1000_35be(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_35be();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3670 FUN_1000_3670  FIX: recompiled from the machine code (asm2c)
static void a_1000_3670(void)
{
  FN(0x10003670);
  R.cs = 0x27cc;
  goto L_3670;
L_3661:   PUSH(R.ax);                                                  // 3661 push ax
  PUSH(0x3665); a_1000_37e0();                                 // 3662 call 0x37e0
  PUSH(0x3668); a_1000_3a65();                                 // 3665 call 0x3a65
  R.ax = (u16)(0xff);                                          // 3668 mov ax, 0xff
  PUSH(R.ax);                                                  // 366b push ax
  ASM_INDIRECT_CALL(M16(DS, (u16)(0x26e4))); /* call word ptr [0x26e4] */ // 366c call word ptr [0x26e4]
L_3670:   SETH(R.ax, 0x30);                                            // 3670 mov ah, 0x30
  ASM_INT(0x21);                                               // 3672 int 0x21
  W16(DS, (u16)(0x2759), R.ax);                                // 3674 mov word ptr [0x2759], ax
  R.ax = (u16)(0x3500);                                        // 3677 mov ax, 0x3500
  ASM_INT(0x21);                                               // 367a int 0x21
  W16(DS, (u16)(0x2745), R.bx);                                // 367c mov word ptr [0x2745], bx
  W16(DS, (u16)(0x2747), R.es);                                // 3680 mov word ptr [0x2747], es
  PUSH(R.cs);                                                  // 3684 push cs
  R.ds = POP();                                                // 3685 pop ds
  R.ax = (u16)(0x2500);                                        // 3686 mov ax, 0x2500
  R.dx = (u16)(0x3652);                                        // 3689 mov dx, 0x3652
  ASM_INT(0x21);                                               // 368c int 0x21
  PUSH(R.ss);                                                  // 368e push ss
  R.ds = POP();                                                // 368f pop ds
  R.cx = (u16)(M16(DS, (u16)(0x2bf0)));                        // 3690 mov cx, word ptr [0x2bf0]
  if (R.cx == 0) goto L_36c4;                                  // 3694 jcxz 0x36c4
  R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 3696 mov es, word ptr [0x2757]
  R.si = (u16)(M16(ES, (u16)(0x2c)));                          // 369a mov si, word ptr es:[0x2c]
  { u16 a_ = (u16)(0x2bf2); R.ax = (u16)(M16(DS, a_)); R.ds = M16(DS, (u16)(a_ + 2)); } // 369f lds ax, ptr [0x2bf2]
  R.dx = (u16)(R.ds);                                          // 36a3 mov dx, ds
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 36a5 xor bx, bx
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36ac); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36a7 lcall ss:[0x2bee]
  if (!R.cf) goto L_36b3;                                      // 36ac jae 0x36b3
  PUSH(R.ss);                                                  // 36ae push ss
  R.ds = POP();                                                // 36af pop ds
  goto L_3800;                                                 // 36b0 jmp 0x3800
L_36b3:   { u16 a_ = (u16)(0x2bf6); R.ax = (u16)(M16(SS, a_)); R.ds = M16(SS, (u16)(a_ + 2)); } // 36b3 lds ax, ptr ss:[0x2bf6]
  R.dx = (u16)(R.ds);                                          // 36b8 mov dx, ds
  R.bx = (u16)(0x3);                                           // 36ba mov bx, 3
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36c2); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36bd lcall ss:[0x2bee]
  PUSH(R.ss);                                                  // 36c2 push ss
  R.ds = POP();                                                // 36c3 pop ds
L_36c4:   R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 36c4 mov es, word ptr [0x2757]
  R.cx = (u16)(M16(ES, (u16)(0x2c)));                          // 36c8 mov cx, word ptr es:[0x2c]
  if (R.cx == 0) goto L_3705;                                  // 36cd jcxz 0x3705
  R.es = (u16)(R.cx);                                          // 36cf mov es, cx
  R.di = (u16)(XOR16(R.di, R.di));                             // 36d1 xor di, di
L_36d3:   SUB8(M8(ES, (u16)(R.di)), 0x0);                              // 36d3 cmp byte ptr es:[di], 0
  if (R.zf) goto L_3705;                                       // 36d7 je 0x3705
  R.cx = (u16)(0xc);                                           // 36d9 mov cx, 0xc
  R.si = (u16)(0x2738);                                        // 36dc mov si, 0x2738
  REPECMPSB();                                                 // 36df repe cmpsb byte ptr [si], byte ptr es:[di]
  if (R.zf) goto L_36ee;                                       // 36e1 je 0x36ee
  R.cx = (u16)(0x7fff);                                        // 36e3 mov cx, 0x7fff
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 36e6 xor ax, ax
  REPNESCASB();                                                // 36e8 repne scasb al, byte ptr es:[di]
  if (!R.zf) goto L_3705;                                      // 36ea jne 0x3705
  goto L_36d3;                                                 // 36ec jmp 0x36d3
L_36ee:   PUSH(R.es);                                                  // 36ee push es
  PUSH(R.ds);                                                  // 36ef push ds
  R.es = POP();                                                // 36f0 pop es
  R.ds = POP();                                                // 36f1 pop ds
  R.si = (u16)(R.di);                                          // 36f2 mov si, di
  R.di = (u16)(0x2760);                                        // 36f4 mov di, 0x2760
  LODSB();                                                     // 36f7 lodsb al, byte ptr [si]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 36f8 cwde
  { u16 t_ = R.cx; R.cx = (u16)(R.ax); R.ax = (u16)(t_); }     // 36f9 xchg cx, ax
L_36fa:   LODSB();                                                     // 36fa lodsb al, byte ptr [si]
  SETL(R.ax, INC8((u8)R.ax));                                  // 36fb inc al
  if (R.zf) goto L_3700;                                       // 36fd je 0x3700
  R.ax = (u16)(DEC16(R.ax));                                   // 36ff dec ax
L_3700:   STOSB();                                                     // 3700 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_36fa;                                // 3701 loop 0x36fa
  PUSH(R.ss);                                                  // 3703 push ss
  R.ds = POP();                                                // 3704 pop ds
L_3705:   R.bx = (u16)(0x4);                                           // 3705 mov bx, 4
L_3708:   W8(DS, (u16)(R.bx + 0x2760), AND8(M8(DS, (u16)(R.bx + 0x2760)), 0xbf)); // 3708 and byte ptr [bx + 0x2760], 0xbf
  R.ax = (u16)(0x4400);                                        // 370d mov ax, 0x4400
  ASM_INT(0x21);                                               // 3710 int 0x21
  if (R.cf) goto L_371e;                                       // 3712 jb 0x371e
  AND8((u8)R.dx, 0x80);                                        // 3714 test dl, 0x80
  if (R.zf) goto L_371e;                                       // 3717 je 0x371e
  W8(DS, (u16)(R.bx + 0x2760), OR8(M8(DS, (u16)(R.bx + 0x2760)), 0x40)); // 3719 or byte ptr [bx + 0x2760], 0x40
L_371e:   R.bx = (u16)(DEC16(R.bx));                                   // 371e dec bx
  if (!R.sf) goto L_3708;                                      // 371f jns 0x3708
  R.si = (u16)(0x2bfa);                                        // 3721 mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 3724 mov di, 0x2bfa
  PUSH(0x372a); a_1000_37cc();                                 // 3727 call 0x37cc
  R.si = (u16)(0x2bfa);                                        // 372a mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 372d mov di, 0x2bfa
  PUSH(0x3733); a_1000_37bd();                                 // 3730 call 0x37bd
  R.sp += 2; goto L_ret;                                       // 3733 ret
L_3800:   R.ax = (u16)(0x2);                                           // 3800 mov ax, 2
  goto L_3661;                                                 // 3803 jmp 0x3661
L_ret:
  return;
}

static u16 f_1000_3670(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_3670();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:37BD FUN_1000_37bd  FIX: recompiled from the machine code (asm2c)
static void a_1000_37bd(void)
{
  FN(0x100037BD);
  R.cs = 0x27cc;
L_37bd:   SUB16(R.si, R.di);                                           // 37bd cmp si, di
  if (!R.cf) goto L_37cb;                                      // 37bf jae 0x37cb
  R.di = (u16)(DEC16(R.di));                                   // 37c1 dec di
  R.di = (u16)(DEC16(R.di));                                   // 37c2 dec di
  R.cx = (u16)(M16(DS, (u16)(R.di)));                          // 37c3 mov cx, word ptr [di]
  if (R.cx == 0) goto L_37bd;                                  // 37c5 jcxz 0x37bd
  ASM_INDIRECT_CALL(R.cx); /* call cx */                       // 37c7 call cx
  goto L_37bd;                                                 // 37c9 jmp 0x37bd
L_37cb:   R.sp += 2; goto L_ret;                                       // 37cb ret
L_ret:
  return;
}

static u16 f_1000_37bd(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_37bd();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:37CC FUN_1000_37cc  FIX: recompiled from the machine code (asm2c)
static void a_1000_37cc(void)
{
  FN(0x100037CC);
  R.cs = 0x27cc;
L_37cc:   SUB16(R.si, R.di);                                           // 37cc cmp si, di
  if (!R.cf) goto L_37de;                                      // 37ce jae 0x37de
  R.di = (u16)(SUB16(R.di, 0x4));                              // 37d0 sub di, 4
  R.ax = (u16)(M16(DS, (u16)(R.di)));                          // 37d3 mov ax, word ptr [di]
  R.ax = (u16)(OR16(R.ax, M16(DS, (u16)(R.di + 0x2))));        // 37d5 or ax, word ptr [di + 2]
  if (R.zf) goto L_37cc;                                       // 37d8 je 0x37cc
  { u16 o_ = M16(DS, (u16)(R.di)), s_ = M16(DS, (u16)((u16)(R.di) + 2)); PUSH(0x27cc); PUSH(0x37dc); du_far_call(s_, o_); } /* lcall [di] */ // 37da lcall [di]
  goto L_37cc;                                                 // 37dc jmp 0x37cc
L_37de:   R.sp += 2; goto L_ret;                                       // 37de ret
L_ret:
  return;
}

static u16 f_1000_37cc(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_37cc();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:37E0 FUN_1000_37e0  FIX: recompiled from the machine code (asm2c)
static void a_1000_37e0(void)
{
  FN(0x100037E0);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 37e0 push bp
  R.bp = (u16)(R.sp);                                          // 37e1 mov bp, sp
  R.ax = (u16)(0xfc);                                          // 37e3 mov ax, 0xfc
  PUSH(R.ax);                                                  // 37e6 push ax
  PUSH(0x37ea); a_1000_3a65();                                 // 37e7 call 0x3a65
  SUB16(M16(DS, (u16)(0x2788)), 0x0);                          // 37ea cmp word ptr [0x2788], 0
  if (R.zf) goto L_37f5;                                       // 37ef je 0x37f5
  ASM_INDIRECT_CALL(M16(DS, (u16)(0x2788))); /* call word ptr [0x2788] */ // 37f1 call word ptr [0x2788]
L_37f5:   R.ax = (u16)(0xff);                                          // 37f5 mov ax, 0xff
  PUSH(R.ax);                                                  // 37f8 push ax
  PUSH(0x37fc); a_1000_3a65();                                 // 37f9 call 0x3a65
  R.sp = (u16)(R.bp);                                          // 37fc mov sp, bp
  R.bp = POP();                                                // 37fe pop bp
  R.sp += 2; goto L_ret;                                       // 37ff ret
L_ret:
  return;
}

static u16 f_1000_37e0(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_37e0();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:383E FUN_1000_383e  FIX: recompiled from the machine code (asm2c)
static void a_1000_383e(void)
{
  FN(0x1000383E);
  R.cs = 0x27cc;
  W16(DS, (u16)(0x278c), POP());                               // 383e pop word ptr [0x278c]
  R.dx = (u16)(0x2);                                           // 3842 mov dx, 2
  SUB8(M8(DS, (u16)(0x2759)), (u8)R.dx);                       // 3845 cmp byte ptr [0x2759], dl
  if (R.zf) goto L_3874;                                       // 3849 je 0x3874
  R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 384b mov es, word ptr [0x2757]
  R.es = (u16)(M16(ES, (u16)(0x2c)));                          // 384f mov es, word ptr es:[0x2c]
  W16(DS, (u16)(0x277c), R.es);                                // 3854 mov word ptr [0x277c], es
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3858 xor ax, ax
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 385a cdq
  R.cx = (u16)(0x8000);                                        // 385b mov cx, 0x8000
  R.di = (u16)(XOR16(R.di, R.di));                             // 385e xor di, di
L_3860:   REPNESCASB();                                                // 3860 repne scasb al, byte ptr es:[di]
  SCASB();                                                     // 3862 scasb al, byte ptr es:[di]
  if (!R.zf) goto L_3860;                                      // 3863 jne 0x3860
  R.di = (u16)(INC16(R.di));                                   // 3865 inc di
  R.di = (u16)(INC16(R.di));                                   // 3866 inc di
  W16(DS, (u16)(0x277a), R.di);                                // 3867 mov word ptr [0x277a], di
  R.cx = (u16)(0xffff);                                        // 386b mov cx, 0xffff
  REPNESCASB();                                                // 386e repne scasb al, byte ptr es:[di]
  R.cx = (u16)((u16)~R.cx);                                    // 3870 not cx
  R.dx = (u16)(R.cx);                                          // 3872 mov dx, cx
L_3874:   R.di = (u16)(0x1);                                           // 3874 mov di, 1
  R.si = (u16)(0x81);                                          // 3877 mov si, 0x81
  R.ds = (u16)(M16(DS, (u16)(0x2757)));                        // 387a mov ds, word ptr [0x2757]
L_387e:   LODSB();                                                     // 387e lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x20);                                        // 387f cmp al, 0x20
  if (R.zf) goto L_387e;                                       // 3881 je 0x387e
  SUB8((u8)R.ax, 0x9);                                         // 3883 cmp al, 9
  if (R.zf) goto L_387e;                                       // 3885 je 0x387e
  SUB8((u8)R.ax, 0xd);                                         // 3887 cmp al, 0xd
  if (R.zf) goto L_38fa;                                       // 3889 je 0x38fa
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 388b or al, al
  if (R.zf) goto L_38fa;                                       // 388d je 0x38fa
  R.di = (u16)(INC16(R.di));                                   // 388f inc di
L_3890:   R.si = (u16)(DEC16(R.si));                                   // 3890 dec si
L_3891:   LODSB();                                                     // 3891 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x20);                                        // 3892 cmp al, 0x20
  if (R.zf) goto L_387e;                                       // 3894 je 0x387e
  SUB8((u8)R.ax, 0x9);                                         // 3896 cmp al, 9
  if (R.zf) goto L_387e;                                       // 3898 je 0x387e
  SUB8((u8)R.ax, 0xd);                                         // 389a cmp al, 0xd
  if (R.zf) goto L_38fa;                                       // 389c je 0x38fa
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 389e or al, al
  if (R.zf) goto L_38fa;                                       // 38a0 je 0x38fa
  SUB8((u8)R.ax, 0x22);                                        // 38a2 cmp al, 0x22
  if (R.zf) goto L_38ca;                                       // 38a4 je 0x38ca
  SUB8((u8)R.ax, 0x5c);                                        // 38a6 cmp al, 0x5c
  if (R.zf) goto L_38ad;                                       // 38a8 je 0x38ad
  R.dx = (u16)(INC16(R.dx));                                   // 38aa inc dx
  goto L_3891;                                                 // 38ab jmp 0x3891
L_38ad:   R.cx = (u16)(XOR16(R.cx, R.cx));                             // 38ad xor cx, cx
L_38af:   R.cx = (u16)(INC16(R.cx));                                   // 38af inc cx
  LODSB();                                                     // 38b0 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x5c);                                        // 38b1 cmp al, 0x5c
  if (R.zf) goto L_38af;                                       // 38b3 je 0x38af
  SUB8((u8)R.ax, 0x22);                                        // 38b5 cmp al, 0x22
  if (R.zf) goto L_38bd;                                       // 38b7 je 0x38bd
  R.dx = (u16)(ADD16(R.dx, R.cx));                             // 38b9 add dx, cx
  goto L_3890;                                                 // 38bb jmp 0x3890
L_38bd:   R.ax = (u16)(R.cx);                                          // 38bd mov ax, cx
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 38bf shr cx, 1
  R.dx = (u16)(ADC16(R.dx, R.cx));                             // 38c1 adc dx, cx
  AND8((u8)R.ax, 0x1);                                         // 38c3 test al, 1
  if (!R.zf) goto L_3891;                                      // 38c5 jne 0x3891
  goto L_38ca;                                                 // 38c7 jmp 0x38ca
L_38c9:   R.si = (u16)(DEC16(R.si));                                   // 38c9 dec si
L_38ca:   LODSB();                                                     // 38ca lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0xd);                                         // 38cb cmp al, 0xd
  if (R.zf) goto L_38fa;                                       // 38cd je 0x38fa
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 38cf or al, al
  if (R.zf) goto L_38fa;                                       // 38d1 je 0x38fa
  SUB8((u8)R.ax, 0x22);                                        // 38d3 cmp al, 0x22
  if (R.zf) goto L_3891;                                       // 38d5 je 0x3891
  SUB8((u8)R.ax, 0x5c);                                        // 38d7 cmp al, 0x5c
  if (R.zf) goto L_38de;                                       // 38d9 je 0x38de
  R.dx = (u16)(INC16(R.dx));                                   // 38db inc dx
  goto L_38ca;                                                 // 38dc jmp 0x38ca
L_38de:   R.cx = (u16)(XOR16(R.cx, R.cx));                             // 38de xor cx, cx
L_38e0:   R.cx = (u16)(INC16(R.cx));                                   // 38e0 inc cx
  LODSB();                                                     // 38e1 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x5c);                                        // 38e2 cmp al, 0x5c
  if (R.zf) goto L_38e0;                                       // 38e4 je 0x38e0
  SUB8((u8)R.ax, 0x22);                                        // 38e6 cmp al, 0x22
  if (R.zf) goto L_38ee;                                       // 38e8 je 0x38ee
  R.dx = (u16)(ADD16(R.dx, R.cx));                             // 38ea add dx, cx
  goto L_38c9;                                                 // 38ec jmp 0x38c9
L_38ee:   R.ax = (u16)(R.cx);                                          // 38ee mov ax, cx
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 38f0 shr cx, 1
  R.dx = (u16)(ADC16(R.dx, R.cx));                             // 38f2 adc dx, cx
  AND8((u8)R.ax, 0x1);                                         // 38f4 test al, 1
  if (!R.zf) goto L_38ca;                                      // 38f6 jne 0x38ca
  goto L_3891;                                                 // 38f8 jmp 0x3891
L_38fa:   PUSH(R.ss);                                                  // 38fa push ss
  R.ds = POP();                                                // 38fb pop ds
  W16(DS, (u16)(0x2774), R.di);                                // 38fc mov word ptr [0x2774], di
  R.dx = (u16)(ADD16(R.dx, R.di));                             // 3900 add dx, di
  R.di = (u16)(INC16(R.di));                                   // 3902 inc di
  R.di = (u16)(SHL16(R.di, 0x1));                              // 3903 shl di, 1
  R.dx = (u16)(ADD16(R.dx, R.di));                             // 3905 add dx, di
  SETL(R.dx, AND8((u8)R.dx, 0xfe));                            // 3907 and dl, 0xfe
  R.sp = (u16)(SUB16(R.sp, R.dx));                             // 390a sub sp, dx
  R.ax = (u16)(R.sp);                                          // 390c mov ax, sp
  W16(DS, (u16)(0x2776), R.ax);                                // 390e mov word ptr [0x2776], ax
  R.bx = (u16)(R.ax);                                          // 3911 mov bx, ax
  R.di = (u16)(ADD16(R.di, R.bx));                             // 3913 add di, bx
  PUSH(R.ss);                                                  // 3915 push ss
  R.es = POP();                                                // 3916 pop es
  W16(SS, (u16)(R.bx), R.di);                                  // 3917 mov word ptr ss:[bx], di
  R.bx = (u16)(INC16(R.bx));                                   // 391a inc bx
  R.bx = (u16)(INC16(R.bx));                                   // 391b inc bx
  { u16 a_ = (u16)(0x277a); R.si = (u16)(M16(DS, a_)); R.ds = M16(DS, (u16)(a_ + 2)); } // 391c lds si, ptr [0x277a]
L_3920:   LODSB();                                                     // 3920 lodsb al, byte ptr [si]
  STOSB();                                                     // 3921 stosb byte ptr es:[di], al
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 3922 or al, al
  if (!R.zf) goto L_3920;                                      // 3924 jne 0x3920
  R.si = (u16)(0x81);                                          // 3926 mov si, 0x81
  R.ds = (u16)(M16(SS, (u16)(0x2757)));                        // 3929 mov ds, word ptr ss:[0x2757]
  goto L_3933;                                                 // 392e jmp 0x3933
L_3930:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3930 xor ax, ax
  STOSB();                                                     // 3932 stosb byte ptr es:[di], al
L_3933:   LODSB();                                                     // 3933 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x20);                                        // 3934 cmp al, 0x20
  if (R.zf) goto L_3933;                                       // 3936 je 0x3933
  SUB8((u8)R.ax, 0x9);                                         // 3938 cmp al, 9
  if (R.zf) goto L_3933;                                       // 393a je 0x3933
  SUB8((u8)R.ax, 0xd);                                         // 393c cmp al, 0xd
  if (!R.zf) goto L_3943;                                      // 393e jne 0x3943
  goto L_39c2;                                                 // 3940 jmp 0x39c2
L_3943:   SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 3943 or al, al
  if (!R.zf) goto L_394a;                                      // 3945 jne 0x394a
  goto L_39c2;                                                 // 3947 jmp 0x39c2
L_394a:   W16(SS, (u16)(R.bx), R.di);                                  // 394a mov word ptr ss:[bx], di
  R.bx = (u16)(INC16(R.bx));                                   // 394d inc bx
  R.bx = (u16)(INC16(R.bx));                                   // 394e inc bx
L_394f:   R.si = (u16)(DEC16(R.si));                                   // 394f dec si
L_3950:   LODSB();                                                     // 3950 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x20);                                        // 3951 cmp al, 0x20
  if (R.zf) goto L_3930;                                       // 3953 je 0x3930
  SUB8((u8)R.ax, 0x9);                                         // 3955 cmp al, 9
  if (R.zf) goto L_3930;                                       // 3957 je 0x3930
  SUB8((u8)R.ax, 0xd);                                         // 3959 cmp al, 0xd
  if (R.zf) goto L_39bf;                                       // 395b je 0x39bf
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 395d or al, al
  if (R.zf) goto L_39bf;                                       // 395f je 0x39bf
  SUB8((u8)R.ax, 0x22);                                        // 3961 cmp al, 0x22
  if (R.zf) goto L_398c;                                       // 3963 je 0x398c
  SUB8((u8)R.ax, 0x5c);                                        // 3965 cmp al, 0x5c
  if (R.zf) goto L_396c;                                       // 3967 je 0x396c
  STOSB();                                                     // 3969 stosb byte ptr es:[di], al
  goto L_3950;                                                 // 396a jmp 0x3950
L_396c:   R.cx = (u16)(XOR16(R.cx, R.cx));                             // 396c xor cx, cx
L_396e:   R.cx = (u16)(INC16(R.cx));                                   // 396e inc cx
  LODSB();                                                     // 396f lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x5c);                                        // 3970 cmp al, 0x5c
  if (R.zf) goto L_396e;                                       // 3972 je 0x396e
  SUB8((u8)R.ax, 0x22);                                        // 3974 cmp al, 0x22
  if (R.zf) goto L_397e;                                       // 3976 je 0x397e
  SETL(R.ax, 0x5c);                                            // 3978 mov al, 0x5c
  REPSTOSB();                                                  // 397a rep stosb byte ptr es:[di], al
  goto L_394f;                                                 // 397c jmp 0x394f
L_397e:   SETL(R.ax, 0x5c);                                            // 397e mov al, 0x5c
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 3980 shr cx, 1
  REPSTOSB();                                                  // 3982 rep stosb byte ptr es:[di], al
  if (!R.cf) goto L_398c;                                      // 3984 jae 0x398c
  SETL(R.ax, 0x22);                                            // 3986 mov al, 0x22
  STOSB();                                                     // 3988 stosb byte ptr es:[di], al
  goto L_3950;                                                 // 3989 jmp 0x3950
L_398b:   R.si = (u16)(DEC16(R.si));                                   // 398b dec si
L_398c:   LODSB();                                                     // 398c lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0xd);                                         // 398d cmp al, 0xd
  if (R.zf) goto L_39bf;                                       // 398f je 0x39bf
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 3991 or al, al
  if (R.zf) goto L_39bf;                                       // 3993 je 0x39bf
  SUB8((u8)R.ax, 0x22);                                        // 3995 cmp al, 0x22
  if (R.zf) goto L_3950;                                       // 3997 je 0x3950
  SUB8((u8)R.ax, 0x5c);                                        // 3999 cmp al, 0x5c
  if (R.zf) goto L_39a0;                                       // 399b je 0x39a0
  STOSB();                                                     // 399d stosb byte ptr es:[di], al
  goto L_398c;                                                 // 399e jmp 0x398c
L_39a0:   R.cx = (u16)(XOR16(R.cx, R.cx));                             // 39a0 xor cx, cx
L_39a2:   R.cx = (u16)(INC16(R.cx));                                   // 39a2 inc cx
  LODSB();                                                     // 39a3 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x5c);                                        // 39a4 cmp al, 0x5c
  if (R.zf) goto L_39a2;                                       // 39a6 je 0x39a2
  SUB8((u8)R.ax, 0x22);                                        // 39a8 cmp al, 0x22
  if (R.zf) goto L_39b2;                                       // 39aa je 0x39b2
  SETL(R.ax, 0x5c);                                            // 39ac mov al, 0x5c
  REPSTOSB();                                                  // 39ae rep stosb byte ptr es:[di], al
  goto L_398b;                                                 // 39b0 jmp 0x398b
L_39b2:   SETL(R.ax, 0x5c);                                            // 39b2 mov al, 0x5c
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 39b4 shr cx, 1
  REPSTOSB();                                                  // 39b6 rep stosb byte ptr es:[di], al
  if (!R.cf) goto L_3950;                                      // 39b8 jae 0x3950
  SETL(R.ax, 0x22);                                            // 39ba mov al, 0x22
  STOSB();                                                     // 39bc stosb byte ptr es:[di], al
  goto L_398c;                                                 // 39bd jmp 0x398c
L_39bf:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 39bf xor ax, ax
  STOSB();                                                     // 39c1 stosb byte ptr es:[di], al
L_39c2:   PUSH(R.ss);                                                  // 39c2 push ss
  R.ds = POP();                                                // 39c3 pop ds
  W16(DS, (u16)(R.bx), 0x0);                                   // 39c4 mov word ptr [bx], 0
  goto L_ret;   /* to the return address the routine popped */ // 39c8 jmp word ptr [0x278c]
L_ret:
  return;
}

static u16 f_1000_383e(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_383e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:39CC FUN_1000_39cc  FIX: recompiled from the machine code (asm2c)
static void a_1000_39cc(void)
{
  FN(0x100039CC);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 39cc push bp
  R.bp = (u16)(R.sp);                                          // 39cd mov bp, sp
  PUSH(R.bp);                                                  // 39cf push bp
  R.ds = (u16)(M16(DS, (u16)(0x2757)));                        // 39d0 mov ds, word ptr [0x2757]
  R.cx = (u16)(XOR16(R.cx, R.cx));                             // 39d4 xor cx, cx
  R.ax = (u16)(R.cx);                                          // 39d6 mov ax, cx
  R.bp = (u16)(R.cx);                                          // 39d8 mov bp, cx
  R.di = (u16)(R.cx);                                          // 39da mov di, cx
  R.cx = (u16)(DEC16(R.cx));                                   // 39dc dec cx
  R.si = (u16)(M16(DS, (u16)(0x2c)));                          // 39dd mov si, word ptr [0x2c]
  R.si = (u16)(OR16(R.si, R.si));                              // 39e1 or si, si
  if (R.zf) goto L_39f5;                                       // 39e3 je 0x39f5
  R.es = (u16)(R.si);                                          // 39e5 mov es, si
  SUB8(M8(ES, (u16)(0x0)), 0x0);                               // 39e7 cmp byte ptr es:[0], 0
  if (R.zf) goto L_39f5;                                       // 39ed je 0x39f5
L_39ef:   REPNESCASB();                                                // 39ef repne scasb al, byte ptr es:[di]
  R.bp = (u16)(INC16(R.bp));                                   // 39f1 inc bp
  SCASB();                                                     // 39f2 scasb al, byte ptr es:[di]
  if (!R.zf) goto L_39ef;                                      // 39f3 jne 0x39ef
L_39f5:   R.bp = (u16)(INC16(R.bp));                                   // 39f5 inc bp
  { u16 t_ = R.di; R.di = (u16)(R.ax); R.ax = (u16)(t_); }     // 39f6 xchg di, ax
  R.ax = (u16)(INC16(R.ax));                                   // 39f7 inc ax
  SETL(R.ax, AND8((u8)R.ax, 0xfe));                            // 39f8 and al, 0xfe
  R.di = (u16)(R.bp);                                          // 39fa mov di, bp
  R.bp = (u16)(SHL16(R.bp, 0x1));                              // 39fc shl bp, 1
  R.ax = (u16)(ADD16(R.ax, R.bp));                             // 39fe add ax, bp
  PUSH(R.ss);                                                  // 3a00 push ss
  R.ds = POP();                                                // 3a01 pop ds
  PUSH(R.di);                                                  // 3a02 push di
  R.di = (u16)(0x9);                                           // 3a03 mov di, 9
  PUSH(0x3a09); a_1000_3a8e();                                 // 3a06 call 0x3a8e
  R.di = POP();                                                // 3a09 pop di
  R.cx = (u16)(R.di);                                          // 3a0a mov cx, di
  R.di = (u16)(R.bp);                                          // 3a0c mov di, bp
  R.di = (u16)(ADD16(R.di, R.ax));                             // 3a0e add di, ax
  W16(DS, (u16)(0x2778), R.bp);                                // 3a10 mov word ptr [0x2778], bp
  PUSH(R.ds);                                                  // 3a14 push ds
  R.es = POP();                                                // 3a15 pop es
  R.ds = (u16)(R.si);                                          // 3a16 mov ds, si
  R.si = (u16)(XOR16(R.si, R.si));                             // 3a18 xor si, si
  R.cx = (u16)(DEC16(R.cx));                                   // 3a1a dec cx
  if (R.cx == 0) goto L_3a30;                                  // 3a1b jcxz 0x3a30
L_3a1d:   SUB16(M16(DS, (u16)(R.si)), 0x433b);                         // 3a1d cmp word ptr [si], 0x433b
  if (R.zf) goto L_3a28;                                       // 3a21 je 0x3a28
  W16(SS, (u16)(R.bp), R.di);                                  // 3a23 mov word ptr [bp], di
  R.bp = (u16)(INC16(R.bp));                                   // 3a26 inc bp
  R.bp = (u16)(INC16(R.bp));                                   // 3a27 inc bp
L_3a28:   LODSB();                                                     // 3a28 lodsb al, byte ptr [si]
  STOSB();                                                     // 3a29 stosb byte ptr es:[di], al
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 3a2a or al, al
  if (!R.zf) goto L_3a28;                                      // 3a2c jne 0x3a28
  if (--R.cx != 0) goto L_3a1d;                                // 3a2e loop 0x3a1d
L_3a30:   W16(SS, (u16)(R.bp), R.cx);                                  // 3a30 mov word ptr [bp], cx
  PUSH(R.ss);                                                  // 3a33 push ss
  R.ds = POP();                                                // 3a34 pop ds
  R.bp = POP();                                                // 3a35 pop bp
  R.sp = (u16)(R.bp);                                          // 3a36 mov sp, bp
  R.bp = POP();                                                // 3a38 pop bp
  R.sp += 2; goto L_ret;                                       // 3a39 ret
L_ret:
  return;
}

static u16 f_1000_39cc(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_39cc();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3A3A FUN_1000_3a3a  FIX: recompiled from the machine code (asm2c)
static void a_1000_3a3a(void)
{
  FN(0x10003A3A);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 3a3a push bp
  R.bp = (u16)(R.sp);                                          // 3a3b mov bp, sp
  PUSH(R.si);                                                  // 3a3d push si
  PUSH(R.di);                                                  // 3a3e push di
  PUSH(R.ds);                                                  // 3a3f push ds
  R.es = POP();                                                // 3a40 pop es
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 3a41 mov dx, word ptr [bp + 4]
  R.si = (u16)(0x2c04);                                        // 3a44 mov si, 0x2c04
L_3a47:   LODSW();                                                     // 3a47 lodsw ax, word ptr [si]
  SUB16(R.ax, R.dx);                                           // 3a48 cmp ax, dx
  if (R.zf) goto L_3a5c;                                       // 3a4a je 0x3a5c
  R.ax = (u16)(INC16(R.ax));                                   // 3a4c inc ax
  { u16 t_ = R.si; R.si = (u16)(R.ax); R.ax = (u16)(t_); }     // 3a4d xchg si, ax
  if (R.zf) goto L_3a5c;                                       // 3a4e je 0x3a5c
  { u16 t_ = R.di; R.di = (u16)(R.ax); R.ax = (u16)(t_); }     // 3a50 xchg di, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3a51 xor ax, ax
  R.cx = (u16)(0xffff);                                        // 3a53 mov cx, 0xffff
  REPNESCASB();                                                // 3a56 repne scasb al, byte ptr es:[di]
  R.si = (u16)(R.di);                                          // 3a58 mov si, di
  goto L_3a47;                                                 // 3a5a jmp 0x3a47
L_3a5c:   { u16 t_ = R.si; R.si = (u16)(R.ax); R.ax = (u16)(t_); }     // 3a5c xchg si, ax
  R.di = POP();                                                // 3a5d pop di
  R.si = POP();                                                // 3a5e pop si
  R.sp = (u16)(R.bp);                                          // 3a5f mov sp, bp
  R.bp = POP();                                                // 3a61 pop bp
  R.sp += 4; goto L_ret;                                       // 3a62 ret 2
L_ret:
  return;
}

static u16 f_1000_3a3a(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_3a3a();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3A65 FUN_1000_3a65  FIX: recompiled from the machine code (asm2c)
static void a_1000_3a65(void)
{
  FN(0x10003A65);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 3a65 push bp
  R.bp = (u16)(R.sp);                                          // 3a66 mov bp, sp
  PUSH(R.di);                                                  // 3a68 push di
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 3a69 push word ptr [bp + 4]
  PUSH(0x3a6f); a_1000_3a3a();                                 // 3a6c call 0x3a3a
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 3a6f or ax, ax
  if (R.zf) goto L_3a87;                                       // 3a71 je 0x3a87
  { u16 t_ = R.dx; R.dx = (u16)(R.ax); R.ax = (u16)(t_); }     // 3a73 xchg dx, ax
  R.di = (u16)(R.dx);                                          // 3a74 mov di, dx
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3a76 xor ax, ax
  R.cx = (u16)(0xffff);                                        // 3a78 mov cx, 0xffff
  REPNESCASB();                                                // 3a7b repne scasb al, byte ptr es:[di]
  R.cx = (u16)((u16)~R.cx);                                    // 3a7d not cx
  R.cx = (u16)(DEC16(R.cx));                                   // 3a7f dec cx
  R.bx = (u16)(0x2);                                           // 3a80 mov bx, 2
  SETH(R.ax, 0x40);                                            // 3a83 mov ah, 0x40
  ASM_INT(0x21);                                               // 3a85 int 0x21
L_3a87:   R.di = POP();                                                // 3a87 pop di
  R.sp = (u16)(R.bp);                                          // 3a88 mov sp, bp
  R.bp = POP();                                                // 3a8a pop bp
  R.sp += 4; goto L_ret;                                       // 3a8b ret 2
L_ret:
  return;
}

static u16 f_1000_3a65(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_3a65();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3A8E FUN_1000_3a8e  FIX: recompiled from the machine code (asm2c)
static void a_1000_3a8e(void)
{
  FN(0x10003A8E);
  R.cs = 0x27cc;
  goto L_3a8e;
L_3661:   PUSH(R.ax);                                                  // 3661 push ax
  PUSH(0x3665); a_1000_37e0();                                 // 3662 call 0x37e0
  PUSH(0x3668); a_1000_3a65();                                 // 3665 call 0x3a65
  R.ax = (u16)(0xff);                                          // 3668 mov ax, 0xff
  PUSH(R.ax);                                                  // 366b push ax
  ASM_INDIRECT_CALL(M16(DS, (u16)(0x26e4))); /* call word ptr [0x26e4] */ // 366c call word ptr [0x26e4]
L_3670:   FN(0x10003670); SETH(R.ax, 0x30);                            // 3670 mov ah, 0x30
  ASM_INT(0x21);                                               // 3672 int 0x21
  W16(DS, (u16)(0x2759), R.ax);                                // 3674 mov word ptr [0x2759], ax
  R.ax = (u16)(0x3500);                                        // 3677 mov ax, 0x3500
  ASM_INT(0x21);                                               // 367a int 0x21
  W16(DS, (u16)(0x2745), R.bx);                                // 367c mov word ptr [0x2745], bx
  W16(DS, (u16)(0x2747), R.es);                                // 3680 mov word ptr [0x2747], es
  PUSH(R.cs);                                                  // 3684 push cs
  R.ds = POP();                                                // 3685 pop ds
  R.ax = (u16)(0x2500);                                        // 3686 mov ax, 0x2500
  R.dx = (u16)(0x3652);                                        // 3689 mov dx, 0x3652
  ASM_INT(0x21);                                               // 368c int 0x21
  PUSH(R.ss);                                                  // 368e push ss
  R.ds = POP();                                                // 368f pop ds
  R.cx = (u16)(M16(DS, (u16)(0x2bf0)));                        // 3690 mov cx, word ptr [0x2bf0]
  if (R.cx == 0) goto L_36c4;                                  // 3694 jcxz 0x36c4
  R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 3696 mov es, word ptr [0x2757]
  R.si = (u16)(M16(ES, (u16)(0x2c)));                          // 369a mov si, word ptr es:[0x2c]
  { u16 a_ = (u16)(0x2bf2); R.ax = (u16)(M16(DS, a_)); R.ds = M16(DS, (u16)(a_ + 2)); } // 369f lds ax, ptr [0x2bf2]
  R.dx = (u16)(R.ds);                                          // 36a3 mov dx, ds
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 36a5 xor bx, bx
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36ac); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36a7 lcall ss:[0x2bee]
  if (!R.cf) goto L_36b3;                                      // 36ac jae 0x36b3
  PUSH(R.ss);                                                  // 36ae push ss
  R.ds = POP();                                                // 36af pop ds
  goto L_3800;                                                 // 36b0 jmp 0x3800
L_36b3:   { u16 a_ = (u16)(0x2bf6); R.ax = (u16)(M16(SS, a_)); R.ds = M16(SS, (u16)(a_ + 2)); } // 36b3 lds ax, ptr ss:[0x2bf6]
  R.dx = (u16)(R.ds);                                          // 36b8 mov dx, ds
  R.bx = (u16)(0x3);                                           // 36ba mov bx, 3
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36c2); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36bd lcall ss:[0x2bee]
  PUSH(R.ss);                                                  // 36c2 push ss
  R.ds = POP();                                                // 36c3 pop ds
L_36c4:   R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 36c4 mov es, word ptr [0x2757]
  R.cx = (u16)(M16(ES, (u16)(0x2c)));                          // 36c8 mov cx, word ptr es:[0x2c]
  if (R.cx == 0) goto L_3705;                                  // 36cd jcxz 0x3705
  R.es = (u16)(R.cx);                                          // 36cf mov es, cx
  R.di = (u16)(XOR16(R.di, R.di));                             // 36d1 xor di, di
L_36d3:   SUB8(M8(ES, (u16)(R.di)), 0x0);                              // 36d3 cmp byte ptr es:[di], 0
  if (R.zf) goto L_3705;                                       // 36d7 je 0x3705
  R.cx = (u16)(0xc);                                           // 36d9 mov cx, 0xc
  R.si = (u16)(0x2738);                                        // 36dc mov si, 0x2738
  REPECMPSB();                                                 // 36df repe cmpsb byte ptr [si], byte ptr es:[di]
  if (R.zf) goto L_36ee;                                       // 36e1 je 0x36ee
  R.cx = (u16)(0x7fff);                                        // 36e3 mov cx, 0x7fff
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 36e6 xor ax, ax
  REPNESCASB();                                                // 36e8 repne scasb al, byte ptr es:[di]
  if (!R.zf) goto L_3705;                                      // 36ea jne 0x3705
  goto L_36d3;                                                 // 36ec jmp 0x36d3
L_36ee:   PUSH(R.es);                                                  // 36ee push es
  PUSH(R.ds);                                                  // 36ef push ds
  R.es = POP();                                                // 36f0 pop es
  R.ds = POP();                                                // 36f1 pop ds
  R.si = (u16)(R.di);                                          // 36f2 mov si, di
  R.di = (u16)(0x2760);                                        // 36f4 mov di, 0x2760
  LODSB();                                                     // 36f7 lodsb al, byte ptr [si]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 36f8 cwde
  { u16 t_ = R.cx; R.cx = (u16)(R.ax); R.ax = (u16)(t_); }     // 36f9 xchg cx, ax
L_36fa:   LODSB();                                                     // 36fa lodsb al, byte ptr [si]
  SETL(R.ax, INC8((u8)R.ax));                                  // 36fb inc al
  if (R.zf) goto L_3700;                                       // 36fd je 0x3700
  R.ax = (u16)(DEC16(R.ax));                                   // 36ff dec ax
L_3700:   STOSB();                                                     // 3700 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_36fa;                                // 3701 loop 0x36fa
  PUSH(R.ss);                                                  // 3703 push ss
  R.ds = POP();                                                // 3704 pop ds
L_3705:   R.bx = (u16)(0x4);                                           // 3705 mov bx, 4
L_3708:   W8(DS, (u16)(R.bx + 0x2760), AND8(M8(DS, (u16)(R.bx + 0x2760)), 0xbf)); // 3708 and byte ptr [bx + 0x2760], 0xbf
  R.ax = (u16)(0x4400);                                        // 370d mov ax, 0x4400
  ASM_INT(0x21);                                               // 3710 int 0x21
  if (R.cf) goto L_371e;                                       // 3712 jb 0x371e
  AND8((u8)R.dx, 0x80);                                        // 3714 test dl, 0x80
  if (R.zf) goto L_371e;                                       // 3717 je 0x371e
  W8(DS, (u16)(R.bx + 0x2760), OR8(M8(DS, (u16)(R.bx + 0x2760)), 0x40)); // 3719 or byte ptr [bx + 0x2760], 0x40
L_371e:   R.bx = (u16)(DEC16(R.bx));                                   // 371e dec bx
  if (!R.sf) goto L_3708;                                      // 371f jns 0x3708
  R.si = (u16)(0x2bfa);                                        // 3721 mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 3724 mov di, 0x2bfa
  PUSH(0x372a); a_1000_37cc();                                 // 3727 call 0x37cc
  R.si = (u16)(0x2bfa);                                        // 372a mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 372d mov di, 0x2bfa
  PUSH(0x3733); a_1000_37bd();                                 // 3730 call 0x37bd
  R.sp += 2; goto L_ret;                                       // 3733 ret
L_3800:   R.ax = (u16)(0x2);                                           // 3800 mov ax, 2
  goto L_3661;                                                 // 3803 jmp 0x3661
L_3a8e:   R.dx = (u16)(R.ax);                                          // 3a8e mov dx, ax
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x26e6))));           // 3a90 add ax, word ptr [0x26e6]
  if (R.cf) goto L_3acb;                                       // 3a94 jb 0x3acb
  SUB16(M16(DS, (u16)(0x26e0)), R.ax);                         // 3a96 cmp word ptr [0x26e0], ax
  if (!R.cf) goto L_3ac1;                                      // 3a9a jae 0x3ac1
  R.ax = (u16)(ADD16(R.ax, 0xf));                              // 3a9c add ax, 0xf
  PUSH(R.ax);                                                  // 3a9f push ax
  R.ax = (u16)(RCR16(R.ax, 0x1));                              // 3aa0 rcr ax, 1
  SETL(R.cx, 0x3);                                             // 3aa2 mov cl, 3
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 3aa4 shr ax, cl
  R.cx = (u16)(R.ds);                                          // 3aa6 mov cx, ds
  R.bx = (u16)(M16(DS, (u16)(0x2757)));                        // 3aa8 mov bx, word ptr [0x2757]
  R.cx = (u16)(SUB16(R.cx, R.bx));                             // 3aac sub cx, bx
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 3aae add ax, cx
  R.es = (u16)(R.bx);                                          // 3ab0 mov es, bx
  R.bx = (u16)(R.ax);                                          // 3ab2 mov bx, ax
  SETH(R.ax, 0x4a);                                            // 3ab4 mov ah, 0x4a
  ASM_INT(0x21);                                               // 3ab6 int 0x21
  R.ax = POP();                                                // 3ab8 pop ax
  if (R.cf) goto L_3acb;                                       // 3ab9 jb 0x3acb
  SETL(R.ax, AND8((u8)R.ax, 0xf0));                            // 3abb and al, 0xf0
  R.ax = (u16)(DEC16(R.ax));                                   // 3abd dec ax
  W16(DS, (u16)(0x26e0), R.ax);                                // 3abe mov word ptr [0x26e0], ax
L_3ac1:   { u16 t_ = R.bp; R.bp = (u16)(R.ax); R.ax = (u16)(t_); }     // 3ac1 xchg bp, ax
  R.bp = (u16)(M16(DS, (u16)(0x26e6)));                        // 3ac2 mov bp, word ptr [0x26e6]
  W16(DS, (u16)(0x26e6), ADD16(M16(DS, (u16)(0x26e6)), R.dx)); // 3ac6 add word ptr [0x26e6], dx
  R.sp += 2; goto L_ret;                                       // 3aca ret
L_3acb:   R.ax = (u16)(R.di);                                          // 3acb mov ax, di
  goto L_3661;                                                 // 3acd jmp 0x3661
L_ret:
  return;
}

static u16 f_1000_3a8e(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_3a8e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3AF0 FUN_1000_3af0  FIX: recompiled from the machine code (asm2c)
static void a_1000_3af0(void)
{
  FN(0x10003AF0);
  R.cs = 0x27cc;
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 3af0 xor ah, ah
  PUSH(0x3af5); a_1000_3af6();                                 // 3af2 call 0x3af6
  R.sp += 2; goto L_ret;                                       // 3af5 ret
L_ret:
  return;
}

static u16 f_1000_3af0(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_3af0();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:3AF6 FUN_1000_3af6  FIX: recompiled from the machine code (asm2c)
static void a_1000_3af6(void)
{
  FN(0x10003AF6);
  R.cs = 0x27cc;
  W8(DS, (u16)(0x275c), (u8)R.ax);                             // 3af6 mov byte ptr [0x275c], al
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 3af9 or ah, ah
  if (!R.zf) goto L_3b20;                                      // 3afb jne 0x3b20
  SUB8(M8(DS, (u16)(0x2759)), 0x3);                            // 3afd cmp byte ptr [0x2759], 3
  if (R.cf) goto L_3b11;                                       // 3b02 jb 0x3b11
  SUB8((u8)R.ax, 0x22);                                        // 3b04 cmp al, 0x22
  if (!R.cf) goto L_3b15;                                      // 3b06 jae 0x3b15
  SUB8((u8)R.ax, 0x20);                                        // 3b08 cmp al, 0x20
  if (R.cf) goto L_3b11;                                       // 3b0a jb 0x3b11
  SETL(R.ax, 0x5);                                             // 3b0c mov al, 5
  goto L_3b17;                                                 // 3b0e jmp 0x3b17
L_3b11:   SUB8((u8)R.ax, 0x13);                                        // 3b11 cmp al, 0x13
  if (R.cf || R.zf) goto L_3b17;                               // 3b13 jbe 0x3b17
L_3b15:   SETL(R.ax, 0x13);                                            // 3b15 mov al, 0x13
L_3b17:   R.bx = (u16)(0x278e);                                        // 3b17 mov bx, 0x278e
  SETL(R.ax, M8(DS, (u16)(R.bx + (u8)R.ax)));                  // 3b1a xlatb
L_3b1b:   R.ax = (u16)(i16)(i8)R.ax;                                   // 3b1b cwde
  W16(DS, (u16)(0x2751), R.ax);                                // 3b1c mov word ptr [0x2751], ax
  R.sp += 2; goto L_ret;                                       // 3b1f ret
L_3b20:   SETL(R.ax, (u8)(R.ax >> 8));                                 // 3b20 mov al, ah
  goto L_3b1b;                                                 // 3b22 jmp 0x3b1b
L_ret:
  return;
}

static u16 f_1000_3af6(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_3af6();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:434C FUN_1000_434c  FIX: recompiled from the machine code (asm2c)
static void a_1000_434c(void)
{
  FN(0x1000434C);
  R.cs = 0x27cc;
  goto L_434c;
L_3661:   PUSH(R.ax);                                                  // 3661 push ax
  PUSH(0x3665); a_1000_37e0();                                 // 3662 call 0x37e0
  PUSH(0x3668); a_1000_3a65();                                 // 3665 call 0x3a65
  R.ax = (u16)(0xff);                                          // 3668 mov ax, 0xff
  PUSH(R.ax);                                                  // 366b push ax
  ASM_INDIRECT_CALL(M16(DS, (u16)(0x26e4))); /* call word ptr [0x26e4] */ // 366c call word ptr [0x26e4]
L_3670:   FN(0x10003670); SETH(R.ax, 0x30);                            // 3670 mov ah, 0x30
  ASM_INT(0x21);                                               // 3672 int 0x21
  W16(DS, (u16)(0x2759), R.ax);                                // 3674 mov word ptr [0x2759], ax
  R.ax = (u16)(0x3500);                                        // 3677 mov ax, 0x3500
  ASM_INT(0x21);                                               // 367a int 0x21
  W16(DS, (u16)(0x2745), R.bx);                                // 367c mov word ptr [0x2745], bx
  W16(DS, (u16)(0x2747), R.es);                                // 3680 mov word ptr [0x2747], es
  PUSH(R.cs);                                                  // 3684 push cs
  R.ds = POP();                                                // 3685 pop ds
  R.ax = (u16)(0x2500);                                        // 3686 mov ax, 0x2500
  R.dx = (u16)(0x3652);                                        // 3689 mov dx, 0x3652
  ASM_INT(0x21);                                               // 368c int 0x21
  PUSH(R.ss);                                                  // 368e push ss
  R.ds = POP();                                                // 368f pop ds
  R.cx = (u16)(M16(DS, (u16)(0x2bf0)));                        // 3690 mov cx, word ptr [0x2bf0]
  if (R.cx == 0) goto L_36c4;                                  // 3694 jcxz 0x36c4
  R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 3696 mov es, word ptr [0x2757]
  R.si = (u16)(M16(ES, (u16)(0x2c)));                          // 369a mov si, word ptr es:[0x2c]
  { u16 a_ = (u16)(0x2bf2); R.ax = (u16)(M16(DS, a_)); R.ds = M16(DS, (u16)(a_ + 2)); } // 369f lds ax, ptr [0x2bf2]
  R.dx = (u16)(R.ds);                                          // 36a3 mov dx, ds
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 36a5 xor bx, bx
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36ac); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36a7 lcall ss:[0x2bee]
  if (!R.cf) goto L_36b3;                                      // 36ac jae 0x36b3
  PUSH(R.ss);                                                  // 36ae push ss
  R.ds = POP();                                                // 36af pop ds
  goto L_3800;                                                 // 36b0 jmp 0x3800
L_36b3:   { u16 a_ = (u16)(0x2bf6); R.ax = (u16)(M16(SS, a_)); R.ds = M16(SS, (u16)(a_ + 2)); } // 36b3 lds ax, ptr ss:[0x2bf6]
  R.dx = (u16)(R.ds);                                          // 36b8 mov dx, ds
  R.bx = (u16)(0x3);                                           // 36ba mov bx, 3
  { u16 o_ = M16(SS, (u16)(0x2bee)), s_ = M16(SS, (u16)((u16)(0x2bee) + 2)); PUSH(0x27cc); PUSH(0x36c2); du_far_call(s_, o_); } /* lcall ss:[0x2bee] */ // 36bd lcall ss:[0x2bee]
  PUSH(R.ss);                                                  // 36c2 push ss
  R.ds = POP();                                                // 36c3 pop ds
L_36c4:   R.es = (u16)(M16(DS, (u16)(0x2757)));                        // 36c4 mov es, word ptr [0x2757]
  R.cx = (u16)(M16(ES, (u16)(0x2c)));                          // 36c8 mov cx, word ptr es:[0x2c]
  if (R.cx == 0) goto L_3705;                                  // 36cd jcxz 0x3705
  R.es = (u16)(R.cx);                                          // 36cf mov es, cx
  R.di = (u16)(XOR16(R.di, R.di));                             // 36d1 xor di, di
L_36d3:   SUB8(M8(ES, (u16)(R.di)), 0x0);                              // 36d3 cmp byte ptr es:[di], 0
  if (R.zf) goto L_3705;                                       // 36d7 je 0x3705
  R.cx = (u16)(0xc);                                           // 36d9 mov cx, 0xc
  R.si = (u16)(0x2738);                                        // 36dc mov si, 0x2738
  REPECMPSB();                                                 // 36df repe cmpsb byte ptr [si], byte ptr es:[di]
  if (R.zf) goto L_36ee;                                       // 36e1 je 0x36ee
  R.cx = (u16)(0x7fff);                                        // 36e3 mov cx, 0x7fff
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 36e6 xor ax, ax
  REPNESCASB();                                                // 36e8 repne scasb al, byte ptr es:[di]
  if (!R.zf) goto L_3705;                                      // 36ea jne 0x3705
  goto L_36d3;                                                 // 36ec jmp 0x36d3
L_36ee:   PUSH(R.es);                                                  // 36ee push es
  PUSH(R.ds);                                                  // 36ef push ds
  R.es = POP();                                                // 36f0 pop es
  R.ds = POP();                                                // 36f1 pop ds
  R.si = (u16)(R.di);                                          // 36f2 mov si, di
  R.di = (u16)(0x2760);                                        // 36f4 mov di, 0x2760
  LODSB();                                                     // 36f7 lodsb al, byte ptr [si]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 36f8 cwde
  { u16 t_ = R.cx; R.cx = (u16)(R.ax); R.ax = (u16)(t_); }     // 36f9 xchg cx, ax
L_36fa:   LODSB();                                                     // 36fa lodsb al, byte ptr [si]
  SETL(R.ax, INC8((u8)R.ax));                                  // 36fb inc al
  if (R.zf) goto L_3700;                                       // 36fd je 0x3700
  R.ax = (u16)(DEC16(R.ax));                                   // 36ff dec ax
L_3700:   STOSB();                                                     // 3700 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_36fa;                                // 3701 loop 0x36fa
  PUSH(R.ss);                                                  // 3703 push ss
  R.ds = POP();                                                // 3704 pop ds
L_3705:   R.bx = (u16)(0x4);                                           // 3705 mov bx, 4
L_3708:   W8(DS, (u16)(R.bx + 0x2760), AND8(M8(DS, (u16)(R.bx + 0x2760)), 0xbf)); // 3708 and byte ptr [bx + 0x2760], 0xbf
  R.ax = (u16)(0x4400);                                        // 370d mov ax, 0x4400
  ASM_INT(0x21);                                               // 3710 int 0x21
  if (R.cf) goto L_371e;                                       // 3712 jb 0x371e
  AND8((u8)R.dx, 0x80);                                        // 3714 test dl, 0x80
  if (R.zf) goto L_371e;                                       // 3717 je 0x371e
  W8(DS, (u16)(R.bx + 0x2760), OR8(M8(DS, (u16)(R.bx + 0x2760)), 0x40)); // 3719 or byte ptr [bx + 0x2760], 0x40
L_371e:   R.bx = (u16)(DEC16(R.bx));                                   // 371e dec bx
  if (!R.sf) goto L_3708;                                      // 371f jns 0x3708
  R.si = (u16)(0x2bfa);                                        // 3721 mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 3724 mov di, 0x2bfa
  PUSH(0x372a); a_1000_37cc();                                 // 3727 call 0x37cc
  R.si = (u16)(0x2bfa);                                        // 372a mov si, 0x2bfa
  R.di = (u16)(0x2bfa);                                        // 372d mov di, 0x2bfa
  PUSH(0x3733); a_1000_37bd();                                 // 3730 call 0x37bd
  R.sp += 2; goto L_ret;                                       // 3733 ret
L_3800:   R.ax = (u16)(0x2);                                           // 3800 mov ax, 2
  goto L_3661;                                                 // 3803 jmp 0x3661
L_3ae3:   if (!R.cf) goto L_3aec;                                      // 3ae3 jae 0x3aec
  PUSH(0x3ae8); a_1000_3af6();                                 // 3ae5 call 0x3af6
  R.ax = (u16)(0xffff);                                        // 3ae8 mov ax, 0xffff
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 3aeb cdq
L_3aec:   R.sp = (u16)(R.bp);                                          // 3aec mov sp, bp
  R.bp = POP();                                                // 3aee pop bp
  R.sp += 2; goto L_ret;                                       // 3aef ret
L_434c:   PUSH(R.bp);                                                  // 434c push bp
  R.bp = (u16)(R.sp);                                          // 434d mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x8));                              // 434f sub sp, 8
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4352 mov bx, word ptr [bp + 4]
  SUB16(R.bx, M16(DS, (u16)(0x275e)));                         // 4355 cmp bx, word ptr [0x275e]
  if (R.cf) goto L_4362;                                       // 4359 jb 0x4362
  R.ax = (u16)(0x900);                                         // 435b mov ax, 0x900
  R.cf = 1;                                                    // 435e stc
L_435f:   goto L_3ae3;                                                 // 435f jmp 0x3ae3
L_4362:   AND8(M8(DS, (u16)(R.bx + 0x2760)), 0x20);                    // 4362 test byte ptr [bx + 0x2760], 0x20
  if (R.zf) goto L_4374;                                       // 4367 je 0x4374
  R.ax = (u16)(0x4202);                                        // 4369 mov ax, 0x4202
  R.cx = (u16)(XOR16(R.cx, R.cx));                             // 436c xor cx, cx
  R.dx = (u16)(R.cx);                                          // 436e mov dx, cx
  ASM_INT(0x21);                                               // 4370 int 0x21
  if (R.cf) goto L_435f;                                       // 4372 jb 0x435f
L_4374:   AND8(M8(DS, (u16)(R.bx + 0x2760)), 0x80);                    // 4374 test byte ptr [bx + 0x2760], 0x80
  if (R.zf) goto L_43e9;                                       // 4379 je 0x43e9
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 437b mov dx, word ptr [bp + 6]
  PUSH(R.ds);                                                  // 437e push ds
  R.es = POP();                                                // 437f pop es
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 4380 xor ax, ax
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 4382 mov word ptr [bp - 2], ax
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 4385 mov word ptr [bp - 4], ax
  R.df = 0;                                                    // 4388 cld
  PUSH(R.di);                                                  // 4389 push di
  PUSH(R.si);                                                  // 438a push si
  R.di = (u16)(R.dx);                                          // 438b mov di, dx
  R.si = (u16)(R.dx);                                          // 438d mov si, dx
  W16(SS, (u16)(R.bp + 0xfff8), R.sp);                         // 438f mov word ptr [bp - 8], sp
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 4392 mov cx, word ptr [bp + 8]
  if (R.cx == 0) goto L_43eb;                                  // 4395 jcxz 0x43eb
  SETL(R.ax, 0xa);                                             // 4397 mov al, 0xa
  REPNESCASB();                                                // 4399 repne scasb al, byte ptr es:[di]
  if (!R.zf) goto L_43e7;                                      // 439b jne 0x43e7
  PUSH(0x43a0); a_1000_4474();                                 // 439d call 0x4474
  SUB16(R.ax, 0xa8);                                           // 43a0 cmp ax, 0xa8
  if (R.cf || R.zf) goto L_43ed;                               // 43a3 jbe 0x43ed
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 43a5 sub sp, 2
  R.bx = (u16)(R.sp);                                          // 43a8 mov bx, sp
  R.dx = (u16)(0x200);                                         // 43aa mov dx, 0x200
  SUB16(R.ax, 0x228);                                          // 43ad cmp ax, 0x228
  if (!R.cf) goto L_43b5;                                      // 43b0 jae 0x43b5
  R.dx = (u16)(0x80);                                          // 43b2 mov dx, 0x80
L_43b5:   R.sp = (u16)(SUB16(R.sp, R.dx));                             // 43b5 sub sp, dx
  R.dx = (u16)(R.sp);                                          // 43b7 mov dx, sp
  R.di = (u16)(R.dx);                                          // 43b9 mov di, dx
  PUSH(R.ss);                                                  // 43bb push ss
  R.es = POP();                                                // 43bc pop es
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 43bd mov cx, word ptr [bp + 8]
L_43c0:   LODSB();                                                     // 43c0 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0xa);                                         // 43c1 cmp al, 0xa
  if (R.zf) goto L_43d1;                                       // 43c3 je 0x43d1
L_43c5:   SUB16(R.di, R.bx);                                           // 43c5 cmp di, bx
  if (R.zf) goto L_43e2;                                       // 43c7 je 0x43e2
L_43c9:   STOSB();                                                     // 43c9 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_43c0;                                // 43ca loop 0x43c0
  PUSH(0x43cf); a_1000_43f2();                                 // 43cc call 0x43f2
  goto L_4432;                                                 // 43cf jmp 0x4432
L_43d1:   SETL(R.ax, 0xd);                                             // 43d1 mov al, 0xd
  SUB16(R.di, R.bx);                                           // 43d3 cmp di, bx
  if (!R.zf) goto L_43da;                                      // 43d5 jne 0x43da
  PUSH(0x43da); a_1000_43f2();                                 // 43d7 call 0x43f2
L_43da:   STOSB();                                                     // 43da stosb byte ptr es:[di], al
  SETL(R.ax, 0xa);                                             // 43db mov al, 0xa
  W16(SS, (u16)(R.bp + 0xfffc), INC16(M16(SS, (u16)(R.bp + 0xfffc)))); // 43dd inc word ptr [bp - 4]
  goto L_43c5;                                                 // 43e0 jmp 0x43c5
L_43e2:   PUSH(0x43e5); a_1000_43f2();                                 // 43e2 call 0x43f2
  goto L_43c9;                                                 // 43e5 jmp 0x43c9
L_43e7:   R.si = POP();                                                // 43e7 pop si
  R.di = POP();                                                // 43e8 pop di
L_43e9:   goto L_4440;                                                 // 43e9 jmp 0x4440
L_43eb:   goto L_4432;                                                 // 43eb jmp 0x4432
L_43ed:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 43ed xor ax, ax
  goto L_3661;                                                 // 43ef jmp 0x3661
L_4432:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 4432 mov ax, word ptr [bp - 2]
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0xfffc))));    // 4435 sub ax, word ptr [bp - 4]
  R.sp = (u16)(M16(SS, (u16)(R.bp + 0xfff8)));                 // 4438 mov sp, word ptr [bp - 8]
  R.si = POP();                                                // 443b pop si
  R.di = POP();                                                // 443c pop di
L_443d:   goto L_3ae3;                                                 // 443d jmp 0x3ae3
L_4440:   R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 4440 mov cx, word ptr [bp + 8]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 4443 or cx, cx
  if (!R.zf) goto L_444c;                                      // 4445 jne 0x444c
  R.ax = (u16)(R.cx);                                          // 4447 mov ax, cx
  goto L_3ae3;                                                 // 4449 jmp 0x3ae3
L_444c:   R.dx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 444c mov dx, word ptr [bp + 6]
  SETH(R.ax, 0x40);                                            // 444f mov ah, 0x40
  ASM_INT(0x21);                                               // 4451 int 0x21
  if (!R.cf) goto L_4459;                                      // 4453 jae 0x4459
  SETH(R.ax, 0x9);                                             // 4455 mov ah, 9
  goto L_443d;                                                 // 4457 jmp 0x443d
L_4459:   R.ax = (u16)(OR16(R.ax, R.ax));                              // 4459 or ax, ax
  if (!R.zf) goto L_443d;                                      // 445b jne 0x443d
  AND8(M8(DS, (u16)(R.bx + 0x2760)), 0x40);                    // 445d test byte ptr [bx + 0x2760], 0x40
  if (R.zf) goto L_446e;                                       // 4462 je 0x446e
  R.bx = (u16)(R.dx);                                          // 4464 mov bx, dx
  SUB8(M8(DS, (u16)(R.bx)), 0x1a);                             // 4466 cmp byte ptr [bx], 0x1a
  if (!R.zf) goto L_446e;                                      // 4469 jne 0x446e
  R.cf = 0;                                                    // 446b clc
  goto L_443d;                                                 // 446c jmp 0x443d
L_446e:   R.cf = 1;                                                    // 446e stc
  R.ax = (u16)(0x1c00);                                        // 446f mov ax, 0x1c00
  goto L_443d;                                                 // 4472 jmp 0x443d
L_ret:
  return;
}

static u16 f_1000_434c(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_434c();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:43F2 FUN_1000_43f2  FIX: recompiled from the machine code (asm2c)
static void a_1000_43f2(void)
{
  FN(0x100043F2);
  R.cs = 0x27cc;
  goto L_43f2;
L_3ae3:   if (!R.cf) goto L_3aec;                                      // 3ae3 jae 0x3aec
  PUSH(0x3ae8); a_1000_3af6();                                 // 3ae5 call 0x3af6
  R.ax = (u16)(0xffff);                                        // 3ae8 mov ax, 0xffff
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 3aeb cdq
L_3aec:   R.sp = (u16)(R.bp);                                          // 3aec mov sp, bp
  R.bp = POP();                                                // 3aee pop bp
  R.sp += 2; goto L_ret;                                       // 3aef ret
L_43f2:   PUSH(R.ax);                                                  // 43f2 push ax
  PUSH(R.bx);                                                  // 43f3 push bx
  PUSH(R.cx);                                                  // 43f4 push cx
  R.cx = (u16)(R.di);                                          // 43f5 mov cx, di
  R.cx = (u16)(SUB16(R.cx, R.dx));                             // 43f7 sub cx, dx
  if (R.cx == 0) goto L_440b;                                  // 43f9 jcxz 0x440b
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 43fb mov bx, word ptr [bp + 4]
  SETH(R.ax, 0x40);                                            // 43fe mov ah, 0x40
  ASM_INT(0x21);                                               // 4400 int 0x21
  if (R.cf) goto L_4411;                                       // 4402 jb 0x4411
  W16(SS, (u16)(R.bp + 0xfffe), ADD16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 4404 add word ptr [bp - 2], ax
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 4407 or ax, ax
  if (R.zf) goto L_4411;                                       // 4409 je 0x4411
L_440b:   R.cx = POP();                                                // 440b pop cx
  R.bx = POP();                                                // 440c pop bx
  R.ax = POP();                                                // 440d pop ax
  R.di = (u16)(R.dx);                                          // 440e mov di, dx
  R.sp += 2; goto L_ret;                                       // 4410 ret
L_4411:   R.sp = (u16)(ADD16(R.sp, 0x8));                              // 4411 add sp, 8
  if (!R.cf) goto L_441a;                                      // 4414 jae 0x441a
  SETH(R.ax, 0x9);                                             // 4416 mov ah, 9
  goto L_4438;                                                 // 4418 jmp 0x4438
L_441a:   AND8(M8(DS, (u16)(R.bx + 0x2760)), 0x40);                    // 441a test byte ptr [bx + 0x2760], 0x40
  if (R.zf) goto L_442c;                                       // 441f je 0x442c
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 4421 mov bx, word ptr [bp + 6]
  SUB8(M8(DS, (u16)(R.bx)), 0x1a);                             // 4424 cmp byte ptr [bx], 0x1a
  if (!R.zf) goto L_442c;                                      // 4427 jne 0x442c
  R.cf = 0;                                                    // 4429 clc
  goto L_4438;                                                 // 442a jmp 0x4438
L_442c:   R.cf = 1;                                                    // 442c stc
  R.ax = (u16)(0x1c00);                                        // 442d mov ax, 0x1c00
  goto L_4438;                                                 // 4430 jmp 0x4438
L_4438:   R.sp = (u16)(M16(SS, (u16)(R.bp + 0xfff8)));                 // 4438 mov sp, word ptr [bp - 8]
  R.si = POP();                                                // 443b pop si
  R.di = POP();                                                // 443c pop di
  goto L_3ae3;                                                 // 443d jmp 0x3ae3
L_ret:
  return;
}

static u16 f_1000_43f2(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_43f2();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4474 FUN_1000_4474  FIX: recompiled from the machine code (asm2c)
static void a_1000_4474(void)
{
  FN(0x10004474);
  R.cs = 0x27cc;
  R.cx = POP();                                                // 4474 pop cx
  R.ax = (u16)(M16(DS, (u16)(0x278a)));                        // 4475 mov ax, word ptr [0x278a]
  SUB16(R.ax, R.sp);                                           // 4478 cmp ax, sp
  if (!R.cf) goto L_4482;                                      // 447a jae 0x4482
  R.ax = (u16)(SUB16(R.ax, R.sp));                             // 447c sub ax, sp
  R.ax = (u16)(NEG16(R.ax));                                   // 447e neg ax
L_4480:   goto L_ret;   /* to the return address the routine popped */ // 4480 jmp cx
L_4482:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 4482 xor ax, ax
  goto L_4480;                                                 // 4484 jmp 0x4480
L_ret:
  return;
}

static u16 f_1000_4474(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_4474();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4720 FUN_1000_4720  FIX: recompiled from the machine code (asm2c)
static void a_1000_4720(void)
{
  FN(0x10004720);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4720 push bp
  R.bp = (u16)(R.sp);                                          // 4721 mov bp, sp
  PUSH(R.di);                                                  // 4723 push di
  PUSH(R.si);                                                  // 4724 push si
  PUSH(R.ds);                                                  // 4725 push ds
  R.es = POP();                                                // 4726 pop es
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4727 mov di, word ptr [bp + 4]
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 472a mov si, word ptr [bp + 6]
  R.bx = (u16)(R.di);                                          // 472d mov bx, di
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 472f mov cx, word ptr [bp + 8]
  if (R.cx == 0) goto L_4740;                                  // 4732 jcxz 0x4740
L_4734:   LODSB();                                                     // 4734 lodsb al, byte ptr [si]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 4735 or al, al
  if (R.zf) goto L_473c;                                       // 4737 je 0x473c
  STOSB();                                                     // 4739 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_4734;                                // 473a loop 0x4734
L_473c:   SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 473c xor al, al
  REPSTOSB();                                                  // 473e rep stosb byte ptr es:[di], al
L_4740:   R.ax = (u16)(R.bx);                                          // 4740 mov ax, bx
  R.si = POP();                                                // 4742 pop si
  R.di = POP();                                                // 4743 pop di
  R.sp = (u16)(R.bp);                                          // 4744 mov sp, bp
  R.bp = POP();                                                // 4746 pop bp
  R.sp += 2; goto L_ret;                                       // 4747 ret
L_ret:
  return;
}

static u16 f_1000_4720(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4720();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4748 FUN_1000_4748  FIX: recompiled from the machine code (asm2c)
static void a_1000_4748(void)
{
  FN(0x10004748);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4748 push bp
  R.bp = (u16)(R.sp);                                          // 4749 mov bp, sp
  PUSH(R.di);                                                  // 474b push di
  PUSH(R.si);                                                  // 474c push si
  PUSH(R.ds);                                                  // 474d push ds
  R.es = POP();                                                // 474e pop es
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 474f mov cx, word ptr [bp + 8]
  if (R.cx == 0) goto L_477a;                                  // 4752 jcxz 0x477a
  R.bx = (u16)(R.cx);                                          // 4754 mov bx, cx
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4756 mov di, word ptr [bp + 4]
  R.si = (u16)(R.di);                                          // 4759 mov si, di
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 475b xor ax, ax
  REPNESCASB();                                                // 475d repne scasb al, byte ptr es:[di]
  R.cx = (u16)(NEG16(R.cx));                                   // 475f neg cx
  R.cx = (u16)(ADD16(R.cx, R.bx));                             // 4761 add cx, bx
  R.di = (u16)(R.si);                                          // 4763 mov di, si
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 4765 mov si, word ptr [bp + 6]
  REPECMPSB();                                                 // 4768 repe cmpsb byte ptr [si], byte ptr es:[di]
  SETL(R.ax, M8(DS, (u16)(R.si + 0xffff)));                    // 476a mov al, byte ptr [si - 1]
  R.cx = (u16)(XOR16(R.cx, R.cx));                             // 476d xor cx, cx
  SUB8((u8)R.ax, M8(DS, (u16)(R.di + 0xffff)));                // 476f cmp al, byte ptr [di - 1]
  if (!R.cf && !R.zf) goto L_4778;                             // 4772 ja 0x4778
  if (R.zf) goto L_477a;                                       // 4774 je 0x477a
  R.cx = (u16)(DEC16(R.cx));                                   // 4776 dec cx
  R.cx = (u16)(DEC16(R.cx));                                   // 4777 dec cx
L_4778:   R.cx = (u16)((u16)~R.cx);                                    // 4778 not cx
L_477a:   R.ax = (u16)(R.cx);                                          // 477a mov ax, cx
  R.si = POP();                                                // 477c pop si
  R.di = POP();                                                // 477d pop di
  R.sp = (u16)(R.bp);                                          // 477e mov sp, bp
  R.bp = POP();                                                // 4780 pop bp
  R.sp += 2; goto L_ret;                                       // 4781 ret
L_ret:
  return;
}

static u16 f_1000_4748(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4748();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4782 FUN_1000_4782  FIX: recompiled from the machine code (asm2c)
static void a_1000_4782(void)
{
  FN(0x10004782);
  R.cs = 0x27cc;
  goto L_4786;                                                 // 4782 jmp 0x4786
L_4786:   PUSH(R.bp);                                                  // 4786 push bp
  R.bp = (u16)(R.sp);                                          // 4787 mov bp, sp
  PUSH(R.di);                                                  // 4789 push di
  PUSH(R.si);                                                  // 478a push si
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 478b mov si, word ptr [bp + 4]
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 478e xor ax, ax
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4790 cdq
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 4791 xor bx, bx
L_4793:   LODSB();                                                     // 4793 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x20);                                        // 4794 cmp al, 0x20
  if (R.zf) goto L_4793;                                       // 4796 je 0x4793
  SUB8((u8)R.ax, 0x9);                                         // 4798 cmp al, 9
  if (R.zf) goto L_4793;                                       // 479a je 0x4793
  PUSH(R.ax);                                                  // 479c push ax
  SUB8((u8)R.ax, 0x2d);                                        // 479d cmp al, 0x2d
  if (R.zf) goto L_47a5;                                       // 479f je 0x47a5
  SUB8((u8)R.ax, 0x2b);                                        // 47a1 cmp al, 0x2b
  if (!R.zf) goto L_47a6;                                      // 47a3 jne 0x47a6
L_47a5:   LODSB();                                                     // 47a5 lodsb al, byte ptr [si]
L_47a6:   SUB8((u8)R.ax, 0x39);                                        // 47a6 cmp al, 0x39
  if (!R.cf && !R.zf) goto L_47c9;                             // 47a8 ja 0x47c9
  SETL(R.ax, SUB8((u8)R.ax, 0x30));                            // 47aa sub al, 0x30
  if (R.cf) goto L_47c9;                                       // 47ac jb 0x47c9
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 47ae shl bx, 1
  R.dx = (u16)(RCL16(R.dx, 0x1));                              // 47b0 rcl dx, 1
  R.cx = (u16)(R.bx);                                          // 47b2 mov cx, bx
  R.di = (u16)(R.dx);                                          // 47b4 mov di, dx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 47b6 shl bx, 1
  R.dx = (u16)(RCL16(R.dx, 0x1));                              // 47b8 rcl dx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 47ba shl bx, 1
  R.dx = (u16)(RCL16(R.dx, 0x1));                              // 47bc rcl dx, 1
  R.bx = (u16)(ADD16(R.bx, R.cx));                             // 47be add bx, cx
  R.dx = (u16)(ADC16(R.dx, R.di));                             // 47c0 adc dx, di
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 47c2 add bx, ax
  R.dx = (u16)(ADC16(R.dx, 0x0));                              // 47c4 adc dx, 0
  goto L_47a5;                                                 // 47c7 jmp 0x47a5
L_47c9:   R.ax = POP();                                                // 47c9 pop ax
  SUB8((u8)R.ax, 0x2d);                                        // 47ca cmp al, 0x2d
  { u16 t_ = R.bx; R.bx = (u16)(R.ax); R.ax = (u16)(t_); }     // 47cc xchg bx, ax
  if (!R.zf) goto L_47d6;                                      // 47cd jne 0x47d6
  R.ax = (u16)(NEG16(R.ax));                                   // 47cf neg ax
  R.dx = (u16)(ADC16(R.dx, 0x0));                              // 47d1 adc dx, 0
  R.dx = (u16)(NEG16(R.dx));                                   // 47d4 neg dx
L_47d6:   R.si = POP();                                                // 47d6 pop si
  R.di = POP();                                                // 47d7 pop di
  R.bp = POP();                                                // 47d8 pop bp
  R.sp += 2; goto L_ret;                                       // 47d9 ret
L_ret:
  return;
}

static u16 f_1000_4782(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4782();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:47DA FUN_1000_47da  FIX: recompiled from the machine code (asm2c)
static void a_1000_47da(void)
{
  FN(0x100047DA);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 47da push bp
  R.bp = (u16)(R.sp);                                          // 47db mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 47dd sub sp, 4
  PUSH(R.di);                                                  // 47e0 push di
  PUSH(R.si);                                                  // 47e1 push si
  R.si = (u16)(M16(DS, (u16)(0x2778)));                        // 47e2 mov si, word ptr [0x2778]
  R.si = (u16)(OR16(R.si, R.si));                              // 47e6 or si, si
  if (R.zf) goto L_4830;                                       // 47e8 je 0x4830
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 47ea cmp word ptr [bp + 4], 0
  if (R.zf) goto L_4830;                                       // 47ee je 0x4830
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 47f0 push word ptr [bp + 4]
  PUSH(0x47f6); a_1000_331f();                                 // 47f3 call 0x331f
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 47f6 add sp, 2
  R.di = (u16)(R.ax);                                          // 47f9 mov di, ax
  goto L_4801;                                                 // 47fb jmp 0x4801
L_47fe:   R.si = (u16)(ADD16(R.si, 0x2));                              // 47fe add si, 2
L_4801:   SUB16(M16(DS, (u16)(R.si)), 0x0);                            // 4801 cmp word ptr [si], 0
  if (R.zf) goto L_4830;                                       // 4804 je 0x4830
  PUSH(M16(DS, (u16)(R.si)));                                  // 4806 push word ptr [si]
  PUSH(0x480b); a_1000_331f();                                 // 4808 call 0x331f
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 480b add sp, 2
  SUB16(R.ax, R.di);                                           // 480e cmp ax, di
  if (R.zf || R.sf != R.of) goto L_47fe;                       // 4810 jle 0x47fe
  R.bx = (u16)(M16(DS, (u16)(R.si)));                          // 4812 mov bx, word ptr [si]
  SUB8(M8(DS, (u16)(R.bx + R.di)), 0x3d);                      // 4814 cmp byte ptr [bx + di], 0x3d
  if (!R.zf) goto L_47fe;                                      // 4817 jne 0x47fe
  PUSH(R.di);                                                  // 4819 push di
  PUSH(M16(SS, (u16)(R.bp + 0x4)));                            // 481a push word ptr [bp + 4]
  PUSH(R.bx);                                                  // 481d push bx
  PUSH(0x4821); a_1000_4748();                                 // 481e call 0x4748
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 4821 add sp, 6
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 4824 or ax, ax
  if (!R.zf) goto L_47fe;                                      // 4826 jne 0x47fe
  R.bx = (u16)(M16(DS, (u16)(R.si)));                          // 4828 mov bx, word ptr [si]
  R.ax = (u16)((u16)(R.bx + R.di + 0x1));                      // 482a lea ax, [bx + di + 1]
  goto L_4832;                                                 // 482d jmp 0x4832
L_4830:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 4830 sub ax, ax
L_4832:   R.si = POP();                                                // 4832 pop si
  R.di = POP();                                                // 4833 pop di
  R.sp = (u16)(R.bp);                                          // 4834 mov sp, bp
  R.bp = POP();                                                // 4836 pop bp
  R.sp += 2; goto L_ret;                                       // 4837 ret
L_ret:
  return;
}

static u16 f_1000_47da(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_47da();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4838 FUN_1000_4838  FIX: recompiled from the machine code (asm2c)
static void a_1000_4838(void)
{
  FN(0x10004838);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4838 push bp
  R.bp = (u16)(R.sp);                                          // 4839 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 483b sub sp, 2
  PUSH(R.di);                                                  // 483e push di
  PUSH(R.si);                                                  // 483f push si
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4840 mov si, word ptr [bp + 4]
  R.di = (u16)(0x2);                                           // 4843 mov di, 2
  R.si = (u16)(OR16(R.si, R.si));                              // 4846 or si, si
  if (R.zf) goto L_4870;                                       // 4848 je 0x4870
  SUB8(M8(DS, (u16)(R.si)), 0x0);                              // 484a cmp byte ptr [si], 0
  if (R.zf) goto L_4870;                                       // 484d je 0x4870
  PUSH(R.si);                                                  // 484f push si
  PUSH(0x4853); a_1000_331f();                                 // 4850 call 0x331f
  R.sp = (u16)(ADD16(R.sp, R.di));                             // 4853 add sp, di
  PUSH(R.ax);                                                  // 4855 push ax
  PUSH(R.si);                                                  // 4856 push si
  R.ax = (u16)(R.di);                                          // 4857 mov ax, di
  PUSH(R.ax);                                                  // 4859 push ax
  PUSH(0x485d); a_1000_434c();                                 // 485a call 0x434c
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 485d add sp, 6
  R.ax = (u16)(R.di);                                          // 4860 mov ax, di
  PUSH(R.ax);                                                  // 4862 push ax
  R.ax = (u16)(0x29d8);                                        // 4863 mov ax, 0x29d8
  PUSH(R.ax);                                                  // 4866 push ax
  R.ax = (u16)(R.di);                                          // 4867 mov ax, di
  PUSH(R.ax);                                                  // 4869 push ax
  PUSH(0x486d); a_1000_434c();                                 // 486a call 0x434c
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 486d add sp, 6
L_4870:   SUB16(M16(DS, (u16)(0x2751)), 0x0);                          // 4870 cmp word ptr [0x2751], 0
  if (R.sf != R.of) goto L_4880;                               // 4875 jl 0x4880
  R.ax = (u16)(M16(DS, (u16)(0x2bea)));                        // 4877 mov ax, word ptr [0x2bea]
  SUB16(M16(DS, (u16)(0x2751)), R.ax);                         // 487a cmp word ptr [0x2751], ax
  if (R.sf != R.of) goto L_4886;                               // 487e jl 0x4886
L_4880:   R.bx = (u16)(M16(DS, (u16)(0x2bea)));                        // 4880 mov bx, word ptr [0x2bea]
  goto L_488a;                                                 // 4884 jmp 0x488a
L_4886:   R.bx = (u16)(M16(DS, (u16)(0x2751)));                        // 4886 mov bx, word ptr [0x2751]
L_488a:   R.bx = (u16)(SHL16(R.bx, 0x1));                              // 488a shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x2b9e)));                 // 488c mov si, word ptr [bx + 0x2b9e]
  PUSH(R.si);                                                  // 4890 push si
  PUSH(0x4894); a_1000_331f();                                 // 4891 call 0x331f
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 4894 add sp, 2
  PUSH(R.ax);                                                  // 4897 push ax
  PUSH(R.si);                                                  // 4898 push si
  PUSH(R.di);                                                  // 4899 push di
  PUSH(0x489d); a_1000_434c();                                 // 489a call 0x434c
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 489d add sp, 6
  R.ax = (u16)(0x1);                                           // 48a0 mov ax, 1
  PUSH(R.ax);                                                  // 48a3 push ax
  R.ax = (u16)(0x29db);                                        // 48a4 mov ax, 0x29db
  PUSH(R.ax);                                                  // 48a7 push ax
  PUSH(R.di);                                                  // 48a8 push di
  PUSH(0x48ac); a_1000_434c();                                 // 48a9 call 0x434c
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 48ac add sp, 6
  R.si = POP();                                                // 48af pop si
  R.di = POP();                                                // 48b0 pop di
  R.sp = (u16)(R.bp);                                          // 48b1 mov sp, bp
  R.bp = POP();                                                // 48b3 pop bp
  R.sp += 2; goto L_ret;                                       // 48b4 ret
L_ret:
  return;
}

static u16 f_1000_4838(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4838();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:48BA FUN_1000_48ba  FIX: recompiled from the machine code (asm2c)
static void a_1000_48ba(void)
{
  FN(0x100048BA);
  R.cs = 0x27cc;
  SETH(R.dx, 0x8);                                             // 48ba mov dh, 8
  R.ax = (u16)(M16(DS, (u16)(0x29de)));                        // 48bc mov ax, word ptr [0x29de]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 48bf or ah, ah
  if (!R.zf) goto L_48cb;                                      // 48c1 jne 0x48cb
  W16(DS, (u16)(0x29de), 0xffff);                              // 48c3 mov word ptr [0x29de], 0xffff
  goto L_48d0;                                                 // 48c9 jmp 0x48d0
L_48cb:   { u16 t_ = R.dx; R.dx = (u16)(R.ax); R.ax = (u16)(t_); }     // 48cb xchg dx, ax
  ASM_INT(0x21);                                               // 48cc int 0x21
  SETH(R.ax, 0x0);                                             // 48ce mov ah, 0
L_48d0:   R.sp += 2; goto L_ret;                                       // 48d0 ret
L_ret:
  return;
}

static u16 f_1000_48ba(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_48ba();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4CEE FUN_1000_4cee  FIX: recompiled from the machine code (asm2c)
static void a_1000_4cee(void)
{
  FN(0x10004CEE);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4cee push bp
  R.bp = (u16)(R.sp);                                          // 4cef mov bp, sp
  PUSH(R.si);                                                  // 4cf1 push si
  PUSH(R.di);                                                  // 4cf2 push di
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4cf3 mov di, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.di)));                          // 4cf6 mov ax, word ptr [di]
  R.bx = (u16)(M16(DS, (u16)(R.di + 0x2)));                    // 4cf8 mov bx, word ptr [di + 2]
  R.cx = (u16)(M16(DS, (u16)(R.di + 0x4)));                    // 4cfb mov cx, word ptr [di + 4]
  R.dx = (u16)(M16(DS, (u16)(R.di + 0x6)));                    // 4cfe mov dx, word ptr [di + 6]
  R.si = (u16)(M16(DS, (u16)(R.di + 0x8)));                    // 4d01 mov si, word ptr [di + 8]
  R.di = (u16)(M16(DS, (u16)(R.di + 0xa)));                    // 4d04 mov di, word ptr [di + 0xa]
  ASM_INT(0x21);                                               // 4d07 int 0x21
  PUSH(R.di);                                                  // 4d09 push di
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 4d0a mov di, word ptr [bp + 6]
  W16(DS, (u16)(R.di), R.ax);                                  // 4d0d mov word ptr [di], ax
  W16(DS, (u16)(R.di + 0x2), R.bx);                            // 4d0f mov word ptr [di + 2], bx
  W16(DS, (u16)(R.di + 0x4), R.cx);                            // 4d12 mov word ptr [di + 4], cx
  W16(DS, (u16)(R.di + 0x6), R.dx);                            // 4d15 mov word ptr [di + 6], dx
  W16(DS, (u16)(R.di + 0x8), R.si);                            // 4d18 mov word ptr [di + 8], si
  W16(DS, (u16)(R.di + 0xa), POP());                           // 4d1b pop word ptr [di + 0xa]
  if (R.cf) goto L_4d24;                                       // 4d1e jb 0x4d24
  R.si = (u16)(XOR16(R.si, R.si));                             // 4d20 xor si, si
  goto L_4d2c;                                                 // 4d22 jmp 0x4d2c
L_4d24:   PUSH(0x4d27); a_1000_3af0();                                 // 4d24 call 0x3af0
  R.si = (u16)(0x1);                                           // 4d27 mov si, 1
  R.ax = (u16)(M16(DS, (u16)(R.di)));                          // 4d2a mov ax, word ptr [di]
L_4d2c:   W16(DS, (u16)(R.di + 0xc), R.si);                            // 4d2c mov word ptr [di + 0xc], si
  R.di = POP();                                                // 4d2f pop di
  R.si = POP();                                                // 4d30 pop si
  R.sp = (u16)(R.bp);                                          // 4d31 mov sp, bp
  R.bp = POP();                                                // 4d33 pop bp
  R.sp += 2; goto L_ret;                                       // 4d34 ret
L_ret:
  return;
}

static u16 f_1000_4cee(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4cee();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4D36 FUN_1000_4d36  FIX: recompiled from the machine code (asm2c)
static void a_1000_4d36(void)
{
  FN(0x10004D36);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4d36 push bp
  R.bp = (u16)(R.sp);                                          // 4d37 mov bp, sp
  PUSH(R.si);                                                  // 4d39 push si
  PUSH(R.di);                                                  // 4d3a push di
  PUSH(R.ds);                                                  // 4d3b push ds
  R.ds = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4d3c mov ds, word ptr [bp + 4]
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 4d3f mov si, word ptr [bp + 6]
  R.es = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 4d42 mov es, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 4d45 mov di, word ptr [bp + 0xa]
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 4d48 mov cx, word ptr [bp + 0xc]
  REPMOVSB();                                                  // 4d4b rep movsb byte ptr es:[di], byte ptr [si]
  R.ds = POP();                                                // 4d4d pop ds
  R.di = POP();                                                // 4d4e pop di
  R.si = POP();                                                // 4d4f pop si
  R.sp = (u16)(R.bp);                                          // 4d50 mov sp, bp
  R.bp = POP();                                                // 4d52 pop bp
  R.sp += 2; goto L_ret;                                       // 4d53 ret
L_ret:
  return;
}

static u16 f_1000_4d36(u16 p0, u16 p1, u16 p2, u16 p3, u16 p4)
{
  ASM_ENTER();
  PUSH((u16)p4);
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4d36();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4D54 FUN_1000_4d54  FIX: recompiled from the machine code (asm2c)
static void a_1000_4d54(void)
{
  FN(0x10004D54);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4d54 push bp
  R.bp = (u16)(R.sp);                                          // 4d55 mov bp, sp
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4d57 mov dx, word ptr [bp + 4]
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 4d5a in al, dx
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 4d5b xor ah, ah
  R.sp = (u16)(R.bp);                                          // 4d5d mov sp, bp
  R.bp = POP();                                                // 4d5f pop bp
  R.sp += 2; goto L_ret;                                       // 4d60 ret
L_ret:
  return;
}

static u16 f_1000_4d54(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4d54();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4D62 FUN_1000_4d62  FIX: recompiled from the machine code (asm2c)
static void a_1000_4d62(void)
{
  FN(0x10004D62);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4d62 push bp
  R.bp = (u16)(R.sp);                                          // 4d63 mov bp, sp
  PUSH(R.si);                                                  // 4d65 push si
  SETH(R.ax, 0x2a);                                            // 4d66 mov ah, 0x2a
  ASM_INT(0x21);                                               // 4d68 int 0x21
  R.bx = (u16)(R.dx);                                          // 4d6a mov bx, dx
  R.si = (u16)(R.cx);                                          // 4d6c mov si, cx
  SETH(R.ax, 0x2c);                                            // 4d6e mov ah, 0x2c
  ASM_INT(0x21);                                               // 4d70 int 0x21
  SETH(R.ax, 0x0);                                             // 4d72 mov ah, 0
  SETL(R.ax, (u8)(R.dx >> 8));                                 // 4d74 mov al, dh
  PUSH(R.ax);                                                  // 4d76 push ax
  SETL(R.ax, (u8)R.cx);                                        // 4d77 mov al, cl
  PUSH(R.ax);                                                  // 4d79 push ax
  SETL(R.ax, (u8)(R.cx >> 8));                                 // 4d7a mov al, ch
  PUSH(R.ax);                                                  // 4d7c push ax
  PUSH(R.ax);                                                  // 4d7d push ax
  SETH(R.ax, 0x2a);                                            // 4d7e mov ah, 0x2a
  ASM_INT(0x21);                                               // 4d80 int 0x21
  SUB16(R.bx, R.dx);                                           // 4d82 cmp bx, dx
  R.ax = POP();                                                // 4d84 pop ax
  if (R.zf) goto L_4d8f;                                       // 4d85 je 0x4d8f
  SUB8((u8)R.ax, 0x17);                                        // 4d87 cmp al, 0x17
  if (!R.zf) goto L_4d8f;                                      // 4d89 jne 0x4d8f
  R.dx = (u16)(R.bx);                                          // 4d8b mov dx, bx
  R.cx = (u16)(R.si);                                          // 4d8d mov cx, si
L_4d8f:   SETH(R.ax, 0x0);                                             // 4d8f mov ah, 0
  SETL(R.ax, (u8)R.dx);                                        // 4d91 mov al, dl
  PUSH(R.ax);                                                  // 4d93 push ax
  SETL(R.ax, (u8)(R.dx >> 8));                                 // 4d94 mov al, dh
  PUSH(R.ax);                                                  // 4d96 push ax
  R.cx = (u16)(SUB16(R.cx, 0x7bc));                            // 4d97 sub cx, 0x7bc
  PUSH(R.cx);                                                  // 4d9b push cx
  PUSH(0x4d9f); a_1000_4f3e();                                 // 4d9c call 0x4f3e
  R.sp = (u16)(ADD16(R.sp, 0xc));                              // 4d9f add sp, 0xc
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 4da2 cmp word ptr [bp + 4], 0
  if (R.zf) goto L_4db0;                                       // 4da6 je 0x4db0
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4da8 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x2), R.dx);                            // 4dab mov word ptr [bx + 2], dx
  W16(DS, (u16)(R.bx), R.ax);                                  // 4dae mov word ptr [bx], ax
L_4db0:   R.si = POP();                                                // 4db0 pop si
  R.bp = POP();                                                // 4db1 pop bp
  R.sp += 2; goto L_ret;                                       // 4db2 ret
L_ret:
  return;
}

static u16 f_1000_4d62(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4d62();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4DB4 FUN_1000_4db4  FIX: recompiled from the machine code (asm2c)
static void a_1000_4db4(void)
{
  FN(0x10004DB4);
  R.cs = 0x27cc;
  SUB16(M16(DS, (u16)(0x4a60)), 0x0);                          // 4db4 cmp word ptr [0x4a60], 0
  if (!R.zf) goto L_4dc2;                                      // 4db9 jne 0x4dc2
  PUSH(0x4dbe); a_1000_4dc4();                                 // 4dbb call 0x4dc4
  W16(DS, (u16)(0x4a60), INC16(M16(DS, (u16)(0x4a60))));       // 4dbe inc word ptr [0x4a60]
L_4dc2:   R.sp += 2; goto L_ret;                                       // 4dc2 ret
L_ret:
  return;
}

static u16 f_1000_4db4(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_4db4();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4DC4 FUN_1000_4dc4  FIX: recompiled from the machine code (asm2c)
static void a_1000_4dc4(void)
{
  FN(0x10004DC4);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4dc4 push bp
  R.bp = (u16)(R.sp);                                          // 4dc5 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 4dc7 sub sp, 4
  PUSH(R.di);                                                  // 4dca push di
  PUSH(R.si);                                                  // 4dcb push si
  R.ax = (u16)(0x2a14);                                        // 4dcc mov ax, 0x2a14
  PUSH(R.ax);                                                  // 4dcf push ax
  PUSH(0x4dd3); a_1000_47da();                                 // 4dd0 call 0x47da
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 4dd3 add sp, 2
  R.si = (u16)(R.ax);                                          // 4dd6 mov si, ax
  R.si = (u16)(OR16(R.si, R.si));                              // 4dd8 or si, si
  if (!R.zf) goto L_4ddf;                                      // 4dda jne 0x4ddf
  goto L_4e6e;                                                 // 4ddc jmp 0x4e6e
L_4ddf:   SUB8(M8(DS, (u16)(R.si)), 0x0);                              // 4ddf cmp byte ptr [si], 0
  if (!R.zf) goto L_4de7;                                      // 4de2 jne 0x4de7
  goto L_4e6e;                                                 // 4de4 jmp 0x4e6e
L_4de7:   R.ax = (u16)(0x3);                                           // 4de7 mov ax, 3
  PUSH(R.ax);                                                  // 4dea push ax
  PUSH(R.si);                                                  // 4deb push si
  PUSH(M16(DS, (u16)(0x2a26)));                                // 4dec push word ptr [0x2a26]
  PUSH(0x4df3); a_1000_4720();                                 // 4df0 call 0x4720
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 4df3 add sp, 6
  R.ax = (u16)(0xe10);                                         // 4df6 mov ax, 0xe10
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4df9 cdq
  PUSH(R.dx);                                                  // 4dfa push dx
  PUSH(R.ax);                                                  // 4dfb push ax
  R.si = (u16)(ADD16(R.si, 0x3));                              // 4dfc add si, 3
  PUSH(R.si);                                                  // 4dff push si
  PUSH(0x4e03); a_1000_4782();                                 // 4e00 call 0x4782
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 4e03 add sp, 2
  PUSH(R.dx);                                                  // 4e06 push dx
  PUSH(R.ax);                                                  // 4e07 push ax
  PUSH(0x4e0b); a_1000_5240();                                 // 4e08 call 0x5240
  W16(DS, (u16)(0x2a20), R.ax);                                // 4e0b mov word ptr [0x2a20], ax
  W16(DS, (u16)(0x2a22), R.dx);                                // 4e0e mov word ptr [0x2a22], dx
  R.di = (u16)(SUB16(R.di, R.di));                             // 4e12 sub di, di
L_4e14:   R.bx = (u16)(R.di);                                          // 4e14 mov bx, di
  R.bx = (u16)(ADD16(R.bx, R.si));                             // 4e16 add bx, si
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 4e18 cmp byte ptr [bx], 0
  if (R.zf) goto L_4e3c;                                       // 4e1b je 0x4e3c
  R.bx = (u16)(R.di);                                          // 4e1d mov bx, di
  R.bx = (u16)(ADD16(R.bx, R.si));                             // 4e1f add bx, si
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 4e21 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 4e23 cwde
  R.bx = (u16)(R.ax);                                          // 4e24 mov bx, ax
  AND8(M8(DS, (u16)(R.bx + 0x28d7)), 0x4);                     // 4e26 test byte ptr [bx + 0x28d7], 4
  if (!R.zf) goto L_4e36;                                      // 4e2b jne 0x4e36
  R.bx = (u16)(R.di);                                          // 4e2d mov bx, di
  R.bx = (u16)(ADD16(R.bx, R.si));                             // 4e2f add bx, si
  SUB8(M8(DS, (u16)(R.bx)), 0x2d);                             // 4e31 cmp byte ptr [bx], 0x2d
  if (!R.zf) goto L_4e3c;                                      // 4e34 jne 0x4e3c
L_4e36:   R.di = (u16)(INC16(R.di));                                   // 4e36 inc di
  SUB16(R.di, 0x3);                                            // 4e37 cmp di, 3
  if (R.sf != R.of) goto L_4e14;                               // 4e3a jl 0x4e14
L_4e3c:   R.bx = (u16)(R.di);                                          // 4e3c mov bx, di
  R.bx = (u16)(ADD16(R.bx, R.si));                             // 4e3e add bx, si
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 4e40 cmp byte ptr [bx], 0
  if (R.zf) goto L_4e5a;                                       // 4e43 je 0x4e5a
  R.ax = (u16)(0x3);                                           // 4e45 mov ax, 3
  PUSH(R.ax);                                                  // 4e48 push ax
  R.ax = (u16)(R.di);                                          // 4e49 mov ax, di
  R.ax = (u16)(ADD16(R.ax, R.si));                             // 4e4b add ax, si
  PUSH(R.ax);                                                  // 4e4d push ax
  PUSH(M16(DS, (u16)(0x2a28)));                                // 4e4e push word ptr [0x2a28]
  PUSH(0x4e55); a_1000_4720();                                 // 4e52 call 0x4720
  R.sp = (u16)(ADD16(R.sp, 0x6));                              // 4e55 add sp, 6
  goto L_4e61;                                                 // 4e58 jmp 0x4e61
L_4e5a:   R.bx = (u16)(M16(DS, (u16)(0x2a28)));                        // 4e5a mov bx, word ptr [0x2a28]
  W8(DS, (u16)(R.bx), 0x0);                                    // 4e5e mov byte ptr [bx], 0
L_4e61:   R.bx = (u16)(M16(DS, (u16)(0x2a28)));                        // 4e61 mov bx, word ptr [0x2a28]
  SUB8(M8(DS, (u16)(R.bx)), 0x1);                              // 4e65 cmp byte ptr [bx], 1
  R.ax = (u16)(SBB16(R.ax, R.ax));                             // 4e68 sbb ax, ax
  R.ax = (u16)(INC16(R.ax));                                   // 4e6a inc ax
  W16(DS, (u16)(0x2a24), R.ax);                                // 4e6b mov word ptr [0x2a24], ax
L_4e6e:   R.si = POP();                                                // 4e6e pop si
  R.di = POP();                                                // 4e6f pop di
  R.sp = (u16)(R.bp);                                          // 4e70 mov sp, bp
  R.bp = POP();                                                // 4e72 pop bp
  R.sp += 2; goto L_ret;                                       // 4e73 ret
L_ret:
  return;
}

static u16 f_1000_4dc4(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_4dc4();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4E74 FUN_1000_4e74  FIX: recompiled from the machine code (asm2c)
static void a_1000_4e74(void)
{
  FN(0x10004E74);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4e74 push bp
  R.bp = (u16)(R.sp);                                          // 4e75 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x6));                              // 4e77 sub sp, 6
  PUSH(R.di);                                                  // 4e7a push di
  PUSH(R.si);                                                  // 4e7b push si
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4e7c mov si, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.si + 0x8)), 0x3);                      // 4e7f cmp word ptr [si + 8], 3
  if (R.sf == R.of) goto L_4e88;                               // 4e83 jge 0x4e88
  goto L_4f36;                                                 // 4e85 jmp 0x4f36
L_4e88:   SUB16(M16(DS, (u16)(R.si + 0x8)), 0x9);                      // 4e88 cmp word ptr [si + 8], 9
  if (R.zf || R.sf != R.of) goto L_4e91;                       // 4e8c jle 0x4e91
  goto L_4f36;                                                 // 4e8e jmp 0x4f36
L_4e91:   SUB16(M16(DS, (u16)(R.si + 0x8)), 0x3);                      // 4e91 cmp word ptr [si + 8], 3
  if (R.zf || R.sf != R.of) goto L_4ea0;                       // 4e95 jle 0x4ea0
  SUB16(M16(DS, (u16)(R.si + 0x8)), 0x9);                      // 4e97 cmp word ptr [si + 8], 9
  if (R.sf == R.of) goto L_4ea0;                               // 4e9b jge 0x4ea0
  goto L_4f20;                                                 // 4e9d jmp 0x4f20
L_4ea0:   R.di = (u16)(M16(DS, (u16)(R.si + 0xa)));                    // 4ea0 mov di, word ptr [si + 0xa]
  R.di = (u16)(ADD16(R.di, 0x76c));                            // 4ea3 add di, 0x76c
  SUB16(R.di, 0x7c2);                                          // 4ea7 cmp di, 0x7c2
  if (R.zf || R.sf != R.of) goto L_4ec2;                       // 4eab jle 0x4ec2
  SUB16(M16(DS, (u16)(R.si + 0x8)), 0x3);                      // 4ead cmp word ptr [si + 8], 3
  if (!R.zf) goto L_4ec2;                                      // 4eb1 jne 0x4ec2
  R.bx = (u16)(M16(DS, (u16)(R.si + 0x8)));                    // 4eb3 mov bx, word ptr [si + 8]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 4eb6 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x29fa)));                 // 4eb8 mov ax, word ptr [bx + 0x29fa]
  R.ax = (u16)(ADD16(R.ax, 0x7));                              // 4ebc add ax, 7
  goto L_4ecb;                                                 // 4ebf jmp 0x4ecb
L_4ec2:   R.bx = (u16)(M16(DS, (u16)(R.si + 0x8)));                    // 4ec2 mov bx, word ptr [si + 8]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 4ec5 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x29fc)));                 // 4ec7 mov ax, word ptr [bx + 0x29fc]
L_4ecb:   W16(SS, (u16)(R.bp + 0xfffa), R.ax);                         // 4ecb mov word ptr [bp - 6], ax
  AND16(R.di, 0x3);                                            // 4ece test di, 3
  if (!R.zf) goto L_4ed7;                                      // 4ed2 jne 0x4ed7
  W16(SS, (u16)(R.bp + 0xfffa), INC16(M16(SS, (u16)(R.bp + 0xfffa)))); // 4ed4 inc word ptr [bp - 6]
L_4ed7:   R.di = (u16)(M16(DS, (u16)(R.si + 0xa)));                    // 4ed7 mov di, word ptr [si + 0xa]
  R.di = (u16)(SUB16(R.di, 0x46));                             // 4eda sub di, 0x46
  R.ax = (u16)(0x16d);                                         // 4edd mov ax, 0x16d
  IMUL16(R.di);                                                // 4ee0 imul di
  R.cx = (u16)(R.ax);                                          // 4ee2 mov cx, ax
  R.ax = (u16)((u16)(R.di + 0x1));                             // 4ee4 lea ax, [di + 1]
  R.bx = (u16)(R.cx);                                          // 4ee7 mov bx, cx
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4ee9 cdq
  R.ax = (u16)(XOR16(R.ax, R.dx));                             // 4eea xor ax, dx
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 4eec sub ax, dx
  R.cx = (u16)(0x2);                                           // 4eee mov cx, 2
  R.ax = (u16)(SAR16(R.ax, (u8)R.cx));                         // 4ef1 sar ax, cl
  R.ax = (u16)(XOR16(R.ax, R.dx));                             // 4ef3 xor ax, dx
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 4ef5 sub ax, dx
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xfffa))));    // 4ef7 add ax, word ptr [bp - 6]
  R.ax = (u16)(ADD16(R.ax, R.bx));                             // 4efa add ax, bx
  R.ax = (u16)(ADD16(R.ax, 0x4));                              // 4efc add ax, 4
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4eff cdq
  R.cx = (u16)(0x7);                                           // 4f00 mov cx, 7
  IDIV16(R.cx, 0x4f03);                                        // 4f03 idiv cx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 4f05 mov ax, word ptr [bp - 6]
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 4f08 sub ax, dx
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 4f0a mov word ptr [bp - 2], ax
  SUB16(M16(DS, (u16)(R.si + 0x8)), 0x3);                      // 4f0d cmp word ptr [si + 8], 3
  if (!R.zf) goto L_4f26;                                      // 4f11 jne 0x4f26
  SUB16(M16(DS, (u16)(R.si + 0xe)), R.ax);                     // 4f13 cmp word ptr [si + 0xe], ax
  if (!R.zf && R.sf == R.of) goto L_4f20;                      // 4f16 jg 0x4f20
  if (!R.zf) goto L_4f36;                                      // 4f18 jne 0x4f36
  SUB16(M16(DS, (u16)(R.si + 0x4)), 0x2);                      // 4f1a cmp word ptr [si + 4], 2
  if (R.sf != R.of) goto L_4f36;                               // 4f1e jl 0x4f36
L_4f20:   R.ax = (u16)(0x1);                                           // 4f20 mov ax, 1
  goto L_4f38;                                                 // 4f23 jmp 0x4f38
L_4f26:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 4f26 mov ax, word ptr [bp - 2]
  SUB16(M16(DS, (u16)(R.si + 0xe)), R.ax);                     // 4f29 cmp word ptr [si + 0xe], ax
  if (R.sf != R.of) goto L_4f20;                               // 4f2c jl 0x4f20
  if (!R.zf) goto L_4f36;                                      // 4f2e jne 0x4f36
  SUB16(M16(DS, (u16)(R.si + 0x4)), 0x1);                      // 4f30 cmp word ptr [si + 4], 1
  if (R.sf != R.of) goto L_4f20;                               // 4f34 jl 0x4f20
L_4f36:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 4f36 sub ax, ax
L_4f38:   R.si = POP();                                                // 4f38 pop si
  R.di = POP();                                                // 4f39 pop di
  R.sp = (u16)(R.bp);                                          // 4f3a mov sp, bp
  R.bp = POP();                                                // 4f3c pop bp
  R.sp += 2; goto L_ret;                                       // 4f3d ret
L_ret:
  return;
}

static u16 f_1000_4e74(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4e74();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:4F3E FUN_1000_4f3e  FIX: recompiled from the machine code (asm2c)
static void a_1000_4f3e(void)
{
  FN(0x10004F3E);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 4f3e push bp
  R.bp = (u16)(R.sp);                                          // 4f3f mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x20));                             // 4f41 sub sp, 0x20
  PUSH(R.di);                                                  // 4f44 push di
  PUSH(R.si);                                                  // 4f45 push si
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 4f46 mov si, word ptr [bp + 4]
  R.ax = (u16)(0x5180);                                        // 4f49 mov ax, 0x5180
  R.dx = (u16)(0x1);                                           // 4f4c mov dx, 1
  PUSH(R.dx);                                                  // 4f4f push dx
  PUSH(R.ax);                                                  // 4f50 push ax
  R.ax = (u16)((u16)(R.si + 0x3));                             // 4f51 lea ax, [si + 3]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4f54 cdq
  R.ax = (u16)(XOR16(R.ax, R.dx));                             // 4f55 xor ax, dx
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 4f57 sub ax, dx
  R.cx = (u16)(0x2);                                           // 4f59 mov cx, 2
  R.ax = (u16)(SAR16(R.ax, (u8)R.cx));                         // 4f5c sar ax, cl
  R.ax = (u16)(XOR16(R.ax, R.dx));                             // 4f5e xor ax, dx
  R.ax = (u16)(SUB16(R.ax, R.dx));                             // 4f60 sub ax, dx
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4f62 cdq
  PUSH(R.dx);                                                  // 4f63 push dx
  PUSH(R.ax);                                                  // 4f64 push ax
  PUSH(0x4f68); a_1000_5240();                                 // 4f65 call 0x5240
  W16(SS, (u16)(R.bp + 0xffea), R.ax);                         // 4f68 mov word ptr [bp - 0x16], ax
  W16(SS, (u16)(R.bp + 0xffec), R.dx);                         // 4f6b mov word ptr [bp - 0x14], dx
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 4f6e mov bx, word ptr [bp + 6]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 4f71 shl bx, 1
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x29f8)));                 // 4f73 mov di, word ptr [bx + 0x29f8]
  R.ax = (u16)(R.si);                                          // 4f77 mov ax, si
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4f79 cdq
  R.cx = (u16)(0x4);                                           // 4f7a mov cx, 4
  IDIV16(R.cx, 0x4f7d);                                        // 4f7d idiv cx
  R.dx = (u16)(OR16(R.dx, R.dx));                              // 4f7f or dx, dx
  if (!R.zf) goto L_4f8a;                                      // 4f81 jne 0x4f8a
  SUB16(M16(SS, (u16)(R.bp + 0x6)), 0x2);                      // 4f83 cmp word ptr [bp + 6], 2
  if (R.zf || R.sf != R.of) goto L_4f8a;                       // 4f87 jle 0x4f8a
  R.di = (u16)(INC16(R.di));                                   // 4f89 inc di
L_4f8a:   R.ax = (u16)(0x3c);                                          // 4f8a mov ax, 0x3c
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4f8d cdq
  PUSH(R.dx);                                                  // 4f8e push dx
  PUSH(R.ax);                                                  // 4f8f push ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 4f90 mov ax, word ptr [bp + 0xc]
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4f93 cdq
  PUSH(R.dx);                                                  // 4f94 push dx
  PUSH(R.ax);                                                  // 4f95 push ax
  PUSH(0x4f99); a_1000_5240();                                 // 4f96 call 0x5240
  R.cx = (u16)(0xe10);                                         // 4f99 mov cx, 0xe10
  R.bx = (u16)(SUB16(R.bx, R.bx));                             // 4f9c sub bx, bx
  PUSH(R.bx);                                                  // 4f9e push bx
  PUSH(R.cx);                                                  // 4f9f push cx
  R.cx = (u16)(R.ax);                                          // 4fa0 mov cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 4fa2 mov ax, word ptr [bp + 0xa]
  R.bx = (u16)(R.dx);                                          // 4fa5 mov bx, dx
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4fa7 cdq
  PUSH(R.dx);                                                  // 4fa8 push dx
  PUSH(R.ax);                                                  // 4fa9 push ax
  W16(SS, (u16)(R.bp + 0xffe4), R.cx);                         // 4faa mov word ptr [bp - 0x1c], cx
  W16(SS, (u16)(R.bp + 0xffe6), R.bx);                         // 4fad mov word ptr [bp - 0x1a], bx
  PUSH(0x4fb3); a_1000_5240();                                 // 4fb0 call 0x5240
  R.cx = (u16)(0x5180);                                        // 4fb3 mov cx, 0x5180
  R.bx = (u16)(0x1);                                           // 4fb6 mov bx, 1
  PUSH(R.bx);                                                  // 4fb9 push bx
  PUSH(R.cx);                                                  // 4fba push cx
  R.cx = (u16)(R.ax);                                          // 4fbb mov cx, ax
  R.ax = (u16)(0x16d);                                         // 4fbd mov ax, 0x16d
  R.bx = (u16)(R.dx);                                          // 4fc0 mov bx, dx
  IMUL16(R.si);                                                // 4fc2 imul si
  R.dx = (u16)(R.ax);                                          // 4fc4 mov dx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 4fc6 mov ax, word ptr [bp + 8]
  R.ax = (u16)(ADD16(R.ax, R.dx));                             // 4fc9 add ax, dx
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 4fcb add ax, di
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4fcd cdq
  PUSH(R.dx);                                                  // 4fce push dx
  PUSH(R.ax);                                                  // 4fcf push ax
  W16(SS, (u16)(R.bp + 0xffe0), R.cx);                         // 4fd0 mov word ptr [bp - 0x20], cx
  W16(SS, (u16)(R.bp + 0xffe2), R.bx);                         // 4fd3 mov word ptr [bp - 0x1e], bx
  PUSH(0x4fd9); a_1000_5240();                                 // 4fd6 call 0x5240
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xffe0))));    // 4fd9 add ax, word ptr [bp - 0x20]
  R.dx = (u16)(ADC16(R.dx, M16(SS, (u16)(R.bp + 0xffe2))));    // 4fdc adc dx, word ptr [bp - 0x1e]
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xffe4))));    // 4fdf add ax, word ptr [bp - 0x1c]
  R.dx = (u16)(ADC16(R.dx, M16(SS, (u16)(R.bp + 0xffe6))));    // 4fe2 adc dx, word ptr [bp - 0x1a]
  R.cx = (u16)(R.ax);                                          // 4fe5 mov cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 4fe7 mov ax, word ptr [bp + 0xe]
  R.bx = (u16)(R.dx);                                          // 4fea mov bx, dx
  R.dx = (R.ax & 0x8000) ? 0xFFFF : 0;                         // 4fec cdq
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 4fed add cx, ax
  R.bx = (u16)(ADC16(R.bx, R.dx));                             // 4fef adc bx, dx
  R.cx = (u16)(ADD16(R.cx, 0xa600));                           // 4ff1 add cx, 0xa600
  R.bx = (u16)(ADC16(R.bx, 0x12ce));                           // 4ff5 adc bx, 0x12ce
  W16(SS, (u16)(R.bp + 0xffea), ADD16(M16(SS, (u16)(R.bp + 0xffea)), R.cx)); // 4ff9 add word ptr [bp - 0x16], cx
  W16(SS, (u16)(R.bp + 0xffec), ADC16(M16(SS, (u16)(R.bp + 0xffec)), R.bx)); // 4ffc adc word ptr [bp - 0x14], bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 4fff mov ax, word ptr [bp + 8]
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 5002 add ax, di
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 5004 mov word ptr [bp - 4], ax
  PUSH(0x500a); a_1000_4db4();                                 // 5007 call 0x4db4
  R.ax = (u16)(M16(DS, (u16)(0x2a20)));                        // 500a mov ax, word ptr [0x2a20]
  R.dx = (u16)(M16(DS, (u16)(0x2a22)));                        // 500d mov dx, word ptr [0x2a22]
  W16(SS, (u16)(R.bp + 0xffea), ADD16(M16(SS, (u16)(R.bp + 0xffea)), R.ax)); // 5011 add word ptr [bp - 0x16], ax
  W16(SS, (u16)(R.bp + 0xffec), ADC16(M16(SS, (u16)(R.bp + 0xffec)), R.dx)); // 5014 adc word ptr [bp - 0x14], dx
  R.ax = (u16)((u16)(R.si + 0x50));                            // 5017 lea ax, [si + 0x50]
  W16(SS, (u16)(R.bp + 0xfff8), R.ax);                         // 501a mov word ptr [bp - 8], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 501d mov ax, word ptr [bp + 6]
  R.ax = (u16)(DEC16(R.ax));                                   // 5020 dec ax
  W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 5021 mov word ptr [bp - 0xa], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 5024 mov ax, word ptr [bp + 0xa]
  W16(SS, (u16)(R.bp + 0xfff2), R.ax);                         // 5027 mov word ptr [bp - 0xe], ax
  SUB16(M16(DS, (u16)(0x2a24)), 0x0);                          // 502a cmp word ptr [0x2a24], 0
  if (R.zf) goto L_5048;                                       // 502f je 0x5048
  R.ax = (u16)((u16)(R.bp + 0xffee));                          // 5031 lea ax, [bp - 0x12]
  PUSH(R.ax);                                                  // 5034 push ax
  PUSH(0x5038); a_1000_4e74();                                 // 5035 call 0x4e74
  R.sp = (u16)(ADD16(R.sp, 0x2));                              // 5038 add sp, 2
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 503b or ax, ax
  if (R.zf) goto L_5048;                                       // 503d je 0x5048
  W16(SS, (u16)(R.bp + 0xffea), SUB16(M16(SS, (u16)(R.bp + 0xffea)), 0xe10)); // 503f sub word ptr [bp - 0x16], 0xe10
  W16(SS, (u16)(R.bp + 0xffec), SBB16(M16(SS, (u16)(R.bp + 0xffec)), 0x0)); // 5044 sbb word ptr [bp - 0x14], 0
L_5048:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0xffea)));                 // 5048 mov ax, word ptr [bp - 0x16]
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0xffec)));                 // 504b mov dx, word ptr [bp - 0x14]
  R.si = POP();                                                // 504e pop si
  R.di = POP();                                                // 504f pop di
  R.sp = (u16)(R.bp);                                          // 5050 mov sp, bp
  R.bp = POP();                                                // 5052 pop bp
  R.sp += 2; goto L_ret;                                       // 5053 ret
L_ret:
  return;
}

static u16 f_1000_4f3e(u16 p0, u16 p1, u16 p2, u16 p3, u16 p4, u16 p5)
{
  ASM_ENTER();
  PUSH((u16)p5);
  PUSH((u16)p4);
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_4f3e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:5054 FUN_1000_5054  FIX: recompiled from the machine code (asm2c)
static void a_1000_5054(void)
{
  FN(0x10005054);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 5054 push bp
  R.bp = (u16)(R.sp);                                          // 5055 mov bp, sp
  PUSH(R.di);                                                  // 5057 push di
  PUSH(R.si);                                                  // 5058 push si
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 5059 mov si, word ptr [bp + 4]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 505c mov di, word ptr [bp + 6]
  PUSH(R.ds);                                                  // 505f push ds
  R.es = POP();                                                // 5060 pop es
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 5061 mov cx, word ptr [bp + 8]
  if (R.cx == 0) goto L_50a3;                                  // 5064 jcxz 0x50a3
  SETH(R.bx, 0x41);                                            // 5066 mov bh, 0x41
  SETL(R.bx, 0x5a);                                            // 5068 mov bl, 0x5a
  SETH(R.dx, 0x20);                                            // 506a mov dh, 0x20
L_506c:   SETH(R.ax, M8(DS, (u16)(R.si)));                             // 506c mov ah, byte ptr [si]
  SETL(R.ax, M8(DS, (u16)(R.di)));                             // 506e mov al, byte ptr [di]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 5070 or ah, ah
  if (R.zf) goto L_5094;                                       // 5072 je 0x5094
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 5074 or al, al
  if (R.zf) goto L_5094;                                       // 5076 je 0x5094
  R.si = (u16)(INC16(R.si));                                   // 5078 inc si
  R.di = (u16)(INC16(R.di));                                   // 5079 inc di
  SUB8((u8)(R.ax >> 8), (u8)(R.bx >> 8));                      // 507a cmp ah, bh
  if (R.cf) goto L_5084;                                       // 507c jb 0x5084
  SUB8((u8)(R.ax >> 8), (u8)R.bx);                             // 507e cmp ah, bl
  if (!R.cf && !R.zf) goto L_5084;                             // 5080 ja 0x5084
  SETH(R.ax, ADD8((u8)(R.ax >> 8), (u8)(R.dx >> 8)));          // 5082 add ah, dh
L_5084:   SUB8((u8)R.ax, (u8)(R.bx >> 8));                             // 5084 cmp al, bh
  if (R.cf) goto L_508e;                                       // 5086 jb 0x508e
  SUB8((u8)R.ax, (u8)R.bx);                                    // 5088 cmp al, bl
  if (!R.cf && !R.zf) goto L_508e;                             // 508a ja 0x508e
  SETL(R.ax, ADD8((u8)R.ax, (u8)(R.dx >> 8)));                 // 508c add al, dh
L_508e:   SUB8((u8)(R.ax >> 8), (u8)R.ax);                             // 508e cmp ah, al
  if (!R.zf) goto L_509a;                                      // 5090 jne 0x509a
  if (--R.cx != 0) goto L_506c;                                // 5092 loop 0x506c
L_5094:   R.cx = (u16)(XOR16(R.cx, R.cx));                             // 5094 xor cx, cx
  SUB8((u8)(R.ax >> 8), (u8)R.ax);                             // 5096 cmp ah, al
  if (R.zf) goto L_50a3;                                       // 5098 je 0x50a3
L_509a:   R.cx = (u16)(0x0);                                           // 509a mov cx, 0
  if (R.cf) goto L_50a1;                                       // 509d jb 0x50a1
  R.cx = (u16)(DEC16(R.cx));                                   // 509f dec cx
  R.cx = (u16)(DEC16(R.cx));                                   // 50a0 dec cx
L_50a1:   R.cx = (u16)((u16)~R.cx);                                    // 50a1 not cx
L_50a3:   R.ax = (u16)(R.cx);                                          // 50a3 mov ax, cx
  R.si = POP();                                                // 50a5 pop si
  R.di = POP();                                                // 50a6 pop di
  R.sp = (u16)(R.bp);                                          // 50a7 mov sp, bp
  R.bp = POP();                                                // 50a9 pop bp
  R.sp += 2; goto L_ret;                                       // 50aa ret
L_ret:
  return;
}

static u16 f_1000_5054(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_5054();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:50D8 FUN_1000_50d8  FIX: recompiled from the machine code (asm2c)
static void a_1000_50d8(void)
{
  FN(0x100050D8);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 50d8 push bp
  R.bp = (u16)(R.sp);                                          // 50d9 mov bp, sp
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x0);                      // 50db cmp word ptr [bp + 4], 0
  if (R.sf != R.of) goto L_50e6;                               // 50df jl 0x50e6
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 50e1 mov ax, word ptr [bp + 4]
  goto L_50eb;                                                 // 50e4 jmp 0x50eb
L_50e6:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 50e6 mov ax, word ptr [bp + 4]
  R.ax = (u16)(NEG16(R.ax));                                   // 50e9 neg ax
L_50eb:   R.bp = POP();                                                // 50eb pop bp
  R.sp += 2; goto L_ret;                                       // 50ec ret
L_ret:
  return;
}

static u16 f_1000_50d8(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_50d8();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:50EE FUN_1000_50ee  FIX: recompiled from the machine code (asm2c)
static void a_1000_50ee(void)
{
  FN(0x100050EE);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 50ee push bp
  R.bp = (u16)(R.sp);                                          // 50ef mov bp, sp
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 50f1 mov ax, word ptr [bp + 4]
  W16(DS, (u16)(0x2a66), R.ax);                                // 50f4 mov word ptr [0x2a66], ax
  W16(DS, (u16)(0x2a68), 0x0);                                 // 50f7 mov word ptr [0x2a68], 0
  R.bp = POP();                                                // 50fd pop bp
  R.sp += 2; goto L_ret;                                       // 50fe ret
L_ret:
  return;
}

static u16 f_1000_50ee(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_50ee();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:5100 FUN_1000_5100  FIX: recompiled from the machine code (asm2c)
static void a_1000_5100(void)
{
  FN(0x10005100);
  R.cs = 0x27cc;
  R.ax = (u16)(0x43fd);                                        // 5100 mov ax, 0x43fd
  R.dx = (u16)(0x3);                                           // 5103 mov dx, 3
  PUSH(R.dx);                                                  // 5106 push dx
  PUSH(R.ax);                                                  // 5107 push ax
  PUSH(M16(DS, (u16)(0x2a68)));                                // 5108 push word ptr [0x2a68]
  PUSH(M16(DS, (u16)(0x2a66)));                                // 510c push word ptr [0x2a66]
  PUSH(0x5113); a_1000_5240();                                 // 5110 call 0x5240
  R.ax = (u16)(ADD16(R.ax, 0x9ec3));                           // 5113 add ax, 0x9ec3
  R.dx = (u16)(ADC16(R.dx, 0x26));                             // 5116 adc dx, 0x26
  W16(DS, (u16)(0x2a66), R.ax);                                // 5119 mov word ptr [0x2a66], ax
  W16(DS, (u16)(0x2a68), R.dx);                                // 511c mov word ptr [0x2a68], dx
  R.ax = (u16)(R.dx);                                          // 5120 mov ax, dx
  SETH(R.ax, AND8((u8)(R.ax >> 8), 0x7f));                     // 5122 and ah, 0x7f
  R.sp += 2; goto L_ret;                                       // 5125 ret
L_ret:
  return;
}

static u16 f_1000_5100(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1000_5100();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:5126 FUN_1000_5126  FIX: recompiled from the machine code (asm2c)
static void a_1000_5126(void)
{
  FN(0x10005126);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 5126 push bp
  R.bp = (u16)(R.sp);                                          // 5127 mov bp, sp
  SETH(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 5129 mov ah, byte ptr [bp + 4]
  ASM_INT(0x16);                                               // 512c int 0x16
  if (!R.zf) goto L_5138;                                      // 512e jne 0x5138
  SUB8(M8(SS, (u16)(R.bp + 0x4)), 0x1);                        // 5130 cmp byte ptr [bp + 4], 1
  if (!R.zf) goto L_5138;                                      // 5134 jne 0x5138
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 5136 xor ax, ax
L_5138:   R.bp = POP();                                                // 5138 pop bp
  R.sp += 2; goto L_ret;                                       // 5139 ret
L_ret:
  return;
}

static u16 f_1000_5126(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_5126();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:513A FUN_1000_513a  FIX: recompiled from the machine code (asm2c)
static void a_1000_513a(void)
{
  FN(0x1000513A);
  R.cs = 0x27cc;
  goto L_513a;
L_3ad2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3ad2 xor ax, ax
  R.sp = (u16)(R.bp);                                          // 3ad4 mov sp, bp
  R.bp = POP();                                                // 3ad6 pop bp
  R.sp += 2; goto L_ret;                                       // 3ad7 ret
L_3ad8:   if (!R.cf) goto L_3ad2;                                      // 3ad8 jae 0x3ad2
  PUSH(R.ax);                                                  // 3ada push ax
  PUSH(0x3ade); a_1000_3af6();                                 // 3adb call 0x3af6
  R.ax = POP();                                                // 3ade pop ax
  R.sp = (u16)(R.bp);                                          // 3adf mov sp, bp
  R.bp = POP();                                                // 3ae1 pop bp
  R.sp += 2; goto L_ret;                                       // 3ae2 ret
L_513a:   PUSH(R.bp);                                                  // 513a push bp
  R.bp = (u16)(R.sp);                                          // 513b mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 513d mov bx, word ptr [bp + 4]
  SETH(R.ax, 0x3e);                                            // 5140 mov ah, 0x3e
  ASM_INT(0x21);                                               // 5142 int 0x21
  goto L_3ad8;                                                 // 5144 jmp 0x3ad8
L_ret:
  return;
}

static u16 f_1000_513a(u16 p0)
{
  ASM_ENTER();
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_513a();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:5168 FUN_1000_5168  FIX: recompiled from the machine code (asm2c)
static void a_1000_5168(void)
{
  FN(0x10005168);
  R.cs = 0x27cc;
  goto L_5168;
L_3ad2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3ad2 xor ax, ax
  R.sp = (u16)(R.bp);                                          // 3ad4 mov sp, bp
  R.bp = POP();                                                // 3ad6 pop bp
  R.sp += 2; goto L_ret;                                       // 3ad7 ret
L_3ad8:   if (!R.cf) goto L_3ad2;                                      // 3ad8 jae 0x3ad2
  PUSH(R.ax);                                                  // 3ada push ax
  PUSH(0x3ade); a_1000_3af6();                                 // 3adb call 0x3af6
  R.ax = POP();                                                // 3ade pop ax
  R.sp = (u16)(R.bp);                                          // 3adf mov sp, bp
  R.bp = POP();                                                // 3ae1 pop bp
  R.sp += 2; goto L_ret;                                       // 3ae2 ret
L_5168:   PUSH(R.bp);                                                  // 5168 push bp
  R.bp = (u16)(R.sp);                                          // 5169 mov bp, sp
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 516b mov dx, word ptr [bp + 4]
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 516e mov ax, word ptr [bp + 6]
  SETH(R.ax, 0x3d);                                            // 5171 mov ah, 0x3d
  ASM_INT(0x21);                                               // 5173 int 0x21
  if (R.cf) goto L_517c;                                       // 5175 jb 0x517c
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 5177 mov bx, word ptr [bp + 8]
  W16(DS, (u16)(R.bx), R.ax);                                  // 517a mov word ptr [bx], ax
L_517c:   goto L_3ad8;                                                 // 517c jmp 0x3ad8
L_ret:
  return;
}

static u16 f_1000_5168(u16 p0, u16 p1, u16 p2)
{
  ASM_ENTER();
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_5168();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:5180 FUN_1000_5180  FIX: recompiled from the machine code (asm2c)
static void a_1000_5180(void)
{
  FN(0x10005180);
  R.cs = 0x27cc;
  goto L_5180;
L_3ad2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 3ad2 xor ax, ax
  R.sp = (u16)(R.bp);                                          // 3ad4 mov sp, bp
  R.bp = POP();                                                // 3ad6 pop bp
  R.sp += 2; goto L_ret;                                       // 3ad7 ret
L_3ad8:   if (!R.cf) goto L_3ad2;                                      // 3ad8 jae 0x3ad2
  PUSH(R.ax);                                                  // 3ada push ax
  PUSH(0x3ade); a_1000_3af6();                                 // 3adb call 0x3af6
  R.ax = POP();                                                // 3ade pop ax
  R.sp = (u16)(R.bp);                                          // 3adf mov sp, bp
  R.bp = POP();                                                // 3ae1 pop bp
  R.sp += 2; goto L_ret;                                       // 3ae2 ret
L_5180:   PUSH(R.bp);                                                  // 5180 push bp
  R.bp = (u16)(R.sp);                                          // 5181 mov bp, sp
  SETH(R.ax, 0x3f);                                            // 5183 mov ah, 0x3f
  goto L_518c;                                                 // 5185 jmp 0x518c
L_518c:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 518c mov bx, word ptr [bp + 4]
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 518f mov cx, word ptr [bp + 0xa]
  PUSH(R.ds);                                                  // 5192 push ds
  { u16 a_ = (u16)(R.bp + 0x6); R.dx = (u16)(M16(SS, a_)); R.ds = M16(SS, (u16)(a_ + 2)); } // 5193 lds dx, ptr [bp + 6]
  ASM_INT(0x21);                                               // 5196 int 0x21
  R.ds = POP();                                                // 5198 pop ds
  if (R.cf) goto L_51a0;                                       // 5199 jb 0x51a0
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 519b mov bx, word ptr [bp + 0xc]
  W16(DS, (u16)(R.bx), R.ax);                                  // 519e mov word ptr [bx], ax
L_51a0:   goto L_3ad8;                                                 // 51a0 jmp 0x3ad8
L_ret:
  return;
}

static u16 f_1000_5180(u16 p0, u16 p1, u16 p2, u16 p3, u16 p4)
{
  ASM_ENTER();
  PUSH((u16)p4);
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_5180();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1000:5240 FUN_1000_5240  FIX: recompiled from the machine code (asm2c)
static void a_1000_5240(void)
{
  FN(0x10005240);
  R.cs = 0x27cc;
  PUSH(R.bp);                                                  // 5240 push bp
  R.bp = (u16)(R.sp);                                          // 5241 mov bp, sp
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 5243 mov ax, word ptr [bp + 6]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 5246 mov bx, word ptr [bp + 0xa]
  R.bx = (u16)(OR16(R.bx, R.ax));                              // 5249 or bx, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 524b mov bx, word ptr [bp + 8]
  if (!R.zf) goto L_525b;                                      // 524e jne 0x525b
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 5250 mov ax, word ptr [bp + 4]
  MUL16(R.bx);                                                 // 5253 mul bx
  R.sp = (u16)(R.bp);                                          // 5255 mov sp, bp
  R.bp = POP();                                                // 5257 pop bp
  R.sp += 10; goto L_ret;                                      // 5258 ret 8
L_525b:   MUL16(R.bx);                                                 // 525b mul bx
  R.cx = (u16)(R.ax);                                          // 525d mov cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 525f mov ax, word ptr [bp + 4]
  MUL16(M16(SS, (u16)(R.bp + 0xa)));                           // 5262 mul word ptr [bp + 0xa]
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 5265 add cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 5267 mov ax, word ptr [bp + 4]
  MUL16(R.bx);                                                 // 526a mul bx
  R.dx = (u16)(ADD16(R.dx, R.cx));                             // 526c add dx, cx
  R.sp = (u16)(R.bp);                                          // 526e mov sp, bp
  R.bp = POP();                                                // 5270 pop bp
  R.sp += 10; goto L_ret;                                      // 5271 ret 8
L_ret:
  return;
}

static u16 f_1000_5240(u16 p0, u16 p1, u16 p2, u16 p3)
{
  ASM_ENTER();
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0);  // the return address (near)
  a_1000_5240();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:0121 FUN_1533_0121  FIX: recompiled from the machine code (asm2c)
static void a_1533_0121(void)
{
  FN(0x15330121);
  R.cs = 0x2cff;
  R.bx = (u16)(R.sp);                                          // 0121 mov bx, sp
  R.dx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0123 mov dx, word ptr [bx + 4]
  PUSH(R.si);                                                  // 0126 push si
  PUSH(R.di);                                                  // 0127 push di
  PUSH(R.es);                                                  // 0128 push es
  R.es = (u16)(R.dx);                                          // 0129 mov es, dx
  R.bx = (u16)(0x1f6c);                                        // 012b mov bx, 0x1f6c
  R.ax = (u16)(M16(ES, (u16)(0x2e)));                          // 012e mov ax, word ptr es:[0x2e]
  SETL(R.dx, 0x5);                                             // 0132 mov dl, 5
  MUL8((u8)R.dx);                                              // 0134 mul dl
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 0136 add bx, ax
  R.cx = (u16)(M16(ES, (u16)(0x30)));                          // 0138 mov cx, word ptr es:[0x30]
  R.si = (u16)(0x32);                                          // 013d mov si, 0x32
  R.di = (u16)(M16(ES, (u16)(0x28)));                          // 0140 mov di, word ptr es:[0x28]
L_0145:   R.ax = (u16)(M16(ES, (u16)(R.si)));                          // 0145 mov ax, word ptr es:[si]
  W16(DS, (u16)(R.bx + 0x1), R.ax);                            // 0148 mov word ptr [bx + 1], ax
  W16(DS, (u16)(R.bx + 0x3), R.di);                            // 014b mov word ptr [bx + 3], di
  R.si = (u16)(ADD16(R.si, 0x2));                              // 014e add si, 2
  R.bx = (u16)(ADD16(R.bx, 0x5));                              // 0151 add bx, 5
  if (--R.cx != 0) goto L_0145;                                // 0154 loop 0x145
  R.es = POP();                                                // 0156 pop es
  R.di = POP();                                                // 0157 pop di
  R.si = POP();                                                // 0158 pop si
  R.sp += 4; goto L_ret;                                       // 0159 retf
L_ret:
  return;
}

static u16 f_1533_0121(void)
{
  ASM_ENTER();
  PUSH(0x2cff); PUSH(0);  // the return address (far)
  a_1533_0121();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:0170 FUN_1533_0170  FIX: recompiled from the machine code (asm2c)
static void a_1533_0170(void)
{
  FN(0x15330170);
  R.cs = 0x2cff;
  W16(DS, (u16)(0x22b2), 0x1);                                 // 0170 mov word ptr [0x22b2], 1
  W16(DS, (u16)(0x22bc), 0x1);                                 // 0176 mov word ptr [0x22bc], 1
  W16(DS, (u16)(0x22a8), 0x0);                                 // 017c mov word ptr [0x22a8], 0
  W16(DS, (u16)(0x22aa), 0x0);                                 // 0182 mov word ptr [0x22aa], 0
  PUSH(0x018b); a_1533_02c7();                                 // 0188 call 0x2c7
  SETH(R.ax, 0x35);                                            // 018b mov ah, 0x35
  SETL(R.ax, 0x8);                                             // 018d mov al, 8
  ASM_INT(0x21);                                               // 018f int 0x21
  W16(CS, (u16)(0x25c), R.bx);                                 // 0191 mov word ptr cs:[0x25c], bx
  W16(CS, (u16)(0x25e), R.es);                                 // 0196 mov word ptr cs:[0x25e], es
  PUSH(R.ds);                                                  // 019b push ds
  SETH(R.ax, 0x25);                                            // 019c mov ah, 0x25
  SETL(R.ax, 0x8);                                             // 019e mov al, 8
  { u16 a_ = (u16)(0x1f9); R.dx = (u16)(M16(CS, a_)); R.ds = M16(CS, (u16)(a_ + 2)); } // 01a0 lds dx, ptr cs:[0x1f9]
  ASM_INT(0x21);                                               // 01a5 int 0x21
  R.ds = POP();                                                // 01a7 pop ds
  W8(DS, (u16)(0x22a7), 0x1);                                  // 01a8 mov byte ptr [0x22a7], 1
  R.sp += 4; goto L_ret;                                       // 01ad retf
L_ret:
  return;
}

static u16 f_1533_0170(void)
{
  ASM_ENTER();
  PUSH(0x2cff); PUSH(0);  // the return address (far)
  a_1533_0170();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:01AE FUN_1533_01ae  FIX: recompiled from the machine code (asm2c)
static void a_1533_01ae(void)
{
  FN(0x153301AE);
  R.cs = 0x2cff;
  SETL(R.ax, 0x36);                                            // 01ae mov al, 0x36
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 01b0 out 0x43, al
  goto L_01b4;                                                 // 01b2 jmp 0x1b4
L_01b4:   SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 01b4 xor al, al
  ASM_PORT_OUT(0x40, (u8)R.ax);                                // 01b6 out 0x40, al
  goto L_01ba;                                                 // 01b8 jmp 0x1ba
L_01ba:   ASM_PORT_OUT(0x40, (u8)R.ax);                                // 01ba out 0x40, al
  PUSH(R.ds);                                                  // 01bc push ds
  SETH(R.ax, 0x25);                                            // 01bd mov ah, 0x25
  SETL(R.ax, 0x8);                                             // 01bf mov al, 8
  { u16 a_ = (u16)(0x25c); R.dx = (u16)(M16(CS, a_)); R.ds = M16(CS, (u16)(a_ + 2)); } // 01c1 lds dx, ptr cs:[0x25c]
  ASM_INT(0x21);                                               // 01c6 int 0x21
  R.ds = POP();                                                // 01c8 pop ds
  W8(DS, (u16)(0x22a7), 0x0);                                  // 01c9 mov byte ptr [0x22a7], 0
  R.sp += 4; goto L_ret;                                       // 01ce retf
L_ret:
  return;
}

static u16 f_1533_01ae(void)
{
  ASM_ENTER();
  PUSH(0x2cff); PUSH(0);  // the return address (far)
  a_1533_01ae();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:02C7 FUN_1533_02c7  FIX: recompiled from the machine code (asm2c)
static void a_1533_02c7(void)
{
  FN(0x153302C7);
  R.cs = 0x2cff;
  PUSH(FLAGS16());                                             // 02c7 pushf
  // 02c8 cli 
  W8(DS, (u16)(0x22b4), 0x1);                                  // 02c9 mov byte ptr [0x22b4], 1
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 02ce xor ax, ax
  W8(DS, (u16)(0x22bb), 0x1);                                  // 02d0 mov byte ptr [0x22bb], 1
  W16(DS, (u16)(0x22b7), R.ax);                                // 02d5 mov word ptr [0x22b7], ax
  W16(DS, (u16)(0x22b9), R.ax);                                // 02d8 mov word ptr [0x22b9], ax
  PUSH(0x02de); a_1533_035c();                                 // 02db call 0x35c
  R.bx = (u16)(R.ax);                                          // 02de mov bx, ax
  R.cx = (u16)(0x10);                                          // 02e0 mov cx, 0x10
L_02e3:   PUSH(R.bx);                                                  // 02e3 push bx
  PUSH(0x02e7); a_1533_035c();                                 // 02e4 call 0x35c
  R.bx = POP();                                                // 02e7 pop bx
  R.bx = (u16)(SUB16(R.bx, R.ax));                             // 02e8 sub bx, ax
  W16(DS, (u16)(0x22b7), ADD16(M16(DS, (u16)(0x22b7)), R.bx)); // 02ea add word ptr [0x22b7], bx
  W16(DS, (u16)(0x22b9), ADC16(M16(DS, (u16)(0x22b9)), 0x0));  // 02ee adc word ptr [0x22b9], 0
  R.bx = (u16)(R.ax);                                          // 02f3 mov bx, ax
  if (--R.cx != 0) goto L_02e3;                                // 02f5 loop 0x2e3
  R.ax = (u16)(M16(DS, (u16)(0x22b7)));                        // 02f7 mov ax, word ptr [0x22b7]
  R.dx = (u16)(M16(DS, (u16)(0x22b9)));                        // 02fa mov dx, word ptr [0x22b9]
  W16(DS, (u16)(0x22a8), ADD16(M16(DS, (u16)(0x22a8)), R.ax)); // 02fe add word ptr [0x22a8], ax
  W16(DS, (u16)(0x22aa), ADC16(M16(DS, (u16)(0x22aa)), R.dx)); // 0302 adc word ptr [0x22aa], dx
  R.cx = (u16)(0x10);                                          // 0306 mov cx, 0x10
  DIV16(R.cx, 0x0309);                                         // 0309 div cx
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 030b shr ax, 1
  W16(DS, (u16)(0x22b7), R.ax);                                // 030d mov word ptr [0x22b7], ax
  R.bx = (u16)(R.ax);                                          // 0310 mov bx, ax
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0312 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0314 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0316 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0318 shr bx, 1
  R.ax = (u16)(ADD16(R.ax, R.bx));                             // 031a add ax, bx
  R.dx = (u16)(XOR16(R.dx, R.dx));                             // 031c xor dx, dx
  R.bx = (u16)(0xf89);                                         // 031e mov bx, 0xf89
  DIV16(R.bx, 0x0321);                                         // 0321 div bx
  SUB16(R.ax, 0x4);                                            // 0323 cmp ax, 4
  if (R.cf) goto L_0330;                                       // 0326 jb 0x330
  SUB16(R.ax, 0x6);                                            // 0328 cmp ax, 6
  if (!R.cf && !R.zf) goto L_0330;                             // 032b ja 0x330
  goto L_033e;                                                 // 032d jmp 0x33e
L_0330:   W8(DS, (u16)(0x22bb), 0x0);                                  // 0330 mov byte ptr [0x22bb], 0
  W16(DS, (u16)(0x22b7), 0x4dae);                              // 0335 mov word ptr [0x22b7], 0x4dae
  R.ax = (u16)(0x5);                                           // 033b mov ax, 5
L_033e:   W16(DS, (u16)(0x22b5), R.ax);                                // 033e mov word ptr [0x22b5], ax
  SUB16(M16(DS, (u16)(0x22b2)), 0x1);                          // 0341 cmp word ptr [0x22b2], 1
  if (R.zf) goto L_034b;                                       // 0346 je 0x34b
  W16(DS, (u16)(0x22b2), R.ax);                                // 0348 mov word ptr [0x22b2], ax
L_034b:   R.ax = (u16)(M16(DS, (u16)(0x22b7)));                        // 034b mov ax, word ptr [0x22b7]
  R.dx = (u16)(XOR16(R.dx, R.dx));                             // 034e xor dx, dx
  DIV16(M16(DS, (u16)(0x22b2)), 0x0350);                       // 0350 div word ptr [0x22b2]
  W16(DS, (u16)(0x22ae), R.ax);                                // 0354 mov word ptr [0x22ae], ax
  W16(DS, (u16)(0x22ac), R.ax);                                // 0357 mov word ptr [0x22ac], ax
  SETFLAGS16(POP());                                           // 035a popf
  R.sp += 2; goto L_ret;                                       // 035b ret
L_ret:
  return;
}

static u16 f_1533_02c7(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1533_02c7();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:035C FUN_1533_035c  FIX: recompiled from the machine code (asm2c)
static void a_1533_035c(void)
{
  FN(0x1533035C);
  R.cs = 0x2cff;
  PUSH(FLAGS16());                                             // 035c pushf
  // 035d cli 
  R.dx = (u16)(0x3da);                                         // 035e mov dx, 0x3da
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 0361 xor bx, bx
L_0363:   R.bx = (u16)(DEC16(R.bx));                                   // 0363 dec bx
  if (R.zf) goto L_0387;                                       // 0364 je 0x387
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0366 in al, dx
  AND8((u8)R.ax, 0x8);                                         // 0367 test al, 8
  if (!R.zf) goto L_0363;                                      // 0369 jne 0x363
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 036b xor bx, bx
L_036d:   R.bx = (u16)(DEC16(R.bx));                                   // 036d dec bx
  if (R.zf) goto L_0387;                                       // 036e je 0x387
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0370 in al, dx
  AND8((u8)R.ax, 0x8);                                         // 0371 test al, 8
  if (R.zf) goto L_036d;                                       // 0373 je 0x36d
  SETL(R.ax, 0x0);                                             // 0375 mov al, 0
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 0377 out 0x43, al
  goto L_037b;                                                 // 0379 jmp 0x37b
L_037b:   SETL(R.ax, ASM_PORT_IN(0x40));                               // 037b in al, 0x40
  goto L_037f;                                                 // 037d jmp 0x37f
L_037f:   SETL(R.bx, (u8)R.ax);                                        // 037f mov bl, al
  SETL(R.ax, ASM_PORT_IN(0x40));                               // 0381 in al, 0x40
  goto L_0385;                                                 // 0383 jmp 0x385
L_0385:   SETH(R.bx, (u8)R.ax);                                        // 0385 mov bh, al
L_0387:   R.ax = (u16)(R.bx);                                          // 0387 mov ax, bx
  SETFLAGS16(POP());                                           // 0389 popf
  R.sp += 2; goto L_ret;                                       // 038a ret
L_ret:
  return;
}

static u16 f_1533_035c(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1533_035c();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:0394 FUN_1533_0394  FIX: recompiled from the machine code (asm2c)
static void a_1533_0394(void)
{
  FN(0x15330394);
  R.cs = 0x2cff;
  PUSH(R.bp);                                                  // 0394 push bp
  R.bp = (u16)(R.sp);                                          // 0395 mov bp, sp
  PUSH(R.si);                                                  // 0397 push si
  PUSH(R.di);                                                  // 0398 push di
  PUSH(R.es);                                                  // 0399 push es
  SETH(R.ax, 0x35);                                            // 039a mov ah, 0x35
  SETL(R.ax, 0x24);                                            // 039c mov al, 0x24
  ASM_INT(0x21);                                               // 039e int 0x21
  W16(DS, (u16)(0x22c8), R.es);                                // 03a0 mov word ptr [0x22c8], es
  W16(DS, (u16)(0x22ca), R.bx);                                // 03a4 mov word ptr [0x22ca], bx
  SETH(R.ax, 0x25);                                            // 03a8 mov ah, 0x25
  SETL(R.ax, 0x24);                                            // 03aa mov al, 0x24
  R.dx = (u16)(0x442);                                         // 03ac mov dx, 0x442
  PUSH(R.ds);                                                  // 03af push ds
  PUSH(R.cs);                                                  // 03b0 push cs
  R.ds = POP();                                                // 03b1 pop ds
  ASM_INT(0x21);                                               // 03b2 int 0x21
  R.ds = POP();                                                // 03b4 pop ds
  R.ax = (u16)(0x2df6 /* segment */);                          // 03b5 mov ax, 0x62a
  R.es = (u16)(R.ax);                                          // 03b8 mov es, ax
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 03ba mov si, word ptr [bp + 6]
  R.di = (u16)(0x22cd);                                        // 03bd mov di, 0x22cd
  R.ax = (u16)(0x2900);                                        // 03c0 mov ax, 0x2900
  ASM_INT(0x21);                                               // 03c3 int 0x21
  W16(CS, (u16)(0x392), 0x0);                                  // 03c5 mov word ptr cs:[0x392], 0
  SETH(R.ax, 0x11);                                            // 03cc mov ah, 0x11
  R.dx = (u16)(0x22cd);                                        // 03ce mov dx, 0x22cd
  ASM_INT(0x21);                                               // 03d1 int 0x21
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 03d3 or al, al
  if (R.zf) goto L_042a;                                       // 03d5 je 0x42a
  SETH(R.ax, 0xe);                                             // 03d7 mov ah, 0xe
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 03d9 mov dx, word ptr [bp + 8]
  ASM_INT(0x21);                                               // 03dc int 0x21
  W16(CS, (u16)(0x392), 0x0);                                  // 03de mov word ptr cs:[0x392], 0
  SETH(R.ax, 0x11);                                            // 03e5 mov ah, 0x11
  R.dx = (u16)(0x22cd);                                        // 03e7 mov dx, 0x22cd
  ASM_INT(0x21);                                               // 03ea int 0x21
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 03ec or al, al
  if (!R.zf) goto L_03f8;                                      // 03ee jne 0x3f8
  SUB16(M16(CS, (u16)(0x392)), 0x0);                           // 03f0 cmp word ptr cs:[0x392], 0
  if (R.zf) goto L_042a;                                       // 03f6 je 0x42a
L_03f8:   ASM_INT(0x11);                                               // 03f8 int 0x11
  SETL(R.ax, ROL8((u8)R.ax, 0x1));                             // 03fa rol al, 1
  SETL(R.ax, ROL8((u8)R.ax, 0x1));                             // 03fc rol al, 1
  SETL(R.ax, AND8((u8)R.ax, 0x3));                             // 03fe and al, 3
  if (!R.zf) goto L_0408;                                      // 0400 jne 0x408
L_0402:   R.ax = (u16)(0xffff);                                        // 0402 mov ax, 0xffff
  goto L_042a;                                                 // 0405 jmp 0x42a
L_0408:   W16(CS, (u16)(0x392), 0x0);                                  // 0408 mov word ptr cs:[0x392], 0
  SETH(R.ax, 0x19);                                            // 040f mov ah, 0x19
  ASM_INT(0x21);                                               // 0411 int 0x21
  SETL(R.ax, XOR8((u8)R.ax, 0x1));                             // 0413 xor al, 1
  SETL(R.dx, (u8)R.ax);                                        // 0415 mov dl, al
  SETH(R.ax, 0xe);                                             // 0417 mov ah, 0xe
  ASM_INT(0x21);                                               // 0419 int 0x21
  SETH(R.ax, 0x11);                                            // 041b mov ah, 0x11
  R.dx = (u16)(0x22cd);                                        // 041d mov dx, 0x22cd
  ASM_INT(0x21);                                               // 0420 int 0x21
  SUB16(M16(CS, (u16)(0x392)), 0x0);                           // 0422 cmp word ptr cs:[0x392], 0
  if (!R.zf) goto L_0402;                                      // 0428 jne 0x402
L_042a:   R.ax = (u16)(i16)(i8)R.ax;                                   // 042a cwde
  PUSH(R.ax);                                                  // 042b push ax
  SETH(R.ax, 0x25);                                            // 042c mov ah, 0x25
  SETL(R.ax, 0x24);                                            // 042e mov al, 0x24
  PUSH(R.ds);                                                  // 0430 push ds
  R.ds = (u16)(M16(DS, (u16)(0x22c8)));                        // 0431 mov ds, word ptr [0x22c8]
  R.dx = (u16)(M16(DS, (u16)(0x22ca)));                        // 0435 mov dx, word ptr [0x22ca]
  ASM_INT(0x21);                                               // 0439 int 0x21
  R.ds = POP();                                                // 043b pop ds
  R.ax = POP();                                                // 043c pop ax
  R.es = POP();                                                // 043d pop es
  R.di = POP();                                                // 043e pop di
  R.si = POP();                                                // 043f pop si
  R.bp = POP();                                                // 0440 pop bp
  R.sp += 4; goto L_ret;                                       // 0441 retf
L_ret:
  return;
}

static u16 f_1533_0394(u16 p0, u16 p1)
{
  ASM_ENTER();
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0x2cff); PUSH(0);  // the return address (far)
  a_1533_0394();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:045C FUN_1533_045c  FIX: recompiled from the machine code (asm2c)
static void a_1533_045c(void)
{
  FN(0x1533045C);
  R.cs = 0x2cff;
  PUSH(R.bp);                                                  // 045c push bp
  R.bp = (u16)(R.sp);                                          // 045d mov bp, sp
  PUSH(R.di);                                                  // 045f push di
  PUSH(R.si);                                                  // 0460 push si
  PUSH(0x0464); a_1533_04e4();                                 // 0461 call 0x4e4
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0464 mov bx, word ptr [bp + 6]
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 0467 mov ax, word ptr [bx]
  PUSH(0x2cff); PUSH(0x046e); du_driver(44);   /* driver slot 44 */ // 0469 lcall 0x62a, 0x2048
  SETH(R.ax, M8(SS, (u16)(R.bp + 0x10)));                      // 046e mov ah, byte ptr [bp + 0x10]
  PUSH(0x2cff); PUSH(0x0476); du_driver(37);   /* driver slot 37 */ // 0471 lcall 0x62a, 0x2025
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0476 mov si, word ptr [bp + 0xa]
  R.si = (u16)(ADD16(R.si, M16(DS, (u16)(R.bx + 0x4))));       // 0479 add si, word ptr [bx + 4]
  W16(DS, (u16)(0x26a3), R.si);                                // 047c mov word ptr [0x26a3], si
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 0480 mov cx, word ptr [bp + 0xe]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0483 shl si, 1
  R.di = (u16)((u16)(0x232f));                                 // 0485 lea di, [0x232f]
  R.di = (u16)(ADD16(R.di, R.si));                             // 0489 add di, si
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 048b mov ax, word ptr [bp + 8]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(R.bx + 0x2))));       // 048e add ax, word ptr [bx + 2]
  R.dx = (u16)(R.cx);                                          // 0491 mov dx, cx
  REPSTOSW();                                                  // 0493 rep stosw word ptr es:[di], ax
  R.cx = (u16)(R.dx);                                          // 0495 mov cx, dx
  R.di = (u16)((u16)(0x24e7));                                 // 0497 lea di, [0x24e7]
  R.di = (u16)(ADD16(R.di, R.si));                             // 049b add di, si
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 049d mov ax, word ptr [bp + 8]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(R.bx + 0x2))));       // 04a0 add ax, word ptr [bx + 2]
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0xc))));       // 04a3 add ax, word ptr [bp + 0xc]
  R.ax = (u16)(DEC16(R.ax));                                   // 04a6 dec ax
  REPSTOSW();                                                  // 04a7 rep stosw word ptr es:[di], ax
  R.ax = (u16)(M16(DS, (u16)(0x26a3)));                        // 04a9 mov ax, word ptr [0x26a3]
  R.cx = (u16)(R.ax);                                          // 04ac mov cx, ax
  R.cx = (u16)(ADD16(R.cx, M16(SS, (u16)(R.bp + 0xe))));       // 04ae add cx, word ptr [bp + 0xe]
  R.cx = (u16)(DEC16(R.cx));                                   // 04b1 dec cx
  W16(DS, (u16)(0x26a5), R.cx);                                // 04b2 mov word ptr [0x26a5], cx
  R.bx = (u16)(0x232f);                                        // 04b6 mov bx, 0x232f
  PUSH(0x2cff); PUSH(0x04be); du_driver(35);   /* driver slot 35 */ // 04b9 lcall 0x62a, 0x201b
  PUSH(0x2cff); PUSH(0x04c3); du_driver(36);   /* driver slot 36 */ // 04be lcall 0x62a, 0x2020
  R.si = POP();                                                // 04c3 pop si
  R.di = POP();                                                // 04c4 pop di
  R.bp = POP();                                                // 04c5 pop bp
  R.sp += 4; goto L_ret;                                       // 04c6 retf
L_ret:
  return;
}

static u16 f_1533_045c(u16 p0, u16 p1, u16 p2, u16 p3, u16 p4, u16 p5)
{
  ASM_ENTER();
  PUSH((u16)p5);
  PUSH((u16)p4);
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0x2cff); PUSH(0);  // the return address (far)
  a_1533_045c();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:04E4 FUN_1533_04e4  FIX: recompiled from the machine code (asm2c)
static void a_1533_04e4(void)
{
  FN(0x153304E4);
  R.cs = 0x2cff;
  R.ax = (u16)(0x2df6 /* segment */);                          // 04e4 mov ax, 0x62a
  R.es = (u16)(R.ax);                                          // 04e7 mov es, ax
  R.di = (u16)(M16(DS, (u16)(0x26a3)));                        // 04e9 mov di, word ptr [0x26a3]
  R.di = (u16)(OR16(R.di, R.di));                              // 04ed or di, di
  if (R.sf) goto L_0519;                                       // 04ef js 0x519
  R.cx = (u16)(M16(DS, (u16)(0x26a5)));                        // 04f1 mov cx, word ptr [0x26a5]
  R.cx = (u16)(INC16(R.cx));                                   // 04f5 inc cx
  R.cx = (u16)(SUB16(R.cx, R.di));                             // 04f6 sub cx, di
  R.di = (u16)(SHL16(R.di, 0x1));                              // 04f8 shl di, 1
  R.bx = (u16)(R.cx);                                          // 04fa mov bx, cx
  R.dx = (u16)(R.di);                                          // 04fc mov dx, di
  R.di = (u16)(ADD16(R.di, 0x232f));                           // 04fe add di, 0x232f
  R.ax = (u16)(0xffff);                                        // 0502 mov ax, 0xffff
  REPSTOSW();                                                  // 0505 rep stosw word ptr es:[di], ax
  W16(DS, (u16)(0x26a3), R.ax);                                // 0507 mov word ptr [0x26a3], ax
  R.cx = (u16)(R.bx);                                          // 050a mov cx, bx
  R.di = (u16)(R.dx);                                          // 050c mov di, dx
  R.di = (u16)(ADD16(R.di, 0x24e7));                           // 050e add di, 0x24e7
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0512 sub ax, ax
  REPSTOSW();                                                  // 0514 rep stosw word ptr es:[di], ax
  W16(DS, (u16)(0x26a5), R.ax);                                // 0516 mov word ptr [0x26a5], ax
L_0519:   R.sp += 2; goto L_ret;                                       // 0519 ret
L_ret:
  return;
}

static u16 f_1533_04e4(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1533_04e4();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:0692 FUN_1533_0692  FIX: recompiled from the machine code (asm2c)
static void a_1533_0692(void)
{
  FN(0x15330692);
  R.cs = 0x2cff;
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0692 sub ax, ax
  R.es = (u16)(R.ax);                                          // 0694 mov es, ax
  PUSH(M16(ES, (u16)(0x0)));                                   // 0696 push word ptr es:[0]
  PUSH(M16(ES, (u16)(0x2)));                                   // 069b push word ptr es:[2]
  R.ax = (u16)((u16)(0x83f));                                  // 06a0 lea ax, [0x83f]
  W16(ES, (u16)(0x0), R.ax);                                   // 06a4 mov word ptr es:[0], ax
  W16(ES, (u16)(0x2), 0x2cff /* segment */);                   // 06a8 mov word ptr es:[2], 0x533
  PUSH(R.ds);                                                  // 06af push ds
  R.es = POP();                                                // 06b0 pop es
  goto L_071a;                                                 // 06b1 jmp 0x71a
L_06b4:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 06b4 sub ax, ax
  R.es = (u16)(R.ax);                                          // 06b6 mov es, ax
  W16(ES, (u16)(0x2), POP());                                  // 06b8 pop word ptr es:[2]
  W16(ES, (u16)(0x0), POP());                                  // 06bd pop word ptr es:[0]
  PUSH(R.ds);                                                  // 06c2 push ds
  R.es = POP();                                                // 06c3 pop es
  R.ax = (u16)(M16(DS, (u16)(0x2327)));                        // 06c4 mov ax, word ptr [0x2327]
  R.bx = (u16)(M16(DS, (u16)(0x232b)));                        // 06c7 mov bx, word ptr [0x232b]
  R.cx = (u16)(M16(DS, (u16)(0x2329)));                        // 06cb mov cx, word ptr [0x2329]
  R.dx = (u16)(M16(DS, (u16)(0x232d)));                        // 06cf mov dx, word ptr [0x232d]
  PUSH(0x2cff); PUSH(0x06d8); du_driver(38);   /* driver slot 38 */ // 06d3 lcall 0x62a, 0x202a
  R.cf = 0;                                                    // 06d8 clc
  R.sp += 2; goto L_ret;                                       // 06d9 ret
L_06da:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 06da sub ax, ax
  R.es = (u16)(R.ax);                                          // 06dc mov es, ax
  W16(ES, (u16)(0x2), POP());                                  // 06de pop word ptr es:[2]
  W16(ES, (u16)(0x0), POP());                                  // 06e3 pop word ptr es:[0]
  PUSH(R.ds);                                                  // 06e8 push ds
  R.es = POP();                                                // 06e9 pop es
  R.cf = 1;                                                    // 06ea stc
  R.sp += 2; goto L_ret;                                       // 06eb ret
L_06ec:   R.cf = !R.cf;                                                // 06ec cmc
  R.dx = (u16)(RCR16(R.dx, 0x1));                              // 06ed rcr dx, 1
  W16(DS, (u16)(0x26ad), R.dx);                                // 06ef mov word ptr [0x26ad], dx
  R.dx = (u16)(SAR16(R.dx, 0x1));                              // 06f3 sar dx, 1
  W16(DS, (u16)(0x26b1), R.dx);                                // 06f5 mov word ptr [0x26b1], dx
  R.dx = (u16)(R.di);                                          // 06f9 mov dx, di
  R.dx = (u16)(SUB16(R.dx, R.bp));                             // 06fb sub dx, bp
  if (!R.of) goto L_0705;                                      // 06fd jno 0x705
  R.cf = !R.cf;                                                // 06ff cmc
  R.dx = (u16)(RCR16(R.dx, 0x1));                              // 0700 rcr dx, 1
  goto L_0775;                                                 // 0702 jmp 0x775
L_0705:   R.dx = (u16)(SAR16(R.dx, 0x1));                              // 0705 sar dx, 1
  goto L_0775;                                                 // 0707 jmp 0x775
L_070a:   R.cf = !R.cf;                                                // 070a cmc
  R.dx = (u16)(RCR16(R.dx, 0x1));                              // 070b rcr dx, 1
  W16(DS, (u16)(0x26ad), SAR16(M16(DS, (u16)(0x26ad)), 0x1));  // 070d sar word ptr [0x26ad], 1
  W16(DS, (u16)(0x26b1), SAR16(M16(DS, (u16)(0x26b1)), 0x1));  // 0711 sar word ptr [0x26b1], 1
  goto L_0775;                                                 // 0715 jmp 0x775
L_0718:   goto L_06da;                                                 // 0718 jmp 0x6da
L_071a:   R.cx = (u16)(M16(DS, (u16)(0x2327)));                        // 071a mov cx, word ptr [0x2327]
  R.dx = (u16)(M16(DS, (u16)(0x232b)));                        // 071e mov dx, word ptr [0x232b]
  R.si = (u16)(M16(DS, (u16)(0x2329)));                        // 0722 mov si, word ptr [0x2329]
  R.di = (u16)(M16(DS, (u16)(0x232d)));                        // 0726 mov di, word ptr [0x232d]
  R.bx = (u16)(R.cx);                                          // 072a mov bx, cx
  R.bp = (u16)(R.dx);                                          // 072c mov bp, dx
  PUSH(0x0731); a_1533_081e();                                 // 072e call 0x81e
  W8(DS, (u16)(0x26ac), (u8)R.ax);                             // 0731 mov byte ptr [0x26ac], al
  R.bx = (u16)(R.si);                                          // 0734 mov bx, si
  R.bp = (u16)(R.di);                                          // 0736 mov bp, di
  PUSH(0x073b); a_1533_081e();                                 // 0738 call 0x81e
  if (!R.zf) goto L_0757;                                      // 073b jne 0x757
  SUB8(M8(DS, (u16)(0x26ac)), 0x0);                            // 073d cmp byte ptr [0x26ac], 0
  if (!R.zf) goto L_0747;                                      // 0742 jne 0x747
  goto L_06b4;                                                 // 0744 jmp 0x6b4
L_0747:   { u16 t_ = R.si; R.si = (u16)(R.cx); R.cx = (u16)(t_); }     // 0747 xchg si, cx
  { u16 t_ = R.di; R.di = (u16)(R.dx); R.dx = (u16)(t_); }     // 0749 xchg di, dx
  { u16 t_ = M8(DS, (u16)(0x26ac)); W8(DS, (u16)(0x26ac), (u8)R.ax); SETL(R.ax, t_); } // 074b xchg byte ptr [0x26ac], al
  W16(DS, (u16)(0x2327), R.cx);                                // 074f mov word ptr [0x2327], cx
  W16(DS, (u16)(0x232b), R.dx);                                // 0753 mov word ptr [0x232b], dx
L_0757:   AND8(M8(DS, (u16)(0x26ac)), (u8)R.ax);                       // 0757 test byte ptr [0x26ac], al
  if (!R.zf) goto L_0718;                                      // 075b jne 0x718
  R.bp = (u16)(R.dx);                                          // 075d mov bp, dx
  R.dx = (u16)(R.si);                                          // 075f mov dx, si
  R.dx = (u16)(SUB16(R.dx, R.cx));                             // 0761 sub dx, cx
  if (R.of) goto L_06ec;                                       // 0763 jo 0x6ec
  W16(DS, (u16)(0x26ad), R.dx);                                // 0765 mov word ptr [0x26ad], dx
  R.dx = (u16)(SAR16(R.dx, 0x1));                              // 0769 sar dx, 1
  W16(DS, (u16)(0x26b1), R.dx);                                // 076b mov word ptr [0x26b1], dx
  R.dx = (u16)(R.di);                                          // 076f mov dx, di
  R.dx = (u16)(SUB16(R.dx, R.bp));                             // 0771 sub dx, bp
  if (R.of) goto L_070a;                                       // 0773 jo 0x70a
L_0775:   W16(DS, (u16)(0x26af), R.dx);                                // 0775 mov word ptr [0x26af], dx
  R.dx = (u16)(SAR16(R.dx, 0x1));                              // 0779 sar dx, 1
  W16(DS, (u16)(0x26b3), R.dx);                                // 077b mov word ptr [0x26b3], dx
L_077f:   AND8((u8)R.ax, 0x9);                                         // 077f test al, 9
  if (R.zf) goto L_07bb;                                       // 0781 je 0x7bb
  R.bx = (u16)(SUB16(R.bx, R.bx));                             // 0783 sub bx, bx
  R.si = (u16)(OR16(R.si, R.si));                              // 0785 or si, si
  if (R.sf) goto L_078d;                                       // 0787 js 0x78d
  R.bx = (u16)(M16(DS, (u16)(0x26b5)));                        // 0789 mov bx, word ptr [0x26b5]
L_078d:   R.ax = (u16)(R.bx);                                          // 078d mov ax, bx
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 078f sub ax, cx
  IMUL16(M16(DS, (u16)(0x26af)));                              // 0791 imul word ptr [0x26af]
  PUSH(R.bx);                                                  // 0795 push bx
  R.bx = (u16)(R.dx);                                          // 0796 mov bx, dx
  IDIV16(M16(DS, (u16)(0x26ad)), 0x0798);                      // 0798 idiv word ptr [0x26ad]
  SETL(R.bx, (u8)(R.bx >> 8));                                 // 079c mov bl, bh
  SETL(R.bx, XOR8((u8)R.bx, M8(DS, (u16)(0x26ae))));           // 079e xor bl, byte ptr [0x26ae]
  if (!R.sf) goto L_07a7;                                      // 07a2 jns 0x7a7
  R.dx = (u16)(NEG16(R.dx));                                   // 07a4 neg dx
  R.ax = (u16)(DEC16(R.ax));                                   // 07a6 dec ax
L_07a7:   R.dx = (u16)(SUB16(R.dx, M16(DS, (u16)(0x26b1))));           // 07a7 sub dx, word ptr [0x26b1]
  SETH(R.dx, XOR8((u8)(R.dx >> 8), (u8)(R.bx >> 8)));          // 07ab xor dh, bh
  if (R.sf) goto L_07b0;                                       // 07ad js 0x7b0
  R.ax = (u16)(INC16(R.ax));                                   // 07af inc ax
L_07b0:   R.bx = POP();                                                // 07b0 pop bx
  R.ax = (u16)(ADD16(R.ax, R.bp));                             // 07b1 add ax, bp
  if (R.sf) goto L_07c3;                                       // 07b3 js 0x7c3
  SUB16(R.ax, M16(DS, (u16)(0x26b7)));                         // 07b5 cmp ax, word ptr [0x26b7]
  if (R.zf || R.sf != R.of) goto L_07f4;                       // 07b9 jle 0x7f4
L_07bb:   R.bx = (u16)(M16(DS, (u16)(0x26b7)));                        // 07bb mov bx, word ptr [0x26b7]
  SUB16(R.di, R.bx);                                           // 07bf cmp di, bx
  if (!R.zf && R.sf == R.of) goto L_07c5;                      // 07c1 jg 0x7c5
L_07c3:   R.bx = (u16)(SUB16(R.bx, R.bx));                             // 07c3 sub bx, bx
L_07c5:   R.ax = (u16)(R.bx);                                          // 07c5 mov ax, bx
  R.ax = (u16)(SUB16(R.ax, R.bp));                             // 07c7 sub ax, bp
  IMUL16(M16(DS, (u16)(0x26ad)));                              // 07c9 imul word ptr [0x26ad]
  PUSH(R.bx);                                                  // 07cd push bx
  R.bx = (u16)(R.dx);                                          // 07ce mov bx, dx
  IDIV16(M16(DS, (u16)(0x26af)), 0x07d0);                      // 07d0 idiv word ptr [0x26af]
  SETL(R.bx, (u8)(R.bx >> 8));                                 // 07d4 mov bl, bh
  SETL(R.bx, XOR8((u8)R.bx, M8(DS, (u16)(0x26b0))));           // 07d6 xor bl, byte ptr [0x26b0]
  if (!R.sf) goto L_07df;                                      // 07da jns 0x7df
  R.dx = (u16)(NEG16(R.dx));                                   // 07dc neg dx
  R.ax = (u16)(DEC16(R.ax));                                   // 07de dec ax
L_07df:   R.dx = (u16)(SUB16(R.dx, M16(DS, (u16)(0x26b3))));           // 07df sub dx, word ptr [0x26b3]
  SETH(R.dx, XOR8((u8)(R.dx >> 8), (u8)(R.bx >> 8)));          // 07e3 xor dh, bh
  if (R.sf) goto L_07e8;                                       // 07e5 js 0x7e8
  R.ax = (u16)(INC16(R.ax));                                   // 07e7 inc ax
L_07e8:   R.bx = POP();                                                // 07e8 pop bx
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 07e9 add ax, cx
  if (R.sf) goto L_0805;                                       // 07eb js 0x805
  SUB16(R.ax, M16(DS, (u16)(0x26b5)));                         // 07ed cmp ax, word ptr [0x26b5]
  if (!R.zf && R.sf == R.of) goto L_0805;                      // 07f1 jg 0x805
  { u16 t_ = R.bx; R.bx = (u16)(R.ax); R.ax = (u16)(t_); }     // 07f3 xchg bx, ax
L_07f4:   SUB8(M8(DS, (u16)(0x26ac)), 0x0);                            // 07f4 cmp byte ptr [0x26ac], 0
  if (!R.zf) goto L_0808;                                      // 07f9 jne 0x808
  W16(DS, (u16)(0x232d), R.ax);                                // 07fb mov word ptr [0x232d], ax
  W16(DS, (u16)(0x2329), R.bx);                                // 07fe mov word ptr [0x2329], bx
  goto L_06b4;                                                 // 0802 jmp 0x6b4
L_0805:   goto L_06da;                                                 // 0805 jmp 0x6da
L_0808:   W16(DS, (u16)(0x232b), R.ax);                                // 0808 mov word ptr [0x232b], ax
  W16(DS, (u16)(0x2327), R.bx);                                // 080b mov word ptr [0x2327], bx
  { u16 t_ = R.si; R.si = (u16)(R.cx); R.cx = (u16)(t_); }     // 080f xchg si, cx
  { u16 t_ = R.di; R.di = (u16)(R.bp); R.bp = (u16)(t_); }     // 0811 xchg di, bp
  SETL(R.ax, M8(DS, (u16)(0x26ac)));                           // 0813 mov al, byte ptr [0x26ac]
  W8(DS, (u16)(0x26ac), 0x0);                                  // 0816 mov byte ptr [0x26ac], 0
  goto L_077f;                                                 // 081b jmp 0x77f
L_ret:
  return;
}

static u16 f_1533_0692(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1533_0692();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:081E FUN_1533_081e  FIX: recompiled from the machine code (asm2c)
static void a_1533_081e(void)
{
  FN(0x1533081E);
  R.cs = 0x2cff;
  SETL(R.ax, 0xf);                                             // 081e mov al, 0xf
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0820 or bx, bx
  if (R.sf) goto L_0826;                                       // 0822 js 0x826
  SETL(R.ax, AND8((u8)R.ax, 0xf7));                            // 0824 and al, 0xf7
L_0826:   SUB16(R.bx, M16(DS, (u16)(0x26b5)));                         // 0826 cmp bx, word ptr [0x26b5]
  if (!R.zf && R.sf == R.of) goto L_082e;                      // 082a jg 0x82e
  SETL(R.ax, AND8((u8)R.ax, 0xfe));                            // 082c and al, 0xfe
L_082e:   R.bp = (u16)(OR16(R.bp, R.bp));                              // 082e or bp, bp
  if (R.sf) goto L_0834;                                       // 0830 js 0x834
  SETL(R.ax, AND8((u8)R.ax, 0xfb));                            // 0832 and al, 0xfb
L_0834:   SUB16(R.bp, M16(DS, (u16)(0x26b7)));                         // 0834 cmp bp, word ptr [0x26b7]
  if (!R.zf && R.sf == R.of) goto L_083c;                      // 0838 jg 0x83c
  SETL(R.ax, AND8((u8)R.ax, 0xfd));                            // 083a and al, 0xfd
L_083c:   SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 083c or al, al
  R.sp += 2; goto L_ret;                                       // 083e ret
L_ret:
  return;
}

static u16 f_1533_081e(void)
{
  ASM_ENTER();
  PUSH(0);  // the return address (near)
  a_1533_081e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 1533:0A36 FUN_1533_0a36  FIX: recompiled from the machine code (asm2c)
static void a_1533_0a36(void)
{
  FN(0x15330A36);
  R.cs = 0x2cff;
  PUSH(R.bp);                                                  // 0a36 push bp
  R.bp = (u16)(R.sp);                                          // 0a37 mov bp, sp
  PUSH(R.si);                                                  // 0a39 push si
  PUSH(R.di);                                                  // 0a3a push di
  SETH(R.ax, M8(SS, (u16)(R.bp + 0x10)));                      // 0a3b mov ah, byte ptr [bp + 0x10]
  PUSH(0x2cff); PUSH(0x0a43); du_driver(37);   /* driver slot 37 */ // 0a3e lcall 0x62a, 0x2025
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0a43 mov bx, word ptr [bp + 6]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0a46 mov ax, word ptr [bx + 6]
  W16(DS, (u16)(0x26b5), R.ax);                                // 0a49 mov word ptr [0x26b5], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x8)));                    // 0a4c mov ax, word ptr [bx + 8]
  W16(DS, (u16)(0x26b7), R.ax);                                // 0a4f mov word ptr [0x26b7], ax
  PUSH(0x2cff); PUSH(0x0a57); du_driver(45);   /* driver slot 45 */ // 0a52 lcall 0x62a, 0x204d
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0a57 mov ax, word ptr [bp + 8]
  W16(DS, (u16)(0x2327), R.ax);                                // 0a5a mov word ptr [0x2327], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0a5d mov ax, word ptr [bp + 0xa]
  W16(DS, (u16)(0x232b), R.ax);                                // 0a60 mov word ptr [0x232b], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0a63 mov ax, word ptr [bp + 0xc]
  W16(DS, (u16)(0x2329), R.ax);                                // 0a66 mov word ptr [0x2329], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 0a69 mov ax, word ptr [bp + 0xe]
  W16(DS, (u16)(0x232d), R.ax);                                // 0a6c mov word ptr [0x232d], ax
  PUSH(0x0a72); a_1533_0692();                                 // 0a6f call 0x692
  PUSH(0x2cff); PUSH(0x0a77); du_driver(36);   /* driver slot 36 */ // 0a72 lcall 0x62a, 0x2020
  R.di = POP();                                                // 0a77 pop di
  R.si = POP();                                                // 0a78 pop si
  R.bp = POP();                                                // 0a79 pop bp
  R.sp += 4; goto L_ret;                                       // 0a7a retf
L_ret:
  return;
}

static u16 f_1533_0a36(u16 p0, u16 p1, u16 p2, u16 p3, u16 p4, u16 p5)
{
  ASM_ENTER();
  PUSH((u16)p5);
  PUSH((u16)p4);
  PUSH((u16)p3);
  PUSH((u16)p2);
  PUSH((u16)p1);
  PUSH((u16)p0);
  PUSH(0x2cff); PUSH(0);  // the return address (far)
  a_1533_0a36();
  ASM_LEAVE(); return (u16)R.ax;
}

// 15e6:000E FUN_15e6_000e  FIX: recompiled from the machine code (asm2c)
static void a_15e6_000e(void)
{
  FN(0x15E6000E);
  R.cs = 0x2db2;
  PUSH(R.ds);                                                  // 000e push ds
  R.ax = (u16)(0x40);                                          // 000f mov ax, 0x40
  R.ds = (u16)(R.ax);                                          // 0012 mov ds, ax
  W8(DS, (u16)(0x17), AND8(M8(DS, (u16)(0x17)), 0xdf));        // 0014 and byte ptr [0x17], 0xdf
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0019 xor ax, ax
  W8(SS, (u16)(0x22f6), (u8)R.ax);                             // 001b mov byte ptr ss:[0x22f6], al
  W16(SS, (u16)(0x22f7), R.ax);                                // 001f mov word ptr ss:[0x22f7], ax
  W8(SS, (u16)(0x22f9), (u8)R.ax);                             // 0023 mov byte ptr ss:[0x22f9], al
  W8(SS, (u16)(0x22fa), (u8)R.ax);                             // 0027 mov byte ptr ss:[0x22fa], al
  W8(SS, (u16)(0x22fb), (u8)R.ax);                             // 002b mov byte ptr ss:[0x22fb], al
  W8(SS, (u16)(0x22f4), (u8)R.ax);                             // 002f mov byte ptr ss:[0x22f4], al
  W8(SS, (u16)(0x22f5), (u8)R.ax);                             // 0033 mov byte ptr ss:[0x22f5], al
  W8(SS, (u16)(0x22f2), 0x80);                                 // 0037 mov byte ptr ss:[0x22f2], 0x80
  W8(SS, (u16)(0x22f3), 0x80);                                 // 003d mov byte ptr ss:[0x22f3], 0x80
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0043 xor ax, ax
  R.ds = (u16)(R.ax);                                          // 0045 mov ds, ax
  R.bx = (u16)(0x24);                                          // 0047 mov bx, 0x24
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 004a mov ax, word ptr [bx]
  R.dx = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 004c mov dx, word ptr [bx + 2]
  W16(CS, (u16)(0x198), R.ax);                                 // 004f mov word ptr cs:[0x198], ax
  W16(CS, (u16)(0x19a), R.dx);                                 // 0053 mov word ptr cs:[0x19a], dx
  R.ax = (u16)(0x80);                                          // 0058 mov ax, 0x80
  R.dx = (u16)(R.cs);                                          // 005b mov dx, cs
  // 005d cli 
  W16(DS, (u16)(R.bx), R.ax);                                  // 005e mov word ptr [bx], ax
  W16(DS, (u16)(R.bx + 0x2), R.dx);                            // 0060 mov word ptr [bx + 2], dx
  // 0063 sti 
  R.ds = POP();                                                // 0064 pop ds
  R.sp += 4; goto L_ret;                                       // 0065 retf
L_ret:
  return;
}

static u16 f_15e6_000e(void)
{
  ASM_ENTER();
  PUSH(0x2db2); PUSH(0);  // the return address (far)
  a_15e6_000e();
  ASM_LEAVE(); return (u16)R.ax;
}

// 15e6:0066 FUN_15e6_0066  FIX: recompiled from the machine code (asm2c)
static void a_15e6_0066(void)
{
  FN(0x15E60066);
  R.cs = 0x2db2;
  PUSH(R.ds);                                                  // 0066 push ds
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0067 xor ax, ax
  R.ds = (u16)(R.ax);                                          // 0069 mov ds, ax
  R.bx = (u16)(0x24);                                          // 006b mov bx, 0x24
  R.ax = (u16)(M16(CS, (u16)(0x198)));                         // 006e mov ax, word ptr cs:[0x198]
  R.dx = (u16)(M16(CS, (u16)(0x19a)));                         // 0072 mov dx, word ptr cs:[0x19a]
  // 0077 cli 
  W16(DS, (u16)(R.bx), R.ax);                                  // 0078 mov word ptr [bx], ax
  W16(DS, (u16)(R.bx + 0x2), R.dx);                            // 007a mov word ptr [bx + 2], dx
  // 007d sti 
  R.ds = POP();                                                // 007e pop ds
  R.sp += 4; goto L_ret;                                       // 007f retf
L_ret:
  return;
}

static u16 f_15e6_0066(void)
{
  ASM_ENTER();
  PUSH(0x2db2); PUSH(0);  // the return address (far)
  a_15e6_0066();
  ASM_LEAVE(); return (u16)R.ax;
}

// far calls through a pointer: the functions the program stores as pointers (a segment in any of the
// three encodings: Ghidra's, the image's, the loaded program's)
void du_far_call(u16 seg, u16 off)
{
  if (off == 0x245a && (seg == 0x1000 || seg == 0x0000 || seg == 0x27cc)) { a_1000_245a(); return; }
  if (off == 0x249e && (seg == 0x1000 || seg == 0x0000 || seg == 0x27cc)) { a_1000_249e(); return; }
  asm_unknown_call(seg, off);
}

// the C library start-up (1000:35BE), the entry of the executable, as DOS starts it
void du_crt0_body(void) { a_1000_35be(); }

// main (1000:0010), entered with its return address on the stack
void du_main_body(void) { a_1000_0010(); }
