// duelexetest DUEL.snap INPUTS.txt GAMEDIR [run|step]: the duel program (DUEL.EXE recompiled) against a capture of
// the real game (the workspace's oracle/gen_duel.py and du_ev.py). DUEL.snap holds the state at main's entry (the
// data segment DS:0000-6C1F, the shared block, memory 00000-9FFFF) and, at every frame wait's end and at exit(),
// the data segment and the shared block; INPUTS.txt the answers the program got (DOS's, the BIOS's, MISC's), each
// kind in its order, the frame waits (with the frame timer's bytes) and the keyboard joystick's bytes at its
// reads in theirs. The C runs from main to exit() on those answers and is compared at every checkpoint.
//   run:  from main's state only (the default)
//   step: the capture's data segment and shared block again at every checkpoint (after comparing), so that the
//         checkpoints after a difference are compared too
#include "asm2c.h"
#include "dosmem.h"
#include "shared.h"
#include "duelexe.h"

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t *far_ptr(uint16_t seg, uint16_t off);

#define SHARED_SEG 0x1942
#define MEM_LEN 0xA0000

typedef struct { uint32_t frame; uint64_t n; uint16_t kind, site; uint8_t *ds, *sh; } Check;
typedef struct { uint32_t value, count; int wait; } Run;  // wait: the frame waits before its first answer
typedef struct { Run *r; int n, cap, pos; uint32_t left; const char *name; } Queue;
typedef struct { uint8_t bytes[0x23]; int check; } Wait;
typedef struct { uint16_t site; uint8_t bytes[10]; } Kbd;

static Check *chk;
static int nchk;
#define NQ 16
static Queue q[NQ];
static int qkind[NQ], nq;  // the kinds of answers (du_ev.py's WHAT)
static Kbd *kbds;
static int nkbds, kbdPos;  // qd: MISC slots 90..97
static Wait *waits;
static int nwaits;
static Queue *queue_of(int kind, int create)
{
  for (int k = 0; k < nq; k++)
    if (qkind[k] == kind) return &q[k];
  if (!create || nq == NQ) return NULL;
  qkind[nq] = kind;
  static char names[NQ][16];
  snprintf(names[nq], 16, "answer %X", kind);
  q[nq].name = names[nq];
  return &q[nq++];
}
static int exitCode = -1, exitCheck = -1;
static int stepMode, errors, badChecks, shownChecks, show = 12;
static uint32_t dsLen;
static uint8_t ds[0x10000];
static jmp_buf exitJump;

static void push(Queue *q, uint32_t v, uint32_t count, int wait)
{
  if (q->n == q->cap) q->r = realloc(q->r, sizeof *q->r * (size_t)(q->cap = q->cap * 2 + 64));
  q->r[q->n++] = (Run){ v, count, wait };
}

static int waitPos, desync;
static int pop(Queue *q, uint32_t *v)
{
  if (!q->left)
  {
    if (q->pos >= q->n) return 0;
    Run *r = &q->r[q->pos++];
    q->left = r->count;
    // the answers change in the C at the frame where they changed in the game
    if (r->wait >= 0 && r->wait != waitPos && desync++ < 8)
      printf("  %s: the answer %X after %d frame waits in the game, %d in the C\n", q->name, r->value, r->wait, waitPos);
  }
  q->left--;
  *v = q->r[q->pos - 1].value;
  return 1;
}

static void problem(const char *fmt, const char *what)
{
  if (waitPos >= nwaits && exitCheck < 0) longjmp(exitJump, 3);  // past the last checkpoint of a capture without an exit: its end
  if (errors++ < 8) { printf("  "); printf(fmt, what); printf(" (at wait %d)\n", waitPos); }
  if (errors > 50) longjmp(exitJump, 2);  // the C went elsewhere
}

static uint32_t host_answer(void *ctx, int what)
{
  (void)ctx;
  int kind = what >= 0x1600 && what < 0x1700 ? 0x16 : what;  // the BIOS keyboard: one queue for its functions
  Queue *qq = queue_of(kind, 0);
  uint32_t v = 0;
  char name[32];
  snprintf(name, sizeof name, "answer %X", what);
  if (!qq || !pop(qq, &v)) problem("the C asked for %s more often than the game", name);
  return v;
}

// the bytes the C may have otherwise: the stack (DS:6410-6C0F: the interrupt handlers' frames in the original,
// which stay in the locals a function reads only after writing them), the picture decoder's private stack and its
// saved stack pointer (the original's coroutine frames)
static int volatile_byte(uint32_t k, uint16_t sp) { (void)sp; return (k >= 0x6410 && k < 0x6C10) || (k >= 0x485F && k < 0x4A5F) || k == 0x484C || k == 0x484D; }

static void compare(int c, const char *what)
{
  Check *b = &chk[c];
  int diff = 0;
  for (uint32_t k = 0; k < dsLen; k++) diff += ds[k] != b->ds[k] && !volatile_byte(k, R.sp);
  for (int k = 0; k < SHARED_SIZE; k++) diff += shared.b[k] != b->sh[k];
  if (diff)
  {
    badChecks++;
    if (shownChecks++ < 10)
    {
      printf("checkpoint %d (%s, video frame %u): %d bytes differ", c, what, b->frame, diff);
      int s = 0;
      for (uint32_t k = 0; k < dsLen && s < show; k++)
        if (ds[k] != b->ds[k] && !volatile_byte(k, R.sp)) { printf(" %04X:%02X/%02X", k, ds[k], b->ds[k]); s++; }
      for (int k = 0; k < SHARED_SIZE && s < show; k++)
        if (shared.b[k] != b->sh[k]) { printf(" shared+%03X:%02X/%02X", k, shared.b[k], b->sh[k]); s++; }
      printf("\n");
    }
  }
  if (stepMode)
  {
    memcpy(ds, b->ds, dsLen);
    memcpy(shared.b, b->sh, SHARED_SIZE);
  }
}

static void host_frame_poll(void *ctx)
{
  (void)ctx;
  if (waitPos >= nwaits)
  {
    if (exitCheck < 0) longjmp(exitJump, 3);  // the capture ends here (before exit())
    problem("the C waited for %s more often than the game", "the frame timer");
    return;
  }
  Wait *w = &waits[waitPos];
  memcpy(ds + 0x22A6, w->bytes, sizeof w->bytes);
  // the keyboard joystick's bytes change with the keys (its interrupt): as they are at the wait's end
  if (w->check >= 0) memcpy(ds + 0x22F2, chk[w->check].ds + 0x22F2, 10);
  char what[32];
  snprintf(what, sizeof what, "wait %d", waitPos);
  waitPos++;
  if (w->check >= 0) compare(w->check, what);
}

static void host_keyboard_poll(void *ctx, int site)
{
  (void)ctx;
  if (kbdPos >= nkbds) { problem("the C read %s more often than the game", "the keyboard joystick"); return; }
  Kbd *k = &kbds[kbdPos++];
  if (k->site != site) problem("the C read %s at another place than the game", "the keyboard joystick");
  memcpy(ds + 0x22F2, k->bytes, sizeof k->bytes);
}

// TRACEWAIT=N: the functions the C enters from frame wait N on (the first TRACEMAX, default 2000)
static int traceWait = -1, traceLeft = 2000;
static void trace_fn(uint32_t addr)
{
  if (waitPos >= traceWait && traceLeft > 0)
  {
    traceLeft--;
    printf("F %04X:%04X sp=%04X ax=%04X bx=%04X cx=%04X dx=%04X\n", addr >> 16, addr & 0xFFFF, R.sp, R.ax, R.bx, R.cx, R.dx);
  }
}

static bool exited;
static void host_exit(void *ctx, int code)
{
  (void)ctx;
  exitCode = code;
  exited = true;
  longjmp(exitJump, 1);
}

static void hexbytes(const char *p, uint8_t *out, int n)
{
  for (int k = 0; k < n && p[0] && p[1]; k++, p += 2)
  {
    char h[3] = { p[0], p[1], 0 };
    out[k] = (uint8_t)strtoul(h, 0, 16);
  }
}

int main(int argc, char **argv)
{
  setvbuf(stdout, NULL, _IOLBF, 0);
  if (argc < 4) { fprintf(stderr, "usage: duelexetest DUEL.snap INPUTS.txt GAMEDIR [run|step]\n"); return 2; }
  stepMode = argc > 4 && !strcmp(argv[4], "step");
  if (getenv("SHOW")) show = atoi(getenv("SHOW"));
  FILE *f = fopen(argv[1], "rb");
  char magic[4];
  if (!f || fread(magic, 1, 4, f) != 4 || memcmp(magic, "DUE1", 4) || fread(&dsLen, 4, 1, f) != 1 || dsLen > 0x10000) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
  static uint8_t mainDs[0x10000], mainSh[SHARED_SIZE];
  uint8_t *mem = malloc(MEM_LEN);
  if (fread(mainDs, 1, dsLen, f) != dsLen || fread(mainSh, 1, SHARED_SIZE, f) != SHARED_SIZE || fread(mem, 1, MEM_LEN, f) != MEM_LEN) { fprintf(stderr, "%s: no main state\n", argv[1]); return 2; }
  int cap = 0;
  for (;;)
  {
    Check k;
    if (fread(&k.frame, 4, 1, f) != 1 || fread(&k.n, 8, 1, f) != 1 || fread(&k.kind, 2, 1, f) != 1 || fread(&k.site, 2, 1, f) != 1) break;
    k.ds = malloc(dsLen);
    k.sh = malloc(SHARED_SIZE);
    if (fread(k.ds, 1, dsLen, f) != dsLen || fread(k.sh, 1, SHARED_SIZE, f) != SHARED_SIZE) break;
    if (nchk == cap) chk = realloc(chk, sizeof *chk * (size_t)(cap = cap * 2 + 256));
    chk[nchk++] = k;
  }
  fclose(f);
  FILE *fi = fopen(argv[2], "r");
  if (!fi) { fprintf(stderr, "cannot read %s\n", argv[2]); return 2; }
  char line[256];
  uint16_t regs[9] = { 0 };
  int wcap = 0;
  while (fgets(line, sizeof line, fi))
  {
    char *p = line, *q;
    if (!strncmp(p, "main ", 5))
    {
      p += 5;
      for (int k = 0; k < 9; k++) { regs[k] = (uint16_t)strtoul(p, &q, 16); p = q; }
    }
    else if (!strncmp(p, "a ", 2))  // WHAT VALUE COUNT WAITS
    {
      int kind = (int)strtol(p + 2, &q, 16);
      uint32_t v = (uint32_t)strtoul(q, &q, 16), n = (uint32_t)strtoul(q, &q, 10);
      int w = (int)strtol(q, &p, 10);
      push(queue_of(kind, 1), v, n, p == q ? -1 : w);
    }
    else if (!strncmp(p, "kbd ", 4))
    {
      if (nkbds % 256 == 0) kbds = realloc(kbds, sizeof *kbds * (size_t)(nkbds + 256));
      Kbd *k = &kbds[nkbds++];
      k->site = (uint16_t)strtoul(p + 4, &q, 16);
      hexbytes(q + 1, k->bytes, 10);
    }
    else if (!strncmp(p, "wait ", 5))
    {
      if (nwaits == wcap) waits = realloc(waits, sizeof *waits * (size_t)(wcap = wcap * 2 + 256));
      Wait *w = &waits[nwaits++];
      hexbytes(p + 5, w->bytes, sizeof w->bytes);
      q = strchr(p + 5, ' ');
      w->check = q ? atoi(q + 1) : -1;
    }
    else if (!strncmp(p, "exit ", 5))
    {
      exitCheck = (int)strtol(p + 5, &q, 10);  // the code, then the checkpoint
      exitCheck = atoi(q);
    }
  }
  fclose(fi);
  DuelHost host = { host_answer, host_frame_poll, host_keyboard_poll, host_exit, argv[3], NULL };
  duel_attach(ds, SHARED_SEG, &host);
  memcpy(far_ptr(0, 0), mem, MEM_LEN);  // the flat megabyte (the data segment and the shared block are their own)
  free(mem);
  memcpy(ds, mainDs, dsLen);
  memcpy(shared.b, mainSh, SHARED_SIZE);
  dos_arena_from_memory(0x2700, 0xA000);
  if (getenv("TRACEWAIT"))
  {
    traceWait = atoi(getenv("TRACEWAIT"));
    if (getenv("TRACEMAX")) traceLeft = atoi(getenv("TRACEMAX"));
    duel_trace = trace_fn;
  }
  int r = setjmp(exitJump);
  if (!r) duel_main(regs);
  if (r == 2) printf("  gave up: too many differences in the inputs\n");
  if (r == 3) printf("  the end of the capture\n");
  if (exited)
  {
    printf("  exit(%d)\n", exitCode);
    if (exitCheck >= 0)
    {
      // the interrupt handlers' bytes (the frame timer's, the keyboard joystick's) as they are at the end
      memcpy(ds + 0x22A6, chk[exitCheck].ds + 0x22A6, 0x23);
      memcpy(ds + 0x22F2, chk[exitCheck].ds + 0x22F2, 10);
      compare(exitCheck, "exit");
    }
  }
  else if (exitCheck >= 0) printf("  the C did not reach exit()\n");
  if (waitPos < nwaits && r != 1 && r != 3) printf("  the game waited %d more times\n", nwaits - waitPos);
  printf("%s: %d checkpoints, %d waits served of %d, %d checkpoints differ, %d input differences, %d out of step (%s)\n", argv[1], nchk, waitPos, nwaits, badChecks, errors, desync, stepMode ? "step" : "run");
  return badChecks || errors || desync || (exitCheck >= 0 && !exited);
}
