// opensamurai GAMEDIR [/NT] [/AA|/AI|/AT|/AN]: the game in a window. The screen is the VGA's mode 13h (VRAM at A000, the DAC's
// palette), 70 frames a second as on the VGA; the keyboard gives the BIOS's keys. OpenSamurai.ini holds the settings;
// F4 (or the left mouse button, or a controller's Start) opens the in-game menu (overlay_menu.c), which changes them.
#include <SDL.h>
#include <ctype.h>
#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include "asm2c.h"
#include "vga.h"
#include "game.h"
#include "rp.h"
#include "start.h"
#include "cheats.h"
#include "overlay_menu.h"
#include "settings.h"

uint8_t *far_ptr(uint16_t seg, uint16_t off);

static SDL_Window *window;
static os_settings S;  // OpenSamurai.ini's settings (and the in-game menu's)
// the joystick: the first one plugged in (/NJ: none), its first two axes (or its hat) and buttons; for scripted runs
// OPENSAMURAI_JOY="FRAME:X,Y,BUTTONS ..." (from that frame on; X and Y -32768 to 32767, BUTTONS bit 0 and 1). A game
// controller (SDL's: one it knows the layout of) is opened as one, for the in-game menu (Start, the D-pad, A and B):
// the game reads it as a joystick all the same
static SDL_Joystick *joy;
static SDL_GameController *pad;
static bool useJoystick = true;
static bool joyHeld;  // (the menu closed with a button held: the game sees none until they are all let go)
static const char *scriptJoy;
static long frameCount;
static void joystick_open(int index)
{
  if (SDL_IsGameController(index) && (pad = SDL_GameControllerOpen(index))) joy = SDL_GameControllerGetJoystick(pad);
  else joy = SDL_JoystickOpen(index);
}
static void joystick_close(void)
{
  if (pad) SDL_GameControllerClose(pad);
  else if (joy) SDL_JoystickClose(joy);
  pad = NULL, joy = NULL;
}
static int pad_held(uint32_t *held, int *x, int *y)
{
  if (!pad) return 0;
  for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX && b < 32; b++)
    if (SDL_GameControllerGetButton(pad, (SDL_GameControllerButton)b)) *held |= 1u << b;
  *x = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTX);
  *y = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTY);
  return 1;
}
static int joystick(void *ctx, int *x, int *y)
{
  (void)ctx;
  if (scriptJoy)
  {
    int b = 0;
    *x = *y = 0;
    for (const char *p = scriptJoy; *p;)
    {
      char *q;
      long f = strtol(p, &q, 10);
      int sx, sy, sb;
      if (q == p || *q != ':' || sscanf(q + 1, "%d,%d,%d", &sx, &sy, &sb) != 3 || f > frameCount) break;
      *x = sx, *y = sy, b = sb;
      p = strchr(q, ' ');
      if (!p) break;
      while (*p == ' ') p++;
    }
    return b;
  }
  if (!joy) return -1;
  *x = SDL_JoystickGetAxis(joy, 0);
  *y = SDL_JoystickNumAxes(joy) > 1 ? SDL_JoystickGetAxis(joy, 1) : 0;
  if (SDL_JoystickNumHats(joy) > 0)
  {
    Uint8 h = SDL_JoystickGetHat(joy, 0);
    if (h & SDL_HAT_LEFT) *x = -32768;
    if (h & SDL_HAT_RIGHT) *x = 32767;
    if (h & SDL_HAT_UP) *y = -32768;
    if (h & SDL_HAT_DOWN) *y = 32767;
  }
  int b = (SDL_JoystickGetButton(joy, 0) ? 1 : 0) | (SDL_JoystickGetButton(joy, 1) ? 2 : 0);
  if (joyHeld && b) return 0;
  joyHeld = false;
  return b;
}
static SDL_Renderer *renderer;
static SDL_Texture *texture, *texture2x;
// the BIOS's keyboard buffer: 15 keys (its ring of 16 words); a key typed into a full one is lost
static uint16_t keys[64];
static int keyHead, keyTail;
static void key_push(uint16_t k)
{
  if ((keyTail - keyHead + 64) % 64 >= 15) return;
  keys[keyTail] = k;
  keyTail = (keyTail + 1) % 64;
}
// RP's, DUEL's and MELEE's keyboard handlers, while hooked, at each scan code (a key's press, its repeats, its
// release) before the BIOS's handler: a key repeated at the buffer's head kept once (game_keyboard_hooked)
static void key_collapse(void)
{
  if (keyHead == keyTail || !game_keyboard_hooked()) return;
  uint16_t k = keys[keyHead];
  for (int n = (keyHead + 1) % 64; n != keyTail && keys[n] == k; n = (n + 1) % 64) keyHead = n;
}
// for scripted runs: OPENSAMURAI_KEYS="FRAME:KEY ..." (KEY hexadecimal, the BIOS's), OPENSAMURAI_SHOTS="FRAME ..."
// (FRAME.ppm written), OPENSAMURAI_FRAMES=N (the end); OPENSAMURAI_FAST=1: a virtual clock, no waiting, the start on
// 25 October 1989 at noon;
// OPENSAMURAI_WAV=FILE: the sound written to a WAV file; OPENSAMURAI_MIDI=FILE: the MT-32's MIDI to a MIDI file;
// OPENSAMURAI_MT32ROMS=DIR: the MT-32's ROMs (else the user's data folder's roms, the program's, the game's folder);
// OPENSAMURAI_SEED=N: the seed of the game's random numbers (else the clock's, read once at the start)
static long lastFrame = -1;
static const char *scriptKeys, *scriptShots, *scriptScans;
// OPENSAMURAI_SCANS="FRAME:+SS FRAME:-SS ..." (SS the PC's scan code, hexadecimal; +e/-e for the grey keys): the
// keyboard's make and break codes, for the programs that read the keyboard themselves
static void scans(long n)
{
  for (const char *p = scriptScans; p && *p;)
  {
    char *q;
    long f = strtol(p, &q, 10);
    if (q == p || *q != ':') break;
    bool press = q[1] == '+', ext = q[2] == 'e';
    unsigned sc = (unsigned)strtoul(q + 2 + ext, &q, 16);
    if (f == n) game_key((uint8_t)sc, ext, press);
    p = q;
    while (*p == ' ') p++;
  }
}
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

// the keys the game saw pressed: their releases still reach it while the menu shows, and it gets no release of a key it
// did not see pressed (one held from the menu)
static bool gameDown[2][128];
static void game_key_event(uint8_t scan, bool extended, bool pressed)
{
  if (!pressed && !gameDown[extended][scan & 0x7F]) return;
  gameDown[extended][scan & 0x7F] = pressed;
  game_key(scan, extended, pressed);
  key_collapse();
}

// a key typed for the player (a COMMANDS entry of the menu, or a key with Alt that closed it), as the keyboard gives
// one: the make codes and the BIOS's key now, the break codes three frames later
static struct
{
  long frame;
  uint8_t scan;
  bool extended, alt;
} typed = { -1, 0, false, false };
static void typed_release(void)
{
  if (typed.frame < 0 || frameCount < typed.frame) return;
  if (typed.scan) game_key_event(typed.scan, typed.extended, false);
  if (typed.alt) game_key_event(0x38, false, false);
  typed.frame = -1;
}
static void type_key(uint16_t bios, uint8_t scan, bool extended, bool alt)
{
  if (typed.frame >= 0) typed.frame = frameCount, typed_release();  // (the one before: released first)
  if (alt) game_key_event(0x38, false, true);
  if (scan) game_key_event(scan, extended, true);
  if (bios) key_push(bios);
  typed.frame = frameCount + 3, typed.scan = scan, typed.extended = extended, typed.alt = alt;
}

// Alt+Enter: fullscreen on or off (not the game's)
static bool fullscreen_key(const SDL_Event *e)
{
  if (e->type != SDL_KEYDOWN || !(e->key.keysym.mod & KMOD_ALT) || (e->key.keysym.sym != SDLK_RETURN && e->key.keysym.sym != SDLK_KP_ENTER)) return false;
  if (!e->key.repeat && window)
  {
    bool full = !(SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(window, full ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    SDL_ShowCursor(full ? SDL_DISABLE : SDL_ENABLE);
  }
  return true;
}
static bool device_event(const SDL_Event *e)
{
  if (e->type == SDL_JOYDEVICEADDED && !joy && useJoystick) joystick_open(e->jdevice.which);
  else if (e->type == SDL_JOYDEVICEREMOVED && joy && e->jdevice.which == SDL_JoystickInstanceID(joy)) joystick_close();
  else return false;
  return true;
}

static void menu_run(void);
static void pump(void)
{
  SDL_Event ev;
  while (SDL_PollEvent(&ev))
  {
    if (ev.type == SDL_QUIT) exit(0);
    if (device_event(&ev) || fullscreen_key(&ev)) continue;
    int menu = overlay_menu_open_event(&ev);
    if (menu == 1) menu_run();
    if (menu) continue;
    if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
    {
      bool ext;
      uint8_t sc = pc_scan(ev.key.keysym.scancode, &ext);
      if (sc && !ev.key.repeat) game_key_event(sc, ext, ev.type == SDL_KEYDOWN);
      else if (sc) key_collapse();  // (a repeat: the keyboard sends the press again)
    }
    if (ev.type == SDL_KEYDOWN)
    {
      uint16_t k = bios_key(&ev.key.keysym);
      if (k) key_push(k);
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

// for scripted runs of the in-game menu: OPENSAMURAI_TAPS="PICTURE:KEY ..." (KEY an SDL key name: F4, Down, Return,
// Escape, ...; alt+KEY with Alt) taps the key as that picture is shown; OPENSAMURAI_PICTURES="PICTURE ..." writes it to
// pic-PICTURE.ppm, the menu included. The pictures are the game's frames and the menu's alike, counted from 1 (until
// the menu first opens, a picture's number is its frame's)
static const char *scriptTaps, *scriptPictures;
static long pictureCount;
static void taps(long n)
{
  for (const char *p = scriptTaps; p && *p;)
  {
    char *q, name[64];
    long f = strtol(p, &q, 10);
    if (q == p || *q != ':') break;
    size_t len = strcspn(q + 1, " ");
    snprintf(name, sizeof name, "%.*s", (int)len, q + 1);
    p = q + 1 + len;
    while (*p == ' ') p++;
    if (f != n) continue;
    bool alt = !strncasecmp(name, "alt+", 4);
    SDL_Event e = { 0 };
    e.key.keysym.scancode = SDL_GetScancodeFromName(name + (alt ? 4 : 0));
    e.key.keysym.sym = SDL_GetKeyFromScancode(e.key.keysym.scancode);
    e.key.keysym.mod = alt ? KMOD_LALT : 0;
    e.type = SDL_KEYDOWN, e.key.state = SDL_PRESSED;
    SDL_PushEvent(&e);
    e.type = SDL_KEYUP, e.key.state = SDL_RELEASED;
    SDL_PushEvent(&e);
  }
}

// the picture: VRAM through the DAC, with the in-game menu over it when it shows
static void draw_screen(void)
{
  static uint32_t argb[64000];
  static uint8_t planar[64000];
  const uint8_t *vram = far_ptr(0xA000, 0);
  if (vga.planar)  // the EGA's planar mode (the melee): the planes through the attribute controller
  {
    vga_render(planar, asm_dac);
    vram = planar;
  }
  for (int k = 0; k < 64000; k++)
  {
    const uint8_t *c = asm_dac[vram[k]];
    argb[k] = 0xFF000000u | (uint32_t)((c[0] << 2 | c[0] >> 4) << 16 | (c[1] << 2 | c[1] >> 4) << 8 | (c[2] << 2 | c[2] >> 4));
  }
  overlay_menu_compose(argb);
  pictureCount++;
  if (listed(scriptPictures, pictureCount, NULL))
  {
    char name[64];
    snprintf(name, sizeof name, "pic-%ld.ppm", pictureCount);
    FILE *f = fopen(name, "wb");
    if (f)
    {
      fprintf(f, "P6 320 200 255\n");
      for (int k = 0; k < 64000; k++) fputc((int)(argb[k] >> 16 & 0xFF), f), fputc((int)(argb[k] >> 8 & 0xFF), f), fputc((int)(argb[k] & 0xFF), f);
      fclose(f);
    }
  }
  taps(pictureCount);
  SDL_UpdateTexture(texture, NULL, argb, 320 * 4);
  SDL_RenderClear(renderer);
  if (texture2x)  // fuzzy: nearest-neighbour to twice the size, then smooth to the window
  {
    SDL_SetRenderTarget(renderer, texture2x);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture2x, NULL, NULL);
  }
  else SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

// the logical size (4:3 or square pixels), integer scaling and the scaling method's textures (at the start, and when
// the menu changes them)
static void setup_video(void)
{
  SDL_RenderSetLogicalSize(renderer, 320, S.use_correct_aspect_ratio ? 240 : 200);  // (the VGA's 320x200 on a 4:3 screen)
#if SDL_VERSION_ATLEAST(2, 0, 5)
  SDL_RenderSetIntegerScale(renderer, S.use_integer_scaling ? SDL_TRUE : SDL_FALSE);
#endif
  if (texture) SDL_DestroyTexture(texture);
  if (texture2x) SDL_DestroyTexture(texture2x);
  texture = texture2x = NULL;
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, S.scaling_type == SCALING_BLURRY ? "linear" : "nearest");
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 320, 200);
  if (S.scaling_type == SCALING_FUZZY)
  {
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    texture2x = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, 640, 400);
    if (!texture2x) fprintf(stderr, "opensamurai: no render target (%s): sharp scaling\n", SDL_GetError());
  }
}

// OPENSAMURAI_PEEK="FRAME:SEG:OFF:LEN ..." (hexadecimal but FRAME): memory at those frames, on the error output
// (scripted runs, debugging)
static const char *scriptPeek;
static void peek(long n)
{
  for (const char *p = scriptPeek; p && *p;)
  {
    char *q;
    long f = strtol(p, &q, 10);
    unsigned seg, off, len;
    if (q == p || sscanf(q, ":%x:%x:%x", &seg, &off, &len) != 3) break;
    if (f == n)
    {
      fprintf(stderr, "peek %ld %04X:%04X", n, seg, off);
      for (unsigned k = 0; k < len; k++) fprintf(stderr, " %02X", *far_ptr((uint16_t)seg, (uint16_t)(off + k)));
      fprintf(stderr, "\n");
    }
    p = strchr(q, ' ');
    if (!p) break;
    while (*p == ' ') p++;
  }
}

static void present(void *ctx)
{
  (void)ctx;
  frameCount++;
  peek(frameCount);
  typed_release();
  unsigned k;
  if (listed(scriptKeys, frameCount, &k)) key_push((uint16_t)k);
  scans(frameCount);
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
  draw_screen();
  pump();
}

// the clock: real time (without the time the in-game menu showed), or (fast) a virtual one that runs a little at each
// look and jumps at the waits
static uint64_t virtualNow, menuTime;
static uint64_t real_us(void)
{
  uint64_t c = SDL_GetPerformanceCounter(), f = SDL_GetPerformanceFrequency();
  return c / f * 1000000 + c % f * 1000000 / f;  // (c * 1000000 would overflow after hours of a nanosecond counter)
}
// the virtual clock (OPENSAMURAI_FAST): 20 us a look, the melee's tick reads what they cost on the original machine
// (GameHost.meleeTickRead: the speed test's loop 10 us, a pass of its main loop 690 us: with the pass's other looks,
// about 21 passes a tick, as in the oracle)
static uint64_t lookCost = 20;
static void melee_tick_read(void *ctx, int site)
{
  (void)ctx;
  lookCost = site == 0x072B ? 10 : 690;
}
static uint64_t now_us(void *ctx)
{
  (void)ctx;
  if (fast)
  {
    virtualNow += lookCost;
    lookCost = 20;
    return virtualNow;
  }
  return real_us() - menuTime;
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

// the sound (stereo, 44100 Hz): the game's (mono) and the MT-32's, to the audio device (at most a quarter of a
// second ahead), and to OPENSAMURAI_WAV (a WAV file of it all)
static SDL_AudioDeviceID audioDevice;
static FILE *wav;
static uint32_t wavFrames;
static void put32(uint32_t v, FILE *f) { for (int k = 0; k < 4; k++) fputc((int)(v >> 8 * k) & 0xFF, f); }
static void wav_header(uint32_t n)
{
  fseek(wav, 0, SEEK_SET);
  fwrite("RIFF", 1, 4, wav), put32(36 + 4 * n, wav), fwrite("WAVEfmt ", 1, 8, wav);
  put32(16, wav), put32(1 | 2 << 16, wav), put32(44100, wav), put32(176400, wav), put32(4 | 16 << 16, wav);
  fwrite("data", 1, 4, wav), put32(4 * n, wav);
  fseek(wav, 0, SEEK_END);
}

#ifdef HAVE_MT32EMU
// the MT-32 (Munt's libmt32emu, built in from extern/munt): its ROMs the user's (see mt32_open); the MIDI at its
// time, rendered with the game's sound
#define MT32EMU_API_TYPE 1
#include <mt32emu.h>
static mt32emu_context mt32;
// its reports: no debugging messages; the messages the game shows on its display, once each
static mt32emu_report_handler_version MT32EMU_C_CALL mt32_version(mt32emu_report_handler_i i)
{
  (void)i;
  return MT32EMU_REPORT_HANDLER_VERSION_0;
}
static void MT32EMU_C_CALL mt32_debug(void *data, const char *fmt, va_list list) { (void)data, (void)fmt, (void)list; }
static void MT32EMU_C_CALL mt32_lcd(void *data, const char *message)
{
  static char last[64];
  (void)data;
  if (!strncmp(last, message, sizeof last - 1)) return;
  snprintf(last, sizeof last, "%s", message);
  fprintf(stderr, "opensamurai: the MT-32's display: %s\n", message);
}
static const mt32emu_report_handler_i_v0 mt32Reports = { mt32_version, mt32_debug, NULL, NULL, mt32_lcd };
// the ROMs: every file of a directory tried for each machine in turn (the MT-32s of 1987-89 first, whose sound the
// game was made for; then the later MT-32s and the CM-32L); the first machine whose control and PCM ROMs are there
static bool mt32_try(const char *dir)
{
  static const char *machines[] = { "mt32_1_07", "mt32_1_06", "mt32_1_05", "mt32_1_04", "mt32_bluer", "mt32_2_07",
                                    "mt32_2_06", "mt32_2_04", "mt32_2_03", "cm32l_1_02", "cm32l_1_00", "cm32ln_1_00" };
  DIR *d = opendir(dir);
  if (!d) return false;
  char names[64][256];
  int n = 0;
  for (struct dirent *e; (e = readdir(d)) && n < 64;)
    if (e->d_name[0] != '.') snprintf(names[n++], sizeof names[0], "%s", e->d_name);
  closedir(d);
  mt32emu_report_handler_i reports = { &mt32Reports };
  for (unsigned m = 0; m < sizeof machines / sizeof *machines; m++)
  {
    mt32 = mt32emu_create_context(reports, NULL);
    bool control = false, pcm = false;
    char path[5000];
    for (int k = 0; k < n; k++)
    {
      int w = snprintf(path, sizeof path, "%s/%s", dir, names[k]);
      if (w < 0 || w >= (int)sizeof path) continue;
      mt32emu_return_code rc = mt32emu_add_machine_rom_file(mt32, machines[m], path);
      if (rc == MT32EMU_RC_ADDED_CONTROL_ROM) control = true;
      if (rc == MT32EMU_RC_ADDED_PCM_ROM) pcm = true;
    }
    mt32emu_set_stereo_output_samplerate(mt32, 44100);
    if (control && pcm && mt32emu_open_synth(mt32) == MT32EMU_RC_OK)
    {
      fprintf(stderr, "opensamurai: the MT-32 (%s) from %s\n", machines[m], dir);
      return true;
    }
    mt32emu_free_context(mt32);
    mt32 = NULL;
  }
  return false;
}

// where the ROMs are looked for: OPENSAMURAI_MT32ROMS, OpenSamurai.ini's mt32_roms, the user's data folder's roms (SDL's:
// on Linux ~/.local/share/OpenSamurai/roms), the roms folder next to the program, the game's folder
static bool mt32_open(const char *gameDir)
{
  char dirs[5][1024];
  int n = 0;
  if (getenv("OPENSAMURAI_MT32ROMS")) snprintf(dirs[n++], sizeof dirs[0], "%s", getenv("OPENSAMURAI_MT32ROMS"));
  if (S.mt32_roms[0]) snprintf(dirs[n++], sizeof dirs[0], "%s", S.mt32_roms);
  char *pref = SDL_GetPrefPath("", "OpenSamurai");
  if (pref) snprintf(dirs[n++], sizeof dirs[0], "%sroms", pref), SDL_free(pref);
  char *base = SDL_GetBasePath();
  if (base) snprintf(dirs[n++], sizeof dirs[0], "%sroms", base), SDL_free(base);
  snprintf(dirs[n++], sizeof dirs[0], "%s", gameDir);
  for (int k = 0; k < n; k++)
    if (mt32_try(dirs[k])) return true;
  fprintf(stderr, "opensamurai: no MT-32 ROMs (a control ROM and a PCM ROM, any names) in:\n");
  for (int k = 0; k < n; k++) fprintf(stderr, "  %s\n", dirs[k]);
  fprintf(stderr, "opensamurai: the AdLib's sound instead\n");
  return false;
}
#endif

static void audio(void *ctx, const int16_t *samples, int n)
{
  (void)ctx;
  static int16_t st[2 * 4096];
  if (n > 4096) n = 4096;
  for (int k = 0; k < n; k++) st[2 * k] = st[2 * k + 1] = samples[k];
#ifdef HAVE_MT32EMU
  if (mt32)
  {
    static int16_t mt[2 * 4096];
    mt32emu_render_bit16s(mt32, mt, (mt32emu_bit32u)n);
    for (int k = 0; k < 2 * n; k++)
    {
      int v = st[k] + mt[k];
      st[k] = (int16_t)(v > 32767 ? 32767 : v < -32768 ? -32768 : v);
    }
  }
#endif
  if (wav) fwrite(st, 4, (size_t)n, wav), wavFrames += (uint32_t)n;
  if (audioDevice && SDL_GetQueuedAudioSize(audioDevice) < 44100 / 4 * 4)
  {
    if (S.volume < 15)  // (the settings' volume: the device's, not the WAV file's)
      for (int k = 0; k < 2 * n; k++) st[k] = (int16_t)(st[k] * S.volume / 15);
    SDL_QueueAudio(audioDevice, st, (Uint32)n * 4);
  }
}

// the MT-32's MIDI (/AR): to OPENSAMURAI_MIDI, a standard MIDI file (one track; a tick a sample: 22050 a quarter
// note at 120 a minute), its messages split from the stream (running status, SysEx)
static FILE *midiFile;
static uint64_t midiLast;
static uint8_t msg[512], runStatus;
static int msgLen, msgWant;
static void put_var(uint32_t v, FILE *f)
{
  uint8_t b[5];
  int n = 0;
  do b[n++] = (uint8_t)(v & 0x7F), v >>= 7;
  while (v);
  while (n--) fputc(b[n] | (n ? 0x80 : 0), f);
}
static void midi_event(uint64_t sample)
{
  if (!midiFile) return;
  if (!ftell(midiFile))
  {
    fwrite("MThd\0\0\0\6\0\0\0\1\x56\x22MTrk\0\0\0\0", 1, 22, midiFile);  // (the track's length at the end)
    midiLast = sample;
  }
  put_var((uint32_t)(sample - midiLast), midiFile);
  midiLast = sample;
  if (msg[0] == 0xF0)
  {
    fputc(0xF0, midiFile);
    put_var((uint32_t)(msgLen - 1), midiFile);
    fwrite(msg + 1, 1, (size_t)(msgLen - 1), midiFile);
  }
  else fwrite(msg, 1, (size_t)msgLen, midiFile);
}
static void midi(void *ctx, uint8_t b, uint64_t sample)
{
  (void)ctx;
#ifdef HAVE_MT32EMU
  if (mt32) mt32emu_parse_stream_at(mt32, &b, 1, mt32emu_convert_output_to_synth_timestamp(mt32, (mt32emu_bit32u)sample));
#endif
  if (b >= 0xF8) return;  // (real-time messages)
  if (b & 0x80)
  {
    if (b == 0xF7 && msgLen && msg[0] == 0xF0) { msg[msgLen++] = b; midi_event(sample); msgLen = 0; return; }
    msgLen = 0;
    msg[msgLen++] = b;
    if (b < 0xF0) runStatus = b;
    msgWant = b == 0xF0 ? -1 : (b & 0xE0) == 0xC0 ? 2 : b < 0xF0 ? 3 : 1;
  }
  else
  {
    if (!msgLen) { if (!runStatus) return; msg[msgLen++] = runStatus; msgWant = (runStatus & 0xE0) == 0xC0 ? 2 : 3; }
    if (msgLen < (int)sizeof msg) msg[msgLen++] = b;
  }
  if (msgWant > 0 && msgLen == msgWant) { midi_event(sample); msgLen = 0; }
}
static void midi_file_end(void)
{
  if (ftell(midiFile)) fwrite("\0\xFF\x2F\0", 1, 4, midiFile);
  long len = ftell(midiFile) - 22;
  if (len >= 0)
  {
    fseek(midiFile, 18, SEEK_SET);
    for (int k = 3; k >= 0; k--) fputc((int)(len >> 8 * k) & 0xFF, midiFile);
  }
  fclose(midiFile);
}

// OPENSAMURAI_WATCHDOG=SECONDS (debugging): when the run takes longer, the last functions START or RP entered are
// printed, and it ends
static uint32_t lastFns[16];
static int lastFn;
static void last_fn(uint32_t addr) { lastFns[lastFn] = addr; lastFn = (lastFn + 1) % 16; }
static void __attribute__((unused)) last_rp_fn(uint32_t addr) { last_fn(addr | 0x80000000u); }
static void __attribute__((unused)) watchdog(int sig)
{
  (void)sig;
  fprintf(stderr, "watchdog: at frame %ld, the last functions entered:", frameCount);
  for (int k = 0; k < 16; k++) fprintf(stderr, " %s%04X:%04X", lastFns[(lastFn + k) % 16] >> 31 ? "rp " : "", (lastFns[(lastFn + k) % 16] >> 16) & 0x7FFF, lastFns[(lastFn + k) % 16] & 0xFFFF);
  fprintf(stderr, "\nwatchdog: SS:SP %04X:%04X, the stack:", R.ss, R.sp);
  for (int k = 0; k < 24; k++) fprintf(stderr, " %04X", *(uint16_t *)far_ptr(R.ss, (uint16_t)(R.sp + 2 * k)));
  fprintf(stderr, "\n");
  _exit(3);
}

// a message for the player: on the error output, and on Windows (where a program started with a double-click has no
// console) in a message box too
static void notify_player(const char *msg)
{
  fputs(msg, stderr);
#ifdef _WIN32
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Sword of the Samurai", msg, NULL);
#endif
}

// the in-game menu (overlay_menu.c), opened by pump(): it runs here, 70 frames a second, until it closes; the game waits
// meanwhile, inside its call of the frontend, its clock stopped (menuTime), its sound paused
static void menu_run(void)
{
  overlay_menu_open();
  uint64_t start = real_us(), next = start;
  if (audioDevice) SDL_PauseAudioDevice(audioDevice, 1);
  while (overlay_menu_is_open())
  {
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
      if (ev.type == SDL_QUIT) overlay_menu_close(), exit(0);
      if (device_event(&ev) || fullscreen_key(&ev)) continue;
      if (ev.type == SDL_KEYUP)  // (a key the game saw pressed is released to it)
      {
        bool ext;
        uint8_t sc = pc_scan(ev.key.keysym.scancode, &ext);
        if (sc) game_key_event(sc, ext, false);
      }
      overlay_menu_event(&ev);
    }
    int action = overlay_menu_frame();
    if (action == OVERLAY_MENU_QUIT) exit(0);
    if (action == OVERLAY_MENU_KEY)  // a key with Alt or Ctrl: the game's
    {
      SDL_Keysym k = { 0 };
      overlay_menu_key(&k.scancode, &k.mod);
      k.sym = SDL_GetKeyFromScancode(k.scancode);
      bool ext;
      uint8_t sc = pc_scan(k.scancode, &ext);
      type_key(bios_key(&k), sc, ext, (k.mod & KMOD_ALT) != 0);
    }
    if (action == OVERLAY_MENU_COMMAND)  // F1-F3, or Alt and a letter
    {
      uint16_t key = (uint16_t)overlay_menu_command_key();
      uint8_t sc = (uint8_t)(key >> 8);
      type_key(key, sc, false, !(sc >= 0x3B && sc <= 0x44));
    }
    draw_screen();
    next += 1000000 / 70;
    uint64_t now = real_us();
    if (next > now + 1000) SDL_Delay((uint32_t)((next - now) / 1000));
    else if (now > next + 100000) next = now;
  }
  if (audioDevice) SDL_PauseAudioDevice(audioDevice, 0);
  menuTime += real_us() - start;
  joyHeld = true;
}

// the CHEATS page's switches, and the game's (source/cheats.h): the speeds 0..3 there, 1, 2, 4, 8 here
static overlay_menu_cheats menuCheats;
static int speed_index(int k) { return k >= 8 ? 3 : k >= 4 ? 2 : k >= 2 ? 1 : 0; }
#define CHEAT_FIELDS(X) X(invulnerableMelee) X(invulnerableDuel) X(oneBlowKills) X(invulnerableTroops) X(troopsNeverRout) \
  X(noEncounters) X(stealth) X(stopAgeing) X(maxHonor) X(maxTroops) X(maxLand) X(maxSwordsmanship) X(maxGeneralship)
static void cheats_to_menu(void)
{
#define TO_MENU(f) menuCheats.f = game_cheats.f;
  CHEAT_FIELDS(TO_MENU)
  menuCheats.fasterTroops = speed_index(game_cheats.fasterTroops);
  menuCheats.walkMap = speed_index(game_cheats.walkMap);
  menuCheats.walkMelee = speed_index(game_cheats.walkMelee);
}
static void cheats_from_menu(void)
{
#define FROM_MENU(f) game_cheats.f = menuCheats.f;
  CHEAT_FIELDS(FROM_MENU)
  game_cheats.fasterTroops = 1 << menuCheats.fasterTroops;
  game_cheats.walkMap = 1 << menuCheats.walkMap;
  game_cheats.walkMelee = 1 << menuCheats.walkMelee;
}

// how the menu's settings take effect (overlay_menu_host.apply); the volume is read as the sound goes out
static void menu_apply(int what)
{
  if (what & OVERLAY_MENU_APPLY_CHEATS) cheats_from_menu();
  if (what & OVERLAY_MENU_APPLY_FULLSCREEN) SDL_SetWindowFullscreen(window, S.start_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
  if (what & OVERLAY_MENU_APPLY_VIDEO) setup_video();
}

// OpenSamurai.ini: the first of the current folder's, the one next to the program and the game folder's; the menu's
// OpenSamurai.cfg next to it, or in the game's folder without one. 1: read
static void warn_ini(const char *m) { fprintf(stderr, "opensamurai: %s\n", m); }
static int settings_files(const char *gameDir, char *ini, size_t iniSize, char *cfg, size_t cfgSize)
{
  char cands[3][1100];
  int n = 0;
  snprintf(cands[n++], sizeof cands[0], "OpenSamurai.ini");
  char *base = SDL_GetBasePath();
  if (base) snprintf(cands[n++], sizeof cands[0], "%sOpenSamurai.ini", base), SDL_free(base);
  snprintf(cands[n++], sizeof cands[0], "%s/OpenSamurai.ini", gameDir);
  ini[0] = 0;
  for (int k = 0; k < n && !ini[0]; k++)
  {
    FILE *f = fopen(cands[k], "rb");
    size_t len = strlen(cands[k]);
    if (f) fclose(f);
    if (f && len < iniSize) memcpy(ini, cands[k], len + 1);
  }
  const char *slash = strrchr(ini, '/'), *bslash = strrchr(ini, '\\');
  if (bslash && (!slash || bslash > slash)) slash = bslash;
  if (!ini[0]) snprintf(cfg, cfgSize, "%s/OpenSamurai.cfg", gameDir);
  else if (!slash) snprintf(cfg, cfgSize, "OpenSamurai.cfg");
  else snprintf(cfg, cfgSize, "%.*sOpenSamurai.cfg", (int)(slash - ini + 1), ini);
  return ini[0] && settings_load(&S, ini, warn_ini);
}

// OPENSAMURAI_CHEATS="NAME[=N] ...": cheats on from the start (scripted runs; the in-game menu's CHEATS page sets
// them otherwise): invulnerable_melee, invulnerable_duel, one_blow_kills, invulnerable_troops, never_rout,
// faster_troops=N, walk_map=N, no_encounters, walk_melee=N (N 1, 2, 4 or 8), stealth, stop_ageing, max_honor, max_troops, max_land, max_swordsmanship, max_generalship
static void script_cheats(const char *list)
{
  static const struct { const char *name; int *on; } names[] = {
    { "invulnerable_melee", &game_cheats.invulnerableMelee }, { "invulnerable_duel", &game_cheats.invulnerableDuel },
    { "one_blow_kills", &game_cheats.oneBlowKills }, { "no_encounters", &game_cheats.noEncounters },
    { "invulnerable_troops", &game_cheats.invulnerableTroops }, { "never_rout", &game_cheats.troopsNeverRout },
    { "faster_troops", &game_cheats.fasterTroops },
    { "walk_map", &game_cheats.walkMap }, { "walk_melee", &game_cheats.walkMelee }, { "stealth", &game_cheats.stealth },
    { "stop_ageing", &game_cheats.stopAgeing },
    { "max_honor", &game_cheats.maxHonor }, { "max_troops", &game_cheats.maxTroops }, { "max_land", &game_cheats.maxLand },
    { "max_swordsmanship", &game_cheats.maxSwordsmanship }, { "max_generalship", &game_cheats.maxGeneralship },
  };
  for (const char *p = list; p && *p;)
  {
    size_t n = strcspn(p, " ,"), k;
    for (k = 0; k < sizeof names / sizeof *names; k++)
    {
      size_t len = strlen(names[k].name);
      if (n >= len && !strncmp(p, names[k].name, len) && (n == len || p[len] == '='))
      {
        *names[k].on = n > len ? atoi(p + len + 1) : 1;
        break;
      }
    }
    if (k == sizeof names / sizeof *names) fprintf(stderr, "opensamurai: OPENSAMURAI_CHEATS: no cheat \"%.*s\"\n", (int)n, p);
    p += n;
    while (*p == ' ' || *p == ',') p++;
  }
}

int main(int argc, char **argv)
{
  // the game's folder: the first argument; without one (started with a double-click), the program's folder or the
  // current one, if the game is there
  static char *args[64], here[1024];
  DIR *first = argc >= 2 ? opendir(argv[1]) : NULL;  // (a folder: the game's; else an option such as /NT)
  if (first) closedir(first);
  if (argc < 2 || (!first && (argv[1][0] == '/' || argv[1][0] == '-')))
  {
    char *base = SDL_GetBasePath();
    const char *found = NULL;
    for (int k = 0; k < 2 && !found; k++)
    {
      if (k == 0 && !base) continue;
      snprintf(here, sizeof here, "%s", k == 0 ? base : ".");
      size_t n = strlen(here);
      if (n > 1 && (here[n - 1] == '/' || here[n - 1] == '\\')) here[n - 1] = 0;
      char path[1100];
      snprintf(path, sizeof path, "%s/START.EXE", here);
      FILE *f = fopen(path, "rb");
      if (!f) snprintf(path, sizeof path, "%s/start.exe", here), f = fopen(path, "rb");
      if (f) fclose(f), found = here;
    }
    if (base) SDL_free(base);
    if (!found)
    {
      notify_player("usage: opensamurai GAMEDIR [/NT] [/NJ] [/AA|/AR|/AI|/AT|/AN]\n  GAMEDIR: the game's files (the original floppy's; without it, the program's folder if the game is there)\n  /NT: no title; /NJ: no joystick; the sound: /AA the AdLib's (the default), /AR the MT-32's, /AI the IBM speaker's, /AT Tandy's, /AN none\n");
      return 2;
    }
    args[0] = argv[0];
    args[1] = (char *)found;
    for (int k = 1; k < argc && k < 62; k++) args[k + 1] = argv[k];
    argc = argc < 62 ? argc + 1 : 63;
    argv = args;
  }
  scriptKeys = getenv("OPENSAMURAI_KEYS");
  scriptShots = getenv("OPENSAMURAI_SHOTS");
  scriptScans = getenv("OPENSAMURAI_SCANS");
  scriptTaps = getenv("OPENSAMURAI_TAPS");
  scriptPeek = getenv("OPENSAMURAI_PEEK");
  script_cheats(getenv("OPENSAMURAI_CHEATS"));
  scriptPictures = getenv("OPENSAMURAI_PICTURES");
  if (getenv("OPENSAMURAI_FRAMES")) lastFrame = atol(getenv("OPENSAMURAI_FRAMES"));
  fast = getenv("OPENSAMURAI_FAST") != NULL;
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  static struct tm fixed = { .tm_year = 89, .tm_mon = 9, .tm_mday = 25, .tm_hour = 12 };
  if (getenv("OPENSAMURAI_FAST")) tm = &fixed;  // (a scripted run starts on the same day: it goes the same way)
  // the settings (OpenSamurai.ini, then the menu's OpenSamurai.cfg unless the ini is newer); a scripted run
  // (OPENSAMURAI_FAST) reads neither: it goes the same way whatever the player's settings
  settings_defaults(&S);
  char iniPath[1100] = "", cfgPath[1100] = "";
  if (!fast)
  {
    if (settings_files(argv[1], iniPath, sizeof iniPath, cfgPath, sizeof cfgPath)) fprintf(stderr, "opensamurai: settings from %s\n", iniPath);
    if (overlay_menu_load_cfg(&S, cfgPath, iniPath, warn_ini)) fprintf(stderr, "opensamurai: the in-game menu's settings from %s\n", cfgPath);
  }
  GameHost host = { present, now_us, sleep_until, key_waiting, read_key,
                    { tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, 0 },
                    argv[1], S.skip_title, NULL, settings_sound_letters[S.sound], audio, midi, joystick, 0 };
  useJoystick = S.enable_joystick;
  // the game's one source of randomness (GameHost.seed): the system's clock, read once, here; OPENSAMURAI_SEED=N
  // gives it (the same N draws the same random numbers), else the settings' random_seed; a scripted run
  // (OPENSAMURAI_FAST) has 0
  if (fast) host.meleeTickRead = melee_tick_read;
  if (getenv("OPENSAMURAI_SEED")) host.seed = strtoull(getenv("OPENSAMURAI_SEED"), NULL, 0);
  else if (!fast) host.seed = S.random_seed_clock ? (uint64_t)t : S.random_seed;
  fprintf(stderr, "opensamurai: random seed %llu (OPENSAMURAI_SEED=%llu repeats it)\n", (unsigned long long)host.seed, (unsigned long long)host.seed);
  // the setup's arguments (over the settings, for this run): /NT no title, /J the joystick (the default, when one is
  // plugged in), /NJ none, /A<letter> the sound driver (A the AdLib, the default; I the IBM speaker, T Tandy's, R the
  // MT-32's, N none)
  for (int k = 2; k < argc; k++)
    if (!strcasecmp(argv[k], "/NT")) host.noTitle = true;
    else if (!strcasecmp(argv[k], "/NJ")) useJoystick = false;
    else if (!strcasecmp(argv[k], "/J")) useJoystick = true;
    else if ((argv[k][0] == '/' || argv[k][0] == '-') && (argv[k][1] == 'A' || argv[k][1] == 'a') && argv[k][2])
      host.sound = (char)toupper((unsigned char)argv[k][2]);
  if (!strchr("ITARN", host.sound))
  {
    fprintf(stderr, "opensamurai: the reconstruction has the AdLib's sound driver (/AA), the IBM speaker's (/AI), Tandy's (/AT), the MT-32's (/AR) or none (/AN)\n");
    host.sound = 'A';
  }
  if (getenv("OPENSAMURAI_MIDI")) midiFile = fopen(getenv("OPENSAMURAI_MIDI"), "wb");
#ifdef HAVE_MT32EMU
  if (host.sound == 'R' && !mt32_open(argv[1])) host.sound = 'A';
#else
  if (host.sound == 'R') fprintf(stderr, "opensamurai: built without the MT-32 (Munt's libmt32emu): the AdLib's sound instead\n"), host.sound = 'A';
#endif
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | (host.sound != 'N' ? SDL_INIT_AUDIO : 0)))
  {
    fprintf(stderr, "opensamurai: %s\n", SDL_GetError());
    return 1;
  }
  scriptJoy = getenv("OPENSAMURAI_JOY");
#ifndef _WIN32
  if (getenv("OPENSAMURAI_WATCHDOG")) start_trace = last_fn, rp_trace = last_rp_fn, signal(SIGALRM, watchdog), alarm((unsigned)atoi(getenv("OPENSAMURAI_WATCHDOG")));
#endif
  if (useJoystick && !scriptJoy && SDL_NumJoysticks() > 0) joystick_open(0);
  if (!useJoystick) host.joystick = NULL;
  if (joy) fprintf(stderr, "opensamurai: the joystick: %s\n", SDL_JoystickName(joy));
  if (host.sound != 'N' && !fast)
  {
    SDL_AudioSpec want = { 0 }, have;
    want.freq = 44100;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = 1024;
    audioDevice = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (!audioDevice) fprintf(stderr, "opensamurai: no sound: %s\n", SDL_GetError());
    else SDL_PauseAudioDevice(audioDevice, 0);
  }
  if (getenv("OPENSAMURAI_WAV")) wav = fopen(getenv("OPENSAMURAI_WAV"), "wb"), wav_header(0);
  int width = S.window_width ? S.window_width : 960, height = S.window_height ? S.window_height : S.use_correct_aspect_ratio ? 720 : 600;
  window = SDL_CreateWindow("Sword of the Samurai", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                            SDL_WINDOW_RESIZABLE | (S.start_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0));
  if (S.start_fullscreen) SDL_ShowCursor(SDL_DISABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) renderer = SDL_CreateRenderer(window, -1, 0);
  setup_video();
  overlay_menu_host menuHost = { &S, window, renderer, menu_apply, pad_held, "", &menuCheats };
  snprintf(menuHost.cfg_path, sizeof menuHost.cfg_path, "%s", cfgPath);
  cheats_to_menu();
  overlay_menu_init(&menuHost);
  int code = game_run(&host);
  overlay_menu_close();
  if (wav) wav_header(wavFrames), fclose(wav);
  if (midiFile) midi_file_end();
  if (audioDevice) SDL_CloseAudioDevice(audioDevice);
  if (code < 0)
  {
    char msg[1400];
    snprintf(msg, sizeof msg, "opensamurai: the game's files are not all in %s (MISC.EXE, NSOUND.SAM, MGRAPHIC.EXE, FONTS.SAM, START.EXE, ...)\n", argv[1]);
    notify_player(msg);
  }
  SDL_Quit();
  return code < 0 ? 1 : 0;
}
