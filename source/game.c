// The game as its launcher runs it (game.h). SAMURAI.COM (the original launcher, OLD.COM in the provided game
// directory) publishes a 1 KB shared block, loads MISC.EXE, runs SU.EXE (the setup), loads the graphics driver
// with FONTS.SAM after it and the sound driver, allocates a picture buffer, runs START.EXE, and then RP.EXE and
// the action games by the exit codes. Here the setup's choices are VGA, no sound and no joystick.
#include "game.h"

#include <stdio.h>
#include <string.h>

#include "asm2c.h"
#include "dos.h"
#include "dosmem.h"
#include "exe.h"
#include "shared.h"
#include "start.h"
#include "rp.h"
#include "duelexe.h"

#include <setjmp.h>
#include <time.h>

static const GameHost *host;

// the BIOS's keyboard buffer: the host's keys, with one taken ahead for a look (INT 16h/01)
static bool keyAhead;
static uint16_t keyAheadValue;
static bool key_waiting(void) { return keyAhead || (host->keyWaiting && host->keyWaiting(host->ctx)); }
static uint16_t key_peek(void)
{
  if (!keyAhead && host->keyWaiting && host->keyWaiting(host->ctx)) keyAheadValue = host->readKey(host->ctx), keyAhead = true;
  return keyAhead ? keyAheadValue : 0;
}
static uint16_t key_read(void)
{
  uint16_t k = key_peek();
  keyAhead = false;
  return k;
}

static void w16(uint16_t seg, uint16_t off, uint16_t v)
{
  far_ptr(seg, off)[0] = (uint8_t)v;
  far_ptr(seg, off)[1] = (uint8_t)(v >> 8);
}

static bool game_file(const char *name, char *path, size_t n)
{
  snprintf(path, n, "%s/%s", host->gameDir, name);
  FILE *f = fopen(path, "rb");
  if (f)
  {
    fclose(f);
    return true;
  }
  // the names are the DOS ones: look for them in any case
  char lower[64];
  size_t k = 0;
  for (; name[k] && k < sizeof lower - 1; k++) lower[k] = (char)(name[k] >= 'A' && name[k] <= 'Z' ? name[k] + 32 : name[k]);
  lower[k] = 0;
  snprintf(path, n, "%s/%s", host->gameDir, lower);
  f = fopen(path, "rb");
  if (f) fclose(f);
  return f != NULL;
}

bool game_setup(const GameHost *h)
{
  host = h;
  char path[1024];
  g_dsSeg = 0;
  g_ds = NULL;
  g_sharedSeg = GAME_SHARED_SEG;
  memset(far_ptr(0, 0), 0, 0xA0000);
  memset(shared.b, 0, SHARED_SIZE);
  // the interrupt vectors the programs save and restore (DOSBox-X's BIOS)
  w16(0, 0x00, 0xCA60), w16(0, 0x02, 0xF000);  // divide error
  w16(0, 0x20, 0xFEA5), w16(0, 0x22, 0xF000);  // the timer
  w16(0, 0x24, 0xE987), w16(0, 0x26, 0xF000);  // the keyboard
  w16(0, 0x6C, 0xD1A0), w16(0, 0x6E, 0xF000);  // Ctrl-Break
  // the launcher's terminate address, DOS's Ctrl-C and critical-error handlers (DOS copies them into each
  // program's PSP and puts them back from there when it ends)
  w16(0, 0x88, 0x0258), w16(0, 0x8A, 0x189E);
  w16(0, 0x8C, 0x0128), w16(0, 0x8E, 0x072F);
  w16(0, 0x90, 0x0110), w16(0, 0x92, 0x072F);
  // the BIOS data area: text mode, the keyboard buffer empty; the launcher's words at 40:F0 (the shared block)
  *far_ptr(0x40, 0x49) = 3;
  w16(0x40, 0x1A, 0x1E), w16(0x40, 0x1C, 0x1E);
  w16(0, 0x4F0, GAME_SHARED_SEG), w16(0, 0x4F2, 1), w16(0, 0x4F4, 0);
  // the drivers, as the launcher loads them (overlays: relocated for their segment)
  ExeInfo e;
  if (!game_file("MISC.EXE", path, sizeof path) || !exe_load(path, GAME_MISC_SEG, &e)) return false;
  if (!game_file("NSOUND.SAM", path, sizeof path) || !exe_load(path, GAME_SOUND_SEG, &e)) return false;
  if (!game_file("MGRAPHIC.EXE", path, sizeof path) || !exe_load(path, GAME_GRAPHICS_SEG, &e)) return false;
  uint16_t fonts = (uint16_t)(GAME_GRAPHICS_SEG + e.imageParagraphs);
  if (!game_file("FONTS.SAM", path, sizeof path) || !raw_load(path, fonts, NULL)) return false;
  // the shared block: the setup's choices (the drivers' names, VGA, no joystick), the launcher's segments
  memcpy(shared.b + 0x00, "MGRAPHIC.EXE", 13);
  memcpy(shared.b + 0x0D, "NSOUND.SAM", 11);
  shared_set_w(0x1A, GAME_GRAPHICS_SEG);
  shared_set_w(0x1C, GAME_SOUND_SEG);
  shared_set_w(0x1E, GAME_MISC_SEG);
  shared_set_w(0x20, GAME_BUFFER_SEG);
  shared_set_w(0x22, 4);  // VGA
  shared.b[0x26] = h->noTitle;
  for (int k = 0; k < 6; k++) shared_set_w(0x3E + 2 * k, 0xFFFF);
  shared_set_w(0x38, 1);
  shared_set_w(0x7A, 1);
  shared_set_w(0x2F6, 1);
  shared_set_w(0x30A, 1);
  shared.b[0x31E] = 0xFF;
  return true;
}

// ---------------------------------------------------------------- a program started as DOS starts it

#define MEMORY_TOP 0x9FFF  // the paragraph after conventional memory's last (DOSBox-X's 640 KB)

static void mcb(uint16_t seg, char kind, uint16_t owner, uint16_t size)
{
  *far_ptr(seg, 0) = (uint8_t)kind;
  w16(seg, 1, owner);
  w16(seg, 3, size);
}

// the environment, the program segment prefix and the program at GAME_PSP_SEG + 10h; DOS's arena from there on
static bool program_load(const char *name, ExeInfo *e)
{
  char path[1024];
  if (!game_file(name, path, sizeof path)) return false;
  // the environment block (DOSBox-X's shell's, with the program's path after it)
  static const char env[] = "COMSPEC=Z:\\COMMAND.COM\0PATH=Z:\\\0PROMPT=$P$G\0\0\x01\0C:\\SAMURAI\\";
  memset(far_ptr(GAME_ENV_SEG, 0), 0, 0x480);
  memcpy(far_ptr(GAME_ENV_SEG, 0), env, sizeof env - 1);
  strcpy((char *)far_ptr(GAME_ENV_SEG, sizeof env - 1), name);
  mcb((uint16_t)(GAME_ENV_SEG - 1), 'M', GAME_PSP_SEG, 0x48);
  // the program segment prefix
  memset(far_ptr(GAME_PSP_SEG, 0), 0, 0x100);
  w16(GAME_PSP_SEG, 0x00, 0x20CD);
  w16(GAME_PSP_SEG, 0x02, MEMORY_TOP);
  w16(GAME_PSP_SEG, 0x2C, GAME_ENV_SEG);
  memcpy(far_ptr(GAME_PSP_SEG, 0x0A), far_ptr(0, 0x88), 12);  // INT 22h-24h
  static const uint8_t jft[20] = { 1, 1, 1, 0, 2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
  memcpy(far_ptr(GAME_PSP_SEG, 0x18), jft, sizeof jft);
  w16(GAME_PSP_SEG, 0x32, 20);
  w16(GAME_PSP_SEG, 0x34, 0x18), w16(GAME_PSP_SEG, 0x36, GAME_PSP_SEG);
  w16(GAME_PSP_SEG, 0x50, 0x21CD), *far_ptr(GAME_PSP_SEG, 0x52) = 0xCB;
  const char *tail = host->noTitle ? " /NT" : "";
  *far_ptr(GAME_PSP_SEG, 0x80) = (uint8_t)strlen(tail);
  memcpy(far_ptr(GAME_PSP_SEG, 0x81), tail, strlen(tail));
  *far_ptr(GAME_PSP_SEG, (uint16_t)(0x81 + strlen(tail))) = 0x0D;
  // all the memory to the program, as DOS gives it (its start-up gives the rest back)
  mcb((uint16_t)(GAME_PSP_SEG - 1), 'Z', GAME_PSP_SEG, (uint16_t)(MEMORY_TOP - GAME_PSP_SEG));
  if (!exe_load(path, (uint16_t)(GAME_PSP_SEG + 0x10), e)) return false;
  dos_arena_from_memory(0x2700, 0xA000);
  return true;
}

// the program ends: DOS frees its blocks and puts back INT 22h-24h from its PSP
static void program_end(void)
{
  dos_close_all();
  dos_free_owner(GAME_PSP_SEG);
  memcpy(far_ptr(0, 0x88), far_ptr(GAME_PSP_SEG, 0x0A), 12);
}

// ---------------------------------------------------------------- START.EXE

#define START_DS 0x2F4F

static int exitCode;
static void prog_exit(void *ctx, int code)
{
  (void)ctx;
  exitCode = code;
}

// ---------------------------------------------------------------- time

// Frames pass with the host's clock (70.086 a second, the VGA's), whenever the program looks at the time (a key
// poll, the clock, the VGA's status, a frame wait); a frame wait waits for the next. At each frame the running
// program's timer handler (INT 8, once it has hooked it) counts it.
#define FRAME_US 14268
uint64_t game_frames;
static uint64_t t0, nextFrame;
static void (*timerFrame)(void);  // the running program's frame routine

static void poll(bool wait)
{
  uint64_t t = host->now(host->ctx);
  if (wait && t < nextFrame)
  {
    host->sleepUntil(host->ctx, nextFrame);
    t = nextFrame;
  }
  while (t >= nextFrame)
  {
    if (timerFrame) timerFrame();
    game_frames++;
    host->present(host->ctx);
    nextFrame += FRAME_US;
  }
}

static void frame(void) { poll(true); }

// the date and the time: the host's at the start, and on with its clock
static void clock_now(GameClock *c, uint32_t *biosTicks)
{
  uint64_t us = host->now(host->ctx) - t0;
  uint64_t s0 = (uint64_t)host->start.hour * 3600 + host->start.minute * 60 + host->start.second;
  uint64_t cs = s0 * 100 + host->start.hundredths + us / 10000;
  uint64_t days = cs / 8640000;
  cs %= 8640000;
  *c = host->start;
  c->day += (int)days;  // (the month's end is not kept: a game does not last that long)
  c->hour = (int)(cs / 360000);
  c->minute = (int)(cs / 6000 % 60);
  c->second = (int)(cs / 100 % 60);
  c->hundredths = (int)(cs % 100);
  if (biosTicks) *biosTicks = (uint32_t)(cs * 182065 / 1000000);
}

static uint32_t start_dos(void *ctx, int ah)
{
  (void)ctx;
  poll(false);
  GameClock c;
  clock_now(&c, NULL);
  if (ah == 0x2A) return (uint32_t)c.year << 16 | (uint32_t)c.month << 8 | (uint32_t)c.day;
  if (ah == 0x2C) return (uint32_t)(c.hour << 8 | c.minute) << 16 | (uint32_t)(c.second << 8 | c.hundredths);
  if (ah == 0x0B) return key_waiting() ? 0xFF : 0;
  return 0;
}

static uint16_t start_input(void *ctx, int slot)
{
  (void)ctx;
  switch (slot)
  {
  case 90:  // a key waiting
    poll(false);
    return key_waiting() ? 0 : 0xFFFF;
  case 91:  // the next key: the program waits for it
    while (!key_waiting()) frame();
    return key_read();
  default:  // no joystick
    return 0;
  }
}

// a frame wait: the next video frame (the timer handler counts it: START's 1694:07D4, while DS:1BAF says hooked)
static void start_frame_poll(void *ctx, int site)
{
  (void)ctx;
  (void)site;
  frame();
}

static void start_timer_frame(void)
{
  if (*far_ptr(START_DS, 0x1BAF))
    for (uint16_t a = 0x1BA8; a <= 0x1BAB; a++) (*far_ptr(START_DS, a))++;
}

static uint16_t bios_ticks(void *ctx)
{
  (void)ctx;
  poll(false);
  GameClock c;
  uint32_t t;
  clock_now(&c, &t);
  return (uint16_t)t;
}

// the VGA's status (3DAh): each retrace is a frame's end, so that the waits for it take their real time
static uint16_t port_in(u16 port)
{
  static uint8_t retrace;
  if (port != 0x3DA) return 0;
  retrace = !retrace;
  if (retrace) frame();
  return retrace ? 0x09 : 0x00;
}

static int run_start(void)
{
  ExeInfo e;
  if (!program_load("START.EXE", &e)) return -1;
  static const StartHost sh = { start_dos, start_input, start_frame_poll, bios_ticks, prog_exit, NULL, NULL };
  StartHost h = sh;
  h.gameDir = host->gameDir;
  g_dsSeg = 0;
  start_attach(far_ptr(START_DS, 0), START_DS, GAME_SHARED_SEG, &h);
  exitCode = -1;
  timerFrame = start_timer_frame;
  start_entry(GAME_PSP_SEG, e.ss, e.sp);
  timerFrame = NULL;
  program_end();
  return exitCode;
}

static void clock_now(GameClock *c, uint32_t *biosTicks);


// ---------------------------------------------------------------- the keyboard hooks

// RP (and the action games) hook INT 9 with a handler that turns the direction keys into a joystick: Enter and
// Backspace are its buttons, the keypad and the arrows its directions (one held at a time; pressed twice within 5
// BIOS ticks, a full deflection). The handler's bytes in the program's data segment:
typedef struct
{
  uint16_t handlerSeg, handlerOff;  // the handler's address (the hook is on while INT 9 points at it)
  uint16_t x, y, b1, b2, held, lastTick, prefix, lastCode, skip, table;
  uint8_t center;
} KeyJoystick;
static const KeyJoystick rpKeys = { 0x2E58, 0x0DA8, 0x339A, 0x339B, 0x339C, 0x339D, 0x339E, 0x339F, 0x33A1, 0x33A2, 0x33A3, 0x33A4, 0 };
static const KeyJoystick duelKeys = { 0x2DB2, 0x0080, 0x22F2, 0x22F3, 0x22F4, 0x22F5, 0x22F6, 0x22F7, 0x22F9, 0x22FA, 0x22FB, 0x22FC, 0x80 };
static const KeyJoystick *keyHook;
static uint16_t keyDs;

static void key_byte(uint8_t al)
{
  const KeyJoystick *k = keyHook;
  uint8_t *ds = far_ptr(keyDs, 0);
  if (ds[k->skip]) { ds[k->skip]--; return; }
  bool afterPrefix = ds[k->prefix] == 0xE0;
  ds[k->prefix] = al;
  if (!afterPrefix && al == 0xE0) return;
  if (!afterPrefix && al == 0xE1) { ds[k->skip] = 2; return; }
  uint8_t ah = al;
  al &= 0x7F;
  if (al == 0x1C) { ds[k->b1] = ah & 0x80 ? 0 : 0xFF; return; }
  if (al == 0x0E) { ds[k->b2] = ah & 0x80 ? 0 : 0xFF; return; }
  if (al > 0x51 || al < 0x29) return;
  al = ds[(uint16_t)(k->table + al - 0x29)];
  if (!al) return;
  if (ah & 0x80)  // released
  {
    if (ds[k->held] == al) ds[k->held] = 0, ds[k->x] = ds[k->y] = k->center;
    return;
  }
  if (ds[k->held]) return;
  ds[k->held] = al;
  bool again = ds[k->lastCode] == al;
  ds[k->lastCode] = al;
  GameClock c;
  uint32_t ticks;
  clock_now(&c, &ticks);  // (not bios_ticks: this runs inside the host's event handling)
  uint16_t now = (uint16_t)ticks;
  uint8_t d = again && (uint16_t)(now - (ds[k->lastTick] | ds[k->lastTick + 1] << 8)) < 5 ? 0x7F : 0x5A;
  if (al & 1) ds[k->y] = (uint8_t)(k->center - d);
  if (al & 2) ds[k->y] = (uint8_t)(k->center + d);
  if (al & 4) ds[k->x] = (uint8_t)(k->center - d);
  if (al & 8) ds[k->x] = (uint8_t)(k->center + d);
  ds[k->lastTick] = (uint8_t)now, ds[k->lastTick + 1] = (uint8_t)(now >> 8);
}

void game_key(uint8_t scan, bool extended, bool pressed)
{
  if (!keyHook) return;
  uint16_t off = *(uint16_t *)far_ptr(0, 0x24), seg = *(uint16_t *)far_ptr(0, 0x26);
  if (seg != keyHook->handlerSeg || off != keyHook->handlerOff) return;  // not hooked now
  if (extended) key_byte(0xE0);
  key_byte((uint8_t)(scan | (pressed ? 0 : 0x80)));
}

// ---------------------------------------------------------------- RP.EXE

#define RP_DS 0x41E2

static jmp_buf rpExit;
static void rp_exit_(void *ctx, int code)
{
  (void)ctx;
  exitCode = code;
  longjmp(rpExit, 1);
}

static uint32_t rp_time_(void *ctx)
{
  (void)ctx;
  poll(false);
  GameClock c;
  clock_now(&c, NULL);
  // seconds since 1970 (days from the civil date)
  int y = c.year - (c.month <= 2), era = y / 400, yoe = y - era * 400, mp = (c.month + 9) % 12;
  int doy = (153 * mp + 2) / 5 + c.day - 1, doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
  long days = era * 146097L + doe - 719468;
  return (uint32_t)(days * 86400 + c.hour * 3600 + c.minute * 60 + c.second);
}

static int rp_key_waiting(void *ctx)
{
  (void)ctx;
  poll(false);
  return key_waiting();
}

static uint16_t rp_read_key(void *ctx)
{
  (void)ctx;
  while (!rp_key_waiting(NULL)) frame();
  return key_read();
}

// a frame wait (DS:3038): the next video frame (the timer handler counts it: RP's 168c:091C, while DS:303F says
// hooked)
static void rp_frame_poll(void *ctx, uint8_t flag)
{
  (void)ctx;
  (void)flag;
  frame();
}

static void rp_timer_frame(void)
{
  if (*far_ptr(RP_DS, 0x303F))
    for (uint16_t a = 0x3038; a <= 0x303B; a++) (*far_ptr(RP_DS, a))++;
}

static uint16_t rp_bios_ticks(void *ctx) { return bios_ticks(ctx); }

static void rp_subgame(void *ctx, int code);

// RP loaded and started from main (its start-up's effects in C); main does not return (exit longjmps to rpExit)
static void rp_start(void)
{
  ExeInfo e;
  if (!program_load("RP.EXE", &e))
  {
    exitCode = -1;
    longjmp(rpExit, 1);
  }
  // the C library's start-up (RP's is not reconstructed), as it leaves the data segment: the uninitialized data
  // zeroed, the heap and stack limits, the divide-error vector it saves and replaces, the PSP, DOS's version,
  // the standard handles (devices)
  uint8_t *ds = far_ptr(RP_DS, 0);
  memset(ds + 0x3A48, 0, 0x5518);
  w16(RP_DS, 0x344A, 0xFFFF), w16(RP_DS, 0x344C, 0x975E), w16(RP_DS, 0x3450, 0x975E);
  w16(RP_DS, 0x34AF, *(uint16_t *)far_ptr(0, 0)), w16(RP_DS, 0x34B1, *(uint16_t *)far_ptr(0, 2));
  w16(0, 0x00, 0x00B8), w16(0, 0x02, 0x37FA);
  w16(RP_DS, 0x34C1, GAME_PSP_SEG);
  ds[0x34C3] = 5, ds[0x34C4] = 0;
  for (int k = 0; k < 5; k++) ds[0x34CA + k] |= 0x40;
  // DOS gives the program's memory back to the start-up's size (its DGROUP's 64 KB)
  dos_resize(GAME_PSP_SEG, (uint16_t)(RP_DS + 0x1000 - GAME_PSP_SEG));
  w16(GAME_PSP_SEG, 0x02, (uint16_t)(RP_DS + 0x1000));
  // main's far return address (into the start-up) and its arguments (none) on the stack
  w16(RP_DS, 0x9754, 0x00B2), w16(RP_DS, 0x9756, 0x37FA);
  w16(RP_DS, 0x9758, 0), w16(RP_DS, 0x975A, 0), w16(RP_DS, 0x975C, 0);
  static const uint16_t regs[9] = { 0x9754, 0, 0x396A, 0x396A, GAME_ENV_SEG, 0x80D3, 0xFFFF, 0x7FE5, 0x80D3 };
  static RpHost rh = { rp_time_, rp_key_waiting, rp_read_key, rp_frame_poll, NULL, rp_bios_ticks, rp_exit_, rp_subgame, NULL, NULL, true };
  rh.gameDir = host->gameDir;
  g_dsSeg = 0;
  rp_attach(far_ptr(RP_DS, 0), RP_DS, GAME_SHARED_SEG, &rh);
  keyHook = &rpKeys;
  keyDs = RP_DS;
  timerFrame = rp_timer_frame;
  rp_main(regs);
}

// ---------------------------------------------------------------- DUEL.EXE

static int duelCode;
static void duel_exit_(void *ctx, int code)
{
  (void)ctx;
  duelCode = code;
}

static uint32_t duel_answer(void *ctx, int what)
{
  (void)ctx;
  switch (what)
  {
  case 0x2A:
  case 0x2C:
  case 0x0B:
    return start_dos(NULL, what);
  case 0x07:  // DOS's console input: the next character
  case 0x08:
  case 0x1600:  // the BIOS's: the next key
    while (!key_waiting()) frame();
    return what == 0x1600 ? key_read() : (uint32_t)(key_read() & 0xFF);
  case 0x1601:  // a key waiting: which (bit 16, ZF, if none)
    poll(false);
    return key_waiting() ? key_peek() : 0x10000;
  case 0x1100:  // the equipment: two floppy drives, a colour display
    return 0x4421;
  case 0x1A00:
  {
    GameClock c;
    uint32_t t;
    poll(false);
    clock_now(&c, &t);
    return t;
  }
  case 90:
    poll(false);
    return key_waiting() ? 0 : 0xFFFF;
  case 91:
    while (!key_waiting()) frame();
    return key_read();
  default:  // no joystick
    return 0;
  }
}

// the frame wait: the next frame (the timer's callback 1000:20AA counts it while INT 8 is DUEL's 1533:01FD)
static void duel_frame_poll(void *ctx)
{
  (void)ctx;
  frame();
}

static void duel_timer_frame(void)
{
  if (*(uint16_t *)far_ptr(0, 0x20) != 0x01FD || *(uint16_t *)far_ptr(0, 0x22) != 0x2CFF) return;
  uint16_t *ticks = (uint16_t *)far_ptr(DUEL_DS, 0x22C2), *down = (uint16_t *)far_ptr(DUEL_DS, 0x22C4);
  (*ticks)++;
  if (*down) (*down)--;
}

static int run_duel(void)
{
  ExeInfo e;
  if (!program_load("DUEL.EXE", &e)) return -1;
  static DuelHost dh = { duel_answer, duel_frame_poll, NULL, duel_exit_, NULL, NULL };
  dh.gameDir = host->gameDir;
  g_dsSeg = 0;
  duel_attach(far_ptr(DUEL_DS, 0), GAME_SHARED_SEG, &dh);
  keyHook = &duelKeys;
  keyDs = DUEL_DS;
  timerFrame = duel_timer_frame;
  duelCode = -1;
  duel_entry(GAME_PSP_SEG, e.ss, e.sp);
  keyHook = NULL;
  timerFrame = NULL;
  dos_close_all();
  program_end();
  return duelCode;
}

// ---------------------------------------------------------------- RP and its sub-games

// RP exits for a sub-game after hibernating (its data segment in the picture buffer): the launcher runs the
// sub-game, then RP again, whose main finds the hibernation and resumes (RestoreContext goes back into the
// first run's C stack: this does not return)
static void rp_subgame(void *ctx, int code)
{
  (void)ctx;
  keyHook = NULL;
  timerFrame = NULL;
  rp_close_files();
  program_end();
  int r = 1;
  if (code == 1) r = run_duel();
  else fprintf(stderr, "opensamurai: the %s is not in the reconstruction yet; it is skipped\n", code == 2 ? "battle" : "melee");
  if (r == 0)  // the player quit (Alt-Q)
  {
    exitCode = 0;
    longjmp(rpExit, 1);
  }
  rp_start();
}

static int run_rp(void)
{
  exitCode = -1;
  if (!setjmp(rpExit)) rp_start();
  keyHook = NULL;
  timerFrame = NULL;
  rp_close_files();
  program_end();
  return exitCode;
}

int game_run(const GameHost *h)
{
  if (!game_setup(h)) return -1;
  t0 = h->now(h->ctx);
  nextFrame = t0 + FRAME_US;
  asm_port_hook = port_in;
  int code = run_start();
  // the launcher: RP and its exit codes (1-3 the action games, which RP runs itself while it hibernates: see
  // rp_rt.c; 4 a new game: START again; 0 the end)
  while (code == 1 || code == 4)
  {
    if (code == 4) code = run_start();
    if (code == 1) code = run_rp();
  }
  asm_port_hook = NULL;
  return code;
}
