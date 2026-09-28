#include "asm2c.h"

// IS: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void is_0000_run(u16 entry);

void is_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0xd000;
dispatch_:
  switch (ip_)
  {
  case 0x0099: goto L_0099;
  case 0x00a2: goto L_00a2;
  case 0x00a9: goto L_00a9;
  case 0x00ac: goto L_00ac;
  case 0x00af: goto L_00af;
  case 0x00cb: goto L_00cb;
  case 0x00cf: goto L_00cf;
  case 0x00d1: goto L_00d1;
  case 0x00da: goto L_00da;
  case 0x00e7: goto L_00e7;
  case 0x00e8: goto L_00e8;
  case 0x00f1: goto L_00f1;
  case 0x00f3: goto L_00f3;
  case 0x00f6: goto L_00f6;
  case 0x00f9: goto L_00f9;
  case 0x00fc: goto L_00fc;
  case 0x00fe: goto L_00fe;
  case 0x0115: goto L_0115;
  case 0x011d: goto L_011d;
  case 0x0123: goto L_0123;
  case 0x0128: goto L_0128;
  case 0x0135: goto L_0135;
  case 0x0138: goto L_0138;
  case 0x013a: goto L_013a;
  case 0x0163: goto L_0163;
  case 0x0165: goto L_0165;
  case 0x016a: goto L_016a;
  case 0x0183: goto L_0183;
  case 0x0191: goto L_0191;
  case 0x0198: goto L_0198;
  case 0x01b7: goto L_01b7;
  case 0x01b9: goto L_01b9;
  case 0x01d3: goto L_01d3;
  case 0x01da: goto L_01da;
  case 0x01ff: goto L_01ff;
  case 0x0200: goto L_0200;
  case 0x020b: goto L_020b;
  case 0x0212: goto L_0212;
  case 0x021c: goto L_021c;
  case 0x0223: goto L_0223;
  case 0x022a: goto L_022a;
  case 0x023e: goto L_023e;
  case 0x0245: goto L_0245;
  case 0x024c: goto L_024c;
  case 0x0253: goto L_0253;
  case 0x025a: goto L_025a;
  case 0x0261: goto L_0261;
  case 0x026b: goto L_026b;
  case 0x0272: goto L_0272;
  case 0x0279: goto L_0279;
  case 0x027d: goto L_027d;
  case 0x0280: goto L_0280;
  case 0x028d: goto L_028d;
  case 0x0294: goto L_0294;
  case 0x0298: goto L_0298;
  case 0x029b: goto L_029b;
  case 0x02a8: goto L_02a8;
  case 0x02af: goto L_02af;
  case 0x02b6: goto L_02b6;
  case 0x02bd: goto L_02bd;
  case 0x02c4: goto L_02c4;
  case 0x02c8: goto L_02c8;
  case 0x02cb: goto L_02cb;
  case 0x02d8: goto L_02d8;
  case 0x02df: goto L_02df;
  case 0x02e2: goto L_02e2;
  case 0x030c: goto L_030c;
  case 0x030d: goto L_030d;
  case 0x0320: goto L_0320;
  case 0x0333: goto L_0333;
  case 0x0346: goto L_0346;
  case 0x0359: goto L_0359;
  case 0x036c: goto L_036c;
  case 0x037f: goto L_037f;
  case 0x0392: goto L_0392;
  case 0x0398: goto L_0398;
  case 0x039e: goto L_039e;
  case 0x03a2: goto L_03a2;
  case 0x03a4: goto L_03a4;
  case 0x03b4: goto L_03b4;
  case 0x03e1: goto L_03e1;
  case 0x03f2: goto L_03f2;
  case 0x03f3: goto L_03f3;
  case 0x0416: goto L_0416;
  case 0x0419: goto L_0419;
  case 0x0448: goto L_0448;
  case 0x044f: goto L_044f;
  case 0x0452: goto L_0452;
  case 0x045a: goto L_045a;
  case 0x0461: goto L_0461;
  case 0x04a0: goto L_04a0;
  case 0x04a2: goto L_04a2;
  case 0x04a8: goto L_04a8;
  case 0x04eb: goto L_04eb;
  case 0x04fb: goto L_04fb;
  case 0x04fe: goto L_04fe;
  case 0x0503: goto L_0503;
  case 0x0507: goto L_0507;
  case 0x051c: goto L_051c;
  case 0x0530: goto L_0530;
  default: asm_unknown_call(0xd000, ip_); return;
  }
L_0099:   PUSH(R.ds);                                                  // 0099 push ds
  R.ax = (u16)(0xd054 /* segment */);                          // 009a mov ax, 0x54
  R.ds = (u16)(R.ax);                                          // 009d mov ds, ax
  PUSH(0x00a2); goto L_00f3;                                   // 009f call 0xf3
L_00a2:   W8(DS, (u16)(0xacd), 0x0);                                   // 00a2 mov byte ptr [0xacd], 0
  R.ds = POP();                                                // 00a7 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00a8 retf
L_00a9:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 00a9 xor ax, ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00ab retf
L_00ac:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00ac retf
L_00af:   PUSH(R.bp);                                                  // 00af push bp
  R.bp = (u16)(R.sp);                                          // 00b0 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 00b2 mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x56);                                           // 00b5 cmp bx, 0x56
  if (!R.zf && R.sf == R.of) goto L_00cf;                      // 00b8 jg 0xcf
  PUSH(R.ds);                                                  // 00ba push ds
  R.ax = (u16)(0xd054 /* segment */);                          // 00bb mov ax, 0x54
  R.ds = (u16)(R.ax);                                          // 00be mov ds, ax
  W16(DS, (u16)(0xac7), 0x0);                                  // 00c0 mov word ptr [0xac7], 0
  { u16 t_ = M16(CS, (u16)(R.bx + 0x41)); PUSH(0x00cb); ip_ = t_; goto dispatch_; } // 00c6 call word ptr cs:[bx + 0x41]
L_00cb:   R.ax = (u16)(M16(DS, (u16)(0xac7)));                         // 00cb mov ax, word ptr [0xac7]
  R.ds = POP();                                                // 00ce pop ds
L_00cf:   R.bp = POP();                                                // 00cf pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00d0 retf
L_00d1:   PUSH(R.ds);                                                  // 00d1 push ds
  R.ax = (u16)(0xd054 /* segment */);                          // 00d2 mov ax, 0x54
  R.ds = (u16)(R.ax);                                          // 00d5 mov ds, ax
  PUSH(0x00da); goto L_0198;                                   // 00d7 call 0x198
L_00da:   R.ax = (u16)(M16(DS, (u16)(0xac1)));                         // 00da mov ax, word ptr [0xac1]
  W16(DS, (u16)(0xac1), 0x0);                                  // 00dd mov word ptr [0xac1], 0
  R.ds = POP();                                                // 00e3 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00e4 retf
L_00e7:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00e7 retf
L_00e8:   PUSH(R.ds);                                                  // 00e8 push ds
  R.ax = (u16)(0xd054 /* segment */);                          // 00e9 mov ax, 0x54
  R.ds = (u16)(R.ax);                                          // 00ec mov ds, ax
  PUSH(0x00f1); goto L_01da;                                   // 00ee call 0x1da
L_00f1:   R.ds = POP();                                                // 00f1 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00f2 retf
L_00f3:   PUSH(0x00f6); goto L_0165;                                   // 00f3 call 0x165
L_00f6:   PUSH(0x00f9); goto L_013a;                                   // 00f6 call 0x13a
L_00f9:   PUSH(0x00fc); goto L_00fe;                                   // 00f9 call 0xfe
L_00fc:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 00fc ret
L_00fe:   SUB8(M8(CS, (u16)(0xfd)), 0x7b);                             // 00fe cmp byte ptr cs:[0xfd], 0x7b
  if (R.zf) goto L_0138;                                       // 0104 je 0x138
  W8(CS, (u16)(0xfd), 0x7b);                                   // 0106 mov byte ptr cs:[0xfd], 0x7b
  R.bx = (u16)(0x194);                                         // 010c mov bx, 0x194
  SETL(R.ax, 0x7e);                                            // 010f mov al, 0x7e
  // 0111 nop 
  PUSH(0x0115); goto L_03f3;                                   // 0112 call 0x3f3
L_0115:   R.dx = (u16)(0x43);                                          // 0115 mov dx, 0x43
  SETL(R.ax, 0x80);                                            // 0118 mov al, 0x80
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 011a out dx, al
  goto L_011d;                                                 // 011b jmp 0x11d
L_011d:   SETL(R.ax, ASM_PORT_IN(0x42));                               // 011d in al, 0x42
  SETH(R.ax, (u8)R.ax);                                        // 011f mov ah, al
  goto L_0123;                                                 // 0121 jmp 0x123
L_0123:   SETL(R.ax, 0x80);                                            // 0123 mov al, 0x80
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 0125 out dx, al
  goto L_0128;                                                 // 0126 jmp 0x128
L_0128:   SETL(R.ax, ASM_PORT_IN(0x42));                               // 0128 in al, 0x42
  SUB8((u8)(R.ax >> 8), (u8)R.ax);                             // 012a cmp ah, al
  if (!R.zf) goto L_0135;                                      // 012c jne 0x135
  R.ax = (u16)(0x9090);                                        // 012e mov ax, 0x9090
  W16(CS, (u16)(0x4a4), R.ax);                                 // 0131 mov word ptr cs:[0x4a4], ax
L_0135:   PUSH(0x0138); goto L_0419;                                   // 0135 call 0x419
L_0138:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0138 ret
L_013a:   SUB8(M8(CS, (u16)(0x139)), 0x7b);                            // 013a cmp byte ptr cs:[0x139], 0x7b
  if (R.zf) goto L_0138;                                       // 0140 je 0x138
  W8(CS, (u16)(0x139), 0x7b);                                  // 0142 mov byte ptr cs:[0x139], 0x7b
  PUSH(R.es);                                                  // 0148 push es
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0149 xor ax, ax
  R.es = (u16)(R.ax);                                          // 014b mov es, ax
  R.es = (u16)(M16(ES, (u16)(0x4f0)));                         // 014d mov es, word ptr es:[0x4f0]
  SUB16(M16(ES, (u16)(0x34)), 0x1);                            // 0152 cmp word ptr es:[0x34], 1
  if (R.zf) goto L_0163;                                       // 0158 je 0x163
  R.bx = (u16)((u16)(0x478));                                  // 015a lea bx, [0x478]
  W16(CS, (u16)(R.bx), 0x6eb);                                 // 015e mov word ptr cs:[bx], 0x6eb
L_0163:   R.es = POP();                                                // 0163 pop es
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0164 ret
L_0165:   W8(DS, (u16)(0xac0), 0x0);                                   // 0165 mov byte ptr [0xac0], 0
L_016a:   R.bx = (u16)(XOR16(R.bx, R.bx));                             // 016a xor bx, bx
  W16(DS, (u16)(0xab8), R.bx);                                 // 016c mov word ptr [0xab8], bx
  W16(DS, (u16)(0xab0), R.bx);                                 // 0170 mov word ptr [0xab0], bx
  W16(DS, (u16)(0xab2), R.bx);                                 // 0174 mov word ptr [0xab2], bx
  R.bx = (u16)((u16)(0xaae));                                  // 0178 lea bx, [0xaae]
  W16(DS, (u16)(0xab6), R.bx);                                 // 017c mov word ptr [0xab6], bx
  goto L_0191;                                                 // 0180 jmp 0x191
L_0183:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0183 xor ax, ax
  W16(DS, (u16)(0xab8), R.ax);                                 // 0185 mov word ptr [0xab8], ax
  W16(DS, (u16)(0xab0), R.ax);                                 // 0188 mov word ptr [0xab0], ax
  W16(DS, (u16)(0xab4), R.ax);                                 // 018b mov word ptr [0xab4], ax
  PUSH(0x0191); goto L_051c;                                   // 018e call 0x51c
L_0191:   SETL(R.ax, ASM_PORT_IN(0x61));                               // 0191 in al, 0x61
  SETL(R.ax, AND8((u8)R.ax, 0xfc));                            // 0193 and al, 0xfc
  ASM_PORT_OUT(0x61, (u8)R.ax);                                // 0195 out 0x61, al
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0197 ret
L_0198:   W16(CS, (u16)(0xe5), INC16(M16(CS, (u16)(0xe5))));           // 0198 inc word ptr cs:[0xe5]
  SUB16(M16(DS, (u16)(0xab8)), 0x0);                           // 019d cmp word ptr [0xab8], 0
  if (!R.zf) goto L_01b9;                                      // 01a2 jne 0x1b9
  SUB16(M16(DS, (u16)(0xab2)), 0x0);                           // 01a4 cmp word ptr [0xab2], 0
  if (!R.zf) goto L_0200;                                      // 01a9 jne 0x200
  R.bx = (u16)(M16(DS, (u16)(0xab6)));                         // 01ab mov bx, word ptr [0xab6]
  SUB16(M16(DS, (u16)(R.bx)), 0x0);                            // 01af cmp word ptr [bx], 0
  if (R.zf) goto L_0183;                                       // 01b2 je 0x183
  PUSH(0x01b7); goto L_03b4;                                   // 01b4 call 0x3b4
L_01b7:   goto L_01d3;                                                 // 01b7 jmp 0x1d3
L_01b9:   W16(DS, (u16)(0xab8), DEC16(M16(DS, (u16)(0xab8))));         // 01b9 dec word ptr [0xab8]
  SUB16(M16(DS, (u16)(0xab8)), 0x1);                           // 01bd cmp word ptr [0xab8], 1
  if (!R.zf) goto L_01d3;                                      // 01c2 jne 0x1d3
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 01c4 xor ax, ax
  W16(DS, (u16)(0xabe), R.ax);                                 // 01c6 mov word ptr [0xabe], ax
  W16(DS, (u16)(0xacb), R.ax);                                 // 01c9 mov word ptr [0xacb], ax
  R.ax = (u16)(DEC16(R.ax));                                   // 01cc dec ax
  W16(DS, (u16)(0xaba), R.ax);                                 // 01cd mov word ptr [0xaba], ax
  W16(DS, (u16)(0xabc), R.ax);                                 // 01d0 mov word ptr [0xabc], ax
L_01d3:   R.ax = (u16)(M16(DS, (u16)(0xabe)));                         // 01d3 mov ax, word ptr [0xabe]
  W16(DS, (u16)(0xaba), ADD16(M16(DS, (u16)(0xaba)), R.ax));   // 01d6 add word ptr [0xaba], ax
L_01da:   SUB16(M16(DS, (u16)(0xab8)), 0x0);                           // 01da cmp word ptr [0xab8], 0
  if (R.zf) goto L_01ff;                                       // 01df je 0x1ff
  R.ax = (u16)(0x9248);                                        // 01e1 mov ax, 0x9248
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0xacb))));            // 01e4 add ax, word ptr [0xacb]
  R.ax = (u16)(ROR16(R.ax, 0x1));                              // 01e8 ror ax, 1
  R.ax = (u16)(ROR16(R.ax, 0x1));                              // 01ea ror ax, 1
  R.ax = (u16)(ROR16(R.ax, 0x1));                              // 01ec ror ax, 1
  W16(DS, (u16)(0xacb), R.ax);                                 // 01ee mov word ptr [0xacb], ax
  R.ax = (u16)(AND16(R.ax, M16(DS, (u16)(0xabc))));            // 01f1 and ax, word ptr [0xabc]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(0xaba))));            // 01f5 add ax, word ptr [0xaba]
  ASM_PORT_OUT(0x42, (u8)R.ax);                                // 01f9 out 0x42, al
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 01fb mov al, ah
  ASM_PORT_OUT(0x42, (u8)R.ax);                                // 01fd out 0x42, al
L_01ff:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 01ff ret
L_0200:   W16(DS, (u16)(0xab2), DEC16(M16(DS, (u16)(0xab2))));         // 0200 dec word ptr [0xab2]
  R.bx = (u16)(M16(DS, (u16)(0xab4)));                         // 0204 mov bx, word ptr [0xab4]
  goto L_03b4;                                                 // 0208 jmp 0x3b4
L_020b:   R.bx = (u16)((u16)(0xe8));                                   // 020b lea bx, [0xe8]
  goto L_03a2;                                                 // 020f jmp 0x3a2
L_0212:   R.bx = (u16)((u16)(0x72));                                   // 0212 lea bx, [0x72]
  R.ax = (u16)(0x5);                                           // 0216 mov ax, 5
  goto L_03a4;                                                 // 0219 jmp 0x3a4
L_021c:   R.bx = (u16)((u16)(0xc4));                                   // 021c lea bx, [0xc4]
  goto L_03a2;                                                 // 0220 jmp 0x3a2
L_0223:   R.bx = (u16)((u16)(0x5c));                                   // 0223 lea bx, [0x5c]
  goto L_03a2;                                                 // 0227 jmp 0x3a2
L_022a:   R.ax = (u16)(M16(CS, (u16)(0xe5)));                          // 022a mov ax, word ptr cs:[0xe5]
  R.ax = (u16)(ADD16(R.ax, 0x9245));                           // 022e add ax, 0x9245
  SETL(R.ax, XOR8((u8)R.ax, (u8)(R.ax >> 8)));                 // 0231 xor al, ah
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0233 cwde
  W16(DS, (u16)(0xd8), R.ax);                                  // 0234 mov word ptr [0xd8], ax
  R.bx = (u16)((u16)(0xd0));                                   // 0237 lea bx, [0xd0]
  goto L_03a2;                                                 // 023b jmp 0x3a2
L_023e:   R.bx = (u16)((u16)(0xac));                                   // 023e lea bx, [0xac]
  goto L_03a2;                                                 // 0242 jmp 0x3a2
L_0245:   R.bx = (u16)((u16)(0xa0));                                   // 0245 lea bx, [0xa0]
  goto L_03a2;                                                 // 0249 jmp 0x3a2
L_024c:   R.bx = (u16)((u16)(0x88));                                   // 024c lea bx, [0x88]
  goto L_03a2;                                                 // 0250 jmp 0x3a2
L_0253:   R.bx = (u16)((u16)(0x94));                                   // 0253 lea bx, [0x94]
  goto L_03a2;                                                 // 0257 jmp 0x3a2
L_025a:   R.bx = (u16)((u16)(0xdc));                                   // 025a lea bx, [0xdc]
  goto L_03a2;                                                 // 025e jmp 0x3a2
L_0261:   R.bx = (u16)((u16)(0x50));                                   // 0261 lea bx, [0x50]
  R.ax = (u16)(0x2);                                           // 0265 mov ax, 2
  goto L_03a4;                                                 // 0268 jmp 0x3a4
L_026b:   R.bx = (u16)((u16)(0x8f6));                                  // 026b lea bx, [0x8f6]
  goto L_04eb;                                                 // 026f jmp 0x4eb
L_0272:   R.bx = (u16)((u16)(0x308));                                  // 0272 lea bx, [0x308]
  goto L_04eb;                                                 // 0276 jmp 0x4eb
L_0279:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0279 xor ax, ax
  goto L_0280;                                                 // 027b jmp 0x280
L_027d:   R.ax = (u16)(0x29);                                          // 027d mov ax, 0x29
L_0280:   R.bx = (u16)((u16)(0xa78));                                  // 0280 lea bx, [0xa78]
  W16(DS, (u16)(R.bx), R.ax);                                  // 0284 mov word ptr [bx], ax
  R.bx = (u16)((u16)(0xa60));                                  // 0286 lea bx, [0xa60]
  goto L_04eb;                                                 // 028a jmp 0x4eb
L_028d:   R.bx = (u16)((u16)(0x8a0));                                  // 028d lea bx, [0x8a0]
  goto L_04eb;                                                 // 0291 jmp 0x4eb
L_0294:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0294 xor ax, ax
  goto L_029b;                                                 // 0296 jmp 0x29b
L_0298:   R.ax = (u16)(0x21);                                          // 0298 mov ax, 0x21
L_029b:   R.bx = (u16)((u16)(0x160));                                  // 029b lea bx, [0x160]
  W16(DS, (u16)(R.bx), R.ax);                                  // 029f mov word ptr [bx], ax
  R.bx = (u16)((u16)(0x10c));                                  // 02a1 lea bx, [0x10c]
  goto L_04eb;                                                 // 02a5 jmp 0x4eb
L_02a8:   R.bx = (u16)((u16)(0x2c4));                                  // 02a8 lea bx, [0x2c4]
  goto L_04eb;                                                 // 02ac jmp 0x4eb
L_02af:   R.bx = (u16)((u16)(0x83a));                                  // 02af lea bx, [0x83a]
  goto L_04eb;                                                 // 02b3 jmp 0x4eb
L_02b6:   R.bx = (u16)((u16)(0x52a));                                  // 02b6 lea bx, [0x52a]
  goto L_04eb;                                                 // 02ba jmp 0x4eb
L_02bd:   R.bx = (u16)((u16)(0x4ec));                                  // 02bd lea bx, [0x4ec]
  goto L_04eb;                                                 // 02c1 jmp 0x4eb
L_02c4:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 02c4 xor ax, ax
  goto L_02cb;                                                 // 02c6 jmp 0x2cb
L_02c8:   R.ax = (u16)(0x8);                                           // 02c8 mov ax, 8
L_02cb:   R.bx = (u16)((u16)(0x72a));                                  // 02cb lea bx, [0x72a]
  W16(DS, (u16)(R.bx), R.ax);                                  // 02cf mov word ptr [bx], ax
  R.bx = (u16)((u16)(0x68e));                                  // 02d1 lea bx, [0x68e]
  goto L_04eb;                                                 // 02d5 jmp 0x4eb
L_02d8:   R.bx = (u16)((u16)(0xb8));                                   // 02d8 lea bx, [0xb8]
  PUSH(0x02df); goto L_02e2;                                   // 02dc call 0x2e2
L_02df:   goto L_03a2;                                                 // 02df jmp 0x3a2
L_02e2:   R.ax = (u16)(0x9249);                                        // 02e2 mov ax, 0x9249
  R.ax = (u16)(ADD16(R.ax, M16(CS, (u16)(0xe5))));             // 02e5 add ax, word ptr cs:[0xe5]
  R.ax = (u16)(ROR16(R.ax, 0x1));                              // 02ea ror ax, 1
  R.ax = (u16)(ROR16(R.ax, 0x1));                              // 02ec ror ax, 1
  R.ax = (u16)(ROR16(R.ax, 0x1));                              // 02ee ror ax, 1
  PUSH(R.ax);                                                  // 02f0 push ax
  SETL(R.ax, AND8((u8)R.ax, 0xf));                             // 02f1 and al, 0xf
  W8(DS, (u16)(R.bx + 0x2), XOR8(M8(DS, (u16)(R.bx + 0x2)), (u8)R.ax)); // 02f3 xor byte ptr [bx + 2], al
  R.ax = POP();                                                // 02f6 pop ax
  R.ax = (u16)(AND16(R.ax, 0x7f3f));                           // 02f7 and ax, 0x7f3f
  W8(DS, (u16)(R.bx + 0x4), (u8)R.ax);                         // 02fa mov byte ptr [bx + 4], al
  SETH(R.ax, OR8((u8)(R.ax >> 8), 0x7));                       // 02fd or ah, 7
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0300 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0302 shr ax, 1
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0304 shr ax, 1
  SETH(R.ax, OR8((u8)(R.ax >> 8), 0x7));                       // 0306 or ah, 7
  W16(DS, (u16)(R.bx + 0x6), R.ax);                            // 0309 mov word ptr [bx + 6], ax
L_030c:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 030c ret
L_030d:   SETL(R.bx, 0xc);                                             // 030d mov bl, 0xc
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 030f cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 0313 je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 0315 mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x372));                                  // 0319 lea bx, [0x372]
  goto L_04eb;                                                 // 031d jmp 0x4eb
L_0320:   SETL(R.bx, 0x7b);                                            // 0320 mov bl, 0x7b
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 0322 cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 0326 je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 0328 mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x352));                                  // 032c lea bx, [0x352]
  goto L_04eb;                                                 // 0330 jmp 0x4eb
L_0333:   SETL(R.bx, 0xc9);                                            // 0333 mov bl, 0xc9
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 0335 cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 0339 je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 033b mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x4a8));                                  // 033f lea bx, [0x4a8]
  goto L_04eb;                                                 // 0343 jmp 0x4eb
L_0346:   SETL(R.bx, 0x99);                                            // 0346 mov bl, 0x99
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 0348 cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 034c je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 034e mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x458));                                  // 0352 lea bx, [0x458]
  goto L_04eb;                                                 // 0356 jmp 0x4eb
L_0359:   SETL(R.bx, 0x45);                                            // 0359 mov bl, 0x45
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 035b cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 035f je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 0361 mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x426));                                  // 0365 lea bx, [0x426]
  goto L_04eb;                                                 // 0369 jmp 0x4eb
L_036c:   SETL(R.bx, 0x4);                                             // 036c mov bl, 4
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 036e cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 0372 je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 0374 mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x3dc));                                  // 0378 lea bx, [0x3dc]
  goto L_04eb;                                                 // 037c jmp 0x4eb
L_037f:   SETL(R.bx, 0xe0);                                            // 037f mov bl, 0xe0
  SUB8((u8)R.bx, M8(DS, (u16)(0xac0)));                        // 0381 cmp bl, byte ptr [0xac0]
  if (R.zf) goto L_030c;                                       // 0385 je 0x30c
  W8(DS, (u16)(0xac0), (u8)R.bx);                              // 0387 mov byte ptr [0xac0], bl
  R.bx = (u16)((u16)(0x392));                                  // 038b lea bx, [0x392]
  goto L_04eb;                                                 // 038f jmp 0x4eb
L_0392:   R.bx = (u16)((u16)(0x100));                                  // 0392 lea bx, [0x100]
  goto L_03a2;                                                 // 0396 jmp 0x3a2
L_0398:   R.bx = (u16)((u16)(0x7c));                                   // 0398 lea bx, [0x7c]
  goto L_03a2;                                                 // 039c jmp 0x3a2
L_039e:   R.bx = (u16)((u16)(0xf4));                                   // 039e lea bx, [0xf4]
L_03a2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 03a2 xor ax, ax
L_03a4:   PUSH(R.ax);                                                  // 03a4 push ax
  R.ax = (u16)(M16(DS, (u16)(0xab0)));                         // 03a5 mov ax, word ptr [0xab0]
  SUB8((u8)R.ax, M8(DS, (u16)(R.bx)));                         // 03a8 cmp al, byte ptr [bx]
  R.ax = POP();                                                // 03aa pop ax
  if (!R.cf) goto L_03f2;                                      // 03ab jae 0x3f2
  W16(DS, (u16)(0xab2), R.ax);                                 // 03ad mov word ptr [0xab2], ax
  W16(DS, (u16)(0xab4), R.bx);                                 // 03b0 mov word ptr [0xab4], bx
L_03b4:   W16(DS, (u16)(0xacb), 0x0);                                  // 03b4 mov word ptr [0xacb], 0
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 03ba mov ax, word ptr [bx]
  W16(DS, (u16)(0xab0), R.ax);                                 // 03bc mov word ptr [0xab0], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 03bf mov ax, word ptr [bx + 2]
  W16(DS, (u16)(0xab8), R.ax);                                 // 03c2 mov word ptr [0xab8], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 03c5 mov ax, word ptr [bx + 4]
  W16(DS, (u16)(0xabc), R.ax);                                 // 03c8 mov word ptr [0xabc], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x6)));                    // 03cb mov ax, word ptr [bx + 6]
  W16(DS, (u16)(0xaba), R.ax);                                 // 03ce mov word ptr [0xaba], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x8)));                    // 03d1 mov ax, word ptr [bx + 8]
  W16(DS, (u16)(0xabe), R.ax);                                 // 03d4 mov word ptr [0xabe], ax
  R.bx = (u16)(ADD16(R.bx, 0xa));                              // 03d7 add bx, 0xa
  W16(DS, (u16)(0xab6), R.bx);                                 // 03da mov word ptr [0xab6], bx
  PUSH(0x03e1); goto L_0507;                                   // 03de call 0x507
L_03e1:   SUB8(M8(DS, (u16)(0xacd)), 0xff);                            // 03e1 cmp byte ptr [0xacd], 0xff
  if (R.zf) goto L_03f2;                                       // 03e6 je 0x3f2
  SETL(R.ax, 0xb6);                                            // 03e8 mov al, 0xb6
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 03ea out 0x43, al
  SETL(R.ax, ASM_PORT_IN(0x61));                               // 03ec in al, 0x61
  SETL(R.ax, OR8((u8)R.ax, 0x3));                              // 03ee or al, 3
  ASM_PORT_OUT(0x61, (u8)R.ax);                                // 03f0 out 0x61, al
L_03f2:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 03f2 ret
L_03f3:   PUSH(R.ax);                                                  // 03f3 push ax
  SETL(R.ax, ASM_PORT_IN(0x61));                               // 03f4 in al, 0x61
  W8(DS, (u16)(0xac4), (u8)R.ax);                              // 03f6 mov byte ptr [0xac4], al
  SETL(R.ax, (u8)R.bx);                                        // 03f9 mov al, bl
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 03fb out 0x43, al
  SETL(R.ax, ASM_PORT_IN(0x61));                               // 03fd in al, 0x61
  SETL(R.ax, OR8((u8)R.ax, (u8)(R.bx >> 8)));                  // 03ff or al, bh
  ASM_PORT_OUT(0x61, (u8)R.ax);                                // 0401 out 0x61, al
  // 0403 cli 
  SETL(R.ax, ASM_PORT_IN(0x21));                               // 0404 in al, 0x21
  W8(DS, (u16)(0xac3), (u8)R.ax);                              // 0406 mov byte ptr [0xac3], al
  SETL(R.ax, OR8((u8)R.ax, 0x1));                              // 0409 or al, 1
  ASM_PORT_OUT(0x21, (u8)R.ax);                                // 040b out 0x21, al
  // 040d sti 
  SETL(R.ax, 0x14);                                            // 040e mov al, 0x14
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 0410 out 0x43, al
  R.ax = POP();                                                // 0412 pop ax
  ASM_PORT_OUT(0x40, (u8)R.ax);                                // 0413 out 0x40, al
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0415 ret
L_0416:   R.ax = (u16)(0x1);                                           // 0416 mov ax, 1
L_0419:   W16(DS, (u16)(0xac7), R.ax);                                 // 0419 mov word ptr [0xac7], ax
  W8(CS, (u16)(0x40), 0xff);                                   // 041c mov byte ptr cs:[0x40], 0xff
  SETL(R.ax, 0x36);                                            // 0422 mov al, 0x36
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 0424 out 0x43, al
  R.ax = (u16)(0x4c90);                                        // 0426 mov ax, 0x4c90
  ASM_PORT_OUT(0x40, (u8)R.ax);                                // 0429 out 0x40, al
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 042b mov al, ah
  ASM_PORT_OUT(0x40, (u8)R.ax);                                // 042d out 0x40, al
  // 042f cli 
  SETL(R.ax, M8(DS, (u16)(0xac3)));                            // 0430 mov al, byte ptr [0xac3]
  ASM_PORT_OUT(0x21, (u8)R.ax);                                // 0433 out 0x21, al
  SETL(R.ax, M8(DS, (u16)(0xac4)));                            // 0435 mov al, byte ptr [0xac4]
  ASM_PORT_OUT(0x61, (u8)R.ax);                                // 0438 out 0x61, al
  SETL(R.ax, 0xb6);                                            // 043a mov al, 0xb6
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 043c out 0x43, al
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 043e xor ax, ax
  ASM_PORT_OUT(0x42, (u8)R.ax);                                // 0440 out 0x42, al
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 0442 mov al, ah
  ASM_PORT_OUT(0x42, (u8)R.ax);                                // 0444 out 0x42, al
  // 0446 sti 
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0447 ret
L_0448:   W16(DS, (u16)(0xac9), R.bx);                                 // 0448 mov word ptr [0xac9], bx
  PUSH(0x044f); goto L_051c;                                   // 044c call 0x51c
L_044f:   PUSH(0x0452); goto L_016a;                                   // 044f call 0x16a
L_0452:   R.bx = (u16)(0x2b4);                                         // 0452 mov bx, 0x2b4
  SETL(R.ax, 0x7e);                                            // 0455 mov al, 0x7e
  PUSH(0x045a); goto L_03f3;                                   // 0457 call 0x3f3
L_045a:   SETL(R.ax, M8(DS, (u16)(0xac4)));                            // 045a mov al, byte ptr [0xac4]
  W8(CS, (u16)(0x4e2), (u8)R.ax);                              // 045d mov byte ptr cs:[0x4e2], al
L_0461:   R.bx = (u16)(M16(DS, (u16)(0xac9)));                         // 0461 mov bx, word ptr [0xac9]
  R.si = (u16)(M16(DS, (u16)(R.bx)));                          // 0465 mov si, word ptr [bx]
  R.ax = (u16)(R.si);                                          // 0467 mov ax, si
  R.ax = (u16)(OR16(R.ax, R.ax));                              // 0469 or ax, ax
  if (R.zf) goto L_0419;                                       // 046b je 0x419
  R.ax = (u16)(M16(ES, (u16)(0x41a)));                         // 046d mov ax, word ptr es:[0x41a]
  SUB16(R.ax, M16(ES, (u16)(0x41c)));                          // 0471 cmp ax, word ptr es:[0x41c]
  if (!R.zf) goto L_0416;                                      // 0476 jne 0x416
  R.dx = (u16)(0x201);                                         // 0478 mov dx, 0x201
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 047b in al, dx
  AND8((u8)R.ax, 0x10);                                        // 047c test al, 0x10
  if (R.zf) goto L_0416;                                       // 047e je 0x416
  SETH(R.dx, M8(DS, (u16)(R.bx + 0x2)));                       // 0480 mov dh, byte ptr [bx + 2]
  R.cx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0483 mov cx, word ptr [bx + 4]
  W16(DS, (u16)(0xac9), ADD16(M16(DS, (u16)(0xac9)), 0x6));    // 0486 add word ptr [0xac9], 6
  SETH(R.bx, (u8)R.cx);                                        // 048b mov bh, cl
  SETL(R.dx, 0x2);                                             // 048d mov dl, 2
  SETL(R.cx, 0x1);                                             // 048f mov cl, 1
  SETL(R.bx, XOR8((u8)R.bx, (u8)R.bx));                        // 0491 xor bl, bl
  R.bp = (u16)(0x2ff);                                         // 0493 mov bp, 0x2ff
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)(R.bx >> 8)));           // 0496 or bh, bh
  if (!R.zf) goto L_04a0;                                      // 0498 jne 0x4a0
  R.bp = (u16)(XOR16(R.bp, 0x200));                            // 049a xor bp, 0x200
  SETH(R.bx, 0x64);                                            // 049e mov bh, 0x64
L_04a0:   SETH(R.ax, 0xff);                                            // 04a0 mov ah, 0xff
L_04a2:   SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 04a2 xor al, al
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 04a4 out 0x43, al
  goto L_04a8;                                                 // 04a6 jmp 0x4a8
L_04a8:   SETL(R.ax, ASM_PORT_IN(0x40));                               // 04a8 in al, 0x40
  SUB8((u8)(R.ax >> 8), (u8)R.ax);                             // 04aa cmp ah, al
  SETH(R.ax, (u8)R.ax);                                        // 04ac mov ah, al
  if (!R.cf) goto L_04a2;                                      // 04ae jae 0x4a2
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04b0 xor ax, ax
  SETL(R.dx, SUB8((u8)R.dx, 0x1));                             // 04b2 sub dl, 1
  R.ax = (u16)(RCL16(R.ax, 0x1));                              // 04b5 rcl ax, 1
  R.ax = (u16)(NEG16(R.ax));                                   // 04b7 neg ax
  SETL(R.ax, AND8((u8)R.ax, (u8)(R.dx >> 8)));                 // 04b9 and al, dh
  SETL(R.dx, ADD8((u8)R.dx, (u8)R.ax));                        // 04bb add dl, al
  R.di = (u16)(R.ax);                                          // 04bd mov di, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04bf xor ax, ax
  SETL(R.cx, SUB8((u8)R.cx, 0x1));                             // 04c1 sub cl, 1
  R.ax = (u16)(RCL16(R.ax, 0x1));                              // 04c4 rcl ax, 1
  R.ax = (u16)(NEG16(R.ax));                                   // 04c6 neg ax
  SETL(R.ax, AND8((u8)R.ax, (u8)(R.cx >> 8)));                 // 04c8 and al, ch
  SETL(R.cx, ADD8((u8)R.cx, (u8)R.ax));                        // 04ca add cl, al
  R.di = (u16)(OR16(R.di, R.ax));                              // 04cc or di, ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04ce xor ax, ax
  SETL(R.bx, SUB8((u8)R.bx, 0x1));                             // 04d0 sub bl, 1
  R.ax = (u16)(RCL16(R.ax, 0x1));                              // 04d3 rcl ax, 1
  R.si = (u16)(SUB16(R.si, R.ax));                             // 04d5 sub si, ax
  if (R.zf) goto L_0461;                                       // 04d7 je 0x461
  R.ax = (u16)(NEG16(R.ax));                                   // 04d9 neg ax
  SETL(R.ax, AND8((u8)R.ax, (u8)(R.bx >> 8)));                 // 04db and al, bh
  SETL(R.bx, ADD8((u8)R.bx, (u8)R.ax));                        // 04dd add bl, al
  R.ax = (u16)(OR16(R.ax, R.di));                              // 04df or ax, di
  SETL(R.ax, M8(CS, 0x04e2));  /* the immediate as 045D wrote it */ // 04e1 mov al, 0x7b
  R.ax = (u16)(AND16(R.ax, R.bp));                             // 04e3 and ax, bp
  SETL(R.ax, OR8((u8)R.ax, (u8)(R.ax >> 8)));                  // 04e5 or al, ah
  ASM_PORT_OUT(0x61, (u8)R.ax);                                // 04e7 out 0x61, al
  goto L_04a0;                                                 // 04e9 jmp 0x4a0
L_04eb:   PUSH(R.es);                                                  // 04eb push es
  PUSH(R.di);                                                  // 04ec push di
  PUSH(R.si);                                                  // 04ed push si
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04ee xor ax, ax
  R.es = (u16)(R.ax);                                          // 04f0 mov es, ax
  W8(ES, (u16)(0x440), 0x1);                                   // 04f2 mov byte ptr es:[0x440], 1
  R.cx = (u16)(0xea60);                                        // 04f8 mov cx, 0xea60
L_04fb:   PUSH(0x04fe); goto L_03f2;                                   // 04fb call 0x3f2
L_04fe:   if (--R.cx != 0) goto L_04fb;                                // 04fe loop 0x4fb
  PUSH(0x0503); goto L_0448;                                   // 0500 call 0x448
L_0503:   R.si = POP();                                                // 0503 pop si
  R.di = POP();                                                // 0504 pop di
  R.es = POP();                                                // 0505 pop es
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0506 ret
L_0507:   SUB8(M8(CS, (u16)(0x40)), 0x1);                              // 0507 cmp byte ptr cs:[0x40], 1
  if (R.zf) goto L_0530;                                       // 050d je 0x530
  W8(CS, (u16)(0x40), 0x1);                                    // 050f mov byte ptr cs:[0x40], 1
  W16(DS, (u16)(0xac1), 0x1);                                  // 0515 mov word ptr [0xac1], 1
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 051b ret
L_051c:   SUB8(M8(CS, (u16)(0x40)), 0xff);                             // 051c cmp byte ptr cs:[0x40], 0xff
  if (R.zf) goto L_0530;                                       // 0522 je 0x530
  W8(CS, (u16)(0x40), 0xff);                                   // 0524 mov byte ptr cs:[0x40], 0xff
  W16(DS, (u16)(0xac1), 0xffff);                               // 052a mov word ptr [0xac1], 0xffff
L_0530:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0530 ret
}

// the driver's slots: slot 0 + k runs the k-th entry, with the caller's far return address on the stack
void is_slot(int slot)
{
  static const u16 entries[] = { 0x0099, 0x00af, 0x00d1, 0x00e8, 0x00e7, 0x00a9, 0x00ac };
  if (slot >= 0 && slot < 7) is_0000_run(entries[slot - 0]);
}
