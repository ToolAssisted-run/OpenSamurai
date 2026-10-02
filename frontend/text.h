// The frontend's drawing for its in-game menu (overlay_menu.c): SDLPoP2's port library (its source/text.c, the part
// that is not the game's), QuickDraw-like ports (a 320 x 200 bitmap of colour indices, a clip rectangle, a pen, colours
// and a font), rectangles, and text in the PoP fonts' format. Nothing here touches the game's screen.
#ifndef OPENSAMURAI_TEXT_H
#define OPENSAMURAI_TEXT_H

#include <stdint.h>

enum { SCREEN_W = 320, SCREEN_H = 200 };

typedef struct qrect { int16_t top, left, bottom, right; } qrect;  // bottom and right exclusive

typedef struct gport
{
  uint8_t *bits;               // row 0 of the bitmap, SCREEN_W bytes a row
  int16_t origin_v, origin_h;  // the bitmap's top-left in port coordinates
  qrect clip;
  int16_t bg;                  // the erase colour
  int16_t pen_v, pen_h;        // the pen (the text's baseline)
  int16_t fg;                  // the colour of text and frames
  uint16_t font;               // a font given to gfx_add_font
} gport;

extern gport *the_port;  // the current port
extern const qrect rect_screen;  // (0, 0, 200, 320)
gport *port_new(const qrect *r);  // a port for r (colour 0, the pen at 0, fg 15)
void port_free(gport *p);

void gfx_fill_rect(int color, const qrect *r);  // (clipped to the port)
void gfx_frame_rect(const qrect *r);            // 1-pixel lines in the fg colour
void gfx_move_to(int v, int h);
void gfx_text_font(uint16_t id);
// a font under an id: [0] the first character, [1] the last, words at 2 the ascent, 4 the descent, 6 the leading, 8
// the extra advance, then a word offset per character to {height, width, flags, rows of (width + 7) / 8 bytes, high
// bit first} (the data stays the caller's)
void gfx_add_font(uint16_t id, const uint8_t *data);
int gfx_text_width(const char *s, int n);
int gfx_draw_text(const char *s, int n);  // the glyphs at the pen (on its baseline); the pen moves; -> the advance
void gfx_draw_string(const char *s);
// words wrapped into r ('\r' breaks a line); vjust / hjust < 0 top / left, 0 centre, > 0 bottom / right
void gfx_text_box(const char *s, int n, int vjust, int hjust, const qrect *r);
void gfx_text_box_str(const char *s, int vjust, int hjust, const qrect *r);

#endif
