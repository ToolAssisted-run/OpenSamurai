// The melee's program (MELEE.EXE 1000:0010-E021), translated from Ghidra's decompilation over the image of
// its data segment by the workspace's work/ghidra2c.py, then corrected by hand where the decompilation was
// wrong (marked FIX) against the original's disassembly and captures of the real game. Function names are
// the original's offsets; docs/FINDINGS.md and the analysis name them.
#include "dsimage.h"
#include "melee_rt.h"

static u16 f_0010(void);
static u16 f_0062(void);
static u16 f_00aa(void);
static u16 f_0200(void);
static u16 f_0252(void);
static u16 f_0280(void);
static u16 f_03a0(i8 param_1);
static u16 f_03b2(void);
static u16 f_03c0(void);
static u16 f_0430(u16 param_1);
static u8 f_04aa(i16 param_1);
static u16 f_0534(void);
static u16 f_055a(void);
static u16 f_05ba(void);
static u16 f_05c6(void);
static u16 f_0602(void);
static u8 f_0676(void);
static u16 f_068e(void);
static u16 f_0690(void);
static u16 f_0708(void);
static u32 f_075a(void);
static u32 f_0776(u16 param_1, u16 param_2, u16 param_3);
static u16 f_078e(void);
static u16 f_07ba(u16 param_1);
static u16 f_07c2(void);
static u16 f_07e8(void);
static u16 f_0808(void);
static u16 f_081a(u16 param_1);
static u16 f_0827(u16 param_1);
static u16 f_0834(void);
static u16 f_0870(u16 param_1);
static u16 f_08b4(void);
static u16 f_08c4(u8 param_1);
static u16 f_08f4(void);
static u16 f_0948(i16 param_1);
static u16 f_098c(u8 param_1);
static u16 f_09a4(void);
static u16 f_09b0(void);
static u16 f_09bc(void);
static u16 f_09c6(void);
static u16 f_09ee(void);
static u16 f_0a04(void);
static u16 f_0a10(i8 param_1);
static u16 f_0a2e(void);
static u16 f_0a62(u8 param_1);
static u16 f_0aba(u8 param_1);
static u8 f_0b46(u8 param_1);
static u8 f_0b92(u8 param_1);
static u8 f_0c4c(u8 param_1);
static u8 f_0d04(u8 param_1,u8 param_2,u8 param_3,u8 param_4);
static u16 f_0df4(u8 param_1);
static u16 f_0e14(u8 param_1);
static u16 f_0e64(u8 param_1);
static u16 f_0e86(u8 param_1);
static u16 f_0ea8(u8 param_1);
static u16 f_0eca(u8 param_1);
static u16 f_0efc(u8 param_1,u8 param_2);
static u16 f_0f28(u8 param_1,u8 param_2);
static u16 f_0f54(u8 param_1,u8 param_2,u8 param_3);
static u16 f_0fa4(u8 param_1,u8 param_2,u8 param_3);
static u8 f_0ff4(u8 param_1);
static u16 f_1096(u8 param_1);
static u16 f_10e2(u8 param_1);
static u8 f_1132(u8 param_1);
static u16 f_11a4(u8 param_1);
static u16 f_11ea(void);
static u16 f_1230(u8 param_1);
static u16 f_1392(u8 param_1);
static u16 f_13b8(u8 param_1);
static u16 f_1542(u8 param_1);
static u16 f_159e(u8 param_1);
static u8 f_15e0(i8 param_1);
static u8 f_161c(i8 param_1);
static u8 f_1658(u8 param_1,i8 param_2);
static i16 f_170e(i16 param_1);
static u16 f_1726(u8 param_1);
static i16 f_1746(i16 param_1,i16 param_2);
static i16 f_1756(i16 param_1,i16 param_2);
static i16 f_1766(u8 param_1,u8 param_2);
static u8 f_1792(u8 param_1);
static u8 f_1802(i16 param_1);
static i16 f_1836(u8 param_1);
static u16 f_18b0(u8 param_1);
static u8 f_18c2(u8 param_1,u8 param_2);
static u16 f_190c(u8 param_1,u8 param_2);
static i32 f_1938(u8 param_1,u8 param_2);
static u8 f_19a0(u8 param_1);
static i16 f_19f8(u8 param_1);
static u8 f_1a26(u8 param_1);
static i16 f_1a36(u8 param_1,u8 param_2);
static u16 f_1a5a(u8 param_1,u8 param_2,u8 param_3);
static u16 f_1a88(u8 param_1,u8 param_2);
static u16 f_1b80(u8 param_1,u8 param_2,u8 param_3);
static u8 f_1c36(u8 param_1);
static u8 f_1c46(u8 param_1);
static u8 f_1c56(u8 param_1);
static u16 f_1c66(u8 param_1);
static u16 f_1ca2(u8 param_1);
static u16 f_1ce4(u8 param_1);
static u16 f_1d36(u8 param_1);
static u16 f_1d9c(u8 param_1,u8 param_2,u8 param_3);
static u8 f_1e7c(u8 param_1,u16 param_2);
static u8 f_1f1e(u8 param_1,u8 param_2);
static u16 f_1fb0(void);
static u16 f_1fb2(void);
static u16 f_1fb4(u8 param_1);
static u16 f_1fcc(void);
static u16 f_1fce(u8 param_1,u8 param_2);
static u8 f_20f2(u8 param_1,u8 param_2);
static u16 f_212e(u8 param_1,u8 param_2);
static u16 f_215c(i8 param_1,u8 param_2,i8 param_3);
static u16 f_21dc(void);
static u8 f_21de(i8 param_1,u8 param_2);
static u8 f_221c(u8 param_1);
static u16 f_223e(u8 param_1,u8 param_2);
static u8 f_2276(u8 param_1);
static u16 f_2298(u8 param_1,u8 param_2);
static u16 f_22bc(u8 param_1);
static u16 f_231a(i16 param_1);
static u16 f_2346(i16 param_1);
static u8 f_2366(u8 param_1);
static u16 f_2388(u8 param_1,u8 param_2);
static u8 f_23ac(u8 param_1);
static u16 f_23ce(u8 param_1);
static u16 f_23de(u8 param_1);
static u16 f_23ee(u8 param_1);
static u16 f_23fe(u8 param_1);
static u16 f_2420(u8 param_1);
static u8 f_2440(u8 param_1);
static u16 f_2462(u8 param_1);
static u16 f_2504(void);
static u16 f_252a(void);
static u16 f_2540(void);
static u16 f_25b8(u8 param_1);
static u16 f_2622(void);
static u16 f_2646(void);
static u8 f_2696(i8 param_1);
static u16 f_26e8(void);
static u16 f_2840(u8 param_1);
static u16 f_2898(void);
static u16 f_2986(u8 param_1);
static u16 f_2a10(u8 param_1);
static u8 f_2a6e(u8 param_1);
static u8 f_2aa8(u8 param_1);
static u16 f_2ae0(u8 param_1,u8 param_2);
static u16 f_2b38(u8 param_1);
static u16 f_2dc6(u8 param_1,u8 param_2);
static u16 f_2eb6(u8 param_1,u8 param_2);
static u8 f_2f42(void);
static u16 f_2f72(void);
static u16 f_2f8e(u8 param_1);
static bool f_303a(u8 param_1,u8 param_2);
static u16 f_3064(u8 param_1,u8 param_2);
static u16 f_30c4(u8 param_1,i8 param_2,i8 param_3);
static u16 f_32c4(u8 param_1);
static u16 f_32d4(u8 param_1,u16 param_2);
static u16 f_32e8(u8 param_1,i16 param_2);
static u16 f_32fc(u8 param_1);
static u16 f_330c(u8 param_1,u16 param_2);
static u16 f_3320(u8 param_1,i16 param_2);
static u8 f_3334(u8 param_1);
static u16 f_3344(u8 param_1,u8 param_2);
static u8 f_3356(u8 param_1);
static u16 f_3366(u8 param_1,u8 param_2);
static u16 f_3378(void);
static u16 f_33aa(void);
static u16 f_33dc(u8 param_1);
static u16 f_340c(void);
static u16 f_3434(void);
static u16 f_352a(void);
static u16 f_3570(void);
static u16 f_363c(u8 param_1,u8 param_2);
static u16 f_365a(u8 param_1,u8 param_2,u8 param_3);
static u8 f_369c(void);
static u16 f_36c8(u8 param_1);
static u16 f_36ea(void);
static u16 f_3740(u8 param_1,u8 param_2);
static u16 f_3830(void);
static u16 f_3856(void);
static u8 f_38d0(u8 param_1);
static u8 f_38ea(u8 param_1);
static u8 f_38fa(u8 param_1);
static u16 f_390a(u8 param_1);
static u16 f_391a(u8 param_1);
static u16 f_392a(u8 param_1);
static u16 f_393a(u8 param_1,u8 param_2);
static u16 f_394c(u8 param_1,u8 param_2);
static u16 f_395e(u8 param_1,u16 param_2);
static u16 f_3972(u8 param_1,u16 param_2);
static u16 f_3986(u8 param_1,u16 param_2);
static u8 f_399a(u8 param_1);
static u16 f_39b4(void);
static u16 f_3a70(void);
static u16 f_3a88(void);
static bool f_3a8c(void);
static u16 f_3aa4(void);
static u16 f_3ab2(void);
static u16 f_3ad6(void);
static u8 f_3afa(u8 param_1);
static u16 f_3b0a(u8 param_1);
static u16 f_3b1a(u8 param_1);
static u16 f_3b28(void);
static u16 f_3b2e(i8 param_1);
static u16 f_3b7c(u8 param_1);
static u16 f_3bb8(void);
static u16 f_3bfa(void);
static u16 f_3bfe(void);
static u16 f_3ca8(void);
static u16 f_3cce(void);
static u16 f_3d1a(void);
static u16 f_3d56(u8 param_1);
static u16 f_3d90(void);
static u16 f_3dac(u8 param_1);
static u16 f_3de0(u8 param_1);
static u16 f_3e14(u8 param_1);
static u16 f_3e92(u8 param_1);
static u16 f_3ec8(u8 param_1);
static u16 f_3efe(u8 param_1);
static u16 f_3f42(void);
static u16 f_3f70(u8 param_1,u8 param_2);
static u16 f_3fdc(u8 param_1,u8 param_2);
static u16 f_4048(u8 param_1);
static u16 f_40a4(u8 param_1);
static u32 f_4102(u8 param_1,u8 param_2,u8 param_3);
static u16 f_4124(u8 param_1);
static u16 f_41a6(u8 param_1);
static u16 f_4228(u8 param_1);
static u16 f_4252(u8 param_1);
static u16 f_427c(u8 param_1);
static u16 f_432a(void);
static u16 f_435e(void);
static u16 f_437c(void);
static u16 f_44a4(void);
static u16 f_44da(void);
static u16 f_4526(void);
static u16 f_454a(void);
static u16 f_45ca(void);
static u16 f_46f6(void);
static u16 f_4706(void);
static u16 f_4712(void);
static u16 f_475e(u8 param_1,u8 param_2);
static u16 f_4794(u8 param_1,u8 param_2);
static u16 f_48aa(u8 param_1,u8 param_2);
static u16 f_48e2(u8 param_1);
static u16 f_49a4(u8 param_1);
static u16 f_4a1a(u8 param_1);
static u16 f_4a80(u8 param_1);
static u16 f_4aa6(u8 param_1);
static u16 f_4ae6(u8 param_1);
static u16 f_4ba4(u8 param_1);
static u8 f_4bdc(void);
static u16 f_4c12(void);
static u8 f_4c70(void);
static u16 f_4ca6(void);
static u8 f_4cc6(void);
static u16 f_4d14(void);
static u16 f_4d4e(void);
static u16 f_4dbe(void);
static u8 f_4dc0(void);
static u16 f_4dee(void);
static u16 f_4e22(void);
static u16 f_4e32(void);
static u16 f_4e3e(void);
static u16 f_4e5c(void);
static u16 f_4e7c(u16 param_1);
static u16 f_4e9a(void);
static u16 f_4fac(u8 param_1);
static u16 f_500c(void);
static u16 f_50c6(void);
static u8 f_512e(void);
static u8 f_5222(i8 param_1);
static u16 f_52b8(u8 param_1);
static u16 f_5308(u8 param_1);
static u8 f_5348(void);
static u8 f_5382(void);
static u8 f_5400(void);
static u16 f_5460(u8 param_1);
static u16 f_5478(u8 param_1);
static u16 f_54b8(u8 param_1);
static u16 f_54da(u8 param_1);
static u16 f_5562(u8 param_1,u8 param_2);
static u16 f_55fc(u8 param_1);
static u16 f_573e(u8 param_1);
static u16 f_57ea(u8 param_1);
static u16 f_5950(u8 param_1,u8 param_2);
static u16 f_599a(u8 param_1,u8 param_2);
static u16 f_59c2(u8 param_1,u8 param_2);
static u16 f_5a9e(u8 param_1,u8 param_2);
static u16 f_5aca(u8 param_1,u8 param_2);
static u16 f_5b42(u8 param_1,u8 param_2);
static u16 f_5b78(u8 param_1,u8 param_2);
static u16 f_5bf2(u8 param_1);
static u16 f_5c70(i16 param_1,i16 param_2);
static u16 f_5cae(u16 param_1,u16 param_2);
static u16 f_5d0a(u8 param_1,u8 param_2);
static u16 f_5d58(u8 param_1,u8 param_2);
static u16 f_5da6(u8 param_1,u8 param_2);
static u16 f_5df4(u8 param_1,u8 param_2);
static u16 f_5e44(u8 param_1,u8 param_2);
static u16 f_5e94(u8 param_1,u8 param_2);
static u16 f_5ee2(u8 param_1,u8 param_2);
static u16 f_5f32(u8 param_1,u8 param_2);
static u16 f_5f82(u8 param_1,u8 param_2);
static u16 f_6006(u8 param_1,u8 param_2);
static u16 f_6148(u8 param_1,u8 param_2,u8 param_3,u8 param_4);
static u16 f_6176(u8 param_1,u8 param_2,u8 param_3);
static u16 f_61f6(u8 param_1,u8 param_2,u8 param_3);
static i16 f_6320(u8 param_1,u8 param_2);
static u16 f_63ce(u8 param_1,u8 param_2,u8 param_3);
static u16 f_6408(u8 param_1,u8 param_2,u8 param_3);
static u16 f_6468(u8 param_1,u8 param_2);
static u16 f_64b6(u8 param_1,u8 param_2,u8 param_3);
static u16 f_6554(u8 param_1,u8 param_2);
static u16 f_6602(u16 param_1,u16 param_2);
static u8 f_66b6(void);
static u8 f_66c4(u8 param_1);
static u8 f_66d4(u8 param_1);
static u8 f_66e4(u8 param_1);
static u16 f_66f4(void);
static u16 f_6714(u8 param_1);
static u16 f_673a(u8 param_1,u8 param_2);
static u16 f_6766(u8 param_1);
static u16 f_67ce(u16 param_1,u16 param_2);
static u16 f_6836(u8 param_1);
static u16 f_687e(void);
static u16 f_68d0(u8 param_1);
static u16 f_6988(u8 param_1);
static u16 f_69b6(u8 param_1);
static u16 f_69ea(u8 param_1);
static u16 f_6a02(void);
static u8 f_6a30(void);
static u16 f_6a64(u8 param_1);
static u8 f_6a82(void);
static u8 f_6ac8(u8 param_1);
static u16 f_6af2(u8 param_1,u8 param_2);
static u16 f_6b42(u8 param_1,u8 param_2);
static u16 f_6b70(u8 param_1);
static u8 f_6b8e(void);
static u16 f_6bc2(void);
static u16 f_6c5c(void);
static u16 f_6da6(void);
static u16 f_6de8(void);
static bool f_6ed4(u8 param_1);
static u16 f_6f54(u8 param_1);
static u16 f_6fe0(void);
static u16 f_7004(void);
static u16 f_707e(u8 param_1,u8 param_2);
static u16 f_7108(i8 param_1);
static u8 f_7122(void);
static bool f_7130(void);
static u16 f_713e(i16 param_1);
static u16 f_7158(i8 param_1);
static u8 f_7172(void);
static u8 f_7180(void);
static u8 f_718e(void);
static u8 f_719c(void);
static u16 f_71aa(void);
static u16 f_71b4(void);
static u16 f_71dc(void);
static u16 f_71fc(void);
static u16 f_7238(void);
static i16 f_725c(u8 param_1);
static u16 f_727a(u8 param_1);
static u16 f_734a(u8 param_1);
static i16 f_7464(void);
static u16 f_7496(void);
static u16 f_75c4(u8 param_1,u8 param_2);
static u16 f_775c(u8 param_1,u8 param_2);
static u16 f_7788(u16 param_1,u8 param_2);
static u16 f_7816(u8 param_1,u8 param_2);
static u16 f_78b4(u8 param_1,u8 param_2,u8 param_3);
static u16 f_7942(u8 param_1);
static u16 f_7956(u8 param_1);
static u16 f_796a(u8 param_1);
static u16 f_7990(u8 param_1);
static u8 f_79f0(void);
static u16 f_7a66(u8 param_1);
static u16 f_7ae0(u8 param_1);
static u8 f_7b32(u8 param_1);
static u16 f_7b4e(u8 param_1);
static u16 f_7bd4(u8 param_1);
static u16 f_7c16(u16 param_1);
static u16 f_7c38(void);
static u16 f_7c54(u8 param_1);
static u16 f_7c84(u8 param_1,u8 param_2);
static u16 f_7cac(u8 param_1);
static u16 f_7ce2(u8 param_1);
static u16 f_7d0e(u8 param_1);
static u16 f_7d6e(u8 param_1);
static u16 f_7dce(u8 param_1);
static u16 f_7e44(u8 param_1);
static bool f_7eb6(u16 param_1);
static bool f_7ece(u8 param_1,i16 param_2,u8 param_3);
static i16 f_7f28(i16 param_1,i16 param_2);
static u16 f_7f78(u8 param_1,u8 param_2);
static u16 f_8014(i16 param_1);
static u16 f_8040(u8 param_1,u8 param_2);
static u16 f_81a2(u8 param_1,u8 param_2);
static u16 f_8250(u8 param_1,u8 param_2);
static u16 f_82be(u8 param_1);
static u16 f_82e0(u8 param_1);
static u16 f_831a(u8 param_1);
static u16 f_83ac(u8 param_1);
static u16 f_83ce(u8 param_1);
static u16 f_83fa(i16 param_1);
static u16 f_841e(u8 param_1);
static u16 f_8462(u8 param_1);
static u16 f_849a(u8 param_1);
static u16 f_8580(u8 param_1);
static u16 f_85e2(u8 param_1);
static u16 f_8654(u8 param_1,u8 param_2);
static i8 f_869e(u8 param_1);
static u16 f_876e(u8 param_1);
static u16 f_879e(u8 param_1);
static u16 f_87e8(u8 param_1);
static u16 f_8824(u8 param_1);
static u8 f_8986(u8 param_1,u16 param_2);
static u16 f_8a34(u16 param_1);
static u16 f_8a72(u8 param_1);
static u16 f_8a88(u8 param_1);
static u16 f_8ad0(u8 param_1,u8 param_2,u8 param_3);
static u16 f_8bb2(u8 param_1);
static u8 f_8bd4(u8 param_1);
static u16 f_8be6(u8 param_1,u8 param_2);
static u16 f_8c2a(u8 param_1);
static u16 f_8c52(u8 param_1,u8 param_2);
static u16 f_8cae(u8 param_1);
static u16 f_8ccc(u8 param_1,u8 param_2);
static u16 f_8d3c(i16 param_1,i16 param_2,i16 param_3,i16 param_4);
static u16 f_8dde(i16 param_1,i16 param_2,u16 param_3,i16 param_4);
static u16 f_8e5e(u16 param_1,u16 param_2,i16 param_3,i16 param_4,u16 param_5,
             u16 param_6,u16 param_7,u16 param_8);
static u16 f_8ea8(i16 param_1,i16 param_2,i16 param_3,i16 param_4,i16 param_5,u16 param_6,
             u16 param_7,i16 param_8);
static u16 f_8f64(u8 param_1);
static u16 f_902e(u16 param_1,u16 param_2,u16 param_3,u16 param_4,i16 param_5,
             i16 param_6);
static u16 f_9168(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u16 param_6,u16 param_7,u16 param_8);
static u16 f_91ac(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u16 param_6);
static u16 f_91d8(i16 param_1,i16 param_2,i16 param_3,u16 param_4);
static i16 f_922a(u8 param_1);
static u16 f_9258(u8 param_1);
static u16 f_929c(u8 param_1,u8 param_2);
static u16 f_92e4(u8 param_1,u8 param_2);
static u16 f_930c(u8 param_1,u8 param_2);
static u16 f_9328(u16 param_1,u8 param_2,u16 param_3);
static u16 f_93ba(u8 param_1,u16 param_2,u16 param_3,u16 param_4);
static u16 f_944e(u16 param_1,u16 param_2,u16 param_3,i16 param_4);
static u16 f_9486(u8 param_1);
static u16 f_952c(u8 param_1);
static u16 f_9584(u16 param_1,u8 param_2,u8 param_3,u16 param_4);
static u16 f_95c8(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u16 param_6);
static u16 f_961c(u8 param_1,u8 param_2);
static u16 f_96bc(u8 param_1,u8 param_2);
static u16 f_9720(u8 param_1,u8 param_2);
static u16 f_9784(void);
static u16 f_97a4(void);
static u16 f_9950(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5);
static u16 f_998a(void);
static u16 f_9a00(void);
static u16 f_9a0a(u8 param_1);
static u16 f_9b78(u8 param_1);
static u16 f_9e16(u8 param_1);
static u16 f_9ece(u16 param_1);
static u16 f_9f12(void);
static u16 f_9f42(void);
static u16 f_9f4e(void);
static u16 f_9f8a(void);
static u8 f_9fda(i16 param_1,i16 param_2);
static u16 f_a02a(void);
static u16 f_a054(void);
static u16 f_a0a8(u16 param_1);
static u16 f_a0ba(i16 param_1,u8 param_2);
static u8 f_a0dc(i16 param_1);
static u16 f_a0ea(u16 param_1);
static u16 f_a0fc(i16 param_1,i16 param_2,i16 param_3);
static u32 f_a114(i16 param_1,i16 param_2);
static u32 f_a122(u8 param_1,u8 param_2);
static u16 f_a146(void);
static u16 f_a148(u8 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u8 param_6);
static u16 f_a170(u8 param_1,u8 param_2,u8 param_3);
static u16 f_a19e(u8 param_1,u8 param_2,u8 param_3);
static u16 f_a1cc(u8 param_1,u8 param_2,u8 param_3);
static u16 f_a1fa(u16 param_1);
static u16 f_a21a(u16 param_1);
static u16 f_a27e(u16 param_1);
static u8 f_a2f2(u8 param_1);
static u16 f_a384(u8 param_1);
static u16 f_a3b4(u16 param_1);
static u16 f_a3ea(u16 param_1);
static u16 f_a424(u8 param_1);
static u16 f_a440(u8 param_1);
static u16 f_a450(u8 param_1);
static u16 f_a476(u8 param_1);
static u16 f_a4d0(u8 param_1);
static u16 f_a50e(u8 param_1);
static u16 f_a58c(u8 param_1);
static u16 f_a5aa(u8 param_1);
static u16 f_a5c6(u8 param_1);
static u16 f_a65c(u8 param_1,u8 param_2,u8 param_3);
static u16 f_a6fc(u8 param_1,u8 param_2);
static u16 f_a716(u8 param_1,u8 param_2);
static u16 f_a730(u8 param_1,u8 param_2);
static u16 f_a7cc(u8 param_1,u8 param_2);
static u16 f_a850(void);
static u16 f_a864(void);
static u8 f_a892(u8 param_1);
static u16 f_a8b2(u8 param_1);
static u16 f_a8e2(u8 param_1);
static bool f_a948(u8 param_1);
static u16 f_a970(u8 param_1);
static u16 f_a998(u8 param_1);
static u16 f_aa12(u8 param_1,u8 param_2);
static u16 f_aa24(u8 param_1,u8 param_2);
static u16 f_aa36(u8 param_1);
static u16 f_aaac(void);
static u16 f_aaae(u8 param_1);
static u16 f_aaf6(u8 param_1,u8 param_2);
static u16 f_ab12(u8 param_1,u8 param_2);
static u16 f_ab3c(u8 param_1,u8 param_2);
static u16 f_abee(u8 param_1);
static u16 f_ac36(u8 param_1);
static u16 f_ac64(u8 param_1);
static u8 f_ac9a(u8 param_1);
static u16 f_ad2c(u8 param_1);
static i16 f_ad7a(u8 param_1);
static u16 f_add4(u8 param_1);
static u16 f_ae62(u8 param_1);
static u16 f_ae80(u8 param_1,u8 param_2);
static u16 f_af0c(u16 param_1);
static u16 f_af30(i16 param_1);
static u16 f_af4e(u8 param_1);
static u16 f_b084(u8 param_1);
static u16 f_b0ea(u8 param_1);
static u16 f_b102(u8 param_1);
static u16 f_b11a(u8 param_1);
static u16 f_b1c0(u8 param_1);
static u16 f_b2ae(u8 param_1);
static u16 f_b334(u8 param_1);
static u16 f_b490(u8 param_1);
static u16 f_b526(u8 param_1);
static u16 f_b5ec(u8 param_1);
static u16 f_b68a(u8 param_1,u8 param_2,u8 param_3);
static u16 f_b6cc(u8 param_1);
static u16 f_b706(u8 param_1);
static u16 f_b742(u8 param_1);
static u16 f_b84c(u8 param_1,u8 param_2);
static u8 f_b85e(i16 param_1);
static u16 f_b86c(u8 param_1,u8 param_2);
static u16 f_b8da(u8 param_1,i8 param_2,u8 param_3);
static u16 f_b91e(u8 param_1,u8 param_2);
static u16 f_b9bc(u8 param_1,i8 param_2,u8 param_3);
static u16 f_ba00(void);
static u16 f_ba4c(i8 param_1,u8 param_2);
static u16 f_ba90(void);
static u16 f_bb46(i16 param_1);
static u32 f_bb6a(void);
static u32 f_bb7e(void);
static u8 f_bb92(void);
static u16 f_bbd0(void);
static u16 f_bbf0(void);
static u16 f_bbfe(void);
static u16 f_bc26(u8 param_1);
static u16 f_bc52(void);
static u16 f_bccc(u16 param_1,u8 param_2);
static u16 f_bd10(u8 param_1,u8 param_2,u8 param_3);
static u16 f_bd5c(u8 param_1,u8 param_2);
static u16 f_bd96(u8 param_1);
static u16 f_bdbe(void);
static u8 f_be1a(u8 param_1);
static u16 f_be2e(u8 param_1,u8 param_2,u16 param_3,u8 param_4);
static u16 f_beae(u8 param_1);
static u8 f_bec2(u8 param_1);
static u8 f_bed6(u8 param_1);
static u16 f_beea(u8 param_1);
static u16 f_befc(u8 param_1,u8 param_2);
static u16 f_bf12(u8 param_1,u8 param_2);
static u16 f_bf7c(u8 param_1,u8 param_2);
static u16 f_bfe0(u8 param_1,u8 param_2);
static u16 f_c054(u8 param_1,u8 param_2,u8 param_3);
static i16 f_c148(u16 param_1);
static u16 f_c1ae(u8 param_1,u8 param_2);
static u16 f_c324(void);
static u8 f_c380(u8 param_1);
static u8 f_c390(u8 param_1);
static u8 f_c3a0(u8 param_1,u8 param_2);
static u16 f_c3c2(u8 param_1);
static u16 f_c3ec(void);
static u16 f_c410(void);
static u32 f_c43e(u8 param_1,u8 param_2);
static u16 f_c45c(u8 param_1,u8 param_2,u16 param_3);
static u16 f_c47e(void);
static u16 f_c492(void);
static u16 f_c498(u8 param_1,u8 param_2,u8 param_3);
static u16 f_c4e0(u8 param_1);
static u16 f_c5d8(void);
static u16 f_c722(u8 param_1,u8 param_2);
static u16 f_c74c(u8 param_1);
static u16 f_c776(u16 param_1);
static u16 f_c798(void);
static u16 f_c7a8(void);
static u16 f_c7f6(u16 param_1);
static u16 f_c810(u8 param_1,u8 param_2);
static u16 f_c856(u8 param_1,u8 param_2,u8 param_3);
static u16 f_cb74(u8 param_1,u8 param_2);
static u16 f_cc6a(u8 param_1,u8 param_2,u8 param_3);
static u16 f_ccd6(u8 param_1,i8 param_2,u8 param_3,u8 param_4,i16 param_5);
static u8 f_ce2a(u8 param_1);
static bool f_ce56(u8 param_1);
static u16 f_ce7c(void);
static u16 f_cf22(void);
static u16 f_cf58(void);
static u16 f_cf68(void);
static u16 f_cfaa(void);
static u16 f_cfce(u8 param_1);
static u16 f_d054(void);
static u16 f_d07e(void);
static u16 f_d0c8(u8 param_1,u8 param_2);
static u8 f_d19e(i8 param_1,i8 param_2,i8 param_3,i8 param_4);
static u16 f_d274(i8 param_1,i8 param_2);
static u16 f_d2b4(i8 param_1,i8 param_2);
static u16 f_d306(i8 param_1,i8 param_2);
static u16 f_d32c(void);
static u16 f_d3ac(u8 param_1,u8 param_2);
static u16 f_d410(void);
static u16 f_d4b4(void);
static u16 f_d4b6(u8 param_1,u8 param_2,u8 param_3);
static u16 f_d5dc(u16 param_1,u8 param_2);
static u16 f_d620(u8 param_1,u8 param_2);
static u16 f_d648(u8 param_1);
static u16 f_d6aa(u8 param_1);
static u16 f_d6c2(void);
static u16 f_d6cc(u8 param_1);
static u16 f_d6f0(void);
static u16 f_d702(void);
static u16 f_d724(i16 param_1);
static u16 f_d766(void);
static u16 f_d770(void);
static u16 f_d77c(void);
static u8 f_d782(void);
static u16 f_d788(void);
static u16 f_d78e(void);
static u16 f_d858(void);
static u16 f_d87e(void);
static u16 f_daa6(i16 param_1,i8a *param_2);
static u16 f_dafe(u16 param_1,u16 param_2);
static u16 f_db5e(u16 param_1);
static u16 f_db88(i16 param_1);
static u16 f_dbac(u16 param_1,u16 param_2);
static u16 f_dbf0(u16 param_1,u16 param_2,u16 param_3);
static u16 f_dc36(u16 param_1,u16 param_2,u16 param_3,u16 param_4);
static u16 f_dc78(u16 param_1,u16 param_2);
static u16 f_dcd8(u16 param_1);
static u16 f_dd46(u16 param_1,u16 param_2);
static u16 f_dd58(u16 param_1,u16 param_2);
static u16 f_ddb2(u16 param_1,u16 param_2);
static u16 f_de14(u16 param_1);
static u16 f_de32(void);
static u16 f_de66(u16 param_1);
static u16 f_de76(void);
static u16 f_de9e(u16 param_1);
static u16 f_dec0(u8 param_1);
static u16 f_def0(u16 param_1);
static u16 f_df20(void);
static u16 f_df46(u16 param_1,u16 param_2);
static u16 f_dfe2(u16 param_1,u16 param_2,u16 param_3);

// 1000:0010 FUN_1000_0010
static u16 f_0010(void)

{
  FN(0x0010);
  u16 uVar1;
  
  f_97a4();
  f_0252();
  f_0708();
  f_998a();
  f_435e();
  f_46f6();
  f_09ee();
  f_0062();
  f_a850();
  f_4706();
  if (*PS16(0x4a) != 0) {
    f_03b2();
  }
  f_9a00();
  if (*PS16(0x4a) == 0) {
    f_07ba(0 /* ARGS? */);
    DRV();
    uVar1 = 0;
  }
  else {
    f_d87e();
    uVar1 = *P16(0x4a);
  }
  return f_e19a(uVar1);
}

// 1000:0062 FUN_1000_0062
static u16 f_0062(void)

{
  FN(0x0062);
  
  *P8(0x57) = 1;
  while (*PS8(0x8b32) == '\0') {
    f_11ea();
    f_c47e();
    f_0a2e();
    f_3a70();
    f_3bb8();
    f_71b4();
    f_4dee();
    f_ba00();
    f_bc52();
    if (((*PS8(0x44) == '\0') && (*PS8(0x3435) != '\0')) && (*PS16(0xe4) == 0)) {
      f_0827(0 /* ARGS? */);
      *P8(0x3435) = 0;
    }
  }
  return 0 /* AX? */;
}

// 1000:00AA FUN_1000_00aa
static u16 f_00aa(void)

{
  FN(0x00AA);
  u8 bVar1;
  i16 iVar2;
  u16 uVar3;
  u16 local_a;
  
  *P16(0x8132) = 0;
  *P16(0x8130) = 0x4f2;
  *P16(0x734a) = 0;
  *P16(0x7348) = 0x4f4;
  *P16(0xae56) = BIOS16(0x04f0);
  *P16(0xae54) = 0;
  if (*SH16(0x22) < 5) {
    *P8(0x44) = *SH8(0x22);
  }
  else {
    *P8(0x44) = 0;
  }
  if (*SHS16(0x30) != 0) {
    *P8(0x42) = 1;
  }
  f_0690();
  *P8(0x232f) = *SH8(0x310);
  FUN_1fe7_058b(*SH16(0x1c));
  FUN_1fe7_058b(*SH16(0x1e));
  *P8(0x52) = *SH8(0x34);
  f_0200();
  bVar1 = *SH8(0x3a);
  *P8(0x3450) = bVar1;
  if ((bVar1 == 0) || (0x1b < bVar1)) {
    f_07ba(0 /* ARGS? */);
    f_e5b4(0x5342, *P8(0x3450));
    f_e19a(0);
  }
  *P8(0x46) = *SH8(0x38);
  local_a = *SHS16(0x36) * 2;
  if (*SHS16(0x3c) == 5) {
    local_a = local_a + 1;
  }
  if (*PS8(0x3450) == '\x05') {
    local_a = local_a + 1;
  }
  if (*PS8(0x353a) == '\x02') {
    local_a = local_a + 2;
  }
  uVar3 = f_1746(local_a, 0);
  bVar1 = f_1756(uVar3, 7);
  *P8(0x355c) = bVar1 & 7;
  iVar2 = f_7122();
  if (iVar2 == 0) {
    *P8(0x48) = 0;
  }
  else {
    *P8(0x48) = *SH8(0x60);
  }
  if (*PS8(0x3450) == '\x15') {
    *P8(0x48) = 0;
  }
  if (*PS8(0x3450) == '\x16') {
    *P8(0x48) = 1;
  }
  return 0 /* AX? */;
}

// 1000:0200 FUN_1000_0200
static u16 f_0200(void)

{
  FN(0x0200);
  
  *SH16(0x4e) = 0;
  *SH16(0x4c) = 0;
  *SH16(0x54) = 0;
  *SH16(0x52) = 0;
  *SH16(0x2a) = 0;
  *SH16(0x62) = 0;
  *SH16(0x56) = 0;
  *SH16(0x78) = 1;
  return 0 /* AX? */;
}

// 1000:0252 FUN_1000_0252
static u16 f_0252(void)

{
  FN(0x0252);
  
  f_00aa();
  f_d6aa(0);
  DRV(*P8(0x43));
  DRV();
  *P8(0x353a) = *P8(*P8(0x3450) + 0x3452);
  return 0 /* AX? */;
}

// 1000:0280 FUN_1000_0280
static u16 f_0280(void)

{
  FN(0x0280);
  u16 uVar1;
  i16 iVar2;
  
  *SH16(0x310) = (u16)*P8(0x232f);
  uVar1 = f_03a0(*P8(0x34a8));
  *SH16(0x4e) = uVar1;
  uVar1 = f_03a0(*P8(0x34aa));
  *SH16(0x4c) = uVar1;
  uVar1 = f_03a0(*P8(0x9e18));
  *SH16(0x54) = uVar1;
  uVar1 = f_d782();
  uVar1 = f_03a0(uVar1);
  *SH16(0x2a) = uVar1;
  if (*SHS16(0x2a) == 0) {
    iVar2 = f_4e22();
    if (iVar2 != 0) {
      iVar2 = f_7130();
      if (iVar2 == 0) {
        uVar1 = f_03a0(*P8(0x34a9));
        *SH16(0x52) = uVar1;
        goto LAB_1000_0322;
      }
    }
    *SH16(0x52) = 1;
  }
  else {
    *SH16(0x52) = 0;
  }
LAB_1000_0322:
  *SH16(0x56) = (u16)*P8(0x7340);
  if (*PS8(*P8(0x3558) + 0x343e) == '\0') {
    *SH16(0x78) = 1;
  }
  else {
    *SHS16(0x78) =
         (u16)*P8(0x343e) + (u16)*P8(0x343f) + (u16)*P8(0x3440);
  }
  if ((((*SHS16(0x4e) == 0) && (*SHS16(0x4c) == 0)) &&
      (*SHS16(0x2a) == 0)) && ((*SHS16(0x52) != 0 && (*PS8(0x34ab) == '\0')))
     ) {
    *SH16(0x62) = 1;
    return 0 /* AX? */;
  }
  *SH16(0x62) = 0;
  return 0 /* AX? */;
}

// 1000:03A0 FUN_1000_03a0
static u16 f_03a0(i8 param_1)

{
  FN(0x03A0);
  if (param_1 != '\0') {
    return 1;
  }
  return 0;
}

// 1000:03B2 FUN_1000_03b2
static u16 f_03b2(void)

{
  FN(0x03B2);
  
  DRV();
  f_0280();
  *P8(0x47) = 1;
  return 0 /* AX? */;
}

// 1000:03C0 FUN_1000_03c0
static u16 f_03c0(void)

{
  FN(0x03C0);
  i16 iVar1;
  i16 iVar2;
  u16 uVar3;
  u16 local_4;
  
  iVar1 = *SHS16(0x3c);
  if (iVar1 == 0) {
    local_4 = *SH16(0x3e);
  }
  else if (iVar1 == 1) {
    local_4 = *SH16(0x44);
  }
  else if (iVar1 == 2) {
    local_4 = *SH16(0x46);
  }
  else if (iVar1 == 3) {
    local_4 = *SH16(0x48);
  }
  else if (iVar1 == 4) {
    local_4 = *SH16(0x4a);
  }
  else if (iVar1 == 5) {
    local_4 = *SH16(0x40);
  }
  iVar1 = f_7130();
  if (iVar1 != 0) {
    local_4 = *SH16(0x3e);
  }
  return local_4;
}

// 1000:0430 FUN_1000_0430
static u16 f_0430(u16 param_1)

{
  FN(0x0430);
  i16 iVar1;
  i16 iVar2;
  u16 uVar3;
  
  iVar1 = *SHS16(0x3c);
  if (iVar1 == 0) {
    *SH16(0x3e) = param_1;
  }
  else {
    if (iVar1 == 1) {
      *SH16(0x44) = param_1;
      return 0 /* AX? */;
    }
    if (iVar1 == 2) {
      *SH16(0x46) = param_1;
      return 0 /* AX? */;
    }
    if (iVar1 == 3) {
      *SH16(0x48) = param_1;
      return 0 /* AX? */;
    }
    if (iVar1 == 4) {
      *SH16(0x4a) = param_1;
      return 0 /* AX? */;
    }
    if (iVar1 != 5) {
      return 0 /* AX? */;
    }
    *SH16(0x40) = param_1;
  }
  return 0 /* AX? */;
}

// 1000:04AA FUN_1000_04aa
static u8 f_04aa(i16 param_1)

{
  FN(0x04AA);
  u8 bVar1;
  i16 iVar2;
  u16 uVar3;
  u8 local_6;
  u16 local_4;
  
  local_6 = 1;
  if ((param_1 != -1) && (param_1 != 2)) {
    if (((param_1 != *SHS16(0x3e)) &&
        (((param_1 != *SHS16(0x44) && (param_1 != *SHS16(0x46))) &&
         (param_1 != *SHS16(0x48))))) &&
       ((param_1 != *SHS16(0x4a) && (param_1 != *SHS16(0x40))))) {
      local_4 = 0;
      do {
        if (*SHS16(local_4 * 2 + 800) == param_1) {
          local_6 = 0;
        }
        bVar1 = (i8)local_4 + 1;
        local_4 = (u16)bVar1;
      } while (bVar1 < 10);
      return local_6;
    }
  }
  return 0;
}

// 1000:0534 FUN_1000_0534
static u16 f_0534(void)

{
  FN(0x0534);
  u16 uVar1;
  i16 iVar2;
  
  do {
    uVar1 = f_170e(30000);
    iVar2 = f_04aa(uVar1);
  } while (iVar2 == 0);
  return uVar1;
}

// 1000:055A FUN_1000_055a
static u16 f_055a(void)

{
  FN(0x055A);
  u16 uVar1;
  u16 uVar2;
  
  if (*PS8(0x3450) == '\x1a') {
    *P8(0x48) = 0;
  }
  else if (*PS8(0x3450) != '\x05') {
    if (*PS8(0x3450) == '\x15') {
      return 1;
    }
    if (*PS8(0x3450) == '\x16') {
      return 2;
    }
    if (*SHS16(0x3c) == 5) {
      uVar1 = f_1756(3, *P8(0x46) + 1);
    }
    else {
      uVar1 = *P8(0x46) & 3;
    }
    uVar2 = f_1746(1, uVar1);
    return uVar2;
  }
  return 3;
}

// 1000:05BA FUN_1000_05ba
static u16 f_05ba(void)

{
  FN(0x05BA);
  
  *SH16(0x62) = 1;
  return 0 /* AX? */;
}

// 1000:05C6 FUN_1000_05c6
static u16 f_05c6(void)

{
  FN(0x05C6);
  u8 bVar1;
  u16 uVar2;
  
  f_4e5c();
  bVar1 = 0;
  do {
    uVar2 = f_0534();
    *SH16((u16)bVar1 * 2 + 800) = uVar2;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 10);
  *SH8(0x31e) = 0;
  return 0 /* AX? */;
}

// 1000:0602 FUN_1000_0602
static u16 f_0602(void)

{
  FN(0x0602);
  u16 uVar1;
  i16 iVar2;
  u16 uVar3;
  u16 uVar4;
  
  if (*SHS8(0x31e) == -1) {
    f_05c6();
  }
  uVar3 = *SH16(*SHS8(0x31e) * 2 + 800);
  uVar1 = f_0534();
  *SH16(*SHS8(0x31e) * 2 + 800) = uVar1;
  *SH8(0x31e) = (i8)((*SHS8(0x31e) + 1) % 10);
  return uVar3;
}

// 1000:0676 FUN_1000_0676
static u8 f_0676(void)

{
  FN(0x0676);
  i16 iVar1;
  
  iVar1 = f_4e22();
  if (iVar1 != 0) {
    iVar1 = f_7130();
    if (iVar1 == 0) {
      return *P8(0x48);
    }
  }
  return 0;
}

// 1000:068E FUN_1000_068e
static u16 f_068e(void)

{
  FN(0x068E);
  return 0 /* AX? */;
}

// 1000:0690 FUN_1000_0690
static u16 f_0690(void)

{
  FN(0x0690);
  i8 cVar1;
  u16 uVar2;
  
  cVar1 = *PS8(0x44);
  if (cVar1 == '\0') {
    *P8(0x4c) = 0;
    uVar2 = 0x536a;
  }
  else if (cVar1 == '\x01') {
    *P8(0x4c) = 1;
    uVar2 = 0x5386;
  }
  else if (cVar1 == '\x02') {
    *P8(0x4c) = 2;
    uVar2 = 0x535c;
  }
  else if (cVar1 == '\x03') {
    *P8(0x4c) = 0;
    *P8(0x43) = 4;
    uVar2 = 0x5378;
  }
  else if (cVar1 == '\x04') {
    *P8(0x4c) = 2;
    uVar2 = 0x5394;
  }
  else {
    if (cVar1 != '\x05') {
      return 0 /* AX? */;
    }
    *P8(0x4c) = 0;
    uVar2 = 0x53a2;
  }
  uVar2 = FUN_1fe7_0492(uVar2);
  FUN_1fe7_058b(uVar2);
  return 0 /* AX? */;
}

// 1000:0708 FUN_1000_0708
static u16 f_0708(void)

{
  FN(0x0708);
  bool bVar1;
  u16 local_6;
  u16 local_4;
  
  FUN_1fe7_0216();
  *P8(0x57) = 1;
  local_4 = 0;
  local_6 = 0;
  *P16(0x53) = 0;
  do {
    bVar1 = 0xfffe < local_6;
    local_6 = local_6 + 1;
    local_4 = local_4 + (u16)bVar1;
  } while (*PS16(0x53) < 0xf);
  *P8(0x57) = 0;
  if ((local_4 < 1) && ((local_4 < 0 || (local_6 < 15000)))) {
    *P8(0x342a) = 1;
    *P8(0x3564) = 2;
  }
  FUN_1fe7_0254();
  return 0 /* AX? */;
}

// 1000:075A FUN_1000_075a  FIX: the CRTC start address (hardware scrolling): nothing to simulate
static u32 f_075a(void)
{
  FN(0x075A);
  return 0;
}

// 1000:0776 FUN_1000_0776  FIX: CRTC ports
static u32 f_0776(u16 param_1, u16 param_2, u16 param_3)
{
  FN(0x0776);
  (void)param_2;
  return CONCAT22(param_1, param_3);
}

// 1000:078E FUN_1000_078e
static u16 f_078e(void)

{
  FN(0x078E);
  return f_0776(0 /* ARGS? */, 0 /* ARGS? */, 0 /* ARGS? */);
}

// 1000:07BA FUN_1000_07ba  FIX: INT 10h (video BIOS)
static u16 f_07ba(u16 param_1)
{
  FN(0x07BA);
  return param_1;
}

// 1000:07C2 FUN_1000_07c2  FIX: the 77 countdown timers at [DS:0055] (= DS:0058) decrement, stopping at 0
static u16 f_07c2(void)
{
  FN(0x07C2);
  i16a *t = PS16(*P16(0x55));
  for (int k = 0; k < 0x4d; k++)
    if (t[k] != 0) t[k]--;
  return 0;
}

// 1000:07E8 FUN_1000_07e8  FIX: all timers to 0
static u16 f_07e8(void)
{
  FN(0x07E8);
  u16a *t = P16(*P16(0x55));
  for (int k = 0; k < 0x4d; k++) t[k] = 0;
  return 0;
}

// 1000:0808 FUN_1000_0808  FIX: INT 10h (video BIOS)
static u16 f_0808(void)
{
  FN(0x0808);
  return 0;
}

// 1000:081A FUN_1000_081a  FIX: INT 10h (video BIOS)
static u16 f_081a(u16 param_1)
{
  FN(0x081A);
  return param_1;
}

// 1000:0827 FUN_1000_0827  FIX: INT 10h (video BIOS)
static u16 f_0827(u16 param_1)
{
  FN(0x0827);
  return param_1;
}

// 1000:0834 FUN_1000_0834
static u16 f_0834(void)

{
  FN(0x0834);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = *PS16(0x50);
  iVar2 = f_0870(*P16(0x730c));
  *PS16(0x50) = iVar2;
  if (iVar1 != iVar2) {
    if (iVar2 < iVar1) {
      f_d766();
      f_075a();
    }
    if (iVar1 < *PS16(0x50)) {
      f_075a();
      f_d770();
    }
  }
  return 0 /* AX? */;
}

// 1000:0870 FUN_1000_0870
static u16 f_0870(u16 param_1)

{
  FN(0x0870);
  i16 iVar1;
  u16 local_4;
  
  if (param_1 < 0x65) {
    local_4 = 0;
  }
  else {
    local_4 = param_1 - 100;
  }
  iVar1 = f_08b4();
  if (iVar1 + 0xc0U <= local_4) {
    iVar1 = f_08b4();
    local_4 = iVar1 + 0xc0;
  }
  return *P8(*P8(0x4c) + 0x232a) & local_4;
}

// 1000:08B4 FUN_1000_08b4
static u16 f_08b4(void)

{
  FN(0x08B4);
  i16 iVar1;
  
  iVar1 = f_4e22();
  if (iVar1 != 0) {
    return 6;
  }
  return 0;
}

// 1000:08C4 FUN_1000_08c4
static u16 f_08c4(u8 param_1)

{
  FN(0x08C4);
  
  if (*PS8(0x232f) == '\x01') {
    if (0x25 < param_1) {
      return 0 /* AX? */;
    }
  }
  else {
    if (*PS8(0x232f) != '\0') {
      return 0 /* AX? */;
    }
    if (0x56 < param_1) {
      return 0 /* AX? */;
    }
  }
  DRV(param_1);
  return 0 /* AX? */;
}

// 1000:08F4 FUN_1000_08f4
static u16 f_08f4(void)

{
  FN(0x08F4);
  u8 bVar1;
  u16 uVar2;
  u16 uVar3;
  
  uVar2 = 0x1000;
  if (*PS8(0x232f) == '\0') {
    uVar2 = 0x20ba;
    DRV(2);
  }
  uVar3 = uVar2;
  if (*PS8(0x232f) == '\x01') {
    uVar3 = 0x20ba;
    DRV(0);
  }
  if (*PS8(0x232f) == '\x02') {
    DRV(0x52);
  }
  bVar1 = *P8(0x232f);
  *P8(0x232f) = (i8)((u32)(bVar1 + 1) % 3);
  return (bVar1 + 1) / 3;
}

// 1000:0948 FUN_1000_0948
static u16 f_0948(i16 param_1)

{
  FN(0x0948);
  i8 cVar1;
  u16 uVar2;
  
  cVar1 = *PS8(param_1 + -0x74ca);
  if ((cVar1 == '\0') || (cVar1 == '\x01')) {
    uVar2 = 0x1c;
  }
  else if (cVar1 == '\x02') {
    uVar2 = 10;
  }
  else {
    if (cVar1 != '\x03') {
      return 0 /* AX? */;
    }
    uVar2 = 6;
  }
  return f_08c4(uVar2);
}

// 1000:098C FUN_1000_098c
static u16 f_098c(u8 param_1)

{
  FN(0x098C);
  
  *P8(0x232e) = param_1;
  DRV(param_1);
  return 0 /* AX? */;
}

// 1000:09A4 FUN_1000_09a4
static u16 f_09a4(void)

{
  FN(0x09A4);
  return f_098c(4);
}

// 1000:09B0 FUN_1000_09b0
static u16 f_09b0(void)

{
  FN(0x09B0);
  return f_098c(5);
}

// 1000:09BC FUN_1000_09bc
static u16 f_09bc(void)

{
  FN(0x09BC);
  return f_098c(0);
}

// 1000:09C6 FUN_1000_09c6
static u16 f_09c6(void)

{
  FN(0x09C6);
  i16 iVar1;
  
  if (*PS8(0x34a8) == '\0') {
    iVar1 = f_7122();
    if (iVar1 == 0) {
      if (*PS8(0x34aa) == '\0') goto LAB_1000_09e9;
    }
    else if (*PS8(0x34aa) != '\0') {
LAB_1000_09e9:
      return f_09b0();
    }
  }
  return f_09bc();
}

// 1000:09EE FUN_1000_09ee
static u16 f_09ee(void)

{
  FN(0x09EE);
  f_098c(2);
  return f_08c4(0x52);
}

// 1000:0A04 FUN_1000_0a04
static u16 f_0a04(void)

{
  FN(0x0A04);
  return f_e5b4(0x53b0);
}

// 1000:0A10 FUN_1000_0a10
static u16 f_0a10(i8 param_1)

{
  FN(0x0A10);
  u8 local_4;
  
  local_4 = param_1;
  while (local_4 != '\0') {
    local_4 = local_4 + -1;
    f_0a04();
  }
  return 0 /* AX? */;
}

// 1000:0A2E FUN_1000_0a2e
static u16 f_0a2e(void)

{
  FN(0x0A2E);
  i16 iVar1;
  u8 local_4;
  
  local_4 = 0;
  do {
    iVar1 = f_38ea(local_4);
    if (iVar1 != 0) {
      f_0a62(local_4);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:0A62 FUN_1000_0a62
static u16 f_0a62(u8 param_1)

{
  FN(0x0A62);
  i16 iVar1;
  
  iVar1 = f_38ea(param_1);
  if (iVar1 == 2) {
    iVar1 = f_3a8c();
    if (iVar1 != 0) {
      return f_393a(param_1, 0);
    }
  }
  else if (*PS16((u16)param_1 * 2 + 0x9e) == 0) {
    f_0aba((u16)param_1);
    *P16((u16)param_1 * 2 + 0x9e) = 4;
  }
  return 0 /* AX? */;
}

// 1000:0ABA FUN_1000_0aba
static u16 f_0aba(u8 param_1)

{
  FN(0x0ABA);
  i16 iVar1;
  i16 iVar2;
  i16 iVar3;
  
  iVar1 = f_0b46(param_1);
  if (iVar1 == 0) {
    iVar1 = f_1132(param_1);
    if (iVar1 == 0) {
      iVar1 = f_390a(param_1);
      iVar2 = f_399a(param_1);
      iVar3 = f_38fa(param_1);
      f_395e(param_1, *PS8(iVar3 + 0x3572) * iVar2 + iVar1);
      return f_1096(param_1);
    }
  }
  return f_393a(param_1, 2);
}

// 1000:0B46 FUN_1000_0b46
static u8 f_0b46(u8 param_1)

{
  FN(0x0B46);
  i16 iVar1;
  u8 local_4;
  
  iVar1 = f_38fa(param_1);
  if (iVar1 == 0) {
LAB_1000_0b6e:
    local_4 = f_0b92(param_1);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 4) goto LAB_1000_0b6e;
      if (iVar1 != 6) {
        return local_4;
      }
    }
    local_4 = f_0c4c(param_1);
  }
  return local_4;
}

// 1000:0B92 FUN_1000_0b92  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_0b92(u8 param_1)

{
  FN(0x0B92);
  u8 uVar1;
  u8 uVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  i8 local_e;
  u8 local_4;
  
  local_e = '\0';
  iVar3 = f_390a(param_1);
  iVar4 = f_390a(param_1);
  for (local_4 = 0; local_4 < 7; local_4 = local_4 + 1) {
    if ((local_4 != param_1) && (*PS8(local_4 + 0xae6b) != '\0')) {
      uVar1 = f_1766(iVar3 % 0x4d & 0xff, *P8(local_4 + 0x7776));
      uVar2 = f_1766(iVar4 / 0x4d & 0xff, *P8(local_4 + 0x79ee));
      if ((local_e == '\0') && (iVar5 = f_0d04(param_1, local_4, uVar2, uVar1), iVar5 == 0)) {
        local_e = '\0';
      }
      else {
        local_e = '\x01';
      }
    }
  }
  return local_e;
}

// 1000:0C4C FUN_1000_0c4c  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_0c4c(u8 param_1)

{
  FN(0x0C4C);
  u8 uVar1;
  u8 uVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  i8 local_e;
  u8 local_4;
  
  local_e = '\0';
  iVar3 = f_390a(param_1);
  iVar4 = f_390a(param_1);
  for (local_4 = 0; local_4 < 7; local_4 = local_4 + 1) {
    if ((local_4 != param_1) && (*PS8(local_4 + 0xae6b) != '\0')) {
      uVar1 = f_1766(iVar3 % 0x4d & 0xff, *P8(local_4 + 0x7776));
      uVar2 = f_1766(iVar4 / 0x4d & 0xff, *P8(local_4 + 0x79ee));
      if ((local_e == '\0') && (iVar5 = f_0d04(param_1, local_4, uVar1, uVar2), iVar5 == 0)) {
        local_e = '\0';
      }
      else {
        local_e = '\x01';
      }
    }
  }
  return local_e;
}

// 1000:0D04 FUN_1000_0d04
static u8 f_0d04(u8 param_1,u8 param_2,u8 param_3,u8 param_4)

{
  FN(0x0D04);
  i16 iVar1;
  i16 iVar2;
  u16 uVar3;
  u8 local_4;
  
  iVar1 = f_38fa(param_1);
  iVar2 = f_8986(param_1, param_2);
  if (iVar2 == iVar1) {
    local_4 = 0;
    uVar3 = f_38d0(param_1);
    if ((((param_3 <= uVar3) && (param_4 < 2)) &&
        (uVar3 = f_170e(100),
        uVar3 < ((u16)*P8(param_1 + 0x7353) + (u16)param_4 * -2) * 0x14 + 0x50)) &&
       ((*PS8(param_2 + 0x9e24) == '\0' || (*PS8(param_2 + 0x9b06) != '\0')))) {
      f_a730(param_2, param_1);
      local_4 = 1;
      iVar1 = f_390a(param_1);
      iVar2 = f_38fa(param_1);
      f_395e(param_1, (u16)*P8(iVar2 + 0x3572) * (u16)param_3 + iVar1);
      f_1096(param_1);
    }
    return local_4;
  }
  return 0;
}

// 1000:0DF4 FUN_1000_0df4
static u16 f_0df4(u8 param_1)

{
  FN(0x0DF4);
  i16 iVar1;
  
  iVar1 = f_38ea(param_1);
  if (iVar1 == 1) {
    return 2;
  }
  return 1;
}

// 1000:0E14 FUN_1000_0e14
static u16 f_0e14(u8 param_1)

{
  FN(0x0E14);
  i16 iVar1;
  
  iVar1 = f_38ea(param_1);
  if (iVar1 == 0) {
    f_395e((u16)param_1, *P16((u16)param_1 * 2 + -0x76b2));
    f_1096(param_1);
    f_394c((u16)param_1, *P8(param_1 + 0x7596) & 6);
  }
  return 0 /* AX? */;
}

// 1000:0E64 FUN_1000_0e64
static u16 f_0e64(u8 param_1)

{
  FN(0x0E64);
  f_0e14(param_1);
  return f_393a(param_1, 3);
}

// 1000:0E86 FUN_1000_0e86
static u16 f_0e86(u8 param_1)

{
  FN(0x0E86);
  f_0e14(param_1);
  return f_393a(param_1, 1);
}

// 1000:0EA8 FUN_1000_0ea8
static u16 f_0ea8(u8 param_1)

{
  FN(0x0EA8);
  f_0e14(param_1);
  return f_393a(param_1, 4);
}

// 1000:0ECA FUN_1000_0eca
static u16 f_0eca(u8 param_1)

{
  FN(0x0ECA);
  i16 iVar1;
  
  i16 y = f_391a(param_1) / 0x1c;  // FIX: pushed before the other call (Ghidra lost it)
  iVar1 = f_392a(param_1);
  return f_c3a0(iVar1 / 0x1c, y);
}

// 1000:0EFC FUN_1000_0efc
static u16 f_0efc(u8 param_1,u8 param_2)

{
  FN(0x0EFC);
  i16 iVar1;
  
  iVar1 = f_1766(*P8(param_1 + 0x7776), *P8(param_2 + 0x7776));
  if (iVar1 < 2) {
    return 1;
  }
  return 0;
}

// 1000:0F28 FUN_1000_0f28
static u16 f_0f28(u8 param_1,u8 param_2)

{
  FN(0x0F28);
  i16 iVar1;
  
  iVar1 = f_1766(*P8(param_1 + 0x79ee), *P8(param_2 + 0x79ee));
  if (iVar1 < 2) {
    return 1;
  }
  return 0;
}

// 1000:0F54 FUN_1000_0f54
static u16 f_0f54(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x0F54);
  
  if ((*P8(param_2 + 0x7776) <= *P8(param_1 + 0x7776)) ||
     (*P8(param_3 + 0x7776) <= *P8(param_2 + 0x7776))) {
    if ((*P8(param_2 + 0x7776) <= *P8(param_3 + 0x7776)) ||
       (*P8(param_1 + 0x7776) <= *P8(param_2 + 0x7776))) {
      return 0;
    }
  }
  return 1;
}

// 1000:0FA4 FUN_1000_0fa4
static u16 f_0fa4(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x0FA4);
  
  if ((*P8(param_2 + 0x79ee) <= *P8(param_1 + 0x79ee)) ||
     (*P8(param_3 + 0x79ee) <= *P8(param_2 + 0x79ee))) {
    if ((*P8(param_2 + 0x79ee) <= *P8(param_3 + 0x79ee)) ||
       (*P8(param_1 + 0x79ee) <= *P8(param_2 + 0x79ee))) {
      return 0;
    }
  }
  return 1;
}

// 1000:0FF4 FUN_1000_0ff4
static u8 f_0ff4(u8 param_1)

{
  FN(0x0FF4);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_6 = 1;
  local_4 = 1;
  do {
    if (6 < local_4) {
      return local_6;
    }
    if (*PS8(local_4 + 0xae6b) != '\0') {
      if (local_4 != param_1) {
        if ((*P8(param_1 + 0x7596) & 2) == 0) {
          iVar1 = f_0efc(param_1, local_4);
          if (iVar1 != 0) {
            iVar1 = f_0fa4(param_1, local_4, 0);
LAB_1000_1028:
            if (iVar1 != 0) {
              local_6 = 0;
            }
          }
        }
        else if ((*P8(param_1 + 0x7596) & 2) == 2) {
          iVar1 = f_0f28(param_1, local_4);
          if (iVar1 != 0) {
            iVar1 = f_0f54(param_1, local_4, 0);
            goto LAB_1000_1028;
          }
        }
        else {
          f_068e();
        }
      }
    }
    local_4 = local_4 + 1;
  } while( true );
}

// 1000:1096 FUN_1000_1096
static u16 f_1096(u8 param_1)

{
  FN(0x1096);
  i16 iVar1;
  
  iVar1 = f_390a(param_1);
  f_3972(param_1, iVar1 % 0x4d << 2);
  iVar1 = f_390a(param_1);
  return f_3986(param_1, iVar1 / 0x4d << 2);
  return 0 /* AX? */;
}

// 1000:10E2 FUN_1000_10e2
static u16 f_10e2(u8 param_1)

{
  FN(0x10E2);
  i16 iVar1;
  u8 local_4;
  
  local_4 = 0;
  do {
    if (local_4 != param_1) {
      iVar1 = f_38ea(local_4);
      if (iVar1 != 0) {
        f_38fa(local_4);
        f_8986(local_4, param_1);
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:1132 FUN_1000_1132
static u8 f_1132(u8 param_1)

{
  FN(0x1132);
  u8 bVar1;
  i16 iVar2;
  i16 iVar3;
  u8 local_8;
  u8 local_4;
  
  local_4 = f_399a(param_1);
  local_8 = 0;
  bVar1 = f_38fa(param_1);
  iVar2 = f_390a(param_1);
  for (; local_4 != 0; local_4 = local_4 - 1) {
    iVar3 = f_a0dc((i16)*PS8(bVar1 + 0x3572) * (local_4 - 1) + iVar2);
    if (iVar3 == 0) {
      local_8 = 1;
    }
  }
  return local_8;
}

// 1000:11A4 FUN_1000_11a4
static u16 f_11a4(u8 param_1)

{
  FN(0x11A4);
  i8 cVar1;
  u16 uVar2;
  
  u16 dir = f_1c36(f_38fa(param_1));  // FIX: pushed before the other call (Ghidra lost it)
  uVar2 = f_0eca(param_1);
  cVar1 = f_20f2(uVar2, dir);
  if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
    return 0;
  }
  return 1;
}

// 1000:11EA FUN_1000_11ea
static u16 f_11ea(void)

{
  FN(0x11EA);
  f_1230(0);
  f_1230(1);
  f_1230(2);
  f_1230(3);
  f_1230(4);
  f_1230(5);
  return f_1230(6);
}

// 1000:1230 FUN_1000_1230
static u16 f_1230(u8 param_1)

{
  FN(0x1230);
  i16 iVar1;
  u16 uVar2;
  i16a *piVar3;
  
  if ((*PS8(param_1 + 0xae6b) != '\0') && (iVar1 = f_3afa((u16)param_1), iVar1 == 0)) {
    f_13b8(param_1);
    if (*PS8(param_1 + 0x734c) == '\0') {
      f_aaae((u16)param_1);
    }
    else {
      uVar2 = (u16)param_1;
      if (*PS16(uVar2 * 2 + 200) == 0) {
        if (*PS8(uVar2 + 0x9b06) == '\0') {
          if (((param_1 == 0) && (*PS16(0x74) == 0)) && (iVar1 = f_9f4e(), iVar1 != 0)) {
            iVar1 = f_6836(0);
            if ((iVar1 == 0) && (iVar1 = f_687e(), iVar1 == 0)) {
              iVar1 = f_6766(0);
              if (iVar1 == 0) {
                f_a440(0);
              }
              else {
                f_69ea(0);
              }
            }
            else {
              f_68d0(0);
            }
          }
          if (*PS16((u16)param_1 * 2 + 0x74) == 0) {
            f_a424((u16)param_1);
          }
        }
        else {
          f_7a66(uVar2);
        }
        *P16((u16)param_1 * 2 + 200) = 2;
      }
      piVar3 = PS16((u16)param_1 * 2 + 0x58);
      if (*piVar3 == 0) {
        iVar1 = f_1792((u16)param_1);
        *piVar3 = iVar1;
        if (*PS8(param_1 + 0xaefc) != '\0') {
          f_876e((u16)param_1);
        }
        if (*PS8(param_1 + 0xaefc) == '\0') {
          f_1392((u16)param_1);
        }
        if (*PS8(param_1 + 0x9b06) == '\0') {
          f_796a((u16)param_1);
        }
        else {
          f_8824(param_1);
        }
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:1392 FUN_1000_1392  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u16 f_1392(u8 param_1)

{
  FN(0x1392);
  if (param_1 == '\0') {
    return f_1542(0);
  }
  return f_159e(param_1);
}

// 1000:13B8 FUN_1000_13b8
static u16 f_13b8(u8 param_1)

{
  FN(0x13B8);
  i16 iVar1;
  u16 uVar2;
  u8 bVar3;
  u8 local_4;
  
  if (1 < *P8(param_1 + 0x9e18)) {
    iVar1 = f_7108((u16)param_1);
    if (iVar1 != 0) {
      *P8(0x342c) = 1;
      f_71aa();
    }
    f_aa12(param_1, 0);
    if (*PS8(param_1 + 0x85fe) == '\x04') {
      f_707e((u16)param_1, 4);
      f_39b4();
    }
    iVar1 = f_7158(param_1);
    if (iVar1 != 0) {
      f_71aa();
    }
    f_2420(*P8(param_1 + 0xae64));
    uVar2 = (u16)param_1;
    *P16(*PS16(0x75fc) * 2 + 0x7796) = *P16(uVar2 * 2 + -0x76b2);
    *P8(*PS16(0x75fc) + 0x75fe) = *P8(uVar2 + 0x7596);
    if (*PS8(uVar2 + 0x9e24) == '\0') {
      *P8(*PS16(0x75fc) + -0x79f4) = *P8(param_1 + 0x8b36);
    }
    else {
      *P8(*PS16(0x75fc) + -0x79f4) = 5;
    }
    *P8(*PS16(0x75fc) + -0x644a) = *P8(0x3558);
    f_32e8(*P8(param_1 + 0xae64), 10);
    if (param_1 != 0) {
      *PS8(0x7340) = *PS8(0x7340) + '\x01';
    }
    if (*PS8(param_1 + 0x8947) == '\0') {
      local_4 = 1;
      do {
        if (((local_4 != param_1) && (uVar2 = (u16)local_4, *PS8(uVar2 + 0xae6b) != '\0')) &&
           (*PS8(uVar2 + 0x734c) != '\0')) {
          f_1ca2(uVar2);
        }
        local_4 = local_4 + 1;
      } while (local_4 < 7);
    }
    uVar2 = (u16)param_1;
    *P8(uVar2 + 0x8134) = 4;
    iVar1 = uVar2 * 2;
    *P8(uVar2 + 0x79ee) = (i8)((u32)*P16(iVar1 + -0x76b2) / 0x4d);
    bVar3 = (u8)((u32)*P16(iVar1 + -0x76b2) % 0x4d);
    *P8(uVar2 + 0x7776) = bVar3;
    *PS16(iVar1 + 0x72d8) = (u16)bVar3 << 2;
    *PS16(iVar1 + 0x730c) = (u16)*P8(uVar2 + 0x79ee) << 2;
    f_961c(4, *P16(0x75fc));
    *PS16(0x75fc) = *PS16(0x75fc) + 1;
  }
  return 0 /* AX? */;
}

// 1000:1542 FUN_1000_1542
static u16 f_1542(u8 param_1)

{
  FN(0x1542);
  
  f_d858();
  f_3efe(param_1);
  f_b86c((u16)param_1, *P8(param_1 + 0xae64));
  f_9f8a();
  if (*PS16(0x9b74) != 8) {
    f_7f78(param_1, *P16(0x9b74));
  }
  f_7c16(*P16(0x894e));
  f_7496();
  return f_ba90();
}

// 1000:159E FUN_1000_159e
static u16 f_159e(u8 param_1)

{
  FN(0x159E);
  i16a *piVar1;
  
  piVar1 = PS16((u16)param_1 * 2 + 0x7768);
  *piVar1 = *piVar1 + 1;
  f_7e44((u16)param_1);
  if (*PS8(param_1 + 0xae3e) != '\0') {
    return f_1d36((u16)param_1);
  }
  return f_a8b2(param_1);
}

// 1000:15E0 FUN_1000_15e0
static u8 f_15e0(i8 param_1)

{
  FN(0x15E0);
  u8 local_6;
  u8 local_4;
  
  local_6 = 0;
  local_4 = 0;
  do {
    if ((*PS8(local_4 + 0xae6b) != '\0') && (*PS8(local_4 + 0xae64) == param_1)) {
      local_6 = 1;
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return local_6;
}

// 1000:161C FUN_1000_161c
static u8 f_161c(i8 param_1)

{
  FN(0x161C);
  u8 local_6;
  u8 local_4;
  
  local_6 = 0;
  local_4 = 1;
  do {
    if ((*PS8(local_4 + 0xae6b) != '\0') && (*PS8(local_4 + 0xae64) == param_1)) {
      local_6 = 1;
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return local_6;
}

// 1000:1658 FUN_1000_1658
static u8 f_1658(u8 param_1,i8 param_2)

{
  FN(0x1658);
  u16 uVar1;
  i16 iVar2;
  u8 local_6;
  u8 local_4;
  
  local_6 = 0;
  local_4 = 1;
  do {
    if (((((param_1 != local_4) && (uVar1 = (u16)local_4, *PS8(uVar1 + 0xae6b) != '\0')) &&
         (*PS8(uVar1 + 0xae64) == param_2)) &&
        ((param_2 != *PS8(0xae64) && (*PS8(uVar1 + 0xae64) != *PS8(param_1 + 0xae64))))
        ) && (iVar2 = f_1f1e((u16)param_1, uVar1), iVar2 == 0)) {
      local_6 = 1;
      if ((*PS8(param_1 + 0x734c) == '\x01') && (*PS8(local_4 + 0x734c) == '\x02')) {
        f_aa12((u16)local_4, 1);
      }
      if ((*PS8(local_4 + 0x734c) == '\x01') && (*PS8(param_1 + 0x734c) == '\x02')) {
        f_aa12((u16)param_1, 1);
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return local_6;
}

// 1000:170E FUN_1000_170e
static i16 f_170e(i16 param_1)

{
  FN(0x170E);
  i16 iVar1;
  
  iVar1 = f_fd0c();
  return iVar1 % param_1;
}

// 1000:1726 FUN_1000_1726
static u16 f_1726(u8 param_1)

{
  FN(0x1726);
  u16 uVar1;
  
  uVar1 = f_170e(100);
  if (uVar1 < param_1) {
    return 1;
  }
  return 0;
}

// 1000:1746 FUN_1000_1746
static i16 f_1746(i16 param_1,i16 param_2)

{
  FN(0x1746);
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return param_1;
}

// 1000:1756 FUN_1000_1756
static i16 f_1756(i16 param_1,i16 param_2)

{
  FN(0x1756);
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return param_1;
}

// 1000:1766 FUN_1000_1766
static i16 f_1766(u8 param_1,u8 param_2)

{
  FN(0x1766);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = f_1756(param_1, param_2);
  iVar2 = f_1746(param_1, param_2);
  return iVar2 - iVar1;
}

// 1000:1792 FUN_1000_1792  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_1792(u8 param_1)

{
  FN(0x1792);
  i16 iVar1;
  u8 local_4;
  
  local_4 = *PS8(0x2330);
  iVar1 = f_a0dc(*P16((u16)param_1 * 2 + -0x76b2));
  if (iVar1 == 4) {
    local_4 = *PS8(0x2330) * '\x03';
  }
  if ((*PS8(0x353a) == '\x03') && ((*P8(param_1 + 0x7d80) & 1) != 0)) {
    local_4 = local_4 << 1;
  }
  if (*PS8(param_1 + 0x7d80) != *PS8(param_1 + 0x7596)) {
    local_4 = local_4 << 1;
  }
  return local_4 << (*P8(param_1 + 0x9e18) & 0x1f);
}

// 1000:1802 FUN_1000_1802
static u8 f_1802(i16 param_1)

{
  FN(0x1802);
  u8 local_4;
  
  local_4 = *P8(*P8(param_1 + -0x74ca) + 0x2332);
  if ((*PS8(0x3450) == '\x1b') && (*PS8(param_1 + -0x74ca) == '\x03')) {
    local_4 = local_4 >> 1;
  }
  return local_4;
}

// 1000:1836 FUN_1000_1836
static i16 f_1836(u8 param_1)

{
  FN(0x1836);
  i8 cVar1;
  i8 cVar2;
  i16 iVar3;
  u8 local_4;
  
  cVar2 = *PS8(*P8(param_1 + 0x7353) + 0x2338);
  cVar1 = f_1802((u16)param_1);
  local_4 = cVar2 + cVar1;
  if (*PS8(param_1 + 0x9e18) != '\0') {
    local_4 = local_4 + *PS8(0x233c);
  }
  iVar3 = f_170e(8);
  local_4 = local_4 + *PS8(iVar3 + (*P16(param_1 + 0x7353) & 0xff) * 8 + 0x233e);
  if (param_1 != 0) {
    cVar2 = f_170e(3);
    local_4 = local_4 + cVar2;
  }
  return (u16)local_4 * 0xc;
}

// 1000:18B0 FUN_1000_18b0
static u16 f_18b0(u8 param_1)

{
  FN(0x18B0);
  
  *P16((u16)param_1 * 2 + 0x74) = 0x18;
  return 0 /* AX? */;
}

// 1000:18C2 FUN_1000_18c2
static u8 f_18c2(u8 param_1,u8 param_2)

{
  FN(0x18C2);
  u16 uVar1;
  
  uVar1 = f_1938(param_1, param_2);
  uVar1 = f_170e(-((uVar1 & 0xff) - 8));
  return *P8((uVar1 & 0xff) + (*P16(param_1 + 0x7353) & 0xff) * 8 + 0x235e);
}

// 1000:190C FUN_1000_190c
static u16 f_190c(u8 param_1,u8 param_2)

{
  FN(0x190C);
  u16 uVar1;
  
  uVar1 = f_8986((u16)param_1, param_2);
  if (*P8(param_1 + 0x7596) == uVar1) {
    return 1;
  }
  return 0;
}

// 1000:1938 FUN_1000_1938
static i32 f_1938(u8 param_1,u8 param_2)

{
  FN(0x1938);
  u16 uVar1;
  u16 in_DX;
  u32 uVar2;
  
  if (param_1 != 0) {
    uVar2 = f_7158(param_1);
    in_DX = (u16)((u32)uVar2 >> 0x10);
    if ((i16)uVar2 == 0) {
      uVar1 = f_190c((u16)param_1, (u16)param_2);
      return (u32)(*P8((u16)*P8(param_1 + 0x8b36) * 5 +
                               (u16)*P8(param_2 + 0x8b36) + 0x2386) & uVar1) *
             (u32)*P8(param_1 + 0x7353);
    }
  }
  return CONCAT22(in_DX,3);
}

// 1000:19A0 FUN_1000_19a0
static u8 f_19a0(u8 param_1)

{
  FN(0x19A0);
  i16 iVar1;
  u16 uVar2;
  u16 local_6;
  
  local_6 = (u16)(*PS8(0x7340) != '\0');
  iVar1 = f_170e(8);
  uVar2 = f_1756(7, (u16)*P8(param_1 + 0x40f4) + iVar1);
  return *P8((uVar2 & 0xff) + local_6 * 8 + 0x40e4);
}

// 1000:19F8 FUN_1000_19f8
static i16 f_19f8(u8 param_1)

{
  FN(0x19F8);
  i16 iVar1;
  
  iVar1 = f_170e(8);
  iVar1 = f_1746(0, iVar1 - (u16)*P8(param_1 + 0x4100));
  return (u16)*P8(iVar1 + 0x40f8) * 3;
}

// 1000:1A26 FUN_1000_1a26
static u8 f_1a26(u8 param_1)

{
  FN(0x1A26);
  
  return *P8(param_1 + 0x23a0);
}

// 1000:1A36 FUN_1000_1a36
static i16 f_1a36(u8 param_1,u8 param_2)

{
  FN(0x1A36);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = f_1a26(param_2);
  iVar2 = f_1a26(param_1);
  return iVar2 + iVar1;
}

// 1000:1A5A FUN_1000_1a5a
static u16 f_1a5a(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x1A5A);
  if ((u16)param_3 + (u16)param_2 < (u16)param_1) {
    return 1;
  }
  return 0;
}

// 1000:1A88 FUN_1000_1a88
static u16 f_1a88(u8 param_1,u8 param_2)

{
  FN(0x1A88);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_1a5a(0, param_1, param_2);
  if (iVar1 == 0) {
    iVar1 = f_1a5a(1, param_1, param_2);
    if (iVar1 == 0) {
      iVar1 = f_1a5a(2, param_1, param_2);
      if (iVar1 == 0) {
        iVar1 = f_1a5a(3, param_1, param_2);
        if (iVar1 != 0) {
          return 3;
        }
        iVar1 = f_1a5a(4, param_1, param_2);
        if (iVar1 != 0) {
          return 4;
        }
        iVar1 = f_1a5a(5, param_1, param_2);
        if (iVar1 != 0) {
          return 5;
        }
        iVar1 = f_1a5a(6, param_1, param_2);
        if (iVar1 != 0) {
          return 6;
        }
        iVar1 = f_1a5a(7, param_1, param_2);
        if (iVar1 != 0) {
          return 7;
        }
        uVar2 = 8;
      }
      else {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// 1000:1B80 FUN_1000_1b80
static u16 f_1b80(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x1B80);
  i16 iVar1;
  
  if ((param_2 < 2) || (param_3 < 2)) {
    if (*PS8(param_1 + 0x8b36) == '\0') {
      iVar1 = f_1a5a(3, param_2, param_3);
      if (iVar1 != 0) {
        return 100;
      }
      iVar1 = f_1a5a(5, param_2, param_3);
      if (iVar1 != 0) {
        return 0x46;
      }
    }
    else if ((*PS8(param_1 + 0x8b36) == '\x01') &&
            (iVar1 = f_af30((u16)param_1), iVar1 == 0)) {
      iVar1 = f_1a5a(9, param_2, param_3);
      if (iVar1 != 0) {
        return 0x50;
      }
      iVar1 = f_1a5a(10, param_2, param_3);
      if (iVar1 != 0) {
        return 0x32;
      }
    }
  }
  return 0;
}

// 1000:1C36 FUN_1000_1c36  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u8 f_1c36(u8 param_1)

{
  FN(0x1C36);
  return param_1 + 4U & 7;
}

// 1000:1C46 FUN_1000_1c46  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u8 f_1c46(u8 param_1)

{
  FN(0x1C46);
  return param_1 - 2U & 7;
}

// 1000:1C56 FUN_1000_1c56  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u8 f_1c56(u8 param_1)

{
  FN(0x1C56);
  return param_1 + 2U & 7;
}

// 1000:1C66 FUN_1000_1c66
static u16 f_1c66(u8 param_1)

{
  FN(0x1C66);
  i8a *pcVar1;
  
  if (*PS16((u16)param_1 * 2 + 0x90) == 0) {
    if (*PS8(param_1 + 0xae45) == '\0') {
      return 1;
    }
    pcVar1 = PS8(param_1 + 0xae45);
    *pcVar1 = *pcVar1 + -1;
    *P16((u16)param_1 * 2 + 0x90) = 0x3c;
  }
  return 0;
}

// 1000:1CA2 FUN_1000_1ca2
static u16 f_1ca2(u8 param_1)

{
  FN(0x1CA2);
  i16 iVar1;
  
  if ((*PS8(param_1 + 0x9d90) != '\0') || (*PS8(0x353a) != '\x01')) {
    iVar1 = f_19a0(*P8(param_1 + 0x7353));
    if (iVar1 == 3) {
      iVar1 = f_7130();
      if (iVar1 == 0) {
        f_1ce4(param_1);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:1CE4 FUN_1000_1ce4
static u16 f_1ce4(u8 param_1)

{
  FN(0x1CE4);
  u8 uVar1;
  
  f_b84c(param_1, 3);
  *P16((u16)param_1 * 2 + 0x74) = 0x28;
  f_aa12((u16)param_1, 3);
  uVar1 = f_19f8(*P8(param_1 + 0x7353));
  *P8(param_1 + 0xae45) = uVar1;
  *P8(param_1 + 0xae3e) = 0;
  return 0 /* AX? */;
}

// 1000:1D36 FUN_1000_1d36
static u16 f_1d36(u8 param_1)

{
  FN(0x1D36);
  u8 uVar1;
  u16 uVar2;
  i16 iVar3;
  
  uVar1 = f_8986((u16)param_1, 0);
  *P8(param_1 + 0x7d80) = uVar1;
  uVar2 = (u16)param_1;
  *P8(uVar2 + 0x7596) = *P8(uVar2 + 0x7d80);
  iVar3 = f_a716(uVar2, 0);
  if (iVar3 == 0) {
    if (*PS8(param_1 + 0x9d90) == '\0') {
      *P8(param_1 + 0xae3e) = 0;
      return 0 /* AX? */;
    }
    f_ae62(param_1);
  }
  else {
    f_a440(param_1);
  }
  return 0 /* AX? */;
}

// 1000:1D9C FUN_1000_1d9c
static u16 f_1d9c(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x1D9C);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = (u16)param_1;
  if (((*PS8(uVar1 + 0x8b36) == '\x01') &&
      (((*PS8(uVar1 + 0x8134) == '\x02' || (*PS8(uVar1 + 0x8134) == '\x03')) &&
       (uVar1 = f_8986((u16)param_1, 0), *P8(param_1 + 0x7596) == uVar1)))) &&
     (((*PS8(param_1 + 0x7776) == *PS8(0x7776) &&
       (iVar2 = f_1766(*P8(param_1 + 0x79ee), *P8(0x79ee)), iVar2 < 7))
      || ((*PS8(param_1 + 0x79ee) == *PS8(0x79ee) &&
          (iVar2 = f_1766(*P8(param_1 + 0x7776), *P8(0x7776)), iVar2 < 7
          )))))) {
    if (*PS8(0x353b) == '\0') {
      *P8(0x353b) = 1;
    }
  }
  else {
    iVar2 = f_1766(*P8(param_1 + 0x7776), param_2);
    if ((2 < iVar2) || (iVar2 = f_1766(*P8(param_1 + 0x79ee), param_3), 2 < iVar2)
       ) {
      return 0;
    }
  }
  return 1;
}

// 1000:1E7C FUN_1000_1e7c  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_1e7c(u8 param_1,u16 param_2)

{
  FN(0x1E7C);
  u16 uVar1;
  i16 iVar2;
  i8 local_a;
  u8 local_8;
  
  local_a = '\0';
  local_8 = 0;
  do {
    if ((((local_8 != param_1) && (uVar1 = (u16)local_8, *PS8(uVar1 + 0xae6b) != '\0')) &&
        (*PS8(uVar1 + 0x734c) != '\0')) &&
       ((iVar2 = f_1d9c(uVar1, (i8)((u32)param_2 % 0x4d), (i8)((u32)param_2 / 0x4d)),
        iVar2 != 0 && (iVar2 = f_1f1e(param_1, local_8), iVar2 == 0)))) {
      local_a = '\x01';
      f_1fce(param_1, local_8);
    }
    local_8 = local_8 + 1;
  } while (local_a == '\0' && local_8 < 7);
  return local_a;
}

// 1000:1F1E FUN_1000_1f1e  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_1f1e(u8 param_1,u8 param_2)

{
  FN(0x1F1E);
  i16 iVar1;
  u8 local_4;
  
  f_1fb0();
  local_4 = '\0';
  iVar1 = f_7108(param_1);
  if ((iVar1 != 0) && (param_2 != 0)) {
    local_4 = '\x01';
  }
  iVar1 = f_7108(param_2);
  if ((iVar1 != 0) && (param_1 != 0)) {
    local_4 = '\x01';
  }
  iVar1 = f_7158(param_1);
  if ((iVar1 != 0) && (*PS8(param_2 + 0x9e24) != '\0')) {
    local_4 = '\x01';
  }
  iVar1 = f_7158(param_2);
  if ((iVar1 != 0) && (*PS8(param_1 + 0x9e24) != '\0')) {
    local_4 = '\x01';
  }
  if (local_4 != '\0') {
    f_1fb2();
  }
  return local_4;
}

// 1000:1FB0 FUN_1000_1fb0
static u16 f_1fb0(void)

{
  FN(0x1FB0);
  return 0 /* AX? */;
}

// 1000:1FB2 FUN_1000_1fb2
static u16 f_1fb2(void)

{
  FN(0x1FB2);
  return 0 /* AX? */;
}

// 1000:1FB4 FUN_1000_1fb4
static u16 f_1fb4(u8 param_1)

{
  FN(0x1FB4);
  
  if (*PS8(param_1 + 0x734c) == '\x03') {
    return 1;
  }
  return 0;
}

// 1000:1FCC FUN_1000_1fcc
static u16 f_1fcc(void)

{
  FN(0x1FCC);
  return 0 /* AX? */;
}

// 1000:1FCE FUN_1000_1fce
static u16 f_1fce(u8 param_1,u8 param_2)

{
  FN(0x1FCE);
  i16 iVar1;
  u16 uVar2;
  u16 uVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = f_7108(param_1);
    if ((iVar1 != 0) && (param_2 != 0)) {
      f_1ce4(param_2);
    }
    iVar1 = f_7108(param_2);
    if ((iVar1 != 0) && (param_1 != 0)) {
      f_1ce4(param_1);
    }
    iVar1 = f_1fb4(param_1);
    if ((iVar1 != 0) || (iVar1 = f_1fb4(param_2), iVar1 != 0)) {
      f_1fcc();
    }
    if (*PS8(param_1 + 0x734c) == '\x03') {
      uVar2 = (u16)param_2;
      if (*PS8(uVar2 + 0x734c) == '\x03') {
        return 0 /* AX? */;
      }
    }
    else {
      if (*PS8(param_2 + 0x734c) != '\x03') {
        if ((*PS8(param_1 + 0x734c) == '\x01') && (*PS8(param_2 + 0x734c) == '\x02')) {
          f_aa12((u16)param_2, 1);
        }
        if (*PS8(param_2 + 0x734c) != '\x01') {
          return 0 /* AX? */;
        }
        uVar2 = (u16)param_1;
        if (*PS8(uVar2 + 0x734c) != '\x02') {
          return 0 /* AX? */;
        }
        uVar3 = 1;
        goto LAB_1000_20e8;
      }
      uVar2 = (u16)param_1;
    }
    return f_1ce4(uVar2);
  }
  if (param_1 != 0) {
    param_2 = param_1;
  }
  uVar3 = 2;
  uVar2 = (u16)param_2;
LAB_1000_20e8:
  return f_aa12(uVar2, uVar3);
}

// 1000:20F2 FUN_1000_20f2
static u8 f_20f2(u8 param_1,u8 param_2)

{
  FN(0x20F2);
  i16 iVar1;
  
  iVar1 = f_21de(param_1, param_2);
  return *P8((param_2 >> 1 & 1) + (iVar1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6103);
}

// 1000:212E FUN_1000_212e
static u16 f_212e(u8 param_1,u8 param_2)

{
  FN(0x212E);
  i8 cVar1;
  
  cVar1 = f_20f2(param_1, param_2);
  if ((cVar1 != '\0') && (cVar1 != '\x03')) {
    return 0;
  }
  return 1;
}

// 1000:215C FUN_1000_215c
static u16 f_215c(i8 param_1,u8 param_2,i8 param_3)

{
  FN(0x215C);
  i16 iVar1;
  u8 local_4;
  
  if (((param_1 == ' ') && (param_2 == 0)) && (param_3 != '\0')) {
    f_21dc();
  }
  if (param_3 == '\x04') {
    iVar1 = f_170e(100);
    if (iVar1 < 0x32) {
      local_4 = '\x02';
    }
    else {
      local_4 = '\x01';
    }
  }
  else {
    local_4 = param_3;
  }
  iVar1 = f_21de(param_1, param_2);
  *PS8((param_2 >> 1 & 1) + (iVar1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6103) = local_4;
  return 0 /* AX? */;
}

// 1000:21DC FUN_1000_21dc
static u16 f_21dc(void)

{
  FN(0x21DC);
  return 0 /* AX? */;
}

// 1000:21DE FUN_1000_21de  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_21de(i8 param_1,u8 param_2)

{
  FN(0x21DE);
  i8 local_4;
  
  if (param_2 != 0) {
    if ((param_2 == 2) || (param_2 == 4)) {
      param_1 = *PS8((param_2 >> 1) + 0x4104) + param_1;
    }
    else if (param_2 != 6) {
      return local_4;
    }
  }
  return param_1;
}

// 1000:221C FUN_1000_221c
static u8 f_221c(u8 param_1)

{
  FN(0x221C);
  
  return *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6104);
}

// 1000:223E FUN_1000_223e
static u16 f_223e(u8 param_1,u8 param_2)

{
  FN(0x223E);
  i16 iVar1;
  
  iVar1 = f_221c(param_1);
  if (iVar1 == 0) {
    *PS8(0x23b0) = *PS8(0x23b0) + -1;
  }
  *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6104) = param_2;
  return 0 /* AX? */;
}

// 1000:2276 FUN_1000_2276
static u8 f_2276(u8 param_1)

{
  FN(0x2276);
  
  return *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6101);
}

// 1000:2298 FUN_1000_2298
static u16 f_2298(u8 param_1,u8 param_2)

{
  FN(0x2298);
  
  *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6101) = param_2;
  return 0 /* AX? */;
}

// 1000:22BC FUN_1000_22bc
static u16 f_22bc(u8 param_1)

{
  FN(0x22BC);
  i16 iVar1;
  
  iVar1 = f_2276(param_1);
  if (iVar1 != 0) {
    iVar1 = f_2a6e(param_1);
    if (iVar1 == 0) {
      iVar1 = f_3d56(param_1);
      if (iVar1 == 0) {
        iVar1 = f_170e(4);
        if (iVar1 == 0) {
          return f_231a(param_1);
        }
      }
    }
  }
  return f_2346(param_1);
}

// 1000:231A FUN_1000_231a
static u16 f_231a(i16 param_1)

{
  FN(0x231A);
  i8 cVar1;
  
  cVar1 = f_170e(0xd);
  *PS8((param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x60ff) = cVar1 + '\x01';
  return 0 /* AX? */;
}

// 1000:2346 FUN_1000_2346
static u16 f_2346(i16 param_1)

{
  FN(0x2346);
  
  *P8((param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x60ff) = 0;
  return 0 /* AX? */;
}

// 1000:2366 FUN_1000_2366
static u8 f_2366(u8 param_1)

{
  FN(0x2366);
  
  return *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x60ff);
}

// 1000:2388 FUN_1000_2388
static u16 f_2388(u8 param_1,u8 param_2)

{
  FN(0x2388);
  
  *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6100) = param_2;
  return 0 /* AX? */;
}

// 1000:23AC FUN_1000_23ac
static u8 f_23ac(u8 param_1)

{
  FN(0x23AC);
  
  return *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x6100);
}

// 1000:23CE FUN_1000_23ce
static u16 f_23ce(u8 param_1)

{
  FN(0x23CE);
  
  return *P16((u16)param_1 * 2 + 0x23c8);
}

// 1000:23DE FUN_1000_23de
static u16 f_23de(u8 param_1)

{
  FN(0x23DE);
  
  return *P16((u16)param_1 * 2 + 0x23b0);
}

// 1000:23EE FUN_1000_23ee
static u16 f_23ee(u8 param_1)

{
  FN(0x23EE);
  
  return *P16((u16)param_1 * 2 + 0x23e0);
}

// 1000:23FE FUN_1000_23fe
static u16 f_23fe(u8 param_1)

{
  FN(0x23FE);
  
  *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x60fe) = 0;
  return 0 /* AX? */;
}

// 1000:2420 FUN_1000_2420
static u16 f_2420(u8 param_1)

{
  FN(0x2420);
  i8a *pcVar1;
  
  pcVar1 = PS8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x60fe);
  *pcVar1 = *pcVar1 + '\x01';
  return 0 /* AX? */;
}

// 1000:2440 FUN_1000_2440
static u8 f_2440(u8 param_1)

{
  FN(0x2440);
  
  return *P8(((u16)param_1 + (u16)*P8(0x3558) * 0xb4) * 7 + -0x60fe);
}

// 1000:2462 FUN_1000_2462
static u16 f_2462(u8 param_1)

{
  FN(0x2462);
  i16 iVar1;
  
  *P8(0x3557) = param_1;
  f_3f42();
  f_25b8(0);
  if (1 < *P8(0x3557)) {
    f_4124(0);
    f_25b8(1);
    f_41a6(1);
  }
  if (2 < *P8(0x3557)) {
    f_4124(1);
    f_25b8(2);
    f_41a6(2);
    f_2646();
  }
  f_6c5c();
  iVar1 = f_7122();
  if (iVar1 != 0) {
    iVar1 = f_0676();
    if (iVar1 != 0) {
      f_6de8();
    }
  }
  if (1 < *P8(0x3557)) {
    *P8(0x3558) = 0;
    f_432a();
    *P8(0x3558) = 1;
    f_432a();
  }
  if (2 < *P8(0x3557)) {
    *P8(0x3558) = 2;
    f_432a();
  }
  return 0 /* AX? */;
}

// 1000:2504 FUN_1000_2504
static u16 f_2504(void)

{
  FN(0x2504);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P8(local_4 + 0x33ba) = 0;
    *P8(0x33c9) = 0xe;
    local_4 = local_4 + 1;
  } while (local_4 < 0xe);
  return 0 /* AX? */;
}

// 1000:252A FUN_1000_252a
static u16 f_252a(void)

{
  FN(0x252A);
  return f_170e(0xe);
}

// 1000:2540 FUN_1000_2540
static u16 f_2540(void)

{
  FN(0x2540);
  u8 local_6;
  u8 local_4;
  
  for (local_4 = 0; local_4 < 0x9a; local_4 = local_4 + 1) {
    f_223e(local_4, 0);
    f_2298(local_4, 0);
    f_2388(local_4, 0);
    f_23fe(local_4);
    for (local_6 = 0; local_6 < 4; local_6 = local_6 + 2) {
      f_215c(local_4, local_6, 0);
    }
  }
  return 0 /* AX? */;
}

// 1000:25B8 FUN_1000_25b8
static u16 f_25b8(u8 param_1)

{
  FN(0x25B8);
  u8 uVar1;
  u8 uVar2;
  u16 uVar3;
  
  *P8(0x3558) = param_1;
  f_2540();
  uVar1 = f_252a();
  uVar2 = f_252a();
  *P8(0x3559) = uVar1;
  *P8(0x355a) = uVar2;
  uVar3 = f_170e(100);
  f_30c4(uVar1, 0, uVar3 & 1);
  uVar3 = f_170e(100);
  f_30c4(uVar2, 1, uVar3 & 1);
  return f_2622();
}

// 1000:2622 FUN_1000_2622
static u16 f_2622(void)

{
  FN(0x2622);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_22bc(local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 0x9a);
  return 0 /* AX? */;
}

// 1000:2646 FUN_1000_2646
static u16 f_2646(void)

{
  FN(0x2646);
  i16 iVar1;
  i16 iVar2;
  u8 uVar3;
  
  *P8(0x33cd) = 0;
  uVar3 = 0;
  iVar2 = 500;
  do {
    if (2 < *P8(0x33cd)) {
      return 0 /* AX? */;
    }
    uVar3 = f_170e(0x9a);
    iVar1 = f_2276(uVar3);
    if (iVar1 == 0) {
      *P8(*P8(0x33cd) + 0x33ca) = uVar3;
      *PS8(0x33cd) = *PS8(0x33cd) + '\x01';
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0 /* AX? */;
}

// 1000:2696 FUN_1000_2696
static u8 f_2696(i8 param_1)

{
  FN(0x2696);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_6 = 0;
  iVar1 = f_4e22();
  if ((iVar1 != 0) && (*PS8(0x3558) == '\x02')) {
    if (*PS8(0x33cd) != '\0') {
      local_4 = *P8(0x33cd);
      while (local_4 != 0) {
        local_4 = local_4 - 1;
        if (*PS8(local_4 + 0x33ca) == param_1) {
          local_6 = 1;
        }
      }
    }
    return local_6;
  }
  return 0;
}

// 1000:26E8 FUN_1000_26e8
static u16 f_26e8(void)

{
  FN(0x26E8);
  i8 cVar1;
  u8 uVar2;
  i16 iVar3;
  u8 local_c;
  u8 local_a;
  u8 local_8;
  u8 local_6;
  u8 local_4;
  
  cVar1 = *PS8(0x353a);
  if (cVar1 == '\x01') {
    local_4 = 1;
  }
  else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
    local_4 = 2;
  }
  if (*PS8(0x353a) != '\x01') {
    for (local_a = 0; local_a < 0x9a; local_a = local_a + 1) {
      for (local_c = 0; local_c < 8; local_c = local_c + 2) {
        f_215c(local_a, local_c, 0);
      }
    }
  }
  local_a = 0;
  do {
    f_215c(local_a, 0, local_4);
    f_215c(local_a + 0x8f, 4, local_4);
    local_a = local_a + 1;
  } while (local_a < 0xb);
  local_a = 0;
  do {
    f_215c(local_a, 6, local_4);
    f_215c(local_a + 10, 2, local_4);
    local_a = local_a + 0xb;
  } while (local_a < 0x9a);
  if ((*PS8(0xae6b) != '\0') && (*PS8(0x3558) == '\0')) {
    f_215c(*P8(0x9af7), 4, 2);
  }
  if (*PS8(0x353a) == '\x03') {
    for (local_6 = 1; local_6 < 0xd; local_6 = local_6 + 1) {
      for (local_8 = 1; local_8 < 10; local_8 = local_8 + 1) {
        uVar2 = f_c3a0(local_6, local_8);
        iVar3 = f_3334(uVar2);
        if (iVar3 == 0xd) {
          f_2840(uVar2);
        }
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:2840 FUN_1000_2840
static u16 f_2840(u8 param_1)

{
  FN(0x2840);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_215c(param_1, local_4, 1);
    f_215c((i16)*PS8((local_4 >> 1) + 0x4104) + (u16)param_1, local_4 + 4 & 7, 1);
    local_4 = local_4 + 2;
  } while (local_4 < 8);
  return 0 /* AX? */;
}

// 1000:2898 FUN_1000_2898
static u16 f_2898(void)

{
  FN(0x2898);
  u8 uVar1;
  i16 iVar2;
  u8 local_8;
  u8 local_4;
  
  for (local_4 = 0; local_4 < 0xe; local_4 = local_4 + 1) {
    for (local_8 = 0; local_8 < 0xb; local_8 = local_8 + 1) {
      uVar1 = f_c3a0(local_4, -(local_8 - 10));
      if ((*PS8(0x353a) != '\x01') || (iVar2 = f_7130(), iVar2 != 0)) {
        f_223e(uVar1, 1);
      }
      f_bf7c(4, uVar1);
      iVar2 = f_221c(uVar1);
      if (iVar2 != 0) {
        f_bf7c(2, uVar1);
      }
      iVar2 = f_7130();
      if ((((iVar2 != 0) && (iVar2 = f_2276(uVar1), iVar2 == 0)) &&
          (*PS8(0x353a) == '\x01')) &&
         ((iVar2 = f_2a6e(uVar1), iVar2 == 0 && (iVar2 = f_170e(3), iVar2 == 0)))) {
        f_2986(uVar1);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:2986 FUN_1000_2986
static u16 f_2986(u8 param_1)

{
  FN(0x2986);
  u8 bVar1;
  i16 iVar2;
  i16 iVar3;
  
  iVar2 = f_c380(param_1);
  iVar2 = iVar2 * 0x1c + 0xe;
  iVar3 = f_c390(param_1);
  iVar3 = iVar3 * 0x1c + 0xe;
  bVar1 = f_170e(4);
  f_8d3c(4, bVar1 + 0x173, iVar3, iVar2);
  f_8d3c(2, bVar1 + 0x173, iVar3, iVar2);
  return f_8d3c(0, bVar1 + 0x173, iVar3, iVar2);
  return 0 /* AX? */;
}

// 1000:2A10 FUN_1000_2a10
static u16 f_2a10(u8 param_1)

{
  FN(0x2A10);
  i16 iVar1;
  
  if (*PS8(0x353a) == '\x02') {
    iVar1 = f_3334(param_1);
    if (iVar1 == 6) {
      return 1;
    }
    iVar1 = f_3334(param_1);
    if (iVar1 == 7) {
      return 1;
    }
    iVar1 = f_3334(param_1);
    if (iVar1 < 3) {
      return 1;
    }
  }
  if ((*PS8(0x353a) == '\x03') && (iVar1 = f_3334(param_1), iVar1 == 0xd)) {
    return 1;
  }
  return 0;
}

// 1000:2A6E FUN_1000_2a6e  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_2a6e(u8 param_1)

{
  FN(0x2A6E);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_6 = '\0';
  local_4 = 0;
  do {
    iVar1 = f_20f2(param_1, local_4);
    if (iVar1 == 2) {
      local_6 = local_6 + '\x01';
    }
    local_4 = local_4 + 2;
  } while (local_4 < 8);
  return local_6;
}

// 1000:2AA8 FUN_1000_2aa8  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_2aa8(u8 param_1)

{
  FN(0x2AA8);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_6 = '\0';
  local_4 = 0;
  do {
    iVar1 = f_20f2(param_1, local_4);
    if (iVar1 != 0) {
      local_6 = local_6 + '\x01';
    }
    local_4 = local_4 + 2;
  } while (local_4 < 8);
  return local_6;
}

// 1000:2AE0 FUN_1000_2ae0
static u16 f_2ae0(u8 param_1,u8 param_2)

{
  FN(0x2AE0);
  i8 cVar1;
  i16 iVar2;
  
  if ((*PS8(0x353a) == '\x02') &&
     (iVar2 = f_2276((i16)*PS8((param_2 >> 1) + 0x4104) + (u16)param_1), iVar2 != 0)) {
    return 0;
  }
  cVar1 = f_20f2(param_1, param_2 & 6);
  if ((cVar1 != '\0') && (cVar1 != '\x03')) {
    return 0;
  }
  return 1;
}

// 1000:2B38 FUN_1000_2b38
static u16 f_2b38(u8 param_1)

{
  FN(0x2B38);
  u8 bVar1;
  u8 uVar2;
  u8 uVar3;
  i8 cVar4;
  u16 uVar5;
  i16 iVar6;
  i16 iVar7;
  u16 uVar8;
  u8 local_1a;
  u8 local_14;
  u8 local_12;
  u8 local_10;
  i8 local_e;
  u8 local_a;
  u8 local_8;
  u8 local_6;
  
  if (*PS8(0xae3d) == '\0') {
    *P8(0xae3d) = 1;
    local_e = '\0';
    local_10 = param_1;
    local_a = param_1;
    local_1a = f_c380(param_1);
    local_8 = f_c390(param_1);
    local_6 = f_c380(param_1);
    local_14 = f_c390(param_1);
    bVar1 = f_2276(param_1);
    if (bVar1 == 0) {
      f_b86c(0, param_1);
    }
    else {
      local_12 = 0;
      do {
        uVar5 = f_2276(local_12);
        if (uVar5 == bVar1) {
          local_e = local_e + '\x01';
          f_223e(local_12, 1);
          f_bf7c(4, local_12);
          local_10 = f_1756(local_12, local_10);
          local_a = f_1746(local_12, local_a);
          uVar2 = f_c380(local_12);
          uVar3 = f_c390(local_12);
          local_1a = f_1756(local_1a, uVar2);
          local_8 = f_1756(local_8, uVar3);
          local_6 = f_1746(local_6, uVar2);
          local_14 = f_1746(local_14, uVar3);
        }
        local_12 = local_12 + 1;
      } while (local_12 < 0x9a);
      cVar4 = f_170e(local_e);
      local_e = '\0';
      local_12 = local_10;
      do {
        uVar5 = f_2276(local_12);
        if (uVar5 == bVar1) {
          if (((cVar4 == local_e) && (iVar6 = f_23ac(local_12), iVar6 == 0)) &&
             (uVar5 = f_170e(100), uVar5 < (u16)*P8(0x355c) * 10 + 0x14)) {
            if ((local_12 != *P8(0xae64)) && (iVar6 = f_15e0(local_12), iVar6 == 0)) {
              iVar6 = f_2276(*P8(0xae64));
              iVar7 = f_2276(local_12);
              if (iVar7 != iVar6) {
                f_4fac(local_12);
              }
            }
            local_12 = local_a;
          }
          local_e = local_e + '\x01';
        }
        local_12 = local_12 + 1;
      } while ((u16)local_12 < local_a + 1);
      uVar8 = f_1746(0, (u16)local_8 * 0x1c + -8);
      *P16(0x8bec) = uVar8;
      uVar8 = f_1746(0, (u16)local_1a * 0x1c + -8);
      *P16(0x9aec) = uVar8;
      uVar8 = f_1756(0x13f, (u16)local_14 * 0x1c + 0x2c);
      *P16(0x8d22) = uVar8;
      uVar8 = f_1756(399, (u16)local_6 * 0x1c + 0x2c);
      *P16(0x9aee) = uVar8;
      *P8(0x355b) = 1;
    }
  }
  return f_4712();
}

// 1000:2DC6 FUN_1000_2dc6  FIX: param_2 is zero-extended (u8, not Ghidra's i8)
static u16 f_2dc6(u8 param_1,u8 param_2)

{
  FN(0x2DC6);
  i16 iVar1;
  u16 uVar2;
  u8 local_4;
  
  if (param_1 == 0) {
    iVar1 = f_221c(param_2);
    if (iVar1 == 0) {
      iVar1 = f_2276(param_2);
      if (iVar1 == 0) {
        f_223e(param_2, 1);
        f_bf7c(4, param_2);
        f_bf7c(2, param_2);
        f_bf7c(0, param_2);
      }
      else {
        f_2b38(param_2);
      }
    }
  }
  local_4 = 0;
  do {
    if (*PS8(local_4 + 0xae6b) != '\0') {
      iVar1 = f_b706((u16)local_4);
      if (((iVar1 != 0) && (local_4 != param_1)) && (*P8(local_4 + 0xae64) == param_2)) {
        u16 hi = f_1746(param_1, (u16)local_4);  // FIX: pushed before the other call (Ghidra lost it)
        uVar2 = f_1756(param_1, local_4);
        f_ba4c(uVar2, hi);
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  if (*PS8(0x39c4) != '\0') {
    f_39b4();
    *P8(0x39c4) = 0;
  }
  return 0 /* AX? */;
}

// 1000:2EB6 FUN_1000_2eb6
static u16 f_2eb6(u8 param_1,u8 param_2)

{
  FN(0x2EB6);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  if ((*PS8(0x353a) == '\x01') && (*PS8(0x3434) == '\0')) {
    for (local_4 = 0; uVar1 = (u16)local_4, uVar1 < *P16(0x75fc); local_4 = local_4 + 1) {
      if (*PS8(uVar1 + 0x9bb6) == *PS8(0x3558)) {
        uVar1 = f_8a34(*P16(uVar1 * 2 + 0x7796));
        if ((uVar1 == param_2) && (uVar1 = (u16)param_1, *PS8(uVar1 + 0x72d0) == '\0')) {
          *P8(uVar1 + 0x72d0) = 1;
          if (*PS8(uVar1 + 0x734c) == '\x01') {
            f_aa12(uVar1, 2);
          }
          iVar2 = f_6a82();
          if (iVar2 == 0) {
            f_c722(0, param_2);
          }
        }
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:2F42 FUN_1000_2f42
static u8 f_2f42(void)

{
  FN(0x2F42);
  u8 local_6;
  u8 local_4;
  
  local_6 = 0;
  local_4 = 1;
  do {
    if (*PS8(local_4 + 0x72d0) != '\0') {
      local_6 = 1;
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return local_6;
}

// 1000:2F72 FUN_1000_2f72
static u16 f_2f72(void)

{
  FN(0x2F72);
  u8 uVar1;
  u16 uVar2;
  
  uVar1 = f_5348();
  *P8(0x7795) = uVar1;
  uVar2 = f_2276(uVar1);
  *P16(0x9b76) = uVar2;
  return 0 /* AX? */;
}

// 1000:2F8E FUN_1000_2f8e
static u16 f_2f8e(u8 param_1)

{
  FN(0x2F8E);
  i8 cVar1;
  i16 iVar2;
  
  iVar2 = f_7942(param_1);
  if ((iVar2 != 0) &&
     ((*PS8(param_1 + 0xae64) == *PS8(0xae64) ||
      ((((iVar2 = f_7788(0, param_1), iVar2 != 0 &&
         ((i16)*PS8((*P8(param_1 + 0x7d80) >> 1) + 0x4104) +
          (u16)*P8(param_1 + 0xae64) == (u16)*P8(0xae64))) &&
        (cVar1 = f_20f2(*P8(param_1 + 0xae64), *P8(param_1 + 0x7d80) & 6),
        cVar1 != '\x02')) && (cVar1 != '\x01')))))) {
    return 1;
  }
  return 0;
}

// 1000:303A FUN_1000_303a
static bool f_303a(u8 param_1,u8 param_2)

{
  FN(0x303A);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = f_8a72(param_1);
  iVar2 = f_20f2(uVar1, param_2 & 6);  // FIX: pushed before the other call (Ghidra lost it)
  return iVar2 != 0;
}

// 1000:3064 FUN_1000_3064
static u16 f_3064(u8 param_1,u8 param_2)

{
  FN(0x3064);
  i16 iVar1;
  
  if ((param_2 & 1) == 0) {
    iVar1 = f_20f2(*P8(param_1 + 0xae64), param_2 & 6);
    if (iVar1 == 2) {
      return 1;
    }
  }
  return 0;
}

// 1000:30C4 FUN_1000_30c4
static u16 f_30c4(u8 param_1,i8 param_2,i8 param_3)

{
  FN(0x30C4);
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u8 bVar4;
  i16 iVar5;
  i16 iVar6;
  u16 uVar7;
  u8 local_18;
  i8 local_14;
  u8 local_c;
  u8 local_a;
  u8 local_8;
  u8 local_6;
  
  iVar5 = (u16)param_1 * 0x60;
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    for (local_18 = 0; local_18 < 0xb; local_18 = local_18 + 1) {
      if (param_3 == '\0') {
        local_a = local_18;
        bVar4 = local_18;
      }
      else {
        local_a = 10 - local_18;
        bVar4 = 0xb - local_18;
      }
      if (param_2 == '\0') {
        local_6 = local_c;
        local_8 = local_c;
      }
      else {
        local_8 = 6 - local_c;
        local_6 = 7 - local_c;
      }
      bVar1 = param_2 * '\a' + local_c;
      bVar2 = f_c3a0(bVar1, local_18);
      if ((local_c < 7) && (local_18 < 0xb)) {
        bVar3 = local_6;
        if (param_2 != '\0') {
          bVar3 = local_8;
        }
        local_14 = *PS8(iVar5 + (u16)bVar3 * 0xc + (u16)local_a + 0x23fa);
        if ((param_2 != '\0') && (local_14 != '\0')) {
          local_14 = local_14 + -0x80;
        }
        f_2298(bVar2, local_14);
      }
      if (local_18 < 0xb) {
        f_215c(bVar2, 0, *P8(iVar5 + (u16)local_6 * 0xc + (u16)local_a + 0x2e7a))
        ;
      }
      if (bVar1 < 0xe) {
        f_215c(bVar2, 6, *P8(iVar5 + (u16)local_8 * 0xc + (u16)bVar4 + 0x293a));
      }
      if ((((local_c == 0) && (param_2 != '\0')) &&
          (((iVar6 = f_2276(bVar2), iVar6 == 0 &&
            (iVar6 = f_2276(bVar2 - 0xb), iVar6 != 0)) ||
           ((iVar6 = f_2276(bVar2), iVar6 != 0 &&
            (iVar6 = f_2276(bVar2 - 0xb), iVar6 == 0)))))) &&
         ((iVar6 = f_23ac(bVar2 - 0xb), iVar6 < 0x17b &&
          (iVar6 = f_23ac(bVar2), iVar6 < 0x17b)))) {
        iVar6 = f_20f2(bVar2 - 1, 0);
        if (iVar6 == 1) {
          uVar7 = 2;
        }
        else {
          uVar7 = 1;
        }
        f_215c(bVar2, 0, uVar7);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:32C4 FUN_1000_32c4
static u16 f_32c4(u8 param_1)

{
  FN(0x32C4);
  
  return *P16((u16)param_1 * 2 + -0x7602);
}

// 1000:32D4 FUN_1000_32d4
static u16 f_32d4(u8 param_1,u16 param_2)

{
  FN(0x32D4);
  
  *P16((u16)param_1 * 2 + -0x7602) = param_2;
  return 0 /* AX? */;
}

// 1000:32E8 FUN_1000_32e8
static u16 f_32e8(u8 param_1,i16 param_2)

{
  FN(0x32E8);
  i16a *piVar1;
  
  piVar1 = PS16((u16)param_1 * 2 + -0x7602);
  *piVar1 = *piVar1 + param_2;
  return 0 /* AX? */;
}

// 1000:32FC FUN_1000_32fc
static u16 f_32fc(u8 param_1)

{
  FN(0x32FC);
  
  return *P16((u16)param_1 * 2 + -0x7412);
}

// 1000:330C FUN_1000_330c
static u16 f_330c(u8 param_1,u16 param_2)

{
  FN(0x330C);
  
  *P16((u16)param_1 * 2 + -0x7412) = param_2;
  return 0 /* AX? */;
}

// 1000:3320 FUN_1000_3320
static u16 f_3320(u8 param_1,i16 param_2)

{
  FN(0x3320);
  i16a *piVar1;
  
  piVar1 = PS16((u16)param_1 * 2 + -0x7412);
  *piVar1 = *piVar1 + param_2;
  return 0 /* AX? */;
}

// 1000:3334 FUN_1000_3334
static u8 f_3334(u8 param_1)

{
  FN(0x3334);
  
  return *P8(param_1 + 0x8b3e);
}

// 1000:3344 FUN_1000_3344
static u16 f_3344(u8 param_1,u8 param_2)

{
  FN(0x3344);
  
  *P8(param_1 + 0x8b3e) = param_2;
  return 0 /* AX? */;
}

// 1000:3356 FUN_1000_3356
static u8 f_3356(u8 param_1)

{
  FN(0x3356);
  
  return *P8(param_1 + 0x8d28);
}

// 1000:3366 FUN_1000_3366
static u16 f_3366(u8 param_1,u8 param_2)

{
  FN(0x3366);
  
  *P8(param_1 + 0x8d28) = param_2;
  return 0 /* AX? */;
}

// 1000:3378 FUN_1000_3378
static u16 f_3378(void)

{
  FN(0x3378);
  i8 cVar1;
  i8 cVar2;
  
  cVar1 = f_170e(4);
  cVar2 = f_170e(5);
  return f_c3a0(cVar1 + '\x02', cVar2 + '\x03');
  return 0 /* AX? */;
}

// 1000:33AA FUN_1000_33aa
static u16 f_33aa(void)

{
  FN(0x33AA);
  i8 cVar1;
  i8 cVar2;
  
  cVar1 = f_170e(4);
  cVar2 = f_170e(5);
  return f_c3a0(cVar1 + '\t', cVar2 + '\x03');
  return 0 /* AX? */;
}

// 1000:33DC FUN_1000_33dc
static u16 f_33dc(u8 param_1)

{
  FN(0x33DC);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_c45c(*P8(param_1 + 0x9b02), local_4, 0);
    local_4 = local_4 + 1;
  } while (local_4 < 0x9a);
  return 0 /* AX? */;
}

// 1000:340C FUN_1000_340c
static u16 f_340c(void)

{
  FN(0x340C);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_3344(local_4, 7);
    local_4 = local_4 + 1;
  } while (local_4 < 0x9a);
  return 0 /* AX? */;
}

// 1000:3434 FUN_1000_3434
static u16 f_3434(void)

{
  FN(0x3434);
  u8 uVar1;
  i16 iVar2;
  u8 local_8;
  u8 local_4;
  
  f_33dc(0);
  f_340c();
  *P8(0x9dd4) = 0;
  uVar1 = f_3378();
  f_c45c(*P8(0x9b02), uVar1, 1);
  f_3344(uVar1, 8);
  uVar1 = f_33aa();
  f_c45c(*P8(0x9b02), uVar1, 1);
  f_3344(uVar1, 8);
  *P16(0xaea8) = 1;
  do {
    f_3570();
  } while (*PS8(0x9dd4) == '\0');
  for (local_4 = 1; local_4 < 0xd; local_4 = local_4 + 1) {
    for (local_8 = 1; local_8 < 10; local_8 = local_8 + 1) {
      if (local_8 != 5) {
        uVar1 = f_c3a0(local_4, local_8);
        iVar2 = f_3334(uVar1);
        if (iVar2 == 7) {
          iVar2 = f_170e(0x10);
          if (iVar2 == 0) {
            f_3344(uVar1, 0xd);
            f_2298(uVar1, 0xd);
          }
        }
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:352A FUN_1000_352a
static u16 f_352a(void)

{
  FN(0x352A);
  u8 uVar1;
  u8 local_4;
  
  if (*PS8(0x3450) == '\x17') {
    local_4 = 0;
    do {
      uVar1 = f_c3a0(local_4, 5);
      f_3344(uVar1, 0xf);
      local_4 = local_4 + 1;
    } while (local_4 < 0xe);
  }
  return 0 /* AX? */;
}

// 1000:3570 FUN_1000_3570
static u16 f_3570(void)

{
  FN(0x3570);
  i8 cVar1;
  i16 iVar2;
  u16 uVar3;
  u8 bVar4;
  u8 bVar5;
  
  *P8(0x9dd4) = 1;
  bVar5 = 0;
  do {
    iVar2 = f_c43e(*P8(0x9b02), bVar5);
    if (iVar2 == *PS16(0xaea8)) {
      bVar4 = 0;
      do {
        iVar2 = f_212e(bVar5, bVar4);
        if (iVar2 != 0) {
          uVar3 = f_3334(bVar5);
          iVar2 = f_363c(uVar3, bVar4);  // FIX: pushed before the other call (Ghidra lost it)
          if (iVar2 != 0) {
            cVar1 = *PS8((bVar4 >> 1) + 0x4104) + bVar5;
            iVar2 = f_c43e(*P8(0x9b02), cVar1);
            if (iVar2 == 0) {
              *P8(0x9dd4) = 0;
              f_c45c(*P8(0x9b02), cVar1, *PS16(0xaea8) + 1);
              f_365a(cVar1, bVar5, bVar4);
            }
          }
        }
        bVar4 = bVar4 + 2;
      } while (bVar4 < 8);
    }
    bVar5 = bVar5 + 1;
  } while (bVar5 < 0x9a);
  *PS16(0xaea8) = *PS16(0xaea8) + 1;
  return 0 /* AX? */;
}

// 1000:363C FUN_1000_363c
static u16 f_363c(u8 param_1,u8 param_2)

{
  FN(0x363C);
  
  return *P16((u16)param_1 * 2 + 0x33ce) & 1 << (param_2 >> 1 & 0x1f);
}

// 1000:365A FUN_1000_365a
static u16 f_365a(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x365A);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_3334(param_2);
  if (iVar1 < 3) {
    uVar2 = f_36c8(param_3);
  }
  else if ((param_3 & 2) == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  return f_3344(param_1, uVar2);
}

// 1000:369C FUN_1000_369c  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_369c(void)

{
  FN(0x369C);
  u8 bVar1;
  u8 local_4;
  
  bVar1 = f_170e(0x10);
  if (bVar1 < 9) {
    local_4 = '\0';
  }
  else {
    local_4 = bVar1 - 9;
  }
  return local_4;
}

// 1000:36C8 FUN_1000_36c8
static u16 f_36c8(u8 param_1)

{
  FN(0x36C8);
  i16 iVar1;
  
  iVar1 = f_369c();
  return *P16((u16)(param_1 >> 1) * 0xe + iVar1 * 2 + 0x33ea);
}

// 1000:36EA FUN_1000_36ea
static u16 f_36ea(void)

{
  FN(0x36EA);
  u16 uVar1;
  i16 iVar2;
  u8 local_8;
  
  for (local_8 = 0; local_8 < 0x9a; local_8 = local_8 + 1) {
    if (((*PS8(0x353a) == '\x03') && (iVar2 = f_3334(local_8), iVar2 == 7)) ||
       (*PS8(0x353a) == '\x02')) {
      uVar1 = 4;
    }
    else {
      uVar1 = 1;
    }
    f_32d4(local_8, uVar1);
  }
  return 0 /* AX? */;
}

// 1000:3740 FUN_1000_3740
static u16 f_3740(u8 param_1,u8 param_2)

{
  FN(0x3740);
  u8 bVar1;
  i8 cVar2;
  u16 uVar3;
  i16 iVar4;
  
  if ((param_2 != 4) || (bVar1 = f_c380(param_1), bVar1 < 0xd)) {
    uVar3 = f_20f2(param_1, param_2);
    cVar2 = (i8)uVar3;
    if (*PS8(0x353a) == '\x01') {
      iVar4 = f_7122();
      if ((((iVar4 == 0) || (iVar4 = f_0676(), iVar4 == 0)) ||
          (iVar4 = f_5478((i16)*PS8((param_2 >> 1) + 0x4104) + (u16)param_1),
          iVar4 == 0)) && (cVar2 != '\x01')) {
        return 1;
      }
    }
    else {
      if (*PS8(0x353a) != '\x02') {
        if (*PS8(0x353a) == '\x03') {
          iVar4 = f_3334((i16)*PS8((param_2 >> 1) + 0x4104) + (u16)param_1);
          if (iVar4 == 0xd) {
            return 0;
          }
          uVar3 = (u16)(cVar2 == '\0');
        }
        return uVar3;
      }
      if (cVar2 == '\0') {
        cVar2 = f_3334((i16)*PS8((param_2 >> 1) + 0x4104) + (u16)param_1);
        if (cVar2 == '\b') {
          return 1;
        }
        if (cVar2 == '\x05') {
          return 1;
        }
        if (cVar2 == '\x03') {
          return 1;
        }
        if (cVar2 == '\x04') {
          return 1;
        }
      }
    }
  }
  return 0;
}

// 1000:3830 FUN_1000_3830
static u16 f_3830(void)

{
  FN(0x3830);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_3366(local_4, 0);
    local_4 = local_4 + 1;
  } while (local_4 < 0x9a);
  return 0 /* AX? */;
}

// 1000:3856 FUN_1000_3856
static u16 f_3856(void)

{
  FN(0x3856);
  i16 iVar1;
  u16 uVar2;
  u8 local_6;
  u8 local_4;
  
  f_3830();
  local_6 = 0;
  do {
    if (7 < local_6) {
      return 0 /* AX? */;
    }
    local_4 = *PS8(0xae64);
LAB_1000_3896:
    iVar1 = f_2ae0(local_4, local_6);
    if (iVar1 != 0) {
      local_4 = local_4 + *PS8((local_6 >> 1) + 0x4104);
      if (*PS8(0x353a) == '\x03') break;
      if (local_6 == *P8(0x7596)) {
        uVar2 = 2;
      }
      else {
        uVar2 = 1;
      }
      goto LAB_1000_3877;
    }
    local_6 = local_6 + 2;
  } while( true );
  if (local_6 == *P8(0x7596)) {
    uVar2 = 0;
LAB_1000_3877:
    f_3366(local_4, uVar2);
  }
  goto LAB_1000_3896;
  return 0 /* AX? */;
}

// 1000:38D0 FUN_1000_38d0
static u8 f_38d0(u8 param_1)

{
  FN(0x38D0);
  i16 iVar1;
  
  iVar1 = f_38ea(param_1);
  return *P8(iVar1 + 0x3422);
}

// 1000:38EA FUN_1000_38ea
static u8 f_38ea(u8 param_1)

{
  FN(0x38EA);
  
  return *P8(param_1 + 0x9af0);
}

// 1000:38FA FUN_1000_38fa
static u8 f_38fa(u8 param_1)

{
  FN(0x38FA);
  
  return *P8(param_1 + 0x772a);
}

// 1000:390A FUN_1000_390a
static u16 f_390a(u8 param_1)

{
  FN(0x390A);
  
  return *P16((u16)param_1 * 2 + 0x7758);
}

// 1000:391A FUN_1000_391a
static u16 f_391a(u8 param_1)

{
  FN(0x391A);
  
  return *P16((u16)param_1 * 2 + -0x646a);
}

// 1000:392A FUN_1000_392a
static u16 f_392a(u8 param_1)

{
  FN(0x392A);
  
  return *P16((u16)param_1 * 2 + -0x645c);
}

// 1000:393A FUN_1000_393a
static u16 f_393a(u8 param_1,u8 param_2)

{
  FN(0x393A);
  
  *P8(param_1 + 0x9af0) = param_2;
  return 0 /* AX? */;
}

// 1000:394C FUN_1000_394c
static u16 f_394c(u8 param_1,u8 param_2)

{
  FN(0x394C);
  
  *P8(param_1 + 0x772a) = param_2;
  return 0 /* AX? */;
}

// 1000:395E FUN_1000_395e
static u16 f_395e(u8 param_1,u16 param_2)

{
  FN(0x395E);
  
  *P16((u16)param_1 * 2 + 0x7758) = param_2;
  return 0 /* AX? */;
}

// 1000:3972 FUN_1000_3972
static u16 f_3972(u8 param_1,u16 param_2)

{
  FN(0x3972);
  
  *P16((u16)param_1 * 2 + -0x646a) = param_2;
  return 0 /* AX? */;
}

// 1000:3986 FUN_1000_3986
static u16 f_3986(u8 param_1,u16 param_2)

{
  FN(0x3986);
  
  *P16((u16)param_1 * 2 + -0x645c) = param_2;
  return 0 /* AX? */;
}

// 1000:399A FUN_1000_399a
static u8 f_399a(u8 param_1)

{
  FN(0x399A);
  i16 iVar1;
  
  iVar1 = f_38ea(param_1);
  return *P8(iVar1 + 0x3422);
}

// 1000:39B4 FUN_1000_39b4
static u16 f_39b4(void)

{
  FN(0x39B4);
  
  if (*PS8(0x3432) != '\0') {
    f_902e(4, 0x80, *PS16(0x50) + 0x5a, 0x40, 0x1c, 2);
  }
  f_a3ea(2);
  f_8c2a(2);
  f_bd96(2);
  f_6714(2);
  f_a1fa(2);
  if (*PS8(0x3432) != '\0') {
    f_902e(2, 0x80, *PS16(0x50) + 0x5a, 0x40, 0x1c, 0);
    *P8(0x3432) = 0;
  }
  f_8be6(2, 0);
  f_673a(2, 0);
  return f_8ccc(2, 0);
}

// 1000:3A70 FUN_1000_3a70
static u16 f_3a70(void)

{
  FN(0x3A70);
  
  if (*PS16(0x3428) == 0) {
    f_39b4();
    *P16(0x3428) = 0;
    return 0 /* AX? */;
  }
  *PS16(0x3428) = *PS16(0x3428) + -1;
  return 0 /* AX? */;
}

// 1000:3A88 FUN_1000_3a88
static u16 f_3a88(void)

{
  FN(0x3A88);
  
  return *P16(0x3428);
}

// 1000:3A8C FUN_1000_3a8c
static bool f_3a8c(void)

{
  FN(0x3A8C);
  
  return *PS16(0x3428) == 0;
}

// 1000:3AA4 FUN_1000_3aa4
static u16 f_3aa4(void)

{
  FN(0x3AA4);
  f_3b0a(0);
  return f_3ad6();
}

// 1000:3AB2 FUN_1000_3ab2
static u16 f_3ab2(void)

{
  FN(0x3AB2);
  u8 local_4;
  
  local_4 = 1;
  do {
    f_3b1a(local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:3AD6 FUN_1000_3ad6
static u16 f_3ad6(void)

{
  FN(0x3AD6);
  u8 local_4;
  
  local_4 = 1;
  do {
    f_3b0a(local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:3AFA FUN_1000_3afa
static u8 f_3afa(u8 param_1)

{
  FN(0x3AFA);
  
  return *P8(param_1 + 0x735d);
}

// 1000:3B0A FUN_1000_3b0a
static u16 f_3b0a(u8 param_1)

{
  FN(0x3B0A);
  
  *P8(param_1 + 0x735d) = 1;
  return 0 /* AX? */;
}

// 1000:3B1A FUN_1000_3b1a
static u16 f_3b1a(u8 param_1)

{
  FN(0x3B1A);
  
  *P8(param_1 + 0x735d) = 0;
  return 0 /* AX? */;
}

// 1000:3B28 FUN_1000_3b28
static u16 f_3b28(void)

{
  FN(0x3B28);
  
  *P8(0x342b) = 2;
  return 0 /* AX? */;
}

// 1000:3B2E FUN_1000_3b2e
static u16 f_3b2e(i8 param_1)

{
  FN(0x3B2E);
  u8 local_4;
  
  for (local_4 = param_1; (*PS8(0xae3c) != '\0' && (local_4 != '\0')); local_4 = local_4 + -1) {
    *PS8(0xae3c) = *PS8(0xae3c) + -1;
  }
  return 0 /* AX? */;
}

// 1000:3B7C FUN_1000_3b7c
static u16 f_3b7c(u8 param_1)

{
  FN(0x3B7C);
  
  if (*PS8(0x342b) == '\0') {
    *P8(0x8b32) = 5;
  }
  else {
    f_3b2e(param_1);
    if (*PS8(0xae3c) == '\0') {
      *P8(0xae3c) = 0x3c;
      *PS16(0xae62) = *PS16(0xae62) + -1;
      if (*PS8(0x342c) != '\0') {
        *PS8(0x342b) = *PS8(0x342b) + -1;
        return 0 /* AX? */;
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:3BB8 FUN_1000_3bb8
static u16 f_3bb8(void)

{
  FN(0x3BB8);
  u8 local_6;
  u8 local_4;
  
  *PS16(0x342e) = *PS16(0x342e) + 1;
  local_4 = (i8)*P16(0x53);
  local_6 = local_4 - *PS8(0x7594);
  *P16(0x7594) = *P16(0x53);
  f_3b7c(local_6);
  for (; local_6 != '\0'; local_6 = local_6 + -1) {
    *PS16(0x3430) = *PS16(0x3430) + 1;
    f_07c2();
  }
  return 0 /* AX? */;
}

// 1000:3BFA FUN_1000_3bfa
static u16 f_3bfa(void)

{
  FN(0x3BFA);
  return f_07e8();
}

// 1000:3BFE FUN_1000_3bfe
static u16 f_3bfe(void)

{
  FN(0x3BFE);
  bool bVar1;
  i16 iVar2;
  i16 iVar3;
  u16 uVar4;
  
  uVar4 = 0x1000;
  *P8(0x57) = 0;
  bVar1 = true;
  f_08c4(0);
  f_8d3c(2, 0x1c4, 0x80, *PS16(0x50) + 0x5a);
  f_902e(2, 0x80, *PS16(0x50) + 0x5a, 0x40, 0x1c, 0);
  *P8(0x3432) = 1;
  while (bVar1) {
    do {
      iVar2 = DRV();
      uVar4 = 0x20ba;
    } while (iVar2 != 0);
    iVar2 = DRV();
    while( true ) {
      uVar4 = 0x20ba;
      iVar3 = DRV();
      if (iVar3 != 0) break;
      DRV();
    }
    if (iVar2 == 0x3920) {
      bVar1 = false;
    }
  }
  f_39b4();
  f_08c4(0x52);
  *P8(0x57) = 1;
  return 0 /* AX? */;
}

// 1000:3CA8 FUN_1000_3ca8
static u16 f_3ca8(void)

{
  FN(0x3CA8);
  i16 iVar1;
  
  *(bool *)0x3434 = *PS8(0x353a) != '\x01';
  iVar1 = f_7130();
  if ((iVar1 != 0) || (*PS8(0x3450) == '\x05')) {
    *P8(0x3434) = 1;
  }
  return 0 /* AX? */;
}

// 1000:3CCE FUN_1000_3cce
static u16 f_3cce(void)

{
  FN(0x3CCE);
  i16 iVar1;
  
  if (*PS8(0x3434) == '\0') {
    *P8(0x3434) = 1;
    iVar1 = f_221c(*P8(0xae06));
    if (iVar1 != 0) {
      f_6fe0();
    }
    f_08c4(0x24);
    if (*PS8(0x44) == '\0') {
      f_081a(0 /* ARGS? */);
      *P8(0x3435) = 1;
      *P16(0xe4) = 0x1e;
      return 0 /* AX? */;
    }
    f_d6cc(4);
  }
  return 0 /* AX? */;
}

// 1000:3D1A FUN_1000_3d1a
static u16 f_3d1a(void)

{
  FN(0x3D1A);
  u16 uVar1;
  u8 local_4;
  
  f_3cce();
  local_4 = 1;
  do {
    uVar1 = (u16)local_4;
    if ((*PS8(uVar1 + 0xae6b) != '\0') && (*PS8(uVar1 + 0x734c) == '\x01')) {
      f_aa12(uVar1, 2);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:3D56 FUN_1000_3d56
static u16 f_3d56(u8 param_1)

{
  FN(0x3D56);
  
  if ((*P16((u16)*P8(0x3558) * 2 + 0x3544) != (u16)param_1) &&
     (*P16((u16)*P8(0x3558) * 2 + 0x354a) != (u16)param_1)) {
    return 0;
  }
  return 1;
}

// 1000:3D90 FUN_1000_3d90
static u16 f_3d90(void)

{
  FN(0x3D90);
  
  if (*PS8(0x3558) == '\0') {
    return (u16)*P8(0x9af7);
  }
  return *P16((u16)*P8(0x3558) * 2 + 0x354a);
}

// 1000:3DAC FUN_1000_3dac
static u16 f_3dac(u8 param_1)

{
  FN(0x3DAC);
  
  DRV();
  f_bbf0();
  f_71fc();
  *PS8(0x3558) = *PS8(0x3558) + '\x01';
  *P8(param_1 + 0xae64) = *P8((u16)*P8(0x3558) * 2 + 0x354a);
  return f_3e14((u16)param_1);
}

// 1000:3DE0 FUN_1000_3de0
static u16 f_3de0(u8 param_1)

{
  FN(0x3DE0);
  
  DRV();
  f_bbf0();
  f_71fc();
  *PS8(0x3558) = *PS8(0x3558) + -1;
  *P8(param_1 + 0xae64) = *P8((u16)*P8(0x3558) * 2 + 0x3544);
  return f_3e14((u16)param_1);
}

// 1000:3E14 FUN_1000_3e14
static u16 f_3e14(u8 param_1)

{
  FN(0x3E14);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_7130();
  if (iVar1 != 0) {
    if (param_1 == 0) {
      f_05ba();
    }
    return f_a864();
  }
  uVar2 = f_7464();
  *P16((u16)param_1 * 2 + -0x76b2) = uVar2;
  f_87e8(param_1);
  f_8824(param_1);
  f_4ca6();
  if (*PS8(*P8(0x3558) + 0x9ce9) == '\0') {
    f_45ca();
  }
  else {
    f_7238();
  }
  if (*PS8(0x3434) != '\0') {
    f_3d1a();
  }
  f_c7a8();
  f_2b38(*P8(param_1 + 0xae64));
  f_44a4();
  DRV();
  return 0 /* AX? */;
}

// 1000:3E92 FUN_1000_3e92
static u16 f_3e92(u8 param_1)

{
  FN(0x3E92);
  
  if ((*P16((u16)*P8(0x3558) * 2 + 0x3544) == (u16)*P8(param_1 + 0xae64)) &&
     (3 < *P8(param_1 + 0x79ee) % 7)) {
    return 1;
  }
  return 0;
}

// 1000:3EC8 FUN_1000_3ec8
static u16 f_3ec8(u8 param_1)

{
  FN(0x3EC8);
  
  if ((*P16((u16)*P8(0x3558) * 2 + 0x354a) == (u16)*P8(param_1 + 0xae64)) &&
     (*P8(param_1 + 0x79ee) % 7 < 3)) {
    return 1;
  }
  return 0;
}

// 1000:3EFE FUN_1000_3efe
static u16 f_3efe(u8 param_1)

{
  FN(0x3EFE);
  i16 iVar1;
  
  if (*PS8(0x353a) == '\x01') {
    iVar1 = f_3e92(param_1);
    if (iVar1 != 0) {
      f_3dac(param_1);
    }
    iVar1 = f_3ec8(param_1);
    if (iVar1 != 0) {
      f_3de0(param_1);
    }
  }
  return 0 /* AX? */;
}

// 1000:3F42 FUN_1000_3f42
static u16 f_3f42(void)

{
  FN(0x3F42);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P16((u16)local_4 * 2 + 0x3544) = 0xff;
    *P16((u16)local_4 * 2 + 0x354a) = 0xff;
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return 0 /* AX? */;
}

// 1000:3F70 FUN_1000_3f70
static u16 f_3f70(u8 param_1,u8 param_2)

{
  FN(0x3F70);
  
  *P16((u16)param_1 * 2 + 0x3544) = (u16)param_2;
  f_215c((u16)param_2, 6, 1);
  f_215c(param_2, 2, 1);
  f_215c(param_2, 4, 1);
  f_2388(param_2, 0x17b);
  return f_22bc(param_2);
}

// 1000:3FDC FUN_1000_3fdc
static u16 f_3fdc(u8 param_1,u8 param_2)

{
  FN(0x3FDC);
  
  *P16((u16)param_1 * 2 + 0x354a) = (u16)param_2;
  f_215c((u16)param_2, 6, 1);
  f_215c(param_2, 2, 1);
  f_215c(param_2, 0, 1);
  f_2388(param_2, 0x17b);
  return f_22bc(param_2);
}

// 1000:4048 FUN_1000_4048
static u16 f_4048(u8 param_1)

{
  FN(0x4048);
  i16 iVar1;
  
  iVar1 = f_2276(param_1);
  if (iVar1 != 0) {
    iVar1 = f_2a6e(param_1);
    if (iVar1 == 0) {
      iVar1 = f_20f2(param_1, 0);
      if (iVar1 == 0) {
        iVar1 = f_6b42(param_1, *P16((u16)*P8(0x3558) * 2 + 0x354a));
        if (iVar1 == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// 1000:40A4 FUN_1000_40a4
static u16 f_40a4(u8 param_1)

{
  FN(0x40A4);
  i16 iVar1;
  
  iVar1 = f_2276(param_1);
  if (iVar1 != 0) {
    iVar1 = f_2a6e(param_1);
    if (iVar1 == 0) {
      iVar1 = f_20f2(param_1, 4);
      if (iVar1 == 0) {
        iVar1 = f_6b42(param_1, *P16((u16)*P8(0x3558) * 2 + 0x3544));
        if (iVar1 == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// 1000:4102 FUN_1000_4102
static u32 f_4102(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x4102);
  i32 lVar1;
  
  lVar1 = (u32)*P16((param_3 & 7) * 2 + 0x48f4) * (u32)param_2;
  return CONCAT22((i16)((u32)lVar1 >> 0x10),(i16)lVar1 + (u16)param_1);
}

// 1000:4124 FUN_1000_4124
static u16 f_4124(u8 param_1)

{
  FN(0x4124);
  bool bVar1;
  u16 uVar2;
  i16 iVar3;
  u8 local_c;
  u8 local_8;
  u8 local_4;
  
  bVar1 = false;
  local_8 = 0;
  do {
    local_8 = local_8 + 1;
    local_c = 0;
    do {
      uVar2 = f_4102(0x47, local_8, local_c);
      iVar3 = f_4048(uVar2);
      if (iVar3 != 0) {
        bVar1 = true;
        local_4 = f_4102(0x47, local_8, local_c);
      }
      local_c = local_c + 1;
    } while (local_c < 8);
  } while ((!bVar1) && (local_8 < 5));
  if (bVar1) {
    f_3f70(param_1, local_4);
  }
  return 0 /* AX? */;
}

// 1000:41A6 FUN_1000_41a6
static u16 f_41a6(u8 param_1)

{
  FN(0x41A6);
  bool bVar1;
  u16 uVar2;
  i16 iVar3;
  u8 local_c;
  u8 local_8;
  u8 local_4;
  
  bVar1 = false;
  local_8 = 0;
  do {
    local_8 = local_8 + 1;
    local_c = 0;
    do {
      uVar2 = f_4102(0x52, local_8, local_c);
      iVar3 = f_40a4(uVar2);
      if (iVar3 != 0) {
        bVar1 = true;
        local_4 = f_4102(0x52, local_8, local_c);
      }
      local_c = local_c + 1;
    } while (local_c < 8);
  } while ((!bVar1) && (local_8 < 5));
  if (bVar1) {
    f_3fdc(param_1, local_4);
  }
  return 0 /* AX? */;
}

// 1000:4228 FUN_1000_4228
static u16 f_4228(u8 param_1)

{
  FN(0x4228);
  
  if ((*PS8(0x3558) != '\0') &&
     ((u16)*P8(param_1 + 0xae64) == *P16((u16)*P8(0x3558) * 2 + 0x354a))) {
    return 1;
  }
  return 0;
}

// 1000:4252 FUN_1000_4252
static u16 f_4252(u8 param_1)

{
  FN(0x4252);
  
  if ((*PS8(0x3558) != '\0') &&
     ((u16)*P8(param_1 + 0xae64) == *P16((u16)*P8(0x3558) * 2 + 0x3544))) {
    return 1;
  }
  return 0;
}

// 1000:427C FUN_1000_427c
static u16 f_427c(u8 param_1)

{
  FN(0x427C);
  i16 iVar1;
  
  iVar1 = f_4e22();
  if (((iVar1 != 0) && (iVar1 = f_055a(), iVar1 != 1)) &&
     ((((*PS8(0x3558) == '\0' &&
        (iVar1 = f_6b42(param_1, *P16((u16)*P8(0x3558) * 2 + 0x3544)),
        iVar1 != 0)) ||
       ((*PS8(0x3558) == '\x01' &&
        ((iVar1 = f_6b42(param_1, *P16((u16)*P8(0x3558) * 2 + 0x354a)),
         iVar1 != 0 ||
         ((iVar1 = f_055a(), 2 < iVar1 &&
          (iVar1 = f_6b42(param_1, *P16((u16)*P8(0x3558) * 2 + 0x3544)),
          iVar1 != 0)))))))) ||
      ((*PS8(0x3558) == '\x02' &&
       (iVar1 = f_6b42(param_1, *P16((u16)*P8(0x3558) * 2 + 0x354a)),
       iVar1 != 0)))))) {
    return 1;
  }
  return 0;
}

// 1000:432A FUN_1000_432a
static u16 f_432a(void)

{
  FN(0x432A);
  i16 iVar1;
  u8 local_4;
  
  local_4 = 0;
  do {
    iVar1 = f_427c(local_4);
    if (iVar1 != 0) {
      f_2346(local_4);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 0x9a);
  return 0 /* AX? */;
}

// 1000:435E FUN_1000_435e
static u16 f_435e(void)

{
  FN(0x435E);
  
  f_c324();
  f_9f42();
  if (*PS8(0x342a) == '\0') {
    *P8(0x3564) = 1;
  }
  else {
    *P8(0x3564) = 2;
  }
  return f_437c();
}

// 1000:437C FUN_1000_437c
static u16 f_437c(void)

{
  FN(0x437C);
  u8 uVar1;
  u16 uVar2;
  i16 iVar3;
  u8 local_6;
  
  *P8(0x3444) = 1;
  *P8(0x342c) = 0;
  local_6 = 0;
  do {
    *P16((u16)local_6 * 2 + 0x3438) = 0;
    local_6 = local_6 + 1;
  } while (local_6 < 3);
  f_66f4();
  f_9784();
  f_d77c();
  f_3b28();
  f_6a02();
  f_bdbe();
  f_3bfa();
  f_d6cc(0);
  f_4e5c();
  f_c3ec();
  f_4526();
  f_4ae6(0);
  f_c7a8();
  f_b86c(0, *P8(0xae64));
  f_4e5c();
  f_4e3e();
  uVar2 = f_4cc6();
  uVar2 = f_1756(0x3c, uVar2);
  *P16(0x343e) = uVar2;
  iVar3 = f_4cc6();
  uVar2 = f_1756(0x78, iVar3 << 1);
  *P16(0x3440) = uVar2;
  iVar3 = f_4cc6();
  uVar2 = f_1756(0x78, iVar3 << 1);
  *P16(0x3442) = uVar2;
  f_36ea();
  f_3856();
  f_44a4();
  f_3ca8();
  f_45ca();
  iVar3 = f_7130();
  if (iVar3 != 0) {
    uVar1 = f_3d90();
    *P8(0xae6a) = uVar1;
    *P8(0x759c) = 4;
    *P8(0x7d86) = 4;
    uVar2 = f_8a88(uVar1);
    *P16(0x895a) = uVar2;
    f_87e8(6);
    f_8824(6);
    iVar3 = f_719c();
    if (iVar3 != 0) {
      f_b84c(6, 1);
    }
  }
  *P16(0xae62) = 0x4b0;
  *P8(0x4d) = 1;
  if (*PS8(0x4c) != '\x02') {
    f_d702();
  }
  f_39b4();
  f_39b4();
  DRV();
  return 0 /* AX? */;
}

// 1000:44A4 FUN_1000_44a4
static u16 f_44a4(void)

{
  FN(0x44A4);
  i16 iVar1;
  
  f_c722(0, *P8(0xae64));
  f_6da6();
  f_44da();
  iVar1 = f_719c();
  if ((iVar1 != 0) && (*PS8(0x3558) == *PS8(0x759d))) {
    f_c722(1, *P8(0x89fd));
  }
  return 0 /* AX? */;
}

// 1000:44DA FUN_1000_44da
static u16 f_44da(void)

{
  FN(0x44DA);
  u8 uVar1;
  i16 iVar2;
  
  iVar2 = f_4e22();
  if (iVar2 != 0) {
    do {
      do {
        uVar1 = f_170e(0x9a);
        iVar2 = f_2276(uVar1);
      } while (iVar2 != 0);
      iVar2 = f_2a6e(uVar1);
    } while (iVar2 != 0);
    f_c722(2, uVar1);
  }
  return 0 /* AX? */;
}

// 1000:4526 FUN_1000_4526
static u16 f_4526(void)

{
  FN(0x4526);
  i8 cVar1;
  
  cVar1 = *PS8(0x353a);
  if (cVar1 == '\x01') {
    f_454a();
  }
  else {
    if (cVar1 == '\x02') {
      return f_ce7c();
    }
    if (cVar1 == '\x03') {
      f_3434();
      return f_352a();
    }
  }
  return 0 /* AX? */;
}

// 1000:454A FUN_1000_454a
static u16 f_454a(void)

{
  FN(0x454A);
  u16 uVar1;
  i16 iVar2;
  
  f_4e5c();
  if (*PS8(0x3450) == '\x1a') {
    iVar2 = 2;
  }
  else if (((*PS8(0x3450) == '\x15') || (*PS8(0x3450) == '\x16')) ||
          (*PS8(0x3450) == '\x19')) {
    iVar2 = f_0602();
  }
  else {
    iVar2 = f_03c0();
    if (iVar2 == -1) {
      iVar2 = f_0534();
      f_0430(iVar2);
    }
  }
  f_4e7c(iVar2);
  uVar1 = f_055a();
  f_2462(uVar1);
  iVar2 = f_7130();
  if (iVar2 == 0) {
    *P8(0x3558) = 0;
  }
  else {
    *P8(0x3558) = *P8(0x759d);
  }
  f_bbd0();
  return f_71dc();
}

// 1000:45CA FUN_1000_45ca
static u16 f_45ca(void)

{
  FN(0x45CA);
  i8 cVar1;
  u16 uVar2;
  u8 local_6;
  u8 local_4;
  
  if (*PS8(0x3450) == '\x06') {
    f_4e9a();
    *P8(0x8b3c) = 0;
    f_b84c(6, 3);
  }
  if (*PS8(0x3450) == '\x1b') {
    uVar2 = f_c3a0(7, 2);
    f_48aa(6, uVar2);
    *P8(0x8b3c) = 3;
    uVar2 = f_c3a0(7, 3);
    f_48aa(1, uVar2);
    uVar2 = f_c3a0(7, 4);
    f_48aa(2, uVar2);
    uVar2 = f_c3a0(7, 5);
    f_48aa(3, uVar2);
    if (*PS8(0x342a) == '\0') {
      uVar2 = f_c3a0(7, 6);
      f_48aa(4, uVar2);
      uVar2 = f_c3a0(7, 7);
      return f_48aa(5, uVar2);
    }
  }
  else {
    local_6 = 0;
    cVar1 = f_170e(3);
    local_4 = cVar1 + 3;
    if ((*PS8(0x3450) == '\x05') || (*PS8(0x3450) == '\r')) {
      local_4 = 6;
    }
    if (*PS8(0x342a) != '\0') {
      local_4 = f_1756(local_4, 4);
    }
    do {
      local_6 = local_6 + 1;
      if (*PS8(0x3436) != '\0') {
        f_4e9a();
      }
    } while (local_6 < local_4);
  }
  return 0 /* AX? */;
}

// 1000:46F6 FUN_1000_46f6
static u16 f_46f6(void)

{
  FN(0x46F6);
  FUN_1fe7_0216();
  FUN_1fe7_0088();
  DRV();
  return 0 /* AX? */;
}

// 1000:4706 FUN_1000_4706
static u16 f_4706(void)

{
  FN(0x4706);
  FUN_1fe7_00e0();
  FUN_1fe7_0254();
  return 0 /* AX? */;
}

// 1000:4712 FUN_1000_4712
static u16 f_4712(void)

{
  FN(0x4712);
  bool bVar1;
  i16 iVar2;
  
  bVar1 = false;
  iVar2 = f_4e22();
  if (((iVar2 == 0) || (iVar2 = f_7130(), iVar2 != 0)) || (*PS8(0x3450) == '\x15')) {
    iVar2 = f_4d4e();
    if ((iVar2 == 0) && (iVar2 = f_4dc0(), iVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if ((bVar1) || (*PS8(0xae6b) == '\0')) {
    f_a864();
  }
  return 0 /* AX? */;
}

// 1000:475E FUN_1000_475e
static u16 f_475e(u8 param_1,u8 param_2)

{
  FN(0x475E);
  i16 iVar1;
  
  iVar1 = f_15e0(param_2);
  if (iVar1 == 0) {
    iVar1 = f_c776(param_2);
    if (iVar1 != 0) {
      f_4794(param_1, param_2);
    }
  }
  return 0 /* AX? */;
}

// 1000:4794 FUN_1000_4794
static u16 f_4794(u8 param_1,u8 param_2)

{
  FN(0x4794);
  i16a *piVar1;
  i8 cVar2;
  u8 bVar3;
  u16 uVar4;
  
  uVar4 = (u16)param_1;
  *P8(uVar4 + 0xae64) = param_2;
  *P8(uVar4 + 0xae6b) = 1;
  cVar2 = f_170e(4);
  *PS8(uVar4 + 0x7d80) = cVar2 << 1;
  uVar4 = (u16)param_1;
  *P8(uVar4 + 0x8134) = 0;
  *P8(uVar4 + 0xaefc) = 0;
  *P16(uVar4 * 2 + 0x7768) = 0;
  *P8(uVar4 + 0x9d90) = 0;
  *P8(uVar4 + 0x72d0) = 0;
  *P8(uVar4 + 0xae3e) = 0;
  bVar3 = f_170e(100);
  *P8(uVar4 + 0xae4c) = bVar3 & 1;
  uVar4 = (u16)param_1;
  *P8(uVar4 + 0x9e18) = 0;
  *P8(uVar4 + 0x9b06) = 0;
  *P8(uVar4 + 0x9d86) = 0;
  *P8(uVar4 + 0x3568) = 0;
  f_4a1a(uVar4);
  f_49a4(param_1);
  f_2346(param_2);
  f_aa24(param_1, 1);
  f_796a(param_1);
  f_bc26(param_1);
  f_4aa6(param_1);
  f_a58c(param_1);
  f_b84c(param_1, 2);
  f_48e2(param_1);
  f_87e8(param_1);
  f_8824(param_1);
  piVar1 = PS16((u16)*P8(0x3558) * 2 + 0x3438);
  *piVar1 = *piVar1 + 1;
  return 0 /* AX? */;
}

// 1000:48AA FUN_1000_48aa
static u16 f_48aa(u8 param_1,u8 param_2)

{
  FN(0x48AA);
  u16 uVar1;
  
  f_475e(param_1, param_2);
  uVar1 = (u16)param_1;
  *P8(uVar1 + 0x8b36) = 0;
  *P8(uVar1 + 0x7d80) = 4;
  *P8(uVar1 + 0x7596) = 4;
  return f_aa24(uVar1, 2);
}

// 1000:48E2 FUN_1000_48e2
static u16 f_48e2(u8 param_1)

{
  FN(0x48E2);
  i16a *piVar1;
  u16 uVar2;
  i16 iVar3;
  
  uVar2 = f_8a88(*P8(param_1 + 0xae64));
  *P16((u16)param_1 * 2 + -0x76b2) = uVar2;
  if (*PS8(0x353a) != '\x01') {
    iVar3 = f_c390(*P8(param_1 + 0xae64));
    if (iVar3 == 0) {
      piVar1 = PS16((u16)param_1 * 2 + -0x76b2);
      *piVar1 = *piVar1 + -2;
      return 0 /* AX? */;
    }
    iVar3 = f_c390(*P8(param_1 + 0xae64));
    if (iVar3 == 10) {
      piVar1 = PS16((u16)param_1 * 2 + -0x76b2);
      *piVar1 = *piVar1 + 2;
      return 0 /* AX? */;
    }
    iVar3 = f_c380(*P8(param_1 + 0xae64));
    if (iVar3 == 0) {
      piVar1 = PS16((u16)param_1 * 2 + -0x76b2);
      *piVar1 = *piVar1 + -0x9a;
      return 0 /* AX? */;
    }
    iVar3 = f_c380(*P8(param_1 + 0xae64));
    if (iVar3 == 0xd) {
      piVar1 = PS16((u16)param_1 * 2 + -0x76b2);
      *piVar1 = *piVar1 + 0x9a;
    }
  }
  return 0 /* AX? */;
}

// 1000:49A4 FUN_1000_49a4
static u16 f_49a4(u8 param_1)

{
  FN(0x49A4);
  u8 bVar1;
  i16 iVar2;
  
  bVar1 = f_170e(8);
  *P8(param_1 + 0x8b36) =
       *P8((u16)bVar1 + ((*P16(0x353a) & 0xff) * 8 + (u16)*P8(0x355c)) * 8 + 0x410e);
  if (*PS8(0x3450) == '\x06') {
    iVar2 = f_7108((u16)param_1);
    if (iVar2 != 0) {
      *P8(param_1 + 0x8b36) = 0;
      return 0 /* AX? */;
    }
    if (*PS8(param_1 + 0x8b36) == '\0') {
      *PS8(param_1 + 0x8b36) = '\x01';
    }
  }
  return 0 /* AX? */;
}

// 1000:4A1A FUN_1000_4a1a
static u16 f_4a1a(u8 param_1)

{
  FN(0x4A1A);
  u8 bVar1;
  i16 iVar2;
  u16 local_4;
  
  iVar2 = f_7158(param_1);
  if (iVar2 == 0) {
    iVar2 = f_7108(param_1);
    if (iVar2 == 0) {
      bVar1 = f_170e(8);
      local_4 = (u16)bVar1;
      *P8(param_1 + 0x7353) =
           *P8((u16)*P8(0x355c) * 8 + local_4 + 0x410e);
      return 0 /* AX? */;
    }
  }
  *P8(param_1 + 0x7353) = 3;
  return 0 /* AX? */;
}

// 1000:4A80 FUN_1000_4a80
static u16 f_4a80(u8 param_1)

{
  FN(0x4A80);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_7130();
  if ((iVar1 == 0) && (*PS8(0x3450) != '\x05')) {
    uVar2 = f_bb7e();
  }
  else {
    uVar2 = f_bb6a();
  }
  *P16((u16)param_1 * 2 + 0x66) = uVar2;
  return 0 /* AX? */;
}

// 1000:4AA6 FUN_1000_4aa6
static u16 f_4aa6(u8 param_1)

{
  FN(0x4AA6);
  i16 iVar1;
  
  iVar1 = (u16)param_1 * 2;
  *P16(iVar1 + 0x58) = 0;
  *P16(iVar1 + 0x74) = 0;
  *P16(iVar1 + 0x82) = 0;
  *P16(iVar1 + 0x90) = 0;
  *P16(iVar1 + 0x9e) = 0;
  *P16(iVar1 + 0xac) = 0;
  return f_4a80((u16)param_1);
}

// 1000:4AE6 FUN_1000_4ae6
static u16 f_4ae6(u8 param_1)

{
  FN(0x4AE6);
  u8 uVar1;
  u16 uVar2;
  i16 iVar3;
  u16 uVar4;
  
  *P8(param_1 + 0x7340) = 0;
  f_aa24((u16)param_1, 2);
  uVar2 = (u16)param_1;
  *P8(uVar2 + 0xae6b) = 1;
  *P8(uVar2 + 0x8b36) = 2;
  *P8(uVar2 + 0x7353) = 3;
  uVar1 = f_4bdc();
  *P8(uVar2 + 0xae64) = uVar1;
  *P8(0x9af7) = *P8(param_1 + 0xae64);
  *P8(param_1 + 0x8134) = 0;
  iVar3 = f_7130();
  if (iVar3 != 0) {
    uVar1 = f_4ba4((u16)param_1);
    *P8(param_1 + 0xae64) = uVar1;
    *P8(param_1 + 0x8b36) = 0;
  }
  f_2346(*P8(param_1 + 0xae64));
  uVar4 = f_8a88(*P8(param_1 + 0xae64));
  *P16((u16)param_1 * 2 + -0x76b2) = uVar4;
  f_87e8(param_1);
  f_8824(param_1);
  return f_796a(param_1);
}

// 1000:4BA4 FUN_1000_4ba4  FIX: returns the cell found (Ghidra lost AX)
static u16 f_4ba4(u8 param_1)

{
  FN(0x4BA4);
  i8 cVar1;
  
  if (*PS8(0x3450) == '\x13') {
    return f_5308(param_1);
  }
  do {
    cVar1 = f_5222(param_1);
  } while (cVar1 == -1);
  return (u8)cVar1;
}

// 1000:4BDC FUN_1000_4bdc
static u8 f_4bdc(void)

{
  FN(0x4BDC);
  i8 cVar1;
  u8 local_4;
  
  cVar1 = *PS8(0x353a);
  if (cVar1 == '\x01') {
    local_4 = f_4c70();
  }
  else if (cVar1 == '\x02') {
    local_4 = *P8(0xae72);
  }
  else if (cVar1 == '\x03') {
    local_4 = f_4c12();
  }
  return local_4;
}

// 1000:4C12 FUN_1000_4c12
static u16 f_4c12(void)

{
  FN(0x4C12);
  u8 bVar1;
  i8 cVar2;
  u16 uVar3;
  u16 uVar4;
  i8 local_6;
  
  if (*PS8(0x3450) == '\x17') {
    uVar3 = f_c3a0(0xd, 5);
    return uVar3;
  }
  local_6 = '\x14';
  do {
    local_6 = local_6 + -1;
    uVar4 = f_170e(0xb);
    bVar1 = f_c3a0(0xd, uVar4);
    cVar2 = f_3334(bVar1);
    if (local_6 == '\0') break;
  } while (cVar2 == '\a');
  return (u16)bVar1;
}

// 1000:4C70 FUN_1000_4c70
static u8 f_4c70(void)

{
  FN(0x4C70);
  u8 uVar1;
  i16 iVar2;
  i8 local_4;
  
  local_4 = '\0';
  do {
    uVar1 = f_c3a0(0xd, local_4);
    local_4 = local_4 + '\x01';
    iVar2 = f_2276(uVar1);
  } while (iVar2 != 0);
  return uVar1;
}

// 1000:4CA6 FUN_1000_4ca6
static u16 f_4ca6(void)

{
  FN(0x4CA6);
  u8 local_4;
  
  local_4 = 1;
  do {
    *P8(local_4 + 0xae6b) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:4CC6 FUN_1000_4cc6
static u8 f_4cc6(void)

{
  FN(0x4CC6);
  i8 cVar1;
  u8 local_4;
  
  if (*PS8(0x3450) == '\x1b') {
    local_4 = 9;
  }
  else {
    cVar1 = f_170e(7);
    local_4 = *PS8((*P8(0x355c) & 7) + 0x3446) + cVar1;
  }
  if (5 < *P8(0x355c)) {
    local_4 = local_4 << 1;
  }
  *SH16(0x78) = (u16)local_4;
  return local_4;
}

// 1000:4D14 FUN_1000_4d14
static u16 f_4d14(void)

{
  FN(0x4D14);
  i16 iVar1;
  
  iVar1 = f_4d4e();
  if (iVar1 != 0) {
    if (*PS8(0x353a) == '\x01') {
      if ((*PS8(0x3434) == '\0') &&
         (iVar1 = f_1726((u16)*P8(0x355c) * 10 + 10), iVar1 == 0)) {
        return 0 /* AX? */;
      }
      return f_50c6();
    }
    f_500c();
  }
  return 0 /* AX? */;
}

// 1000:4D4E FUN_1000_4d4e
static u16 f_4d4e(void)

{
  FN(0x4D4E);
  bool bVar1;
  i16 iVar2;
  u8 local_6;
  
  if (*PS8(0x3450) == '\x15') {
    bVar1 = false;
    local_6 = 0;
    do {
      iVar2 = f_2276(local_6);
      if ((iVar2 != 0) && (iVar2 = f_221c(local_6), iVar2 == 0)) {
        f_4dbe();
        bVar1 = true;
      }
      local_6 = local_6 + 1;
    } while (local_6 < 0x9a);
    if (!bVar1) {
      return 0;
    }
  }
  if (*P16((u16)*P8(0x3558) * 2 + 0x343e) <= *P16((u16)*P8(0x3558) * 2 + 0x3438)
     ) {
    return 0;
  }
  return 1;
}

// 1000:4DBE FUN_1000_4dbe
static u16 f_4dbe(void)

{
  FN(0x4DBE);
  return 0 /* AX? */;
}

// 1000:4DC0 FUN_1000_4dc0  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_4dc0(void)

{
  FN(0x4DC0);
  u8 local_6;
  u8 local_4;
  
  local_6 = '\0';
  local_4 = 1;
  do {
    if (*PS8(local_4 + 0xae6b) != '\0') {
      local_6 = local_6 + '\x01';
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return local_6;
}

// 1000:4DEE FUN_1000_4dee
static u16 f_4dee(void)

{
  FN(0x4DEE);
  i16 iVar1;
  
  f_4e32();
  iVar1 = f_7122();
  if (((iVar1 != 0) || (*PS8(0x3450) == '\x13')) && (iVar1 = f_4d4e(), iVar1 != 0)) {
    if (*PS16(0x9d8e) != 0) {
      iVar1 = f_4e22();
      if (iVar1 != 0) {
        return 0 /* AX? */;
      }
      iVar1 = f_4dc0();
      if (iVar1 != 0) {
        return 0 /* AX? */;
      }
    }
    f_4e3e();
    f_4d14();
  }
  return 0 /* AX? */;
}

// 1000:4E22 FUN_1000_4e22
static u16 f_4e22(void)

{
  FN(0x4E22);
  
  if (*PS8(0x353a) == '\x01') {
    return 1;
  }
  return 0;
}

// 1000:4E32 FUN_1000_4e32
static u16 f_4e32(void)

{
  FN(0x4E32);
  
  if (*PS16(0x9d8e) != 0) {
    *PS16(0x9d8e) = *PS16(0x9d8e) + -1;
  }
  return 0 /* AX? */;
}

// 1000:4E3E FUN_1000_4e3e
static u16 f_4e3e(void)

{
  FN(0x4E3E);
  i16 iVar1;
  
  iVar1 = f_170e(-(*P8(0x355c) - 9));
  *PS16(0x9d8e) = iVar1 * 0x3c + 0x78;
  return 0 /* AX? */;
}

// 1000:4E5C FUN_1000_4e5c
static u16 f_4e5c(void)

{
  FN(0x4E5C);
  u8 local_14 [4];
  u8 local_10;
  u8 local_8;
  
  f_f8ba(local_14);
  local_8 = local_10;
  return f_4e7c(local_10);
}

// 1000:4E7C FUN_1000_4e7c
static u16 f_4e7c(u16 param_1)

{
  FN(0x4E7C);
  u16 uVar1;
  
  uVar1 = f_a892(param_1);
  return f_fcfa(uVar1, uVar1);
}

// 1000:4E9A FUN_1000_4e9a
static u16 f_4e9a(void)

{
  FN(0x4E9A);
  i16 iVar1;
  u16 uVar2;
  u8 local_6;
  u8 local_4;
  
  local_4 = 0;
  local_6 = 1;
  do {
    if (*PS8(local_6 + 0xae6b) == '\0') {
      local_4 = local_6;
    }
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  if (local_4 != 0) {
    iVar1 = f_7108(local_4);
    if (iVar1 == 0) {
      uVar2 = f_5382();
    }
    else {
      uVar2 = f_5400();
    }
    f_475e(local_4, uVar2);
    iVar1 = f_7108(local_4);
    if (iVar1 != 0) {
      *P8(local_4 + 0x8b36) = 1;
    }
    if ((*PS8(0x353a) == '\x01') || (*PS8(0x3450) == '\x13')) {
      iVar1 = f_7130();
      if (iVar1 != 0) {
        *P8(local_4 + 0x8b36) = 0;
        if ((local_4 < 6) || (*PS8(0x3450) == '\x13')) {
          *P8(local_4 + 0x9e24) = 1;
        }
        else {
          iVar1 = f_719c();
          if ((iVar1 != 0) && (local_4 == 6)) {
            f_b84c(6, 1);
            *P8(0x7352) = 2;
          }
        }
        *P8(local_4 + 0x9b8d) = 0;
      }
      f_54b8(local_4);
    }
    else {
      f_aa24(local_4, 2);
    }
    if (*PS8(0x3450) == '\x13') {
      *P8(local_4 + 0x9e24) = 1;
      *P8(local_4 + 0x8b36) = 0;
    }
  }
  return 0 /* AX? */;
}

// 1000:4FAC FUN_1000_4fac
static u16 f_4fac(u8 param_1)

{
  FN(0x4FAC);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  iVar1 = f_7122();
  if (iVar1 != 0) {
    iVar1 = f_4d4e();
    if (iVar1 != 0) {
      local_4 = 0;
      local_6 = 1;
      do {
        if (*PS8(local_6 + 0xae6b) == '\0') {
          local_4 = local_6;
        }
        local_6 = local_6 + 1;
      } while (local_6 < 7);
      if (local_4 != 0) {
        f_475e(local_4, param_1);
        f_aa24(local_4, 2);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:500C FUN_1000_500c
static u16 f_500c(void)

{
  FN(0x500C);
  i8 cVar1;
  i16 iVar2;
  u16 uVar3;
  u8 local_4;
  
  local_4 = 6;
  while ((*P8(*P8(0x342a) + 0x344e) < local_4 && (*PS8(local_4 + 0xae6b) != '\0'))) {
    local_4 = local_4 - 1;
  }
  if (*P8(*P8(0x342a) + 0x344e) < local_4) {
    cVar1 = f_512e();
    if (cVar1 != -1) {
      if (*PS8(0x3450) == '\x1b') {
        f_48aa(local_4, cVar1);
      }
      else {
        f_475e(local_4, cVar1);
      }
      f_54b8(local_4);
      iVar2 = f_7108(local_4);
      if (iVar2 != 0) {
        *P8(local_4 + 0x8b36) = 1;
      }
      if (*PS8(0x3450) == '\x13') {
        uVar3 = (u16)local_4;
        *P8(uVar3 + 0x9e24) = 1;
        *P8(uVar3 + 0x8b36) = 0;
        *P8(uVar3 + 0x9b8d) = 0;
      }
      return 1;
    }
  }
  return 0;
}

// 1000:50C6 FUN_1000_50c6  FIX: FUN_1000_5222 is called without its argument, which is then the stack word
// under the return address: [bp-4] here, not yet written. Its only path (1000:4DEE -> 4E3E, 4D14 -> 4D4E,
// [1726], 50C6) leaves in that word: the 100 FUN_1000_1726 pushes for FUN_1000_170e when the alarm is off
// (DS:3434 == 0); otherwise FUN_1000_4d4e's cell counter (0x9A after its loop) in mission type 0x15, else the
// remainder FUN_1000_170e computed for FUN_1000_4e3e just before (its [bp-2]), which DS:9D8E still holds as
// remainder * 60 + 120. Zero = the first 0x26 cells only, nonzero = the whole floor.
static u16 f_50c6(void)

{
  FN(0x50C6);
  i8 cVar1;
  u8 local_4;
  
  local_4 = 6;
  while ((*P8(*P8(0x342a) + 0x344e) < local_4 && (*PS8(local_4 + 0xae6b) != '\0'))) {
    local_4 = local_4 - 1;
  }
  if (*P8(*P8(0x342a) + 0x344e) < local_4) {
    cVar1 = f_5222(*PS8(0x3434) == 0 ? 100 : *PS8(0x3450) == 0x15 ? 0x9a : (*P16(0x9d8e) - 0x78) / 0x3c);
    if (cVar1 != -1) {
      f_475e(local_4, cVar1);
      f_54b8(local_4);
      return 1;
    }
  }
  return 0;
}

// 1000:512E FUN_1000_512e
static u8 f_512e(void)

{
  FN(0x512E);
  i8 cVar1;
  u8 uVar2;
  i16 iVar3;
  u8 local_c;
  u8 local_8;
  i8 local_6;
  
  local_6 = '\n';
  do {
    cVar1 = f_170e(4);
    if (cVar1 == '\0') {
      local_8 = f_170e(0xe);
      local_c = 0;
    }
    else if (cVar1 == '\x01') {
      local_8 = f_170e(0xe);
      local_c = 10;
    }
    else {
      if (cVar1 == '\x02') {
        local_8 = 0;
      }
      else {
        if (cVar1 != '\x03') goto LAB_1000_5177;
        local_8 = 0xd;
      }
      local_c = f_170e(0xb);
    }
LAB_1000_5177:
    uVar2 = f_c3a0(local_8, local_c);
    local_6 = local_6 + -1;
    iVar3 = f_2276(uVar2);
    if ((((iVar3 == 0) && (iVar3 = f_15e0(uVar2), iVar3 == 0)) &&
        (iVar3 = f_2a10(uVar2), iVar3 == 0)) || (local_6 == '\0')) {
      iVar3 = f_15e0(uVar2);
      if ((iVar3 == 0) && (iVar3 = f_2276(uVar2), iVar3 == 0)) {
        return uVar2;
      }
      return 0xff;
    }
  } while( true );
}

// 1000:5222 FUN_1000_5222
static u8 f_5222(i8 param_1)

{
  FN(0x5222);
  u8 uVar1;
  i16 iVar2;
  i8 local_8;
  u8 local_6;
  
  if (param_1 == '\0') {
    local_6 = 0x26;
  }
  else {
    local_6 = 0x9a;
  }
  local_8 = '2';
  do {
    uVar1 = f_170e(local_6);
    local_8 = local_8 + -1;
    iVar2 = f_2276(uVar1);
    if (iVar2 != 0) {
      iVar2 = f_221c(uVar1);
      if (iVar2 == 0) {
        iVar2 = f_15e0(uVar1);
        if (iVar2 == 0) {
          iVar2 = f_3d56(uVar1);
          if (iVar2 == 0) {
            iVar2 = f_5478(uVar1);
            if (iVar2 == 0) break;
          }
        }
      }
    }
  } while (local_8 != '\0');
  if (local_8 == '\0') {
    return 0xff;
  }
  return uVar1;
}

// 1000:52B8 FUN_1000_52b8
static u16 f_52b8(u8 param_1)

{
  FN(0x52B8);
  u8 uVar1;
  i16 iVar2;
  
  do {
    do {
      do {
        uVar1 = f_170e(0x9a);
        iVar2 = f_2276(uVar1);
      } while (iVar2 != 0);
      iVar2 = f_221c(uVar1);
    } while (iVar2 != 0);
    iVar2 = f_15e0(uVar1);
  } while (iVar2 != 0);
  *P8(param_1 + 0xae64) = uVar1;
  return 0 /* AX? */;
}

// 1000:5308 FUN_1000_5308
static u16 f_5308(u8 param_1)

{
  FN(0x5308);
  u8 uVar1;
  i16 iVar2;
  
  do {
    do {
      uVar1 = f_170e(0x9a);
      iVar2 = f_2276(uVar1);
    } while (iVar2 != 0);
    iVar2 = f_15e0(uVar1);
  } while (iVar2 != 0);
  *P8(param_1 + 0xae64) = uVar1;
  return 0 /* AX? */;
}

// 1000:5348 FUN_1000_5348
static u8 f_5348(void)

{
  FN(0x5348);
  u8 uVar1;
  i16 iVar2;
  
  do {
    do {
      uVar1 = f_170e(0x21);
      iVar2 = f_2276(uVar1);
    } while (iVar2 == 0);
    iVar2 = f_2a6e(uVar1);
  } while (iVar2 != 0);
  return uVar1;
}

// 1000:5382 FUN_1000_5382
static u8 f_5382(void)

{
  FN(0x5382);
  u8 uVar1;
  i16 iVar2;
  u8 local_4;
  
  if ((*PS8(0x3558) == '\0') && (*PS8(0x3450) != '\x05')) {
    local_4 = 0x4d;
  }
  else {
    local_4 = 0x9a;
  }
  iVar2 = f_7130();
  if (iVar2 != 0) {
    local_4 = 0x4d;
  }
  do {
    do {
      do {
        do {
          uVar1 = f_170e(local_4);
          iVar2 = f_2276(uVar1);
        } while (iVar2 != 0);
        iVar2 = f_15e0(uVar1);
      } while (iVar2 != 0);
      iVar2 = f_2a10(uVar1);
    } while (iVar2 != 0);
    iVar2 = f_5478(uVar1);
  } while (iVar2 != 0);
  return uVar1;
}

// 1000:5400 FUN_1000_5400
static u8 f_5400(void)

{
  FN(0x5400);
  u8 uVar1;
  i16 iVar2;
  
  do {
    do {
      do {
        do {
          uVar1 = f_170e(0x4d);
          iVar2 = f_2276(uVar1);
        } while (iVar2 != 0);
        iVar2 = f_15e0(uVar1);
      } while (iVar2 != 0);
      iVar2 = f_2a10(uVar1);
    } while (iVar2 != 0);
    iVar2 = f_5478(uVar1);
  } while (iVar2 != 0);
  return uVar1;
}

// 1000:5460 FUN_1000_5460
static u16 f_5460(u8 param_1)

{
  FN(0x5460);
  
  return f_5478(*P8(param_1 + 0xae64));
}

// 1000:5478 FUN_1000_5478
static u16 f_5478(u8 param_1)

{
  FN(0x5478);
  i16 iVar1;
  u16 uVar2;
  
  if (*PS8(0x353a) == '\x01') {
    iVar1 = f_7130();
    if (iVar1 == 0) {
      iVar1 = f_0676();
      if ((iVar1 != 0) && (*PS8(0x3558) == *PS8(0x7364))) {
        uVar2 = f_2276(param_1);
        if (uVar2 == *P8(0xae73)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// 1000:54B8 FUN_1000_54b8
static u16 f_54b8(u8 param_1)

{
  FN(0x54B8);
  u16 uVar1;
  
  if (*PS8(0x3434) == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return f_aa24(param_1, uVar1);
}

// 1000:54DA FUN_1000_54da
static u16 f_54da(u8 param_1)

{
  FN(0x54DA);
  u8 bVar1;
  u16 uVar2;
  u16 uVar3;
  u8 bVar4;
  
  uVar2 = f_7c38();
  bVar4 = (u8)((u32)uVar2 % 0x4d);
  bVar1 = (u8)((u32)uVar2 / 0x4d);
  if ((*P8(param_1 + 0x7596) & 2) == 0) {
    if (bVar4 < *P8(param_1 + 0x7776)) {
      uVar3 = 6;
    }
    else {
      if (bVar4 <= *P8(param_1 + 0x7776)) {
        return 0 /* AX? */;
      }
      uVar3 = 2;
    }
  }
  else if (bVar1 < *P8(param_1 + 0x79ee)) {
    uVar3 = 0;
  }
  else {
    if (bVar1 <= *P8(param_1 + 0x79ee)) {
      return 0 /* AX? */;
    }
    uVar3 = 4;
  }
  return f_5562(param_1, uVar3);
}

// 1000:5562 FUN_1000_5562  FIX: param_2 is zero-extended (u8, not Ghidra's i8)
static u16 f_5562(u8 param_1,u8 param_2)

{
  FN(0x5562);
  u8 local_4;
  
  local_4 = param_2;
  if ((param_2 == '\0') && (*PS8(param_1 + 0x79ee) == '\0')) {
    local_4 = f_1c36(0);
  }
  if ((param_2 == '\x04') && (*PS8(param_1 + 0x79ee) == '\x06')) {
    local_4 = f_1c36(4);
  }
  if ((param_2 == '\x06') && (*PS8(param_1 + 0x7776) == '\0')) {
    local_4 = f_1c36(6);
  }
  if ((param_2 == '\x02') && (*PS8(param_1 + 0x7776) == '\x06')) {
    local_4 = f_1c36(2);
  }
  return f_8654(param_1, local_4);
}

// 1000:55FC FUN_1000_55fc
static u16 f_55fc(u8 param_1)

{
  FN(0x55FC);
  u8 bVar1;
  u16 uVar2;
  i16 iVar3;
  u8 bVar4;
  u8 local_a;
  
  uVar2 = f_7c38();
  bVar4 = (u8)((u32)uVar2 % 0x4d);
  bVar1 = (u8)((u32)uVar2 / 0x4d);
  uVar2 = (u16)param_1;
  if ((*P8(uVar2 + 0x7596) & 2) != 0) {
    if (bVar1 < *P8(uVar2 + 0x79ee)) {
      bVar1 = *P8(uVar2 + 0x79ee);
joined_r0x0001569e:
      if (5 < bVar1 % 7) {
        local_a = 0;
        goto LAB_1000_5728;
      }
    }
    else {
      bVar4 = *P8(param_1 + 0x79ee);
      if (bVar1 <= bVar4) {
        iVar3 = f_170e(100);
        if (0x31 < iVar3) {
          bVar1 = *P8(param_1 + 0x79ee);
          goto joined_r0x0001569e;
        }
        bVar4 = *P8(param_1 + 0x79ee);
      }
      if (bVar4 % 7 != 0) {
        local_a = 0;
        goto LAB_1000_5728;
      }
    }
    local_a = 4;
    goto LAB_1000_5728;
  }
  bVar1 = *P8(param_1 + 0x7776);
  if (bVar4 < bVar1) {
joined_r0x00015722:
    if (5 < bVar1 % 7) {
LAB_1000_5724:
      local_a = 6;
      goto LAB_1000_5728;
    }
  }
  else {
    bVar1 = *P8(param_1 + 0x7776);
    if (bVar4 <= bVar1) {
      iVar3 = f_170e(100);
      if (0x31 < iVar3) {
        bVar1 = *P8(param_1 + 0x7776);
        goto joined_r0x00015722;
      }
      bVar1 = *P8(param_1 + 0x7776);
    }
    if (bVar1 % 7 != 0) goto LAB_1000_5724;
  }
  local_a = 2;
LAB_1000_5728:
  return f_5562(param_1, local_a);
}

// 1000:573E FUN_1000_573e
static u16 f_573e(u8 param_1)

{
  FN(0x573E);
  u8 bVar1;
  u16 uVar2;
  u16 uVar3;
  u8 bVar4;
  
  uVar2 = (u16)param_1;
  *P8(uVar2 + 0xae3e) = 0;
  uVar2 = f_8a88((i16)*PS8((*P8(uVar2 + 0x7596) >> 1) + 0x4104) +
                        (u16)*P8(uVar2 + 0xae64));
  bVar4 = (u8)((u32)uVar2 % 0x4d);
  bVar1 = (u8)((u32)uVar2 / 0x4d);
  if ((*P8(param_1 + 0x7596) & 2) == 0) {
    if (bVar4 < *P8(param_1 + 0x7776)) {
      uVar3 = 6;
    }
    else {
      if (bVar4 <= *P8(param_1 + 0x7776)) {
        return 0 /* AX? */;
      }
      uVar3 = 2;
    }
  }
  else if (bVar1 < *P8(param_1 + 0x79ee)) {
    uVar3 = 0;
  }
  else {
    if (bVar1 <= *P8(param_1 + 0x79ee)) {
      return 0 /* AX? */;
    }
    uVar3 = 4;
  }
  return f_5562(param_1, uVar3);
}

// 1000:57EA FUN_1000_57ea
static u16 f_57ea(u8 param_1)

{
  FN(0x57EA);
  u8 bVar1;
  u16 uVar2;
  i16 iVar3;
  u8 bVar4;
  u8 local_a;
  
  uVar2 = (u16)param_1;
  *P8(uVar2 + 0xae3e) = 0;
  uVar2 = f_8a88((i16)*PS8((*P8(uVar2 + 0x7596) >> 1) + 0x4104) +
                        (u16)*P8(uVar2 + 0xae64));
  bVar4 = (u8)((u32)uVar2 % 0x4d);
  bVar1 = (u8)((u32)uVar2 / 0x4d);
  uVar2 = (u16)param_1;
  if ((*P8(uVar2 + 0x7596) & 2) != 0) {
    if (bVar1 < *P8(uVar2 + 0x79ee)) {
      bVar1 = *P8(uVar2 + 0x79ee);
joined_r0x000158b0:
      if (5 < bVar1 % 7) {
        local_a = 0;
        goto LAB_1000_593a;
      }
    }
    else {
      bVar4 = *P8(param_1 + 0x79ee);
      if (bVar1 <= bVar4) {
        iVar3 = f_170e(100);
        if (0x31 < iVar3) {
          bVar1 = *P8(param_1 + 0x79ee);
          goto joined_r0x000158b0;
        }
        bVar4 = *P8(param_1 + 0x79ee);
      }
      if (bVar4 % 7 != 0) {
        local_a = 0;
        goto LAB_1000_593a;
      }
    }
    local_a = 4;
    goto LAB_1000_593a;
  }
  bVar1 = *P8(param_1 + 0x7776);
  if (bVar4 < bVar1) {
joined_r0x00015934:
    if (5 < bVar1 % 7) {
LAB_1000_5936:
      local_a = 6;
      goto LAB_1000_593a;
    }
  }
  else {
    bVar1 = *P8(param_1 + 0x7776);
    if (bVar4 <= bVar1) {
      iVar3 = f_170e(100);
      if (0x31 < iVar3) {
        bVar1 = *P8(param_1 + 0x7776);
        goto joined_r0x00015934;
      }
      bVar1 = *P8(param_1 + 0x7776);
    }
    if (bVar1 % 7 != 0) goto LAB_1000_5936;
  }
  local_a = 2;
LAB_1000_593a:
  return f_5562(param_1, local_a);
}

// 1000:5950 FUN_1000_5950
static u16 f_5950(u8 param_1,u8 param_2)

{
  FN(0x5950);
  i16 iVar1;
  
  iVar1 = f_599a(param_1, param_2);
  if (iVar1 == 0) {
    iVar1 = f_7ece((u16)param_1, *P16((u16)param_1 * 2 + -0x76b2), param_2);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}

// 1000:599A FUN_1000_599a
static u16 f_599a(u8 param_1,u8 param_2)

{
  FN(0x599A);
  
  return f_1e7c((u16)param_1, (i16)*PS8(param_2 + 0x3572) + *PS16((u16)param_1 * 2 + -0x76b2));
  return 0 /* AX? */;
}

// 1000:59C2 FUN_1000_59c2
static u16 f_59c2(u8 param_1,u8 param_2)

{
  FN(0x59C2);
  i8 cVar1;
  i16 iVar2;
  
  if ((param_1 == 0) ||
     (iVar2 = f_3740(*P8(param_1 + 0xae64), param_2), iVar2 != 0)) {
    if (*PS8(0x353a) == '\x02') {
      iVar2 = f_ad2c(*P8(param_1 + 0xae64));
      if ((iVar2 != 0) &&
         (iVar2 = f_ad7a(*P8(param_1 + 0xae64)), iVar2 != 0)) {
        return 0;
      }
      iVar2 = f_2276((i16)*PS8((param_2 >> 1) + 0x4104) +
                            (u16)*P8(param_1 + 0xae64));
      if (iVar2 != 0) {
        return 1;
      }
    }
    if ((((param_1 == 0) || (param_2 != 4)) ||
        (iVar2 = f_c380(*P8(param_1 + 0xae64)), iVar2 != 0xd)) &&
       (cVar1 = f_20f2(*P8(param_1 + 0xae64), param_2 & 6), cVar1 != '\x01')) {
      return 0;
    }
  }
  return 1;
}

// 1000:5A9E FUN_1000_5a9e
static u16 f_5a9e(u8 param_1,u8 param_2)

{
  FN(0x5A9E);
  i16 iVar1;
  
  iVar1 = f_20f2(*P8(param_1 + 0xae64), param_2 & 6);
  if (iVar1 == 2) {
    return 1;
  }
  return 0;
}

// 1000:5ACA FUN_1000_5aca
static u16 f_5aca(u8 param_1,u8 param_2)

{
  FN(0x5ACA);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_59c2(param_1, param_2);
  if (iVar1 == 0) {
    iVar1 = f_599a(param_1, param_2);
    if (iVar1 == 0) {
      iVar1 = f_5a9e(param_1, param_2);
      if (iVar1 != 0) {
        uVar2 = f_170e(8);
        return uVar2;
      }
      iVar1 = f_161c((i16)*PS8((param_2 >> 1) + 0x4104) +
                            (u16)*P8(param_1 + 0xae64));
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// 1000:5B42 FUN_1000_5b42
static u16 f_5b42(u8 param_1,u8 param_2)

{
  FN(0x5B42);
  i8 cVar1;
  
  cVar1 = f_20f2(param_1, param_2 & 6);
  if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
    return 0;
  }
  return 1;
}

// 1000:5B78 FUN_1000_5b78
static u16 f_5b78(u8 param_1,u8 param_2)

{
  FN(0x5B78);
  i16 iVar1;
  u16 uVar2;
  
  if (*PS8(param_1 + 0x734c) == '\x02') {
    iVar1 = f_3356(*P8(param_1 + 0xae64));
    if (iVar1 == 0) {
      iVar1 = f_3356((i16)*PS8((param_2 >> 1) + 0x4104) +
                            (u16)*P8(param_1 + 0xae64));
      if (iVar1 != 0) {
        uVar2 = f_8a34((i16)*PS8(param_2 + 0x3572) +
                              *PS16((u16)param_1 * 2 + -0x76b2));
        iVar1 = f_2440(uVar2);
        if (4 < iVar1) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// 1000:5BF2 FUN_1000_5bf2
static u16 f_5bf2(u8 param_1)

{
  FN(0x5BF2);
  u8 bVar1;
  u8 bVar2;
  u16 uVar3;
  u8 local_a;
  u8 local_6;
  
  bVar1 = f_c380(param_1);
  bVar2 = f_c390(param_1);
  uVar3 = (u16)bVar2;
  for (local_6 = 0; local_6 < 7; local_6 = local_6 + 1) {
    for (local_a = 0; local_a < 7; local_a = local_a + 1) {
      f_a0a8((u16)local_a * 0x4d + (u16)local_6 + (u16)bVar1 * 0x21b + uVar3 * 7);
    }
  }
  return 0 /* AX? */;
}

// 1000:5C70 FUN_1000_5c70
static u16 f_5c70(i16 param_1,i16 param_2)

{
  FN(0x5C70);
  f_5cae(param_1, param_2);
  f_5cae(param_1 + 1, param_2);
  f_5cae(param_1, param_2 + 1);
  return f_5cae(param_1 + 1, param_2 + 1);
  return 0 /* AX? */;
}

// 1000:5CAE FUN_1000_5cae
static u16 f_5cae(u16 param_1,u16 param_2)

{
  FN(0x5CAE);
  i16 iVar1;
  i16 iVar2;
  u16 local_8;
  u16 local_6;
  
  iVar1 = f_a114(0xfffe, 0xfffe);
  iVar2 = f_a122(param_1, param_2);
  for (local_6 = 0; local_6 < 4; local_6 = local_6 + 1) {
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      f_a0fc(iVar2 + iVar1, local_6, local_8);
    }
  }
  return 0 /* AX? */;
}

// 1000:5D0A FUN_1000_5d0a
static u16 f_5d0a(u8 param_1,u8 param_2)

{
  FN(0x5D0A);
  i16 iVar1;
  i16 iVar2;
  u16 local_6;
  
  iVar1 = f_a114(0, 1);
  iVar2 = f_a122(param_1, param_2);
  local_6 = 0;
  do {
    f_a0fc(iVar2 + iVar1, local_6, 0);
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  return 0 /* AX? */;
}

// 1000:5D58 FUN_1000_5d58
static u16 f_5d58(u8 param_1,u8 param_2)

{
  FN(0x5D58);
  i16 iVar1;
  i16 iVar2;
  u16 local_6;
  
  iVar1 = f_a114(0, 0xfffe);
  iVar2 = f_a122(param_1 + 1, param_2);
  local_6 = 0;
  do {
    f_a0fc(iVar2 + iVar1, local_6, 0);
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  return 0 /* AX? */;
}

// 1000:5DA6 FUN_1000_5da6
static u16 f_5da6(u8 param_1,u8 param_2)

{
  FN(0x5DA6);
  i16 iVar1;
  i16 iVar2;
  u16 local_8;
  
  iVar1 = f_a114(1, 0);
  iVar2 = f_a122(param_1, param_2);
  local_8 = 0;
  do {
    f_a0fc(iVar2 + iVar1, 0, local_8);
    local_8 = local_8 + 1;
  } while (local_8 < 7);
  return 0 /* AX? */;
}

// 1000:5DF4 FUN_1000_5df4
static u16 f_5df4(u8 param_1,u8 param_2)

{
  FN(0x5DF4);
  i16 iVar1;
  i16 iVar2;
  u16 local_8;
  
  iVar1 = f_a114(0xfffe, 0);
  iVar2 = f_a122(param_1, param_2 + 1);
  local_8 = 0;
  do {
    f_a0fc(iVar2 + iVar1, 0, local_8);
    local_8 = local_8 + 1;
  } while (local_8 < 7);
  return 0 /* AX? */;
}

// 1000:5E44 FUN_1000_5e44
static u16 f_5e44(u8 param_1,u8 param_2)

{
  FN(0x5E44);
  u16 local_6;
  
  local_6 = 2;
  do {
    f_a0a8((u16)param_1 * 0x21b + (u16)param_2 * 7 + 0x4d + local_6);
    local_6 = local_6 + 1;
  } while (local_6 < 5);
  return 0 /* AX? */;
}

// 1000:5E94 FUN_1000_5e94
static u16 f_5e94(u8 param_1,u8 param_2)

{
  FN(0x5E94);
  u16 uVar1;
  u16 local_6;
  
  uVar1 = 0;
  local_6 = 2;
  do {
    f_a0a8((u16)param_1 * 0x21b + (u16)param_2 * 7 + 0x181 + local_6);
    local_6 = local_6 + 1;
  } while (local_6 < 5);
  return 0 /* AX? */;
}

// 1000:5EE2 FUN_1000_5ee2
static u16 f_5ee2(u8 param_1,u8 param_2)

{
  FN(0x5EE2);
  u16 local_8;
  
  local_8 = 2;
  do {
    f_a0a8(local_8 * 0x4d + (u16)param_1 * 0x21b + (u16)param_2 * 7 + 1);
    local_8 = local_8 + 1;
  } while (local_8 < 5);
  return 0 /* AX? */;
}

// 1000:5F32 FUN_1000_5f32
static u16 f_5f32(u8 param_1,u8 param_2)

{
  FN(0x5F32);
  u16 uVar1;
  u16 uVar2;
  
  uVar2 = 0;
  uVar1 = 2;
  do {
    f_a0a8(uVar1 * 0x4d + (u16)param_1 * 0x21b + (u16)param_2 * 7 + 5);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 5);
  return 0 /* AX? */;
}

// 1000:5F82 FUN_1000_5f82  FIX: param_2 is zero-extended (u8, not Ghidra's i8)
static u16 f_5f82(u8 param_1,u8 param_2)

{
  FN(0x5F82);
  u8 uVar1;
  u8 uVar2;
  
  uVar1 = f_c380(param_1);
  uVar2 = f_c390(param_1);
  if (param_2 == '\0') {
    f_5e44(uVar1, uVar2);
  }
  else if (param_2 == '\x02') {
    f_5f32(uVar1, uVar2);
  }
  else if (param_2 == '\x04') {
    f_5e94(uVar1, uVar2);
  }
  else {
    if (param_2 != '\x06') {
      return 0 /* AX? */;
    }
    f_5ee2(uVar1, uVar2);
  }
  return 0 /* AX? */;
}

// 1000:6006 FUN_1000_6006  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u16 f_6006(u8 param_1,u8 param_2)

{
  FN(0x6006);
  i8 cVar1;
  u8 uVar2;
  i16 iVar3;
  
  if (*PS8(0x353a) == '\x01') {
    cVar1 = f_c380(param_1);
    if ((cVar1 != '\r') || (param_2 != 4)) {
      uVar2 = f_1c36(param_2);
      cVar1 = *PS8((param_2 >> 1) + 0x4104) + param_1;
      f_215c(param_1, param_2, 3);
      f_bf7c(4, param_1);
      if (*PS8(0x342c) == '\0') {
        f_bf7c(4, cVar1);
      }
      f_5f82(param_1, param_2);
      if (*PS8(0x342c) == '\0') {
        f_5f82(cVar1, uVar2);
      }
      iVar3 = f_221c(cVar1);
      if (((iVar3 == 0) && (*PS8(0x342c) == '\0')) && (param_1 == *P8(0xae64))) {
        f_2b38(cVar1);
      }
      iVar3 = f_221c(param_1);
      if ((iVar3 == 0) && (iVar3 = f_221c(cVar1), iVar3 == 0)) {
        return 0 /* AX? */;
      }
      f_61f6(4, param_1, param_2);
      f_61f6(2, param_1, param_2);
      return f_61f6(0, param_1, param_2);
    }
  }
  else {
    f_05ba();
  }
  return f_a864();
}

// 1000:6148 FUN_1000_6148
static u16 f_6148(u8 param_1,u8 param_2,u8 param_3,u8 param_4)

{
  FN(0x6148);
  u8 uVar1;
  
  uVar1 = f_c3a0(param_2, param_3);
  return f_6176(param_1, uVar1, param_4);
}

// 1000:6176 FUN_1000_6176  FIX: param_3 is zero-extended (u8, not Ghidra's i8)
static u16 f_6176(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x6176);
  i8 cVar1;
  u16 uVar2;
  u8 local_12;
  u8 local_a;
  
  local_a = f_c380(param_2);
  local_12 = f_c390(param_2);
  cVar1 = f_20f2(param_2, param_3);
  if (cVar1 != '\0') {
    uVar2 = f_6320(param_2, param_3);
    if (param_3 == '\x02') {
      local_12 = local_12 + 1;
    }
    if (param_3 == '\x04') {
      local_a = local_a + 1;
    }
    f_8d3c(param_1, uVar2, (u16)local_12 * 0x1c, (u16)local_a * 0x1c);
  }
  return 0 /* AX? */;
}

// 1000:61F6 FUN_1000_61f6  FIX: param_2 is zero-extended (u8, not Ghidra's i8)
static u16 f_61f6(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x61F6);
  i8 cVar1;
  u8 bVar2;
  u8 bVar3;
  i16 iVar4;
  u16 local_14;
  u16 local_e;
  u16 local_c;
  u16 local_4;
  
  bVar2 = f_c380(param_2);
  bVar3 = f_c390(param_2);
  iVar4 = f_6320(param_2, param_3);
  if (param_3 == 0) {
    local_4 = (u16)bVar2 * 0x1c;
LAB_1000_6255:
    local_14 = (u16)bVar3 * 0x1c;
    local_c = 0x18;
    local_e = 5;
  }
  else {
    if (param_3 == 2) {
      local_14 = (u16)bVar3 * 0x1c + 0x1c;
    }
    else {
      if (param_3 == 4) {
        local_4 = (u16)bVar2 * 0x1c + 0x1c;
        goto LAB_1000_6255;
      }
      if (param_3 != 6) goto LAB_1000_629e;
      local_14 = (u16)bVar3 * 0x1c;
    }
    local_4 = (u16)bVar2 * 0x1c;
    local_c = 4;
    local_e = 0x17;
  }
LAB_1000_629e:
  cVar1 = *PS8((param_3 >> 1) + 0x4104);
  f_95c8(param_1, param_2, *PS16(iVar4 * 2 + 0x39d0) + local_14, *PS16(iVar4 * 2 + 0x3d5a) + local_4, local_c, local_e);
  f_95c8(param_1, cVar1 + param_2, *PS16(iVar4 * 2 + 0x39d0) + local_14, *PS16(iVar4 * 2 + 0x3d5a) + local_4, local_c, local_e);
  return f_8d3c(param_1, iVar4, local_14, local_4);
  return 0 /* AX? */;
}

// 1000:6320 FUN_1000_6320
static i16 f_6320(u8 param_1,u8 param_2)

{
  FN(0x6320);
  i8 cVar1;
  i8 cVar2;
  u8 bVar3;
  u8 local_6;
  i16 local_4;
  
  cVar1 = f_c380(param_1);
  cVar2 = f_c390(param_1);
  local_6 = f_20f2(param_1, param_2);
  if ((param_2 == 0) && (cVar1 == '\0')) {
    local_6 = local_6 + 3;
  }
  if ((param_2 == 4) && (cVar1 == '\r')) {
    local_6 = local_6 + 3;
  }
  if ((param_2 == 6) && (cVar2 == '\0')) {
    local_6 = local_6 + 3;
  }
  if ((param_2 == 2) && (cVar2 == '\n')) {
    local_6 = local_6 + 3;
  }
  bVar3 = param_2 & 6;
  if ((param_2 & 6) == 0) {
LAB_1000_63b2:
    local_4 = local_6 + 0x184;
  }
  else {
    if (bVar3 != 2) {
      if (bVar3 == 4) goto LAB_1000_63b2;
      if (bVar3 != 6) {
        return local_4;
      }
    }
    local_4 = local_6 + 0x180;
  }
  return local_4;
}

// 1000:63CE FUN_1000_63ce
static u16 f_63ce(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x63CE);
  u8 uVar1;
  u8 uVar2;
  
  uVar1 = f_c380(param_2);
  uVar2 = f_c390(param_2);
  return f_6176(param_1, param_2, param_3);
  return 0 /* AX? */;
}

// 1000:6408 FUN_1000_6408  FIX: param_3 is zero-extended (u8, not Ghidra's i8)
static u16 f_6408(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x6408);
  if (param_3 == '\0') {
    f_5d0a(param_1, param_2);
  }
  else if (param_3 == '\x02') {
    f_5df4(param_1, param_2);
  }
  else if (param_3 == '\x04') {
    f_5d58(param_1, param_2);
  }
  else {
    if (param_3 != '\x06') {
      return 0 /* AX? */;
    }
    f_5da6(param_1, param_2);
  }
  return 0 /* AX? */;
}

// 1000:6468 FUN_1000_6468
static u16 f_6468(u8 param_1,u8 param_2)

{
  FN(0x6468);
  u8 uVar1;
  u8 uVar2;
  
  uVar1 = f_c380(param_1);
  uVar2 = f_c390(param_1);
  f_6408(uVar1, uVar2, param_2);
  return f_64b6(uVar1, uVar2, param_2);
}

// 1000:64B6 FUN_1000_64b6  FIX: param_3 is zero-extended (u8, not Ghidra's i8)
static u16 f_64b6(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x64B6);
  u16 uVar1;
  u16 uVar2;
  
  if (param_3 == '\0') {
    f_5cae(param_1, param_2);
    uVar1 = param_2 + 1;
LAB_1000_64ea:
    uVar2 = (u16)param_1;
  }
  else {
    if (param_3 == '\x02') {
      f_5cae(param_1, param_2 + 1);
      uVar1 = param_2 + 1;
    }
    else {
      if (param_3 != '\x04') {
        if (param_3 != '\x06') {
          return 0 /* AX? */;
        }
        f_5cae(param_1 + 1, param_2);
        uVar1 = (u16)param_2;
        goto LAB_1000_64ea;
      }
      f_5cae(param_1 + 1, param_2 + 1);
      uVar1 = (u16)param_2;
    }
    uVar2 = param_1 + 1;
  }
  return f_5cae(uVar2, uVar1);
}

// 1000:6554 FUN_1000_6554
static u16 f_6554(u8 param_1,u8 param_2)

{
  FN(0x6554);
  u8 bVar1;
  
  if (*PS8(0x353a) == '\x01') {
    bVar1 = *P8(param_2 + 0x7776) % 7;
    if (bVar1 < 2) {
      f_63ce(param_1, *P8(param_2 + 0xae64), 6);
    }
    if (4 < bVar1) {
      f_63ce(param_1, *P8(param_2 + 0xae64), 2);
    }
    bVar1 = *P8(param_2 + 0x79ee) % 7;
    if (bVar1 < 2) {
      f_63ce(param_1, *P8(param_2 + 0xae64), 0);
    }
    if (4 < bVar1) {
      f_63ce(param_1, *P8(param_2 + 0xae64), 4);
    }
  }
  return 0 /* AX? */;
}

// 1000:6602 FUN_1000_6602
static u16 f_6602(u16 param_1,u16 param_2)

{
  FN(0x6602);
  u8 bVar2;
  u16 uVar1;
  
  if (*PS8(0x353a) == '\x01') {
    bVar2 = (u8)((u32)param_2 % 0x4d) % 7;
    if (bVar2 < 2) {
      uVar1 = f_8a34(param_2);
      f_63ce(param_1, uVar1, 6);  // FIX: pushed before the other call (Ghidra lost it)
    }
    if (4 < bVar2) {
      uVar1 = f_8a34(param_2);
      f_63ce(param_1, uVar1, 2);  // FIX: pushed before the other call (Ghidra lost it)
    }
    bVar2 = (u8)((u32)param_2 / 0x4d) % 7;
    if (bVar2 < 2) {
      uVar1 = f_8a34(param_2);
      f_63ce(param_1, uVar1, 0);  // FIX: pushed before the other call (Ghidra lost it)
    }
    if (4 < bVar2) {
      uVar1 = f_8a34(param_2);
      f_63ce(param_1, uVar1, 4);  // FIX: pushed before the other call (Ghidra lost it)
    }
  }
  return 0 /* AX? */;
}

// 1000:66B6 FUN_1000_66b6
static u8 f_66b6(void)

{
  FN(0x66B6);
  
  return *P8(*P8(0x3450) + 0x346e);
}

// 1000:66C4 FUN_1000_66c4
static u8 f_66c4(u8 param_1)

{
  FN(0x66C4);
  
  return *P8(param_1 + 0x348a);
}

// 1000:66D4 FUN_1000_66d4
static u8 f_66d4(u8 param_1)

{
  FN(0x66D4);
  
  return *P8(param_1 + 0x3494);
}

// 1000:66E4 FUN_1000_66e4
static u8 f_66e4(u8 param_1)

{
  FN(0x66E4);
  
  return *P8(param_1 + 0x349e);
}

// 1000:66F4 FUN_1000_66f4
static u16 f_66f4(void)

{
  FN(0x66F4);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P8(local_4 + 0x85fe) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:6714 FUN_1000_6714
static u16 f_6714(u8 param_1)

{
  FN(0x6714);
  u8 local_4;
  
  local_4 = 9;
  do {
    f_bf12(param_1, local_4 - 1);
    local_4 = local_4 - 1;
  } while (local_4 != 0);
  return 0 /* AX? */;
}

// 1000:673A FUN_1000_673a
static u16 f_673a(u8 param_1,u8 param_2)

{
  FN(0x673A);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_bd10(local_4, param_1, param_2);
    local_4 = local_4 + 1;
  } while (local_4 < 9);
  return 0 /* AX? */;
}

// 1000:6766 FUN_1000_6766
static u16 f_6766(u8 param_1)

{
  FN(0x6766);
  i16 iVar1;
  u16 uVar2;
  
  if ((param_1 != 0) || (*PS8(0xaeac) == '\0')) {
    iVar1 = f_7130();
    if ((iVar1 == 0) || (param_1 != 0)) {
      iVar1 = f_7122();
      if ((((iVar1 == 0) || (param_1 == 0)) && (*PS8(param_1 + 0x85fe) == '\0')) &&
         (*PS8(0x3558) == *PS8(0x759d))) {
        uVar2 = f_66b6();
        uVar2 = f_beea(uVar2);
        iVar1 = f_67ce(*P16(0x894e), uVar2);
        if (iVar1 != 0) {
          uVar2 = f_66b6();
          uVar2 = f_66c4(uVar2);
          return uVar2;
        }
      }
    }
  }
  return 0;
}

// 1000:67CE FUN_1000_67ce
static u16 f_67ce(u16 param_1,u16 param_2)

{
  FN(0x67CE);
  u8 uVar1;
  u8 uVar2;
  i16 iVar3;
  u8 uVar4;
  
  uVar1 = (u8)((u32)param_1 / 0x4d);
  uVar2 = (u8)((u32)param_2 / 0x4d);
  uVar4 = (u8)((u32)param_2 % 0x4d);
  iVar3 = f_1766((i8)((u32)param_1 % 0x4d), uVar4);
  if (iVar3 < 4) {
    iVar3 = f_1766(uVar1, uVar2);
    if (iVar3 < 4) {
      return 1;
    }
  }
  return 0;
}

// 1000:6836 FUN_1000_6836
static u16 f_6836(u8 param_1)

{
  FN(0x6836);
  u16 uVar1;
  u16 uVar2;
  
  if (*PS8(param_1 + 0x85fe) == '\x04') {
    return 1;
  }
  if ((*PS8(param_1 + 0x85fe) == '\x01') && (*PS8(0x3558) == *PS8(0x759d))) {
    uVar1 = f_8a34(*P16(0x894e));
    uVar2 = f_2276(uVar1);
    if (uVar2 == *P8(0x9b94)) {
      return 1;
    }
  }
  return 0;
}

// 1000:687E FUN_1000_687e
static u16 f_687e(void)

{
  FN(0x687E);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = f_66b6();
  iVar2 = f_66e4(uVar1);
  if (((iVar2 != 0) && (*PS8(0x34aa) == '\0')) && (*PS8(0x3558) == *PS8(0x759d))) {
    uVar1 = f_66b6();
    uVar1 = f_beea(uVar1);
    iVar2 = f_67ce(uVar1, *PS8(*P8(0x7596) + 0x3572) * 3 + *PS16(0x894e));  // FIX: pushed before the other call (Ghidra lost it)
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

// 1000:68D0 FUN_1000_68d0
static u16 f_68d0(u8 param_1)

{
  FN(0x68D0);
  u16 uVar1;
  u8 uVar2;
  i16 iVar3;
  
  *P8(0x759d) = *P8(0x3558);
  uVar1 = *P16(0x894e);
  *P16(0x8d26) = uVar1;
  uVar2 = f_8a34(uVar1);
  *P8(0x89fd) = uVar2;
  uVar2 = f_2276(uVar2);
  *P8(0x9b94) = uVar2;
  *P8(0x34a7) = 1;
  *P8(param_1 + 0x85fe) = 0;
  iVar3 = f_7122();
  if (iVar3 == 0) {
    if (*PS8(0x3450) == '\x10') {
      f_707e(param_1, 1);
    }
    iVar3 = f_7180();
    if (iVar3 != 0) {
      f_6988(6);
    }
  }
  else {
    if (*PS8(0x3450) == '\t') {
      f_707e(param_1, 1);
      f_71aa();
    }
    iVar3 = f_718e();
    if (iVar3 != 0) {
      f_707e(param_1, 4);
    }
    iVar3 = f_7180();
    if (iVar3 != 0) {
      f_6988(0);
      f_71aa();
    }
  }
  *P16((u16)param_1 * 2 + 0x74) = 0x1e;
  return 0 /* AX? */;
}

// 1000:6988 FUN_1000_6988
static u16 f_6988(u8 param_1)

{
  FN(0x6988);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  *P16(uVar1 * 2 + 0x74) = 0;
  *P8(uVar1 + 0x8b36) = 0;
  f_a440(uVar1);
  return f_707e(6, 6);  // FIX: called with one argument; the other is not used on this path (FUN_1000_7180 != 0)
}

// 1000:69B6 FUN_1000_69b6
static u16 f_69b6(u8 param_1)

{
  FN(0x69B6);
  u8 uVar1;
  u16 uVar2;
  
  uVar2 = f_66b6();
  f_befc(uVar2, 1);  // FIX: pushed before the other call (Ghidra lost it)
  uVar2 = f_66b6();
  f_beae(uVar2);
  uVar1 = f_66b6();
  *P8(param_1 + 0x85fe) = uVar1;
  *P16((u16)param_1 * 2 + 0x74) = 0x1e;
  return 0 /* AX? */;
}

// 1000:69EA FUN_1000_69ea
static u16 f_69ea(u8 param_1)

{
  FN(0x69EA);
  u16 uVar1;
  
  f_09a4();
  uVar1 = f_66b6();
  return f_69b6(param_1);
}

// 1000:6A02 FUN_1000_6a02
static u16 f_6a02(void)

{
  FN(0x6A02);
  u8 uVar1;
  
  *P8(0x34a8) = 0;
  *P8(0x34a9) = 0;
  *P8(0x34aa) = 0;
  if (*PS8(0x3450) == '\t') {
    *P8(0x85fe) = 1;
  }
  if (*PS8(0x3450) == '\x10') {
    *P8(0x8604) = 1;
  }
  uVar1 = f_7130();
  *P8(0x3434) = uVar1;
  return 0 /* AX? */;
}

// 1000:6A30 FUN_1000_6a30  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_6a30(void)

{
  FN(0x6A30);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_4 = '\0';
  local_6 = 1;
  do {
    iVar1 = f_6a64(local_6);
    if (iVar1 != 0) {
      local_4 = local_4 + '\x01';
    }
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  return local_4;
}

// 1000:6A64 FUN_1000_6a64
static u16 f_6a64(u8 param_1)

{
  FN(0x6A64);
  
  if ((*PS8(param_1 + 0xae6b) != '\0') && (*PS8(param_1 + 0x734c) != '\0')) {
    return 1;
  }
  return 0;
}

// 1000:6A82 FUN_1000_6a82  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_6a82(void)

{
  FN(0x6A82);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_6 = '\0';
  local_4 = 1;
  do {
    if (*PS8(local_4 + 0xae6b) != '\0') {
      iVar1 = f_6ac8((u16)local_4);
      if (iVar1 != 0) {
        local_6 = local_6 + '\x01';
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  if (local_6 != '\0') {
    f_c492();
  }
  return local_6;
}

// 1000:6AC8 FUN_1000_6ac8
static u8 f_6ac8(u8 param_1)

{
  FN(0x6AC8);
  i16 iVar1;
  
  iVar1 = f_6af2(0, param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return *P8(param_1 + 0x9d90);
}

// 1000:6AF2 FUN_1000_6af2
static u16 f_6af2(u8 param_1,u8 param_2)

{
  FN(0x6AF2);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = f_2276(*P8(param_1 + 0xae64));
  if (iVar1 != 0) {
    iVar1 = f_2276(*P8(param_2 + 0xae64));
    iVar2 = f_2276(*P8(param_1 + 0xae64));
    if (iVar2 == iVar1) {
      return 1;
    }
  }
  return 0;
}

// 1000:6B42 FUN_1000_6b42
static u16 f_6b42(u8 param_1,u8 param_2)

{
  FN(0x6B42);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = f_2276(param_2);
  iVar2 = f_2276(param_1);
  if (iVar2 == iVar1) {
    return 1;
  }
  return 0;
}

// 1000:6B70 FUN_1000_6b70
static u16 f_6b70(u8 param_1)

{
  FN(0x6B70);
  
  if ((*PS8(param_1 + 0xae6b) != '\0') && (*PS8(param_1 + 0x734c) == '\x02')) {
    return 1;
  }
  return 0;
}

// 1000:6B8E FUN_1000_6b8e  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_6b8e(void)

{
  FN(0x6B8E);
  i16 iVar1;
  u8 local_6;
  u8 local_4;
  
  local_4 = '\0';
  local_6 = 1;
  do {
    iVar1 = f_6b70(local_6);
    if (iVar1 != 0) {
      local_4 = local_4 + '\x01';
    }
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  return local_4;
}

// 1000:6BC2 FUN_1000_6bc2
static u16 f_6bc2(void)

{
  FN(0x6BC2);
  i16 iVar1;
  
  if (*PS8(0x34aa) == '\0') {
    switch(*P8(0x3450)) {
    case 2:
    case 3:
    case 4:
    case 0xc:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x17:
    case 0x18:
    case 0x1b:
      iVar1 = f_6a30();
      *(bool *)0x34aa = iVar1 == 0;
      break;
    case 7:
    case 8:
    case 0xb:
    case 0x14:
    case 0x19:
    case 0x1a:
      if (*PS8(0x85fe) == '\0') {
        *P8(0x34aa) = 0;
      }
      else {
        *P8(0x34aa) = 1;
      }
    }
    if ((*PS8(0x3450) == '\x14') && (iVar1 = f_6a30(), iVar1 == 0)) {
      *P8(0x34aa) = 1;
    }
  }
  return 0 /* AX? */;
}

// 1000:6C5C FUN_1000_6c5c
static u16 f_6c5c(void)

{
  FN(0x6C5C);
  u8 uVar1;
  u8 bVar2;
  u8 bVar3;
  i16 iVar4;
  u16 uVar5;
  i8 local_e;
  
  f_4e5c();
  iVar4 = f_055a();
  if (iVar4 != 1) {
    iVar4 = f_170e(100);
    if (9 < iVar4) {
      iVar4 = f_055a();
      if (iVar4 != 2) {
        iVar4 = f_170e(100);
        if (0x13 < iVar4) {
          local_e = '\x02';
          goto LAB_1000_6ca4;
        }
      }
      local_e = '\x01';
      goto LAB_1000_6ca4;
    }
  }
  local_e = '\0';
LAB_1000_6ca4:
  iVar4 = f_7130();
  if (iVar4 != 0) {
    local_e = f_055a();
    local_e = local_e + -1;
  }
  *PS8(0x3558) = local_e;
  if (*PS8(0x353a) == '\x02') {
    *P8(0x3558) = 0;
  }
  *P8(0x759d) = *P8(0x3558);
  do {
    iVar4 = f_7122();
    if (iVar4 == 0) {
LAB_1000_6cf4:
      uVar5 = 0x4d;
    }
    else {
      iVar4 = f_4e22();
      if (iVar4 == 0) goto LAB_1000_6cf4;
      if (*PS8(0x3558) == '\0') {
        iVar4 = f_170e(5);
        if (iVar4 != 0) goto LAB_1000_6cf4;
      }
      uVar5 = 0x9a;
    }
    uVar1 = f_170e(uVar5);
    iVar4 = f_6ed4(uVar1);
    if (iVar4 != 0) {
      f_2346(uVar1);
      bVar2 = f_c380(uVar1);
      bVar3 = f_c390(uVar1);
      *P8(0x89fd) = uVar1;
      uVar1 = f_2276(uVar1);
      *P8(0x9b94) = uVar1;
      *PS16(0x8d26) = ((u16)bVar2 * 7 + 3) * 0x4d + (u16)bVar3 * 7 + 3;
      uVar5 = f_66b6();
      f_be2e(uVar5, *P8(0x3558), *P16(0x8d26), 2);  // FIX: pushed before the other call (Ghidra lost it)
      iVar4 = f_7130();
      if (iVar4 != 0) {
        f_36ea();
      }
      return 0 /* AX? */;
    }
  } while( true );
  return 0 /* AX? */;
}

// 1000:6DA6 FUN_1000_6da6
static u16 f_6da6(void)

{
  FN(0x6DA6);
  u16 uVar1;
  
  if (*PS8(0x353a) == '\x01') {
    if (*PS8(0x3558) == '\0') {
      uVar1 = f_4bdc();
    }
    else {
      uVar1 = *P16((u16)*P8(0x3558) * 2 + 0x354a);
    }
    f_c722(3, uVar1);
  }
  if (*PS8(0x353a) == '\x02') {
    f_c722(3, *P8(0x893c));
  }
  return 0 /* AX? */;
}

// 1000:6DE8 FUN_1000_6de8
static u16 f_6de8(void)

{
  FN(0x6DE8);
  u8 bVar1;
  u8 bVar2;
  u8 uVar3;
  i16 iVar4;
  u8 local_e;
  u8 local_a;
  
  f_4e5c();
  *P8(0x7364) = *P8(0x759d);
  if (*PS8(0x3450) == '\x05') {
    *P8(0x7364) = 2;
  }
  *P8(0x3558) = *P8(0x7364);
  if (*PS8(0x3450) == '\x01') {
    local_e = *P8(0x89fd);
  }
  else {
    do {
      local_e = f_170e(0x9a);
      iVar4 = f_6f54(local_e);
    } while (iVar4 == 0);
  }
  f_2346(local_e);
  bVar1 = f_c380(local_e);
  bVar2 = f_c390(local_e);
  *P8(0xae06) = local_e;
  uVar3 = f_2276(local_e);
  *P8(0xae73) = uVar3;
  *PS16(0x9b72) = ((u16)bVar1 * 7 + 3) * 0x4d + (u16)bVar2 * 7 + 3;
  *P8(0x34ac) = 0;
  local_a = 1;
  do {
    iVar4 = f_5460(local_a);
    if (iVar4 != 0) {
      *P8(local_a + 0xae6b) = 0;
    }
    local_a = local_a + 1;
  } while (local_a < 7);
  return 0 /* AX? */;
}

// 1000:6ED4 FUN_1000_6ed4
static bool f_6ed4(u8 param_1)

{
  FN(0x6ED4);
  i16 iVar1;
  i16 iVar2;
  
  if (*PS8(0x353a) == '\x02') {
    iVar1 = f_2276(param_1);
    return iVar1 == 0;
  }
  iVar1 = f_7130();
  if ((iVar1 == 0) || (param_1 < 0x4e)) {
    iVar1 = f_2276(param_1);
    if (iVar1 != 0) {
      iVar1 = f_2276(*P16((u16)*P8(0x3558) * 2 + 0x354a));
      iVar2 = f_2276(param_1);
      if (iVar2 != iVar1) {
        iVar1 = f_2a6e(param_1);
        if (iVar1 == 0) {
          return true;
        }
      }
    }
  }
  return false;
}

// 1000:6F54 FUN_1000_6f54
static u16 f_6f54(u8 param_1)

{
  FN(0x6F54);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = f_2276(param_1);
  if (iVar1 != 0) {
    iVar1 = f_2276(*P16((u16)*P8(0x3558) * 2 + 0x354a));
    iVar2 = f_2276(param_1);
    if (iVar2 != iVar1) {
      iVar1 = f_2276(*P16((u16)*P8(0x3558) * 2 + 0x3544));
      iVar2 = f_2276(param_1);
      if (iVar2 != iVar1) {
        iVar1 = f_2a6e(param_1);
        if (iVar1 == 0) {
          iVar1 = f_6b42(param_1, *P8(0x89fd));
          if (iVar1 == 0) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// 1000:6FE0 FUN_1000_6fe0
static u16 f_6fe0(void)

{
  FN(0x6FE0);
  i16 iVar1;
  
  if (*PS8(0x3558) == *PS8(0x7364)) {
    iVar1 = f_0676();
    if (iVar1 != 0) {
      iVar1 = f_221c(*P8(0xae06));
      if (iVar1 != 0) {
        f_7004();
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:7004 FUN_1000_7004
static u16 f_7004(void)

{
  FN(0x7004);
  
  if (*PS8(0x3450) == '\x01') {
    if (*PS8(0x34aa) != '\0') {
      f_beae(5);
      return f_be2e(6, *P8(0x3558), *P16(0x9b72), 2);
    }
    if (*PS8(0x3434) == '\0') {
      return 0 /* AX? */;
    }
    f_beae(5);
    f_be2e(8, *P8(0x3558), *P16(0x9b72), 2);
  }
  f_be2e(3, *P8(0x3558), *P16(0x9b72), 2);
  *P8(0x34ac) = 1;
  return 0 /* AX? */;
}

// 1000:707E FUN_1000_707e
static u16 f_707e(u8 param_1,u8 param_2)

{
  FN(0x707E);
  u8 uVar1;
  i16 iVar2;
  u16 uVar3;
  u16 uVar4;
  
  iVar2 = f_7180();
  if (iVar2 == 0) {
    uVar3 = (u16)param_1;
    if (*PS8(uVar3 + 0x734c) == '\0') {
      iVar2 = *PS8(*P8(uVar3 + 0x7596) + 0x3572) * 3 + *PS16(uVar3 * 2 + -0x76b2);
    }
    else {
      iVar2 = *PS16((u16)param_1 * 2 + -0x76b2);
    }
    uVar4 = 2;
    uVar1 = *P8(0x3558);
  }
  else {
    f_08c4(0x14);
    f_beae(5);
    uVar4 = 2;
    iVar2 = f_beea(5);
    uVar1 = *P8(0x3558);
    param_2 = 6;
  }
  return f_be2e(param_2, uVar1, iVar2, uVar4);
  return 0 /* AX? */;
}

// 1000:7108 FUN_1000_7108
static u16 f_7108(i8 param_1)

{
  FN(0x7108);
  
  if ((*PS8(0x3450) == '\x06') && (param_1 == '\x06')) {
    return 1;
  }
  return 0;
}

// 1000:7122 FUN_1000_7122
static u8 f_7122(void)

{
  FN(0x7122);
  
  return *P8(*P8(0x3450) + 0x34ae);
}

// 1000:7130 FUN_1000_7130
static bool f_7130(void)

{
  FN(0x7130);
  i16 iVar1;
  
  iVar1 = f_7122();
  return iVar1 == 0;
}

// 1000:713E FUN_1000_713e
static u16 f_713e(i16 param_1)

{
  FN(0x713E);
  
  if ((*PS8(0x3450) == '\f') && (param_1 == 6)) {
    return 1;
  }
  return 0;
}

// 1000:7158 FUN_1000_7158
static u16 f_7158(i8 param_1)

{
  FN(0x7158);
  i16 iVar1;
  
  iVar1 = f_7172();
  if ((iVar1 != 0) && (param_1 == '\x06')) {
    return 1;
  }
  return 0;
}

// 1000:7172 FUN_1000_7172
static u8 f_7172(void)

{
  FN(0x7172);
  
  return *P8(*P8(0x3450) + 0x34ca);
}

// 1000:7180 FUN_1000_7180
static u8 f_7180(void)

{
  FN(0x7180);
  
  return *P8(*P8(0x3450) + 0x34e6);
}

// 1000:718E FUN_1000_718e
static u8 f_718e(void)

{
  FN(0x718E);
  
  return *P8(*P8(0x3450) + 0x3502);
}

// 1000:719C FUN_1000_719c
static u8 f_719c(void)

{
  FN(0x719C);
  
  return *P8(*P8(0x3450) + 0x351e);
}

// 1000:71AA FUN_1000_71aa
static u16 f_71aa(void)

{
  FN(0x71AA);
  
  *P8(0x34aa) = 1;
  return f_09a4();
}

// 1000:71B4 FUN_1000_71b4
static u16 f_71b4(void)

{
  FN(0x71B4);
  i16 iVar1;
  
  if (((*PS8(0x34aa) == '\0') && (*PS8(0x85fe) == '\0')) && (*PS8(0x8604) == '\0')) {
    iVar1 = f_6b8e();
    iVar1 = (iVar1 >> 1) + 1;
  }
  else {
    iVar1 = 4;
  }
  return f_098c(iVar1);
}

// 1000:71DC FUN_1000_71dc
static u16 f_71dc(void)

{
  FN(0x71DC);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P8(local_4 + 0x9ce9) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return 0 /* AX? */;
}

// 1000:71FC FUN_1000_71fc
static u16 f_71fc(void)

{
  FN(0x71FC);
  u8 bVar1;
  u8 local_4;
  
  bVar1 = *P8(0x3558);
  *P8(bVar1 + 0x9ce9) = 1;
  *P16((u16)bVar1 * 2 + -0x79fa) = *P16(0x894e);
  local_4 = 1;
  do {
    f_727a(local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:7238 FUN_1000_7238
static u16 f_7238(void)

{
  FN(0x7238);
  u8 local_4;
  
  local_4 = 1;
  do {
    f_734a(local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:725C FUN_1000_725c
static i16 f_725c(u8 param_1)

{
  FN(0x725C);
  
  return (u16)param_1 + (u16)*P8(0x3558) * 7;
}

// 1000:727A FUN_1000_727a
static u16 f_727a(u8 param_1)

{
  FN(0x727A);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = (u16)param_1;
  iVar2 = f_725c(uVar1);
  *P8(iVar2 + 0x7365) = *P8(uVar1 + 0xae6b);
  iVar2 = f_725c(uVar1);
  *P8(iVar2 + -0x7eea) = *P8(param_1 + 0x7596);
  iVar2 = f_725c((u16)param_1);
  *P8(iVar2 + -0x64a3) = *P8(param_1 + 0x734c);
  iVar2 = f_725c((u16)param_1);
  *P8(iVar2 + -0x6488) = *P8(param_1 + 0x8b36);
  iVar2 = f_725c((u16)param_1);
  *P8(iVar2 + 0x75e6) = *P8(param_1 + 0x9e18);
  iVar2 = f_725c((u16)param_1);
  *P8(iVar2 + -0x64b8) = *P8(param_1 + 0x7353);
  iVar2 = f_725c((u16)param_1);
  *P8(iVar2 + 0x7731) = *P8(param_1 + 0xae64);
  iVar2 = f_725c((u16)param_1);
  *P16(iVar2 * 2 + -0x7a98) = *P16((u16)param_1 * 2 + -0x76b2);
  return 0 /* AX? */;
}

// 1000:734A FUN_1000_734a
static u16 f_734a(u8 param_1)

{
  FN(0x734A);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_725c((u16)param_1);
  *P8(param_1 + 0xae6b) = *P8(iVar1 + 0x7365);
  uVar2 = (u16)param_1;
  if (*PS8(uVar2 + 0xae6b) != '\0') {
    iVar1 = f_725c(uVar2);
    *P8(uVar2 + 0xae64) = *P8(iVar1 + 0x7731);
    f_475e((u16)param_1, *P8(param_1 + 0xae64));
    iVar1 = f_725c((u16)param_1);
    *P8(param_1 + 0x7596) = *P8(iVar1 + -0x7eea);
    iVar1 = f_725c((u16)param_1);
    *P8(param_1 + 0x734c) = *P8(iVar1 + -0x64a3);
    iVar1 = f_725c((u16)param_1);
    *P8(param_1 + 0x8b36) = *P8(iVar1 + -0x6488);
    iVar1 = f_725c((u16)param_1);
    *P8(param_1 + 0x9e18) = *P8(iVar1 + 0x75e6);
    iVar1 = f_725c((u16)param_1);
    *P8(param_1 + 0x7353) = *P8(iVar1 + -0x64b8);
    iVar1 = f_725c((u16)param_1);
    *P8(param_1 + 0xae64) = *P8(iVar1 + 0x7731);
    iVar1 = f_725c((u16)param_1);
    *P16((u16)param_1 * 2 + -0x76b2) = *P16(iVar1 * 2 + -0x7a98);
    f_87e8(param_1);
    f_8824(param_1);
  }
  return 0 /* AX? */;
}

// 1000:7464 FUN_1000_7464
static i16 f_7464(void)

{
  FN(0x7464);
  i16 iVar1;
  
  if (*PS8(*P8(0x3558) + 0x9ce9) != '\0') {
    return (i16)*PS8(*P8(0x7d80) + 0x3572) + *PS16((u16)*P8(0x3558) * 2 + -0x79fa);
  }
  iVar1 = f_8a88(*P8(0xae64));
  return iVar1;
}

// 1000:7496 FUN_1000_7496
static u16 f_7496(void)

{
  FN(0x7496);
  bool bVar1;
  u8 bVar2;
  i16 iVar3;
  u16 uVar4;
  u16 uVar5;
  u8 local_c;
  u8 local_6;
  u8 local_4;
  
  *P8(0xaeac) = 0;
  local_4 = 0;
  local_c = 0xe;
  bVar1 = false;
  local_6 = 1;
  do {
    if (*PS8(local_6 + 0xae6b) != '\0') {
      iVar3 = f_7788(0, (u16)local_6);
      if (iVar3 != 0) {
        *P8(0xaeac) = 1;
        uVar4 = f_8986(0, local_6);
        if (uVar4 == *P8(0x7596)) {
          bVar1 = true;
        }
      }
      if (*PS8(local_6 + 0x9d90) != '\0') {
        uVar5 = f_75c4(0, (u16)local_6);
        local_c = f_1756(local_c, uVar5);
        uVar4 = f_75c4(0, local_6);
        if (uVar4 == local_c) {
          local_4 = local_6;
        }
      }
    }
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  if ((!bVar1) && (*PS8(0xaeac) != '\0')) {
    bVar2 = f_8986(0, local_4);
    *P8(0x7596) = bVar2 & 6;
  }
  if (*PS16(0x82) != 0) {
    return 0 /* AX? */;
  }
  if (*PS8(0x8b36) == '\x02') {
    if (8 < local_c) {
      return 0 /* AX? */;
    }
  }
  else {
    if (local_c < 0xe) {
      return 0 /* AX? */;
    }
    if ((*PS8(0x3450) != '\x1b') || (*PS8(0x3444) != '\0')) {
      if (*PS8(0x8b36) != '\0') {
        return 0 /* AX? */;
      }
      f_18b0(0);
      *P8(0x8b36) = 2;
      return 0 /* AX? */;
    }
  }
  if (*PS8(0x8b36) != '\x02') {
    return 0 /* AX? */;
  }
  f_18b0(0);
  *P8(0x8b36) = 0;
  return 0 /* AX? */;
}

// 1000:75C4 FUN_1000_75c4
static u16 f_75c4(u8 param_1,u8 param_2)

{
  FN(0x75C4);
  u8 bVar1;
  u8 bVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  
  bVar1 = f_1766(*P8(param_1 + 0x7776), *P8(param_2 + 0x7776));
  bVar2 = f_1766(*P8(param_1 + 0x79ee), *P8(param_2 + 0x79ee));
  if ((bVar1 < 0xf) && (bVar2 < 0xf)) {
    iVar3 = f_1a26(0xd);
    iVar4 = f_1a26(bVar2);
    iVar5 = f_1a26(bVar1);
    if (iVar5 + iVar4 <= iVar3) {
      iVar3 = f_1a26(0xc);
      iVar4 = f_1a26(bVar2);
      iVar5 = f_1a26(bVar1);
      if (iVar3 < iVar5 + iVar4) {
        return 0xd;
      }
      iVar3 = f_1a26(0xb);
      iVar4 = f_1a26(bVar2);
      iVar5 = f_1a26(bVar1);
      if (iVar3 < iVar5 + iVar4) {
        return 0xc;
      }
      iVar3 = f_1a26(10);
      iVar4 = f_1a26(bVar2);
      iVar5 = f_1a26(bVar1);
      if (iVar3 < iVar5 + iVar4) {
        return 0xb;
      }
      iVar3 = f_1a26(9);
      iVar4 = f_1a26(bVar2);
      iVar5 = f_1a26(bVar1);
      if (iVar5 + iVar4 <= iVar3) {
        iVar3 = f_1a26(8);
        iVar4 = f_1a26(bVar2);
        iVar5 = f_1a26(bVar1);
        if (iVar5 + iVar4 <= iVar3) {
          return 8;
        }
        return 9;
      }
      return 10;
    }
  }
  return 0xe;
}

// 1000:775C FUN_1000_775c
static u16 f_775c(u8 param_1,u8 param_2)

{
  FN(0x775C);
  u16 uVar1;
  
  uVar1 = f_8986((u16)param_1, param_2);
  if (*P8(param_1 + 0x7596) == uVar1) {
    return 1;
  }
  return 0;
}

// 1000:7788 FUN_1000_7788
static u16 f_7788(u16 param_1,u8 param_2)

{
  FN(0x7788);
  u8 bVar1;
  u8 bVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  
  if (*PS8(param_2 + 0x9d90) != '\0') {
    bVar1 = f_1766(*P8(0x7776), *P8(param_2 + 0x7776));
    bVar2 = f_1766(*P8(0x79ee), *P8(param_2 + 0x79ee));
    if ((bVar1 < 9) && (bVar2 < 9)) {
      iVar3 = f_1a26(8);
      iVar4 = f_1a26(bVar2);
      iVar5 = f_1a26(bVar1);
      if (iVar5 + iVar4 <= iVar3) {
        return 1;
      }
    }
  }
  return 0;
}

// 1000:7816 FUN_1000_7816
static u16 f_7816(u8 param_1,u8 param_2)

{
  FN(0x7816);
  u8 bVar1;
  u8 bVar2;
  u16 uVar3;
  i16 iVar4;
  i16 iVar5;
  i16 iVar6;
  
  uVar3 = f_7c38();
  bVar1 = f_1766(uVar3 % 0x4d, *P8(param_2 + 0x7776));
  bVar2 = f_1766(uVar3 / 0x4d, *P8(param_2 + 0x79ee));
  if ((bVar1 <= param_1) && (bVar2 <= param_1)) {
    iVar4 = f_1a26(param_1);
    iVar5 = f_1a26(bVar2);
    iVar6 = f_1a26(bVar1);
    if (iVar6 + iVar5 <= iVar4) {
      return 1;
    }
  }
  return 0;
}

// 1000:78B4 FUN_1000_78b4
static u16 f_78b4(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x78B4);
  u8 bVar1;
  u8 bVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  
  bVar1 = f_1766(*P8(param_2 + 0x7776), *P8(param_3 + 0x7776));
  bVar2 = f_1766(*P8(param_2 + 0x79ee), *P8(param_3 + 0x79ee));
  if ((bVar1 <= param_1) && (bVar2 <= param_1)) {
    iVar3 = f_1a26(param_1);
    iVar4 = f_1a26(bVar2);
    iVar5 = f_1a26(bVar1);
    if (iVar5 + iVar4 <= iVar3) {
      return 1;
    }
  }
  return 0;
}

// 1000:7942 FUN_1000_7942
static u16 f_7942(u8 param_1)

{
  FN(0x7942);
  return f_775c(param_1, 0);
}

// 1000:7956 FUN_1000_7956
static u16 f_7956(u8 param_1)

{
  FN(0x7956);
  return f_775c(0, param_1);
}

// 1000:796A FUN_1000_796a
static u16 f_796a(u8 param_1)

{
  FN(0x796A);
  u8 uVar1;
  
  uVar1 = f_7990((u16)param_1);
  *P8(param_1 + 0x8134) = uVar1;
  return f_8824(param_1);
}

// 1000:7990 FUN_1000_7990
static u16 f_7990(u8 param_1)

{
  FN(0x7990);
  u16 uVar1;
  i16 iVar2;
  
  if (*PS8(param_1 + 0x85fe) == '\x04') {
    return 5;
  }
  if (*PS16((u16)param_1 * 2 + 0x74) == 0) {
    if (param_1 == 0) {
      iVar2 = f_79f0();
      if (iVar2 != 0) {
        return 1;
      }
    }
    else {
      uVar1 = (u16)param_1;
      if (((*PS8(uVar1 + 0x9d90) != '\0') && (*PS8(uVar1 + 0x734c) != '\x03')) &&
         (iVar2 = f_af0c(uVar1), iVar2 == 0)) {
        return 1;
      }
    }
  }
  return 0;
}

// 1000:79F0 FUN_1000_79f0
static u8 f_79f0(void)

{
  FN(0x79F0);
  u16 uVar1;
  i16 iVar2;
  u8 local_6;
  u8 local_4;
  
  local_4 = 0;
  for (local_6 = 1; local_6 < 7; local_6 = local_6 + 1) {
    uVar1 = (u16)local_6;
    if ((((*PS8(uVar1 + 0xae6b) != '\0') && (*PS8(uVar1 + 0x9d90) != '\0')) &&
        (iVar2 = f_b706(uVar1), iVar2 != 0)) &&
       (((iVar2 = f_7956(local_6), iVar2 != 0 || (*PS8(0x8b36) == '\0')) &&
        ((*PS8(local_6 + 0x9e24) == '\0' || (*PS8(local_6 + 0x9b8d) != '\0')))))) {
      local_4 = 1;
    }
  }
  return local_4;
}

// 1000:7A66 FUN_1000_7a66
static u16 f_7a66(u8 param_1)

{
  FN(0x7A66);
  i8 cVar1;
  
  cVar1 = *PS8(param_1 + 0x9d86);
  if (cVar1 == '\0') {
    return 0 /* AX? */;
  }
  if (cVar1 == '\x01') {
    f_7ae0(param_1);
  }
  else {
    if (cVar1 != '\b') {
      if (cVar1 == '\t') {
        f_0948(param_1);
      }
      else if (cVar1 == '\n') {
        f_a5c6(param_1);
      }
      else if (cVar1 == '\x10') {
        return f_7bd4(param_1);
      }
      *PS8(param_1 + 0x9d86) = *PS8(param_1 + 0x9d86) + '\x01';
      return 0 /* AX? */;
    }
    f_7b4e(param_1);
  }
  return 0 /* AX? */;
}

// 1000:7AE0 FUN_1000_7ae0
static u16 f_7ae0(u8 param_1)

{
  FN(0x7AE0);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  *P8(uVar1 + 0x8134) = 2;
  if (*PS8(uVar1 + 0x8b36) == '\x04') {
    f_a58c(uVar1);
  }
  if ((param_1 != 0) && (*PS8(param_1 + 0xae3e) == '\0')) {
    *PS8(param_1 + 0x9d86) = *PS8(param_1 + 0x9d86) + '\x01';
    return 0 /* AX? */;
  }
  *P8(param_1 + 0x9d86) = 8;
  return f_7b4e((u16)param_1);
}

// 1000:7B32 FUN_1000_7b32
static u8 f_7b32(u8 param_1)

{
  FN(0x7B32);
  u8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = *P8(0x7766);
  }
  else {
    uVar1 = *P8(param_1 + 0x8b36);
  }
  return uVar1;
}

// 1000:7B4E FUN_1000_7b4e
static u16 f_7b4e(u8 param_1)

{
  FN(0x7B4E);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = (u16)param_1;
  if (*PS8(uVar1 + 0x8b36) == '\x04') {
    if (*PS16(uVar1 * 2 + 0x74) != 0) {
      return 0 /* AX? */;
    }
    *P8(uVar1 + 0x8134) = 3;
    f_0ea8(uVar1);
  }
  else {
    *P8(param_1 + 0x8134) = 3;
    iVar2 = f_7b32((u16)param_1);
    if (((iVar2 == 2) && (f_0e64(param_1), param_1 == 0)) && (*PS8(0x3450) == '\x1b')) {
      *PS8(0x3444) = *PS8(0x3444) + -1;
    }
    iVar2 = f_7b32(param_1);
    if (iVar2 == 3) {
      f_0e86(param_1);
    }
  }
  *PS8(param_1 + 0x9d86) = *PS8(param_1 + 0x9d86) + '\x01';
  return 0 /* AX? */;
}

// 1000:7BD4 FUN_1000_7bd4
static u16 f_7bd4(u8 param_1)

{
  FN(0x7BD4);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  *P8(uVar1 + 0x8134) = 0;
  if (*PS8(uVar1 + 0xae3e) != '\0') {
    *P8(uVar1 + 0xae3e) = 0;
  }
  *P8(param_1 + 0x9b06) = 0;
  *P8(param_1 + 0x9d86) = 0;
  if (((param_1 == 0) && (*PS8(0x3444) == '\0')) && (*PS8(0x3450) == '\x1b')) {
    *P8(0x8b36) = 0;
  }
  return 0 /* AX? */;
}

// 1000:7C16 FUN_1000_7c16
static u16 f_7c16(u16 param_1)

{
  FN(0x7C16);
  
  *P16(0x894e) = param_1;
  *P16((u16)*P8(0x358a) * 2 + 0x357a) = param_1;
  *P8(0x358a) = *PS8(0x358a) + 1U & 7;
  return 0 /* AX? */;
}

// 1000:7C38 FUN_1000_7c38
static u16 f_7c38(void)

{
  FN(0x7C38);
  
  return *P16((((u16)*P8(0x358a) + (u16)*P8(0x355c)) - 7 & 7) * 2 + 0x357a);
}

// 1000:7C54 FUN_1000_7c54
static u16 f_7c54(u8 param_1)

{
  FN(0x7C54);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  *P16(uVar1 * 2 + 0x7768) = 0;
  if (*PS8(uVar1 + 0xae4c) != '\0') {
    *P8(uVar1 + 0xae4c) = 0;
    return 0 /* AX? */;
  }
  *P8(param_1 + 0xae4c) = 1;
  return 0 /* AX? */;
}

// 1000:7C84 FUN_1000_7c84  FIX: returns the turned direction (Ghidra lost the callees' AX)
static u16 f_7c84(u8 param_1,u8 param_2)

{
  FN(0x7C84);
  
  if (*PS8(param_1 + 0xae4c) == '\0') {
    return f_1c46(param_2);
  }
  return f_1c56(param_2);
}

// 1000:7CAC FUN_1000_7cac
static u16 f_7cac(u8 param_1)

{
  FN(0x7CAC);
  i16 iVar1;
  
  iVar1 = f_869e(param_1);
  if (iVar1 != 0) {
    f_7ce2(param_1);
  }
  return f_ab12((u16)param_1, *P8(param_1 + 0x7596));
  return 0 /* AX? */;
}

// 1000:7CE2 FUN_1000_7ce2
static u16 f_7ce2(u8 param_1)

{
  FN(0x7CE2);
  
  if (*PS8(param_1 + 0xae4c) != '\0') {
    return f_7d0e((u16)param_1);
  }
  return f_7d6e(param_1);
}

// 1000:7D0E FUN_1000_7d0e
static u16 f_7d0e(u8 param_1)

{
  FN(0x7D0E);
  u8 uVar1;
  i16 iVar2;
  u8 local_4;
  
  uVar1 = f_1c56(*P8(param_1 + 0x7596));
  *P8(param_1 + 0x7596) = uVar1;
  local_4 = '\x04';
  while( true ) {
    iVar2 = f_5aca((u16)param_1, *P8(param_1 + 0x7596));
    if ((iVar2 == 0) || (local_4 == '\0')) break;
    local_4 = local_4 + -1;
    uVar1 = f_1c46(*P8(param_1 + 0x7596));
    *P8(param_1 + 0x7596) = uVar1;
  }
  return 0 /* AX? */;
}

// 1000:7D6E FUN_1000_7d6e
static u16 f_7d6e(u8 param_1)

{
  FN(0x7D6E);
  u8 uVar1;
  i16 iVar2;
  u8 local_4;
  
  uVar1 = f_1c46(*P8(param_1 + 0x7596));
  *P8(param_1 + 0x7596) = uVar1;
  local_4 = '\x04';
  while( true ) {
    iVar2 = f_5aca((u16)param_1, *P8(param_1 + 0x7596));
    if ((iVar2 == 0) || (local_4 == '\0')) break;
    local_4 = local_4 + -1;
    uVar1 = f_1c56(*P8(param_1 + 0x7596));
    *P8(param_1 + 0x7596) = uVar1;
  }
  return 0 /* AX? */;
}

// 1000:7DCE FUN_1000_7dce
static u16 f_7dce(u8 param_1)

{
  FN(0x7DCE);
  u16 uVar1;
  u8 bVar2;
  u8 bVar3;
  
  uVar1 = (u16)param_1;
  bVar2 = *P8(uVar1 + 0x7776) % 7;
  bVar3 = *P8(uVar1 + 0x79ee) % 7;
  if (((((*PS8(uVar1 + 0x7596) != '\0') || (bVar3 == 0)) &&
       ((*PS8(param_1 + 0x7596) != '\x02' || (2 < bVar2)))) &&
      ((*PS8(param_1 + 0x7596) != '\x04' || (2 < bVar3)))) &&
     ((*PS8(param_1 + 0x7596) != '\x06' || (bVar2 < 4)))) {
    return 0;
  }
  return 1;
}

// 1000:7E44 FUN_1000_7e44
static u16 f_7e44(u8 param_1)

{
  FN(0x7E44);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_2276(*P8(param_1 + 0xae64));
  if (iVar1 == 0) {
    uVar2 = *P16((u16)param_1 * 2 + 0x7768);
    if (uVar2 % 100 != 0) {
      return uVar2 / 100;
    }
    uVar2 = f_170e(8);
    if (uVar2 != 0) {
      return uVar2;
    }
  }
  else {
    uVar2 = *P16((u16)param_1 * 2 + 0x7768);
    if (uVar2 % 0x14 != 0) {
      return uVar2 / 0x14;
    }
    iVar1 = f_170e(2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = f_7c54(param_1);
  return uVar2;
}

// 1000:7EB6 FUN_1000_7eb6
static bool f_7eb6(u16 param_1)

{
  FN(0x7EB6);
  i16 iVar1;
  
  iVar1 = f_a0dc(param_1);
  return iVar1 == 0;
}

// 1000:7ECE FUN_1000_7ece  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static bool f_7ece(u8 param_1,i16 param_2,u8 param_3)

{
  FN(0x7ECE);
  u16 uVar1;
  i16 iVar2;
  
  if ((param_1 != '\0') && (*PS8(0x353a) == '\x01')) {
    uVar1 = f_8a34(*PS8(param_3 + 0x3572) + param_2);
    iVar2 = f_1658(param_1, uVar1);
    if (iVar2 != 0) {
      return false;
    }
  }
  iVar2 = f_7eb6(*PS8(param_3 + 0x3572) + param_2);
  return iVar2 == 0;
}

// 1000:7F28 FUN_1000_7f28
static i16 f_7f28(i16 param_1,i16 param_2)

{
  FN(0x7F28);
  u8 bVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    bVar1 = *P8(param_1 + 0x79ee);
joined_r0x00017f4c:
    if (3 < bVar1) {
      return 0;
    }
  }
  else {
    if (param_2 == 2) {
      bVar2 = *P8(param_1 + 0x7776) < 0x4a;
    }
    else {
      if (param_2 != 4) {
        if (param_2 != 6) {
          return param_2;
        }
        bVar1 = *P8(param_1 + 0x7776);
        goto joined_r0x00017f4c;
      }
      bVar2 = *P8(param_1 + 0x79ee) < 0x5f;
    }
    if (bVar2) {
      return 0;
    }
  }
  return 1;
}

// 1000:7F78 FUN_1000_7f78
static u16 f_7f78(u8 param_1,u8 param_2)

{
  FN(0x7F78);
  i16 iVar1;
  u16 uVar2;
  
  if ((param_1 == 0) || (*PS8(0x353a) == '\x01')) {
    iVar1 = f_7eb6((i16)*PS8(param_2 + 0x3572) + *PS16((u16)param_1 * 2 + -0x76b2));
    if (iVar1 != 0) {
      uVar2 = (u16)param_1;
      if (*PS8(uVar2 + 0x3568) != '\0') {
        return f_8040(param_1, param_2);
      }
      *P16(uVar2 * 2 + 0xac) = 0x1e;
      *P8(uVar2 + 0x3568) = 1;
      return 0 /* AX? */;
    }
  }
  else if ((*PS8(0x353a) != '\x01') && (iVar1 = f_7f28(param_1, param_2), iVar1 != 0)) {
    return f_8014(param_1);
  }
  return f_81a2(param_1, param_2);
}

// 1000:8014 FUN_1000_8014
static u16 f_8014(i16 param_1)

{
  FN(0x8014);
  i16 iVar1;
  
  iVar1 = f_7108(param_1);
  if (iVar1 == 0) {
    f_aa12(param_1, 4);
    *PS8(0x7340) = *PS8(0x7340) + '\x01';
    *P8(param_1 + 0x757e) = 2;
  }
  return 0 /* AX? */;
}

// 1000:8040 FUN_1000_8040
static u16 f_8040(u8 param_1,u8 param_2)

{
  FN(0x8040);
  u8 bVar1;
  u8 uVar2;
  i16 iVar3;
  u8 local_8;
  u8 local_6;
  
  if ((param_1 != 0) && (iVar3 = f_8462(param_1), iVar3 != 0)) {
    return f_8014(param_1);  // FIX: called without its argument, which is then the SI saved above: the caller's (1000:7FD0), param_1
  }
  bVar1 = f_1766(*P8(param_1 + 0x7596), param_2);
  if ((2 < bVar1) && (bVar1 < 6)) {
    uVar2 = f_1c36(*P8(param_1 + 0x7596));
    *P8(param_1 + 0x7596) = uVar2;
  }
  if ((param_2 & 1) == 0) {
    iVar3 = f_3064(param_1, param_2);
    if (iVar3 == 0) {
      return 0 /* AX? */;
    }
    if ((param_1 == 0) && (*PS16(0xac) != 0)) {
      return 0 /* AX? */;
    }
    *P8(param_1 + 0x7596) = param_2;
    iVar3 = f_4e22();
    if (iVar3 != 0) {
      f_08c4(4);
    }
    f_6006(*P8(param_1 + 0xae64), param_2);
    local_6 = param_2;
    if (*PS8(0x8b32) != '\0') {
      return 0 /* AX? */;
    }
    goto LAB_1000_818f;
  }
  if (param_2 == 1) {
    local_6 = 2;
LAB_1000_80c8:
    local_8 = 0;
  }
  else {
    if (param_2 == 3) {
      local_6 = 2;
    }
    else {
      if (param_2 != 5) {
        if (param_2 == 7) {
          local_6 = 6;
          goto LAB_1000_80c8;
        }
        goto LAB_1000_80cc;
      }
      local_6 = 6;
    }
    local_8 = 4;
  }
LAB_1000_80cc:
  iVar3 = f_7eb6((i16)*PS8(local_6 + 0x3572) + *PS16((u16)param_1 * 2 + -0x76b2));
  if ((iVar3 != 0) &&
     (iVar3 = f_7eb6((i16)*PS8(local_8 + 0x3572) + *PS16((u16)param_1 * 2 + -0x76b2)), local_6 = local_8, iVar3 != 0)) {
    return 0 /* AX? */;
  }
LAB_1000_818f:
  return f_81a2(param_1, local_6);
}

// 1000:81A2 FUN_1000_81a2
static u16 f_81a2(u8 param_1,u8 param_2)

{
  FN(0x81A2);
  i16 iVar1;
  u16 uVar2;
  u8 local_4;
  
  *P8(param_1 + 0x3568) = 0;
  iVar1 = f_59c2((u16)param_1, param_2);
  if (iVar1 == 0) {
    *P8(param_1 + 0x7596) = param_2 & 6;
  }
  else {
    uVar2 = (u16)param_1;
    if (*P8(uVar2 + 0x7786) < 8) {
      *P8(uVar2 + 0x7596) = *P8(uVar2 + 0x7786) & 6;
    }
    if (param_1 == 0) {
      local_4 = 1;
      do {
        uVar2 = (u16)local_4;
        if (((*PS8(uVar2 + 0xae6b) != '\0') && (*PS8(0xae64) == *PS8(uVar2 + 0xae64)))
           && (uVar2 = f_8986(0, uVar2), uVar2 == param_2)) {
          *P8(0x7596) = param_2 & 6;
        }
        local_4 = local_4 + 1;
      } while (local_4 < 7);
    }
  }
  return f_8654(param_1, param_2);
}

// 1000:8250 FUN_1000_8250
static u16 f_8250(u8 param_1,u8 param_2)

{
  FN(0x8250);
  i16a *piVar1;
  u8 uVar2;
  u16 uVar3;
  
  uVar3 = (u16)param_1;
  *P8(uVar3 + 0x7d80) = param_2;
  *P8(uVar3 + 0xaefc) = 4;
  *P8(uVar3 + 0xade4) = *P8(uVar3 + 0xae64);
  uVar2 = f_2276(*P8(uVar3 + 0xae64));
  *P8(uVar3 + 0x778e) = uVar2;
  uVar3 = (u16)param_1;
  piVar1 = PS16(uVar3 * 2 + -0x76b2);
  *piVar1 = *piVar1 + (i16)*PS8(param_2 + 0x3572);
  uVar2 = f_8a72(uVar3);
  *P8(uVar3 + 0xae64) = uVar2;
  f_87e8(param_1);
  return f_831a(param_1);
}

// 1000:82BE FUN_1000_82be
static u16 f_82be(u8 param_1)

{
  FN(0x82BE);
  
  if (*PS8(param_1 + 0xae64) != *PS8(param_1 + 0xade4)) {
    return 1;
  }
  return 0;
}

// 1000:82E0 FUN_1000_82e0
static u16 f_82e0(u8 param_1)

{
  FN(0x82E0);
  i16 iVar1;
  i16 iVar2;
  
  iVar1 = f_2276(*P8(param_1 + 0xade4));
  iVar2 = f_2276(*P8(param_1 + 0xae64));
  if (iVar2 != iVar1) {
    return 1;
  }
  return 0;
}

// 1000:831A FUN_1000_831a
static u16 f_831a(u8 param_1)

{
  FN(0x831A);
  i8a *pcVar1;
  i8 cVar2;
  i16 iVar3;
  
  iVar3 = f_82be(param_1);
  if (iVar3 != 0) {
    if (param_1 != 0) {
      iVar3 = f_82e0(param_1);
      if (iVar3 != 0) {
        *P16((u16)param_1 * 2 + 0xd6) = 0xf0;
      }
      cVar2 = f_2276(*P8(param_1 + 0xae64));
      if (cVar2 != '\0') {
        if (*PS8(param_1 + 0x778e) == cVar2) {
          pcVar1 = PS8(param_1 + 0x9d97);
          *pcVar1 = *pcVar1 + '\x01';
        }
        else {
          *P8(param_1 + 0x9d97) = 1;
        }
      }
      f_83ac(param_1);
    }
    f_85e2(param_1);
  }
  return 0 /* AX? */;
}

// 1000:83AC FUN_1000_83ac
static u16 f_83ac(u8 param_1)

{
  FN(0x83AC);
  i16 iVar1;
  
  iVar1 = f_c74c(param_1);
  if (iVar1 != 0) {
    f_849a(param_1);
  }
  return 0 /* AX? */;
}

// 1000:83CE FUN_1000_83ce
static u16 f_83ce(u8 param_1)

{
  FN(0x83CE);
  i16 iVar1;
  
  iVar1 = f_83fa(param_1);
  if (iVar1 == 0) {
    iVar1 = f_4252(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 4;
}

// 1000:83FA FUN_1000_83fa
static u16 f_83fa(i16 param_1)

{
  FN(0x83FA);
  u16 uVar1;
  
  if (*PS8(0x3558) == '\0') {
    uVar1 = f_4bdc();
    if (*P8(param_1 + -0x519c) == uVar1) {
      return 1;
    }
  }
  return 0;
}

// 1000:841E FUN_1000_841e
static u16 f_841e(u8 param_1)

{
  FN(0x841E);
  i16 iVar1;
  
  if (*PS8(0x353a) != '\x01') {
    return 0;
  }
  iVar1 = f_4252(param_1);
  if (((iVar1 == 0) && (iVar1 = f_4228(param_1), iVar1 == 0)) &&
     (iVar1 = f_83fa(param_1), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

// 1000:8462 FUN_1000_8462
static u16 f_8462(u8 param_1)

{
  FN(0x8462);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_841e(param_1);
  if (iVar1 != 0) {
    uVar2 = f_83ce((u16)param_1);
    if (*P8(param_1 + 0x7596) == uVar2) {
      return 1;
    }
  }
  return 0;
}

// 1000:849A FUN_1000_849a
static u16 f_849a(u8 param_1)

{
  FN(0x849A);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_7108(param_1);
  if (iVar1 != 0) {
    f_b84c(param_1, 0);
    f_aa12(param_1, 1);
  }
  iVar1 = f_7158(param_1);
  if (iVar1 == 0) {
    uVar2 = (u16)param_1;
    if (*PS8(uVar2 + 0x734c) == '\x02') {
      if (*PS8(uVar2 + 0x9d90) == '\0') {
        return f_aa12(uVar2, 1);
      }
    }
    else {
      f_8580(param_1);
    }
  }
  else {
    iVar1 = f_841e(param_1);
    if (iVar1 != 0) {
      *P8(0x34ab) = 1;
      return f_a864();
    }
    if ((*PS8(0x3450) == '\x0f') || (*PS8(0x3450) == '\x10')) {
      f_68d0(param_1);
      f_b84c(param_1, 3);
    }
    if ((*PS8(0x3450) == '\r') || (*PS8(0x3450) == '\x0e')) {
      f_69ea(param_1);
      return f_b84c(param_1, 3);
    }
  }
  return 0 /* AX? */;
}

// 1000:8580 FUN_1000_8580
static u16 f_8580(u8 param_1)

{
  FN(0x8580);
  i16 iVar1;
  u16 uVar2;
  
  if ((param_1 == 0) || (iVar1 = f_841e(param_1), iVar1 == 0)) {
    if (*PS8(0x353a) == '\x01') {
      return 0 /* AX? */;
    }
    iVar1 = f_ad2c(*P8(param_1 + 0xae64));
    if (iVar1 == 0) {
      return 0 /* AX? */;
    }
    uVar2 = f_ad7a(*P8(param_1 + 0xae64));
  }
  else {
    uVar2 = f_83ce(param_1);
  }
  return f_ab12(param_1, uVar2);
}

// 1000:85E2 FUN_1000_85e2
static u16 f_85e2(u8 param_1)

{
  FN(0x85E2);
  i16 iVar1;
  
  iVar1 = f_2696(*P8(param_1 + 0xae64));
  if (iVar1 == 0) {
    return 0 /* AX? */;
  }
  if (((param_1 != 0) && (iVar1 = f_7130(), iVar1 != 0)) ||
     ((param_1 == 0 && (iVar1 = f_7122(), iVar1 != 0)))) {
    f_08c4(0x20);
  }
  if ((param_1 == 0) && (iVar1 = f_7122(), iVar1 != 0)) {
    f_3d1a();
    if (*PS8(0x3434) == '\0') {
      return f_c722(0, *P8(0xae64));
    }
    f_c492();
  }
  return 0 /* AX? */;
}

// 1000:8654 FUN_1000_8654
static u16 f_8654(u8 param_1,u8 param_2)

{
  FN(0x8654);
  i16 iVar1;
  
  iVar1 = f_599a(param_1, param_2);
  if (iVar1 == 0) {
    iVar1 = f_7ece((u16)param_1, *P16((u16)param_1 * 2 + -0x76b2), param_2);
    if (iVar1 != 0) {
      f_8250(param_1, param_2);
    }
  }
  return 0 /* AX? */;
}

// 1000:869E FUN_1000_869e
static i8 f_869e(u8 param_1)

{
  FN(0x869E);
  i8 cVar1;
  u8 bVar2;
  i16 iVar3;
  u16 uVar4;
  u8 bVar5;
  u8 bVar6;
  
  iVar3 = f_5950((u16)param_1, *P8(param_1 + 0x7d80));
  if (iVar3 == 0) {
    uVar4 = (u16)param_1;
    bVar5 = *P8(uVar4 + 0x7776) % 7;
    bVar6 = *P8(uVar4 + 0x79ee) % 7;
    iVar3 = f_59c2(uVar4, *P8(uVar4 + 0x7d80));
    if (iVar3 == 0) {
      cVar1 = *PS8(param_1 + 0x7d80);
      bVar2 = bVar6;
      if ((((cVar1 != '\0') && (bVar2 = bVar5, cVar1 != '\x02')) && (bVar2 = bVar6, cVar1 != '\x04')
          ) && (bVar2 = bVar5, cVar1 != '\x06')) {
        return cVar1;
      }
      if (bVar2 != 3) {
        return '\0';
      }
    }
    else {
      cVar1 = *PS8(param_1 + 0x7d80);
      if (cVar1 != '\0') {
        bVar2 = bVar5;
        if ((cVar1 == '\x02') || (bVar2 = bVar6, cVar1 == '\x04')) {
          if (2 < bVar2) {
            return '\x01';
          }
          return '\0';
        }
        bVar6 = bVar5;
        if (cVar1 != '\x06') {
          return cVar1;
        }
      }
      if (3 < bVar6) {
        return '\0';
      }
    }
  }
  return '\x01';
}

// 1000:876E FUN_1000_876e
static u16 f_876e(u8 param_1)

{
  FN(0x876E);
  i8a *pcVar1;
  u16 uVar2;
  
  uVar2 = (u16)param_1;
  pcVar1 = PS8(uVar2 + 0xaefc);
  *pcVar1 = *pcVar1 - *PS8(0x3564);
  if (*pcVar1 == '\0') {
    *P8(uVar2 + 0x8bd8) = *PS8(uVar2 + 0x8bd8) + 1U & 3;
  }
  return f_879e(param_1);
}

// 1000:879E FUN_1000_879e
static u16 f_879e(u8 param_1)

{
  FN(0x879E);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = (u16)param_1;
  if (*PS8(uVar1 + 0xaefc) == '\0') {
    iVar2 = f_7ece(uVar1, *P16(uVar1 * 2 + -0x76b2), *P8(uVar1 + 0x7d80));
    if (iVar2 == 0) {
      *P8(param_1 + 0x7786) = *P8(param_1 + 0x7596);
      return 0 /* AX? */;
    }
    *P8(param_1 + 0x7786) = 8;
  }
  return 0 /* AX? */;
}

// 1000:87E8 FUN_1000_87e8
static u16 f_87e8(u8 param_1)

{
  FN(0x87E8);
  u16 uVar1;
  u16 uVar2;
  
  uVar2 = (u16)param_1;
  uVar1 = *P16(uVar2 * 2 + -0x76b2);
  *P8(uVar2 + 0x79ee) = (i8)((u32)uVar1 / 0x4d);
  *P8(uVar2 + 0x7776) = (i8)((u32)uVar1 % 0x4d);
  return uVar1 / 0x4d;
}

// 1000:8824 FUN_1000_8824
static u16 f_8824(u8 param_1)

{
  FN(0x8824);
  i16a *piVar1;
  u16 uVar2;
  u8 bVar3;
  i16 iVar4;
  i16 local_4;
  
  uVar2 = (u16)param_1;
  iVar4 = uVar2 * 2;
  *P8(uVar2 + 0x79ee) = (i8)((u32)*P16(iVar4 + -0x76b2) / 0x4d);
  bVar3 = (u8)((u32)*P16(iVar4 + -0x76b2) % 0x4d);
  *P8(uVar2 + 0x7776) = bVar3;
  *PS16(iVar4 + 0x72d8) = (u16)bVar3 << 2;
  *PS16(iVar4 + 0x730c) = (u16)*P8(uVar2 + 0x79ee) << 2;
  switch(*P8(uVar2 + 0x7d80)) {
  case 0:
    piVar1 = PS16((u16)param_1 * 2 + 0x730c);
    *piVar1 = *piVar1 + (u16)*P8(param_1 + 0xaefc);
    return 0 /* AX? */;
  case 1:
    uVar2 = (u16)*P8(param_1 + 0xaefc);
    local_4 = (u16)param_1 * 2;
    *PS16(local_4 + 0x72d8) = *PS16(local_4 + 0x72d8) - uVar2;
    break;
  case 2:
    piVar1 = PS16((u16)param_1 * 2 + 0x72d8);
    *piVar1 = *piVar1 - (u16)*P8(param_1 + 0xaefc);
    return 0 /* AX? */;
  case 3:
    uVar2 = (u16)*P8(param_1 + 0xaefc);
    local_4 = (u16)param_1 * 2;
    *PS16(local_4 + 0x72d8) = *PS16(local_4 + 0x72d8) - uVar2;
    goto LAB_1000_88f4;
  case 4:
    piVar1 = PS16((u16)param_1 * 2 + 0x730c);
    *piVar1 = *piVar1 - (u16)*P8(param_1 + 0xaefc);
    return 0 /* AX? */;
  case 5:
    uVar2 = (u16)*P8(param_1 + 0xaefc);
    local_4 = (u16)param_1 * 2;
    *PS16(local_4 + 0x72d8) = *PS16(local_4 + 0x72d8) + uVar2;
LAB_1000_88f4:
    *PS16(local_4 + 0x730c) = *PS16(local_4 + 0x730c) - uVar2;
    return 0 /* AX? */;
  case 6:
    piVar1 = PS16((u16)param_1 * 2 + 0x72d8);
    *piVar1 = *piVar1 + (u16)*P8(param_1 + 0xaefc);
    return 0 /* AX? */;
  case 7:
    uVar2 = (u16)*P8(param_1 + 0xaefc);
    local_4 = (u16)param_1 * 2;
    *PS16(local_4 + 0x72d8) = *PS16(local_4 + 0x72d8) + uVar2;
    break;
  default:
    return 0 /* AX? */;
  }
  *PS16(local_4 + 0x730c) = *PS16(local_4 + 0x730c) + uVar2;
  return 0 /* AX? */;
}

// 1000:8986 FUN_1000_8986
static u8 f_8986(u8 param_1,u16 param_2)

{
  FN(0x8986);
  u8 bVar1;
  u8 bVar2;
  
  bVar1 = f_1766(*P8(param_1 + 0x7776), *P8((param_2 & 0xff) + 0x7776));
  bVar2 = f_1766(*P8(param_1 + 0x79ee), *P8((param_2 & 0xff) + 0x79ee));
  if (bVar1 == bVar2) {
    return *P8(param_1 + 0x7596) & 6;
  }
  if (bVar2 < bVar1) {
    if (*P8((param_2 & 0xff) + 0x7776) < *P8(param_1 + 0x7776)) {
      return 6;
    }
    return 2;
  }
  if (*P8((param_2 & 0xff) + 0x79ee) < *P8(param_1 + 0x79ee)) {
    return 0;
  }
  return 4;
}

// 1000:8A34 FUN_1000_8a34
static u16 f_8a34(u16 param_1)

{
  FN(0x8A34);
  u8 uVar1;
  
  uVar1 = (u8)(((u32)param_1 % 0x4d) / 7);
  return f_c3a0((i8)((u32)param_1 / 0x21b), uVar1);
  return 0 /* AX? */;
}

// 1000:8A72 FUN_1000_8a72
static u16 f_8a72(u8 param_1)

{
  FN(0x8A72);
  
  return f_8a34(*P16((u16)param_1 * 2 + -0x76b2));
  return 0 /* AX? */;
}

// 1000:8A88 FUN_1000_8a88  FIX: the tile of a cell's centre (Ghidra lost the computation of AX)
static u16 f_8a88(u8 param_1)

{
  FN(0x8A88);
  u8 x = f_c380(param_1);
  u8 y = f_c390(param_1);
  return (u16)(x * 0x21b + y * 7 + 0xea);
}

// 1000:8AD0 FUN_1000_8ad0
static u16 f_8ad0(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0x8AD0);
  u16 uVar1;
  i16 iVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  
  uVar1 = f_1756(*P16((u16)param_1 * 2 + -0x518c), *P16((u16)param_1 * 2 + -0x7a6e));
  iVar2 = f_1746(1, uVar1);
  uVar1 = f_1756(*P16((u16)param_1 * 2 + -0x514c), *P16((u16)param_1 * 2 + -0x7a36));
  iVar3 = f_1746(1, uVar1);
  iVar4 = (u16)param_1 * 2;
  iVar4 = f_1746(*PS16(iVar4 + -0x518c) + *PS16(iVar4 + -0x6138), *PS16(iVar4 + -0x7a6e) + *PS16(iVar4 + -0x6260));
  iVar5 = (u16)param_1 * 2;
  iVar5 = f_1746(*PS16(iVar5 + -0x514c) + *PS16(iVar5 + -0x51f8), *PS16(iVar5 + -0x7a36) + *PS16(iVar5 + -0x621c));
  f_902e(param_2, iVar2, iVar3, iVar4 - iVar2, iVar5 - iVar3, param_3);
  if (param_1 == 0) {
    f_0834();
  }
  return 0 /* AX? */;
}

// 1000:8BB2 FUN_1000_8bb2
static u16 f_8bb2(u8 param_1)

{
  FN(0x8BB2);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  if ((*PS8(uVar1 + 0xae6b) != '\0') && (*PS8(uVar1 + 0x734c) == '\x04')) {
    *P8(uVar1 + 0xae6b) = 0;
    f_4712();
  }
  return 0 /* AX? */;
}

// 1000:8BD4 FUN_1000_8bd4
static u8 f_8bd4(u8 param_1)

{
  FN(0x8BD4);
  
  return *P8(param_1 + 0x757e);
}

// 1000:8BE6 FUN_1000_8be6
static u16 f_8be6(u8 param_1,u8 param_2)

{
  FN(0x8BE6);
  
  if (*PS8(0x355b) != '\0') {
    f_902e(param_1, *P16(0x8bec), *P16(0x9aec), *PS16(0x8d22) - *PS16(0x8bec), *PS16(0x9aee) - *PS16(0x9aec), param_2);
    *P8(0x355b) = 0;
  }
  return 0 /* AX? */;
}

// 1000:8C2A FUN_1000_8c2a
static u16 f_8c2a(u8 param_1)

{
  FN(0x8C2A);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_8c52(param_1, local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:8C52 FUN_1000_8c52
static u16 f_8c52(u8 param_1,u8 param_2)

{
  FN(0x8C52);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = (u16)param_2;
  if ((*PS8(uVar1 + 0xae6b) != '\0') && (*PS8(uVar1 + 0x757e) != '\0')) {
    f_a19e(uVar1, 4, param_1);
    *PS8(param_2 + 0x757e) = *PS8(param_2 + 0x757e) + -1;
  }
  iVar2 = f_38ea(param_2);
  if (1 < iVar2) {
    f_a19e(param_2 + 7, 4, param_1);
  }
  return 0 /* AX? */;
}

// 1000:8CAE FUN_1000_8cae
static u16 f_8cae(u8 param_1)

{
  FN(0x8CAE);
  
  if ((*PS8(param_1 + 0xae6b) != '\0') && (*PS8(param_1 + 0x734c) == '\x04')) {
    return 1;
  }
  return 0;
}

// 1000:8CCC FUN_1000_8ccc
static u16 f_8ccc(u8 param_1,u8 param_2)

{
  FN(0x8CCC);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  local_4 = 0;
  do {
    uVar1 = (u16)local_4;
    if ((*PS8(uVar1 + 0xae6b) != '\0') && (*PS8(uVar1 + 0x757e) != '\0')) {
      f_8ad0(uVar1, param_1, param_2);
      f_8bb2(local_4);
    }
    iVar2 = f_38ea(local_4);
    if (1 < iVar2) {
      f_a1cc(local_4 + 7, param_1, param_2);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:8D3C FUN_1000_8d3c
static u16 f_8d3c(i16 param_1,i16 param_2,i16 param_3,i16 param_4)

{
  FN(0x8D3C);
  i16 iVar1;
  
  if (((param_2 != 0) && (param_2 < 0x1c5)) && (*PS16(param_2 * 2 + 0x35f6) < 0x1c5)) {
    if ((param_1 != 0) || (*PS8(0x4c) == '\x02')) {
      param_2 = param_2 * 2;
      return f_8dde(param_1, *P16(param_2 + 0x35f6), *PS16(param_2 + 0x39d0) + param_3, *PS16(param_2 + 0x3d5a) + param_4);
    }
    param_2 = param_2 * 2;
    iVar1 = *PS16(param_2 + 0x35f6) * 2;
    param_3 = *PS16(param_2 + 0x39d0) + param_3;
    param_4 = *PS16(param_2 + 0x3d5a) + param_4;
    f_902e(2, param_3, param_4, *P16(iVar1 + 0x79f6), *P16(iVar1 + 0x7d8c), 0);
  }
  return 0 /* AX? */;
}

// 1000:8DDE FUN_1000_8dde
static u16 f_8dde(i16 param_1,i16 param_2,u16 param_3,i16 param_4)

{
  FN(0x8DDE);
  u16 uVar1;
  
  *PS16(0x358c) = param_1;
  if ((param_1 == 0) && (*PS8(0x4c) != '\x02')) {
    *P16(0x3590) = *P16(0x50);
    *PS16(0x3594) = *P8((*P16(0x4c) & 0xff) + 0x35d4) + 199;
    uVar1 = *P16(param_2 * 2 + -0x723e);
    param_4 = param_4 - *PS16(0x50);
  }
  else {
    *P16(0x3590) = 0;
    *P16(0x3594) = 399;
    uVar1 = *P16(param_2 * 2 + -0x723e);
  }
  DRV(0x358c,param_3,param_4,uVar1);
  return 0 /* AX? */;
}

// 1000:8E5E FUN_1000_8e5e
static u16 f_8e5e(u16 param_1,u16 param_2,i16 param_3,i16 param_4,u16 param_5,
             u16 param_6,u16 param_7,u16 param_8)

{
  FN(0x8E5E);
  i16 iVar1;
  
  if (((param_2 != 0) && (param_2 < 0x1c5)) &&
     (iVar1 = param_2 * 2, *PS16(iVar1 + 0x35f6) < 0x1c5)) {
    f_8ea8(param_1, *P16(iVar1 + 0x35f6), *PS16(iVar1 + 0x39d0) + param_3, *PS16(iVar1 + 0x3d5a) + param_4, param_5, param_6, param_7, param_8);
  }
  return 0 /* AX? */;
}

// 1000:8EA8 FUN_1000_8ea8
static u16 f_8ea8(i16 param_1,i16 param_2,i16 param_3,i16 param_4,i16 param_5,u16 param_6,
             u16 param_7,i16 param_8)

{
  FN(0x8EA8);
  i16 iVar1;
  
  *PS16(0x359e) = param_1;
  *PS16(0x35a0) = param_5;
  *P16(0x35a4) = param_7;
  if ((param_1 == 0) && (*PS8(0x4c) != '\x02')) {
    if (param_6 + param_8 <= *P16(0x50)) {
      return 0 /* AX? */;
    }
    if (*PS16(0x50) + 200U <= param_6) {
      return 0 /* AX? */;
    }
    iVar1 = f_1746(*P16(0x50), param_6);
    *PS16(0x35a2) = iVar1;
    param_8 = f_1756(param_8, ((u16)*P8(*P8(0x4c) + 0x35d4) - iVar1) + *PS16(0x50)
                                    + 200);
  }
  else {
    *P16(0x35a2) = param_6;
  }
  *PS16(0x35a6) = param_8;
  DRV(0x359e,param_3 - param_5,param_4 - param_6,
             *P16(param_2 * 2 + -0x723e));
  return 0 /* AX? */;
}

// 1000:8F64 FUN_1000_8f64
static u16 f_8f64(u8 param_1)

{
  FN(0x8F64);
  i16 iVar1;
  u16 uVar2;
  i16 iVar3;
  
  iVar1 = f_3a88();
  if (iVar1 == 0) {
    iVar1 = (u16)param_1 * 2;
    *P16(iVar1 + -0x7a6e) = *P16(iVar1 + -0x518c);
    *P16(iVar1 + -0x6260) = *P16(iVar1 + -0x6138);
    *P16(iVar1 + -0x7a36) = *P16(iVar1 + -0x514c);
    *P16(iVar1 + -0x621c) = *P16(iVar1 + -0x51f8);
    if (*PS16(iVar1 + -0x64ec) == 0x165) {
      *P16(iVar1 + -0x518c) = *P16(iVar1 + 0x72d8);
      *P16(iVar1 + -0x6138) = 2;
      *P16(iVar1 + -0x514c) = *P16(iVar1 + 0x730c);
      *P16(iVar1 + -0x51f8) = 2;
      return 0 /* AX? */;
    }
    iVar1 = (u16)param_1 * 2;
    iVar3 = *PS16(iVar1 + -0x64ec) * 2;
    *PS16(iVar1 + -0x518c) = *PS16(iVar3 + 0x39d0) + *PS16(iVar1 + 0x72d8);
    uVar2 = f_1756(0x20, *P16(*PS16(iVar3 + 0x35f6) * 2 + 0x79f6));
    *P16(iVar1 + -0x6138) = uVar2;
    iVar1 = (u16)param_1 * 2;
    iVar3 = *PS16(iVar1 + -0x64ec) * 2;
    *PS16(iVar1 + -0x514c) = *PS16(iVar3 + 0x3d5a) + *PS16(iVar1 + 0x730c);
    uVar2 = f_1756(0x20, *P16(*PS16(iVar3 + 0x35f6) * 2 + 0x7d8c));
    *P16(iVar1 + -0x51f8) = uVar2;
  }
  return 0 /* AX? */;
}

// 1000:902E FUN_1000_902e
static u16 f_902e(u16 param_1,u16 param_2,u16 param_3,u16 param_4,i16 param_5,
             i16 param_6)

{
  FN(0x902E);
  u16 uVar1;
  u16 uVar2;
  i16 iVar3;
  i16 local_c;
  
  *P16(0x35b0) = param_1;
  *PS16(0x35c2) = param_6;
  uVar1 = f_1746(0, param_2);
  uVar2 = f_1746(0, param_3);
  iVar3 = f_1756(0x13f, uVar1);
  local_c = f_1756(399, uVar2);
  uVar1 = f_1756(param_4, 0x140 - iVar3);
  uVar2 = f_1756(param_5, 399 - local_c);
  uVar1 = f_1746(0, uVar1);
  uVar2 = f_1746(0, uVar2);
  if ((param_6 == 0) && (*PS8(0x4c) != '\x02')) {
    if (((i16)(param_3 + param_5) <= *PS16(0x50)) ||
       ((u16)*P8(*P8(0x4c) + 0x35d4) + *PS16(0x50) + 200 <= param_3))
    goto LAB_1000_915e;
    local_c = f_1746(param_3, *P16(0x50));
    uVar2 = f_1756(param_5, ((u16)*P8(*P8(0x4c) + 0x35d4) - local_c) + *PS16(0x50)
                                  + 200);
  }
  DRV(0x35b0,iVar3,local_c,uVar1,uVar2,0x35c2,iVar3,local_c);
LAB_1000_915e:
  *PS16(0x8b34) = *PS16(0x8b34) + 1;
  return 0 /* AX? */;
}

// 1000:9168 FUN_1000_9168
static u16 f_9168(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u16 param_6,u16 param_7,u16 param_8)

{
  FN(0x9168);
  
  *P16(0x35b0) = param_1;
  *P16(0x35c2) = param_6;
  DRV(0x35b0,param_2,param_3,param_4,param_5,0x35c2,param_7,param_8);
  *PS16(0x8b34) = *PS16(0x8b34) + 1;
  return 0 /* AX? */;
}

// 1000:91AC FUN_1000_91ac
static u16 f_91ac(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u16 param_6)

{
  FN(0x91AC);
  
  *P16(0x35c2) = param_1;
  FUN_1fe7_06e8(0x35c2,param_2,param_3,param_4,param_5,param_6);
  return 0 /* AX? */;
}

// 1000:91D8 FUN_1000_91d8
static u16 f_91d8(i16 param_1,i16 param_2,i16 param_3,u16 param_4)

{
  FN(0x91D8);
  
  *PS16(0x35b0) = param_1;
  if (((param_1 != 0) || (*PS8(0x4c) == '\x02')) ||
     ((*PS16(0x50) < param_3 &&
      (((param_3 < *PS16(0x50) + 200 && (0 < param_2)) && (param_2 < 0x13f)))))) {
    FUN_1fe7_0049(0x35b0,param_2,param_3,param_4);
  }
  return 0 /* AX? */;
}

// 1000:922A FUN_1000_922a
static i16 f_922a(u8 param_1)

{
  FN(0x922A);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  return (*P8(*P8(uVar1 + 0x8134) + 0x35dc) - 1 & (u16)*P8(uVar1 + 0x8bd8)) +
         (u16)*P8((*P8(uVar1 + 0x7596) >> 1) + 0x35d8);
}

// 1000:9258 FUN_1000_9258
static u16 f_9258(u8 param_1)

{
  FN(0x9258);
  u16 uVar1;
  i16 iVar2;
  i16 iVar3;
  
  uVar1 = (u16)param_1;
  iVar2 = f_9486(uVar1);
  iVar3 = f_922a(uVar1);
  *PS16(uVar1 * 2 + -0x64ec) =
       (u16)*P8(*P8(uVar1 + 0x8134) + 0x35e2) + iVar3 + iVar2;
  return *P16((u16)param_1 * 2 + -0x64ec);
}

// 1000:929C FUN_1000_929c
static u16 f_929c(u8 param_1,u8 param_2)

{
  FN(0x929C);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = f_9258((u16)param_2);
  *P16((u16)param_2 * 2 + -0x64ec) = uVar1;
  iVar2 = (u16)param_2 * 2;
  f_8d3c(param_1, *P16(iVar2 + -0x64ec), *P16(iVar2 + 0x72d8), *P16(iVar2 + 0x730c));
  return f_8f64(param_2);
}

// 1000:92E4 FUN_1000_92e4
static u16 f_92e4(u8 param_1,u8 param_2)

{
  FN(0x92E4);
  i16 iVar1;
  
  iVar1 = f_38fa(param_2);
  return f_9328(param_1, param_2, (iVar1 >> 1) + 0x161);
  return 0 /* AX? */;
}

// 1000:930C FUN_1000_930c
static u16 f_930c(u8 param_1,u8 param_2)

{
  FN(0x930C);
  return f_9328(param_1, param_2, 0x165);
}

// 1000:9328 FUN_1000_9328
static u16 f_9328(u16 param_1,u8 param_2,u16 param_3)

{
  FN(0x9328);
  u16 uVar1;
  u16 uVar2;
  i16 iVar3;
  
  iVar3 = (u16)param_2 * 2;
  *P16(iVar3 + -0x64de) = param_3;
  uVar1 = f_391a((u16)param_2);
  *P16(iVar3 + 0x72e6) = uVar1;
  uVar1 = f_392a((u16)param_2);
  *P16((u16)param_2 * 2 + 0x731a) = uVar1;
  uVar2 = (u16)param_2;
  if (*PS8(uVar2 + 0x9e24) == '\0') {
    f_8d3c(param_1, param_3, *P16((u16)param_2 * 2 + 0x72e6), *P16((u16)param_2 * 2 + 0x731a));
  }
  else {
    f_93ba(uVar2, param_1, *P16(uVar2 * 2 + 0x72e6), *P16(uVar2 * 2 + 0x731a));
  }
  return f_8f64(param_2 + 7);
}

// 1000:93BA FUN_1000_93ba
static u16 f_93ba(u8 param_1,u16 param_2,u16 param_3,u16 param_4)

{
  FN(0x93BA);
  i8 cVar1;
  
  cVar1 = *PS8(param_1 + 0x9b0d);
  f_944e(param_2, param_3, param_4, cVar1 == '\0');
  f_944e(param_2, param_3, param_4, cVar1 == '\x01');
  f_944e(param_2, param_3, param_4, cVar1 == '\x02');
  f_944e(param_2, param_3, param_4, cVar1 == '\x03');
  *P8(param_1 + 0x9b0d) = cVar1 + 1U & 3;
  return 0 /* AX? */;
}

// 1000:944E FUN_1000_944e
static u16 f_944e(u16 param_1,u16 param_2,u16 param_3,i16 param_4)

{
  FN(0x944E);
  u16 uVar1;
  
  if (param_4 == 0) {
    uVar1 = *P16((u16)*P8(0x4c) * 2 + 0x35ea);
  }
  else {
    uVar1 = *P16((u16)*P8(0x4c) * 2 + 0x35f0);
  }
  FUN_1fe7_0049(param_1,param_2,param_3,uVar1);
  return 0 /* AX? */;
}

// 1000:9486 FUN_1000_9486
static u16 f_9486(u8 param_1)

{
  FN(0x9486);
  i8 cVar1;
  u16 local_4;
  
  if ((param_1 == 0) && ((*P8(0xba) & 8) == 0)) {
    if (*PS8(0x8b36) == '\0') {
      local_4 = 1;
    }
    else if (*PS8(0x8b36) == '\x02') {
      local_4 = 0x2d;
    }
  }
  else {
    cVar1 = *PS8(param_1 + 0x8b36);
    if (cVar1 == '\0') {
      local_4 = 0x59;
    }
    else if (cVar1 == '\x01') {
      local_4 = 0xb1;
    }
    else if (cVar1 == '\x02') {
      local_4 = 0x85;
    }
    else if (cVar1 == '\x03') {
      local_4 = 0xdd;
    }
    if (*PS8(param_1 + 0x9e24) != '\0') {
      if (*PS8(param_1 + 0x8b36) == '\0') {
        local_4 = 0x109;
      }
      else {
        local_4 = 0x135;
      }
    }
  }
  return local_4;
}

// 1000:952C FUN_1000_952c
static u16 f_952c(u8 param_1)

{
  FN(0x952C);
  i8 cVar1;
  u16 local_4;
  
  cVar1 = *PS8(param_1 + 0x860c);
  if (cVar1 == '\0') {
    local_4 = 0x59;
  }
  else if (cVar1 == '\x01') {
    local_4 = 0xb1;
  }
  else if (cVar1 == '\x02') {
    local_4 = 0x85;
  }
  else if (cVar1 == '\x03') {
    local_4 = 0xdd;
  }
  else if (cVar1 == '\x05') {
    local_4 = 0x109;
  }
  return local_4;
}

// 1000:9584 FUN_1000_9584
static u16 f_9584(u16 param_1,u8 param_2,u8 param_3,u16 param_4)

{
  FN(0x9584);
  i16 iVar1;
  i16 iVar2;
  
  if (*PS8(0x353a) == '\x02') {
    iVar1 = f_c7f6(param_4);
    if (iVar1 != 0) {
      iVar1 = (u16)param_2 * 0x1c + -3;
      iVar2 = (u16)param_3 * 0x1c + 3;
      goto LAB_1000_95b9;
    }
  }
  iVar1 = (u16)param_2 * 0x1c;
  iVar2 = (u16)param_3 * 0x1c;
LAB_1000_95b9:
  return f_8d3c(param_1, param_4, iVar2, iVar1);
  return 0 /* AX? */;
}

// 1000:95C8 FUN_1000_95c8
static u16 f_95c8(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u16 param_6)

{
  FN(0x95C8);
  u8 bVar1;
  u8 bVar2;
  u16 uVar3;
  
  if (param_2 < 0x9a) {
    bVar1 = f_c380(param_2);
    bVar2 = f_c390(param_2);
    uVar3 = f_c148(param_2);
    f_8e5e(param_1, uVar3, (u16)bVar2 * 0x1c, (u16)bVar1 * 0x1c, param_3, param_4, param_5, param_6);  // FIX: pushed before the other call (Ghidra lost it)
  }
  return 0 /* AX? */;
}

// 1000:961C FUN_1000_961c
static u16 f_961c(u8 param_1,u8 param_2)

{
  FN(0x961C);
  u16 uVar1;
  i16 iVar2;
  
  iVar2 = f_952c((u16)param_2);
  uVar1 = *P16((u16)param_2 * 2 + 0x7796);
  f_8d3c(param_1, (u16)(*P8(param_2 + 0x75fe) >> 1) * 0xb + iVar2 + 8, (u16)(u8)((u32)uVar1 % 0x4d) << 2, (u16)(u8)((u32)uVar1 / 0x4d) << 2);
  return f_6602(param_1, *P16((u16)param_2 * 2 + 0x7796));
  return 0 /* AX? */;
}

// 1000:96BC FUN_1000_96bc
static u16 f_96bc(u8 param_1,u8 param_2)

{
  FN(0x96BC);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  if (*PS16(0x75fc) != 0) {
    local_4 = 0;
    do {
      if (*PS8(local_4 + 0x9bb6) == *PS8(0x3558)) {
        uVar1 = f_8a34(*P16((u16)local_4 * 2 + 0x7796));
        iVar2 = f_9720(param_2, uVar1);
        if (iVar2 != 0) {
          f_961c(param_1, local_4);
        }
      }
      local_4 = local_4 + 1;
    } while ((u16)local_4 < *P16(0x75fc));
  }
  return 0 /* AX? */;
}

// 1000:9720 FUN_1000_9720
static u16 f_9720(u8 param_1,u8 param_2)

{
  FN(0x9720);
  
  if ((((param_1 != param_2) && ((u16)param_1 + (i16)*PS8(0x4104) != (u16)param_2)) &&
      ((u16)param_1 + (i16)*PS8(0x4105) != (u16)param_2)) &&
     (((u16)param_1 + (i16)*PS8(0x4106) != (u16)param_2 &&
      ((u16)param_1 + (i16)*PS8(0x4107) != (u16)param_2)))) {
    return 0;
  }
  return 1;
}

// 1000:9784 FUN_1000_9784
static u16 f_9784(void)

{
  FN(0x9784);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P8(local_4 + 0x757e) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:97A4 FUN_1000_97a4
static u16 f_97a4(void)

{
  FN(0x97A4);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  local_4 = 0;
  do {
    uVar1 = (u16)local_4;
    *P8(uVar1 + 0x3568) = 0;
    *P8(uVar1 + 0x8560) = 0;
    *P8(uVar1 + 0xae3e) = 0;
    *P8(uVar1 + 0xae45) = 0;
    *P8(uVar1 + 0xae4c) = 0;
    *P8(uVar1 + 0xaeac) = 0;
    *P8(uVar1 + 0xae5a) = 0;
    *P8(uVar1 + 0x9d86) = 0;
    *P8(uVar1 + 0x9b06) = 0;
    *P8(uVar1 + 0x9ddc) = 0;
    *P8(uVar1 + 0x8bd8) = 0;
    *P8(uVar1 + 0x7776) = 0;
    *P8(uVar1 + 0x79ee) = 0;
    *P8(uVar1 + 0x7340) = 0;
    *P8(uVar1 + 0xae6b) = 0;
    *P8(uVar1 + 0x9d90) = 0;
    *P8(uVar1 + 0x7d80) = 0;
    *P8(uVar1 + 0x7596) = 0;
    *P8(uVar1 + 0x7786) = 0;
    *P8(uVar1 + 0xaefc) = 0;
    *P8(uVar1 + 0x734c) = 0;
    *P8(uVar1 + 0x89f6) = 0;
    *P8(uVar1 + 0x8b36) = 0;
    *P8(uVar1 + 0x8947) = 0;
    *P8(uVar1 + 0x9e18) = 0;
    *P8(uVar1 + 0x8940) = 0;
    *P8(uVar1 + 0x7353) = 0;
    *P8(uVar1 + 0xae64) = 0;
    *P8(uVar1 + 0xade4) = 0;
    *P8(uVar1 + 0x8be4) = 0;
    iVar2 = uVar1 * 2;
    *P16(iVar2 + 0x7768) = 0;
    *P16(iVar2 + -0x76b2) = 0;
    *P16(iVar2 + -0x64ec) = 0;
    *P16(iVar2 + 0x72d8) = 0;
    *P16(iVar2 + 0x730c) = 0;
    *P8(uVar1 + 0x9af0) = 0;
    *P8(uVar1 + 0x772a) = 0;
    *P16(iVar2 + -0x646a) = 0;
    *P16(iVar2 + -0x645c) = 0;
    *P16(iVar2 + 0x7758) = 0;
    *P8(uVar1 + 0x9ce2) = 0;
    *P8(uVar1 + 0x9b8d) = 0;
    *P8(uVar1 + 0x778e) = 0;
    *P8(uVar1 + 0x9d97) = 0;
    *P8(uVar1 + 0x774f) = 0;
    *P8(uVar1 + 0x9dd5) = 0;
    *P8(uVar1 + 0x72d0) = 0;
    *P8(uVar1 + 0x735d) = 0;
    *P8(uVar1 + 0x9e24) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  *P8(0x353b) = 0;
  *P8(0x3557) = 3;
  *P8(0x3558) = 0;
  *P8(0x3559) = 0xb;
  *P8(0x355a) = 0xb;
  *P8(0x355b) = 0;
  *P16(0x355e) = 400;
  *P16(0x3560) = 0;
  *P16(0x3562) = 0;
  *P8(0x3564) = 1;
  *P8(0x3565) = 1;
  *P8(0x3566) = 0;
  *P8(0x3567) = 0;
  *P8(0x356f) = 3;
  *P8(0x3570) = 0;
  *P8(0x3571) = 0;
  *P8(0x812e) = 0;
  *P8(0xae3d) = 0;
  *P8(0x8d24) = 0;
  *P8(0x735a) = 0;
  *P16(0x75fc) = 0;
  *P8(0x7766) = 0;
  *P8(0x873a) = 0;
  *P8(0x735b) = 0;
  *P16(0x8bec) = 0;
  *P16(0x9aec) = 0;
  *P16(0x8d22) = 0;
  *P16(0x9aee) = 0;
  *P8(0x7795) = 0;
  *P16(0x9b76) = 0;
  *P16(0x9b74) = 0;
  *P16(0xaeaa) = 0;
  *P16(0xaee8) = 0;
  *P8(0x8b32) = 0;
  *P8(0x4d) = 0;
  *P8(0x9ec6) = 3;
  return 0 /* AX? */;
}

// 1000:9950 FUN_1000_9950
static u16 f_9950(u16 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5)

{
  FN(0x9950);
  u16 uVar1;
  i16 iVar2;
  
  iVar2 = *PS16(0x3560) * 2;
  *P16(iVar2 + 0x79f6) = param_4;
  *P16(iVar2 + 0x7d8c) = param_5;
  uVar1 = DRV(param_1,param_2,param_3,param_4,param_5);
  *P16(iVar2 + -0x723e) = uVar1;
  *PS16(0x3560) = *PS16(0x3560) + 1;
  return 0 /* AX? */;
}

// 1000:998A FUN_1000_998a
static u16 f_998a(void)

{
  FN(0x998A);
  u16 uVar1;
  
  uVar1 = DRV(0);
  DRV(0,uVar1);
  uVar1 = DRV(2);
  DRV(2,uVar1);
  uVar1 = DRV(4);
  DRV(4,uVar1);
  if (*PS8(0x4c) != '\0') {
    f_d6aa(3);
  }
  DRV();
  f_def0(0x53fc);
  f_9f12();
  DRV();
  return f_df20();
}

// 1000:9A00 FUN_1000_9a00
static u16 f_9a00(void)

{
  FN(0x9A00);
  return f_d648(0);
}

// 1000:9A0A FUN_1000_9a0a
static u16 f_9a0a(u8 param_1)

{
  FN(0x9A0A);
  u16 uVar1;
  u16 local_4;
  
  f_dc78(param_1, 0x5406);
  for (local_4 = 0; local_4 < 7; local_4 = local_4 + 1) {
    for (uVar1 = 0; uVar1 < 0x14; uVar1 = uVar1 + 1) {
      f_9950(param_1, uVar1 << 4, local_4 << 4, 0x10, 0x10);
    }
  }
  uVar1 = 0;
  do {
    f_9950(param_1, uVar1 << 4, 0x70, 0x10, 0x10);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x13);
  for (local_4 = 0; local_4 < 2; local_4 = local_4 + 1) {
    for (uVar1 = 0; uVar1 < 0xd; uVar1 = uVar1 + 1) {
      f_9950(param_1, uVar1 * 0x18, local_4 * 0x18 + 0x80, 0x18, 0x18);
    }
  }
  uVar1 = 0;
  do {
    f_9950(param_1, uVar1 * 0x18, 0xb0, 0x18, 0x18);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 10);
  f_9950(param_1, 0xf0, 0xb0, 4, 5);
  f_9950(param_1, 0x108, 0xb0, 4, 5);
  return f_9950(param_1, 0x120, 0xb0, 0x18, 0x18);
  return 0 /* AX? */;
}

// 1000:9B78 FUN_1000_9b78
static u16 f_9b78(u8 param_1)

{
  FN(0x9B78);
  u16 uVar1;
  i16 iVar2;
  u16 local_6;
  u16 local_4;
  
  f_dc78(param_1, 0x5412);
  f_9950(param_1, 0, 0, 0x10, 0x20);
  f_9950(param_1, 0x10, 0, 0x10, 0x20);
  f_9950(param_1, 0x20, 0, 0x20, 0x10);
  f_9950(param_1, 0x20, 0x10, 0x20, 0x10);
  f_9950(param_1, 0x40, 0, 0x10, 0x20);
  f_9950(param_1, 0x50, 0, 0x10, 0x20);
  f_9950(param_1, 0x60, 0, 0x20, 0x10);
  f_9950(param_1, 0x60, 0x10, 0x20, 0x10);
  uVar1 = 4;
  do {
    f_9950(param_1, uVar1 << 5, 0, 0x20, 0x20);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 10);
  for (local_4 = 1; local_4 < 5; local_4 = local_4 + 1) {
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1) {
      f_9950(param_1, uVar1 << 5, local_4 << 5, 0x20, 0x20);
    }
  }
  uVar1 = 0;
  do {
    f_9950(param_1, uVar1 << 5, 0xa0, 0x20, 0x20);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
  iVar2 = 3;
  local_6 = 0;
  do {
    f_9950(param_1, iVar2 * 0x20 + 2, local_6 * 6 + 0xa0, 0x18, 5);
    local_6 = local_6 + 1;
  } while (local_6 < 5);
  iVar2 = 4;
  f_9950(param_1, 0x80, 0xa2, 4, 0x17);
  f_9950(param_1, iVar2 * 0x20 + 9, 0xa2, 4, 0x17);
  f_9950(param_1, iVar2 * 0x20 + 0x10, 0xa2, 4, 0x17);
  f_9950(param_1, iVar2 * 0x20 + 0x18, 0xa2, 4, 0x17);
  return f_9950(param_1, 0xa2, 0xa0, 0x18, 5);
  return 0 /* AX? */;
}

// 1000:9E16 FUN_1000_9e16
static u16 f_9e16(u8 param_1)

{
  FN(0x9E16);
  u16 local_6;
  u16 local_4;
  
  f_dc78(param_1, 0x541e);
  for (local_4 = 0; local_4 < 7; local_4 = local_4 + 1) {
    for (local_6 = 0; local_6 < 0xd; local_6 = local_6 + 1) {
      f_9950(param_1, local_6 * 0x18, local_4 * 0x18, 0x18, 0x18);
    }
  }
  local_6 = 0;
  do {
    f_9950(param_1, local_6 * 0x18, 0xa8, 0x18, 0x18);
    local_6 = local_6 + 1;
  } while (local_6 < 6);
  local_6 = 0;
  do {
    f_9950(param_1, local_6 * 0x10 + 0x90, 0xa8, 0x10, 0x10);
    local_6 = local_6 + 1;
  } while (local_6 < 8);
  return 0 /* AX? */;
}

// 1000:9ECE FUN_1000_9ece
static u16 f_9ece(u16 param_1)

{
  FN(0x9ECE);
  f_dc78(param_1, 0x542a);
  f_9950(param_1, 0xc0, 0xa0, 0x1c, 0x1c);
  return f_9950(param_1, 0xe0, 0xa0, 0x40, 0x1c);
  return 0 /* AX? */;
}

// 1000:9F12 FUN_1000_9f12
static u16 f_9f12(void)

{
  FN(0x9F12);
  
  *P16(0x3560) = 0;
  f_9a0a(2);
  f_9b78(2);
  f_9e16(2);
  return f_9ece(2);
}

// 1000:9F42 FUN_1000_9f42
static u16 f_9f42(void)

{
  FN(0x9F42);
  
  *P8(0x812c) = 0;
  *P8(0x812d) = 0;
  return 0 /* AX? */;
}

// 1000:9F4E FUN_1000_9f4e  FIX: the controls the keyboard hook keeps come from the host (joystick: DS:0052=0)
static u16 f_9f4e(void)

{
  FN(0x9F4E);
  u16 uVar1;
  u16 uVar2;
  
  melee_read_controls(1);
  if (*PS8(0x398e) != '\0' || *PS8(0x398f) != '\0') {
    return 1;
  }
  if (*PS8(0x52) != '\0') {
    uVar1 = DRV(1);
    uVar2 = DRV(0);
    return uVar2 | uVar1;
  }
  return 0;
}

// 1000:9F8A FUN_1000_9f8a  FIX: the controls the keyboard hook keeps come from the host (joystick: DS:0052=0)
static u16 f_9f8a(void)

{
  FN(0x9F8A);
  i16 iVar1;
  u16 uVar2;
  
  melee_read_controls(0);
  iVar1 = f_9fda((i16)*PS8(0x398c), (i16)*PS8(0x398d));
  *PS16(0x9b74) = iVar1;
  if ((*PS8(0x52) != '\0') && (iVar1 == 8)) {
    uVar2 = DRV();
    *P16(0x812c) = uVar2;
    uVar2 = f_9fda((i16)*PS8(0x812c), (i16)*PS8(0x812d));
    *P16(0x9b74) = uVar2;
  }
  if ((u16)*P8(0x3980) != *P16(0x9b74)) {
    *P8(0x3568) = 0;
  }
  *P8(0x3980) = *P8(0x9b74);
  return 0 /* AX? */;
}

// 1000:9FDA FUN_1000_9fda
static u8 f_9fda(i16 param_1,i16 param_2)

{
  FN(0x9FDA);
  u8 local_6;
  u8 local_4;
  
  local_4 = 1;
  local_6 = 1;
  if (0x3c < param_1) {
    local_4 = 2;
  }
  if (param_1 < -0x3c) {
    local_4 = 0;
  }
  if (0x3c < param_2) {
    local_6 = 2;
  }
  if (param_2 < -0x3c) {
    local_6 = 0;
  }
  return *P8((u16)local_4 + (u16)local_6 * 3 + 0x3982);
}

// 1000:A02A FUN_1000_a02a
static u16 f_a02a(void)

{
  FN(0xA02A);
  u16 local_8;
  
  local_8 = 0;
  do {
    f_a0ba(local_8, 0xff);
    local_8 = local_8 + 1;
  } while (local_8 < 0x1d7a);
  return f_a054();
}

// 1000:A054 FUN_1000_a054
static u16 f_a054(void)

{
  FN(0xA054);
  u16 local_4;
  
  local_4 = 0;
  do {
    f_a0ea(local_4);
    f_a0ea(local_4 + 0x1d2d);
    local_4 = local_4 + 1;
  } while (local_4 < 0x4d);
  local_4 = 0;
  do {
    f_a0ea(local_4);
    f_a0ea(local_4 + 0x4c);
    local_4 = local_4 + 0x4d;
  } while (local_4 < 0x1d7a);
  return 0 /* AX? */;
}

// 1000:A0A8 FUN_1000_a0a8
static u16 f_a0a8(u16 param_1)

{
  FN(0xA0A8);
  return f_a0ba(param_1, 0xff);
}

// 1000:A0BA FUN_1000_a0ba
static u16 f_a0ba(i16 param_1,u8 param_2)

{
  FN(0xA0BA);
  
  if ((-1 < param_1) && (param_1 < 0x1d7a)) {
    *P8(param_1 + 0x5b0) = param_2;
    return 0 /* AX? */;
  }
  return f_a146();
}

// 1000:A0DC FUN_1000_a0dc
static u8 f_a0dc(i16 param_1)

{
  FN(0xA0DC);
  
  return *P8(param_1 + 0x5b0);
}

// 1000:A0EA FUN_1000_a0ea
static u16 f_a0ea(u16 param_1)

{
  FN(0xA0EA);
  return f_a0ba(param_1, 0);
}

// 1000:A0FC FUN_1000_a0fc
static u16 f_a0fc(i16 param_1,i16 param_2,i16 param_3)

{
  FN(0xA0FC);
  return f_a0ea(param_3 * 0x4d + param_1 + param_2);
  return 0 /* AX? */;
}

// 1000:A114 FUN_1000_a114
static u32 f_a114(i16 param_1,i16 param_2)

{
  FN(0xA114);
  return CONCAT22((i16)((u32)((i32)param_2 * 0x4d) >> 0x10),(i16)((i32)param_2 * 0x4d) + param_1
                 );
}

// 1000:A122 FUN_1000_a122
static u32 f_a122(u8 param_1,u8 param_2)

{
  FN(0xA122);
  return CONCAT22(param_1 / 0x7a,(u16)param_1 * 0x21b + (u16)param_2 * 7);
}

// 1000:A146 FUN_1000_a146
static u16 f_a146(void)

{
  FN(0xA146);
  return 0 /* AX? */;
}

// 1000:A148 FUN_1000_a148
static u16 f_a148(u8 param_1,u16 param_2,u16 param_3,u16 param_4,
             u16 param_5,u8 param_6)

{
  FN(0xA148);
  return f_902e(param_1, param_2, param_3, param_4, param_5, param_6);
  return 0 /* AX? */;
}

// 1000:A170 FUN_1000_a170
static u16 f_a170(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xA170);
  i16 iVar1;
  
  iVar1 = (u16)param_1 * 2;
  return f_a148(param_2, *P16(iVar1 + -0x7a6e), *P16(iVar1 + -0x7a36), *P16(iVar1 + -0x6260), *P16(iVar1 + -0x621c), param_3);
  return 0 /* AX? */;
}

// 1000:A19E FUN_1000_a19e
static u16 f_a19e(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xA19E);
  i16 iVar1;
  
  iVar1 = (u16)param_1 * 2;
  return f_a148(param_2, *P16(iVar1 + -0x518c), *P16(iVar1 + -0x514c), *P16(iVar1 + -0x6138), *P16(iVar1 + -0x51f8), param_3);
  return 0 /* AX? */;
}

// 1000:A1CC FUN_1000_a1cc
static u16 f_a1cc(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xA1CC);
  f_a170(param_1, param_2, param_3);
  return f_a19e(param_1, param_2, param_3);
  return 0 /* AX? */;
}

// 1000:A1FA FUN_1000_a1fa
static u16 f_a1fa(u16 param_1)

{
  FN(0xA1FA);
  f_a21a(param_1);
  f_a27e(param_1);
  return f_a3b4(param_1);
}

// 1000:A21A FUN_1000_a21a
static u16 f_a21a(u16 param_1)

{
  FN(0xA21A);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  for (local_4 = 0; local_4 < 7; local_4 = local_4 + 1) {
    uVar1 = f_0eca(local_4);
    iVar2 = f_221c(uVar1);
    if (iVar2 != 0) {
      iVar2 = f_38ea(local_4);
      if (iVar2 == 3) {
        f_92e4(param_1, local_4);
      }
      else if (iVar2 == 4) {
        f_930c(param_1, local_4);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:A27E FUN_1000_a27e
static u16 f_a27e(u16 param_1)

{
  FN(0xA27E);
  u8 bVar1;
  i16 iVar2;
  u8 local_4;
  
  local_4 = 0;
  do {
    if (local_4 != *P8(0x3571)) {
      iVar2 = f_a2f2(local_4);
      if (iVar2 != 0) {
        f_929c(param_1, local_4);
        *P8(local_4 + 0x757e) = 2;
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  bVar1 = *P8(0x3571);
  iVar2 = f_a2f2(bVar1);
  if (iVar2 != 0) {
    f_929c(param_1, bVar1);
    *P8(bVar1 + 0x757e) = 2;
  }
  return 0 /* AX? */;
}

// 1000:A2F2 FUN_1000_a2f2
static u8 f_a2f2(u8 param_1)

{
  FN(0xA2F2);
  i16 iVar1;
  
  if ((*PS8(param_1 + 0xae6b) != '\0') && (*PS8(param_1 + 0x734c) != '\x04')) {
    iVar1 = f_221c(*P8(param_1 + 0xae64));
    if (iVar1 != 0) {
      iVar1 = f_b6cc(param_1);
      if (iVar1 != 0) {
        if (*PS8(param_1 + 0x9e24) != '\0') {
          iVar1 = f_2696(*P8(param_1 + 0xae64));
          if ((iVar1 == 0) &&
             (((*P8(param_1 + 0x9d86) < 2 || (*PS8(param_1 + 0x8b36) != '\x04')) &&
              (*PS8(param_1 + 0x734c) != '\0')))) {
            return *P8(param_1 + 0x9b8d);
          }
        }
        return 1;
      }
    }
  }
  return 0;
}

// 1000:A384 FUN_1000_a384
static u16 f_a384(u8 param_1)

{
  FN(0xA384);
  i16 iVar1;
  
  if ((*PS8(0x353a) == '\x01') && (*PS8(param_1 + 0xae6b) != '\0')) {
    iVar1 = f_221c(*P8(param_1 + 0xae64));
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

// 1000:A3B4 FUN_1000_a3b4
static u16 f_a3b4(u16 param_1)

{
  FN(0xA3B4);
  i16 iVar1;
  u8 local_4;
  
  local_4 = 0;
  do {
    iVar1 = f_a384(local_4);
    if (iVar1 != 0) {
      f_6554(param_1, local_4);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return 0 /* AX? */;
}

// 1000:A3EA FUN_1000_a3ea
static u16 f_a3ea(u16 param_1)

{
  FN(0xA3EA);
  
  if (*PS8(0x355b) != '\0') {
    f_902e(4, *P16(0x8bec), *P16(0x9aec), *PS16(0x8d22) - *PS16(0x8bec), *PS16(0x9aee) - *PS16(0x9aec), param_1);
  }
  return 0 /* AX? */;
}

// 1000:A424 FUN_1000_a424
static u16 f_a424(u8 param_1)

{
  FN(0xA424);
  
  if (*PS8(param_1 + 0x9ce2) != '\0') {
    f_a450((u16)param_1);
  }
  return 0 /* AX? */;
}

// 1000:A440 FUN_1000_a440
static u16 f_a440(u8 param_1)

{
  FN(0xA440);
  
  *P8(param_1 + 0x9ce2) = 1;
  return 0 /* AX? */;
}

// 1000:A450 FUN_1000_a450  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u16 f_a450(u8 param_1)

{
  FN(0xA450);
  if (param_1 != '\0') {
    return f_a476(param_1);
  }
  return f_a50e(0);
}

// 1000:A476 FUN_1000_a476
static u16 f_a476(u8 param_1)

{
  FN(0xA476);
  i16 iVar1;
  
  if (((*PS16((u16)param_1 * 2 + 0x74) == 0) &&
      (iVar1 = f_38ea((u16)param_1), iVar1 == 0)) &&
     (*PS16((u16)param_1 * 2 + 0x66) == 0)) {
    if (*PS8(param_1 + 0x734c) != '\x02') {
      if (param_1 != 6) {
        return 0 /* AX? */;
      }
      iVar1 = f_719c();
      if (iVar1 == 0) {
        return 0 /* AX? */;
      }
    }
    f_a4d0(param_1);
  }
  return 0 /* AX? */;
}

// 1000:A4D0 FUN_1000_a4d0
static u16 f_a4d0(u8 param_1)

{
  FN(0xA4D0);
  u16 uVar1;
  
  f_a58c(param_1);
  uVar1 = (u16)param_1;
  *P16(uVar1 * 2 + 0x82) = 0xf;
  *P8(0x3571) = param_1;
  *P8(uVar1 + 0x9b06) = 1;
  *P8(uVar1 + 0x9d86) = 1;
  *P8(uVar1 + 0x9ddc) = 1;
  *P8(uVar1 + 0x9ce2) = 0;
  return 0 /* AX? */;
}

// 1000:A50E FUN_1000_a50e
static u16 f_a50e(u8 param_1)

{
  FN(0xA50E);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  *P8(0x7766) = *P8(0x8b36);
  local_4 = 1;
  do {
    uVar1 = (u16)local_4;
    if ((*PS8(uVar1 + 0xae6b) != '\0') &&
       ((*PS8(uVar1 + 0x734c) == '\x02' || (*PS8(uVar1 + 0x734c) == '\x01')))) {
      iVar2 = f_6ac8(local_4);
      if (iVar2 != 0) {
        *P8(local_4 + 0x72d0) = 1;
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  if (*PS16((u16)param_1 * 2 + 0x74) == 0) {
    iVar2 = f_38ea((u16)param_1);
    if (iVar2 == 0) {
      f_a4d0(param_1);
    }
  }
  return 0 /* AX? */;
}

// 1000:A58C FUN_1000_a58c
static u16 f_a58c(u8 param_1)

{
  FN(0xA58C);
  u16 uVar1;
  
  uVar1 = f_1836((u16)param_1);
  *P16((u16)param_1 * 2 + 0x74) = uVar1;
  return 0 /* AX? */;
}

// 1000:A5AA FUN_1000_a5aa
static u16 f_a5aa(u8 param_1)

{
  FN(0xA5AA);
  
  *P8(param_1 + 0x9b06) = 0;
  *P8(param_1 + 0x9d86) = 0;
  return 0 /* AX? */;
}

// 1000:A5C6 FUN_1000_a5c6
static u16 f_a5c6(u8 param_1)

{
  FN(0xA5C6);
  u16 uVar1;
  i16 iVar2;
  u8 local_6;
  u8 local_4;
  
  *P8(0x353b) = 0;
  uVar1 = (u16)param_1;
  *P8(uVar1 + 0x9ddc) = 0;
  if (*P8(uVar1 + 0x8b36) < 2) {
    local_6 = 7;
    if (param_1 == 0) {
      local_4 = 1;
      do {
        if (*PS8(local_4 + 0xae6b) != '\0') {
          iVar2 = f_a6fc(0, (u16)local_4);
          if (iVar2 != 0) {
            local_6 = local_4;
          }
        }
        local_4 = local_4 + 1;
      } while (local_4 < 7);
    }
    else {
      iVar2 = f_a6fc(uVar1, 0);
      if (iVar2 != 0) {
        local_6 = 0;
      }
    }
    if (local_6 < 7) {
      iVar2 = f_7158(local_6);
      if (iVar2 == 0) {
        f_a730(local_6, param_1);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:A65C FUN_1000_a65c
static u16 f_a65c(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xA65C);
  u8 bVar1;
  u8 bVar2;
  u16 uVar3;
  
  uVar3 = f_8986((u16)param_1, param_2);
  if (*P8(param_1 + 0x7596) == uVar3) {
    bVar1 = f_1766(*P8(param_1 + 0x7776), *P8(param_2 + 0x7776));
    bVar2 = f_1766(*P8(param_1 + 0x79ee), *P8(param_2 + 0x79ee));
    if (((bVar1 < 2) || (bVar2 < 2)) &&
       ((u16)bVar1 + (u16)bVar2 <
        (u16)*P8((*P8(param_1 + 0x8b36) & 1) + 0x39c0) + (u16)param_3)) {
      return 1;
    }
  }
  return 0;
}

// 1000:A6FC FUN_1000_a6fc
static u16 f_a6fc(u8 param_1,u8 param_2)

{
  FN(0xA6FC);
  return f_a65c(param_1, param_2, 2);
}

// 1000:A716 FUN_1000_a716
static u16 f_a716(u8 param_1,u8 param_2)

{
  FN(0xA716);
  return f_a65c(param_1, param_2, 1);
}

// 1000:A730 FUN_1000_a730
static u16 f_a730(u8 param_1,u8 param_2)

{
  FN(0xA730);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_b706(param_1);
  if (iVar1 != 0) {
    *P8(param_1 + 0x8947) = *P8(param_2 + 0x8b36);
    iVar1 = f_775c((u16)param_1, (u16)param_2);
    if ((((iVar1 != 0) && (uVar2 = (u16)param_1, *PS8(uVar2 + 0x9d86) != '\0')) &&
        (*P8(uVar2 + 0x8b36) < 2)) &&
       ((*P8(param_2 + 0x8b36) < 2 &&
        ((*P8(uVar2 + 0x9d86) = 0x10, param_2 != 0 ||
         (iVar1 = f_170e(3), iVar1 != 0)))))) {
      f_08c4(0x10);
      *P8(param_2 + 0x9d86) = 0xf;
      return 0 /* AX? */;
    }
    f_a7cc(param_1, param_2);
  }
  return 0 /* AX? */;
}

// 1000:A7CC FUN_1000_a7cc
static u16 f_a7cc(u8 param_1,u8 param_2)

{
  FN(0xA7CC);
  i8a *pcVar1;
  i8 cVar2;
  u16 uVar3;
  i16 iVar4;
  
  if (param_1 == 0) {
    uVar3 = 0x18;
  }
  else {
    uVar3 = 0x14;
  }
  f_08c4(uVar3);
  if ((param_1 != 0) || (*PS8(0x3567) == '\0')) {
    cVar2 = f_18c2((u16)param_1, param_2);
    pcVar1 = PS8(param_1 + 0x9e18);
    *pcVar1 = *pcVar1 + cVar2;
  }
  if (*P8(param_1 + 0x9e18) < 2) {
    *P16((u16)param_1 * 2 + 0xba) = 0x2c;
  }
  iVar4 = f_7108(param_1);
  if ((iVar4 != 0) && (1 < *P8(param_1 + 0x9e18))) {
    f_3aa4();
    f_3b1a(param_1);
  }
  return 0 /* AX? */;
}

// 1000:A850 FUN_1000_a850
static u16 f_a850(void)

{
  FN(0xA850);
  u8 uVar1;
  
  if (*PS16(0x4a) != 0) {
    f_6bc2();
    f_09c6();
    uVar1 = f_bbfe();
    *P8(0x34a9) = uVar1;
  }
  return 0 /* AX? */;
}

// 1000:A864 FUN_1000_a864
static u16 f_a864(void)

{
  FN(0xA864);
  
  if (*PS8(0x342c) == '\0') {
    *P8(0x342c) = 1;
    if (*PS16(0x4a) != 0) {
      *P8(0x342b) = 2;
      *P8(0xae3c) = 0x3c;
      return f_3aa4();
    }
    *P8(0x342b) = 0;
    *P8(0xae3c) = 0;
  }
  return 0 /* AX? */;
}

// 1000:A892 FUN_1000_a892
static u8 f_a892(u8 param_1)

{
  FN(0xA892);
  return param_1;
}

// 1000:A8B2 FUN_1000_a8b2
static u16 f_a8b2(u8 param_1)

{
  FN(0xA8B2);
  i16 iVar1;
  
  iVar1 = f_a948(param_1);
  if (iVar1 != 0) {
    return f_a970(param_1);
  }
  return f_a8e2(param_1);
}

// 1000:A8E2 FUN_1000_a8e2
static u16 f_a8e2(u8 param_1)

{
  FN(0xA8E2);
  i8 cVar1;
  
  cVar1 = *PS8(param_1 + 0x734c);
  if (cVar1 == '\0') {
    return f_aaae(param_1);
  }
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      return f_b11a(param_1);
    }
    if (cVar1 == '\x03') {
      return f_b5ec(param_1);
    }
    if (cVar1 == '\x04') {
      return f_aaac();
    }
    f_068e();
  }
  return f_aa36(param_1);
}

// 1000:A948 FUN_1000_a948
static bool f_a948(u8 param_1)

{
  FN(0xA948);
  i16 iVar1;
  
  iVar1 = f_7108(param_1);
  return iVar1 != 0;
}

// 1000:A970 FUN_1000_a970
static u16 f_a970(u8 param_1)

{
  FN(0xA970);
  i16 iVar1;
  
  iVar1 = f_7108(param_1);
  if (iVar1 != 0) {
    return f_a998(param_1);
  }
  return f_068e();
}

// 1000:A998 FUN_1000_a998
static u16 f_a998(u8 param_1)

{
  FN(0xA998);
  i16 iVar1;
  
  iVar1 = f_b6cc(param_1);
  if (iVar1 != 0) {
    iVar1 = f_7788(0, param_1);
    if (iVar1 == 0) {
      iVar1 = f_b85e(param_1);
      if (iVar1 == 3) {
        f_ae62(param_1);
      }
      else {
        if (*PS8(param_1 + 0x9d90) != '\0') {
          return f_b84c((u16)param_1, 3);
        }
        f_aa36(param_1);
      }
    }
    else {
      f_b11a(param_1);
    }
  }
  return 0 /* AX? */;
}

// 1000:AA12 FUN_1000_aa12
static u16 f_aa12(u8 param_1,u8 param_2)

{
  FN(0xAA12);
  
  *P8(param_1 + 0x734c) = param_2;
  return 0 /* AX? */;
}

// 1000:AA24 FUN_1000_aa24
static u16 f_aa24(u8 param_1,u8 param_2)

{
  FN(0xAA24);
  
  *P8(param_1 + 0x734c) = param_2;
  return 0 /* AX? */;
}

// 1000:AA36 FUN_1000_aa36
static u16 f_aa36(u8 param_1)

{
  FN(0xAA36);
  i16 iVar1;
  u16 uVar2;
  
  f_b84c(param_1, 2);
  f_b91e((u16)param_1, *P8(param_1 + 0xae64));
  iVar1 = f_2276(*P8(param_1 + 0xae64));
  if ((iVar1 != 0) && (*PS16((u16)param_1 * 2 + 0xd6) == 0)) {
    uVar2 = f_ac64((u16)param_1);
    return f_ab12(param_1, uVar2);
  }
  return f_7cac(param_1);
}

// 1000:AAAC FUN_1000_aaac
static u16 f_aaac(void)

{
  FN(0xAAAC);
  return 0 /* AX? */;
}

// 1000:AAAE FUN_1000_aaae
static u16 f_aaae(u8 param_1)

{
  FN(0xAAAE);
  i16 iVar1;
  
  *P8(param_1 + 0xaeac) = 0;
  *P8(param_1 + 0x8134) = 4;
  f_39b4();
  *P8(param_1 + 0xae6b) = 0;
  f_4712();
  if (param_1 == 0) {
    *P8(0x34a8) = 1;
  }
  iVar1 = f_7158(param_1);
  if (iVar1 != 0) {
    f_71aa();
    f_a864();
  }
  return 0 /* AX? */;
}

// 1000:AAF6 FUN_1000_aaf6
static u16 f_aaf6(u8 param_1,u8 param_2)

{
  FN(0xAAF6);
  
  *P8(param_1 + 0x7d80) = param_2;
  return f_abee((u16)param_1);
}

// 1000:AB12 FUN_1000_ab12
static u16 f_ab12(u8 param_1,u8 param_2)

{
  FN(0xAB12);
  i16 iVar1;
  
  iVar1 = f_5b78(param_1, param_2);
  if (iVar1 == 0) {
    f_ab3c(param_1, param_2);
  }
  return 0 /* AX? */;
}

// 1000:AB3C FUN_1000_ab3c
static u16 f_ab3c(u8 param_1,u8 param_2)

{
  FN(0xAB3C);
  u16 uVar1;
  u8 bVar3;
  i16 iVar2;
  u8 local_4;
  
  uVar1 = (u16)param_1;
  *P8(uVar1 + 0x7d80) = param_2;
  *P8(uVar1 + 0x7596) = param_2;
  if ((param_2 & 2) == 0) {
    bVar3 = *P8(param_1 + 0x7776) % 7;
    if (bVar3 == 3) goto LAB_1000_abe2;
    if (bVar3 < 3) {
      local_4 = 2;
    }
    else {
      local_4 = 6;
    }
    iVar2 = f_599a(param_1, local_4);
  }
  else {
    bVar3 = *P8(uVar1 + 0x79ee) % 7;
    if (bVar3 == 3) goto LAB_1000_abe2;
    if (bVar3 < 3) {
      local_4 = 4;
    }
    else {
      local_4 = 0;
    }
    iVar2 = f_599a(param_1, local_4);
  }
  if (iVar2 == 0) {
    return f_573e(param_1);
  }
LAB_1000_abe2:
  return f_abee(param_1);
}

// 1000:ABEE FUN_1000_abee
static u16 f_abee(u8 param_1)

{
  FN(0xABEE);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = (u16)param_1;
  *P8(uVar1 + 0x7596) = *P8(uVar1 + 0x7d80);
  iVar2 = f_599a(uVar1, *P8(uVar1 + 0x7d80));
  if (iVar2 != 0) {
    return f_ac36(param_1);
  }
  return f_7f78((u16)param_1, *P8(param_1 + 0x7d80));
  return 0 /* AX? */;
}

// 1000:AC36 FUN_1000_ac36
static u16 f_ac36(u8 param_1)

{
  FN(0xAC36);
  i16 iVar1;
  
  iVar1 = f_170e(100);
  if (iVar1 < 0x4b) {
    return f_573e(param_1);
  }
  return f_57ea(param_1);
}

// 1000:AC64 FUN_1000_ac64
static u16 f_ac64(u8 param_1)

{
  FN(0xAC64);
  
  if (*PS8(param_1 + 0x9d90) != '\0') {
    return f_8986((u16)param_1, 0);
  }
  return f_ac9a(param_1);
}

// 1000:AC9A FUN_1000_ac9a
static u8 f_ac9a(u8 param_1)

{
  FN(0xAC9A);
  i16 iVar1;
  u16 uVar2;
  u8 local_a;
  u8 local_6;
  u16 local_4;
  
  local_4 = 0;
  local_6 = 0;
  local_a = 0;
  do {
    iVar1 = f_3740(*P8(param_1 + 0xae64), local_a);
    if (iVar1 != 0) {
      iVar1 = f_b85e((u16)param_1);
      uVar2 = f_c43e(*P8(iVar1 + 0x7d88), *PS8((local_a >> 1) + 0x4104) + *P8(param_1 + 0xae64));  // FIX: pushed before the other call (Ghidra lost it)
      if ((local_4 == 0) || (uVar2 < local_4)) {
        local_6 = local_a;
        local_4 = uVar2;
      }
    }
    local_a = local_a + 2;
  } while (local_a < 8);
  return local_6;
}

// 1000:AD2C FUN_1000_ad2c
static u16 f_ad2c(u8 param_1)

{
  FN(0xAD2C);
  i16 iVar1;
  
  iVar1 = f_c380(param_1);
  if (iVar1 != 0) {
    iVar1 = f_c380(param_1);
    if (iVar1 != 0xd) {
      iVar1 = f_c390(param_1);
      if (iVar1 != 0) {
        iVar1 = f_c390(param_1);
        if (iVar1 != 10) {
          return 0;
        }
      }
    }
  }
  return 1;
}

// 1000:AD7A FUN_1000_ad7a
static i16 f_ad7a(u8 param_1)

{
  FN(0xAD7A);
  i16 iVar1;
  
  iVar1 = f_c380(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = f_c380(param_1);
  if (iVar1 == 0xd) {
    return 4;
  }
  iVar1 = f_c390(param_1);
  if (iVar1 == 0) {
    return 6;
  }
  iVar1 = f_c390(param_1);
  if (iVar1 == 10) {
    iVar1 = 2;
  }
  return iVar1;
}

// 1000:ADD4 FUN_1000_add4
static u16 f_add4(u8 param_1)

{
  FN(0xADD4);
  u8 bVar1;
  u16 uVar2;
  i16 iVar3;
  
  if (*PS8(0x353a) != '\x01') {
    iVar3 = f_ad2c(*P8(param_1 + 0xae64));
    if (iVar3 != 0) {
      uVar2 = f_ad7a(*P8(param_1 + 0xae64));
      return uVar2;
    }
    if (*PS8(0x353a) == '\x03') {
      bVar1 = f_8986(0, param_1);
      iVar3 = f_59c2(param_1, bVar1);
      if (iVar3 == 0) {
        return (u16)bVar1;
      }
      uVar2 = f_7c84(param_1, bVar1);
      return uVar2;
    }
  }
  uVar2 = f_ac9a(param_1);
  return uVar2;
}

// 1000:AE62 FUN_1000_ae62
static u16 f_ae62(u8 param_1)

{
  FN(0xAE62);
  u16 uVar1;
  
  uVar1 = f_ac64(param_1);
  return f_ab12(param_1, uVar1);
}

// 1000:AE80 FUN_1000_ae80
static u16 f_ae80(u8 param_1,u8 param_2)

{
  FN(0xAE80);
  i16 iVar1;
  u16 uVar2;
  u16 uVar3;
  
  iVar1 = f_5950(param_1, param_2);
  if (iVar1 == 0) {
    uVar3 = (u16)param_2;
  }
  else {
    uVar2 = f_7c84(param_1, param_2);
    iVar1 = f_5950(param_1, uVar2);
    if (iVar1 != 0) {
      iVar1 = f_170e(*P8(param_1 + 0x7353) + 2);
      if (iVar1 != 0) {
        f_7c54(param_1);
      }
      return 0 /* AX? */;
    }
    uVar3 = f_7c84(param_1, param_2);
  }
  return f_8654(param_1, uVar3);
}

// 1000:AF0C FUN_1000_af0c
static u16 f_af0c(u16 param_1)

{
  FN(0xAF0C);
  i16 iVar1;
  u16 uVar2;
  
  iVar1 = f_b0ea(param_1);
  if (iVar1 != 0) {
    uVar2 = f_7816(5, param_1);
    return uVar2;
  }
  return 0;
}

// 1000:AF30 FUN_1000_af30
static u16 f_af30(i16 param_1)

{
  FN(0xAF30);
  u16 uVar1;
  
  if (*PS8(param_1 + -0x74ca) == '\x01') {
    uVar1 = f_7816(7, param_1);
    return uVar1;
  }
  return 0;
}

// 1000:AF4E FUN_1000_af4e
static u16 f_af4e(u8 param_1)

{
  FN(0xAF4E);
  u8 uVar1;
  u8 uVar2;
  i8 cVar3;
  i8 cVar4;
  i16 iVar5;
  u16 uVar6;
  u16 uVar7;
  u8 local_6;
  u8 local_4;
  
  uVar1 = f_8986(0, param_1);
  iVar5 = f_af0c(param_1);
  if (iVar5 == 0) {
    cVar3 = f_1766(*P8(param_1 + 0x7776), *P8(0x7776));
    if (cVar3 == '\0') {
      local_4 = 8;
    }
    else if (*P8(0x7776) < *P8(param_1 + 0x7776)) {
      local_4 = 6;
    }
    else {
      local_4 = 2;
    }
    cVar4 = f_1766(*P8(param_1 + 0x79ee), *P8(0x79ee));
    if (cVar4 == '\0') {
      local_6 = 8;
    }
    else if (*P8(0x79ee) < *P8(param_1 + 0x79ee)) {
      local_6 = 0;
    }
    else {
      local_6 = 4;
    }
    if ((cVar3 != '\0') && ((cVar4 == '\0' || (*PS8(param_1 + 0xae4c) != '\0')))) {
      local_6 = local_4;
    }
    uVar6 = f_8986(param_1, 0);
    iVar5 = f_59c2(param_1, uVar6);
    if (iVar5 == 0) {
      uVar7 = local_6 & 6;
    }
    else {
      uVar7 = f_7c84(param_1, local_6 & 6);
    }
    return f_ab12(param_1, uVar7);
  }
  uVar2 = f_1c36(uVar1);
  *P8(param_1 + 0x7596) = uVar2;
  return f_ae80(param_1, uVar1);
}

// 1000:B084 FUN_1000_b084
static u16 f_b084(u8 param_1)

{
  FN(0xB084);
  u16 uVar1;
  i16 iVar2;
  
  if (*PS8(param_1 + 0x9d90) != '\0') {
    uVar1 = f_8986((u16)param_1, 0);
    if (*P8(param_1 + 0x7596) == uVar1) {
      iVar2 = f_b706(param_1);
      if (iVar2 != 0) {
        iVar2 = f_0ff4(param_1);
        if (iVar2 != 0) {
          iVar2 = f_af0c(param_1);
          if (iVar2 == 0) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// 1000:B0EA FUN_1000_b0ea
static u16 f_b0ea(u8 param_1)

{
  FN(0xB0EA);
  
  if (1 < *P8(param_1 + 0x8b36)) {
    return 1;
  }
  return 0;
}

// 1000:B102 FUN_1000_b102
static u16 f_b102(u8 param_1)

{
  FN(0xB102);
  
  if (*P8(param_1 + 0x8b36) < 2) {
    return 1;
  }
  return 0;
}

// 1000:B11A FUN_1000_b11a
static u16 f_b11a(u8 param_1)

{
  FN(0xB11A);
  i8 cVar1;
  i16 iVar2;
  
  iVar2 = f_719c();
  if ((iVar2 == 0) || (param_1 != 6)) {
    f_b84c(param_1, 0);
  }
  f_b91e((u16)param_1, *P8(param_1 + 0xae64));
  if ((*PS8(param_1 + 0x9d90) == '\0') && (iVar2 = f_c74c((u16)param_1), iVar2 != 0)) {
    *P8(param_1 + 0x9d97) = 0;
    return f_aa12((u16)param_1, 1);
  }
  cVar1 = *PS8(param_1 + 0x8b36);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    if ((cVar1 == '\x02') || ((cVar1 == '\x03' || (cVar1 == '\x04')))) {
      return f_b2ae(param_1);
    }
    f_068e();
  }
  return f_b1c0(param_1);
}

// 1000:B1C0 FUN_1000_b1c0
static u16 f_b1c0(u8 param_1)

{
  FN(0xB1C0);
  u8 uVar1;
  u16 uVar2;
  i16 iVar3;
  u16 uVar4;
  
  if ((*PS8(param_1 + 0x9d90) != '\0') &&
     (uVar2 = f_8986(0, (u16)param_1), uVar2 != *P8(0x7596))) {
    uVar2 = (u16)param_1;
    *P8(uVar2 + 0xae3e) = 1;
    uVar1 = f_8986(uVar2, 0);
    *P8(uVar2 + 0x7596) = uVar1;
    *P8(param_1 + 0x7d80) = *P8(param_1 + 0x7596);
  }
  iVar3 = f_7788(0, param_1);
  if (iVar3 == 0) {
    *P8(param_1 + 0xaeac) = 0;
    f_ae62((u16)param_1);
  }
  else {
    uVar2 = (u16)param_1;
    *P8(uVar2 + 0xaeac) = 1;
    uVar1 = f_8986(uVar2, 0);
    *P8(uVar2 + 0x7596) = uVar1;
    uVar2 = (u16)param_1;
    *P8(uVar2 + 0x7d80) = *P8(uVar2 + 0x7596);
    iVar3 = f_af30(uVar2);
    if (iVar3 != 0) {
      uVar4 = f_1c36(*P8(param_1 + 0x7596));
      return f_ae80(param_1, uVar4);
    }
    f_b742(param_1);
    if (*PS8(param_1 + 0x9b06) == '\0') {
      f_b334((u16)param_1);
    }
  }
  return 0 /* AX? */;
}

// 1000:B2AE FUN_1000_b2ae
static u16 f_b2ae(u8 param_1)

{
  FN(0xB2AE);
  i8 cVar1;
  i16 iVar2;
  
  iVar2 = f_b084(param_1);
  if (iVar2 == 0) {
    f_a58c(param_1);
    iVar2 = f_b706(param_1);
    if ((iVar2 == 0) || (*PS8(0x353a) != '\x03')) {
      cVar1 = *PS8(param_1 + 0x9d90);
    }
    else {
      cVar1 = *PS8(param_1 + 0x9d90);
    }
    if (cVar1 == '\0') {
      f_ae62(param_1);
    }
    else {
      f_af4e(param_1);
    }
  }
  else {
    f_b742(param_1);
    if (*PS8(param_1 + 0x9b06) == '\0') {
      f_54da((u16)param_1);
    }
  }
  return 0 /* AX? */;
}

// 1000:B334 FUN_1000_b334
static u16 f_b334(u8 param_1)

{
  FN(0xB334);
  i8 cVar1;
  i8 cVar2;
  u16 uVar3;
  u16 uVar4;
  u8 local_6;
  
  if (*PS8(param_1 + 0x8b36) != '\0') goto LAB_1000_b3c5;
  uVar3 = f_8986(0, (u16)param_1);
  if (uVar3 == *P8(0x7596)) {
    uVar3 = f_170e(100);
    if ((u16)*P8(param_1 + 0x7353) * 0xf + 0x3c <= uVar3) goto LAB_1000_b3c5;
    if (*PS16((u16)param_1 * 2 + 0x74) == 0) {
      local_6 = 0x4b;
    }
    else {
      local_6 = 0x19;
    }
    uVar3 = f_170e(100);
    if (local_6 <= uVar3) {
      f_b526(param_1);
      goto LAB_1000_b3c5;
    }
  }
  f_b490(param_1);
LAB_1000_b3c5:
  if (*PS8(param_1 + 0x8b36) == '\x01') {
    uVar3 = f_7c38();
    cVar2 = (i8)((u32)uVar3 % 0x4d);
    cVar1 = (i8)((u32)uVar3 / 0x4d);
    uVar3 = (u16)param_1;
    if ((*PS8(uVar3 + 0x7776) != cVar2) && (*PS8(uVar3 + 0x79ee) != cVar1)) {
      return f_54da(uVar3);
    }
    cVar1 = f_1766(*P8(param_1 + 0x79ee), cVar1);
    cVar2 = f_1766(*P8(param_1 + 0x7776), cVar2);
    if ((u8)(cVar2 + cVar1) < 7) {
      uVar4 = f_1c36(*P8(param_1 + 0x7596));
      f_8654(param_1, uVar4);
    }
    if (7 < (u8)(cVar2 + cVar1)) {
      f_8654((u16)param_1, *P8(param_1 + 0x7596));
    }
  }
  return 0 /* AX? */;
}

// 1000:B490 FUN_1000_b490
static u16 f_b490(u8 param_1)

{
  FN(0xB490);
  u16 uVar1;
  i16 iVar2;
  i16 iVar3;
  
  if (*P8(param_1 + 0x8b36) < 2) {
    uVar1 = f_7c38();
    iVar2 = f_1766(*P8(param_1 + 0x7776), uVar1 % 0x4d);
    iVar3 = f_1766(*P8(param_1 + 0x79ee), uVar1 / 0x4d);
    if ((iVar2 == 0) || (iVar3 == 0)) {
      return f_8654((u16)param_1, *P8(param_1 + 0x7596));
    }
  }
  return f_54da(param_1);
}

// 1000:B526 FUN_1000_b526
static u16 f_b526(u8 param_1)

{
  FN(0xB526);
  u8 uVar1;
  u8 uVar2;
  u16 uVar3;
  i16 iVar4;
  i16 iVar5;
  i16 iVar6;
  u16 uVar7;
  
  uVar3 = f_7c38();
  uVar1 = f_1766(*P8(param_1 + 0x7776), (i8)((u32)uVar3 % 0x4d));
  uVar2 = f_1766(*P8(param_1 + 0x79ee), (i8)((u32)uVar3 / 0x4d));
  iVar4 = f_1a26(7);
  iVar5 = f_1a26(uVar2);
  iVar6 = f_1a26(uVar1);
  if (iVar6 + iVar5 < iVar4) {
    iVar4 = f_170e(100);
    if (iVar4 < 0x4b) {
      uVar7 = f_1c36(*P8(param_1 + 0x7596));
      return f_8654(param_1, uVar7);
    }
    f_55fc(param_1);
  }
  return 0 /* AX? */;
}

// 1000:B5EC FUN_1000_b5ec
static u16 f_b5ec(u8 param_1)

{
  FN(0xB5EC);
  u8 bVar1;
  i16 iVar2;
  u16 uVar3;
  
  iVar2 = f_c74c(param_1);
  if (iVar2 != 0) {
    return f_8580(param_1);
  }
  iVar2 = f_1c66(param_1);
  if (iVar2 != 0) {
    f_b84c(param_1, 0);
    f_aa12(param_1, 2);
    bVar1 = f_170e(8);
    *P8(param_1 + 0x7d80) = bVar1 & 6;
    *P8(param_1 + 0x7596) = *P8(param_1 + 0x7d80);
    return 0 /* AX? */;
  }
  uVar3 = f_add4(param_1);
  return f_ab12(param_1, uVar3);
}

// 1000:B68A FUN_1000_b68a
static u16 f_b68a(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xB68A);
  u8 bVar1;
  u16 uVar2;
  
  bVar1 = f_1b80(param_1, param_2, param_3);
  if (bVar1 != 100) {
    uVar2 = f_170e(100);
    if (bVar1 <= uVar2) {
      return 0;
    }
  }
  return 1;
}

// 1000:B6CC FUN_1000_b6cc
static u16 f_b6cc(u8 param_1)

{
  FN(0xB6CC);
  
  if ((param_1 != 0) &&
     ((*PS16((u16)param_1 * 2 + 0x730c) + 0x18U <= *P16(0x50) ||
      (*PS16(0x50) + 200U <= *P16((u16)param_1 * 2 + 0x730c))))) {
    return 0;
  }
  return 1;
}

// 1000:B706 FUN_1000_b706
static u16 f_b706(u8 param_1)

{
  FN(0xB706);
  
  if ((param_1 != 0) &&
     ((*P16((u16)param_1 * 2 + 0x730c) <= *P16(0x50) ||
      (*PS16(0x50) + 200U <= *PS16((u16)param_1 * 2 + 0x730c) + 8U)))) {
    return 0;
  }
  return 1;
}

// 1000:B742 FUN_1000_b742
static u16 f_b742(u8 param_1)

{
  FN(0xB742);
  u8 uVar1;
  u8 uVar2;
  i16 iVar3;
  u16 uVar4;
  i16 iVar5;
  
  if (*P8(param_1 + 0x8b36) < 2) {
    uVar4 = f_7c38();
    uVar1 = f_1766(*P8(param_1 + 0x7776), (i8)((u32)uVar4 % 0x4d));
    uVar2 = f_1766(*P8(param_1 + 0x79ee), (i8)((u32)uVar4 / 0x4d));
    uVar4 = (u16)param_1;
    if (*PS8(uVar4 + 0x8b36) == '\x01') {
      if ((*PS8(uVar4 + 0x7776) != *PS8(0x7776)) &&
         (*PS8(uVar4 + 0x79ee) != *PS8(0x79ee))) {
        return 0 /* AX? */;
      }
      iVar3 = f_1766(*P8(param_1 + 0x79ee), *P8(0x79ee));
      iVar5 = f_1766(*P8(param_1 + 0x7776), *P8(0x7776));
      if (iVar5 + iVar3 < 7) {
        return 0 /* AX? */;
      }
    }
    iVar3 = f_b68a(param_1, uVar1, uVar2);
    if (iVar3 == 0) {
      return 0 /* AX? */;
    }
  }
  else {
    iVar3 = f_b706((u16)param_1);
    if (iVar3 == 0) {
      return 0 /* AX? */;
    }
    iVar3 = f_170e(100);
    if (0x18 < iVar3) {
      return 0 /* AX? */;
    }
  }
  return f_a440(param_1);
}

// 1000:B84C FUN_1000_b84c
static u16 f_b84c(u8 param_1,u8 param_2)

{
  FN(0xB84C);
  
  *P8(param_1 + 0x774f) = param_2;
  return 0 /* AX? */;
}

// 1000:B85E FUN_1000_b85e
static u8 f_b85e(i16 param_1)

{
  FN(0xB85E);
  
  return *P8(param_1 + 0x774f);
}

// 1000:B86C FUN_1000_b86c
static u16 f_b86c(u8 param_1,u8 param_2)

{
  FN(0xB86C);
  u8 local_8;
  u8 local_6;
  
  if (param_1 == 0) {
    local_6 = 1;
    do {
      *P8(local_6 + 0x9d90) = 0;
      local_6 = local_6 + 1;
    } while (local_6 < 7);
  }
  else {
    *P8(param_1 + 0x9d90) = 0;
  }
  *P8(0xae3d) = 0;
  *P8(0x39c4) = 0;
  f_2dc6(param_1, param_2);
  local_8 = 0;
  do {
    f_b8da(param_1, param_2, local_8);
    local_8 = local_8 + 2;
  } while (local_8 < 8);
  return 0 /* AX? */;
}

// 1000:B8DA FUN_1000_b8da
static u16 f_b8da(u8 param_1,i8 param_2,u8 param_3)

{
  FN(0xB8DA);
  i16 iVar1;
  u8 local_4;
  
  local_4 = param_2;
  while( true ) {
    iVar1 = f_2ae0(local_4, param_3);
    if (iVar1 == 0) break;
    local_4 = local_4 + *PS8((param_3 >> 1) + 0x4104);
    f_2dc6(param_1, local_4);
  }
  return 0 /* AX? */;
}

// 1000:B91E FUN_1000_b91e
static u16 f_b91e(u8 param_1,u8 param_2)

{
  FN(0xB91E);
  u8 bVar1;
  u16 uVar2;
  u8 local_8;
  
  if (*PS8(0x3434) == '\0') {
    f_2eb6(param_1, param_2);
    local_8 = 0;
    do {
      f_b9bc(param_1, param_2, local_8);
      local_8 = local_8 + 2;
    } while (local_8 < 8);
  }
  uVar2 = (u16)param_1;
  if (*PS8(uVar2 + 0x9e24) != '\0') {
    if (*PS8(uVar2 + 0x9d90) == '\0') {
      *P8(param_1 + 0x8b36) = 0;
    }
    else {
      bVar1 = f_75c4(0, uVar2);
      if (0xd < bVar1) {
        *P8(param_1 + 0x8b36) = 4;
        *P8(param_1 + 0x9b8d) = 0;
      }
      if (bVar1 < 9) {
        *P8(param_1 + 0x8b36) = 0;
        *P8(param_1 + 0x9b8d) = 1;
        return 0 /* AX? */;
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:B9BC FUN_1000_b9bc
static u16 f_b9bc(u8 param_1,i8 param_2,u8 param_3)

{
  FN(0xB9BC);
  i16 iVar1;
  u8 local_4;
  
  local_4 = param_2;
  while( true ) {
    iVar1 = f_2ae0(local_4, param_3);
    if (iVar1 == 0) break;
    local_4 = local_4 + *PS8((param_3 >> 1) + 0x4104);
    f_2eb6(param_1, local_4);
  }
  return 0 /* AX? */;
}

// 1000:BA00 FUN_1000_ba00
static u16 f_ba00(void)

{
  FN(0xBA00);
  i16 iVar1;
  u8 local_6;
  
  local_6 = 1;
  do {
    iVar1 = f_6af2(0, local_6);
    if (iVar1 != 0) {
      if (*PS8(local_6 + 0x734c) == '\x01') {
        f_aa12((u16)local_6, 2);
      }
      f_c492();
    }
    local_6 = local_6 + 1;
  } while (local_6 < 7);
  return 0 /* AX? */;
}

// 1000:BA4C FUN_1000_ba4c
static u16 f_ba4c(i8 param_1,u8 param_2)

{
  FN(0xBA4C);
  
  if (param_1 == '\0') {
    if (*PS8(param_2 + 0x734c) == '\x01') {
      f_aa12((u16)param_2, 2);
    }
    if (*PS8(param_2 + 0x9d90) == '\0') {
      *P8(0x39c4) = 1;
    }
    *P8(param_2 + 0x9d90) = 1;
    f_c492();
  }
  return 0 /* AX? */;
}

// 1000:BA90 FUN_1000_ba90
static u16 f_ba90(void)

{
  FN(0xBA90);
  u16 uVar1;
  i16 iVar2;
  u8 local_4;
  
  local_4 = 1;
  do {
    if (6 < local_4) {
      return 0 /* AX? */;
    }
    uVar1 = (u16)local_4;
    if ((*PS8(uVar1 + 0xae6b) != '\0') &&
       ((*PS8(uVar1 + 0x734c) == '\x02' || (*PS8(uVar1 + 0x734c) == '\x01')))) {
      iVar2 = f_6ac8(local_4);
      if (iVar2 == 0) {
        if (*PS8(local_4 + 0x72d0) == '\0') {
          f_bb46(local_4);
        }
        else if ((*PS8(0x3434) == '\0') && (*PS16((u16)local_4 * 2 + 0x66) == 0))
        goto LAB_1000_bacb;
      }
      else {
        if (*PS8(0x3434) == '\0') {
          f_aa12(local_4, 2);
        }
        else {
          f_3d1a();
        }
        uVar1 = (u16)local_4;
        if ((*PS8(uVar1 + 0x9dd5) == '\0') && (*PS16(uVar1 * 2 + 0x66) == 0)) {
          *P8(uVar1 + 0x9dd5) = 1;
LAB_1000_bacb:
          f_3d1a();
        }
      }
    }
    local_4 = local_4 + 1;
  } while( true );
  return 0 /* AX? */;
}

// 1000:BB46 FUN_1000_bb46
static u16 f_bb46(i16 param_1)

{
  FN(0xBB46);
  i16 iVar1;
  
  if (*PS8(0x3434) == '\0') {
    iVar1 = f_bb7e();
  }
  else {
    iVar1 = f_bb6a();
  }
  *PS16(param_1 * 2 + 0x66) = iVar1 << (*P8(0x342a) & 0x1f);
  return 0 /* AX? */;
}

// 1000:BB6A FUN_1000_bb6a
static u32 f_bb6a(void)

{
  FN(0xBB6A);
  i32 lVar1;
  
  lVar1 = (u32)-(*P8(0x355c) - 7) * 0x1e;
  return CONCAT22((i16)((u32)lVar1 >> 0x10),(i16)lVar1 + 0x3c);
}

// 1000:BB7E FUN_1000_bb7e
static u32 f_bb7e(void)

{
  FN(0xBB7E);
  i32 lVar1;
  
  lVar1 = (u32)-(*P8(0x355c) - 7) * 0x1e;
  return CONCAT22((i16)((u32)lVar1 >> 0x10),(i16)lVar1 + 0xb4);
}

// 1000:BB92 FUN_1000_bb92  FIX: returns AL zero-extended (u8, not Ghidra's i8)
static u8 f_bb92(void)

{
  FN(0xBB92);
  u16 uVar1;
  u8 local_6;
  u8 local_4;
  
  local_6 = '\0';
  local_4 = 1;
  do {
    uVar1 = (u16)local_4;
    if (((*PS8(uVar1 + 0xae6b) != '\0') && (*PS8(uVar1 + 0x734c) != '\0')) &&
       (*PS8(uVar1 + 0x9dd5) != '\0')) {
      local_6 = local_6 + '\x01';
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  return local_6;
}

// 1000:BBD0 FUN_1000_bbd0
static u16 f_bbd0(void)

{
  FN(0xBBD0);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P8(local_4 + 0x39c6) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return 0 /* AX? */;
}

// 1000:BBF0 FUN_1000_bbf0
static u16 f_bbf0(void)

{
  FN(0xBBF0);
  u8 uVar1;
  
  uVar1 = f_bb92();
  *P8(*P8(0x3558) + 0x39c6) = uVar1;
  return 0 /* AX? */;
}

// 1000:BBFE FUN_1000_bbfe
static u16 f_bbfe(void)

{
  FN(0xBBFE);
  
  f_bbf0();
  if ((((*PS8(0x34a8) == '\0') && (*PS8(0x39c6) == '\0')) && (*PS8(0x39c7) == '\0')) &&
     (*PS8(0x39c8) == '\0')) {
    return 0;
  }
  return 1;
}

// 1000:BC26 FUN_1000_bc26
static u16 f_bc26(u8 param_1)

{
  FN(0xBC26);
  u8 uVar1;
  
  if ((*PS8(0x3450) != '\x05') && (*PS8(0x353a) == '\x01')) {
    uVar1 = f_7130();
    *P8(param_1 + 0x9dd5) = uVar1;
    return 0 /* AX? */;
  }
  *P8(param_1 + 0x9dd5) = 1;
  return 0 /* AX? */;
}

// 1000:BC52 FUN_1000_bc52  FIX: the command keys (Alt-Q quit, Alt-J joystick, Alt-V sound, Space pause) come
// from the BIOS keyboard buffer through the MISC driver; the simulation has none
static u16 f_bc52(void)
{
  FN(0xBC52);
  return 0;
}

// 1000:BCCC FUN_1000_bccc
static u16 f_bccc(u16 param_1,u8 param_2)

{
  FN(0xBCCC);
  u16 uVar1;
  i16 iVar2;
  
  iVar2 = (u16)param_2 * 2;
  uVar1 = *P16((u16)param_2 * 8 + 0x75a4);
  *P16(iVar2 + -0x64d0) = uVar1;
  f_8d3c(param_1, uVar1, *P16(iVar2 + 0x72f4), *P16(iVar2 + 0x7328));
  return f_8f64(param_2 + 0xe);
}

// 1000:BD10 FUN_1000_bd10
static u16 f_bd10(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xBD10);
  i16 iVar1;
  
  iVar1 = f_bec2(param_1);
  if (iVar1 != 0) {
    f_a19e(param_1 + 0xe, param_2, param_3);
  }
  iVar1 = f_bec2(param_1);
  if (iVar1 == 1) {
    f_befc(param_1, 0);
  }
  return 0 /* AX? */;
}

// 1000:BD5C FUN_1000_bd5c
static u16 f_bd5c(u8 param_1,u8 param_2)

{
  FN(0xBD5C);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = f_66b6();
  if (uVar1 == param_2) {
    iVar2 = f_be1a((u16)param_2);
    if (iVar2 == 0) {
      f_a19e(param_2 + 0xe, 4, param_1);
    }
  }
  return 0 /* AX? */;
}

// 1000:BD96 FUN_1000_bd96
static u16 f_bd96(u8 param_1)

{
  FN(0xBD96);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_bd5c(param_1, local_4);
    local_4 = local_4 + 1;
  } while (local_4 < 9);
  return 0 /* AX? */;
}

// 1000:BDBE FUN_1000_bdbe
static u16 f_bdbe(void)

{
  FN(0xBDBE);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P8((u16)local_4 * 8 + 0x75a2) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 9);
  *P16(0x75a4) = 0;
  *P16(0x75ac) = 0x170;
  *P16(0x75b4) = 0x16b;
  *P16(0x75c4) = 0x171;
  *P16(0x75cc) = 0x16e;
  *P16(0x75e4) = 0x172;
  *P16(0x75dc) = 0x16c;
  *P16(0x75d4) = 0x16f;
  *P16(0x75bc) = 0x16d;
  return 0 /* AX? */;
}

// 1000:BE1A FUN_1000_be1a
static u8 f_be1a(u8 param_1)

{
  FN(0xBE1A);
  
  return *P8((u16)param_1 * 8 + 0x759e);
}

// 1000:BE2E FUN_1000_be2e
static u16 f_be2e(u8 param_1,u8 param_2,u16 param_3,u8 param_4)

{
  FN(0xBE2E);
  i16 iVar1;
  i16 iVar2;
  
  iVar2 = (u16)param_1 * 8;
  *P8(iVar2 + 0x759e) = 1;
  *P8(iVar2 + 0x759f) = param_2;
  *P16(iVar2 + 0x75a0) = param_3;
  iVar1 = (u16)param_1 * 2;
  *PS16(iVar1 + 0x72f4) = (param_3 % 0x4d) * 4;
  *PS16(iVar1 + 0x7328) = param_3 / 0x4d << 2;
  *P8(iVar2 + 0x75a2) = param_4;
  if (param_1 == 2) {
    f_be2e(7, param_2, param_3, param_4);
  }
  return 0 /* AX? */;
}

// 1000:BEAE FUN_1000_beae
static u16 f_beae(u8 param_1)

{
  FN(0xBEAE);
  
  *P8((u16)param_1 * 8 + 0x759e) = 0;
  return 0 /* AX? */;
}

// 1000:BEC2 FUN_1000_bec2
static u8 f_bec2(u8 param_1)

{
  FN(0xBEC2);
  
  return *P8((u16)param_1 * 8 + 0x75a2);
}

// 1000:BED6 FUN_1000_bed6
static u8 f_bed6(u8 param_1)

{
  FN(0xBED6);
  
  return *P8((u16)param_1 * 8 + 0x759f);
}

// 1000:BEEA FUN_1000_beea
static u16 f_beea(u8 param_1)

{
  FN(0xBEEA);
  
  return *P16((u16)param_1 * 8 + 0x75a0);
}

// 1000:BEFC FUN_1000_befc
static u16 f_befc(u8 param_1,u8 param_2)

{
  FN(0xBEFC);
  
  *P8((u16)param_1 * 8 + 0x75a2) = param_2;
  return 0 /* AX? */;
}

// 1000:BF12 FUN_1000_bf12
static u16 f_bf12(u8 param_1,u8 param_2)

{
  FN(0xBF12);
  i16 iVar1;
  u16 uVar2;
  u16 uVar3;
  
  iVar1 = f_be1a(param_2);
  if (iVar1 != 0) {
    uVar2 = f_bed6(param_2);
    if (uVar2 == *P8(0x3558)) {
      uVar3 = f_beea(param_2);
      uVar3 = f_8a34(uVar3);
      iVar1 = f_221c(uVar3);
      if (iVar1 != 0) {
        iVar1 = f_bec2(param_2);
        if (iVar1 == 2) {
          f_bccc(param_1, param_2);
        }
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:BF7C FUN_1000_bf7c
static u16 f_bf7c(u8 param_1,u8 param_2)

{
  FN(0xBF7C);
  i8 cVar1;
  
  if (0x99 < param_2) {
    return 0 /* AX? */;
  }
  cVar1 = *PS8(0x353a);
  if (cVar1 == '\x01') {
    f_c1ae(param_1, param_2);
    f_bfe0(param_1, param_2);
  }
  else if (cVar1 == '\x02') {
    f_c810(param_1, param_2);
  }
  else {
    if (cVar1 != '\x03') {
      return 0 /* AX? */;
    }
    f_d5dc(param_1, param_2);
  }
  return 0 /* AX? */;
}

// 1000:BFE0 FUN_1000_bfe0
static u16 f_bfe0(u8 param_1,u8 param_2)

{
  FN(0xBFE0);
  i16 iVar1;
  
  iVar1 = f_221c(param_2);
  if (iVar1 != 0) {
    iVar1 = f_2366(param_2);
    if (iVar1 != 0) {
      i16 x = (i16)f_c380(param_2) * 0x1c + 0xe;  // FIX: pushed before the other calls (Ghidra lost them)
      i16 y = (i16)f_c390(param_2) * 0x1c + 0xe;
      iVar1 = f_2366(param_2);
      f_8d3c(param_1, (iVar1 + -1) % 0xd + 0x18d, y, x);
    }
  }
  return 0 /* AX? */;
}

// 1000:C054 FUN_1000_c054
static u16 f_c054(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xC054);
  f_8d3c(param_1, (param_2 == 0 || param_3 == 0) + 0x18b, (u16)param_3 * 0x1c, (u16)param_2 * 0x1c);
  f_8d3c(param_1, (param_2 == 0 || param_3 == 10) + 0x18b, (u16)param_3 * 0x1c + 0x1c, (u16)param_2 * 0x1c);
  f_8d3c(param_1, (param_2 == 0xd || param_3 == 0) + 0x18b, (u16)param_3 * 0x1c, (u16)param_2 * 0x1c + 0x1c);
  return f_8d3c(param_1, (param_2 == 0xd || param_3 == 10) + 0x18b, (u16)param_3 * 0x1c + 0x1c, (u16)param_2 * 0x1c + 0x1c);
  return 0 /* AX? */;
}

// 1000:C148 FUN_1000_c148
static i16 f_c148(u16 param_1)

{
  FN(0xC148);
  i16 iVar1;
  u16 uVar2;
  u16 local_4;
  
  iVar1 = f_2276(param_1);
  if (iVar1 == 0) {
    if (*PS8(0x3558) == '\0') {
      local_4 = 0x177;
    }
    else if (*PS8(0x3558) == '\x01') {
      local_4 = 0x178;
    }
    else {
      iVar1 = f_2696(param_1);
      if (iVar1 == 0) {
        local_4 = 0x179;
      }
      else {
        local_4 = 0x17a;
      }
    }
  }
  else {
    uVar2 = f_2276(param_1);
    local_4 = (uVar2 & 3) + 0x17d;
  }
  return local_4;
}

// 1000:C1AE FUN_1000_c1ae
static u16 f_c1ae(u8 param_1,u8 param_2)

{
  FN(0xC1AE);
  u8 uVar1;
  u8 uVar2;
  i8 cVar3;
  i16 iVar4;
  u8 local_10;
  u16 local_4;
  
  uVar1 = f_c380(param_2);
  uVar2 = f_c390(param_2);
  local_4 = f_c148(param_2);
  iVar4 = f_221c(param_2);
  if (iVar4 != 0) {
    iVar4 = f_23ac(param_2);
    if (iVar4 != 0) {
      f_9584(param_1, uVar1, uVar2, local_4);
      local_4 = 0x17b;
      if (*P16((u16)*P8(0x3558) * 2 + 0x3544) == (u16)param_2) {
        local_4 = 0x17c;
      }
    }
    f_9584(param_1, uVar1, uVar2, local_4);
    if (param_2 == *P8(0xae06)) {
      f_6fe0();
    }
    f_96bc(param_1, param_2);
  }
  local_10 = 0;
  do {
    cVar3 = f_20f2(param_2, local_10);
    if ((cVar3 == '\x01') || (cVar3 == '\x02')) {
      f_6408(uVar1, uVar2, local_10);
    }
    iVar4 = f_221c(param_2);
    if ((iVar4 != 0) && (cVar3 != '\0')) {
      f_6148(param_1, uVar1, uVar2, local_10);
    }
    local_10 = local_10 + 2;
  } while (local_10 < 8);
  f_5c70(uVar1, uVar2);
  iVar4 = f_221c(param_2);
  if (iVar4 != 0) {
    f_c054(param_1, uVar1, uVar2);
  }
  return 0 /* AX? */;
}

// 1000:C324 FUN_1000_c324
static u16 f_c324(void)

{
  FN(0xC324);
  u8 local_8;
  
  local_8 = 0;
  do {
    *P8(local_8 + 0x9cec) = local_8 / 0xb;
    *P8(local_8 + 0x895c) = local_8 % 0xb;
    *P8((u16)(local_8 % 0xb) + (u16)(local_8 / 0xb) * 0xb + -0x61d4) = local_8;
    local_8 = local_8 + 1;
  } while (local_8 < 0x9a);
  return 0 /* AX? */;
}

// 1000:C380 FUN_1000_c380
static u8 f_c380(u8 param_1)

{
  FN(0xC380);
  
  return *P8(param_1 + 0x9cec);
}

// 1000:C390 FUN_1000_c390
static u8 f_c390(u8 param_1)

{
  FN(0xC390);
  
  return *P8(param_1 + 0x895c);
}

// 1000:C3A0 FUN_1000_c3a0
static u8 f_c3a0(u8 param_1,u8 param_2)

{
  FN(0xC3A0);
  
  return *P8((u16)param_2 + (u16)param_1 * 0xb + -0x61d4);
}

// 1000:C3C2 FUN_1000_c3c2
static u16 f_c3c2(u8 param_1)

{
  FN(0xC3C2);
  u16 uVar1;
  
  uVar1 = (u16)param_1;
  *PS8(uVar1 + 0x9b02) = param_1 * '\x02';
  *PS8(uVar1 + 0x7d88) = param_1 * '\x02' + '\x01';
  *P8(uVar1 + 0x777e) = 0;
  return 0 /* AX? */;
}

// 1000:C3EC FUN_1000_c3ec
static u16 f_c3ec(void)

{
  FN(0xC3EC);
  u8 local_4;
  
  local_4 = '\x04';
  do {
    local_4 = local_4 + -1;
    f_c3c2(local_4);
  } while (local_4 != '\0');
  return 0 /* AX? */;
}

// 1000:C410 FUN_1000_c410
static u16 f_c410(void)

{
  FN(0xC410);
  u8 uVar1;
  u16 uVar2;
  
  uVar2 = (u16)*P8(0x7756);
  uVar1 = *P8(uVar2 + 0x9b02);
  *P8(uVar2 + 0x9b02) = *P8(uVar2 + 0x7d88);
  *P8(uVar2 + 0x7d88) = uVar1;
  *P8(uVar2 + 0x777e) = 1;
  return 0 /* AX? */;
}

// 1000:C43E FUN_1000_c43e
static u32 f_c43e(u8 param_1,u8 param_2)

{
  FN(0xC43E);
  
  return CONCAT22(param_1 / 0xd5,
                  *P16((u16)param_2 * 2 + (u16)param_1 * 0x134 + -0x6eb4));
}

// 1000:C45C FUN_1000_c45c
static u16 f_c45c(u8 param_1,u8 param_2,u16 param_3)

{
  FN(0xC45C);
  
  *P16((u16)param_2 * 2 + (u16)param_1 * 0x134 + -0x6eb4) = param_3;
  return 0 /* AX? */;
}

// 1000:C47E FUN_1000_c47e
static u16 f_c47e(void)

{
  FN(0xC47E);
  
  return f_c498(0, *P8(0xae64), 7);
}

// 1000:C492 FUN_1000_c492
static u16 f_c492(void)

{
  FN(0xC492);
  
  *P8(0x46a8) = 1;
  return 0 /* AX? */;
}

// 1000:C498 FUN_1000_c498  FIX: param_2 is zero-extended (u8, not Ghidra's i8)
static u16 f_c498(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xC498);
  
  *P8(0x7756) = param_1;
  *P8(0x9d9e) = param_3;
  if (*PS8(*P8(0x7756) + 0x777e) == '\0') {
    f_c5d8();
  }
  else if ((*PS8(0x46a8) != '\0') && (param_2 != *P8(0x46a9))) {
    f_c4e0(param_2);
    *PS8(0x46a9) = param_2;
    *P8(0x46a8) = 0;
    return 0 /* AX? */;
  }
  return 0 /* AX? */;
}

// 1000:C4E0 FUN_1000_c4e0
static u16 f_c4e0(u8 param_1)

{
  FN(0xC4E0);
  u8 bVar1;
  u8 uVar2;
  i16 iVar3;
  i16 iVar4;
  u16 uVar5;
  u8 local_6;
  u8 local_4;
  
  *P8(*P8(0x7756) + 0x777e) = 0;
  f_3856();
  for (local_6 = 0; local_6 < 0x9a; local_6 = local_6 + 1) {
    f_c45c(*P8(*P8(0x7756) + 0x9b02), local_6, 0);
    if (*PS8(0x7756) == '\0') {
      iVar3 = f_3356(local_6);
      iVar4 = f_32c4(local_6);
      iVar4 = iVar4 + iVar3;
    }
    else {
      iVar4 = 1;
    }
    f_330c(local_6, iVar4);
  }
  local_4 = 1;
  do {
    if (*PS8(local_4 + 0xae6b) != '\0') {
      iVar4 = f_7108((u16)local_4);
      if (iVar4 == 0) {
        f_3320(*P8(local_4 + 0xae64), 100);
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 7);
  bVar1 = *P8(0x7756);
  uVar5 = (u16)bVar1;
  *P8(uVar5 + 0x8be0) = 0;
  *P8(uVar5 + 0x7782) = 0;
  *P8(uVar5 + 0x9e20) = param_1;
  uVar2 = *P8(uVar5 + 0x8be0);
  *PS8(uVar5 + 0x8be0) = *PS8(uVar5 + 0x8be0) + '\x01';
  *P8(CONCAT11(bVar1,uVar2) + -0x7ea0) = param_1;
  return f_c45c(*P8(uVar5 + 0x9b02), param_1, 1);
  return 0 /* AX? */;
}

// 1000:C5D8 FUN_1000_c5d8
static u16 f_c5d8(void)

{
  FN(0xC5D8);
  i8 cVar1;
  i8 cVar2;
  i16 iVar3;
  i16 iVar4;
  i16 iVar5;
  u16 uVar6;
  u8 local_c;
  u8 local_a;
  
  local_c = 0;
  do {
    uVar6 = (u16)*P8(0x7756);
    cVar1 = *PS8(uVar6 * 0x100 + (*P16(uVar6 + 0x7782) & 0xff) + -0x7ea0);
    *PS8(uVar6 + 0x7782) = *PS8(uVar6 + 0x7782) + '\x01';
    local_a = 0;
    do {
      iVar3 = f_3740(cVar1, (u16)local_a << 1);
      if (iVar3 != 0) {
        cVar2 = *PS8(local_a + 0x4104) + cVar1;
        iVar3 = f_32fc(cVar2);
        iVar4 = f_c43e(*P8(*P8(0x7756) + 0x9b02), cVar1);
        iVar5 = f_c43e(*P8(*P8(0x7756) + 0x9b02), cVar2);
        if ((iVar5 == 0) ||
           (uVar6 = f_c43e(*P8(*P8(0x7756) + 0x9b02), cVar2),
           (u16)(iVar4 + iVar3) < uVar6)) {
          f_c45c(*P8(*P8(0x7756) + 0x9b02), cVar2, iVar4 + iVar3);
          uVar6 = (u16)*P8(0x7756);
          *PS8(uVar6 * 0x100 + (*P16(uVar6 + 0x8be0) & 0xff) + -0x7ea0) = cVar2;
          *PS8(uVar6 + 0x8be0) = *PS8(uVar6 + 0x8be0) + '\x01';
          *PS8(uVar6 + 0x737a) = cVar2;
          local_c = local_c + 1;
        }
      }
      local_a = local_a + 1;
    } while (local_a < 4);
  } while ((*PS8(*P8(0x7756) + 0x7782) != *PS8(*P8(0x7756) + 0x8be0)) &&
          (local_c < *P8(0x9d9e)));
  uVar6 = (u16)*P8(0x7756);
  if (*PS8(uVar6 + 0x7782) == *PS8(uVar6 + 0x8be0)) {
    *P8(uVar6 + 0x893c) = *P8(uVar6 + 0x737a);
    f_c410();
  }
  return 0 /* AX? */;
}

// 1000:C722 FUN_1000_c722
static u16 f_c722(u8 param_1,u8 param_2)

{
  FN(0xC722);
  
  *P8(0x7756) = param_1;
  f_c4e0(param_2);
  while (*PS8(*P8(0x7756) + 0x777e) == '\0') {
    f_c5d8();
  }
  return 0 /* AX? */;
}

// 1000:C74C FUN_1000_c74c
static u16 f_c74c(u8 param_1)

{
  FN(0xC74C);
  i16 iVar1;
  
  iVar1 = f_b85e((u16)param_1);
  if (*PS8(iVar1 + -0x61e0) == *PS8(param_1 + 0xae64)) {
    return 1;
  }
  return 0;
}

// 1000:C776 FUN_1000_c776
static u16 f_c776(u16 param_1)

{
  FN(0xC776);
  
  return f_c43e(*P8(0x7d88), param_1);
}

// 1000:C798 FUN_1000_c798
static u16 f_c798(void)

{
  FN(0xC798);
  
  *P8(0x812e) = 0;
  f_a02a();
  f_26e8();
  return f_a054();
}

// 1000:C7A8 FUN_1000_c7a8
static u16 f_c7a8(void)

{
  FN(0xC7A8);
  f_c798();
  f_d648(0);
  f_d648(2);
  f_d648(4);
  f_d6f0();
  f_2898();
  f_d620(4, 2);
  f_d620(4, 0);
  return f_a054();
}

// 1000:C7F6 FUN_1000_c7f6
static u16 f_c7f6(u16 param_1)

{
  FN(0xC7F6);
  if ((0x1a7 < param_1) && (param_1 < 0x1ba)) {
    return 1;
  }
  return 0;
}

// 1000:C810 FUN_1000_c810
static u16 f_c810(u8 param_1,u8 param_2)

{
  FN(0xC810);
  u8 uVar1;
  u8 uVar2;
  
  uVar1 = f_c380(param_2);
  uVar2 = f_c390(param_2);
  f_c856(param_1, uVar1, uVar2);
  return f_96bc(param_1, param_2);
}

// 1000:C856 FUN_1000_c856
static u16 f_c856(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xC856);
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  i16 iVar4;
  i16 iVar5;
  u16 uVar6;
  u8 local_e;
  u8 local_c;
  
  iVar4 = f_a122(param_2, param_3);
  bVar2 = f_c3a0(param_2, param_3);
  bVar3 = f_3334(bVar2);
  bVar1 = *P8(bVar3 + 0x48e4);
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    for (local_e = 0; local_e < 7; local_e = local_e + 1) {
      iVar5 = f_a114(local_c, local_e);
      f_a0ba(iVar5 + iVar4, *P8((u16)bVar1 * 0x31 + (u16)local_e * 7 + (u16)local_c + 0x420e));
    }
  }
  if ((bVar3 == 8) || (bVar3 == 5)) {
    f_2298(bVar2, 0);
    f_9584(param_1, param_2, param_3, 0x1ba);
    for (local_c = 0; local_c < 8; local_c = local_c + 2) {
      iVar4 = f_20f2(bVar2, local_c);
      if (iVar4 != 0) {
        f_6468(bVar2, local_c);
      }
    }
  }
  else if (bVar3 < 3) {
    f_2298(bVar2, 1);
    for (local_c = 0; local_c < 8; local_c = local_c + 2) {
      f_215c(bVar2, local_c, 1);
      f_6468(bVar2, local_c);
      uVar6 = f_1c36(local_c);
      f_6468((i16)*PS8((local_c >> 1) + 0x4104) + (u16)bVar2, uVar6);
    }
  }
  else {
    f_2298(bVar2, 0);
  }
  if (bVar3 == 3) {
    f_9584(param_1, param_2, param_3, 0x1ba);
    f_9584(param_1, param_2, param_3, 0x1c1);
  }
  if (bVar3 == 6) {
    f_9584(param_1, param_2, param_3, 0x1ba);
    f_9584(param_1, param_2, param_3, 0x1c3);
    f_2298(bVar2, 6);
  }
  if (bVar3 == 7) {
    f_9584(param_1, param_2, param_3, 0x1ba);
    f_9584(param_1, param_2, param_3, 0x1c2);
    f_2298(bVar2, 7);
  }
  if (bVar3 == 4) {
    f_9584(param_1, param_2, param_3, 0x1be);
  }
  if (bVar3 == 5) {
    f_cc6a(param_1, param_2, param_3);
    f_215c(bVar2, 2, 1);
    f_6468(bVar2, 2);
    f_215c(bVar2, 6, 1);
    f_6468(bVar2, 6);
  }
  if (bVar3 == 1) {
    f_ccd6(param_1, param_2, param_3, 1, 0x1b1);
  }
  if (bVar3 == 2) {
    f_ccd6(param_1, param_2, param_3, 2, 0x1a8);
  }
  return 0 /* AX? */;
}

// 1000:CB74 FUN_1000_cb74
static u16 f_cb74(u8 param_1,u8 param_2)

{
  FN(0xCB74);
  bool bVar1;
  i16 iVar2;
  u16 uVar3;
  
  if ((*PS8(0x353a) == '\x02') && (iVar2 = f_3334(param_2), iVar2 == 8)) {
    bVar1 = false;
    iVar2 = f_170e(5);
    if ((iVar2 == 0) &&
       ((iVar2 = f_20f2(param_2, 2), iVar2 == 0 &&
        (iVar2 = f_20f2(param_2, 6), iVar2 == 0)))) {
      u16 y = f_c390(param_2);  // FIX: pushed before the other call (Ghidra lost it)
      uVar3 = f_c380(param_2);
      f_9584(param_1, uVar3, y, 0x1bf);
      bVar1 = true;
    }
    if ((((!bVar1) && (iVar2 = f_170e(5), iVar2 == 0)) &&
        (iVar2 = f_20f2(param_2, 0), iVar2 == 0)) &&
       (iVar2 = f_20f2(param_2, 4), iVar2 == 0)) {
      u16 y = f_c390(param_2);  // FIX: pushed before the other call (Ghidra lost it)
      uVar3 = f_c380(param_2);
      f_9584(param_1, uVar3, y, 0x1c0);
    }
  }
  return 0 /* AX? */;
}

// 1000:CC6A FUN_1000_cc6a
static u16 f_cc6a(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xCC6A);
  u8 bVar1;
  i16 iVar2;
  u8 local_4;
  
  bVar1 = f_c3a0(param_2, param_3);
  iVar2 = f_3334(bVar1 - 0xb);
  if (iVar2 == 5) {
    iVar2 = f_3334(bVar1 + 0xb);
    if (iVar2 == 5) {
      local_4 = 1;
    }
    else {
      local_4 = 2;
    }
  }
  else {
    local_4 = 0;
  }
  return f_9584(param_1, param_2, param_3, local_4 + 0x1bb);
  return 0 /* AX? */;
}

// 1000:CCD6 FUN_1000_ccd6  FIX: param_3 is zero-extended (u8, not Ghidra's i8)
static u16 f_ccd6(u8 param_1,i8 param_2,u8 param_3,u8 param_4,i16 param_5)

{
  FN(0xCCD6);
  u16 uVar1;
  u16 uVar2;
  u8 local_4;
  
  uVar1 = f_c3a0(param_2, param_3);
  if (param_2 != '\0') {
    uVar2 = f_3334((uVar1 & 0xff) - 0xb);
    if (uVar2 == param_4) {
      if (param_2 != '\r') {
        uVar2 = f_3334((uVar1 & 0xff) + 0xb);
        if (uVar2 == param_4) {
          if (param_3 != '\0') {
            uVar2 = f_3334((uVar1 & 0xff) - 1);
            if (uVar2 == param_4) {
              if (param_3 != '\n') {
                uVar1 = f_3334((uVar1 & 0xff) + 1);
                if (uVar1 == param_4) {
                  local_4 = 4;
                  goto LAB_1000_ce0c;
                }
              }
              local_4 = 5;
              goto LAB_1000_ce0c;
            }
          }
          local_4 = 3;
          goto LAB_1000_ce0c;
        }
      }
      if (param_3 != '\0') {
        uVar2 = f_3334((uVar1 & 0xff) - 1);
        if (uVar2 == param_4) {
          if (param_3 != '\n') {
            uVar1 = f_3334((uVar1 & 0xff) + 1);
            if (uVar1 == param_4) {
              local_4 = 7;
              goto LAB_1000_ce0c;
            }
          }
          local_4 = 8;
          goto LAB_1000_ce0c;
        }
      }
      local_4 = 6;
      goto LAB_1000_ce0c;
    }
  }
  if (param_3 != '\0') {
    uVar2 = f_3334((uVar1 & 0xff) - 1);
    if (uVar2 == param_4) {
      if (param_3 != '\n') {
        uVar1 = f_3334((uVar1 & 0xff) + 1);
        if (uVar1 == param_4) {
          local_4 = 1;
          goto LAB_1000_ce0c;
        }
      }
      local_4 = 2;
      goto LAB_1000_ce0c;
    }
  }
  local_4 = 0;
LAB_1000_ce0c:
  return f_9584(param_1, param_2, param_3, (u16)local_4 + param_5);
  return 0 /* AX? */;
}

// 1000:CE2A FUN_1000_ce2a
static u8 f_ce2a(u8 param_1)

{
  FN(0xCE2A);
  u8 local_4;
  
  local_4 = 0;
  if ((2 < param_1) && ((param_1 < 5 || (param_1 == 8)))) {
    local_4 = 1;
  }
  return local_4;
}

// 1000:CE56 FUN_1000_ce56  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static bool f_ce56(u8 param_1)

{
  FN(0xCE56);
  i16 iVar1;
  
  if (param_1 == '\x05') {
    return false;
  }
  iVar1 = f_ce2a(param_1);
  return iVar1 == 0;
}

// 1000:CE7C FUN_1000_ce7c
static u16 f_ce7c(void)

{
  FN(0xCE7C);
  i16 iVar1;
  u16 uVar2;
  u8 bVar3;
  u8 uVar4;
  
  if (*PS8(0x3450) == '\x1b') {
    f_4e7c(1);
  }
  f_cf22();
  f_cf58();
  f_cfaa();
  f_cf68();
  f_d07e();
  f_d32c();
  f_d410();
  f_d4b4();
  f_d054();
  iVar1 = f_718e();
  if (iVar1 != 0) {
    f_6c5c();
  }
  if (*PS8(0x3450) == '\x1b') {
    uVar4 = 7;
    bVar3 = 0;
    do {
      uVar2 = f_c3a0(uVar4, bVar3);
      f_3344(uVar2, 8);  // FIX: pushed before the other call (Ghidra lost it)
      bVar3 = bVar3 + 1;
    } while (bVar3 < 0xb);
    uVar2 = f_c3a0(8, 3);
    f_3344(uVar2, 3);  // FIX: pushed before the other call (Ghidra lost it)
    uVar2 = f_c3a0(8, 4);
    f_3344(uVar2, 7);
  }
  return 0 /* AX? */;
}

// 1000:CF22 FUN_1000_cf22
static u16 f_cf22(void)

{
  FN(0xCF22);
  u8 local_4;
  
  local_4 = 0;
  do {
    f_3344(local_4, 8);
    f_2298(local_4, 0);
    local_4 = local_4 + 1;
  } while (local_4 < 0x9a);
  return 0 /* AX? */;
}

// 1000:CF58 FUN_1000_cf58
static u16 f_cf58(void)

{
  FN(0xCF58);
  i8 cVar1;
  
  cVar1 = f_170e(5);
  *PS8(0xae72) = cVar1 + -0x6e;
  return 0 /* AX? */;
}

// 1000:CF68 FUN_1000_cf68
static u16 f_cf68(void)

{
  FN(0xCF68);
  i16 iVar1;
  
  iVar1 = f_170e(8);
  if (iVar1 == 0) {
    iVar1 = f_170e(3);
    iVar1 = iVar1 + 3;
  }
  else {
    iVar1 = f_170e(8);
    if (iVar1 != 0) {
      return 0 /* AX? */;
    }
    iVar1 = f_170e(3);
    iVar1 = iVar1 + 9;
  }
  return f_cfce(iVar1);
}

// 1000:CFAA FUN_1000_cfaa
static u16 f_cfaa(void)

{
  FN(0xCFAA);
  u8 local_4;
  
  local_4 = 0;
  do {
    *P16((u16)local_4 * 2 + 0x48ee) = 0;
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return 0 /* AX? */;
}

// 1000:CFCE FUN_1000_cfce
static u16 f_cfce(u8 param_1)

{
  FN(0xCFCE);
  i8 cVar1;
  u16 uVar2;
  u16 uVar3;
  u8 local_a;
  u8 local_4;
  
  local_a = 0;
  do {
    uVar2 = f_c3a0(param_1, local_a);
    f_3344(uVar2, 4);  // FIX: pushed before the other call (Ghidra lost it)
    local_a = local_a + 1;
  } while (local_a < 0xb);
  cVar1 = f_170e(5);
  local_4 = 0;
  do {
    uVar3 = f_c3a0((u16)param_1 + (u16)local_4 + -1, cVar1 + '\x04');
    *P16((u16)local_4 * 2 + 0x48ee) = uVar3 & 0xff;
    f_3344(uVar3 & 0xff, 5);
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return 0 /* AX? */;
}

// 1000:D054 FUN_1000_d054
static u16 f_d054(void)

{
  FN(0xD054);
  
  if (*PS16(0x48ee) != 0) {
    f_3344(*PS16(0x48ee) + -0xb, 8);
    f_3344(*PS16(0x48f2) + 0xb, 8);
  }
  return 0 /* AX? */;
}

// 1000:D07E FUN_1000_d07e
static u16 f_d07e(void)

{
  FN(0xD07E);
  i16 iVar1;
  u8 local_8;
  u8 local_4;
  
  for (local_4 = 0; local_4 < 0xd; local_4 = local_4 + 1) {
    for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
      iVar1 = f_170e(2);
      if (iVar1 == 0) {
        f_d0c8(local_4, local_8);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:D0C8 FUN_1000_d0c8
static u16 f_d0c8(u8 param_1,u8 param_2)

{
  FN(0xD0C8);
  u8 bVar1;
  i8 cVar2;
  i16 iVar3;
  u16 uVar4;
  u8 local_a;
  u8 local_8;
  u8 local_6;
  u8 local_4;
  
  local_8 = 2;
  local_a = 2;
  bVar1 = f_170e(0x10);
  if (bVar1 == 0) {
    local_a = 3;
  }
  else if (bVar1 < 4) {
    local_8 = 3;
  }
  iVar3 = f_d19e(param_1, param_2, local_8, local_a);
  if (iVar3 != 0) {
    cVar2 = f_170e(2);
    local_4 = local_8;
    while (local_4 != 0) {
      local_4 = local_4 - 1;
      local_6 = local_a;
      while (local_6 != 0) {
        local_6 = local_6 - 1;
        uVar4 = f_c3a0((u16)param_1 + (u16)local_4, (u16)param_2 + (u16)local_6);
        f_3344(uVar4, (u8)(cVar2 + 1));  // FIX: pushed before the other call (Ghidra lost it), f_170e(2) + 1
        uVar4 = f_c3a0((u16)param_1 + (u16)local_4, (u16)param_2 + (u16)local_6);
        f_2298(uVar4, 1);  // FIX: pushed before the other call (Ghidra lost it)
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:D19E FUN_1000_d19e
static u8 f_d19e(i8 param_1,i8 param_2,i8 param_3,i8 param_4)

{
  FN(0xD19E);
  i8 cVar1;
  i8 cVar2;
  i16 iVar3;
  u8 local_8;
  u8 local_6;
  u8 local_4;
  
  if (((i16)param_1 + (i16)param_3 < 0xf) && ((i16)param_2 + (i16)param_4 < 0xc)) {
    local_6 = 1;
    local_4 = param_3 + '\x02';
    while (local_4 != '\0') {
      local_4 = local_4 + -1;
      local_8 = param_4 + '\x02';
      while (local_8 != '\0') {
        local_8 = local_8 + -1;
        cVar1 = param_1 + local_4 + -1;
        cVar2 = param_2 + local_8 + -1;
        iVar3 = f_d306((i16)cVar1, (i16)cVar2);
        if (iVar3 != 0) {
          if ((((local_4 == '\0') || (local_8 == '\0')) || (param_3 < local_4)) ||
             (param_4 < local_8)) {
            iVar3 = f_d2b4((i16)cVar1, (i16)cVar2);
          }
          else {
            iVar3 = f_d274((i16)cVar1, (i16)cVar2);
          }
          if (iVar3 == 0) {
            local_6 = 0;
          }
        }
      }
    }
    return local_6;
  }
  return 0;
}

// 1000:D274 FUN_1000_d274
static u16 f_d274(i8 param_1,i8 param_2)

{
  FN(0xD274);
  i8 cVar1;
  i16 iVar2;
  
  cVar1 = f_c3a0((i16)param_1, (i16)param_2);
  if (cVar1 != *PS8(0xae72)) {
    iVar2 = f_3334(cVar1);
    if (iVar2 == 8) {
      return 1;
    }
  }
  return 0;
}

// 1000:D2B4 FUN_1000_d2b4
static u16 f_d2b4(i8 param_1,i8 param_2)

{
  FN(0xD2B4);
  i8 cVar1;
  i16 iVar2;
  
  cVar1 = f_c3a0((i16)param_1, (i16)param_2);
  if (cVar1 == *PS8(0xae72)) {
    return 0;
  }
  iVar2 = f_3334(cVar1);
  if ((iVar2 != 8) && (iVar2 = f_3334(cVar1), iVar2 != 4)) {
    return 0;
  }
  return 1;
}

// 1000:D306 FUN_1000_d306
static u16 f_d306(i8 param_1,i8 param_2)

{
  FN(0xD306);
  if ((((param_1 != -1) && (param_2 != -1)) && (param_1 != '\x0e')) && (param_2 != '\v')) {
    return 1;
  }
  return 0;
}

// 1000:D32C FUN_1000_d32c
static u16 f_d32c(void)

{
  FN(0xD32C);
  i8 cVar1;
  i8 cVar2;
  u8 uVar3;
  i16 iVar4;
  i16 iVar5;
  
  iVar5 = 500;
  do {
    iVar5 = iVar5 + -1;
    cVar1 = f_170e(0xc);
    cVar2 = f_170e(9);
    cVar2 = cVar2 + '\x01';
    uVar3 = f_c3a0(cVar1 + '\x01', cVar2);
    iVar4 = f_d3ac(uVar3, 7);
    if (iVar4 != 0) {
      f_3344(uVar3, 6);
      f_2298(uVar3, 1);
      iVar5 = 0;
    }
  } while (iVar5 != 0);
  return 0 /* AX? */;
}

// 1000:D3AC FUN_1000_d3ac
static u16 f_d3ac(u8 param_1,u8 param_2)

{
  FN(0xD3AC);
  i16 iVar1;
  u16 uVar2;
  u8 local_a;
  u8 local_4;
  
  iVar1 = f_3334(param_1);
  if (iVar1 == 8) {
    local_4 = 0;
    local_a = 0;
    do {
      uVar2 = f_3334(*PS16((u16)local_a * 2 + 0x48f4) + (u16)param_1);
      iVar1 = f_ce2a(uVar2);
      if (iVar1 != 0) {
        local_4 = local_4 + 1;
      }
      local_a = local_a + 1;
    } while (local_a < 8);
    if (param_2 <= local_4) {
      return 1;
    }
  }
  return 0;
}

// 1000:D410 FUN_1000_d410
static u16 f_d410(void)

{
  FN(0xD410);
  u8 uVar1;
  i16 iVar2;
  u8 local_6;
  u8 local_4;
  
  for (local_4 = 1; local_4 < 0xd; local_4 = local_4 + 1) {
    for (local_6 = 1; local_6 < 10; local_6 = local_6 + 1) {
      uVar1 = f_c3a0(local_4, local_6);
      iVar2 = f_d3ac(uVar1, 7);
      if (iVar2 == 0) {
        iVar2 = f_d3ac(uVar1, 6);
        if ((iVar2 != 0) && (iVar2 = f_170e(2), iVar2 == 0)) {
          f_3344(uVar1, 3);
        }
      }
      else {
        f_3344(uVar1, 7);
        f_2298(uVar1, 1);
      }
    }
  }
  return 0 /* AX? */;
}

// 1000:D4B4 FUN_1000_d4b4
static u16 f_d4b4(void)

{
  FN(0xD4B4);
  return 0 /* AX? */;
}

// 1000:D4B6 FUN_1000_d4b6
static u16 f_d4b6(u8 param_1,u8 param_2,u8 param_3)

{
  FN(0xD4B6);
  i8 cVar1;
  i16 iVar2;
  u16 uVar3;
  i16 iVar4;
  u16 local_8;
  u16 local_6;
  
  iVar2 = f_a122(param_2, param_3);
  uVar3 = f_c3a0(param_2, param_3);
  cVar1 = f_3334(uVar3);
  for (local_6 = 0; local_6 < 7; local_6 = local_6 + 1) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      iVar4 = f_a114(local_6, local_8);
      f_a0ba(iVar4 + iVar2, *P8(local_6 + local_8 * 7 + (u16)(u8)(cVar1 - 1U) * 0x31 + 0x43c8));
    }
  }
  uVar3 = f_c3a0(param_2, param_3);
  iVar2 = f_3334(uVar3);
  if (iVar2 == 0xf) {
    iVar2 = 0x1a7;
  }
  else {
    iVar2 = (u8)(cVar1 - 1U) + 0x19a;
  }
  f_9584(param_1, param_2, param_3, iVar2);
  uVar3 = f_c3a0(param_2, param_3);
  iVar2 = f_3334(uVar3);
  if (iVar2 == 0xd) {
    f_9584(param_1, param_2, param_3, 0x1a0);
    f_9584(param_1, param_2, param_3, 0x1a6);
  }
  return 0 /* AX? */;
}

// 1000:D5DC FUN_1000_d5dc
static u16 f_d5dc(u16 param_1,u8 param_2)

{
  FN(0xD5DC);
  u8 uVar1;
  u8 uVar2;
  
  uVar1 = f_c380(param_2);
  uVar2 = f_c390(param_2);
  f_d4b6(param_1, uVar1, uVar2);
  return f_96bc(param_1, param_2);
}

// 1000:D620 FUN_1000_d620
static u16 f_d620(u8 param_1,u8 param_2)

{
  FN(0xD620);
  return f_902e(param_1, 0, 0, 0x140, 400, param_2);
  return 0 /* AX? */;
}

// 1000:D648 FUN_1000_d648  FIX: param_1 is zero-extended (u8, not Ghidra's i8)
static u16 f_d648(u8 param_1)

{
  FN(0xD648);
  u16 uVar1;
  
  if ((param_1 == '\0') && (*PS8(0x4c) != '\x02')) {
    uVar1 = f_d6c2();
    DRV(2,uVar1);
    return f_d620(2, 0);
  }
  uVar1 = f_d6c2();
  DRV(param_1,uVar1);
  return 0 /* AX? */;
}

// 1000:D6AA FUN_1000_d6aa
static u16 f_d6aa(u8 param_1)

{
  FN(0xD6AA);
  
  *P16(0x4a24) = (u16)param_1;
  *P8(0x35e8) = param_1;
  *P8(0x35e9) = param_1 + 1 & 3;
  return 0 /* AX? */;
}

// 1000:D6C2 FUN_1000_d6c2
static u16 f_d6c2(void)

{
  FN(0xD6C2);
  
  return *P16(0x4a24);
}

// 1000:D6CC FUN_1000_d6cc
static u16 f_d6cc(u8 param_1)

{
  FN(0xD6CC);
  
  *P8(0x4a26) = param_1 & 0xf;
  return f_0808();
}

// 1000:D6F0 FUN_1000_d6f0
static u16 f_d6f0(void)

{
  FN(0xD6F0);
  u16 uVar1;
  
  uVar1 = f_0870(*P16(0x730c));
  *P16(0x50) = uVar1;
  return f_075a();
}

// 1000:D702 FUN_1000_d702
static u16 f_d702(void)

{
  FN(0xD702);
  
  return f_902e(2, 0, *P16(0x50), 0x140, 200, 0);
  return 0 /* AX? */;
}

// 1000:D724 FUN_1000_d724
static u16 f_d724(i16 param_1)

{
  FN(0xD724);
  
  if (*PS8(0x4c) != '\x02') {
    f_9168(2, 0, param_1 + *PS16(0x50), 0x140, *P8(*P8(0x4c) + 0x4a28), 0, 0, param_1 + *PS16(0x50));
  }
  return 0 /* AX? */;
}

// 1000:D766 FUN_1000_d766
static u16 f_d766(void)

{
  FN(0xD766);
  return f_d724(0);
}

// 1000:D770 FUN_1000_d770
static u16 f_d770(void)

{
  FN(0xD770);
  return f_d724(200);
}

// 1000:D77C FUN_1000_d77c
static u16 f_d77c(void)

{
  FN(0xD77C);
  
  *P8(0x4a2c) = 0;
  return 0 /* AX? */;
}

// 1000:D782 FUN_1000_d782
static u8 f_d782(void)

{
  FN(0xD782);
  
  return *P8(0x4a2c);
}

// 1000:D788 FUN_1000_d788
static u16 f_d788(void)

{
  FN(0xD788);
  
  *P8(0x4a2c) = 1;
  return 0 /* AX? */;
}

// 1000:D78E FUN_1000_d78e
static u16 f_d78e(void)

{
  FN(0xD78E);
  i16 iVar1;
  
  iVar1 = f_7130();
  if (iVar1 == 0) {
    if (*PS8(0x34ac) == '\0') {
      return 0;
    }
    if ((*PS8(0x3450) == '\x01') && (*PS8(0x34aa) != '\0')) {
      return 0;
    }
    iVar1 = f_6b42(*P8(0xae64), *P8(0xae06));
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = f_6b42((i16)*PS8((*P8(0x7596) >> 1) + 0x4104) + (u16)*P8(0xae64), *P8(0xae06));
    if ((iVar1 != 0) &&
       (iVar1 = f_212e(*P8(0xae64), *P8(0x7596)), iVar1 != 0)) {
      return 1;
    }
    iVar1 = f_6b42((i16)*PS8((*P8(0x7d80) >> 1) + 0x4104) + (u16)*P8(0xae64), *P8(0xae06));
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = f_212e(*P8(0xae64), *P8(0x7d80));
  }
  else {
    iVar1 = f_7788(0, 6);
  }
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}

// 1000:D858 FUN_1000_d858
static u16 f_d858(void)

{
  FN(0xD858);
  i16 iVar1;
  
  iVar1 = f_4e22();
  if (iVar1 != 0) {
    if ((*PS8(0x3558) != *PS8(0x7364)) && (iVar1 = f_7130(), iVar1 == 0)) {
      return 0 /* AX? */;
    }
    iVar1 = f_d78e();
    if (iVar1 != 0) {
      f_d788();
      f_a864();
    }
  }
  return 0 /* AX? */;
}

// 1000:D87E FUN_1000_d87e
static u16 f_d87e(void)

{
  FN(0xD87E);
  i16 iVar1;
  u16 uVar2;
  u8 local_4c [30];
  i16 local_2e;
  i16 local_2c;
  i16 local_2a;
  u8 local_28 [30];
  u16 local_a;
  u16 local_8;
  i16 local_6;
  i16 local_4;
  
  if ((*SHS16(0x28) == 0) || (*SHS16(0x2a) == 0)) {
    FUN_1fe7_058b(*SH16(0x1a));
    DRV(0);
    DRV(*SH16(0x30));
    DRV(0);
    FUN_1fe7_06e8(*P16(0x4a40),0,0,0x140,200,0);
    DRV();
    while (iVar1 = FUN_1fe7_0620(0x5436,0), iVar1 == -1) {
      f_f5a0(local_28, 0x543e);
      f_f5a0(local_4c, 0x5454);
      local_2e = f_daa6(*P16(0x4a40), (i8a *)local_4c);  // FIX: the buffer is Ghidra's u8[]
      local_2c = (0x140 - local_2e) / 2;
      FUN_1fe7_06e8(*P16(0x4a40),local_2c + -5,0x57,local_2e + 10,0x1b,4);
      *P16(*PS16(0x4a40) + 0xc) = 0xf;
      DRV(*P16(0x4a40),local_2c,0x65,local_4c);
      local_4 = f_daa6(*P16(0x4a40), (i8a *)local_28);  // FIX: the buffer is Ghidra's u8[]
      local_2a = (0x140 - local_4) / 2;
      DRV(*P16(0x4a40),local_2a,0x5b,local_28);
      local_4 = local_2c + -4;
      local_6 = local_2c + local_2e + 4;
      local_8 = 0x58;
      local_a = 0x70;
      FUN_1fe7_0004(*P16(0x4a40),local_4,0x58,local_6,0x58,0xc);
      FUN_1fe7_0004(*P16(0x4a40),local_6,local_8,local_6,local_a,0xc);
      FUN_1fe7_0004(*P16(0x4a40),local_6,local_a,local_4,local_a,0xc);
      FUN_1fe7_0004(*P16(0x4a40),local_4,local_a,local_4,local_8,0xc);
      uVar2 = 0x1fe7;
      do {
        do {
          iVar1 = f_f7aa();
          if (iVar1 != 0) {
            iVar1 = DRV();
            if (iVar1 == 0x1000) {
              DRV();
              f_e19a(0);
            }
            goto LAB_1000_da66;
          }
        } while (*SHS16(0x34) != 1);
        iVar1 = DRV(0);
        uVar2 = 0x20ba;
      } while (iVar1 != 1);
LAB_1000_da66:
      FUN_1fe7_06e8(*P16(0x4a40),0,0,0x140,200,0);
    }
  }
  return 0 /* AX? */;
}

// 1000:DAA6 FUN_1000_daa6
static u16 f_daa6(i16 param_1,i8a *param_2)

{
  FN(0xDAA6);
  u16 uVar1;
  i16 iVar2;
  u16 uVar3;
  u16 local_8;
  i8a *local_6;
  
  local_6 = param_2;
  uVar1 = *P16(param_1 + 0x10);
  local_8 = 0;
  uVar3 = 0x1000;
  while (*local_6 != '\0') {
    iVar2 = DRV(uVar1,*local_6);
    local_8 = local_8 + iVar2;
    uVar3 = 0x20ba;
    local_6 = local_6 + 1;
  }
  iVar2 = DRV(8);
  if (iVar2 != 0) {
    local_8 = local_8 >> 1;
  }
  return local_8;
}

// 1000:DAFE FUN_1000_dafe
static u16 f_dafe(u16 param_1,u16 param_2)

{
  FN(0xDAFE);
  i16 iVar1;
  u8 local_1c [20];
  u16 local_8;
  u16 local_6;
  u16 local_4;
  
  iVar1 = f_df46(param_1, (u16)(uintptr_t)local_1c);  // FIX: a stack buffer's near address in the original; here the
                                                    // catalog stubs never read through it (as GCC before 14 converted it)
  if (iVar1 != 0) {
    iVar1 = f_dfe2(*P16(0x4e02), local_8, local_6);
    if (iVar1 != 0) {
      f_de9e(param_1);
    }
    return *P16(0x4e02);
  }
  iVar1 = f_fd60(param_1, param_2, &local_4);
  if (iVar1 != 0) {
    f_de9e(param_1);
  }
  return local_4;
}

// 1000:DB5E FUN_1000_db5e
static u16 f_db5e(u16 param_1)

{
  FN(0xDB5E);
  i16 iVar1;
  u16 local_4;
  
  iVar1 = f_fd47(param_1, 0, &local_4);
  if (iVar1 != 0) {
    f_de9e(param_1);
  }
  return local_4;
}

// 1000:DB88 FUN_1000_db88
static u16 f_db88(i16 param_1)

{
  FN(0xDB88);
  i16 iVar1;
  
  if (param_1 != *PS16(0x4e02)) {
    iVar1 = f_fd32(param_1);
    if (iVar1 != 0) {
      f_de9e(0);
    }
  }
  return 0 /* AX? */;
}

// 1000:DBAC FUN_1000_dbac
static u16 f_dbac(u16 param_1,u16 param_2)

{
  FN(0xDBAC);
  u16 uVar1;
  i16 iVar2;
  u16 local_4;
  
  uVar1 = f_dafe(param_1, 0);
  iVar2 = f_fd78(uVar1, param_2);
  if (iVar2 != 0) {
    f_de9e(0);
  }
  f_db88(uVar1);
  return local_4;
}

// 1000:DBF0 FUN_1000_dbf0
static u16 f_dbf0(u16 param_1,u16 param_2,u16 param_3)

{
  FN(0xDBF0);
  u16 uVar1;
  i16 iVar2;
  u16 local_4;
  
  uVar1 = f_dafe(param_1, 0);
  iVar2 = f_fd78(uVar1, param_2, param_3, 0xffff, &local_4);
  if (iVar2 != 0) {
    f_de9e(0);
  }
  f_db88(uVar1);
  return local_4;
}

// 1000:DC36 FUN_1000_dc36
static u16 f_dc36(u16 param_1,u16 param_2,u16 param_3,u16 param_4)

{
  FN(0xDC36);
  u16 uVar1;
  i16 iVar2;
  
  uVar1 = f_db5e(param_1);
  iVar2 = f_fd7f(uVar1, param_2, param_3, param_4, &param_4);
  if (iVar2 != 0) {
    f_de9e(0);
  }
  f_db88(uVar1);
  return param_4;
}

// 1000:DC78 FUN_1000_dc78
static u16 f_dc78(u16 param_1,u16 param_2)

{
  FN(0xDC78);
  u16 uVar1;
  u16 local_4;
  
  uVar1 = f_dafe(param_2, 0);
  f_de14(uVar1);
  FUN_2095_000c();
  for (local_4 = 0; local_4 < *PS16(0x6d4a); local_4 = local_4 + 1) {
    FUN_2095_008d(0x7160);
    DRV(0x7160,param_1,local_4,*P16(0x6d48));
  }
  return f_db88(uVar1);
}

// 1000:DCD8 FUN_1000_dcd8
static u16 f_dcd8(u16 param_1)

{
  FN(0xDCD8);
  u16 uVar1;
  u16 local_4;
  
  uVar1 = f_dafe(param_1, 0);
  f_de14(uVar1);
  FUN_2095_000c();
  DRV(*P16(0x6d48),*P16(0x6d4a));
  for (local_4 = 0; local_4 < *PS16(0x6d4a); local_4 = local_4 + 1) {
    FUN_2095_008d(0x7160);
    DRV(0x7160);
  }
  f_db88(uVar1);
  DRV();
  return 0 /* AX? */;
}

// 1000:DD46 FUN_1000_dd46
static u16 f_dd46(u16 param_1,u16 param_2)

{
  FN(0xDD46);
  return f_dc78(param_2, param_1);
}

// 1000:DD58 FUN_1000_dd58
static u16 f_dd58(u16 param_1,u16 param_2)

{
  FN(0xDD58);
  u16 uVar1;
  u16 local_4;
  
  uVar1 = f_dafe(param_1, 0);
  f_de14(uVar1);
  FUN_2095_000c();
  for (local_4 = 0; local_4 < *PS16(0x6d4a); local_4 = local_4 + 1) {
    FUN_2095_008d(0x7160);
    DRV(0x7160,param_2,local_4,*P16(0x6d48));
  }
  return 0 /* AX? */;
}

// 1000:DDB2 FUN_1000_ddb2
static u16 f_ddb2(u16 param_1,u16 param_2)

{
  FN(0xDDB2);
  u16 local_4;
  
  *P16(0x72a2) = 0;
  *P16(0x72a4) = param_1;
  *P16(0x8738) = *P16(0x4e00);
  *P16(0x9bb2) = 0xde32;
  *P16(0x9bb4) = 0x1000;
  FUN_2095_000c();
  for (local_4 = 0; local_4 < *PS16(0x6d4a); local_4 = local_4 + 1) {
    FUN_2095_008d(0x7160);
    DRV(0x7160,param_2,local_4,*P16(0x6d48));
  }
  return 0 /* AX? */;
}

// 1000:DE14 FUN_1000_de14
static u16 f_de14(u16 param_1)

{
  FN(0xDE14);
  
  *P16(0x72a0) = param_1;
  *P16(0x8738) = *P16(0x4e00);
  *P16(0x9bb2) = 0xde76;
  *P16(0x9bb4) = 0x1000;
  return 0 /* AX? */;
}

// 1000:DE32 FUN_1000_de32
static u16 f_de32(void)

{
  FN(0xDE32);
  
  f_f89c(*P16(0x72a4), *P16(0x72a2));
  *P16(0x8738) = 0x6f60;
  *PS8(0x72a3) = *PS8(0x72a3) + '\x02';
  return 0x200;
}

// 1000:DE66 FUN_1000_de66
static u16 f_de66(u16 param_1)

{
  FN(0xDE66);
  
  *P16(0x72a0) = param_1;
  return f_de76();
}

// 1000:DE76 FUN_1000_de76
static u16 f_de76(void)

{
  FN(0xDE76);
  u16 local_4;
  
  f_fd78(*P16(0x72a0), 0x6f60);
  *P16(0x8738) = 0x6f60;
  return local_4;
}

// 1000:DE9E FUN_1000_de9e
static u16 f_de9e(u16 param_1)

{
  FN(0xDE9E);
  f_dec0(3);
  f_f72c(param_1);
  return f_e19a(99);
}

// 1000:DEC0 FUN_1000_dec0
static u16 f_dec0(u8 param_1)

{
  FN(0xDEC0);
  u16 uVar1;
  u8 local_10;
  u8 local_f;
  
  uVar1 = *P16(0x4e75);
  local_f = 0;
  local_10 = param_1;
  f_f7d6(0x10, &local_10, &local_10);
  *P16(0x4e75) = uVar1;
  return 0 /* AX? */;
}

// 1000:DEF0 FUN_1000_def0
static u16 f_def0(u16 param_1)

{
  FN(0xDEF0);
  i16 iVar1;
  u16 local_4;
  
  iVar1 = f_fd60(param_1, 0x8000, &local_4);
  if (iVar1 != 0) {
    return 0;
  }
  *P16(0x4e02) = local_4;
  return 1;
}

// 1000:DF20 FUN_1000_df20
static u16 f_df20(void)

{
  FN(0xDF20);
  i16 iVar1;
  
  if (*PS16(0x4e02) != -1) {
    iVar1 = f_fd32(*P16(0x4e02));
    if (iVar1 != 0) {
      f_de9e(0);
    }
    *P16(0x4e02) = 0xffff;
  }
  return 0 /* AX? */;
}

// 1000:DF46 FUN_1000_df46
static u16 f_df46(u16 param_1,u16 param_2)

{
  FN(0xDF46);
  i16 iVar1;
  i16 local_6 [2];
  
  if (*PS16(0x4e02) != -1) {
    iVar1 = f_dfe2(*P16(0x4e02), 0, 0);
    if (iVar1 != 0) {
      f_de9e(0);
    }
    iVar1 = f_fd78(*P16(0x4e02), local_6);
    if (iVar1 != 0) {
      f_de9e(0);
    }
    while (local_6[0] != 0) {
      local_6[0] = local_6[0] + -1;
      iVar1 = f_fd78(*P16(0x4e02), param_2);
      if (iVar1 != 0) {
        f_de9e(0);
      }
      iVar1 = f_fc42(param_2, param_1, 0xc);
      if (iVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}

// 1000:DFE2 FUN_1000_dfe2
static u16 f_dfe2(u16 param_1,u16 param_2,u16 param_3)

{
  FN(0xDFE2);
  u16 local_10;
  u16 local_e;
  u16 local_c;
  u16 local_a;
  i16 local_4;
  
  local_10 = 0x4200;
  local_e = param_1;
  local_c = param_3;
  local_a = param_2;
  f_f854(&local_10, &local_10);
  if (local_4 == 0) {
    return 0;
  }
  return local_10;
}

// ---------------------------------------------------------------- hand-written: the loop, split for replays

void melee_attach(uint8_t *ds, const MeleeHost *host)
{
  g_ds = ds;
  melee_host = host;
}

// the loop body after the clock (1000:0079-00A7)
static void pass_rest(void)
{
  f_71b4();
  f_4dee();
  f_ba00();
  f_bc52();
  if (*PS8(0x44) == 0 && *PS8(0x3435) != 0 && *PS16(0xe4) == 0) *P8(0x3435) = 0;  // the CGA alarm flash ends
}

// the clock (1000:3BB8) up to the first timer decrement
static u8 clock_start(void)
{
  FN(0x3BB8);
  *PS16(0x342e) = *PS16(0x342e) + 1;
  u8 elapsed = (u8)(*P16(0x53) - *P8(0x7594));
  *P16(0x7594) = *P16(0x53);
  f_3b7c(elapsed);
  if (elapsed) *PS16(0x3430) = *PS16(0x3430) + 1;
  return elapsed;
}

static u8 pendingTicks;  // decrements still due in the pass stopped at the timer routine

void melee_pass_start(void)
{
  f_11ea();
  f_c47e();
  f_0a2e();
  f_3a70();
  pendingTicks = clock_start();
}

void melee_pass_finish(void)
{
  for (; pendingTicks != 0; pendingTicks--)
  {
    f_07c2();
    if (pendingTicks > 1) *PS16(0x3430) = *PS16(0x3430) + 1;
  }
  pass_rest();
}

int melee_pass(int elapsedTicks)
{
  *P16(0x53) = (u16)(*P16(0x7594) + elapsedTicks);
  melee_pass_start();
  melee_pass_finish();
  return *PS8(0x8b32) != 0;
}

void melee_set_pending_ticks(int n) { pendingTicks = (u8)n; }
