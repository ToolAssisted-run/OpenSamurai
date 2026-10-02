// SDLPoP's in-game menu (overlay_menu.c, by way of SDLPoP2): the pause menu (resume, the game's commands, settings,
// quit) and the settings screen (general, visuals) over the game's picture, dimmed; keyboard, mouse and game
// controllers. The settings are OpenSamurai.ini's (settings.h), edited in place, applied at once (or, for the setup's
// choices, at the next start) and saved to OpenSamurai.cfg when the menu closes (SDLPoP's SDLPoP.cfg mechanism).
//
// While the menu shows, the frontend keeps the game waiting (its clock, its sound and its keyboard stopped). The menu
// draws into ports of its own (text.h, 320 x 200), composed over the game's picture by overlay_menu_compose().
#ifndef OPENSAMURAI_OVERLAY_MENU_H
#define OPENSAMURAI_OVERLAY_MENU_H

#include <stddef.h>
#include <stdint.h>
#include <SDL.h>

#include "settings.h"

// what the frontend applies again when the menu changed a setting (overlay_menu_host.apply)
enum
{
  OVERLAY_MENU_APPLY_VIDEO = 1,       // use_correct_aspect_ratio, use_integer_scaling, scaling_type
  OVERLAY_MENU_APPLY_FULLSCREEN = 2,  // start_fullscreen: the window goes to it now (SDLPoP's)
  OVERLAY_MENU_APPLY_AUDIO = 4,       // volume
};
// what overlay_menu_frame asks of the frontend
enum
{
  OVERLAY_MENU_NONE,
  OVERLAY_MENU_QUIT,     // QUIT GAME, confirmed: the program ends
  OVERLAY_MENU_KEY,      // a key with Alt or Ctrl closed the menu: overlay_menu_key() gives it, for the game
  OVERLAY_MENU_COMMAND,  // a COMMANDS entry was chosen (the menu closed): type overlay_menu_command_key() into the game
};

typedef struct overlay_menu_host
{
  os_settings *settings;   // the frontend's settings: the menu edits them in place
  SDL_Window *window;      // NULL: headless (tests)
  SDL_Renderer *renderer;  // (the mouse's coordinates: its logical size)
  void (*apply)(int what); // OVERLAY_MENU_APPLY_* (NULL: nothing)
  // the game controller, if one is plugged in: 1, its buttons held (1 << SDL_CONTROLLER_BUTTON_*) and its left stick;
  // 0 none (NULL: none)
  int (*controller)(uint32_t *held, int *x, int *y);
  char cfg_path[1024];     // OpenSamurai.cfg: where the menu saves its settings ("": nowhere)
} overlay_menu_host;

void overlay_menu_init(const overlay_menu_host *host);
// the menu closed: every keyboard, mouse and controller event, before the game gets it. 1: the event opens the menu
// (F4, the left mouse button, the controller's Start or Back): call overlay_menu_open; 2: the event is the menu's, not
// the game's (F4 itself, a key still held from closing the menu); 0: the game's
int overlay_menu_open_event(const SDL_Event *e);
void overlay_menu_open(void);
int overlay_menu_is_open(void);
// the menu open: every SDL event (keys, mouse); 1 when it was the menu's (controller events are not: 0)
int overlay_menu_event(const SDL_Event *e);
// once per video frame while it is open: the keys, the mouse and the controller since the last frame, then the menu
// drawn. -> OVERLAY_MENU_*. The menu may have closed (overlay_menu_is_open)
int overlay_menu_frame(void);
void overlay_menu_key(SDL_Scancode *key, uint16_t *mod);  // the key of OVERLAY_MENU_KEY
int overlay_menu_command_key(void);  // the BIOS's key (scan code << 8 | ASCII) of the COMMANDS entry chosen
// a BIOS key as the COMMANDS page shows it: 0x3B00 "F1", 0x1F00 "Alt+S"
void overlay_menu_key_label(int code, char *out, size_t n);
// (tests) the page (0 the pause menu, 1 the settings, 2 the commands), the item under the cursor, the settings page
// shown ("GENERAL", ...; "" none), the setting highlighted there ("" none), the dialog showing (0 none)
void overlay_menu_state(int *page, const char **item, const char **subsection, const char **setting, int *dialog);
void overlay_menu_close(void);  // (the program ends with the menu open) closed as by RESUME: the settings saved
// the menu over the game's picture (ARGB, 320 x 200, what the frontend shows); nothing when it is closed
void overlay_menu_compose(uint32_t *argb);

// OpenSamurai.cfg: the menu's settings as OpenSamurai.ini text. Loading follows SDLPoP's SDLPoP.cfg rule: it is read
// (over the ini's settings) unless the ini is newer. 1: read
int overlay_menu_load_cfg(os_settings *s, const char *cfg_path, const char *ini_path, settings_warn_fn warn);
int overlay_menu_save_cfg(const os_settings *s, const char *cfg_path);  // 0: it could not be written

#endif
