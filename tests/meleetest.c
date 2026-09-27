// meleetest TICKS.snap INPUTS.txt [step|run]: the melee against a capture of the real game.
// TICKS.snap holds MELEE's data segment (DS:0000-AFFF) and the shared block every time the timer routine
// 1000:07C2 is called, i.e. once per elapsed 60 Hz tick, with the instruction count; INPUTS.txt the control reads and the random
// seedings in execution order. Samples with the same loop counter (DS:342E) come from one pass of the game
// loop; each such group starts where the C resumes: it finishes that pass, runs the passes without a tick
// in between, and starts the next pass up to its first timer decrement, where the next group starts.
//   step: every group from the capture's own state, compared with the next (the default)
//   run:  from the first group only
//   trace G: up to group G, printing the functions it enters (for comparing with an instruction trace)
#include "melee.h"
#include "shared.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void melee_set_pending_ticks(int n);

typedef struct { uint32_t frame; uint64_t n; uint8_t *ds, *sh; } Tick;
typedef struct { uint64_t n; int kind; MeleeInput in; uint16_t seed; } Event;  // kind 0 dir, 1 fire, 2 seed

static Event *ev;
static int nev, evPos, errors;

static int next_event(int kind, const char *what)
{
  while (evPos < nev && ev[evPos].kind != kind)
  {
    if (errors++ < 5) printf("  event %d: the C asked for %s, the game did %s next\n", evPos, what, ev[evPos].kind == 2 ? "a seeding" : ev[evPos].kind ? "a fire read" : "a direction read");
    evPos++;
  }
  return evPos < nev ? evPos++ : -1;
}

static MeleeInput host_dir(void *ctx) { (void)ctx; int i = next_event(0, "a direction read"); return i < 0 ? (MeleeInput){ 0 } : ev[i].in; }
static MeleeInput host_fire(void *ctx) { (void)ctx; int i = next_event(1, "a fire read"); return i < 0 ? (MeleeInput){ 0 } : ev[i].in; }
static uint16_t host_clock(void *ctx) { (void)ctx; return evPos < nev && ev[evPos].kind == 2 ? ev[evPos].seed : 0; }
static void host_seeded(void *ctx, uint16_t seed)
{
  (void)ctx;
  int i = next_event(2, "a seeding");
  if (i >= 0 && ev[i].seed != seed && errors++ < 5) printf("  seed %d: C %04X, game %04X\n", i, seed, ev[i].seed);
}

// the interrupt handlers' own state, which the reconstruction has no counterpart of: the keyboard's
// (1FE7:00FA: the virtual joystick DS:398C-398F, which changes whenever a key does and reaches the C
// through the input events, and its key state 3990-3995) and the timer's (1FE7:0086-02FF: PIT rate,
// retrace calibration, tick dividers)
static int isr_state(int k) { return (k >= 0x398C && k <= 0x3995) || (k >= 0x46AA && k <= 0x46CA); }

// trace: the functions entered, and (WATCH=OFF[,LEN]) the changes of a range of the data segment between entries
static uint8_t *traceDs, watchOld[64];
static int watchOff = -1, watchLen = 1;
static void print_fn(uint16_t addr)
{
  for (int k = 0; watchOff >= 0 && k < watchLen; k++)
    if (traceDs[watchOff + k] != watchOld[k])
    {
      printf("W %04X %02X -> %02X\n", watchOff + k, watchOld[k], traceDs[watchOff + k]);
      watchOld[k] = traceDs[watchOff + k];
    }
  printf("F %04X\n", addr);
}

static uint16_t W(const uint8_t *ds, int off) { return (uint16_t)(ds[off] | (ds[off + 1] << 8)); }

int main(int argc, char **argv)
{
  if (argc < 3) { fprintf(stderr, "usage: meleetest TICKS.snap INPUTS.txt [step|run]\n"); return 2; }
  FILE *f = fopen(argv[1], "rb");
  char magic[4];
  uint32_t len;
  if (!f || fread(magic, 1, 4, f) != 4 || memcmp(magic, "SNP2", 4) || fread(&len, 4, 1, f) != 1) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
  // the data segment DS:0000-AFFF, then (newer captures) the shared block
  uint32_t dsLen = len < 0xB000 ? len : 0xB000, shLen = len - dsLen;
  if (shLen > SHARED_SIZE) { fprintf(stderr, "%s: bad sample length\n", argv[1]); return 2; }
  Tick *t = NULL;
  int nt = 0;
  for (;;)
  {
    Tick k;
    if (fread(&k.frame, 4, 1, f) != 1 || fread(&k.n, 8, 1, f) != 1) break;
    k.ds = calloc(1, MELEE_DS_SIZE);
    k.sh = calloc(1, SHARED_SIZE);
    if (fread(k.ds, 1, dsLen, f) != dsLen || fread(k.sh, 1, shLen, f) != shLen) break;
    t = realloc(t, sizeof *t * (nt + 1));
    t[nt++] = k;
  }
  fclose(f);
  FILE *fi = fopen(argv[2], "r");
  if (!fi) { fprintf(stderr, "cannot read %s\n", argv[2]); return 2; }
  char line[256];
  while (fgets(line, sizeof line, fi))
  {
    Event e = { 0 };
    char kind[8];
    unsigned long long n;
    unsigned a, b, c, d;
    if (sscanf(line, "%llu %7s", &n, kind) != 2) continue;
    e.n = n;
    if (!strcmp(kind, "seed")) { sscanf(line, "%*llu %*s %x", &a); e.kind = 2; e.seed = (uint16_t)a; }
    else { sscanf(line, "%*llu %*s %x %x %x %x", &a, &b, &c, &d); e.kind = !strcmp(kind, "fire"); e.in = (MeleeInput){ (int8_t)a, (int8_t)b, (uint8_t)c, (uint8_t)d }; }
    ev = realloc(ev, sizeof *ev * (nev + 1));
    ev[nev++] = e;
  }
  fclose(fi);
  int run = argc > 3 && !strcmp(argv[3], "run");
  int traceGroup = argc > 4 && !strcmp(argv[3], "trace") ? atoi(argv[4]) : -1;
  // groups: consecutive samples of one pass
  int *gs = malloc(sizeof(int) * (nt + 1)), ng = 0;
  for (int k = 0; k < nt; k++)
    if (k == 0 || W(t[k].ds, 0x342E) != W(t[k - 1].ds, 0x342E)) gs[ng++] = k;
  gs[ng] = nt;
  static uint8_t ds[MELEE_DS_SIZE];
  MeleeHost host = { host_dir, host_fire, host_clock, host_seeded, NULL };
  melee_attach(ds, &host);
  int bad = 0, restarts = 0, shown = 0, show = getenv("SHOW") ? atoi(getenv("SHOW")) : 12;
  memcpy(ds, t[0].ds, MELEE_DS_SIZE);
  memcpy(shared.b, t[0].sh, SHARED_SIZE);
  for (int g = 0; g + 1 < ng; g++)
  {
    const Tick *a = &t[gs[g]], *b = &t[gs[g + 1]];
    // a new run of the program (the loop counter starts again): start from its own state
    if ((uint16_t)(W(b->ds, 0x342E) - W(a->ds, 0x342E)) > 0x8000 || W(b->ds, 0x342E) < W(a->ds, 0x342E))
    {
      memcpy(ds, b->ds, MELEE_DS_SIZE);
      memcpy(shared.b, b->sh, SHARED_SIZE);
      restarts++;
      continue;
    }
    if (traceGroup >= 0 && g == traceGroup)
    {
      printf("group %d from n=%llu to n=%llu frames %u %u\n", g, (unsigned long long)a->n, (unsigned long long)b->n, a->frame, b->frame);
      melee_trace = print_fn;
      traceDs = ds;
      if (getenv("WATCH")) sscanf(getenv("WATCH"), "%x,%d", &watchOff, &watchLen);
      if (watchLen > 64) watchLen = 64;
      for (int k = 0; watchOff >= 0 && k < watchLen; k++) watchOld[k] = a->ds[watchOff + k];
    }
    if (!run)
    {
      memcpy(ds, a->ds, MELEE_DS_SIZE);
      memcpy(shared.b, a->sh, SHARED_SIZE);
    }
    evPos = 0;
    while (evPos < nev && ev[evPos].n < a->n) evPos++;
    errors = 0;
    melee_set_pending_ticks(gs[g + 1] - gs[g]);
    melee_pass_finish();
    int passes = (uint16_t)(W(b->ds, 0x342E) - W(a->ds, 0x342E));
    for (int p = 1; p < passes; p++)
    {
      melee_set_pending_ticks(0);
      melee_pass_start();
      melee_pass_finish();
    }
    ds[0x53] = b->ds[0x53];
    ds[0x54] = b->ds[0x54];
    melee_pass_start();
    if (traceGroup >= 0 && g == traceGroup) print_fn(0x07C2);  // the next group's first timer decrement, where the capture stops
    int diff = 0;
    for (int k = 0; k < (int)dsLen; k++) diff += ds[k] != b->ds[k] && !isr_state(k);
    for (int k = 0; k < (int)shLen; k++) diff += shared.b[k] != b->sh[k];
    if (diff || errors)
    {
      bad++;
      if (shown++ < 8)
      {
        printf("group %d (video %u, pass %u): %d bytes differ", g + 1, b->frame, W(b->ds, 0x342E), diff);
        int s = 0;
        for (int k = 0; k < (int)dsLen && s < show; k++)
          if (ds[k] != b->ds[k] && !isr_state(k)) { printf(" %04X:%02X/%02X", k, ds[k], b->ds[k]); s++; }
        for (int k = 0; k < (int)shLen && s < show; k++)
          if (shared.b[k] != b->sh[k]) { printf(" shared+%03X:%02X/%02X", k, shared.b[k], b->sh[k]); s++; }
        printf("\n");
      }
      if (run) break;
    }
    if (traceGroup >= 0 && g == traceGroup) break;
  }
  printf("%s: %d ticks, %d passes groups, %d runs, %d differ (%s)\n", argv[1], nt, ng, restarts + 1, bad, run ? "run" : "step");
  return bad != 0;
}
