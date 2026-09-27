// The emulated 8086 that the recompiled functions (the workspace's work/asm2c.py: functions whose decompilation
// failed, recompiled statement for statement from the machine code) run on: the registers and flags, memory
// through the segment registers (far_ptr: the data segment image, the shared block, the rest of the
// megabyte), the stack in the data segment as on the 8086 (SS = DS, the stack pointer shared with the
// translated C through g_sp), and the calls between recompiled and C code.
#ifndef OPENSAMURAI_ASM2C_H
#define OPENSAMURAI_ASM2C_H

#include "dsimage.h"

typedef struct
{
  u16 ax, bx, cx, dx, si, di, bp, sp, es, ds, ss, cs;
  bool cf, zf, sf, of, pf, af, df;
} Regs;
extern Regs R;

// memory
#define SEGV_DS R.ds
#define SEGV_ES R.es
#define SEGV_SS R.ss
#define SEGV_CS R.cs
#define M8(s, a) (*(u8a *)far_ptr(SEGV_##s, (u16)(a)))
#define M16(s, a) (*(u16a *)far_ptr(SEGV_##s, (u16)(a)))
#define W8(s, a, v) (M8(s, a) = (u8)(v))
#define W16(s, a, v) (M16(s, a) = (u16)(v))
#define SETL(r, v) ((r) = (u16)(((r) & 0xFF00) | (u8)(v)))
#define SETH(r, v) ((r) = (u16)(((r) & 0x00FF) | ((u16)(u8)(v) << 8)))

// the stack
#define PUSH(v) \
  do { \
    u16 v_ = (u16)(v); \
    R.sp -= 2; \
    M16(SS, R.sp) = v_; \
  } while (0)
static inline u16 asm_pop(void)
{
  u16 v = M16(SS, R.sp);
  R.sp += 2;
  return v;
}
#define POP() asm_pop()
#define ARG(k) M16(SS, (u16)(R.sp + 2 * (k)))

// entry (the wrapper pushes the arguments and a return address) and exit; entered from C, DS and SS are the
// data segment, entered from recompiled code (g_asmCall) the registers are as the caller left them
extern bool g_asmCall;
#define ASM_ENTER() \
  u16 asm_entry_sp_ = g_sp; \
  R.sp = g_sp; \
  if (!g_asmCall) R.ds = R.ss = g_dsSeg; \
  g_asmCall = 0
#define ASM_LEAVE() (g_sp = asm_entry_sp_, R.sp = asm_entry_sp_)
// a call from recompiled code: the callee's frame goes below the return address; the caller's stack pointer
// comes back as it was (the callee's own return pops it)
#define CALL_BEGIN(retbytes) \
  { \
    u16 csp_ = R.sp; \
    g_sp = (u16)(csp_ - (retbytes))
#define CALL_END() \
  R.sp = csp_; \
  g_sp = csp_; \
  }

// flags
static inline bool asm_parity(u8 v)
{
  v ^= v >> 4;
  v ^= v >> 2;
  v ^= v >> 1;
  return !(v & 1);
}
#define FLAGS_SZP8(r) (R.zf = (u8)(r) == 0, R.sf = ((r) & 0x80) != 0, R.pf = asm_parity((u8)(r)))
#define FLAGS_SZP16(r) (R.zf = (u16)(r) == 0, R.sf = ((r) & 0x8000) != 0, R.pf = asm_parity((u8)(r)))
static inline u8 ADD8(u8 a, u8 b) { unsigned r = a + b; R.cf = r > 0xFF; R.of = ((a ^ r) & (b ^ r) & 0x80) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP8(r); return (u8)r; }
static inline u16 ADD16(u16 a, u16 b) { unsigned r = a + b; R.cf = r > 0xFFFF; R.of = ((a ^ r) & (b ^ r) & 0x8000) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP16(r); return (u16)r; }
static inline u8 ADC8(u8 a, u8 b) { unsigned r = a + b + R.cf; R.cf = r > 0xFF; R.of = ((a ^ r) & (b ^ r) & 0x80) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP8(r); return (u8)r; }
static inline u16 ADC16(u16 a, u16 b) { unsigned r = a + b + R.cf; R.cf = r > 0xFFFF; R.of = ((a ^ r) & (b ^ r) & 0x8000) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP16(r); return (u16)r; }
static inline u8 SUB8(u8 a, u8 b) { unsigned r = (unsigned)a - b; R.cf = a < b; R.of = ((a ^ b) & (a ^ r) & 0x80) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP8(r); return (u8)r; }
static inline u16 SUB16(u16 a, u16 b) { unsigned r = (unsigned)a - b; R.cf = a < b; R.of = ((a ^ b) & (a ^ r) & 0x8000) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP16(r); return (u16)r; }
static inline u8 SBB8(u8 a, u8 b) { unsigned c = R.cf, r = (unsigned)a - b - c; R.cf = (unsigned)a < (unsigned)b + c; R.of = ((a ^ b) & (a ^ r) & 0x80) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP8(r); return (u8)r; }
static inline u16 SBB16(u16 a, u16 b) { unsigned c = R.cf, r = (unsigned)a - b - c; R.cf = (unsigned)a < (unsigned)b + c; R.of = ((a ^ b) & (a ^ r) & 0x8000) != 0; R.af = ((a ^ b ^ r) & 0x10) != 0; FLAGS_SZP16(r); return (u16)r; }
static inline u8 AND8(u8 a, u8 b) { u8 r = a & b; R.cf = R.of = 0; FLAGS_SZP8(r); return r; }
static inline u16 AND16(u16 a, u16 b) { u16 r = a & b; R.cf = R.of = 0; FLAGS_SZP16(r); return r; }
static inline u8 OR8(u8 a, u8 b) { u8 r = a | b; R.cf = R.of = 0; FLAGS_SZP8(r); return r; }
static inline u16 OR16(u16 a, u16 b) { u16 r = a | b; R.cf = R.of = 0; FLAGS_SZP16(r); return r; }
static inline u8 XOR8(u8 a, u8 b) { u8 r = a ^ b; R.cf = R.of = 0; FLAGS_SZP8(r); return r; }
static inline u16 XOR16(u16 a, u16 b) { u16 r = a ^ b; R.cf = R.of = 0; FLAGS_SZP16(r); return r; }
static inline u8 INC8(u8 a) { bool c = R.cf; u8 r = ADD8(a, 1); R.cf = c; return r; }
static inline u16 INC16(u16 a) { bool c = R.cf; u16 r = ADD16(a, 1); R.cf = c; return r; }
static inline u8 DEC8(u8 a) { bool c = R.cf; u8 r = SUB8(a, 1); R.cf = c; return r; }
static inline u16 DEC16(u16 a) { bool c = R.cf; u16 r = SUB16(a, 1); R.cf = c; return r; }
static inline u8 NEG8(u8 a) { u8 r = SUB8(0, a); R.cf = a != 0; return r; }
static inline u16 NEG16(u16 a) { u16 r = SUB16(0, a); R.cf = a != 0; return r; }
// shifts and rotates by n (masked to 5 bits as on the 286+; the counts here are small)
static inline u8 SHL8(u8 a, u8 n) { n &= 31; if (!n) return a; unsigned r = (unsigned)a << n; R.cf = (r >> 8) & 1; FLAGS_SZP8(r); R.of = (((r >> 7) & 1) ^ R.cf) != 0; return (u8)r; }
static inline u16 SHL16(u16 a, u8 n) { n &= 31; if (!n) return a; u32 r = (u32)a << n; R.cf = (r >> 16) & 1; FLAGS_SZP16(r); R.of = (((r >> 15) & 1) ^ R.cf) != 0; return (u16)r; }
#define SAL8 SHL8
#define SAL16 SHL16
static inline u8 SHR8(u8 a, u8 n) { n &= 31; if (!n) return a; R.cf = n <= 8 ? (a >> (n - 1)) & 1 : 0; u8 r = n < 8 ? a >> n : 0; FLAGS_SZP8(r); R.of = n == 1 && (a & 0x80); return r; }
static inline u16 SHR16(u16 a, u8 n) { n &= 31; if (!n) return a; R.cf = n <= 16 ? (a >> (n - 1)) & 1 : 0; u16 r = n < 16 ? a >> n : 0; FLAGS_SZP16(r); R.of = n == 1 && (a & 0x8000); return r; }
static inline u8 SAR8(u8 a, u8 n) { n &= 31; if (!n) return a; i8 s = (i8)a; R.cf = ((n < 8 ? s >> (n - 1) : s >> 7)) & 1; u8 r = (u8)(n < 8 ? s >> n : s >> 7); FLAGS_SZP8(r); R.of = 0; return r; }
static inline u16 SAR16(u16 a, u8 n) { n &= 31; if (!n) return a; i16 s = (i16)a; R.cf = ((n < 16 ? s >> (n - 1) : s >> 15)) & 1; u16 r = (u16)(n < 16 ? s >> n : s >> 15); FLAGS_SZP16(r); R.of = 0; return r; }
static inline u8 ROL8(u8 a, u8 n) { n &= 7; u8 r = (u8)((a << n) | (a >> ((8 - n) & 7))); if (n) R.cf = r & 1; return r; }
static inline u16 ROL16(u16 a, u8 n) { n &= 15; u16 r = (u16)((a << n) | (a >> ((16 - n) & 15))); if (n) R.cf = r & 1; return r; }
static inline u8 ROR8(u8 a, u8 n) { n &= 7; u8 r = (u8)((a >> n) | (a << ((8 - n) & 7))); if (n) R.cf = (r >> 7) & 1; return r; }
static inline u16 ROR16(u16 a, u8 n) { n &= 15; u16 r = (u16)((a >> n) | (a << ((16 - n) & 15))); if (n) R.cf = (r >> 15) & 1; return r; }
static inline u8 RCL8(u8 a, u8 n) { for (n &= 31; n; n--) { bool c = a & 0x80; a = (u8)((a << 1) | R.cf); R.cf = c; } return a; }
static inline u16 RCL16(u16 a, u8 n) { for (n &= 31; n; n--) { bool c = a & 0x8000; a = (u16)((a << 1) | R.cf); R.cf = c; } return a; }
static inline u8 RCR8(u8 a, u8 n) { for (n &= 31; n; n--) { bool c = a & 1; a = (u8)((a >> 1) | (R.cf << 7)); R.cf = c; } return a; }
static inline u16 RCR16(u16 a, u8 n) { for (n &= 31; n; n--) { bool c = a & 1; a = (u16)((a >> 1) | (R.cf << 15)); R.cf = c; } return a; }
// multiplication and division
static inline void MUL8(u8 b) { R.ax = (u16)((u8)R.ax * b); R.cf = R.of = (R.ax >> 8) != 0; }
static inline void MUL16(u16 b) { u32 r = (u32)R.ax * b; R.ax = (u16)r; R.dx = (u16)(r >> 16); R.cf = R.of = R.dx != 0; }
static inline void IMUL8(u8 b) { i16 r = (i16)((i8)R.ax * (i8)b); R.ax = (u16)r; R.cf = R.of = r != (i8)r; }
static inline void IMUL16(u16 b) { i32 r = (i32)(i16)R.ax * (i16)b; R.ax = (u16)r; R.dx = (u16)((u32)r >> 16); R.cf = R.of = r != (i16)r; }
static inline u16 IMUL3(u16 a, u16 b) { i32 r = (i32)(i16)a * (i16)b; R.cf = R.of = r != (i16)r; return (u16)r; }
// a divide error (INT 0): the program's handler, if it has one (asm_divide_error: ip = the instruction's offset)
void asm_divide_error(u16 ip);
static inline void DIV8(u8 b, u16 ip) { if (!b || R.ax / b > 0xFF) { asm_divide_error(ip); return; } u16 a = R.ax; R.ax = (u16)(((a % b) << 8) | (a / b)); }
static inline void DIV16(u16 b, u16 ip) { u32 a = ((u32)R.dx << 16) | R.ax; if (!b || a / b > 0xFFFF) { asm_divide_error(ip); return; } R.ax = (u16)(a / b); R.dx = (u16)(a % b); }
static inline void IDIV8(u8 b, u16 ip) { i16 a = (i16)R.ax; if (!b) { asm_divide_error(ip); return; } i16 q = a / (i8)b; if (q != (i8)q) { asm_divide_error(ip); return; } R.ax = (u16)(((u8)(a % (i8)b) << 8) | (u8)q); }
static inline void IDIV16(u16 b, u16 ip) { i32 a = (i32)(((u32)R.dx << 16) | R.ax); if (!b) { asm_divide_error(ip); return; } i32 q = a / (i16)b; if (q != (i16)q) { asm_divide_error(ip); return; } R.ax = (u16)q; R.dx = (u16)(a % (i16)b); }

// string instructions (DF = 0 in these programs)
#define MOVSB() (W8(ES, R.di, M8(DS, R.si)), R.si += R.df ? -1 : 1, R.di += R.df ? -1 : 1)
#define MOVSW() (W16(ES, R.di, M16(DS, R.si)), R.si += R.df ? -2 : 2, R.di += R.df ? -2 : 2)
#define STOSB() (W8(ES, R.di, R.ax), R.di += R.df ? -1 : 1)
#define STOSW() (W16(ES, R.di, R.ax), R.di += R.df ? -2 : 2)
#define LODSB() (SETL(R.ax, M8(DS, R.si)), R.si += R.df ? -1 : 1)
#define LODSW() (R.ax = M16(DS, R.si), R.si += R.df ? -2 : 2)
#define SCASB() (SUB8((u8)R.ax, M8(ES, R.di)), R.di += R.df ? -1 : 1)
#define CMPSB() (SUB8(M8(DS, R.si), M8(ES, R.di)), R.si += R.df ? -1 : 1, R.di += R.df ? -1 : 1)
#define REPMOVSB() for (; R.cx; R.cx--) MOVSB()
#define REPMOVSW() for (; R.cx; R.cx--) MOVSW()
#define REPSTOSB() for (; R.cx; R.cx--) STOSB()
#define REPSTOSW() for (; R.cx; R.cx--) STOSW()
#define REPESCASB() for (; R.cx && (R.cx--, SCASB(), R.zf);)
#define REPNESCASB() for (; R.cx && (R.cx--, SCASB(), !R.zf);)
#define REPECMPSB() for (; R.cx && (R.cx--, CMPSB(), R.zf);)

// what the recompiled code cannot do by itself
u16 asm_port_in(u16 port);
void asm_port_out(u16 port, u16 value);
void asm_int(u8 n);
void asm_unknown_call(u16 seg, u16 off);
void asm_bad_switch(void);
void asm_far_call(u16 seg, u16 off);  // a call through a far function pointer (rp_core.c)
#define ASM_PORT_IN(p) asm_port_in(p)
#define ASM_PORT_OUT(p, v) asm_port_out(p, v)
#define ASM_INT(n) asm_int(n)
#define ASM_UNKNOWN_CALL(s, o) asm_unknown_call(s, o)
#define ASM_BAD_SWITCH() asm_bad_switch()
#define ASM_INDIRECT_CALL(t) asm_unknown_call(0xFFFF, t)

#endif
