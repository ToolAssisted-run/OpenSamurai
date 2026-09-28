// opensamurai GAMEDIR [/NT]: the game in a window. The screen is the VGA's mode 13h (VRAM at A000, the DAC's
// palette), 70 frames a second as on the VGA; the keyboard gives the BIOS's keys.
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "asm2c.h"
#include "vga.h"
#include "game.h"

uint8_t *far_ptr(uint16_t seg, uint16_t off);

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture;
static uint16_t keys[64];
static int keyHead, keyTail;
// for scripted runs: OPENSAMURAI_KEYS="FRAME:KEY ..." (KEY hexadecimal, the BIOS's), OPENSAMURAI_SHOTS="FRAME ..."
// (FRAME.ppm written), OPENSAMURAI_FRAMES=N (the end); OPENSAMURAI_FAST=1: a virtual clock, no waiting
static long frameCount, lastFrame = -1;
static const char *scriptKeys, *scriptShots;
static bool fast;

// the BIOS's key (scan code << 8 | ASCII, as INT 16h/00 gives it) for an SDL key, 0 for none
static uint16_t bios_key(const SDL_Keysym *k)
{
  static const uint8_t letterScan[26] = { 0x1E, 0x30, 0x2E, 0x20, 0x12, 0x21, 0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32,
                                          0x31, 0x18, 0x19, 0x10, 0x13, 0x1F, 0x14, 0x16, 0x2F, 0x11, 0x2D, 0x15, 0x2C };
  bool shift = k->mod & KMOD_SHIFT, ctrl = k->mod & KMOD_CTRL, alt = k->mod & KMOD_ALT;
  SDL_Keycode c = k->sym;
  if (c >= SDLK_a && c <= SDLK_z)
  {
    uint16_t scan = letterScan[c - SDLK_a];
    if (alt) return (uint16_t)(scan << 8);
    if (ctrl) return (uint16_t)(scan << 8 | (c - SDLK_a + 1));
    bool upper = shift != ((k->mod & KMOD_CAPS) != 0);
    return (uint16_t)(scan << 8 | (upper ? c - 32 : c));
  }
  if (c >= SDLK_1 && c <= SDLK_9 && !shift) return (uint16_t)((alt ? (0x78 + c - SDLK_1) : (2 + c - SDLK_1)) << 8 | (alt ? 0 : c));
  if (c == SDLK_0 && !shift) return alt ? 0x8100 : 0x0B30;
  switch (c)
  {
  case SDLK_RETURN: case SDLK_KP_ENTER: return 0x1C0D;
  case SDLK_ESCAPE: return 0x011B;
  case SDLK_BACKSPACE: return 0x0E08;
  case SDLK_TAB: return 0x0F09;
  case SDLK_SPACE: return 0x3920;
  case SDLK_MINUS: return shift ? 0x0C5F : 0x0C2D;
  case SDLK_EQUALS: return shift ? 0x0D2B : 0x0D3D;
  case SDLK_QUOTE: return shift ? 0x2822 : 0x2827;
  case SDLK_PERIOD: return 0x342E;
  case SDLK_COMMA: return 0x332C;
  case SDLK_UP: case SDLK_KP_8: return 0x4800;
  case SDLK_DOWN: case SDLK_KP_2: return 0x5000;
  case SDLK_LEFT: case SDLK_KP_4: return 0x4B00;
  case SDLK_RIGHT: case SDLK_KP_6: return 0x4D00;
  case SDLK_HOME: case SDLK_KP_7: return 0x4700;
  case SDLK_END: case SDLK_KP_1: return 0x4F00;
  case SDLK_PAGEUP: case SDLK_KP_9: return 0x4900;
  case SDLK_PAGEDOWN: case SDLK_KP_3: return 0x5100;
  case SDLK_KP_5: return 0x4C00;
  case SDLK_INSERT: case SDLK_KP_0: return 0x5200;
  case SDLK_DELETE: case SDLK_KP_PERIOD: return 0x5300;
  case SDLK_KP_PLUS: return 0x4E2B;
  case SDLK_KP_MINUS: return 0x4A2D;
  case SDLK_KP_MULTIPLY: return 0x372A;
  default: break;
  }
  if (c >= SDLK_F1 && c <= SDLK_F10) return (uint16_t)((0x3B + c - SDLK_F1) << 8);
  return 0;
}

// the PC keyboard's scan code (set 1) for an SDL key; *extended for the grey keys (E0-prefixed)
static uint8_t pc_scan(SDL_Scancode c, bool *extended)
{
  *extended = false;
  if (c >= SDL_SCANCODE_A && c <= SDL_SCANCODE_Z)
  {
    static const uint8_t s[26] = { 0x1E, 0x30, 0x2E, 0x20, 0x12, 0x21, 0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32,
                                   0x31, 0x18, 0x19, 0x10, 0x13, 0x1F, 0x14, 0x16, 0x2F, 0x11, 0x2D, 0x15, 0x2C };
    return s[c - SDL_SCANCODE_A];
  }
  if (c >= SDL_SCANCODE_1 && c <= SDL_SCANCODE_0) return (uint8_t)(2 + c - SDL_SCANCODE_1);
  if (c >= SDL_SCANCODE_F1 && c <= SDL_SCANCODE_F10) return (uint8_t)(0x3B + c - SDL_SCANCODE_F1);
  switch (c)
  {
  case SDL_SCANCODE_ESCAPE: return 0x01;
  case SDL_SCANCODE_MINUS: return 0x0C;
  case SDL_SCANCODE_EQUALS: return 0x0D;
  case SDL_SCANCODE_BACKSPACE: return 0x0E;
  case SDL_SCANCODE_TAB: return 0x0F;
  case SDL_SCANCODE_RETURN: return 0x1C;
  case SDL_SCANCODE_KP_ENTER: *extended = true; return 0x1C;
  case SDL_SCANCODE_LCTRL: return 0x1D;
  case SDL_SCANCODE_LSHIFT: return 0x2A;
  case SDL_SCANCODE_RSHIFT: return 0x36;
  case SDL_SCANCODE_LALT: return 0x38;
  case SDL_SCANCODE_SPACE: return 0x39;
  case SDL_SCANCODE_KP_MULTIPLY: return 0x37;
  case SDL_SCANCODE_KP_7: return 0x47;
  case SDL_SCANCODE_KP_8: return 0x48;
  case SDL_SCANCODE_KP_9: return 0x49;
  case SDL_SCANCODE_KP_MINUS: return 0x4A;
  case SDL_SCANCODE_KP_4: return 0x4B;
  case SDL_SCANCODE_KP_5: return 0x4C;
  case SDL_SCANCODE_KP_6: return 0x4D;
  case SDL_SCANCODE_KP_PLUS: return 0x4E;
  case SDL_SCANCODE_KP_1: return 0x4F;
  case SDL_SCANCODE_KP_2: return 0x50;
  case SDL_SCANCODE_KP_3: return 0x51;
  case SDL_SCANCODE_HOME: *extended = true; return 0x47;
  case SDL_SCANCODE_UP: *extended = true; return 0x48;
  case SDL_SCANCODE_PAGEUP: *extended = true; return 0x49;
  case SDL_SCANCODE_LEFT: *extended = true; return 0x4B;
  case SDL_SCANCODE_RIGHT: *extended = true; return 0x4D;
  case SDL_SCANCODE_END: *extended = true; return 0x4F;
  case SDL_SCANCODE_DOWN: *extended = true; return 0x50;
  case SDL_SCANCODE_PAGEDOWN: *extended = true; return 0x51;
  default: return 0;
  }
}

static void pump(void)
{
  SDL_Event ev;
  while (SDL_PollEvent(&ev))
  {
    if (ev.type == SDL_QUIT) exit(0);
    if ((ev.type == SDL_KEYDOWN && !ev.key.repeat) || ev.type == SDL_KEYUP)
    {
      bool ext;
      uint8_t sc = pc_scan(ev.key.keysym.scancode, &ext);
      if (sc) game_key(sc, ext, ev.type == SDL_KEYDOWN);
    }
    if (ev.type == SDL_KEYDOWN)
    {
      uint16_t k = bios_key(&ev.key.keysym);
      if (k && (keyTail + 1) % 64 != keyHead)
      {
        keys[keyTail] = k;
        keyTail = (keyTail + 1) % 64;
      }
    }
  }
}

static void shot(long n)
{
  char name[64];
  snprintf(name, sizeof name, "%ld.ppm", n);
  FILE *f = fopen(name, "wb");
  if (!f) return;
  fprintf(f, "P6 320 200 255\n");
  static uint8_t planar[64000];
  const uint8_t *vram = far_ptr(0xA000, 0);
  if (vga.planar) vga_render(planar, asm_dac), vram = planar;
  for (int k = 0; k < 64000; k++)
    for (int c = 0; c < 3; c++) fputc(asm_dac[vram[k]][c] << 2 | asm_dac[vram[k]][c] >> 4, f);
  fclose(f);
}

static bool listed(const char *list, long n, unsigned *value)
{
  for (const char *p = list; p && *p;)
  {
    char *q;
    long f = strtol(p, &q, 10);
    if (q == p) break;
    unsigned v = 0;
    if (*q == ':') v = (unsigned)strtoul(q + 1, &q, 16);
    if (f == n)
    {
      if (value) *value = v;
      return true;
    }
    p = q;
    while (*p == ' ' || *p == ',') p++;
  }
  return false;
}

static void present(void *ctx)
{
  (void)ctx;
  frameCount++;
  unsigned k;
  if (listed(scriptKeys, frameCount, &k) && (keyTail + 1) % 64 != keyHead)
  {
    keys[keyTail] = (uint16_t)k;
    keyTail = (keyTail + 1) % 64;
  }
  if (listed(scriptShots, frameCount, NULL))
  {
    shot(frameCount);
    if (getenv("OPENSAMURAI_DEBUGVGA"))
    {
      unsigned long sum[4] = { 0 };
      for (int p = 0; p < 4; p++)
        for (int k = 0; k < 0x10000; k++) sum[p] += vga.plane[p][k] != 0;
      fprintf(stderr, "frame %ld: mode %02X planar %d start %02X%02X offset %02X planes %lu %lu %lu %lu attr", frameCount, vga.mode, vga.planar, vga.crtc[0xC], vga.crtc[0xD], vga.crtc[0x13], sum[0], sum[1], sum[2], sum[3]);
      for (int k = 0; k < 21; k++) fprintf(stderr, " %02X", vga.attr[k]);
      fprintf(stderr, " seq2 %02X gc5 %02X\n", vga.seq[2], vga.gc[5]);
      static uint8_t img[64000];
      vga_render(img, asm_dac);
      int count[256] = { 0 };
      for (int k = 0; k < 64000; k++) count[img[k]]++;
      for (int k = 0; k < 256; k++)
        if (count[k]) fprintf(stderr, "  index %02X: %d pixels, DAC %02X %02X %02X\n", k, count[k], asm_dac[k][0], asm_dac[k][1], asm_dac[k][2]);
    }
  }
  if (lastFrame >= 0 && frameCount >= lastFrame) exit(0);
  uint32_t *px;
  int pitch;
  if (!SDL_LockTexture(texture, NULL, (void **)&px, &pitch))
  {
    static uint8_t planar[64000];
    const uint8_t *vram = far_ptr(0xA000, 0);
    if (vga.planar)  // the EGA's planar mode (the melee): the planes through the attribute controller
    {
      vga_render(planar, asm_dac);
      vram = planar;
    }
    for (int y = 0; y < 200; y++)
      for (int x = 0; x < 320; x++)
      {
        const uint8_t *c = asm_dac[vram[y * 320 + x]];
        px[y * (pitch / 4) + x] = 0xFF000000u | (uint32_t)((c[0] << 2 | c[0] >> 4) << 16 | (c[1] << 2 | c[1] >> 4) << 8 | (c[2] << 2 | c[2] >> 4));
      }
    SDL_UnlockTexture(texture);
  }
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  pump();
}

// the clock: real time, or (fast) a virtual one that runs a little at each look and jumps at the waits
static uint64_t virtualNow;
static uint64_t now_us(void *ctx)
{
  (void)ctx;
  if (fast) return virtualNow += 20;
  return SDL_GetPerformanceCounter() * 1000000 / SDL_GetPerformanceFrequency();
}

static void sleep_until(void *ctx, uint64_t t)
{
  if (fast)
  {
    if (t > virtualNow) virtualNow = t;
    return;
  }
  uint64_t n = now_us(ctx);
  if (t > n + 1000) SDL_Delay((uint32_t)((t - n) / 1000));
  pump();
}

static int key_waiting(void *ctx)
{
  (void)ctx;
  pump();
  return keyHead != keyTail;
}

static uint16_t read_key(void *ctx)
{
  (void)ctx;
  if (keyHead == keyTail) return 0;
  uint16_t k = keys[keyHead];
  keyHead = (keyHead + 1) % 64;
  return k;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "usage: opensamurai GAMEDIR [/NT]\n  GAMEDIR: the game's files (the original floppy's)\n");
    return 2;
  }
  scriptKeys = getenv("OPENSAMURAI_KEYS");
  scriptShots = getenv("OPENSAMURAI_SHOTS");
  if (getenv("OPENSAMURAI_FRAMES")) lastFrame = atol(getenv("OPENSAMURAI_FRAMES"));
  fast = getenv("OPENSAMURAI_FAST") != NULL;
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  GameHost host = { present, now_us, sleep_until, key_waiting, read_key,
                    { tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, 0 },
                    argv[1], argc > 2 && !strcasecmp(argv[2], "/NT"), NULL };
  if (SDL_Init(SDL_INIT_VIDEO))
  {
    fprintf(stderr, "opensamurai: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow("Sword of the Samurai", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 600, SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_RenderSetLogicalSize(renderer, 320, 240);  // the VGA's 320x200 on a 4:3 screen
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 320, 200);
  int code = game_run(&host);
  if (code < 0) fprintf(stderr, "opensamurai: the game's files are not all in %s (MISC.EXE, NSOUND.SAM, MGRAPHIC.EXE, FONTS.SAM, START.EXE, ...)\n", argv[1]);
  SDL_Quit();
  return code < 0 ? 1 : 0;
}
