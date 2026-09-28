#include "asm2c.h"

// MI: each code segment as one function: calls push their return addresses as the original's,
// returns jump through the dispatch below (so the routines that pop their own return address, or jump
// into another one's epilogue, work); a far return to another segment leaves the function

void mi_0000_run(u16 entry);

void mi_0000_run(u16 entry)
{
  u16 ip_ = entry, cs_ = 0;
  (void)cs_;
  R.cs = 0x1983;
dispatch_:
  switch (ip_)
  {
  case 0x0042: goto L_0042;
  case 0x0047: goto L_0047;
  case 0x004c: goto L_004c;
  case 0x0055: goto L_0055;
  case 0x005a: goto L_005a;
  case 0x006c: goto L_006c;
  case 0x0080: goto L_0080;
  case 0x0089: goto L_0089;
  case 0x008f: goto L_008f;
  case 0x0095: goto L_0095;
  case 0x0097: goto L_0097;
  case 0x00aa: goto L_00aa;
  case 0x00b3: goto L_00b3;
  case 0x00b9: goto L_00b9;
  case 0x00bf: goto L_00bf;
  case 0x00c4: goto L_00c4;
  case 0x00d3: goto L_00d3;
  case 0x00d5: goto L_00d5;
  case 0x00e6: goto L_00e6;
  case 0x00f1: goto L_00f1;
  case 0x0106: goto L_0106;
  case 0x011b: goto L_011b;
  case 0x0128: goto L_0128;
  case 0x013b: goto L_013b;
  case 0x0143: goto L_0143;
  default: asm_unknown_call(0x1983, ip_); return;
  }
L_0042:   SETH(R.ax, 0x1);                                             // 0042 mov ah, 1
  ASM_INT(0x21);                                               // 0044 int 0x21
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 0046 retf
L_0047:   SETH(R.ax, SUB8((u8)(R.ax >> 8), (u8)(R.ax >> 8)));          // 0047 sub ah, ah
  ASM_INT(0x16);                                               // 0049 int 0x16
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 004b retf
L_004c:   SETH(R.ax, 0x1);                                             // 004c mov ah, 1
  ASM_INT(0x16);                                               // 004e int 0x16
  if (R.zf) goto L_0055;                                       // 0050 je 0x55
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0052 sub ax, ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 0054 retf
L_0055:   R.ax = (u16)(SUB16(R.ax, R.ax));                             // 0055 sub ax, ax
  R.ax = (u16)((u16)~R.ax);                                    // 0057 not ax
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 0059 retf
L_005a:   PUSH(R.es);                                                  // 005a push es
  R.ax = (u16)(SUB16(R.ax, R.ax));                             // 005b sub ax, ax
  R.es = (u16)(R.ax);                                          // 005d mov es, ax
  SETL(R.ax, M8(ES, (u16)(0x417)));                            // 005f mov al, byte ptr es:[0x417]
  SETL(R.ax, AND8((u8)R.ax, 0xf0));                            // 0063 and al, 0xf0
  W8(ES, (u16)(0x417), (u8)R.ax);                              // 0065 mov byte ptr es:[0x417], al
  R.es = POP();                                                // 0069 pop es
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 006a retf
L_006c:   R.bx = (u16)(R.sp);                                          // 006c mov bx, sp
  R.dx = (u16)(0x201);                                         // 006e mov dx, 0x201
  SETL(R.ax, ASM_PORT_IN(R.dx));                               // 0071 in al, dx
  SETL(R.ax, (u8)~(u8)R.ax);                                   // 0072 not al
  R.cx = (u16)(M16(DS, (u16)(R.bx + 0x4)));                    // 0074 mov cx, word ptr [bx + 4]
  R.cx = (u16)(ADD16(R.cx, 0x4));                              // 0077 add cx, 4
  SETL(R.ax, SHR8((u8)R.ax, (u8)R.cx));                        // 007a shr al, cl
  R.ax = (u16)(AND16(R.ax, 0x1));                              // 007c and ax, 1
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 007f retf
L_0080:   PUSH(R.ds);                                                  // 0080 push ds
  R.ax = (u16)(0x1998 /* segment */);                          // 0081 mov ax, 0x15
  R.ds = (u16)(R.ax);                                          // 0084 mov ds, ax
  PUSH(0x0089); goto L_00c4;                                   // 0086 call 0xc4
L_0089:   R.bx = (u16)(0x0);                                           // 0089 mov bx, 0
  PUSH(0x008f); goto L_0097;                                   // 008c call 0x97
L_008f:   R.bx = (u16)(0x1);                                           // 008f mov bx, 1
  PUSH(0x0095); goto L_0097;                                   // 0092 call 0x97
L_0095:   R.ds = POP();                                                // 0095 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 0096 retf
L_0097:   R.bx = (u16)(SHL16(R.bx, 0x1));                              // 0097 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x78)));                   // 0099 mov ax, word ptr [bx + 0x78]
  W16(DS, (u16)(R.bx + 0x70), R.ax);                           // 009d mov word ptr [bx + 0x70], ax
  W16(DS, (u16)(R.bx + 0x60), R.ax);                           // 00a1 mov word ptr [bx + 0x60], ax
  W16(DS, (u16)(R.bx + 0x68), R.ax);                           // 00a5 mov word ptr [bx + 0x68], ax
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 00a9 ret
L_00aa:   PUSH(R.ds);                                                  // 00aa push ds
  R.ax = (u16)(0x1998 /* segment */);                          // 00ab mov ax, 0x15
  R.ds = (u16)(R.ax);                                          // 00ae mov ds, ax
  PUSH(0x00b3); goto L_00c4;                                   // 00b0 call 0xc4
L_00b3:   R.bx = (u16)(0x0);                                           // 00b3 mov bx, 0
  PUSH(0x00b9); goto L_00f1;                                   // 00b6 call 0xf1
L_00b9:   R.bx = (u16)(0x1);                                           // 00b9 mov bx, 1
  PUSH(0x00bf); goto L_00f1;                                   // 00bc call 0xf1
L_00bf:   R.ax = (u16)(M16(DS, (u16)(0x80)));                          // 00bf mov ax, word ptr [0x80]
  R.ds = POP();                                                // 00c2 pop ds
  ip_ = POP(); cs_ = POP(); R.sp += 0; if (cs_ != 0x1983) return; goto dispatch_; // 00c3 retf
L_00c4:   PUSH(R.bp);                                                  // 00c4 push bp
  R.bx = (u16)(XOR16(R.bx, R.bx));                             // 00c5 xor bx, bx
  R.bp = (u16)(XOR16(R.bp, R.bp));                             // 00c7 xor bp, bp
  R.cx = (u16)(0xffff);                                        // 00c9 mov cx, 0xffff
  R.dx = (u16)(0x201);                                         // 00cc mov dx, 0x201
  // 00cf cli 
  ASM_PORT_OUT(R.dx, (u8)R.ax);                                // 00d0 out dx, al
  goto L_00d3;                                                 // 00d1 jmp 0xd3
L_00d3:   goto L_00d5;                                                 // 00d3 jmp 0xd5
L_00d5:   SETL(R.ax, ASM_PORT_IN(R.dx));                               // 00d5 in al, dx
  SETL(R.ax, AND8((u8)R.ax, 0x3));                             // 00d6 and al, 3
  if (R.zf) goto L_00e6;                                       // 00d8 je 0xe6
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 00da shr al, 1
  R.bx = (u16)(ADC16(R.bx, 0x0));                              // 00dc adc bx, 0
  SETL(R.ax, SHR8((u8)R.ax, 0x1));                             // 00df shr al, 1
  R.bp = (u16)(ADC16(R.bp, 0x0));                              // 00e1 adc bp, 0
  if (--R.cx != 0) goto L_00d5;                                // 00e4 loop 0xd5
L_00e6:                                                                // 00e6 sti
  W16(DS, (u16)(0x78), R.bx);                                  // 00e7 mov word ptr [0x78], bx
  W16(DS, (u16)(0x7a), R.bp);                                  // 00eb mov word ptr [0x7a], bp
  R.bp = POP();                                                // 00ef pop bp
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 00f0 ret
L_00f1:   R.bx = (u16)(SHL16(R.bx, 0x1));                              // 00f1 shl bx, 1
  R.ax = (u16)(M16(DS, (u16)(R.bx + 0x78)));                   // 00f3 mov ax, word ptr [bx + 0x78]
  R.dx = (u16)(R.ax);                                          // 00f7 mov dx, ax
  R.dx = (u16)(SUB16(R.dx, M16(DS, (u16)(R.bx + 0x70))));      // 00f9 sub dx, word ptr [bx + 0x70]
  if (R.cf) goto L_0106;                                       // 00fd jb 0x106
  if (!R.cf && !R.zf) goto L_0128;                             // 00ff ja 0x128
  SETH(R.ax, 0x0);                                             // 0101 mov ah, 0
  goto L_0143;                                                 // 0103 jmp 0x143
L_0106:   R.dx = (u16)(NEG16(R.dx));                                   // 0106 neg dx
  SUB16(R.ax, M16(DS, (u16)(R.bx + 0x60)));                    // 0108 cmp ax, word ptr [bx + 0x60]
  if (!R.cf && !R.zf) goto L_011b;                             // 010c ja 0x11b
  W16(DS, (u16)(R.bx + 0x60), R.ax);                           // 010e mov word ptr [bx + 0x60], ax
  W16(DS, (u16)(R.bx + 0x50), R.dx);                           // 0112 mov word ptr [bx + 0x50], dx
  SETH(R.ax, 0x81);                                            // 0116 mov ah, 0x81
  goto L_0143;                                                 // 0118 jmp 0x143
L_011b:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 011b xor ax, ax
  DIV16(M16(DS, (u16)(R.bx + 0x50)), 0x011d);                  // 011d div word ptr [bx + 0x50]
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0121 shr ax, 1
  R.ax = (u16)(NEG16(R.ax));                                   // 0123 neg ax
  goto L_0143;                                                 // 0125 jmp 0x143
L_0128:   SUB16(R.ax, M16(DS, (u16)(R.bx + 0x68)));                    // 0128 cmp ax, word ptr [bx + 0x68]
  if (R.cf) goto L_013b;                                       // 012c jb 0x13b
  W16(DS, (u16)(R.bx + 0x68), R.ax);                           // 012e mov word ptr [bx + 0x68], ax
  W16(DS, (u16)(R.bx + 0x58), R.dx);                           // 0132 mov word ptr [bx + 0x58], dx
  SETH(R.ax, 0x7f);                                            // 0136 mov ah, 0x7f
  goto L_0143;                                                 // 0138 jmp 0x143
L_013b:   R.ax = (u16)(XOR16(R.ax, R.ax));                             // 013b xor ax, ax
  DIV16(M16(DS, (u16)(R.bx + 0x58)), 0x013d);                  // 013d div word ptr [bx + 0x58]
  R.ax = (u16)(SHR16(R.ax, 0x1));                              // 0141 shr ax, 1
L_0143:   R.bx = (u16)(SHR16(R.bx, 0x1));                              // 0143 shr bx, 1
  W8(DS, (u16)(R.bx + 0x80), (u8)(R.ax >> 8));                 // 0145 mov byte ptr [bx + 0x80], ah
  ip_ = POP(); R.sp += 0; goto dispatch_;                      // 0149 ret
}

// the driver's slots: slot 90 + k runs the k-th entry, with the caller's far return address on the stack
void mi_slot(int slot)
{
  static const u16 entries[] = { 0x004c, 0x0047, 0x0042, 0x005a, 0x005a, 0x006c, 0x0080, 0x00aa };
  if (slot >= 90 && slot < 98) mi_0000_run(entries[slot - 90]);
}
