// soundtest SND.TXT GAMEDIR [I|T]: a sound driver (I: the IBM speaker's, ISOUND.SAM: isound.c; T: Tandy's, TSOUND.SAM:
// tsound.c; recompiled whole) against a capture of
// the real one (the workspace's oracle/cap_snd.sh + snd_ev.py): the driver's slot calls as the game made them,
// the port reads as the game got them, and every port write compared. The PWM player's polls of the PIT's channel
// 0 (04A8, the loop's timing, not captured) are answered by a counter that wraps every fourth read, and its latch
// command (04A4) is not compared. With no joystick the game's driver jumps over its button read (it writes the jump
// at 0478 at its start); here the read answers no button. The timer's interrupts that came in a call (its ticks)
// run at the call's next port access (or where it waits for them), and the PWM songs' key checks see the BIOS's
// keyboard buffer as the game's.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asm2c.h"
#include "dsimage.h"
#include "exe.h"

void is_slot(int slot);
void ts_slot(int slot);
static char drv = 'I';

typedef struct
{
  char kind;  // c r o i
  int a, b;
  int frame;
} Ev;

static Ev *ev;
static int nev, pos, errors, lastFrame;

static void fail(const char *what, int port, int value)
{
  if (errors++ < 10)
  {
    Ev *e = pos < nev ? &ev[pos] : NULL;
    printf("  event %d (frame %d): the C %s %02X %02X, the game ", pos, e ? e->frame : lastFrame, what, port, value);
    if (e) printf("%c %02X %02X\n", e->kind, e->a, e->b);
    else printf("had no more\n");
  }
}

// the timer's interrupts that came while a call ran (the ticks, slots 2 and 3, before its next port access in the
// capture): run there, on its stack, its registers kept
static int depth, calls;
static void call(int slot, u16 arg);
static void interrupts(void)
{
  while (depth > 0 && pos < nev && ev[pos].kind == 'c' && (ev[pos].a == 2 || ev[pos].a == 3))
  {
    Regs saved = R;
    int slot = ev[pos++].a;
    call(slot, 0);
    R = saved;
  }
}

// a PWM song's key check coming (its note's end, after the channel 0 polls): the BIOS's keyboard buffer as the
// game's was (a key waiting or none)
static void keys(void)
{
  while (pos < nev && ev[pos].kind == 'k')
  {
    *(u16a *)far_ptr(0x40, 0x1C) = (u16)(*(u16a *)far_ptr(0x40, 0x1A) + (ev[pos].a ? 2 : 0));
    pos++;
  }
}

// a wait for the tick in a call: the ticks that came meanwhile (the capture's next ones), else it would wait forever
static void idle(void)
{
  int before = pos;
  interrupts();
  if (pos == before)
  {
    fail("waits for a tick; the game has", 0, 0);
    printf("%d calls, %d events, %d differences\n", calls, nev, errors);
    exit(1);
  }
}

static u8 pit0 = 0x7e;
static u16 port_in(u16 port)
{
  interrupts();
  keys();
  if (port == 0x40)
  {
    pit0 = (u8)(pit0 < 0x30 ? 0x7e : pit0 - 0x20);
    return pit0;
  }
  // the joystick's buttons: none pressed (the game's driver, with no joystick, jumps over its read: 0478)
  if (port == 0x201) return 0xFF;
  if (pos < nev && ev[pos].kind == 'i' && ev[pos].a == port) return (u16)ev[pos++].b;
  fail("reads", port, 0);
  return 0xFF;
}

static bool port_out(u16 port, u8 v)
{
  interrupts();
  keys();
  if (port == 0x43 && v == 0x00) return true;  // the PWM loop's latch
  if (pos < nev && ev[pos].kind == 'o' && ev[pos].a == port && ev[pos].b == v) pos++;
  else fail("writes", port, v);
  keys();
  return true;
}

static void call(int slot, u16 arg)
{
  PUSH(arg);     // slot 1's sound (the others take none)
  PUSH(0x1234);  // the caller's far return
  PUSH(0x0000);
  depth++;
  if (drv == 'T') ts_slot(slot);
  else is_slot(slot);
  depth--;
  R.sp += 2;
  calls++;
  if (slot == 2)
  {
    if (pos < nev && ev[pos].kind == 'r' && ev[pos].a == R.ax) pos++;
    else fail("ticks, returning", R.ax >> 8, R.ax & 0xFF);
  }
}

int main(int argc, char **argv)
{
  if (argc < 3) { fprintf(stderr, "usage: soundtest SND.TXT GAMEDIR [I|T]\n"); return 2; }
  if (argc > 3) drv = argv[3][0];
  FILE *f = fopen(argv[1], "r");
  if (!f) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
  char line[256];
  int cap = 0, frame = 0;
  while (fgets(line, sizeof line, f))
  {
    Ev e = { line[0], 0, 0, frame };
    if (line[0] == 'F') { frame = atoi(line + 2); continue; }
    if (sscanf(line + 2, "%x %x", (unsigned *)&e.a, (unsigned *)&e.b) < 1) continue;
    if (nev == cap) ev = realloc(ev, sizeof *ev * (size_t)(cap = cap * 2 + 1024));
    ev[nev++] = e;
  }
  fclose(f);
  char path[1024];
  snprintf(path, sizeof path, "%s/%s", argv[2], drv == 'T' ? "TSOUND.SAM" : "ISOUND.SAM");
  ExeInfo info;
  if (!exe_load(path, 0xD000, &info)) { fprintf(stderr, "cannot load %s\n", path); return 2; }
  // the shared block's segment at 0000:04F0 (the driver reads the joystick flag there, +34: none)
  g_sharedSeg = 0x1942;  // (segment 0 is memory, not the shared block)
  *(u16a *)far_ptr(0, 0x4F0) = 0x1942;
  *(u16a *)far_ptr(0x40, 0x1A) = *(u16a *)far_ptr(0x40, 0x1C) = 0x1E;  // the keyboard buffer: empty
  asm_port_hook = port_in;
  asm_port_out_hook = port_out;
  asm_idle_hook = idle;
  R.ss = 0x9000;
  R.sp = 0xFFF0;
  while (pos < nev && errors < 10)
  {
    Ev *e = &ev[pos];
    lastFrame = e->frame;
    if (e->kind != 'c') { fail("expected a call, not", e->kind, 0); pos++; continue; }
    pos++;
    call(e->a, (u16)e->b);
  }
  printf("%s: %d calls, %d events, %d differences\n", argv[1], calls, nev, errors);
  return errors != 0;
}
