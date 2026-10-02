// OpenSamurai.ini: the frontend's settings (see the file itself for every option). The parser and the defaults use no
// SDL. Every default is what OpenSamurai does without the file; the command line's options (the original setup's) win
// over the file's.
#ifndef OPENSAMURAI_SETTINGS_H
#define OPENSAMURAI_SETTINGS_H

#include <stdint.h>

enum { SCALING_SHARP, SCALING_FUZZY, SCALING_BLURRY };
// the setup's sound drivers, in the menu's order; their letters (the setup's /A<letter>): "ARITN"
enum { SOUND_ADLIB, SOUND_MT32, SOUND_SPEAKER, SOUND_TANDY, SOUND_NONE, SOUND_COUNT };
extern const char settings_sound_letters[SOUND_COUNT + 1];

typedef struct os_settings
{
  // [General]
  int start_fullscreen;
  int window_width, window_height;  // 0: auto
  int use_correct_aspect_ratio;     // 1: 4:3 (mode 13h on a monitor of the time)
  int use_integer_scaling;
  int scaling_type;                 // SCALING_*
  int sound;                        // SOUND_*: the setup's sound driver (at the start)
  int volume;                       // 0..15
  char mt32_roms[256];              // the MT-32's ROMs' folder ("": the default places)
  int skip_title;                   // /NT (at the start)
  // [Controller]
  int enable_joystick;              // a joystick or game controller is the game's joystick (/J, /NJ; at the start)
  // [AdditionalFeatures]
  int random_seed_clock;            // the seed: the clock's, or a number (at the start)
  uint64_t random_seed;
} os_settings;

void settings_defaults(os_settings *s);
// warn: called with a message for each unknown section, key or bad value
typedef void (*settings_warn_fn)(const char *msg);
int settings_load(os_settings *s, const char *path, settings_warn_fn warn);  // 0: the file could not be read
int settings_parse_text(os_settings *s, const char *text, const char *origin, settings_warn_fn warn);  // -> warnings

#endif
