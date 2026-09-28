// The game as its launcher runs it (game.h). SAMURAI.COM (the original launcher, OLD.COM in the provided game
// directory) publishes a 1 KB shared block, loads MISC.EXE, runs SU.EXE (the setup), loads the graphics driver
// with FONTS.SAM after it and the sound driver, allocates a picture buffer, runs START.EXE, and then RP.EXE and
// the action games by the exit codes. Here the setup's choices are VGA, no sound and no joystick.
#include "game.h"

#include <stdio.h>
#include <string.h>

#include "asm2c.h"
#include "dosmem.h"
#include "exe.h"
#include "shared.h"
#include "start.h"

static const GameHost *host;

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

// ---------------------------------------------------------------- START.EXE

#define START_DS 0x2F4F

static int exitCode;
static void prog_exit(void *ctx, int code)
{
  (void)ctx;
  exitCode = code;
}

static uint32_t start_dos(void *ctx, int ah)
{
  (void)ctx;
  GameClock c = { 1989, 1, 1, 12, 0, 0, 0 };
  if (host->clock) host->clock(host->ctx, &c);
  if (ah == 0x2A) return (uint32_t)c.year << 16 | (uint32_t)c.month << 8 | (uint32_t)c.day;
  if (ah == 0x2C) return (uint32_t)(c.hour << 8 | c.minute) << 16 | (uint32_t)(c.second << 8 | c.hundredths);
  if (ah == 0x0B) return host->keyWaiting && host->keyWaiting(host->ctx) ? 0xFF : 0;
  return 0;
}

static void frame(void)
{
  if (host->frame) host->frame(host->ctx);
}

static uint16_t start_input(void *ctx, int slot)
{
  (void)ctx;
  switch (slot)
  {
  case 90:  // a key waiting
    return host->keyWaiting && host->keyWaiting(host->ctx) ? 0 : 0xFFFF;
  case 91:  // the next key: the program waits for it
    while (!(host->keyWaiting && host->keyWaiting(host->ctx))) frame();
    return host->readKey(host->ctx);
  default:  // no joystick
    return 0;
  }
}

// a frame wait: one video frame passes, and the timer interrupt's frame routine (1694:07D4) counts it
static void start_frame_poll(void *ctx, int site)
{
  (void)ctx;
  (void)site;
  frame();
  for (uint16_t a = 0x1BA8; a <= 0x1BAB; a++) (*far_ptr(START_DS, a))++;
}

static uint16_t bios_ticks(void *ctx)
{
  (void)ctx;
  return (uint16_t)(host->biosTicks ? host->biosTicks(host->ctx) : 0);
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
  start_entry(GAME_PSP_SEG, e.ss, e.sp);
  dos_free_owner(GAME_PSP_SEG);  // DOS frees the program's blocks
  return exitCode;
}

int game_run(const GameHost *h)
{
  if (!game_setup(h)) return -1;
  asm_port_hook = port_in;
  int code = run_start();
  asm_port_hook = NULL;
  return code;
}
