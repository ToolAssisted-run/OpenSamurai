#include "asm2c.h"

// AS: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void as_0000_run(u16 entry);

void as_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0xd000;
dispatch_:
  switch (ip_)
  {
  case 0x004d: goto L_004d;
  case 0x0054: goto L_0054;
  case 0x0059: goto L_0059;
  case 0x0065: goto L_0065;
  case 0x006c: goto L_006c;
  case 0x0072: goto L_0072;
  case 0x007d: goto L_007d;
  case 0x0082: goto L_0082;
  case 0x0095: goto L_0095;
  case 0x009a: goto L_009a;
  case 0x009d: goto L_009d;
  case 0x00a1: goto L_00a1;
  case 0x00a3: goto L_00a3;
  case 0x010a: goto L_010a;
  case 0x010e: goto L_010e;
  case 0x0119: goto L_0119;
  case 0x0139: goto L_0139;
  case 0x0143: goto L_0143;
  case 0x0154: goto L_0154;
  case 0x0169: goto L_0169;
  case 0x016f: goto L_016f;
  case 0x017a: goto L_017a;
  case 0x017b: goto L_017b;
  case 0x019a: goto L_019a;
  case 0x01d4: goto L_01d4;
  case 0x01f5: goto L_01f5;
  case 0x01f6: goto L_01f6;
  case 0x0209: goto L_0209;
  case 0x020a: goto L_020a;
  case 0x0233: goto L_0233;
  case 0x024c: goto L_024c;
  case 0x024d: goto L_024d;
  case 0x0260: goto L_0260;
  case 0x0272: goto L_0272;
  case 0x02ae: goto L_02ae;
  case 0x02e7: goto L_02e7;
  case 0x0301: goto L_0301;
  case 0x0310: goto L_0310;
  case 0x031d: goto L_031d;
  case 0x0328: goto L_0328;
  case 0x0333: goto L_0333;
  case 0x033e: goto L_033e;
  case 0x0349: goto L_0349;
  case 0x0354: goto L_0354;
  case 0x0361: goto L_0361;
  case 0x036c: goto L_036c;
  case 0x0379: goto L_0379;
  case 0x0384: goto L_0384;
  case 0x038f: goto L_038f;
  case 0x039c: goto L_039c;
  case 0x03a7: goto L_03a7;
  case 0x03b2: goto L_03b2;
  case 0x03bf: goto L_03bf;
  case 0x03ca: goto L_03ca;
  case 0x03d5: goto L_03d5;
  case 0x03e2: goto L_03e2;
  case 0x03ed: goto L_03ed;
  case 0x03f8: goto L_03f8;
  case 0x0405: goto L_0405;
  case 0x0410: goto L_0410;
  case 0x041b: goto L_041b;
  case 0x0428: goto L_0428;
  case 0x0433: goto L_0433;
  case 0x043e: goto L_043e;
  case 0x044b: goto L_044b;
  case 0x0456: goto L_0456;
  case 0x0461: goto L_0461;
  case 0x046e: goto L_046e;
  case 0x0479: goto L_0479;
  case 0x0486: goto L_0486;
  case 0x0491: goto L_0491;
  case 0x049c: goto L_049c;
  case 0x04a9: goto L_04a9;
  case 0x04b4: goto L_04b4;
  case 0x04bf: goto L_04bf;
  case 0x04cc: goto L_04cc;
  case 0x04d7: goto L_04d7;
  case 0x04dd: goto L_04dd;
  case 0x04ea: goto L_04ea;
  case 0x04f5: goto L_04f5;
  case 0x04fb: goto L_04fb;
  case 0x0508: goto L_0508;
  case 0x0513: goto L_0513;
  case 0x0517: goto L_0517;
  case 0x0523: goto L_0523;
  case 0x0533: goto L_0533;
  case 0x0540: goto L_0540;
  case 0x057d: goto L_057d;
  case 0x058d: goto L_058d;
  case 0x059a: goto L_059a;
  case 0x05a5: goto L_05a5;
  case 0x05b0: goto L_05b0;
  case 0x05b1: goto L_05b1;
  case 0x05c1: goto L_05c1;
  case 0x05ce: goto L_05ce;
  case 0x05d9: goto L_05d9;
  case 0x05e4: goto L_05e4;
  case 0x05e5: goto L_05e5;
  case 0x05f5: goto L_05f5;
  case 0x0602: goto L_0602;
  case 0x060d: goto L_060d;
  case 0x0618: goto L_0618;
  case 0x0619: goto L_0619;
  case 0x0629: goto L_0629;
  case 0x0636: goto L_0636;
  case 0x0641: goto L_0641;
  case 0x064c: goto L_064c;
  case 0x064d: goto L_064d;
  case 0x065d: goto L_065d;
  case 0x066a: goto L_066a;
  case 0x0675: goto L_0675;
  case 0x0680: goto L_0680;
  case 0x0681: goto L_0681;
  case 0x068e: goto L_068e;
  case 0x0699: goto L_0699;
  case 0x06a4: goto L_06a4;
  case 0x06a7: goto L_06a7;
  case 0x06af: goto L_06af;
  case 0x06b2: goto L_06b2;
  case 0x06c0: goto L_06c0;
  case 0x06d8: goto L_06d8;
  case 0x06e5: goto L_06e5;
  case 0x06f2: goto L_06f2;
  case 0x06ff: goto L_06ff;
  case 0x070c: goto L_070c;
  case 0x0719: goto L_0719;
  case 0x0734: goto L_0734;
  case 0x0741: goto L_0741;
  case 0x074e: goto L_074e;
  case 0x075b: goto L_075b;
  case 0x0768: goto L_0768;
  case 0x0775: goto L_0775;
  case 0x0782: goto L_0782;
  case 0x078f: goto L_078f;
  case 0x079e: goto L_079e;
  case 0x07aa: goto L_07aa;
  case 0x07b6: goto L_07b6;
  case 0x07c2: goto L_07c2;
  case 0x07cf: goto L_07cf;
  case 0x07da: goto L_07da;
  case 0x07e5: goto L_07e5;
  case 0x07e6: goto L_07e6;
  case 0x07ed: goto L_07ed;
  case 0x07f4: goto L_07f4;
  case 0x0859: goto L_0859;
  case 0x0864: goto L_0864;
  case 0x0868: goto L_0868;
  case 0x0881: goto L_0881;
  case 0x0882: goto L_0882;
  case 0x0886: goto L_0886;
  case 0x088f: goto L_088f;
  case 0x089a: goto L_089a;
  case 0x08a3: goto L_08a3;
  case 0x08a7: goto L_08a7;
  case 0x08bf: goto L_08bf;
  case 0x08c0: goto L_08c0;
  case 0x08c2: goto L_08c2;
  case 0x08cf: goto L_08cf;
  case 0x0901: goto L_0901;
  case 0x090a: goto L_090a;
  case 0x091a: goto L_091a;
  case 0x0925: goto L_0925;
  case 0x0926: goto L_0926;
  case 0x0931: goto L_0931;
  case 0x0935: goto L_0935;
  case 0x0936: goto L_0936;
  case 0x0954: goto L_0954;
  case 0x0962: goto L_0962;
  case 0x098e: goto L_098e;
  case 0x09a5: goto L_09a5;
  case 0x09c9: goto L_09c9;
  case 0x09d0: goto L_09d0;
  case 0x09e1: goto L_09e1;
  case 0x0a25: goto L_0a25;
  case 0x0a63: goto L_0a63;
  case 0x0a6a: goto L_0a6a;
  case 0x0a7b: goto L_0a7b;
  case 0x0ac1: goto L_0ac1;
  case 0x0ae9: goto L_0ae9;
  case 0x0b6c: goto L_0b6c;
  case 0x0b88: goto L_0b88;
  case 0x0baa: goto L_0baa;
  case 0x0bb0: goto L_0bb0;
  case 0x0be1: goto L_0be1;
  case 0x0be4: goto L_0be4;
  case 0x0be8: goto L_0be8;
  case 0x0c0b: goto L_0c0b;
  case 0x0c16: goto L_0c16;
  case 0x0c7f: goto L_0c7f;
  case 0x0c82: goto L_0c82;
  case 0x0ceb: goto L_0ceb;
  case 0x0cee: goto L_0cee;
  case 0x0cff: goto L_0cff;
  case 0x0d13: goto L_0d13;
  case 0x0d2b: goto L_0d2b;
  case 0x0d50: goto L_0d50;
  case 0x0d56: goto L_0d56;
  case 0x0d85: goto L_0d85;
  case 0x0d88: goto L_0d88;
  case 0x0d8e: goto L_0d8e;
  case 0x0dac: goto L_0dac;
  case 0x0dae: goto L_0dae;
  case 0x0dbe: goto L_0dbe;
  case 0x0dc0: goto L_0dc0;
  case 0x0dd1: goto L_0dd1;
  case 0x0dd8: goto L_0dd8;
  case 0x0de6: goto L_0de6;
  case 0x0de8: goto L_0de8;
  case 0x0df0: goto L_0df0;
  case 0x0df4: goto L_0df4;
  case 0x0e31: goto L_0e31;
  case 0x0e38: goto L_0e38;
  case 0x0e68: goto L_0e68;
  case 0x0e6b: goto L_0e6b;
  case 0x0e77: goto L_0e77;
  case 0x0e7e: goto L_0e7e;
  case 0x0eb8: goto L_0eb8;
  case 0x0ec0: goto L_0ec0;
  case 0x0efb: goto L_0efb;
  case 0x0f02: goto L_0f02;
  case 0x0f24: goto L_0f24;
  case 0x0f26: goto L_0f26;
  case 0x0f3a: goto L_0f3a;
  case 0x0f3c: goto L_0f3c;
  case 0x0f50: goto L_0f50;
  case 0x0f52: goto L_0f52;
  case 0x0f66: goto L_0f66;
  case 0x0f68: goto L_0f68;
  case 0x0f81: goto L_0f81;
  case 0x0f88: goto L_0f88;
  case 0x0fa9: goto L_0fa9;
  case 0x0fb0: goto L_0fb0;
  case 0x0fb3: goto L_0fb3;
  case 0x0fb6: goto L_0fb6;
  case 0x0fb9: goto L_0fb9;
  case 0x0fbc: goto L_0fbc;
  case 0x0fbf: goto L_0fbf;
  case 0x0fc2: goto L_0fc2;
  case 0x0fc5: goto L_0fc5;
  case 0x0fc8: goto L_0fc8;
  case 0x0fca: goto L_0fca;
  case 0x0fdd: goto L_0fdd;
  case 0x1018: goto L_1018;
  case 0x101b: goto L_101b;
  case 0x10a3: goto L_10a3;
  case 0x10df: goto L_10df;
  case 0x10e6: goto L_10e6;
  case 0x1100: goto L_1100;
  case 0x1123: goto L_1123;
  case 0x1126: goto L_1126;
  case 0x1135: goto L_1135;
  case 0x114b: goto L_114b;
  case 0x1156: goto L_1156;
  case 0x1160: goto L_1160;
  case 0x116c: goto L_116c;
  case 0x1194: goto L_1194;
  case 0x11ac: goto L_11ac;
  case 0x11ae: goto L_11ae;
  case 0x11d2: goto L_11d2;
  case 0x11de: goto L_11de;
  case 0x11e2: goto L_11e2;
  case 0x11ee: goto L_11ee;
  case 0x121e: goto L_121e;
  case 0x1236: goto L_1236;
  case 0x123a: goto L_123a;
  case 0x126a: goto L_126a;
  case 0x1276: goto L_1276;
  case 0x127a: goto L_127a;
  case 0x1292: goto L_1292;
  case 0x1298: goto L_1298;
  case 0x129c: goto L_129c;
  case 0x12c5: goto L_12c5;
  case 0x12cc: goto L_12cc;
  case 0x12e4: goto L_12e4;
  case 0x12fc: goto L_12fc;
  case 0x1325: goto L_1325;
  case 0x132c: goto L_132c;
  case 0x135a: goto L_135a;
  case 0x1367: goto L_1367;
  case 0x136f: goto L_136f;
  case 0x1377: goto L_1377;
  case 0x137f: goto L_137f;
  case 0x1387: goto L_1387;
  case 0x138f: goto L_138f;
  case 0x1397: goto L_1397;
  case 0x139a: goto L_139a;
  case 0x13da: goto L_13da;
  case 0x13e4: goto L_13e4;
  case 0x13ea: goto L_13ea;
  case 0x1425: goto L_1425;
  case 0x1428: goto L_1428;
  case 0x1443: goto L_1443;
  case 0x1446: goto L_1446;
  case 0x1454: goto L_1454;
  case 0x1497: goto L_1497;
  case 0x149a: goto L_149a;
  case 0x14a4: goto L_14a4;
  case 0x14ae: goto L_14ae;
  case 0x14ba: goto L_14ba;
  case 0x14c4: goto L_14c4;
  case 0x14ce: goto L_14ce;
  case 0x14d8: goto L_14d8;
  case 0x14e2: goto L_14e2;
  case 0x14ec: goto L_14ec;
  case 0x14ef: goto L_14ef;
  default: asm_unknown_call(0xd000, ip_); return;
  }
L_004d:   SETL(R.ax, 0x4);                                             // 004d mov al, 4
  SETL(R.bx, 0x60);                                            // 004f mov bl, 0x60
  PUSH(0x0054); goto L_0143;                                   // 0051 call 0x143
L_0054:   SETL(R.bx, 0x80);                                            // 0054 mov bl, 0x80
  PUSH(0x0059); goto L_0143;                                   // 0056 call 0x143
L_0059:   R.dx = (u16)(0x388);                                         // 0059 mov dx, 0x388
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 005c in al, dx
  PUSH(R.ax);                                                  // 005d push ax
  SETL(R.ax, 0x2);                                             // 005e mov al, 2
  SETL(R.bx, 0xff);                                            // 0060 mov bl, 0xff
  PUSH(0x0065); goto L_0143;                                   // 0062 call 0x143
L_0065:   SETL(R.ax, 0x4);                                             // 0065 mov al, 4
  SETL(R.bx, 0x21);                                            // 0067 mov bl, 0x21
  PUSH(0x006c); goto L_0143;                                   // 0069 call 0x143
L_006c:   R.cx = (u16)(0xc8);                                          // 006c mov cx, 0xc8
  R.dx = (u16)(0x388);                                         // 006f mov dx, 0x388
L_0072:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0072 in al, dx
  if (--R.cx != 0) goto L_0072;                                // 0073 loop 0x72
  PUSH(R.ax);                                                  // 0075 push ax
  SETL(R.ax, 0x4);                                             // 0076 mov al, 4
  SETL(R.bx, 0x60);                                            // 0078 mov bl, 0x60
  PUSH(0x007d); goto L_0143;                                   // 007a call 0x143
L_007d:   SETL(R.bx, 0x80);                                            // 007d mov bl, 0x80
  PUSH(0x0082); goto L_0143;                                   // 007f call 0x143
L_0082:   R.ax = POP();                                                // 0082 pop ax
  R.bx = POP();                                                // 0083 pop bx
  R.dx = (u16)(0x0);                                           // 0084 mov dx, 0
  SETL(R.ax, AND8((u8)R.ax, 0xe0));                            // 0087 and al, 0xe0
  SUB8((u8)R.ax, 0xc0);                                        // 0089 cmp al, 0xc0
  if (!R.zf) goto L_0095;                                      // 008b jne 0x95
  SETL(R.bx, AND8((u8)R.bx, 0xe0));                            // 008d and bl, 0xe0
  SUB8((u8)R.bx, 0x0);                                         // 0090 cmp bl, 0
  if (R.zf) goto L_009a;                                       // 0093 je 0x9a
L_0095:   R.ax = (u16)(0x41);                                          // 0095 mov ax, 0x41
  goto L_009d;                                                 // 0098 jmp 0x9d
L_009a:   R.ax = (u16)(0x0);                                           // 009a mov ax, 0
L_009d:   PUSH(R.ax);                                                  // 009d push ax
  PUSH(0x00a1); goto L_00a3;                                   // 009e call 0xa3
L_00a1:   R.ax = POP();                                                // 00a1 pop ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 00a2 ret
L_00a3:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 00a3 xor ax, ax
  W8(DS, (u16)(0x19aa), (u8)R.ax);                             // 00a5 mov byte ptr [0x19aa], al
  R.bx = (u16)((u16)(0x19ac));                                 // 00a8 lea bx, [0x19ac]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00ac mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00ae mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00b1 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x19c4));                                 // 00b4 lea bx, [0x19c4]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00b8 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00ba mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00bd mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x19dc));                                 // 00c0 lea bx, [0x19dc]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00c4 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00c6 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00c9 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x19f4));                                 // 00cc lea bx, [0x19f4]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00d0 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00d2 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00d5 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x1a0c));                                 // 00d8 lea bx, [0x1a0c]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00dc mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00de mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00e1 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x1a24));                                 // 00e4 lea bx, [0x1a24]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00e8 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00ea mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00ed mov byte ptr [bx + 2], al
  W8(DS, (u16)(0x1a3c), (u8)R.ax);                             // 00f0 mov byte ptr [0x1a3c], al
  W8(DS, (u16)(0x1a3d), (u8)R.ax);                             // 00f3 mov byte ptr [0x1a3d], al
  W16(DS, (u16)(0x19a6), R.ax);                                // 00f6 mov word ptr [0x19a6], ax
  W16(DS, (u16)(0x19a8), R.ax);                                // 00f9 mov word ptr [0x19a8], ax
  W8(DS, (u16)(0x19aa), 0xff);                                 // 00fc mov byte ptr [0x19aa], 0xff
  W16(DS, (u16)(0x18f9), R.ax);                                // 0101 mov word ptr [0x18f9], ax
  R.bx = (u16)(0x0);                                           // 0104 mov bx, 0
  R.ax = (u16)(0xff);                                          // 0107 mov ax, 0xff
L_010a:   PUSH(R.ax);                                                  // 010a push ax
  PUSH(0x010e); goto L_0143;                                   // 010b call 0x143
L_010e:   R.ax = POP();                                                // 010e pop ax
  R.ax = (u16)(DEC16(R.ax));                                   // 010f dec ax
  if (!R.zf) goto L_010a;                                      // 0110 jne 0x10a
  SETL(R.ax, 0x1);                                             // 0112 mov al, 1
  SETL(R.bx, 0x20);                                            // 0114 mov bl, 0x20
  PUSH(0x0119); goto L_0143;                                   // 0116 call 0x143
L_0119:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0119 ret
L_0139:   PUSH(R.bp);                                                  // 0139 push bp
  R.bp = (u16)(R.sp);                                          // 013a mov bp, sp
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 013c mov ax, word ptr [bp + 4]
  SETL(R.bx, M8(SS, (u16)(R.bp + 0x6)));                       // 013f mov bl, byte ptr [bp + 6]
  R.bp = POP();                                                // 0142 pop bp
L_0143:   PUSH(R.di);                                                  // 0143 push di
  SETH(R.ax, 0x0);                                             // 0144 mov ah, 0
  R.di = (u16)(R.ax);                                          // 0146 mov di, ax
  W8(DS, (u16)(R.di + 0x1a46), (u8)R.bx);                      // 0148 mov byte ptr [di + 0x1a46], bl
  R.dx = (u16)(0x388);                                         // 014c mov dx, 0x388
  PUSH(R.ax);                                                  // 014f push ax
  PUSH(R.cx);                                                  // 0150 push cx
  R.cx = (u16)(0x1e);                                          // 0151 mov cx, 0x1e
L_0154:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0154 in al, dx
  if (--R.cx != 0) goto L_0154;                                // 0155 loop 0x154
  R.cx = POP();                                                // 0157 pop cx
  R.ax = POP();                                                // 0158 pop ax
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0159 out dx, al
  SETL(R.ax, (u8)R.bx);                                        // 015a mov al, bl
  R.dx = (u16)(0x389);                                         // 015c mov dx, 0x389
  PUSH(R.ax);                                                  // 015f push ax
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0160 in al, dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0161 in al, dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0162 in al, dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0163 in al, dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0164 in al, dx
  R.ax = POP();                                                // 0165 pop ax
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0166 out dx, al
  R.di = POP();                                                // 0167 pop di
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0168 ret
L_0169:   PUSH(R.ax);                                                  // 0169 push ax
  SETL(R.ax, ADD8((u8)R.ax, 0xa0));                            // 016a add al, 0xa0
  PUSH(0x016f); goto L_0143;                                   // 016c call 0x143
L_016f:   R.ax = POP();                                                // 016f pop ax
  SETL(R.ax, ADD8((u8)R.ax, 0xb0));                            // 0170 add al, 0xb0
  SETL(R.bx, (u8)(R.bx >> 8));                                 // 0172 mov bl, bh
  SETL(R.bx, OR8((u8)R.bx, 0x20));                             // 0174 or bl, 0x20
  PUSH(0x017a); goto L_0143;                                   // 0177 call 0x143
L_017a:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 017a ret
L_017b:   PUSH(R.es);                                                  // 017b push es
  PUSH(R.si);                                                  // 017c push si
  PUSH(R.di);                                                  // 017d push di
  PUSH(R.bp);                                                  // 017e push bp
  W16(CS, (u16)(0x49), R.ss);                                  // 017f mov word ptr cs:[0x49], ss
  W16(CS, (u16)(0x4b), R.sp);                                  // 0184 mov word ptr cs:[0x4b], sp
  R.ax = (u16)(0xd14f /* segment */);                          // 0189 mov ax, 0x14f
  R.es = (u16)(R.ax);                                          // 018c mov es, ax
  R.ss = (u16)(R.ax);                                          // 018e mov ss, ax
  R.sp = (u16)(0x18e8);                                        // 0190 mov sp, 0x18e8
  W16(DS, (u16)(0x18ee), INC16(M16(DS, (u16)(0x18ee))));       // 0193 inc word ptr [0x18ee]
  PUSH(0x019a); goto L_14a4;                                   // 0197 call 0x14a4
L_019a:   R.bx = (u16)(M16(CS, (u16)(0x49)));                          // 019a mov bx, word ptr cs:[0x49]
  R.ss = (u16)(R.bx);                                          // 019f mov ss, bx
  R.sp = (u16)(M16(CS, (u16)(0x4b)));                          // 01a1 mov sp, word ptr cs:[0x4b]
  R.bp = POP();                                                // 01a6 pop bp
  R.di = POP();                                                // 01a7 pop di
  R.si = POP();                                                // 01a8 pop si
  R.es = POP();                                                // 01a9 pop es
  SETL(R.ax, M8(DS, (u16)(0x1a3d)));                           // 01aa mov al, byte ptr [0x1a3d]
  SETL(R.ax, OR8((u8)R.ax, M8(DS, (u16)(0x1a3c))));            // 01ad or al, byte ptr [0x1a3c]
  if (R.zf) goto L_01f6;                                       // 01b1 je 0x1f6
  SUB8(M8(DS, (u16)(0x1a3c)), 0x0);                            // 01b3 cmp byte ptr [0x1a3c], 0
  if (R.zf) goto L_01d4;                                       // 01b8 je 0x1d4
  R.ax = (u16)(M16(DS, (u16)(0x19a2)));                        // 01ba mov ax, word ptr [0x19a2]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x19a6))));           // 01bd add ax, word ptr [0x19a6]
  W16(DS, (u16)(0x19a2), R.ax);                                // 01c1 mov word ptr [0x19a2], ax
  W8(DS, (u16)(0x1a3c), DEC8(M8(DS, (u16)(0x1a3c))));          // 01c4 dec byte ptr [0x1a3c]
  if (!R.zf) goto L_01d4;                                      // 01c8 jne 0x1d4
  SETL(R.ax, M8(DS, (u16)(0x1a43)));                           // 01ca mov al, byte ptr [0x1a43]
  SETL(R.ax, ADD8((u8)R.ax, 0xb0));                            // 01cd add al, 0xb0
  SETL(R.bx, 0x0);                                             // 01cf mov bl, 0
  PUSH(0x01d4); goto L_0143;                                   // 01d1 call 0x143
L_01d4:   SUB8(M8(DS, (u16)(0x1a3d)), 0x0);                            // 01d4 cmp byte ptr [0x1a3d], 0
  if (R.zf) goto L_01f5;                                       // 01d9 je 0x1f5
  R.ax = (u16)(M16(DS, (u16)(0x19a4)));                        // 01db mov ax, word ptr [0x19a4]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x19a8))));           // 01de add ax, word ptr [0x19a8]
  W16(DS, (u16)(0x19a4), R.ax);                                // 01e2 mov word ptr [0x19a4], ax
  W8(DS, (u16)(0x1a3d), DEC8(M8(DS, (u16)(0x1a3d))));          // 01e5 dec byte ptr [0x1a3d]
  if (!R.zf) goto L_01f5;                                      // 01e9 jne 0x1f5
  SETL(R.ax, M8(DS, (u16)(0x1a44)));                           // 01eb mov al, byte ptr [0x1a44]
  SETL(R.ax, ADD8((u8)R.ax, 0xb0));                            // 01ee add al, 0xb0
  SETL(R.bx, 0x0);                                             // 01f0 mov bl, 0
  PUSH(0x01f5); goto L_0143;                                   // 01f2 call 0x143
L_01f5:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 01f5 ret
L_01f6:   SUB16(M16(DS, (u16)(0x18ec)), 0xffff);                       // 01f6 cmp word ptr [0x18ec], -1
  if (R.zf) goto L_0209;                                       // 01fb je 0x209
  W16(DS, (u16)(0x18ec), 0xffff);                              // 01fd mov word ptr [0x18ec], 0xffff
  W16(DS, (u16)(0x18ea), 0xffff);                              // 0203 mov word ptr [0x18ea], 0xffff
L_0209:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0209 ret
L_020a:   R.bx = (u16)(0x9248);                                        // 020a mov bx, 0x9248
  R.bx = (u16)(ADD16(R.bx, M16(DS, (u16)(0x1944))));           // 020d add bx, word ptr [0x1944]
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 0211 ror bx, 1
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 0213 ror bx, 1
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 0215 ror bx, 1
  W16(DS, (u16)(0x1944), R.bx);                                // 0217 mov word ptr [0x1944], bx
  SUB8(M8(DS, (u16)(0x1a3c)), 0x0);                            // 021b cmp byte ptr [0x1a3c], 0
  if (R.zf) goto L_0233;                                       // 0220 je 0x233
  R.bx = (u16)(XOR16(R.bx, 0xffff));                           // 0222 xor bx, 0xffff
  R.bx = (u16)(AND16(R.bx, M16(DS, (u16)(0x1a3e))));           // 0225 and bx, word ptr [0x1a3e]
  R.bx = (u16)(ADD16(R.bx, M16(DS, (u16)(0x19a2))));           // 0229 add bx, word ptr [0x19a2]
  SETL(R.ax, M8(DS, (u16)(0x1a43)));                           // 022d mov al, byte ptr [0x1a43]
  PUSH(0x0233); goto L_0169;                                   // 0230 call 0x169
L_0233:   SUB8(M8(DS, (u16)(0x1a3d)), 0x0);                            // 0233 cmp byte ptr [0x1a3d], 0
  if (R.zf) goto L_024c;                                       // 0238 je 0x24c
  R.bx = (u16)(M16(DS, (u16)(0x1944)));                        // 023a mov bx, word ptr [0x1944]
  R.bx = (u16)(AND16(R.bx, M16(DS, (u16)(0x1a40))));           // 023e and bx, word ptr [0x1a40]
  R.bx = (u16)(ADD16(R.bx, M16(DS, (u16)(0x19a4))));           // 0242 add bx, word ptr [0x19a4]
  SETL(R.ax, M8(DS, (u16)(0x1a44)));                           // 0246 mov al, byte ptr [0x1a44]
  PUSH(0x024c); goto L_0169;                                   // 0249 call 0x169
L_024c:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 024c ret
L_024d:   SUB16(M16(DS, (u16)(0x18ec)), 0x1);                          // 024d cmp word ptr [0x18ec], 1
  if (R.zf) goto L_0260;                                       // 0252 je 0x260
  W16(DS, (u16)(0x18ec), 0x1);                                 // 0254 mov word ptr [0x18ec], 1
  W16(DS, (u16)(0x18ea), 0x1);                                 // 025a mov word ptr [0x18ea], 1
L_0260:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0260 ret
L_0272:   SETL(R.dx, M8(DS, (u16)(0x19aa)));                           // 0272 mov dl, byte ptr [0x19aa]
  PUSH(R.dx);                                                  // 0276 push dx
  W8(DS, (u16)(0x19aa), 0x0);                                  // 0277 mov byte ptr [0x19aa], 0
  W8(DS, (u16)(R.bx + 0x1), 0x0);                              // 027c mov byte ptr [bx + 1], 0
  W8(DS, (u16)(R.bx + 0x9), 0xff);                             // 0280 mov byte ptr [bx + 9], 0xff
  W8(DS, (u16)(R.bx + 0x2), 0x0);                              // 0284 mov byte ptr [bx + 2], 0
  W16(DS, (u16)(R.bx + 0xa), R.cx);                            // 0288 mov word ptr [bx + 0xa], cx
  W16(DS, (u16)(R.bx + 0xc), R.cx);                            // 028b mov word ptr [bx + 0xc], cx
  W16(DS, (u16)(R.bx + 0xe), R.cx);                            // 028e mov word ptr [bx + 0xe], cx
  W16(DS, (u16)(R.bx + 0x10), R.cx);                           // 0291 mov word ptr [bx + 0x10], cx
  W16(DS, (u16)(R.bx + 0x12), 0x0);                            // 0294 mov word ptr [bx + 0x12], 0
  W16(DS, (u16)(R.bx + 0x14), 0x0);                            // 0299 mov word ptr [bx + 0x14], 0
  W8(DS, (u16)(R.bx + 0x6), 0x0);                              // 029e mov byte ptr [bx + 6], 0
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 02a2 mov word ptr [bx + 0x16], ax
  W8(DS, (u16)(R.bx), 0x1);                                    // 02a5 mov byte ptr [bx], 1
  R.dx = POP();                                                // 02a8 pop dx
  W8(DS, (u16)(0x19aa), (u8)R.dx);                             // 02a9 mov byte ptr [0x19aa], dl
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 02ad ret
L_02ae:   SETL(R.dx, M8(DS, (u16)(0x19aa)));                           // 02ae mov dl, byte ptr [0x19aa]
  PUSH(R.dx);                                                  // 02b2 push dx
  W8(DS, (u16)(0x19aa), 0x0);                                  // 02b3 mov byte ptr [0x19aa], 0
  W8(DS, (u16)(R.bx + 0x1), 0x0);                              // 02b8 mov byte ptr [bx + 1], 0
  W8(DS, (u16)(R.bx + 0x9), 0xff);                             // 02bc mov byte ptr [bx + 9], 0xff
  W8(DS, (u16)(R.bx + 0x2), 0x0);                              // 02c0 mov byte ptr [bx + 2], 0
  R.cx = (u16)(M16(DS, (u16)(R.bx + 0xa)));                    // 02c4 mov cx, word ptr [bx + 0xa]
  W16(DS, (u16)(R.bx + 0xc), R.cx);                            // 02c7 mov word ptr [bx + 0xc], cx
  W16(DS, (u16)(R.bx + 0xe), R.cx);                            // 02ca mov word ptr [bx + 0xe], cx
  W16(DS, (u16)(R.bx + 0x10), R.cx);                           // 02cd mov word ptr [bx + 0x10], cx
  W16(DS, (u16)(R.bx + 0x12), 0x0);                            // 02d0 mov word ptr [bx + 0x12], 0
  W16(DS, (u16)(R.bx + 0x14), 0x0);                            // 02d5 mov word ptr [bx + 0x14], 0
  W8(DS, (u16)(R.bx + 0x6), 0x0);                              // 02da mov byte ptr [bx + 6], 0
  W8(DS, (u16)(R.bx), 0x1);                                    // 02de mov byte ptr [bx], 1
  R.dx = POP();                                                // 02e1 pop dx
  W8(DS, (u16)(0x19aa), (u8)R.dx);                             // 02e2 mov byte ptr [0x19aa], dl
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 02e6 ret
L_02e7:   R.cx = (u16)((u16)(0x608));                                  // 02e7 lea cx, [0x608]
  R.bx = (u16)((u16)(0x19ac));                                 // 02eb lea bx, [0x19ac]
  W16(DS, (u16)(R.bx + 0xc), R.cx);                            // 02ef mov word ptr [bx + 0xc], cx
  R.bx = (u16)((u16)(0x19c4));                                 // 02f2 lea bx, [0x19c4]
  W16(DS, (u16)(R.bx + 0xc), R.cx);                            // 02f6 mov word ptr [bx + 0xc], cx
  R.bx = (u16)((u16)(0x19dc));                                 // 02f9 lea bx, [0x19dc]
  W16(DS, (u16)(R.bx + 0xc), R.cx);                            // 02fd mov word ptr [bx + 0xc], cx
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0300 ret
L_0301:   R.ax = (u16)((u16)(0x310));                                  // 0301 lea ax, [0x310]
  R.bx = (u16)((u16)(0x19ac));                                 // 0305 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x1598));                                 // 0309 lea cx, [0x1598]
  goto L_0272;                                                 // 030d jmp 0x272
L_0310:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0310 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0312 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x15a0));                                 // 0316 lea cx, [0x15a0]
  PUSH(0x031d); goto L_0272;                                   // 031a call 0x272
L_031d:   R.bx = (u16)((u16)(0x19c4));                                 // 031d lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x15dc));                                 // 0321 lea cx, [0x15dc]
  PUSH(0x0328); goto L_0272;                                   // 0325 call 0x272
L_0328:   R.bx = (u16)((u16)(0x19dc));                                 // 0328 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x160a));                                 // 032c lea cx, [0x160a]
  PUSH(0x0333); goto L_0272;                                   // 0330 call 0x272
L_0333:   R.bx = (u16)((u16)(0x19f4));                                 // 0333 lea bx, [0x19f4]
  R.cx = (u16)((u16)(0x1646));                                 // 0337 lea cx, [0x1646]
  PUSH(0x033e); goto L_0272;                                   // 033b call 0x272
L_033e:   R.bx = (u16)((u16)(0x1a0c));                                 // 033e lea bx, [0x1a0c]
  R.cx = (u16)((u16)(0x1658));                                 // 0342 lea cx, [0x1658]
  PUSH(0x0349); goto L_0272;                                   // 0346 call 0x272
L_0349:   R.bx = (u16)((u16)(0x1a24));                                 // 0349 lea bx, [0x1a24]
  R.cx = (u16)((u16)(0x166a));                                 // 034d lea cx, [0x166a]
  goto L_0272;                                                 // 0351 jmp 0x272
L_0354:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0354 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0356 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x1382));                                 // 035a lea cx, [0x1382]
  PUSH(0x0361); goto L_0272;                                   // 035e call 0x272
L_0361:   R.bx = (u16)((u16)(0x19c4));                                 // 0361 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x13b6));                                 // 0365 lea cx, [0x13b6]
  goto L_0272;                                                 // 0369 jmp 0x272
L_036c:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 036c xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 036e lea bx, [0x19ac]
  R.cx = (u16)((u16)(0xa68));                                  // 0372 lea cx, [0xa68]
  PUSH(0x0379); goto L_0272;                                   // 0376 call 0x272
L_0379:   R.bx = (u16)((u16)(0x19c4));                                 // 0379 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0xafe));                                  // 037d lea cx, [0xafe]
  PUSH(0x0384); goto L_0272;                                   // 0381 call 0x272
L_0384:   R.bx = (u16)((u16)(0x19dc));                                 // 0384 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0xb9a));                                  // 0388 lea cx, [0xb9a]
  goto L_0272;                                                 // 038c jmp 0x272
L_038f:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 038f xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0391 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x8b4));                                  // 0395 lea cx, [0x8b4]
  PUSH(0x039c); goto L_0272;                                   // 0399 call 0x272
L_039c:   R.bx = (u16)((u16)(0x19c4));                                 // 039c lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x92e));                                  // 03a0 lea cx, [0x92e]
  PUSH(0x03a7); goto L_0272;                                   // 03a4 call 0x272
L_03a7:   R.bx = (u16)((u16)(0x19dc));                                 // 03a7 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x964));                                  // 03ab lea cx, [0x964]
  goto L_0272;                                                 // 03af jmp 0x272
L_03b2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 03b2 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 03b4 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x7c0));                                  // 03b8 lea cx, [0x7c0]
  PUSH(0x03bf); goto L_0272;                                   // 03bc call 0x272
L_03bf:   R.bx = (u16)((u16)(0x19c4));                                 // 03bf lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x83c));                                  // 03c3 lea cx, [0x83c]
  PUSH(0x03ca); goto L_0272;                                   // 03c7 call 0x272
L_03ca:   R.bx = (u16)((u16)(0x19dc));                                 // 03ca lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x87c));                                  // 03ce lea cx, [0x87c]
  goto L_0272;                                                 // 03d2 jmp 0x272
L_03d5:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 03d5 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 03d7 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x13e0));                                 // 03db lea cx, [0x13e0]
  PUSH(0x03e2); goto L_0272;                                   // 03df call 0x272
L_03e2:   R.bx = (u16)((u16)(0x19c4));                                 // 03e2 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x1430));                                 // 03e6 lea cx, [0x1430]
  PUSH(0x03ed); goto L_0272;                                   // 03ea call 0x272
L_03ed:   R.bx = (u16)((u16)(0x19dc));                                 // 03ed lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x145c));                                 // 03f1 lea cx, [0x145c]
  goto L_0272;                                                 // 03f5 jmp 0x272
L_03f8:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 03f8 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 03fa lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x12f0));                                 // 03fe lea cx, [0x12f0]
  PUSH(0x0405); goto L_0272;                                   // 0402 call 0x272
L_0405:   R.bx = (u16)((u16)(0x19c4));                                 // 0405 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x132a));                                 // 0409 lea cx, [0x132a]
  PUSH(0x0410); goto L_0272;                                   // 040d call 0x272
L_0410:   R.bx = (u16)((u16)(0x19dc));                                 // 0410 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x134e));                                 // 0414 lea cx, [0x134e]
  goto L_0272;                                                 // 0418 jmp 0x272
L_041b:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 041b xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 041d lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x1488));                                 // 0421 lea cx, [0x1488]
  PUSH(0x0428); goto L_0272;                                   // 0425 call 0x272
L_0428:   R.bx = (u16)((u16)(0x19c4));                                 // 0428 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x14c0));                                 // 042c lea cx, [0x14c0]
  PUSH(0x0433); goto L_0272;                                   // 0430 call 0x272
L_0433:   R.bx = (u16)((u16)(0x19dc));                                 // 0433 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x14dc));                                 // 0437 lea cx, [0x14dc]
  goto L_0272;                                                 // 043b jmp 0x272
L_043e:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 043e xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0440 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0xc12));                                  // 0444 lea cx, [0xc12]
  PUSH(0x044b); goto L_0272;                                   // 0448 call 0x272
L_044b:   R.bx = (u16)((u16)(0x19c4));                                 // 044b lea bx, [0x19c4]
  R.cx = (u16)((u16)(0xc70));                                  // 044f lea cx, [0xc70]
  PUSH(0x0456); goto L_0272;                                   // 0453 call 0x272
L_0456:   R.bx = (u16)((u16)(0x19dc));                                 // 0456 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0xc9c));                                  // 045a lea cx, [0xc9c]
  goto L_0272;                                                 // 045e jmp 0x272
L_0461:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0461 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0463 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x6ba));                                  // 0467 lea cx, [0x6ba]
  PUSH(0x046e); goto L_0272;                                   // 046b call 0x272
L_046e:   R.bx = (u16)((u16)(0x19c4));                                 // 046e lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x796));                                  // 0472 lea cx, [0x796]
  goto L_0272;                                                 // 0476 jmp 0x272
L_0479:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0479 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 047b lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x59a));                                  // 047f lea cx, [0x59a]
  PUSH(0x0486); goto L_0272;                                   // 0483 call 0x272
L_0486:   R.bx = (u16)((u16)(0x19c4));                                 // 0486 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x60a));                                  // 048a lea cx, [0x60a]
  PUSH(0x0491); goto L_0272;                                   // 048e call 0x272
L_0491:   R.bx = (u16)((u16)(0x19dc));                                 // 0491 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x662));                                  // 0495 lea cx, [0x662]
  goto L_0272;                                                 // 0499 jmp 0x272
L_049c:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 049c xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 049e lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x9e2));                                  // 04a2 lea cx, [0x9e2]
  PUSH(0x04a9); goto L_0272;                                   // 04a6 call 0x272
L_04a9:   R.bx = (u16)((u16)(0x19c4));                                 // 04a9 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0xa24));                                  // 04ad lea cx, [0xa24]
  PUSH(0x04b4); goto L_0272;                                   // 04b1 call 0x272
L_04b4:   R.bx = (u16)((u16)(0x19dc));                                 // 04b4 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0xa4e));                                  // 04b8 lea cx, [0xa4e]
  goto L_0272;                                                 // 04bc jmp 0x272
L_04bf:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04bf xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 04c1 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0xcd4));                                  // 04c5 lea cx, [0xcd4]
  PUSH(0x04cc); goto L_0272;                                   // 04c9 call 0x272
L_04cc:   R.bx = (u16)((u16)(0x19c4));                                 // 04cc lea bx, [0x19c4]
  R.cx = (u16)((u16)(0xd0a));                                  // 04d0 lea cx, [0xd0a]
  PUSH(0x04d7); goto L_0272;                                   // 04d4 call 0x272
L_04d7:   R.ax = (u16)((u16)(0x18fb));                                 // 04d7 lea ax, [0x18fb]
  goto L_0517;                                                 // 04db jmp 0x517
L_04dd:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04dd xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 04df lea bx, [0x19ac]
  R.cx = (u16)((u16)(0xe4c));                                  // 04e3 lea cx, [0xe4c]
  PUSH(0x04ea); goto L_0272;                                   // 04e7 call 0x272
L_04ea:   R.bx = (u16)((u16)(0x19c4));                                 // 04ea lea bx, [0x19c4]
  R.cx = (u16)((u16)(0xe68));                                  // 04ee lea cx, [0xe68]
  PUSH(0x04f5); goto L_0272;                                   // 04f2 call 0x272
L_04f5:   R.ax = (u16)((u16)(0x1913));                                 // 04f5 lea ax, [0x1913]
  goto L_0517;                                                 // 04f9 jmp 0x517
L_04fb:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04fb xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 04fd lea bx, [0x19ac]
  R.cx = (u16)((u16)(0xfbe));                                  // 0501 lea cx, [0xfbe]
  PUSH(0x0508); goto L_0272;                                   // 0505 call 0x272
L_0508:   R.bx = (u16)((u16)(0x19c4));                                 // 0508 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0xfcc));                                  // 050c lea cx, [0xfcc]
  PUSH(0x0513); goto L_0272;                                   // 0510 call 0x272
L_0513:   R.ax = (u16)((u16)(0x192b));                                 // 0513 lea ax, [0x192b]
L_0517:   W16(DS, (u16)(0x18f7), R.ax);                                // 0517 mov word ptr [0x18f7], ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 051a xor ax, ax
  W16(DS, (u16)(0x18f3), R.ax);                                // 051c mov word ptr [0x18f3], ax
  W16(DS, (u16)(0x18f5), R.ax);                                // 051f mov word ptr [0x18f5], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0522 ret
L_0523:   SUB16(M16(DS, (u16)(0x18f9)), 0x6);                          // 0523 cmp word ptr [0x18f9], 6
  if (R.zf) goto L_0540;                                       // 0528 je 0x540
  W16(DS, (u16)(0x18f9), 0x6);                                 // 052a mov word ptr [0x18f9], 6
  PUSH(0x0533); goto L_02e7;                                   // 0530 call 0x2e7
L_0533:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0533 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0535 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x394));                                  // 0539 lea cx, [0x394]
  PUSH(0x0540); goto L_0272;                                   // 053d call 0x272
L_0540:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0540 ret
L_057d:   SUB16(M16(DS, (u16)(0x18f9)), 0x5);                          // 057d cmp word ptr [0x18f9], 5
  if (R.zf) goto L_05b0;                                       // 0582 je 0x5b0
  W16(DS, (u16)(0x18f9), 0x5);                                 // 0584 mov word ptr [0x18f9], 5
  PUSH(0x058d); goto L_02e7;                                   // 058a call 0x2e7
L_058d:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 058d xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 058f lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x12a2));                                 // 0593 lea cx, [0x12a2]
  PUSH(0x059a); goto L_0272;                                   // 0597 call 0x272
L_059a:   R.bx = (u16)((u16)(0x19c4));                                 // 059a lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x12c0));                                 // 059e lea cx, [0x12c0]
  PUSH(0x05a5); goto L_0272;                                   // 05a2 call 0x272
L_05a5:   R.bx = (u16)((u16)(0x19dc));                                 // 05a5 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x12d0));                                 // 05a9 lea cx, [0x12d0]
  PUSH(0x05b0); goto L_0272;                                   // 05ad call 0x272
L_05b0:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 05b0 ret
L_05b1:   SUB16(M16(DS, (u16)(0x18f9)), 0x1);                          // 05b1 cmp word ptr [0x18f9], 1
  if (R.zf) goto L_05e4;                                       // 05b6 je 0x5e4
  W16(DS, (u16)(0x18f9), 0x1);                                 // 05b8 mov word ptr [0x18f9], 1
  PUSH(0x05c1); goto L_02e7;                                   // 05be call 0x2e7
L_05c1:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 05c1 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 05c3 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x11ae));                                 // 05c7 lea cx, [0x11ae]
  PUSH(0x05ce); goto L_0272;                                   // 05cb call 0x272
L_05ce:   R.bx = (u16)((u16)(0x19c4));                                 // 05ce lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x11c8));                                 // 05d2 lea cx, [0x11c8]
  PUSH(0x05d9); goto L_0272;                                   // 05d6 call 0x272
L_05d9:   R.bx = (u16)((u16)(0x19dc));                                 // 05d9 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x11f4));                                 // 05dd lea cx, [0x11f4]
  PUSH(0x05e4); goto L_0272;                                   // 05e1 call 0x272
L_05e4:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 05e4 ret
L_05e5:   SUB16(M16(DS, (u16)(0x18f9)), 0x2);                          // 05e5 cmp word ptr [0x18f9], 2
  if (R.zf) goto L_0618;                                       // 05ea je 0x618
  W16(DS, (u16)(0x18f9), 0x2);                                 // 05ec mov word ptr [0x18f9], 2
  PUSH(0x05f5); goto L_02e7;                                   // 05f2 call 0x2e7
L_05f5:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 05f5 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 05f7 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x1200));                                 // 05fb lea cx, [0x1200]
  PUSH(0x0602); goto L_0272;                                   // 05ff call 0x272
L_0602:   R.bx = (u16)((u16)(0x19c4));                                 // 0602 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x1212));                                 // 0606 lea cx, [0x1212]
  PUSH(0x060d); goto L_0272;                                   // 060a call 0x272
L_060d:   R.bx = (u16)((u16)(0x19dc));                                 // 060d lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x1224));                                 // 0611 lea cx, [0x1224]
  PUSH(0x0618); goto L_0272;                                   // 0615 call 0x272
L_0618:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0618 ret
L_0619:   SUB16(M16(DS, (u16)(0x18f9)), 0x3);                          // 0619 cmp word ptr [0x18f9], 3
  if (R.zf) goto L_064c;                                       // 061e je 0x64c
  W16(DS, (u16)(0x18f9), 0x3);                                 // 0620 mov word ptr [0x18f9], 3
  PUSH(0x0629); goto L_02e7;                                   // 0626 call 0x2e7
L_0629:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0629 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 062b lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x1230));                                 // 062f lea cx, [0x1230]
  PUSH(0x0636); goto L_0272;                                   // 0633 call 0x272
L_0636:   R.bx = (u16)((u16)(0x19c4));                                 // 0636 lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x1244));                                 // 063a lea cx, [0x1244]
  PUSH(0x0641); goto L_0272;                                   // 063e call 0x272
L_0641:   R.bx = (u16)((u16)(0x19dc));                                 // 0641 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x1258));                                 // 0645 lea cx, [0x1258]
  PUSH(0x064c); goto L_0272;                                   // 0649 call 0x272
L_064c:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 064c ret
L_064d:   SUB16(M16(DS, (u16)(0x18f9)), 0x4);                          // 064d cmp word ptr [0x18f9], 4
  if (R.zf) goto L_0680;                                       // 0652 je 0x680
  W16(DS, (u16)(0x18f9), 0x4);                                 // 0654 mov word ptr [0x18f9], 4
  PUSH(0x065d); goto L_02e7;                                   // 065a call 0x2e7
L_065d:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 065d xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 065f lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x1264));                                 // 0663 lea cx, [0x1264]
  PUSH(0x066a); goto L_0272;                                   // 0667 call 0x272
L_066a:   R.bx = (u16)((u16)(0x19c4));                                 // 066a lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x1282));                                 // 066e lea cx, [0x1282]
  PUSH(0x0675); goto L_0272;                                   // 0672 call 0x272
L_0675:   R.bx = (u16)((u16)(0x19dc));                                 // 0675 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x1292));                                 // 0679 lea cx, [0x1292]
  PUSH(0x0680); goto L_0272;                                   // 067d call 0x272
L_0680:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0680 ret
L_0681:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0681 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 0683 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x3a2));                                  // 0687 lea cx, [0x3a2]
  PUSH(0x068e); goto L_0272;                                   // 068b call 0x272
L_068e:   R.bx = (u16)((u16)(0x19c4));                                 // 068e lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x44c));                                  // 0692 lea cx, [0x44c]
  PUSH(0x0699); goto L_0272;                                   // 0696 call 0x272
L_0699:   R.bx = (u16)((u16)(0x19dc));                                 // 0699 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x544));                                  // 069d lea cx, [0x544]
  goto L_0272;                                                 // 06a1 jmp 0x272
L_06a4:   PUSH(0x06a7); goto L_0681;                                   // 06a4 call 0x681
L_06a7:   R.ax = (u16)((u16)(0x608));                                  // 06a7 lea ax, [0x608]
  PUSH(R.ax);                                                  // 06ab push ax
  PUSH(R.ax);                                                  // 06ac push ax
  goto L_06c0;                                                 // 06ad jmp 0x6c0
L_06af:   PUSH(0x06b2); goto L_0681;                                   // 06af call 0x681
L_06b2:   R.ax = (u16)((u16)(0x554));                                  // 06b2 lea ax, [0x554]
  PUSH(R.ax);                                                  // 06b6 push ax
  R.ax = (u16)((u16)(0x486));                                  // 06b7 lea ax, [0x486]
  PUSH(R.ax);                                                  // 06bb push ax
  R.ax = (u16)((u16)(0x3c0));                                  // 06bc lea ax, [0x3c0]
L_06c0:   R.bx = (u16)((u16)(0x19ac));                                 // 06c0 lea bx, [0x19ac]
  W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 06c4 mov word ptr [bx + 0x10], ax
  R.ax = POP();                                                // 06c7 pop ax
  R.bx = (u16)((u16)(0x19c4));                                 // 06c8 lea bx, [0x19c4]
  W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 06cc mov word ptr [bx + 0x10], ax
  R.ax = POP();                                                // 06cf pop ax
  R.bx = (u16)((u16)(0x19dc));                                 // 06d0 lea bx, [0x19dc]
  W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 06d4 mov word ptr [bx + 0x10], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 06d7 ret
L_06d8:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06d8 xor ax, ax
  R.bx = (u16)((u16)(0x19f4));                                 // 06da lea bx, [0x19f4]
  R.cx = (u16)((u16)(0x1500));                                 // 06de lea cx, [0x1500]
  goto L_0272;                                                 // 06e2 jmp 0x272
L_06e5:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06e5 xor ax, ax
  R.bx = (u16)((u16)(0x19dc));                                 // 06e7 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x1508));                                 // 06eb lea cx, [0x1508]
  goto L_0272;                                                 // 06ef jmp 0x272
L_06f2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06f2 xor ax, ax
  R.bx = (u16)((u16)(0x19dc));                                 // 06f4 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x1510));                                 // 06f8 lea cx, [0x1510]
  goto L_0272;                                                 // 06fc jmp 0x272
L_06ff:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06ff xor ax, ax
  R.bx = (u16)((u16)(0x19f4));                                 // 0701 lea bx, [0x19f4]
  R.cx = (u16)((u16)(0x1524));                                 // 0705 lea cx, [0x1524]
  goto L_0272;                                                 // 0709 jmp 0x272
L_070c:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 070c xor ax, ax
  R.bx = (u16)((u16)(0x19f4));                                 // 070e lea bx, [0x19f4]
  R.cx = (u16)((u16)(0x152c));                                 // 0712 lea cx, [0x152c]
  goto L_0272;                                                 // 0716 jmp 0x272
L_0719:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0719 ret
L_0734:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0734 xor ax, ax
  R.bx = (u16)((u16)(0x1a0c));                                 // 0736 lea bx, [0x1a0c]
  R.cx = (u16)((u16)(0x1576));                                 // 073a lea cx, [0x1576]
  goto L_0272;                                                 // 073e jmp 0x272
L_0741:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0741 xor ax, ax
  R.bx = (u16)((u16)(0x1a0c));                                 // 0743 lea bx, [0x1a0c]
  R.cx = (u16)((u16)(0x1582));                                 // 0747 lea cx, [0x1582]
  goto L_0272;                                                 // 074b jmp 0x272
L_074e:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 074e xor ax, ax
  R.bx = (u16)((u16)(0x19dc));                                 // 0750 lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x158a));                                 // 0754 lea cx, [0x158a]
  goto L_0272;                                                 // 0758 jmp 0x272
L_075b:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 075b xor ax, ax
  R.bx = (u16)((u16)(0x1a24));                                 // 075d lea bx, [0x1a24]
  R.cx = (u16)((u16)(0x608));                                  // 0761 lea cx, [0x608]
  goto L_0272;                                                 // 0765 jmp 0x272
L_0768:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0768 xor ax, ax
  R.bx = (u16)((u16)(0x1a24));                                 // 076a lea bx, [0x1a24]
  R.cx = (u16)((u16)(0x154c));                                 // 076e lea cx, [0x154c]
  goto L_0272;                                                 // 0772 jmp 0x272
L_0775:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0775 xor ax, ax
  R.bx = (u16)((u16)(0x1a24));                                 // 0777 lea bx, [0x1a24]
  R.cx = (u16)((u16)(0x1562));                                 // 077b lea cx, [0x1562]
  goto L_0272;                                                 // 077f jmp 0x272
L_0782:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0782 xor ax, ax
  R.bx = (u16)((u16)(0x1a24));                                 // 0784 lea bx, [0x1a24]
  R.cx = (u16)((u16)(0x1556));                                 // 0788 lea cx, [0x1556]
  goto L_0272;                                                 // 078c jmp 0x272
L_078f:   R.ax = (u16)((u16)(0x75b));                                  // 078f lea ax, [0x75b]
  R.bx = (u16)((u16)(0x1a24));                                 // 0793 lea bx, [0x1a24]
  R.cx = (u16)((u16)(0x1544));                                 // 0797 lea cx, [0x1544]
  goto L_0272;                                                 // 079b jmp 0x272
L_079e:   R.ax = (u16)((u16)(0x768));                                  // 079e lea ax, [0x768]
  R.bx = (u16)((u16)(0x1a24));                                 // 07a2 lea bx, [0x1a24]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 07a6 mov word ptr [bx + 0x16], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 07a9 ret
L_07aa:   R.ax = (u16)((u16)(0x775));                                  // 07aa lea ax, [0x775]
  R.bx = (u16)((u16)(0x1a24));                                 // 07ae lea bx, [0x1a24]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 07b2 mov word ptr [bx + 0x16], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 07b5 ret
L_07b6:   R.ax = (u16)((u16)(0x782));                                  // 07b6 lea ax, [0x782]
  R.bx = (u16)((u16)(0x1a24));                                 // 07ba lea bx, [0x1a24]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 07be mov word ptr [bx + 0x16], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 07c1 ret
L_07c2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07c2 xor ax, ax
  R.bx = (u16)((u16)(0x19ac));                                 // 07c4 lea bx, [0x19ac]
  R.cx = (u16)((u16)(0x16b6));                                 // 07c8 lea cx, [0x16b6]
  PUSH(0x07cf); goto L_0272;                                   // 07cc call 0x272
L_07cf:   R.bx = (u16)((u16)(0x19c4));                                 // 07cf lea bx, [0x19c4]
  R.cx = (u16)((u16)(0x16d0));                                 // 07d3 lea cx, [0x16d0]
  PUSH(0x07da); goto L_0272;                                   // 07d7 call 0x272
L_07da:   R.bx = (u16)((u16)(0x19dc));                                 // 07da lea bx, [0x19dc]
  R.cx = (u16)((u16)(0x16dc));                                 // 07de lea cx, [0x16dc]
  goto L_0272;                                                 // 07e2 jmp 0x272
L_07e5:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 07e5 ret
L_07e6:   R.bx = (u16)((u16)(0x19ac));                                 // 07e6 lea bx, [0x19ac]
  goto L_02ae;                                                 // 07ea jmp 0x2ae
L_07ed:   R.bx = (u16)((u16)(0x19c4));                                 // 07ed lea bx, [0x19c4]
  goto L_02ae;                                                 // 07f1 jmp 0x2ae
L_07f4:   R.bx = (u16)((u16)(0x19dc));                                 // 07f4 lea bx, [0x19dc]
  goto L_02ae;                                                 // 07f8 jmp 0x2ae
L_0859:   PUSH(R.di);                                                  // 0859 push di
  PUSH(R.bp);                                                  // 085a push bp
  PUSH(R.ds);                                                  // 085b push ds
  R.ax = (u16)(0xd14f /* segment */);                          // 085c mov ax, 0x14f
  R.ds = (u16)(R.ax);                                          // 085f mov ds, ax
  PUSH(0x0864); goto L_004d;                                   // 0861 call 0x4d
L_0864:   R.ds = POP();                                                // 0864 pop ds
  R.bp = POP();                                                // 0865 pop bp
  R.di = POP();                                                // 0866 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0867 retf
L_0868:   PUSH(R.bp);                                                  // 0868 push bp
  R.bp = (u16)(R.sp);                                          // 0869 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 086b mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x5c);                                           // 086e cmp bx, 0x5c
  if (!R.zf && R.sf == R.of) goto L_0882;                      // 0871 jg 0x882
  PUSH(R.ds);                                                  // 0873 push ds
  R.ax = (u16)(0xd14f /* segment */);                          // 0874 mov ax, 0x14f
  R.ds = (u16)(R.ax);                                          // 0877 mov ds, ax
  R.bx = (u16)(AND16(R.bx, 0xfffe));                           // 0879 and bx, 0xfffe
  { u16 t_ = M16(CS, (u16)(R.bx + 0x7fb)); PUSH(0x0881); ip_ = t_; goto dispatch_; } // 087c call word ptr cs:[bx + 0x7fb]
L_0881:   R.ds = POP();                                                // 0881 pop ds
L_0882:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0882 xor ax, ax
  R.bp = POP();                                                // 0884 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0885 retf
L_0886:   PUSH(R.ds);                                                  // 0886 push ds
  R.ax = (u16)(0xd14f /* segment */);                          // 0887 mov ax, 0x14f
  R.ds = (u16)(R.ax);                                          // 088a mov ds, ax
  PUSH(0x088f); goto L_017b;                                   // 088c call 0x17b
L_088f:   R.ax = (u16)(M16(DS, (u16)(0x18ea)));                        // 088f mov ax, word ptr [0x18ea]
  W16(DS, (u16)(0x18ea), 0x0);                                 // 0892 mov word ptr [0x18ea], 0
  R.ds = POP();                                                // 0898 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0899 retf
L_089a:   PUSH(R.ds);                                                  // 089a push ds
  R.ax = (u16)(0xd14f /* segment */);                          // 089b mov ax, 0x14f
  R.ds = (u16)(R.ax);                                          // 089e mov ds, ax
  PUSH(0x08a3); goto L_020a;                                   // 08a0 call 0x20a
L_08a3:   R.ds = POP();                                                // 08a3 pop ds
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 08a4 xor ax, ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 08a6 retf
L_08a7:   PUSH(R.bp);                                                  // 08a7 push bp
  R.bp = (u16)(R.sp);                                          // 08a8 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 08aa mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x5);                                            // 08ad cmp bx, 5
  if (!R.zf && R.sf == R.of) goto L_08c0;                      // 08b0 jg 0x8c0
  PUSH(R.ds);                                                  // 08b2 push ds
  R.ax = (u16)(0xd14f /* segment */);                          // 08b3 mov ax, 0x14f
  R.ds = (u16)(R.ax);                                          // 08b6 mov ds, ax
  W16(DS, (u16)(0x18f3), R.bx);                                // 08b8 mov word ptr [0x18f3], bx
  PUSH(0x08bf); goto L_08cf;                                   // 08bc call 0x8cf
L_08bf:   R.ds = POP();                                                // 08bf pop ds
L_08c0:   R.bp = POP();                                                // 08c0 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 08c1 retf
L_08c2:   W16(DS, (u16)(R.bx + 0xa), R.ax);                            // 08c2 mov word ptr [bx + 0xa], ax
  W16(DS, (u16)(R.bx + 0xe), R.ax);                            // 08c5 mov word ptr [bx + 0xe], ax
  R.ax = (u16)(0x2);                                           // 08c8 mov ax, 2
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 08cb mov word ptr [bx + 0x12], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 08ce ret
L_08cf:   R.ax = (u16)(M16(DS, (u16)(0x18f3)));                        // 08cf mov ax, word ptr [0x18f3]
  SUB16(R.ax, M16(DS, (u16)(0x18f5)));                         // 08d2 cmp ax, word ptr [0x18f5]
  if (R.zf) goto L_0925;                                       // 08d6 je 0x925
  W16(DS, (u16)(0x18f5), R.ax);                                // 08d8 mov word ptr [0x18f5], ax
  W8(DS, (u16)(0x18f2), 0x2);                                  // 08db mov byte ptr [0x18f2], 2
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 08e0 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 08e2 shl ax, 1
  R.bx = (u16)(M16(DS, (u16)(0x18f7)));                        // 08e4 mov bx, word ptr [0x18f7]
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 08e8 add bx, ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 08ea mov ax, word ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 08ec inc bx
  R.bx = (u16)(INC16(R.bx));                                   // 08ed inc bx
  R.cx = (u16)(M16(DS, (u16)(R.bx)));                          // 08ee mov cx, word ptr [bx]
  SETL(R.bx, M8(DS, (u16)(0x19aa)));                           // 08f0 mov bl, byte ptr [0x19aa]
  PUSH(R.bx);                                                  // 08f4 push bx
  W8(DS, (u16)(0x19aa), 0x0);                                  // 08f5 mov byte ptr [0x19aa], 0
  R.bx = (u16)((u16)(0x19ac));                                 // 08fa lea bx, [0x19ac]
  PUSH(0x0901); goto L_08c2;                                   // 08fe call 0x8c2
L_0901:   R.ax = (u16)(R.cx);                                          // 0901 mov ax, cx
  R.bx = (u16)((u16)(0x19c4));                                 // 0903 lea bx, [0x19c4]
  PUSH(0x090a); goto L_08c2;                                   // 0907 call 0x8c2
L_090a:   R.bx = POP();                                                // 090a pop bx
  W8(DS, (u16)(0x19aa), (u8)R.bx);                             // 090b mov byte ptr [0x19aa], bl
  R.ax = (u16)(M16(DS, (u16)(0x18f3)));                        // 090f mov ax, word ptr [0x18f3]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 0912 or al, al
  if (R.zf) goto L_091a;                                       // 0914 je 0x91a
  SUB8((u8)R.ax, 0x5);                                         // 0916 cmp al, 5
  if (!R.zf) goto L_0925;                                      // 0918 jne 0x925
L_091a:   SETL(R.ax, M8(DS, (u16)(0x19ac)));                           // 091a mov al, byte ptr [0x19ac]
  SETL(R.ax, OR8((u8)R.ax, M8(DS, (u16)(0x19c4))));            // 091d or al, byte ptr [0x19c4]
  SUB8((u8)R.ax, 0x0);                                         // 0921 cmp al, 0
  if (!R.zf) { asm_idle(); goto L_091a; }  /* a wait for the tick */ // 0923 jne 0x91a
L_0925:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0925 ret
L_0926:   PUSH(R.di);                                                  // 0926 push di
  PUSH(R.bp);                                                  // 0927 push bp
  PUSH(R.ds);                                                  // 0928 push ds
  R.ax = (u16)(0xd14f /* segment */);                          // 0929 mov ax, 0x14f
  R.ds = (u16)(R.ax);                                          // 092c mov ds, ax
  PUSH(0x0931); goto L_004d;                                   // 092e call 0x4d
L_0931:   R.ds = POP();                                                // 0931 pop ds
  R.bp = POP();                                                // 0932 pop bp
  R.di = POP();                                                // 0933 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0934 retf
L_0935:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0935 retf
L_0936:   PUSH(R.bp);                                                  // 0936 push bp
  R.bp = (u16)(R.sp);                                          // 0937 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 0939 sub sp, 2
  PUSH(R.si);                                                  // 093d push si
  PUSH(R.di);                                                  // 093e push di
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 093f mov ax, word ptr [bp + 4]
  SETL(R.bx, (u8)R.ax);                                        // 0942 mov bl, al
  SUB8((u8)R.ax, 0x6);                                         // 0944 cmp al, 6
  if (R.zf || R.sf != R.of) goto L_0954;                       // 0946 jle 0x954
  SETL(R.bx, 0x7);                                             // 0948 mov bl, 7
  SUB8((u8)R.ax, 0x7);                                         // 094a cmp al, 7
  if (R.zf) goto L_0954;                                       // 094c je 0x954
  SUB8((u8)R.ax, 0xa);                                         // 094e cmp al, 0xa
  if (R.zf) goto L_0954;                                       // 0950 je 0x954
  SETL(R.bx, 0x8);                                             // 0952 mov bl, 8
L_0954:   SETH(R.bx, XOR8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));          // 0954 xor bh, bh
  W16(SS, (u16)(R.bp + 0xfffe), R.bx);                         // 0956 mov word ptr [bp - 2], bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0959 mov ax, word ptr [bp - 2]
  R.di = POP();                                                // 095c pop di
  R.si = POP();                                                // 095d pop si
  R.sp = (u16)(R.bp);                                          // 095e mov sp, bp
  R.bp = POP();                                                // 0960 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0961 ret
L_0962:   PUSH(R.bp);                                                  // 0962 push bp
  R.bp = (u16)(R.sp);                                          // 0963 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0965 sub sp, 4
  SUB16(M16(SS, (u16)(R.bp + 0x4)), 0x6);                      // 0969 cmp word ptr [bp + 4], 6
  if (!R.cf) goto L_098e;                                      // 096d jae 0x98e
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 096f mov ax, word ptr [bp + 4]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0972 shl ax, 1
  R.cx = (u16)(0x196c);                                        // 0974 mov cx, 0x196c
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0977 add cx, ax
  R.bx = (u16)(R.cx);                                          // 0979 mov bx, cx
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1)));                       // 097b mov al, byte ptr [bx + 1]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 097e cwde
  R.bx = (u16)(R.ax);                                          // 097f mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1982)));                    // 0981 mov al, byte ptr [bx + 0x1982]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0985 cwde
  R.ax = (u16)(ADD16(R.ax, 0x40));                             // 0986 add ax, 0x40
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0989 mov word ptr [bp - 2], ax
  goto L_09a5;                                                 // 098c jmp 0x9a5
L_098e:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 098e mov bx, word ptr [bp + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0991 shl bx, 1
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x196c)));                    // 0993 mov al, byte ptr [bx + 0x196c]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0997 cwde
  R.bx = (u16)(R.ax);                                          // 0998 mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1982)));                    // 099a mov al, byte ptr [bx + 0x1982]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 099e cwde
  R.ax = (u16)(ADD16(R.ax, 0x40));                             // 099f add ax, 0x40
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 09a2 mov word ptr [bp - 2], ax
L_09a5:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 09a5 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 09a8 mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0xc0));                             // 09ac and ax, 0xc0
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 09af mov word ptr [bp - 4], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 09b2 mov ax, word ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0x3f));                             // 09b5 and ax, 0x3f
  R.cx = (u16)(0x3f);                                          // 09b8 mov cx, 0x3f
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 09bb sub cx, ax
  W16(SS, (u16)(R.bp + 0xfffc), OR16(M16(SS, (u16)(R.bp + 0xfffc)), R.cx)); // 09bd or word ptr [bp - 4], cx
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 09c0 push word ptr [bp - 4]
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 09c3 push word ptr [bp - 2]
  PUSH(0x09c9); goto L_0139;                                   // 09c6 call 0x139
L_09c9:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 09c9 add sp, 4
  R.sp = (u16)(R.bp);                                          // 09cc mov sp, bp
  R.bp = POP();                                                // 09ce pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 09cf ret
L_09d0:   PUSH(R.bp);                                                  // 09d0 push bp
  R.bp = (u16)(R.sp);                                          // 09d1 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0xc));                              // 09d3 sub sp, 0xc
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 09d7 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 09da and ax, 0xff
  PUSH(R.ax);                                                  // 09dd push ax
  PUSH(0x09e1); goto L_0936;                                   // 09de call 0x936
L_09e1:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 09e1 add sp, 2
  R.ax = (u16)(ADD16(R.ax, 0xa0));                             // 09e4 add ax, 0xa0
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 09e7 mov word ptr [bp - 2], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 09ea mov al, byte ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 09ed and ax, 0xff
  R.cx = (u16)(0xc);                                           // 09f0 mov cx, 0xc
  R.dx = (u16)(SUB16(R.dx, R.dx));                             // 09f3 sub dx, dx
  DIV16(R.cx, 0x09f5);                                         // 09f5 div cx
  W8(SS, (u16)(R.bp + 0xfff8), (u8)R.dx);                      // 09f7 mov byte ptr [bp - 8], dl
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 09fa mov al, byte ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 09fd and ax, 0xff
  R.cx = (u16)(0xc);                                           // 0a00 mov cx, 0xc
  R.dx = (u16)(SUB16(R.dx, R.dx));                             // 0a03 sub dx, dx
  DIV16(R.cx, 0x0a05);                                         // 0a05 div cx
  W8(SS, (u16)(R.bp + 0xfff6), (u8)R.ax);                      // 0a07 mov byte ptr [bp - 0xa], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfff8)));                    // 0a0a mov al, byte ptr [bp - 8]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a0d and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0a10 mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0a12 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x194e)));                 // 0a14 mov ax, word ptr [bx + 0x194e]
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0a18 mov word ptr [bp - 4], ax
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a1b and ax, 0xff
  PUSH(R.ax);                                                  // 0a1e push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0a1f push word ptr [bp - 2]
  PUSH(0x0a25); goto L_0139;                                   // 0a22 call 0x139
L_0a25:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0a25 add sp, 4
  W16(SS, (u16)(R.bp + 0xfffe), ADD16(M16(SS, (u16)(R.bp + 0xfffe)), 0x10)); // 0a28 add word ptr [bp - 2], 0x10
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0a2c mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 0a2f mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0x20));                             // 0a33 and ax, 0x20
  W8(SS, (u16)(R.bp + 0xfffa), (u8)R.ax);                      // 0a36 mov byte ptr [bp - 6], al
  R.cx = (u16)(0x8);                                           // 0a39 mov cx, 8
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 0a3c mov ax, word ptr [bp - 4]
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 0a3f shr ax, cl
  W16(SS, (u16)(R.bp + 0xfff4), R.ax);                         // 0a41 mov word ptr [bp - 0xc], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfff6)));                    // 0a44 mov al, byte ptr [bp - 0xa]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a47 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0a4a shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0a4c shl ax, 1
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xfff4)));                 // 0a4e mov cx, word ptr [bp - 0xc]
  R.cx = (u16)(OR16(R.cx, R.ax));                              // 0a51 or cx, ax
  W8(SS, (u16)(R.bp + 0xfffa), OR8(M8(SS, (u16)(R.bp + 0xfffa)), (u8)R.cx)); // 0a53 or byte ptr [bp - 6], cl
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfffa)));                    // 0a56 mov al, byte ptr [bp - 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a59 and ax, 0xff
  PUSH(R.ax);                                                  // 0a5c push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0a5d push word ptr [bp - 2]
  PUSH(0x0a63); goto L_0139;                                   // 0a60 call 0x139
L_0a63:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0a63 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0a66 mov sp, bp
  R.bp = POP();                                                // 0a68 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0a69 ret
L_0a6a:   PUSH(R.bp);                                                  // 0a6a push bp
  R.bp = (u16)(R.sp);                                          // 0a6b mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0xa));                              // 0a6d sub sp, 0xa
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0a71 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a74 and ax, 0xff
  PUSH(R.ax);                                                  // 0a77 push ax
  PUSH(0x0a7b); goto L_0936;                                   // 0a78 call 0x936
L_0a7b:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0a7b add sp, 2
  R.ax = (u16)(ADD16(R.ax, 0xa0));                             // 0a7e add ax, 0xa0
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0a81 mov word ptr [bp - 2], ax
  R.ax = (u16)(ADD16(R.ax, 0x10));                             // 0a84 add ax, 0x10
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0a87 mov word ptr [bp - 4], ax
  R.bx = (u16)(R.ax);                                          // 0a8a mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 0a8c mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0x1f));                             // 0a90 and ax, 0x1f
  R.cx = (u16)(0x8);                                           // 0a93 mov cx, 8
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 0a96 shl ax, cl
  W16(SS, (u16)(R.bp + 0xfffa), R.ax);                         // 0a98 mov word ptr [bp - 6], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0a9b mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 0a9e mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0aa2 and ax, 0xff
  W16(SS, (u16)(R.bp + 0xfff6), R.ax);                         // 0aa5 mov word ptr [bp - 0xa], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 0aa8 mov al, byte ptr [bp + 6]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0aab cwde
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xfff6)));                 // 0aac mov cx, word ptr [bp - 0xa]
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0aaf add cx, ax
  W16(SS, (u16)(R.bp + 0xfffa), ADD16(M16(SS, (u16)(R.bp + 0xfffa)), R.cx)); // 0ab1 add word ptr [bp - 6], cx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 0ab4 mov ax, word ptr [bp - 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ab7 and ax, 0xff
  PUSH(R.ax);                                                  // 0aba push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0abb push word ptr [bp - 2]
  PUSH(0x0ac1); goto L_0139;                                   // 0abe call 0x139
L_0ac1:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0ac1 add sp, 4
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 0ac4 mov bx, word ptr [bp - 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 0ac7 mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0x20));                             // 0acb and ax, 0x20
  W8(SS, (u16)(R.bp + 0xfff8), (u8)R.ax);                      // 0ace mov byte ptr [bp - 8], al
  R.cx = (u16)(0x8);                                           // 0ad1 mov cx, 8
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 0ad4 mov ax, word ptr [bp - 6]
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 0ad7 shr ax, cl
  W8(SS, (u16)(R.bp + 0xfff8), OR8(M8(SS, (u16)(R.bp + 0xfff8)), (u8)R.ax)); // 0ad9 or byte ptr [bp - 8], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfff8)));                    // 0adc mov al, byte ptr [bp - 8]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0adf and ax, 0xff
  PUSH(R.ax);                                                  // 0ae2 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0ae3 push word ptr [bp - 4]
  PUSH(0x0ae9); goto L_0139;                                   // 0ae6 call 0x139
L_0ae9:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0ae9 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0aec mov sp, bp
  R.bp = POP();                                                // 0aee pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0aef ret
L_0b6c:   PUSH(R.bp);                                                  // 0b6c push bp
  R.bp = (u16)(R.sp);                                          // 0b6d mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x6));                              // 0b6f sub sp, 6
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0b73 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b76 and ax, 0xff
  SUB16(R.ax, 0x6);                                            // 0b79 cmp ax, 6
  if (!R.cf) goto L_0bb0;                                      // 0b7c jae 0xbb0
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0b7e mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b81 and ax, 0xff
  PUSH(R.ax);                                                  // 0b84 push ax
  PUSH(0x0b88); goto L_0936;                                   // 0b85 call 0x936
L_0b88:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b88 add sp, 2
  R.ax = (u16)(ADD16(R.ax, 0xb0));                             // 0b8b add ax, 0xb0
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0b8e mov word ptr [bp - 4], ax
  R.bx = (u16)(R.ax);                                          // 0b91 mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 0b93 mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0xdf));                             // 0b97 and ax, 0xdf
  W8(SS, (u16)(R.bp + 0xfffe), (u8)R.ax);                      // 0b9a mov byte ptr [bp - 2], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfffe)));                    // 0b9d mov al, byte ptr [bp - 2]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ba0 and ax, 0xff
  PUSH(R.ax);                                                  // 0ba3 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0ba4 push word ptr [bp - 4]
  PUSH(0x0baa); goto L_0139;                                   // 0ba7 call 0x139
L_0baa:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0baa add sp, 4
  goto L_0be4;                                                 // 0bad jmp 0xbe4
L_0bb0:   SETL(R.ax, M8(DS, (u16)(0x1b03)));                           // 0bb0 mov al, byte ptr [0x1b03]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bb3 and ax, 0xff
  W16(SS, (u16)(R.bp + 0xfffa), R.ax);                         // 0bb6 mov word ptr [bp - 6], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0bb9 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bbc and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0bbf mov bx, ax
  R.bx = (u16)(ADD16(R.bx, 0xfffa));                           // 0bc1 add bx, -6
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1948)));                    // 0bc4 mov al, byte ptr [bx + 0x1948]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0bc8 cwde
  R.ax = (u16)((u16)~R.ax);                                    // 0bc9 not ax
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 0bcb mov cx, word ptr [bp - 6]
  R.cx = (u16)(AND16(R.cx, R.ax));                             // 0bce and cx, ax
  W8(SS, (u16)(R.bp + 0xfffe), (u8)R.cx);                      // 0bd0 mov byte ptr [bp - 2], cl
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfffe)));                    // 0bd3 mov al, byte ptr [bp - 2]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bd6 and ax, 0xff
  PUSH(R.ax);                                                  // 0bd9 push ax
  R.ax = (u16)(0xbd);                                          // 0bda mov ax, 0xbd
  PUSH(R.ax);                                                  // 0bdd push ax
  PUSH(0x0be1); goto L_0139;                                   // 0bde call 0x139
L_0be1:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0be1 add sp, 4
L_0be4:   R.sp = (u16)(R.bp);                                          // 0be4 mov sp, bp
  R.bp = POP();                                                // 0be6 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0be7 ret
L_0be8:   PUSH(R.bp);                                                  // 0be8 push bp
  R.bp = (u16)(R.sp);                                          // 0be9 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x6));                              // 0beb sub sp, 6
  PUSH(R.si);                                                  // 0bef push si
  PUSH(R.di);                                                  // 0bf0 push di
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0bf1 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bf4 and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0bf7 mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0bf9 shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0bfb shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0bfd shl bx, 1
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1b46)));                    // 0bff mov al, byte ptr [bx + 0x1b46]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c03 and ax, 0xff
  if (!R.zf) goto L_0c0b;                                      // 0c06 jne 0xc0b
  goto L_0cee;                                                 // 0c08 jmp 0xcee
L_0c0b:   SETL(R.ax, M8(DS, (u16)(0x1a3c)));                           // 0c0b mov al, byte ptr [0x1a3c]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c0e and ax, 0xff
  if (R.zf) goto L_0c16;                                       // 0c11 je 0xc16
  goto L_0c82;                                                 // 0c13 jmp 0xc82
L_0c16:   SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c16 mov al, byte ptr [bp + 4]
  W8(DS, (u16)(0x1a43), (u8)R.ax);                             // 0c19 mov byte ptr [0x1a43], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c1c mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c1f and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0c22 mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c24 shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c26 shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c28 shl bx, 1
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1b46)));                    // 0c2a mov al, byte ptr [bx + 0x1b46]
  W8(DS, (u16)(0x1a3c), (u8)R.ax);                             // 0c2e mov byte ptr [0x1a3c], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c31 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c34 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c37 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c39 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c3b shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 0c3d mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0c40 add cx, ax
  R.bx = (u16)(R.cx);                                          // 0c42 mov bx, cx
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 0c44 mov ax, word ptr [bx + 2]
  W16(DS, (u16)(0x1a3e), R.ax);                                // 0c47 mov word ptr [0x1a3e], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c4a mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c4d and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c50 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c52 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c54 shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 0c56 mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0c59 add cx, ax
  R.bx = (u16)(R.cx);                                          // 0c5b mov bx, cx
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0c5d mov ax, word ptr [bx + 4]
  W16(DS, (u16)(0x19a2), R.ax);                                // 0c60 mov word ptr [0x19a2], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c63 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c66 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c69 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c6b shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0c6d shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 0c6f mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0c72 add cx, ax
  R.bx = (u16)(R.cx);                                          // 0c74 mov bx, cx
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0c76 mov ax, word ptr [bx + 6]
  W16(DS, (u16)(0x19a6), R.ax);                                // 0c79 mov word ptr [0x19a6], ax
  PUSH(0x0c7f); goto L_024d;                                   // 0c7c call 0x24d
L_0c7f:   goto L_0ceb;                                                 // 0c7f jmp 0xceb
L_0c82:   SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c82 mov al, byte ptr [bp + 4]
  W8(DS, (u16)(0x1a44), (u8)R.ax);                             // 0c85 mov byte ptr [0x1a44], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c88 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0c8b and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0c8e mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c90 shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c92 shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c94 shl bx, 1
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1b46)));                    // 0c96 mov al, byte ptr [bx + 0x1b46]
  W8(DS, (u16)(0x1a3d), (u8)R.ax);                             // 0c9a mov byte ptr [0x1a3d], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0c9d mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ca0 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ca3 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ca5 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ca7 shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 0ca9 mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0cac add cx, ax
  R.bx = (u16)(R.cx);                                          // 0cae mov bx, cx
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 0cb0 mov ax, word ptr [bx + 2]
  W16(DS, (u16)(0x1a40), R.ax);                                // 0cb3 mov word ptr [0x1a40], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0cb6 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0cb9 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0cbc shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0cbe shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0cc0 shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 0cc2 mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0cc5 add cx, ax
  R.bx = (u16)(R.cx);                                          // 0cc7 mov bx, cx
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0cc9 mov ax, word ptr [bx + 4]
  W16(DS, (u16)(0x19a4), R.ax);                                // 0ccc mov word ptr [0x19a4], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0ccf mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0cd2 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0cd5 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0cd7 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0cd9 shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 0cdb mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0cde add cx, ax
  R.bx = (u16)(R.cx);                                          // 0ce0 mov bx, cx
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0ce2 mov ax, word ptr [bx + 6]
  W16(DS, (u16)(0x19a8), R.ax);                                // 0ce5 mov word ptr [0x19a8], ax
  PUSH(0x0ceb); goto L_024d;                                   // 0ce8 call 0x24d
L_0ceb:   goto L_0d88;                                                 // 0ceb jmp 0xd88
L_0cee:   SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 0cee mov al, byte ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0cf1 and ax, 0xff
  PUSH(R.ax);                                                  // 0cf4 push ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0cf5 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0cf8 and ax, 0xff
  PUSH(R.ax);                                                  // 0cfb push ax
  PUSH(0x0cff); goto L_09d0;                                   // 0cfc call 0x9d0
L_0cff:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0cff add sp, 4
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x8)));                       // 0d02 mov al, byte ptr [bp + 8]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d05 and ax, 0xff
  PUSH(R.ax);                                                  // 0d08 push ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0d09 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d0c and ax, 0xff
  PUSH(R.ax);                                                  // 0d0f push ax
  PUSH(0x0d13); goto L_0962;                                   // 0d10 call 0x962
L_0d13:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0d13 add sp, 4
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0d16 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d19 and ax, 0xff
  SUB16(R.ax, 0x6);                                            // 0d1c cmp ax, 6
  if (!R.cf) goto L_0d56;                                      // 0d1f jae 0xd56
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0d21 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d24 and ax, 0xff
  PUSH(R.ax);                                                  // 0d27 push ax
  PUSH(0x0d2b); goto L_0936;                                   // 0d28 call 0x936
L_0d2b:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0d2b add sp, 2
  R.ax = (u16)(ADD16(R.ax, 0xb0));                             // 0d2e add ax, 0xb0
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0d31 mov word ptr [bp - 4], ax
  R.bx = (u16)(R.ax);                                          // 0d34 mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1a46)));                    // 0d36 mov al, byte ptr [bx + 0x1a46]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d3a and ax, 0xff
  R.ax = (u16)(OR16(R.ax, 0x20));                              // 0d3d or ax, 0x20
  W8(SS, (u16)(R.bp + 0xfffe), (u8)R.ax);                      // 0d40 mov byte ptr [bp - 2], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfffe)));                    // 0d43 mov al, byte ptr [bp - 2]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d46 and ax, 0xff
  PUSH(R.ax);                                                  // 0d49 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0d4a push word ptr [bp - 4]
  PUSH(0x0d50); goto L_0139;                                   // 0d4d call 0x139
L_0d50:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0d50 add sp, 4
  goto L_0d88;                                                 // 0d53 jmp 0xd88
L_0d56:   SETL(R.ax, M8(DS, (u16)(0x1b03)));                           // 0d56 mov al, byte ptr [0x1b03]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d59 and ax, 0xff
  W16(SS, (u16)(R.bp + 0xfffa), R.ax);                         // 0d5c mov word ptr [bp - 6], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0d5f mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d62 and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0d65 mov bx, ax
  R.bx = (u16)(ADD16(R.bx, 0xfffa));                           // 0d67 add bx, -6
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1948)));                    // 0d6a mov al, byte ptr [bx + 0x1948]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0d6e cwde
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 0d6f mov cx, word ptr [bp - 6]
  R.cx = (u16)(OR16(R.cx, R.ax));                              // 0d72 or cx, ax
  W8(SS, (u16)(R.bp + 0xfffe), (u8)R.cx);                      // 0d74 mov byte ptr [bp - 2], cl
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfffe)));                    // 0d77 mov al, byte ptr [bp - 2]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0d7a and ax, 0xff
  PUSH(R.ax);                                                  // 0d7d push ax
  R.ax = (u16)(0xbd);                                          // 0d7e mov ax, 0xbd
  PUSH(R.ax);                                                  // 0d81 push ax
  PUSH(0x0d85); goto L_0139;                                   // 0d82 call 0x139
L_0d85:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0d85 add sp, 4
L_0d88:   R.di = POP();                                                // 0d88 pop di
  R.si = POP();                                                // 0d89 pop si
  R.sp = (u16)(R.bp);                                          // 0d8a mov sp, bp
  R.bp = POP();                                                // 0d8c pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0d8d ret
L_0d8e:   PUSH(R.bp);                                                  // 0d8e push bp
  R.bp = (u16)(R.sp);                                          // 0d8f mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 0d91 sub sp, 2
  SETL(R.ax, M8(DS, (u16)(0x1b03)));                           // 0d95 mov al, byte ptr [0x1b03]
  R.ax = (u16)(AND16(R.ax, 0x3f));                             // 0d98 and ax, 0x3f
  W8(SS, (u16)(R.bp + 0xfffe), (u8)R.ax);                      // 0d9b mov byte ptr [bp - 2], al
  SETL(R.ax, M8(DS, (u16)(0x1966)));                           // 0d9e mov al, byte ptr [0x1966]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0da1 and ax, 0xff
  if (R.zf) goto L_0dac;                                       // 0da4 je 0xdac
  R.ax = (u16)(0x80);                                          // 0da6 mov ax, 0x80
  goto L_0dae;                                                 // 0da9 jmp 0xdae
L_0dac:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0dac xor ax, ax
L_0dae:   W8(SS, (u16)(R.bp + 0xfffe), OR8(M8(SS, (u16)(R.bp + 0xfffe)), (u8)R.ax)); // 0dae or byte ptr [bp - 2], al
  SETL(R.ax, M8(DS, (u16)(0x1968)));                           // 0db1 mov al, byte ptr [0x1968]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0db4 and ax, 0xff
  if (R.zf) goto L_0dbe;                                       // 0db7 je 0xdbe
  R.ax = (u16)(0x40);                                          // 0db9 mov ax, 0x40
  goto L_0dc0;                                                 // 0dbc jmp 0xdc0
L_0dbe:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0dbe xor ax, ax
L_0dc0:   W8(SS, (u16)(R.bp + 0xfffe), OR8(M8(SS, (u16)(R.bp + 0xfffe)), (u8)R.ax)); // 0dc0 or byte ptr [bp - 2], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xfffe)));                    // 0dc3 mov al, byte ptr [bp - 2]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0dc6 and ax, 0xff
  PUSH(R.ax);                                                  // 0dc9 push ax
  R.ax = (u16)(0xbd);                                          // 0dca mov ax, 0xbd
  PUSH(R.ax);                                                  // 0dcd push ax
  PUSH(0x0dd1); goto L_0139;                                   // 0dce call 0x139
L_0dd1:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0dd1 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0dd4 mov sp, bp
  R.bp = POP();                                                // 0dd6 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0dd7 ret
L_0dd8:   SETL(R.ax, M8(DS, (u16)(0x196a)));                           // 0dd8 mov al, byte ptr [0x196a]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ddb and ax, 0xff
  if (R.zf) goto L_0de6;                                       // 0dde je 0xde6
  R.ax = (u16)(0x40);                                          // 0de0 mov ax, 0x40
  goto L_0de8;                                                 // 0de3 jmp 0xde8
L_0de6:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0de6 xor ax, ax
L_0de8:   PUSH(R.ax);                                                  // 0de8 push ax
  R.ax = (u16)(0x8);                                           // 0de9 mov ax, 8
  PUSH(R.ax);                                                  // 0dec push ax
  PUSH(0x0df0); goto L_0139;                                   // 0ded call 0x139
L_0df0:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0df0 add sp, 4
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0df3 ret
L_0df4:   PUSH(R.bp);                                                  // 0df4 push bp
  R.bp = (u16)(R.sp);                                          // 0df5 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0df7 sub sp, 4
  R.ax = (u16)(M16(DS, (u16)(0x1ba0)));                        // 0dfb mov ax, word ptr [0x1ba0]
  R.ax = (u16)(ADD16(R.ax, 0x40));                             // 0dfe add ax, 0x40
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0e01 mov word ptr [bp - 4], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0e04 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x6)));                       // 0e08 mov al, byte ptr [bx + 6]
  R.ax = (u16)(AND16(R.ax, 0x3f));                             // 0e0b and ax, 0x3f
  R.cx = (u16)(0x3f);                                          // 0e0e mov cx, 0x3f
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 0e11 sub cx, ax
  W16(SS, (u16)(R.bp + 0xfffe), R.cx);                         // 0e13 mov word ptr [bp - 2], cx
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0e16 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x7)));                       // 0e1a mov al, byte ptr [bx + 7]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0e1d and ax, 0xff
  R.cx = (u16)(0x6);                                           // 0e20 mov cx, 6
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 0e23 shl ax, cl
  W16(SS, (u16)(R.bp + 0xfffe), OR16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0e25 or word ptr [bp - 2], ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0e28 push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0e2b push word ptr [bp - 4]
  PUSH(0x0e31); goto L_0139;                                   // 0e2e call 0x139
L_0e31:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0e31 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0e34 mov sp, bp
  R.bp = POP();                                                // 0e36 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0e37 ret
L_0e38:   PUSH(R.bp);                                                  // 0e38 push bp
  R.bp = (u16)(R.sp);                                          // 0e39 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0e3b sub sp, 4
  R.ax = (u16)(M16(DS, (u16)(0x1b9e)));                        // 0e3f mov ax, word ptr [0x1b9e]
  R.ax = (u16)(ADD16(R.ax, 0xc0));                             // 0e42 add ax, 0xc0
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0e45 mov word ptr [bp - 4], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0e48 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xa)));                       // 0e4c mov al, byte ptr [bx + 0xa]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0e4f and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0e52 shl ax, 1
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0e54 mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0e57 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xd)));                       // 0e5b mov al, byte ptr [bx + 0xd]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0e5e and ax, 0xff
  if (R.zf) goto L_0e68;                                       // 0e61 je 0xe68
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0e63 xor ax, ax
  goto L_0e6b;                                                 // 0e65 jmp 0xe6b
L_0e68:   R.ax = (u16)(0x1);                                           // 0e68 mov ax, 1
L_0e6b:   W16(SS, (u16)(R.bp + 0xfffe), OR16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0e6b or word ptr [bp - 2], ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0e6e push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0e71 push word ptr [bp - 4]
  PUSH(0x0e77); goto L_0139;                                   // 0e74 call 0x139
L_0e77:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0e77 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0e7a mov sp, bp
  R.bp = POP();                                                // 0e7c pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0e7d ret
L_0e7e:   PUSH(R.bp);                                                  // 0e7e push bp
  R.bp = (u16)(R.sp);                                          // 0e7f mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0e81 sub sp, 4
  R.ax = (u16)(M16(DS, (u16)(0x1ba0)));                        // 0e85 mov ax, word ptr [0x1ba0]
  R.ax = (u16)(ADD16(R.ax, 0x60));                             // 0e88 add ax, 0x60
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0e8b mov word ptr [bp - 4], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0e8e mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0e92 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0e94 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0e97 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0e99 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0e9b shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0e9d shl ax, 1
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0e9f mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0ea2 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1)));                       // 0ea6 mov al, byte ptr [bx + 1]
  R.ax = (u16)(AND16(R.ax, 0xf));                              // 0ea9 and ax, 0xf
  W16(SS, (u16)(R.bp + 0xfffe), OR16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0eac or word ptr [bp - 2], ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0eaf push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0eb2 push word ptr [bp - 4]
  PUSH(0x0eb8); goto L_0139;                                   // 0eb5 call 0x139
L_0eb8:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0eb8 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0ebb mov sp, bp
  R.bp = POP();                                                // 0ebd pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0ebe ret
L_0ec0:   PUSH(R.bp);                                                  // 0ec0 push bp
  R.bp = (u16)(R.sp);                                          // 0ec1 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0ec3 sub sp, 4
  R.ax = (u16)(M16(DS, (u16)(0x1ba0)));                        // 0ec7 mov ax, word ptr [0x1ba0]
  R.ax = (u16)(ADD16(R.ax, 0x80));                             // 0eca add ax, 0x80
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0ecd mov word ptr [bp - 4], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0ed0 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x2)));                       // 0ed4 mov al, byte ptr [bx + 2]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ed7 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0eda shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0edc shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ede shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ee0 shl ax, 1
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0ee2 mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0ee5 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x3)));                       // 0ee9 mov al, byte ptr [bx + 3]
  R.ax = (u16)(AND16(R.ax, 0xf));                              // 0eec and ax, 0xf
  W16(SS, (u16)(R.bp + 0xfffe), OR16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0eef or word ptr [bp - 2], ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0ef2 push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0ef5 push word ptr [bp - 4]
  PUSH(0x0efb); goto L_0139;                                   // 0ef8 call 0x139
L_0efb:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0efb add sp, 4
  R.sp = (u16)(R.bp);                                          // 0efe mov sp, bp
  R.bp = POP();                                                // 0f00 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0f01 ret
L_0f02:   PUSH(R.bp);                                                  // 0f02 push bp
  R.bp = (u16)(R.sp);                                          // 0f03 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0f05 sub sp, 4
  R.ax = (u16)(M16(DS, (u16)(0x1ba0)));                        // 0f09 mov ax, word ptr [0x1ba0]
  R.ax = (u16)(ADD16(R.ax, 0x20));                             // 0f0c add ax, 0x20
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0f0f mov word ptr [bp - 4], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0f12 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xb)));                       // 0f16 mov al, byte ptr [bx + 0xb]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f19 and ax, 0xff
  if (R.zf) goto L_0f24;                                       // 0f1c je 0xf24
  R.ax = (u16)(0x80);                                          // 0f1e mov ax, 0x80
  goto L_0f26;                                                 // 0f21 jmp 0xf26
L_0f24:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0f24 xor ax, ax
L_0f26:   W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0f26 mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0f29 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xc)));                       // 0f2d mov al, byte ptr [bx + 0xc]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f30 and ax, 0xff
  if (R.zf) goto L_0f3a;                                       // 0f33 je 0xf3a
  R.ax = (u16)(0x40);                                          // 0f35 mov ax, 0x40
  goto L_0f3c;                                                 // 0f38 jmp 0xf3c
L_0f3a:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0f3a xor ax, ax
L_0f3c:   W16(SS, (u16)(R.bp + 0xfffe), ADD16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0f3c add word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0f3f mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x4)));                       // 0f43 mov al, byte ptr [bx + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f46 and ax, 0xff
  if (R.zf) goto L_0f50;                                       // 0f49 je 0xf50
  R.ax = (u16)(0x20);                                          // 0f4b mov ax, 0x20
  goto L_0f52;                                                 // 0f4e jmp 0xf52
L_0f50:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0f50 xor ax, ax
L_0f52:   W16(SS, (u16)(R.bp + 0xfffe), ADD16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0f52 add word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0f55 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x5)));                       // 0f59 mov al, byte ptr [bx + 5]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f5c and ax, 0xff
  if (R.zf) goto L_0f66;                                       // 0f5f je 0xf66
  R.ax = (u16)(0x10);                                          // 0f61 mov ax, 0x10
  goto L_0f68;                                                 // 0f64 jmp 0xf68
L_0f66:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0f66 xor ax, ax
L_0f68:   W16(SS, (u16)(R.bp + 0xfffe), ADD16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0f68 add word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0f6b mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x9)));                       // 0f6f mov al, byte ptr [bx + 9]
  R.ax = (u16)(AND16(R.ax, 0xf));                              // 0f72 and ax, 0xf
  W16(SS, (u16)(R.bp + 0xfffe), ADD16(M16(SS, (u16)(R.bp + 0xfffe)), R.ax)); // 0f75 add word ptr [bp - 2], ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0f78 push word ptr [bp - 2]
  PUSH(M16(SS, (u16)(R.bp + 0xfffc)));                         // 0f7b push word ptr [bp - 4]
  PUSH(0x0f81); goto L_0139;                                   // 0f7e call 0x139
L_0f81:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0f81 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0f84 mov sp, bp
  R.bp = POP();                                                // 0f86 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0f87 ret
L_0f88:   PUSH(R.bp);                                                  // 0f88 push bp
  R.bp = (u16)(R.sp);                                          // 0f89 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 0f8b sub sp, 2
  R.ax = (u16)(M16(DS, (u16)(0x1ba0)));                        // 0f8f mov ax, word ptr [0x1ba0]
  R.ax = (u16)(ADD16(R.ax, 0xe0));                             // 0f92 add ax, 0xe0
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0f95 mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 0f98 mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x8)));                       // 0f9c mov al, byte ptr [bx + 8]
  R.ax = (u16)(AND16(R.ax, 0x3));                              // 0f9f and ax, 3
  PUSH(R.ax);                                                  // 0fa2 push ax
  PUSH(M16(SS, (u16)(R.bp + 0xfffe)));                         // 0fa3 push word ptr [bp - 2]
  PUSH(0x0fa9); goto L_0139;                                   // 0fa6 call 0x139
L_0fa9:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0fa9 add sp, 4
  R.sp = (u16)(R.bp);                                          // 0fac mov sp, bp
  R.bp = POP();                                                // 0fae pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0faf ret
L_0fb0:   PUSH(0x0fb3); goto L_0d8e;                                   // 0fb0 call 0xd8e
L_0fb3:   PUSH(0x0fb6); goto L_0dd8;                                   // 0fb3 call 0xdd8
L_0fb6:   PUSH(0x0fb9); goto L_0df4;                                   // 0fb6 call 0xdf4
L_0fb9:   PUSH(0x0fbc); goto L_0e38;                                   // 0fb9 call 0xe38
L_0fbc:   PUSH(0x0fbf); goto L_0e7e;                                   // 0fbc call 0xe7e
L_0fbf:   PUSH(0x0fc2); goto L_0ec0;                                   // 0fbf call 0xec0
L_0fc2:   PUSH(0x0fc5); goto L_0f02;                                   // 0fc2 call 0xf02
L_0fc5:   PUSH(0x0fc8); goto L_0f88;                                   // 0fc5 call 0xf88
L_0fc8:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0fc8 ret
L_0fca:   PUSH(R.bp);                                                  // 0fca push bp
  R.bp = (u16)(R.sp);                                          // 0fcb mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x2));                              // 0fcd sub sp, 2
  PUSH(R.si);                                                  // 0fd1 push si
  PUSH(R.di);                                                  // 0fd2 push di
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0fd3 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0fd6 and ax, 0xff
  PUSH(R.ax);                                                  // 0fd9 push ax
  PUSH(0x0fdd); goto L_0936;                                   // 0fda call 0x936
L_0fdd:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0fdd add sp, 2
  W16(DS, (u16)(0x1b9e), R.ax);                                // 0fe0 mov word ptr [0x1b9e], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 0fe3 mov al, byte ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0fe6 and ax, 0xff
  R.cx = (u16)(0x2c);                                          // 0fe9 mov cx, 0x2c
  IMUL16(R.cx);                                                // 0fec imul cx
  R.cx = (u16)(0x50);                                          // 0fee mov cx, 0x50
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 0ff1 add cx, ax
  W16(DS, (u16)(0x1ba2), R.cx);                                // 0ff3 mov word ptr [0x1ba2], cx
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0ff7 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ffa and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0ffd mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0fff shl bx, 1
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x196c)));                    // 1001 mov al, byte ptr [bx + 0x196c]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1005 cwde
  R.bx = (u16)(R.ax);                                          // 1006 mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1982)));                    // 1008 mov al, byte ptr [bx + 0x1982]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 100c cwde
  W16(DS, (u16)(0x1ba0), R.ax);                                // 100d mov word ptr [0x1ba0], ax
  SUB16(R.ax, 0x14);                                           // 1010 cmp ax, 0x14
  if (R.cf) goto L_1018;                                       // 1013 jb 0x1018
  goto L_10a3;                                                 // 1015 jmp 0x10a3
L_1018:   PUSH(0x101b); goto L_0fb0;                                   // 1018 call 0xfb0
L_101b:   R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 101b mov bx, word ptr [0x1ba2]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xe)));                       // 101f mov al, byte ptr [bx + 0xe]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 1022 mov word ptr [bp - 2], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 1025 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1028 and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 102b mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 102d shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 102f shl bx, 1
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1031 shl bx, 1
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1033 mov ax, word ptr [bp - 2]
  W8(DS, (u16)(R.bx + 0x1b46), (u8)R.ax);                      // 1036 mov byte ptr [bx + 0x1b46], al
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 103a mov bx, word ptr [0x1ba2]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x10)));                   // 103e mov ax, word ptr [bx + 0x10]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 1041 mov word ptr [bp - 2], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 1044 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1047 and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 104a shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 104c shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 104e shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 1050 mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 1053 add cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1055 mov ax, word ptr [bp - 2]
  R.bx = (u16)(R.cx);                                          // 1058 mov bx, cx
  W16(DS, (u16)(R.bx + 0x2), R.ax);                            // 105a mov word ptr [bx + 2], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 105d mov bx, word ptr [0x1ba2]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 1061 mov ax, word ptr [bx + 0x12]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 1064 mov word ptr [bp - 2], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 1067 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 106a and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 106d shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 106f shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1071 shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 1073 mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 1076 add cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1078 mov ax, word ptr [bp - 2]
  R.bx = (u16)(R.cx);                                          // 107b mov bx, cx
  W16(DS, (u16)(R.bx + 0x4), R.ax);                            // 107d mov word ptr [bx + 4], ax
  R.bx = (u16)(M16(DS, (u16)(0x1ba2)));                        // 1080 mov bx, word ptr [0x1ba2]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x14)));                   // 1084 mov ax, word ptr [bx + 0x14]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 1087 mov word ptr [bp - 2], ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 108a mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 108d and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1090 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1092 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 1094 shl ax, 1
  R.cx = (u16)(0x1b46);                                        // 1096 mov cx, 0x1b46
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 1099 add cx, ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 109b mov ax, word ptr [bp - 2]
  R.bx = (u16)(R.cx);                                          // 109e mov bx, cx
  W16(DS, (u16)(R.bx + 0x6), R.ax);                            // 10a0 mov word ptr [bx + 6], ax
L_10a3:   SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 10a3 mov al, byte ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 10a6 and ax, 0xff
  R.cx = (u16)(0x2c);                                          // 10a9 mov cx, 0x2c
  IMUL16(R.cx);                                                // 10ac imul cx
  R.cx = (u16)(0x50);                                          // 10ae mov cx, 0x50
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 10b1 add cx, ax
  R.cx = (u16)(ADD16(R.cx, 0x16));                             // 10b3 add cx, 0x16
  W16(DS, (u16)(0x1ba2), R.cx);                                // 10b6 mov word ptr [0x1ba2], cx
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 10ba mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 10bd and ax, 0xff
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 10c0 shl ax, 1
  R.cx = (u16)(0x196c);                                        // 10c2 mov cx, 0x196c
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 10c5 add cx, ax
  R.bx = (u16)(R.cx);                                          // 10c7 mov bx, cx
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1)));                       // 10c9 mov al, byte ptr [bx + 1]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 10cc cwde
  R.bx = (u16)(R.ax);                                          // 10cd mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1982)));                    // 10cf mov al, byte ptr [bx + 0x1982]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 10d3 cwde
  W16(DS, (u16)(0x1ba0), R.ax);                                // 10d4 mov word ptr [0x1ba0], ax
  SUB16(R.ax, 0x14);                                           // 10d7 cmp ax, 0x14
  if (!R.cf) goto L_10df;                                      // 10da jae 0x10df
  PUSH(0x10df); goto L_0fb0;                                   // 10dc call 0xfb0
L_10df:   R.di = POP();                                                // 10df pop di
  R.si = POP();                                                // 10e0 pop si
  R.sp = (u16)(R.bp);                                          // 10e1 mov sp, bp
  R.bp = POP();                                                // 10e3 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 10e4 ret
L_10e6:   PUSH(R.bp);                                                  // 10e6 push bp
  R.bp = (u16)(R.sp);                                          // 10e7 mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x6));                              // 10e9 sub sp, 6
  PUSH(R.si);                                                  // 10ed push si
  PUSH(R.di);                                                  // 10ee push di
  W8(SS, (u16)(R.bp + 0xfffc), 0x0);                           // 10ef mov byte ptr [bp - 4], 0
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 10f3 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 10f6 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 10f8 and ax, 0xff
  if (!R.zf) goto L_1100;                                      // 10fb jne 0x1100
  goto L_1428;                                                 // 10fd jmp 0x1428
L_1100:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1100 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x7)));                       // 1103 mov al, byte ptr [bx + 7]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1106 and ax, 0xff
  if (R.zf) goto L_1126;                                       // 1109 je 0x1126
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 110b mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x7), DEC8(M8(DS, (u16)(R.bx + 0x7))));  // 110e dec byte ptr [bx + 7]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x7)));                       // 1111 mov al, byte ptr [bx + 7]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1114 and ax, 0xff
  if (!R.zf) goto L_1126;                                      // 1117 jne 0x1126
  SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 1119 mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 111c and ax, 0xff
  PUSH(R.ax);                                                  // 111f push ax
  PUSH(0x1123); goto L_0b6c;                                   // 1120 call 0xb6c
L_1123:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1123 add sp, 2
L_1126:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1126 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx), DEC8(M8(DS, (u16)(R.bx))));              // 1129 dec byte ptr [bx]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 112b mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 112d and ax, 0xff
  if (R.cf || R.zf) goto L_1135;                               // 1130 jbe 0x1135
  goto L_1428;                                                 // 1132 jmp 0x1428
L_1135:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1135 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 1138 mov ax, word ptr [bx + 0xc]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 113b mov word ptr [bp - 2], ax
  R.bx = (u16)(R.ax);                                          // 113e mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1140 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1142 cwde
  R.ax = (u16)(AND16(R.ax, 0x80));                             // 1143 and ax, 0x80
  if (!R.zf) goto L_114b;                                      // 1146 jne 0x114b
  goto L_139a;                                                 // 1148 jmp 0x139a
L_114b:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 114b mov bx, word ptr [bp - 2]
  SUB8(M8(DS, (u16)(R.bx)), 0xf7);                             // 114e cmp byte ptr [bx], 0xf7
  if (!R.zf && R.sf == R.of) goto L_1156;                      // 1151 jg 0x1156
  goto L_139a;                                                 // 1153 jmp 0x139a
L_1156:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1156 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1159 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 115b cwde
  goto L_135a;                                                 // 115c jmp 0x135a
L_1160:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1160 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x12)), 0x0);                     // 1163 cmp word ptr [bx + 0x12], 0
  if (R.zf) goto L_116c;                                       // 1167 je 0x116c
  goto L_11ae;                                                 // 1169 jmp 0x11ae
L_116c:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 116c inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 116f mov bx, word ptr [bp - 2]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 1172 cmp byte ptr [bx], 0
  if (!R.zf) goto L_1194;                                      // 1175 jne 0x1194
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1177 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 117a add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 117e mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 1181 mov ax, word ptr [bx + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1184 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xe), R.ax);                            // 1187 mov word ptr [bx + 0xe], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 118a mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), 0x0);                            // 118d mov word ptr [bx + 0x12], 0
  goto L_11ac;                                                 // 1192 jmp 0x11ac
L_1194:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 1194 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1197 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1199 cwde
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 119a mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 119d mov word ptr [bx + 0x12], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11a0 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xe)));                    // 11a3 mov ax, word ptr [bx + 0xe]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11a6 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), R.ax);                            // 11a9 mov word ptr [bx + 0xc], ax
L_11ac:   goto L_11de;                                                 // 11ac jmp 0x11de
L_11ae:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11ae mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), DEC16(M16(DS, (u16)(R.bx + 0x12)))); // 11b1 dec word ptr [bx + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11b4 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x12)), 0x0);                     // 11b7 cmp word ptr [bx + 0x12], 0
  if (!R.zf) goto L_11d2;                                      // 11bb jne 0x11d2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11bd mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 11c0 add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11c4 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 11c7 mov ax, word ptr [bx + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11ca mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xe), R.ax);                            // 11cd mov word ptr [bx + 0xe], ax
  goto L_11de;                                                 // 11d0 jmp 0x11de
L_11d2:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11d2 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xe)));                    // 11d5 mov ax, word ptr [bx + 0xe]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11d8 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), R.ax);                            // 11db mov word ptr [bx + 0xc], ax
L_11de:   goto L_1397;                                                 // 11de jmp 0x1397
L_11e2:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11e2 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x14)), 0x0);                     // 11e5 cmp word ptr [bx + 0x14], 0
  if (R.zf) goto L_11ee;                                       // 11e9 je 0x11ee
  goto L_123a;                                                 // 11eb jmp 0x123a
L_11ee:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 11ee inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 11f1 mov bx, word ptr [bp - 2]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 11f4 cmp byte ptr [bx], 0
  if (!R.zf) goto L_121e;                                      // 11f7 jne 0x121e
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 11f9 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 11fc add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1200 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 1203 mov ax, word ptr [bx + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1206 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 1209 mov word ptr [bx + 0x10], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 120c mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), 0x0);                            // 120f mov word ptr [bx + 0x12], 0
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1214 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x14), 0x0);                            // 1217 mov word ptr [bx + 0x14], 0
  goto L_1236;                                                 // 121c jmp 0x1236
L_121e:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 121e mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1221 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1223 cwde
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1224 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x14), R.ax);                           // 1227 mov word ptr [bx + 0x14], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 122a mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x10)));                   // 122d mov ax, word ptr [bx + 0x10]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1230 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), R.ax);                            // 1233 mov word ptr [bx + 0xc], ax
L_1236:   goto L_1276;                                                 // 1236 jmp 0x1276
L_123a:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 123a mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x14), DEC16(M16(DS, (u16)(R.bx + 0x14)))); // 123d dec word ptr [bx + 0x14]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1240 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x14)), 0x0);                     // 1243 cmp word ptr [bx + 0x14], 0
  if (!R.zf) goto L_126a;                                      // 1247 jne 0x126a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1249 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 124c add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1250 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 1253 mov ax, word ptr [bx + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1256 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 1259 mov word ptr [bx + 0x10], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 125c mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 125f mov ax, word ptr [bx + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1262 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xe), R.ax);                            // 1265 mov word ptr [bx + 0xe], ax
  goto L_1276;                                                 // 1268 jmp 0x1276
L_126a:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 126a mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x10)));                   // 126d mov ax, word ptr [bx + 0x10]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1270 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), R.ax);                            // 1273 mov word ptr [bx + 0xc], ax
L_1276:   goto L_1397;                                                 // 1276 jmp 0x1397
L_127a:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 127a mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x16)), 0x0);                     // 127d cmp word ptr [bx + 0x16], 0
  if (!R.zf) goto L_1292;                                      // 1281 jne 0x1292
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1283 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xa)));                    // 1286 mov ax, word ptr [bx + 0xa]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1289 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), R.ax);                            // 128c mov word ptr [bx + 0xc], ax
  goto L_1298;                                                 // 128f jmp 0x1298
L_1292:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1292 mov bx, word ptr [bp + 4]
  { u16 t_ = M16(DS, (u16)(R.bx + 0x16)); PUSH(0x1298); ip_ = t_; goto dispatch_; } // 1295 call word ptr [bx + 0x16]
L_1298:   goto L_1397;                                                 // 1298 jmp 0x1397
L_129c:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 129c inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 129f mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 12a2 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12a4 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x4), (u8)R.ax);                         // 12a7 mov byte ptr [bx + 4], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12aa mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 12ad add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12b1 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x4)));                       // 12b4 mov al, byte ptr [bx + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 12b7 and ax, 0xff
  PUSH(R.ax);                                                  // 12ba push ax
  SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 12bb mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 12be and ax, 0xff
  PUSH(R.ax);                                                  // 12c1 push ax
  PUSH(0x12c5); goto L_0fca;                                   // 12c2 call 0xfca
L_12c5:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 12c5 add sp, 4
  goto L_1397;                                                 // 12c8 jmp 0x1397
L_12cc:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 12cc inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 12cf mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 12d2 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12d4 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x6), (u8)R.ax);                         // 12d7 mov byte ptr [bx + 6], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12da mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 12dd add word ptr [bx + 0xc], 2
  goto L_1397;                                                 // 12e1 jmp 0x1397
L_12e4:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 12e4 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 12e7 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 12ea mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12ec mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 12ef mov byte ptr [bx + 1], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 12f2 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 12f5 add word ptr [bx + 0xc], 2
  goto L_1397;                                                 // 12f9 jmp 0x1397
L_12fc:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 12fc inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 12ff mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1302 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1304 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x5), (u8)R.ax);                         // 1307 mov byte ptr [bx + 5], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 130a mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 130d add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1311 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x5)));                       // 1314 mov al, byte ptr [bx + 5]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1317 and ax, 0xff
  PUSH(R.ax);                                                  // 131a push ax
  SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 131b mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 131e and ax, 0xff
  PUSH(R.ax);                                                  // 1321 push ax
  PUSH(0x1325); goto L_0962;                                   // 1322 call 0x962
L_1325:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1325 add sp, 4
  goto L_1397;                                                 // 1328 jmp 0x1397
L_132c:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 132c inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 132f mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1332 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1334 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x9), (u8)R.ax);                         // 1337 mov byte ptr [bx + 9], al
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 133a inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 133d mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1340 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1342 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 1345 mov byte ptr [bx + 2], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1348 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x8), 0x1);                              // 134b mov byte ptr [bx + 8], 1
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 134f mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x3)); // 1352 add word ptr [bx + 0xc], 3
  goto L_1397;                                                 // 1356 jmp 0x1397
L_135a:   SUB16(R.ax, 0xfff8);                                         // 135a cmp ax, 0xfff8
  if (R.zf) goto L_132c;                                       // 135d je 0x132c
  SUB16(R.ax, 0xfff9);                                         // 135f cmp ax, 0xfff9
  if (!R.zf) goto L_1367;                                      // 1362 jne 0x1367
  goto L_12fc;                                                 // 1364 jmp 0x12fc
L_1367:   SUB16(R.ax, 0xfffa);                                         // 1367 cmp ax, 0xfffa
  if (!R.zf) goto L_136f;                                      // 136a jne 0x136f
  goto L_12e4;                                                 // 136c jmp 0x12e4
L_136f:   SUB16(R.ax, 0xfffb);                                         // 136f cmp ax, 0xfffb
  if (!R.zf) goto L_1377;                                      // 1372 jne 0x1377
  goto L_12cc;                                                 // 1374 jmp 0x12cc
L_1377:   SUB16(R.ax, 0xfffc);                                         // 1377 cmp ax, 0xfffc
  if (!R.zf) goto L_137f;                                      // 137a jne 0x137f
  goto L_129c;                                                 // 137c jmp 0x129c
L_137f:   SUB16(R.ax, 0xfffd);                                         // 137f cmp ax, 0xfffd
  if (!R.zf) goto L_1387;                                      // 1382 jne 0x1387
  goto L_127a;                                                 // 1384 jmp 0x127a
L_1387:   SUB16(R.ax, 0xfffe);                                         // 1387 cmp ax, 0xfffe
  if (!R.zf) goto L_138f;                                      // 138a jne 0x138f
  goto L_11e2;                                                 // 138c jmp 0x11e2
L_138f:   SUB16(R.ax, 0xffff);                                         // 138f cmp ax, 0xffff
  if (!R.zf) goto L_1397;                                      // 1392 jne 0x1397
  goto L_1160;                                                 // 1394 jmp 0x1160
L_1397:   goto L_1135;                                                 // 1397 jmp 0x1135
L_139a:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 139a mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0xc)));                    // 139d mov ax, word ptr [bx + 0xc]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 13a0 mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 13a3 mov bx, word ptr [bp - 2]
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 13a6 inc word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 13a9 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13ab mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 13ae mov byte ptr [bx], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 13b0 mov bx, word ptr [bp - 2]
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 13b3 inc word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 13b6 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13b8 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x3), (u8)R.ax);                         // 13bb mov byte ptr [bx + 3], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13be mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0xc), ADD16(M16(DS, (u16)(R.bx + 0xc)), 0x2)); // 13c1 add word ptr [bx + 0xc], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13c5 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x3)));                       // 13c8 mov al, byte ptr [bx + 3]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 13cb and ax, 0xff
  if (R.zf) goto L_13da;                                       // 13ce je 0x13da
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13d0 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 13d3 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 13d5 and ax, 0xff
  if (!R.zf) goto L_13ea;                                      // 13d8 jne 0x13ea
L_13da:   SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 13da mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 13dd and ax, 0xff
  PUSH(R.ax);                                                  // 13e0 push ax
  PUSH(0x13e4); goto L_0b6c;                                   // 13e1 call 0xb6c
L_13e4:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 13e4 add sp, 2
  goto L_1428;                                                 // 13e7 jmp 0x1428
L_13ea:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13ea mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 13ed mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 13ef and ax, 0xff
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 13f2 mov bx, word ptr [bp + 4]
  W16(SS, (u16)(R.bp + 0xfffa), R.ax);                         // 13f5 mov word ptr [bp - 6], ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x6)));                       // 13f8 mov al, byte ptr [bx + 6]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 13fb cwde
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xfffa)));                 // 13fc mov cx, word ptr [bp - 6]
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 13ff sub cx, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1401 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x7), (u8)R.cx);                         // 1404 mov byte ptr [bx + 7], cl
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1407 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x5)));                       // 140a mov al, byte ptr [bx + 5]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 140d and ax, 0xff
  PUSH(R.ax);                                                  // 1410 push ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1411 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x3)));                       // 1414 mov al, byte ptr [bx + 3]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1417 and ax, 0xff
  PUSH(R.ax);                                                  // 141a push ax
  SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 141b mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 141e and ax, 0xff
  PUSH(R.ax);                                                  // 1421 push ax
  PUSH(0x1425); goto L_0be8;                                   // 1422 call 0xbe8
L_1425:   R.sp = (u16)(ADD16(R.sp, 0x6));                              // 1425 add sp, 6
L_1428:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1428 mov bx, word ptr [bp + 4]
  SUB8(M8(DS, (u16)(R.bx + 0x1)), 0x0);                        // 142b cmp byte ptr [bx + 1], 0
  if (R.zf) goto L_1446;                                       // 142f je 0x1446
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1431 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1)));                       // 1434 mov al, byte ptr [bx + 1]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 1437 cwde
  PUSH(R.ax);                                                  // 1438 push ax
  SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 1439 mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 143c and ax, 0xff
  PUSH(R.ax);                                                  // 143f push ax
  PUSH(0x1443); goto L_0a6a;                                   // 1440 call 0xa6a
L_1443:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1443 add sp, 4
L_1446:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1446 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x8)));                       // 1449 mov al, byte ptr [bx + 8]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 144c and ax, 0xff
  if (!R.zf) goto L_1454;                                      // 144f jne 0x1454
  goto L_149a;                                                 // 1451 jmp 0x149a
L_1454:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1454 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x8), DEC8(M8(DS, (u16)(R.bx + 0x8))));  // 1457 dec byte ptr [bx + 8]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x8)));                       // 145a mov al, byte ptr [bx + 8]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 145d and ax, 0xff
  if (!R.zf) goto L_149a;                                      // 1460 jne 0x149a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1462 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x9)));                       // 1465 mov al, byte ptr [bx + 9]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1468 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x8), (u8)R.ax);                         // 146b mov byte ptr [bx + 8], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 146e mov bx, word ptr [bp + 4]
  SUB8(M8(DS, (u16)(R.bx + 0x2)), 0x0);                        // 1471 cmp byte ptr [bx + 2], 0
  if (R.zf) goto L_149a;                                       // 1475 je 0x149a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1477 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x2)));                       // 147a mov al, byte ptr [bx + 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 147d mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x5), ADD8(M8(DS, (u16)(R.bx + 0x5)), (u8)R.ax)); // 1480 add byte ptr [bx + 5], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 1483 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x5)));                       // 1486 mov al, byte ptr [bx + 5]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1489 and ax, 0xff
  PUSH(R.ax);                                                  // 148c push ax
  SETL(R.ax, M8(DS, (u16)(0x1a42)));                           // 148d mov al, byte ptr [0x1a42]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 1490 and ax, 0xff
  PUSH(R.ax);                                                  // 1493 push ax
  PUSH(0x1497); goto L_0962;                                   // 1494 call 0x962
L_1497:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 1497 add sp, 4
L_149a:   W8(DS, (u16)(0x1a42), INC8(M8(DS, (u16)(0x1a42))));          // 149a inc byte ptr [0x1a42]
  R.di = POP();                                                // 149e pop di
  R.si = POP();                                                // 149f pop si
  R.sp = (u16)(R.bp);                                          // 14a0 mov sp, bp
  R.bp = POP();                                                // 14a2 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 14a3 ret
L_14a4:   SUB8(M8(DS, (u16)(0x19aa)), 0x0);                            // 14a4 cmp byte ptr [0x19aa], 0
  if (!R.zf) goto L_14ae;                                      // 14a9 jne 0x14ae
  goto L_14ef;                                                 // 14ab jmp 0x14ef
L_14ae:   W8(DS, (u16)(0x1a42), 0x0);                                  // 14ae mov byte ptr [0x1a42], 0
  R.ax = (u16)(0x19ac);                                        // 14b3 mov ax, 0x19ac
  PUSH(R.ax);                                                  // 14b6 push ax
  PUSH(0x14ba); goto L_10e6;                                   // 14b7 call 0x10e6
L_14ba:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14ba add sp, 2
  R.ax = (u16)(0x19c4);                                        // 14bd mov ax, 0x19c4
  PUSH(R.ax);                                                  // 14c0 push ax
  PUSH(0x14c4); goto L_10e6;                                   // 14c1 call 0x10e6
L_14c4:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14c4 add sp, 2
  R.ax = (u16)(0x19dc);                                        // 14c7 mov ax, 0x19dc
  PUSH(R.ax);                                                  // 14ca push ax
  PUSH(0x14ce); goto L_10e6;                                   // 14cb call 0x10e6
L_14ce:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14ce add sp, 2
  R.ax = (u16)(0x19f4);                                        // 14d1 mov ax, 0x19f4
  PUSH(R.ax);                                                  // 14d4 push ax
  PUSH(0x14d8); goto L_10e6;                                   // 14d5 call 0x10e6
L_14d8:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14d8 add sp, 2
  R.ax = (u16)(0x1a0c);                                        // 14db mov ax, 0x1a0c
  PUSH(R.ax);                                                  // 14de push ax
  PUSH(0x14e2); goto L_10e6;                                   // 14df call 0x10e6
L_14e2:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14e2 add sp, 2
  R.ax = (u16)(0x1a24);                                        // 14e5 mov ax, 0x1a24
  PUSH(R.ax);                                                  // 14e8 push ax
  PUSH(0x14ec); goto L_10e6;                                   // 14e9 call 0x10e6
L_14ec:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 14ec add sp, 2
L_14ef:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 14ef ret
}

// the driver's slots: slot 0 + k runs the k-th entry, with the caller's far return address on the stack
void as_slot(int slot)
{
  static const u16 entries[] = { 0x0859, 0x0868, 0x0886, 0x089a, 0x08a7, 0x0926, 0x0935 };
  if (slot >= 0 && slot < 7) as_0000_run(entries[slot - 0]);
}
