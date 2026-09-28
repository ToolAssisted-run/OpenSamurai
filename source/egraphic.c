#include "asm2c.h"

// EG: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void eg_0000_run(u16 entry);

void eg_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0x4887;
dispatch_:
  switch (ip_)
  {
  case 0x0092: goto L_0092;
  case 0x00b1: goto L_00b1;
  case 0x0124: goto L_0124;
  case 0x013c: goto L_013c;
  case 0x0144: goto L_0144;
  case 0x0166: goto L_0166;
  case 0x017f: goto L_017f;
  case 0x0188: goto L_0188;
  case 0x01a2: goto L_01a2;
  case 0x01ab: goto L_01ab;
  case 0x01b2: goto L_01b2;
  case 0x01d5: goto L_01d5;
  case 0x01ea: goto L_01ea;
  case 0x01eb: goto L_01eb;
  case 0x0230: goto L_0230;
  case 0x024f: goto L_024f;
  case 0x0256: goto L_0256;
  case 0x027b: goto L_027b;
  case 0x0282: goto L_0282;
  case 0x0288: goto L_0288;
  case 0x028e: goto L_028e;
  case 0x0294: goto L_0294;
  case 0x02ac: goto L_02ac;
  case 0x02ae: goto L_02ae;
  case 0x02b3: goto L_02b3;
  case 0x02b6: goto L_02b6;
  case 0x02b7: goto L_02b7;
  case 0x02d0: goto L_02d0;
  case 0x02d6: goto L_02d6;
  case 0x02dc: goto L_02dc;
  case 0x02e2: goto L_02e2;
  case 0x02ea: goto L_02ea;
  case 0x02f0: goto L_02f0;
  case 0x02f6: goto L_02f6;
  case 0x02fc: goto L_02fc;
  case 0x0316: goto L_0316;
  case 0x031b: goto L_031b;
  case 0x036c: goto L_036c;
  case 0x036e: goto L_036e;
  case 0x036f: goto L_036f;
  case 0x039c: goto L_039c;
  case 0x03be: goto L_03be;
  case 0x03c8: goto L_03c8;
  case 0x0418: goto L_0418;
  case 0x0432: goto L_0432;
  case 0x043d: goto L_043d;
  case 0x0454: goto L_0454;
  case 0x0462: goto L_0462;
  case 0x046c: goto L_046c;
  case 0x047c: goto L_047c;
  case 0x0489: goto L_0489;
  case 0x04b0: goto L_04b0;
  case 0x04cb: goto L_04cb;
  case 0x04ce: goto L_04ce;
  case 0x04db: goto L_04db;
  case 0x04f1: goto L_04f1;
  case 0x04fe: goto L_04fe;
  case 0x050b: goto L_050b;
  case 0x0516: goto L_0516;
  case 0x051b: goto L_051b;
  case 0x0539: goto L_0539;
  case 0x053e: goto L_053e;
  case 0x055e: goto L_055e;
  case 0x0574: goto L_0574;
  case 0x0585: goto L_0585;
  case 0x0588: goto L_0588;
  case 0x0590: goto L_0590;
  case 0x05b6: goto L_05b6;
  case 0x05e0: goto L_05e0;
  case 0x05e7: goto L_05e7;
  case 0x05fc: goto L_05fc;
  case 0x0613: goto L_0613;
  case 0x061e: goto L_061e;
  case 0x0631: goto L_0631;
  case 0x063e: goto L_063e;
  case 0x0640: goto L_0640;
  case 0x0654: goto L_0654;
  case 0x065d: goto L_065d;
  case 0x0660: goto L_0660;
  case 0x0671: goto L_0671;
  case 0x0673: goto L_0673;
  case 0x0687: goto L_0687;
  case 0x068c: goto L_068c;
  case 0x06a5: goto L_06a5;
  case 0x06a6: goto L_06a6;
  case 0x06cd: goto L_06cd;
  case 0x06d8: goto L_06d8;
  case 0x0715: goto L_0715;
  case 0x071d: goto L_071d;
  case 0x0732: goto L_0732;
  case 0x0740: goto L_0740;
  case 0x0743: goto L_0743;
  case 0x0790: goto L_0790;
  case 0x081b: goto L_081b;
  case 0x081e: goto L_081e;
  case 0x083f: goto L_083f;
  case 0x0866: goto L_0866;
  case 0x0883: goto L_0883;
  case 0x0888: goto L_0888;
  case 0x088e: goto L_088e;
  case 0x08b6: goto L_08b6;
  case 0x08c2: goto L_08c2;
  case 0x08c8: goto L_08c8;
  case 0x08e6: goto L_08e6;
  case 0x090d: goto L_090d;
  case 0x092b: goto L_092b;
  case 0x0932: goto L_0932;
  case 0x0938: goto L_0938;
  case 0x0966: goto L_0966;
  case 0x0992: goto L_0992;
  case 0x09b0: goto L_09b0;
  case 0x09b3: goto L_09b3;
  case 0x09da: goto L_09da;
  case 0x09fa: goto L_09fa;
  case 0x0a6b: goto L_0a6b;
  case 0x0a70: goto L_0a70;
  case 0x0a7c: goto L_0a7c;
  case 0x0a80: goto L_0a80;
  case 0x0a97: goto L_0a97;
  case 0x0ab0: goto L_0ab0;
  case 0x0ab4: goto L_0ab4;
  case 0x0ab8: goto L_0ab8;
  case 0x0acb: goto L_0acb;
  case 0x0ad7: goto L_0ad7;
  case 0x0af4: goto L_0af4;
  case 0x0b2a: goto L_0b2a;
  case 0x0b52: goto L_0b52;
  case 0x0b6f: goto L_0b6f;
  case 0x0bae: goto L_0bae;
  case 0x0bba: goto L_0bba;
  case 0x0bcb: goto L_0bcb;
  case 0x0be2: goto L_0be2;
  case 0x0be7: goto L_0be7;
  case 0x0bf9: goto L_0bf9;
  case 0x0c13: goto L_0c13;
  case 0x0c23: goto L_0c23;
  case 0x0c27: goto L_0c27;
  case 0x0c4d: goto L_0c4d;
  case 0x0c69: goto L_0c69;
  case 0x0c83: goto L_0c83;
  case 0x0c89: goto L_0c89;
  case 0x0c98: goto L_0c98;
  case 0x0c9d: goto L_0c9d;
  case 0x0d9b: goto L_0d9b;
  case 0x0da5: goto L_0da5;
  case 0x0da9: goto L_0da9;
  case 0x0daa: goto L_0daa;
  case 0x0dc3: goto L_0dc3;
  case 0x0dc8: goto L_0dc8;
  case 0x0dff: goto L_0dff;
  case 0x0e17: goto L_0e17;
  case 0x0e27: goto L_0e27;
  case 0x0e3f: goto L_0e3f;
  case 0x0e79: goto L_0e79;
  case 0x0e7f: goto L_0e7f;
  case 0x0e98: goto L_0e98;
  case 0x0e9d: goto L_0e9d;
  case 0x0eaf: goto L_0eaf;
  case 0x0ee6: goto L_0ee6;
  case 0x0f01: goto L_0f01;
  case 0x0f5a: goto L_0f5a;
  case 0x0f65: goto L_0f65;
  case 0x0f71: goto L_0f71;
  case 0x0f90: goto L_0f90;
  case 0x0f94: goto L_0f94;
  case 0x0fd1: goto L_0fd1;
  case 0x0fe0: goto L_0fe0;
  case 0x0fe5: goto L_0fe5;
  case 0x0ff5: goto L_0ff5;
  case 0x0ffa: goto L_0ffa;
  case 0x1011: goto L_1011;
  case 0x1017: goto L_1017;
  case 0x1019: goto L_1019;
  case 0x1028: goto L_1028;
  case 0x1043: goto L_1043;
  case 0x1076: goto L_1076;
  case 0x109e: goto L_109e;
  case 0x10a7: goto L_10a7;
  case 0x10ae: goto L_10ae;
  case 0x10b1: goto L_10b1;
  case 0x10e4: goto L_10e4;
  case 0x110c: goto L_110c;
  case 0x1115: goto L_1115;
  case 0x111c: goto L_111c;
  case 0x111f: goto L_111f;
  case 0x1130: goto L_1130;
  case 0x1158: goto L_1158;
  case 0x1161: goto L_1161;
  case 0x1168: goto L_1168;
  case 0x116c: goto L_116c;
  case 0x1191: goto L_1191;
  case 0x11ad: goto L_11ad;
  case 0x11bd: goto L_11bd;
  case 0x11cd: goto L_11cd;
  case 0x11e1: goto L_11e1;
  case 0x11eb: goto L_11eb;
  case 0x122a: goto L_122a;
  case 0x1232: goto L_1232;
  case 0x123a: goto L_123a;
  case 0x123c: goto L_123c;
  case 0x1248: goto L_1248;
  case 0x124b: goto L_124b;
  case 0x1268: goto L_1268;
  case 0x126a: goto L_126a;
  case 0x126c: goto L_126c;
  case 0x1279: goto L_1279;
  case 0x12cd: goto L_12cd;
  case 0x12f4: goto L_12f4;
  case 0x12fc: goto L_12fc;
  case 0x1338: goto L_1338;
  case 0x135b: goto L_135b;
  case 0x1369: goto L_1369;
  case 0x1389: goto L_1389;
  case 0x13c3: goto L_13c3;
  case 0x13d4: goto L_13d4;
  case 0x141e: goto L_141e;
  case 0x1423: goto L_1423;
  case 0x146a: goto L_146a;
  case 0x1470: goto L_1470;
  case 0x1492: goto L_1492;
  case 0x1495: goto L_1495;
  case 0x14ab: goto L_14ab;
  case 0x14af: goto L_14af;
  case 0x14b2: goto L_14b2;
  case 0x14b5: goto L_14b5;
  case 0x14b8: goto L_14b8;
  case 0x14bb: goto L_14bb;
  case 0x14be: goto L_14be;
  case 0x14c1: goto L_14c1;
  case 0x14c4: goto L_14c4;
  case 0x14c7: goto L_14c7;
  case 0x14ed: goto L_14ed;
  case 0x14f1: goto L_14f1;
  case 0x14fb: goto L_14fb;
  case 0x14ff: goto L_14ff;
  case 0x1500: goto L_1500;
  case 0x1503: goto L_1503;
  case 0x1506: goto L_1506;
  case 0x1509: goto L_1509;
  case 0x152a: goto L_152a;
  case 0x154c: goto L_154c;
  case 0x154d: goto L_154d;
  case 0x1551: goto L_1551;
  case 0x1554: goto L_1554;
  case 0x1557: goto L_1557;
  case 0x155a: goto L_155a;
  case 0x157e: goto L_157e;
  case 0x1592: goto L_1592;
  case 0x1593: goto L_1593;
  case 0x1597: goto L_1597;
  case 0x159a: goto L_159a;
  case 0x15af: goto L_15af;
  case 0x15bd: goto L_15bd;
  case 0x15c6: goto L_15c6;
  case 0x160a: goto L_160a;
  case 0x161e: goto L_161e;
  case 0x164a: goto L_164a;
  default: asm_unknown_call(0x4887, ip_); return;
  }
L_0092:   PUSH(R.bp);                                                  // 0092 push bp
  R.bp = (u16)(R.sp);                                          // 0093 mov bp, sp
  PUSH(R.si);                                                  // 0095 push si
  PUSH(R.di);                                                  // 0096 push di
  PUSH(R.ds);                                                  // 0097 push ds
  PUSH(R.es);                                                  // 0098 push es
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0099 mov si, word ptr [bp + 6]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 009c mov di, word ptr [bp + 0xc]
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 009f mov dx, word ptr [bp + 8]
  R.dx = (u16)(ADD16(R.dx, M16(DS, (u16)(R.si + 0x2))));       // 00a2 add dx, word ptr [si + 2]
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 00a5 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_00b1;                                      // 00ab jne 0xb1
  R.dx = (u16)(SHL16(R.dx, 0x1));                              // 00ad shl dx, 1
  R.di = (u16)(SHL16(R.di, 0x1));                              // 00af shl di, 1
L_00b1:   R.di = (u16)(ADD16(R.di, R.dx));                             // 00b1 add di, dx
  R.di = (u16)(DEC16(R.di));                                   // 00b3 dec di
  R.ax = (u16)(R.di);                                          // 00b4 mov ax, di
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 00b6 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 00b8 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 00ba shr ax, 1
  R.bx = (u16)(R.dx);                                          // 00bc mov bx, dx
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 00be shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 00c0 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 00c2 shr bx, 1
  R.ax = (u16)(SUB16(R.ax, R.bx));                             // 00c4 sub ax, bx
  R.ax = (u16)(INC16(R.ax));                                   // 00c6 inc ax
  R.bx = (u16)(0xff80);                                        // 00c7 mov bx, 0xff80
  R.cx = (u16)(R.dx);                                          // 00ca mov cx, dx
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 00cc and cl, 7
  SETH(R.bx, SHR8((u8)(R.bx >> 8), (u8)R.cx));                 // 00cf shr bh, cl
  R.cx = (u16)(R.di);                                          // 00d1 mov cx, di
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 00d3 and cl, 7
  SETL(R.bx, SAR8((u8)R.bx, (u8)R.cx));                        // 00d6 sar bl, cl
  R.cx = (u16)(R.ax);                                          // 00d8 mov cx, ax
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 00da mov di, word ptr [bp + 0xa]
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(R.si + 0x4))));       // 00dd add di, word ptr [si + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 00e0 shl di, 1
  R.di = (u16)(M16(CS, (u16)(R.di + 0x192e)));                 // 00e2 mov di, word ptr cs:[di + 0x192e]
  R.dx = (u16)(SHR16(R.dx, 0x1));                              // 00e7 shr dx, 1
  R.dx = (u16)(SHR16(R.dx, 0x1));                              // 00e9 shr dx, 1
  R.dx = (u16)(SHR16(R.dx, 0x1));                              // 00eb shr dx, 1
  R.di = (u16)(ADD16(R.di, R.dx));                             // 00ed add di, dx
  // 00ef cli 
  R.dx = (u16)(0x3c4);                                         // 00f0 mov dx, 0x3c4
  R.ax = (u16)(0xf02);                                         // 00f3 mov ax, 0xf02
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 00f6 out dx, ax
  R.dx = (u16)(0x3ce);                                         // 00f7 mov dx, 0x3ce
  SETH(R.ax, M8(SS, (u16)(R.bp + 0x10)));                      // 00fa mov ah, byte ptr [bp + 0x10]
  SETL(R.ax, 0x2);                                             // 00fd mov al, 2
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 00ff out dx, ax
  SETH(R.ax, M8(SS, (u16)(R.bp + 0x12)));                      // 0100 mov ah, byte ptr [bp + 0x12]
  SETL(R.ax, 0x0);                                             // 0103 mov al, 0
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0105 out dx, ax
  R.ax = (u16)(0xff01);                                        // 0106 mov ax, 0xff01
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0109 out dx, ax
  R.ax = (u16)(0x805);                                         // 010a mov ax, 0x805
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 010d out dx, ax
  SETL(R.ax, 0x8);                                             // 010e mov al, 8
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0110 out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 0111 inc dx
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 0112 mov bp, word ptr [bp + 0xe]
  R.si = (u16)(M16(DS, (u16)(R.si)));                          // 0115 mov si, word ptr [si]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0117 shl si, 1
  R.si = (u16)(M16(CS, (u16)(R.si + 0x1c58)));                 // 0119 mov si, word ptr cs:[si + 0x1c58]
  R.ds = (u16)(R.si);                                          // 011e mov ds, si
  R.es = (u16)(R.si);                                          // 0120 mov es, si
  R.si = (u16)(R.di);                                          // 0122 mov si, di
L_0124:   R.di = (u16)(R.si);                                          // 0124 mov di, si
  SETH(R.cx, (u8)R.cx);                                        // 0126 mov ch, cl
  SETH(R.ax, (u8)(R.bx >> 8));                                 // 0128 mov ah, bh
  SETH(R.ax, AND8((u8)(R.ax >> 8), (u8)R.bx));                 // 012a and ah, bl
  SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 012c dec ch
  if (R.zf) goto L_0144;                                       // 012e je 0x144
  SETL(R.ax, M8(DS, (u16)(R.di)));                             // 0130 mov al, byte ptr [di]
  SETL(R.ax, AND8((u8)R.ax, (u8)(R.bx >> 8)));                 // 0132 and al, bh
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0134 out dx, al
  STOSB();                                                     // 0135 stosb byte ptr es:[di], al
  SETH(R.ax, (u8)R.bx);                                        // 0136 mov ah, bl
  SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 0138 dec ch
  if (R.zf) goto L_0144;                                       // 013a je 0x144
L_013c:   SETL(R.ax, M8(DS, (u16)(R.di)));                             // 013c mov al, byte ptr [di]
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 013e out dx, al
  STOSB();                                                     // 013f stosb byte ptr es:[di], al
  SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 0140 dec ch
  if (!R.zf) goto L_013c;                                      // 0142 jne 0x13c
L_0144:   SETL(R.ax, M8(DS, (u16)(R.di)));                             // 0144 mov al, byte ptr [di]
  SETL(R.ax, AND8((u8)R.ax, (u8)(R.ax >> 8)));                 // 0146 and al, ah
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0148 out dx, al
  STOSB();                                                     // 0149 stosb byte ptr es:[di], al
  R.si = (u16)(ADD16(R.si, M16(CS, (u16)(0x1c70))));           // 014a add si, word ptr cs:[0x1c70]
  R.bp = (u16)(DEC16(R.bp));                                   // 014f dec bp
  if (!R.zf) goto L_0124;                                      // 0150 jne 0x124
  R.dx = (u16)(DEC16(R.dx));                                   // 0152 dec dx
  R.ax = (u16)(0x1);                                           // 0153 mov ax, 1
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0156 out dx, ax
  R.ax = (u16)(0x5);                                           // 0157 mov ax, 5
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 015a out dx, ax
  R.ax = (u16)(0xff08);                                        // 015b mov ax, 0xff08
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 015e out dx, ax
  R.es = POP();                                                // 015f pop es
  R.ds = POP();                                                // 0160 pop ds
  R.di = POP();                                                // 0161 pop di
  R.si = POP();                                                // 0162 pop si
  R.bp = POP();                                                // 0163 pop bp
  // 0164 sti 
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0165 retf
L_0166:   R.bx = (u16)(R.sp);                                          // 0166 mov bx, sp
  PUSH(R.es);                                                  // 0168 push es
  R.ax = (u16)(0x49ec /* segment */);                          // 0169 mov ax, 0x165
  R.es = (u16)(R.ax);                                          // 016c mov es, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x4)));                       // 016e mov al, byte ptr [bx + 4]
  SETH(R.ax, M8(DS, (u16)(R.bx + 0x6)));                       // 0171 mov ah, byte ptr [bx + 6]
  SUB8((u8)(R.ax >> 8), 0x8);                                  // 0174 cmp ah, 8
  if (R.cf) goto L_017f;                                       // 0177 jb 0x17f
  SETH(R.ax, AND8((u8)(R.ax >> 8), 0x7));                      // 0179 and ah, 7
  SETH(R.ax, OR8((u8)(R.ax >> 8), 0x10));                      // 017c or ah, 0x10
L_017f:   R.bx = (u16)(R.ax);                                          // 017f mov bx, ax
  R.ax = (u16)(0x1000);                                        // 0181 mov ax, 0x1000
  ASM_INT(0x10);                                               // 0184 int 0x10
  R.es = POP();                                                // 0186 pop es
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0187 retf
L_0188:   R.bx = (u16)(R.sp);                                          // 0188 mov bx, sp
  PUSH(R.si);                                                  // 018a push si
  PUSH(R.di);                                                  // 018b push di
  PUSH(R.es);                                                  // 018c push es
  R.ax = (u16)(0x49ec /* segment */);                          // 018d mov ax, 0x165
  R.es = (u16)(R.ax);                                          // 0190 mov es, ax
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0192 mov di, word ptr [bx + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0195 shl di, 1
  R.di = (u16)(M16(ES, (u16)(R.di + 0x50)));                   // 0197 mov di, word ptr es:[di + 0x50]
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 019c mov si, word ptr [bx + 6]
  R.cx = (u16)(0x11);                                          // 019f mov cx, 0x11
L_01a2:   LODSB();                                                     // 01a2 lodsb al, byte ptr [si]
  SUB8((u8)R.ax, 0x8);                                         // 01a3 cmp al, 8
  if (R.cf) goto L_01ab;                                       // 01a5 jb 0x1ab
  SETL(R.ax, AND8((u8)R.ax, 0x7));                             // 01a7 and al, 7
  SETL(R.ax, OR8((u8)R.ax, 0x10));                             // 01a9 or al, 0x10
L_01ab:   STOSB();                                                     // 01ab stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_01a2;                                // 01ac loop 0x1a2
  R.es = POP();                                                // 01ae pop es
  R.di = POP();                                                // 01af pop di
  R.si = POP();                                                // 01b0 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 01b1 retf
L_01b2:   R.bx = (u16)(R.sp);                                          // 01b2 mov bx, sp
  PUSH(R.si);                                                  // 01b4 push si
  PUSH(R.es);                                                  // 01b5 push es
  PUSH(R.ds);                                                  // 01b6 push ds
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 01b7 mov si, word ptr [bx + 4]
  R.bx = (u16)(0x49ec /* segment */);                          // 01ba mov bx, 0x165
  R.ds = (u16)(R.bx);                                          // 01bd mov ds, bx
  R.es = (u16)(R.bx);                                          // 01bf mov es, bx
  R.si = (u16)(SHL16(R.si, 0x1));                              // 01c1 shl si, 1
  R.dx = (u16)(M16(DS, (u16)(R.si + 0x50)));                   // 01c3 mov dx, word ptr [si + 0x50]
  R.ax = (u16)(0x1002);                                        // 01c7 mov ax, 0x1002
  ASM_INT(0x10);                                               // 01ca int 0x10
  R.ds = POP();                                                // 01cc pop ds
  R.es = POP();                                                // 01cd pop es
  R.si = POP();                                                // 01ce pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 01cf retf
L_01d5:   R.dx = (u16)(0x3ce);                                         // 01d5 mov dx, 0x3ce
  SETL(R.ax, 0x0);                                             // 01d8 mov al, 0
  W8(CS, (u16)(0x1c79), (u8)(R.ax >> 8));                      // 01da mov byte ptr cs:[0x1c79], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 01df out dx, ax
  R.ax = (u16)(0xff01);                                        // 01e0 mov ax, 0xff01
  W8(CS, (u16)(0x1c75), (u8)(R.ax >> 8));                      // 01e3 mov byte ptr cs:[0x1c75], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 01e8 out dx, ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 01e9 retf
L_01ea:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 01ea retf
L_01eb:   PUSH(R.ds);                                                  // 01eb push ds
  R.ax = (u16)(0x49ec /* segment */);                          // 01ec mov ax, 0x165
  R.ds = (u16)(R.ax);                                          // 01ef mov ds, ax
  R.dx = (u16)(0x3c4);                                         // 01f1 mov dx, 0x3c4
  R.ax = (u16)(0xf02);                                         // 01f4 mov ax, 0xf02
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 01f7 mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 01fc out dx, ax
  R.dx = (u16)(0x3ce);                                         // 01fd mov dx, 0x3ce
  R.ax = (u16)(0x1);                                           // 0200 mov ax, 1
  W8(CS, (u16)(0x1c75), (u8)(R.ax >> 8));                      // 0203 mov byte ptr cs:[0x1c75], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0208 out dx, ax
  R.ax = (u16)(0xff08);                                        // 0209 mov ax, 0xff08
  W8(CS, (u16)(0x1c72), (u8)(R.ax >> 8));                      // 020c mov byte ptr cs:[0x1c72], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0211 out dx, ax
  R.ax = (u16)(0x5);                                           // 0212 mov ax, 5
  W8(CS, (u16)(0x1c77), (u8)(R.ax >> 8));                      // 0215 mov byte ptr cs:[0x1c77], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 021a out dx, ax
  R.ax = (u16)(0x3);                                           // 021b mov ax, 3
  W8(CS, (u16)(0x1c74), (u8)(R.ax >> 8));                      // 021e mov byte ptr cs:[0x1c74], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0223 out dx, ax
  R.ax = (u16)(0x4);                                           // 0224 mov ax, 4
  W8(CS, (u16)(0x1c78), (u8)(R.ax >> 8));                      // 0227 mov byte ptr cs:[0x1c78], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 022c out dx, ax
  R.ds = POP();                                                // 022d pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 022e retf
L_0230:   R.bx = (u16)(R.sp);                                          // 0230 mov bx, sp
  PUSH(R.si);                                                  // 0232 push si
  PUSH(R.di);                                                  // 0233 push di
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0234 mov si, word ptr [bx + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x8)));                    // 0237 mov ax, word ptr [bx + 8]
  R.di = (u16)(R.ax);                                          // 023a mov di, ax
  R.di = (u16)(SHL16(R.di, 0x1));                              // 023c shl di, 1
  R.di = (u16)(M16(CS, (u16)(R.di + 0x192e)));                 // 023e mov di, word ptr cs:[di + 0x192e]
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0243 mov bx, word ptr [bx + 6]
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));           // 0246 or bh, bh
  if (R.zf) goto L_024f;                                       // 0248 je 0x24f
  R.es = (u16)(R.bx);                                          // 024a mov es, bx
  goto L_0256;                                                 // 024c jmp 0x256
L_024f:   R.bx = (u16)(SHL16(R.bx, 0x1));                              // 024f shl bx, 1
  R.es = (u16)(M16(CS, (u16)(R.bx + 0x1c58)));                 // 0251 mov es, word ptr cs:[bx + 0x1c58]
L_0256:   PUSH(R.es);                                                  // 0256 push es
  PUSH(R.di);                                                  // 0257 push di
  R.bx = (u16)(0x49ec /* segment */);                          // 0258 mov bx, 0x165
  R.es = (u16)(R.bx);                                          // 025b mov es, bx
  R.di = (u16)(0x9d);                                          // 025d mov di, 0x9d
  R.ax = (u16)(AND16(R.ax, 0x1));                              // 0260 and ax, 1
  R.ax = (u16)(XOR16(R.ax, 0x1));                              // 0263 xor ax, 1
  W8(ES, (u16)(0x9c), (u8)R.ax);                               // 0266 mov byte ptr es:[0x9c], al
  R.cx = (u16)(0x140);                                         // 026a mov cx, 0x140
  SETH(R.ax, 0x80);                                            // 026d mov ah, 0x80
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 026f xor bx, bx
  R.dx = (u16)(XOR16(R.dx, R.dx));                             // 0271 xor dx, dx
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 0273 cmp word ptr cs:[0x1c56], 1
  if (R.zf) goto L_02b6;                                       // 0279 je 0x2b6
L_027b:   LODSB();                                                     // 027b lodsb al, byte ptr [si]
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 027c shr al, 1
  if (!R.cf) goto L_0282;                                      // 027e jae 0x282
  SETL(R.bx, OR8((u8)R.bx, (u8)(R.ax >> 8)));                  // 0280 or bl, ah
L_0282:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 0282 shr al, 1
  if (!R.cf) goto L_0288;                                      // 0284 jae 0x288
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)(R.ax >> 8)));           // 0286 or bh, ah
L_0288:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 0288 shr al, 1
  if (!R.cf) goto L_028e;                                      // 028a jae 0x28e
  SETL(R.dx, OR8((u8)R.dx, (u8)(R.ax >> 8)));                  // 028c or dl, ah
L_028e:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 028e shr al, 1
  if (!R.cf) goto L_0294;                                      // 0290 jae 0x294
  SETH(R.dx, OR8((u8)(R.dx >> 8), (u8)(R.ax >> 8)));           // 0292 or dh, ah
L_0294:   SETH(R.ax, ROR8((u8)(R.ax >> 8), 0x1));                      // 0294 ror ah, 1
  if (!R.cf) goto L_02ac;                                      // 0296 jae 0x2ac
  W8(ES, (u16)(R.di), (u8)R.bx);                               // 0298 mov byte ptr es:[di], bl
  W8(ES, (u16)(R.di + 0x28), (u8)(R.bx >> 8));                 // 029b mov byte ptr es:[di + 0x28], bh
  W8(ES, (u16)(R.di + 0x50), (u8)R.dx);                        // 029f mov byte ptr es:[di + 0x50], dl
  W8(ES, (u16)(R.di + 0x78), (u8)(R.dx >> 8));                 // 02a3 mov byte ptr es:[di + 0x78], dh
  R.di = (u16)(INC16(R.di));                                   // 02a7 inc di
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 02a8 xor bx, bx
  R.dx = (u16)(XOR16(R.dx, R.dx));                             // 02aa xor dx, dx
L_02ac:   if (--R.cx != 0) goto L_027b;                                // 02ac loop 0x27b
L_02ae:   R.di = POP();                                                // 02ae pop di
  R.es = POP();                                                // 02af pop es
  PUSH(0x02b3); goto L_031b;                                   // 02b0 call 0x31b
L_02b3:   R.di = POP();                                                // 02b3 pop di
  R.si = POP();                                                // 02b4 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 02b5 retf
L_02b6:   PUSH(R.bp);                                                  // 02b6 push bp
L_02b7:   LODSB();                                                     // 02b7 lodsb al, byte ptr [si]
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 02b8 shl al, 1
  SETL(R.ax, ADD8((u8)R.ax, M8(ES, (u16)(0x9c))));             // 02ba add al, byte ptr es:[0x9c]
  R.bp = (u16)(R.ax);                                          // 02bf mov bp, ax
  R.bp = (u16)(AND16(R.bp, 0xff));                             // 02c1 and bp, 0xff
  SETL(R.ax, M8(ES, (u16)(R.bp + 0x1dd)));                     // 02c5 mov al, byte ptr es:[bp + 0x1dd]
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02ca shr al, 1
  if (!R.cf) goto L_02d0;                                      // 02cc jae 0x2d0
  SETL(R.bx, OR8((u8)R.bx, (u8)(R.ax >> 8)));                  // 02ce or bl, ah
L_02d0:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02d0 shr al, 1
  if (!R.cf) goto L_02d6;                                      // 02d2 jae 0x2d6
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)(R.ax >> 8)));           // 02d4 or bh, ah
L_02d6:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02d6 shr al, 1
  if (!R.cf) goto L_02dc;                                      // 02d8 jae 0x2dc
  SETL(R.dx, OR8((u8)R.dx, (u8)(R.ax >> 8)));                  // 02da or dl, ah
L_02dc:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02dc shr al, 1
  if (!R.cf) goto L_02e2;                                      // 02de jae 0x2e2
  SETH(R.dx, OR8((u8)(R.dx >> 8), (u8)(R.ax >> 8)));           // 02e0 or dh, ah
L_02e2:   SETH(R.ax, ROR8((u8)(R.ax >> 8), 0x1));                      // 02e2 ror ah, 1
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02e4 shr al, 1
  if (!R.cf) goto L_02ea;                                      // 02e6 jae 0x2ea
  SETL(R.bx, OR8((u8)R.bx, (u8)(R.ax >> 8)));                  // 02e8 or bl, ah
L_02ea:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02ea shr al, 1
  if (!R.cf) goto L_02f0;                                      // 02ec jae 0x2f0
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)(R.ax >> 8)));           // 02ee or bh, ah
L_02f0:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02f0 shr al, 1
  if (!R.cf) goto L_02f6;                                      // 02f2 jae 0x2f6
  SETL(R.dx, OR8((u8)R.dx, (u8)(R.ax >> 8)));                  // 02f4 or dl, ah
L_02f6:   SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 02f6 shr al, 1
  if (!R.cf) goto L_02fc;                                      // 02f8 jae 0x2fc
  SETH(R.dx, OR8((u8)(R.dx >> 8), (u8)(R.ax >> 8)));           // 02fa or dh, ah
L_02fc:   SETH(R.ax, ROR8((u8)(R.ax >> 8), 0x1));                      // 02fc ror ah, 1
  if (!R.cf) goto L_0316;                                      // 02fe jae 0x316
  W8(ES, (u16)(R.di), (u8)R.bx);                               // 0300 mov byte ptr es:[di], bl
  W8(ES, (u16)(R.di + 0x50), (u8)(R.bx >> 8));                 // 0303 mov byte ptr es:[di + 0x50], bh
  W8(ES, (u16)(R.di + 0xa0), (u8)R.dx);                        // 0307 mov byte ptr es:[di + 0xa0], dl
  W8(ES, (u16)(R.di + 0xf0), (u8)(R.dx >> 8));                 // 030c mov byte ptr es:[di + 0xf0], dh
  R.di = (u16)(INC16(R.di));                                   // 0311 inc di
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 0312 xor bx, bx
  R.dx = (u16)(XOR16(R.dx, R.dx));                             // 0314 xor dx, dx
L_0316:   if (--R.cx != 0) goto L_02b7;                                // 0316 loop 0x2b7
  R.bp = POP();                                                // 0318 pop bp
  goto L_02ae;                                                 // 0319 jmp 0x2ae
L_031b:   PUSH(R.ds);                                                  // 031b push ds
  R.ax = (u16)(0x49ec /* segment */);                          // 031c mov ax, 0x165
  R.ds = (u16)(R.ax);                                          // 031f mov ds, ax
  R.si = (u16)(0x9d);                                          // 0321 mov si, 0x9d
  R.bx = (u16)(R.di);                                          // 0324 mov bx, di
  R.dx = (u16)(0x3c4);                                         // 0326 mov dx, 0x3c4
  SETL(R.ax, 0x2);                                             // 0329 mov al, 2
  // 032b cli 
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 032c out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 032d inc dx
  SETL(R.ax, 0x1);                                             // 032e mov al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0330 out dx, al
  R.cx = (u16)(M16(CS, (u16)(0x1c70)));                        // 0331 mov cx, word ptr cs:[0x1c70]
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 0336 shr cx, 1
  R.di = (u16)(R.bx);                                          // 0338 mov di, bx
  REPMOVSW();                                                  // 033a rep movsw word ptr es:[di], word ptr [si]
  SETL(R.ax, 0x2);                                             // 033c mov al, 2
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 033e out dx, al
  R.cx = (u16)(M16(CS, (u16)(0x1c70)));                        // 033f mov cx, word ptr cs:[0x1c70]
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 0344 shr cx, 1
  R.di = (u16)(R.bx);                                          // 0346 mov di, bx
  REPMOVSW();                                                  // 0348 rep movsw word ptr es:[di], word ptr [si]
  SETL(R.ax, 0x4);                                             // 034a mov al, 4
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 034c out dx, al
  R.cx = (u16)(M16(CS, (u16)(0x1c70)));                        // 034d mov cx, word ptr cs:[0x1c70]
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 0352 shr cx, 1
  R.di = (u16)(R.bx);                                          // 0354 mov di, bx
  REPMOVSW();                                                  // 0356 rep movsw word ptr es:[di], word ptr [si]
  SETL(R.ax, 0x8);                                             // 0358 mov al, 8
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 035a out dx, al
  R.cx = (u16)(M16(CS, (u16)(0x1c70)));                        // 035b mov cx, word ptr cs:[0x1c70]
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 0360 shr cx, 1
  R.di = (u16)(R.bx);                                          // 0362 mov di, bx
  REPMOVSW();                                                  // 0364 rep movsw word ptr es:[di], word ptr [si]
  SETL(R.ax, 0xf);                                             // 0366 mov al, 0xf
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0368 out dx, al
  // 0369 sti 
  R.ds = POP();                                                // 036a pop ds
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 036b ret
L_036c:   R.es = POP();                                                // 036c pop es
  R.ds = POP();                                                // 036d pop ds
L_036e:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 036e retf
L_036f:   R.ax = (u16)(OR16(R.ax, R.ax));                              // 036f or ax, ax
  if (R.sf) goto L_036e;                                       // 0371 js 0x36e
  PUSH(R.ds);                                                  // 0373 push ds
  PUSH(R.es);                                                  // 0374 push es
  R.dx = (u16)(0x49ec /* segment */);                          // 0375 mov dx, 0x165
  R.ds = (u16)(R.dx);                                          // 0378 mov ds, dx
  R.es = (u16)(M16(CS, (u16)(0x1c68)));                        // 037a mov es, word ptr cs:[0x1c68]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 037f shl ax, 1
  R.si = (u16)(R.ax);                                          // 0381 mov si, ax
  W16(DS, (u16)(0x66e), R.bx);                                 // 0383 mov word ptr [0x66e], bx
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 0387 shl cx, 1
  W16(DS, (u16)(0x62a), R.cx);                                 // 0389 mov word ptr [0x62a], cx
  R.dx = (u16)(0x3ce);                                         // 038d mov dx, 0x3ce
  SETL(R.ax, 0x8);                                             // 0390 mov al, 8
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0392 out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 0393 inc dx
  SETH(R.ax, M8(CS, (u16)(0x1c56)));                           // 0394 mov ah, byte ptr cs:[0x1c56]
  R.si = (u16)(SUB16(R.si, 0x2));                              // 0399 sub si, 2
L_039c:   R.si = (u16)(ADD16(R.si, 0x2));                              // 039c add si, 2
  SUB16(R.si, M16(DS, (u16)(0x62a)));                          // 039f cmp si, word ptr [0x62a]
  if (!R.cf && !R.zf) goto L_036c;                             // 03a3 ja 0x36c
  R.cx = (u16)(M16(SS, (u16)(R.bx + R.si + 0x1b8)));           // 03a5 mov cx, word ptr ss:[bx + si + 0x1b8]
  R.bp = (u16)(M16(SS, (u16)(R.bx + R.si)));                   // 03aa mov bp, word ptr ss:[bx + si]
  SUB16(R.cx, R.bp);                                           // 03ad cmp cx, bp
  if (R.cf) goto L_039c;                                       // 03af jb 0x39c
  if (!R.cf && !R.zf) goto L_03be;                             // 03b1 ja 0x3be
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 03b3 or cx, cx
  if (R.zf) goto L_039c;                                       // 03b5 je 0x39c
  SUB16(R.cx, M16(CS, (u16)(0x1c6e)));                         // 03b7 cmp cx, word ptr cs:[0x1c6e]
  if (R.zf) goto L_039c;                                       // 03bc je 0x39c
L_03be:   SUB8((u8)(R.ax >> 8), 0x1);                                  // 03be cmp ah, 1
  if (!R.zf) goto L_03c8;                                      // 03c1 jne 0x3c8
  R.bp = (u16)(SHL16(R.bp, 0x1));                              // 03c3 shl bp, 1
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 03c5 shl cx, 1
  R.cx = (u16)(INC16(R.cx));                                   // 03c7 inc cx
L_03c8:   R.bx = (u16)(R.cx);                                          // 03c8 mov bx, cx
  R.bx = (u16)(AND16(R.bx, 0xf));                              // 03ca and bx, 0xf
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 03cd shl bx, 1
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x64c)));                  // 03cf mov bx, word ptr [bx + 0x64c]
  W16(DS, (u16)(0x66c), R.bx);                                 // 03d3 mov word ptr [0x66c], bx
  R.bx = (u16)(R.bp);                                          // 03d7 mov bx, bp
  R.bx = (u16)(AND16(R.bx, 0xf));                              // 03d9 and bx, 0xf
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 03dc shl bx, 1
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x62c)));                  // 03de mov bx, word ptr [bx + 0x62c]
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 03e2 shr cx, 1
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 03e4 shr cx, 1
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 03e6 shr cx, 1
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 03e8 shr cx, 1
  R.bp = (u16)(SHR16(R.bp, 0x1));                              // 03ea shr bp, 1
  R.bp = (u16)(SHR16(R.bp, 0x1));                              // 03ec shr bp, 1
  R.bp = (u16)(SHR16(R.bp, 0x1));                              // 03ee shr bp, 1
  R.bp = (u16)(SHR16(R.bp, 0x1));                              // 03f0 shr bp, 1
  R.di = (u16)(R.bp);                                          // 03f2 mov di, bp
  R.di = (u16)(SHL16(R.di, 0x1));                              // 03f4 shl di, 1
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(R.si + 0x2de))));     // 03f6 add di, word ptr [si + 0x2de]
  R.cx = (u16)(SUB16(R.cx, R.bp));                             // 03fa sub cx, bp
  // 03fc cli 
  if (R.zf) goto L_0418;                                       // 03fd je 0x418
  SETL(R.ax, (u8)R.bx);                                        // 03ff mov al, bl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0401 out dx, al
  W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 0402 inc byte ptr es:[di]
  R.di = (u16)(INC16(R.di));                                   // 0405 inc di
  SETL(R.ax, (u8)(R.bx >> 8));                                 // 0406 mov al, bh
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0408 out dx, al
  W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 0409 inc byte ptr es:[di]
  R.di = (u16)(INC16(R.di));                                   // 040c inc di
  R.bx = (u16)(0xffff);                                        // 040d mov bx, 0xffff
  R.cx = (u16)(DEC16(R.cx));                                   // 0410 dec cx
  if (R.zf) goto L_0418;                                       // 0411 je 0x418
  SETL(R.ax, (u8)R.bx);                                        // 0413 mov al, bl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0415 out dx, al
  REPSTOSW();                                                  // 0416 rep stosw word ptr es:[di], ax
L_0418:   R.bx = (u16)(AND16(R.bx, M16(DS, (u16)(0x66c))));            // 0418 and bx, word ptr [0x66c]
  SETL(R.ax, (u8)R.bx);                                        // 041c mov al, bl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 041e out dx, al
  W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 041f inc byte ptr es:[di]
  R.di = (u16)(INC16(R.di));                                   // 0422 inc di
  SETL(R.ax, (u8)(R.bx >> 8));                                 // 0423 mov al, bh
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0425 out dx, al
  W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 0426 inc byte ptr es:[di]
  // 0429 sti 
  R.bx = (u16)(M16(DS, (u16)(0x66e)));                         // 042a mov bx, word ptr [0x66e]
  goto L_039c;                                                 // 042e jmp 0x39c
L_0432:   R.bx = (u16)(R.sp);                                          // 0432 mov bx, sp
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0434 mov bx, word ptr [bx + 4]
  R.ax = (u16)(M16(CS, (u16)(R.bx + 0x1c4e)));                 // 0437 mov ax, word ptr cs:[bx + 0x1c4e]
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 043c retf
L_043d:   R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 043d mov ax, word ptr [bx + 2]
  W16(CS, (u16)(0x1c6a), R.ax);                                // 0440 mov word ptr cs:[0x1c6a], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0444 mov ax, word ptr [bx + 4]
  W16(CS, (u16)(0x1c6c), R.ax);                                // 0447 mov word ptr cs:[0x1c6c], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 044b mov ax, word ptr [bx + 6]
  W16(CS, (u16)(0x1c6e), R.ax);                                // 044e mov word ptr cs:[0x1c6e], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 0452 mov ax, word ptr [bx]
L_0454:   { u16 t_ = R.bx; R.bx = (u16)(R.ax); R.ax = (u16)(t_); }     // 0454 xchg bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0455 shl bx, 1
  R.bx = (u16)(M16(CS, (u16)(R.bx + 0x1c58)));                 // 0457 mov bx, word ptr cs:[bx + 0x1c58]
  { u16 t_ = R.bx; R.bx = (u16)(R.ax); R.ax = (u16)(t_); }     // 045c xchg bx, ax
  W16(CS, (u16)(0x1c68), R.ax);                                // 045d mov word ptr cs:[0x1c68], ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0461 retf
L_0462:   SETH(R.ax, 0x48);                                            // 0462 mov ah, 0x48
  R.bx = (u16)(0xffff);                                        // 0464 mov bx, 0xffff
  ASM_INT(0x21);                                               // 0467 int 0x21
  R.ax = (u16)(R.bx);                                          // 0469 mov ax, bx
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 046b retf
L_046c:   R.bx = (u16)(R.sp);                                          // 046c mov bx, sp
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 046e mov ax, word ptr [bx + 6]
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0471 mov bx, word ptr [bx + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0474 shl bx, 1
  W16(CS, (u16)(R.bx + 0x1c58), R.ax);                         // 0476 mov word ptr cs:[bx + 0x1c58], ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 047b retf
L_047c:   R.bx = (u16)(R.sp);                                          // 047c mov bx, sp
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 047e mov bx, word ptr [bx + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0481 shl bx, 1
  R.ax = (u16)(M16(CS, (u16)(R.bx + 0x1c58)));                 // 0483 mov ax, word ptr cs:[bx + 0x1c58]
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0488 retf
L_0489:   R.bx = (u16)(R.sp);                                          // 0489 mov bx, sp
  AND16(M16(DS, (u16)(R.bx + 0x4)), 0x2);                      // 048b test word ptr [bx + 4], 2
  if (R.zf) goto L_04b0;                                       // 0490 je 0x4b0
  R.dx = (u16)(0xe);                                           // 0492 mov dx, 0xe
  R.bx = (u16)(0x400);                                         // 0495 mov bx, 0x400
  W16(CS, (u16)(0x1c56), 0x1);                                 // 0498 mov word ptr cs:[0x1c56], 1
  W16(CS, (u16)(0x1c70), 0x50);                                // 049f mov word ptr cs:[0x1c70], 0x50
  W16(CS, (u16)(0x1c54), 0x1);                                 // 04a6 mov word ptr cs:[0x1c54], 1
  goto L_04cb;                                                 // 04ad jmp 0x4cb
L_04b0:   R.dx = (u16)(0xd);                                           // 04b0 mov dx, 0xd
  R.bx = (u16)(0x200);                                         // 04b3 mov bx, 0x200
  W16(CS, (u16)(0x1c56), 0x0);                                 // 04b6 mov word ptr cs:[0x1c56], 0
  W16(CS, (u16)(0x1c70), 0x28);                                // 04bd mov word ptr cs:[0x1c70], 0x28
  W16(CS, (u16)(0x1c54), 0x0);                                 // 04c4 mov word ptr cs:[0x1c54], 0
L_04cb:   PUSH(0x04ce); goto L_04f1;                                   // 04cb call 0x4f1
L_04ce:   R.ax = (u16)(R.dx);                                          // 04ce mov ax, dx
  ASM_INT(0x10);                                               // 04d0 int 0x10
  SETH(R.ax, 0xf);                                             // 04d2 mov ah, 0xf
  ASM_INT(0x10);                                               // 04d4 int 0x10
  SUB8((u8)R.ax, (u8)R.dx);                                    // 04d6 cmp al, dl
  if (!R.zf) goto L_04db;                                      // 04d8 jne 0x4db
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 04da retf
L_04db:   R.dx = (u16)(0x67e);                                         // 04db mov dx, 0x67e
  R.ax = (u16)(0x49ec /* segment */);                          // 04de mov ax, 0x165
  R.ds = (u16)(R.ax);                                          // 04e1 mov ds, ax
  R.ax = (u16)(0x3);                                           // 04e3 mov ax, 3
  ASM_INT(0x10);                                               // 04e6 int 0x10
  SETH(R.ax, 0x9);                                             // 04e8 mov ah, 9
  ASM_INT(0x21);                                               // 04ea int 0x21
  R.ax = (u16)(0x4c00);                                        // 04ec mov ax, 0x4c00
  ASM_INT(0x21);                                               // 04ef int 0x21
L_04f1:   PUSH(R.di);                                                  // 04f1 push di
  PUSH(R.es);                                                  // 04f2 push es
  PUSH(R.cs);                                                  // 04f3 push cs
  R.es = POP();                                                // 04f4 pop es
  R.ax = (u16)(0xa000);                                        // 04f5 mov ax, 0xa000
  R.di = (u16)(0x1c58);                                        // 04f8 mov di, 0x1c58
  R.cx = (u16)(0x8);                                           // 04fb mov cx, 8
L_04fe:   STOSW();                                                     // 04fe stosw word ptr es:[di], ax
  R.ax = (u16)(ADD16(R.ax, R.bx));                             // 04ff add ax, bx
  if (--R.cx != 0) goto L_04fe;                                // 0501 loop 0x4fe
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0503 xor ax, ax
  R.di = (u16)(0x192e);                                        // 0505 mov di, 0x192e
  R.cx = (u16)(0x190);                                         // 0508 mov cx, 0x190
L_050b:   STOSW();                                                     // 050b stosw word ptr es:[di], ax
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x1c70))));           // 050c add ax, word ptr cs:[0x1c70]
  if (--R.cx != 0) goto L_050b;                                // 0511 loop 0x50b
  R.es = POP();                                                // 0513 pop es
  R.di = POP();                                                // 0514 pop di
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0515 ret
L_0516:                                                                // 0516 cli
  PUSH(R.dx);                                                  // 0517 push dx
  R.dx = (u16)(0x3da);                                         // 0518 mov dx, 0x3da
L_051b:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 051b in al, dx
  AND8((u8)R.ax, 0x8);                                         // 051c test al, 8
  if (R.zf) goto L_051b;                                       // 051e je 0x51b
  R.dx = (u16)(0x3c0);                                         // 0520 mov dx, 0x3c0
  SETL(R.ax, 0x12);                                            // 0523 mov al, 0x12
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0525 out dx, al
  SETL(R.ax, 0x0);                                             // 0526 mov al, 0
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0528 out dx, al
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0529 out dx, al
  SETL(R.ax, 0x0);                                             // 052a mov al, 0
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 052c out dx, al
  SETL(R.ax, 0x3);                                             // 052d mov al, 3
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 052f out dx, al
  SETL(R.ax, 0x3);                                             // 0530 mov al, 3
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0532 out dx, al
  SETL(R.ax, 0x20);                                            // 0533 mov al, 0x20
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0535 out dx, al
  R.dx = POP();                                                // 0536 pop dx
  // 0537 sti 
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0538 retf
L_0539:                                                                // 0539 cli
  PUSH(R.dx);                                                  // 053a push dx
  R.dx = (u16)(0x3da);                                         // 053b mov dx, 0x3da
L_053e:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 053e in al, dx
  AND8((u8)R.ax, 0x8);                                         // 053f test al, 8
  if (R.zf) goto L_053e;                                       // 0541 je 0x53e
  R.dx = (u16)(0x3c0);                                         // 0543 mov dx, 0x3c0
  SETL(R.ax, 0x12);                                            // 0546 mov al, 0x12
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0548 out dx, al
  SETL(R.ax, 0xf);                                             // 0549 mov al, 0xf
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 054b out dx, al
  SETL(R.ax, 0x0);                                             // 054c mov al, 0
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 054e out dx, al
  SETL(R.ax, 0x3);                                             // 054f mov al, 3
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0551 out dx, al
  SETL(R.ax, 0x3);                                             // 0552 mov al, 3
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0554 out dx, al
  SETL(R.ax, 0x0);                                             // 0555 mov al, 0
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0557 out dx, al
  SETL(R.ax, 0x20);                                            // 0558 mov al, 0x20
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 055a out dx, al
  R.dx = POP();                                                // 055b pop dx
  // 055c sti 
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 055d retf
L_055e:   PUSH(R.ds);                                                  // 055e push ds
  PUSH(R.es);                                                  // 055f push es
  R.dx = (u16)(0x49ec /* segment */);                          // 0560 mov dx, 0x165
  R.ds = (u16)(R.dx);                                          // 0563 mov ds, dx
  R.es = (u16)(M16(CS, (u16)(0x1c68)));                        // 0565 mov es, word ptr cs:[0x1c68]
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 056a cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_0574;                                      // 0570 jne 0x574
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0572 shl ax, 1
L_0574:   R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x1c6a))));           // 0574 add ax, word ptr cs:[0x1c6a]
  W16(DS, (u16)(0x6ac), R.ax);                                 // 0579 mov word ptr [0x6ac], ax
  R.bx = (u16)(ADD16(R.bx, M16(CS, (u16)(0x1c6c))));           // 057c add bx, word ptr cs:[0x1c6c]
  W16(DS, (u16)(0x6ae), R.bx);                                 // 0581 mov word ptr [0x6ae], bx
L_0585:   PUSH(0x0588); goto L_0590;                                   // 0585 call 0x590
L_0588:   ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0588 out dx, al
  W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 0589 inc byte ptr es:[di]
  // 058c sti 
  R.es = POP();                                                // 058d pop es
  R.ds = POP();                                                // 058e pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 058f retf
L_0590:   R.bx = (u16)(M16(DS, (u16)(0x6ac)));                         // 0590 mov bx, word ptr [0x6ac]
  R.di = (u16)(R.bx);                                          // 0594 mov di, bx
  R.di = (u16)(SHR16(R.di, 0x1));                              // 0596 shr di, 1
  R.di = (u16)(SHR16(R.di, 0x1));                              // 0598 shr di, 1
  R.di = (u16)(SHR16(R.di, 0x1));                              // 059a shr di, 1
  R.si = (u16)(M16(DS, (u16)(0x6ae)));                         // 059c mov si, word ptr [0x6ae]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 05a0 shl si, 1
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(R.si + 0x2de))));     // 05a2 add di, word ptr [si + 0x2de]
  R.dx = (u16)(0x3ce);                                         // 05a6 mov dx, 0x3ce
  SETL(R.ax, 0x8);                                             // 05a9 mov al, 8
  // 05ab cli 
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 05ac out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 05ad inc dx
  R.bx = (u16)(AND16(R.bx, 0x7));                              // 05ae and bx, 7
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x6a4)));                     // 05b1 mov al, byte ptr [bx + 0x6a4]
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 05b5 ret
L_05b6:   PUSH(R.ds);                                                  // 05b6 push ds
  PUSH(R.es);                                                  // 05b7 push es
  R.di = (u16)(0x49ec /* segment */);                          // 05b8 mov di, 0x165
  R.ds = (u16)(R.di);                                          // 05bb mov ds, di
  R.es = (u16)(M16(CS, (u16)(0x1c68)));                        // 05bd mov es, word ptr cs:[0x1c68]
  R.di = (u16)(M16(CS, (u16)(0x1c6a)));                        // 05c2 mov di, word ptr cs:[0x1c6a]
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 05c7 add ax, di
  R.cx = (u16)(ADD16(R.cx, R.di));                             // 05c9 add cx, di
  R.di = (u16)(M16(CS, (u16)(0x1c6c)));                        // 05cb mov di, word ptr cs:[0x1c6c]
  R.bx = (u16)(ADD16(R.bx, R.di));                             // 05d0 add bx, di
  R.dx = (u16)(ADD16(R.dx, R.di));                             // 05d2 add dx, di
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 05d4 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_05e0;                                      // 05da jne 0x5e0
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 05dc shl ax, 1
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 05de shl cx, 1
L_05e0:   SUB16(R.ax, R.cx);                                           // 05e0 cmp ax, cx
  if (R.cf || R.zf) goto L_05e7;                               // 05e2 jbe 0x5e7
  { u16 t_ = R.cx; R.cx = (u16)(R.ax); R.ax = (u16)(t_); }     // 05e4 xchg cx, ax
  { u16 t_ = R.dx; R.dx = (u16)(R.bx); R.bx = (u16)(t_); }     // 05e5 xchg dx, bx
L_05e7:   W16(DS, (u16)(0x6ac), R.ax);                                 // 05e7 mov word ptr [0x6ac], ax
  W16(DS, (u16)(0x6ae), R.bx);                                 // 05ea mov word ptr [0x6ae], bx
  W16(DS, (u16)(0x6b0), R.cx);                                 // 05ee mov word ptr [0x6b0], cx
  W16(DS, (u16)(0x6b2), R.dx);                                 // 05f2 mov word ptr [0x6b2], dx
  if (!R.zf) goto L_05fc;                                      // 05f6 jne 0x5fc
  SUB16(R.bx, R.dx);                                           // 05f8 cmp bx, dx
  if (R.zf) goto L_0585;                                       // 05fa je 0x585
L_05fc:   R.bp = (u16)(M16(CS, (u16)(0x1c70)));                        // 05fc mov bp, word ptr cs:[0x1c70]
  R.bp = (u16)(DEC16(R.bp));                                   // 0601 dec bp
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 0602 sub cx, ax
  W16(DS, (u16)(0x6b4), R.cx);                                 // 0604 mov word ptr [0x6b4], cx
  R.dx = (u16)(SUB16(R.dx, R.bx));                             // 0608 sub dx, bx
  if (!R.sf) goto L_0613;                                      // 060a jns 0x613
  R.bp = (u16)(NEG16(R.bp));                                   // 060c neg bp
  R.bp = (u16)(SUB16(R.bp, 0x2));                              // 060e sub bp, 2
  R.dx = (u16)(NEG16(R.dx));                                   // 0611 neg dx
L_0613:   W16(DS, (u16)(0x6b6), R.dx);                                 // 0613 mov word ptr [0x6b6], dx
  SUB16(R.dx, R.cx);                                           // 0617 cmp dx, cx
  if (!R.cf && !R.zf) goto L_065d;                             // 0619 ja 0x65d
  PUSH(0x061e); goto L_0590;                                   // 061b call 0x590
L_061e:   R.cx = (u16)(M16(DS, (u16)(0x6b4)));                         // 061e mov cx, word ptr [0x6b4]
  R.bx = (u16)(R.cx);                                          // 0622 mov bx, cx
  R.bx = (u16)(INC16(R.bx));                                   // 0624 inc bx
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0625 shr bx, 1
  R.bx = (u16)(NEG16(R.bx));                                   // 0627 neg bx
  R.si = (u16)(M16(DS, (u16)(0x6b6)));                         // 0629 mov si, word ptr [0x6b6]
  SETH(R.ax, (u8)R.ax);                                        // 062d mov ah, al
  goto L_0640;                                                 // 062f jmp 0x640
L_0631:   R.bx = (u16)(SUB16(R.bx, M16(DS, (u16)(0x6b4))));            // 0631 sub bx, word ptr [0x6b4]
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0635 out dx, al
  SUB8((u8)(R.ax >> 8), M8(ES, (u16)(R.di)));                  // 0636 cmp ah, byte ptr es:[di]
  STOSB();                                                     // 0639 stosb byte ptr es:[di], al
  SETH(R.ax, ROR8((u8)(R.ax >> 8), 0x1));                      // 063a ror ah, 1
  R.di = (u16)(ADC16(R.di, R.bp));                             // 063c adc di, bp
L_063e:   SETL(R.ax, (u8)(R.ax >> 8));                                 // 063e mov al, ah
L_0640:   SETL(R.ax, OR8((u8)R.ax, (u8)(R.ax >> 8)));                  // 0640 or al, ah
  R.cx = (u16)(DEC16(R.cx));                                   // 0642 dec cx
  if (R.sf) goto L_0654;                                       // 0643 js 0x654
  R.bx = (u16)(ADD16(R.bx, R.si));                             // 0645 add bx, si
  if (!R.sf) goto L_0631;                                      // 0647 jns 0x631
  SETH(R.ax, ROR8((u8)(R.ax >> 8), 0x1));                      // 0649 ror ah, 1
  if (!R.cf) goto L_0640;                                      // 064b jae 0x640
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 064d out dx, al
  SUB8((u8)(R.ax >> 8), M8(ES, (u16)(R.di)));                  // 064e cmp ah, byte ptr es:[di]
  STOSB();                                                     // 0651 stosb byte ptr es:[di], al
  goto L_063e;                                                 // 0652 jmp 0x63e
L_0654:   ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0654 out dx, al
  SUB8((u8)(R.ax >> 8), M8(ES, (u16)(R.di)));                  // 0655 cmp ah, byte ptr es:[di]
  STOSB();                                                     // 0658 stosb byte ptr es:[di], al
  // 0659 sti 
  R.es = POP();                                                // 065a pop es
  R.ds = POP();                                                // 065b pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 065c retf
L_065d:   PUSH(0x0660); goto L_0590;                                   // 065d call 0x590
L_0660:   R.cx = (u16)(M16(DS, (u16)(0x6b6)));                         // 0660 mov cx, word ptr [0x6b6]
  R.bx = (u16)(R.cx);                                          // 0664 mov bx, cx
  R.bx = (u16)(INC16(R.bx));                                   // 0666 inc bx
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0667 shr bx, 1
  R.bx = (u16)(NEG16(R.bx));                                   // 0669 neg bx
  R.si = (u16)(M16(DS, (u16)(0x6b4)));                         // 066b mov si, word ptr [0x6b4]
  goto L_0673;                                                 // 066f jmp 0x673
L_0671:   R.di = (u16)(ADC16(R.di, R.bp));                             // 0671 adc di, bp
L_0673:   ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0673 out dx, al
  SETH(R.ax, M8(ES, (u16)(R.di)));                             // 0674 mov ah, byte ptr es:[di]
  STOSB();                                                     // 0677 stosb byte ptr es:[di], al
  R.cx = (u16)(DEC16(R.cx));                                   // 0678 dec cx
  if (R.sf) goto L_0687;                                       // 0679 js 0x687
  R.bx = (u16)(ADD16(R.bx, R.si));                             // 067b add bx, si
  if (R.sf) goto L_0671;                                       // 067d js 0x671
  R.bx = (u16)(SUB16(R.bx, M16(DS, (u16)(0x6b6))));            // 067f sub bx, word ptr [0x6b6]
  SETL(R.ax, ROR8((u8)R.ax, 0x1));                             // 0683 ror al, 1
  goto L_0671;                                                 // 0685 jmp 0x671
L_0687:                                                                // 0687 sti
  R.es = POP();                                                // 0688 pop es
  R.ds = POP();                                                // 0689 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 068a retf
L_068c:   R.bx = (u16)(R.sp);                                          // 068c mov bx, sp
  PUSH(R.di);                                                  // 068e push di
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 068f mov di, word ptr [bx + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0692 shl di, 1
  R.ax = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 0694 mov ax, word ptr cs:[di + 0x1c58]
  SETL(R.cx, 0x4);                                             // 0699 mov cl, 4
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 069b shl ax, cl
  SETL(R.ax, 0xc);                                             // 069d mov al, 0xc
  R.dx = (u16)(0x3d4);                                         // 069f mov dx, 0x3d4
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 06a2 out dx, ax
  R.di = POP();                                                // 06a3 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 06a4 retf
L_06a5:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 06a5 retf
L_06a6:   R.bx = (u16)(R.sp);                                          // 06a6 mov bx, sp
  PUSH(R.di);                                                  // 06a8 push di
  PUSH(R.es);                                                  // 06a9 push es
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 06aa mov di, word ptr [bx + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 06ad shl di, 1
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 06af mov es, word ptr cs:[di + 0x1c58]
  R.dx = (u16)(0x3ce);                                         // 06b4 mov dx, 0x3ce
  R.ax = (u16)(0x205);                                         // 06b7 mov ax, 0x205
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 06ba out dx, ax
  R.cx = (u16)(0x4000);                                        // 06bb mov cx, 0x4000
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x6)));                       // 06be mov al, byte ptr [bx + 6]
  SETH(R.ax, (u8)R.ax);                                        // 06c1 mov ah, al
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 06c3 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_06cd;                                      // 06c9 jne 0x6cd
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 06cb shl cx, 1
L_06cd:   R.di = (u16)(XOR16(R.di, R.di));                             // 06cd xor di, di
  REPSTOSW();                                                  // 06cf rep stosw word ptr es:[di], ax
  R.ax = (u16)(0x5);                                           // 06d1 mov ax, 5
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 06d4 out dx, ax
  R.es = POP();                                                // 06d5 pop es
  R.di = POP();                                                // 06d6 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 06d7 retf
L_06d8:   R.bx = (u16)(R.sp);                                          // 06d8 mov bx, sp
  PUSH(R.si);                                                  // 06da push si
  PUSH(R.di);                                                  // 06db push di
  PUSH(R.ds);                                                  // 06dc push ds
  PUSH(R.es);                                                  // 06dd push es
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 06de mov si, word ptr [bx + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 06e1 shl si, 1
  R.si = (u16)(M16(CS, (u16)(R.si + 0x1c58)));                 // 06e3 mov si, word ptr cs:[si + 0x1c58]
  R.dx = (u16)(0x3d4);                                         // 06e8 mov dx, 0x3d4
  SETL(R.ax, 0xc);                                             // 06eb mov al, 0xc
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 06ed out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 06ee inc dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 06ef in al, dx
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 06f0 xor ah, ah
  SETL(R.cx, 0x4);                                             // 06f2 mov cl, 4
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 06f4 shl ax, cl
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x1c58))));           // 06f6 add ax, word ptr cs:[0x1c58]
  SUB16(R.ax, R.si);                                           // 06fb cmp ax, si
  if (R.zf) goto L_0732;                                       // 06fd je 0x732
  R.ds = (u16)(R.si);                                          // 06ff mov ds, si
  R.es = (u16)(R.ax);                                          // 0701 mov es, ax
  R.dx = (u16)(0x3ce);                                         // 0703 mov dx, 0x3ce
  R.ax = (u16)(0x8);                                           // 0706 mov ax, 8
  W8(CS, (u16)(0x1c72), (u8)(R.ax >> 8));                      // 0709 mov byte ptr cs:[0x1c72], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 070e out dx, ax
  R.si = (u16)(0x1);                                           // 070f mov si, 1
  R.cx = (u16)(0x4000);                                        // 0712 mov cx, 0x4000
L_0715:   R.si = (u16)(SHR16(R.si, 0x1));                              // 0715 shr si, 1
  if (!R.cf) goto L_071d;                                      // 0717 jae 0x71d
  R.si = (u16)(XOR16(R.si, 0x1b00));                           // 0719 xor si, 0x1b00
L_071d:   SUB16(R.si, 0x4000);                                         // 071d cmp si, 0x4000
  if (!R.cf && !R.zf) goto L_0715;                             // 0721 ja 0x715
  R.si = (u16)(DEC16(R.si));                                   // 0723 dec si
  R.di = (u16)(R.si);                                          // 0724 mov di, si
  MOVSB();                                                     // 0726 movsb byte ptr es:[di], byte ptr [si]
  if (--R.cx != 0) goto L_0715;                                // 0727 loop 0x715
  R.ax = (u16)(0xff08);                                        // 0729 mov ax, 0xff08
  W8(CS, (u16)(0x1c72), (u8)(R.ax >> 8));                      // 072c mov byte ptr cs:[0x1c72], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0731 out dx, ax
L_0732:   R.es = POP();                                                // 0732 pop es
  R.ds = POP();                                                // 0733 pop ds
  R.di = POP();                                                // 0734 pop di
  R.si = POP();                                                // 0735 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0736 retf
L_0740:   goto L_08c2;                                                 // 0740 jmp 0x8c2
L_0743:   PUSH(R.bp);                                                  // 0743 push bp
  R.bp = (u16)(R.sp);                                          // 0744 mov bp, sp
  PUSH(R.di);                                                  // 0746 push di
  PUSH(R.si);                                                  // 0747 push si
  PUSH(R.es);                                                  // 0748 push es
  PUSH(R.ds);                                                  // 0749 push ds
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 074a mov si, word ptr [bp + 6]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x10)));                   // 074d mov di, word ptr [bp + 0x10]
  R.ax = (u16)(M16(DS, (u16)(R.si)));                          // 0750 mov ax, word ptr [si]
  W16(CS, (u16)(0x73c), R.ax);                                 // 0752 mov word ptr cs:[0x73c], ax
  R.ax = (u16)(M16(DS, (u16)(R.di)));                          // 0756 mov ax, word ptr [di]
  W16(CS, (u16)(0x73e), R.ax);                                 // 0758 mov word ptr cs:[0x73e], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x2)));                    // 075c mov ax, word ptr [si + 2]
  R.bx = (u16)(M16(DS, (u16)(R.si + 0x4)));                    // 075f mov bx, word ptr [si + 4]
  R.cx = (u16)(M16(DS, (u16)(R.di + 0x2)));                    // 0762 mov cx, word ptr [di + 2]
  R.dx = (u16)(M16(DS, (u16)(R.di + 0x4)));                    // 0765 mov dx, word ptr [di + 4]
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0768 mov si, word ptr [bp + 0xc]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 076b mov di, word ptr [bp + 0xe]
  R.si = (u16)(OR16(R.si, R.si));                              // 076e or si, si
  if (R.zf) goto L_0740;                                       // 0770 je 0x740
  R.di = (u16)(OR16(R.di, R.di));                              // 0772 or di, di
  if (R.zf) goto L_0740;                                       // 0774 je 0x740
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0x8))));       // 0776 add ax, word ptr [bp + 8]
  R.bx = (u16)(ADD16(R.bx, M16(SS, (u16)(R.bp + 0xa))));       // 0779 add bx, word ptr [bp + 0xa]
  R.cx = (u16)(ADD16(R.cx, M16(SS, (u16)(R.bp + 0x12))));      // 077c add cx, word ptr [bp + 0x12]
  R.dx = (u16)(ADD16(R.dx, M16(SS, (u16)(R.bp + 0x14))));      // 077f add dx, word ptr [bp + 0x14]
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 0782 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_0790;                                      // 0788 jne 0x790
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 078a shl ax, 1
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 078c shl cx, 1
  R.si = (u16)(SHL16(R.si, 0x1));                              // 078e shl si, 1
L_0790:   R.bp = (u16)(0x49ec /* segment */);                          // 0790 mov bp, 0x165
  R.ds = (u16)(R.bp);                                          // 0793 mov ds, bp
  W16(DS, (u16)(0x6b8), R.ax);                                 // 0795 mov word ptr [0x6b8], ax
  W16(DS, (u16)(0x6ba), R.bx);                                 // 0798 mov word ptr [0x6ba], bx
  W16(DS, (u16)(0x6bc), R.cx);                                 // 079c mov word ptr [0x6bc], cx
  W16(DS, (u16)(0x6be), R.dx);                                 // 07a0 mov word ptr [0x6be], dx
  W16(DS, (u16)(0x6c0), R.si);                                 // 07a4 mov word ptr [0x6c0], si
  W16(DS, (u16)(0x6c2), R.di);                                 // 07a8 mov word ptr [0x6c2], di
  SETL(R.cx, 0x3);                                             // 07ac mov cl, 3
  R.bx = (u16)(M16(DS, (u16)(0x6be)));                         // 07ae mov bx, word ptr [0x6be]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 07b2 shl bx, 1
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x2de)));                  // 07b4 mov di, word ptr [bx + 0x2de]
  R.ax = (u16)(M16(DS, (u16)(0x6bc)));                         // 07b8 mov ax, word ptr [0x6bc]
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 07bb shr ax, cl
  R.di = (u16)(ADD16(R.di, R.ax));                             // 07bd add di, ax
  R.bx = (u16)(M16(DS, (u16)(0x6ba)));                         // 07bf mov bx, word ptr [0x6ba]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 07c3 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x2de)));                  // 07c5 mov si, word ptr [bx + 0x2de]
  R.ax = (u16)(M16(DS, (u16)(0x6b8)));                         // 07c9 mov ax, word ptr [0x6b8]
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 07cc shr ax, cl
  R.si = (u16)(ADD16(R.si, R.ax));                             // 07ce add si, ax
  R.si = (u16)(DEC16(R.si));                                   // 07d0 dec si
  R.cx = (u16)(M16(DS, (u16)(0x6bc)));                         // 07d1 mov cx, word ptr [0x6bc]
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 07d5 and cl, 7
  SETL(R.bx, 0xff);                                            // 07d8 mov bl, 0xff
  SETL(R.bx, SHR8((u8)R.bx, (u8)R.cx));                        // 07da shr bl, cl
  R.cx = (u16)(M16(DS, (u16)(0x6bc)));                         // 07dc mov cx, word ptr [0x6bc]
  R.cx = (u16)(ADD16(R.cx, M16(DS, (u16)(0x6c0))));            // 07e0 add cx, word ptr [0x6c0]
  R.cx = (u16)(DEC16(R.cx));                                   // 07e4 dec cx
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 07e5 and cl, 7
  R.ax = (u16)(0xff80);                                        // 07e8 mov ax, 0xff80
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 07eb shr ax, cl
  SETH(R.bx, (u8)R.ax);                                        // 07ed mov bh, al
  R.ax = (u16)(M16(DS, (u16)(0x6bc)));                         // 07ef mov ax, word ptr [0x6bc]
  R.ax = (u16)(AND16(R.ax, 0x7));                              // 07f2 and ax, 7
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x6c0))));            // 07f5 add ax, word ptr [0x6c0]
  R.ax = (u16)(DEC16(R.ax));                                   // 07f9 dec ax
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 07fa shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 07fc shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 07fe shr ax, 1
  SETH(R.cx, (u8)R.ax);                                        // 0800 mov ch, al
  R.bp = (u16)(M16(DS, (u16)(0x6c2)));                         // 0802 mov bp, word ptr [0x6c2]
  R.ax = (u16)(M16(DS, (u16)(0x6bc)));                         // 0806 mov ax, word ptr [0x6bc]
  SETL(R.ax, AND8((u8)R.ax, 0x7));                             // 0809 and al, 7
  R.dx = (u16)(M16(DS, (u16)(0x6b8)));                         // 080b mov dx, word ptr [0x6b8]
  SETL(R.dx, AND8((u8)R.dx, 0x7));                             // 080f and dl, 7
  SETL(R.ax, SUB8((u8)R.ax, (u8)R.dx));                        // 0812 sub al, dl
  if (R.sf) goto L_081e;                                       // 0814 js 0x81e
  if (R.zf) goto L_081b;                                       // 0816 je 0x81b
  goto L_08c8;                                                 // 0818 jmp 0x8c8
L_081b:   goto L_0966;                                                 // 081b jmp 0x966
L_081e:   SETL(R.ax, NEG8((u8)R.ax));                                  // 081e neg al
  R.si = (u16)(INC16(R.si));                                   // 0820 inc si
  SETL(R.cx, (u8)R.ax);                                        // 0821 mov cl, al
  PUSH(R.di);                                                  // 0823 push di
  R.di = (u16)(M16(CS, (u16)(0x73c)));                         // 0824 mov di, word ptr cs:[0x73c]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0829 shl di, 1
  R.ds = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 082b mov ds, word ptr cs:[di + 0x1c58]
  R.di = (u16)(M16(CS, (u16)(0x73e)));                         // 0830 mov di, word ptr cs:[0x73e]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0835 shl di, 1
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 0837 mov es, word ptr cs:[di + 0x1c58]
  R.di = POP();                                                // 083c pop di
  SETH(R.ax, 0x3);                                             // 083d mov ah, 3
L_083f:   PUSH(R.ax);                                                  // 083f push ax
  PUSH(R.bp);                                                  // 0840 push bp
  PUSH(R.si);                                                  // 0841 push si
  PUSH(R.di);                                                  // 0842 push di
  R.dx = (u16)(0x3ce);                                         // 0843 mov dx, 0x3ce
  SETL(R.ax, 0x4);                                             // 0846 mov al, 4
  W8(CS, (u16)(0x1c78), (u8)(R.ax >> 8));                      // 0848 mov byte ptr cs:[0x1c78], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 084d out dx, ax
  { u16 t_ = R.bx; R.bx = (u16)(R.dx); R.dx = (u16)(t_); }     // 084e xchg bx, dx
  SETL(R.bx, (u8)(R.ax >> 8));                                 // 0850 mov bl, ah
  SETH(R.bx, SUB8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));          // 0852 sub bh, bh
  SETL(R.ax, 0x2);                                             // 0854 mov al, 2
  SETH(R.ax, M8(CS, (u16)(R.bx + 0x738)));                     // 0856 mov ah, byte ptr cs:[bx + 0x738]
  { u16 t_ = R.bx; R.bx = (u16)(R.dx); R.dx = (u16)(t_); }     // 085b xchg bx, dx
  R.dx = (u16)(0x3c4);                                         // 085d mov dx, 0x3c4
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 0860 mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0865 out dx, ax
L_0866:   PUSH(R.si);                                                  // 0866 push si
  PUSH(R.di);                                                  // 0867 push di
  PUSH(R.cx);                                                  // 0868 push cx
  SETH(R.ax, (u8)R.bx);                                        // 0869 mov ah, bl
  SETH(R.cx, OR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));           // 086b or ch, ch
  if (R.zf) goto L_088e;                                       // 086d je 0x88e
  R.dx = (u16)(M16(DS, (u16)(R.si)));                          // 086f mov dx, word ptr [si]
  R.si = (u16)(INC16(R.si));                                   // 0871 inc si
  R.dx = (u16)(ROL16(R.dx, (u8)R.cx));                         // 0872 rol dx, cl
  SETL(R.dx, AND8((u8)R.dx, (u8)(R.ax >> 8)));                 // 0874 and dl, ah
  SETH(R.ax, (u8)~(u8)(R.ax >> 8));                            // 0876 not ah
  SETH(R.ax, AND8((u8)(R.ax >> 8), M8(ES, (u16)(R.di))));      // 0878 and ah, byte ptr es:[di]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.dx));                  // 087b or ah, dl
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 087d mov al, ah
  STOSB();                                                     // 087f stosb byte ptr es:[di], al
  goto L_0888;                                                 // 0880 jmp 0x888
L_0883:   LODSW();                                                     // 0883 lodsw ax, word ptr [si]
  R.si = (u16)(DEC16(R.si));                                   // 0884 dec si
  R.ax = (u16)(ROL16(R.ax, (u8)R.cx));                         // 0885 rol ax, cl
  STOSB();                                                     // 0887 stosb byte ptr es:[di], al
L_0888:   SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 0888 dec ch
  if (!R.zf) goto L_0883;                                      // 088a jne 0x883
  SETH(R.ax, 0xff);                                            // 088c mov ah, 0xff
L_088e:   SETH(R.ax, AND8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));          // 088e and ah, bh
  R.dx = (u16)(M16(DS, (u16)(R.si)));                          // 0890 mov dx, word ptr [si]
  R.dx = (u16)(ROL16(R.dx, (u8)R.cx));                         // 0892 rol dx, cl
  SETL(R.dx, AND8((u8)R.dx, (u8)(R.ax >> 8)));                 // 0894 and dl, ah
  SETH(R.ax, (u8)~(u8)(R.ax >> 8));                            // 0896 not ah
  SETH(R.ax, AND8((u8)(R.ax >> 8), M8(ES, (u16)(R.di))));      // 0898 and ah, byte ptr es:[di]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.dx));                  // 089b or ah, dl
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 089d mov al, ah
  STOSB();                                                     // 089f stosb byte ptr es:[di], al
  R.cx = POP();                                                // 08a0 pop cx
  R.di = POP();                                                // 08a1 pop di
  R.si = POP();                                                // 08a2 pop si
  R.ax = (u16)(M16(CS, (u16)(0x1c70)));                        // 08a3 mov ax, word ptr cs:[0x1c70]
  R.di = (u16)(ADD16(R.di, R.ax));                             // 08a7 add di, ax
  R.si = (u16)(ADD16(R.si, R.ax));                             // 08a9 add si, ax
  R.bp = (u16)(DEC16(R.bp));                                   // 08ab dec bp
  if (!R.zf) goto L_0866;                                      // 08ac jne 0x866
  R.di = POP();                                                // 08ae pop di
  R.si = POP();                                                // 08af pop si
  R.bp = POP();                                                // 08b0 pop bp
  R.ax = POP();                                                // 08b1 pop ax
  SETH(R.ax, DEC8((u8)(R.ax >> 8)));                           // 08b2 dec ah
  if (!R.sf) goto L_083f;                                      // 08b4 jns 0x83f
L_08b6:   R.dx = (u16)(0x3c4);                                         // 08b6 mov dx, 0x3c4
  R.ax = (u16)(0xf02);                                         // 08b9 mov ax, 0xf02
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 08bc mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 08c1 out dx, ax
L_08c2:   R.ds = POP();                                                // 08c2 pop ds
  R.es = POP();                                                // 08c3 pop es
  R.si = POP();                                                // 08c4 pop si
  R.di = POP();                                                // 08c5 pop di
  R.bp = POP();                                                // 08c6 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 08c7 retf
L_08c8:   SETL(R.cx, (u8)R.ax);                                        // 08c8 mov cl, al
  PUSH(R.di);                                                  // 08ca push di
  R.di = (u16)(M16(CS, (u16)(0x73c)));                         // 08cb mov di, word ptr cs:[0x73c]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 08d0 shl di, 1
  R.ds = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 08d2 mov ds, word ptr cs:[di + 0x1c58]
  R.di = (u16)(M16(CS, (u16)(0x73e)));                         // 08d7 mov di, word ptr cs:[0x73e]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 08dc shl di, 1
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 08de mov es, word ptr cs:[di + 0x1c58]
  R.di = POP();                                                // 08e3 pop di
  SETH(R.ax, 0x3);                                             // 08e4 mov ah, 3
L_08e6:   PUSH(R.ax);                                                  // 08e6 push ax
  PUSH(R.bp);                                                  // 08e7 push bp
  PUSH(R.si);                                                  // 08e8 push si
  PUSH(R.di);                                                  // 08e9 push di
  R.dx = (u16)(0x3ce);                                         // 08ea mov dx, 0x3ce
  SETL(R.ax, 0x4);                                             // 08ed mov al, 4
  W8(CS, (u16)(0x1c78), (u8)(R.ax >> 8));                      // 08ef mov byte ptr cs:[0x1c78], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 08f4 out dx, ax
  { u16 t_ = R.bx; R.bx = (u16)(R.dx); R.dx = (u16)(t_); }     // 08f5 xchg bx, dx
  SETL(R.bx, (u8)(R.ax >> 8));                                 // 08f7 mov bl, ah
  SETH(R.bx, SUB8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));          // 08f9 sub bh, bh
  SETL(R.ax, 0x2);                                             // 08fb mov al, 2
  SETH(R.ax, M8(CS, (u16)(R.bx + 0x738)));                     // 08fd mov ah, byte ptr cs:[bx + 0x738]
  { u16 t_ = R.bx; R.bx = (u16)(R.dx); R.dx = (u16)(t_); }     // 0902 xchg bx, dx
  R.dx = (u16)(0x3c4);                                         // 0904 mov dx, 0x3c4
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 0907 mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 090c out dx, ax
L_090d:   PUSH(R.si);                                                  // 090d push si
  PUSH(R.di);                                                  // 090e push di
  PUSH(R.cx);                                                  // 090f push cx
  SETL(R.ax, (u8)R.bx);                                        // 0910 mov al, bl
  SETH(R.cx, OR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));           // 0912 or ch, ch
  if (R.zf) goto L_0938;                                       // 0914 je 0x938
  SETH(R.dx, M8(DS, (u16)(R.si)));                             // 0916 mov dh, byte ptr [si]
  SETL(R.dx, M8(DS, (u16)(R.si + 0x1)));                       // 0918 mov dl, byte ptr [si + 1]
  R.si = (u16)(INC16(R.si));                                   // 091b inc si
  R.dx = (u16)(SHR16(R.dx, (u8)R.cx));                         // 091c shr dx, cl
  SETL(R.dx, AND8((u8)R.dx, (u8)R.ax));                        // 091e and dl, al
  SETL(R.ax, (u8)~(u8)R.ax);                                   // 0920 not al
  SETL(R.ax, AND8((u8)R.ax, M8(ES, (u16)(R.di))));             // 0922 and al, byte ptr es:[di]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.dx));                         // 0925 or al, dl
  STOSB();                                                     // 0927 stosb byte ptr es:[di], al
  goto L_0932;                                                 // 0928 jmp 0x932
L_092b:   LODSW();                                                     // 092b lodsw ax, word ptr [si]
  R.si = (u16)(DEC16(R.si));                                   // 092c dec si
  R.ax = (u16)(ROR16(R.ax, (u8)R.cx));                         // 092d ror ax, cl
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 092f mov al, ah
  STOSB();                                                     // 0931 stosb byte ptr es:[di], al
L_0932:   SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 0932 dec ch
  if (!R.zf) goto L_092b;                                      // 0934 jne 0x92b
  SETL(R.ax, 0xff);                                            // 0936 mov al, 0xff
L_0938:   SETL(R.ax, AND8((u8)R.ax, (u8)(R.bx >> 8)));                 // 0938 and al, bh
  SETH(R.dx, M8(DS, (u16)(R.si)));                             // 093a mov dh, byte ptr [si]
  SETL(R.dx, M8(DS, (u16)(R.si + 0x1)));                       // 093c mov dl, byte ptr [si + 1]
  R.dx = (u16)(SHR16(R.dx, (u8)R.cx));                         // 093f shr dx, cl
  SETL(R.dx, AND8((u8)R.dx, (u8)R.ax));                        // 0941 and dl, al
  SETL(R.ax, (u8)~(u8)R.ax);                                   // 0943 not al
  SETL(R.ax, AND8((u8)R.ax, M8(ES, (u16)(R.di))));             // 0945 and al, byte ptr es:[di]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.dx));                         // 0948 or al, dl
  STOSB();                                                     // 094a stosb byte ptr es:[di], al
  R.cx = POP();                                                // 094b pop cx
  R.di = POP();                                                // 094c pop di
  R.si = POP();                                                // 094d pop si
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x1c70))));           // 094e add di, word ptr cs:[0x1c70]
  R.si = (u16)(ADD16(R.si, M16(CS, (u16)(0x1c70))));           // 0953 add si, word ptr cs:[0x1c70]
  R.bp = (u16)(DEC16(R.bp));                                   // 0958 dec bp
  if (!R.zf) goto L_090d;                                      // 0959 jne 0x90d
  R.di = POP();                                                // 095b pop di
  R.si = POP();                                                // 095c pop si
  R.bp = POP();                                                // 095d pop bp
  R.ax = POP();                                                // 095e pop ax
  SETH(R.ax, DEC8((u8)(R.ax >> 8)));                           // 095f dec ah
  if (!R.sf) goto L_08e6;                                      // 0961 jns 0x8e6
  goto L_08b6;                                                 // 0963 jmp 0x8b6
L_0966:   R.si = (u16)(INC16(R.si));                                   // 0966 inc si
  SETL(R.cx, (u8)(R.cx >> 8));                                 // 0967 mov cl, ch
  SETH(R.cx, SUB8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 0969 sub ch, ch
  PUSH(R.di);                                                  // 096b push di
  R.di = (u16)(M16(CS, (u16)(0x73c)));                         // 096c mov di, word ptr cs:[0x73c]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0971 shl di, 1
  R.ds = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 0973 mov ds, word ptr cs:[di + 0x1c58]
  R.di = (u16)(M16(CS, (u16)(0x73e)));                         // 0978 mov di, word ptr cs:[0x73e]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 097d shl di, 1
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 097f mov es, word ptr cs:[di + 0x1c58]
  R.di = POP();                                                // 0984 pop di
  R.cx = (u16)(DEC16(R.cx));                                   // 0985 dec cx
  if (R.zf || R.sf != R.of) goto L_09b0;                       // 0986 jle 0x9b0
  PUSH(R.bp);                                                  // 0988 push bp
  PUSH(R.si);                                                  // 0989 push si
  PUSH(R.di);                                                  // 098a push di
  R.dx = (u16)(0x3ce);                                         // 098b mov dx, 0x3ce
  R.ax = (u16)(0x8);                                           // 098e mov ax, 8
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 0991 out dx, ax
L_0992:   PUSH(R.si);                                                  // 0992 push si
  PUSH(R.di);                                                  // 0993 push di
  PUSH(R.cx);                                                  // 0994 push cx
  R.di = (u16)(INC16(R.di));                                   // 0995 inc di
  R.si = (u16)(INC16(R.si));                                   // 0996 inc si
  REPMOVSB();                                                  // 0997 rep movsb byte ptr es:[di], byte ptr [si]
  R.cx = POP();                                                // 0999 pop cx
  R.di = POP();                                                // 099a pop di
  R.si = POP();                                                // 099b pop si
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x1c70))));           // 099c add di, word ptr cs:[0x1c70]
  R.si = (u16)(ADD16(R.si, M16(CS, (u16)(0x1c70))));           // 09a1 add si, word ptr cs:[0x1c70]
  R.bp = (u16)(DEC16(R.bp));                                   // 09a6 dec bp
  if (!R.zf) goto L_0992;                                      // 09a7 jne 0x992
  R.di = POP();                                                // 09a9 pop di
  R.si = POP();                                                // 09aa pop si
  R.bp = POP();                                                // 09ab pop bp
  R.ax = (u16)(0xff08);                                        // 09ac mov ax, 0xff08
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 09af out dx, ax
L_09b0:   R.cx = (u16)(INC16(R.cx));                                   // 09b0 inc cx
  SETH(R.ax, 0x3);                                             // 09b1 mov ah, 3
L_09b3:   PUSH(R.ax);                                                  // 09b3 push ax
  PUSH(R.bp);                                                  // 09b4 push bp
  PUSH(R.si);                                                  // 09b5 push si
  PUSH(R.di);                                                  // 09b6 push di
  R.dx = (u16)(0x3ce);                                         // 09b7 mov dx, 0x3ce
  SETL(R.ax, 0x4);                                             // 09ba mov al, 4
  W8(CS, (u16)(0x1c78), (u8)(R.ax >> 8));                      // 09bc mov byte ptr cs:[0x1c78], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 09c1 out dx, ax
  { u16 t_ = R.bx; R.bx = (u16)(R.dx); R.dx = (u16)(t_); }     // 09c2 xchg bx, dx
  SETL(R.bx, (u8)(R.ax >> 8));                                 // 09c4 mov bl, ah
  SETH(R.bx, SUB8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));          // 09c6 sub bh, bh
  SETL(R.ax, 0x2);                                             // 09c8 mov al, 2
  SETH(R.ax, M8(CS, (u16)(R.bx + 0x738)));                     // 09ca mov ah, byte ptr cs:[bx + 0x738]
  { u16 t_ = R.bx; R.bx = (u16)(R.dx); R.dx = (u16)(t_); }     // 09cf xchg bx, dx
  R.dx = (u16)(0x3c4);                                         // 09d1 mov dx, 0x3c4
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 09d4 mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 09d9 out dx, ax
L_09da:   PUSH(R.si);                                                  // 09da push si
  PUSH(R.di);                                                  // 09db push di
  PUSH(R.cx);                                                  // 09dc push cx
  SETH(R.ax, (u8)R.bx);                                        // 09dd mov ah, bl
  SETL(R.cx, OR8((u8)R.cx, (u8)R.cx));                         // 09df or cl, cl
  if (R.zf) goto L_09fa;                                       // 09e1 je 0x9fa
  SETH(R.cx, M8(DS, (u16)(R.si)));                             // 09e3 mov ch, byte ptr [si]
  SETH(R.cx, AND8((u8)(R.cx >> 8), (u8)(R.ax >> 8)));          // 09e5 and ch, ah
  SETH(R.ax, (u8)~(u8)(R.ax >> 8));                            // 09e7 not ah
  SETH(R.ax, AND8((u8)(R.ax >> 8), M8(ES, (u16)(R.di))));      // 09e9 and ah, byte ptr es:[di]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.cx >> 8)));           // 09ec or ah, ch
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 09ee mov al, ah
  STOSB();                                                     // 09f0 stosb byte ptr es:[di], al
  SETH(R.cx, SUB8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 09f1 sub ch, ch
  R.si = (u16)(ADD16(R.si, R.cx));                             // 09f3 add si, cx
  R.cx = (u16)(DEC16(R.cx));                                   // 09f5 dec cx
  R.di = (u16)(ADD16(R.di, R.cx));                             // 09f6 add di, cx
  SETH(R.ax, 0xff);                                            // 09f8 mov ah, 0xff
L_09fa:   SETH(R.ax, AND8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));          // 09fa and ah, bh
  SETH(R.cx, M8(DS, (u16)(R.si)));                             // 09fc mov ch, byte ptr [si]
  SETH(R.cx, AND8((u8)(R.cx >> 8), (u8)(R.ax >> 8)));          // 09fe and ch, ah
  SETH(R.ax, (u8)~(u8)(R.ax >> 8));                            // 0a00 not ah
  SETH(R.ax, AND8((u8)(R.ax >> 8), M8(ES, (u16)(R.di))));      // 0a02 and ah, byte ptr es:[di]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.cx >> 8)));           // 0a05 or ah, ch
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 0a07 mov al, ah
  STOSB();                                                     // 0a09 stosb byte ptr es:[di], al
  R.cx = POP();                                                // 0a0a pop cx
  R.di = POP();                                                // 0a0b pop di
  R.si = POP();                                                // 0a0c pop si
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x1c70))));           // 0a0d add di, word ptr cs:[0x1c70]
  R.si = (u16)(ADD16(R.si, M16(CS, (u16)(0x1c70))));           // 0a12 add si, word ptr cs:[0x1c70]
  R.bp = (u16)(DEC16(R.bp));                                   // 0a17 dec bp
  if (!R.zf) goto L_09da;                                      // 0a18 jne 0x9da
  R.di = POP();                                                // 0a1a pop di
  R.si = POP();                                                // 0a1b pop si
  R.bp = POP();                                                // 0a1c pop bp
  R.ax = POP();                                                // 0a1d pop ax
  SETH(R.ax, DEC8((u8)(R.ax >> 8)));                           // 0a1e dec ah
  if (!R.sf) goto L_09b3;                                      // 0a20 jns 0x9b3
  goto L_08b6;                                                 // 0a22 jmp 0x8b6
L_0a6b:   PUSH(0x4887); PUSH(0x0a70); goto L_0462;                     // 0a6b lcall 0, 0x462
L_0a70:   R.bx = (u16)(R.ax);                                          // 0a70 mov bx, ax
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0a72 or bx, bx
  if (R.zf) goto L_0a7c;                                       // 0a74 je 0xa7c
  SETH(R.ax, 0x48);                                            // 0a76 mov ah, 0x48
  ASM_INT(0x21);                                               // 0a78 int 0x21
  if (!R.cf) goto L_0a80;                                      // 0a7a jae 0xa80
L_0a7c:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0a7c xor ax, ax
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 0a7e xor bx, bx
L_0a80:   R.bx = (u16)(ADD16(R.bx, R.ax));                             // 0a80 add bx, ax
  W16(CS, (u16)(0xa42), 0x0);                                  // 0a82 mov word ptr cs:[0xa42], 0
  W16(CS, (u16)(0xa44), R.ax);                                 // 0a89 mov word ptr cs:[0xa44], ax
  W16(CS, (u16)(0xa46), R.ax);                                 // 0a8d mov word ptr cs:[0xa46], ax
  W16(CS, (u16)(0xa48), R.bx);                                 // 0a91 mov word ptr cs:[0xa48], bx
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0a96 retf
L_0a97:   R.ax = (u16)(M16(CS, (u16)(0xa46)));                         // 0a97 mov ax, word ptr cs:[0xa46]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0a9b or ax, ax
  if (R.zf) goto L_0ab4;                                       // 0a9d je 0xab4
  R.bx = (u16)(M16(CS, (u16)(0xa44)));                         // 0a9f mov bx, word ptr cs:[0xa44]
  R.bx = (u16)(SUB16(R.bx, R.ax));                             // 0aa4 sub bx, ax
  R.es = (u16)(R.ax);                                          // 0aa6 mov es, ax
  SETH(R.ax, 0x4a);                                            // 0aa8 mov ah, 0x4a
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0aaa or bx, bx
  if (!R.zf) goto L_0ab0;                                      // 0aac jne 0xab0
  SETH(R.ax, 0x49);                                            // 0aae mov ah, 0x49
L_0ab0:   ASM_INT(0x21);                                               // 0ab0 int 0x21
  if (R.cf) goto L_0a7c;                                       // 0ab2 jb 0xa7c
L_0ab4:   R.ax = (u16)(0x1);                                           // 0ab4 mov ax, 1
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0ab7 retf
L_0ab8:   R.ax = (u16)(M16(CS, (u16)(0xa48)));                         // 0ab8 mov ax, word ptr cs:[0xa48]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa44))));            // 0abc sub ax, word ptr cs:[0xa44]
  if (R.cf || R.zf) goto L_0b2a;                               // 0ac1 jbe 0xb2a
  SUB16(R.ax, 0x1000);                                         // 0ac3 cmp ax, 0x1000
  if (R.cf) goto L_0acb;                                       // 0ac6 jb 0xacb
  R.ax = (u16)(0xfff);                                         // 0ac8 mov ax, 0xfff
L_0acb:   R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0acb shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0acd shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0acf shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0ad1 shl ax, 1
  W16(CS, (u16)(0xa4a), R.ax);                                 // 0ad3 mov word ptr cs:[0xa4a], ax
L_0ad7:   R.bx = (u16)(R.sp);                                          // 0ad7 mov bx, sp
  PUSH(R.di);                                                  // 0ad9 push di
  { u16 a_ = (u16)(0xa42); R.di = (u16)(M16(CS, a_)); R.es = M16(CS, (u16)(a_ + 2)); } // 0ada les di, ptr cs:[0xa42]
  R.ax = (u16)(M16(SS, (u16)(R.bx + 0x4)));                    // 0adf mov ax, word ptr ss:[bx + 4]
  STOSW();                                                     // 0ae3 stosw word ptr es:[di], ax
  R.cx = (u16)(0xcef);                                         // 0ae4 mov cx, 0xcef
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 0ae7 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_0af4;                                      // 0aed jne 0xaf4
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0aef shl ax, 1
  R.cx = (u16)(0xd2d);                                         // 0af1 mov cx, 0xd2d
L_0af4:   W16(CS, (u16)(0xa5f), R.cx);                                 // 0af4 mov word ptr cs:[0xa5f], cx
  W8(CS, (u16)(0xa61), 0x1);                                   // 0af9 mov byte ptr cs:[0xa61], 1
  R.cx = (u16)(R.ax);                                          // 0aff mov cx, ax
  R.ax = (u16)(ADD16(R.ax, 0x7));                              // 0b01 add ax, 7
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b04 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b06 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b08 shr ax, 1
  W16(CS, (u16)(0xa64), R.ax);                                 // 0b0a mov word ptr cs:[0xa64], ax
  R.cx = (u16)(DEC16(R.cx));                                   // 0b0e dec cx
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 0b0f and cl, 7
  SETL(R.ax, 0x80);                                            // 0b12 mov al, 0x80
  SETL(R.ax, SAR8((u8)R.ax, (u8)R.cx));                        // 0b14 sar al, cl
  W8(CS, (u16)(0xa5e), (u8)R.ax);                              // 0b16 mov byte ptr cs:[0xa5e], al
  R.ax = (u16)(M16(SS, (u16)(R.bx + 0x6)));                    // 0b1a mov ax, word ptr ss:[bx + 6]
  STOSW();                                                     // 0b1e stosw word ptr es:[di], ax
  W16(CS, (u16)(0xa62), R.ax);                                 // 0b1f mov word ptr cs:[0xa62], ax
  W16(CS, (u16)(0xa42), R.di);                                 // 0b23 mov word ptr cs:[0xa42], di
  R.di = POP();                                                // 0b28 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0b29 retf
L_0b2a:   R.ax = (u16)((u16)(0xa36));                                  // 0b2a lea ax, [0xa36]
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b2e shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b30 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b32 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b34 shr ax, 1
  R.cx = (u16)(R.cs);                                          // 0b36 mov cx, cs
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0b38 add ax, cx
  W16(CS, (u16)(0xa44), R.ax);                                 // 0b3a mov word ptr cs:[0xa44], ax
  W16(CS, (u16)(0xa48), R.ax);                                 // 0b3e mov word ptr cs:[0xa48], ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0b42 xor ax, ax
  W16(CS, (u16)(0xa42), R.ax);                                 // 0b44 mov word ptr cs:[0xa42], ax
  W16(CS, (u16)(0xa4a), R.ax);                                 // 0b48 mov word ptr cs:[0xa4a], ax
  W16(CS, (u16)(0xa46), R.ax);                                 // 0b4c mov word ptr cs:[0xa46], ax
  goto L_0ad7;                                                 // 0b50 jmp 0xad7
L_0b52:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0b52 xor ax, ax
  { u16 t_ = M16(CS, (u16)(0xa42)); W16(CS, (u16)(0xa42), R.ax); R.ax = (u16)(t_); } // 0b54 xchg word ptr cs:[0xa42], ax
  R.ax = (u16)(ADD16(R.ax, 0xf));                              // 0b59 add ax, 0xf
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b5c shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b5e shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b60 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0b62 shr ax, 1
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0xa44))));            // 0b64 add ax, word ptr cs:[0xa44]
  { u16 t_ = M16(CS, (u16)(0xa44)); W16(CS, (u16)(0xa44), R.ax); R.ax = (u16)(t_); } // 0b69 xchg word ptr cs:[0xa44], ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0b6e retf
L_0b6f:   PUSH(R.bp);                                                  // 0b6f push bp
  R.bp = (u16)(R.sp);                                          // 0b70 mov bp, sp
  PUSH(R.si);                                                  // 0b72 push si
  PUSH(R.di);                                                  // 0b73 push di
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0b74 mov si, word ptr [bp + 6]
  { u16 a_ = (u16)(0xa42); R.di = (u16)(M16(CS, a_)); R.es = M16(CS, (u16)(a_ + 2)); } // 0b77 les di, ptr cs:[0xa42]
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0b7c xor ax, ax
  W16(CS, (u16)(0xa4c), R.ax);                                 // 0b7e mov word ptr cs:[0xa4c], ax
  W16(CS, (u16)(0xa4e), R.ax);                                 // 0b82 mov word ptr cs:[0xa4e], ax
  W16(CS, (u16)(0xa50), R.ax);                                 // 0b86 mov word ptr cs:[0xa50], ax
  W8(CS, (u16)(0xa61), XOR8(M8(CS, (u16)(0xa61)), 0x1));       // 0b8a xor byte ptr cs:[0xa61], 1
  R.ax = (u16)(M16(CS, (u16)(0xa64)));                         // 0b90 mov ax, word ptr cs:[0xa64]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0b94 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0b96 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, 0x4));                              // 0b98 add ax, 4
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 0b9b add ax, di
  SUB16(R.ax, M16(CS, (u16)(0xa4a)));                          // 0b9d cmp ax, word ptr cs:[0xa4a]
  if (R.cf || R.zf) goto L_0bae;                               // 0ba2 jbe 0xbae
  W16(ES, (u16)(0x2), DEC16(M16(ES, (u16)(0x2))));             // 0ba4 dec word ptr es:[2]
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0ba9 xor ax, ax
  goto L_0c23;                                                 // 0bab jmp 0xc23
L_0bae:   R.bp = (u16)(R.di);                                          // 0bae mov bp, di
  STOSW();                                                     // 0bb0 stosw word ptr es:[di], ax
  STOSW();                                                     // 0bb1 stosw word ptr es:[di], ax
  R.ax = (u16)(M16(CS, (u16)(0xa64)));                         // 0bb2 mov ax, word ptr cs:[0xa64]
  W16(CS, (u16)(0xa66), R.ax);                                 // 0bb6 mov word ptr cs:[0xa66], ax
L_0bba:   ASM_INDIRECT_CALL(M16(CS, (u16)(0xa5f))); /* call word ptr cs:[0xa5f] */ // 0bba call word ptr cs:[0xa5f]
  if (R.zf) goto L_0bcb;                                       // 0bbf je 0xbcb
  W16(CS, (u16)(0xa4e), 0x0);                                  // 0bc1 mov word ptr cs:[0xa4e], 0
  goto L_0be7;                                                 // 0bc8 jmp 0xbe7
L_0bcb:   SUB16(M16(CS, (u16)(0xa50)), 0x0);                           // 0bcb cmp word ptr cs:[0xa50], 0
  if (!R.zf) goto L_0be2;                                      // 0bd1 jne 0xbe2
  W16(CS, (u16)(0xa4c), INC16(M16(CS, (u16)(0xa4c))));         // 0bd3 inc word ptr cs:[0xa4c]
  W16(CS, (u16)(0xa66), DEC16(M16(CS, (u16)(0xa66))));         // 0bd8 dec word ptr cs:[0xa66]
  if (!R.zf) goto L_0bba;                                      // 0bdd jne 0xbba
  goto L_0bf9;                                                 // 0bdf jmp 0xbf9
L_0be2:   W16(CS, (u16)(0xa4e), INC16(M16(CS, (u16)(0xa4e))));         // 0be2 inc word ptr cs:[0xa4e]
L_0be7:   W16(CS, (u16)(0xa50), INC16(M16(CS, (u16)(0xa50))));         // 0be7 inc word ptr cs:[0xa50]
  R.ax = (u16)(R.bx);                                          // 0bec mov ax, bx
  STOSW();                                                     // 0bee stosw word ptr es:[di], ax
  R.ax = (u16)(R.cx);                                          // 0bef mov ax, cx
  STOSW();                                                     // 0bf1 stosw word ptr es:[di], ax
  W16(CS, (u16)(0xa66), DEC16(M16(CS, (u16)(0xa66))));         // 0bf2 dec word ptr cs:[0xa66]
  if (!R.zf) goto L_0bba;                                      // 0bf7 jne 0xbba
L_0bf9:   R.ax = (u16)(M16(CS, (u16)(0xa50)));                         // 0bf9 mov ax, word ptr cs:[0xa50]
  R.bx = (u16)(M16(CS, (u16)(0xa4c)));                         // 0bfd mov bx, word ptr cs:[0xa4c]
  R.cx = (u16)(M16(CS, (u16)(0xa4e)));                         // 0c02 mov cx, word ptr cs:[0xa4e]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 0c07 or cx, cx
  if (R.zf) goto L_0c13;                                       // 0c09 je 0xc13
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 0c0b sub ax, cx
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 0c0d shl cx, 1
  R.cx = (u16)(SHL16(R.cx, 0x1));                              // 0c0f shl cx, 1
  R.di = (u16)(SUB16(R.di, R.cx));                             // 0c11 sub di, cx
L_0c13:   W16(ES, (u16)(R.bp), R.ax);                                  // 0c13 mov word ptr es:[bp], ax
  W16(ES, (u16)(R.bp + 0x2), R.bx);                            // 0c17 mov word ptr es:[bp + 2], bx
  W16(CS, (u16)(0xa42), R.di);                                 // 0c1b mov word ptr cs:[0xa42], di
  R.ax = (u16)(0x1);                                           // 0c20 mov ax, 1
L_0c23:   R.di = POP();                                                // 0c23 pop di
  R.si = POP();                                                // 0c24 pop si
  R.bp = POP();                                                // 0c25 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0c26 retf
L_0c27:   PUSH(R.bp);                                                  // 0c27 push bp
  R.bp = (u16)(R.sp);                                          // 0c28 mov bp, sp
  PUSH(R.si);                                                  // 0c2a push si
  PUSH(R.ds);                                                  // 0c2b push ds
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0c2c mov si, word ptr [bp + 0xa]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0c2f shl si, 1
  R.si = (u16)(M16(CS, (u16)(R.si + 0x192e)));                 // 0c31 mov si, word ptr cs:[si + 0x192e]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0c36 mov bx, word ptr [bp + 6]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c39 shl bx, 1
  R.ds = (u16)(M16(CS, (u16)(R.bx + 0x1c58)));                 // 0c3b mov ds, word ptr cs:[bx + 0x1c58]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0c40 mov bx, word ptr [bp + 8]
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 0c43 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_0c4d;                                      // 0c49 jne 0xc4d
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0c4b shl bx, 1
L_0c4d:   R.ax = (u16)(R.bx);                                          // 0c4d mov ax, bx
  R.ax = (u16)(AND16(R.ax, 0x7));                              // 0c4f and ax, 7
  W8(CS, (u16)(0xa6a), (u8)R.ax);                              // 0c52 mov byte ptr cs:[0xa6a], al
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0c56 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0c58 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0c5a shr bx, 1
  R.si = (u16)(ADD16(R.si, R.bx));                             // 0c5c add si, bx
  PUSH(M16(SS, (u16)(R.bp + 0xe)));                            // 0c5e push word ptr [bp + 0xe]
  PUSH(M16(SS, (u16)(R.bp + 0xc)));                            // 0c61 push word ptr [bp + 0xc]
  PUSH(0x4887); PUSH(0x0c69); goto L_0ab8;                     // 0c64 lcall 0, 0xab8
L_0c69:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0c69 add sp, 4
  W16(CS, (u16)(0xa5f), 0xca1);                                // 0c6c mov word ptr cs:[0xa5f], 0xca1
  SUB16(M16(CS, (u16)(0xa62)), 0x0);                           // 0c73 cmp word ptr cs:[0xa62], 0
  if (R.zf) goto L_0c98;                                       // 0c79 je 0xc98
  SUB16(M16(CS, (u16)(0xa64)), 0x0);                           // 0c7b cmp word ptr cs:[0xa64], 0
  if (R.zf) goto L_0c98;                                       // 0c81 je 0xc98
L_0c83:   PUSH(R.si);                                                  // 0c83 push si
  PUSH(0x4887); PUSH(0x0c89); goto L_0b6f;                     // 0c84 lcall 0, 0xb6f
L_0c89:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0c89 add sp, 2
  R.si = (u16)(ADD16(R.si, M16(CS, (u16)(0x1c70))));           // 0c8c add si, word ptr cs:[0x1c70]
  W16(CS, (u16)(0xa62), DEC16(M16(CS, (u16)(0xa62))));         // 0c91 dec word ptr cs:[0xa62]
  if (!R.zf) goto L_0c83;                                      // 0c96 jne 0xc83
L_0c98:   PUSH(0x4887); PUSH(0x0c9d); goto L_0b52;                     // 0c98 lcall 0, 0xb52
L_0c9d:   R.ds = POP();                                                // 0c9d pop ds
  R.si = POP();                                                // 0c9e pop si
  R.bp = POP();                                                // 0c9f pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0ca0 retf
L_0d9b:   PUSH(R.bp);                                                  // 0d9b push bp
  R.bp = (u16)(R.sp);                                          // 0d9c mov bp, sp
  PUSH(R.si);                                                  // 0d9e push si
  PUSH(R.di);                                                  // 0d9f push di
  PUSH(0x4887); PUSH(0x0da5); goto L_0da9;                     // 0da0 lcall 0, 0xda9
L_0da5:   R.di = POP();                                                // 0da5 pop di
  R.si = POP();                                                // 0da6 pop si
  R.bp = POP();                                                // 0da7 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0da8 retf
L_0da9:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0da9 retf
L_0daa:   PUSH(R.bp);                                                  // 0daa push bp
  R.bp = (u16)(R.sp);                                          // 0dab mov bp, sp
  PUSH(R.si);                                                  // 0dad push si
  PUSH(R.di);                                                  // 0dae push di
  PUSH(R.ds);                                                  // 0daf push ds
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0db0 mov dx, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0db3 mov di, word ptr [bp + 0xa]
  R.ds = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0db6 mov ds, word ptr [bp + 0xc]
  R.si = (u16)(XOR16(R.si, R.si));                             // 0db9 xor si, si
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0dbb mov bp, word ptr [bp + 6]
  PUSH(0x4887); PUSH(0x0dc3); goto L_0dc8;                     // 0dbe lcall 0, 0xdc8
L_0dc3:   R.ds = POP();                                                // 0dc3 pop ds
  R.di = POP();                                                // 0dc4 pop di
  R.si = POP();                                                // 0dc5 pop si
  R.bp = POP();                                                // 0dc6 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0dc7 retf
L_0dc8:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0dc8 xor ax, ax
  W16(CS, (u16)(0xa52), R.ax);                                 // 0dca mov word ptr cs:[0xa52], ax
  W16(CS, (u16)(0xa54), R.ax);                                 // 0dce mov word ptr cs:[0xa54], ax
  W16(CS, (u16)(0xa56), R.ax);                                 // 0dd2 mov word ptr cs:[0xa56], ax
  W16(CS, (u16)(0xa58), R.ax);                                 // 0dd6 mov word ptr cs:[0xa58], ax
  W16(CS, (u16)(0xa3a), R.ax);                                 // 0dda mov word ptr cs:[0xa3a], ax
  W16(CS, (u16)(0xa3c), R.ax);                                 // 0dde mov word ptr cs:[0xa3c], ax
  W16(CS, (u16)(0xa3e), R.ax);                                 // 0de2 mov word ptr cs:[0xa3e], ax
  W16(CS, (u16)(0xa40), R.ax);                                 // 0de6 mov word ptr cs:[0xa40], ax
  R.cx = (u16)(M16(DS, (u16)(R.si)));                          // 0dea mov cx, word ptr [si]
  R.bx = (u16)(M16(DS, (u16)(R.si + 0x2)));                    // 0dec mov bx, word ptr [si + 2]
  R.di = (u16)(OR16(R.di, R.di));                              // 0def or di, di
  if (!R.sf) goto L_0dff;                                      // 0df1 jns 0xdff
  R.ax = (u16)(R.di);                                          // 0df3 mov ax, di
  R.ax = (u16)(NEG16(R.ax));                                   // 0df5 neg ax
  SUB16(R.ax, R.bx);                                           // 0df7 cmp ax, bx
  if (!R.cf) goto L_0e79;                                      // 0df9 jae 0xe79
  W16(CS, (u16)(0xa52), R.ax);                                 // 0dfb mov word ptr cs:[0xa52], ax
L_0dff:   R.ax = (u16)(R.di);                                          // 0dff mov ax, di
  R.ax = (u16)(ADD16(R.ax, R.bx));                             // 0e01 add ax, bx
  R.ax = (u16)(DEC16(R.ax));                                   // 0e03 dec ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0e04 mov bx, word ptr [bp + 8]
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0e07 or bx, bx
  if (R.sf) goto L_0e79;                                       // 0e09 js 0xe79
  SUB16(R.di, R.bx);                                           // 0e0b cmp di, bx
  if (!R.zf && R.sf == R.of) goto L_0e79;                      // 0e0d jg 0xe79
  R.ax = (u16)(SUB16(R.ax, R.bx));                             // 0e0f sub ax, bx
  if (R.zf || R.sf != R.of) goto L_0e17;                       // 0e11 jle 0xe17
  W16(CS, (u16)(0xa56), R.ax);                                 // 0e13 mov word ptr cs:[0xa56], ax
L_0e17:   R.dx = (u16)(OR16(R.dx, R.dx));                              // 0e17 or dx, dx
  if (!R.sf) goto L_0e27;                                      // 0e19 jns 0xe27
  R.ax = (u16)(R.dx);                                          // 0e1b mov ax, dx
  R.ax = (u16)(NEG16(R.ax));                                   // 0e1d neg ax
  SUB16(R.ax, R.cx);                                           // 0e1f cmp ax, cx
  if (!R.cf) goto L_0e79;                                      // 0e21 jae 0xe79
  W16(CS, (u16)(0xa54), R.ax);                                 // 0e23 mov word ptr cs:[0xa54], ax
L_0e27:   R.ax = (u16)(R.dx);                                          // 0e27 mov ax, dx
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0e29 add ax, cx
  R.ax = (u16)(DEC16(R.ax));                                   // 0e2b dec ax
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0e2c mov cx, word ptr [bp + 6]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 0e2f or cx, cx
  if (R.sf) goto L_0e79;                                       // 0e31 js 0xe79
  SUB16(R.dx, R.cx);                                           // 0e33 cmp dx, cx
  if (!R.zf && R.sf == R.of) goto L_0e79;                      // 0e35 jg 0xe79
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 0e37 sub ax, cx
  if (R.zf || R.sf != R.of) goto L_0e3f;                       // 0e39 jle 0xe3f
  W16(CS, (u16)(0xa58), R.ax);                                 // 0e3b mov word ptr cs:[0xa58], ax
L_0e3f:   R.ax = (u16)(M16(CS, (u16)(0xa54)));                         // 0e3f mov ax, word ptr cs:[0xa54]
  R.ax = (u16)(ADD16(R.ax, R.dx));                             // 0e43 add ax, dx
  W16(CS, (u16)(0xa3a), R.ax);                                 // 0e45 mov word ptr cs:[0xa3a], ax
  R.ax = (u16)(M16(CS, (u16)(0xa52)));                         // 0e49 mov ax, word ptr cs:[0xa52]
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 0e4d add ax, di
  W16(CS, (u16)(0xa3c), R.ax);                                 // 0e4f mov word ptr cs:[0xa3c], ax
  R.ax = (u16)(M16(DS, (u16)(R.si)));                          // 0e53 mov ax, word ptr [si]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa54))));            // 0e55 sub ax, word ptr cs:[0xa54]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa58))));            // 0e5a sub ax, word ptr cs:[0xa58]
  W16(CS, (u16)(0xa3e), R.ax);                                 // 0e5f mov word ptr cs:[0xa3e], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x2)));                    // 0e63 mov ax, word ptr [si + 2]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa52))));            // 0e66 sub ax, word ptr cs:[0xa52]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa56))));            // 0e6b sub ax, word ptr cs:[0xa56]
  W16(CS, (u16)(0xa40), R.ax);                                 // 0e70 mov word ptr cs:[0xa40], ax
  PUSH(0x4887); PUSH(0x0e79); goto L_0eaf;                     // 0e74 lcall 0, 0xeaf
L_0e79:   R.ax = (u16)(0xa3a);                                         // 0e79 mov ax, 0xa3a
  R.dx = (u16)(R.cs);                                          // 0e7c mov dx, cs
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0e7e retf
L_0e7f:   PUSH(R.bp);                                                  // 0e7f push bp
  R.bp = (u16)(R.sp);                                          // 0e80 mov bp, sp
  PUSH(R.si);                                                  // 0e82 push si
  PUSH(R.di);                                                  // 0e83 push di
  PUSH(R.ds);                                                  // 0e84 push ds
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0e85 mov dx, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0e88 mov di, word ptr [bp + 0xa]
  R.ds = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0e8b mov ds, word ptr [bp + 0xc]
  R.si = (u16)(XOR16(R.si, R.si));                             // 0e8e xor si, si
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0e90 mov bp, word ptr [bp + 6]
  PUSH(0x4887); PUSH(0x0e98); goto L_0e9d;                     // 0e93 lcall 0, 0xe9d
L_0e98:   R.ds = POP();                                                // 0e98 pop ds
  R.di = POP();                                                // 0e99 pop di
  R.si = POP();                                                // 0e9a pop si
  R.bp = POP();                                                // 0e9b pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 0e9c retf
L_0e9d:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0e9d xor ax, ax
  W16(CS, (u16)(0xa52), R.ax);                                 // 0e9f mov word ptr cs:[0xa52], ax
  W16(CS, (u16)(0xa54), R.ax);                                 // 0ea3 mov word ptr cs:[0xa54], ax
  W16(CS, (u16)(0xa56), R.ax);                                 // 0ea7 mov word ptr cs:[0xa56], ax
  W16(CS, (u16)(0xa58), R.ax);                                 // 0eab mov word ptr cs:[0xa58], ax
L_0eaf:   PUSH(R.bp);                                                  // 0eaf push bp
  PUSH(R.es);                                                  // 0eb0 push es
  R.bx = (u16)(M16(SS, (u16)(R.bp)));                          // 0eb1 mov bx, word ptr [bp]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0eb4 shl bx, 1
  R.es = (u16)(M16(CS, (u16)(R.bx + 0x1c58)));                 // 0eb6 mov es, word ptr cs:[bx + 0x1c58]
  R.dx = (u16)(ADD16(R.dx, M16(SS, (u16)(R.bp + 0x2))));       // 0ebb add dx, word ptr [bp + 2]
  R.di = (u16)(ADD16(R.di, M16(SS, (u16)(R.bp + 0x4))));       // 0ebe add di, word ptr [bp + 4]
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0xa52))));            // 0ec1 add di, word ptr cs:[0xa52]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0ec6 shl di, 1
  R.di = (u16)(M16(CS, (u16)(R.di + 0x192e)));                 // 0ec8 mov di, word ptr cs:[di + 0x192e]
  LODSW();                                                     // 0ecd lodsw ax, word ptr [si]
  R.bp = (u16)(R.ax);                                          // 0ece mov bp, ax
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 0ed0 cmp word ptr cs:[0x1c56], 1
  if (!R.zf) goto L_0ee6;                                      // 0ed6 jne 0xee6
  R.dx = (u16)(SHL16(R.dx, 0x1));                              // 0ed8 shl dx, 1
  R.bp = (u16)(SHL16(R.bp, 0x1));                              // 0eda shl bp, 1
  W16(CS, (u16)(0xa54), SHL16(M16(CS, (u16)(0xa54)), 0x1));    // 0edc shl word ptr cs:[0xa54], 1
  W16(CS, (u16)(0xa58), SHL16(M16(CS, (u16)(0xa58)), 0x1));    // 0ee1 shl word ptr cs:[0xa58], 1
L_0ee6:   R.cx = (u16)(R.dx);                                          // 0ee6 mov cx, dx
  R.cx = (u16)(AND16(R.cx, 0x7));                              // 0ee8 and cx, 7
  W8(CS, (u16)(0xa6a), (u8)R.cx);                              // 0eeb mov byte ptr cs:[0xa6a], cl
  SETL(R.ax, 0xff);                                            // 0ef0 mov al, 0xff
  SETL(R.ax, SHR8((u8)R.ax, (u8)R.cx));                        // 0ef2 shr al, cl
  W8(CS, (u16)(0xa5a), (u8)R.ax);                              // 0ef4 mov byte ptr cs:[0xa5a], al
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 0ef8 xor bx, bx
  SETL(R.cx, OR8((u8)R.cx, (u8)R.cx));                         // 0efa or cl, cl
  if (R.zf) goto L_0f01;                                       // 0efc je 0xf01
  SETL(R.ax, (u8)~(u8)R.ax);                                   // 0efe not al
  R.bx = (u16)(INC16(R.bx));                                   // 0f00 inc bx
L_0f01:   W8(CS, (u16)(0xa5b), (u8)R.ax);                              // 0f01 mov byte ptr cs:[0xa5b], al
  W16(CS, (u16)(0xa68), R.bx);                                 // 0f05 mov word ptr cs:[0xa68], bx
  R.cx = (u16)(R.dx);                                          // 0f0a mov cx, dx
  R.cx = (u16)(ADD16(R.cx, M16(CS, (u16)(0xa54))));            // 0f0c add cx, word ptr cs:[0xa54]
  R.bx = (u16)(R.cx);                                          // 0f11 mov bx, cx
  R.cx = (u16)(AND16(R.cx, 0x7));                              // 0f13 and cx, 7
  SETL(R.ax, 0xff);                                            // 0f16 mov al, 0xff
  SETL(R.ax, SHR8((u8)R.ax, (u8)R.cx));                        // 0f18 shr al, cl
  W8(CS, (u16)(0xa5d), (u8)R.ax);                              // 0f1a mov byte ptr cs:[0xa5d], al
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0f1e shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0f20 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0f22 shr bx, 1
  R.di = (u16)(ADD16(R.di, R.bx));                             // 0f24 add di, bx
  R.dx = (u16)(ADD16(R.dx, R.bp));                             // 0f26 add dx, bp
  R.dx = (u16)(DEC16(R.dx));                                   // 0f28 dec dx
  R.dx = (u16)(SUB16(R.dx, M16(CS, (u16)(0xa58))));            // 0f29 sub dx, word ptr cs:[0xa58]
  R.cx = (u16)(R.dx);                                          // 0f2e mov cx, dx
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 0f30 and cl, 7
  SETL(R.ax, 0x80);                                            // 0f33 mov al, 0x80
  SETL(R.ax, SAR8((u8)R.ax, (u8)R.cx));                        // 0f35 sar al, cl
  W8(CS, (u16)(0xa5e), (u8)R.ax);                              // 0f37 mov byte ptr cs:[0xa5e], al
  R.ax = (u16)(R.dx);                                          // 0f3b mov ax, dx
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0f3d shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0f3f shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0f41 shr ax, 1
  R.ax = (u16)(SUB16(R.ax, R.bx));                             // 0f43 sub ax, bx
  R.ax = (u16)(INC16(R.ax));                                   // 0f45 inc ax
  W16(CS, (u16)(0xa64), R.ax);                                 // 0f46 mov word ptr cs:[0xa64], ax
  LODSW();                                                     // 0f4a lodsw ax, word ptr [si]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa52))));            // 0f4b sub ax, word ptr cs:[0xa52]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa56))));            // 0f50 sub ax, word ptr cs:[0xa56]
  if (!R.zf && R.sf == R.of) goto L_0f5a;                      // 0f55 jg 0xf5a
  goto L_1028;                                                 // 0f57 jmp 0x1028
L_0f5a:   W16(CS, (u16)(0xa62), R.ax);                                 // 0f5a mov word ptr cs:[0xa62], ax
  R.cx = (u16)(M16(CS, (u16)(0xa52)));                         // 0f5e mov cx, word ptr cs:[0xa52]
  if (R.cx == 0) goto L_0f71;                                  // 0f63 jcxz 0xf71
L_0f65:   LODSW();                                                     // 0f65 lodsw ax, word ptr [si]
  R.si = (u16)(ADD16(R.si, 0x2));                              // 0f66 add si, 2
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0f69 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0f6b shl ax, 1
  R.si = (u16)(ADD16(R.si, R.ax));                             // 0f6d add si, ax
  if (--R.cx != 0) goto L_0f65;                                // 0f6f loop 0xf65
L_0f71:   SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0f71 xor ah, ah
  SETL(R.ax, M8(CS, (u16)(0xa6a)));                            // 0f73 mov al, byte ptr cs:[0xa6a]
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0xa54))));            // 0f77 add ax, word ptr cs:[0xa54]
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0f7c shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0f7e shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0f80 shr ax, 1
  W16(CS, (u16)(0xa54), R.ax);                                 // 0f82 mov word ptr cs:[0xa54], ax
  SETL(R.ax, M8(CS, (u16)(0xa6a)));                            // 0f86 mov al, byte ptr cs:[0xa6a]
  SUB8((u8)R.ax, 0x4);                                         // 0f8a cmp al, 4
  if (R.cf || R.zf) goto L_0f90;                               // 0f8c jbe 0xf90
  SETL(R.ax, SUB8((u8)R.ax, 0x8));                             // 0f8e sub al, 8
L_0f90:   W8(CS, (u16)(0xa6a), (u8)R.ax);                              // 0f90 mov byte ptr cs:[0xa6a], al
L_0f94:   LODSW();                                                     // 0f94 lodsw ax, word ptr [si]
  R.dx = (u16)(R.ax);                                          // 0f95 mov dx, ax
  LODSW();                                                     // 0f97 lodsw ax, word ptr [si]
  R.dx = (u16)(OR16(R.dx, R.dx));                              // 0f98 or dx, dx
  if (R.zf) goto L_1019;                                       // 0f9a je 0x1019
  R.bp = (u16)(R.dx);                                          // 0f9c mov bp, dx
  R.bp = (u16)(SHL16(R.bp, 0x1));                              // 0f9e shl bp, 1
  R.bp = (u16)(SHL16(R.bp, 0x1));                              // 0fa0 shl bp, 1
  R.bp = (u16)(ADD16(R.bp, R.si));                             // 0fa2 add bp, si
  PUSH(R.bp);                                                  // 0fa4 push bp
  PUSH(R.di);                                                  // 0fa5 push di
  SETH(R.bx, M8(CS, (u16)(0xa5d)));                            // 0fa6 mov bh, byte ptr cs:[0xa5d]
  SETL(R.bx, M8(CS, (u16)(0xa5e)));                            // 0fab mov bl, byte ptr cs:[0xa5e]
  R.cx = (u16)(M16(CS, (u16)(0xa64)));                         // 0fb0 mov cx, word ptr cs:[0xa64]
  R.dx = (u16)(ADD16(R.dx, M16(CS, (u16)(0xa68))));            // 0fb5 add dx, word ptr cs:[0xa68]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0xa54))));            // 0fba sub ax, word ptr cs:[0xa54]
  if (R.zf) goto L_0fe0;                                       // 0fbf je 0xfe0
  if (R.cf) goto L_0fd1;                                       // 0fc1 jb 0xfd1
  R.di = (u16)(ADD16(R.di, R.ax));                             // 0fc3 add di, ax
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 0fc5 sub cx, ax
  if (R.cf || R.zf) goto L_1017;                               // 0fc7 jbe 0x1017
  SETH(R.bx, M8(CS, (u16)(0xa5a)));                            // 0fc9 mov bh, byte ptr cs:[0xa5a]
  goto L_0fe5;                                                 // 0fce jmp 0xfe5
L_0fd1:   R.ax = (u16)(NEG16(R.ax));                                   // 0fd1 neg ax
  R.dx = (u16)(SUB16(R.dx, R.ax));                             // 0fd3 sub dx, ax
  if (R.cf || R.zf) goto L_1017;                               // 0fd5 jbe 0x1017
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0fd7 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0fd9 shl ax, 1
  R.si = (u16)(ADD16(R.si, R.ax));                             // 0fdb add si, ax
  goto L_0fe5;                                                 // 0fdd jmp 0xfe5
L_0fe0:   SETH(R.bx, AND8((u8)(R.bx >> 8), M8(CS, (u16)(0xa5a))));     // 0fe0 and bh, byte ptr cs:[0xa5a]
L_0fe5:   SUB16(R.dx, R.cx);                                           // 0fe5 cmp dx, cx
  if (R.zf) goto L_0ff5;                                       // 0fe7 je 0xff5
  if (!R.cf && !R.zf) goto L_0ffa;                             // 0fe9 ja 0xffa
  R.cx = (u16)(R.dx);                                          // 0feb mov cx, dx
  SETL(R.bx, M8(CS, (u16)(0xa5b)));                            // 0fed mov bl, byte ptr cs:[0xa5b]
  goto L_0ffa;                                                 // 0ff2 jmp 0xffa
L_0ff5:   SETL(R.bx, AND8((u8)R.bx, M8(CS, (u16)(0xa5b))));            // 0ff5 and bl, byte ptr cs:[0xa5b]
L_0ffa:   W8(CS, (u16)(0xa5c), (u8)R.bx);                              // 0ffa mov byte ptr cs:[0xa5c], bl
  SETL(R.bx, (u8)R.cx);                                        // 0fff mov bl, cl
  R.si = (u16)(SUB16(R.si, 0x4));                              // 1001 sub si, 4
  SUB8(M8(CS, (u16)(0xa6a)), 0x0);                             // 1004 cmp byte ptr cs:[0xa6a], 0
  if (R.zf) goto L_1011;                                       // 100a je 0x1011
  if (R.sf) goto L_1043;                                       // 100c js 0x1043
  goto L_10b1;                                                 // 100e jmp 0x10b1
L_1011:   R.si = (u16)(ADD16(R.si, 0x4));                              // 1011 add si, 4
  goto L_111f;                                                 // 1014 jmp 0x111f
L_1017:   R.di = POP();                                                // 1017 pop di
  R.si = POP();                                                // 1018 pop si
L_1019:   R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x1c70))));           // 1019 add di, word ptr cs:[0x1c70]
  W8(CS, (u16)(0xa62), DEC8(M8(CS, (u16)(0xa62))));            // 101e dec byte ptr cs:[0xa62]
  if (R.zf) goto L_1028;                                       // 1023 je 0x1028
  goto L_0f94;                                                 // 1025 jmp 0xf94
L_1028:   R.dx = (u16)(0x3ce);                                         // 1028 mov dx, 0x3ce
  R.ax = (u16)(0xff08);                                        // 102b mov ax, 0xff08
  W8(CS, (u16)(0x1c72), (u8)(R.ax >> 8));                      // 102e mov byte ptr cs:[0x1c72], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1033 out dx, ax
  R.dx = (u16)(0x3c4);                                         // 1034 mov dx, 0x3c4
  R.ax = (u16)(0xf02);                                         // 1037 mov ax, 0xf02
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 103a mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 103f out dx, ax
  R.es = POP();                                                // 1040 pop es
  R.bp = POP();                                                // 1041 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 1042 retf
L_1043:   { u16 t_ = R.bp; R.bp = (u16)(R.bx); R.bx = (u16)(t_); }     // 1043 xchg bp, bx
  SETL(R.cx, M8(CS, (u16)(0xa6a)));                            // 1045 mov cl, byte ptr cs:[0xa6a]
  SETL(R.cx, NEG8((u8)R.cx));                                  // 104a neg cl
  LODSW();                                                     // 104c lodsw ax, word ptr [si]
  R.dx = (u16)(R.ax);                                          // 104d mov dx, ax
  LODSW();                                                     // 104f lodsw ax, word ptr [si]
  R.bx = (u16)(R.ax);                                          // 1050 mov bx, ax
  LODSW();                                                     // 1052 lodsw ax, word ptr [si]
  { u16 t_ = (u8)(R.ax >> 8); SETH(R.ax, (u8)R.dx); SETL(R.dx, t_); } // 1053 xchg ah, dl
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 1055 shl ax, cl
  R.dx = (u16)(SHL16(R.dx, (u8)R.cx));                         // 1057 shl dx, cl
  SETL(R.dx, (u8)(R.ax >> 8));                                 // 1059 mov dl, ah
  LODSW();                                                     // 105b lodsw ax, word ptr [si]
  R.si = (u16)(SUB16(R.si, 0x4));                              // 105c sub si, 4
  { u16 t_ = (u8)(R.ax >> 8); SETH(R.ax, (u8)R.bx); SETL(R.bx, t_); } // 105f xchg ah, bl
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 1061 shl ax, cl
  R.bx = (u16)(SHL16(R.bx, (u8)R.cx));                         // 1063 shl bx, cl
  SETL(R.bx, (u8)(R.ax >> 8));                                 // 1065 mov bl, ah
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));           // 1067 or ah, bh
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.dx));                  // 1069 or ah, dl
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.dx >> 8)));           // 106b or ah, dh
  R.cx = (u16)(R.dx);                                          // 106d mov cx, dx
  { u16 t_ = R.bx; R.bx = (u16)(R.bp); R.bp = (u16)(t_); }     // 106f xchg bx, bp
  SUB8((u8)R.bx, 0x1);                                         // 1071 cmp bl, 1
  if (R.zf) goto L_10a7;                                       // 1074 je 0x10a7
L_1076:   SETH(R.ax, AND8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));          // 1076 and ah, bh
  if (R.zf) goto L_10ae;                                       // 1078 je 0x10ae
  // 107a cli 
  SETL(R.ax, 0x8);                                             // 107b mov al, 8
  R.dx = (u16)(0x3ce);                                         // 107d mov dx, 0x3ce
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1080 out dx, ax
  SETL(R.dx, 0xc4);                                            // 1081 mov dl, 0xc4
  R.ax = (u16)(0x102);                                         // 1083 mov ax, 0x102
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1086 out dx, ax
  { u16 t_ = M8(ES, (u16)(R.di)); W8(ES, (u16)(R.di), (u8)R.cx); SETL(R.cx, t_); } // 1087 xchg byte ptr es:[di], cl
  R.dx = (u16)(INC16(R.dx));                                   // 108a inc dx
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 108b out dx, al
  W8(ES, (u16)(R.di), (u8)(R.cx >> 8));                        // 108c mov byte ptr es:[di], ch
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 108f shl al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1091 out dx, al
  R.cx = (u16)(R.bp);                                          // 1092 mov cx, bp
  W8(ES, (u16)(R.di), (u8)R.cx);                               // 1094 mov byte ptr es:[di], cl
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 1097 shl al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1099 out dx, al
  SETL(R.ax, (u8)(R.cx >> 8));                                 // 109a mov al, ch
  STOSB();                                                     // 109c stosb byte ptr es:[di], al
  // 109d sti 
L_109e:   SETH(R.bx, 0xff);                                            // 109e mov bh, 0xff
  SETL(R.bx, DEC8((u8)R.bx));                                  // 10a0 dec bl
  if (!R.zf) goto L_1043;                                      // 10a2 jne 0x1043
  goto L_1017;                                                 // 10a4 jmp 0x1017
L_10a7:   SETH(R.bx, AND8((u8)(R.bx >> 8), M8(CS, (u16)(0xa5c))));     // 10a7 and bh, byte ptr cs:[0xa5c]
  goto L_1076;                                                 // 10ac jmp 0x1076
L_10ae:   R.di = (u16)(INC16(R.di));                                   // 10ae inc di
  goto L_109e;                                                 // 10af jmp 0x109e
L_10b1:   { u16 t_ = R.bp; R.bp = (u16)(R.bx); R.bx = (u16)(t_); }     // 10b1 xchg bp, bx
  SETL(R.cx, M8(CS, (u16)(0xa6a)));                            // 10b3 mov cl, byte ptr cs:[0xa6a]
  LODSW();                                                     // 10b8 lodsw ax, word ptr [si]
  R.dx = (u16)(R.ax);                                          // 10b9 mov dx, ax
  LODSW();                                                     // 10bb lodsw ax, word ptr [si]
  R.bx = (u16)(R.ax);                                          // 10bc mov bx, ax
  LODSW();                                                     // 10be lodsw ax, word ptr [si]
  { u16 t_ = (u8)(R.ax >> 8); SETH(R.ax, (u8)R.dx); SETL(R.dx, t_); } // 10bf xchg ah, dl
  R.ax = (u16)(SHR16(R.ax, (u8)R.cx));                         // 10c1 shr ax, cl
  R.dx = (u16)(SHR16(R.dx, (u8)R.cx));                         // 10c3 shr dx, cl
  SETH(R.dx, (u8)R.ax);                                        // 10c5 mov dh, al
  LODSW();                                                     // 10c7 lodsw ax, word ptr [si]
  R.si = (u16)(SUB16(R.si, 0x4));                              // 10c8 sub si, 4
  { u16 t_ = (u8)(R.ax >> 8); SETH(R.ax, (u8)R.bx); SETL(R.bx, t_); } // 10cb xchg ah, bl
  R.ax = (u16)(ROR16(R.ax, (u8)R.cx));                         // 10cd ror ax, cl
  R.bx = (u16)(ROR16(R.bx, (u8)R.cx));                         // 10cf ror bx, cl
  SETH(R.bx, (u8)R.ax);                                        // 10d1 mov bh, al
  SETH(R.ax, (u8)R.bx);                                        // 10d3 mov ah, bl
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));           // 10d5 or ah, bh
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.dx));                  // 10d7 or ah, dl
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.dx >> 8)));           // 10d9 or ah, dh
  R.cx = (u16)(R.dx);                                          // 10db mov cx, dx
  { u16 t_ = R.bx; R.bx = (u16)(R.bp); R.bp = (u16)(t_); }     // 10dd xchg bx, bp
  SUB8((u8)R.bx, 0x1);                                         // 10df cmp bl, 1
  if (R.zf) goto L_1115;                                       // 10e2 je 0x1115
L_10e4:   SETH(R.ax, AND8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));          // 10e4 and ah, bh
  if (R.zf) goto L_111c;                                       // 10e6 je 0x111c
  // 10e8 cli 
  SETL(R.ax, 0x8);                                             // 10e9 mov al, 8
  R.dx = (u16)(0x3ce);                                         // 10eb mov dx, 0x3ce
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 10ee out dx, ax
  SETL(R.dx, 0xc4);                                            // 10ef mov dl, 0xc4
  R.ax = (u16)(0x102);                                         // 10f1 mov ax, 0x102
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 10f4 out dx, ax
  { u16 t_ = M8(ES, (u16)(R.di)); W8(ES, (u16)(R.di), (u8)(R.cx >> 8)); SETH(R.cx, t_); } // 10f5 xchg byte ptr es:[di], ch
  R.dx = (u16)(INC16(R.dx));                                   // 10f8 inc dx
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 10f9 out dx, al
  W8(ES, (u16)(R.di), (u8)R.cx);                               // 10fa mov byte ptr es:[di], cl
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 10fd shl al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 10ff out dx, al
  R.cx = (u16)(R.bp);                                          // 1100 mov cx, bp
  W8(ES, (u16)(R.di), (u8)(R.cx >> 8));                        // 1102 mov byte ptr es:[di], ch
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 1105 shl al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1107 out dx, al
  SETL(R.ax, (u8)R.cx);                                        // 1108 mov al, cl
  STOSB();                                                     // 110a stosb byte ptr es:[di], al
  // 110b sti 
L_110c:   SETH(R.bx, 0xff);                                            // 110c mov bh, 0xff
  SETL(R.bx, DEC8((u8)R.bx));                                  // 110e dec bl
  if (!R.zf) goto L_10b1;                                      // 1110 jne 0x10b1
  goto L_1017;                                                 // 1112 jmp 0x1017
L_1115:   SETH(R.bx, AND8((u8)(R.bx >> 8), M8(CS, (u16)(0xa5c))));     // 1115 and bh, byte ptr cs:[0xa5c]
  goto L_10e4;                                                 // 111a jmp 0x10e4
L_111c:   R.di = (u16)(INC16(R.di));                                   // 111c inc di
  goto L_110c;                                                 // 111d jmp 0x110c
L_111f:   LODSW();                                                     // 111f lodsw ax, word ptr [si]
  R.cx = (u16)(R.ax);                                          // 1120 mov cx, ax
  LODSW();                                                     // 1122 lodsw ax, word ptr [si]
  R.bp = (u16)(R.ax);                                          // 1123 mov bp, ax
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.ax));                  // 1125 or ah, al
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.cx));                  // 1127 or ah, cl
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.cx >> 8)));           // 1129 or ah, ch
  SUB8((u8)R.bx, 0x1);                                         // 112b cmp bl, 1
  if (R.zf) goto L_1161;                                       // 112e je 0x1161
L_1130:   SETH(R.ax, AND8((u8)(R.ax >> 8), (u8)(R.bx >> 8)));          // 1130 and ah, bh
  if (R.zf) goto L_1168;                                       // 1132 je 0x1168
  // 1134 cli 
  SETL(R.ax, 0x8);                                             // 1135 mov al, 8
  R.dx = (u16)(0x3ce);                                         // 1137 mov dx, 0x3ce
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 113a out dx, ax
  SETL(R.dx, 0xc4);                                            // 113b mov dl, 0xc4
  R.ax = (u16)(0x102);                                         // 113d mov ax, 0x102
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1140 out dx, ax
  { u16 t_ = M8(ES, (u16)(R.di)); W8(ES, (u16)(R.di), (u8)R.cx); SETL(R.cx, t_); } // 1141 xchg byte ptr es:[di], cl
  R.dx = (u16)(INC16(R.dx));                                   // 1144 inc dx
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1145 out dx, al
  W8(ES, (u16)(R.di), (u8)(R.cx >> 8));                        // 1146 mov byte ptr es:[di], ch
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 1149 shl al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 114b out dx, al
  R.cx = (u16)(R.bp);                                          // 114c mov cx, bp
  W8(ES, (u16)(R.di), (u8)R.cx);                               // 114e mov byte ptr es:[di], cl
  SETL(R.ax, SHL8((u8)R.ax, 0x1));                             // 1151 shl al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1153 out dx, al
  SETL(R.ax, (u8)(R.cx >> 8));                                 // 1154 mov al, ch
  STOSB();                                                     // 1156 stosb byte ptr es:[di], al
  // 1157 sti 
L_1158:   SETH(R.bx, 0xff);                                            // 1158 mov bh, 0xff
  SETL(R.bx, DEC8((u8)R.bx));                                  // 115a dec bl
  if (!R.zf) goto L_111f;                                      // 115c jne 0x111f
  goto L_1017;                                                 // 115e jmp 0x1017
L_1161:   SETH(R.bx, AND8((u8)(R.bx >> 8), M8(CS, (u16)(0xa5c))));     // 1161 and bh, byte ptr cs:[0xa5c]
  goto L_1130;                                                 // 1166 jmp 0x1130
L_1168:   R.di = (u16)(INC16(R.di));                                   // 1168 inc di
  goto L_1158;                                                 // 1169 jmp 0x1158
L_116c:   R.ax = (u16)(OR16(R.ax, R.ax));                              // 116c or ax, ax
  if (R.sf) goto L_11cd;                                       // 116e js 0x11cd
  PUSH(R.ds);                                                  // 1170 push ds
  PUSH(R.es);                                                  // 1171 push es
  R.si = (u16)(SHL16(R.si, 0x1));                              // 1172 shl si, 1
  R.di = (u16)(SHL16(R.di, 0x1));                              // 1174 shl di, 1
  R.ds = (u16)(M16(CS, (u16)(R.si + 0x1c58)));                 // 1176 mov ds, word ptr cs:[si + 0x1c58]
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1c58)));                 // 117b mov es, word ptr cs:[di + 0x1c58]
  R.bp = (u16)(R.bx);                                          // 1180 mov bp, bx
  R.bx = (u16)(R.ax);                                          // 1182 mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1184 shl bx, 1
  R.dx = (u16)(0x3ce);                                         // 1186 mov dx, 0x3ce
  R.ax = (u16)(0x8);                                           // 1189 mov ax, 8
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 118c out dx, ax
  R.dx = (u16)(R.cx);                                          // 118d mov dx, cx
  R.dx = (u16)(SHL16(R.dx, 0x1));                              // 118f shl dx, 1
L_1191:   R.si = (u16)(R.bx);                                          // 1191 mov si, bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si)));                   // 1193 mov ax, word ptr [bp + si]
  R.cx = (u16)(M16(SS, (u16)(R.bp + R.si + 0x190)));           // 1195 mov cx, word ptr [bp + si + 0x190]
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 1199 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 119b shr ax, 1
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 119d shr cx, 1
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 119f shr cx, 1
  SUB16(M16(CS, (u16)(0x1c56)), 0x1);                          // 11a1 cmp word ptr cs:[0x1c56], 1
  if (R.zf) goto L_11ad;                                       // 11a7 je 0x11ad
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 11a9 shr cx, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 11ab shr ax, 1
L_11ad:   R.cx = (u16)(SUB16(R.cx, R.ax));                             // 11ad sub cx, ax
  if (R.cf) goto L_11bd;                                       // 11af jb 0x11bd
  R.cx = (u16)(INC16(R.cx));                                   // 11b1 inc cx
  R.di = (u16)(M16(CS, (u16)(R.si + 0x192e)));                 // 11b2 mov di, word ptr cs:[si + 0x192e]
  R.di = (u16)(ADD16(R.di, R.ax));                             // 11b7 add di, ax
  R.si = (u16)(R.di);                                          // 11b9 mov si, di
  REPMOVSB();                                                  // 11bb rep movsb byte ptr es:[di], byte ptr [si]
L_11bd:   R.bx = (u16)(ADD16(R.bx, 0x2));                              // 11bd add bx, 2
  SUB16(R.bx, R.dx);                                           // 11c0 cmp bx, dx
  if (R.cf || R.zf) goto L_1191;                               // 11c2 jbe 0x1191
  R.dx = (u16)(0x3ce);                                         // 11c4 mov dx, 0x3ce
  R.ax = (u16)(0xff08);                                        // 11c7 mov ax, 0xff08
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 11ca out dx, ax
  R.es = POP();                                                // 11cb pop es
  R.ds = POP();                                                // 11cc pop ds
L_11cd:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 11cd retf
L_11e1:   R.bx = (u16)(R.sp);                                          // 11e1 mov bx, sp
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x4)));                       // 11e3 mov al, byte ptr [bx + 4]
  W8(CS, (u16)(0x11e0), (u8)R.ax);                             // 11e6 mov byte ptr cs:[0x11e0], al
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 11ea retf
L_11eb:   R.ax = (u16)(M16(CS, (u16)(0x11de)));                        // 11eb mov ax, word ptr cs:[0x11de]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 11ef shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 11f1 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x11de))));           // 11f3 add ax, word ptr cs:[0x11de]
  R.ax = (u16)(INC16(R.ax));                                   // 11f8 inc ax
  W16(CS, (u16)(0x11de), R.ax);                                // 11f9 mov word ptr cs:[0x11de], ax
  R.bx = (u16)(R.ax);                                          // 11fd mov bx, ax
  R.bx = (u16)(AND16(R.bx, 0xf));                              // 11ff and bx, 0xf
  SETL(R.cx, M8(CS, (u16)(R.bx + 0x11ce)));                    // 1202 mov cl, byte ptr cs:[bx + 0x11ce]
  R.dx = (u16)(0x3da);                                         // 1207 mov dx, 0x3da
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 120a in al, dx
  AND8((u8)R.ax, 0x8);                                         // 120b test al, 8
  if (R.zf) goto L_123a;                                       // 120d je 0x123a
  // 120f cli 
  R.dx = (u16)(0x3c0);                                         // 1210 mov dx, 0x3c0
  SETL(R.ax, 0xd);                                             // 1213 mov al, 0xd
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1215 out dx, al
  SETL(R.ax, (u8)R.cx);                                        // 1216 mov al, cl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1218 out dx, al
  SUB8(M8(CS, (u16)(0x11e0)), 0x0);                            // 1219 cmp byte ptr cs:[0x11e0], 0
  if (R.zf) goto L_1232;                                       // 121f je 0x1232
  W8(CS, (u16)(0x11e0), DEC8(M8(CS, (u16)(0x11e0))));          // 1221 dec byte ptr cs:[0x11e0]
  if (!R.zf) goto L_122a;                                      // 1226 jne 0x122a
  SETL(R.bx, XOR8((u8)R.bx, (u8)R.bx));                        // 1228 xor bl, bl
L_122a:   SETL(R.ax, 0x13);                                            // 122a mov al, 0x13
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 122c out dx, al
  SETL(R.ax, (u8)R.bx);                                        // 122d mov al, bl
  SETL(R.ax, AND8((u8)R.ax, 0x7));                             // 122f and al, 7
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1231 out dx, al
L_1232:   SETL(R.ax, 0x20);                                            // 1232 mov al, 0x20
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1234 out dx, al
  R.dx = (u16)(0x3da);                                         // 1235 mov dx, 0x3da
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 1238 in al, dx
  // 1239 sti 
L_123a:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 123a retf
L_123c:   SETL(R.ax, AND8((u8)R.ax, 0x7f));                            // 123c and al, 0x7f
  W8(DS, (u16)(0x6c4), (u8)R.ax);                              // 123e mov byte ptr [0x6c4], al
  SETH(R.ax, (u8)R.ax);                                        // 1241 mov ah, al
  PUSH(0x4887); PUSH(0x1248); goto L_01d5;                     // 1243 lcall 0, 0x1d5
L_1248:   goto L_12cd;                                                 // 1248 jmp 0x12cd
L_124b:   R.dx = (u16)(0x3ce);                                         // 124b mov dx, 0x3ce
  R.ax = (u16)(0x1);                                           // 124e mov ax, 1
  W8(CS, (u16)(0x1c75), (u8)(R.ax >> 8));                      // 1251 mov byte ptr cs:[0x1c75], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1256 out dx, ax
  R.ax = (u16)(0xff08);                                        // 1257 mov ax, 0xff08
  W8(CS, (u16)(0x1c72), (u8)(R.ax >> 8));                      // 125a mov byte ptr cs:[0x1c72], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 125f out dx, ax
  R.bp = POP();                                                // 1260 pop bp
  SETL(R.ax, M8(DS, (u16)(0x6c4)));                            // 1261 mov al, byte ptr [0x6c4]
  W8(SS, (u16)(R.bp + 0xc), (u8)R.ax);                         // 1264 mov byte ptr [bp + 0xc], al
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 1267 retf
L_1268:   goto L_124b;                                                 // 1268 jmp 0x124b
L_126a:   goto L_123c;                                                 // 126a jmp 0x123c
L_126c:   SETL(R.ax, M8(SS, (u16)(R.bp + 0xc)));                       // 126c mov al, byte ptr [bp + 0xc]
  W8(DS, (u16)(0x6c4), (u8)R.ax);                              // 126f mov byte ptr [0x6c4], al
  SETH(R.ax, (u8)R.ax);                                        // 1272 mov ah, al
  PUSH(0x4887); PUSH(0x1279); goto L_01d5;                     // 1274 lcall 0, 0x1d5
L_1279:   SETL(R.ax, M8(SS, (u16)(R.bp + 0xe)));                       // 1279 mov al, byte ptr [bp + 0xe]
  W8(DS, (u16)(0x6c5), (u8)R.ax);                              // 127c mov byte ptr [0x6c5], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xa)));                       // 127f mov al, byte ptr [bp + 0xa]
  W8(DS, (u16)(0x6c6), (u8)R.ax);                              // 1282 mov byte ptr [0x6c6], al
  PUSH(R.bp);                                                  // 1285 push bp
  R.bp = (u16)(M16(DS, (u16)(0x6e1)));                         // 1286 mov bp, word ptr [0x6e1]
  R.bx = (u16)(R.es);                                          // 128a mov bx, es
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 128c shl bx, 1
  R.es = (u16)(M16(CS, (u16)(R.bx + 0x1c58)));                 // 128e mov es, word ptr cs:[bx + 0x1c58]
  R.bx = (u16)(M16(DS, (u16)(0x6e5)));                         // 1293 mov bx, word ptr [0x6e5]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1297 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2de)));                  // 1299 mov ax, word ptr [bx + 0x2de]
  W16(DS, (u16)(0x6cf), R.ax);                                 // 129d mov word ptr [0x6cf], ax
  R.ax = (u16)(M16(CS, (u16)(0x1c70)));                        // 12a0 mov ax, word ptr cs:[0x1c70]
  MUL8(M8(DS, (u16)(0x6df)));                                  // 12a4 mul byte ptr [0x6df]
  W16(DS, (u16)(0x6ca), R.ax);                                 // 12a8 mov word ptr [0x6ca], ax
  R.ax = (u16)(M16(DS, (u16)(0x6e1)));                         // 12ab mov ax, word ptr [0x6e1]
  MUL8(M8(DS, (u16)(0x6df)));                                  // 12ae mul byte ptr [0x6df]
  W16(DS, (u16)(0x6cd), R.ax);                                 // 12b2 mov word ptr [0x6cd], ax
  R.dx = (u16)(0x3c4);                                         // 12b5 mov dx, 0x3c4
  R.ax = (u16)(0xf02);                                         // 12b8 mov ax, 0xf02
  W8(CS, (u16)(0x1c76), (u8)(R.ax >> 8));                      // 12bb mov byte ptr cs:[0x1c76], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 12c0 out dx, ax
  R.dx = (u16)(0x3ce);                                         // 12c1 mov dx, 0x3ce
  R.ax = (u16)(0xff01);                                        // 12c4 mov ax, 0xff01
  W8(CS, (u16)(0x1c75), (u8)(R.ax >> 8));                      // 12c7 mov byte ptr cs:[0x1c75], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 12cc out dx, ax
L_12cd:   R.ax = (u16)(M16(SS, (u16)(R.si)));                          // 12cd mov ax, word ptr ss:[si]
  R.si = (u16)(INC16(R.si));                                   // 12d0 inc si
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 12d1 or al, al
  if (R.zf) goto L_1268;                                       // 12d3 je 0x1268
  if (R.sf) goto L_126a;                                       // 12d5 js 0x126a
  PUSH(R.si);                                                  // 12d7 push si
  SETL(R.ax, SUB8((u8)R.ax, M8(DS, (u16)(0x6d4))));            // 12d8 sub al, byte ptr [0x6d4]
  R.si = (u16)(R.ax);                                          // 12dc mov si, ax
  R.si = (u16)(AND16(R.si, 0xff));                             // 12de and si, 0xff
  SETL(R.cx, M8(DS, (u16)(0x6d9)));                            // 12e2 mov cl, byte ptr [0x6d9]
  SETL(R.cx, OR8((u8)R.cx, (u8)R.cx));                         // 12e6 or cl, cl
  if (!R.zf) goto L_12f4;                                      // 12e8 jne 0x12f4
  R.bx = (u16)(M16(DS, (u16)(0x6d2)));                         // 12ea mov bx, word ptr [0x6d2]
  SETL(R.cx, M8(DS, (u16)(R.bx + R.si)));                      // 12ee mov cl, byte ptr [bx + si]
  SETL(R.cx, ADD8((u8)R.cx, M8(DS, (u16)(0x6d5))));            // 12f0 add cl, byte ptr [0x6d5]
L_12f4:   SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 12f4 or ah, ah
  if (!R.zf) goto L_12fc;                                      // 12f6 jne 0x12fc
  SETL(R.cx, SUB8((u8)R.cx, M8(DS, (u16)(0x6de))));            // 12f8 sub cl, byte ptr [0x6de]
L_12fc:   SETL(R.cx, SUB8((u8)R.cx, M8(DS, (u16)(0x6da))));            // 12fc sub cl, byte ptr [0x6da]
  W8(DS, (u16)(0x6cc), (u8)R.cx);                              // 1300 mov byte ptr [0x6cc], cl
  SETL(R.cx, DEC8((u8)R.cx));                                  // 1304 dec cl
  R.bx = (u16)(0x8000);                                        // 1306 mov bx, 0x8000
  R.bx = (u16)(SAR16(R.bx, (u8)R.cx));                         // 1309 sar bx, cl
  W16(DS, (u16)(0x6c8), R.bx);                                 // 130b mov word ptr [0x6c8], bx
  R.ax = (u16)(M16(DS, (u16)(0x6e3)));                         // 130f mov ax, word ptr [0x6e3]
  SETL(R.cx, (u8)R.ax);                                        // 1312 mov cl, al
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 1314 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 1316 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 1318 shr ax, 1
  R.di = (u16)(M16(DS, (u16)(0x6cf)));                         // 131a mov di, word ptr [0x6cf]
  R.di = (u16)(ADD16(R.di, R.ax));                             // 131e add di, ax
  SETL(R.cx, AND8((u8)R.cx, 0x7));                             // 1320 and cl, 7
  R.bx = (u16)(SHR16(R.bx, (u8)R.cx));                         // 1323 shr bx, cl
  SETL(R.cx, SUB8((u8)R.cx, 0x8));                             // 1325 sub cl, 8
  SETL(R.cx, NEG8((u8)R.cx));                                  // 1328 neg cl
  W8(DS, (u16)(0x6c7), (u8)R.cx);                              // 132a mov byte ptr [0x6c7], cl
  SETL(R.cx, M8(DS, (u16)(0x6d8)));                            // 132e mov cl, byte ptr [0x6d8]
  R.si = (u16)(SHL16(R.si, (u8)R.cx));                         // 1332 shl si, cl
  R.si = (u16)(ADD16(R.si, M16(DS, (u16)(0x6d6))));            // 1334 add si, word ptr [0x6d6]
L_1338:   SUB8(M8(DS, (u16)(0x6c6)), 0x0);                             // 1338 cmp byte ptr [0x6c6], 0
  if (R.zf) goto L_1369;                                       // 133d je 0x1369
  SETH(R.ax, M8(DS, (u16)(0x6c5)));                            // 133f mov ah, byte ptr [0x6c5]
  SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 1343 xor al, al
  W8(CS, (u16)(0x1c79), (u8)(R.ax >> 8));                      // 1345 mov byte ptr cs:[0x1c79], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 134a out dx, ax
  SETL(R.ax, 0x8);                                             // 134b mov al, 8
  SETH(R.ax, (u8)(R.bx >> 8));                                 // 134d mov ah, bh
  W8(CS, (u16)(0x1c72), (u8)(R.ax >> 8));                      // 134f mov byte ptr cs:[0x1c72], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1354 out dx, ax
  SETL(R.cx, M8(DS, (u16)(0x6df)));                            // 1355 mov cl, byte ptr [0x6df]
  SETH(R.cx, XOR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 1359 xor ch, ch
L_135b:   W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 135b inc byte ptr es:[di]
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x1c70))));           // 135e add di, word ptr cs:[0x1c70]
  if (--R.cx != 0) goto L_135b;                                // 1363 loop 0x135b
  R.di = (u16)(SUB16(R.di, M16(DS, (u16)(0x6ca))));            // 1365 sub di, word ptr [0x6ca]
L_1369:   SETH(R.ax, M8(DS, (u16)(0x6c4)));                            // 1369 mov ah, byte ptr [0x6c4]
  SETL(R.ax, SUB8((u8)R.ax, (u8)R.ax));                        // 136d sub al, al
  W8(CS, (u16)(0x1c79), (u8)(R.ax >> 8));                      // 136f mov byte ptr cs:[0x1c79], ah
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 1374 out dx, ax
  SETL(R.ax, 0x8);                                             // 1375 mov al, 8
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1377 out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 1378 inc dx
  SETL(R.cx, M8(DS, (u16)(0x6c7)));                            // 1379 mov cl, byte ptr [0x6c7]
  SETL(R.cx, ADD8((u8)R.cx, M8(DS, (u16)(0x6da))));            // 137d add cl, byte ptr [0x6da]
  SETL(R.cx, AND8((u8)R.cx, 0xf));                             // 1381 and cl, 0xf
  SETH(R.cx, M8(DS, (u16)(0x6df)));                            // 1384 mov ch, byte ptr [0x6df]
  // 1388 cli 
L_1389:   R.ax = (u16)(M16(DS, (u16)(R.si)));                          // 1389 mov ax, word ptr [si]
  { u16 t_ = (u8)R.ax; SETL(R.ax, (u8)(R.ax >> 8)); SETH(R.ax, t_); } // 138b xchg al, ah
  R.ax = (u16)(ROL16(R.ax, (u8)R.cx));                         // 138d rol ax, cl
  SETL(R.ax, AND8((u8)R.ax, (u8)(R.bx >> 8)));                 // 138f and al, bh
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 1391 out dx, al
  W8(ES, (u16)(R.di), INC8(M8(ES, (u16)(R.di))));              // 1392 inc byte ptr es:[di]
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x1c70))));           // 1395 add di, word ptr cs:[0x1c70]
  R.si = (u16)(ADD16(R.si, R.bp));                             // 139a add si, bp
  SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 139c dec ch
  if (!R.zf) goto L_1389;                                      // 139e jne 0x1389
  // 13a0 sti 
  R.dx = (u16)(DEC16(R.dx));                                   // 13a1 dec dx
  R.di = (u16)(INC16(R.di));                                   // 13a2 inc di
  R.di = (u16)(SUB16(R.di, M16(DS, (u16)(0x6ca))));            // 13a3 sub di, word ptr [0x6ca]
  R.si = (u16)(SUB16(R.si, M16(DS, (u16)(0x6cd))));            // 13a7 sub si, word ptr [0x6cd]
  SETL(R.cx, M8(DS, (u16)(0x6c7)));                            // 13ab mov cl, byte ptr [0x6c7]
  SUB8((u8)R.cx, M8(DS, (u16)(0x6cc)));                        // 13af cmp cl, byte ptr [0x6cc]
  if (!R.cf) goto L_13c3;                                      // 13b3 jae 0x13c3
  R.bx = (u16)(M16(DS, (u16)(0x6c8)));                         // 13b5 mov bx, word ptr [0x6c8]
  R.bx = (u16)(SHL16(R.bx, (u8)R.cx));                         // 13b9 shl bx, cl
  W8(DS, (u16)(0x6c7), ADD8(M8(DS, (u16)(0x6c7)), 0x8));       // 13bb add byte ptr [0x6c7], 8
  goto L_1338;                                                 // 13c0 jmp 0x1338
L_13c3:   R.si = POP();                                                // 13c3 pop si
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 13c4 xor ah, ah
  W8(DS, (u16)(0x6da), (u8)(R.ax >> 8));                       // 13c6 mov byte ptr [0x6da], ah
  SETL(R.ax, M8(DS, (u16)(0x6cc)));                            // 13ca mov al, byte ptr [0x6cc]
  W16(DS, (u16)(0x6e3), ADD16(M16(DS, (u16)(0x6e3)), R.ax));   // 13cd add word ptr [0x6e3], ax
  goto L_12cd;                                                 // 13d1 jmp 0x12cd
L_13d4:   PUSH(R.bp);                                                  // 13d4 push bp
  R.bp = (u16)(R.sp);                                          // 13d5 mov bp, sp
  PUSH(R.si);                                                  // 13d7 push si
  PUSH(R.di);                                                  // 13d8 push di
  PUSH(R.es);                                                  // 13d9 push es
  R.ax = (u16)(0x49ec /* segment */);                          // 13da mov ax, 0x165
  R.es = (u16)(R.ax);                                          // 13dd mov es, ax
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 13df mov si, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 13e2 mov di, word ptr [bp + 6]
  SUB16(R.di, 0x0);                                            // 13e5 cmp di, 0
  if (R.zf) goto L_141e;                                       // 13e8 je 0x141e
  SUB16(R.di, M16(ES, (u16)(0x6e8)));                          // 13ea cmp di, word ptr es:[0x6e8]
  if (!R.cf && !R.zf) goto L_141e;                             // 13ef ja 0x141e
  R.di = (u16)(SHL16(R.di, 0x1));                              // 13f1 shl di, 1
  R.di = (u16)(M16(ES, (u16)(R.di + 0x6e8)));                  // 13f3 mov di, word ptr es:[di + 0x6e8]
  SETL(R.cx, M8(DS, (u16)(R.si + 0xfff9)));                    // 13f8 mov cl, byte ptr [si - 7]
  SETL(R.cx, SUB8((u8)R.cx, M8(DS, (u16)(R.si + 0xfff8))));    // 13fb sub cl, byte ptr [si - 8]
  SETL(R.cx, INC8((u8)R.cx));                                  // 13fe inc cl
  SETH(R.cx, XOR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 1400 xor ch, ch
  SETH(R.ax, M8(DS, (u16)(R.si + 0xfffc)));                    // 1402 mov ah, byte ptr [si - 4]
  SETH(R.ax, ADD8((u8)(R.ax >> 8), M8(DS, (u16)(R.si + 0xfffe)))); // 1405 add ah, byte ptr [si - 2]
  SETL(R.ax, M8(DS, (u16)(R.si + 0xfffa)));                    // 1408 mov al, byte ptr [si - 6]
  MUL8((u8)(R.ax >> 8));                                       // 140b mul ah
  MUL8((u8)R.cx);                                              // 140d mul cl
  R.cx = (u16)(ADD16(R.cx, 0x8));                              // 140f add cx, 8
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 1412 add ax, cx
  R.si = (u16)(SUB16(R.si, R.cx));                             // 1414 sub si, cx
  R.di = (u16)(SUB16(R.di, R.cx));                             // 1416 sub di, cx
  R.cx = (u16)(R.ax);                                          // 1418 mov cx, ax
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 141a shr cx, 1
  REPMOVSW();                                                  // 141c rep movsw word ptr es:[di], word ptr [si]
L_141e:   R.es = POP();                                                // 141e pop es
  R.di = POP();                                                // 141f pop di
  R.si = POP();                                                // 1420 pop si
  R.bp = POP();                                                // 1421 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 1422 retf
L_1423:   PUSH(R.bp);                                                  // 1423 push bp
  R.bp = (u16)(R.sp);                                          // 1424 mov bp, sp
  PUSH(R.ds);                                                  // 1426 push ds
  R.ax = (u16)(0x49ec /* segment */);                          // 1427 mov ax, 0x165
  R.ds = (u16)(R.ax);                                          // 142a mov ds, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 142c xor ax, ax
  SETL(R.cx, M8(SS, (u16)(R.bp + 0x8)));                       // 142e mov cl, byte ptr [bp + 8]
  SETL(R.cx, OR8((u8)R.cx, (u8)R.cx));                         // 1431 or cl, cl
  if (R.sf) goto L_146a;                                       // 1433 js 0x146a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 1435 mov bx, word ptr [bp + 6]
  SUB16(R.bx, M16(DS, (u16)(0x6e8)));                          // 1438 cmp bx, word ptr [0x6e8]
  if (!R.cf && !R.zf) goto L_146a;                             // 143c ja 0x146a
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 143e shl bx, 1
  if (R.zf) goto L_146a;                                       // 1440 je 0x146a
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x6e8)));                  // 1442 mov bx, word ptr [bx + 0x6e8]
  SUB8((u8)R.cx, M8(DS, (u16)(R.bx + 0xfff8)));                // 1446 cmp cl, byte ptr [bx - 8]
  if (R.cf) goto L_146a;                                       // 1449 jb 0x146a
  SUB8((u8)R.cx, M8(DS, (u16)(R.bx + 0xfff9)));                // 144b cmp cl, byte ptr [bx - 7]
  if (!R.cf && !R.zf) goto L_146a;                             // 144e ja 0x146a
  SETH(R.ax, M8(DS, (u16)(R.bx + 0xfffd)));                    // 1450 mov ah, byte ptr [bx - 3]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xfffb)));                    // 1453 mov al, byte ptr [bx - 5]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 1456 or al, al
  if (!R.zf) goto L_146a;                                      // 1458 jne 0x146a
  SETL(R.ax, (u8)R.cx);                                        // 145a mov al, cl
  SETL(R.cx, M8(DS, (u16)(R.bx + 0xfff9)));                    // 145c mov cl, byte ptr [bx - 7]
  SETL(R.cx, SUB8((u8)R.cx, (u8)R.ax));                        // 145f sub cl, al
  SETH(R.cx, XOR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 1461 xor ch, ch
  R.bx = (u16)(ADD16(R.bx, 0xfff7));                           // 1463 add bx, -9
  R.bx = (u16)(SUB16(R.bx, R.cx));                             // 1466 sub bx, cx
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 1468 mov al, byte ptr [bx]
L_146a:   SETL(R.ax, ADD8((u8)R.ax, (u8)(R.ax >> 8)));                 // 146a add al, ah
  R.ax = (u16)(i16)(i8)R.ax;                                   // 146c cwde
  R.ds = POP();                                                // 146d pop ds
  R.bp = POP();                                                // 146e pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 146f retf
L_1470:   PUSH(R.bp);                                                  // 1470 push bp
  R.bp = (u16)(R.sp);                                          // 1471 mov bp, sp
  PUSH(R.ds);                                                  // 1473 push ds
  R.ax = (u16)(0x49ec /* segment */);                          // 1474 mov ax, 0x165
  R.ds = (u16)(R.ax);                                          // 1477 mov ds, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 1479 xor ax, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 147b mov bx, word ptr [bp + 6]
  SUB16(R.bx, M16(DS, (u16)(0x6e8)));                          // 147e cmp bx, word ptr [0x6e8]
  if (!R.cf && !R.zf) goto L_1492;                             // 1482 ja 0x1492
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 1484 shl bx, 1
  if (R.zf) goto L_1492;                                       // 1486 je 0x1492
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x6e8)));                  // 1488 mov bx, word ptr [bx + 0x6e8]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xfffc)));                    // 148c mov al, byte ptr [bx - 4]
  SETL(R.ax, ADD8((u8)R.ax, M8(DS, (u16)(R.bx + 0xfffe))));    // 148f add al, byte ptr [bx - 2]
L_1492:   R.ds = POP();                                                // 1492 pop ds
  R.bp = POP();                                                // 1493 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 1494 retf
L_1495:   PUSH(R.bp);                                                  // 1495 push bp
  R.bp = (u16)(R.sp);                                          // 1496 mov bp, sp
  PUSH(R.si);                                                  // 1498 push si
  PUSH(R.di);                                                  // 1499 push di
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 149a mov bx, word ptr [bp + 0xc]
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 149d mov cx, word ptr [bp + 8]
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 14a0 mov dx, word ptr [bp + 0xa]
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 14a3 mov bp, word ptr [bp + 6]
  PUSH(0x4887); PUSH(0x14ab); goto L_14af;                     // 14a6 lcall 0, 0x14af
L_14ab:   R.di = POP();                                                // 14ab pop di
  R.si = POP();                                                // 14ac pop si
  R.bp = POP();                                                // 14ad pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 14ae retf
L_14af:   PUSH(0x14b2); goto L_15c6;                                   // 14af call 0x15c6
L_14b2:   PUSH(0x14b5); goto L_1509;                                   // 14b2 call 0x1509
L_14b5:   PUSH(0x14b8); goto L_14c7;                                   // 14b5 call 0x14c7
L_14b8:   PUSH(0x14bb); goto L_155a;                                   // 14b8 call 0x155a
L_14bb:   goto L_159a;                                                 // 14bb jmp 0x159a
L_14be:   PUSH(0x14c1); goto L_15c6;                                   // 14be call 0x15c6
L_14c1:   PUSH(0x14c4); goto L_14c7;                                   // 14c1 call 0x14c7
L_14c4:   goto L_159a;                                                 // 14c4 jmp 0x159a
L_14c7:   SUB8(M8(DS, (u16)(0x6d9)), 0x0);                             // 14c7 cmp byte ptr [0x6d9], 0
  if (R.zf) goto L_14ff;                                       // 14cc je 0x14ff
  SUB16(M16(SS, (u16)(R.bp + 0x6)), 0x0);                      // 14ce cmp word ptr [bp + 6], 0
  if (R.sf) goto L_14fb;                                       // 14d2 js 0x14fb
  R.ax = (u16)(M16(DS, (u16)(0x6e3)));                         // 14d4 mov ax, word ptr [0x6e3]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 14d7 or ax, ax
  if (!R.sf) goto L_14ff;                                      // 14d9 jns 0x14ff
  W16(DS, (u16)(0x6e3), 0x0);                                  // 14db mov word ptr [0x6e3], 0
  R.ax = (u16)(NEG16(R.ax));                                   // 14e1 neg ax
  DIV8(M8(DS, (u16)(0x6d9)), 0x14e3);                          // 14e3 div byte ptr [0x6d9]
  W8(DS, (u16)(0x6da), (u8)(R.ax >> 8));                       // 14e7 mov byte ptr [0x6da], ah
  SETL(R.ax, INC8((u8)R.ax));                                  // 14eb inc al
L_14ed:   SETL(R.ax, DEC8((u8)R.ax));                                  // 14ed dec al
  if (R.zf) goto L_14ff;                                       // 14ef je 0x14ff
L_14f1:   SETH(R.ax, M8(SS, (u16)(R.bx)));                             // 14f1 mov ah, byte ptr ss:[bx]
  R.bx = (u16)(INC16(R.bx));                                   // 14f4 inc bx
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 14f5 or ah, ah
  if (R.sf) goto L_14f1;                                       // 14f7 js 0x14f1
  if (!R.zf) goto L_14ed;                                      // 14f9 jne 0x14ed
L_14fb:   R.ax = POP();                                                // 14fb pop ax
  goto L_15af;                                                 // 14fc jmp 0x15af
L_14ff:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 14ff ret
L_1500:   PUSH(0x1503); goto L_15c6;                                   // 1500 call 0x15c6
L_1503:   PUSH(0x1506); goto L_1509;                                   // 1503 call 0x1509
L_1506:   goto L_159a;                                                 // 1506 jmp 0x159a
L_1509:   SUB8(M8(DS, (u16)(0x6d9)), 0x0);                             // 1509 cmp byte ptr [0x6d9], 0
  if (R.zf) goto L_154c;                                       // 150e je 0x154c
  R.dx = (u16)(M16(DS, (u16)(0x6e3)));                         // 1510 mov dx, word ptr [0x6e3]
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 1514 mov cx, word ptr [bp + 6]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 1517 or cx, cx
  if (R.sf) goto L_154d;                                       // 1519 js 0x154d
  SUB16(R.dx, R.cx);                                           // 151b cmp dx, cx
  if (!R.zf && R.sf == R.of) goto L_154d;                      // 151d jg 0x154d
  R.dx = (u16)(DEC16(R.dx));                                   // 151f dec dx
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 1520 xor ah, ah
  SETL(R.ax, M8(DS, (u16)(0x6d9)));                            // 1522 mov al, byte ptr [0x6d9]
  R.di = (u16)(R.ax);                                          // 1525 mov di, ax
  R.si = (u16)(R.bx);                                          // 1527 mov si, bx
  R.si = (u16)(DEC16(R.si));                                   // 1529 dec si
L_152a:   R.si = (u16)(INC16(R.si));                                   // 152a inc si
  SUB8(M8(SS, (u16)(R.si)), (u8)(R.ax >> 8));                  // 152b cmp byte ptr ss:[si], ah
  if (R.sf) goto L_152a;                                       // 152e js 0x152a
  if (R.zf) goto L_154c;                                       // 1530 je 0x154c
  R.dx = (u16)(ADD16(R.dx, R.di));                             // 1532 add dx, di
  SUB16(R.dx, R.cx);                                           // 1534 cmp dx, cx
  if (R.sf != R.of) goto L_152a;                               // 1536 jl 0x152a
  R.dx = (u16)(SUB16(R.dx, R.cx));                             // 1538 sub dx, cx
  W8(DS, (u16)(0x6de), (u8)R.dx);                              // 153a mov byte ptr [0x6de], dl
  R.si = (u16)(INC16(R.si));                                   // 153e inc si
  SETL(R.ax, M8(SS, (u16)(R.si)));                             // 153f mov al, byte ptr ss:[si]
  W8(SS, (u16)(R.si), (u8)(R.ax >> 8));                        // 1542 mov byte ptr ss:[si], ah
  W8(DS, (u16)(0x6dd), (u8)R.ax);                              // 1545 mov byte ptr [0x6dd], al
  W16(DS, (u16)(0x6db), R.si);                                 // 1548 mov word ptr [0x6db], si
L_154c:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 154c ret
L_154d:   R.ax = POP();                                                // 154d pop ax
  goto L_15af;                                                 // 154e jmp 0x15af
L_1551:   PUSH(0x1554); goto L_15c6;                                   // 1551 call 0x15c6
L_1554:   PUSH(0x1557); goto L_155a;                                   // 1554 call 0x155a
L_1557:   goto L_159a;                                                 // 1557 jmp 0x159a
L_155a:   R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 155a mov cx, word ptr [bp + 8]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 155d or cx, cx
  if (R.sf) goto L_1593;                                       // 155f js 0x1593
  R.ax = (u16)(M16(DS, (u16)(0x6e5)));                         // 1561 mov ax, word ptr [0x6e5]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 1564 or ax, ax
  if (!R.sf) goto L_157e;                                      // 1566 jns 0x157e
  R.ax = (u16)(NEG16(R.ax));                                   // 1568 neg ax
  W16(DS, (u16)(0x6df), SUB16(M16(DS, (u16)(0x6df)), R.ax));   // 156a sub word ptr [0x6df], ax
  if (R.cf || R.zf) goto L_1593;                               // 156e jbe 0x1593
  W16(DS, (u16)(0x6e5), 0x0);                                  // 1570 mov word ptr [0x6e5], 0
  MUL16(M16(DS, (u16)(0x6e1)));                                // 1576 mul word ptr [0x6e1]
  W16(DS, (u16)(0x6d6), ADD16(M16(DS, (u16)(0x6d6)), R.ax));   // 157a add word ptr [0x6d6], ax
L_157e:   R.ax = (u16)(M16(DS, (u16)(0x6e5)));                         // 157e mov ax, word ptr [0x6e5]
  SUB16(R.ax, R.cx);                                           // 1581 cmp ax, cx
  if (!R.cf && !R.zf) goto L_1593;                             // 1583 ja 0x1593
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x6df))));            // 1585 add ax, word ptr [0x6df]
  R.ax = (u16)(DEC16(R.ax));                                   // 1589 dec ax
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 158a sub ax, cx
  if (R.cf || R.zf) goto L_1592;                               // 158c jbe 0x1592
  W16(DS, (u16)(0x6df), SUB16(M16(DS, (u16)(0x6df)), R.ax));   // 158e sub word ptr [0x6df], ax
L_1592:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 1592 ret
L_1593:   R.ax = POP();                                                // 1593 pop ax
  goto L_15af;                                                 // 1594 jmp 0x15af
L_1597:   PUSH(0x159a); goto L_15c6;                                   // 1597 call 0x15c6
L_159a:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x2)));                    // 159a mov ax, word ptr [bp + 2]
  W16(DS, (u16)(0x6e3), ADD16(M16(DS, (u16)(0x6e3)), R.ax));   // 159d add word ptr [0x6e3], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 15a1 mov ax, word ptr [bp + 4]
  W16(DS, (u16)(0x6e5), ADD16(M16(DS, (u16)(0x6e5)), R.ax));   // 15a4 add word ptr [0x6e5], ax
  R.si = (u16)(R.bx);                                          // 15a8 mov si, bx
  PUSH(0x4887); PUSH(0x15af); goto L_126c;                     // 15aa lcall 0, 0x126c
L_15af:   R.bx = (u16)(M16(DS, (u16)(0x6db)));                         // 15af mov bx, word ptr [0x6db]
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 15b3 or bx, bx
  if (R.zf) goto L_15bd;                                       // 15b5 je 0x15bd
  SETL(R.ax, M8(DS, (u16)(0x6dd)));                            // 15b7 mov al, byte ptr [0x6dd]
  W8(SS, (u16)(R.bx), (u8)R.ax);                               // 15ba mov byte ptr ss:[bx], al
L_15bd:   R.ax = (u16)(M16(DS, (u16)(0x6e3)));                         // 15bd mov ax, word ptr [0x6e3]
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0x2))));       // 15c0 sub ax, word ptr [bp + 2]
  R.es = POP();                                                // 15c3 pop es
  R.ds = POP();                                                // 15c4 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 15c5 retf
L_15c6:   R.si = POP();                                                // 15c6 pop si
  PUSH(R.ds);                                                  // 15c7 push ds
  PUSH(R.es);                                                  // 15c8 push es
  R.ax = (u16)(0x49ec /* segment */);                          // 15c9 mov ax, 0x165
  R.ds = (u16)(R.ax);                                          // 15cc mov ds, ax
  R.es = (u16)(M16(SS, (u16)(R.bp)));                          // 15ce mov es, word ptr [bp]
  W16(DS, (u16)(0x6e3), R.cx);                                 // 15d1 mov word ptr [0x6e3], cx
  W16(DS, (u16)(0x6e5), R.dx);                                 // 15d5 mov word ptr [0x6e5], dx
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 15d9 xor ax, ax
  W16(DS, (u16)(0x6db), R.ax);                                 // 15db mov word ptr [0x6db], ax
  W8(DS, (u16)(0x6da), (u8)R.ax);                              // 15de mov byte ptr [0x6da], al
  W8(DS, (u16)(0x6de), (u8)R.ax);                              // 15e1 mov byte ptr [0x6de], al
  SUB8(M8(SS, (u16)(R.bx)), (u8)R.ax);                         // 15e4 cmp byte ptr ss:[bx], al
  if (R.zf) goto L_15af;                                       // 15e7 je 0x15af
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x10)));                   // 15e9 mov di, word ptr [bp + 0x10]
  SUB16(R.di, M16(DS, (u16)(0x6e8)));                          // 15ec cmp di, word ptr [0x6e8]
  if (!R.cf && !R.zf) goto L_15af;                             // 15f0 ja 0x15af
  R.di = (u16)(SHL16(R.di, 0x1));                              // 15f2 shl di, 1
  if (R.zf) goto L_15af;                                       // 15f4 je 0x15af
  R.di = (u16)(M16(DS, (u16)(R.di + 0x6e8)));                  // 15f6 mov di, word ptr [di + 0x6e8]
  W16(DS, (u16)(0x6d6), R.di);                                 // 15fa mov word ptr [0x6d6], di
  SETL(R.ax, M8(DS, (u16)(R.di + 0xfffc)));                    // 15fe mov al, byte ptr [di - 4]
  AND8(M8(SS, (u16)(R.bp + 0xa)), 0x1);                        // 1601 test byte ptr [bp + 0xa], 1
  if (R.zf) goto L_160a;                                       // 1605 je 0x160a
  SETL(R.ax, ADD8((u8)R.ax, M8(DS, (u16)(R.di + 0xfffe))));    // 1607 add al, byte ptr [di - 2]
L_160a:   R.ax = (u16)(i16)(i8)R.ax;                                   // 160a cwde
  W16(DS, (u16)(0x6df), R.ax);                                 // 160b mov word ptr [0x6df], ax
  SETH(R.ax, M8(DS, (u16)(R.di + 0xfffd)));                    // 160e mov ah, byte ptr [di - 3]
  W8(DS, (u16)(0x6d5), (u8)(R.ax >> 8));                       // 1611 mov byte ptr [0x6d5], ah
  SETL(R.ax, M8(DS, (u16)(R.di + 0xfffb)));                    // 1615 mov al, byte ptr [di - 5]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 1618 or al, al
  if (R.zf) goto L_161e;                                       // 161a je 0x161e
  SETL(R.ax, ADD8((u8)R.ax, (u8)(R.ax >> 8)));                 // 161c add al, ah
L_161e:   W8(DS, (u16)(0x6d9), (u8)R.ax);                              // 161e mov byte ptr [0x6d9], al
  SETH(R.ax, M8(DS, (u16)(R.di + 0xfff8)));                    // 1621 mov ah, byte ptr [di - 8]
  W8(DS, (u16)(0x6d4), (u8)(R.ax >> 8));                       // 1624 mov byte ptr [0x6d4], ah
  SETL(R.ax, M8(DS, (u16)(R.di + 0xfff9)));                    // 1628 mov al, byte ptr [di - 7]
  SETL(R.ax, SUB8((u8)R.ax, (u8)(R.ax >> 8)));                 // 162b sub al, ah
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 162d xor ah, ah
  SETL(R.cx, M8(DS, (u16)(R.di + 0xfffa)));                    // 162f mov cl, byte ptr [di - 6]
  SETL(R.cx, DEC8((u8)R.cx));                                  // 1632 dec cl
  W8(DS, (u16)(0x6d8), (u8)R.cx);                              // 1634 mov byte ptr [0x6d8], cl
  R.di = (u16)(ADD16(R.di, 0xfff7));                           // 1638 add di, -9
  R.di = (u16)(SUB16(R.di, R.ax));                             // 163b sub di, ax
  W16(DS, (u16)(0x6d2), R.di);                                 // 163d mov word ptr [0x6d2], di
  R.ax = (u16)(INC16(R.ax));                                   // 1641 inc ax
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 1642 shl ax, cl
  W16(DS, (u16)(0x6e1), R.ax);                                 // 1644 mov word ptr [0x6e1], ax
  ip_ = R.si; goto dispatch_;                                  // 1647 jmp si
L_164a:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x4887) return; goto dispatch_; // 164a retf
}

// the driver's slots: slot 0 + k runs the k-th entry, with the caller's far return address on the stack
void eg_slot(int slot)
{
  static const u16 entries[] = { 0x047c, 0x0462, 0x0c27, 0x0092, 0x01b2, 0x1423, 0x06a6, 0x0daa, 0x0a97, 0x0000, 0x06d8, 0x1470, 0x164a, 0x13d4, 0x0432, 0x0188, 0x0a6b, 0x0230, 0x0743, 0x1495, 0x0d9b, 0x0516, 0x0539, 0x046c, 0x0166, 0x01ea, 0x11e1, 0x068c, 0x0e7f, 0x0b52, 0x0b6f, 0x0ab8, 0x06a5, 0x0489, 0x055e, 0x036f, 0x01eb, 0x01d5, 0x05b6, 0x14af, 0x14be, 0x1597, 0x1500, 0x1551, 0x0454, 0x043d, 0x116c, 0x11eb };
  if (slot >= 0 && slot < 48) eg_0000_run(entries[slot - 0]);
}
