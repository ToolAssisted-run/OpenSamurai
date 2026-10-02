/*
SDLPoP, a port/conversion of the DOS game Prince of Persia.
Copyright (C) 2013-2025  Dávid Nagy

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

The authors of this program may be contacted at https://forum.princed.org
*/

/* OpenSamurai: SDLPoP's in-game menu (SDLPoP is Dávid Nagy's, NagyD's; its pause menu was written by Falcury, one of
 * SDLPoP's contributors), src/menu.c at commit 3c5add5fb7f8
 * (https://github.com/NagyD/SDLPoP/blob/3c5add5fb7f8/src/menu.c), as SDLPoP2 transcribed it (its sdl/overlay_menu.c: one
 * pass of draw_menu's loop a video frame, the dialogs as states, the overlay a port of colour indices blended over the
 * game), adapted for OpenSamurai. The design, the layout, the colours, the fonts, the navigation (keyboard, mouse,
 * controller), the pages and the code's structure and names are SDLPoP's. The adaptations (marked "OpenSamurai:"):
 *  - Opening: F4, which the game never reads (Sword of the Samurai's Esc and Backspace are SDLPoP's keys: "back" and the
 *    second selector), the left mouse button (the game has no mouse), as SDLPoP's, or the controller's Start / Back;
 *    F4 closes it again from any page. While the menu shows the frontend keeps the game waiting: its clock stopped, its
 *    sound paused, its keyboard left alone (the keys the game saw pressed are still released to it).
 *  - Fonts: SDLPoP's two hardcoded fonts: the small menu font (hc_small_font, menu.c's) and the big one (hc_font,
 *    seg009.c's hc_font_data, PoP1's), drawn by text.c (SDLPoP2's port library). "GAME PAUSED" is SDLPoP's
 *    display_text_bottom, at its place on the bottom line, in a layer under the overlay.
 *  - Pause menu: RESUME, COMMANDS, SETTINGS, QUIT GAME. SDLPoP's quicksave, quickload and restarts have no counterpart
 *    (the game saves its own games: Alt+S at the Home Option scroll). COMMANDS is a page laid out as the settings
 *    (SDLPoP2's CHEATS page): the original game's command keys (the `commands` table), each with its key, as SDLPoP's
 *    CONTROLS page shows keys; choosing one closes the menu and types its key into the game. Keys with Alt or Ctrl (the
 *    game's commands) close the menu and go to the game, as SDLPoP's Ctrl+ keys. QUIT GAME's confirmation ends the
 *    program.
 *  - Cheats: SDLPoP's CHEATS pause item (commented out there), as SDLPoP2 made it: a page laid out as the settings
 *    (CHEATS / BACK, the list on the right, the help line), here of switches and speeds (the host's
 *    overlay_menu_cheats, which the frontend gives the game: source/cheats.h). They are not saved, as SDLPoP's
 *    cheats_enabled is not; greyed out without the host's switches.
 *  - Settings: OpenSamurai.ini's (settings.h) on SDLPoP's pages: GENERAL (the sound driver, the volume, the joystick,
 *    the title, the random seed, "Restore defaults..."), VISUALS (fullscreen, 4:3, integer scaling, the scaling
 *    method). The original setup's choices (the sound driver, the joystick, the title) and the random seed are the
 *    game's from its start, so a change takes effect at the next start (their help lines say so); the others at once. There
 *    is no setting that skips or changes the game's copy protection.
 *  - SDLPoP.cfg is OpenSamurai.cfg, the menu's settings as OpenSamurai.ini text, with SDLPoP's rule: read after the ini
 *    unless the ini is newer.
 *  - Sounds: SDLPoP plays PoP1 sounds on navigation (play_menu_sound); the game's sound is paused while the menu shows,
 *    so play_menu_sound makes none. */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "overlay_menu.h"
#include "text.h"

/* ---- SDLPoP's types and facilities, on the port library ---- */
typedef uint8_t byte;
typedef int8_t sbyte;
typedef uint16_t word;
typedef uint32_t dword;
typedef qrect rect_type;   /* (the same order: top, left, bottom, right) */
typedef int bool_type;
#define COUNT(array) (int)(sizeof(array) / sizeof(array[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
enum { halign_left = -1, halign_center = 0, halign_right = 1 };
enum { valign_top = -1, valign_middle = 0, valign_bottom = 1 };
enum { color_0_black = 0, color_7_lightgray = 7, color_8_darkgray = 8, color_15_brightwhite = 15 };
enum { blitters_0_no_transp = 0 };
enum key_modifiers { WITH_SHIFT = 0x8000, WITH_CTRL = 0x4000, WITH_ALT = 0x2000 };
static const rect_type screen_rect = {0, 0, 200, 320};
static const rect_type rect_bottom_text = {193, 70, 202, 250};

static overlay_menu_host host;
static os_settings *S;            /* host.settings */

/* the overlay's colours: SDLPoP's palette (VGA_PALETTE_DEFAULT, 6-bit << 2), then colours with alpha as they are used */
typedef struct rgba_type { byte r, g, b, a; } rgba_type;
static rgba_type overlay_colors[256];
static int overlay_color_count;
static const byte vga_palette_default[16][3] = {
	{0x00, 0x00, 0x00}, {0x00, 0x00, 0x2A}, {0x00, 0x2A, 0x00}, {0x00, 0x2A, 0x2A},
	{0x2A, 0x00, 0x00}, {0x2A, 0x00, 0x2A}, {0x2A, 0x15, 0x00}, {0x2A, 0x2A, 0x2A},
	{0x15, 0x15, 0x15}, {0x15, 0x15, 0x3F}, {0x15, 0x3F, 0x15}, {0x15, 0x3F, 0x3F},
	{0x3F, 0x15, 0x15}, {0x3F, 0x15, 0x3F}, {0x3F, 0x3F, 0x15}, {0x3F, 0x3F, 0x3F},
};
static int map_rgba(int r, int g, int b, int a)   /* (SDL_MapRGBA) */
{
	if (a == 0) r = g = b = 0;
	for (int i = 0; i < overlay_color_count; i++) {
		rgba_type* c = &overlay_colors[i];
		if (c->r == r && c->g == g && c->b == b && c->a == a) return i;
	}
	if (overlay_color_count >= 256) return 0;
	overlay_colors[overlay_color_count] = (rgba_type) {(byte) r, (byte) g, (byte) b, (byte) a};
	return overlay_color_count++;
}

/* the surfaces: SDLPoP's overlay_surface, and (under it) the screen's bottom text line */
static gport* overlay_surface;
static gport* bottom_text_surface;
static gport* current_target_surface;

/* the fonts: textstate.ptr_font (ids no other font has) */
enum { hc_font = 0xF5F4, hc_small_font = 0xF5F5 };
static struct { word ptr_font; } textstate = { hc_font };
extern byte hc_font_data[];
extern byte hc_small_font_data[];
extern byte arrowhead_up_image_data[];
extern byte arrowhead_down_image_data[];
extern byte arrowhead_left_image_data[];
extern byte arrowhead_right_image_data[];
typedef byte image_type;   /* IMAGE_DATA: height, width, flags (words), then 1-bit rows */
static image_type* arrowhead_up_image;
static image_type* arrowhead_down_image;
static image_type* arrowhead_left_image;
static image_type* arrowhead_right_image;

static int image_word(const byte* p) { return p[0] | p[1] << 8; }
static int calc_stride(const byte* image_data) {
	int width = image_word(image_data + 2);
	int flags = image_word(image_data + 4);
	int depth = ((flags >> 12) & 7) + 1;
	return (depth * width + 7) / 8;
}
/* seg009.c: load_font_character_offsets (the hardcoded font's offsets are filled in at run time) */
static void load_font_character_offsets(byte* data) {
	int n_chars = data[1] - data[0] + 1;
	byte* pos = data + 10 + n_chars * 2;
	for (int index = 0; index < n_chars; ++index) {
		int offset = (int)(pos - data);
		data[10 + index * 2] = (byte) offset;
		data[10 + index * 2 + 1] = (byte) (offset >> 8);
		int image_bytes = image_word(pos) * calc_stride(pos);
		pos += 6 + image_bytes;
	}
}

static void with_target(void) { the_port = current_target_surface; }
static void without_target(gport* saved) { the_port = saved; }

// seg009:37E8
static void draw_rect(const rect_type* rect, int color) {
	gport* saved = the_port; with_target();
	gfx_fill_rect(color, rect);
	without_target(saved);
}
static const rect_type* method_5_rect(const rect_type* rect, int blit, byte color) {
	(void) blit;
	draw_rect(rect, color);
	return rect;
}
static void draw_rect_with_alpha(const rect_type* rect, byte color, byte alpha) {
	const byte* c = vga_palette_default[color];
	draw_rect(rect, map_rgba(c[0] << 2, c[1] << 2, c[2] << 2, alpha));
}
static void draw_rect_contours(const rect_type* rect, byte color) {
	gport* saved = the_port; with_target();
	int saved_fg = the_port->fg; the_port->fg = color;
	gfx_frame_rect(rect);
	the_port->fg = (int16_t) saved_fg;
	without_target(saved);
}
// seg009:39CE
static rect_type* shrink2_rect(rect_type* target_rect, const rect_type* source_rect, int delta_x, int delta_y) {
	target_rect->top    = (int16_t) (source_rect->top    + delta_y);
	target_rect->left   = (int16_t) (source_rect->left   + delta_x);
	target_rect->bottom = (int16_t) (source_rect->bottom - delta_y);
	target_rect->right  = (int16_t) (source_rect->right  - delta_x);
	return target_rect;
}
// seg009:04FF (show_text: draw_text, clipped to the rectangle, with the port library's justification, the same rules
// as SDLPoP's draw_text)
static void show_text_with_color(const rect_type* rect_ptr, int x_align, int y_align, const char* text, int color) {
	gport* saved = the_port; with_target();
	char buffer[512];
	snprintf(buffer, sizeof(buffer), "%s", text);
	for (char* p = buffer; *p; ++p) if (*p == '\n') *p = '\r';   /* (the library's line break) */
	qrect saved_clip = the_port->clip;
	qrect clip = *rect_ptr;
	if (clip.top < saved_clip.top) clip.top = saved_clip.top;
	if (clip.left < saved_clip.left) clip.left = saved_clip.left;
	if (clip.bottom > saved_clip.bottom) clip.bottom = saved_clip.bottom;
	if (clip.right > saved_clip.right) clip.right = saved_clip.right;
	the_port->clip = clip;
	int saved_fg = the_port->fg; word saved_font = the_port->font;
	the_port->fg = (int16_t) color;
	gfx_text_font(textstate.ptr_font);
	gfx_text_box_str(buffer, y_align, x_align, rect_ptr);
	the_port->fg = (int16_t) saved_fg; the_port->font = saved_font; the_port->clip = saved_clip;
	without_target(saved);
}
// seg009:403F
static int get_line_width(const char* text, int length) {
	gport* saved = the_port; with_target();
	word saved_font = the_port->font;
	gfx_text_font(textstate.ptr_font);
	int width = gfx_text_width(text, length);
	the_port->font = saved_font;
	without_target(saved);
	return width;
}
static void draw_image_with_blending(image_type* image, int xpos, int ypos) {
	int height = image_word(image), width = image_word(image + 2), stride = calc_stride(image);
	gport* saved = the_port; with_target();
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (!(image[6 + y * stride + (x >> 3)] & (0x80 >> (x & 7)))) continue;   /* (color key 0) */
			rect_type pixel = {(int16_t) (ypos + y), (int16_t) (xpos + x), (int16_t) (ypos + y + 1), (int16_t) (xpos + x + 1)};
			gfx_fill_rect(color_15_brightwhite, &pixel);   /* (the images' colour 1 is white) */
		}
	}
	without_target(saved);
}
// seg008:2644
static void display_text_bottom(const char* text) {
	gport* saved_target = current_target_surface;
	current_target_surface = bottom_text_surface;
	draw_rect(&screen_rect, map_rgba(0, 0, 0, 0));
	draw_rect(&rect_bottom_text, color_0_black);
	word saved_font = textstate.ptr_font;
	textstate.ptr_font = hc_font;
	show_text_with_color(&rect_bottom_text, halign_center, valign_bottom, text, color_15_brightwhite);
	textstate.ptr_font = saved_font;
	current_target_surface = saved_target;
}

/* the dialog (seg009: copyprot_dialog, made from dialog_settings and dialog_rect_1) */
typedef struct dialog_settings_type {
	short top_border, left_border, bottom_border, right_border, shadow_bottom, shadow_right, outer_border;
} dialog_settings_type;
typedef struct dialog_type {
	const dialog_settings_type* settings;
	rect_type text_rect;
	rect_type peel_rect;
} dialog_type;
static const dialog_settings_type dialog_settings = {4, 4, 4, 4, 3, 4, 1};
static dialog_type copyprot_dialog_ = { &dialog_settings, {60, 56, 124, 264}, {0, 0, 0, 0} };
static dialog_type* copyprot_dialog = &copyprot_dialog_;
// seg009:0BE7
static void calc_dialog_peel_rect(dialog_type* dialog) {
	const dialog_settings_type* settings = dialog->settings;
	dialog->peel_rect.left = (int16_t) (dialog->text_rect.left - settings->left_border);
	dialog->peel_rect.top = (int16_t) (dialog->text_rect.top - settings->top_border);
	dialog->peel_rect.right = (int16_t) (dialog->text_rect.right + settings->right_border + settings->shadow_right);
	dialog->peel_rect.bottom = (int16_t) (dialog->text_rect.bottom + settings->bottom_border + settings->shadow_bottom);
}
// seg009:09F0
static void dialog_method_2_frame(dialog_type* dialog) {
	rect_type rect;
	short shadow_right = dialog->settings->shadow_right;
	short shadow_bottom = dialog->settings->shadow_bottom;
	short bottom_border = dialog->settings->bottom_border;
	short outer_border = dialog->settings->outer_border;
	short peel_top = dialog->peel_rect.top;
	short peel_left = dialog->peel_rect.left;
	short peel_bottom = dialog->peel_rect.bottom;
	short peel_right = dialog->peel_rect.right;
	short text_top = dialog->text_rect.top;
	short text_left = dialog->text_rect.left;
	short text_bottom = dialog->text_rect.bottom;
	short text_right = dialog->text_rect.right;
	// Draw outer border
	rect = (rect_type) { peel_top, peel_left, (int16_t) (peel_bottom - shadow_bottom), (int16_t) (peel_right - shadow_right) };
	draw_rect(&rect, color_0_black);
	// Draw shadow (right)
	rect = (rect_type) { text_top, (int16_t) (peel_right - shadow_right), peel_bottom, peel_right };
	draw_rect(&rect, color_8_darkgray /*dialog's shadow*/);
	// Draw shadow (bottom)
	rect = (rect_type) { (int16_t) (peel_bottom - shadow_bottom), text_left, peel_bottom, peel_right };
	draw_rect(&rect, color_8_darkgray /*dialog's shadow*/);
	// Draw inner border (left)
	rect = (rect_type) { (int16_t) (peel_top + outer_border), (int16_t) (peel_left + outer_border), text_bottom, text_left };
	draw_rect(&rect, color_15_brightwhite);
	// Draw inner border (top)
	rect = (rect_type) { (int16_t) (peel_top + outer_border), text_left, text_top, (int16_t) (text_right + dialog->settings->right_border - outer_border) };
	draw_rect(&rect, color_15_brightwhite);
	// Draw inner border (right)
	rect.top = text_top;
	rect.left =  text_right;
	rect.bottom = (int16_t) (text_bottom + bottom_border - outer_border);           // (rect.right stays the same)
	draw_rect(&rect, color_15_brightwhite);
	// Draw inner border (bottom)
	rect = (rect_type) { text_bottom, (int16_t) (peel_left + outer_border), (int16_t) (text_bottom + bottom_border - outer_border), text_right };
	draw_rect(&rect, color_15_brightwhite);
}

// types.h: names lists
#define MAX_OPTION_VALUE_NAME_LENGTH 20
typedef struct key_value_type {
	char key[MAX_OPTION_VALUE_NAME_LENGTH];
	int value;
} key_value_type;
typedef struct names_list_type {
	byte type; // 0 = names list, 1 = key/value pair list
	union {
		struct {
			const char (* data)[][MAX_OPTION_VALUE_NAME_LENGTH];
			word count;
		} names;
		struct {
			const key_value_type* data;
			word count;
		} kv_pairs;
	};
} names_list_type;
#define NAMES_LIST(listname, ...) static const char listname[][MAX_OPTION_VALUE_NAME_LENGTH] = __VA_ARGS__; \
static names_list_type listname##_list = {.type=0, .names = {&listname, COUNT(listname)}}
#define KEY_VALUE_LIST(listname, ...) static const key_value_type listname[] = __VA_ARGS__; \
static names_list_type listname##_list = {.type=1, .kv_pairs= {listname, COUNT(listname)}}

/* SDLPoP's input state (data.h) */
static bool_type have_mouse_input;
static bool_type have_keyboard_or_controller_input;
static int mouse_x, mouse_y;
static bool_type mouse_moved;
static bool_type mouse_clicked;
static bool_type mouse_button_clicked_right;
static bool_type pressed_enter;
static int menu_control_scroll_y;
static sbyte is_menu_shown;
static bool_type is_joyst_mode;
static int last_key_scancode;       /* the key of this pass (read_key) */

/* the events between two video frames, queued for draw_menu's passes (SDLPoP's process_events fills last_key_scancode
 * as the events come) */
#define KEY_QUEUE_SIZE 32
static int key_queue[KEY_QUEUE_SIZE];
static int key_queue_count;
static int pending_mouse_x, pending_mouse_y, pending_mouse_clicked, pending_mouse_clicked_right, pending_scroll_y;
static byte key_held[SDL_NUM_SCANCODES];
static byte key_suppressed[SDL_NUM_SCANCODES];   // OpenSamurai: held when the menu closed (escape_key_suppressed, for every key)
static int menu_action, menu_action_key; static word menu_action_mod;
static dword frame_counter;              /* video frames while the menu shows (the controller's repeat) */
static bool_type joystick_read_this_frame;
static int command_key_chosen;           /* OpenSamurai: the COMMANDS page's key for the game (OVERLAY_MENU_COMMAND) */

static void play_menu_sound(int sound_id) {
	/* OpenSamurai: SDLPoP plays PoP1's sounds here (play_sound + play_next_sound); the game's sound is paused while the
	   menu shows, so there is no sound. */
	(void) sound_id;
}
enum { sound_10_sword_vs_sword = 10, sound_21_loose_shake_2 = 21, sound_22_loose_shake_3 = 22 };

static void load_arrowhead_images(void) {
	// (the images are drawn from their data: draw_image_with_blending)
	if (arrowhead_up_image == NULL) {
		arrowhead_up_image = arrowhead_up_image_data;
	}
	if (arrowhead_down_image == NULL) {
		arrowhead_down_image = arrowhead_down_image_data;
	}
	if (arrowhead_left_image == NULL) {
		arrowhead_left_image = arrowhead_left_image_data;
	}
	if (arrowhead_right_image == NULL) {
		arrowhead_right_image = arrowhead_right_image_data;
	}
}

#define MAX_MENU_ITEM_LENGTH 32

typedef struct pause_menu_item_type pause_menu_item_type;
struct pause_menu_item_type {
	int id;
	pause_menu_item_type* previous;
	pause_menu_item_type* next;
	const int* required;
	char text[MAX_MENU_ITEM_LENGTH];
};

enum pause_menu_item_ids {
	PAUSE_MENU_RESUME,
	PAUSE_MENU_COMMANDS, // OpenSamurai: the game's commands (SDLPoP2's CHEATS page)
	PAUSE_MENU_CHEATS, // OpenSamurai: the cheats (SDLPoP's CHEATS, commented out there)
	PAUSE_MENU_SETTINGS,
	PAUSE_MENU_QUIT_GAME,
	SETTINGS_MENU_GENERAL,
	SETTINGS_MENU_VISUALS,
	SETTINGS_MENU_BACK,
	SETTINGS_MENU_COMMANDS, // OpenSamurai: the COMMANDS page's list
	COMMANDS_MENU_BACK, // OpenSamurai
	SETTINGS_MENU_CHEATS, // OpenSamurai: the CHEATS page's list
	CHEATS_MENU_BACK, // OpenSamurai
};

static int cheats_available;   // (the host gives the switches)
static pause_menu_item_type pause_menu_items[] = {
		{.id = PAUSE_MENU_RESUME,        .text = "RESUME"},
		// OpenSamurai: SDLPoP's CHEATS item (commented out there) made, as in SDLPoP2, for the game's commands; SDLPoP's
		// QUICKSAVE, QUICKLOAD, RESTART LEVEL and RESTART GAME have no counterpart
		{.id = PAUSE_MENU_COMMANDS,      .text = "COMMANDS"},
		{.id = PAUSE_MENU_CHEATS,        .text = "CHEATS", .required = &cheats_available},
		{.id = PAUSE_MENU_SETTINGS,      .text = "SETTINGS"},
		{.id = PAUSE_MENU_QUIT_GAME,     .text = "QUIT GAME"},
};

static int hovering_pause_menu_item = PAUSE_MENU_RESUME;
static pause_menu_item_type* next_pause_menu_item;
static pause_menu_item_type* previous_pause_menu_item;
static int drawn_menu;
static byte pause_menu_alpha;
static int current_dialog_box;
static const char* current_dialog_text;
static bool_type need_close_menu;

enum menu_dialog_ids {
	DIALOG_NONE,
	DIALOG_RESTORE_DEFAULT_SETTINGS,
	DIALOG_CONFIRM_QUIT,
};

static pause_menu_item_type settings_menu_items[] = {
		{.id = SETTINGS_MENU_GENERAL, .text = "GENERAL"},
		{.id = SETTINGS_MENU_VISUALS, .text = "VISUALS"},
		{.id = SETTINGS_MENU_BACK, .text = "BACK"},
};
// OpenSamurai: the COMMANDS page, laid out as the settings page (its left part), as SDLPoP2's CHEATS page
static pause_menu_item_type commands_menu_items[] = {
		{.id = SETTINGS_MENU_COMMANDS, .text = "COMMANDS"},
		{.id = COMMANDS_MENU_BACK, .text = "BACK"},
};
// OpenSamurai: the CHEATS page, laid out the same way
static pause_menu_item_type cheats_menu_items[] = {
		{.id = SETTINGS_MENU_CHEATS, .text = "CHEATS"},
		{.id = CHEATS_MENU_BACK, .text = "BACK"},
};
static int active_settings_subsection = 0;
static int highlighted_settings_subsection = 0;
static int scroll_position = 0;
static int menu_control_y;
static int menu_control_x;
static int menu_digit = -1, menu_clear;   // (SDLPoP2's) a digit typed (0..9, else -1), Delete pressed (the random seed field)
static int menu_control_back;

enum menu_setting_style_ids {
	SETTING_STYLE_TOGGLE,
	SETTING_STYLE_NUMBER,
	SETTING_STYLE_TEXT_ONLY,
	SETTING_STYLE_COMMAND, // OpenSamurai: an entry of the COMMANDS page (its key shown as SDLPoP's CONTROLS page's keys)
};

enum menu_setting_number_type_ids {
	SETTING_BYTE  = 0,
	SETTING_SBYTE = 1,
	SETTING_WORD  = 2,
	SETTING_SHORT = 3,
	//SETTING_DWORD = 4,
	SETTING_INT   = 5,
};

enum setting_ids {
	SETTING_RESET_ALL_SETTINGS,
	SETTING_SOUND, // OpenSamurai: the setup's sound driver
	SETTING_VOLUME,
	SETTING_ENABLE_JOYSTICK, // OpenSamurai: the setup's joystick
	SETTING_SKIP_TITLE,
	SETTING_RANDOM_SEED,
	SETTING_FULLSCREEN,
	SETTING_USE_CORRECT_ASPECT_RATIO,
	SETTING_USE_INTEGER_SCALING,
	SETTING_SCALING_TYPE,
	SETTING_CHEAT_INVULNERABLE_MELEE, // OpenSamurai: the CHEATS page
	SETTING_CHEAT_INVULNERABLE_DUEL,
	SETTING_CHEAT_ONE_BLOW_KILLS,
	SETTING_CHEAT_INVULNERABLE_TROOPS,
	SETTING_CHEAT_NEVER_ROUT,
	SETTING_CHEAT_FASTER_TROOPS,
	SETTING_CHEAT_WALK_MAP,
	SETTING_CHEAT_NO_ENCOUNTERS,
	SETTING_CHEAT_WALK_MELEE,
	SETTING_CHEAT_STOP_AGEING,
	SETTING_CHEAT_MAX_HONOR,
	SETTING_CHEAT_MAX_TROOPS,
	SETTING_CHEAT_MAX_LAND,
	SETTING_CHEAT_MAX_SWORDSMANSHIP,
	SETTING_CHEAT_MAX_GENERALSHIP,
	SETTING_COMMAND_FIRST, // OpenSamurai: the COMMANDS page's entries (SETTING_COMMAND_FIRST + their index in `commands`)
};

typedef struct setting_type {
	int index;
	int id;
	int previous, next;
	byte style;
	byte number_type;
	void* linked;
	const int* required;
	int min, max; // for 'number'-style settings
	char text[64];
	char explanation[400];
	names_list_type* names_list;
	// OpenSamurai (SDLPoP2's): where the setting is in os_settings (offset + 1; 0: none), its place in OpenSamurai.ini
	// ("Section/key") and the ini's names of its values (names-list settings)
	size_t link;
	const char* ini;
	const char* const* ini_values;
	size_t cheat; // OpenSamurai: where the switch is in overlay_menu_cheats (offset + 1; 0: none)
} setting_type;
#define LINK(field) .link = offsetof(os_settings, field) + 1

static const char* const bool_ini_values[] = {"false", "true"};
static const char* const scaling_ini_values[] = {"sharp", "fuzzy", "blurry"};
static const char* const sound_ini_values[] = {"adlib", "mt32", "speaker", "tandy", "none"};
NAMES_LIST(sound_setting_names, {"AdLib", "Roland MT-32", "PC speaker", "Tandy", "None",});
KEY_VALUE_LIST(random_seed_setting_names, {{"Timer (default)", -1}});

static setting_type general_settings[] = {
		{.id = SETTING_SOUND, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT, .max = SOUND_COUNT - 1,
				LINK(sound), .names_list = &sound_setting_names_list,
				.ini = "General/sound", .ini_values = sound_ini_values,
				.text = "Sound",
				.explanation = "The sound card, as the original setup's /A options choose it.\n"
						"Roland MT-32 needs its ROMs (README); without them, the AdLib.\n"
						"Takes effect at the next start."},
		{.id = SETTING_VOLUME, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT,
				LINK(volume), .min = 0, .max = 15, .ini = "General/volume",
				.text = "Volume",
				.explanation = "The volume, from 0 (silent) to 15 (full).\n"
						"The game's Alt+V still switches the music and effects."},
		{.id = SETTING_ENABLE_JOYSTICK, .style = SETTING_STYLE_TOGGLE, LINK(enable_joystick), .ini = "Controller/enable_joystick",
				.text = "Joystick",
				.explanation = "A joystick or game controller plugged in is the game's\n"
						"joystick (/J, /NJ). Takes effect at the next start."},
		{.id = SETTING_SKIP_TITLE, .style = SETTING_STYLE_TOGGLE, LINK(skip_title), .ini = "General/skip_title",
				.text = "Skip the title",
				.explanation = "Start without the title sequence (/NT).\nTakes effect at the next start."},
		// (SDLPoP2's) the seed: the clock (shown as -1) or a number
		{.id = SETTING_RANDOM_SEED, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT,
				LINK(random_seed), .min = -1, .max = 99999, .names_list = &random_seed_setting_names_list,
				.ini = "AdditionalFeatures/random_seed",
				.text = "Random seed",
				.explanation = "Timer (default): a different game each time. A number: the\n"
						"same random numbers every time. Type it in; Delete: Timer.\n"
						"Takes effect at the next start."},
		{.id = SETTING_RESET_ALL_SETTINGS, .style = SETTING_STYLE_TEXT_ONLY,
				.text = "Restore defaults...", .explanation = "Revert all settings to the default state."},
};

NAMES_LIST(scaling_type_setting_names, {"Sharp", "Fuzzy", "Blurry",});

static int integer_scaling_possible =
#if SDL_VERSION_ATLEAST(2,0,5) // SDL_RenderSetIntegerScale
	1
#else
	0
#endif
;

static setting_type visuals_settings[] = {
		{.id = SETTING_FULLSCREEN, .style = SETTING_STYLE_TOGGLE, LINK(start_fullscreen), .ini = "General/start_fullscreen",
				.text = "Start fullscreen",
				.explanation = "Start the game in fullscreen mode.\nYou can also toggle fullscreen by pressing Alt+Enter."},
		{.id = SETTING_USE_CORRECT_ASPECT_RATIO, .style = SETTING_STYLE_TOGGLE, LINK(use_correct_aspect_ratio), .ini = "General/use_correct_aspect_ratio",
				.text = "Use 4:3 aspect ratio",
				.explanation = "Render the game in the originally intended 4:3 aspect ratio."
				               "\nNB. Works best using a high resolution."},
		{.id = SETTING_USE_INTEGER_SCALING, .style = SETTING_STYLE_TOGGLE, LINK(use_integer_scaling), .ini = "General/use_integer_scaling",
				.required = &integer_scaling_possible,
				.text = "Use integer scaling",
				.explanation = "Enable pixel perfect scaling. That is, make all pixels the same size by forcing integer scale factors.\n"
						"Combining with 4:3 aspect ratio requires at least 1600x1200."
						"\nYou need to compile with SDL 2.0.5 or newer to enable this."},
		{.id = SETTING_SCALING_TYPE, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT, .max = 2,
				LINK(scaling_type), .names_list = &scaling_type_setting_names_list,
				.ini = "General/scaling_type", .ini_values = scaling_ini_values,
				.text = "Scaling method",
				.explanation = "Sharp - Use nearest neighbour resampling.\n"
						"Fuzzy - First upscale to double size, then use smooth scaling.\n"
						"Blurry - Use smooth scaling."},
};

// OpenSamurai: the CHEATS page: the host's switches (overlay_menu_cheats, `cheat` = the field), each a toggle or a
// speed (0..3: 1x, 2x, 4x, 8x)
#define CHEAT(field) .cheat = offsetof(overlay_menu_cheats, field) + 1
NAMES_LIST(speed_setting_names, {"1x", "2x", "4x", "8x",});
static setting_type cheats_settings[] = {
		{.id = SETTING_CHEAT_INVULNERABLE_MELEE, .style = SETTING_STYLE_TOGGLE, CHEAT(invulnerableMelee), .required = &cheats_available,
				.text = "Invulnerable (melee)",
				.explanation = "Blows and arrows never wound you in melees (the game's\n"
						"own debug switch). You still stagger when hit."},
		{.id = SETTING_CHEAT_INVULNERABLE_DUEL, .style = SETTING_STYLE_TOGGLE, CHEAT(invulnerableDuel), .required = &cheats_available,
				.text = "Invulnerable (duel)",
				.explanation = "Your opponent's blows never wound you or knock you back."},
		{.id = SETTING_CHEAT_ONE_BLOW_KILLS, .style = SETTING_STYLE_TOGGLE, CHEAT(oneBlowKills), .required = &cheats_available,
				.text = "One-blow kills (duel, melee)",
				.explanation = "Your first blow that lands fells your opponent in duels,\n"
						"and anyone you strike in melees."},
		{.id = SETTING_CHEAT_INVULNERABLE_TROOPS, .style = SETTING_STYLE_TOGGLE, CHEAT(invulnerableTroops), .required = &cheats_available,
				.text = "Invulnerable troops (battle)",
				.explanation = "Your units lose no men to the enemy's attacks in battles."},
		{.id = SETTING_CHEAT_NEVER_ROUT, .style = SETTING_STYLE_TOGGLE, CHEAT(troopsNeverRout), .required = &cheats_available,
				.text = "Troops never rout (battle)",
				.explanation = "Your units never break and flee on their own in battles.\n"
						"R still orders the retreat."},
		{.id = SETTING_CHEAT_FASTER_TROOPS, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT, .max = 3,
				CHEAT(fasterTroops), .names_list = &speed_setting_names_list, .required = &cheats_available,
				.text = "Faster troops (battle)",
				.explanation = "Your units march and turn faster; the enemy's do not."},
		{.id = SETTING_CHEAT_WALK_MAP, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT, .max = 3,
				CHEAT(walkMap), .names_list = &speed_setting_names_list, .required = &cheats_available,
				.text = "Faster walk (map)",
				.explanation = "Walk faster on the province maps.\n"
						"A shorter trip also brings fewer encounters."},
		{.id = SETTING_CHEAT_NO_ENCOUNTERS, .style = SETTING_STYLE_TOGGLE, CHEAT(noEncounters), .required = &cheats_available,
				.text = "No travel encounters",
				.explanation = "Nobody stops you on the province maps:\n"
						"no bandits, ronin, pirates or duellists."},
		{.id = SETTING_CHEAT_WALK_MELEE, .style = SETTING_STYLE_NUMBER, .number_type = SETTING_INT, .max = 3,
				CHEAT(walkMelee), .names_list = &speed_setting_names_list, .required = &cheats_available,
				.text = "Faster walk (melee)",
				.explanation = "You walk faster in melees (the others do not)."},
		{.id = SETTING_CHEAT_STOP_AGEING, .style = SETTING_STYLE_TOGGLE, CHEAT(stopAgeing), .required = &cheats_available,
				.text = "Stop ageing",
				.explanation = "You and your family stop ageing.\n"
						"Your rivals, the lords and their families age as usual."},
		{.id = SETTING_CHEAT_MAX_HONOR, .style = SETTING_STYLE_TOGGLE, CHEAT(maxHonor), .required = &cheats_available,
				.text = "Max honor",
				.explanation = "Your honor held at 128, the most the game allows\n"
						"(112, plus 16 from a wife, an heir and two more children)."},
		{.id = SETTING_CHEAT_MAX_TROOPS, .style = SETTING_STYLE_TOGGLE, CHEAT(maxTroops), .required = &cheats_available,
				.text = "Max troops",
				.explanation = "Your troops held at 128, the most the game allows."},
		{.id = SETTING_CHEAT_MAX_LAND, .style = SETTING_STYLE_TOGGLE, CHEAT(maxLand), .required = &cheats_available,
				.text = "Max land",
				.explanation = "Your land held at 128, the most the game allows."},
		{.id = SETTING_CHEAT_MAX_SWORDSMANSHIP, .style = SETTING_STYLE_TOGGLE, CHEAT(maxSwordsmanship), .required = &cheats_available,
				.text = "Max swordsmanship",
				.explanation = "Your swordsmanship held at 128, the most the game allows."},
		{.id = SETTING_CHEAT_MAX_GENERALSHIP, .style = SETTING_STYLE_TOGGLE, CHEAT(maxGeneralship), .required = &cheats_available,
				.text = "Max generalship",
				.explanation = "Your generalship held at 128, the most the game allows."},
};

// OpenSamurai: the COMMANDS page: the original game's command keys (README's keys), one line each: the BIOS's key
// (overlay_menu_key_label shows it), the line on the page, the help line. Chosen, the key is typed into the game.
typedef struct command_type {
	word key;
	const char* text;
	const char* explanation;
} command_type;
static const command_type commands[] = {
		{0x3B00, "Status Scroll", "The Status Scroll: you and your rivals."},
		{0x3C00, "Strategic Map", "The Strategic Map."},
		{0x3D00, "Summary Scroll", "The Summary Scroll."},
		{0x1F00, "Save the game", "Save the game (at the Home Option scroll), in the game's folder."},
		{0x1300, "Restore a game", "Restore a saved game (at the Home Option scroll)."},
		{0x3100, "New game", "Start a new game."},
		{0x2F00, "Music and effects", "Music and effects, effects only, or silence."},
		{0x2C00, "Full graphics", "Full graphics on or off."},
		{0x2400, "Calibrate the joystick", "Calibrate the joystick again."},
		{0x1000, "Quit", "The game's own quit."},
};
static setting_type commands_settings[COUNT(commands)];   // (from `commands`: init_commands_settings)

typedef struct settings_area_type {
	setting_type* settings;
	int setting_count;
} settings_area_type;

static settings_area_type general_settings_area = { .settings = general_settings, .setting_count = COUNT(general_settings)};
static settings_area_type visuals_settings_area = { .settings = visuals_settings, .setting_count = COUNT(visuals_settings)};
static settings_area_type commands_settings_area = { .settings = commands_settings, .setting_count = COUNT(commands_settings)}; // OpenSamurai
static settings_area_type cheats_settings_area = { .settings = cheats_settings, .setting_count = COUNT(cheats_settings)}; // OpenSamurai

static settings_area_type* get_settings_area(int menu_item_id) {
	switch(menu_item_id) {
		default:
			return NULL;
		case SETTINGS_MENU_GENERAL:
			return &general_settings_area;
		case SETTINGS_MENU_VISUALS:
			return &visuals_settings_area;
		case SETTINGS_MENU_COMMANDS: // OpenSamurai
			return &commands_settings_area;
		case SETTINGS_MENU_CHEATS: // OpenSamurai
			return &cheats_settings_area;
	}
}
static settings_area_type* const all_settings_areas[] = {   // (saving, restoring the defaults)
	&general_settings_area, &visuals_settings_area,
};

static void init_pause_menu_items(pause_menu_item_type* first_item, int item_count) {
	if (item_count > 0) {
		for (int i = 0; i < item_count; ++i) {
			pause_menu_item_type* item = first_item + i;
			item->previous = (first_item + MAX(0, i-1));
			item->next = (first_item + MIN(item_count-1, i+1));
		}
		pause_menu_item_type* last_item = first_item + (item_count-1);
		first_item->previous = last_item;
		last_item->next = first_item;
	}
}

static void init_settings_list(setting_type* first_setting, int setting_count) {
	if (setting_count > 0) {
		for (int i = 0; i < setting_count; ++i) {
			setting_type* item = first_setting + i;
			item->index = i;
			item->previous = (first_setting + MAX(0, i-1))->id;
			item->next = (first_setting + MIN(setting_count-1, i+1))->id;
			if (item->link) item->linked = (char*) S + (item->link - 1);   // (the frontend's settings)
			if (item->cheat && host.cheats) item->linked = (char*) host.cheats + (item->cheat - 1);   // (its cheats)
		}
	}
}

// OpenSamurai: the COMMANDS page's entries, from the `commands` table
static void init_commands_settings(void) {
	for (int i = 0; i < COUNT(commands); ++i) {
		setting_type* setting = &commands_settings[i];
		setting->id = SETTING_COMMAND_FIRST + i;
		setting->style = SETTING_STYLE_COMMAND;
		setting->linked = (void*) &commands[i];
		snprintf(setting->text, sizeof(setting->text), "%s", commands[i].text);
		snprintf(setting->explanation, sizeof(setting->explanation), "%s", commands[i].explanation);
	}
}

void overlay_menu_key_label(int code, char* out, size_t n) {
	static const char scan_letters[] =   // PC scan codes 0x10..0x32: the letters (Alt+letter is scan << 8)
		"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0QWERTYUIOP\0\0\0\0ASDFGHJKL\0\0\0\0\0ZXCVBNM";
	if (n == 0) return;
	if (code > 0 && code < 0x100) {
		if (code >= 'a' && code <= 'z') snprintf(out, n, "%c", code - 'a' + 'A');
		else if (code >= 'A' && code <= 'Z') snprintf(out, n, "Shift+%c", code);
		else snprintf(out, n, "%c", code);
		return;
	}
	int scan = code >> 8;
	if (scan >= 0x3B && scan <= 0x44) snprintf(out, n, "F%d", scan - 0x3B + 1);
	else if (scan >= 0x10 && scan < (int) sizeof(scan_letters) - 1 && scan_letters[scan]) snprintf(out, n, "Alt+%c", scan_letters[scan]);
	else snprintf(out, n, "0x%04X", code);
}

static void clear_menu_controls(void);
static void process_additional_menu_input(void);
static int key_test_paused_menu(int key);

static void init_menu(void) {
	load_arrowhead_images();

	init_pause_menu_items(pause_menu_items, COUNT(pause_menu_items));
	init_pause_menu_items(settings_menu_items, COUNT(settings_menu_items));
	init_pause_menu_items(commands_menu_items, COUNT(commands_menu_items)); // OpenSamurai
	init_pause_menu_items(cheats_menu_items, COUNT(cheats_menu_items)); // OpenSamurai

	init_settings_list(general_settings, COUNT(general_settings));
	init_settings_list(visuals_settings, COUNT(visuals_settings));
	init_commands_settings(); // OpenSamurai
	init_settings_list(commands_settings, COUNT(commands_settings));
	init_settings_list(cheats_settings, COUNT(cheats_settings)); // OpenSamurai
}

static bool_type is_mouse_over_rect(const rect_type* rect) {
	return (mouse_x >= rect->left && mouse_x < rect->right && mouse_y >= rect->top && mouse_y < rect->bottom);
}

// Maps the cursor position into a coordinate between (0,0) and (320,200) and sets mouse_x, mouse_y and mouse_moved.
// (From the mouse events: SDL gives them in the renderer's logical size, 320 x 240 with the 4:3 aspect ratio.)
static void read_mouse_state(void) {
	int last_mouse_x = mouse_x;
	int last_mouse_y = mouse_y;
	mouse_x = pending_mouse_x;
	mouse_y = pending_mouse_y;
	mouse_moved = (last_mouse_x != mouse_x || last_mouse_y != mouse_y);
}
static void mouse_position_from_event(int x, int y) {
	int logical_width = 0, logical_height = 0;
	if (host.renderer) SDL_RenderGetLogicalSize(host.renderer, &logical_width, &logical_height);
	if (logical_width <= 0 || logical_height <= 0) { logical_width = SCREEN_W; logical_height = SCREEN_H; }
	pending_mouse_x = x * SCREEN_W / logical_width;
	pending_mouse_y = y * SCREEN_H / logical_height;
}

static rect_type explanation_rect = {170, 20, 200, 300};
static int highlighted_setting_id = SETTING_SOUND;
static int controlled_area = 0; // Whether the focus is on the left (0) or right (1) part of the screen in the Settings menu.
static int next_setting_id = 0; // For navigating up/down.
static int previous_setting_id = 0;
static bool_type at_scroll_up_boundary; // When navigating up using keyboard/controller, whether we also need to scroll up
static bool_type at_scroll_down_boundary; // When navigating down using keyboard/controller, whether we also need to scroll down

static void enter_settings_subsection(int settings_menu_id) {
	settings_area_type* settings_area = get_settings_area(settings_menu_id);
	if (active_settings_subsection != settings_menu_id) {
		highlighted_setting_id = settings_area->settings[0].id;
	}
	active_settings_subsection = settings_menu_id;
	highlighted_settings_subsection = settings_menu_id;
	if (!mouse_clicked) hovering_pause_menu_item = 0;
	controlled_area = 1;
	scroll_position = 0;
}

static void leave_settings_subsection(void) {
	// Go back to the top level of the settings menu.
	controlled_area = 0;
	hovering_pause_menu_item = active_settings_subsection;
	active_settings_subsection = 0;
	highlighted_settings_subsection = 0;
}

static void reset_paused_menu(void) {
	drawn_menu = 0;
	controlled_area = 0;
	hovering_pause_menu_item = PAUSE_MENU_RESUME;
}

static void pause_menu_clicked(pause_menu_item_type* item) {
	//printf("Clicked option %s\n", item->text);
	play_menu_sound(sound_22_loose_shake_3);
	switch(item->id) {
		default: break;
		case PAUSE_MENU_RESUME:
			need_close_menu = 1;
			break;
		case PAUSE_MENU_COMMANDS:
			// OpenSamurai: the COMMANDS page (drawn as the settings page), the list in focus at the entry chosen last
			drawn_menu = 2;
			hovering_pause_menu_item = SETTINGS_MENU_COMMANDS;
			enter_settings_subsection(SETTINGS_MENU_COMMANDS);
			scroll_position = MAX(0, highlighted_setting_id - SETTING_COMMAND_FIRST - 8);
			break;
		case PAUSE_MENU_CHEATS:
			// OpenSamurai: the CHEATS page (drawn as the settings page), the list in focus
			drawn_menu = 3;
			hovering_pause_menu_item = SETTINGS_MENU_CHEATS;
			enter_settings_subsection(SETTINGS_MENU_CHEATS);
			break;
		case PAUSE_MENU_SETTINGS:
			drawn_menu = 1;
			hovering_pause_menu_item = SETTINGS_MENU_GENERAL;
			highlighted_settings_subsection = SETTINGS_MENU_GENERAL;
			active_settings_subsection = 0;
			controlled_area = 0;
			break;
		case PAUSE_MENU_QUIT_GAME:
			current_dialog_box = DIALOG_CONFIRM_QUIT;
			current_dialog_text = "Quit OpenSamurai?";
			break;
		case SETTINGS_MENU_GENERAL:
		case SETTINGS_MENU_VISUALS:
		case SETTINGS_MENU_COMMANDS: // OpenSamurai
		case SETTINGS_MENU_CHEATS: // OpenSamurai
			enter_settings_subsection(item->id);
			break;
		case CHEATS_MENU_BACK: // OpenSamurai
			reset_paused_menu();
			active_settings_subsection = highlighted_settings_subsection = 0;
			hovering_pause_menu_item = PAUSE_MENU_CHEATS;
			break;
		case COMMANDS_MENU_BACK: // OpenSamurai
			reset_paused_menu();
			active_settings_subsection = highlighted_settings_subsection = 0;
			hovering_pause_menu_item = PAUSE_MENU_COMMANDS;
			break;
		case SETTINGS_MENU_BACK:
			reset_paused_menu();
			hovering_pause_menu_item = PAUSE_MENU_SETTINGS;
			break;
	}
	clear_menu_controls(); // prevent "click-through" because the screen changes
}

static void draw_pause_menu_item(pause_menu_item_type* item, rect_type* parent, int* y_offset, int inactive_text_color) {
	rect_type text_rect = *parent;
	text_rect.top += *y_offset;
	int text_color = inactive_text_color;

	// (SDLPoP2's) an unavailable item stays in its place, greyed out and inert; navigation skips it as in SDLPoP
	if (item->required != NULL && *item->required == 0) {
		if (hovering_pause_menu_item == item->id) hovering_pause_menu_item = PAUSE_MENU_RESUME;
		show_text_with_color(&text_rect, halign_center, valign_top, item->text, color_7_lightgray);   /* (as SDLPoP's disabled settings) */
		*y_offset += 13;
		return;
	}

	rect_type selection_box = text_rect;
	selection_box.bottom = selection_box.top + 8;
	selection_box.top -= 3;

	bool_type highlighted = (hovering_pause_menu_item == item->id);
	if (have_mouse_input && is_mouse_over_rect(&selection_box)) {
		hovering_pause_menu_item = item->id;
		highlighted = 1;
	}

	if (highlighted) {
		previous_pause_menu_item = item->previous;
		next_pause_menu_item = item->next;
		// Skip over disabled items
		if (previous_pause_menu_item->required != NULL) {
			while (*previous_pause_menu_item->required == 0) {
				previous_pause_menu_item = previous_pause_menu_item->previous;
				if (previous_pause_menu_item->required == NULL) break;
			}
		}
		if (next_pause_menu_item->required != NULL) {
			while (*next_pause_menu_item->required == 0) {
				next_pause_menu_item = next_pause_menu_item->next;
				if (next_pause_menu_item->required == NULL) break;
			}
		}
		text_color = color_15_brightwhite;
		draw_rect_contours(&selection_box, color_7_lightgray);

		if (mouse_clicked) {
			if (is_mouse_over_rect(&selection_box)) {
				pause_menu_clicked(item);
			}
		} else if (pressed_enter && (drawn_menu == 0 || (drawn_menu >= 1 && controlled_area == 0))) { // (2: the COMMANDS page, 3 the CHEATS page)
			pause_menu_clicked(item);
		}

	}
	show_text_with_color(&text_rect, halign_center, valign_top, item->text, text_color);
	*y_offset += 13;

}

static void draw_pause_menu(void) {
	pause_menu_alpha = 120;
	draw_rect_with_alpha(&screen_rect, color_0_black, pause_menu_alpha);
	draw_rect_with_alpha(&rect_bottom_text, color_0_black, 0); // Transparent so that the text "GAME PAUSED" is visible.
	rect_type pause_rect_outer = {0, 110, 192, 210};
	rect_type pause_rect_inner;
	shrink2_rect(&pause_rect_inner, &pause_rect_outer, 5, 5);

	if (!have_mouse_input) {
		if (menu_control_y == 1) {
			play_menu_sound(sound_21_loose_shake_2);
			hovering_pause_menu_item = next_pause_menu_item->id;
		} else if (menu_control_y == -1) {
			play_menu_sound(sound_21_loose_shake_2);
			hovering_pause_menu_item = previous_pause_menu_item->id;
		}
	}

	int y_offset = 50;
	for (int i = 0; i < COUNT(pause_menu_items); ++i) {
		draw_pause_menu_item(&pause_menu_items[i], &pause_rect_inner, &y_offset, color_15_brightwhite);
	}
}

static bool_type were_settings_changed;

// (SDLPoP2's) the frontend applies what changed (SDLPoP's turn_setting_on_off does it itself: SDL_SetWindowFullscreen,
// apply_aspect_ratio, ...); OpenSamurai: the setup's choices and the seed wait for the next start (nothing to apply)
static int setting_apply_group(int setting_id) {
	switch (setting_id) {
		default: return 0;
		case SETTING_FULLSCREEN: return OVERLAY_MENU_APPLY_FULLSCREEN;
		case SETTING_USE_CORRECT_ASPECT_RATIO: case SETTING_USE_INTEGER_SCALING: case SETTING_SCALING_TYPE: return OVERLAY_MENU_APPLY_VIDEO;
		case SETTING_VOLUME: return OVERLAY_MENU_APPLY_AUDIO;
	}
}
// (SDLPoP2's) the random seed setting as the menu shows it: -1 the clock, else the number (shown up to 99999)
static int seed_setting_get(const os_settings* s) { return s->random_seed_clock ? -1 : s->random_seed > 99999 ? 99999 : (int) s->random_seed; }
static void apply_setting(setting_type* setting) {
	int what = setting->cheat ? OVERLAY_MENU_APPLY_CHEATS : setting_apply_group(setting->id);
	if (what && host.apply) host.apply(what);
}

static void turn_setting_on_off(setting_type* setting, byte new_state) {
	if (!setting->cheat) were_settings_changed = 1;   // (the cheats: nothing to save)
	if (setting->linked != NULL) {
		*(int*)(setting->linked) = new_state;
	}
	apply_setting(setting);
}

static void turn_setting_on_off_with_sound(setting_type* setting, byte new_state) {
	play_menu_sound(sound_10_sword_vs_sword);
	turn_setting_on_off(setting, new_state);

}

static int get_setting_value(setting_type* setting) {
	int value = 0;
	if (setting->linked != NULL) {
		switch(setting->number_type) {
			default:
			case SETTING_BYTE:
				value = *(byte*) setting->linked;
				break;
			case SETTING_SBYTE:
				value = *(sbyte*) setting->linked;
				break;
			case SETTING_WORD:
				value = *(word*) setting->linked;
				break;
			case SETTING_SHORT:
				value = *(short*) setting->linked;
				break;
			case SETTING_INT:
				if (setting->id != SETTING_RANDOM_SEED) value = *(int*) setting->linked;
				break;
		}
		if (setting->id == SETTING_RANDOM_SEED) value = seed_setting_get((const os_settings*) ((const char*) setting->linked - offsetof(os_settings, random_seed)));
	}
	return value;
}

static void set_setting_value(setting_type* setting, int value) {
	if (setting->linked != NULL) {
		if (setting->id == SETTING_RANDOM_SEED) {   // (SDLPoP2's) -1 the clock
			os_settings* s = (os_settings*) ((char*) setting->linked - offsetof(os_settings, random_seed));
			s->random_seed_clock = value < 0; s->random_seed = value < 0 ? 0 : (uint64_t) value;
			apply_setting(setting);
			return;
		}
		switch(setting->number_type) {
			default:
			case SETTING_BYTE:
				*(byte*) setting->linked = (byte) value;
				break;
			case SETTING_SBYTE:
				*(sbyte*) setting->linked = (sbyte) value;
				break;
			case SETTING_WORD:
				*(word*) setting->linked = (word) value;
				break;
			case SETTING_SHORT:
				*(short*) setting->linked = (short) value;
				break;
			case SETTING_INT:
				*(int*) setting->linked = value;
				break;
		}
		apply_setting(setting);
	}
}

static void increase_setting(setting_type* setting, int old_value) {
	int new_value = old_value + 1;
	if (setting->linked != NULL && new_value <= setting->max) {
		if (!setting->cheat) were_settings_changed = 1;
		set_setting_value(setting, new_value);
	}
}

static void decrease_setting(setting_type* setting, int old_value) {
	int new_value = old_value - 1;
	if (setting->linked != NULL && new_value >= setting->min) {
		if (!setting->cheat) were_settings_changed = 1;
		set_setting_value(setting, new_value);
	}
}


static void draw_setting_explanation(setting_type* setting) {
	show_text_with_color(&explanation_rect, halign_center, valign_top, setting->explanation, color_7_lightgray);
}

static char* print_setting_value_(setting_type* setting, int value, char* buffer, size_t buffer_size) {
	bool_type has_name = 0;
	names_list_type* list = setting->names_list;
	size_t max_len = MIN(MAX_OPTION_VALUE_NAME_LENGTH, buffer_size);
	if (list != NULL) {
		if (list->type == 0 && value >= 0 && value < list->names.count) {
			snprintf(buffer, max_len, "%s", (*(list->names.data))[value]);
			has_name = 1;
		} else if (list->type == 1) {
			for (int i = 0; i < list->kv_pairs.count; ++i) {
				const key_value_type* kv_pair = list->kv_pairs.data + i;
				if (value == kv_pair->value) {
					snprintf(buffer, max_len, "%s", kv_pair->key);
					has_name = 1;
					break;
				}
			}
		}
	}
	if (!has_name) {
		snprintf(buffer, buffer_size, "%d", value);
	}
	return buffer;
}
#define print_setting_value(setting, value) print_setting_value_(setting, value, value_text_buffer, sizeof(value_text_buffer))

static void draw_setting(setting_type* setting, rect_type* parent, int* y_offset, int inactive_text_color) {
	char value_text_buffer[32];
	rect_type text_rect = *parent;
	text_rect.top += *y_offset;
	int text_color = inactive_text_color;
	int selected_color = color_15_brightwhite;
	int unselected_color = color_7_lightgray;

	rect_type setting_box = text_rect;
	setting_box.top -= 5;
	setting_box.bottom = setting_box.top + 15;
	setting_box.left -= 10;
	setting_box.right += 10;

	if (mouse_clicked && is_mouse_over_rect(&setting_box)) {
		highlighted_setting_id = setting->id;
		controlled_area = 1;
	}

	if (highlighted_setting_id == setting->id) {
		next_setting_id = setting->next;
		previous_setting_id = setting->previous;
		at_scroll_up_boundary = (setting->index == scroll_position);
		at_scroll_down_boundary = (setting->index == scroll_position + 8);

		draw_rect(&setting_box, map_rgba(55, 55, 55, 255));
		rect_type left_side_of_setting_box = setting_box;
		left_side_of_setting_box.left = setting_box.left - 2;
		left_side_of_setting_box.right = setting_box.left;
		draw_rect(&left_side_of_setting_box, color_15_brightwhite);
		draw_setting_explanation(setting);
	}

	bool_type disabled = 0;
	if (setting->required != NULL) {
		disabled = !(*setting->required);
	}
	if (disabled) {
		text_color = color_7_lightgray;
	}

	show_text_with_color(&text_rect, halign_left, valign_top, setting->text, text_color);

	if (setting->style == SETTING_STYLE_TOGGLE && !disabled) {
		bool_type setting_enabled = 1;
		if (setting->linked != NULL) {
			setting_enabled = *(int*)setting->linked;
		}

		// Toggling the setting: either by clicking on "ON" or "OFF", or by pressing left/right.
		if (highlighted_setting_id == setting->id) {
			if (mouse_clicked) {
				if (!setting_enabled) {
					rect_type ON_hitbox = setting_box;
					ON_hitbox.left = setting_box.right - 22;
					if (is_mouse_over_rect(&ON_hitbox)) {
						turn_setting_on_off_with_sound(setting, 1);
						setting_enabled = 0;
					}
				} else {
					rect_type OFF_hitbox = setting_box;
					OFF_hitbox.left = setting_box.right - 49;
					OFF_hitbox.right = setting_box.right - 22;
					if (is_mouse_over_rect(&OFF_hitbox)) {
						turn_setting_on_off_with_sound(setting, 0);
						setting_enabled = 1;
					}
				}
			} else if (setting_enabled && menu_control_x < 0) {
				turn_setting_on_off_with_sound(setting, 0);
				setting_enabled = 0;
			} else if (!setting_enabled && menu_control_x > 0) {
				turn_setting_on_off_with_sound(setting, 1);
				setting_enabled = 1;
			}
		}

		int OFF_color = (setting_enabled) ? unselected_color : selected_color;
		int ON_color = (setting_enabled) ? selected_color : unselected_color;
		show_text_with_color(&text_rect, halign_right, valign_top, "ON", ON_color);
		text_rect.right -= 15;
		show_text_with_color(&text_rect, halign_right, valign_top, "OFF", OFF_color);

	} else if (setting->style == SETTING_STYLE_NUMBER && !disabled) {
		int value = get_setting_value(setting);
		if (highlighted_setting_id == setting->id) {
			if (mouse_clicked) {

				rect_type right_hitbox = {setting_box.top, (int16_t) (text_rect.right - 5), setting_box.bottom, (int16_t) (text_rect.right + 10)};
				if (is_mouse_over_rect(&right_hitbox)) {
					increase_setting(setting, value);
				} else {
					char* value_text = print_setting_value(setting, value);
					int value_text_width = get_line_width(value_text, (int)strlen(value_text));
					rect_type left_hitbox = right_hitbox;
					left_hitbox.left -= (value_text_width + 10);
					left_hitbox.right -= (value_text_width + 5);
					if (is_mouse_over_rect(&left_hitbox)) {
						decrease_setting(setting, value);
					}
				}

			} else if (menu_control_x > 0) {
				increase_setting(setting, value);
			} else if (menu_control_x < 0) {
				decrease_setting(setting, value);
			} else if (setting->id == SETTING_RANDOM_SEED && menu_clear) {   // (SDLPoP2's) Delete: the timer
				were_settings_changed = 1;
				set_setting_value(setting, -1);
			} else if (setting->id == SETTING_RANDOM_SEED && menu_digit >= 0) {   // (SDLPoP2's) digits typed in (the last five kept)
				were_settings_changed = 1;
				set_setting_value(setting, (int) (((long) (value < 0 ? 0 : value) * 10 + menu_digit) % ((long) setting->max + 1)));
			}
		}

		value = get_setting_value(setting); // May have been updated.
		char* value_text = print_setting_value(setting, value);
		show_text_with_color(&text_rect, halign_right, valign_top, value_text, selected_color);

		if (highlighted_setting_id == setting->id) {
			int value_text_width = get_line_width(value_text, (int)strlen(value_text));
			draw_image_with_blending(arrowhead_right_image, text_rect.right + 2, text_rect.top);
			draw_image_with_blending(arrowhead_left_image, text_rect.right - value_text_width - 6, text_rect.top);
		}

	} else if (setting->style == SETTING_STYLE_COMMAND) {
		// OpenSamurai: an entry of the COMMANDS page: its key on the right (as SDLPoP's CONTROLS page's keys); chosen,
		// the menu closes and the key goes to the game
		const command_type* command = (const command_type*) setting->linked;
		char key_text[32];
		overlay_menu_key_label(command->key, key_text, sizeof(key_text));
		show_text_with_color(&text_rect, halign_right, valign_top, key_text, selected_color);
		if (highlighted_setting_id == setting->id) {
			if (pressed_enter || (mouse_clicked && is_mouse_over_rect(&setting_box))) {
				play_menu_sound(sound_22_loose_shake_3);
				menu_action = OVERLAY_MENU_COMMAND;
				command_key_chosen = command->key;
				need_close_menu = 1;
			}
		}

	} else {
		// show text only
		if (highlighted_setting_id == setting->id && (setting->required == NULL || *setting->required != 0)) {
			if (pressed_enter || (mouse_clicked && is_mouse_over_rect(&setting_box))) {
				if (setting->id == SETTING_RESET_ALL_SETTINGS) {
					play_menu_sound(sound_22_loose_shake_3);
					current_dialog_box = DIALOG_RESTORE_DEFAULT_SETTINGS;
					current_dialog_text = "Restore all settings to their default values?";
				}
			}

		}
	}

	*y_offset += 15;
}

static void menu_scroll(int y) {
	settings_area_type* current_settings_area = get_settings_area(active_settings_subsection);
	if (current_settings_area != NULL) {
		int max_scroll = MAX(0, current_settings_area->setting_count - 9);
		if (drawn_menu >= 1 && controlled_area == 1) { // (2: the COMMANDS page)
			if (y < 0 && scroll_position > 0) {
				--scroll_position;
			} else if (y > 0 && scroll_position < max_scroll) {
				++scroll_position;
			}
		}
	}
}

static void draw_settings_area(settings_area_type* settings_area) {
	if (settings_area == NULL) return;
	rect_type settings_area_rect = {0, 80, 170, 320};
	shrink2_rect(&settings_area_rect, &settings_area_rect, 20, 20);

	int start_y_offset = 0;

	int y_offset = start_y_offset;
	int num_drawn_settings = 0;
	for (int i = 0; (i < settings_area->setting_count) && (num_drawn_settings < 9); ++i) {
		if (i >= scroll_position) {
			++num_drawn_settings;
			draw_setting(&settings_area->settings[i], &settings_area_rect, &y_offset, color_15_brightwhite);
		}
	}

	if (scroll_position > 0) {
		draw_image_with_blending(arrowhead_up_image, 200, 10);
	}
	if (scroll_position + num_drawn_settings < settings_area->setting_count) {
		draw_image_with_blending(arrowhead_down_image, 200, 151);
	}

	// Draw a scroll bar if needed.
	// It's not clickable yet, it just shows where you are in the list.
	if (num_drawn_settings < settings_area->setting_count) {
		const int scrollbar_width = 2;
		rect_type scrollbar_rect = {
			.top = (int16_t) (settings_area_rect.top - 5), .bottom = settings_area_rect.bottom,
			.left = (int16_t) (settings_area_rect.right + 10 - scrollbar_width), .right = (int16_t) (settings_area_rect.right + 10)
		};
		method_5_rect(&scrollbar_rect, blitters_0_no_transp, color_8_darkgray);

		int scrollbar_height = scrollbar_rect.bottom - scrollbar_rect.top;
		rect_type scrollbar_slider_rect = {
			.top = (int16_t) (scrollbar_rect.top + scroll_position * scrollbar_height / settings_area->setting_count),
			.bottom = (int16_t) (scrollbar_rect.top + (scroll_position + num_drawn_settings) * scrollbar_height / settings_area->setting_count),
			.left = scrollbar_rect.left, .right = scrollbar_rect.right
		};
		method_5_rect(&scrollbar_slider_rect, blitters_0_no_transp, color_7_lightgray);
	}
}

static void draw_settings_menu(void) {
	settings_area_type* settings_area = get_settings_area(active_settings_subsection);
	pause_menu_alpha = (settings_area == NULL) ? 220 : 255;
	draw_rect_with_alpha(&screen_rect, color_0_black, pause_menu_alpha);

	rect_type pause_rect_outer = {0, 10, 192, 80};
	rect_type pause_rect_inner;
	shrink2_rect(&pause_rect_inner, &pause_rect_outer, 5, 5);

	if (!have_mouse_input) {
		bool_type hovering_item_changed = 0;
		if (controlled_area == 0) {
			int old_hovering_item_id = hovering_pause_menu_item;
			if (menu_control_y == 1) {
				hovering_pause_menu_item = next_pause_menu_item->id;
			} else if (menu_control_y == -1) {
				hovering_pause_menu_item = previous_pause_menu_item->id;
			}
			if (old_hovering_item_id != hovering_pause_menu_item) {
				hovering_item_changed = 1;
			}
		} else if (controlled_area == 1) {
			// settings area
			int old_highlighted_setting_id = highlighted_setting_id;

			// Why does the global variable contain the ID instead of the index?...
			// Find the index from the ID.
			settings_area_type* current_settings_area = get_settings_area(active_settings_subsection);
			int highlighted_setting_index = -1;
			for (int i = 0; i < current_settings_area->setting_count; i++) {
				if (highlighted_setting_id == current_settings_area->settings[i].id) {
					highlighted_setting_index = i;
					break;
				}
			}

			int last = current_settings_area->setting_count - 1;
			int max_scroll = MAX(0, current_settings_area->setting_count - 9);

			if (menu_control_y > 0) {
				// DOWN
				highlighted_setting_index += menu_control_y;
				if (highlighted_setting_index > last) highlighted_setting_index = last;

				// With Page Down, try to leave the selection in the same row visually.
				if (menu_control_y > +1) scroll_position += menu_control_y;

			} else if (menu_control_y < 0) {
				// UP
				highlighted_setting_index += menu_control_y;
				if (highlighted_setting_index < 0) highlighted_setting_index = 0;

				// With Page Up, try to leave the selection in the same row visually.
				if (menu_control_y < -1) scroll_position += menu_control_y;

			}

			if (menu_control_y != 0) {
				// We check both directions in both cases, to scroll the highlighted row back into sight even if the user scrolled it out of sight (with the mouse wheel).
				if (highlighted_setting_index - 8 > scroll_position) scroll_position = highlighted_setting_index - 8;
				if (highlighted_setting_index < scroll_position) scroll_position = highlighted_setting_index;
				if (scroll_position > max_scroll) scroll_position = max_scroll;
				if (scroll_position < 0) scroll_position = 0;
			}

			// Find the ID from the index.
			if (highlighted_setting_index < 0) highlighted_setting_index = 0;   // (not found)
			highlighted_setting_id = current_settings_area->settings[highlighted_setting_index].id;

			if (old_highlighted_setting_id != highlighted_setting_id) {
				hovering_item_changed = 1;
			}
		}
		if (hovering_item_changed) {
			play_menu_sound(sound_21_loose_shake_2);
		}
	}

	// OpenSamurai: the COMMANDS and CHEATS pages have their own left parts
	pause_menu_item_type* left_items = drawn_menu == 2 ? commands_menu_items : drawn_menu == 3 ? cheats_menu_items : settings_menu_items;
	int left_item_count = drawn_menu == 2 ? COUNT(commands_menu_items) : drawn_menu == 3 ? COUNT(cheats_menu_items) : COUNT(settings_menu_items);
	int y_offset = 50;
	for (int i = 0; i < left_item_count; ++i) {
		pause_menu_item_type* item = &left_items[i];
		int text_color = (highlighted_settings_subsection == item->id) ? color_15_brightwhite : color_7_lightgray;
		draw_pause_menu_item(&left_items[i], &pause_rect_inner, &y_offset, text_color);
	}

	draw_settings_area(settings_area);
}

enum dialog_button_ids {
	DIALOG_BUTTON_CANCEL,
	DIALOG_BUTTON_OK,
};

static void set_options_to_default(void);

static void confirmation_dialog_result(int which_dialog, int button) {
	if (button == DIALOG_BUTTON_OK) {
		if (which_dialog == DIALOG_RESTORE_DEFAULT_SETTINGS) {
			play_menu_sound(sound_10_sword_vs_sword);
			were_settings_changed = 1;
			set_options_to_default();
			// (the frontend applies them all: SDLPoP's integer scaling, aspect ratio, sound)
			if (host.apply) host.apply(OVERLAY_MENU_APPLY_VIDEO | OVERLAY_MENU_APPLY_AUDIO);
		} else if (which_dialog == DIALOG_CONFIRM_QUIT) {
			// SDLPoP: last_key_scancode = Ctrl+Q; key_test_quit(); OpenSamurai: the frontend ends the program
			menu_action = OVERLAY_MENU_QUIT;
			need_close_menu = 1;
		}
	} else {
		play_menu_sound(sound_22_loose_shake_3);
	}
}

static rect_type cancel_text_rect = {104, 162,  118,  212};
static rect_type cancel_highlight_rect = {103, 162,  116,  212};
static rect_type ok_text_rect = {104, 108,  118,  158};
static rect_type ok_highlight_rect = {103, 108,  116,  158};

// draw_confirmation_dialog's loop, one pass at a time (the dialog's locals kept between passes). 0: the dialog is done.
static int highlighted_button = DIALOG_BUTTON_OK;
static int old_highlighted_button = -1;
static int draw_confirmation_dialog(int which_dialog, const char* text) {
	{
		key_test_paused_menu(last_key_scancode);
		process_additional_menu_input();

		if (menu_control_back == 1) {
			confirmation_dialog_result(which_dialog, DIALOG_BUTTON_CANCEL);
			goto done;
		}

		if (have_mouse_input) {
			if (is_mouse_over_rect(&ok_highlight_rect)) {
				highlighted_button = DIALOG_BUTTON_OK;
			} else if (is_mouse_over_rect(&cancel_highlight_rect)) {
				highlighted_button = DIALOG_BUTTON_CANCEL;
			}
		}

		if (menu_control_x < 0) {
			highlighted_button = DIALOG_BUTTON_OK;
		} else if (menu_control_x > 0) {
			highlighted_button = DIALOG_BUTTON_CANCEL;
		} else if (mouse_clicked || pressed_enter) {
			confirmation_dialog_result(which_dialog, highlighted_button);
			goto done;
		}

		if (highlighted_button != old_highlighted_button) {
			old_highlighted_button = highlighted_button;
			// Need to redraw the dialog box.
			draw_rect(&screen_rect, color_0_black);
			draw_rect(&copyprot_dialog->peel_rect, color_0_black);
			dialog_method_2_frame(copyprot_dialog);
			rect_type rect;
			shrink2_rect(&rect, &copyprot_dialog->text_rect, 2, 1);
			rect.bottom -= 14;
			show_text_with_color(&rect, halign_center, valign_middle, text, color_15_brightwhite);

			rect_type* highlight_rect;
			int ok_text_color, cancel_text_color;
			if (highlighted_button == DIALOG_BUTTON_OK) {
				highlight_rect = &ok_highlight_rect;
				ok_text_color = color_15_brightwhite;
				cancel_text_color = color_7_lightgray;
			} else {
				highlight_rect = &cancel_highlight_rect;
				ok_text_color = color_7_lightgray;
				cancel_text_color = color_15_brightwhite;
			}
			draw_rect(highlight_rect, color_8_darkgray);
			show_text_with_color(&ok_text_rect, halign_center, valign_middle, "OK", ok_text_color);
			show_text_with_color(&cancel_text_rect, halign_center, valign_middle, "Cancel", cancel_text_color);
		}
		return 1;
	}
done:
	current_dialog_box = 0;
	clear_menu_controls();
	return 0;
}

static int need_full_menu_redraw_count;
static int started_dialog_box;   // the dialog whose loop runs

static void menu_was_closed(void);

// one pass of draw_menu's loop (SDLPoP: while (!need_close_menu) { ... }); overlay_menu_frame runs the passes.
static void draw_menu_pass(void) {
	gport* saved_target_surface = current_target_surface;
	current_target_surface = overlay_surface;

	// (clear_menu_controls, process_events: done by overlay_menu_frame)
	if (current_dialog_box != DIALOG_NONE) {
		// the dialog's loop runs instead of process_key (it reads the keys itself); its locals start afresh
		if (current_dialog_box != started_dialog_box) {
			started_dialog_box = current_dialog_box;
			highlighted_button = DIALOG_BUTTON_OK;
			old_highlighted_button = -1;
		}
		int still_open = draw_confirmation_dialog(current_dialog_box, current_dialog_text);
		if (still_open) goto out;
		started_dialog_box = DIALOG_NONE;
		current_dialog_box = DIALOG_NONE;
		clear_menu_controls();
	} else {
		// process_key
		int key = key_test_paused_menu(last_key_scancode);
		if (key != 0) {
			goto out; // Menu was forcefully closed, for example by pressing Ctrl+A.
		}
		process_additional_menu_input();
	}

	if (is_menu_shown == 1) {
		is_menu_shown = -1; // reset the menu if the menu is drawn for the first time
		need_full_menu_redraw_count = 2;
		reset_paused_menu();
	}
	if (menu_control_back == 1) {
		play_menu_sound(sound_22_loose_shake_3);
		if (drawn_menu == 1) {
			if (controlled_area == 1) {
				leave_settings_subsection();
			} else {
				reset_paused_menu(); // Go back to the top level pause menu.
				hovering_pause_menu_item = PAUSE_MENU_SETTINGS;
			}
		} else if (drawn_menu == 2 || drawn_menu == 3) { // OpenSamurai: the COMMANDS and CHEATS pages, as the settings page
			if (controlled_area == 1) {
				leave_settings_subsection();
			} else {
				int back_to = drawn_menu == 2 ? PAUSE_MENU_COMMANDS : PAUSE_MENU_CHEATS;
				reset_paused_menu();
				hovering_pause_menu_item = back_to;
			}
		} else {
			need_close_menu = 1; // Close the menu.
			goto out;
		}
	}

	if (menu_control_scroll_y != 0) {
		menu_scroll(menu_control_scroll_y);
	}

	if (have_mouse_input || have_keyboard_or_controller_input) {
		// The menu is updated+drawn within the same routine, so redrawing may be necessary after the first time.
		// TODO: Maybe in the future fully separate updating from drawing?
		need_full_menu_redraw_count = 2;
	} else {
		if (need_full_menu_redraw_count == 0) {
			goto out; // Don't redraw if there is no input to process (save CPU cycles).
		}
	}

	{
		word saved_font = textstate.ptr_font;
		textstate.ptr_font = hc_small_font;
		if (drawn_menu == 0) {
			draw_pause_menu();
		} else if (drawn_menu >= 1) { // (2: the COMMANDS page, 3: the CHEATS page, drawn as the settings)
			draw_settings_menu();
		}
		textstate.ptr_font = saved_font;
	}

	--need_full_menu_redraw_count;
out:
	current_target_surface = saved_target_surface;
}

static void clear_menu_controls(void) {
	pressed_enter = 0;
	mouse_moved = 0;
	mouse_clicked = 0;
	mouse_button_clicked_right = 0;
	have_mouse_input = 0;
	have_keyboard_or_controller_input = 0;
	menu_digit = -1; menu_clear = 0;
	menu_control_x = 0;
	menu_control_y = 0;
	menu_control_back = 0;
	menu_control_scroll_y = 0;
}

static void process_additional_menu_input(void) {
	read_mouse_state();
	have_keyboard_or_controller_input = (menu_control_x || menu_control_y || menu_control_back || pressed_enter || menu_digit >= 0 || menu_clear);
	have_mouse_input = (mouse_moved || mouse_clicked || mouse_button_clicked_right || menu_control_scroll_y);

	if (host.window == NULL) return;
	dword flags = SDL_GetWindowFlags(host.window);
	if (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
		if (have_mouse_input) {
			SDL_ShowCursor(SDL_ENABLE);
		} else if (have_keyboard_or_controller_input) {
			SDL_ShowCursor(SDL_DISABLE);
		}
	} else {
		SDL_ShowCursor(SDL_ENABLE);
	}
}

static bool_type joy_ABXY_buttons_released;
static bool_type joy_xy_released;
static dword joy_xy_timeout_counter;
static bool_type joy_menu_button_released;   // (SDLPoP2's) Start / Back -> Backspace

#define CB(button) (1u << (button))
#define MENU_BUTTONS (CB(SDL_CONTROLLER_BUTTON_START) | CB(SDL_CONTROLLER_BUTTON_BACK))
static int controller_held(dword* held, int* x, int* y) {
	*held = 0; *x = *y = 0;
	return host.controller ? host.controller(held, x, y) : 0;
}
static int key_test_paused_menu(int key) {
	menu_digit = -1; menu_clear = 0;
	menu_control_x = 0;
	menu_control_y = 0;
	menu_control_back = 0;

	if (mouse_button_clicked_right) {
		menu_control_back = 1; // Can use RMB to close menus.
	}

	dword held;
	int joy_axis_x, joy_axis_y;
	is_joyst_mode = controller_held(&held, &joy_axis_x, &joy_axis_y);
	if (is_joyst_mode && !joystick_read_this_frame) {   // (once per video frame)
		joystick_read_this_frame = 1;
		int joy_x = 0;
		int joy_y = 0;
		if (held & CB(SDL_CONTROLLER_BUTTON_DPAD_LEFT))
			joy_x = -1;
		else if (held & CB(SDL_CONTROLLER_BUTTON_DPAD_RIGHT))
			joy_x = 1;
		if (held & CB(SDL_CONTROLLER_BUTTON_DPAD_UP))
			joy_y = -1;
		else if (held & CB(SDL_CONTROLLER_BUTTON_DPAD_DOWN))
			joy_y = 1;
		int y_threshold = 14000;
		int x_threshold = 26000; // Less sensitive, to prevent accidentally changing a setting.
		if (joy_axis_y < -y_threshold) {
			joy_y = -1;
		} else if (joy_axis_y > y_threshold) {
			joy_y = 1;
		} else if (joy_axis_x < -x_threshold) {
			joy_x = -1;
		} else if (joy_axis_x > x_threshold) {
			joy_x = 1;
		}

		// Start / Back, pressed: SDLPoP's Backspace (close the menu, go back)
		if (!(held & MENU_BUTTONS)) {
			joy_menu_button_released = 1;
		} else if (joy_menu_button_released) {
			joy_menu_button_released = 0;
			if (key == 0) key = SDL_SCANCODE_BACKSPACE;
		}

		dword needed_timeout = 7; // Delay for hold-down repeated input. (0.1 s in video frames)
		if (joy_x == 0 && joy_y == 0) {
			joy_xy_released = 1;
			joy_xy_timeout_counter = 0;
		} else {
			if (joy_xy_released) {
				needed_timeout = 21; // The delay is longer for the first repetition. (0.3 s)
				joy_xy_released = 0;
			}
			dword current_counter = frame_counter;
			if (current_counter > joy_xy_timeout_counter) {
				menu_control_x = joy_x;
				menu_control_y = joy_y;
				joy_xy_timeout_counter = current_counter + needed_timeout;
				return 0; // cancel other input.
			}
		}

		if (!(held & CB(SDL_CONTROLLER_BUTTON_A)) && !(held & CB(SDL_CONTROLLER_BUTTON_Y)) && !(held & CB(SDL_CONTROLLER_BUTTON_B))) {
			joy_ABXY_buttons_released = 1;
		} else if (joy_ABXY_buttons_released) {
			joy_ABXY_buttons_released = 0;
			if (held & CB(SDL_CONTROLLER_BUTTON_A)) {
				key = SDL_SCANCODE_RETURN;
			} else if (held & CB(SDL_CONTROLLER_BUTTON_B)) {
				key = SDL_SCANCODE_ESCAPE;
			}
		}
	}

	switch(key) {
		default:
			if (key & (WITH_CTRL | WITH_ALT)) {   // OpenSamurai: the game's commands are Alt+ keys
				need_close_menu = 1;
				menu_action = OVERLAY_MENU_KEY;
				menu_action_key = key & 0x1FFF;
				menu_action_mod = (word) (((key & WITH_CTRL) ? KMOD_LCTRL : 0) | ((key & WITH_ALT) ? KMOD_LALT : 0) | ((key & WITH_SHIFT) ? KMOD_LSHIFT : 0));
				return key; // Allow Ctrl+R, etc.
			} else {
				break;
			}
		case SDL_SCANCODE_UP:
			menu_control_y = -1;
			break;
		case SDL_SCANCODE_DOWN:
			menu_control_y = 1;
			break;
		case SDL_SCANCODE_PAGEUP:
			menu_control_y = -9;
			break;
		case SDL_SCANCODE_PAGEDOWN:
			menu_control_y = +9;
			break;
		case SDL_SCANCODE_HOME:
			menu_control_y = -1000;
			break;
		case SDL_SCANCODE_END:
			menu_control_y = +1000;
			break;
		case SDL_SCANCODE_RIGHT:
			menu_control_x = 1;
			break;
		case SDL_SCANCODE_LEFT:
			menu_control_x = -1;
			break;
		case SDL_SCANCODE_RETURN:
		case SDL_SCANCODE_KP_ENTER: // OpenSamurai
		case SDL_SCANCODE_SPACE:
			pressed_enter = 1;
			break;
		case SDL_SCANCODE_1: case SDL_SCANCODE_2: case SDL_SCANCODE_3: case SDL_SCANCODE_4: case SDL_SCANCODE_5:
		case SDL_SCANCODE_6: case SDL_SCANCODE_7: case SDL_SCANCODE_8: case SDL_SCANCODE_9:
			menu_digit = key - SDL_SCANCODE_1 + 1;   // (SDLPoP2's) typed into the random seed field
			break;
		case SDL_SCANCODE_KP_1: case SDL_SCANCODE_KP_2: case SDL_SCANCODE_KP_3: case SDL_SCANCODE_KP_4: case SDL_SCANCODE_KP_5:
		case SDL_SCANCODE_KP_6: case SDL_SCANCODE_KP_7: case SDL_SCANCODE_KP_8: case SDL_SCANCODE_KP_9:
			menu_digit = key - SDL_SCANCODE_KP_1 + 1;
			break;
		case SDL_SCANCODE_0:
		case SDL_SCANCODE_KP_0:
			menu_digit = 0;
			break;
		case SDL_SCANCODE_DELETE:
			menu_clear = 1;   // (SDLPoP2's) the random seed field back to the timer
			break;
		case SDL_SCANCODE_ESCAPE:
		case SDL_SCANCODE_BACKSPACE:
			menu_control_back = 1;
			break;
		case SDL_SCANCODE_F4:   // OpenSamurai: the key that opens the menu closes it, from any page
			need_close_menu = 1;
			break;
	}
	return 0;
}

// (SDLPoP2's) set_options_to_default for the menu's settings
static void set_options_to_default(void) {
	os_settings defaults;
	settings_defaults(&defaults);
	for (int a = 0; a < COUNT(all_settings_areas); ++a) {
		settings_area_type* area = all_settings_areas[a];
		for (int i = 0; i < area->setting_count; ++i) {
			setting_type* setting = &area->settings[i];
			if (!setting->link) continue;
			if (setting->id == SETTING_RANDOM_SEED) {
				S->random_seed_clock = defaults.random_seed_clock; S->random_seed = defaults.random_seed;
				continue;
			}
			memcpy((char*) S + setting->link - 1, (char*) &defaults + setting->link - 1, sizeof(int));
		}
	}
}

/* ---- OpenSamurai.cfg (SDLPoP: SDLPoP.cfg, save_ingame_settings / load_ingame_settings) ---- */
static void write_setting_value(FILE* f, const setting_type* setting, const void* linked) {
	if (setting->id == SETTING_RANDOM_SEED) {
		const os_settings* s = (const os_settings*) ((const char*) linked - offsetof(os_settings, random_seed));
		if (s->random_seed_clock) fprintf(f, "clock\n"); else fprintf(f, "%llu\n", (unsigned long long) s->random_seed);
		return;
	}
	int value = *(const int*) linked;
	if (setting->style == SETTING_STYLE_TOGGLE) fprintf(f, "%s\n", bool_ini_values[value != 0]);
	else if (setting->ini_values) fprintf(f, "%s\n", setting->ini_values[value]);
	else fprintf(f, "%d\n", value);
}
static void write_settings(FILE* f, setting_type* settings, int count, char* section, const os_settings* s, const char* only_section) {
	for (int i = 0; i < count; ++i) {
		setting_type* setting = &settings[i];
		if (setting->ini == NULL || !setting->link) continue;
		const char* slash = strchr(setting->ini, '/');
		if (strncmp(setting->ini, only_section, (size_t)(slash - setting->ini)) != 0 || only_section[slash - setting->ini] != '\0') continue;
		char name[64];
		snprintf(name, sizeof(name), "%.*s", (int)(slash - setting->ini), setting->ini);
		if (strcmp(section, name) != 0) {
			fprintf(f, "\n[%s]\n", name);
			snprintf(section, 64, "%s", name);
		}
		fprintf(f, "%s = ", slash + 1);
		write_setting_value(f, setting, (const char*) s + setting->link - 1);
	}
}
int overlay_menu_save_cfg(const os_settings* s, const char* cfg_path) {
	if (cfg_path == NULL || cfg_path[0] == '\0') return 0;
	FILE* f = fopen(cfg_path, "w");
	if (f == NULL) return 0;
	fprintf(f, "; OpenSamurai.cfg: the settings of OpenSamurai's in-game menu (OpenSamurai.ini's syntax). They are read after\n"
	           "; OpenSamurai.ini unless OpenSamurai.ini is newer. Delete this file to go back to OpenSamurai.ini's settings.\n");
	char section[64] = "";
	static const char* const sections[] = {"General", "Controller", "AdditionalFeatures"};   // (the ini's order)
	for (int k = 0; k < COUNT(sections); ++k) {
		for (int a = 0; a < COUNT(all_settings_areas); ++a) {
			write_settings(f, all_settings_areas[a]->settings, all_settings_areas[a]->setting_count, section, s, sections[k]);
		}
	}
	return fclose(f) == 0;
}
static void save_ingame_settings(void) {
	if (!overlay_menu_save_cfg(S, host.cfg_path) && host.cfg_path[0]) {
		fprintf(stderr, "opensamurai: cannot write %s: the menu's settings are not saved\n", host.cfg_path);
	}
}
int overlay_menu_load_cfg(os_settings* s, const char* cfg_path, const char* ini_path, settings_warn_fn warn) {
	// We want the SDLPoP.cfg file (in-game menu settings) to override the SDLPoP.ini file,
	// but ONLY if the .ini file wasn't modified since the last time the .cfg file was saved!
	struct stat st_ini, st_cfg;
	if (cfg_path == NULL || cfg_path[0] == '\0') return 0;
	if (stat(cfg_path, &st_cfg) != 0) return 0;
	if (ini_path != NULL && ini_path[0] && stat(ini_path, &st_ini) == 0) {
		if (st_ini.st_mtime > st_cfg.st_mtime) {
			// SDLPoP.ini is newer than SDLPoP.cfg, so just go with the .ini configuration
			return 0;
		}
	}
	// If there is a SDLPoP.cfg file, let it override the settings
	return settings_load(s, cfg_path, warn);
}

static void menu_was_closed(void) {
	is_menu_shown = 0;
	memcpy(key_suppressed, key_held, sizeof(key_suppressed));   // OpenSamurai: (SDLPoP's escape_key_suppressed, every key)
	if (were_settings_changed) {
		save_ingame_settings();
		were_settings_changed = 0;
	}
	// In fullscreen mode, hide the mouse cursor (because it is only needed in the menu).
	if (host.window != NULL) {
		dword flags = SDL_GetWindowFlags(host.window);
		if (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
			SDL_ShowCursor(SDL_DISABLE);
		} else {
			SDL_ShowCursor(SDL_ENABLE);
		}
	}
}

/* ---- the frontend's entry points ---- */
void overlay_menu_init(const overlay_menu_host* menu_host) {
	host = *menu_host;
	S = host.settings;
	cheats_available = host.cheats != NULL;
	overlay_color_count = 0;
	for (int i = 0; i < 16; ++i) {
		map_rgba(vga_palette_default[i][0] << 2, vga_palette_default[i][1] << 2, vga_palette_default[i][2] << 2, 255);
	}
	if (overlay_surface == NULL) overlay_surface = port_new(&rect_screen);
	if (bottom_text_surface == NULL) bottom_text_surface = port_new(&rect_screen);
	current_target_surface = overlay_surface;
	static bool_type font_loaded;
	if (!font_loaded) {
		load_font_character_offsets(hc_small_font_data);   // (hc_font_data has its offsets)
		font_loaded = 1;
	}
	gfx_add_font(hc_font, hc_font_data);
	gfx_add_font(hc_small_font, hc_small_font_data);
	calc_dialog_peel_rect(copyprot_dialog);
	init_menu();
	next_pause_menu_item = previous_pause_menu_item = &pause_menu_items[0];   // (before the first drawing)
	is_menu_shown = 0;
	current_dialog_box = DIALOG_NONE;
}

int overlay_menu_is_open(void) { return is_menu_shown != 0; }

static void track_key(const SDL_Event* e) {
	if (e->type != SDL_KEYDOWN && e->type != SDL_KEYUP) return;
	SDL_Scancode scancode = e->key.keysym.scancode;
	if ((int) scancode >= SDL_NUM_SCANCODES) return;
	key_held[scancode] = e->type == SDL_KEYDOWN;
	// Prevent repeated keystrokes opening/closing the menu as long as the key is held down.
	if (e->type == SDL_KEYUP) key_suppressed[scancode] = 0;
}

void overlay_menu_open(void) {
	if (S == NULL || is_menu_shown) return;
	// seg000.c (process_key, play_level_2): is_paused = 1, is_menu_shown = 1; display_text_bottom("GAME PAUSED")
	is_menu_shown = 1;
	display_text_bottom("GAME PAUSED");
	// draw_menu:
	need_close_menu = 0;
	key_queue_count = 0;
	pending_mouse_clicked = pending_mouse_clicked_right = pending_scroll_y = 0;
	dword held; int stick_x, stick_y;
	joy_menu_button_released = !(controller_held(&held, &stick_x, &stick_y) && (held & MENU_BUTTONS));   // (the button that opened it)
	joy_ABXY_buttons_released = !(held & (CB(SDL_CONTROLLER_BUTTON_A) | CB(SDL_CONTROLLER_BUTTON_B) | CB(SDL_CONTROLLER_BUTTON_Y)));
	gport* saved = current_target_surface;
	current_target_surface = overlay_surface;
	draw_rect(&screen_rect, map_rgba(0, 0, 0, 0));
	current_target_surface = saved;
}

int overlay_menu_open_event(const SDL_Event* e) {
	if (S == NULL) return 0;
	if (e->type == SDL_KEYDOWN || e->type == SDL_KEYUP) {
		track_key(e);
		SDL_Scancode scancode = e->key.keysym.scancode;
		if (scancode == SDL_SCANCODE_F4) {   // OpenSamurai: F4 is the menu's, never the game's
			return e->type == SDL_KEYDOWN && !e->key.repeat && !(e->key.keysym.mod & (KMOD_CTRL | KMOD_ALT)) ? 1 : 2;
		}
		if (e->type == SDL_KEYUP) return 0;
		if ((int) scancode < SDL_NUM_SCANCODES && key_suppressed[scancode]) {
			return 2; // Prevent repeated keystrokes opening/closing the menu as long as the key is held down.
		}
		return 0;
	}
	if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT) {
		// seg009.c process_events: the left mouse button (the menu not shown) is Backspace
		mouse_position_from_event(e->button.x, e->button.y);
		return 1;
	}
	if (e->type == SDL_CONTROLLERBUTTONDOWN && (MENU_BUTTONS & CB(e->cbutton.button))) {
		return 1;   // (SDLPoP2's button_menu)
	}
	return 0;
}

int overlay_menu_event(const SDL_Event* e) {
	switch (e->type) {
		case SDL_KEYDOWN: {
			track_key(e);
			SDL_Scancode scancode = e->key.keysym.scancode;
			word modifier = e->key.keysym.mod;
			if (key_queue_count >= KEY_QUEUE_SIZE) return 1;
			int key = 0;
			switch (scancode) {
				// Keys that are ignored by themselves:
				case SDL_SCANCODE_LCTRL:
				case SDL_SCANCODE_LSHIFT:
				case SDL_SCANCODE_LALT:
				case SDL_SCANCODE_LGUI:
				case SDL_SCANCODE_RCTRL:
				case SDL_SCANCODE_RSHIFT:
				case SDL_SCANCODE_RALT:
				case SDL_SCANCODE_RGUI:
				case SDL_SCANCODE_CAPSLOCK:
				case SDL_SCANCODE_SCROLLLOCK:
				case SDL_SCANCODE_NUMLOCKCLEAR:
				case SDL_SCANCODE_APPLICATION:
				case SDL_SCANCODE_PRINTSCREEN:
				case SDL_SCANCODE_VOLUMEUP:
				case SDL_SCANCODE_VOLUMEDOWN:
				// Why are there two mute key codes?
				case SDL_SCANCODE_MUTE:
				case SDL_SCANCODE_AUDIOMUTE:
				case SDL_SCANCODE_PAUSE:
					break;

				default:
					if (scancode == SDL_SCANCODE_F4 && e->key.repeat) break;   // OpenSamurai: (F4 held from opening it)
					key = scancode;
					if (modifier & KMOD_SHIFT) key |= WITH_SHIFT;
					if (modifier & KMOD_CTRL ) key |= WITH_CTRL ;
					if (modifier & KMOD_ALT  ) key |= WITH_ALT  ;
			}
			key_queue[key_queue_count++] = key;
			return 1;
		}
		case SDL_KEYUP:
			track_key(e);
			return 1;
		case SDL_MOUSEMOTION:
			mouse_position_from_event(e->motion.x, e->motion.y);
			return 1;
		case SDL_MOUSEBUTTONDOWN:
			mouse_position_from_event(e->button.x, e->button.y);
			switch(e->button.button) {
				case SDL_BUTTON_LEFT:
					pending_mouse_clicked = 1;
					break;
				case SDL_BUTTON_RIGHT:
				case SDL_BUTTON_X1: // 'Back' button (on mice that have these extra buttons).
					pending_mouse_clicked_right = 1;
					break;
				default: break;
			}
			return 1;
		case SDL_MOUSEBUTTONUP:
			return 1;
		case SDL_MOUSEWHEEL:
			pending_scroll_y = -e->wheel.y;
			return 1;
	}
	return 0;
}

int overlay_menu_frame(void) {
	menu_action = OVERLAY_MENU_NONE;
	if (!is_menu_shown) return menu_action;
	++frame_counter;
	joystick_read_this_frame = 0;
	// draw_menu's loop: a pass for each key that came (at least one pass a frame)
	int count = key_queue_count;
	for (int i = 0; i == 0 || i < count; ++i) {
		clear_menu_controls();
		// process_events
		last_key_scancode = i < count ? key_queue[i] : 0;
		if (i == 0) {
			mouse_clicked = pending_mouse_clicked;
			mouse_button_clicked_right = pending_mouse_clicked_right;
			menu_control_scroll_y = pending_scroll_y;
		}
		draw_menu_pass();
		if (need_close_menu && current_dialog_box == DIALOG_NONE) break;
	}
	key_queue_count = 0;
	pending_mouse_clicked = pending_mouse_clicked_right = pending_scroll_y = 0;
	if (need_close_menu && current_dialog_box == DIALOG_NONE) {
		menu_was_closed();
	}
	return menu_action;
}

void overlay_menu_key(SDL_Scancode* key, uint16_t* mod) {
	*key = (SDL_Scancode) menu_action_key;
	*mod = menu_action_mod;
}

void overlay_menu_state(int* page, const char** item, const char** subsection, const char** setting, int* dialog) {
	*page = drawn_menu;
	*item = *subsection = *setting = "";
	for (int i = 0; i < COUNT(pause_menu_items); ++i) if (pause_menu_items[i].id == hovering_pause_menu_item) *item = pause_menu_items[i].text;
	for (int i = 0; i < COUNT(settings_menu_items); ++i) {
		if (settings_menu_items[i].id == hovering_pause_menu_item) *item = settings_menu_items[i].text;
		if (settings_menu_items[i].id == active_settings_subsection) *subsection = settings_menu_items[i].text;
	}
	for (int i = 0; i < COUNT(commands_menu_items); ++i) {
		if (commands_menu_items[i].id == hovering_pause_menu_item) *item = commands_menu_items[i].text;
		if (commands_menu_items[i].id == active_settings_subsection) *subsection = commands_menu_items[i].text;
	}
	for (int i = 0; i < COUNT(cheats_menu_items); ++i) {
		if (cheats_menu_items[i].id == hovering_pause_menu_item) *item = cheats_menu_items[i].text;
		if (cheats_menu_items[i].id == active_settings_subsection) *subsection = cheats_menu_items[i].text;
	}
	settings_area_type* area = get_settings_area(active_settings_subsection);
	if (area != NULL && controlled_area == 1) {
		for (int i = 0; i < area->setting_count; ++i) if (area->settings[i].id == highlighted_setting_id) *setting = area->settings[i].text;
	}
	*dialog = current_dialog_box;
}

int overlay_menu_command_key(void) { return command_key_chosen; }

void overlay_menu_close(void) {
	if (is_menu_shown) menu_was_closed();
}

static void blend_port(const gport* port, uint32_t* argb) {
	for (int i = 0; i < SCREEN_W * SCREEN_H; ++i) {
		const rgba_type* c = &overlay_colors[port->bits[i]];
		if (c->a == 0) continue;
		if (c->a == 255) {
			argb[i] = 0xFF000000u | (uint32_t) c->r << 16 | (uint32_t) c->g << 8 | c->b;
			continue;
		}
		uint32_t d = argb[i];
		int a = c->a;
		int r = (c->r * a + (int)((d >> 16) & 0xFF) * (255 - a) + 127) / 255;
		int g = (c->g * a + (int)((d >> 8) & 0xFF) * (255 - a) + 127) / 255;
		int b = (c->b * a + (int)(d & 0xFF) * (255 - a) + 127) / 255;
		argb[i] = 0xFF000000u | (uint32_t) r << 16 | (uint32_t) g << 8 | (uint32_t) b;
	}
}
void overlay_menu_compose(uint32_t* argb) {
	if (!is_menu_shown) return;
	// update_screen / draw_overlay: the screen (with its bottom text), then the overlay surface blended over it
	blend_port(bottom_text_surface, argb);
	blend_port(overlay_surface, argb);
}


// Big font (hardcoded): SDLPoP's seg009.c hc_font_data (Prince of Persia's font, its built-in copy).
byte hc_font_data[] = {
0x20,0x83,0x07,0x00,0x02,0x00,0x01,0x00,0x01,0x00,0xD2,0x00,0xD8,0x00,0xE5,0x00,
0xEE,0x00,0xFA,0x00,0x07,0x01,0x14,0x01,0x21,0x01,0x2A,0x01,0x37,0x01,0x44,0x01,
0x50,0x01,0x5C,0x01,0x6A,0x01,0x74,0x01,0x81,0x01,0x8E,0x01,0x9B,0x01,0xA8,0x01,
0xB5,0x01,0xC2,0x01,0xCF,0x01,0xDC,0x01,0xE9,0x01,0xF6,0x01,0x03,0x02,0x10,0x02,
0x1C,0x02,0x2A,0x02,0x37,0x02,0x42,0x02,0x4F,0x02,0x5C,0x02,0x69,0x02,0x76,0x02,
0x83,0x02,0x90,0x02,0x9D,0x02,0xAA,0x02,0xB7,0x02,0xC4,0x02,0xD1,0x02,0xDE,0x02,
0xEB,0x02,0xF8,0x02,0x05,0x03,0x12,0x03,0x1F,0x03,0x2C,0x03,0x39,0x03,0x46,0x03,
0x53,0x03,0x60,0x03,0x6D,0x03,0x7A,0x03,0x87,0x03,0x94,0x03,0xA1,0x03,0xAE,0x03,
0xBB,0x03,0xC8,0x03,0xD5,0x03,0xE2,0x03,0xEB,0x03,0xF9,0x03,0x02,0x04,0x0F,0x04,
0x1C,0x04,0x29,0x04,0x36,0x04,0x43,0x04,0x50,0x04,0x5F,0x04,0x6C,0x04,0x79,0x04,
0x88,0x04,0x95,0x04,0xA2,0x04,0xAF,0x04,0xBC,0x04,0xC9,0x04,0xD8,0x04,0xE7,0x04,
0xF4,0x04,0x01,0x05,0x0E,0x05,0x1B,0x05,0x28,0x05,0x35,0x05,0x42,0x05,0x51,0x05,
0x5E,0x05,0x6B,0x05,0x78,0x05,0x85,0x05,0x8D,0x05,0x9A,0x05,0xA7,0x05,0xBB,0x05,
0xD9,0x05,0x00,0x00,0x03,0x00,0x00,0x00,0x07,0x00,0x02,0x00,0x01,0x00,0xC0,0xC0,
0xC0,0xC0,0xC0,0x00,0xC0,0x03,0x00,0x05,0x00,0x01,0x00,0xD8,0xD8,0xD8,0x06,0x00,
0x07,0x00,0x01,0x00,0x00,0x6C,0xFE,0x6C,0xFE,0x6C,0x07,0x00,0x07,0x00,0x01,0x00,
0x10,0x7C,0xD0,0x7C,0x16,0x7C,0x10,0x07,0x00,0x08,0x00,0x01,0x00,0xC3,0xC6,0x0C,
0x18,0x30,0x63,0xC3,0x07,0x00,0x08,0x00,0x01,0x00,0x38,0x6C,0x38,0x7A,0xCC,0xCE,
0x7B,0x03,0x00,0x03,0x00,0x01,0x00,0x60,0x60,0xC0,0x07,0x00,0x04,0x00,0x01,0x00,
0x30,0x60,0xC0,0xC0,0xC0,0x60,0x30,0x07,0x00,0x04,0x00,0x01,0x00,0xC0,0x60,0x30,
0x30,0x30,0x60,0xC0,0x06,0x00,0x07,0x00,0x01,0x00,0x00,0x6C,0x38,0xFE,0x38,0x6C,
0x06,0x00,0x06,0x00,0x01,0x00,0x00,0x30,0x30,0xFC,0x30,0x30,0x08,0x00,0x03,0x00,
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0xC0,0x04,0x00,0x04,0x00,0x01,0x00,
0x00,0x00,0x00,0xF0,0x07,0x00,0x02,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,
0xC0,0x07,0x00,0x08,0x00,0x01,0x00,0x03,0x06,0x0C,0x18,0x30,0x60,0xC0,0x07,0x00,
0x06,0x00,0x01,0x00,0x78,0xCC,0xCC,0xCC,0xCC,0xCC,0x78,0x07,0x00,0x06,0x00,0x01,
0x00,0x30,0x70,0xF0,0x30,0x30,0x30,0xFC,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,
0x0C,0x18,0x30,0x60,0xFC,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0x0C,0x18,0x0C,
0xCC,0x78,0x07,0x00,0x07,0x00,0x01,0x00,0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x0C,0x07,
0x00,0x06,0x00,0x01,0x00,0xF8,0xC0,0xC0,0xF8,0x0C,0x0C,0xF8,0x07,0x00,0x06,0x00,
0x01,0x00,0x78,0xC0,0xC0,0xF8,0xCC,0xCC,0x78,0x07,0x00,0x06,0x00,0x01,0x00,0xFC,
0x0C,0x18,0x30,0x30,0x30,0x30,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0xCC,0x78,
0xCC,0xCC,0x78,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0xCC,0x7C,0x0C,0xCC,0x78,
0x06,0x00,0x02,0x00,0x01,0x00,0x00,0xC0,0xC0,0x00,0xC0,0xC0,0x08,0x00,0x03,0x00,
0x01,0x00,0x00,0x60,0x60,0x00,0x00,0x60,0x60,0xC0,0x07,0x00,0x05,0x00,0x01,0x00,
0x18,0x30,0x60,0xC0,0x60,0x30,0x18,0x05,0x00,0x04,0x00,0x01,0x00,0x00,0x00,0xF0,
0x00,0xF0,0x07,0x00,0x05,0x00,0x01,0x00,0xC0,0x60,0x30,0x18,0x30,0x60,0xC0,0x07,
0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0x0C,0x18,0x30,0x00,0x30,0x07,0x00,0x06,0x00,
0x01,0x00,0x78,0xCC,0xDC,0xDC,0xD8,0xC0,0x78,0x07,0x00,0x06,0x00,0x01,0x00,0x78,
0xCC,0xCC,0xFC,0xCC,0xCC,0xCC,0x07,0x00,0x06,0x00,0x01,0x00,0xF8,0xCC,0xCC,0xF8,
0xCC,0xCC,0xF8,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0xC0,0xC0,0xC0,0xCC,0x78,
0x07,0x00,0x06,0x00,0x01,0x00,0xF8,0xCC,0xCC,0xCC,0xCC,0xCC,0xF8,0x07,0x00,0x05,
0x00,0x01,0x00,0xF8,0xC0,0xC0,0xF0,0xC0,0xC0,0xF8,0x07,0x00,0x05,0x00,0x01,0x00,
0xF8,0xC0,0xC0,0xF0,0xC0,0xC0,0xC0,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0xC0,
0xDC,0xCC,0xCC,0x78,0x07,0x00,0x06,0x00,0x01,0x00,0xCC,0xCC,0xCC,0xFC,0xCC,0xCC,
0xCC,0x07,0x00,0x04,0x00,0x01,0x00,0xF0,0x60,0x60,0x60,0x60,0x60,0xF0,0x07,0x00,
0x06,0x00,0x01,0x00,0x0C,0x0C,0x0C,0x0C,0x0C,0xCC,0x78,0x07,0x00,0x07,0x00,0x01,
0x00,0xC6,0xCC,0xD8,0xF0,0xD8,0xCC,0xC6,0x07,0x00,0x05,0x00,0x01,0x00,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC0,0xF8,0x07,0x00,0x08,0x00,0x01,0x00,0xC3,0xE7,0xFF,0xDB,0xC3,
0xC3,0xC3,0x07,0x00,0x06,0x00,0x01,0x00,0xCC,0xCC,0xEC,0xFC,0xDC,0xCC,0xCC,0x07,
0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0xCC,0xCC,0xCC,0xCC,0x78,0x07,0x00,0x06,0x00,
0x01,0x00,0xF8,0xCC,0xCC,0xF8,0xC0,0xC0,0xC0,0x07,0x00,0x06,0x00,0x01,0x00,0x78,
0xCC,0xCC,0xCC,0xCC,0xD8,0x6C,0x07,0x00,0x06,0x00,0x01,0x00,0xF8,0xCC,0xCC,0xF8,
0xD8,0xCC,0xCC,0x07,0x00,0x06,0x00,0x01,0x00,0x78,0xCC,0xC0,0x78,0x0C,0xCC,0x78,
0x07,0x00,0x06,0x00,0x01,0x00,0xFC,0x30,0x30,0x30,0x30,0x30,0x30,0x07,0x00,0x06,
0x00,0x01,0x00,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0x7C,0x07,0x00,0x06,0x00,0x01,0x00,
0xCC,0xCC,0xCC,0xCC,0xCC,0x78,0x30,0x07,0x00,0x08,0x00,0x01,0x00,0xC3,0xC3,0xC3,
0xDB,0xFF,0xE7,0xC3,0x07,0x00,0x06,0x00,0x01,0x00,0xCC,0xCC,0x78,0x30,0x78,0xCC,
0xCC,0x07,0x00,0x06,0x00,0x01,0x00,0xCC,0xCC,0xCC,0x78,0x30,0x30,0x30,0x07,0x00,
0x08,0x00,0x01,0x00,0xFF,0x06,0x0C,0x18,0x30,0x60,0xFF,0x07,0x00,0x04,0x00,0x01,
0x00,0xF0,0xC0,0xC0,0xC0,0xC0,0xC0,0xF0,0x07,0x00,0x08,0x00,0x01,0x00,0xC0,0x60,
0x30,0x18,0x0C,0x06,0x03,0x07,0x00,0x04,0x00,0x01,0x00,0xF0,0x30,0x30,0x30,0x30,
0x30,0xF0,0x03,0x00,0x06,0x00,0x01,0x00,0x30,0x78,0xCC,0x08,0x00,0x06,0x00,0x01,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x03,0x00,0x04,0x00,0x01,0x00,0xC0,
0x60,0x30,0x07,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x78,0x0C,0x7C,0xCC,0x7C,0x07,
0x00,0x06,0x00,0x01,0x00,0xC0,0xC0,0xF8,0xCC,0xCC,0xCC,0xF8,0x07,0x00,0x06,0x00,
0x01,0x00,0x00,0x00,0x78,0xCC,0xC0,0xCC,0x78,0x07,0x00,0x06,0x00,0x01,0x00,0x0C,
0x0C,0x7C,0xCC,0xCC,0xCC,0x7C,0x07,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x78,0xCC,
0xFC,0xC0,0x7C,0x07,0x00,0x05,0x00,0x01,0x00,0x38,0x60,0xF8,0x60,0x60,0x60,0x60,
0x09,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x78,0xCC,0xCC,0xCC,0x7C,0x0C,0x78,0x07,
0x00,0x06,0x00,0x01,0x00,0xC0,0xC0,0xF8,0xCC,0xCC,0xCC,0xCC,0x07,0x00,0x02,0x00,
0x01,0x00,0xC0,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x09,0x00,0x04,0x00,0x01,0x00,0x30,
0x00,0x30,0x30,0x30,0x30,0x30,0x30,0xE0,0x07,0x00,0x06,0x00,0x01,0x00,0xC0,0xC0,
0xCC,0xD8,0xF0,0xD8,0xCC,0x07,0x00,0x02,0x00,0x01,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,
0xC0,0xC0,0x07,0x00,0x08,0x00,0x01,0x00,0x00,0x00,0xFE,0xDB,0xDB,0xDB,0xDB,0x07,
0x00,0x06,0x00,0x01,0x00,0x00,0x00,0xF8,0xCC,0xCC,0xCC,0xCC,0x07,0x00,0x06,0x00,
0x01,0x00,0x00,0x00,0x78,0xCC,0xCC,0xCC,0x78,0x09,0x00,0x06,0x00,0x01,0x00,0x00,
0x00,0xF8,0xCC,0xCC,0xCC,0xF8,0xC0,0xC0,0x09,0x00,0x06,0x00,0x01,0x00,0x00,0x00,
0x78,0xCC,0xCC,0xCC,0x7C,0x0C,0x0C,0x07,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x78,
0xCC,0xC0,0xC0,0xC0,0x07,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x78,0xC0,0x78,0x0C,
0xF8,0x07,0x00,0x05,0x00,0x01,0x00,0x60,0x60,0xF8,0x60,0x60,0x60,0x38,0x07,0x00,
0x06,0x00,0x01,0x00,0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x7C,0x07,0x00,0x06,0x00,0x01,
0x00,0x00,0x00,0xCC,0xCC,0xCC,0x78,0x30,0x07,0x00,0x08,0x00,0x01,0x00,0x00,0x00,
0xC3,0xC3,0xDB,0xFF,0x66,0x07,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0xCC,0x78,0x30,
0x78,0xCC,0x09,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x7C,0x0C,
0x78,0x07,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0xFC,0x18,0x30,0x60,0xFC,0x07,0x00,
0x04,0x00,0x01,0x00,0x30,0x60,0x60,0xC0,0x60,0x60,0x30,0x07,0x00,0x02,0x00,0x01,
0x00,0xC0,0xC0,0xC0,0x00,0xC0,0xC0,0xC0,0x07,0x00,0x04,0x00,0x01,0x00,0xC0,0x60,
0x60,0x30,0x60,0x60,0xC0,0x02,0x00,0x07,0x00,0x01,0x00,0x76,0xDC,0x07,0x00,0x07,
0x00,0x01,0x00,0x00,0x00,0x70,0xC4,0xCC,0x8C,0x38,0x07,0x00,0x07,0x00,0x01,0x00,
0x00,0x06,0x0C,0xD8,0xF0,0xE0,0xC0,0x08,0x00,0x10,0x00,0x02,0x00,0x7F,0xFE,0xCD,
0xC7,0xB5,0xEF,0xB5,0xEF,0x85,0xEF,0xB5,0xEF,0xB4,0x6F,0x08,0x00,0x13,0x00,0x03,
0x00,0x7F,0xFF,0xC0,0xCC,0x46,0xE0,0xB6,0xDA,0xE0,0xBE,0xDA,0xE0,0xBE,0xC6,0xE0,
0xB6,0xDA,0xE0,0xCE,0xDA,0x20,0x7F,0xFF,0xC0,0x08,0x00,0x11,0x00,0x03,0x00,0x7F,
0xFF,0x00,0xC6,0x73,0x80,0xDD,0xAD,0x80,0xCE,0xEF,0x80,0xDF,0x6F,0x80,0xDD,0xAD,
0x80,0xC6,0x73,0x80,0x7F,0xFF,0x00
};

// Small font (hardcoded).
// The alphanumeric characters were adapted from the freeware font '04b_03' by Yuji Oshimoto. See: http://www.04.jp.org/

#define BINARY_8(b7,b6,b5,b4,b3,b2,b1,b0) ((b0) | ((b1)<<1) | ((b2)<<2) | ((b3)<<3) | ((b4)<<4) | ((b5)<<5) | ((b6)<<6) | ((b7)<<7))
#define BINARY_4(b7,b6,b5,b4) (((b4)<<4) | ((b5)<<5) | ((b6)<<6) | ((b7)<<7))
#define _ 0
#define WORD(x) (byte)(x), (byte)((x)>>8)
#define IMAGE_DATA(height, width, flags) WORD(height), WORD(width), WORD(flags)

byte hc_small_font_data[] = {

		32, 126, WORD(5), WORD(2), WORD(1), WORD(1),

		// offsets (will be initialized at run-time)
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 41
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 51
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 61
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 71
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 81
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 91
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 101
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 111
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 121
		WORD(0), WORD(0), WORD(0), WORD(0), WORD(0), // 126

		IMAGE_DATA(1, 3, 1), // space
		BINARY_4( _,_,_,_ ),

		IMAGE_DATA(5, 1, 1), // !
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 3, 1), // "
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),

		IMAGE_DATA(5, 5, 1), // #
		BINARY_8( _,1,_,1,_,_,_,_ ),
		BINARY_8( 1,1,1,1,1,_,_,_ ),
		BINARY_8( _,1,_,1,_,_,_,_ ),
		BINARY_8( 1,1,1,1,1,_,_,_ ),
		BINARY_8( _,1,_,1,_,_,_,_ ),

		IMAGE_DATA(6, 3, 1), // $
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,1,_,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 6, 1), // %
		BINARY_8( _,_,_,_,_,_,_,_ ),
		BINARY_8( 1,1,_,_,1,_,_,_ ),
		BINARY_8( 1,1,_,1,_,_,_,_ ),
		BINARY_8( _,_,1,_,1,1,_,_ ),
		BINARY_8( _,1,_,_,1,1,_,_ ),

		IMAGE_DATA(5, 5, 1), // &
		BINARY_8( _,1,1,_,_,_,_,_ ),
		BINARY_8( _,1,1,_,_,_,_,_ ),
		BINARY_8( 1,1,1,_,1,_,_,_ ),
		BINARY_8( 1,_,_,1,_,_,_,_ ),
		BINARY_8( _,1,1,_,1,_,_,_ ),

		IMAGE_DATA(2, 1, 1), // '
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 3, 1), // (
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 3, 1), // )
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(4, 5, 1),
		BINARY_8( _,_,_,_,_,_,_,_ ), // *
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( _,1,1,1,_,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),

		IMAGE_DATA(4, 3, 1), // +
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(6, 2, 1), // ,
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(3, 3, 1), // -
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 1, 1), // .
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // /
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // 0
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 2, 1), // 1
		BINARY_4( 1,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 4, 1), // 2
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // 3
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // 4
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,1,1,1 ),
		BINARY_4( _,_,1,_ ),

		IMAGE_DATA(5, 4, 1), // 5
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // 6
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // 7
		BINARY_4( 1,1,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 4, 1), // 8
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // 9
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 1, 1), // :
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(6, 2, 1), // ;
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 3, 1), // <
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,1,_ ),

		IMAGE_DATA(4, 3, 1), // =
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // >
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // ?
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,1,_ ),

		IMAGE_DATA(6, 4, 1), // @
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,1,1 ),
		BINARY_4( 1,_,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // A
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // B
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // C
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // D
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // E
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // F
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // G
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // H
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 3, 1), // I
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // J
		BINARY_4( _,_,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // K
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,1,_,_ ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // L
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,1 ),

		IMAGE_DATA(5, 5, 1), // M
		BINARY_8( 1,_,_,_,1,_,_,_ ),
		BINARY_8( 1,1,_,1,1,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( 1,_,_,_,1,_,_,_ ),
		BINARY_8( 1,_,_,_,1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // N
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,_,1 ),
		BINARY_4( 1,_,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // O
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // P
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(6, 4, 1), // Q
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( _,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // R
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // S
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 3, 1), // T
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 4, 1), // U
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // V
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 5, 1),
		BINARY_8( 1,_,_,_,1,_,_,_ ), // W
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( _,1,_,1,_,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // X
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // Y
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 3, 1), // Z
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 2, 1), // [
		BINARY_4( 1,1,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,_,_ ),

		IMAGE_DATA(5, 4, 1), // '\'
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // ]
		BINARY_4( 1,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,_,_ ),

		IMAGE_DATA(2, 3, 1), // ^
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,1,_ ),

		IMAGE_DATA(5, 3, 1), // _
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(2, 2, 1), // `
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 4, 1), // a
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // b
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 3, 1), // c
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // d
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // e
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,1,1 ),
		BINARY_4( 1,1,_,_ ),
		BINARY_4( _,1,1,1 ),

		IMAGE_DATA(5, 3, 1), // f
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(7, 4, 1), // g
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // h
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 1, 1), // i
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(7, 2, 1), // j
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // k
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 1, 1), // l
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 5, 1), // m
		BINARY_8( _,_,_,_,_,_,_,_ ),
		BINARY_8( 1,1,1,1,_,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // n
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),

		IMAGE_DATA(5, 4, 1), // o
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(7, 4, 1), // p
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(7, 4, 1), // q
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,_,_,1 ),

		IMAGE_DATA(5, 3, 1), // r
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( 1,1,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // s
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( 1,1,_,_ ),
		BINARY_4( _,_,1,1 ),
		BINARY_4( 1,1,1,_ ),

		IMAGE_DATA(5, 3, 1), // t
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,1,_ ),

		IMAGE_DATA(5, 4, 1), // u
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // v
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( _,1,_,_ ),

		IMAGE_DATA(5, 5, 1), // w
		BINARY_8( _,_,_,_,_,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( 1,_,1,_,1,_,_,_ ),
		BINARY_8( _,1,_,1,_,_,_,_ ),
		BINARY_8( _,1,_,1,_,_,_,_ ),

		IMAGE_DATA(5, 3, 1), // x
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,1,_ ),

		IMAGE_DATA(7, 4, 1), // y
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( 1,_,_,1 ),
		BINARY_4( _,1,1,1 ),
		BINARY_4( _,_,_,1 ),
		BINARY_4( _,1,1,_ ),

		IMAGE_DATA(5, 4, 1), // z
		BINARY_4( _,_,_,_ ),
		BINARY_4( 1,1,1,1 ),
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,1,1 ),

		IMAGE_DATA(5, 4, 1), // {
		BINARY_4( _,_,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,1,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,_,1,_ ),

		IMAGE_DATA(5, 1, 1), // |
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // }
		BINARY_4( 1,_,_,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( _,1,1,_ ),
		BINARY_4( _,1,_,_ ),
		BINARY_4( 1,_,_,_ ),

		IMAGE_DATA(5, 4, 1), // ~
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,1,_,1 ),
		BINARY_4( 1,_,1,_ ),
		BINARY_4( _,_,_,_ ),
		BINARY_4( _,_,_,_ ),


};

byte arrowhead_up_image_data[] = {
		IMAGE_DATA(4, 7, 1),
		BINARY_8( _,_,_,1,_,_,_,_ ),
		BINARY_8( _,_,1,1,1,_,_,_ ),
		BINARY_8( _,1,1,1,1,1,_,_ ),
		BINARY_8( 1,1,1,1,1,1,1,_ ),
};

byte arrowhead_down_image_data[] = {
		IMAGE_DATA(4, 7, 1),
		BINARY_8( 1,1,1,1,1,1,1,_ ),
		BINARY_8( _,1,1,1,1,1,_,_ ),
		BINARY_8( _,_,1,1,1,_,_,_ ),
		BINARY_8( _,_,_,1,_,_,_,_ ),
};

byte arrowhead_left_image_data[] = {
		IMAGE_DATA(5, 3, 1),
		BINARY_8( _,_,1,_,_,_,_,_ ),
		BINARY_8( _,1,1,_,_,_,_,_ ),
		BINARY_8( 1,1,1,_,_,_,_,_ ),
		BINARY_8( _,1,1,_,_,_,_,_ ),
		BINARY_8( _,_,1,_,_,_,_,_ ),
};

byte arrowhead_right_image_data[] = {
		IMAGE_DATA(5, 3, 1),
		BINARY_8( 1,_,_,_,_,_,_,_ ),
		BINARY_8( 1,1,_,_,_,_,_,_ ),
		BINARY_8( 1,1,1,_,_,_,_,_ ),
		BINARY_8( 1,1,_,_,_,_,_,_ ),
		BINARY_8( 1,_,_,_,_,_,_,_ ),
};


#undef _
#undef WORD
#undef IMAGE_DATA
#undef BINARY_8
#undef BINARY_4
