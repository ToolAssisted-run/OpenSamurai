// OpenSamurai.ini: the defaults and the parser (settings.h), SDLPoP2's (its source/settings.c) with OpenSamurai's options.
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "settings.h"

const char settings_sound_letters[SOUND_COUNT + 1] = "ARITN";

void settings_defaults(os_settings *s)
{
  memset(s, 0, sizeof *s);
  s->use_correct_aspect_ratio = 1, s->scaling_type = SCALING_SHARP;
  s->sound = SOUND_ADLIB, s->volume = 15;
  s->enable_joystick = 1;
  s->random_seed_clock = 1;
}

typedef enum { T_BOOL, T_INT, T_SIZE, T_STR, T_SCALING, T_SOUND, T_SEED } ftype;
typedef struct
{
  const char *section, *key;
  ftype type;
  size_t off, size;
  int min, max;
} field;
#define F(sec, name, t, lo, hi) { sec, #name, t, offsetof(os_settings, name), sizeof((os_settings *)0)->name, lo, hi }
static const field fields[] = {
  F("General", start_fullscreen, T_BOOL, 0, 1),
  F("General", window_width, T_SIZE, 0, 16384),
  F("General", window_height, T_SIZE, 0, 16384),
  F("General", use_correct_aspect_ratio, T_BOOL, 0, 1),
  F("General", use_integer_scaling, T_BOOL, 0, 1),
  F("General", scaling_type, T_SCALING, 0, 2),
  F("General", sound, T_SOUND, 0, SOUND_COUNT - 1),
  F("General", volume, T_INT, 0, 15),
  F("General", mt32_roms, T_STR, 0, 0),
  F("General", skip_title, T_BOOL, 0, 1),
  F("Controller", enable_joystick, T_BOOL, 0, 1),
  F("AdditionalFeatures", random_seed, T_SEED, 0, 0),
};
#define NFIELDS (int)(sizeof fields / sizeof fields[0])
static const char *const sound_names[SOUND_COUNT] = { "adlib", "mt32", "speaker", "tandy", "none" };

static void warn_default(const char *m) { fprintf(stderr, "%s\n", m); }
static int ieq(const char *a, const char *b)
{
  while (*a && *b && tolower((unsigned char)*a) == tolower((unsigned char)*b)) a++, b++;
  return !*a && !*b;
}
static int parse_int(const char *v, long *out)
{
  char *end;
  long n = strtol(v, &end, 0);
  if (end == v || *end) return 0;
  *out = n;
  return 1;
}
static int parse_bool(const char *v, int *out)
{
  if (ieq(v, "true") || ieq(v, "yes") || ieq(v, "on") || !strcmp(v, "1")) return *out = 1, 1;
  if (ieq(v, "false") || ieq(v, "no") || ieq(v, "off") || !strcmp(v, "0")) return *out = 0, 1;
  return 0;
}
// one field from its text; 0 for a bad value
static int set_field(os_settings *s, const os_settings *d, const field *f, const char *v)
{
  char *p = (char *)s + f->off;
  if (ieq(v, "default"))
  {
    memcpy(p, (const char *)d + f->off, f->size);
    if (f->type == T_SEED) s->random_seed_clock = d->random_seed_clock;
    return 1;
  }
  long n;
  int b;
  switch (f->type)
  {
  case T_BOOL:
    if (!parse_bool(v, &b)) return 0;
    *(int *)p = b;
    return 1;
  case T_SIZE:
    if (ieq(v, "auto")) return *(int *)p = 0, 1;
    // fall through
  case T_INT:
    if (!parse_int(v, &n) || n < f->min || n > f->max) return 0;
    *(int *)p = (int)n;
    return 1;
  case T_STR: snprintf(p, f->size, "%s", v); return 1;
  case T_SCALING:
    if (ieq(v, "sharp")) b = SCALING_SHARP;
    else if (ieq(v, "fuzzy")) b = SCALING_FUZZY;
    else if (ieq(v, "blurry")) b = SCALING_BLURRY;
    else return 0;
    *(int *)p = b;
    return 1;
  case T_SOUND:
    for (b = 0; b < SOUND_COUNT; b++)
      if (ieq(v, sound_names[b])) return *(int *)p = b, 1;
    return 0;
  case T_SEED:
    if (ieq(v, "clock")) return s->random_seed_clock = 1, s->random_seed = 0, 1;
    {
      char *end;
      unsigned long long u = strtoull(v, &end, 0);
      if (end == v || *end || v[0] == '-') return 0;
      s->random_seed_clock = 0, s->random_seed = u;
      return 1;
    }
  }
  return 0;
}
static char *trim(char *s)
{
  while (isspace((unsigned char)*s)) s++;
  char *e = s + strlen(s);
  while (e > s && isspace((unsigned char)e[-1])) *--e = 0;
  return s;
}

int settings_parse_text(os_settings *s, const char *text, const char *origin, settings_warn_fn warn)
{
  if (!warn) warn = warn_default;
  os_settings d;
  settings_defaults(&d);
  char section[64] = "", msg[512];
  int nwarn = 0, lineno = 0;
#define WARN(...) do { snprintf(msg, sizeof msg, __VA_ARGS__); warn(msg); nwarn++; } while (0)
  while (*text)
  {
    char line[1024];
    size_t n = strcspn(text, "\n"), k = n < sizeof line - 1 ? n : sizeof line - 1;
    memcpy(line, text, k), line[k] = 0;
    text += n;
    if (*text) text++;
    lineno++;
    char *c = strchr(line, ';');  // comments, also after a value
    if (c) *c = 0;
    char *l = trim(line);
    if (!*l) continue;
    if (*l == '[')
    {
      char *e = strchr(l, ']');
      if (!e)
      {
        WARN("%s:%d: bad section line", origin, lineno);
        section[0] = 0;
        continue;
      }
      *e = 0;
      snprintf(section, sizeof section, "%s", trim(l + 1));
      if (strcmp(section, "General") && strcmp(section, "Controller") && strcmp(section, "AdditionalFeatures"))
      {
        WARN("%s:%d: unknown section [%s]", origin, lineno, section);
        section[0] = 0;
      }
      continue;
    }
    char *eq = strchr(l, '=');
    if (!eq)
    {
      WARN("%s:%d: expected key = value", origin, lineno);
      continue;
    }
    *eq = 0;
    char *key = trim(l), *val = trim(eq + 1);
    if (!section[0])
    {
      WARN("%s:%d: '%s' outside a known section", origin, lineno, key);
      continue;
    }
    int ok = -1;  // -1 an unknown key, 0 a bad value, 1 set
    for (int i = 0; i < NFIELDS && ok < 0; i++)
      if (!strcmp(section, fields[i].section) && !strcmp(key, fields[i].key)) ok = set_field(s, &d, &fields[i], val);
    if (ok < 0) WARN("%s:%d: unknown option '%s' in [%s]", origin, lineno, key, section);
    else if (ok == 0) WARN("%s:%d: bad value '%s' for '%s' (kept as it was)", origin, lineno, val, key);
  }
#undef WARN
  return nwarn;
}

int settings_load(os_settings *s, const char *path, settings_warn_fn warn)
{
  FILE *f = fopen(path, "rb");
  if (!f) return 0;
  size_t cap = 1 << 16, n = 0;
  char *buf = malloc(cap);
  for (size_t r; buf && (r = fread(buf + n, 1, cap - n - 1, f)) > 0;)
  {
    n += r;
    if (n + 1 >= cap)
    {
      char *b = realloc(buf, cap *= 2);
      if (!b) free(buf);
      buf = b;
    }
  }
  fclose(f);
  if (!buf) return 0;
  buf[n] = 0;
  settings_parse_text(s, buf, path, warn);
  free(buf);
  return 1;
}
