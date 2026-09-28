// rptest TICKS.snap INPUTS.txt GAMEDIR [step|run|trace T]: the role-playing game against a capture of the real game.
// TICKS.snap holds RP's data segment (DS:0000-975F: data, BSS, stack), the shared block and memory 40000-9FFFF
// (the program's buffers) at every tick of its main loop (106a:0048); INPUTS.txt the time() results, the keys
// read, the frame waits (with the bytes the interrupt handlers keep) and the seedings in execution order. The C
// asks the host for them in the same order; a different order is reported as a mismatch.
//   step: every tick from the capture's own state, compared with the next (the default)
//   run:  from the first tick only
//   trace T: up to tick T, printing the functions tick T enters (for comparing with an instruction trace)
//   main MAIN.snap: from main's entry to the first tick (RP's start-up: its buffers, catalogs, the new game)
#include "asm2c.h"
#include "rp.h"
#include "shared.h"

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dsimage.h's far memory and stack
uint8_t *far_ptr(uint16_t seg, uint16_t off);
extern uint16_t g_sp;

#define DS_LEN 0x9760
// memory samples: 40000-9FFFF (older captures) or 00000-9FFFF (with the drivers)
static uint32_t MEM_BASE = 0x40000, MEM_LEN = 0x60000;
#define DS_SEG 0x41E2
#define SHARED_SEG 0x1942

typedef struct { uint32_t frame; uint64_t n; uint8_t *ds, *sh, *mem; } Tick;
typedef enum { E_TICK, E_TIME, E_KEY, E_WAIT, E_SEED, E_KB90 } Kind;
typedef struct { uint64_t n; Kind kind; uint32_t value, count; uint8_t f[8], k[8], j[2]; char site; } Event;

static uint32_t watchFn;  // WATCHFN=SEGOFF: the registers and the stack words at each entry of that function
static Event *ev;
static int nev, evPos, errors;
static uint32_t timeLeft;  // calls left in the current time or kb90 run

static const char *kind_name(Kind k) { return (const char *[]){ "tick", "time", "key", "wait", "seed", "kb90" }[k]; }

static jmp_buf exitJump;
static void mismatch(const char *what)
{
  if (errors > 50) longjmp(exitJump, 2);  // the C went elsewhere: give up the tick
  if (errors++ < 5) printf("  event %d (n=%llu): the C asked for %s, the game did %s\n", evPos, evPos < nev ? (unsigned long long)ev[evPos].n : 0ULL, what, evPos < nev ? kind_name(ev[evPos].kind) : "nothing");
}

// the next event that is not a tick
static Event *peek(void)
{
  while (evPos < nev && (ev[evPos].kind == E_TICK || ev[evPos].kind == E_SEED)) evPos++;  // srand() is the program's own
  return evPos < nev ? &ev[evPos] : NULL;
}

static uint8_t *dsImage;
static int traceEvents;  // trace mode: the events as they are served, among the function entries
static void tev(const char *k) { if (traceEvents) printf("E %s\n", k); }

static uint32_t host_time(void *ctx)
{
  (void)ctx;
  Event *e = peek();
  if (!e || e->kind != E_TIME) { mismatch("time()"); return 0; }
  if (!timeLeft) timeLeft = e->count;
  uint32_t v = e->value;
  if (--timeLeft == 0) evPos++;
  tev("time");
  return v;
}

static int host_key_waiting(void *ctx)
{
  (void)ctx;
  Event *e = peek();
  if (!e || e->kind != E_KB90) { mismatch("a key poll"); return 0; }
  if (!timeLeft) timeLeft = e->count;
  int v = (int)e->value;
  if (--timeLeft == 0) evPos++;
  tev("kb90");
  return v;
}

static uint16_t host_read_key(void *ctx)
{
  (void)ctx;
  Event *e = peek();
  if (!e || e->kind != E_KEY) { mismatch("a key"); return 0; }
  evPos++;
  tev("key");
  return (uint16_t)e->value;
}

static void host_frame_poll(void *ctx, uint8_t flag)
{
  (void)ctx;
  Event *e = peek();
  if (!e || e->kind != E_WAIT) { mismatch("a frame"); dsImage[0x3038] = 0xFF; return; }
  // the game's probe is after the loop: one event each time a wait loop ends, whether it had to wait or not
  (void)flag;
  memcpy(dsImage + 0x3038, e->f, 8);
  memcpy(dsImage + 0x3398, e->k, 8);
  memcpy(dsImage + 0x6EF0, e->j, 2);
  evPos++;
  tev("wait");
}

static void host_seeded(void *ctx, uint16_t seed)
{
  (void)ctx;
  Event *e = peek();
  if (!e || e->kind != E_SEED) { mismatch("srand()"); return; }
  if (e->value != seed && errors++ < 5) printf("  seed: C %04X, game %04X\n", seed, e->value);
  evPos++;
}

static int exitCode;
static const uint8_t *nextShared;  // the next tick's shared block: what the sub-game left
static int subgames;
static void host_subgame(void *ctx, int code)
{
  (void)ctx;
  printf("  sub-game %d\n", code);
  subgames++;
  uint16_t flag = shared_w(0x2c);
  memcpy(shared.b, nextShared, SHARED_SIZE);
  shared_set_w(0x2c, flag);  // RP's own flag (it clears it when it resumes)
}
static void host_exit(void *ctx, int code)
{
  (void)ctx;
  exitCode = code;
  longjmp(exitJump, 1);
}

static int hexdigit(char c) { return c <= '9' ? c - '0' : (c | 32) - 'a' + 10; }
static void hexbytes(const char *s, uint8_t *out, int n)
{
  for (int k = 0; k < n; k++) out[k] = (uint8_t)(hexdigit(s[2 * k]) << 4 | hexdigit(s[2 * k + 1]));
}

// the function entries: printed in trace mode, counted always (a tick that runs away is given up)
static long calls;
static void count_fn(uint32_t addr)
{
  if (++calls > 20000000)
  {
    printf("  runaway: 20 million function entries (the last %04X:%04X)\n", addr >> 16, addr & 0xFFFF);
    longjmp(exitJump, 3);
  }
}

static void print_fn(uint32_t addr)
{
  printf("F %04X:%04X\n", addr >> 16, addr & 0xFFFF);
  if (addr == watchFn)
  {
    printf("  SP=%04X BP=%04X stack:", R.sp, R.bp);
    for (int k = 0; k < 10; k++) printf(" %04X", *(u16a *)far_ptr(R.ss, (u16)(R.sp + 2 * k)));
    printf("\n");
  }
  count_fn(addr);
}

// the bytes the interrupt handlers keep (timer DS:3038-305F, keyboard DS:3398-339F) and the stack (DS:8F60-975F,
// where the reconstruction's frames are not where the original's were)
// and the picture decoder's work area (DS:419A-5BB2: its string table, re-initialised by every decode, and its
// private stack, which in the original also holds the frames of the catalog routines it calls for its input)
static uint16_t mainRegs[9];
static int haveMainRegs;
static jmp_buf tickJump;
static void stop_at_tick(void) { longjmp(tickJump, 1); }

static int volatile_byte(int k) { return (k >= 0x3038 && k < 0x3060) || (k >= 0x3398 && k < 0x33A0) || (k >= 0x419A && k < 0x5BB3) || k >= 0x8F60; }

int main(int argc, char **argv)
{
  setvbuf(stdout, NULL, _IOLBF, 0);
  if (argc < 4) { fprintf(stderr, "usage: rptest TICKS.snap INPUTS.txt GAMEDIR [step|run|trace T|main MAIN.snap]\n"); return 2; }
  FILE *f = fopen(argv[1], "rb");
  char magic[4];
  uint32_t len;
  if (!f || fread(magic, 1, 4, f) != 4 || memcmp(magic, "SNP2", 4) || fread(&len, 4, 1, f) != 1 || len < DS_LEN + SHARED_SIZE) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
  MEM_LEN = len - DS_LEN - SHARED_SIZE;
  MEM_BASE = 0xA0000 - MEM_LEN;
  Tick *t = NULL;
  int nt = 0;
  for (;;)
  {
    Tick k;
    if (fread(&k.frame, 4, 1, f) != 1 || fread(&k.n, 8, 1, f) != 1) break;
    k.ds = calloc(1, RP_DS_SIZE);
    k.sh = malloc(SHARED_SIZE);
    k.mem = malloc(MEM_LEN);
    if (fread(k.ds, 1, DS_LEN, f) != DS_LEN || fread(k.sh, 1, SHARED_SIZE, f) != SHARED_SIZE || fread(k.mem, 1, MEM_LEN, f) != MEM_LEN) break;
    t = realloc(t, sizeof *t * (nt + 1));
    t[nt++] = k;
  }
  fclose(f);
  FILE *fi = fopen(argv[2], "r");
  if (!fi) { fprintf(stderr, "cannot read %s\n", argv[2]); return 2; }
  char line[512];
  uint16_t (*tickRegs)[9] = NULL;
  int ntsp = 0, cap = 0, capSp = 0;
  while (fgets(line, sizeof line, fi))
  {
    Event e = { 0 };
    char *p = line, *q;
    e.n = strtoull(p, &q, 10);
    if (q == p) continue;
    p = q + 1;
    char kind[8] = { 0 };
    int k = 0;
    while (*p && *p != ' ' && *p != '\n' && k < 7) kind[k++] = *p++;
    if (*p == ' ') p++;
    if (!strcmp(kind, "tick"))  // SP [BP SI DI ES AX BX CX DX]
    {
      e.kind = E_TICK;
      if (ntsp == capSp) tickRegs = realloc(tickRegs, sizeof *tickRegs * (capSp = capSp * 2 + 16));
      uint16_t *r = tickRegs[ntsp++];
      for (int k = 0; k < 9; k++) { r[k] = (uint16_t)strtoul(p, &q, 16); if (q == p) { r[k] = k == 1 ? (uint16_t)(r[0] + 6) : 0; } p = q; }
    }
    else if (!strcmp(kind, "time")) { e.kind = E_TIME; e.value = (uint32_t)strtoul(p, &q, 16); e.count = (uint32_t)strtoul(q, 0, 10); }
    else if (!strcmp(kind, "kb90")) { e.kind = E_KB90; e.value = (uint32_t)strtoul(p, &q, 10); e.count = (uint32_t)strtoul(q, 0, 10); }
    else if (!strcmp(kind, "key")) { e.kind = E_KEY; strtoul(p, &q, 16); strtoul(q, &q, 16); e.value = (uint32_t)strtoul(q, 0, 16); }
    else if (!strcmp(kind, "wait"))
    {
      e.kind = E_WAIT;  // SITE, then the three probes' samples (at least 64 bytes each, as the tracer prints them)
      e.site = *p;
      p += 2;
      hexbytes(p, e.f, 8);
      p = strchr(p, ' ');
      if (p) { hexbytes(++p, e.k, 8); p = strchr(p, ' '); }
      if (p) hexbytes(++p, e.j, 2);
    }
    else if (!strcmp(kind, "seed")) { e.kind = E_SEED; e.value = (uint32_t)strtoul(p, 0, 16); }
    else if (!strcmp(kind, "main"))  // main's entry: SP BP SI DI ES AX BX CX DX
    {
      for (int k = 0; k < 9; k++) { mainRegs[k] = (uint16_t)strtoul(p, &q, 16); p = q; }
      haveMainRegs = 1;
      continue;
    }
    else continue;
    if (nev == cap) ev = realloc(ev, sizeof *ev * (size_t)(cap = cap * 2 + 1024));
    ev[nev++] = e;
  }
  fclose(fi);
  int run = argc > 4 && !strcmp(argv[4], "run");
  if (getenv("WATCHFN")) watchFn = (uint32_t)strtoul(getenv("WATCHFN"), 0, 16);
  int traceTick = argc > 5 && !strcmp(argv[4], "trace") ? atoi(argv[5]) : -1;
  static uint8_t ds[RP_DS_SIZE];
  dsImage = ds;
  RpHost host = { host_time, host_key_waiting, host_read_key, host_frame_poll, host_seeded, NULL, host_exit, host_subgame, argv[3], NULL };
  rp_attach(ds, DS_SEG, SHARED_SEG, &host);
  rp_set_arena(0x9000, 0x9FFF);
  if (argc > 5 && !strcmp(argv[4], "main"))
  {
    // main: from main's entry (MAIN.snap) to the main loop's first tick, compared with the capture's first tick
    FILE *fm = fopen(argv[5], "rb");
    static uint8_t mem[0xA0000];
    if (!fm || fread(ds, 1, DS_LEN, fm) != DS_LEN || fread(shared.b, 1, SHARED_SIZE, fm) != SHARED_SIZE || fread(mem, 1, sizeof mem, fm) != sizeof mem || !haveMainRegs || nt < 1) { fprintf(stderr, "cannot read %s (or no main in the inputs)\n", argv[5]); return 2; }
    fclose(fm);
    memcpy(far_ptr(0, 0), mem, sizeof mem);
    rp_arena_from_memory(0x2700, 0xA000);
    evPos = 0;
    timeLeft = 0;
    errors = 0;
    exitCode = -1;
    nextShared = t[0].sh;
    rp_trace = count_fn;
    rp_tickHook = stop_at_tick;
    int r = setjmp(tickJump);
    if (!r && !setjmp(exitJump)) rp_main(mainRegs);
    rp_tickHook = NULL;
    rp_trace = NULL;
    if (!r) printf("  the C did not reach the main loop\n");
    if (evPos < nev && peek() && peek()->n < t[0].n && errors++ < 5) printf("  the game had more before the first tick: %s at n=%llu\n", kind_name(peek()->kind), (unsigned long long)peek()->n);
    int diff = 0, s2 = 0;
    for (int k = 0; k < DS_LEN; k++)
      if (ds[k] != t[0].ds[k] && !volatile_byte(k)) { if (s2++ < 12) printf(" %04X:%02X/%02X", k, ds[k], t[0].ds[k]); diff++; }
    for (int k = 0; k < SHARED_SIZE; k++)
      if (shared.b[k] != t[0].sh[k]) { if (s2++ < 12) printf(" shared+%03X:%02X/%02X", k, shared.b[k], t[0].sh[k]); diff++; }
    printf("\n%s: main to the first tick: %d bytes differ, %d input differences (main)\n", argv[1], diff, errors);
    return diff || errors;
  }
  int bad = 0, shown = 0, show = getenv("SHOW") ? atoi(getenv("SHOW")) : 12;
  for (int g = 0; g + 1 < nt; g++)
  {
    Tick *a = &t[g], *b = &t[g + 1];
    if (!run || g == 0)
    {
      memcpy(ds, a->ds, RP_DS_SIZE);
      memcpy(shared.b, a->sh, SHARED_SIZE);
      memcpy(far_ptr(MEM_BASE >> 4, 0), a->mem, MEM_LEN);
      rp_arena_from_memory(0x4000, 0xA000);
    }
    evPos = 0;
    timeLeft = 0;
    while (evPos < nev && ev[evPos].n < a->n) evPos++;
    uint16_t defaultRegs[9] = { 0x9736, 0x973C };
    const uint16_t *regs = g < ntsp ? tickRegs[g] : defaultRegs;
    errors = 0;
    if (traceTick >= 0 && g == traceTick)
    {
      printf("tick %d from n=%llu to n=%llu frames %u %u\n", g, (unsigned long long)a->n, (unsigned long long)b->n, a->frame, b->frame);
      rp_trace = print_fn;
      traceEvents = 1;
    }
    exitCode = -1;
    nextShared = b->sh;
    calls = 0;
    if (!rp_trace) rp_trace = count_fn;
    if (!setjmp(exitJump)) rp_tick(regs);
    if (exitCode >= 0) printf("  exit(%d)\n", exitCode);
    rp_trace = NULL;
    traceEvents = 0;
    // the tick ends at the next tick's sample, where the next event is that tick
    if (evPos < nev && ev[evPos].n < b->n)
    {
      Event *e = peek();
      if (e && e->n < b->n && errors++ < 5) printf("  the game had more before the next tick: %s at n=%llu\n", kind_name(e->kind), (unsigned long long)e->n);
    }
    int diff = 0;
    for (int k = 0; k < DS_LEN; k++) diff += ds[k] != b->ds[k] && !volatile_byte(k);
    for (int k = 0; k < SHARED_SIZE; k++) diff += shared.b[k] != b->sh[k];
    if (diff || errors)
    {
      bad++;
      if (shown++ < 8)
      {
        printf("tick %d (video %u): %d bytes differ", g + 1, b->frame, diff);
        int s = 0;
        for (int k = 0; k < DS_LEN && s < show; k++)
          if (ds[k] != b->ds[k] && !volatile_byte(k)) { printf(" %04X:%02X/%02X", k, ds[k], b->ds[k]); s++; }
        for (int k = 0; k < SHARED_SIZE && s < show; k++)
          if (shared.b[k] != b->sh[k]) { printf(" shared+%03X:%02X/%02X", k, shared.b[k], b->sh[k]); s++; }
        printf("\n");
      }
      if (run) break;
    }
    if (traceTick >= 0 && g == traceTick) break;
  }
  printf("%s: %d ticks, %d into sub-games, %d differ (%s)\n", argv[1], nt, subgames, bad, run ? "run" : "step");
  return bad != 0;
}
