#include "asm2c.h"

// RS: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void rs_0000_run(u16 entry);

void rs_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0xd000;
dispatch_:
  switch (ip_)
  {
  case 0x004d: goto L_004d;
  case 0x005e: goto L_005e;
  case 0x006d: goto L_006d;
  case 0x0076: goto L_0076;
  case 0x0079: goto L_0079;
  case 0x0094: goto L_0094;
  case 0x00a9: goto L_00a9;
  case 0x00ff: goto L_00ff;
  case 0x011e: goto L_011e;
  case 0x0143: goto L_0143;
  case 0x014d: goto L_014d;
  case 0x0150: goto L_0150;
  case 0x0157: goto L_0157;
  case 0x015e: goto L_015e;
  case 0x0165: goto L_0165;
  case 0x016c: goto L_016c;
  case 0x0173: goto L_0173;
  case 0x017a: goto L_017a;
  case 0x0181: goto L_0181;
  case 0x0188: goto L_0188;
  case 0x018f: goto L_018f;
  case 0x0196: goto L_0196;
  case 0x019d: goto L_019d;
  case 0x01a4: goto L_01a4;
  case 0x01ab: goto L_01ab;
  case 0x01b2: goto L_01b2;
  case 0x01b9: goto L_01b9;
  case 0x01c0: goto L_01c0;
  case 0x01c7: goto L_01c7;
  case 0x01ce: goto L_01ce;
  case 0x01d5: goto L_01d5;
  case 0x01dc: goto L_01dc;
  case 0x01e1: goto L_01e1;
  case 0x01e2: goto L_01e2;
  case 0x01e9: goto L_01e9;
  case 0x01f3: goto L_01f3;
  case 0x01f6: goto L_01f6;
  case 0x01fe: goto L_01fe;
  case 0x0208: goto L_0208;
  case 0x020b: goto L_020b;
  case 0x021b: goto L_021b;
  case 0x0220: goto L_0220;
  case 0x0224: goto L_0224;
  case 0x0227: goto L_0227;
  case 0x0231: goto L_0231;
  case 0x023c: goto L_023c;
  case 0x0246: goto L_0246;
  case 0x0251: goto L_0251;
  case 0x0254: goto L_0254;
  case 0x0255: goto L_0255;
  case 0x025f: goto L_025f;
  case 0x0269: goto L_0269;
  case 0x0274: goto L_0274;
  case 0x027e: goto L_027e;
  case 0x0286: goto L_0286;
  case 0x0290: goto L_0290;
  case 0x0292: goto L_0292;
  case 0x0294: goto L_0294;
  case 0x02a1: goto L_02a1;
  case 0x02a8: goto L_02a8;
  case 0x02bb: goto L_02bb;
  case 0x02be: goto L_02be;
  case 0x02d1: goto L_02d1;
  case 0x02e0: goto L_02e0;
  case 0x02f2: goto L_02f2;
  case 0x036f: goto L_036f;
  case 0x0389: goto L_0389;
  case 0x0398: goto L_0398;
  case 0x03a5: goto L_03a5;
  case 0x03b2: goto L_03b2;
  case 0x03bd: goto L_03bd;
  case 0x03c8: goto L_03c8;
  case 0x03d3: goto L_03d3;
  case 0x03de: goto L_03de;
  case 0x03e9: goto L_03e9;
  case 0x03f6: goto L_03f6;
  case 0x0401: goto L_0401;
  case 0x040e: goto L_040e;
  case 0x0419: goto L_0419;
  case 0x0424: goto L_0424;
  case 0x0431: goto L_0431;
  case 0x043c: goto L_043c;
  case 0x0447: goto L_0447;
  case 0x0454: goto L_0454;
  case 0x045f: goto L_045f;
  case 0x046a: goto L_046a;
  case 0x0477: goto L_0477;
  case 0x0482: goto L_0482;
  case 0x048d: goto L_048d;
  case 0x049a: goto L_049a;
  case 0x04a5: goto L_04a5;
  case 0x04b0: goto L_04b0;
  case 0x04bd: goto L_04bd;
  case 0x04c8: goto L_04c8;
  case 0x04d3: goto L_04d3;
  case 0x04e0: goto L_04e0;
  case 0x04eb: goto L_04eb;
  case 0x04f6: goto L_04f6;
  case 0x0503: goto L_0503;
  case 0x050e: goto L_050e;
  case 0x051b: goto L_051b;
  case 0x0526: goto L_0526;
  case 0x0531: goto L_0531;
  case 0x053e: goto L_053e;
  case 0x0549: goto L_0549;
  case 0x0554: goto L_0554;
  case 0x0561: goto L_0561;
  case 0x056c: goto L_056c;
  case 0x0573: goto L_0573;
  case 0x0580: goto L_0580;
  case 0x058b: goto L_058b;
  case 0x0592: goto L_0592;
  case 0x059f: goto L_059f;
  case 0x05aa: goto L_05aa;
  case 0x05ae: goto L_05ae;
  case 0x05ba: goto L_05ba;
  case 0x05ca: goto L_05ca;
  case 0x05d7: goto L_05d7;
  case 0x05e2: goto L_05e2;
  case 0x05e3: goto L_05e3;
  case 0x05fd: goto L_05fd;
  case 0x0608: goto L_0608;
  case 0x0613: goto L_0613;
  case 0x0614: goto L_0614;
  case 0x0624: goto L_0624;
  case 0x0631: goto L_0631;
  case 0x063c: goto L_063c;
  case 0x0647: goto L_0647;
  case 0x0648: goto L_0648;
  case 0x0658: goto L_0658;
  case 0x0665: goto L_0665;
  case 0x0670: goto L_0670;
  case 0x067b: goto L_067b;
  case 0x067c: goto L_067c;
  case 0x068c: goto L_068c;
  case 0x0699: goto L_0699;
  case 0x06a4: goto L_06a4;
  case 0x06af: goto L_06af;
  case 0x06b0: goto L_06b0;
  case 0x06c0: goto L_06c0;
  case 0x06cd: goto L_06cd;
  case 0x06d8: goto L_06d8;
  case 0x06e3: goto L_06e3;
  case 0x06e4: goto L_06e4;
  case 0x06f1: goto L_06f1;
  case 0x06fc: goto L_06fc;
  case 0x0707: goto L_0707;
  case 0x070a: goto L_070a;
  case 0x0713: goto L_0713;
  case 0x0716: goto L_0716;
  case 0x0724: goto L_0724;
  case 0x073c: goto L_073c;
  case 0x0749: goto L_0749;
  case 0x0756: goto L_0756;
  case 0x0763: goto L_0763;
  case 0x0770: goto L_0770;
  case 0x077d: goto L_077d;
  case 0x0787: goto L_0787;
  case 0x0797: goto L_0797;
  case 0x07a1: goto L_07a1;
  case 0x07b1: goto L_07b1;
  case 0x07be: goto L_07be;
  case 0x07cb: goto L_07cb;
  case 0x07d8: goto L_07d8;
  case 0x07e5: goto L_07e5;
  case 0x07f2: goto L_07f2;
  case 0x07ff: goto L_07ff;
  case 0x080e: goto L_080e;
  case 0x081a: goto L_081a;
  case 0x0826: goto L_0826;
  case 0x0832: goto L_0832;
  case 0x084c: goto L_084c;
  case 0x0857: goto L_0857;
  case 0x0862: goto L_0862;
  case 0x0863: goto L_0863;
  case 0x0879: goto L_0879;
  case 0x087c: goto L_087c;
  case 0x087f: goto L_087f;
  case 0x0888: goto L_0888;
  case 0x088d: goto L_088d;
  case 0x0892: goto L_0892;
  case 0x0897: goto L_0897;
  case 0x089c: goto L_089c;
  case 0x08a6: goto L_08a6;
  case 0x0905: goto L_0905;
  case 0x0910: goto L_0910;
  case 0x0914: goto L_0914;
  case 0x092d: goto L_092d;
  case 0x092e: goto L_092e;
  case 0x0930: goto L_0930;
  case 0x0939: goto L_0939;
  case 0x0944: goto L_0944;
  case 0x0945: goto L_0945;
  case 0x095d: goto L_095d;
  case 0x095e: goto L_095e;
  case 0x0960: goto L_0960;
  case 0x096d: goto L_096d;
  case 0x099f: goto L_099f;
  case 0x09a8: goto L_09a8;
  case 0x09b8: goto L_09b8;
  case 0x09c3: goto L_09c3;
  case 0x09c4: goto L_09c4;
  case 0x09d0: goto L_09d0;
  case 0x09d3: goto L_09d3;
  case 0x09dd: goto L_09dd;
  case 0x09e0: goto L_09e0;
  case 0x09e3: goto L_09e3;
  case 0x09e8: goto L_09e8;
  case 0x09f3: goto L_09f3;
  case 0x09f8: goto L_09f8;
  case 0x0a10: goto L_0a10;
  case 0x0a31: goto L_0a31;
  case 0x0a3a: goto L_0a3a;
  case 0x0a4f: goto L_0a4f;
  case 0x0a5a: goto L_0a5a;
  case 0x0a6a: goto L_0a6a;
  case 0x0a6c: goto L_0a6c;
  case 0x0a90: goto L_0a90;
  case 0x0a99: goto L_0a99;
  case 0x0aa5: goto L_0aa5;
  case 0x0ab4: goto L_0ab4;
  case 0x0ac8: goto L_0ac8;
  case 0x0aec: goto L_0aec;
  case 0x0af5: goto L_0af5;
  case 0x0b01: goto L_0b01;
  case 0x0b06: goto L_0b06;
  case 0x0b2a: goto L_0b2a;
  case 0x0b33: goto L_0b33;
  case 0x0b3c: goto L_0b3c;
  case 0x0b4b: goto L_0b4b;
  case 0x0b50: goto L_0b50;
  case 0x0b74: goto L_0b74;
  case 0x0b7d: goto L_0b7d;
  case 0x0b85: goto L_0b85;
  case 0x0b94: goto L_0b94;
  case 0x0b9a: goto L_0b9a;
  case 0x0bb0: goto L_0bb0;
  case 0x0bcc: goto L_0bcc;
  case 0x0bdb: goto L_0bdb;
  case 0x0bf1: goto L_0bf1;
  case 0x0bfc: goto L_0bfc;
  case 0x0c06: goto L_0c06;
  case 0x0c12: goto L_0c12;
  case 0x0c3a: goto L_0c3a;
  case 0x0c52: goto L_0c52;
  case 0x0c54: goto L_0c54;
  case 0x0c78: goto L_0c78;
  case 0x0c84: goto L_0c84;
  case 0x0c88: goto L_0c88;
  case 0x0c94: goto L_0c94;
  case 0x0cc4: goto L_0cc4;
  case 0x0cdc: goto L_0cdc;
  case 0x0ce0: goto L_0ce0;
  case 0x0d10: goto L_0d10;
  case 0x0d1c: goto L_0d1c;
  case 0x0d20: goto L_0d20;
  case 0x0d38: goto L_0d38;
  case 0x0d3e: goto L_0d3e;
  case 0x0d42: goto L_0d42;
  case 0x0d61: goto L_0d61;
  case 0x0d68: goto L_0d68;
  case 0x0d80: goto L_0d80;
  case 0x0dbc: goto L_0dbc;
  case 0x0dd4: goto L_0dd4;
  case 0x0e02: goto L_0e02;
  case 0x0e21: goto L_0e21;
  case 0x0e28: goto L_0e28;
  case 0x0e47: goto L_0e47;
  case 0x0e4e: goto L_0e4e;
  case 0x0e5b: goto L_0e5b;
  case 0x0e63: goto L_0e63;
  case 0x0e6b: goto L_0e6b;
  case 0x0e73: goto L_0e73;
  case 0x0e7b: goto L_0e7b;
  case 0x0e83: goto L_0e83;
  case 0x0e8b: goto L_0e8b;
  case 0x0e93: goto L_0e93;
  case 0x0e9b: goto L_0e9b;
  case 0x0e9e: goto L_0e9e;
  case 0x0ede: goto L_0ede;
  case 0x0ee1: goto L_0ee1;
  case 0x0ee4: goto L_0ee4;
  case 0x0f18: goto L_0f18;
  case 0x0f1b: goto L_0f1b;
  case 0x0f57: goto L_0f57;
  case 0x0f5a: goto L_0f5a;
  case 0x0f66: goto L_0f66;
  case 0x0f99: goto L_0f99;
  case 0x0f9c: goto L_0f9c;
  case 0x0fb0: goto L_0fb0;
  case 0x0fba: goto L_0fba;
  case 0x0fc4: goto L_0fc4;
  case 0x0fd0: goto L_0fd0;
  case 0x0fda: goto L_0fda;
  case 0x0fe4: goto L_0fe4;
  case 0x0fee: goto L_0fee;
  case 0x0ff8: goto L_0ff8;
  case 0x1002: goto L_1002;
  case 0x1005: goto L_1005;
  default: asm_unknown_call(0xd000, ip_); return;
  }
L_004d:   PUSH(R.cx);                                                  // 004d push cx
  // 004e cli 
  SETL(R.ax, 0x0);                                             // 004f mov al, 0
  ASM_PORT_OUT(0x43, (u8)R.ax);                                // 0051 out 0x43, al
  SETL(R.ax, ASM_PORT_IN(0x40));                               // 0053 in al, 0x40
  SETL(R.bx, (u8)R.ax);                                        // 0055 mov bl, al
  SETL(R.ax, ASM_PORT_IN(0x40));                               // 0057 in al, 0x40
  SETH(R.bx, (u8)R.ax);                                        // 0059 mov bh, al
  R.cx = (u16)(0x100);                                         // 005b mov cx, 0x100
L_005e:   if (--R.cx != 0) goto L_005e;                                // 005e loop 0x5e
  SETL(R.ax, ASM_PORT_IN(0x40));                               // 0060 in al, 0x40
  SETL(R.dx, (u8)R.ax);                                        // 0062 mov dl, al
  SETL(R.ax, ASM_PORT_IN(0x40));                               // 0064 in al, 0x40
  SETH(R.dx, (u8)R.ax);                                        // 0066 mov dh, al
  // 0068 sti 
  R.bx = (u16)(SUB16(R.bx, R.dx));                             // 0069 sub bx, dx
  R.cx = POP();                                                // 006b pop cx
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 006c ret
L_006d:   W16(DS, (u16)(0x158a), 0x0);                                 // 006d mov word ptr [0x158a], 0
  R.cx = (u16)(0x10);                                          // 0073 mov cx, 0x10
L_0076:   PUSH(0x0079); goto L_004d;                                   // 0076 call 0x4d
L_0079:   W16(DS, (u16)(0x158a), ADD16(M16(DS, (u16)(0x158a)), R.bx)); // 0079 add word ptr [0x158a], bx
  if (--R.cx != 0) goto L_0076;                                // 007d loop 0x76
  R.bx = (u16)(M16(DS, (u16)(0x158a)));                        // 007f mov bx, word ptr [0x158a]
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0083 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0085 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0087 shr bx, 1
  R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0089 shr bx, 1
  SUB16(R.bx, 0xa28);                                          // 008b cmp bx, 0xa28
  if (R.zf || R.sf != R.of) goto L_0094;                       // 008f jle 0x94
  R.bx = (u16)(0xa28);                                         // 0091 mov bx, 0xa28
L_0094:   R.dx = (u16)(0x0);                                           // 0094 mov dx, 0
  R.ax = (u16)(0x5140);                                        // 0097 mov ax, 0x5140
  DIV16(R.bx, 0x009a);                                         // 009a div bx
  R.ax = (u16)(INC16(R.ax));                                   // 009c inc ax
  SETH(R.ax, (u8)R.ax);                                        // 009d mov ah, al
  SETL(R.ax, 0x0);                                             // 009f mov al, 0
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 00a1 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 00a3 shl ax, 1
  W16(DS, (u16)(0x158c), R.ax);                                // 00a5 mov word ptr [0x158c], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 00a8 ret
L_00a9:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 00a9 xor ax, ax
  W8(DS, (u16)(0x2760), (u8)R.ax);                             // 00ab mov byte ptr [0x2760], al
  R.bx = (u16)((u16)(0x2762));                                 // 00ae lea bx, [0x2762]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00b2 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00b4 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00b7 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x2780));                                 // 00ba lea bx, [0x2780]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00be mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00c0 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00c3 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x279e));                                 // 00c6 lea bx, [0x279e]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00ca mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00cc mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00cf mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x27bc));                                 // 00d2 lea bx, [0x27bc]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00d6 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00d8 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00db mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x27da));                                 // 00de lea bx, [0x27da]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00e2 mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00e4 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00e7 mov byte ptr [bx + 2], al
  R.bx = (u16)((u16)(0x27f8));                                 // 00ea lea bx, [0x27f8]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 00ee mov byte ptr [bx], al
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 00f0 mov byte ptr [bx + 1], al
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 00f3 mov byte ptr [bx + 2], al
  W8(DS, (u16)(0x2760), 0xff);                                 // 00f6 mov byte ptr [0x2760], 0xff
  W16(DS, (u16)(0x1597), R.ax);                                // 00fb mov word ptr [0x1597], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 00fe ret
L_00ff:   PUSH(R.es);                                                  // 00ff push es
  PUSH(R.si);                                                  // 0100 push si
  PUSH(R.di);                                                  // 0101 push di
  PUSH(R.bp);                                                  // 0102 push bp
  W16(CS, (u16)(0x49), R.ss);                                  // 0103 mov word ptr cs:[0x49], ss
  W16(CS, (u16)(0x4b), R.sp);                                  // 0108 mov word ptr cs:[0x4b], sp
  R.ax = (u16)(0xd101 /* segment */);                          // 010d mov ax, 0x101
  R.es = (u16)(R.ax);                                          // 0110 mov es, ax
  R.ss = (u16)(R.ax);                                          // 0112 mov ss, ax
  R.sp = (u16)(0x157e);                                        // 0114 mov sp, 0x157e
  W16(DS, (u16)(0x1586), INC16(M16(DS, (u16)(0x1586))));       // 0117 inc word ptr [0x1586]
  PUSH(0x011e); goto L_0fba;                                   // 011b call 0xfba
L_011e:   R.bx = (u16)(M16(CS, (u16)(0x49)));                          // 011e mov bx, word ptr cs:[0x49]
  R.ss = (u16)(R.bx);                                          // 0123 mov ss, bx
  R.sp = (u16)(M16(CS, (u16)(0x4b)));                          // 0125 mov sp, word ptr cs:[0x4b]
  R.bp = POP();                                                // 012a pop bp
  R.di = POP();                                                // 012b pop di
  R.si = POP();                                                // 012c pop si
  R.es = POP();                                                // 012d pop es
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 012e ret
L_0143:   SUB8(M8(DS, (u16)(0x1580)), 0x0);                            // 0143 cmp byte ptr [0x1580], 0
  if (R.zf) goto L_014d;                                       // 0148 je 0x14d
  goto L_01e1;                                                 // 014a jmp 0x1e1
L_014d:   PUSH(0x0150); goto L_0879;                                   // 014d call 0x879
L_0150:   R.ax = (u16)((u16)(0x15e7));                                 // 0150 lea ax, [0x15e7]
  PUSH(0x0157); goto L_01e2;                                   // 0154 call 0x1e2
L_0157:   R.ax = (u16)((u16)(0x15ff));                                 // 0157 lea ax, [0x15ff]
  PUSH(0x015e); goto L_01e2;                                   // 015b call 0x1e2
L_015e:   R.ax = (u16)((u16)(0x161a));                                 // 015e lea ax, [0x161a]
  PUSH(0x0165); goto L_01e2;                                   // 0162 call 0x1e2
L_0165:   R.ax = (u16)((u16)(0x16be));                                 // 0165 lea ax, [0x16be]
  PUSH(0x016c); goto L_01e2;                                   // 0169 call 0x1e2
L_016c:   R.ax = (u16)((u16)(0x17b8));                                 // 016c lea ax, [0x17b8]
  PUSH(0x0173); goto L_01e2;                                   // 0170 call 0x1e2
L_0173:   R.ax = (u16)((u16)(0x18b2));                                 // 0173 lea ax, [0x18b2]
  PUSH(0x017a); goto L_01e2;                                   // 0177 call 0x1e2
L_017a:   R.ax = (u16)((u16)(0x19ac));                                 // 017a lea ax, [0x19ac]
  PUSH(0x0181); goto L_01e2;                                   // 017e call 0x1e2
L_0181:   R.ax = (u16)((u16)(0x1aa6));                                 // 0181 lea ax, [0x1aa6]
  PUSH(0x0188); goto L_01e2;                                   // 0185 call 0x1e2
L_0188:   R.ax = (u16)((u16)(0x1ba0));                                 // 0188 lea ax, [0x1ba0]
  PUSH(0x018f); goto L_01e2;                                   // 018c call 0x1e2
L_018f:   R.ax = (u16)((u16)(0x1c9a));                                 // 018f lea ax, [0x1c9a]
  PUSH(0x0196); goto L_01e2;                                   // 0193 call 0x1e2
L_0196:   R.ax = (u16)((u16)(0x1d94));                                 // 0196 lea ax, [0x1d94]
  PUSH(0x019d); goto L_01e2;                                   // 019a call 0x1e2
L_019d:   R.ax = (u16)((u16)(0x1e8e));                                 // 019d lea ax, [0x1e8e]
  PUSH(0x01a4); goto L_01e2;                                   // 01a1 call 0x1e2
L_01a4:   R.ax = (u16)((u16)(0x1f88));                                 // 01a4 lea ax, [0x1f88]
  PUSH(0x01ab); goto L_01e2;                                   // 01a8 call 0x1e2
L_01ab:   R.ax = (u16)((u16)(0x2082));                                 // 01ab lea ax, [0x2082]
  PUSH(0x01b2); goto L_01e2;                                   // 01af call 0x1e2
L_01b2:   R.ax = (u16)((u16)(0x217c));                                 // 01b2 lea ax, [0x217c]
  PUSH(0x01b9); goto L_01e2;                                   // 01b6 call 0x1e2
L_01b9:   R.ax = (u16)((u16)(0x2370));                                 // 01b9 lea ax, [0x2370]
  PUSH(0x01c0); goto L_01e2;                                   // 01bd call 0x1e2
L_01c0:   R.ax = (u16)((u16)(0x2276));                                 // 01c0 lea ax, [0x2276]
  PUSH(0x01c7); goto L_01e2;                                   // 01c4 call 0x1e2
L_01c7:   R.ax = (u16)((u16)(0x246a));                                 // 01c7 lea ax, [0x246a]
  PUSH(0x01ce); goto L_01e2;                                   // 01cb call 0x1e2
L_01ce:   R.ax = (u16)((u16)(0x2564));                                 // 01ce lea ax, [0x2564]
  PUSH(0x01d5); goto L_01e2;                                   // 01d2 call 0x1e2
L_01d5:   R.ax = (u16)((u16)(0x265e));                                 // 01d5 lea ax, [0x265e]
  PUSH(0x01dc); goto L_01e2;                                   // 01d9 call 0x1e2
L_01dc:   W8(DS, (u16)(0x1580), 0xff);                                 // 01dc mov byte ptr [0x1580], 0xff
L_01e1:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 01e1 ret
L_01e2:   PUSH(R.ax);                                                  // 01e2 push ax
  R.ax = (u16)((u16)(0x15e1));                                 // 01e3 lea ax, [0x15e1]
  R.si = (u16)(R.ax);                                          // 01e7 mov si, ax
L_01e9:   SETL(R.bx, M8(DS, (u16)(R.si)));                             // 01e9 mov bl, byte ptr [si]
  SUB8((u8)R.bx, 0xff);                                        // 01eb cmp bl, 0xff
  if (R.zf) goto L_01f6;                                       // 01ee je 0x1f6
  PUSH(0x01f3); goto L_025f;                                   // 01f0 call 0x25f
L_01f3:   R.si = (u16)(INC16(R.si));                                   // 01f3 inc si
  goto L_01e9;                                                 // 01f4 jmp 0x1e9
L_01f6:   W8(DS, (u16)(0x1581), 0x0);                                  // 01f6 mov byte ptr [0x1581], 0
  R.ax = POP();                                                // 01fb pop ax
  R.si = (u16)(R.ax);                                          // 01fc mov si, ax
L_01fe:   SETL(R.bx, M8(DS, (u16)(R.si)));                             // 01fe mov bl, byte ptr [si]
  SUB8((u8)R.bx, 0xff);                                        // 0200 cmp bl, 0xff
  if (R.zf) goto L_020b;                                       // 0203 je 0x20b
  PUSH(0x0208); goto L_0255;                                   // 0205 call 0x255
L_0208:   R.si = (u16)(INC16(R.si));                                   // 0208 inc si
  goto L_01fe;                                                 // 0209 jmp 0x1fe
L_020b:   SETL(R.bx, M8(DS, (u16)(0x1581)));                           // 020b mov bl, byte ptr [0x1581]
  SETL(R.bx, XOR8((u8)R.bx, 0xff));                            // 020f xor bl, 0xff
  SETL(R.bx, ADD8((u8)R.bx, 0x1));                             // 0212 add bl, 1
  SETL(R.bx, AND8((u8)R.bx, 0x7f));                            // 0215 and bl, 0x7f
  PUSH(0x021b); goto L_025f;                                   // 0218 call 0x25f
L_021b:   SETL(R.bx, 0xf7);                                            // 021b mov bl, 0xf7
  PUSH(0x0220); goto L_025f;                                   // 021d call 0x25f
L_0220:   R.cx = (u16)(M16(DS, (u16)(0x158c)));                        // 0220 mov cx, word ptr [0x158c]
L_0224:   if (--R.cx != 0) goto L_0224;                                // 0224 loop 0x224
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0226 ret
L_0227:   R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 0227 mov dx, word ptr [0x137c]
  R.dx = (u16)(ADD16(R.dx, 0x1));                              // 022b add dx, 1
  R.cx = (u16)(0xffff);                                        // 022e mov cx, 0xffff
L_0231:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0231 in al, dx
  SETL(R.ax, AND8((u8)R.ax, 0x40));                            // 0232 and al, 0x40
  if (R.zf) goto L_023c;                                       // 0234 je 0x23c
  if (--R.cx != 0) goto L_0231;                                // 0236 loop 0x231
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0238 xor ax, ax
  if (R.zf) goto L_0254;                                       // 023a je 0x254
L_023c:   SETL(R.ax, (u8)R.bx);                                        // 023c mov al, bl
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 023e out dx, al
  R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 023f mov dx, word ptr [0x137c]
  R.cx = (u16)(0xffff);                                        // 0243 mov cx, 0xffff
L_0246:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0246 in al, dx
  SUB8((u8)R.ax, 0xfe);                                        // 0247 cmp al, 0xfe
  if (R.zf) goto L_0251;                                       // 0249 je 0x251
  if (--R.cx != 0) goto L_0246;                                // 024b loop 0x246
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 024d xor ax, ax
  if (R.zf) goto L_0254;                                       // 024f je 0x254
L_0251:   R.ax = (u16)(0x1);                                           // 0251 mov ax, 1
L_0254:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0254 ret
L_0255:   PUSH(R.bx);                                                  // 0255 push bx
  SETL(R.bx, ADD8((u8)R.bx, M8(DS, (u16)(0x1581))));           // 0256 add bl, byte ptr [0x1581]
  W8(DS, (u16)(0x1581), (u8)R.bx);                             // 025a mov byte ptr [0x1581], bl
  R.bx = POP();                                                // 025e pop bx
L_025f:   R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 025f mov dx, word ptr [0x137c]
  R.dx = (u16)(ADD16(R.dx, 0x1));                              // 0263 add dx, 1
  R.cx = (u16)(0xffff);                                        // 0266 mov cx, 0xffff
L_0269:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0269 in al, dx
  SETL(R.ax, AND8((u8)R.ax, 0x40));                            // 026a and al, 0x40
  if (R.zf) goto L_0274;                                       // 026c je 0x274
  if (--R.cx != 0) goto L_0269;                                // 026e loop 0x269
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0270 xor ax, ax
  if (R.zf) goto L_027e;                                       // 0272 je 0x27e
L_0274:   SETL(R.ax, (u8)R.bx);                                        // 0274 mov al, bl
  R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 0276 mov dx, word ptr [0x137c]
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 027a out dx, al
  R.ax = (u16)(0x1);                                           // 027b mov ax, 1
L_027e:   PUSH(R.ax);                                                  // 027e push ax
  R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 027f mov dx, word ptr [0x137c]
  R.dx = (u16)(ADD16(R.dx, 0x1));                              // 0283 add dx, 1
L_0286:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0286 in al, dx
  SETL(R.ax, AND8((u8)R.ax, 0x80));                            // 0287 and al, 0x80
  if (!R.zf) goto L_0290;                                      // 0289 jne 0x290
  R.dx = (u16)(DEC16(R.dx));                                   // 028b dec dx
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 028c in al, dx
  R.dx = (u16)(INC16(R.dx));                                   // 028d inc dx
  goto L_0286;                                                 // 028e jmp 0x286
L_0290:   R.ax = POP();                                                // 0290 pop ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0291 ret
L_0292:   SETL(R.bx, 0x5);                                             // 0292 mov bl, 5
L_0294:   R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 0294 mov dx, word ptr [0x137c]
  R.dx = (u16)(ADD16(R.dx, 0x1));                              // 0298 add dx, 1
  SETL(R.ax, 0xff);                                            // 029b mov al, 0xff
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 029d out dx, al
  R.cx = (u16)(0xffff);                                        // 029e mov cx, 0xffff
L_02a1:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 02a1 in al, dx
  SETL(R.ax, AND8((u8)R.ax, 0x80));                            // 02a2 and al, 0x80
  if (R.zf) goto L_02a8;                                       // 02a4 je 0x2a8
  if (--R.cx != 0) goto L_02a1;                                // 02a6 loop 0x2a1
L_02a8:   R.dx = (u16)(M16(DS, (u16)(0x137c)));                        // 02a8 mov dx, word ptr [0x137c]
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 02ac in al, dx
  SUB8((u8)R.ax, 0xfe);                                        // 02ad cmp al, 0xfe
  if (R.zf) goto L_02bb;                                       // 02af je 0x2bb
  SETL(R.bx, DEC8((u8)R.bx));                                  // 02b1 dec bl
  if (!R.zf) goto L_0294;                                      // 02b3 jne 0x294
  R.ax = (u16)(0x52);                                          // 02b5 mov ax, 0x52
  goto L_02be;                                                 // 02b8 jmp 0x2be
L_02bb:   R.ax = (u16)(0x0);                                           // 02bb mov ax, 0
L_02be:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 02be ret
L_02d1:   PUSH(R.bp);                                                  // 02d1 push bp
  R.bp = (u16)(R.sp);                                          // 02d2 mov bp, sp
  PUSH(R.ds);                                                  // 02d4 push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 02d5 mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 02d8 mov ds, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 02da mov bx, word ptr [bp + 6]
  PUSH(0x02e0); goto L_025f;                                   // 02dd call 0x25f
L_02e0:   R.ds = POP();                                                // 02e0 pop ds
  R.bp = POP();                                                // 02e1 pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 02e2 retf
L_02f2:   SETL(R.dx, M8(DS, (u16)(0x2760)));                           // 02f2 mov dl, byte ptr [0x2760]
  PUSH(R.dx);                                                  // 02f6 push dx
  W8(DS, (u16)(0x2760), 0x0);                                  // 02f7 mov byte ptr [0x2760], 0
  W8(DS, (u16)(R.bx + 0x1), 0x0);                              // 02fc mov byte ptr [bx + 1], 0
  W8(DS, (u16)(R.bx + 0x2), 0x0);                              // 0300 mov byte ptr [bx + 2], 0
  W8(DS, (u16)(R.bx + 0xc), 0xff);                             // 0304 mov byte ptr [bx + 0xc], 0xff
  W8(DS, (u16)(R.bx + 0xa), 0x64);                             // 0308 mov byte ptr [bx + 0xa], 0x64
  W8(DS, (u16)(R.bx + 0xb), 0x40);                             // 030c mov byte ptr [bx + 0xb], 0x40
  W16(DS, (u16)(R.bx + 0x10), R.cx);                           // 0310 mov word ptr [bx + 0x10], cx
  W16(DS, (u16)(R.bx + 0x12), R.cx);                           // 0313 mov word ptr [bx + 0x12], cx
  W16(DS, (u16)(R.bx + 0x14), R.cx);                           // 0316 mov word ptr [bx + 0x14], cx
  W16(DS, (u16)(R.bx + 0x16), R.cx);                           // 0319 mov word ptr [bx + 0x16], cx
  W16(DS, (u16)(R.bx + 0x18), 0x0);                            // 031c mov word ptr [bx + 0x18], 0
  W16(DS, (u16)(R.bx + 0x1a), 0x0);                            // 0321 mov word ptr [bx + 0x1a], 0
  W8(DS, (u16)(R.bx + 0x6), 0x0);                              // 0326 mov byte ptr [bx + 6], 0
  W16(DS, (u16)(R.bx + 0x1c), R.ax);                           // 032a mov word ptr [bx + 0x1c], ax
  W8(DS, (u16)(R.bx), 0x1);                                    // 032d mov byte ptr [bx], 1
  R.dx = POP();                                                // 0330 pop dx
  W8(DS, (u16)(0x2760), (u8)R.dx);                             // 0331 mov byte ptr [0x2760], dl
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0335 ret
L_036f:   R.cx = (u16)((u16)(0x2ca));                                  // 036f lea cx, [0x2ca]
  R.bx = (u16)((u16)(0x2762));                                 // 0373 lea bx, [0x2762]
  W16(DS, (u16)(R.bx + 0x12), R.cx);                           // 0377 mov word ptr [bx + 0x12], cx
  R.bx = (u16)((u16)(0x2780));                                 // 037a lea bx, [0x2780]
  W16(DS, (u16)(R.bx + 0x12), R.cx);                           // 037e mov word ptr [bx + 0x12], cx
  R.bx = (u16)((u16)(0x279e));                                 // 0381 lea bx, [0x279e]
  W16(DS, (u16)(R.bx + 0x12), R.cx);                           // 0385 mov word ptr [bx + 0x12], cx
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0388 ret
L_0389:   R.ax = (u16)((u16)(0x3a5));                                  // 0389 lea ax, [0x3a5]
  R.bx = (u16)((u16)(0x2762));                                 // 038d lea bx, [0x2762]
  R.cx = (u16)((u16)(0x121e));                                 // 0391 lea cx, [0x121e]
  PUSH(0x0398); goto L_02f2;                                   // 0395 call 0x2f2
L_0398:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0398 xor ax, ax
  R.bx = (u16)((u16)(0x2780));                                 // 039a lea bx, [0x2780]
  R.cx = (u16)((u16)(0x1228));                                 // 039e lea cx, [0x1228]
  goto L_02f2;                                                 // 03a2 jmp 0x2f2
L_03a5:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 03a5 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 03a7 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x1232));                                 // 03ab lea cx, [0x1232]
  PUSH(0x03b2); goto L_02f2;                                   // 03af call 0x2f2
L_03b2:   R.bx = (u16)((u16)(0x2780));                                 // 03b2 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x126e));                                 // 03b6 lea cx, [0x126e]
  PUSH(0x03bd); goto L_02f2;                                   // 03ba call 0x2f2
L_03bd:   R.bx = (u16)((u16)(0x279e));                                 // 03bd lea bx, [0x279e]
  R.cx = (u16)((u16)(0x129c));                                 // 03c1 lea cx, [0x129c]
  PUSH(0x03c8); goto L_02f2;                                   // 03c5 call 0x2f2
L_03c8:   R.bx = (u16)((u16)(0x27bc));                                 // 03c8 lea bx, [0x27bc]
  R.cx = (u16)((u16)(0x12d8));                                 // 03cc lea cx, [0x12d8]
  PUSH(0x03d3); goto L_02f2;                                   // 03d0 call 0x2f2
L_03d3:   R.bx = (u16)((u16)(0x27da));                                 // 03d3 lea bx, [0x27da]
  R.cx = (u16)((u16)(0x12ea));                                 // 03d7 lea cx, [0x12ea]
  PUSH(0x03de); goto L_02f2;                                   // 03db call 0x2f2
L_03de:   R.bx = (u16)((u16)(0x27f8));                                 // 03de lea bx, [0x27f8]
  R.cx = (u16)((u16)(0x12fc));                                 // 03e2 lea cx, [0x12fc]
  goto L_02f2;                                                 // 03e6 jmp 0x2f2
L_03e9:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 03e9 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 03eb lea bx, [0x2762]
  R.cx = (u16)((u16)(0x1038));                                 // 03ef lea cx, [0x1038]
  PUSH(0x03f6); goto L_02f2;                                   // 03f3 call 0x2f2
L_03f6:   R.bx = (u16)((u16)(0x2780));                                 // 03f6 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x106c));                                 // 03fa lea cx, [0x106c]
  goto L_02f2;                                                 // 03fe jmp 0x2f2
L_0401:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0401 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0403 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x6e8));                                  // 0407 lea cx, [0x6e8]
  PUSH(0x040e); goto L_02f2;                                   // 040b call 0x2f2
L_040e:   R.bx = (u16)((u16)(0x2780));                                 // 040e lea bx, [0x2780]
  R.cx = (u16)((u16)(0x788));                                  // 0412 lea cx, [0x788]
  PUSH(0x0419); goto L_02f2;                                   // 0416 call 0x2f2
L_0419:   R.bx = (u16)((u16)(0x279e));                                 // 0419 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x82c));                                  // 041d lea cx, [0x82c]
  goto L_02f2;                                                 // 0421 jmp 0x2f2
L_0424:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0424 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0426 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x554));                                  // 042a lea cx, [0x554]
  PUSH(0x0431); goto L_02f2;                                   // 042e call 0x2f2
L_0431:   R.bx = (u16)((u16)(0x2780));                                 // 0431 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x5ae));                                  // 0435 lea cx, [0x5ae]
  PUSH(0x043c); goto L_02f2;                                   // 0439 call 0x2f2
L_043c:   R.bx = (u16)((u16)(0x279e));                                 // 043c lea bx, [0x279e]
  R.cx = (u16)((u16)(0x5e4));                                  // 0440 lea cx, [0x5e4]
  goto L_02f2;                                                 // 0444 jmp 0x2f2
L_0447:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0447 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0449 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x486));                                  // 044d lea cx, [0x486]
  PUSH(0x0454); goto L_02f2;                                   // 0451 call 0x2f2
L_0454:   R.bx = (u16)((u16)(0x2780));                                 // 0454 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x4de));                                  // 0458 lea cx, [0x4de]
  PUSH(0x045f); goto L_02f2;                                   // 045c call 0x2f2
L_045f:   R.bx = (u16)((u16)(0x279e));                                 // 045f lea bx, [0x279e]
  R.cx = (u16)((u16)(0x51e));                                  // 0463 lea cx, [0x51e]
  goto L_02f2;                                                 // 0467 jmp 0x2f2
L_046a:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 046a xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 046c lea bx, [0x2762]
  R.cx = (u16)((u16)(0x108e));                                 // 0470 lea cx, [0x108e]
  PUSH(0x0477); goto L_02f2;                                   // 0474 call 0x2f2
L_0477:   R.bx = (u16)((u16)(0x2780));                                 // 0477 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x10d2));                                 // 047b lea cx, [0x10d2]
  PUSH(0x0482); goto L_02f2;                                   // 047f call 0x2f2
L_0482:   R.bx = (u16)((u16)(0x279e));                                 // 0482 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x10fe));                                 // 0486 lea cx, [0x10fe]
  goto L_02f2;                                                 // 048a jmp 0x2f2
L_048d:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 048d xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 048f lea bx, [0x2762]
  R.cx = (u16)((u16)(0xfa0));                                  // 0493 lea cx, [0xfa0]
  PUSH(0x049a); goto L_02f2;                                   // 0497 call 0x2f2
L_049a:   R.bx = (u16)((u16)(0x2780));                                 // 049a lea bx, [0x2780]
  R.cx = (u16)((u16)(0xfdc));                                  // 049e lea cx, [0xfdc]
  PUSH(0x04a5); goto L_02f2;                                   // 04a2 call 0x2f2
L_04a5:   R.bx = (u16)((u16)(0x279e));                                 // 04a5 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x1002));                                 // 04a9 lea cx, [0x1002]
  goto L_02f2;                                                 // 04ad jmp 0x2f2
L_04b0:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04b0 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 04b2 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x1124));                                 // 04b6 lea cx, [0x1124]
  PUSH(0x04bd); goto L_02f2;                                   // 04ba call 0x2f2
L_04bd:   R.bx = (u16)((u16)(0x2780));                                 // 04bd lea bx, [0x2780]
  R.cx = (u16)((u16)(0x1154));                                 // 04c1 lea cx, [0x1154]
  PUSH(0x04c8); goto L_02f2;                                   // 04c5 call 0x2f2
L_04c8:   R.bx = (u16)((u16)(0x279e));                                 // 04c8 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x1170));                                 // 04cc lea cx, [0x1170]
  goto L_02f2;                                                 // 04d0 jmp 0x2f2
L_04d3:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04d3 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 04d5 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x8aa));                                  // 04d9 lea cx, [0x8aa]
  PUSH(0x04e0); goto L_02f2;                                   // 04dd call 0x2f2
L_04e0:   R.bx = (u16)((u16)(0x2780));                                 // 04e0 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x908));                                  // 04e4 lea cx, [0x908]
  PUSH(0x04eb); goto L_02f2;                                   // 04e8 call 0x2f2
L_04eb:   R.bx = (u16)((u16)(0x279e));                                 // 04eb lea bx, [0x279e]
  R.cx = (u16)((u16)(0x934));                                  // 04ef lea cx, [0x934]
  goto L_02f2;                                                 // 04f3 jmp 0x2f2
L_04f6:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 04f6 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 04f8 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x37c));                                  // 04fc lea cx, [0x37c]
  PUSH(0x0503); goto L_02f2;                                   // 0500 call 0x2f2
L_0503:   R.bx = (u16)((u16)(0x2780));                                 // 0503 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x45c));                                  // 0507 lea cx, [0x45c]
  goto L_02f2;                                                 // 050b jmp 0x2f2
L_050e:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 050e xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0510 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x25e));                                  // 0514 lea cx, [0x25e]
  PUSH(0x051b); goto L_02f2;                                   // 0518 call 0x2f2
L_051b:   R.bx = (u16)((u16)(0x2780));                                 // 051b lea bx, [0x2780]
  R.cx = (u16)((u16)(0x2cc));                                  // 051f lea cx, [0x2cc]
  PUSH(0x0526); goto L_02f2;                                   // 0523 call 0x2f2
L_0526:   R.bx = (u16)((u16)(0x279e));                                 // 0526 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x324));                                  // 052a lea cx, [0x324]
  goto L_02f2;                                                 // 052e jmp 0x2f2
L_0531:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0531 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0533 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x662));                                  // 0537 lea cx, [0x662]
  PUSH(0x053e); goto L_02f2;                                   // 053b call 0x2f2
L_053e:   R.bx = (u16)((u16)(0x2780));                                 // 053e lea bx, [0x2780]
  R.cx = (u16)((u16)(0x6a4));                                  // 0542 lea cx, [0x6a4]
  PUSH(0x0549); goto L_02f2;                                   // 0546 call 0x2f2
L_0549:   R.bx = (u16)((u16)(0x279e));                                 // 0549 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x6ce));                                  // 054d lea cx, [0x6ce]
  goto L_02f2;                                                 // 0551 jmp 0x2f2
L_0554:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0554 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0556 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x96c));                                  // 055a lea cx, [0x96c]
  PUSH(0x0561); goto L_02f2;                                   // 055e call 0x2f2
L_0561:   R.bx = (u16)((u16)(0x2780));                                 // 0561 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x9a2));                                  // 0565 lea cx, [0x9a2]
  PUSH(0x056c); goto L_02f2;                                   // 0569 call 0x2f2
L_056c:   R.ax = (u16)((u16)(0x1599));                                 // 056c lea ax, [0x1599]
  goto L_05ae;                                                 // 0570 jmp 0x5ae
L_0573:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0573 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0575 lea bx, [0x2762]
  R.cx = (u16)((u16)(0xaea));                                  // 0579 lea cx, [0xaea]
  PUSH(0x0580); goto L_02f2;                                   // 057d call 0x2f2
L_0580:   R.bx = (u16)((u16)(0x2780));                                 // 0580 lea bx, [0x2780]
  R.cx = (u16)((u16)(0xb06));                                  // 0584 lea cx, [0xb06]
  PUSH(0x058b); goto L_02f2;                                   // 0588 call 0x2f2
L_058b:   R.ax = (u16)((u16)(0x15b1));                                 // 058b lea ax, [0x15b1]
  goto L_05ae;                                                 // 058f jmp 0x5ae
L_0592:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0592 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0594 lea bx, [0x2762]
  R.cx = (u16)((u16)(0xc5c));                                  // 0598 lea cx, [0xc5c]
  PUSH(0x059f); goto L_02f2;                                   // 059c call 0x2f2
L_059f:   R.bx = (u16)((u16)(0x2780));                                 // 059f lea bx, [0x2780]
  R.cx = (u16)((u16)(0xc6a));                                  // 05a3 lea cx, [0xc6a]
  PUSH(0x05aa); goto L_02f2;                                   // 05a7 call 0x2f2
L_05aa:   R.ax = (u16)((u16)(0x15c9));                                 // 05aa lea ax, [0x15c9]
L_05ae:   W16(DS, (u16)(0x1595), R.ax);                                // 05ae mov word ptr [0x1595], ax
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 05b1 xor ax, ax
  W16(DS, (u16)(0x1591), R.ax);                                // 05b3 mov word ptr [0x1591], ax
  W16(DS, (u16)(0x1593), R.ax);                                // 05b6 mov word ptr [0x1593], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 05b9 ret
L_05ba:   SUB16(M16(DS, (u16)(0x1597)), 0x6);                          // 05ba cmp word ptr [0x1597], 6
  if (R.zf) goto L_05e2;                                       // 05bf je 0x5e2
  W16(DS, (u16)(0x1597), 0x6);                                 // 05c1 mov word ptr [0x1597], 6
  PUSH(0x05ca); goto L_036f;                                   // 05c7 call 0x36f
L_05ca:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 05ca xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 05cc lea bx, [0x2762]
  R.cx = (u16)((u16)(0x50));                                   // 05d0 lea cx, [0x50]
  PUSH(0x05d7); goto L_02f2;                                   // 05d4 call 0x2f2
L_05d7:   R.bx = (u16)((u16)(0x2780));                                 // 05d7 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x58));                                   // 05db lea cx, [0x58]
  PUSH(0x05e2); goto L_02f2;                                   // 05df call 0x2f2
L_05e2:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 05e2 ret
L_05e3:   SUB16(M16(DS, (u16)(0x1597)), 0x5);                          // 05e3 cmp word ptr [0x1597], 5
  if (R.zf) goto L_0613;                                       // 05e8 je 0x613
  W16(DS, (u16)(0x1597), 0x5);                                 // 05ea mov word ptr [0x1597], 5
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 05f0 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 05f2 lea bx, [0x2762]
  R.cx = (u16)((u16)(0xf38));                                  // 05f6 lea cx, [0xf38]
  PUSH(0x05fd); goto L_02f2;                                   // 05fa call 0x2f2
L_05fd:   R.bx = (u16)((u16)(0x2780));                                 // 05fd lea bx, [0x2780]
  R.cx = (u16)((u16)(0xf56));                                  // 0601 lea cx, [0xf56]
  PUSH(0x0608); goto L_02f2;                                   // 0605 call 0x2f2
L_0608:   R.bx = (u16)((u16)(0x279e));                                 // 0608 lea bx, [0x279e]
  R.cx = (u16)((u16)(0xf6c));                                  // 060c lea cx, [0xf6c]
  PUSH(0x0613); goto L_02f2;                                   // 0610 call 0x2f2
L_0613:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0613 ret
L_0614:   SUB16(M16(DS, (u16)(0x1597)), 0x1);                          // 0614 cmp word ptr [0x1597], 1
  if (R.zf) goto L_0647;                                       // 0619 je 0x647
  W16(DS, (u16)(0x1597), 0x1);                                 // 061b mov word ptr [0x1597], 1
  PUSH(0x0624); goto L_036f;                                   // 0621 call 0x36f
L_0624:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0624 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0626 lea bx, [0x2762]
  R.cx = (u16)((u16)(0xe4c));                                  // 062a lea cx, [0xe4c]
  PUSH(0x0631); goto L_02f2;                                   // 062e call 0x2f2
L_0631:   R.bx = (u16)((u16)(0x2780));                                 // 0631 lea bx, [0x2780]
  R.cx = (u16)((u16)(0xe64));                                  // 0635 lea cx, [0xe64]
  PUSH(0x063c); goto L_02f2;                                   // 0639 call 0x2f2
L_063c:   R.bx = (u16)((u16)(0x279e));                                 // 063c lea bx, [0x279e]
  R.cx = (u16)((u16)(0xe90));                                  // 0640 lea cx, [0xe90]
  PUSH(0x0647); goto L_02f2;                                   // 0644 call 0x2f2
L_0647:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0647 ret
L_0648:   SUB16(M16(DS, (u16)(0x1597)), 0x2);                          // 0648 cmp word ptr [0x1597], 2
  if (R.zf) goto L_067b;                                       // 064d je 0x67b
  W16(DS, (u16)(0x1597), 0x2);                                 // 064f mov word ptr [0x1597], 2
  PUSH(0x0658); goto L_036f;                                   // 0655 call 0x36f
L_0658:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0658 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 065a lea bx, [0x2762]
  R.cx = (u16)((u16)(0xe9c));                                  // 065e lea cx, [0xe9c]
  PUSH(0x0665); goto L_02f2;                                   // 0662 call 0x2f2
L_0665:   R.bx = (u16)((u16)(0x2780));                                 // 0665 lea bx, [0x2780]
  R.cx = (u16)((u16)(0xeac));                                  // 0669 lea cx, [0xeac]
  PUSH(0x0670); goto L_02f2;                                   // 066d call 0x2f2
L_0670:   R.bx = (u16)((u16)(0x279e));                                 // 0670 lea bx, [0x279e]
  R.cx = (u16)((u16)(0xebc));                                  // 0674 lea cx, [0xebc]
  PUSH(0x067b); goto L_02f2;                                   // 0678 call 0x2f2
L_067b:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 067b ret
L_067c:   SUB16(M16(DS, (u16)(0x1597)), 0x3);                          // 067c cmp word ptr [0x1597], 3
  if (R.zf) goto L_06af;                                       // 0681 je 0x6af
  W16(DS, (u16)(0x1597), 0x3);                                 // 0683 mov word ptr [0x1597], 3
  PUSH(0x068c); goto L_036f;                                   // 0689 call 0x36f
L_068c:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 068c xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 068e lea bx, [0x2762]
  R.cx = (u16)((u16)(0xec6));                                  // 0692 lea cx, [0xec6]
  PUSH(0x0699); goto L_02f2;                                   // 0696 call 0x2f2
L_0699:   R.bx = (u16)((u16)(0x2780));                                 // 0699 lea bx, [0x2780]
  R.cx = (u16)((u16)(0xeda));                                  // 069d lea cx, [0xeda]
  PUSH(0x06a4); goto L_02f2;                                   // 06a1 call 0x2f2
L_06a4:   R.bx = (u16)((u16)(0x279e));                                 // 06a4 lea bx, [0x279e]
  R.cx = (u16)((u16)(0xeee));                                  // 06a8 lea cx, [0xeee]
  PUSH(0x06af); goto L_02f2;                                   // 06ac call 0x2f2
L_06af:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 06af ret
L_06b0:   SUB16(M16(DS, (u16)(0x1597)), 0x4);                          // 06b0 cmp word ptr [0x1597], 4
  if (R.zf) goto L_06e3;                                       // 06b5 je 0x6e3
  W16(DS, (u16)(0x1597), 0x4);                                 // 06b7 mov word ptr [0x1597], 4
  PUSH(0x06c0); goto L_036f;                                   // 06bd call 0x36f
L_06c0:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06c0 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 06c2 lea bx, [0x2762]
  R.cx = (u16)((u16)(0xefa));                                  // 06c6 lea cx, [0xefa]
  PUSH(0x06cd); goto L_02f2;                                   // 06ca call 0x2f2
L_06cd:   R.bx = (u16)((u16)(0x2780));                                 // 06cd lea bx, [0x2780]
  R.cx = (u16)((u16)(0xf18));                                  // 06d1 lea cx, [0xf18]
  PUSH(0x06d8); goto L_02f2;                                   // 06d5 call 0x2f2
L_06d8:   R.bx = (u16)((u16)(0x279e));                                 // 06d8 lea bx, [0x279e]
  R.cx = (u16)((u16)(0xf28));                                  // 06dc lea cx, [0xf28]
  PUSH(0x06e3); goto L_02f2;                                   // 06e0 call 0x2f2
L_06e3:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 06e3 ret
L_06e4:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 06e4 xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 06e6 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x60));                                   // 06ea lea cx, [0x60]
  PUSH(0x06f1); goto L_02f2;                                   // 06ee call 0x2f2
L_06f1:   R.bx = (u16)((u16)(0x2780));                                 // 06f1 lea bx, [0x2780]
  R.cx = (u16)((u16)(0x10e));                                  // 06f5 lea cx, [0x10e]
  PUSH(0x06fc); goto L_02f2;                                   // 06f9 call 0x2f2
L_06fc:   R.bx = (u16)((u16)(0x279e));                                 // 06fc lea bx, [0x279e]
  R.cx = (u16)((u16)(0x20a));                                  // 0700 lea cx, [0x20a]
  goto L_02f2;                                                 // 0704 jmp 0x2f2
L_0707:   PUSH(0x070a); goto L_06e4;                                   // 0707 call 0x6e4
L_070a:   R.ax = (u16)((u16)(0x2ca));                                  // 070a lea ax, [0x2ca]
  PUSH(R.ax);                                                  // 070e push ax
  PUSH(R.ax);                                                  // 070f push ax
  goto L_0724;                                                 // 0710 jmp 0x724
L_0713:   PUSH(0x0716); goto L_06e4;                                   // 0713 call 0x6e4
L_0716:   R.ax = (u16)((u16)(0x218));                                  // 0716 lea ax, [0x218]
  PUSH(R.ax);                                                  // 071a push ax
  R.ax = (u16)((u16)(0x148));                                  // 071b lea ax, [0x148]
  PUSH(R.ax);                                                  // 071f push ax
  R.ax = (u16)((u16)(0x7c));                                   // 0720 lea ax, [0x7c]
L_0724:   R.bx = (u16)((u16)(0x2762));                                 // 0724 lea bx, [0x2762]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 0728 mov word ptr [bx + 0x16], ax
  R.ax = POP();                                                // 072b pop ax
  R.bx = (u16)((u16)(0x2780));                                 // 072c lea bx, [0x2780]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 0730 mov word ptr [bx + 0x16], ax
  R.ax = POP();                                                // 0733 pop ax
  R.bx = (u16)((u16)(0x279e));                                 // 0734 lea bx, [0x279e]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 0738 mov word ptr [bx + 0x16], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 073b ret
L_073c:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 073c xor ax, ax
  R.bx = (u16)((u16)(0x27bc));                                 // 073e lea bx, [0x27bc]
  R.cx = (u16)((u16)(0x1190));                                 // 0742 lea cx, [0x1190]
  goto L_02f2;                                                 // 0746 jmp 0x2f2
L_0749:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0749 xor ax, ax
  R.bx = (u16)((u16)(0x279e));                                 // 074b lea bx, [0x279e]
  R.cx = (u16)((u16)(0x1198));                                 // 074f lea cx, [0x1198]
  goto L_02f2;                                                 // 0753 jmp 0x2f2
L_0756:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0756 xor ax, ax
  R.bx = (u16)((u16)(0x279e));                                 // 0758 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x11a0));                                 // 075c lea cx, [0x11a0]
  goto L_02f2;                                                 // 0760 jmp 0x2f2
L_0763:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0763 xor ax, ax
  R.bx = (u16)((u16)(0x27bc));                                 // 0765 lea bx, [0x27bc]
  R.cx = (u16)((u16)(0x11b4));                                 // 0769 lea cx, [0x11b4]
  goto L_02f2;                                                 // 076d jmp 0x2f2
L_0770:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0770 xor ax, ax
  R.bx = (u16)((u16)(0x27bc));                                 // 0772 lea bx, [0x27bc]
  R.cx = (u16)((u16)(0x11bc));                                 // 0776 lea cx, [0x11bc]
  goto L_02f2;                                                 // 077a jmp 0x2f2
L_077d:   SETL(R.ax, 0x29);                                            // 077d mov al, 0x29
  SUB8((u8)R.ax, M8(DS, (u16)(0x11fb)));                       // 077f cmp al, byte ptr [0x11fb]
  if (!R.zf) goto L_0787;                                      // 0783 jne 0x787
  SETL(R.ax, 0x24);                                            // 0785 mov al, 0x24
L_0787:   W8(DS, (u16)(0x11fb), (u8)R.ax);                             // 0787 mov byte ptr [0x11fb], al
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 078a xor ax, ax
  R.bx = (u16)((u16)(0x27da));                                 // 078c lea bx, [0x27da]
  R.cx = (u16)((u16)(0x11f6));                                 // 0790 lea cx, [0x11f6]
  goto L_02f2;                                                 // 0794 jmp 0x2f2
L_0797:   SETL(R.ax, 0x29);                                            // 0797 mov al, 0x29
  SUB8((u8)R.ax, M8(DS, (u16)(0x1203)));                       // 0799 cmp al, byte ptr [0x1203]
  if (!R.zf) goto L_07a1;                                      // 079d jne 0x7a1
  SETL(R.ax, 0x24);                                            // 079f mov al, 0x24
L_07a1:   W8(DS, (u16)(0x1203), (u8)R.ax);                             // 07a1 mov byte ptr [0x1203], al
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07a4 xor ax, ax
  R.bx = (u16)((u16)(0x27da));                                 // 07a6 lea bx, [0x27da]
  R.cx = (u16)((u16)(0x11fe));                                 // 07aa lea cx, [0x11fe]
  goto L_02f2;                                                 // 07ae jmp 0x2f2
L_07b1:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07b1 xor ax, ax
  R.bx = (u16)((u16)(0x27da));                                 // 07b3 lea bx, [0x27da]
  R.cx = (u16)((u16)(0x1206));                                 // 07b7 lea cx, [0x1206]
  goto L_02f2;                                                 // 07bb jmp 0x2f2
L_07be:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07be xor ax, ax
  R.bx = (u16)((u16)(0x279e));                                 // 07c0 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x120e));                                 // 07c4 lea cx, [0x120e]
  goto L_02f2;                                                 // 07c8 jmp 0x2f2
L_07cb:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07cb xor ax, ax
  R.bx = (u16)((u16)(0x27f8));                                 // 07cd lea bx, [0x27f8]
  R.cx = (u16)((u16)(0x2ca));                                  // 07d1 lea cx, [0x2ca]
  goto L_02f2;                                                 // 07d5 jmp 0x2f2
L_07d8:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07d8 xor ax, ax
  R.bx = (u16)((u16)(0x27f8));                                 // 07da lea bx, [0x27f8]
  R.cx = (u16)((u16)(0x11dc));                                 // 07de lea cx, [0x11dc]
  goto L_02f2;                                                 // 07e2 jmp 0x2f2
L_07e5:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07e5 xor ax, ax
  R.bx = (u16)((u16)(0x27f8));                                 // 07e7 lea bx, [0x27f8]
  R.cx = (u16)((u16)(0x11ee));                                 // 07eb lea cx, [0x11ee]
  goto L_02f2;                                                 // 07ef jmp 0x2f2
L_07f2:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 07f2 xor ax, ax
  R.bx = (u16)((u16)(0x27f8));                                 // 07f4 lea bx, [0x27f8]
  R.cx = (u16)((u16)(0x11e6));                                 // 07f8 lea cx, [0x11e6]
  goto L_02f2;                                                 // 07fc jmp 0x2f2
L_07ff:   R.ax = (u16)((u16)(0x7cb));                                  // 07ff lea ax, [0x7cb]
  R.bx = (u16)((u16)(0x27f8));                                 // 0803 lea bx, [0x27f8]
  R.cx = (u16)((u16)(0x11d4));                                 // 0807 lea cx, [0x11d4]
  goto L_02f2;                                                 // 080b jmp 0x2f2
L_080e:   R.ax = (u16)((u16)(0x7d8));                                  // 080e lea ax, [0x7d8]
  R.bx = (u16)((u16)(0x27f8));                                 // 0812 lea bx, [0x27f8]
  W16(DS, (u16)(R.bx + 0x1c), R.ax);                           // 0816 mov word ptr [bx + 0x1c], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0819 ret
L_081a:   R.ax = (u16)((u16)(0x7e5));                                  // 081a lea ax, [0x7e5]
  R.bx = (u16)((u16)(0x27f8));                                 // 081e lea bx, [0x27f8]
  W16(DS, (u16)(R.bx + 0x1c), R.ax);                           // 0822 mov word ptr [bx + 0x1c], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0825 ret
L_0826:   R.ax = (u16)((u16)(0x7f2));                                  // 0826 lea ax, [0x7f2]
  R.bx = (u16)((u16)(0x27f8));                                 // 082a lea bx, [0x27f8]
  W16(DS, (u16)(R.bx + 0x1c), R.ax);                           // 082e mov word ptr [bx + 0x1c], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0831 ret
L_0832:   SUB16(M16(DS, (u16)(0x1597)), 0x6);                          // 0832 cmp word ptr [0x1597], 6
  if (R.zf) goto L_0862;                                       // 0837 je 0x862
  W16(DS, (u16)(0x1597), 0x6);                                 // 0839 mov word ptr [0x1597], 6
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 083f xor ax, ax
  R.bx = (u16)((u16)(0x2762));                                 // 0841 lea bx, [0x2762]
  R.cx = (u16)((u16)(0x1348));                                 // 0845 lea cx, [0x1348]
  PUSH(0x084c); goto L_02f2;                                   // 0849 call 0x2f2
L_084c:   R.bx = (u16)((u16)(0x2780));                                 // 084c lea bx, [0x2780]
  R.cx = (u16)((u16)(0x1364));                                 // 0850 lea cx, [0x1364]
  PUSH(0x0857); goto L_02f2;                                   // 0854 call 0x2f2
L_0857:   R.bx = (u16)((u16)(0x279e));                                 // 0857 lea bx, [0x279e]
  R.cx = (u16)((u16)(0x1370));                                 // 085b lea cx, [0x1370]
  PUSH(0x0862); goto L_02f2;                                   // 085f call 0x2f2
L_0862:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0862 ret
L_0863:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0863 ret
L_0879:   PUSH(0x087c); goto L_00a9;                                   // 0879 call 0xa9
L_087c:   R.cx = (u16)(0x9);                                           // 087c mov cx, 9
L_087f:   PUSH(R.cx);                                                  // 087f push cx
  SETL(R.bx, (u8)R.cx);                                        // 0880 mov bl, cl
  SETL(R.bx, OR8((u8)R.bx, 0xb0));                             // 0882 or bl, 0xb0
  PUSH(0x0888); goto L_025f;                                   // 0885 call 0x25f
L_0888:   SETL(R.bx, 0x7b);                                            // 0888 mov bl, 0x7b
  PUSH(0x088d); goto L_025f;                                   // 088a call 0x25f
L_088d:   SETL(R.bx, 0x0);                                             // 088d mov bl, 0
  PUSH(0x0892); goto L_025f;                                   // 088f call 0x25f
L_0892:   SETL(R.bx, 0x7);                                             // 0892 mov bl, 7
  PUSH(0x0897); goto L_025f;                                   // 0894 call 0x25f
L_0897:   SETL(R.bx, 0x64);                                            // 0897 mov bl, 0x64
  PUSH(0x089c); goto L_025f;                                   // 0899 call 0x25f
L_089c:   R.cx = POP();                                                // 089c pop cx
  if (--R.cx != 0) goto L_087f;                                // 089d loop 0x87f
  R.ax = (u16)((u16)(0x15e7));                                 // 089f lea ax, [0x15e7]
  PUSH(0x08a6); goto L_01e2;                                   // 08a3 call 0x1e2
L_08a6:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 08a6 ret
L_0905:   PUSH(R.di);                                                  // 0905 push di
  PUSH(R.bp);                                                  // 0906 push bp
  PUSH(R.ds);                                                  // 0907 push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 0908 mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 090b mov ds, ax
  PUSH(0x0910); goto L_0879;                                   // 090d call 0x879
L_0910:   R.ds = POP();                                                // 0910 pop ds
  R.bp = POP();                                                // 0911 pop bp
  R.di = POP();                                                // 0912 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0913 retf
L_0914:   PUSH(R.bp);                                                  // 0914 push bp
  R.bp = (u16)(R.sp);                                          // 0915 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0917 mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x56);                                           // 091a cmp bx, 0x56
  if (!R.zf && R.sf == R.of) goto L_092e;                      // 091d jg 0x92e
  PUSH(R.ds);                                                  // 091f push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 0920 mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 0923 mov ds, ax
  R.bx = (u16)(AND16(R.bx, 0xfffe));                           // 0925 and bx, 0xfffe
  { u16 t_ = M16(CS, (u16)(R.bx + 0x8a7)); PUSH(0x092d); ip_ = t_; goto dispatch_; } // 0928 call word ptr cs:[bx + 0x8a7]
L_092d:   R.ds = POP();                                                // 092d pop ds
L_092e:   R.bp = POP();                                                // 092e pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 092f retf
L_0930:   PUSH(R.ds);                                                  // 0930 push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 0931 mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 0934 mov ds, ax
  PUSH(0x0939); goto L_00ff;                                   // 0936 call 0xff
L_0939:   R.ax = (u16)(M16(DS, (u16)(0x1582)));                        // 0939 mov ax, word ptr [0x1582]
  W16(DS, (u16)(0x1582), 0x0);                                 // 093c mov word ptr [0x1582], 0
  R.ds = POP();                                                // 0942 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0943 retf
L_0944:   ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 0944 retf
L_0945:   PUSH(R.bp);                                                  // 0945 push bp
  R.bp = (u16)(R.sp);                                          // 0946 mov bp, sp
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x6)));                    // 0948 mov bx, word ptr [bp + 6]
  SUB16(R.bx, 0x5);                                            // 094b cmp bx, 5
  if (!R.zf && R.sf == R.of) goto L_095e;                      // 094e jg 0x95e
  PUSH(R.ds);                                                  // 0950 push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 0951 mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 0954 mov ds, ax
  W16(DS, (u16)(0x1591), R.bx);                                // 0956 mov word ptr [0x1591], bx
  PUSH(0x095d); goto L_096d;                                   // 095a call 0x96d
L_095d:   R.ds = POP();                                                // 095d pop ds
L_095e:   R.bp = POP();                                                // 095e pop bp
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 095f retf
L_0960:   W16(DS, (u16)(R.bx + 0x10), R.ax);                           // 0960 mov word ptr [bx + 0x10], ax
  W16(DS, (u16)(R.bx + 0x14), R.ax);                           // 0963 mov word ptr [bx + 0x14], ax
  R.ax = (u16)(0x2);                                           // 0966 mov ax, 2
  W16(DS, (u16)(R.bx + 0x18), R.ax);                           // 0969 mov word ptr [bx + 0x18], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 096c ret
L_096d:   R.ax = (u16)(M16(DS, (u16)(0x1591)));                        // 096d mov ax, word ptr [0x1591]
  SUB16(R.ax, M16(DS, (u16)(0x1593)));                         // 0970 cmp ax, word ptr [0x1593]
  if (R.zf) goto L_09c3;                                       // 0974 je 0x9c3
  SETL(R.bx, M8(DS, (u16)(0x2760)));                           // 0976 mov bl, byte ptr [0x2760]
  PUSH(R.bx);                                                  // 097a push bx
  W8(DS, (u16)(0x2760), 0x0);                                  // 097b mov byte ptr [0x2760], 0
  W16(DS, (u16)(0x1593), R.ax);                                // 0980 mov word ptr [0x1593], ax
  W8(DS, (u16)(0x1590), 0x2);                                  // 0983 mov byte ptr [0x1590], 2
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 0988 shl ax, 1
  R.ax = (u16)(SHL16(R.ax, 0x1));                              // 098a shl ax, 1
  R.bx = (u16)(M16(DS, (u16)(0x1595)));                        // 098c mov bx, word ptr [0x1595]
  R.bx = (u16)(ADD16(R.bx, R.ax));                             // 0990 add bx, ax
  R.ax = (u16)(M16(DS, (u16)(R.bx)));                          // 0992 mov ax, word ptr [bx]
  R.bx = (u16)(INC16(R.bx));                                   // 0994 inc bx
  R.bx = (u16)(INC16(R.bx));                                   // 0995 inc bx
  R.cx = (u16)(M16(DS, (u16)(R.bx)));                          // 0996 mov cx, word ptr [bx]
  R.bx = (u16)((u16)(0x2762));                                 // 0998 lea bx, [0x2762]
  PUSH(0x099f); goto L_0960;                                   // 099c call 0x960
L_099f:   R.ax = (u16)(R.cx);                                          // 099f mov ax, cx
  R.bx = (u16)((u16)(0x2780));                                 // 09a1 lea bx, [0x2780]
  PUSH(0x09a8); goto L_0960;                                   // 09a5 call 0x960
L_09a8:   R.bx = POP();                                                // 09a8 pop bx
  W8(DS, (u16)(0x2760), (u8)R.bx);                             // 09a9 mov byte ptr [0x2760], bl
  R.ax = (u16)(M16(DS, (u16)(0x1591)));                        // 09ad mov ax, word ptr [0x1591]
  SETL(R.ax, OR8((u8)R.ax, (u8)R.ax));                         // 09b0 or al, al
  if (R.zf) goto L_09b8;                                       // 09b2 je 0x9b8
  SUB8((u8)R.ax, 0x5);                                         // 09b4 cmp al, 5
  if (!R.zf) goto L_09c3;                                      // 09b6 jne 0x9c3
L_09b8:   SETL(R.ax, M8(DS, (u16)(0x2762)));                           // 09b8 mov al, byte ptr [0x2762]
  SETL(R.ax, OR8((u8)R.ax, M8(DS, (u16)(0x2780))));            // 09bb or al, byte ptr [0x2780]
  SUB8((u8)R.ax, 0x0);                                         // 09bf cmp al, 0
  if (!R.zf) { asm_idle(); goto L_09b8; }  /* a wait for the tick */ // 09c1 jne 0x9b8
L_09c3:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 09c3 ret
L_09c4:   PUSH(R.si);                                                  // 09c4 push si
  PUSH(R.di);                                                  // 09c5 push di
  PUSH(R.bp);                                                  // 09c6 push bp
  PUSH(R.ds);                                                  // 09c7 push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 09c8 mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 09cb mov ds, ax
  PUSH(0x09d0); goto L_006d;                                   // 09cd call 0x6d
L_09d0:   PUSH(0x09d3); goto L_0292;                                   // 09d0 call 0x292
L_09d3:   SUB16(R.ax, 0x0);                                            // 09d3 cmp ax, 0
  if (!R.zf) goto L_09e3;                                      // 09d6 jne 0x9e3
  SETL(R.bx, 0x3f);                                            // 09d8 mov bl, 0x3f
  PUSH(0x09dd); goto L_0227;                                   // 09da call 0x227
L_09dd:   PUSH(0x09e0); goto L_0143;                                   // 09dd call 0x143
L_09e0:   R.ax = (u16)(0x0);                                           // 09e0 mov ax, 0
L_09e3:   R.ds = POP();                                                // 09e3 pop ds
  R.bp = POP();                                                // 09e4 pop bp
  R.di = POP();                                                // 09e5 pop di
  R.si = POP();                                                // 09e6 pop si
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 09e7 retf
L_09e8:   PUSH(R.di);                                                  // 09e8 push di
  PUSH(R.bp);                                                  // 09e9 push bp
  PUSH(R.ds);                                                  // 09ea push ds
  R.ax = (u16)(0xd101 /* segment */);                          // 09eb mov ax, 0x101
  R.ds = (u16)(R.ax);                                          // 09ee mov ds, ax
  PUSH(0x09f3); goto L_0292;                                   // 09f0 call 0x292
L_09f3:   R.ds = POP();                                                // 09f3 pop ds
  R.bp = POP();                                                // 09f4 pop bp
  R.di = POP();                                                // 09f5 pop di
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0xd000) return; goto dispatch_; // 09f6 retf
L_09f8:   SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 09f8 mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 09fb and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 09fe mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x2816)));                    // 0a00 mov al, byte ptr [bx + 0x2816]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a04 and ax, 0xff
  SUB16(R.ax, 0xff);                                           // 0a07 cmp ax, 0xff
  if (!R.zf) goto L_0a10;                                      // 0a0a jne 0xa10
  goto L_0a6a;                                                 // 0a0c jmp 0xa6a
L_0a10:   SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0a10 mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a13 and ax, 0xff
  R.ax = (u16)(OR16(R.ax, 0x90));                              // 0a16 or ax, 0x90
  W8(DS, (u16)(0x275a), (u8)R.ax);                             // 0a19 mov byte ptr [0x275a], al
  SETL(R.ax, M8(DS, (u16)(0x2758)));                           // 0a1c mov al, byte ptr [0x2758]
  SUB8(M8(DS, (u16)(0x275a)), (u8)R.ax);                       // 0a1f cmp byte ptr [0x275a], al
  if (R.zf) goto L_0a3a;                                       // 0a23 je 0xa3a
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0a25 mov al, byte ptr [0x275a]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a28 and ax, 0xff
  PUSH(R.ax);                                                  // 0a2b push ax
  PUSH(0xd000); PUSH(0x0a31); goto L_02d1;                     // 0a2c lcall 0, 0x2d1
L_0a31:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0a31 add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0a34 mov al, byte ptr [0x275a]
  W8(DS, (u16)(0x2758), (u8)R.ax);                             // 0a37 mov byte ptr [0x2758], al
L_0a3a:   SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0a3a mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a3d and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0a40 mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x2816)));                    // 0a42 mov al, byte ptr [bx + 0x2816]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a46 and ax, 0xff
  PUSH(R.ax);                                                  // 0a49 push ax
  PUSH(0xd000); PUSH(0x0a4f); goto L_02d1;                     // 0a4a lcall 0, 0x2d1
L_0a4f:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0a4f add sp, 2
  R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0a52 xor ax, ax
  PUSH(R.ax);                                                  // 0a54 push ax
  PUSH(0xd000); PUSH(0x0a5a); goto L_02d1;                     // 0a55 lcall 0, 0x2d1
L_0a5a:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0a5a add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0a5d mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a60 and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0a63 mov bx, ax
  W8(DS, (u16)(R.bx + 0x2816), 0xff);                          // 0a65 mov byte ptr [bx + 0x2816], 0xff
L_0a6a:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0a6a ret
L_0a6c:   PUSH(R.bp);                                                  // 0a6c push bp
  R.bp = (u16)(R.sp);                                          // 0a6d mov bp, sp
  SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0a6f mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a72 and ax, 0xff
  R.ax = (u16)(OR16(R.ax, 0x90));                              // 0a75 or ax, 0x90
  W8(DS, (u16)(0x275a), (u8)R.ax);                             // 0a78 mov byte ptr [0x275a], al
  SETL(R.ax, M8(DS, (u16)(0x2758)));                           // 0a7b mov al, byte ptr [0x2758]
  SUB8(M8(DS, (u16)(0x275a)), (u8)R.ax);                       // 0a7e cmp byte ptr [0x275a], al
  if (R.zf) goto L_0a99;                                       // 0a82 je 0xa99
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0a84 mov al, byte ptr [0x275a]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a87 and ax, 0xff
  PUSH(R.ax);                                                  // 0a8a push ax
  PUSH(0xd000); PUSH(0x0a90); goto L_02d1;                     // 0a8b lcall 0, 0x2d1
L_0a90:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0a90 add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0a93 mov al, byte ptr [0x275a]
  W8(DS, (u16)(0x2758), (u8)R.ax);                             // 0a96 mov byte ptr [0x2758], al
L_0a99:   SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0a99 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0a9c and ax, 0xff
  PUSH(R.ax);                                                  // 0a9f push ax
  PUSH(0xd000); PUSH(0x0aa5); goto L_02d1;                     // 0aa0 lcall 0, 0x2d1
L_0aa5:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0aa5 add sp, 2
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x6)));                       // 0aa8 mov al, byte ptr [bp + 6]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0aab and ax, 0xff
  PUSH(R.ax);                                                  // 0aae push ax
  PUSH(0xd000); PUSH(0x0ab4); goto L_02d1;                     // 0aaf lcall 0, 0x2d1
L_0ab4:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0ab4 add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0ab7 mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0aba and ax, 0xff
  R.bx = (u16)(R.ax);                                          // 0abd mov bx, ax
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0abf mov al, byte ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x2816), (u8)R.ax);                      // 0ac2 mov byte ptr [bx + 0x2816], al
  R.bp = POP();                                                // 0ac6 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0ac7 ret
L_0ac8:   PUSH(R.bp);                                                  // 0ac8 push bp
  R.bp = (u16)(R.sp);                                          // 0ac9 mov bp, sp
  SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0acb mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ace and ax, 0xff
  R.ax = (u16)(OR16(R.ax, 0xc0));                              // 0ad1 or ax, 0xc0
  W8(DS, (u16)(0x275a), (u8)R.ax);                             // 0ad4 mov byte ptr [0x275a], al
  SETL(R.ax, M8(DS, (u16)(0x2758)));                           // 0ad7 mov al, byte ptr [0x2758]
  SUB8(M8(DS, (u16)(0x275a)), (u8)R.ax);                       // 0ada cmp byte ptr [0x275a], al
  if (R.zf) goto L_0af5;                                       // 0ade je 0xaf5
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0ae0 mov al, byte ptr [0x275a]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ae3 and ax, 0xff
  PUSH(R.ax);                                                  // 0ae6 push ax
  PUSH(0xd000); PUSH(0x0aec); goto L_02d1;                     // 0ae7 lcall 0, 0x2d1
L_0aec:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0aec add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0aef mov al, byte ptr [0x275a]
  W8(DS, (u16)(0x2758), (u8)R.ax);                             // 0af2 mov byte ptr [0x2758], al
L_0af5:   SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0af5 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0af8 and ax, 0xff
  PUSH(R.ax);                                                  // 0afb push ax
  PUSH(0xd000); PUSH(0x0b01); goto L_02d1;                     // 0afc lcall 0, 0x2d1
L_0b01:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b01 add sp, 2
  R.bp = POP();                                                // 0b04 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0b05 ret
L_0b06:   PUSH(R.bp);                                                  // 0b06 push bp
  R.bp = (u16)(R.sp);                                          // 0b07 mov bp, sp
  SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0b09 mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b0c and ax, 0xff
  R.ax = (u16)(OR16(R.ax, 0xb0));                              // 0b0f or ax, 0xb0
  W8(DS, (u16)(0x275a), (u8)R.ax);                             // 0b12 mov byte ptr [0x275a], al
  SETL(R.ax, M8(DS, (u16)(0x2758)));                           // 0b15 mov al, byte ptr [0x2758]
  SUB8(M8(DS, (u16)(0x275a)), (u8)R.ax);                       // 0b18 cmp byte ptr [0x275a], al
  if (R.zf) goto L_0b33;                                       // 0b1c je 0xb33
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0b1e mov al, byte ptr [0x275a]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b21 and ax, 0xff
  PUSH(R.ax);                                                  // 0b24 push ax
  PUSH(0xd000); PUSH(0x0b2a); goto L_02d1;                     // 0b25 lcall 0, 0x2d1
L_0b2a:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b2a add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0b2d mov al, byte ptr [0x275a]
  W8(DS, (u16)(0x2758), (u8)R.ax);                             // 0b30 mov byte ptr [0x2758], al
L_0b33:   R.ax = (u16)(0x7);                                           // 0b33 mov ax, 7
  PUSH(R.ax);                                                  // 0b36 push ax
  PUSH(0xd000); PUSH(0x0b3c); goto L_02d1;                     // 0b37 lcall 0, 0x2d1
L_0b3c:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b3c add sp, 2
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0b3f mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b42 and ax, 0xff
  PUSH(R.ax);                                                  // 0b45 push ax
  PUSH(0xd000); PUSH(0x0b4b); goto L_02d1;                     // 0b46 lcall 0, 0x2d1
L_0b4b:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b4b add sp, 2
  R.bp = POP();                                                // 0b4e pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0b4f ret
L_0b50:   PUSH(R.bp);                                                  // 0b50 push bp
  R.bp = (u16)(R.sp);                                          // 0b51 mov bp, sp
  SETL(R.ax, M8(DS, (u16)(0x2827)));                           // 0b53 mov al, byte ptr [0x2827]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b56 and ax, 0xff
  R.ax = (u16)(OR16(R.ax, 0xe0));                              // 0b59 or ax, 0xe0
  W8(DS, (u16)(0x275a), (u8)R.ax);                             // 0b5c mov byte ptr [0x275a], al
  SETL(R.ax, M8(DS, (u16)(0x2758)));                           // 0b5f mov al, byte ptr [0x2758]
  SUB8(M8(DS, (u16)(0x275a)), (u8)R.ax);                       // 0b62 cmp byte ptr [0x275a], al
  if (R.zf) goto L_0b7d;                                       // 0b66 je 0xb7d
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0b68 mov al, byte ptr [0x275a]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b6b and ax, 0xff
  PUSH(R.ax);                                                  // 0b6e push ax
  PUSH(0xd000); PUSH(0x0b74); goto L_02d1;                     // 0b6f lcall 0, 0x2d1
L_0b74:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b74 add sp, 2
  SETL(R.ax, M8(DS, (u16)(0x275a)));                           // 0b77 mov al, byte ptr [0x275a]
  W8(DS, (u16)(0x2758), (u8)R.ax);                             // 0b7a mov byte ptr [0x2758], al
L_0b7d:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 0b7d xor ax, ax
  PUSH(R.ax);                                                  // 0b7f push ax
  PUSH(0xd000); PUSH(0x0b85); goto L_02d1;                     // 0b80 lcall 0, 0x2d1
L_0b85:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b85 add sp, 2
  SETL(R.ax, M8(SS, (u16)(R.bp + 0x4)));                       // 0b88 mov al, byte ptr [bp + 4]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0b8b and ax, 0xff
  PUSH(R.ax);                                                  // 0b8e push ax
  PUSH(0xd000); PUSH(0x0b94); goto L_02d1;                     // 0b8f lcall 0, 0x2d1
L_0b94:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0b94 add sp, 2
  R.bp = POP();                                                // 0b97 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0b98 ret
L_0b9a:   PUSH(R.bp);                                                  // 0b9a push bp
  R.bp = (u16)(R.sp);                                          // 0b9b mov bp, sp
  R.sp = (u16)(SUB16(R.sp, 0x4));                              // 0b9d sub sp, 4
  PUSH(R.si);                                                  // 0ba1 push si
  PUSH(R.di);                                                  // 0ba2 push di
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ba3 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0ba6 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ba8 and ax, 0xff
  if (!R.zf) goto L_0bb0;                                      // 0bab jne 0xbb0
  goto L_0f1b;                                                 // 0bad jmp 0xf1b
L_0bb0:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0bb0 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x7)));                       // 0bb3 mov al, byte ptr [bx + 7]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bb6 and ax, 0xff
  if (R.zf) goto L_0bcc;                                       // 0bb9 je 0xbcc
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0bbb mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x7), DEC8(M8(DS, (u16)(R.bx + 0x7))));  // 0bbe dec byte ptr [bx + 7]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x7)));                       // 0bc1 mov al, byte ptr [bx + 7]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bc4 and ax, 0xff
  if (!R.zf) goto L_0bcc;                                      // 0bc7 jne 0xbcc
  PUSH(0x0bcc); goto L_09f8;                                   // 0bc9 call 0x9f8
L_0bcc:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0bcc mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx), DEC8(M8(DS, (u16)(R.bx))));              // 0bcf dec byte ptr [bx]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0bd1 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0bd3 and ax, 0xff
  if (R.cf || R.zf) goto L_0bdb;                               // 0bd6 jbe 0xbdb
  goto L_0f1b;                                                 // 0bd8 jmp 0xf1b
L_0bdb:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0bdb mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0bde mov ax, word ptr [bx + 0x12]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0be1 mov word ptr [bp - 2], ax
  R.bx = (u16)(R.ax);                                          // 0be4 mov bx, ax
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0be6 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0be8 cwde
  R.ax = (u16)(AND16(R.ax, 0x80));                             // 0be9 and ax, 0x80
  if (!R.zf) goto L_0bf1;                                      // 0bec jne 0xbf1
  goto L_0e9e;                                                 // 0bee jmp 0xe9e
L_0bf1:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0bf1 mov bx, word ptr [bp - 2]
  SUB8(M8(DS, (u16)(R.bx)), 0xf5);                             // 0bf4 cmp byte ptr [bx], 0xf5
  if (!R.zf && R.sf == R.of) goto L_0bfc;                      // 0bf7 jg 0xbfc
  goto L_0e9e;                                                 // 0bf9 jmp 0xe9e
L_0bfc:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0bfc mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0bff mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0c01 cwde
  goto L_0e4e;                                                 // 0c02 jmp 0xe4e
L_0c06:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c06 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x18)), 0x0);                     // 0c09 cmp word ptr [bx + 0x18], 0
  if (R.zf) goto L_0c12;                                       // 0c0d je 0xc12
  goto L_0c54;                                                 // 0c0f jmp 0xc54
L_0c12:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0c12 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0c15 mov bx, word ptr [bp - 2]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 0c18 cmp byte ptr [bx], 0
  if (!R.zf) goto L_0c3a;                                      // 0c1b jne 0xc3a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c1d mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0c20 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c24 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0c27 mov ax, word ptr [bx + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c2a mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x14), R.ax);                           // 0c2d mov word ptr [bx + 0x14], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c30 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x18), 0x0);                            // 0c33 mov word ptr [bx + 0x18], 0
  goto L_0c52;                                                 // 0c38 jmp 0xc52
L_0c3a:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0c3a mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0c3d mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0c3f cwde
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c40 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x18), R.ax);                           // 0c43 mov word ptr [bx + 0x18], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c46 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x14)));                   // 0c49 mov ax, word ptr [bx + 0x14]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c4c mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 0c4f mov word ptr [bx + 0x12], ax
L_0c52:   goto L_0c84;                                                 // 0c52 jmp 0xc84
L_0c54:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c54 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x18), DEC16(M16(DS, (u16)(R.bx + 0x18)))); // 0c57 dec word ptr [bx + 0x18]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c5a mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x18)), 0x0);                     // 0c5d cmp word ptr [bx + 0x18], 0
  if (!R.zf) goto L_0c78;                                      // 0c61 jne 0xc78
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c63 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0c66 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c6a mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0c6d mov ax, word ptr [bx + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c70 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x14), R.ax);                           // 0c73 mov word ptr [bx + 0x14], ax
  goto L_0c84;                                                 // 0c76 jmp 0xc84
L_0c78:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c78 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x14)));                   // 0c7b mov ax, word ptr [bx + 0x14]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c7e mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 0c81 mov word ptr [bx + 0x12], ax
L_0c84:   goto L_0e9b;                                                 // 0c84 jmp 0xe9b
L_0c88:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c88 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x1a)), 0x0);                     // 0c8b cmp word ptr [bx + 0x1a], 0
  if (R.zf) goto L_0c94;                                       // 0c8f je 0xc94
  goto L_0ce0;                                                 // 0c91 jmp 0xce0
L_0c94:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0c94 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0c97 mov bx, word ptr [bp - 2]
  SUB8(M8(DS, (u16)(R.bx)), 0x0);                              // 0c9a cmp byte ptr [bx], 0
  if (!R.zf) goto L_0cc4;                                      // 0c9d jne 0xcc4
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0c9f mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0ca2 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ca6 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0ca9 mov ax, word ptr [bx + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cac mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 0caf mov word ptr [bx + 0x16], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cb2 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x18), 0x0);                            // 0cb5 mov word ptr [bx + 0x18], 0
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cba mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x1a), 0x0);                            // 0cbd mov word ptr [bx + 0x1a], 0
  goto L_0cdc;                                                 // 0cc2 jmp 0xcdc
L_0cc4:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0cc4 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0cc7 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0cc9 cwde
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cca mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x1a), R.ax);                           // 0ccd mov word ptr [bx + 0x1a], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cd0 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x16)));                   // 0cd3 mov ax, word ptr [bx + 0x16]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cd6 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 0cd9 mov word ptr [bx + 0x12], ax
L_0cdc:   goto L_0d1c;                                                 // 0cdc jmp 0xd1c
L_0ce0:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ce0 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x1a), DEC16(M16(DS, (u16)(R.bx + 0x1a)))); // 0ce3 dec word ptr [bx + 0x1a]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ce6 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x1a)), 0x0);                     // 0ce9 cmp word ptr [bx + 0x1a], 0
  if (!R.zf) goto L_0d10;                                      // 0ced jne 0xd10
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cef mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0cf2 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cf6 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0cf9 mov ax, word ptr [bx + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0cfc mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x16), R.ax);                           // 0cff mov word ptr [bx + 0x16], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d02 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0d05 mov ax, word ptr [bx + 0x12]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d08 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x14), R.ax);                           // 0d0b mov word ptr [bx + 0x14], ax
  goto L_0d1c;                                                 // 0d0e jmp 0xd1c
L_0d10:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d10 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x16)));                   // 0d13 mov ax, word ptr [bx + 0x16]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d16 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 0d19 mov word ptr [bx + 0x12], ax
L_0d1c:   goto L_0e9b;                                                 // 0d1c jmp 0xe9b
L_0d20:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d20 mov bx, word ptr [bp + 4]
  SUB16(M16(DS, (u16)(R.bx + 0x1c)), 0x0);                     // 0d23 cmp word ptr [bx + 0x1c], 0
  if (!R.zf) goto L_0d38;                                      // 0d27 jne 0xd38
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d29 mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x10)));                   // 0d2c mov ax, word ptr [bx + 0x10]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d2f mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), R.ax);                           // 0d32 mov word ptr [bx + 0x12], ax
  goto L_0d3e;                                                 // 0d35 jmp 0xd3e
L_0d38:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d38 mov bx, word ptr [bp + 4]
  { u16 t_ = M16(DS, (u16)(R.bx + 0x1c)); PUSH(0x0d3e); ip_ = t_; goto dispatch_; } // 0d3b call word ptr [bx + 0x1c]
L_0d3e:   goto L_0e9b;                                                 // 0d3e jmp 0xe9b
L_0d42:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0d42 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0d45 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0d48 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d4a mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x4), (u8)R.ax);                         // 0d4d mov byte ptr [bx + 4], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d50 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0d53 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0d57 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0d5a mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0d5c cwde
  PUSH(R.ax);                                                  // 0d5d push ax
  PUSH(0x0d61); goto L_0ac8;                                   // 0d5e call 0xac8
L_0d61:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0d61 add sp, 2
  goto L_0e9b;                                                 // 0d64 jmp 0xe9b
L_0d68:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0d68 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0d6b mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0d6e mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d70 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x6), (u8)R.ax);                         // 0d73 mov byte ptr [bx + 6], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d76 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0d79 add word ptr [bx + 0x12], 2
  goto L_0e9b;                                                 // 0d7d jmp 0xe9b
L_0d80:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0d80 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0d83 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0d86 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d88 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xd), (u8)R.ax);                         // 0d8b mov byte ptr [bx + 0xd], al
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0d8e inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0d91 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0d94 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0d96 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x1), (u8)R.ax);                         // 0d99 mov byte ptr [bx + 1], al
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0d9c inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0d9f mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0da2 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0da4 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xe), (u8)R.ax);                         // 0da7 mov byte ptr [bx + 0xe], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0daa mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x9), 0x1);                              // 0dad mov byte ptr [bx + 9], 1
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0db1 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x4)); // 0db4 add word ptr [bx + 0x12], 4
  goto L_0e9b;                                                 // 0db8 jmp 0xe9b
L_0dbc:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0dbc inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0dbf mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0dc2 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0dc4 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x5), (u8)R.ax);                         // 0dc7 mov byte ptr [bx + 5], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0dca mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0dcd add word ptr [bx + 0x12], 2
  goto L_0e9b;                                                 // 0dd1 jmp 0xe9b
L_0dd4:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0dd4 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0dd7 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0dda mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ddc mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xc), (u8)R.ax);                         // 0ddf mov byte ptr [bx + 0xc], al
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0de2 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0de5 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0de8 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0dea mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x2), (u8)R.ax);                         // 0ded mov byte ptr [bx + 2], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0df0 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x8), 0x1);                              // 0df3 mov byte ptr [bx + 8], 1
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0df7 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x3)); // 0dfa add word ptr [bx + 0x12], 3
  goto L_0e9b;                                                 // 0dfe jmp 0xe9b
L_0e02:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0e02 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0e05 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0e08 mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0e0a mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xb), (u8)R.ax);                         // 0e0d mov byte ptr [bx + 0xb], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0e10 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0e13 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0e17 mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0e1a mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0e1c cwde
  PUSH(R.ax);                                                  // 0e1d push ax
  PUSH(0x0e21); goto L_0b50;                                   // 0e1e call 0xb50
L_0e21:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0e21 add sp, 2
  goto L_0e9b;                                                 // 0e24 jmp 0xe9b
L_0e28:   W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0e28 inc word ptr [bp - 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0e2b mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0e2e mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0e30 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xa), (u8)R.ax);                         // 0e33 mov byte ptr [bx + 0xa], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0e36 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0e39 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0e3d mov bx, word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0e40 mov al, byte ptr [bx]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0e42 cwde
  PUSH(R.ax);                                                  // 0e43 push ax
  PUSH(0x0e47); goto L_0b06;                                   // 0e44 call 0xb06
L_0e47:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0e47 add sp, 2
  goto L_0e9b;                                                 // 0e4a jmp 0xe9b
L_0e4e:   SUB16(R.ax, 0xfff6);                                         // 0e4e cmp ax, 0xfff6
  if (R.zf) goto L_0e28;                                       // 0e51 je 0xe28
  SUB16(R.ax, 0xfff7);                                         // 0e53 cmp ax, 0xfff7
  if (!R.zf) goto L_0e5b;                                      // 0e56 jne 0xe5b
  goto L_0e02;                                                 // 0e58 jmp 0xe02
L_0e5b:   SUB16(R.ax, 0xfff8);                                         // 0e5b cmp ax, 0xfff8
  if (!R.zf) goto L_0e63;                                      // 0e5e jne 0xe63
  goto L_0dd4;                                                 // 0e60 jmp 0xdd4
L_0e63:   SUB16(R.ax, 0xfff9);                                         // 0e63 cmp ax, 0xfff9
  if (!R.zf) goto L_0e6b;                                      // 0e66 jne 0xe6b
  goto L_0dbc;                                                 // 0e68 jmp 0xdbc
L_0e6b:   SUB16(R.ax, 0xfffa);                                         // 0e6b cmp ax, 0xfffa
  if (!R.zf) goto L_0e73;                                      // 0e6e jne 0xe73
  goto L_0d80;                                                 // 0e70 jmp 0xd80
L_0e73:   SUB16(R.ax, 0xfffb);                                         // 0e73 cmp ax, 0xfffb
  if (!R.zf) goto L_0e7b;                                      // 0e76 jne 0xe7b
  goto L_0d68;                                                 // 0e78 jmp 0xd68
L_0e7b:   SUB16(R.ax, 0xfffc);                                         // 0e7b cmp ax, 0xfffc
  if (!R.zf) goto L_0e83;                                      // 0e7e jne 0xe83
  goto L_0d42;                                                 // 0e80 jmp 0xd42
L_0e83:   SUB16(R.ax, 0xfffd);                                         // 0e83 cmp ax, 0xfffd
  if (!R.zf) goto L_0e8b;                                      // 0e86 jne 0xe8b
  goto L_0d20;                                                 // 0e88 jmp 0xd20
L_0e8b:   SUB16(R.ax, 0xfffe);                                         // 0e8b cmp ax, 0xfffe
  if (!R.zf) goto L_0e93;                                      // 0e8e jne 0xe93
  goto L_0c88;                                                 // 0e90 jmp 0xc88
L_0e93:   SUB16(R.ax, 0xffff);                                         // 0e93 cmp ax, 0xffff
  if (!R.zf) goto L_0e9b;                                      // 0e96 jne 0xe9b
  goto L_0c06;                                                 // 0e98 jmp 0xc06
L_0e9b:   goto L_0bdb;                                                 // 0e9b jmp 0xbdb
L_0e9e:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0e9e mov bx, word ptr [bp + 4]
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x12)));                   // 0ea1 mov ax, word ptr [bx + 0x12]
  W16(SS, (u16)(R.bp + 0xfffe), R.ax);                         // 0ea4 mov word ptr [bp - 2], ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0ea7 mov bx, word ptr [bp - 2]
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0eaa inc word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0ead mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0eaf mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx), (u8)R.ax);                               // 0eb2 mov byte ptr [bx], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0xfffe)));                 // 0eb4 mov bx, word ptr [bp - 2]
  W16(SS, (u16)(R.bp + 0xfffe), INC16(M16(SS, (u16)(R.bp + 0xfffe)))); // 0eb7 inc word ptr [bp - 2]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0eba mov al, byte ptr [bx]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ebc mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x3), (u8)R.ax);                         // 0ebf mov byte ptr [bx + 3], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ec2 mov bx, word ptr [bp + 4]
  W16(DS, (u16)(R.bx + 0x12), ADD16(M16(DS, (u16)(R.bx + 0x12)), 0x2)); // 0ec5 add word ptr [bx + 0x12], 2
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ec9 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x3)));                       // 0ecc mov al, byte ptr [bx + 3]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ecf and ax, 0xff
  if (R.zf) goto L_0ede;                                       // 0ed2 je 0xede
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ed4 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0ed7 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ed9 and ax, 0xff
  if (!R.zf) goto L_0ee4;                                      // 0edc jne 0xee4
L_0ede:   PUSH(0x0ee1); goto L_09f8;                                   // 0ede call 0x9f8
L_0ee1:   goto L_0f1b;                                                 // 0ee1 jmp 0xf1b
L_0ee4:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0ee4 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx)));                             // 0ee7 mov al, byte ptr [bx]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0ee9 and ax, 0xff
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0eec mov bx, word ptr [bp + 4]
  W16(SS, (u16)(R.bp + 0xfffc), R.ax);                         // 0eef mov word ptr [bp - 4], ax
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x6)));                       // 0ef2 mov al, byte ptr [bx + 6]
  R.ax = (u16)(i16)(i8)R.ax;                                   // 0ef5 cwde
  R.cx = (u16)(M16(SS, (u16)(R.bp + 0xfffc)));                 // 0ef6 mov cx, word ptr [bp - 4]
  R.cx = (u16)(SUB16(R.cx, R.ax));                             // 0ef9 sub cx, ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0efb mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x7), (u8)R.cx);                         // 0efe mov byte ptr [bx + 7], cl
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f01 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x5)));                       // 0f04 mov al, byte ptr [bx + 5]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f07 and ax, 0xff
  PUSH(R.ax);                                                  // 0f0a push ax
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f0b mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x3)));                       // 0f0e mov al, byte ptr [bx + 3]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f11 and ax, 0xff
  PUSH(R.ax);                                                  // 0f14 push ax
  PUSH(0x0f18); goto L_0a6c;                                   // 0f15 call 0xa6c
L_0f18:   R.sp = (u16)(ADD16(R.sp, 0x4));                              // 0f18 add sp, 4
L_0f1b:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f1b mov bx, word ptr [bp + 4]
  SUB8(M8(DS, (u16)(R.bx + 0x2)), 0x0);                        // 0f1e cmp byte ptr [bx + 2], 0
  if (R.zf) goto L_0f5a;                                       // 0f22 je 0xf5a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f24 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x8), DEC8(M8(DS, (u16)(R.bx + 0x8))));  // 0f27 dec byte ptr [bx + 8]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x8)));                       // 0f2a mov al, byte ptr [bx + 8]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f2d and ax, 0xff
  if (!R.zf) goto L_0f5a;                                      // 0f30 jne 0xf5a
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f32 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xc)));                       // 0f35 mov al, byte ptr [bx + 0xc]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f38 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x8), (u8)R.ax);                         // 0f3b mov byte ptr [bx + 8], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f3e mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x2)));                       // 0f41 mov al, byte ptr [bx + 2]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f44 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xa), ADD8(M8(DS, (u16)(R.bx + 0xa)), (u8)R.ax)); // 0f47 add byte ptr [bx + 0xa], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f4a mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xa)));                       // 0f4d mov al, byte ptr [bx + 0xa]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f50 and ax, 0xff
  PUSH(R.ax);                                                  // 0f53 push ax
  PUSH(0x0f57); goto L_0b06;                                   // 0f54 call 0xb06
L_0f57:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0f57 add sp, 2
L_0f5a:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f5a mov bx, word ptr [bp + 4]
  SUB8(M8(DS, (u16)(R.bx + 0x1)), 0x0);                        // 0f5d cmp byte ptr [bx + 1], 0
  if (!R.zf) goto L_0f66;                                      // 0f61 jne 0xf66
  goto L_0fb0;                                                 // 0f63 jmp 0xfb0
L_0f66:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f66 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x9), DEC8(M8(DS, (u16)(R.bx + 0x9))));  // 0f69 dec byte ptr [bx + 9]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x9)));                       // 0f6c mov al, byte ptr [bx + 9]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f6f and ax, 0xff
  if (!R.zf) goto L_0f9c;                                      // 0f72 jne 0xf9c
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f74 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xd)));                       // 0f77 mov al, byte ptr [bx + 0xd]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f7a mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x9), (u8)R.ax);                         // 0f7d mov byte ptr [bx + 9], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f80 mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0x1)));                       // 0f83 mov al, byte ptr [bx + 1]
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f86 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xb), ADD8(M8(DS, (u16)(R.bx + 0xb)), (u8)R.ax)); // 0f89 add byte ptr [bx + 0xb], al
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f8c mov bx, word ptr [bp + 4]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xb)));                       // 0f8f mov al, byte ptr [bx + 0xb]
  R.ax = (u16)(AND16(R.ax, 0xff));                             // 0f92 and ax, 0xff
  PUSH(R.ax);                                                  // 0f95 push ax
  PUSH(0x0f99); goto L_0b50;                                   // 0f96 call 0xb50
L_0f99:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0f99 add sp, 2
L_0f9c:   R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0f9c mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0xe), DEC8(M8(DS, (u16)(R.bx + 0xe))));  // 0f9f dec byte ptr [bx + 0xe]
  SETL(R.ax, M8(DS, (u16)(R.bx + 0xe)));                       // 0fa2 mov al, byte ptr [bx + 0xe]
  SETL(R.ax, AND8((u8)R.ax, (u8)R.ax));                        // 0fa5 and al, al
  if (!R.zf) goto L_0fb0;                                      // 0fa7 jne 0xfb0
  R.bx = (u16)(M16(SS, (u16)(R.bp + 0x4)));                    // 0fa9 mov bx, word ptr [bp + 4]
  W8(DS, (u16)(R.bx + 0x1), 0x0);                              // 0fac mov byte ptr [bx + 1], 0
L_0fb0:   W8(DS, (u16)(0x2827), INC8(M8(DS, (u16)(0x2827))));          // 0fb0 inc byte ptr [0x2827]
  R.di = POP();                                                // 0fb4 pop di
  R.si = POP();                                                // 0fb5 pop si
  R.sp = (u16)(R.bp);                                          // 0fb6 mov sp, bp
  R.bp = POP();                                                // 0fb8 pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0fb9 ret
L_0fba:   SUB8(M8(DS, (u16)(0x2760)), 0x0);                            // 0fba cmp byte ptr [0x2760], 0
  if (!R.zf) goto L_0fc4;                                      // 0fbf jne 0xfc4
  goto L_1005;                                                 // 0fc1 jmp 0x1005
L_0fc4:   W8(DS, (u16)(0x2827), 0x1);                                  // 0fc4 mov byte ptr [0x2827], 1
  R.ax = (u16)(0x2762);                                        // 0fc9 mov ax, 0x2762
  PUSH(R.ax);                                                  // 0fcc push ax
  PUSH(0x0fd0); goto L_0b9a;                                   // 0fcd call 0xb9a
L_0fd0:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0fd0 add sp, 2
  R.ax = (u16)(0x2780);                                        // 0fd3 mov ax, 0x2780
  PUSH(R.ax);                                                  // 0fd6 push ax
  PUSH(0x0fda); goto L_0b9a;                                   // 0fd7 call 0xb9a
L_0fda:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0fda add sp, 2
  R.ax = (u16)(0x279e);                                        // 0fdd mov ax, 0x279e
  PUSH(R.ax);                                                  // 0fe0 push ax
  PUSH(0x0fe4); goto L_0b9a;                                   // 0fe1 call 0xb9a
L_0fe4:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0fe4 add sp, 2
  R.ax = (u16)(0x27bc);                                        // 0fe7 mov ax, 0x27bc
  PUSH(R.ax);                                                  // 0fea push ax
  PUSH(0x0fee); goto L_0b9a;                                   // 0feb call 0xb9a
L_0fee:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0fee add sp, 2
  R.ax = (u16)(0x27da);                                        // 0ff1 mov ax, 0x27da
  PUSH(R.ax);                                                  // 0ff4 push ax
  PUSH(0x0ff8); goto L_0b9a;                                   // 0ff5 call 0xb9a
L_0ff8:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 0ff8 add sp, 2
  R.ax = (u16)(0x27f8);                                        // 0ffb mov ax, 0x27f8
  PUSH(R.ax);                                                  // 0ffe push ax
  PUSH(0x1002); goto L_0b9a;                                   // 0fff call 0xb9a
L_1002:   R.sp = (u16)(ADD16(R.sp, 0x2));                              // 1002 add sp, 2
L_1005:   ip_ = POP(); R.sp += 0; goto dispatch_;                      // 1005 ret
}

// the driver's slots: slot 0 + k runs the k-th entry, with the caller's far return address on the stack
void rs_slot(int slot)
{
  static const u16 entries[] = { 0x0905, 0x0914, 0x0930, 0x0944, 0x0945, 0x09c4, 0x09e8 };
  if (slot >= 0 && slot < 7) rs_0000_run(entries[slot - 0]);
}
