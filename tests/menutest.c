// The frontend's in-game menu (frontend/overlay_menu.c, SDLPoP's menu) and its settings (frontend/settings.c), driven
// headlessly with synthetic keyboard, mouse and controller events, as frontend/main.c drives them:
//  1. F4, the left mouse button and the controller's Start open it; F4 is never the game's; F4 closes it from any page
//     and Esc backs out page by page; a key held when it closes stays the menu's until let go;
//  2. navigation: the pause menu (wrap-around), the settings pages, a subsection, back;
//  3. settings: a number (the volume) and toggles changed and applied through the frontend's hook; the random seed
//     typed in and reset with Delete; "Restore defaults..."; saved to OpenSamurai.cfg when the menu closes and read
//     back by SDLPoP's rule (not when the ini is newer);
//  4. COMMANDS: an entry chosen closes the menu with its key; a key with Alt closes it for the game; CHEATS: a toggle
//     and a speed changed and applied through the frontend's hook, never saved to OpenSamurai.cfg;
//  5. the quit confirmation (Cancel, then OK), the mouse (a click on an item, the right button backs out), the
//     controller (the D-pad, A, B);
//  6. OpenSamurai.ini's parser: every option, "default", bad values and unknown keys reported.
// usage: menutest TMPDIR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <utime.h>
#include <SDL.h>

#include "../frontend/overlay_menu.h"
#include "../frontend/settings.h"

static int failures;
#define CHECK(c, ...) do { if (!(c)) { failures++; printf("FAIL: " __VA_ARGS__); printf("\n"); } else if (getenv("VERBOSE")) { printf("ok: " __VA_ARGS__); printf("\n"); } } while (0)

static os_settings S;
static overlay_menu_cheats C;
static int applied, action;
static uint32_t padHeld;
static int padPlugged;
static void apply(int what) { applied |= what; }
static int pad(uint32_t *held, int *x, int *y)
{
  *held = padHeld, *x = *y = 0;
  return padPlugged;
}

static void key(SDL_Scancode sc, int down, Uint16 mod)
{
  SDL_Event e;
  memset(&e, 0, sizeof e);
  e.type = down ? SDL_KEYDOWN : SDL_KEYUP;
  e.key.state = down ? SDL_PRESSED : SDL_RELEASED;
  e.key.keysym.scancode = sc, e.key.keysym.sym = SDL_GetKeyFromScancode(sc), e.key.keysym.mod = mod;
  if (overlay_menu_is_open()) overlay_menu_event(&e);
  else if (overlay_menu_open_event(&e) == 1) overlay_menu_open();
}
static void frame(void) { action = overlay_menu_frame(); }
// a key pressed and let go, then two frames (the second with no key: the menu redraws, as between a player's keys)
static void tap_mod(SDL_Scancode sc, Uint16 mod)
{
  key(sc, 1, mod);
  key(sc, 0, mod);
  frame();
  int first = action;
  frame();
  if (first) action = first;
}
static void tap(SDL_Scancode sc) { tap_mod(sc, 0); }
static void mouse(int button, int x, int y)  // (x, y in the 320 x 200 picture: no renderer, no logical size)
{
  SDL_Event e;
  memset(&e, 0, sizeof e);
  e.type = SDL_MOUSEBUTTONDOWN, e.button.button = (Uint8)button, e.button.x = x, e.button.y = y;
  if (overlay_menu_is_open()) overlay_menu_event(&e);
  else if (overlay_menu_open_event(&e) == 1) overlay_menu_open();
  e.type = SDL_MOUSEBUTTONUP;
  if (overlay_menu_is_open()) overlay_menu_event(&e);
  frame();
}
static void state(int *page, const char **item, const char **sub, const char **setting, int *dialog)
{
  overlay_menu_state(page, item, sub, setting, dialog);
}
static const char *item_now(void)
{
  int page, dialog;
  const char *item, *sub, *setting;
  state(&page, &item, &sub, &setting, &dialog);
  return item;
}
static const char *setting_now(void)
{
  int page, dialog;
  const char *item, *sub, *setting;
  state(&page, &item, &sub, &setting, &dialog);
  return setting;
}
static int dialog_now(void)
{
  int page, dialog;
  const char *item, *sub, *setting;
  state(&page, &item, &sub, &setting, &dialog);
  return dialog;
}
// from the pause menu's RESUME to a settings page's first setting
static void to_settings_page(int page)
{
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_RETURN);  // SETTINGS
  for (int k = 0; k < page; k++) tap(SDL_SCANCODE_DOWN);
  tap(SDL_SCANCODE_RETURN);
}

static int warnings;
static void warn(const char *m) { warnings++; if (getenv("VERBOSE")) printf("  (warning: %s)\n", m); }

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "usage: menutest TMPDIR\n");
    return 2;
  }
  char cfg[1024], ini[1024];
  snprintf(cfg, sizeof cfg, "%s/menutest.cfg", argv[1]);
  snprintf(ini, sizeof ini, "%s/menutest.ini", argv[1]);
  remove(cfg);
  settings_defaults(&S);
  overlay_menu_host host = { &S, NULL, NULL, apply, pad, "", &C };
  snprintf(host.cfg_path, sizeof host.cfg_path, "%s", cfg);
  overlay_menu_init(&host);

  // 1. opening and closing
  SDL_Event e;
  memset(&e, 0, sizeof e);
  e.type = SDL_KEYDOWN, e.key.keysym.scancode = SDL_SCANCODE_F4;
  CHECK(overlay_menu_open_event(&e) == 1, "F4 opens the menu");
  e.key.repeat = 1;
  CHECK(overlay_menu_open_event(&e) == 2, "F4's repeat is the menu's, not the game's");
  e.type = SDL_KEYUP, e.key.repeat = 0;
  CHECK(overlay_menu_open_event(&e) == 2, "F4's release is not the game's");
  e.key.keysym.scancode = SDL_SCANCODE_ESCAPE;
  e.type = SDL_KEYDOWN;
  CHECK(overlay_menu_open_event(&e) == 0, "Esc is the game's");
  e.key.keysym.scancode = SDL_SCANCODE_BACKSPACE;
  CHECK(overlay_menu_open_event(&e) == 0, "Backspace is the game's");
  tap(SDL_SCANCODE_F4);
  CHECK(overlay_menu_is_open(), "open after F4");
  CHECK(!strcmp(item_now(), "RESUME"), "RESUME first (%s)", item_now());
  tap(SDL_SCANCODE_F4);
  CHECK(!overlay_menu_is_open() && action == OVERLAY_MENU_NONE, "F4 closes it");
  tap(SDL_SCANCODE_F4);
  tap(SDL_SCANCODE_ESCAPE);
  CHECK(!overlay_menu_is_open(), "Esc on the pause menu closes it");
  tap(SDL_SCANCODE_F4);
  to_settings_page(0);
  CHECK(!strcmp(setting_now(), "Sound"), "GENERAL's first setting (%s)", setting_now());
  tap(SDL_SCANCODE_F4);
  CHECK(!overlay_menu_is_open(), "F4 closes it from a settings page");
  tap(SDL_SCANCODE_F4);
  CHECK(!strcmp(item_now(), "RESUME"), "it opens on the pause menu again (%s)", item_now());
  key(SDL_SCANCODE_RETURN, 1, 0);
  frame();  // RESUME, Return still held
  CHECK(!overlay_menu_is_open(), "RESUME closes it");
  memset(&e, 0, sizeof e);
  e.type = SDL_KEYDOWN, e.key.keysym.scancode = SDL_SCANCODE_RETURN, e.key.repeat = 1;
  CHECK(overlay_menu_open_event(&e) == 2, "Return held from RESUME: its repeats are not the game's");
  key(SDL_SCANCODE_RETURN, 0, 0);
  e.key.repeat = 0;
  CHECK(overlay_menu_open_event(&e) == 0, "Return let go: the game's again");
  mouse(SDL_BUTTON_LEFT, 10, 10);
  CHECK(overlay_menu_is_open(), "the left mouse button opens it");
  mouse(SDL_BUTTON_RIGHT, 10, 10);
  CHECK(!overlay_menu_is_open(), "the right button backs out");
  memset(&e, 0, sizeof e);
  e.type = SDL_CONTROLLERBUTTONDOWN, e.cbutton.button = SDL_CONTROLLER_BUTTON_START;
  CHECK(overlay_menu_open_event(&e) == 1, "the controller's Start opens it");
  e.cbutton.button = SDL_CONTROLLER_BUTTON_A;
  CHECK(overlay_menu_open_event(&e) == 0, "the controller's A is the game's");

  // 2. navigation
  tap(SDL_SCANCODE_F4);
  tap(SDL_SCANCODE_UP);
  CHECK(!strcmp(item_now(), "QUIT GAME"), "up from RESUME wraps to QUIT GAME (%s)", item_now());
  tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(item_now(), "RESUME"), "and down back to RESUME (%s)", item_now());
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_RETURN);
  CHECK(!strcmp(item_now(), "GENERAL"), "SETTINGS: GENERAL (%s)", item_now());
  tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(item_now(), "VISUALS"), "VISUALS (%s)", item_now());
  tap(SDL_SCANCODE_RETURN);
  CHECK(!strcmp(setting_now(), "Start fullscreen"), "VISUALS' first setting (%s)", setting_now());
  tap(SDL_SCANCODE_END);
  CHECK(!strcmp(setting_now(), "Scaling method"), "End: the last (%s)", setting_now());
  tap(SDL_SCANCODE_ESCAPE);
  CHECK(!strcmp(item_now(), "VISUALS") && !setting_now()[0], "Esc: back to the left (%s)", item_now());
  tap(SDL_SCANCODE_ESCAPE);
  CHECK(!strcmp(item_now(), "SETTINGS"), "Esc: back to the pause menu, at SETTINGS (%s)", item_now());
  tap(SDL_SCANCODE_ESCAPE);
  CHECK(!overlay_menu_is_open(), "Esc: closed");

  // 3. settings
  applied = 0;
  tap(SDL_SCANCODE_F4);
  to_settings_page(0);
  tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(setting_now(), "Volume"), "Volume (%s)", setting_now());
  tap(SDL_SCANCODE_RIGHT);
  CHECK(S.volume == 15, "the volume stops at 15 (%d)", S.volume);
  tap(SDL_SCANCODE_LEFT), tap(SDL_SCANCODE_LEFT);
  CHECK(S.volume == 13 && (applied & OVERLAY_MENU_APPLY_AUDIO), "the volume 13, applied (%d, %d)", S.volume, applied);
  tap(SDL_SCANCODE_UP);
  tap(SDL_SCANCODE_RIGHT);
  CHECK(S.sound == SOUND_MT32, "the sound: the MT-32 (%d)", S.sound);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(setting_now(), "Joystick"), "Joystick (%s)", setting_now());
  tap(SDL_SCANCODE_LEFT);
  CHECK(!S.enable_joystick, "the joystick off");
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(setting_now(), "Random seed"), "Random seed (%s)", setting_now());
  tap(SDL_SCANCODE_1), tap(SDL_SCANCODE_2), tap(SDL_SCANCODE_KP_3);
  CHECK(!S.random_seed_clock && S.random_seed == 123, "the seed typed in: 123 (%d, %llu)", S.random_seed_clock, (unsigned long long)S.random_seed);
  tap(SDL_SCANCODE_ESCAPE);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_RETURN);  // VISUALS
  applied = 0;
  tap(SDL_SCANCODE_DOWN);
  tap(SDL_SCANCODE_LEFT);
  CHECK(!S.use_correct_aspect_ratio && (applied & OVERLAY_MENU_APPLY_VIDEO), "4:3 off, applied (%d)", applied);
  tap(SDL_SCANCODE_UP);
  applied = 0;
  tap(SDL_SCANCODE_RIGHT);
  CHECK(S.start_fullscreen && (applied & OVERLAY_MENU_APPLY_FULLSCREEN), "fullscreen on, applied (%d)", applied);
  tap(SDL_SCANCODE_LEFT);
  tap(SDL_SCANCODE_F4);
  struct stat st;
  CHECK(stat(cfg, &st) == 0, "OpenSamurai.cfg written when the menu closed");
  os_settings back;
  settings_defaults(&back);
  CHECK(overlay_menu_load_cfg(&back, cfg, NULL, warn) == 1, "OpenSamurai.cfg read");
  CHECK(back.volume == 13 && back.sound == SOUND_MT32 && !back.enable_joystick && !back.random_seed_clock && back.random_seed == 123
        && !back.use_correct_aspect_ratio && !back.start_fullscreen, "OpenSamurai.cfg holds the menu's settings");
  CHECK(warnings == 0, "OpenSamurai.cfg reads without a warning (%d)", warnings);
  FILE *f = fopen(ini, "w");
  fprintf(f, "[General]\nvolume = 7\n");
  fclose(f);
  struct utimbuf old = { st.st_mtime - 100, st.st_mtime - 100 }, newer = { st.st_mtime + 100, st.st_mtime + 100 };
  utime(ini, &old);
  settings_defaults(&back);
  settings_load(&back, ini, warn);
  CHECK(overlay_menu_load_cfg(&back, cfg, ini, warn) == 1 && back.volume == 13, "the cfg wins over an older ini (%d)", back.volume);
  utime(ini, &newer);
  settings_defaults(&back);
  settings_load(&back, ini, warn);
  CHECK(overlay_menu_load_cfg(&back, cfg, ini, warn) == 0 && back.volume == 7, "a newer ini wins over the cfg (%d)", back.volume);
  // the seed back to the timer; then "Restore defaults..."
  tap(SDL_SCANCODE_F4);
  to_settings_page(0);
  tap(SDL_SCANCODE_END), tap(SDL_SCANCODE_UP);
  tap(SDL_SCANCODE_DELETE);
  CHECK(S.random_seed_clock, "Delete: the seed back to the timer");
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_RETURN);
  CHECK(dialog_now() != 0, "Restore defaults...: the confirmation");
  tap(SDL_SCANCODE_RIGHT), tap(SDL_SCANCODE_RETURN);
  CHECK(dialog_now() == 0 && S.volume == 13, "Cancel: nothing restored");
  applied = 0;
  tap(SDL_SCANCODE_RETURN), tap(SDL_SCANCODE_RETURN);
  os_settings defaults;
  settings_defaults(&defaults);
  CHECK(!memcmp(&S, &defaults, sizeof S), "OK: every setting restored");
  CHECK((applied & (OVERLAY_MENU_APPLY_VIDEO | OVERLAY_MENU_APPLY_AUDIO)) == (OVERLAY_MENU_APPLY_VIDEO | OVERLAY_MENU_APPLY_AUDIO), "and applied (%d)", applied);
  tap(SDL_SCANCODE_F4);

  // 4. COMMANDS, Alt keys
  tap(SDL_SCANCODE_F4);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_RETURN);
  CHECK(!strcmp(setting_now(), "Status Scroll"), "COMMANDS: the Status Scroll first (%s)", setting_now());
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(setting_now(), "Save the game"), "Save the game (%s)", setting_now());
  tap(SDL_SCANCODE_RETURN);
  CHECK(!overlay_menu_is_open() && action == OVERLAY_MENU_COMMAND && overlay_menu_command_key() == 0x1F00, "chosen: the menu closes with Alt+S (%d, %04X)", action, overlay_menu_command_key());
  tap(SDL_SCANCODE_F4);
  tap_mod(SDL_SCANCODE_V, KMOD_LALT);
  SDL_Scancode sc;
  uint16_t mod;
  overlay_menu_key(&sc, &mod);
  CHECK(!overlay_menu_is_open() && action == OVERLAY_MENU_KEY && sc == SDL_SCANCODE_V && (mod & KMOD_ALT), "Alt+V closes the menu, for the game");
  // the CHEATS page
  applied = 0;
  remove(cfg);
  tap(SDL_SCANCODE_F4);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(item_now(), "CHEATS"), "CHEATS (%s)", item_now());
  tap(SDL_SCANCODE_RETURN);
  CHECK(!strcmp(setting_now(), "Invulnerable (melee)"), "CHEATS: Invulnerable (melee) first (%s)", setting_now());
  tap(SDL_SCANCODE_RIGHT);
  CHECK(C.invulnerableMelee == 1 && (applied & OVERLAY_MENU_APPLY_CHEATS), "Invulnerable (melee) on, applied (%d)", applied);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(setting_now(), "Faster troops (battle)"), "Faster troops (%s)", setting_now());
  tap(SDL_SCANCODE_RIGHT), tap(SDL_SCANCODE_RIGHT), tap(SDL_SCANCODE_RIGHT), tap(SDL_SCANCODE_RIGHT);
  CHECK(C.fasterTroops == 3, "Faster troops: 8x at most (%d)", C.fasterTroops);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN);
  CHECK(!strcmp(setting_now(), "No travel encounters"), "No travel encounters (%s)", setting_now());
  tap(SDL_SCANCODE_RIGHT);
  CHECK(C.noEncounters == 1, "No travel encounters on");
  tap(SDL_SCANCODE_END);
  CHECK(!strcmp(setting_now(), "Max generalship"), "Max generalship last (%s)", setting_now());
  tap(SDL_SCANCODE_RIGHT);
  CHECK(C.maxGeneralship == 1, "Max generalship on");
  tap(SDL_SCANCODE_F4);
  CHECK(stat(cfg, &st) != 0, "the cheats are not saved: no OpenSamurai.cfg");
  tap(SDL_SCANCODE_F4);
  tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_DOWN), tap(SDL_SCANCODE_RETURN);
  tap(SDL_SCANCODE_ESCAPE), tap(SDL_SCANCODE_ESCAPE);
  CHECK(!strcmp(item_now(), "CHEATS") && overlay_menu_is_open(), "Esc, Esc: back to the pause menu at CHEATS (%s)", item_now());
  tap(SDL_SCANCODE_F4);
  char label[32];
  overlay_menu_key_label(0x3D00, label, sizeof label);
  CHECK(!strcmp(label, "F3"), "0x3D00 is F3 (%s)", label);
  overlay_menu_key_label(0x2400, label, sizeof label);
  CHECK(!strcmp(label, "Alt+J"), "0x2400 is Alt+J (%s)", label);

  // 5. quit, the mouse, the controller
  tap(SDL_SCANCODE_F4);
  tap(SDL_SCANCODE_UP), tap(SDL_SCANCODE_RETURN);
  CHECK(dialog_now() != 0, "QUIT GAME: the confirmation");
  tap(SDL_SCANCODE_RIGHT), tap(SDL_SCANCODE_RETURN);
  CHECK(overlay_menu_is_open() && dialog_now() == 0 && action == OVERLAY_MENU_NONE, "Cancel: still open");
  tap(SDL_SCANCODE_RETURN), tap(SDL_SCANCODE_RETURN);
  CHECK(!overlay_menu_is_open() && action == OVERLAY_MENU_QUIT, "OK: the frontend quits (%d)", action);
  tap(SDL_SCANCODE_F4);
  mouse(SDL_BUTTON_LEFT, 160, 96);  // SETTINGS (the items from y 55, 13 apart)
  CHECK(!strcmp(item_now(), "GENERAL"), "a click on SETTINGS (%s)", item_now());
  mouse(SDL_BUTTON_RIGHT, 0, 0);
  CHECK(!strcmp(item_now(), "SETTINGS"), "the right button: back (%s)", item_now());
  tap(SDL_SCANCODE_F4);
  padPlugged = 1;
  padHeld = 1u << SDL_CONTROLLER_BUTTON_START;
  tap(SDL_SCANCODE_F4);
  frame();
  CHECK(overlay_menu_is_open(), "Start held from opening it does not close it");
  padHeld = 0, frame();
  padHeld = 1u << SDL_CONTROLLER_BUTTON_DPAD_DOWN, frame();
  padHeld = 0, frame();
  CHECK(!strcmp(item_now(), "COMMANDS"), "the D-pad (%s)", item_now());
  padHeld = 1u << SDL_CONTROLLER_BUTTON_A, frame();
  padHeld = 0, frame();
  CHECK(!strcmp(setting_now(), "Status Scroll"), "A: COMMANDS (%s)", setting_now());
  padHeld = 1u << SDL_CONTROLLER_BUTTON_B, frame();
  padHeld = 0, frame();
  padHeld = 1u << SDL_CONTROLLER_BUTTON_B, frame();
  padHeld = 0, frame();
  CHECK(!strcmp(item_now(), "COMMANDS") && overlay_menu_is_open(), "B, B: the pause menu (%s)", item_now());
  padHeld = 1u << SDL_CONTROLLER_BUTTON_START, frame();
  CHECK(!overlay_menu_is_open(), "Start closes it");
  padHeld = 0, padPlugged = 0;

  // 6. the ini's parser
  settings_defaults(&back);
  warnings = 0;
  int n = settings_parse_text(&back,
                              "; comment\n[General]\nstart_fullscreen = yes ; after a value\nwindow_width = 1280\nwindow_height = auto\n"
                              "use_correct_aspect_ratio = false\nuse_integer_scaling = on\nscaling_type = fuzzy\nsound = speaker\nvolume = 9\n"
                              "mt32_roms = /roms here\nskip_title = true\n[Controller]\nenable_joystick = 0\n[AdditionalFeatures]\n"
                              "random_seed = 18446744073709551615\n",
                              "text", warn);
  CHECK(n == 0 && back.start_fullscreen && back.window_width == 1280 && back.window_height == 0 && !back.use_correct_aspect_ratio
        && back.use_integer_scaling && back.scaling_type == SCALING_FUZZY && back.sound == SOUND_SPEAKER && back.volume == 9
        && !strcmp(back.mt32_roms, "/roms here") && back.skip_title && !back.enable_joystick && !back.random_seed_clock
        && back.random_seed == 18446744073709551615ull, "every option parsed (%d warnings)", n);
  n = settings_parse_text(&back, "[General]\nvolume = default\nsound = default\n[AdditionalFeatures]\nrandom_seed = clock\n", "text", warn);
  CHECK(n == 0 && back.volume == 15 && back.sound == SOUND_ADLIB && back.random_seed_clock, "default and clock");
  n = settings_parse_text(&back, "[General]\nvolume = 16\nsound = gus\nnothing = 1\n[Other]\nx = 1\nfloating\n", "text", warn);
  CHECK(n == 6 && back.volume == 15 && back.sound == SOUND_ADLIB, "bad values, unknown keys and sections reported (%d)", n);

  overlay_menu_close();
  remove(cfg);
  remove(ini);
  printf("%s: %d failure%s\n", failures ? "FAILED" : "passed", failures, failures == 1 ? "" : "s");
  return failures ? 1 : 0;
}
