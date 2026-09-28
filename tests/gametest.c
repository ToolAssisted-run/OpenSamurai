// gametest GAMEDIR [START.snap FRAMES]: the game as the launcher runs it, headless: the drivers and START.EXE loaded
// from the game's files and started from its entry (the C library's start-up), without keys, for FRAMES video
// frames. With a capture of START (the workspace's oracle/st_ev.py), its state at main's entry is compared with
// the one the start-up leaves.
#include "asm2c.h"
#include "game.h"
#include "shared.h"
#include "start.h"

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

static void frame(void *ctx)
{
  (void)ctx;
  if (++frames >= maxFrames) longjmp(stop, 1);
}
static int key_waiting(void *ctx) { (void)ctx; return 0; }
static uint16_t read_key(void *ctx) { (void)ctx; return 0; }
// the clock runs a hundredth of a second a reading (the programs' waits for it read it in a loop)
static long hundredths;
static void clock_(void *ctx, GameClock *c)
{
  (void)ctx;
  long t = hundredths++;
  *c = (GameClock){ 1989, 10, 25, 12, (int)(t / 6000 % 60), (int)(t / 100 % 60), (int)(t % 100) };
}
static uint32_t ticks(void *ctx) { (void)ctx; return 0x0CBF9D; }

int main(int argc, char **argv)
{
  setvbuf(stdout, NULL, _IOLBF, 0);
  if (argc < 2) { fprintf(stderr, "usage: gametest GAMEDIR [START.snap FRAMES]\n"); return 2; }
  if (argc > 2)
  {
    FILE *f = fopen(argv[2], "rb");
    if (!f || fseek(f, 8, SEEK_SET) || fread(mainDs, 1, sizeof mainDs, f) != sizeof mainDs || fread(mainSh, 1, SHARED_SIZE, f) != SHARED_SIZE) { fprintf(stderr, "cannot read %s\n", argv[2]); return 2; }
    fclose(f);
    haveMain = 1;
  }
  if (argc > 3) maxFrames = atoi(argv[3]);
  GameHost h = { frame, key_waiting, read_key, clock_, ticks, argv[1], false, NULL };
  start_trace = on_fn;
  int code = -2;
  if (!setjmp(stop)) code = game_run(&h);
  printf("%d frames, exit code %d\n", frames, code);
  return haveMain && differ != 0;
}
