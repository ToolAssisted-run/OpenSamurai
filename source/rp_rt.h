// What rp_core.c calls outside the game's own code: the Microsoft C 5.1 run-time library (segment 202e),
// MicroProse's catalog, picture and buffer modules (290b, 2965, 29fd), the assembly module (168c: drawing
// helpers, timer, keyboard hooks, context save) and the drivers (DRV(slot, ...)). Pointers are near (data
// segment offsets) unless given as offset and segment. The prototypes are the ones given to Ghidra
// (the workspace's work/rp_sigs.txt).
#ifndef OPENSAMURAI_RP_RT_H
#define OPENSAMURAI_RP_RT_H

#include "dsimage.h"
#include "rp.h"

// function entries, for comparing the flow with the original's instruction traces (tests)
#define FN(addr) \
  do { \
    if (rp_trace) rp_trace(addr); \
  } while (0)

// the run-time library's functions have the library's names in the translation: here they are rp_ functions
// (the C library of the host has its own)
#define exit rp_exit
#define fclose rp_fclose
#define fopen rp_fopen
#define fread rp_fread
#define fwrite rp_fwrite
#define strcat rp_strcat
#define strcpy rp_strcpy
#define strlen rp_strlen
#define itoa rp_itoa
#define perror rp_perror
#define intdos rp_intdos
#define int86 rp_int86
#define movedata rp_movedata
#define time rp_time
#define stricmp rp_stricmp
#define strnicmp rp_strnicmp
#define strupr rp_strupr
#define memmove rp_memmove
#define memcpy rp_memcpy
#define srand rp_srand
#define rand rp_rand
#define close rp_close
#define read rp_read
#define write rp_write
#define unlink rp_unlink
#define strncpy rp_strncpy
#define getenv rp_getenv
#define strncmp rp_strncmp
#define atoi rp_atoi

#undef DRV
// a driver call through the far-jump slot table at DS:3060 (graphics 0-47, MISC 90-97, sound 100-106;
// -1 = a call whose slot the translation could not tell)
u16 rp_drv(int slot, ...);
void rp_driver(int slot);  // from recompiled code, the return address pushed
#define DRV(...) rp_drv(__VA_ARGS__)

// the frame flag DS:3038 the timer interrupt sets every video frame, where the program waits on it: the host lets
// the frames pass (rp_frame_poll: the flag, after the frame the program waits for if it is not there yet)
u8 rp_frame_poll(void);
// the hibernation around a sub-game (23bb:0222): exit(1-3) runs the sub-game (the host) and comes back to the
// point after SaveContext with the data segment restored
#include <setjmp.h>
extern jmp_buf rp_resume;
extern u8 rp_resumeArmed;
// the tick entry into the recompiled main loop (106a:0000 at 106a:0048; rp_tick)
extern u8 rp_tickEntry, rp_tickArmed;
// DOS memory (the arena: first fit, as DOS) and the fatal message of AllocBuffer
u16 rp_dos_alloc(u16 paragraphs);
void rp_dos_free(u16 seg);
bool rp_dos_resize(u16 seg, u16 paragraphs);
void rp_fatal_memory(i16 name, i16 suffix);
void rp_delay_frames(int n);

// MS C 5.1 run-time (202e); pointers are near (int), far ones split into offset/segment
void exit(i16 code);  // 202e:01a0
i16 fclose(i16 f);  // 202e:023e
i16 fopen(i16 name, i16 mode);  // 202e:0306
i16 fread(i16 buf, i16 size, i16 n, i16 f);  // 202e:0332
i16 fwrite(i16 buf, i16 size, i16 n, i16 f);  // 202e:0524
i16 strcat(i16 dst, i16 src);  // 202e:066a
i16 strcpy(i16 dst, i16 src);  // 202e:06aa
i16 strlen(i16 s);  // 202e:06dc
i16 itoa(i16 v, i16 buf, i16 radix);  // 202e:06f8
void perror(i16 s);  // 202e:0714
i16 int86(i16 n, i16 in, i16 out);  // 202e:079e
i16 intdos(i16 in, i16 out);  // 202e:081e
void movedata(u16 srcseg, u16 srcoff, u16 dstseg, u16 dstoff, u16 n);  // 202e:0868
i32 time(i16 p);  // 202e:0886
i16 stricmp(i16 a, i16 b);  // 202e:08da
i16 strnicmp(i16 a, i16 b, i16 n);  // 202e:091c
i16 strupr(i16 s);  // 202e:0974
i16 memmove(i16 dst, i16 src, u16 n);  // 202e:0996
i16 memcpy(i16 dst, i16 src, u16 n);  // 202e:09de
void srand(u16 seed);  // 202e:0a0a
i16 rand(void);  // 202e:0a1c
i16 _dos_close(i16 h);  // 202e:0a44
i16 _dos_creat(i16 name, i16 attr, i16 ph);  // 202e:0a59
i16 _dos_open(i16 name, i16 mode, i16 ph);  // 202e:0a72
i16 _dos_read(i16 h, u16 off, u16 seg, u16 n, i16 pn);  // 202e:0a8a
i16 _dos_write(i16 h, u16 off, u16 seg, u16 n, i16 pn);  // 202e:0a91
i32 __aFldiv(i32 a, i32 b);  // 202e:0aae
i32 __aFlmul(i32 a, i32 b);  // 202e:0b4a
i32 __aFlrem(i32 a, i32 b);  // 202e:0b7e
void __aFnaldiv(i16 p, i32 b);  // 202e:0c20
void __aFnalmul(i16 p, i32 b);  // 202e:0c44
u32 __aFuldiv(u32 a, u32 b);  // 202e:0c68
i16 _filbuf(i16 f);  // 202e:0dc4
i16 _flsbuf(i16 c, i16 f);  // 202e:0e86
i16 close(i16 h);  // 202e:11b8
i16 read(i16 h, i16 buf, u16 n);  // 202e:11d8
i16 write(i16 h, i16 buf, u16 n);  // 202e:12b6
i16 unlink(i16 name);  // 202e:1562
i16 strncpy(i16 dst, i16 src, i16 n);  // 202e:1bdc
i16 getenv(i16 name);  // 202e:1c08
i16 strncmp(i16 a, i16 b, i16 n);  // 202e:1d30
i16 atoi(i16 s);  // 202e:1d6a

// MicroProse modules: catalog (290b), pictures (2965), text (2990), misc (29f7), buffers (29fd)
i16 CatReadFar(i16 name, u16 off, u16 seg);  // 290b:0104
i16 CatWriteFile(i16 name, u16 off, u16 seg, u16 n);  // 290b:0150
i16 LoadDataEntry(u16 off, u16 seg, i16 name);  // 290b:01fa
i16 LoadPic(i16 name, i16 dest);  // 290b:02ae
i16 CatalogOpen(i16 name);  // 290b:0466
void CatalogClose(void);  // 290b:0498
u16 AllocBuffer(u16 lo, u16 hi, i16 name);  // 29fd:000a
void FreeBuffer(u16 seg, i16 name);  // 29fd:0098
u16 ReallocBuffer(u16 seg, u16 lo, u16 hi, i16 name);  // 29fd:00f8

// the assembly module (168c)
i16 FileOnDisk(i16 name, i16 disk);  // 168c:0002
void SaveContext(u16 seg);  // 168c:00ca
void RestoreContext(u16 seg);  // 168c:00ee
i16 NotOriginalDisk(void);  // 168c:0120
void DrawLine(i16 win, i16 x1, i16 y1, i16 x2, i16 y2, i16 col);  // 168c:04fc
void FillRect(i16 win, i16 x, i16 y, i16 w, i16 h, i16 col);  // 168c:0604
void StrcpyToFar(u16 dstoff, u16 dstseg, i16 src);  // 168c:084a
void StrcpyFromFar(i16 dst, u16 srcoff, u16 srcseg);  // 168c:0861
void DosPrint(i16 s);  // 168c:0910
void InstallTimer(void);  // 168c:0958
void RestoreTimer(void);  // 168c:0996
u16 BiosTicks(void);  // 168c:0b78
void SaveVectors(void);  // 168c:0b80
void RestoreVectors(void);  // 168c:0ba2
void RegisterOverlay(u16 seg);  // 168c:0ce7
void HookKeyboard(void);  // 168c:0d36
void UnhookKeyboard(void);  // 168c:0d8e

// others the translation calls
u16 ext_202e_022b();
u16 ext_202e_0d90();
u16 ext_202e_1b5e();
u16 ext_202e_1b98();

#endif
