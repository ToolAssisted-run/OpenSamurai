// gametest GAMEDIR [START.snap FRAMES]: the game as the launcher runs it, headless: the drivers and START.EXE loaded
// from the game's files and started from its entry (the C library's start-up), without keys, for FRAMES video
// frames. With a capture of START (the workspace's oracle/st_ev.py), its state at main's entry is compared with
// the one the start-up leaves. SOUND=I: with the IBM speaker's driver; TIMER="FRAME ...": START's timer bytes.
#include "asm2c.h"
#include "game.h"
#include "shared.h"
#include "start.h"
#include "rp.h"

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t *far_ptr(uint16_t seg, uint16_t off);

static uint8_t mainDs[0x5800], mainSh[SHARED_SIZE];
static int haveMain, frames, maxFrames = 2000, differ = -1;
static jmp_buf stop;

static long nfn;
static void on_fn(uint32_t addr)
{
  if (getenv("TRACEFN") && nfn < atol(getenv("TRACEFN"))) printf("F %04X:%04X sp=%04X ss=%04X ds=%04X\n", addr >> 16, addr & 0xFFFF, R.sp, R.ss, R.ds);
  nfn++;
  if (addr != 0x10000010 || !haveMain || differ >= 0) return;
  // main's entry: the start-up's work, against the real game's (the stack below the entry is the start-up's)
  differ = 0;
  for (int k = 0; k < 0x5800; k++)
    if (*far_ptr(0x2F4F, (uint16_t)k) != mainDs[k] && !(k >= 0x4F90 && k < R.sp) && k < 0x578E)  // above: the unpacker's leftovers
    {
      if (differ++ < 16) printf("  DS:%04X %02X/%02X\n", k, *far_ptr(0x2F4F, (uint16_t)k), mainDs[k]);
    }
  for (int k = 0; k < SHARED_SIZE; k++)
    if (shared.b[k] != mainSh[k] && differ++ < 32) printf("  shared+%03X %02X/%02X\n", k, shared.b[k], mainSh[k]);
  printf("main: %d bytes differ from the capture's (SP %04X)\n", differ, R.sp);
}

// KEYS="FRAME:KEY ..." (the BIOS's keys, hexadecimal): each becomes waiting at its frame
static const char *script;
static uint16_t pending[16];
static int npending;
// TIMER="FRAME ...": START's timer bytes (DS:1BA8-1BC7) printed at those frames
static void present(void *ctx)
{
  (void)ctx;
  if (++frames >= maxFrames) longjmp(stop, 1);
  for (const char *p = getenv("TIMER"); p && *p;)
  {
    char *q;
    long f = strtol(p, &q, 10);
    if (q == p) break;
    if (f == frames)
    {
      printf("frame %d, START's timer:", frames);
      for (int k = 0x1BA8; k < 0x1BC8; k++) printf(" %02X", *far_ptr(0x2F4F, (uint16_t)k));
      printf("\n");
    }
    p = q;
  }
  for (const char *p = script; p && *p;)
  {
    char *q;
    long f = strtol(p, &q, 10);
    if (q == p || *q != ':') break;
    unsigned k = (unsigned)strtoul(q + 1, &q, 16);
    if (f == frames && npending < 16) pending[npending++] = (uint16_t)k;
    p = q;
    while (*p == ' ') p++;
  }
}
// a virtual clock: 20 microseconds a look, the waits jump
static uint64_t vnow;
static uint64_t now_us(void *ctx) { (void)ctx; return vnow += 20; }
static void sleep_until(void *ctx, uint64_t t) { (void)ctx; if (t > vnow) vnow = t; }
static int key_waiting(void *ctx) { (void)ctx; return npending > 0; }
static uint16_t read_key(void *ctx)
{
  (void)ctx;
  uint16_t k = pending[0];
  if (npending) memmove(pending, pending + 1, sizeof *pending * (size_t)--npending);
  return k;
}
static long nrp;
static void rp_fn(uint32_t addr)
{
  if (getenv("TRACERP") && nrp < atol(getenv("TRACERP"))) printf("R %04X:%04X frame %d ret %04X:%04X\n", addr >> 16, addr & 0xFFFF, frames, *(uint16_t *)far_ptr(R.ss, (uint16_t)(R.sp + 2)), *(uint16_t *)far_ptr(R.ss, R.sp));
  nrp++;
}

int main(int argc, char **argv)
{
  setvbuf(stdout, NULL, _IOLBF, 0);
  if (argc < 2) { fprintf(stderr, "usage: gametest GAMEDIR [START.snap FRAMES]\n"); return 2; }
  if (argc > 2 && strcmp(argv[2], "-"))  // (- for none)
  {
    FILE *f = fopen(argv[2], "rb");
    if (!f || fseek(f, 8, SEEK_SET) || fread(mainDs, 1, sizeof mainDs, f) != sizeof mainDs || fread(mainSh, 1, SHARED_SIZE, f) != SHARED_SIZE) { fprintf(stderr, "cannot read %s\n", argv[2]); return 2; }
    fclose(f);
    haveMain = 1;
  }
  if (argc > 3) maxFrames = atoi(argv[3]);
  GameHost h = { present, now_us, sleep_until, key_waiting, read_key, { 1989, 10, 25, 12, 0, 0, 0 }, argv[1], false, NULL };
  if (getenv("SOUND")) h.sound = getenv("SOUND")[0];  // SOUND=I: the IBM speaker's driver
  start_trace = on_fn;
  rp_trace = rp_fn;
  script = getenv("KEYS");
  int code = -2;
  if (!setjmp(stop)) code = game_run(&h);
  printf("%d frames, exit code %d\n", frames, code);
  return haveMain && differ != 0;
}
