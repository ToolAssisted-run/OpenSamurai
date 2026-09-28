#include "asm2c.h"

// TS: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void ts_0000_run(u16 entry);

void ts_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0xd000;
dispatch_:
  switch (ip_)
  {
  case 0x0098: goto L_0098;
  case 0x00a1: goto L_00a1;
  case 0x00b5: goto L_00b5;
  case 0x00c1: goto L_00c1;
  case 0x00c3: goto L_00c3;
  case 0x00c4: goto L_00c4;
  case 0x00db: goto L_00db;
  case 0x00df: goto L_00df;
  case 0x00e0: goto L_00e0;
  case 0x00e3: goto L_00e3;
  case 0x00ef: goto L_00ef;
  case 0x00f6: goto L_00f6;
  case 0x010e: goto L_010e;
  case 0x0111: goto L_0111;
  case 0x0118: goto L_0118;
  case 0x011c: goto L_011c;
  case 0x0121: goto L_0121;
  case 0x0122: goto L_0122;
  case 0x0135: goto L_0135;
  case 0x013c: goto L_013c;
  case 0x0143: goto L_0143;
  case 0x0147: goto L_0147;
  case 0x0155: goto L_0155;
  case 0x018b: goto L_018b;
  case 0x01a8: goto L_01a8;
  case 0x01d9: goto L_01d9;
  case 0x0213: goto L_0213;
  case 0x0215: goto L_0215;
  case 0x0216: goto L_0216;
  case 0x0222: goto L_0222;
  case 0x022d: goto L_022d;
  case 0x0235: goto L_0235;
  case 0x0238: goto L_0238;
  case 0x0265: goto L_0265;
  case 0x0266: goto L_0266;
  case 0x0267: goto L_0267;
  case 0x027e: goto L_027e;
  case 0x029a: goto L_029a;
  case 0x02ae: goto L_02ae;
  case 0x02c0: goto L_02c0;
  case 0x02c8: goto L_02c8;
  case 0x02cf: goto L_02cf;
  case 0x02d7: goto L_02d7;
  case 0x02e9: goto L_02e9;
  case 0x02ef: goto L_02ef;
  case 0x02f6: goto L_02f6;
  case 0x02fc: goto L_02fc;
  case 0x0308: goto L_0308;
  case 0x0314: goto L_0314;
  case 0x0326: goto L_0326;
  case 0x0335: goto L_0335;
  case 0x0344: goto L_0344;
  case 0x0354: goto L_0354;
  case 0x035d: goto L_035d;
  case 0x0366: goto L_0366;
  case 0x036f: goto L_036f;
  case 0x0375: goto L_0375;
  case 0x0388: goto L_0388;
  case 0x03a9: goto L_03a9;
  case 0x03aa: goto L_03aa;
  case 0x03ad: goto L_03ad;
  case 0x03b0: goto L_03b0;
  case 0x03b3: goto L_03b3;
  case 0x03e0: goto L_03e0;
  case 0x03e6: goto L_03e6;
  case 0x03ec: goto L_03ec;
  case 0x0400: goto L_0400;
  case 0x0401: goto L_0401;
  case 0x040e: goto L_040e;
  case 0x0415: goto L_0415;
  case 0x0422: goto L_0422;
  case 0x0429: goto L_0429;
  case 0x0430: goto L_0430;
  case 0x0433: goto L_0433;
  case 0x043a: goto L_043a;
  case 0x0441: goto L_0441;
  case 0x0448: goto L_0448;
  case 0x044f: goto L_044f;
  case 0x0456: goto L_0456;
  case 0x045d: goto L_045d;
  case 0x0464: goto L_0464;
  case 0x046b: goto L_046b;
  case 0x0472: goto L_0472;
  case 0x0479: goto L_0479;
  case 0x0480: goto L_0480;
  case 0x0487: goto L_0487;
  case 0x048e: goto L_048e;
  case 0x0495: goto L_0495;
  case 0x049c: goto L_049c;
  case 0x04a3: goto L_04a3;
  case 0x04aa: goto L_04aa;
  case 0x04b1: goto L_04b1;
  case 0x04b8: goto L_04b8;
  case 0x04c9: goto L_04c9;
  case 0x04d4: goto L_04d4;
  case 0x04db: goto L_04db;
  case 0x04e2: goto L_04e2;
  case 0x04f8: goto L_04f8;
  case 0x050e: goto L_050e;
  case 0x0524: goto L_0524;
  case 0x052b: goto L_052b;
  case 0x0532: goto L_0532;
  case 0x053d: goto L_053d;
  case 0x0548: goto L_0548;
  case 0x054c: goto L_054c;
  case 0x0550: goto L_0550;
  case 0x055c: goto L_055c;
  case 0x0563: goto L_0563;
  case 0x056a: goto L_056a;
  case 0x0571: goto L_0571;
  case 0x0578: goto L_0578;
  case 0x058b: goto L_058b;
  case 0x0592: goto L_0592;
  case 0x0599: goto L_0599;
  case 0x05a0: goto L_05a0;
  case 0x05b3: goto L_05b3;
  case 0x05ba: goto L_05ba;
  case 0x05c1: goto L_05c1;
  case 0x05c5: goto L_05c5;
  case 0x05df: goto L_05df;
  case 0x05e0: goto L_05e0;
  case 0x05f3: goto L_05f3;
  case 0x05fa: goto L_05fa;
  case 0x0601: goto L_0601;
  case 0x0614: goto L_0614;
  case 0x061b: goto L_061b;
  case 0x0622: goto L_0622;
  case 0x0635: goto L_0635;
  case 0x063c: goto L_063c;
  case 0x0643: goto L_0643;
  case 0x0656: goto L_0656;
  case 0x065d: goto L_065d;
  case 0x0664: goto L_0664;
  case 0x0677: goto L_0677;
  case 0x067e: goto L_067e;
  case 0x0685: goto L_0685;
  case 0x068c: goto L_068c;
  case 0x068f: goto L_068f;
  case 0x069a: goto L_069a;
  case 0x069d: goto L_069d;
  case 0x06a9: goto L_06a9;
  case 0x06b4: goto L_06b4;
  case 0x06b5: goto L_06b5;
  case 0x06bc: goto L_06bc;
  case 0x06c3: goto L_06c3;
  case 0x06ca: goto L_06ca;
  case 0x06d1: goto L_06d1;
  case 0x06d8: goto L_06d8;
  case 0x06df: goto L_06df;
  case 0x06e6: goto L_06e6;
  case 0x06ed: goto L_06ed;
  case 0x06f4: goto L_06f4;
  case 0x06fb: goto L_06fb;
  case 0x0702: goto L_0702;
  case 0x0709: goto L_0709;
  case 0x072d: goto L_072d;
  case 0x0734: goto L_0734;
  case 0x073d: goto L_073d;
  case 0x0751: goto L_0751;
  case 0x075d: goto L_075d;
  case 0x0764: goto L_0764;
  case 0x076b: goto L_076b;
  case 0x0772: goto L_0772;
  case 0x0779: goto L_0779;
  case 0x0780: goto L_0780;
  case 0x0787: goto L_0787;
  case 0x078e: goto L_078e;
  case 0x0795: goto L_0795;
  case 0x079c: goto L_079c;
  case 0x07a3: goto L_07a3;
  case 0x07aa: goto L_07aa;
  case 0x07b1: goto L_07b1;
  case 0x07b8: goto L_07b8;
  case 0x07bf: goto L_07bf;
  case 0x07ce: goto L_07ce;
  case 0x07dd: goto L_07dd;
  case 0x07e9: goto L_07e9;
  case 0x07f8: goto L_07f8;
  default: asm_unknown_call(0xd000, ip_); return;
  }
L_0098:   PUSH(R.ds);                                                  // 0098 push ds
  R.ax = (u16)(0xd080 /* segment */);                          // 0099 mov ax, 0x80
  R.ds = (u16)(R.ax);                                          // 009c mov ds, ax
  PUSH(0x00a1); goto L_03aa;                                   // 009e call 0x3aa
L_00a1:   SETH(R.ax, 0x0);                                             // 00a1 mov ah, 0
  W8(DS, (u16)(0xcf), (u8)(R.ax >> 8));                        // 00a3 mov byte ptr [0xcf], ah
  SETH(R.ax, 0x81);                                            // 00a7 mov ah, 0x81
  ASM_INT(0x1a);                                               // 00a9 int 0x1a
  AND16(R.ax, 0xf000);                                         // 00ab test ax, 0xf000
  if (!R.zf) goto L_00b5;                                      // 00ae jne 0xb5
  W8(DS, (u16)(0xcf), 0xff);                                   // 00b0 mov byte ptr [0xcf], 0xff
L_00b5:   W8(DS, (u16)(0xca), 0x0);                                    // 00b5 mov byte ptr [0xca], 0
  W8(DS, (u16)(0xc9), 0x0);                                    // 00ba mov byte ptr [0xc9], 0
  R.ds = POP();                                                // 00bf pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00c0 retf
L_00c1:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 00c1 xor ax, ax
L_00c3:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00c3 retf
L_00c4:   PUSH(R.bp);                                                  // 00c4 push bp
  R.bp = (u16)(R.sp);                                          // 00c5 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 00c7 mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x56);                                           // 00ca cmp bx, 0x56
  if (!R.zf && R.sf == R.of) goto L_00df;                      // 00cd jg 0xdf
  PUSH(R.ds);                                                  // 00cf push ds
  R.ax = (u16)(0xd080 /* segment */);                          // 00d0 mov ax, 0x80
  R.ds = (u16)(R.ax);                                          // 00d3 mov ds, ax
  PUSH(R.di);                                                  // 00d5 push di
  { u16 t_ = M16(CS, (u16)(R.bx + 0x40)); PUSH(0x00db); ip_ = t_; goto dispatch_; } // 00d6 call word ptr cs:[bx + 0x40]
L_00db:   R.di = POP();                                                // 00db pop di
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 00dc xor ax, ax
  R.ds = POP();                                                // 00de pop ds
L_00df:   R.bp = POP();                                                // 00df pop bp
L_00e0:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00e0 retf
L_00e3:   PUSH(R.di);                                                  // 00e3 push di
  PUSH(R.bx);                                                  // 00e4 push bx
  PUSH(R.cx);                                                  // 00e5 push cx
  PUSH(R.ds);                                                  // 00e6 push ds
  R.ax = (u16)(0xd080 /* segment */);                          // 00e7 mov ax, 0x80
  R.ds = (u16)(R.ax);                                          // 00ea mov ds, ax
  PUSH(0x00ef); goto L_0122;                                   // 00ec call 0x122
L_00ef:   R.ds = POP();                                                // 00ef pop ds
  R.cx = POP();                                                // 00f0 pop cx
  R.bx = POP();                                                // 00f1 pop bx
  R.di = POP();                                                // 00f2 pop di
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 00f3 xor ax, ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 00f5 retf
L_00f6:   PUSH(R.bp);                                                  // 00f6 push bp
  R.bp = (u16)(R.sp);                                          // 00f7 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 00f9 mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x5);                                            // 00fc cmp bx, 5
  if (!R.zf && R.sf == R.of) goto L_00df;                      // 00ff jg 0xdf
  PUSH(R.ds);                                                  // 0101 push ds
  R.ax = (u16)(0xd080 /* segment */);                          // 0102 mov ax, 0x80
  R.ds = (u16)(R.ax);                                          // 0105 mov ds, ax
  W16(DS, (u16)(0xc4), R.bx);                                  // 0107 mov word ptr [0xc4], bx
  PUSH(0x010e); goto L_0709;                                   // 010b call 0x709
L_010e:   R.ds = POP();                                                // 010e pop ds
  R.bp = POP();                                                // 010f pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0110 retf
L_0111:   R.cx = (u16)(0x79);                                          // 0111 mov cx, 0x79
  R.bx = (u16)((u16)(0x50));                                   // 0114 lea bx, [0x50]
L_0118:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0118 xor ax, ax
  R.bx = (u16)(ADD16(R.bx, R.cx));                             // 011a add bx, cx
L_011c:   R.bx = (u16)(DEC16(R.bx));                                   // 011c dec bx
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 011d mov byte ptr [bx], al
  if (--R.cx != 0) goto L_011c;                                // 011f loop 0x11c
L_0121:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0121 ret
L_0122:   W16(CS, (u16)(0xe1), INC16(M16(CS, (u16)(0xe1))));           // 0122 inc word ptr cs:[0xe1]
  SUB8(M8(DS, (u16)(0xca)), 0xff);                             // 0127 cmp byte ptr [0xca], 0xff
  if (R.zf) goto L_0121;                                       // 012c je 0x121
  R.di = (u16)((u16)(0x50));                                   // 012e lea di, [0x50]
  PUSH(0x0135); goto L_0147;                                   // 0132 call 0x147
L_0135:   R.di = (u16)((u16)(0x6d));                                   // 0135 lea di, [0x6d]
  PUSH(0x013c); goto L_0147;                                   // 0139 call 0x147
L_013c:   R.di = (u16)((u16)(0x8a));                                   // 013c lea di, [0x8a]
  PUSH(0x0143); goto L_0147;                                   // 0140 call 0x147
L_0143:   R.di = (u16)((u16)(0xa7));                                   // 0143 lea di, [0xa7]
L_0147:   SUB8(M8(DS, (u16)(R.di + 0x1c)), 0x0);                       // 0147 cmp byte ptr [di + 0x1c], 0
  if (R.zf) goto L_0121;                                       // 014b je 0x121
  W8(DS, (u16)(R.di + 0x1c), DEC8(M8(DS, (u16)(R.di + 0x1c)))); // 014d dec byte ptr [di + 0x1c]
  if (!R.zf) goto L_0155;                                      // 0150 jne 0x155
  goto L_0216;                                                 // 0152 jmp 0x216
L_0155:   SUB16(M16(DS, (u16)(R.di + 0x2)), 0xffff);                   // 0155 cmp word ptr [di + 2], -1
  if (R.zf) goto L_0121;                                       // 0159 je 0x121
  SETL(R.ax, M8(DS, (u16)(R.di + 0x19)));                      // 015b mov al, byte ptr [di + 0x19]
  SUB8((u8)R.ax, M8(DS, (u16)(R.di + 0x1c)));                  // 015e cmp al, byte ptr [di + 0x1c]
  if (R.cf) goto L_018b;                                       // 0161 jb 0x18b
  SUB8(M8(DS, (u16)(R.di + 0xa)), 0x0);                        // 0163 cmp byte ptr [di + 0xa], 0
  if (R.zf) goto L_018b;                                       // 0167 je 0x18b
  W8(DS, (u16)(R.di + 0x9), DEC8(M8(DS, (u16)(R.di + 0x9))));  // 0169 dec byte ptr [di + 9]
  if (!R.zf) goto L_018b;                                      // 016c jne 0x18b
  SETL(R.ax, M8(DS, (u16)(R.di + 0xa)));                       // 016e mov al, byte ptr [di + 0xa]
  W8(DS, (u16)(R.di + 0x9), (u8)R.ax);                         // 0171 mov byte ptr [di + 9], al
  SETH(R.ax, M8(DS, (u16)(R.di + 0x1a)));                      // 0174 mov ah, byte ptr [di + 0x1a]
  SETL(R.ax, (u8)(R.ax >> 8));                                 // 0177 mov al, ah
  R.ax = (u16)(AND16(R.ax, 0xf00f));                           // 0179 and ax, 0xf00f
  SUB8((u8)R.ax, M8(DS, (u16)(R.di + 0xb)));                   // 017c cmp al, byte ptr [di + 0xb]
  if (R.zf) goto L_018b;                                       // 017f je 0x18b
  SETL(R.ax, ADD8((u8)R.ax, M8(DS, (u16)(R.di + 0x8))));       // 0181 add al, byte ptr [di + 8]
  SETL(R.ax, AND8((u8)R.ax, 0xf));                             // 0184 and al, 0xf
  SETL(R.ax, OR8((u8)R.ax, (u8)(R.ax >> 8)));                  // 0186 or al, ah
  W8(DS, (u16)(R.di + 0x1a), (u8)R.ax);                        // 0188 mov byte ptr [di + 0x1a], al
L_018b:   SUB16(M16(DS, (u16)(R.di + 0x6)), 0x0);                      // 018b cmp word ptr [di + 6], 0
  if (R.zf) goto L_01a8;                                       // 018f je 0x1a8
  W8(DS, (u16)(R.di + 0x6), DEC8(M8(DS, (u16)(R.di + 0x6))));  // 0191 dec byte ptr [di + 6]
  if (!R.zf) goto L_01a8;                                      // 0194 jne 0x1a8
  SETL(R.ax, M8(DS, (u16)(R.di + 0x7)));                       // 0196 mov al, byte ptr [di + 7]
  W8(DS, (u16)(R.di + 0x6), (u8)R.ax);                         // 0199 mov byte ptr [di + 6], al
  R.ax = (u16)(M16(DS, (u16)(R.di + 0x2)));                    // 019c mov ax, word ptr [di + 2]
  R.ax = (u16)(ADD16(R.ax, M16(DS, (u16)(R.di + 0x4))));       // 019f add ax, word ptr [di + 4]
  R.ax = (u16)(AND16(R.ax, 0x3ff));                            // 01a2 and ax, 0x3ff
  W16(DS, (u16)(R.di + 0x2), R.ax);                            // 01a5 mov word ptr [di + 2], ax
L_01a8:   SUB8(M8(DS, (u16)(R.di + 0xd)), 0x0);                        // 01a8 cmp byte ptr [di + 0xd], 0
  if (R.zf) goto L_01d9;                                       // 01ac je 0x1d9
  W8(DS, (u16)(R.di + 0xd), DEC8(M8(DS, (u16)(R.di + 0xd))));  // 01ae dec byte ptr [di + 0xd]
  if (!R.zf) goto L_01d9;                                      // 01b1 jne 0x1d9
  SETL(R.ax, M8(DS, (u16)(R.di + 0xe)));                       // 01b3 mov al, byte ptr [di + 0xe]
  W8(DS, (u16)(R.di + 0xd), (u8)R.ax);                         // 01b6 mov byte ptr [di + 0xd], al
  SETL(R.ax, M8(DS, (u16)(R.di + 0x1a)));                      // 01b9 mov al, byte ptr [di + 0x1a]
  SETH(R.ax, (u8)R.ax);                                        // 01bc mov ah, al
  R.ax = (u16)(AND16(R.ax, 0xf00f));                           // 01be and ax, 0xf00f
  SUB8((u8)R.ax, 0xf);                                         // 01c1 cmp al, 0xf
  if (R.zf) goto L_01d9;                                       // 01c3 je 0x1d9
  SETL(R.ax, ADD8((u8)R.ax, M8(DS, (u16)(R.di + 0xc))));       // 01c5 add al, byte ptr [di + 0xc]
  R.ax = (u16)(AND16(R.ax, 0xf00f));                           // 01c8 and ax, 0xf00f
  SETH(R.ax, OR8((u8)(R.ax >> 8), (u8)R.ax));                  // 01cb or ah, al
  W8(DS, (u16)(R.di + 0x1a), (u8)(R.ax >> 8));                 // 01cd mov byte ptr [di + 0x1a], ah
  SUB8((u8)(R.ax >> 8), M8(DS, (u16)(R.di + 0x1b)));           // 01d0 cmp ah, byte ptr [di + 0x1b]
  if (R.zf) goto L_01d9;                                       // 01d3 je 0x1d9
  W8(DS, (u16)(R.di + 0xc), XOR8(M8(DS, (u16)(R.di + 0xc)), 0xfe)); // 01d5 xor byte ptr [di + 0xc], 0xfe
L_01d9:   SUB8(M8(DS, (u16)(0xc9)), 0xff);                             // 01d9 cmp byte ptr [0xc9], 0xff
  if (R.zf) goto L_0215;                                       // 01de je 0x215
  R.bx = (u16)(M16(DS, (u16)(R.di + 0x2)));                    // 01e0 mov bx, word ptr [di + 2]
  SUB16(R.bx, 0xffff);                                         // 01e3 cmp bx, -1
  if (R.zf) goto L_0215;                                       // 01e6 je 0x215
  SETL(R.ax, (u8)R.bx);                                        // 01e8 mov al, bl
  SETL(R.ax, AND8((u8)R.ax, 0xf));                             // 01ea and al, 0xf
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 01ec ror bx, 1
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 01ee ror bx, 1
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 01f0 ror bx, 1
  R.bx = (u16)(ROR16(R.bx, 0x1));                              // 01f2 ror bx, 1
  SETH(R.bx, (u8)R.ax);                                        // 01f4 mov bh, al
  R.bx = (u16)(AND16(R.bx, 0xf3f));                            // 01f6 and bx, 0xf3f
  SETL(R.ax, M8(DS, (u16)(R.di + 0x1a)));                      // 01fa mov al, byte ptr [di + 0x1a]
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 01fd out 0xc0, al
  SUB16(R.bx, M16(DS, (u16)(R.di)));                           // 01ff cmp bx, word ptr [di]
  if (R.zf) goto L_0215;                                       // 0201 je 0x215
  W16(DS, (u16)(R.di), R.bx);                                  // 0203 mov word ptr [di], bx
  SETL(R.ax, AND8((u8)R.ax, 0xe0));                            // 0205 and al, 0xe0
  SETH(R.bx, OR8((u8)(R.bx >> 8), (u8)R.ax));                  // 0207 or bh, al
  SETL(R.ax, (u8)(R.bx >> 8));                                 // 0209 mov al, bh
  SUB8((u8)R.ax, 0xe0);                                        // 020b cmp al, 0xe0
  if (!R.cf) goto L_0213;                                      // 020d jae 0x213
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 020f out 0xc0, al
  SETL(R.ax, (u8)R.bx);                                        // 0211 mov al, bl
L_0213:   ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 0213 out 0xc0, al
L_0215:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0215 ret
L_0216:   R.bx = (u16)(M16(DS, (u16)(R.di + 0x17)));                   // 0216 mov bx, word ptr [di + 0x17]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0219 mov al, byte ptr [bx]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 021b or al, al
  if (R.zf) goto L_0222;                                       // 021d je 0x222
  goto L_0235;                                                 // 021f jmp 0x235
L_0222:   SETL(R.ax, M8(DS, (u16)(R.di + 0x1a)));                      // 0222 mov al, byte ptr [di + 0x1a]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 0225 or al, al
  if (R.zf) goto L_022d;                                       // 0227 je 0x22d
  SETL(R.ax, OR8((u8)R.ax, 0x9f));                             // 0229 or al, 0x9f
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 022b out 0xc0, al
L_022d:   R.bx = (u16)(R.di);                                          // 022d mov bx, di
  R.cx = (u16)(0x1d);                                          // 022f mov cx, 0x1d
  goto L_0118;                                                 // 0232 jmp 0x118
L_0235:   PUSH(0x0238); goto L_0267;                                   // 0235 call 0x267
L_0238:   if (!R.zf) goto L_0265;                                      // 0238 jne 0x265
  W8(DS, (u16)(R.di + 0x1c), (u8)R.ax);                        // 023a mov byte ptr [di + 0x1c], al
  SUB8((u8)R.ax, 0x0);                                         // 023d cmp al, 0
  if (R.zf) goto L_0222;                                       // 023f je 0x222
  SETL(R.ax, M8(DS, (u16)(R.di + 0x1b)));                      // 0241 mov al, byte ptr [di + 0x1b]
  W8(DS, (u16)(R.di + 0x1a), (u8)R.ax);                        // 0244 mov byte ptr [di + 0x1a], al
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 0247 mov ax, word ptr [bx]
  W16(DS, (u16)(R.di + 0x2), R.ax);                            // 0249 mov word ptr [di + 2], ax
  R.bx = (u16)(INC16(R.bx));                                   // 024c inc bx
  R.bx = (u16)(INC16(R.bx));                                   // 024d inc bx
  W16(DS, (u16)(R.di + 0x17), R.bx);                           // 024e mov word ptr [di + 0x17], bx
  SUB16(R.ax, 0xffff);                                         // 0251 cmp ax, 0xffff
  if (!R.zf) goto L_01d9;                                      // 0254 jne 0x1d9
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0256 xor ax, ax
  W16(DS, (u16)(R.di + 0x4), R.ax);                            // 0258 mov word ptr [di + 4], ax
  W8(DS, (u16)(R.di + 0x8), (u8)R.ax);                         // 025b mov byte ptr [di + 8], al
  SETL(R.ax, M8(DS, (u16)(R.di + 0x1b)));                      // 025e mov al, byte ptr [di + 0x1b]
  SETL(R.ax, OR8((u8)R.ax, 0x9f));                             // 0261 or al, 0x9f
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 0263 out 0xc0, al
L_0265:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0265 ret
L_0266:   R.bx = (u16)(INC16(R.bx));                                   // 0266 inc bx
L_0267:   SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0267 mov al, byte ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 0269 inc bx
  AND8((u8)R.ax, 0x80);                                        // 026a test al, 0x80
  if (R.zf) goto L_0265;                                       // 026c je 0x265
  SUB8((u8)R.ax, 0xc0);                                        // 026e cmp al, 0xc0
  if (!R.zf) goto L_027e;                                      // 0270 jne 0x27e
  SETL(R.ax, M8(DS, (u16)(R.di + 0x1b)));                      // 0272 mov al, byte ptr [di + 0x1b]
  SETL(R.ax, AND8((u8)R.ax, 0xf0));                            // 0275 and al, 0xf0
  SETL(R.ax, OR8((u8)R.ax, M8(DS, (u16)(R.bx))));              // 0277 or al, byte ptr [bx]
  W8(DS, (u16)(R.di + 0x1b), (u8)R.ax);                        // 0279 mov byte ptr [di + 0x1b], al
  goto L_0266;                                                 // 027c jmp 0x266
L_027e:   SUB8((u8)R.ax, 0xa0);                                        // 027e cmp al, 0xa0
  if (!R.zf) goto L_029a;                                      // 0280 jne 0x29a
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0282 mov al, byte ptr [bx]
  SETL(R.ax, AND8((u8)R.ax, 0xf));                             // 0284 and al, 0xf
  W8(DS, (u16)(R.di + 0x8), (u8)R.ax);                         // 0286 mov byte ptr [di + 8], al
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0289 mov al, byte ptr [bx]
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 028b shr al, 1
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 028d shr al, 1
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 028f shr al, 1
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 0291 shr al, 1
  SETH(R.ax, (u8)R.ax);                                        // 0293 mov ah, al
  W16(DS, (u16)(R.di + 0x9), R.ax);                            // 0295 mov word ptr [di + 9], ax
  goto L_0266;                                                 // 0298 jmp 0x266
L_029a:   SUB8((u8)R.ax, 0x90);                                        // 029a cmp al, 0x90
  if (!R.zf) goto L_02ae;                                      // 029c jne 0x2ae
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 029e mov al, byte ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 02a0 inc bx
  SETH(R.ax, (u8)R.ax);                                        // 02a1 mov ah, al
  W16(DS, (u16)(R.di + 0x6), R.ax);                            // 02a3 mov word ptr [di + 6], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 02a6 mov ax, word ptr [bx]
  W16(DS, (u16)(R.di + 0x4), R.ax);                            // 02a8 mov word ptr [di + 4], ax
  R.bx = (u16)(INC16(R.bx));                                   // 02ab inc bx
  goto L_0266;                                                 // 02ac jmp 0x266
L_02ae:   SUB8((u8)R.ax, 0x80);                                        // 02ae cmp al, 0x80
  if (!R.zf) goto L_02d7;                                      // 02b0 jne 0x2d7
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 02b2 mov al, byte ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 02b4 inc bx
  SUB8(M8(DS, (u16)(R.di + 0x12)), 0x0);                       // 02b5 cmp byte ptr [di + 0x12], 0
  if (R.zf) goto L_02c8;                                       // 02b9 je 0x2c8
  W8(DS, (u16)(R.di + 0x12), DEC8(M8(DS, (u16)(R.di + 0x12)))); // 02bb dec byte ptr [di + 0x12]
  if (!R.zf) goto L_02cf;                                      // 02be jne 0x2cf
L_02c0:   W16(DS, (u16)(R.di + 0x13), R.bx);                           // 02c0 mov word ptr [di + 0x13], bx
  W16(DS, (u16)(R.di + 0x10), R.bx);                           // 02c3 mov word ptr [di + 0x10], bx
  goto L_0267;                                                 // 02c6 jmp 0x267
L_02c8:   SUB8((u8)R.ax, 0x0);                                         // 02c8 cmp al, 0
  if (R.zf) goto L_02c0;                                       // 02ca je 0x2c0
  W8(DS, (u16)(R.di + 0x12), (u8)R.ax);                        // 02cc mov byte ptr [di + 0x12], al
L_02cf:   R.bx = (u16)(M16(DS, (u16)(R.di + 0x13)));                   // 02cf mov bx, word ptr [di + 0x13]
  W16(DS, (u16)(R.di + 0x10), R.bx);                           // 02d2 mov word ptr [di + 0x10], bx
  goto L_0267;                                                 // 02d5 jmp 0x267
L_02d7:   SUB8((u8)R.ax, 0xf3);                                        // 02d7 cmp al, 0xf3
  if (!R.zf) goto L_02fc;                                      // 02d9 jne 0x2fc
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 02db mov al, byte ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 02dd inc bx
  SUB8(M8(DS, (u16)(R.di + 0xf)), 0x0);                        // 02de cmp byte ptr [di + 0xf], 0
  if (R.zf) goto L_02ef;                                       // 02e2 je 0x2ef
  W8(DS, (u16)(R.di + 0xf), DEC8(M8(DS, (u16)(R.di + 0xf))));  // 02e4 dec byte ptr [di + 0xf]
  if (!R.zf) goto L_02f6;                                      // 02e7 jne 0x2f6
L_02e9:   W16(DS, (u16)(R.di + 0x10), R.bx);                           // 02e9 mov word ptr [di + 0x10], bx
  goto L_0267;                                                 // 02ec jmp 0x267
L_02ef:   SUB8((u8)R.ax, 0x0);                                         // 02ef cmp al, 0
  if (R.zf) goto L_02e9;                                       // 02f1 je 0x2e9
  W8(DS, (u16)(R.di + 0xf), (u8)R.ax);                         // 02f3 mov byte ptr [di + 0xf], al
L_02f6:   R.bx = (u16)(M16(DS, (u16)(R.di + 0x10)));                   // 02f6 mov bx, word ptr [di + 0x10]
  goto L_0267;                                                 // 02f9 jmp 0x267
L_02fc:   SUB8((u8)R.ax, 0xb0);                                        // 02fc cmp al, 0xb0
  if (!R.zf) goto L_0308;                                      // 02fe jne 0x308
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0300 mov al, byte ptr [bx]
  W8(DS, (u16)(R.di + 0x19), (u8)R.ax);                        // 0302 mov byte ptr [di + 0x19], al
  goto L_0266;                                                 // 0305 jmp 0x266
L_0308:   SUB8((u8)R.ax, 0xd0);                                        // 0308 cmp al, 0xd0
  if (!R.zf) goto L_0314;                                      // 030a jne 0x314
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 030c mov al, byte ptr [bx]
  W8(DS, (u16)(R.di + 0xb), (u8)R.ax);                         // 030e mov byte ptr [di + 0xb], al
  goto L_0266;                                                 // 0311 jmp 0x266
L_0314:   SUB8((u8)R.ax, 0xf1);                                        // 0314 cmp al, 0xf1
  if (!R.zf) goto L_0326;                                      // 0316 jne 0x326
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0318 mov al, byte ptr [bx]
  SETH(R.ax, (u8)R.ax);                                        // 031a mov ah, al
  W16(DS, (u16)(R.di + 0xd), R.ax);                            // 031c mov word ptr [di + 0xd], ax
  W8(DS, (u16)(R.di + 0xc), 0x1);                              // 031f mov byte ptr [di + 0xc], 1
  goto L_0266;                                                 // 0323 jmp 0x266
L_0326:   SUB8((u8)R.ax, 0xf2);                                        // 0326 cmp al, 0xf2
  if (!R.zf) goto L_0335;                                      // 0328 jne 0x335
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 032a xor ax, ax
  W16(DS, (u16)(R.di + 0xd), R.ax);                            // 032c mov word ptr [di + 0xd], ax
  W8(DS, (u16)(R.di + 0xc), (u8)R.ax);                         // 032f mov byte ptr [di + 0xc], al
  goto L_0267;                                                 // 0332 jmp 0x267
L_0335:   SUB8((u8)R.ax, 0xe0);                                        // 0335 cmp al, 0xe0
  if (!R.zf) goto L_0344;                                      // 0337 jne 0x344
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0339 xor ax, ax
  W16(DS, (u16)(R.di + 0x4), R.ax);                            // 033b mov word ptr [di + 4], ax
  W16(DS, (u16)(R.di + 0x6), R.ax);                            // 033e mov word ptr [di + 6], ax
  goto L_0267;                                                 // 0341 jmp 0x267
L_0344:   SUB8((u8)R.ax, 0xf0);                                        // 0344 cmp al, 0xf0
  if (!R.zf) goto L_03a9;                                      // 0346 jne 0x3a9
  R.bx = (u16)(M16(DS, (u16)(R.di + 0x15)));                   // 0348 mov bx, word ptr [di + 0x15]
  W16(DS, (u16)(R.di + 0x10), R.bx);                           // 034b mov word ptr [di + 0x10], bx
  W16(DS, (u16)(R.di + 0x13), R.bx);                           // 034e mov word ptr [di + 0x13], bx
  goto L_0267;                                                 // 0351 jmp 0x267
L_0354:   R.di = (u16)((u16)(0x50));                                   // 0354 lea di, [0x50]
  SETL(R.ax, 0x95);                                            // 0358 mov al, 0x95
  goto L_0375;                                                 // 035a jmp 0x375
L_035d:   R.di = (u16)((u16)(0x6d));                                   // 035d lea di, [0x6d]
  SETL(R.ax, 0xb5);                                            // 0361 mov al, 0xb5
  goto L_0375;                                                 // 0363 jmp 0x375
L_0366:   R.di = (u16)((u16)(0x8a));                                   // 0366 lea di, [0x8a]
  SETL(R.ax, 0xd5);                                            // 036a mov al, 0xd5
  goto L_0375;                                                 // 036c jmp 0x375
L_036f:   R.di = (u16)((u16)(0xa7));                                   // 036f lea di, [0xa7]
  SETL(R.ax, 0xf5);                                            // 0373 mov al, 0xf5
L_0375:   SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 0375 cmp byte ptr [bx], 0
  if (R.zf) goto L_03a9;                                       // 0378 je 0x3a9
  SETH(R.ax, M8(DS, (u16)(0xca)));                             // 037a mov ah, byte ptr [0xca]
  W8(DS, (u16)(0xca), 0xff);                                   // 037e mov byte ptr [0xca], 0xff
  PUSH(R.ax);                                                  // 0383 push ax
  PUSH(R.bx);                                                  // 0384 push bx
  PUSH(0x0388); goto L_0222;                                   // 0385 call 0x222
L_0388:   R.bx = POP();                                                // 0388 pop bx
  R.ax = POP();                                                // 0389 pop ax
  W8(DS, (u16)(R.di + 0x1b), (u8)R.ax);                        // 038a mov byte ptr [di + 0x1b], al
  W16(DS, (u16)(R.di + 0x10), R.bx);                           // 038d mov word ptr [di + 0x10], bx
  W16(DS, (u16)(R.di + 0x13), R.bx);                           // 0390 mov word ptr [di + 0x13], bx
  W16(DS, (u16)(R.di + 0x15), R.bx);                           // 0393 mov word ptr [di + 0x15], bx
  W16(DS, (u16)(R.di + 0x17), R.bx);                           // 0396 mov word ptr [di + 0x17], bx
  W8(DS, (u16)(R.di + 0x19), 0xff);                            // 0399 mov byte ptr [di + 0x19], 0xff
  W8(DS, (u16)(R.di + 0xb), 0xf);                              // 039d mov byte ptr [di + 0xb], 0xf
  W8(DS, (u16)(R.di + 0x1c), 0x1);                             // 03a1 mov byte ptr [di + 0x1c], 1
  W8(DS, (u16)(0xca), (u8)(R.ax >> 8));                        // 03a5 mov byte ptr [0xca], ah
L_03a9:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 03a9 ret
L_03aa:   PUSH(0x03ad); goto L_03e0;                                   // 03aa call 0x3e0
L_03ad:   PUSH(0x03b0); goto L_0111;                                   // 03ad call 0x111
L_03b0:   PUSH(0x03b3); goto L_03e6;                                   // 03b0 call 0x3e6
L_03b3:   SETL(R.ax, 0x82);                                            // 03b3 mov al, 0x82
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03b5 out 0xc0, al
  SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 03b7 xor al, al
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03b9 out 0xc0, al
  SETL(R.ax, 0xa3);                                            // 03bb mov al, 0xa3
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03bd out 0xc0, al
  SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 03bf xor al, al
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03c1 out 0xc0, al
  SETL(R.ax, 0xc4);                                            // 03c3 mov al, 0xc4
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03c5 out 0xc0, al
  SETL(R.ax, XOR8((u8)R.ax, (u8)R.ax));                        // 03c7 xor al, al
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03c9 out 0xc0, al
  SETL(R.ax, 0xe3);                                            // 03cb mov al, 0xe3
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03cd out 0xc0, al
  SETL(R.ax, 0x9f);                                            // 03cf mov al, 0x9f
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03d1 out 0xc0, al
  SETL(R.ax, 0xbf);                                            // 03d3 mov al, 0xbf
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03d5 out 0xc0, al
  SETL(R.ax, 0xdf);                                            // 03d7 mov al, 0xdf
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03d9 out 0xc0, al
  SETL(R.ax, 0xff);                                            // 03db mov al, 0xff
  ASM_PORT_OUT(0xc0, (u8)R.ax);                                // 03dd out 0xc0, al
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 03df ret
L_03e0:   W8(DS, (u16)(0xca), 0xff);                                   // 03e0 mov byte ptr [0xca], 0xff
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 03e5 ret
L_03e6:   W8(DS, (u16)(0xca), 0x0);                                    // 03e6 mov byte ptr [0xca], 0
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 03eb ret
L_03ec:   R.bx = (u16)((u16)(0x1527));                                 // 03ec lea bx, [0x1527]
  W16(DS, (u16)(0x67), R.bx);                                  // 03f0 mov word ptr [0x67], bx
  W16(DS, (u16)(0x84), R.bx);                                  // 03f4 mov word ptr [0x84], bx
  W16(DS, (u16)(0xa1), R.bx);                                  // 03f8 mov word ptr [0xa1], bx
  W16(DS, (u16)(0xbe), R.bx);                                  // 03fc mov word ptr [0xbe], bx
L_0400:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0400 ret
L_0401:   R.bx = (u16)((u16)(0x1f8));                                  // 0401 lea bx, [0x1f8]
  SUB16(M16(DS, (u16)(0x9f)), R.bx);                           // 0405 cmp word ptr [0x9f], bx
  if (R.zf) goto L_0400;                                       // 0409 je 0x400
  PUSH(0x040e); goto L_0366;                                   // 040b call 0x366
L_040e:   R.bx = (u16)((u16)(0x219));                                  // 040e lea bx, [0x219]
  goto L_036f;                                                 // 0412 jmp 0x36f
L_0415:   R.bx = (u16)((u16)(0x1c2));                                  // 0415 lea bx, [0x1c2]
  SUB16(M16(DS, (u16)(0x9f)), R.bx);                           // 0419 cmp word ptr [0x9f], bx
  if (R.zf) goto L_0400;                                       // 041d je 0x400
  PUSH(0x0422); goto L_0366;                                   // 041f call 0x366
L_0422:   R.bx = (u16)((u16)(0x1de));                                  // 0422 lea bx, [0x1de]
  goto L_036f;                                                 // 0426 jmp 0x36f
L_0429:   R.bx = (u16)((u16)(0x28d));                                  // 0429 lea bx, [0x28d]
  PUSH(0x0430); goto L_036f;                                   // 042d call 0x36f
L_0430:   goto L_043a;                                                 // 0430 jmp 0x43a
L_0433:   R.bx = (u16)((u16)(0x150));                                  // 0433 lea bx, [0x150]
  PUSH(0x043a); goto L_036f;                                   // 0437 call 0x36f
L_043a:   R.bx = (u16)((u16)(0x146));                                  // 043a lea bx, [0x146]
  goto L_0366;                                                 // 043e jmp 0x366
L_0441:   R.bx = (u16)((u16)(0x175e));                                 // 0441 lea bx, [0x175e]
  PUSH(0x0448); goto L_0354;                                   // 0445 call 0x354
L_0448:   R.bx = (u16)((u16)(0x1784));                                 // 0448 lea bx, [0x1784]
  PUSH(0x044f); goto L_035d;                                   // 044c call 0x35d
L_044f:   R.bx = (u16)((u16)(0x17aa));                                 // 044f lea bx, [0x17aa]
  goto L_0366;                                                 // 0453 jmp 0x366
L_0456:   R.bx = (u16)((u16)(0x16bb));                                 // 0456 lea bx, [0x16bb]
  PUSH(0x045d); goto L_0354;                                   // 045a call 0x354
L_045d:   R.bx = (u16)((u16)(0x16eb));                                 // 045d lea bx, [0x16eb]
  PUSH(0x0464); goto L_035d;                                   // 0461 call 0x35d
L_0464:   R.bx = (u16)((u16)(0x171d));                                 // 0464 lea bx, [0x171d]
  goto L_0366;                                                 // 0468 jmp 0x366
L_046b:   R.bx = (u16)((u16)(0xd50));                                  // 046b lea bx, [0xd50]
  PUSH(0x0472); goto L_0354;                                   // 046f call 0x354
L_0472:   R.bx = (u16)((u16)(0xddc));                                  // 0472 lea bx, [0xddc]
  PUSH(0x0479); goto L_035d;                                   // 0476 call 0x35d
L_0479:   R.bx = (u16)((u16)(0xe1b));                                  // 0479 lea bx, [0xe1b]
  goto L_0366;                                                 // 047d jmp 0x366
L_0480:   R.bx = (u16)((u16)(0x15a5));                                 // 0480 lea bx, [0x15a5]
  PUSH(0x0487); goto L_0354;                                   // 0484 call 0x354
L_0487:   R.bx = (u16)((u16)(0x15fa));                                 // 0487 lea bx, [0x15fa]
  PUSH(0x048e); goto L_035d;                                   // 048b call 0x35d
L_048e:   R.bx = (u16)((u16)(0x162f));                                 // 048e lea bx, [0x162f]
  goto L_0366;                                                 // 0492 jmp 0x366
L_0495:   R.bx = (u16)((u16)(0x158));                                  // 0495 lea bx, [0x158]
  goto L_036f;                                                 // 0499 jmp 0x36f
L_049c:   R.bx = (u16)((u16)(0x293));                                  // 049c lea bx, [0x293]
  PUSH(0x04a3); goto L_0366;                                   // 04a0 call 0x366
L_04a3:   R.bx = (u16)((u16)(0x2a1));                                  // 04a3 lea bx, [0x2a1]
  goto L_036f;                                                 // 04a7 jmp 0x36f
L_04aa:   R.bx = (u16)((u16)(0x18e));                                  // 04aa lea bx, [0x18e]
  PUSH(0x04b1); goto L_0366;                                   // 04ae call 0x366
L_04b1:   R.bx = (u16)((u16)(0x1b8));                                  // 04b1 lea bx, [0x1b8]
  goto L_036f;                                                 // 04b5 jmp 0x36f
L_04b8:   R.ax = (u16)(M16(CS, (u16)(0xe1)));                          // 04b8 mov ax, word ptr cs:[0xe1]
  R.ax = (u16)(AND16(R.ax, 0xf));                              // 04bc and ax, 0xf
  R.ax = (u16)(ADD16(R.ax, 0x18));                             // 04bf add ax, 0x18
  W16(DS, (u16)(R.bx), R.ax);                                  // 04c2 mov word ptr [bx], ax
  { u16 t_ = R.bx; R.bx = (u16)(R.cx); R.cx = (u16)(t_); }     // 04c4 xchg bx, cx
  W16(DS, (u16)(R.bx), R.ax);                                  // 04c6 mov word ptr [bx], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 04c8 ret
L_04c9:   R.bx = (u16)((u16)(0x1db));                                  // 04c9 lea bx, [0x1db]
  R.cx = (u16)((u16)(0x1c9));                                  // 04cd lea cx, [0x1c9]
  PUSH(0x04d4); goto L_04b8;                                   // 04d1 call 0x4b8
L_04d4:   R.bx = (u16)((u16)(0x1d4));                                  // 04d4 lea bx, [0x1d4]
  PUSH(0x04db); goto L_0366;                                   // 04d8 call 0x366
L_04db:   R.bx = (u16)((u16)(0x1ee));                                  // 04db lea bx, [0x1ee]
  goto L_036f;                                                 // 04df jmp 0x36f
L_04e2:   R.ax = (u16)(M16(CS, (u16)(0xe1)));                          // 04e2 mov ax, word ptr cs:[0xe1]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 04e6 shl ax, 1
  R.ax = (u16)(AND16(R.ax, 0xe));                              // 04e8 and ax, 0xe
  R.ax = (u16)(OR16(R.ax, 0x11));                              // 04eb or ax, 0x11
  W16(DS, (u16)(0x18b), R.ax);                                 // 04ee mov word ptr [0x18b], ax
  R.bx = (u16)((u16)(0x182));                                  // 04f1 lea bx, [0x182]
  goto L_0366;                                                 // 04f5 jmp 0x366
L_04f8:   R.ax = (u16)(M16(CS, (u16)(0xe1)));                          // 04f8 mov ax, word ptr cs:[0xe1]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 04fc shl ax, 1
  R.ax = (u16)(AND16(R.ax, 0xe));                              // 04fe and ax, 0xe
  R.ax = (u16)(OR16(R.ax, 0x11));                              // 0501 or ax, 0x11
  W16(DS, (u16)(0x17f), R.ax);                                 // 0504 mov word ptr [0x17f], ax
  R.ax = (u16)((u16)(0x176));                                  // 0507 lea ax, [0x176]
  goto L_054c;                                                 // 050b jmp 0x54c
L_050e:   R.ax = (u16)(M16(CS, (u16)(0xe1)));                          // 050e mov ax, word ptr cs:[0xe1]
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0512 shl ax, 1
  R.ax = (u16)(AND16(R.ax, 0xe));                              // 0514 and ax, 0xe
  R.ax = (u16)(OR16(R.ax, 0x9));                               // 0517 or ax, 9
  W16(DS, (u16)(0x167), R.ax);                                 // 051a mov word ptr [0x167], ax
  R.bx = (u16)((u16)(0x15e));                                  // 051d lea bx, [0x15e]
  PUSH(0x0524); goto L_0366;                                   // 0521 call 0x366
L_0524:   R.bx = (u16)((u16)(0x16c));                                  // 0524 lea bx, [0x16c]
  goto L_036f;                                                 // 0528 jmp 0x36f
L_052b:   R.ax = (u16)((u16)(0x22d));                                  // 052b lea ax, [0x22d]
  PUSH(0x0532); goto L_054c;                                   // 052f call 0x54c
L_0532:   R.ax = (u16)((u16)(0x239));                                  // 0532 lea ax, [0x239]
  R.bx = (u16)((u16)(0xa7));                                   // 0536 lea bx, [0xa7]
  goto L_0550;                                                 // 053a jmp 0x550
L_053d:   R.ax = (u16)((u16)(0x251));                                  // 053d lea ax, [0x251]
  R.bx = (u16)((u16)(0xa7));                                   // 0541 lea bx, [0xa7]
  PUSH(0x0548); goto L_0550;                                   // 0545 call 0x550
L_0548:   R.ax = (u16)((u16)(0x245));                                  // 0548 lea ax, [0x245]
L_054c:   R.bx = (u16)((u16)(0x8a));                                   // 054c lea bx, [0x8a]
L_0550:   W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 0550 mov word ptr [bx + 0x10], ax
  W16(DS, (u16)(R.bx + 0x15), R.ax);                           // 0553 mov word ptr [bx + 0x15], ax
  SETL(R.ax, 0x2);                                             // 0556 mov al, 2
  W8(DS, (u16)(R.bx + 0xf), (u8)R.ax);                         // 0558 mov byte ptr [bx + 0xf], al
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 055b ret
L_055c:   R.bx = (u16)((u16)(0x275));                                  // 055c lea bx, [0x275]
  PUSH(0x0563); goto L_0366;                                   // 0560 call 0x366
L_0563:   R.bx = (u16)((u16)(0x281));                                  // 0563 lea bx, [0x281]
  goto L_036f;                                                 // 0567 jmp 0x36f
L_056a:   R.bx = (u16)((u16)(0x25d));                                  // 056a lea bx, [0x25d]
  PUSH(0x0571); goto L_0366;                                   // 056e call 0x366
L_0571:   R.bx = (u16)((u16)(0x269));                                  // 0571 lea bx, [0x269]
  goto L_036f;                                                 // 0575 jmp 0x36f
L_0578:   SETL(R.bx, 0xc);                                             // 0578 mov bl, 0xc
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 057a cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_05df;                                       // 057e je 0x5df
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 0580 mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x6ad));                                  // 0584 lea bx, [0x6ad]
  PUSH(0x058b); goto L_0354;                                   // 0588 call 0x354
L_058b:   R.bx = (u16)((u16)(0x6bf));                                  // 058b lea bx, [0x6bf]
  PUSH(0x0592); goto L_035d;                                   // 058f call 0x35d
L_0592:   R.bx = (u16)((u16)(0x6d3));                                  // 0592 lea bx, [0x6d3]
  PUSH(0x0599); goto L_0366;                                   // 0596 call 0x366
L_0599:   R.bx = (u16)((u16)(0x6df));                                  // 0599 lea bx, [0x6df]
  goto L_036f;                                                 // 059d jmp 0x36f
L_05a0:   SETL(R.bx, 0xc9);                                            // 05a0 mov bl, 0xc9
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 05a2 cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_05df;                                       // 05a6 je 0x5df
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 05a8 mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x156b));                                 // 05ac lea bx, [0x156b]
  PUSH(0x05b3); goto L_0354;                                   // 05b0 call 0x354
L_05b3:   R.bx = (u16)((u16)(0x156b));                                 // 05b3 lea bx, [0x156b]
  PUSH(0x05ba); goto L_035d;                                   // 05b7 call 0x35d
L_05ba:   R.bx = (u16)((u16)(0x156b));                                 // 05ba lea bx, [0x156b]
  PUSH(0x05c1); goto L_0366;                                   // 05be call 0x366
L_05c1:   R.bx = (u16)((u16)(0x131));                                  // 05c1 lea bx, [0x131]
L_05c5:   R.ax = (u16)(M16(CS, (u16)(0xe1)));                          // 05c5 mov ax, word ptr cs:[0xe1]
  R.ax = (u16)(AND16(R.ax, 0xe));                              // 05c9 and ax, 0xe
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 05cc add bx, ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 05ce mov ax, word ptr [bx]
  W16(DS, (u16)(0x60), R.ax);                                  // 05d0 mov word ptr [0x60], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x2)));                    // 05d3 mov ax, word ptr [bx + 2]
  W16(DS, (u16)(0x7d), R.ax);                                  // 05d6 mov word ptr [0x7d], ax
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 05d9 mov ax, word ptr [bx + 4]
  W16(DS, (u16)(0x9a), R.ax);                                  // 05dc mov word ptr [0x9a], ax
L_05df:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 05df ret
L_05e0:   SETL(R.bx, 0x99);                                            // 05e0 mov bl, 0x99
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 05e2 cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_05df;                                       // 05e6 je 0x5df
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 05e8 mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x17d2));                                 // 05ec lea bx, [0x17d2]
  PUSH(0x05f3); goto L_0354;                                   // 05f0 call 0x354
L_05f3:   R.bx = (u16)((u16)(0x17f4));                                 // 05f3 lea bx, [0x17f4]
  PUSH(0x05fa); goto L_035d;                                   // 05f7 call 0x35d
L_05fa:   R.bx = (u16)((u16)(0x1816));                                 // 05fa lea bx, [0x1816]
  goto L_0366;                                                 // 05fe jmp 0x366
L_0601:   SETL(R.bx, 0x45);                                            // 0601 mov bl, 0x45
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 0603 cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_05df;                                       // 0607 je 0x5df
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 0609 mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x1826));                                 // 060d lea bx, [0x1826]
  PUSH(0x0614); goto L_0354;                                   // 0611 call 0x354
L_0614:   R.bx = (u16)((u16)(0x183f));                                 // 0614 lea bx, [0x183f]
  PUSH(0x061b); goto L_035d;                                   // 0618 call 0x35d
L_061b:   R.bx = (u16)((u16)(0x1855));                                 // 061b lea bx, [0x1855]
  goto L_0366;                                                 // 061f jmp 0x366
L_0622:   SETL(R.bx, 0x4);                                             // 0622 mov bl, 4
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 0624 cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_05df;                                       // 0628 je 0x5df
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 062a mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x185e));                                 // 062e lea bx, [0x185e]
  PUSH(0x0635); goto L_0354;                                   // 0632 call 0x354
L_0635:   R.bx = (u16)((u16)(0x187a));                                 // 0635 lea bx, [0x187a]
  PUSH(0x063c); goto L_035d;                                   // 0639 call 0x35d
L_063c:   R.bx = (u16)((u16)(0x1890));                                 // 063c lea bx, [0x1890]
  goto L_0366;                                                 // 0640 jmp 0x366
L_0643:   SETL(R.bx, 0xe0);                                            // 0643 mov bl, 0xe0
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 0645 cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_05df;                                       // 0649 je 0x5df
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 064b mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x189b));                                 // 064f lea bx, [0x189b]
  PUSH(0x0656); goto L_0354;                                   // 0653 call 0x354
L_0656:   R.bx = (u16)((u16)(0x18c6));                                 // 0656 lea bx, [0x18c6]
  PUSH(0x065d); goto L_035d;                                   // 065a call 0x35d
L_065d:   R.bx = (u16)((u16)(0x18d5));                                 // 065d lea bx, [0x18d5]
  goto L_0366;                                                 // 0661 jmp 0x366
L_0664:   SETL(R.bx, 0x7b);                                            // 0664 mov bl, 0x7b
  SUB8((u8)R.bx, M8(DS, (u16)(0xc8)));                         // 0666 cmp bl, byte ptr [0xc8]
  if (R.zf) goto L_06b4;                                       // 066a je 0x6b4
  W8(DS, (u16)(0xc8), (u8)R.bx);                               // 066c mov byte ptr [0xc8], bl
  R.bx = (u16)((u16)(0x156b));                                 // 0670 lea bx, [0x156b]
  PUSH(0x0677); goto L_0354;                                   // 0674 call 0x354
L_0677:   R.bx = (u16)((u16)(0x1528));                                 // 0677 lea bx, [0x1528]
  PUSH(0x067e); goto L_035d;                                   // 067b call 0x35d
L_067e:   R.bx = (u16)((u16)(0x1531));                                 // 067e lea bx, [0x1531]
  PUSH(0x0685); goto L_0366;                                   // 0682 call 0x366
L_0685:   R.bx = (u16)((u16)(0x11d));                                  // 0685 lea bx, [0x11d]
  goto L_05c5;                                                 // 0689 jmp 0x5c5
L_068c:   PUSH(0x068f); goto L_06b5;                                   // 068c call 0x6b5
L_068f:   R.ax = (u16)((u16)(0x1527));                                 // 068f lea ax, [0x1527]
  R.bx = (u16)(R.ax);                                          // 0693 mov bx, ax
  R.cx = (u16)(R.ax);                                          // 0695 mov cx, ax
  goto L_06a9;                                                 // 0697 jmp 0x6a9
L_069a:   PUSH(0x069d); goto L_06b5;                                   // 069a call 0x6b5
L_069d:   R.ax = (u16)((u16)(0x2c7));                                  // 069d lea ax, [0x2c7]
  R.bx = (u16)((u16)(0x3d2));                                  // 06a1 lea bx, [0x3d2]
  R.cx = (u16)((u16)(0x4de));                                  // 06a5 lea cx, [0x4de]
L_06a9:   W16(DS, (u16)(0x63), R.ax);                                  // 06a9 mov word ptr [0x63], ax
  W16(DS, (u16)(0x80), R.bx);                                  // 06ac mov word ptr [0x80], bx
  W16(DS, (u16)(0x9d), R.cx);                                  // 06b0 mov word ptr [0x9d], cx
L_06b4:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 06b4 ret
L_06b5:   R.bx = (u16)((u16)(0x2ab));                                  // 06b5 lea bx, [0x2ab]
  PUSH(0x06bc); goto L_0354;                                   // 06b9 call 0x354
L_06bc:   R.bx = (u16)((u16)(0x37c));                                  // 06bc lea bx, [0x37c]
  PUSH(0x06c3); goto L_035d;                                   // 06c0 call 0x35d
L_06c3:   R.bx = (u16)((u16)(0x4c7));                                  // 06c3 lea bx, [0x4c7]
  goto L_0366;                                                 // 06c7 jmp 0x366
L_06ca:   R.bx = (u16)((u16)(0x53e));                                  // 06ca lea bx, [0x53e]
  PUSH(0x06d1); goto L_0354;                                   // 06ce call 0x354
L_06d1:   R.bx = (u16)((u16)(0x5bb));                                  // 06d1 lea bx, [0x5bb]
  PUSH(0x06d8); goto L_035d;                                   // 06d5 call 0x35d
L_06d8:   R.bx = (u16)((u16)(0x635));                                  // 06d8 lea bx, [0x635]
  goto L_0366;                                                 // 06dc jmp 0x366
L_06df:   R.bx = (u16)((u16)(0x18e9));                                 // 06df lea bx, [0x18e9]
  PUSH(0x06e6); goto L_0354;                                   // 06e3 call 0x354
L_06e6:   R.bx = (u16)((u16)(0x1937));                                 // 06e6 lea bx, [0x1937]
  PUSH(0x06ed); goto L_035d;                                   // 06ea call 0x35d
L_06ed:   R.bx = (u16)((u16)(0x19dd));                                 // 06ed lea bx, [0x19dd]
  goto L_0366;                                                 // 06f1 jmp 0x366
L_06f4:   R.bx = (u16)((u16)(0x6f1));                                  // 06f4 lea bx, [0x6f1]
  PUSH(0x06fb); goto L_0354;                                   // 06f8 call 0x354
L_06fb:   R.bx = (u16)((u16)(0x7fe));                                  // 06fb lea bx, [0x7fe]
  PUSH(0x0702); goto L_036f;                                   // 06ff call 0x36f
L_0702:   R.bx = (u16)((u16)(0x7af));                                  // 0702 lea bx, [0x7af]
  goto L_0366;                                                 // 0706 jmp 0x366
L_0709:   R.ax = (u16)(M16(DS, (u16)(0xc4)));                          // 0709 mov ax, word ptr [0xc4]
  SUB16(R.ax, M16(DS, (u16)(0xc6)));                           // 070c cmp ax, word ptr [0xc6]
  if (R.zf) goto L_06b4;                                       // 0710 je 0x6b4
  W16(DS, (u16)(0xc6), R.ax);                                  // 0712 mov word ptr [0xc6], ax
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0715 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0717 shl ax, 1
  R.bx = (u16)(M16(DS, (u16)(0xd3)));                          // 0719 mov bx, word ptr [0xd3]
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 071d add bx, ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 071f mov ax, word ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 0721 inc bx
  R.bx = (u16)(INC16(R.bx));                                   // 0722 inc bx
  R.cx = (u16)(M16(DS, (u16)(R.bx)));                          // 0723 mov cx, word ptr [bx]
  SETL(R.bx, M8(DS, (u16)(0xca)));                             // 0725 mov bl, byte ptr [0xca]
  PUSH(R.bx);                                                  // 0729 push bx
  PUSH(0x072d); goto L_03e0;                                   // 072a call 0x3e0
L_072d:   R.bx = (u16)((u16)(0x50));                                   // 072d lea bx, [0x50]
  PUSH(0x0734); goto L_0550;                                   // 0731 call 0x550
L_0734:   R.ax = (u16)(R.cx);                                          // 0734 mov ax, cx
  R.bx = (u16)((u16)(0x6d));                                   // 0736 lea bx, [0x6d]
  PUSH(0x073d); goto L_0550;                                   // 073a call 0x550
L_073d:   R.bx = POP();                                                // 073d pop bx
  W8(DS, (u16)(0xca), (u8)R.bx);                               // 073e mov byte ptr [0xca], bl
  SUB16(M16(DS, (u16)(0xc4)), 0x0);                            // 0742 cmp word ptr [0xc4], 0
  if (R.zf) goto L_0751;                                       // 0747 je 0x751
  SUB16(M16(DS, (u16)(0xc4)), 0x5);                            // 0749 cmp word ptr [0xc4], 5
  if (R.zf) goto L_0751;                                       // 074e je 0x751
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0750 ret
L_0751:   SETL(R.ax, M8(DS, (u16)(0x6c)));                             // 0751 mov al, byte ptr [0x6c]
  SETL(R.ax, OR8((u8)R.ax, M8(DS, (u16)(0x89))));              // 0754 or al, byte ptr [0x89]
  SUB8((u8)R.ax, 0x0);                                         // 0758 cmp al, 0
  if (!R.zf) { asm_idle(); goto L_0751; }  /* a wait for the tick */ // 075a jne 0x751
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 075c ret
L_075d:   R.bx = (u16)((u16)(0xa7d));                                  // 075d lea bx, [0xa7d]
  PUSH(0x0764); goto L_0354;                                   // 0761 call 0x354
L_0764:   R.bx = (u16)((u16)(0xad8));                                  // 0764 lea bx, [0xad8]
  PUSH(0x076b); goto L_035d;                                   // 0768 call 0x35d
L_076b:   R.bx = (u16)((u16)(0xb0f));                                  // 076b lea bx, [0xb0f]
  goto L_0366;                                                 // 076f jmp 0x366
L_0772:   R.bx = (u16)((u16)(0x81a));                                  // 0772 lea bx, [0x81a]
  PUSH(0x0779); goto L_0354;                                   // 0776 call 0x354
L_0779:   R.bx = (u16)((u16)(0x878));                                  // 0779 lea bx, [0x878]
  PUSH(0x0780); goto L_035d;                                   // 077d call 0x35d
L_0780:   R.bx = (u16)((u16)(0x8d6));                                  // 0780 lea bx, [0x8d6]
  goto L_0366;                                                 // 0784 jmp 0x366
L_0787:   R.bx = (u16)((u16)(0x91b));                                  // 0787 lea bx, [0x91b]
  PUSH(0x078e); goto L_0354;                                   // 078b call 0x354
L_078e:   R.bx = (u16)((u16)(0x982));                                  // 078e lea bx, [0x982]
  PUSH(0x0795); goto L_035d;                                   // 0792 call 0x35d
L_0795:   R.bx = (u16)((u16)(0x9d1));                                  // 0795 lea bx, [0x9d1]
  goto L_0366;                                                 // 0799 jmp 0x366
L_079c:   R.bx = (u16)((u16)(0xb2c));                                  // 079c lea bx, [0xb2c]
  PUSH(0x07a3); goto L_0354;                                   // 07a0 call 0x354
L_07a3:   R.bx = (u16)((u16)(0xbf7));                                  // 07a3 lea bx, [0xbf7]
  PUSH(0x07aa); goto L_035d;                                   // 07a7 call 0x35d
L_07aa:   R.bx = (u16)((u16)(0xcba));                                  // 07aa lea bx, [0xcba]
  goto L_0366;                                                 // 07ae jmp 0x366
L_07b1:   R.bx = (u16)((u16)(0x163b));                                 // 07b1 lea bx, [0x163b]
  PUSH(0x07b8); goto L_0354;                                   // 07b5 call 0x354
L_07b8:   R.bx = (u16)((u16)(0x1688));                                 // 07b8 lea bx, [0x1688]
  goto L_035d;                                                 // 07bc jmp 0x35d
L_07bf:   R.ax = (u16)((u16)(0xd5));                                   // 07bf lea ax, [0xd5]
  R.bx = (u16)((u16)(0xe65));                                  // 07c3 lea bx, [0xe65]
  R.cx = (u16)((u16)(0xe9e));                                  // 07c7 lea cx, [0xe9e]
  goto L_07e9;                                                 // 07cb jmp 0x7e9
L_07ce:   R.ax = (u16)((u16)(0xed));                                   // 07ce lea ax, [0xed]
  R.bx = (u16)((u16)(0x105e));                                 // 07d2 lea bx, [0x105e]
  R.cx = (u16)((u16)(0x1085));                                 // 07d6 lea cx, [0x1085]
  goto L_07e9;                                                 // 07da jmp 0x7e9
L_07dd:   R.ax = (u16)((u16)(0x105));                                  // 07dd lea ax, [0x105]
  R.bx = (u16)((u16)(0x128e));                                 // 07e1 lea bx, [0x128e]
  R.cx = (u16)((u16)(0x129e));                                 // 07e5 lea cx, [0x129e]
L_07e9:   W16(DS, (u16)(0xd3), R.ax);                                  // 07e9 mov word ptr [0xd3], ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07ec xor ax, ax
  W16(DS, (u16)(0xc4), R.ax);                                  // 07ee mov word ptr [0xc4], ax
  W16(DS, (u16)(0xc6), R.ax);                                  // 07f1 mov word ptr [0xc6], ax
  PUSH(R.cx);                                                  // 07f4 push cx
  PUSH(0x07f8); goto L_0354;                                   // 07f5 call 0x354
L_07f8:   R.bx = POP();                                                // 07f8 pop bx
  goto L_035d;                                                 // 07f9 jmp 0x35d
}

// the driver's slots: slot 0 + k runs the k-th entry, with the caller's far return address on the stack
void ts_slot(int slot)
{
  static const u16 entries[] = { 0x0098, 0x00c4, 0x00e3, 0x00e0, 0x00f6, 0x00c1, 0x00c3 };
  if (slot >= 0 && slot < 7) ts_0000_run(entries[slot - 0]);
}
