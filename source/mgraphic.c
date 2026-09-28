#include "asm2c.h"

// MG: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void mg_0000_run(u16 entry);

void mg_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0x19bd;
dispatch_:
  switch (ip_)
  {
  case 0x0092: goto L_0092;
  case 0x00cd: goto L_00cd;
  case 0x00cf: goto L_00cf;
  case 0x00d6: goto L_00d6;
  case 0x00e1: goto L_00e1;
  case 0x00e6: goto L_00e6;
  case 0x0112: goto L_0112;
  case 0x0132: goto L_0132;
  case 0x014e: goto L_014e;
  case 0x015c: goto L_015c;
  case 0x0167: goto L_0167;
  case 0x018d: goto L_018d;
  case 0x0192: goto L_0192;
  case 0x01ac: goto L_01ac;
  case 0x01ae: goto L_01ae;
  case 0x01b4: goto L_01b4;
  case 0x01b5: goto L_01b5;
  case 0x01b6: goto L_01b6;
  case 0x01d8: goto L_01d8;
  case 0x01df: goto L_01df;
  case 0x01e4: goto L_01e4;
  case 0x01fc: goto L_01fc;
  case 0x0213: goto L_0213;
  case 0x0225: goto L_0225;
  case 0x022b: goto L_022b;
  case 0x022e: goto L_022e;
  case 0x0236: goto L_0236;
  case 0x0238: goto L_0238;
  case 0x0243: goto L_0243;
  case 0x025a: goto L_025a;
  case 0x0268: goto L_0268;
  case 0x0272: goto L_0272;
  case 0x0282: goto L_0282;
  case 0x028f: goto L_028f;
  case 0x029a: goto L_029a;
  case 0x02a4: goto L_02a4;
  case 0x02bc: goto L_02bc;
  case 0x02bd: goto L_02bd;
  case 0x02d9: goto L_02d9;
  case 0x02da: goto L_02da;
  case 0x02f0: goto L_02f0;
  case 0x02f3: goto L_02f3;
  case 0x030a: goto L_030a;
  case 0x030d: goto L_030d;
  case 0x0324: goto L_0324;
  case 0x0341: goto L_0341;
  case 0x0344: goto L_0344;
  case 0x0348: goto L_0348;
  case 0x035c: goto L_035c;
  case 0x0381: goto L_0381;
  case 0x0396: goto L_0396;
  case 0x03a6: goto L_03a6;
  case 0x03ae: goto L_03ae;
  case 0x03b9: goto L_03b9;
  case 0x03c9: goto L_03c9;
  case 0x03db: goto L_03db;
  case 0x03de: goto L_03de;
  case 0x03fe: goto L_03fe;
  case 0x0405: goto L_0405;
  case 0x0408: goto L_0408;
  case 0x0428: goto L_0428;
  case 0x0429: goto L_0429;
  case 0x0431: goto L_0431;
  case 0x043b: goto L_043b;
  case 0x0443: goto L_0443;
  case 0x044f: goto L_044f;
  case 0x0463: goto L_0463;
  case 0x046e: goto L_046e;
  case 0x0476: goto L_0476;
  case 0x0482: goto L_0482;
  case 0x048a: goto L_048a;
  case 0x0492: goto L_0492;
  case 0x049e: goto L_049e;
  case 0x04a3: goto L_04a3;
  case 0x04c1: goto L_04c1;
  case 0x04ca: goto L_04ca;
  case 0x04cf: goto L_04cf;
  case 0x04ec: goto L_04ec;
  case 0x054a: goto L_054a;
  case 0x0555: goto L_0555;
  case 0x055c: goto L_055c;
  case 0x057a: goto L_057a;
  case 0x059a: goto L_059a;
  case 0x05a0: goto L_05a0;
  case 0x05a3: goto L_05a3;
  case 0x05ac: goto L_05ac;
  case 0x05e6: goto L_05e6;
  case 0x05eb: goto L_05eb;
  case 0x05f7: goto L_05f7;
  case 0x05fb: goto L_05fb;
  case 0x0612: goto L_0612;
  case 0x062b: goto L_062b;
  case 0x062f: goto L_062f;
  case 0x0633: goto L_0633;
  case 0x0646: goto L_0646;
  case 0x0652: goto L_0652;
  case 0x0671: goto L_0671;
  case 0x0699: goto L_0699;
  case 0x06b6: goto L_06b6;
  case 0x06dd: goto L_06dd;
  case 0x06f4: goto L_06f4;
  case 0x0703: goto L_0703;
  case 0x0715: goto L_0715;
  case 0x071a: goto L_071a;
  case 0x0722: goto L_0722;
  case 0x0738: goto L_0738;
  case 0x0748: goto L_0748;
  case 0x074c: goto L_074c;
  case 0x075c: goto L_075c;
  case 0x0786: goto L_0786;
  case 0x078c: goto L_078c;
  case 0x079a: goto L_079a;
  case 0x079f: goto L_079f;
  case 0x07a3: goto L_07a3;
  case 0x07ad: goto L_07ad;
  case 0x07b1: goto L_07b1;
  case 0x07b2: goto L_07b2;
  case 0x07cb: goto L_07cb;
  case 0x07d0: goto L_07d0;
  case 0x0807: goto L_0807;
  case 0x081f: goto L_081f;
  case 0x082f: goto L_082f;
  case 0x0847: goto L_0847;
  case 0x0881: goto L_0881;
  case 0x0887: goto L_0887;
  case 0x08a0: goto L_08a0;
  case 0x08a5: goto L_08a5;
  case 0x08b7: goto L_08b7;
  case 0x08fb: goto L_08fb;
  case 0x0903: goto L_0903;
  case 0x091c: goto L_091c;
  case 0x0926: goto L_0926;
  case 0x0930: goto L_0930;
  case 0x0938: goto L_0938;
  case 0x0945: goto L_0945;
  case 0x0948: goto L_0948;
  case 0x0955: goto L_0955;
  case 0x095f: goto L_095f;
  case 0x098e: goto L_098e;
  case 0x09ba: goto L_09ba;
  case 0x09c0: goto L_09c0;
  case 0x09c2: goto L_09c2;
  case 0x09ca: goto L_09ca;
  case 0x09d2: goto L_09d2;
  case 0x0a00: goto L_0a00;
  case 0x0a28: goto L_0a28;
  case 0x0a30: goto L_0a30;
  case 0x0a64: goto L_0a64;
  case 0x0a6d: goto L_0a6d;
  case 0x0a74: goto L_0a74;
  case 0x0a84: goto L_0a84;
  case 0x0a98: goto L_0a98;
  case 0x0aa3: goto L_0aa3;
  case 0x0aab: goto L_0aab;
  case 0x0abe: goto L_0abe;
  case 0x0b09: goto L_0b09;
  case 0x0b0e: goto L_0b0e;
  case 0x0b59: goto L_0b59;
  case 0x0b5f: goto L_0b5f;
  case 0x0b85: goto L_0b85;
  case 0x0b88: goto L_0b88;
  case 0x0b9e: goto L_0b9e;
  case 0x0ba2: goto L_0ba2;
  case 0x0ba5: goto L_0ba5;
  case 0x0ba8: goto L_0ba8;
  case 0x0bab: goto L_0bab;
  case 0x0bae: goto L_0bae;
  case 0x0bb1: goto L_0bb1;
  case 0x0bb4: goto L_0bb4;
  case 0x0bb7: goto L_0bb7;
  case 0x0bba: goto L_0bba;
  case 0x0be0: goto L_0be0;
  case 0x0be4: goto L_0be4;
  case 0x0bee: goto L_0bee;
  case 0x0bf2: goto L_0bf2;
  case 0x0bf3: goto L_0bf3;
  case 0x0bf6: goto L_0bf6;
  case 0x0bf9: goto L_0bf9;
  case 0x0bfc: goto L_0bfc;
  case 0x0c1d: goto L_0c1d;
  case 0x0c3f: goto L_0c3f;
  case 0x0c40: goto L_0c40;
  case 0x0c44: goto L_0c44;
  case 0x0c47: goto L_0c47;
  case 0x0c4a: goto L_0c4a;
  case 0x0c4d: goto L_0c4d;
  case 0x0c71: goto L_0c71;
  case 0x0c85: goto L_0c85;
  case 0x0c86: goto L_0c86;
  case 0x0c8a: goto L_0c8a;
  case 0x0c8d: goto L_0c8d;
  case 0x0ca2: goto L_0ca2;
  case 0x0cb0: goto L_0cb0;
  case 0x0cb9: goto L_0cb9;
  case 0x0d01: goto L_0d01;
  case 0x0d15: goto L_0d15;
  case 0x0d40: goto L_0d40;
  default: asm_unknown_call(0x19bd, ip_); return;
  }
L_0092:   PUSH(R.bp);                                                  // 0092 push bp
  R.bp = (u16)(R.sp);                                          // 0093 mov bp, sp
  PUSH(R.si);                                                  // 0095 push si
  PUSH(R.di);                                                  // 0096 push di
  PUSH(R.ds);                                                  // 0097 push ds
  PUSH(R.es);                                                  // 0098 push es
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0099 mov si, word ptr [bp + 6]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 009c mov di, word ptr [bp + 0xa]
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(R.si + 0x4))));       // 009f add di, word ptr [si + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 00a2 shl di, 1
  R.di = (u16)(M16(CS, (u16)(R.di + 0xfa8)));                  // 00a4 mov di, word ptr cs:[di + 0xfa8]
  R.di = (u16)(ADD16(R.di, M16(SS, (u16)(R.bp + 0x8))));       // 00a9 add di, word ptr [bp + 8]
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(R.si + 0x2))));       // 00ac add di, word ptr [si + 2]
  SETH(R.ax, M8(SS, (u16)(R.bp + 0x10)));                      // 00af mov ah, byte ptr [bp + 0x10]
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x12)));                      // 00b2 mov al, byte ptr [bp + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 00b5 mov bx, word ptr [bp + 0xc]
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 00b8 mov bp, word ptr [bp + 0xe]
  R.dx = (u16)(0x140);                                         // 00bb mov dx, 0x140
  R.dx = (u16)(SUB16(R.dx, R.bx));                             // 00be sub dx, bx
  R.si = (u16)(M16(DS, (u16)(R.si)));                          // 00c0 mov si, word ptr [si]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 00c2 shl si, 1
  R.si = (u16)(M16(CS, (u16)(R.si + 0x1138)));                 // 00c4 mov si, word ptr cs:[si + 0x1138]
  R.ds = (u16)(R.si);                                          // 00c9 mov ds, si
  R.es = (u16)(R.si);                                          // 00cb mov es, si
L_00cd:   R.cx = (u16)(R.bx);                                          // 00cd mov cx, bx
L_00cf:   SUB8((u8)(R.ax >> 8), M8(DS, (u16)(R.di)));                  // 00cf cmp ah, byte ptr [di]
  if (!R.zf) goto L_00e1;                                      // 00d1 jne 0xe1
  STOSB();                                                     // 00d3 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_00cf;                                // 00d4 loop 0xcf
L_00d6:   R.di = (u16)(ADD16(R.di, R.dx));                             // 00d6 add di, dx
  R.bp = (u16)(DEC16(R.bp));                                   // 00d8 dec bp
  if (!R.zf) goto L_00cd;                                      // 00d9 jne 0xcd
  R.es = POP();                                                // 00db pop es
  R.ds = POP();                                                // 00dc pop ds
  R.di = POP();                                                // 00dd pop di
  R.si = POP();                                                // 00de pop si
  R.bp = POP();                                                // 00df pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 00e0 retf
L_00e1:   R.di = (u16)(INC16(R.di));                                   // 00e1 inc di
  if (--R.cx != 0) goto L_00cf;                                // 00e2 loop 0xcf
  goto L_00d6;                                                 // 00e4 jmp 0xd6
L_00e6:   R.bx = (u16)(R.sp);                                          // 00e6 mov bx, sp
  PUSH(R.es);                                                  // 00e8 push es
  R.ax = (u16)(0x1a92 /* segment */);                          // 00e9 mov ax, 0xd5
  R.es = (u16)(R.ax);                                          // 00ec mov es, ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 00ee mov ax, word ptr [bx + 4]
  R.cx = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 00f1 mov cx, word ptr [bx + 6]
  R.bx = (u16)(R.cx);                                          // 00f4 mov bx, cx
  R.bx = (u16)(ADD16(R.bx, R.cx));                             // 00f6 add bx, cx
  R.bx = (u16)(ADD16(R.bx, R.cx));                             // 00f8 add bx, cx
  SETH(R.dx, M8(ES, (u16)(R.bx + 0xce)));                      // 00fa mov dh, byte ptr es:[bx + 0xce]
  SETH(R.cx, M8(ES, (u16)(R.bx + 0xcf)));                      // 00ff mov ch, byte ptr es:[bx + 0xcf]
  SETL(R.cx, M8(ES, (u16)(R.bx + 0xd0)));                      // 0104 mov cl, byte ptr es:[bx + 0xd0]
  R.bx = (u16)(R.ax);                                          // 0109 mov bx, ax
  R.ax = (u16)(0x1010);                                        // 010b mov ax, 0x1010
  ASM_INT(0x10);                                               // 010e int 0x10
  R.es = POP();                                                // 0110 pop es
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0111 retf
L_0112:   R.bx = (u16)(R.sp);                                          // 0112 mov bx, sp
  PUSH(R.si);                                                  // 0114 push si
  PUSH(R.di);                                                  // 0115 push di
  PUSH(R.es);                                                  // 0116 push es
  R.ax = (u16)(0x1a92 /* segment */);                          // 0117 mov ax, 0xd5
  R.es = (u16)(R.ax);                                          // 011a mov es, ax
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 011c mov si, word ptr [bx + 6]
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 011f mov di, word ptr [bx + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0122 shl di, 1
  R.di = (u16)(M16(ES, (u16)(R.di + 0x52)));                   // 0124 mov di, word ptr es:[di + 0x52]
  R.cx = (u16)(0x11);                                          // 0129 mov cx, 0x11
  REPMOVSB();                                                  // 012c rep movsb byte ptr es:[di], byte ptr [si]
  R.es = POP();                                                // 012e pop es
  R.di = POP();                                                // 012f pop di
  R.si = POP();                                                // 0130 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0131 retf
L_0132:   R.bx = (u16)(R.sp);                                          // 0132 mov bx, sp
  PUSH(R.si);                                                  // 0134 push si
  PUSH(R.di);                                                  // 0135 push di
  PUSH(R.ds);                                                  // 0136 push ds
  PUSH(R.es);                                                  // 0137 push es
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0138 mov bx, word ptr [bx + 4]
  R.ax = (u16)(0x1a92 /* segment */);                          // 013b mov ax, 0xd5
  R.ds = (u16)(R.ax);                                          // 013e mov ds, ax
  R.es = (u16)(R.ax);                                          // 0140 mov es, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0142 shl bx, 1
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x52)));                   // 0144 mov si, word ptr [bx + 0x52]
  SETL(R.ax, M8(DS, (u16)(R.si + 0x10)));                      // 0148 mov al, byte ptr [si + 0x10]
  R.bx = (u16)(0x10);                                          // 014b mov bx, 0x10
L_014e:   R.bx = (u16)(DEC16(R.bx));                                   // 014e dec bx
  if (R.sf) goto L_015c;                                       // 014f js 0x15c
  SUB8(M8(DS, (u16)(R.bx + R.si)), (u8)R.ax);                  // 0151 cmp byte ptr [bx + si], al
  if (!R.zf) goto L_014e;                                      // 0153 jne 0x14e
  R.ax = (u16)(0x1001);                                        // 0155 mov ax, 0x1001
  SETH(R.bx, (u8)R.bx);                                        // 0158 mov bh, bl
  ASM_INT(0x10);                                               // 015a int 0x10
L_015c:   R.bx = (u16)(R.si);                                          // 015c mov bx, si
  R.di = (u16)((u16)(0x9e));                                   // 015e lea di, [0x9e]
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0162 xor ah, ah
  R.cx = (u16)(0x10);                                          // 0164 mov cx, 0x10
L_0167:   SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0167 mov al, byte ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 0169 inc bx
  R.si = (u16)((u16)(0xce));                                   // 016a lea si, [0xce]
  R.si = (u16)(ADD16(R.si, R.ax));                             // 016e add si, ax
  R.si = (u16)(ADD16(R.si, R.ax));                             // 0170 add si, ax
  R.si = (u16)(ADD16(R.si, R.ax));                             // 0172 add si, ax
  MOVSB();                                                     // 0174 movsb byte ptr es:[di], byte ptr [si]
  MOVSB();                                                     // 0175 movsb byte ptr es:[di], byte ptr [si]
  MOVSB();                                                     // 0176 movsb byte ptr es:[di], byte ptr [si]
  if (--R.cx != 0) goto L_0167;                                // 0177 loop 0x167
  R.ax = (u16)(0x1012);                                        // 0179 mov ax, 0x1012
  R.bx = (u16)(0x0);                                           // 017c mov bx, 0
  R.cx = (u16)(0x10);                                          // 017f mov cx, 0x10
  R.dx = (u16)((u16)(0x9e));                                   // 0182 lea dx, [0x9e]
  ASM_INT(0x10);                                               // 0186 int 0x10
  PUSH(0x19bd); PUSH(0x018d); goto L_030a;                     // 0188 lcall 0, 0x30a
L_018d:   R.es = POP();                                                // 018d pop es
  R.ds = POP();                                                // 018e pop ds
  R.di = POP();                                                // 018f pop di
  R.si = POP();                                                // 0190 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0191 retf
L_0192:   PUSH(R.es);                                                  // 0192 push es
  R.ax = (u16)(0x1a92 /* segment */);                          // 0193 mov ax, 0xd5
  R.es = (u16)(R.ax);                                          // 0196 mov es, ax
  R.ax = (u16)(0x1012);                                        // 0198 mov ax, 0x1012
  R.bx = (u16)(0x0);                                           // 019b mov bx, 0
  R.cx = (u16)(0x80);                                          // 019e mov cx, 0x80
  R.dx = (u16)((u16)(0xce));                                   // 01a1 lea dx, [0xce]
  ASM_INT(0x10);                                               // 01a5 int 0x10
  PUSH(0x19bd); PUSH(0x01ac); goto L_030a;                     // 01a7 lcall 0, 0x30a
L_01ac:   R.es = POP();                                                // 01ac pop es
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 01ad retf
L_01ae:   W8(CS, (u16)(0x1150), (u8)(R.ax >> 8));                      // 01ae mov byte ptr cs:[0x1150], ah
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 01b3 retf
L_01b4:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 01b4 retf
L_01b5:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 01b5 retf
L_01b6:   R.bx = (u16)(R.sp);                                          // 01b6 mov bx, sp
  PUSH(R.si);                                                  // 01b8 push si
  PUSH(R.di);                                                  // 01b9 push di
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 01ba mov si, word ptr [bx + 4]
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x8)));                    // 01bd mov di, word ptr [bx + 8]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 01c0 shl di, 1
  R.di = (u16)(M16(CS, (u16)(R.di + 0xfa8)));                  // 01c2 mov di, word ptr cs:[di + 0xfa8]
  R.cx = (u16)(M16(DS, (u16)(R.bx + 0xa)));                    // 01c7 mov cx, word ptr [bx + 0xa]
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 01ca shr cx, 1
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 01cc mov bx, word ptr [bx + 6]
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));           // 01cf or bh, bh
  if (R.zf) goto L_01d8;                                       // 01d1 je 0x1d8
  R.es = (u16)(R.bx);                                          // 01d3 mov es, bx
  goto L_01df;                                                 // 01d5 jmp 0x1df
L_01d8:   R.bx = (u16)(SHL16(R.bx, 0x1));                              // 01d8 shl bx, 1
  R.es = (u16)(M16(CS, (u16)(R.bx + 0x1138)));                 // 01da mov es, word ptr cs:[bx + 0x1138]
L_01df:   REPMOVSW();                                                  // 01df rep movsw word ptr es:[di], word ptr [si]
  R.di = POP();                                                // 01e1 pop di
  R.si = POP();                                                // 01e2 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 01e3 retf
L_01e4:   R.ax = (u16)(OR16(R.ax, R.ax));                              // 01e4 or ax, ax
  if (R.sf) goto L_0236;                                       // 01e6 js 0x236
  PUSH(R.es);                                                  // 01e8 push es
  R.es = (u16)(M16(CS, (u16)(0x1148)));                        // 01e9 mov es, word ptr cs:[0x1148]
  R.si = (u16)(R.ax);                                          // 01ee mov si, ax
  R.si = (u16)(SHL16(R.si, 0x1));                              // 01f0 shl si, 1
  R.dx = (u16)(R.cx);                                          // 01f2 mov dx, cx
  R.dx = (u16)(SHL16(R.dx, 0x1));                              // 01f4 shl dx, 1
  SETL(R.ax, M8(CS, (u16)(0x1150)));                           // 01f6 mov al, byte ptr cs:[0x1150]
  SETH(R.ax, (u8)R.ax);                                        // 01fa mov ah, al
L_01fc:   R.bp = (u16)(M16(DS, (u16)(R.bx + R.si)));                   // 01fc mov bp, word ptr [bx + si]
  R.cx = (u16)(M16(DS, (u16)(R.bx + R.si + 0x1b8)));           // 01fe mov cx, word ptr [bx + si + 0x1b8]
  R.cx = (u16)(SUB16(R.cx, R.bp));                             // 0202 sub cx, bp
  if (R.cf) goto L_022e;                                       // 0204 jb 0x22e
  if (!R.cf && !R.zf) goto L_0213;                             // 0206 ja 0x213
  R.bp = (u16)(OR16(R.bp, R.bp));                              // 0208 or bp, bp
  if (R.zf) goto L_022e;                                       // 020a je 0x22e
  SUB16(R.bp, M16(CS, (u16)(0x114e)));                         // 020c cmp bp, word ptr cs:[0x114e]
  if (R.zf) goto L_022e;                                       // 0211 je 0x22e
L_0213:   R.cx = (u16)(INC16(R.cx));                                   // 0213 inc cx
  R.di = (u16)(M16(CS, (u16)(R.si + 0xfa8)));                  // 0214 mov di, word ptr cs:[si + 0xfa8]
  R.di = (u16)(ADD16(R.di, R.bp));                             // 0219 add di, bp
  AND16(R.di, 0x1);                                            // 021b test di, 1
  if (R.zf) goto L_0225;                                       // 021f je 0x225
  STOSB();                                                     // 0221 stosb byte ptr es:[di], al
  R.cx = (u16)(DEC16(R.cx));                                   // 0222 dec cx
  if (R.zf) goto L_022e;                                       // 0223 je 0x22e
L_0225:   R.cx = (u16)(SHR16(R.cx, 0x1));                              // 0225 shr cx, 1
  if (R.zf) goto L_022b;                                       // 0227 je 0x22b
  REPSTOSW();                                                  // 0229 rep stosw word ptr es:[di], ax
L_022b:   if (!R.cf) goto L_022e;                                      // 022b jae 0x22e
  STOSB();                                                     // 022d stosb byte ptr es:[di], al
L_022e:   R.si = (u16)(ADD16(R.si, 0x2));                              // 022e add si, 2
  SUB16(R.si, R.dx);                                           // 0231 cmp si, dx
  if (R.cf || R.zf) goto L_01fc;                               // 0233 jbe 0x1fc
  R.es = POP();                                                // 0235 pop es
L_0236:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0236 retf
L_0238:   R.bx = (u16)(R.sp);                                          // 0238 mov bx, sp
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 023a mov bx, word ptr [bx + 4]
  R.ax = (u16)(M16(CS, (u16)(R.bx + 0xf9e)));                  // 023d mov ax, word ptr cs:[bx + 0xf9e]
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0242 retf
L_0243:   R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 0243 mov ax, word ptr [bx + 2]
  W16(CS, (u16)(0x114a), R.ax);                                // 0246 mov word ptr cs:[0x114a], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 024a mov ax, word ptr [bx + 4]
  W16(CS, (u16)(0x114c), R.ax);                                // 024d mov word ptr cs:[0x114c], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0251 mov ax, word ptr [bx + 6]
  W16(CS, (u16)(0x114e), R.ax);                                // 0254 mov word ptr cs:[0x114e], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 0258 mov ax, word ptr [bx]
L_025a:   { u16 t_ = R.bx; R.bx = (u16)(R.ax); R.ax = (u16)(t_); }     // 025a xchg bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 025b shl bx, 1
  R.bx = (u16)(M16(CS, (u16)(R.bx + 0x1138)));                 // 025d mov bx, word ptr cs:[bx + 0x1138]
  { u16 t_ = R.bx; R.bx = (u16)(R.ax); R.ax = (u16)(t_); }     // 0262 xchg bx, ax
  W16(CS, (u16)(0x1148), R.ax);                                // 0263 mov word ptr cs:[0x1148], ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0267 retf
L_0268:   SETH(R.ax, 0x48);                                            // 0268 mov ah, 0x48
  R.bx = (u16)(0xffff);                                        // 026a mov bx, 0xffff
  ASM_INT(0x21);                                               // 026d int 0x21
  R.ax = (u16)(R.bx);                                          // 026f mov ax, bx
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0271 retf
L_0272:   R.bx = (u16)(R.sp);                                          // 0272 mov bx, sp
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0274 mov ax, word ptr [bx + 6]
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0277 mov bx, word ptr [bx + 4]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 027a shl bx, 1
  W16(CS, (u16)(R.bx + 0x1138), R.ax);                         // 027c mov word ptr cs:[bx + 0x1138], ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0281 retf
L_0282:   R.bx = (u16)(R.sp);                                          // 0282 mov bx, sp
  SUB16(M16(DS, (u16)(R.bx + 0x4)), 0x0);                      // 0284 cmp word ptr [bx + 4], 0
  if (!R.zf) goto L_028f;                                      // 0288 jne 0x28f
  R.ax = (u16)(M16(CS, (u16)(0x1138)));                        // 028a mov ax, word ptr cs:[0x1138]
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 028e retf
L_028f:   SETH(R.ax, 0x48);                                            // 028f mov ah, 0x48
  R.bx = (u16)(0xfa0);                                         // 0291 mov bx, 0xfa0
  ASM_INT(0x21);                                               // 0294 int 0x21
  if (!R.cf) goto L_029a;                                      // 0296 jae 0x29a
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0298 xor ax, ax
L_029a:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 029a retf
L_02a4:   R.bx = (u16)(R.sp);                                          // 02a4 mov bx, sp
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 02a6 mov bx, word ptr [bx + 4]
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 02a9 or bx, bx
  if (R.zf) goto L_02bc;                                       // 02ab je 0x2bc
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 02ad shl bx, 1
  R.ax = (u16)(M16(CS, (u16)(R.bx + 0x1138)));                 // 02af mov ax, word ptr cs:[bx + 0x1138]
  PUSH(R.es);                                                  // 02b4 push es
  R.es = (u16)(R.ax);                                          // 02b5 mov es, ax
  SETH(R.ax, 0x49);                                            // 02b7 mov ah, 0x49
  ASM_INT(0x21);                                               // 02b9 int 0x21
  R.es = POP();                                                // 02bb pop es
L_02bc:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 02bc retf
L_02bd:   R.bx = (u16)(R.sp);                                          // 02bd mov bx, sp
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 02bf mov ax, word ptr [bx + 4]
  R.ax = (u16)(AND16(R.ax, 0x80));                             // 02c2 and ax, 0x80
  R.ax = (u16)(OR16(R.ax, 0x13));                              // 02c5 or ax, 0x13
  SETL(R.bx, (u8)R.ax);                                        // 02c8 mov bl, al
  ASM_INT(0x10);                                               // 02ca int 0x10
  SETH(R.ax, 0xf);                                             // 02cc mov ah, 0xf
  ASM_INT(0x10);                                               // 02ce int 0x10
  SUB8((u8)R.ax, (u8)R.bx);                                    // 02d0 cmp al, bl
  if (!R.zf) goto L_02da;                                      // 02d2 jne 0x2da
  PUSH(0x19bd); PUSH(0x02d9); goto L_0192;                     // 02d4 lcall 0, 0x192
L_02d9:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 02d9 retf
L_02da:   R.dx = (u16)(0x410);                                         // 02da mov dx, 0x410
  R.ax = (u16)(0x1a92 /* segment */);                          // 02dd mov ax, 0xd5
  R.ds = (u16)(R.ax);                                          // 02e0 mov ds, ax
  R.ax = (u16)(0x3);                                           // 02e2 mov ax, 3
  ASM_INT(0x10);                                               // 02e5 int 0x10
  SETH(R.ax, 0x9);                                             // 02e7 mov ah, 9
  ASM_INT(0x21);                                               // 02e9 int 0x21
  R.ax = (u16)(0x4c00);                                        // 02eb mov ax, 0x4c00
  ASM_INT(0x21);                                               // 02ee int 0x21
L_02f0:   R.dx = (u16)(0x3da);                                         // 02f0 mov dx, 0x3da
L_02f3:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 02f3 in al, dx
  AND8((u8)R.ax, 0x8);                                         // 02f4 test al, 8
  if (R.zf) goto L_02f3;                                       // 02f6 je 0x2f3
  R.dx = (u16)(0x3d8);                                         // 02f8 mov dx, 0x3d8
  SETL(R.ax, 0x2);                                             // 02fb mov al, 2
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 02fd out dx, al
  R.dx = (u16)(0x3c4);                                         // 02fe mov dx, 0x3c4
  SETL(R.ax, 0x1);                                             // 0301 mov al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0303 out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 0304 inc dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0305 in al, dx
  SETL(R.ax, OR8((u8)R.ax, 0x20));                             // 0306 or al, 0x20
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0308 out dx, al
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0309 retf
L_030a:   R.dx = (u16)(0x3da);                                         // 030a mov dx, 0x3da
L_030d:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 030d in al, dx
  AND8((u8)R.ax, 0x8);                                         // 030e test al, 8
  if (R.zf) goto L_030d;                                       // 0310 je 0x30d
  R.dx = (u16)(0x3d8);                                         // 0312 mov dx, 0x3d8
  SETL(R.ax, 0xa);                                             // 0315 mov al, 0xa
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0317 out dx, al
  R.dx = (u16)(0x3c4);                                         // 0318 mov dx, 0x3c4
  SETL(R.ax, 0x1);                                             // 031b mov al, 1
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 031d out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 031e inc dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 031f in al, dx
  SETL(R.ax, AND8((u8)R.ax, 0xdf));                            // 0320 and al, 0xdf
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0322 out dx, al
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0323 retf
L_0324:   PUSH(R.ds);                                                  // 0324 push ds
  PUSH(R.es);                                                  // 0325 push es
  R.di = (u16)(0x1a92 /* segment */);                          // 0326 mov di, 0xd5
  R.ds = (u16)(R.di);                                          // 0329 mov ds, di
  R.es = (u16)(M16(CS, (u16)(0x1148)));                        // 032b mov es, word ptr cs:[0x1148]
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x114a))));           // 0330 add ax, word ptr cs:[0x114a]
  R.bx = (u16)(ADD16(R.bx, M16(CS, (u16)(0x114c))));           // 0335 add bx, word ptr cs:[0x114c]
  W16(DS, (u16)(0x436), R.ax);                                 // 033a mov word ptr [0x436], ax
  W16(DS, (u16)(0x438), R.bx);                                 // 033d mov word ptr [0x438], bx
L_0341:   PUSH(0x0344); goto L_0348;                                   // 0341 call 0x348
L_0344:   STOSB();                                                     // 0344 stosb byte ptr es:[di], al
  R.es = POP();                                                // 0345 pop es
  R.ds = POP();                                                // 0346 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0347 retf
L_0348:   SETL(R.ax, M8(CS, (u16)(0x1150)));                           // 0348 mov al, byte ptr cs:[0x1150]
  R.di = (u16)(M16(DS, (u16)(0x438)));                         // 034c mov di, word ptr [0x438]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0350 shl di, 1
  R.di = (u16)(M16(CS, (u16)(R.di + 0xfa8)));                  // 0352 mov di, word ptr cs:[di + 0xfa8]
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(0x436))));            // 0357 add di, word ptr [0x436]
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 035b ret
L_035c:   PUSH(R.ds);                                                  // 035c push ds
  PUSH(R.es);                                                  // 035d push es
  R.di = (u16)(0x1a92 /* segment */);                          // 035e mov di, 0xd5
  R.ds = (u16)(R.di);                                          // 0361 mov ds, di
  R.es = (u16)(M16(CS, (u16)(0x1148)));                        // 0363 mov es, word ptr cs:[0x1148]
  R.di = (u16)(M16(CS, (u16)(0x114a)));                        // 0368 mov di, word ptr cs:[0x114a]
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 036d add ax, di
  R.cx = (u16)(ADD16(R.cx, R.di));                             // 036f add cx, di
  R.di = (u16)(M16(CS, (u16)(0x114c)));                        // 0371 mov di, word ptr cs:[0x114c]
  R.bx = (u16)(ADD16(R.bx, R.di));                             // 0376 add bx, di
  R.dx = (u16)(ADD16(R.dx, R.di));                             // 0378 add dx, di
  SUB16(R.ax, R.cx);                                           // 037a cmp ax, cx
  if (R.cf || R.zf) goto L_0381;                               // 037c jbe 0x381
  { u16 t_ = R.cx; R.cx = (u16)(R.ax); R.ax = (u16)(t_); }     // 037e xchg cx, ax
  { u16 t_ = R.dx; R.dx = (u16)(R.bx); R.bx = (u16)(t_); }     // 037f xchg dx, bx
L_0381:   W16(DS, (u16)(0x436), R.ax);                                 // 0381 mov word ptr [0x436], ax
  W16(DS, (u16)(0x438), R.bx);                                 // 0384 mov word ptr [0x438], bx
  W16(DS, (u16)(0x43a), R.cx);                                 // 0388 mov word ptr [0x43a], cx
  W16(DS, (u16)(0x43c), R.dx);                                 // 038c mov word ptr [0x43c], dx
  if (!R.zf) goto L_0396;                                      // 0390 jne 0x396
  SUB16(R.bx, R.dx);                                           // 0392 cmp bx, dx
  if (R.zf) goto L_0341;                                       // 0394 je 0x341
L_0396:   R.si = (u16)(0x1);                                           // 0396 mov si, 1
  R.bp = (u16)(0x140);                                         // 0399 mov bp, 0x140
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 039c sub cx, ax
  R.dx = (u16)(SUB16(R.dx, R.bx));                             // 039e sub dx, bx
  if (!R.sf) goto L_03a6;                                      // 03a0 jns 0x3a6
  R.bp = (u16)(NEG16(R.bp));                                   // 03a2 neg bp
  R.dx = (u16)(NEG16(R.dx));                                   // 03a4 neg dx
L_03a6:   SUB16(R.cx, R.dx);                                           // 03a6 cmp cx, dx
  if (!R.cf) goto L_03ae;                                      // 03a8 jae 0x3ae
  { u16 t_ = R.bp; R.bp = (u16)(R.si); R.si = (u16)(t_); }     // 03aa xchg bp, si
  { u16 t_ = R.dx; R.dx = (u16)(R.cx); R.cx = (u16)(t_); }     // 03ac xchg dx, cx
L_03ae:   W16(DS, (u16)(0x43e), R.cx);                                 // 03ae mov word ptr [0x43e], cx
  W16(DS, (u16)(0x440), R.dx);                                 // 03b2 mov word ptr [0x440], dx
  PUSH(0x03b9); goto L_0348;                                   // 03b6 call 0x348
L_03b9:   R.bx = (u16)(M16(DS, (u16)(0x440)));                         // 03b9 mov bx, word ptr [0x440]
  R.cx = (u16)(M16(DS, (u16)(0x43e)));                         // 03bd mov cx, word ptr [0x43e]
  R.dx = (u16)(R.cx);                                          // 03c1 mov dx, cx
  R.dx = (u16)(INC16(R.dx));                                   // 03c3 inc dx
  R.dx = (u16)(SHR16(R.dx, 0x1));                              // 03c4 shr dx, 1
  R.dx = (u16)(NEG16(R.dx));                                   // 03c6 neg dx
  R.si = (u16)(DEC16(R.si));                                   // 03c8 dec si
L_03c9:   STOSB();                                                     // 03c9 stosb byte ptr es:[di], al
  R.cx = (u16)(DEC16(R.cx));                                   // 03ca dec cx
  if (R.sf) goto L_03db;                                       // 03cb js 0x3db
  R.di = (u16)(ADD16(R.di, R.si));                             // 03cd add di, si
  R.dx = (u16)(ADD16(R.dx, R.bx));                             // 03cf add dx, bx
  if (R.sf) goto L_03c9;                                       // 03d1 js 0x3c9
  R.dx = (u16)(SUB16(R.dx, M16(DS, (u16)(0x43e))));            // 03d3 sub dx, word ptr [0x43e]
  R.di = (u16)(ADD16(R.di, R.bp));                             // 03d7 add di, bp
  goto L_03c9;                                                 // 03d9 jmp 0x3c9
L_03db:   R.es = POP();                                                // 03db pop es
  R.ds = POP();                                                // 03dc pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 03dd retf
L_03de:   R.bx = (u16)(R.sp);                                          // 03de mov bx, sp
  PUSH(R.si);                                                  // 03e0 push si
  PUSH(R.di);                                                  // 03e1 push di
  PUSH(R.ds);                                                  // 03e2 push ds
  PUSH(R.es);                                                  // 03e3 push es
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 03e4 mov si, word ptr [bx + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 03e7 shl si, 1
  if (R.zf) goto L_03fe;                                       // 03e9 je 0x3fe
  R.ds = (u16)(M16(CS, (u16)(R.si + 0x1138)));                 // 03eb mov ds, word ptr cs:[si + 0x1138]
  R.es = (u16)(M16(CS, (u16)(0x1138)));                        // 03f0 mov es, word ptr cs:[0x1138]
  R.si = (u16)(XOR16(R.si, R.si));                             // 03f5 xor si, si
  R.di = (u16)(XOR16(R.di, R.di));                             // 03f7 xor di, di
  R.cx = (u16)(0x7d00);                                        // 03f9 mov cx, 0x7d00
  REPMOVSW();                                                  // 03fc rep movsw word ptr es:[di], word ptr [si]
L_03fe:   R.es = POP();                                                // 03fe pop es
  R.ds = POP();                                                // 03ff pop ds
  R.di = POP();                                                // 0400 pop di
  R.si = POP();                                                // 0401 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0402 retf
L_0405:   goto L_049e;                                                 // 0405 jmp 0x49e
L_0408:   R.bx = (u16)(R.sp);                                          // 0408 mov bx, sp
  PUSH(R.si);                                                  // 040a push si
  PUSH(R.di);                                                  // 040b push di
  PUSH(R.ds);                                                  // 040c push ds
  PUSH(R.es);                                                  // 040d push es
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 040e mov si, word ptr [bx + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0411 shl si, 1
  if (R.zf) goto L_0405;                                       // 0413 je 0x405
  R.ds = (u16)(M16(CS, (u16)(R.si + 0x1138)));                 // 0415 mov ds, word ptr cs:[si + 0x1138]
  R.es = (u16)(M16(CS, (u16)(0x1138)));                        // 041a mov es, word ptr cs:[0x1138]
  R.bx = (u16)(M16(CS, (u16)(0x403)));                         // 041f mov bx, word ptr cs:[0x403]
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0424 or bx, bx
  if (!R.zf) goto L_0463;                                      // 0426 jne 0x463
L_0428:   R.bx = (u16)(INC16(R.bx));                                   // 0428 inc bx
L_0429:   R.dx = (u16)(0x3da);                                         // 0429 mov dx, 0x3da
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 042c in al, dx
  AND8((u8)R.ax, 0x8);                                         // 042d test al, 8
  if (R.zf) goto L_0429;                                       // 042f je 0x429
L_0431:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0431 in al, dx
  AND8((u8)R.ax, 0x8);                                         // 0432 test al, 8
  if (!R.zf) goto L_0431;                                      // 0434 jne 0x431
  R.si = (u16)(0x1);                                           // 0436 mov si, 1
  R.cx = (u16)(XOR16(R.cx, R.cx));                             // 0439 xor cx, cx
L_043b:   R.si = (u16)(SHR16(R.si, 0x1));                              // 043b shr si, 1
  if (!R.cf) goto L_0443;                                      // 043d jae 0x443
  R.si = (u16)(XOR16(R.si, 0xb400));                           // 043f xor si, 0xb400
L_0443:   SUB16(R.si, 0x0);                                            // 0443 cmp si, 0
  if (R.cf) goto L_043b;                                       // 0446 jb 0x43b
  R.si = (u16)(DEC16(R.si));                                   // 0448 dec si
  R.di = (u16)(0xffff);                                        // 0449 mov di, 0xffff
  MOVSB();                                                     // 044c movsb byte ptr es:[di], byte ptr [si]
  R.ax = (u16)(R.bx);                                          // 044d mov ax, bx
L_044f:   R.ax = (u16)(DEC16(R.ax));                                   // 044f dec ax
  if (!R.zf) goto L_044f;                                      // 0450 jne 0x44f
  R.cx = (u16)(INC16(R.cx));                                   // 0452 inc cx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0453 in al, dx
  AND8((u8)R.ax, 0x8);                                         // 0454 test al, 8
  if (R.zf) goto L_043b;                                       // 0456 je 0x43b
  SUB16(R.cx, 0x215);                                          // 0458 cmp cx, 0x215
  if (!R.cf && !R.zf) goto L_0428;                             // 045c ja 0x428
  W16(CS, (u16)(0x403), R.bx);                                 // 045e mov word ptr cs:[0x403], bx
L_0463:   R.si = (u16)(0x1);                                           // 0463 mov si, 1
  R.cx = (u16)(0xfa00);                                        // 0466 mov cx, 0xfa00
  SUB16(R.bx, 0x1);                                            // 0469 cmp bx, 1
  if (R.zf) goto L_048a;                                       // 046c je 0x48a
L_046e:   R.si = (u16)(SHR16(R.si, 0x1));                              // 046e shr si, 1
  if (!R.cf) goto L_0476;                                      // 0470 jae 0x476
  R.si = (u16)(XOR16(R.si, 0xb400));                           // 0472 xor si, 0xb400
L_0476:   SUB16(R.si, 0xfa00);                                         // 0476 cmp si, 0xfa00
  if (!R.cf && !R.zf) goto L_046e;                             // 047a ja 0x46e
  R.si = (u16)(DEC16(R.si));                                   // 047c dec si
  R.di = (u16)(R.si);                                          // 047d mov di, si
  MOVSB();                                                     // 047f movsb byte ptr es:[di], byte ptr [si]
  R.ax = (u16)(R.bx);                                          // 0480 mov ax, bx
L_0482:   R.ax = (u16)(DEC16(R.ax));                                   // 0482 dec ax
  if (!R.zf) goto L_0482;                                      // 0483 jne 0x482
  if (--R.cx != 0) goto L_046e;                                // 0485 loop 0x46e
  goto L_049e;                                                 // 0487 jmp 0x49e
L_048a:   R.si = (u16)(SHR16(R.si, 0x1));                              // 048a shr si, 1
  if (!R.cf) goto L_0492;                                      // 048c jae 0x492
  R.si = (u16)(XOR16(R.si, 0xb400));                           // 048e xor si, 0xb400
L_0492:   SUB16(R.si, 0xfa00);                                         // 0492 cmp si, 0xfa00
  if (!R.cf && !R.zf) goto L_048a;                             // 0496 ja 0x48a
  R.si = (u16)(DEC16(R.si));                                   // 0498 dec si
  R.di = (u16)(R.si);                                          // 0499 mov di, si
  MOVSB();                                                     // 049b movsb byte ptr es:[di], byte ptr [si]
  if (--R.cx != 0) goto L_048a;                                // 049c loop 0x48a
L_049e:   R.es = POP();                                                // 049e pop es
  R.ds = POP();                                                // 049f pop ds
  R.di = POP();                                                // 04a0 pop di
  R.si = POP();                                                // 04a1 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 04a2 retf
L_04a3:   R.bx = (u16)(R.sp);                                          // 04a3 mov bx, sp
  PUSH(R.si);                                                  // 04a5 push si
  PUSH(R.di);                                                  // 04a6 push di
  PUSH(R.ds);                                                  // 04a7 push ds
  PUSH(R.es);                                                  // 04a8 push es
  R.si = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 04a9 mov si, word ptr [bx + 4]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 04ac shl si, 1
  if (R.zf) goto L_04ca;                                       // 04ae je 0x4ca
  R.ds = (u16)(M16(CS, (u16)(R.si + 0x1138)));                 // 04b0 mov ds, word ptr cs:[si + 0x1138]
  R.es = (u16)(M16(CS, (u16)(0x1138)));                        // 04b5 mov es, word ptr cs:[0x1138]
  R.si = (u16)(XOR16(R.si, R.si));                             // 04ba xor si, si
  R.di = (u16)(XOR16(R.di, R.di));                             // 04bc xor di, di
  R.cx = (u16)(0x7d00);                                        // 04be mov cx, 0x7d00
L_04c1:   LODSW();                                                     // 04c1 lodsw ax, word ptr [si]
  R.bx = (u16)(M16(ES, (u16)(R.di)));                          // 04c2 mov bx, word ptr es:[di]
  W16(DS, (u16)(R.di), R.bx);                                  // 04c5 mov word ptr [di], bx
  STOSW();                                                     // 04c7 stosw word ptr es:[di], ax
  if (--R.cx != 0) goto L_04c1;                                // 04c8 loop 0x4c1
L_04ca:   R.es = POP();                                                // 04ca pop es
  R.ds = POP();                                                // 04cb pop ds
  R.di = POP();                                                // 04cc pop di
  R.si = POP();                                                // 04cd pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 04ce retf
L_04cf:   R.bx = (u16)(R.sp);                                          // 04cf mov bx, sp
  PUSH(R.di);                                                  // 04d1 push di
  PUSH(R.es);                                                  // 04d2 push es
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x6)));                       // 04d3 mov al, byte ptr [bx + 6]
  SETH(R.ax, (u8)R.ax);                                        // 04d6 mov ah, al
  R.di = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 04d8 mov di, word ptr [bx + 4]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 04db shl di, 1
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1138)));                 // 04dd mov es, word ptr cs:[di + 0x1138]
  R.di = (u16)(XOR16(R.di, R.di));                             // 04e2 xor di, di
  R.cx = (u16)(0x7d00);                                        // 04e4 mov cx, 0x7d00
  REPSTOSW();                                                  // 04e7 rep stosw word ptr es:[di], ax
  R.es = POP();                                                // 04e9 pop es
  R.di = POP();                                                // 04ea pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 04eb retf
L_04ec:   PUSH(R.bp);                                                  // 04ec push bp
  R.bp = (u16)(R.sp);                                          // 04ed mov bp, sp
  PUSH(R.si);                                                  // 04ef push si
  PUSH(R.di);                                                  // 04f0 push di
  PUSH(R.ds);                                                  // 04f1 push ds
  PUSH(R.es);                                                  // 04f2 push es
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 04f3 mov si, word ptr [bp + 6]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x10)));                   // 04f6 mov di, word ptr [bp + 0x10]
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x2)));                    // 04f9 mov ax, word ptr [si + 2]
  R.bx = (u16)(M16(DS, (u16)(R.si + 0x4)));                    // 04fc mov bx, word ptr [si + 4]
  R.cx = (u16)(M16(DS, (u16)(R.di + 0x2)));                    // 04ff mov cx, word ptr [di + 2]
  R.dx = (u16)(M16(DS, (u16)(R.di + 0x4)));                    // 0502 mov dx, word ptr [di + 4]
  R.ax = (u16)(ADD16(R.ax, M16(SS, (u16)(R.bp + 0x8))));       // 0505 add ax, word ptr [bp + 8]
  R.bx = (u16)(ADD16(R.bx, M16(SS, (u16)(R.bp + 0xa))));       // 0508 add bx, word ptr [bp + 0xa]
  R.cx = (u16)(ADD16(R.cx, M16(SS, (u16)(R.bp + 0x12))));      // 050b add cx, word ptr [bp + 0x12]
  R.dx = (u16)(ADD16(R.dx, M16(SS, (u16)(R.bp + 0x14))));      // 050e add dx, word ptr [bp + 0x14]
  R.si = (u16)(M16(DS, (u16)(R.si)));                          // 0511 mov si, word ptr [si]
  R.di = (u16)(M16(DS, (u16)(R.di)));                          // 0513 mov di, word ptr [di]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0515 shl si, 1
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0517 shl di, 1
  R.ds = (u16)(M16(CS, (u16)(R.si + 0x1138)));                 // 0519 mov ds, word ptr cs:[si + 0x1138]
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1138)));                 // 051e mov es, word ptr cs:[di + 0x1138]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0523 shl bx, 1
  R.si = (u16)(M16(CS, (u16)(R.bx + 0xfa8)));                  // 0525 mov si, word ptr cs:[bx + 0xfa8]
  R.si = (u16)(ADD16(R.si, R.ax));                             // 052a add si, ax
  R.bx = (u16)(R.dx);                                          // 052c mov bx, dx
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 052e shl bx, 1
  R.di = (u16)(M16(CS, (u16)(R.bx + 0xfa8)));                  // 0530 mov di, word ptr cs:[bx + 0xfa8]
  R.di = (u16)(ADD16(R.di, R.cx));                             // 0535 add di, cx
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0537 mov ax, word ptr [bp + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xe)));                    // 053a mov bx, word ptr [bp + 0xe]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 053d or ax, ax
  if (R.zf) goto L_0555;                                       // 053f je 0x555
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0541 or bx, bx
  if (R.zf) goto L_0555;                                       // 0543 je 0x555
  R.dx = (u16)(0x140);                                         // 0545 mov dx, 0x140
  R.dx = (u16)(SUB16(R.dx, R.ax));                             // 0548 sub dx, ax
L_054a:   R.cx = (u16)(R.ax);                                          // 054a mov cx, ax
  REPMOVSB();                                                  // 054c rep movsb byte ptr es:[di], byte ptr [si]
  R.si = (u16)(ADD16(R.si, R.dx));                             // 054e add si, dx
  R.di = (u16)(ADD16(R.di, R.dx));                             // 0550 add di, dx
  R.bx = (u16)(DEC16(R.bx));                                   // 0552 dec bx
  if (!R.zf) goto L_054a;                                      // 0553 jne 0x54a
L_0555:   R.es = POP();                                                // 0555 pop es
  R.ds = POP();                                                // 0556 pop ds
  R.di = POP();                                                // 0557 pop di
  R.si = POP();                                                // 0558 pop si
  R.bp = POP();                                                // 0559 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 055a retf
L_055c:   R.ax = (u16)(OR16(R.ax, R.ax));                              // 055c or ax, ax
  if (R.sf) goto L_05ac;                                       // 055e js 0x5ac
  PUSH(R.ds);                                                  // 0560 push ds
  PUSH(R.es);                                                  // 0561 push es
  R.si = (u16)(SHL16(R.si, 0x1));                              // 0562 shl si, 1
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0564 shl di, 1
  R.ds = (u16)(M16(CS, (u16)(R.si + 0x1138)));                 // 0566 mov ds, word ptr cs:[si + 0x1138]
  R.es = (u16)(M16(CS, (u16)(R.di + 0x1138)));                 // 056b mov es, word ptr cs:[di + 0x1138]
  R.bp = (u16)(R.bx);                                          // 0570 mov bp, bx
  R.bx = (u16)(R.ax);                                          // 0572 mov bx, ax
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0574 shl bx, 1
  R.dx = (u16)(R.cx);                                          // 0576 mov dx, cx
  R.dx = (u16)(SHL16(R.dx, 0x1));                              // 0578 shl dx, 1
L_057a:   R.si = (u16)(R.bx);                                          // 057a mov si, bx
  R.ax = (u16)(M16(SS, (u16)(R.bp + R.si)));                   // 057c mov ax, word ptr [bp + si]
  R.cx = (u16)(M16(SS, (u16)(R.bp + R.si + 0x190)));           // 057e mov cx, word ptr [bp + si + 0x190]
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 0582 sub cx, ax
  if (R.cf) goto L_05a3;                                       // 0584 jb 0x5a3
  R.cx = (u16)(INC16(R.cx));                                   // 0586 inc cx
  R.di = (u16)(M16(CS, (u16)(R.si + 0xfa8)));                  // 0587 mov di, word ptr cs:[si + 0xfa8]
  R.di = (u16)(ADD16(R.di, R.ax));                             // 058c add di, ax
  R.si = (u16)(R.di);                                          // 058e mov si, di
  AND16(R.di, 0x1);                                            // 0590 test di, 1
  if (R.zf) goto L_059a;                                       // 0594 je 0x59a
  MOVSB();                                                     // 0596 movsb byte ptr es:[di], byte ptr [si]
  R.cx = (u16)(DEC16(R.cx));                                   // 0597 dec cx
  if (R.zf) goto L_05a3;                                       // 0598 je 0x5a3
L_059a:   R.cx = (u16)(SHR16(R.cx, 0x1));                              // 059a shr cx, 1
  if (R.zf) goto L_05a0;                                       // 059c je 0x5a0
  REPMOVSW();                                                  // 059e rep movsw word ptr es:[di], word ptr [si]
L_05a0:   if (!R.cf) goto L_05a3;                                      // 05a0 jae 0x5a3
  MOVSB();                                                     // 05a2 movsb byte ptr es:[di], byte ptr [si]
L_05a3:   R.bx = (u16)(ADD16(R.bx, 0x2));                              // 05a3 add bx, 2
  SUB16(R.bx, R.dx);                                           // 05a6 cmp bx, dx
  if (R.cf || R.zf) goto L_057a;                               // 05a8 jbe 0x57a
  R.es = POP();                                                // 05aa pop es
  R.ds = POP();                                                // 05ab pop ds
L_05ac:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 05ac retf
L_05e6:   PUSH(0x19bd); PUSH(0x05eb); goto L_0268;                     // 05e6 lcall 0, 0x268
L_05eb:   R.bx = (u16)(R.ax);                                          // 05eb mov bx, ax
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 05ed or bx, bx
  if (R.zf) goto L_05f7;                                       // 05ef je 0x5f7
  SETH(R.ax, 0x48);                                            // 05f1 mov ah, 0x48
  ASM_INT(0x21);                                               // 05f3 int 0x21
  if (!R.cf) goto L_05fb;                                      // 05f5 jae 0x5fb
L_05f7:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 05f7 xor ax, ax
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 05f9 xor bx, bx
L_05fb:   R.bx = (u16)(ADD16(R.bx, R.ax));                             // 05fb add bx, ax
  W16(CS, (u16)(0x5ca), 0x0);                                  // 05fd mov word ptr cs:[0x5ca], 0
  W16(CS, (u16)(0x5cc), R.ax);                                 // 0604 mov word ptr cs:[0x5cc], ax
  W16(CS, (u16)(0x5ce), R.ax);                                 // 0608 mov word ptr cs:[0x5ce], ax
  W16(CS, (u16)(0x5d0), R.bx);                                 // 060c mov word ptr cs:[0x5d0], bx
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0611 retf
L_0612:   R.ax = (u16)(M16(CS, (u16)(0x5ce)));                         // 0612 mov ax, word ptr cs:[0x5ce]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0616 or ax, ax
  if (R.zf) goto L_062f;                                       // 0618 je 0x62f
  R.bx = (u16)(M16(CS, (u16)(0x5cc)));                         // 061a mov bx, word ptr cs:[0x5cc]
  R.bx = (u16)(SUB16(R.bx, R.ax));                             // 061f sub bx, ax
  R.es = (u16)(R.ax);                                          // 0621 mov es, ax
  SETH(R.ax, 0x4a);                                            // 0623 mov ah, 0x4a
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0625 or bx, bx
  if (!R.zf) goto L_062b;                                      // 0627 jne 0x62b
  SETH(R.ax, 0x49);                                            // 0629 mov ah, 0x49
L_062b:   ASM_INT(0x21);                                               // 062b int 0x21
  if (R.cf) goto L_05f7;                                       // 062d jb 0x5f7
L_062f:   R.ax = (u16)(0x1);                                           // 062f mov ax, 1
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0632 retf
L_0633:   R.ax = (u16)(M16(CS, (u16)(0x5d0)));                         // 0633 mov ax, word ptr cs:[0x5d0]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5cc))));            // 0637 sub ax, word ptr cs:[0x5cc]
  if (R.cf || R.zf) goto L_0671;                               // 063c jbe 0x671
  SUB16(R.ax, 0x1000);                                         // 063e cmp ax, 0x1000
  if (R.cf) goto L_0646;                                       // 0641 jb 0x646
  R.ax = (u16)(0xfff);                                         // 0643 mov ax, 0xfff
L_0646:   R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0646 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0648 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 064a shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 064c shl ax, 1
  W16(CS, (u16)(0x5d2), R.ax);                                 // 064e mov word ptr cs:[0x5d2], ax
L_0652:   R.bx = (u16)(R.sp);                                          // 0652 mov bx, sp
  PUSH(R.di);                                                  // 0654 push di
  { u16 a_ = (u16)(0x5ca); R.di = (u16)(M16(CS, a_)); R.es = M16(CS, (u16)(a_ + 2)); } // 0655 les di, ptr cs:[0x5ca]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 065a mov ax, word ptr [bx + 4]
  STOSW();                                                     // 065d stosw word ptr es:[di], ax
  W16(CS, (u16)(0x5e4), R.ax);                                 // 065e mov word ptr cs:[0x5e4], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 0662 mov ax, word ptr [bx + 6]
  STOSW();                                                     // 0665 stosw word ptr es:[di], ax
  W16(CS, (u16)(0x5e2), R.ax);                                 // 0666 mov word ptr cs:[0x5e2], ax
  W16(CS, (u16)(0x5ca), R.di);                                 // 066a mov word ptr cs:[0x5ca], di
  R.di = POP();                                                // 066f pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0670 retf
L_0671:   R.ax = (u16)((u16)(0x5be));                                  // 0671 lea ax, [0x5be]
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0675 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0677 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0679 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 067b shr ax, 1
  R.cx = (u16)(R.cs);                                          // 067d mov cx, cs
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 067f add ax, cx
  W16(CS, (u16)(0x5cc), R.ax);                                 // 0681 mov word ptr cs:[0x5cc], ax
  W16(CS, (u16)(0x5d0), R.ax);                                 // 0685 mov word ptr cs:[0x5d0], ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0689 xor ax, ax
  W16(CS, (u16)(0x5ca), R.ax);                                 // 068b mov word ptr cs:[0x5ca], ax
  W16(CS, (u16)(0x5d2), R.ax);                                 // 068f mov word ptr cs:[0x5d2], ax
  W16(CS, (u16)(0x5ce), R.ax);                                 // 0693 mov word ptr cs:[0x5ce], ax
  goto L_0652;                                                 // 0697 jmp 0x652
L_0699:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0699 xor ax, ax
  { u16 t_ = M16(CS, (u16)(0x5ca)); W16(CS, (u16)(0x5ca), R.ax); R.ax = (u16)(t_); } // 069b xchg word ptr cs:[0x5ca], ax
  R.ax = (u16)(ADD16(R.ax, 0xf));                              // 06a0 add ax, 0xf
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 06a3 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 06a5 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 06a7 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 06a9 shr ax, 1
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x5cc))));            // 06ab add ax, word ptr cs:[0x5cc]
  { u16 t_ = M16(CS, (u16)(0x5cc)); W16(CS, (u16)(0x5cc), R.ax); R.ax = (u16)(t_); } // 06b0 xchg word ptr cs:[0x5cc], ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 06b5 retf
L_06b6:   PUSH(R.bp);                                                  // 06b6 push bp
  R.bp = (u16)(R.sp);                                          // 06b7 mov bp, sp
  PUSH(R.si);                                                  // 06b9 push si
  PUSH(R.di);                                                  // 06ba push di
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 06bb mov si, word ptr [bp + 6]
  { u16 a_ = (u16)(0x5ca); R.di = (u16)(M16(CS, a_)); R.es = M16(CS, (u16)(a_ + 2)); } // 06be les di, ptr cs:[0x5ca]
  R.ax = (u16)(M16(CS, (u16)(0x5e4)));                         // 06c3 mov ax, word ptr cs:[0x5e4]
  R.ax = (u16)(ADD16(R.ax, 0x4));                              // 06c7 add ax, 4
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 06ca add ax, di
  SUB16(R.ax, M16(CS, (u16)(0x5d2)));                          // 06cc cmp ax, word ptr cs:[0x5d2]
  if (R.cf || R.zf) goto L_06dd;                               // 06d1 jbe 0x6dd
  W16(ES, (u16)(0x2), DEC16(M16(ES, (u16)(0x2))));             // 06d3 dec word ptr es:[2]
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06d8 xor ax, ax
  goto L_0748;                                                 // 06da jmp 0x748
L_06dd:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06dd xor ax, ax
  W16(CS, (u16)(0x5d4), R.ax);                                 // 06df mov word ptr cs:[0x5d4], ax
  W16(CS, (u16)(0x5d6), R.ax);                                 // 06e3 mov word ptr cs:[0x5d6], ax
  W16(CS, (u16)(0x5d8), R.ax);                                 // 06e7 mov word ptr cs:[0x5d8], ax
  R.bp = (u16)(R.di);                                          // 06eb mov bp, di
  STOSW();                                                     // 06ed stosw word ptr es:[di], ax
  STOSW();                                                     // 06ee stosw word ptr es:[di], ax
  R.cx = (u16)(M16(CS, (u16)(0x5e4)));                         // 06ef mov cx, word ptr cs:[0x5e4]
L_06f4:   LODSB();                                                     // 06f4 lodsb al, byte ptr [si]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 06f5 or al, al
  if (R.zf) goto L_0703;                                       // 06f7 je 0x703
  W16(CS, (u16)(0x5d6), 0x0);                                  // 06f9 mov word ptr cs:[0x5d6], 0
  goto L_071a;                                                 // 0700 jmp 0x71a
L_0703:   SUB16(M16(CS, (u16)(0x5d8)), 0x0);                           // 0703 cmp word ptr cs:[0x5d8], 0
  if (!R.zf) goto L_0715;                                      // 0709 jne 0x715
  W16(CS, (u16)(0x5d4), INC16(M16(CS, (u16)(0x5d4))));         // 070b inc word ptr cs:[0x5d4]
  if (--R.cx != 0) goto L_06f4;                                // 0710 loop 0x6f4
  goto L_0722;                                                 // 0712 jmp 0x722
L_0715:   W16(CS, (u16)(0x5d6), INC16(M16(CS, (u16)(0x5d6))));         // 0715 inc word ptr cs:[0x5d6]
L_071a:   W16(CS, (u16)(0x5d8), INC16(M16(CS, (u16)(0x5d8))));         // 071a inc word ptr cs:[0x5d8]
  STOSB();                                                     // 071f stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_06f4;                                // 0720 loop 0x6f4
L_0722:   R.ax = (u16)(M16(CS, (u16)(0x5d8)));                         // 0722 mov ax, word ptr cs:[0x5d8]
  R.bx = (u16)(M16(CS, (u16)(0x5d4)));                         // 0726 mov bx, word ptr cs:[0x5d4]
  R.cx = (u16)(M16(CS, (u16)(0x5d6)));                         // 072b mov cx, word ptr cs:[0x5d6]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 0730 or cx, cx
  if (R.zf) goto L_0738;                                       // 0732 je 0x738
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 0734 sub ax, cx
  R.di = (u16)(SUB16(R.di, R.cx));                             // 0736 sub di, cx
L_0738:   W16(ES, (u16)(R.bp), R.ax);                                  // 0738 mov word ptr es:[bp], ax
  W16(ES, (u16)(R.bp + 0x2), R.bx);                            // 073c mov word ptr es:[bp + 2], bx
  W16(CS, (u16)(0x5ca), R.di);                                 // 0740 mov word ptr cs:[0x5ca], di
  R.ax = (u16)(0x1);                                           // 0745 mov ax, 1
L_0748:   R.di = POP();                                                // 0748 pop di
  R.si = POP();                                                // 0749 pop si
  R.bp = POP();                                                // 074a pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 074b retf
L_074c:   PUSH(R.bp);                                                  // 074c push bp
  R.bp = (u16)(R.sp);                                          // 074d mov bp, sp
  PUSH(R.si);                                                  // 074f push si
  PUSH(R.ds);                                                  // 0750 push ds
  PUSH(M16(SS, (u16)(R.bp + 0xe)));                            // 0751 push word ptr [bp + 0xe]
  PUSH(M16(SS, (u16)(R.bp + 0xc)));                            // 0754 push word ptr [bp + 0xc]
  PUSH(0x19bd); PUSH(0x075c); goto L_0633;                     // 0757 lcall 0, 0x633
L_075c:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 075c add sp, 4
  SUB16(M16(CS, (u16)(0x5e2)), 0x0);                           // 075f cmp word ptr cs:[0x5e2], 0
  if (R.zf) goto L_079a;                                       // 0765 je 0x79a
  SUB16(M16(CS, (u16)(0x5e4)), 0x0);                           // 0767 cmp word ptr cs:[0x5e4], 0
  if (R.zf) goto L_079a;                                       // 076d je 0x79a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 076f mov bx, word ptr [bp + 6]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0772 shl bx, 1
  R.ds = (u16)(M16(CS, (u16)(R.bx + 0x1138)));                 // 0774 mov ds, word ptr cs:[bx + 0x1138]
  R.si = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0779 mov si, word ptr [bp + 0xa]
  R.si = (u16)(SHL16(R.si, 0x1));                              // 077c shl si, 1
  R.si = (u16)(M16(CS, (u16)(R.si + 0xfa8)));                  // 077e mov si, word ptr cs:[si + 0xfa8]
  R.si = (u16)(ADD16(R.si, M16(SS, (u16)(R.bp + 0x8))));       // 0783 add si, word ptr [bp + 8]
L_0786:   PUSH(R.si);                                                  // 0786 push si
  PUSH(0x19bd); PUSH(0x078c); goto L_06b6;                     // 0787 lcall 0, 0x6b6
L_078c:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 078c add sp, 2
  R.si = (u16)(ADD16(R.si, 0x140));                            // 078f add si, 0x140
  W16(CS, (u16)(0x5e2), DEC16(M16(CS, (u16)(0x5e2))));         // 0793 dec word ptr cs:[0x5e2]
  if (!R.zf) goto L_0786;                                      // 0798 jne 0x786
L_079a:   PUSH(0x19bd); PUSH(0x079f); goto L_0699;                     // 079a lcall 0, 0x699
L_079f:   R.ds = POP();                                                // 079f pop ds
  R.si = POP();                                                // 07a0 pop si
  R.bp = POP();                                                // 07a1 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 07a2 retf
L_07a3:   PUSH(R.bp);                                                  // 07a3 push bp
  R.bp = (u16)(R.sp);                                          // 07a4 mov bp, sp
  PUSH(R.si);                                                  // 07a6 push si
  PUSH(R.di);                                                  // 07a7 push di
  PUSH(0x19bd); PUSH(0x07ad); goto L_07b1;                     // 07a8 lcall 0, 0x7b1
L_07ad:   R.di = POP();                                                // 07ad pop di
  R.si = POP();                                                // 07ae pop si
  R.bp = POP();                                                // 07af pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 07b0 retf
L_07b1:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 07b1 retf
L_07b2:   PUSH(R.bp);                                                  // 07b2 push bp
  R.bp = (u16)(R.sp);                                          // 07b3 mov bp, sp
  PUSH(R.si);                                                  // 07b5 push si
  PUSH(R.di);                                                  // 07b6 push di
  PUSH(R.ds);                                                  // 07b7 push ds
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 07b8 mov dx, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 07bb mov di, word ptr [bp + 0xa]
  R.ds = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 07be mov ds, word ptr [bp + 0xc]
  R.si = (u16)(XOR16(R.si, R.si));                             // 07c1 xor si, si
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 07c3 mov bp, word ptr [bp + 6]
  PUSH(0x19bd); PUSH(0x07cb); goto L_07d0;                     // 07c6 lcall 0, 0x7d0
L_07cb:   R.ds = POP();                                                // 07cb pop ds
  R.di = POP();                                                // 07cc pop di
  R.si = POP();                                                // 07cd pop si
  R.bp = POP();                                                // 07ce pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 07cf retf
L_07d0:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07d0 xor ax, ax
  W16(CS, (u16)(0x5da), R.ax);                                 // 07d2 mov word ptr cs:[0x5da], ax
  W16(CS, (u16)(0x5dc), R.ax);                                 // 07d6 mov word ptr cs:[0x5dc], ax
  W16(CS, (u16)(0x5de), R.ax);                                 // 07da mov word ptr cs:[0x5de], ax
  W16(CS, (u16)(0x5e0), R.ax);                                 // 07de mov word ptr cs:[0x5e0], ax
  W16(CS, (u16)(0x5c2), R.ax);                                 // 07e2 mov word ptr cs:[0x5c2], ax
  W16(CS, (u16)(0x5c4), R.ax);                                 // 07e6 mov word ptr cs:[0x5c4], ax
  W16(CS, (u16)(0x5c6), R.ax);                                 // 07ea mov word ptr cs:[0x5c6], ax
  W16(CS, (u16)(0x5c8), R.ax);                                 // 07ee mov word ptr cs:[0x5c8], ax
  R.cx = (u16)(M16(DS, (u16)(R.si)));                          // 07f2 mov cx, word ptr [si]
  R.bx = (u16)(M16(DS, (u16)(R.si + 0x2)));                    // 07f4 mov bx, word ptr [si + 2]
  R.di = (u16)(OR16(R.di, R.di));                              // 07f7 or di, di
  if (!R.sf) goto L_0807;                                      // 07f9 jns 0x807
  R.ax = (u16)(R.di);                                          // 07fb mov ax, di
  R.ax = (u16)(NEG16(R.ax));                                   // 07fd neg ax
  SUB16(R.ax, R.bx);                                           // 07ff cmp ax, bx
  if (!R.cf) goto L_0881;                                      // 0801 jae 0x881
  W16(CS, (u16)(0x5da), R.ax);                                 // 0803 mov word ptr cs:[0x5da], ax
L_0807:   R.ax = (u16)(R.di);                                          // 0807 mov ax, di
  R.ax = (u16)(ADD16(R.ax, R.bx));                             // 0809 add ax, bx
  R.ax = (u16)(DEC16(R.ax));                                   // 080b dec ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 080c mov bx, word ptr [bp + 8]
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 080f or bx, bx
  if (R.sf) goto L_0881;                                       // 0811 js 0x881
  SUB16(R.di, R.bx);                                           // 0813 cmp di, bx
  if (!R.zf && R.sf == R.of) goto L_0881;                      // 0815 jg 0x881
  R.ax = (u16)(SUB16(R.ax, R.bx));                             // 0817 sub ax, bx
  if (R.zf || R.sf != R.of) goto L_081f;                       // 0819 jle 0x81f
  W16(CS, (u16)(0x5de), R.ax);                                 // 081b mov word ptr cs:[0x5de], ax
L_081f:   R.dx = (u16)(OR16(R.dx, R.dx));                              // 081f or dx, dx
  if (!R.sf) goto L_082f;                                      // 0821 jns 0x82f
  R.ax = (u16)(R.dx);                                          // 0823 mov ax, dx
  R.ax = (u16)(NEG16(R.ax));                                   // 0825 neg ax
  SUB16(R.ax, R.cx);                                           // 0827 cmp ax, cx
  if (!R.cf) goto L_0881;                                      // 0829 jae 0x881
  W16(CS, (u16)(0x5dc), R.ax);                                 // 082b mov word ptr cs:[0x5dc], ax
L_082f:   R.ax = (u16)(R.dx);                                          // 082f mov ax, dx
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0831 add ax, cx
  R.ax = (u16)(DEC16(R.ax));                                   // 0833 dec ax
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0834 mov cx, word ptr [bp + 6]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 0837 or cx, cx
  if (R.sf) goto L_0881;                                       // 0839 js 0x881
  SUB16(R.dx, R.cx);                                           // 083b cmp dx, cx
  if (!R.zf && R.sf == R.of) goto L_0881;                      // 083d jg 0x881
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 083f sub ax, cx
  if (R.zf || R.sf != R.of) goto L_0847;                       // 0841 jle 0x847
  W16(CS, (u16)(0x5e0), R.ax);                                 // 0843 mov word ptr cs:[0x5e0], ax
L_0847:   R.ax = (u16)(M16(CS, (u16)(0x5dc)));                         // 0847 mov ax, word ptr cs:[0x5dc]
  R.ax = (u16)(ADD16(R.ax, R.dx));                             // 084b add ax, dx
  W16(CS, (u16)(0x5c2), R.ax);                                 // 084d mov word ptr cs:[0x5c2], ax
  R.ax = (u16)(M16(CS, (u16)(0x5da)));                         // 0851 mov ax, word ptr cs:[0x5da]
  R.ax = (u16)(ADD16(R.ax, R.di));                             // 0855 add ax, di
  W16(CS, (u16)(0x5c4), R.ax);                                 // 0857 mov word ptr cs:[0x5c4], ax
  R.ax = (u16)(M16(DS, (u16)(R.si)));                          // 085b mov ax, word ptr [si]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5dc))));            // 085d sub ax, word ptr cs:[0x5dc]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5e0))));            // 0862 sub ax, word ptr cs:[0x5e0]
  W16(CS, (u16)(0x5c6), R.ax);                                 // 0867 mov word ptr cs:[0x5c6], ax
  R.ax = (u16)(M16(DS, (u16)(R.si + 0x2)));                    // 086b mov ax, word ptr [si + 2]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5da))));            // 086e sub ax, word ptr cs:[0x5da]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5de))));            // 0873 sub ax, word ptr cs:[0x5de]
  W16(CS, (u16)(0x5c8), R.ax);                                 // 0878 mov word ptr cs:[0x5c8], ax
  PUSH(0x19bd); PUSH(0x0881); goto L_08b7;                     // 087c lcall 0, 0x8b7
L_0881:   R.ax = (u16)(0x5c2);                                         // 0881 mov ax, 0x5c2
  R.dx = (u16)(R.cs);                                          // 0884 mov dx, cs
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0886 retf
L_0887:   PUSH(R.bp);                                                  // 0887 push bp
  R.bp = (u16)(R.sp);                                          // 0888 mov bp, sp
  PUSH(R.si);                                                  // 088a push si
  PUSH(R.di);                                                  // 088b push di
  PUSH(R.ds);                                                  // 088c push ds
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 088d mov dx, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0890 mov di, word ptr [bp + 0xa]
  R.ds = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0893 mov ds, word ptr [bp + 0xc]
  R.si = (u16)(XOR16(R.si, R.si));                             // 0896 xor si, si
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0898 mov bp, word ptr [bp + 6]
  PUSH(0x19bd); PUSH(0x08a0); goto L_08a5;                     // 089b lcall 0, 0x8a5
L_08a0:   R.ds = POP();                                                // 08a0 pop ds
  R.di = POP();                                                // 08a1 pop di
  R.si = POP();                                                // 08a2 pop si
  R.bp = POP();                                                // 08a3 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 08a4 retf
L_08a5:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 08a5 xor ax, ax
  W16(CS, (u16)(0x5da), R.ax);                                 // 08a7 mov word ptr cs:[0x5da], ax
  W16(CS, (u16)(0x5dc), R.ax);                                 // 08ab mov word ptr cs:[0x5dc], ax
  W16(CS, (u16)(0x5de), R.ax);                                 // 08af mov word ptr cs:[0x5de], ax
  W16(CS, (u16)(0x5e0), R.ax);                                 // 08b3 mov word ptr cs:[0x5e0], ax
L_08b7:   PUSH(R.bp);                                                  // 08b7 push bp
  PUSH(R.es);                                                  // 08b8 push es
  R.bx = (u16)(M16(SS, (u16)(R.bp)));                          // 08b9 mov bx, word ptr [bp]
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 08bc shl bx, 1
  R.es = (u16)(M16(CS, (u16)(R.bx + 0x1138)));                 // 08be mov es, word ptr cs:[bx + 0x1138]
  R.dx = (u16)(ADD16(R.dx, M16(SS, (u16)(R.bp + 0x2))));       // 08c3 add dx, word ptr [bp + 2]
  R.di = (u16)(ADD16(R.di, M16(SS, (u16)(R.bp + 0x4))));       // 08c6 add di, word ptr [bp + 4]
  R.di = (u16)(ADD16(R.di, M16(CS, (u16)(0x5da))));            // 08c9 add di, word ptr cs:[0x5da]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 08ce shl di, 1
  R.bp = (u16)(M16(CS, (u16)(R.di + 0xfa8)));                  // 08d0 mov bp, word ptr cs:[di + 0xfa8]
  R.bp = (u16)(ADD16(R.bp, R.dx));                             // 08d5 add bp, dx
  LODSW();                                                     // 08d7 lodsw ax, word ptr [si]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5e0))));            // 08d8 sub ax, word ptr cs:[0x5e0]
  if (R.zf || R.sf != R.of) goto L_0945;                       // 08dd jle 0x945
  W16(CS, (u16)(0x5e4), R.ax);                                 // 08df mov word ptr cs:[0x5e4], ax
  LODSW();                                                     // 08e3 lodsw ax, word ptr [si]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5da))));            // 08e4 sub ax, word ptr cs:[0x5da]
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5de))));            // 08e9 sub ax, word ptr cs:[0x5de]
  if (R.zf || R.sf != R.of) goto L_0945;                       // 08ee jle 0x945
  W16(CS, (u16)(0x5e2), R.ax);                                 // 08f0 mov word ptr cs:[0x5e2], ax
  R.cx = (u16)(M16(CS, (u16)(0x5da)));                         // 08f4 mov cx, word ptr cs:[0x5da]
  if (R.cx == 0) goto L_0903;                                  // 08f9 jcxz 0x903
L_08fb:   LODSW();                                                     // 08fb lodsw ax, word ptr [si]
  R.si = (u16)(ADD16(R.si, 0x2));                              // 08fc add si, 2
  R.si = (u16)(ADD16(R.si, R.ax));                             // 08ff add si, ax
  if (--R.cx != 0) goto L_08fb;                                // 0901 loop 0x8fb
L_0903:   LODSW();                                                     // 0903 lodsw ax, word ptr [si]
  R.cx = (u16)(R.ax);                                          // 0904 mov cx, ax
  R.dx = (u16)(R.ax);                                          // 0906 mov dx, ax
  LODSW();                                                     // 0908 lodsw ax, word ptr [si]
  if (R.cx == 0) goto L_0938;                                  // 0909 jcxz 0x938
  R.bx = (u16)(R.ax);                                          // 090b mov bx, ax
  R.cx = (u16)(ADD16(R.cx, R.ax));                             // 090d add cx, ax
  R.ax = (u16)(SUB16(R.ax, M16(CS, (u16)(0x5dc))));            // 090f sub ax, word ptr cs:[0x5dc]
  if (!R.cf && !R.zf) goto L_091c;                             // 0914 ja 0x91c
  R.si = (u16)(SUB16(R.si, R.ax));                             // 0916 sub si, ax
  R.bx = (u16)(SUB16(R.bx, R.ax));                             // 0918 sub bx, ax
  R.dx = (u16)(ADD16(R.dx, R.ax));                             // 091a add dx, ax
L_091c:   R.ax = (u16)(M16(CS, (u16)(0x5e4)));                         // 091c mov ax, word ptr cs:[0x5e4]
  SUB16(R.ax, R.cx);                                           // 0920 cmp ax, cx
  if (!R.cf && !R.zf) goto L_0926;                             // 0922 ja 0x926
  R.cx = (u16)(R.ax);                                          // 0924 mov cx, ax
L_0926:   R.cx = (u16)(SUB16(R.cx, R.bx));                             // 0926 sub cx, bx
  if (R.cf || R.zf) goto L_0938;                               // 0928 jbe 0x938
  R.di = (u16)(R.bp);                                          // 092a mov di, bp
  R.di = (u16)(ADD16(R.di, R.bx));                             // 092c add di, bx
  R.dx = (u16)(SUB16(R.dx, R.cx));                             // 092e sub dx, cx
L_0930:   LODSB();                                                     // 0930 lodsb al, byte ptr [si]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 0931 or al, al
  if (R.zf) goto L_0948;                                       // 0933 je 0x948
  STOSB();                                                     // 0935 stosb byte ptr es:[di], al
  if (--R.cx != 0) goto L_0930;                                // 0936 loop 0x930
L_0938:   R.bp = (u16)(ADD16(R.bp, 0x140));                            // 0938 add bp, 0x140
  R.si = (u16)(ADD16(R.si, R.dx));                             // 093c add si, dx
  W16(CS, (u16)(0x5e2), DEC16(M16(CS, (u16)(0x5e2))));         // 093e dec word ptr cs:[0x5e2]
  if (!R.zf) goto L_0903;                                      // 0943 jne 0x903
L_0945:   R.es = POP();                                                // 0945 pop es
  R.bp = POP();                                                // 0946 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0947 retf
L_0948:   R.di = (u16)(INC16(R.di));                                   // 0948 inc di
  if (--R.cx != 0) goto L_0930;                                // 0949 loop 0x930
  goto L_0938;                                                 // 094b jmp 0x938
L_0955:   R.bx = (u16)(R.sp);                                          // 0955 mov bx, sp
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x4)));                       // 0957 mov al, byte ptr [bx + 4]
  W8(CS, (u16)(0x954), (u8)R.ax);                              // 095a mov byte ptr cs:[0x954], al
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 095e retf
L_095f:   R.ax = (u16)(M16(CS, (u16)(0x952)));                         // 095f mov ax, word ptr cs:[0x952]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0963 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0965 shl ax, 1
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0x952))));            // 0967 add ax, word ptr cs:[0x952]
  R.ax = (u16)(INC16(R.ax));                                   // 096c inc ax
  W16(CS, (u16)(0x952), R.ax);                                 // 096d mov word ptr cs:[0x952], ax
  SETL(R.bx, (u8)R.ax);                                        // 0971 mov bl, al
  R.bx = (u16)(AND16(R.bx, 0x3));                              // 0973 and bx, 3
  SETL(R.bx, M8(CS, (u16)(R.bx + 0x94e)));                     // 0976 mov bl, byte ptr cs:[bx + 0x94e]
  R.dx = (u16)(R.bx);                                          // 097b mov dx, bx
  R.dx = (u16)(SHL16(R.dx, 0x1));                              // 097d shl dx, 1
  R.bx = (u16)(ADD16(R.bx, R.dx));                             // 097f add bx, dx
  SETL(R.cx, 0x8d);                                            // 0981 mov cl, 0x8d
  SETH(R.cx, M8(CS, (u16)(R.bx + 0xdaa)));                     // 0983 mov ch, byte ptr cs:[bx + 0xdaa]
  R.bx = (u16)(INC16(R.bx));                                   // 0988 inc bx
  R.bx = (u16)(M16(CS, (u16)(R.bx + 0xdaa)));                  // 0989 mov bx, word ptr cs:[bx + 0xdaa]
L_098e:   R.dx = (u16)(0x3c8);                                         // 098e mov dx, 0x3c8
  SETL(R.ax, (u8)R.cx);                                        // 0991 mov al, cl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0993 out dx, al
  R.dx = (u16)(INC16(R.dx));                                   // 0994 inc dx
  SETL(R.ax, (u8)(R.cx >> 8));                                 // 0995 mov al, ch
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0997 out dx, al
  SETL(R.ax, (u8)R.bx);                                        // 0998 mov al, bl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 099a out dx, al
  SETL(R.ax, (u8)(R.bx >> 8));                                 // 099b mov al, bh
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 099d out dx, al
  SETL(R.cx, ADD8((u8)R.cx, 0x10));                            // 099e add cl, 0x10
  SUB8((u8)R.cx, 0x1d);                                        // 09a1 cmp cl, 0x1d
  if (!R.zf) goto L_098e;                                      // 09a4 jne 0x98e
  SUB8(M8(CS, (u16)(0x954)), 0x0);                             // 09a6 cmp byte ptr cs:[0x954], 0
  if (R.zf) goto L_09c0;                                       // 09ac je 0x9c0
  SETH(R.ax, AND8((u8)(R.ax >> 8), 0x3));                      // 09ae and ah, 3
  W8(CS, (u16)(0x954), DEC8(M8(CS, (u16)(0x954))));            // 09b1 dec byte ptr cs:[0x954]
  if (!R.zf) goto L_09ba;                                      // 09b6 jne 0x9ba
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 09b8 xor ah, ah
L_09ba:   R.dx = (u16)(0x3d4);                                         // 09ba mov dx, 0x3d4
  SETL(R.ax, 0xd);                                             // 09bd mov al, 0xd
  ASM_PORT_OUT16(R.dx, R.ax);                                  // 09bf out dx, ax
L_09c0:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 09c0 retf
L_09c2:   SETL(R.ax, AND8((u8)R.ax, 0x7f));                            // 09c2 and al, 0x7f
  W8(DS, (u16)(0x442), (u8)R.ax);                              // 09c4 mov byte ptr [0x442], al
  goto L_0a00;                                                 // 09c7 jmp 0xa00
L_09ca:   R.bp = POP();                                                // 09ca pop bp
  SETL(R.ax, M8(DS, (u16)(0x442)));                            // 09cb mov al, byte ptr [0x442]
  W8(SS, (u16)(R.bp + 0xc), (u8)R.ax);                         // 09ce mov byte ptr [bp + 0xc], al
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 09d1 retf
L_09d2:   SETL(R.ax, M8(SS, (u16)(R.bp + 0xc)));                       // 09d2 mov al, byte ptr [bp + 0xc]
  W8(DS, (u16)(0x442), (u8)R.ax);                              // 09d5 mov byte ptr [0x442], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xe)));                       // 09d8 mov al, byte ptr [bp + 0xe]
  W8(DS, (u16)(0x443), (u8)R.ax);                              // 09db mov byte ptr [0x443], al
  SETL(R.ax, M8(SS, (u16)(R.bp + 0xa)));                       // 09de mov al, byte ptr [bp + 0xa]
  W8(DS, (u16)(0x444), (u8)R.ax);                              // 09e1 mov byte ptr [0x444], al
  PUSH(R.bp);                                                  // 09e4 push bp
  R.bp = (u16)(M16(DS, (u16)(0x455)));                         // 09e5 mov bp, word ptr [0x455]
  R.bx = (u16)(R.es);                                          // 09e9 mov bx, es
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 09eb shl bx, 1
  R.es = (u16)(M16(CS, (u16)(R.bx + 0x1138)));                 // 09ed mov es, word ptr cs:[bx + 0x1138]
  R.di = (u16)(M16(DS, (u16)(0x459)));                         // 09f2 mov di, word ptr [0x459]
  R.di = (u16)(SHL16(R.di, 0x1));                              // 09f6 shl di, 1
  R.di = (u16)(M16(DS, (u16)(R.di + 0x258)));                  // 09f8 mov di, word ptr [di + 0x258]
  R.di = (u16)(ADD16(R.di, M16(DS, (u16)(0x457))));            // 09fc add di, word ptr [0x457]
L_0a00:   R.ax = (u16)(M16(SS, (u16)(R.si)));                          // 0a00 mov ax, word ptr ss:[si]
  R.si = (u16)(INC16(R.si));                                   // 0a03 inc si
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 0a04 or al, al
  if (R.zf) goto L_09ca;                                       // 0a06 je 0x9ca
  if (R.sf) goto L_09c2;                                       // 0a08 js 0x9c2
  PUSH(R.si);                                                  // 0a0a push si
  PUSH(R.di);                                                  // 0a0b push di
  SETL(R.ax, SUB8((u8)R.ax, M8(DS, (u16)(0x448))));            // 0a0c sub al, byte ptr [0x448]
  R.si = (u16)(R.ax);                                          // 0a10 mov si, ax
  R.si = (u16)(AND16(R.si, 0xff));                             // 0a12 and si, 0xff
  SETL(R.cx, M8(DS, (u16)(0x44d)));                            // 0a16 mov cl, byte ptr [0x44d]
  SETL(R.cx, OR8((u8)R.cx, (u8)R.cx));                         // 0a1a or cl, cl
  if (!R.zf) goto L_0a28;                                      // 0a1c jne 0xa28
  R.bx = (u16)(M16(DS, (u16)(0x446)));                         // 0a1e mov bx, word ptr [0x446]
  SETL(R.cx, M8(DS, (u16)(R.bx + R.si)));                      // 0a22 mov cl, byte ptr [bx + si]
  SETL(R.cx, ADD8((u8)R.cx, M8(DS, (u16)(0x449))));            // 0a24 add cl, byte ptr [0x449]
L_0a28:   SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 0a28 or ah, ah
  if (!R.zf) goto L_0a30;                                      // 0a2a jne 0xa30
  SETL(R.cx, SUB8((u8)R.cx, M8(DS, (u16)(0x452))));            // 0a2c sub cl, byte ptr [0x452]
L_0a30:   SETL(R.cx, SUB8((u8)R.cx, M8(DS, (u16)(0x44e))));            // 0a30 sub cl, byte ptr [0x44e]
  W8(DS, (u16)(0x445), (u8)R.cx);                              // 0a34 mov byte ptr [0x445], cl
  SETL(R.cx, M8(DS, (u16)(0x44c)));                            // 0a38 mov cl, byte ptr [0x44c]
  R.si = (u16)(SHL16(R.si, (u8)R.cx));                         // 0a3c shl si, cl
  R.si = (u16)(ADD16(R.si, M16(DS, (u16)(0x44a))));            // 0a3e add si, word ptr [0x44a]
  SETL(R.cx, M8(DS, (u16)(0x44e)));                            // 0a42 mov cl, byte ptr [0x44e]
  SETH(R.cx, M8(DS, (u16)(0x453)));                            // 0a46 mov ch, byte ptr [0x453]
  SETL(R.dx, M8(DS, (u16)(0x442)));                            // 0a4a mov dl, byte ptr [0x442]
  SETH(R.dx, M8(DS, (u16)(0x443)));                            // 0a4e mov dh, byte ptr [0x443]
  SUB8(M8(DS, (u16)(0x444)), 0x1);                             // 0a52 cmp byte ptr [0x444], 1
  if (R.zf) goto L_0a98;                                       // 0a57 je 0xa98
  SETL(R.ax, M8(DS, (u16)(0x445)));                            // 0a59 mov al, byte ptr [0x445]
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 0a5c or ah, ah
  if (R.zf) goto L_0a64;                                       // 0a5e je 0xa64
  SETL(R.ax, SUB8((u8)R.ax, M8(DS, (u16)(0x449))));            // 0a60 sub al, byte ptr [0x449]
L_0a64:   PUSH(R.di);                                                  // 0a64 push di
  SETH(R.ax, (u8)R.ax);                                        // 0a65 mov ah, al
  R.bx = (u16)(M16(DS, (u16)(R.si)));                          // 0a67 mov bx, word ptr [si]
  { u16 t_ = (u8)R.bx; SETL(R.bx, (u8)(R.bx >> 8)); SETH(R.bx, t_); } // 0a69 xchg bl, bh
  R.bx = (u16)(SHL16(R.bx, (u8)R.cx));                         // 0a6b shl bx, cl
L_0a6d:   R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0a6d shl bx, 1
  if (!R.cf) goto L_0a74;                                      // 0a6f jae 0xa74
  W8(ES, (u16)(R.di), (u8)R.dx);                               // 0a71 mov byte ptr es:[di], dl
L_0a74:   R.di = (u16)(INC16(R.di));                                   // 0a74 inc di
  SETH(R.ax, DEC8((u8)(R.ax >> 8)));                           // 0a75 dec ah
  if (!R.zf) goto L_0a6d;                                      // 0a77 jne 0xa6d
  R.di = POP();                                                // 0a79 pop di
  R.di = (u16)(ADD16(R.di, 0x140));                            // 0a7a add di, 0x140
  R.si = (u16)(ADD16(R.si, R.bp));                             // 0a7e add si, bp
  SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 0a80 dec ch
  if (!R.zf) goto L_0a64;                                      // 0a82 jne 0xa64
L_0a84:   R.di = POP();                                                // 0a84 pop di
  R.si = POP();                                                // 0a85 pop si
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0a86 xor ah, ah
  W8(DS, (u16)(0x44e), (u8)(R.ax >> 8));                       // 0a88 mov byte ptr [0x44e], ah
  SETL(R.ax, M8(DS, (u16)(0x445)));                            // 0a8c mov al, byte ptr [0x445]
  R.di = (u16)(ADD16(R.di, R.ax));                             // 0a8f add di, ax
  W16(DS, (u16)(0x457), ADD16(M16(DS, (u16)(0x457)), R.ax));   // 0a91 add word ptr [0x457], ax
  goto L_0a00;                                                 // 0a95 jmp 0xa00
L_0a98:   PUSH(R.di);                                                  // 0a98 push di
  SETH(R.ax, M8(DS, (u16)(0x445)));                            // 0a99 mov ah, byte ptr [0x445]
  R.bx = (u16)(M16(DS, (u16)(R.si)));                          // 0a9d mov bx, word ptr [si]
  { u16 t_ = (u8)R.bx; SETL(R.bx, (u8)(R.bx >> 8)); SETH(R.bx, t_); } // 0a9f xchg bl, bh
  R.bx = (u16)(SHL16(R.bx, (u8)R.cx));                         // 0aa1 shl bx, cl
L_0aa3:   SETL(R.ax, (u8)R.dx);                                        // 0aa3 mov al, dl
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0aa5 shl bx, 1
  if (R.cf) goto L_0aab;                                       // 0aa7 jb 0xaab
  SETL(R.ax, (u8)(R.dx >> 8));                                 // 0aa9 mov al, dh
L_0aab:   STOSB();                                                     // 0aab stosb byte ptr es:[di], al
  SETH(R.ax, DEC8((u8)(R.ax >> 8)));                           // 0aac dec ah
  if (!R.zf) goto L_0aa3;                                      // 0aae jne 0xaa3
  R.di = POP();                                                // 0ab0 pop di
  R.di = (u16)(ADD16(R.di, 0x140));                            // 0ab1 add di, 0x140
  R.si = (u16)(ADD16(R.si, R.bp));                             // 0ab5 add si, bp
  SETH(R.cx, DEC8((u8)(R.cx >> 8)));                           // 0ab7 dec ch
  if (!R.zf) goto L_0a98;                                      // 0ab9 jne 0xa98
  goto L_0a84;                                                 // 0abb jmp 0xa84
L_0abe:   PUSH(R.bp);                                                  // 0abe push bp
  R.bp = (u16)(R.sp);                                          // 0abf mov bp, sp
  PUSH(R.si);                                                  // 0ac1 push si
  PUSH(R.di);                                                  // 0ac2 push di
  PUSH(R.es);                                                  // 0ac3 push es
  R.ax = (u16)(0x1a92 /* segment */);                          // 0ac4 mov ax, 0xd5
  R.es = (u16)(R.ax);                                          // 0ac7 mov es, ax
  R.si = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0ac9 mov si, word ptr [bp + 8]
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0acc mov di, word ptr [bp + 6]
  SUB16(R.di, M16(ES, (u16)(0x460)));                          // 0acf cmp di, word ptr es:[0x460]
  if (!R.cf && !R.zf) goto L_0b09;                             // 0ad4 ja 0xb09
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0ad6 shl di, 1
  if (R.zf) goto L_0b09;                                       // 0ad8 je 0xb09
  R.di = (u16)(M16(ES, (u16)(R.di + 0x460)));                  // 0ada mov di, word ptr es:[di + 0x460]
  R.di = (u16)(ADD16(R.di, 0x460));                            // 0adf add di, 0x460
  SETL(R.cx, M8(DS, (u16)(R.si + 0xfff9)));                    // 0ae3 mov cl, byte ptr [si - 7]
  SETL(R.cx, SUB8((u8)R.cx, M8(DS, (u16)(R.si + 0xfff8))));    // 0ae6 sub cl, byte ptr [si - 8]
  SETL(R.cx, INC8((u8)R.cx));                                  // 0ae9 inc cl
  SETH(R.cx, XOR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 0aeb xor ch, ch
  SETH(R.ax, M8(DS, (u16)(R.si + 0xfffc)));                    // 0aed mov ah, byte ptr [si - 4]
  SETH(R.ax, ADD8((u8)(R.ax >> 8), M8(DS, (u16)(R.si + 0xfffe)))); // 0af0 add ah, byte ptr [si - 2]
  SETL(R.ax, M8(DS, (u16)(R.si + 0xfffa)));                    // 0af3 mov al, byte ptr [si - 6]
  MUL8((u8)(R.ax >> 8));                                       // 0af6 mul ah
  MUL8((u8)R.cx);                                              // 0af8 mul cl
  R.cx = (u16)(ADD16(R.cx, 0x8));                              // 0afa add cx, 8
  R.ax = (u16)(ADD16(R.ax, R.cx));                             // 0afd add ax, cx
  R.si = (u16)(SUB16(R.si, R.cx));                             // 0aff sub si, cx
  R.di = (u16)(SUB16(R.di, R.cx));                             // 0b01 sub di, cx
  R.cx = (u16)(R.ax);                                          // 0b03 mov cx, ax
  R.cx = (u16)(SHR16(R.cx, 0x1));                              // 0b05 shr cx, 1
  REPMOVSW();                                                  // 0b07 rep movsw word ptr es:[di], word ptr [si]
L_0b09:   R.es = POP();                                                // 0b09 pop es
  R.di = POP();                                                // 0b0a pop di
  R.si = POP();                                                // 0b0b pop si
  R.bp = POP();                                                // 0b0c pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0b0d retf
L_0b0e:   PUSH(R.bp);                                                  // 0b0e push bp
  R.bp = (u16)(R.sp);                                          // 0b0f mov bp, sp
  PUSH(R.ds);                                                  // 0b11 push ds
  R.ax = (u16)(0x1a92 /* segment */);                          // 0b12 mov ax, 0xd5
  R.ds = (u16)(R.ax);                                          // 0b15 mov ds, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0b17 xor ax, ax
  SETL(R.cx, M8(SS, (u16)(R.bp + 0x8)));                       // 0b19 mov cl, byte ptr [bp + 8]
  SETL(R.cx, OR8((u8)R.cx, (u8)R.cx));                         // 0b1c or cl, cl
  if (R.sf) goto L_0b59;                                       // 0b1e js 0xb59
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0b20 mov bx, word ptr [bp + 6]
  SUB16(R.bx, M16(DS, (u16)(0x460)));                          // 0b23 cmp bx, word ptr [0x460]
  if (!R.cf && !R.zf) goto L_0b59;                             // 0b27 ja 0xb59
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0b29 shl bx, 1
  if (R.zf) goto L_0b59;                                       // 0b2b je 0xb59
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x460)));                  // 0b2d mov bx, word ptr [bx + 0x460]
  R.bx = (u16)(ADD16(R.bx, 0x460));                            // 0b31 add bx, 0x460
  SUB8((u8)R.cx, M8(DS, (u16)(R.bx + 0xfff8)));                // 0b35 cmp cl, byte ptr [bx - 8]
  if (R.cf) goto L_0b59;                                       // 0b38 jb 0xb59
  SUB8((u8)R.cx, M8(DS, (u16)(R.bx + 0xfff9)));                // 0b3a cmp cl, byte ptr [bx - 7]
  if (!R.cf && !R.zf) goto L_0b59;                             // 0b3d ja 0xb59
  SETH(R.ax, M8(DS, (u16)(R.bx + 0xfffd)));                    // 0b3f mov ah, byte ptr [bx - 3]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xfffb)));                    // 0b42 mov al, byte ptr [bx - 5]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 0b45 or al, al
  if (!R.zf) goto L_0b59;                                      // 0b47 jne 0xb59
  SETL(R.ax, (u8)R.cx);                                        // 0b49 mov al, cl
  SETL(R.cx, M8(DS, (u16)(R.bx + 0xfff9)));                    // 0b4b mov cl, byte ptr [bx - 7]
  SETL(R.cx, SUB8((u8)R.cx, (u8)R.ax));                        // 0b4e sub cl, al
  SETH(R.cx, XOR8((u8)(R.cx >> 8), (u8)(R.cx >> 8)));          // 0b50 xor ch, ch
  R.bx = (u16)(ADD16(R.bx, 0xfff7));                           // 0b52 add bx, -9
  R.bx = (u16)(SUB16(R.bx, R.cx));                             // 0b55 sub bx, cx
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0b57 mov al, byte ptr [bx]
L_0b59:   SETL(R.ax, ADD8((u8)R.ax, (u8)(R.ax >> 8)));                 // 0b59 add al, ah
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0b5b cwde
  R.ds = POP();                                                // 0b5c pop ds
  R.bp = POP();                                                // 0b5d pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0b5e retf
L_0b5f:   PUSH(R.bp);                                                  // 0b5f push bp
  R.bp = (u16)(R.sp);                                          // 0b60 mov bp, sp
  PUSH(R.ds);                                                  // 0b62 push ds
  R.ax = (u16)(0x1a92 /* segment */);                          // 0b63 mov ax, 0xd5
  R.ds = (u16)(R.ax);                                          // 0b66 mov ds, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0b68 xor ax, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0b6a mov bx, word ptr [bp + 6]
  SUB16(R.bx, M16(DS, (u16)(0x460)));                          // 0b6d cmp bx, word ptr [0x460]
  if (!R.cf && !R.zf) goto L_0b85;                             // 0b71 ja 0xb85
  R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0b73 shl bx, 1
  if (R.zf) goto L_0b85;                                       // 0b75 je 0xb85
  R.bx = (u16)(M16(DS, (u16)(R.bx + 0x460)));                  // 0b77 mov bx, word ptr [bx + 0x460]
  R.bx = (u16)(ADD16(R.bx, 0x460));                            // 0b7b add bx, 0x460
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xfffc)));                    // 0b7f mov al, byte ptr [bx - 4]
  SETL(R.ax, ADD8((u8)R.ax, M8(DS, (u16)(R.bx + 0xfffe))));    // 0b82 add al, byte ptr [bx - 2]
L_0b85:   R.ds = POP();                                                // 0b85 pop ds
  R.bp = POP();                                                // 0b86 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0b87 retf
L_0b88:   PUSH(R.bp);                                                  // 0b88 push bp
  R.bp = (u16)(R.sp);                                          // 0b89 mov bp, sp
  PUSH(R.si);                                                  // 0b8b push si
  PUSH(R.di);                                                  // 0b8c push di
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xc)));                    // 0b8d mov bx, word ptr [bp + 0xc]
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0b90 mov cx, word ptr [bp + 8]
  R.dx = (u16)(M16(SS, (u16)(R.bp + 0xa)));                    // 0b93 mov dx, word ptr [bp + 0xa]
  R.bp = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0b96 mov bp, word ptr [bp + 6]
  PUSH(0x19bd); PUSH(0x0b9e); goto L_0ba2;                     // 0b99 lcall 0, 0xba2
L_0b9e:   R.di = POP();                                                // 0b9e pop di
  R.si = POP();                                                // 0b9f pop si
  R.bp = POP();                                                // 0ba0 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0ba1 retf
L_0ba2:   PUSH(0x0ba5); goto L_0cb9;                                   // 0ba2 call 0xcb9
L_0ba5:   PUSH(0x0ba8); goto L_0bfc;                                   // 0ba5 call 0xbfc
L_0ba8:   PUSH(0x0bab); goto L_0bba;                                   // 0ba8 call 0xbba
L_0bab:   PUSH(0x0bae); goto L_0c4d;                                   // 0bab call 0xc4d
L_0bae:   goto L_0c8d;                                                 // 0bae jmp 0xc8d
L_0bb1:   PUSH(0x0bb4); goto L_0cb9;                                   // 0bb1 call 0xcb9
L_0bb4:   PUSH(0x0bb7); goto L_0bba;                                   // 0bb4 call 0xbba
L_0bb7:   goto L_0c8d;                                                 // 0bb7 jmp 0xc8d
L_0bba:   SUB8(M8(DS, (u16)(0x44d)), 0x0);                             // 0bba cmp byte ptr [0x44d], 0
  if (R.zf) goto L_0bf2;                                       // 0bbf je 0xbf2
  SUB16(M16(SS, (u16)(R.bp + 0x6)), 0x0);                      // 0bc1 cmp word ptr [bp + 6], 0
  if (R.sf) goto L_0bee;                                       // 0bc5 js 0xbee
  R.ax = (u16)(M16(DS, (u16)(0x457)));                         // 0bc7 mov ax, word ptr [0x457]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0bca or ax, ax
  if (!R.sf) goto L_0bf2;                                      // 0bcc jns 0xbf2
  W16(DS, (u16)(0x457), 0x0);                                  // 0bce mov word ptr [0x457], 0
  R.ax = (u16)(NEG16(R.ax));                                   // 0bd4 neg ax
  DIV8(M8(DS, (u16)(0x44d)), 0x0bd6);                          // 0bd6 div byte ptr [0x44d]
  W8(DS, (u16)(0x44e), (u8)(R.ax >> 8));                       // 0bda mov byte ptr [0x44e], ah
  SETL(R.ax, INC8((u8)R.ax));                                  // 0bde inc al
L_0be0:   SETL(R.ax, DEC8((u8)R.ax));                                  // 0be0 dec al
  if (R.zf) goto L_0bf2;                                       // 0be2 je 0xbf2
L_0be4:   SETH(R.ax, M8(SS, (u16)(R.bx)));                             // 0be4 mov ah, byte ptr ss:[bx]
  R.bx = (u16)(INC16(R.bx));                                   // 0be7 inc bx
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));           // 0be8 or ah, ah
  if (R.sf) goto L_0be4;                                       // 0bea js 0xbe4
  if (!R.zf) goto L_0be0;                                      // 0bec jne 0xbe0
L_0bee:   R.ax = POP();                                                // 0bee pop ax
  goto L_0ca2;                                                 // 0bef jmp 0xca2
L_0bf2:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0bf2 ret
L_0bf3:   PUSH(0x0bf6); goto L_0cb9;                                   // 0bf3 call 0xcb9
L_0bf6:   PUSH(0x0bf9); goto L_0bfc;                                   // 0bf6 call 0xbfc
L_0bf9:   goto L_0c8d;                                                 // 0bf9 jmp 0xc8d
L_0bfc:   SUB8(M8(DS, (u16)(0x44d)), 0x0);                             // 0bfc cmp byte ptr [0x44d], 0
  if (R.zf) goto L_0c3f;                                       // 0c01 je 0xc3f
  R.dx = (u16)(M16(DS, (u16)(0x457)));                         // 0c03 mov dx, word ptr [0x457]
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0c07 mov cx, word ptr [bp + 6]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 0c0a or cx, cx
  if (R.sf) goto L_0c40;                                       // 0c0c js 0xc40
  SUB16(R.dx, R.cx);                                           // 0c0e cmp dx, cx
  if (!R.zf && R.sf == R.of) goto L_0c40;                      // 0c10 jg 0xc40
  R.dx = (u16)(DEC16(R.dx));                                   // 0c12 dec dx
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0c13 xor ah, ah
  SETL(R.ax, M8(DS, (u16)(0x44d)));                            // 0c15 mov al, byte ptr [0x44d]
  R.di = (u16)(R.ax);                                          // 0c18 mov di, ax
  R.si = (u16)(R.bx);                                          // 0c1a mov si, bx
  R.si = (u16)(DEC16(R.si));                                   // 0c1c dec si
L_0c1d:   R.si = (u16)(INC16(R.si));                                   // 0c1d inc si
  SUB8(M8(SS, (u16)(R.si)), (u8)(R.ax >> 8));                  // 0c1e cmp byte ptr ss:[si], ah
  if (R.sf) goto L_0c1d;                                       // 0c21 js 0xc1d
  if (R.zf) goto L_0c3f;                                       // 0c23 je 0xc3f
  R.dx = (u16)(ADD16(R.dx, R.di));                             // 0c25 add dx, di
  SUB16(R.dx, R.cx);                                           // 0c27 cmp dx, cx
  if (R.sf != R.of) goto L_0c1d;                               // 0c29 jl 0xc1d
  R.dx = (u16)(SUB16(R.dx, R.cx));                             // 0c2b sub dx, cx
  W8(DS, (u16)(0x452), (u8)R.dx);                              // 0c2d mov byte ptr [0x452], dl
  R.si = (u16)(INC16(R.si));                                   // 0c31 inc si
  SETL(R.ax, M8(SS, (u16)(R.si)));                             // 0c32 mov al, byte ptr ss:[si]
  W8(SS, (u16)(R.si), (u8)(R.ax >> 8));                        // 0c35 mov byte ptr ss:[si], ah
  W8(DS, (u16)(0x451), (u8)R.ax);                              // 0c38 mov byte ptr [0x451], al
  W16(DS, (u16)(0x44f), R.si);                                 // 0c3b mov word ptr [0x44f], si
L_0c3f:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0c3f ret
L_0c40:   R.ax = POP();                                                // 0c40 pop ax
  goto L_0ca2;                                                 // 0c41 jmp 0xca2
L_0c44:   PUSH(0x0c47); goto L_0cb9;                                   // 0c44 call 0xcb9
L_0c47:   PUSH(0x0c4a); goto L_0c4d;                                   // 0c47 call 0xc4d
L_0c4a:   goto L_0c8d;                                                 // 0c4a jmp 0xc8d
L_0c4d:   R.cx = (u16)(M16(SS, (u16)(R.bp + 0x8)));                    // 0c4d mov cx, word ptr [bp + 8]
  R.cx = (u16)(OR16(R.cx, R.cx));                              // 0c50 or cx, cx
  if (R.sf) goto L_0c86;                                       // 0c52 js 0xc86
  R.ax = (u16)(M16(DS, (u16)(0x459)));                         // 0c54 mov ax, word ptr [0x459]
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0c57 or ax, ax
  if (!R.sf) goto L_0c71;                                      // 0c59 jns 0xc71
  R.ax = (u16)(NEG16(R.ax));                                   // 0c5b neg ax
  W16(DS, (u16)(0x453), SUB16(M16(DS, (u16)(0x453)), R.ax));   // 0c5d sub word ptr [0x453], ax
  if (R.cf || R.zf) goto L_0c86;                               // 0c61 jbe 0xc86
  W16(DS, (u16)(0x459), 0x0);                                  // 0c63 mov word ptr [0x459], 0
  MUL16(M16(DS, (u16)(0x455)));                                // 0c69 mul word ptr [0x455]
  W16(DS, (u16)(0x44a), ADD16(M16(DS, (u16)(0x44a)), R.ax));   // 0c6d add word ptr [0x44a], ax
L_0c71:   R.ax = (u16)(M16(DS, (u16)(0x459)));                         // 0c71 mov ax, word ptr [0x459]
  SUB16(R.ax, R.cx);                                           // 0c74 cmp ax, cx
  if (!R.cf && !R.zf) goto L_0c86;                             // 0c76 ja 0xc86
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0x453))));            // 0c78 add ax, word ptr [0x453]
  R.ax = (u16)(DEC16(R.ax));                                   // 0c7c dec ax
  R.ax = (u16)(SUB16(R.ax, R.cx));                             // 0c7d sub ax, cx
  if (R.cf || R.zf) goto L_0c85;                               // 0c7f jbe 0xc85
  W16(DS, (u16)(0x453), SUB16(M16(DS, (u16)(0x453)), R.ax));   // 0c81 sub word ptr [0x453], ax
L_0c85:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0c85 ret
L_0c86:   R.ax = POP();                                                // 0c86 pop ax
  goto L_0ca2;                                                 // 0c87 jmp 0xca2
L_0c8a:   PUSH(0x0c8d); goto L_0cb9;                                   // 0c8a call 0xcb9
L_0c8d:   R.ax = (u16)(M16(SS, (u16)(R.bp + 0x2)));                    // 0c8d mov ax, word ptr [bp + 2]
  W16(DS, (u16)(0x457), ADD16(M16(DS, (u16)(0x457)), R.ax));   // 0c90 add word ptr [0x457], ax
  R.ax = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c94 mov ax, word ptr [bp + 4]
  W16(DS, (u16)(0x459), ADD16(M16(DS, (u16)(0x459)), R.ax));   // 0c97 add word ptr [0x459], ax
  R.si = (u16)(R.bx);                                          // 0c9b mov si, bx
  PUSH(0x19bd); PUSH(0x0ca2); goto L_09d2;                     // 0c9d lcall 0, 0x9d2
L_0ca2:   R.bx = (u16)(M16(DS, (u16)(0x44f)));                         // 0ca2 mov bx, word ptr [0x44f]
  R.bx = (u16)(OR16(R.bx, R.bx));                              // 0ca6 or bx, bx
  if (R.zf) goto L_0cb0;                                       // 0ca8 je 0xcb0
  SETL(R.ax, M8(DS, (u16)(0x451)));                            // 0caa mov al, byte ptr [0x451]
  W8(SS, (u16)(R.bx), (u8)R.ax);                               // 0cad mov byte ptr ss:[bx], al
L_0cb0:   R.ax = (u16)(M16(DS, (u16)(0x457)));                         // 0cb0 mov ax, word ptr [0x457]
  R.ax = (u16)(SUB16(R.ax, M16(SS, (u16)(R.bp + 0x2))));       // 0cb3 sub ax, word ptr [bp + 2]
  R.es = POP();                                                // 0cb6 pop es
  R.ds = POP();                                                // 0cb7 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0cb8 retf
L_0cb9:   R.si = POP();                                                // 0cb9 pop si
  PUSH(R.ds);                                                  // 0cba push ds
  PUSH(R.es);                                                  // 0cbb push es
  R.ax = (u16)(0x1a92 /* segment */);                          // 0cbc mov ax, 0xd5
  R.ds = (u16)(R.ax);                                          // 0cbf mov ds, ax
  R.es = (u16)(M16(SS, (u16)(R.bp)));                          // 0cc1 mov es, word ptr [bp]
  W16(DS, (u16)(0x457), R.cx);                                 // 0cc4 mov word ptr [0x457], cx
  W16(DS, (u16)(0x459), R.dx);                                 // 0cc8 mov word ptr [0x459], dx
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0ccc xor ax, ax
  W16(DS, (u16)(0x44f), R.ax);                                 // 0cce mov word ptr [0x44f], ax
  W8(DS, (u16)(0x44e), (u8)R.ax);                              // 0cd1 mov byte ptr [0x44e], al
  W8(DS, (u16)(0x452), (u8)R.ax);                              // 0cd4 mov byte ptr [0x452], al
  SUB8(M8(SS, (u16)(R.bx)), (u8)R.ax);                         // 0cd7 cmp byte ptr ss:[bx], al
  if (R.zf) goto L_0ca2;                                       // 0cda je 0xca2
  R.di = (u16)(M16(SS, (u16)(R.bp + 0x10)));                   // 0cdc mov di, word ptr [bp + 0x10]
  SUB16(R.di, M16(DS, (u16)(0x460)));                          // 0cdf cmp di, word ptr [0x460]
  if (!R.cf && !R.zf) goto L_0ca2;                             // 0ce3 ja 0xca2
  R.di = (u16)(SHL16(R.di, 0x1));                              // 0ce5 shl di, 1
  if (R.zf) goto L_0ca2;                                       // 0ce7 je 0xca2
  R.di = (u16)(M16(DS, (u16)(R.di + 0x460)));                  // 0ce9 mov di, word ptr [di + 0x460]
  R.di = (u16)(ADD16(R.di, 0x460));                            // 0ced add di, 0x460
  W16(DS, (u16)(0x44a), R.di);                                 // 0cf1 mov word ptr [0x44a], di
  SETL(R.ax, M8(DS, (u16)(R.di + 0xfffc)));                    // 0cf5 mov al, byte ptr [di - 4]
  AND8(M8(SS, (u16)(R.bp + 0xa)), 0x1);                        // 0cf8 test byte ptr [bp + 0xa], 1
  if (R.zf) goto L_0d01;                                       // 0cfc je 0xd01
  SETL(R.ax, ADD8((u8)R.ax, M8(DS, (u16)(R.di + 0xfffe))));    // 0cfe add al, byte ptr [di - 2]
L_0d01:   R.ax = (u16)(i16)(i8)R.ax;                                   // 0d01 cwde
  W16(DS, (u16)(0x453), R.ax);                                 // 0d02 mov word ptr [0x453], ax
  SETH(R.ax, M8(DS, (u16)(R.di + 0xfffd)));                    // 0d05 mov ah, byte ptr [di - 3]
  W8(DS, (u16)(0x449), (u8)(R.ax >> 8));                       // 0d08 mov byte ptr [0x449], ah
  SETL(R.ax, M8(DS, (u16)(R.di + 0xfffb)));                    // 0d0c mov al, byte ptr [di - 5]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 0d0f or al, al
  if (R.zf) goto L_0d15;                                       // 0d11 je 0xd15
  SETL(R.ax, ADD8((u8)R.ax, (u8)(R.ax >> 8)));                 // 0d13 add al, ah
L_0d15:   W8(DS, (u16)(0x44d), (u8)R.ax);                              // 0d15 mov byte ptr [0x44d], al
  SETH(R.ax, M8(DS, (u16)(R.di + 0xfff8)));                    // 0d18 mov ah, byte ptr [di - 8]
  W8(DS, (u16)(0x448), (u8)(R.ax >> 8));                       // 0d1b mov byte ptr [0x448], ah
  SETL(R.ax, M8(DS, (u16)(R.di + 0xfff9)));                    // 0d1f mov al, byte ptr [di - 7]
  SETL(R.ax, SUB8((u8)R.ax, (u8)(R.ax >> 8)));                 // 0d22 sub al, ah
  SETH(R.ax, XOR8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0d24 xor ah, ah
  SETL(R.cx, M8(DS, (u16)(R.di + 0xfffa)));                    // 0d26 mov cl, byte ptr [di - 6]
  SETL(R.cx, DEC8((u8)R.cx));                                  // 0d29 dec cl
  W8(DS, (u16)(0x44c), (u8)R.cx);                              // 0d2b mov byte ptr [0x44c], cl
  R.di = (u16)(ADD16(R.di, 0xfff7));                           // 0d2f add di, -9
  R.di = (u16)(SUB16(R.di, R.ax));                             // 0d32 sub di, ax
  W16(DS, (u16)(0x446), R.di);                                 // 0d34 mov word ptr [0x446], di
  R.ax = (u16)(INC16(R.ax));                                   // 0d38 inc ax
  R.ax = (u16)(SHL16(R.ax, (u8)R.cx));                         // 0d39 shl ax, cl
  W16(DS, (u16)(0x455), R.ax);                                 // 0d3b mov word ptr [0x455], ax
  ip_ = R.si; goto dispatch_;                                  // 0d3e jmp si
L_0d40:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x19bd) return; goto dispatch_; // 0d40 retf
}

// the driver's slots: slot 0 + k runs the k-th entry, with the caller's far return address on the stack
void mg_slot(int slot)
{
  static const u16 entries[] = { 0x0282, 0x0268, 0x074c, 0x0092, 0x0132, 0x0b0e, 0x04cf, 0x07b2, 0x0612, 0x02a4, 0x0408, 0x0b5f, 0x0d40, 0x0abe, 0x0238, 0x0112, 0x05e6, 0x01b6, 0x04ec, 0x0b88, 0x07a3, 0x02f0, 0x030a, 0x0272, 0x00e6, 0x01b4, 0x0955, 0x03de, 0x0887, 0x0699, 0x06b6, 0x0633, 0x04a3, 0x02bd, 0x0324, 0x01e4, 0x01b5, 0x01ae, 0x035c, 0x0ba2, 0x0bb1, 0x0c8a, 0x0bf3, 0x0c44, 0x025a, 0x0243, 0x055c, 0x095f };
  if (slot >= 0 && slot < 48) mg_0000_run(entries[slot - 0]);
}
