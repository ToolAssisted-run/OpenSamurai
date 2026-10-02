// The in-game menu's port library (text.h): SDLPoP2's source/text.c (its ports, rectangles, fonts, word wrapping and
// justification, the rules of PoP2's 194C library at 194C:64FE / 537A), without the game's parts.
#include <stdlib.h>
#include <string.h>

#include "text.h"

const qrect rect_screen = { 0, 0, 200, 320 };
gport *the_port;

gport *port_new(const qrect *r)
{
  gport *p = calloc(1, sizeof *p);
  p->bits = calloc(SCREEN_W, SCREEN_H);
  p->origin_v = r->top, p->origin_h = r->left;
  p->clip = *r;
  p->fg = 0xF;
  return p;
}
void port_free(gport *p)
{
  if (!p) return;
  if (the_port == p) the_port = NULL;
  free(p->bits);
  free(p);
}

static int sect(const qrect *a, const qrect *b, qrect *o)
{
  o->top = a->top > b->top ? a->top : b->top, o->bottom = a->bottom < b->bottom ? a->bottom : b->bottom;
  o->left = a->left > b->left ? a->left : b->left, o->right = a->right < b->right ? a->right : b->right;
  return o->top < o->bottom && o->left < o->right;
}
static inline uint8_t *pix(gport *p, int v, int h) { return p->bits + (v - p->origin_v) * SCREEN_W + (h - p->origin_h); }

void gfx_fill_rect(int color, const qrect *r)
{
  qrect c;
  if (!sect(r, &the_port->clip, &c)) return;
  for (int v = c.top; v < c.bottom; v++) memset(pix(the_port, v, c.left), color, (size_t)(c.right - c.left));
}
// the top and bottom lines, then the left and right columns between them
void gfx_frame_rect(const qrect *r)
{
  int c = the_port->fg;
  qrect d = *r;
  if (r->top + 1 > r->bottom) return;
  if (r->top + 1 != r->bottom) d.bottom = (int16_t)(r->top + 1), gfx_fill_rect(c, &d);
  d.bottom = r->bottom, d.top = (int16_t)(r->bottom - 1), gfx_fill_rect(c, &d);
  d.top = (int16_t)(r->top + 1), d.bottom = (int16_t)(r->bottom - 1);
  if (r->left + 1 > r->right) return;
  if (r->left + 1 != r->right) d.left = r->left, d.right = (int16_t)(r->left + 1), gfx_fill_rect(c, &d);
  d.right = r->right, d.left = (int16_t)(r->right - 1), gfx_fill_rect(c, &d);
}
void gfx_move_to(int v, int h) { the_port->pen_v = (int16_t)v, the_port->pen_h = (int16_t)h; }

static const uint8_t *added_font[4];
static uint16_t added_id[4];
void gfx_add_font(uint16_t id, const uint8_t *data)
{
  for (int i = 0; i < 4; i++)
    if (!added_font[i] || added_id[i] == id)
    {
      added_font[i] = data, added_id[i] = id;
      return;
    }
}
static const uint8_t *font_data(uint16_t id)
{
  for (int i = 0; i < 4 && added_font[i]; i++)
    if (added_id[i] == id) return added_font[i];
  return NULL;
}
static int16_t rd16s(const uint8_t *p) { return (int16_t)(p[0] | p[1] << 8); }
void gfx_text_font(uint16_t id) { the_port->font = id; }
static const uint8_t *glyph(const uint8_t *f, uint8_t c)
{
  if (!f || c > f[1] || c < f[0]) return NULL;
  return f + (uint16_t)rd16s(f + 10 + (c - f[0]) * 2);
}
int gfx_text_width(const char *s, int n)
{
  const uint8_t *f = font_data(the_port->font), *g;
  int w = 0;
  for (int i = 0; i < n; i++)
    if ((g = glyph(f, (uint8_t)s[i]))) w += rd16s(g + 2) + rd16s(f + 8);
  return w;
}
static void draw_glyph(const uint8_t *g, int top, int left, int color)
{
  int h = rd16s(g), w = rd16s(g + 2), bpr = (w + 7) / 8;
  const uint8_t *rows = g + 6;
  for (int y = 0; y < h; y++)
  {
    int v = top + y;
    if (v < the_port->clip.top || v >= the_port->clip.bottom) continue;
    for (int x = 0; x < w; x++)
    {
      int hh = left + x;
      if (hh < the_port->clip.left || hh >= the_port->clip.right) continue;
      if (rows[y * bpr + (x >> 3)] & (0x80 >> (x & 7))) *pix(the_port, v, hh) = (uint8_t)color;
    }
  }
}
int gfx_draw_text(const char *s, int n)
{
  const uint8_t *f = font_data(the_port->font), *g;
  int h0 = the_port->pen_h;
  if (!f) return 0;
  int top = the_port->pen_v - rd16s(f + 2);
  for (int i = 0; i < n; i++)
    if ((g = glyph(f, (uint8_t)s[i])))
    {
      int x = the_port->pen_h;
      the_port->pen_h = (int16_t)(the_port->pen_h + rd16s(g + 2) + rd16s(f + 8));
      draw_glyph(g, top, x, the_port->fg);
    }
  return the_port->pen_h - h0;
}
void gfx_draw_string(const char *s) { gfx_draw_text(s, (int)strlen(s)); }
// how many characters of s fit in `width` (a break after '\r', '-', or at a space)
static int line_break(int hjust, int width, int n, const char *s)
{
  int di = 0, brk = 0, w = 0;
  while (di != n)
  {
    w += gfx_text_width(s + di, 1);
    if (w > width) return brk ? brk : di;
    char c = s[di++];
    if (c == '\r') return di;
    if (c == '-')
    {
      brk = di;
      continue;
    }
    if (hjust > 0)
    {
      if (s[di] == ' ' && c != ' ') brk = di;
    }
    else if (c == ' ' || s[di] == ' ')
      brk = di;
  }
  return di;
}
void gfx_text_box(const char *s, int n, int vjust, int hjust, const qrect *r)
{
  int save_v = the_port->pen_v, save_h = the_port->pen_h;
  int W = r->right - r->left, H = r->bottom - r->top, nl = 0;
  const char *line[64];
  int len[64];
  const char *p = s;
  int left = n;
  while (left > 0 && nl < 64)
  {
    int k = line_break(hjust, W, left, p);
    if (!k) break;
    line[nl] = p, len[nl] = k, nl++;
    p += k, left -= k;
  }
  const uint8_t *f = font_data(the_port->font);
  if (!f) return;
  int lh = rd16s(f + 2) + rd16s(f + 4) + rd16s(f + 6);
  unsigned total = (unsigned)(lh * nl - rd16s(f + 6));
  int v = r->top;
  if (vjust == 0) v = r->top + (H >> 1) + (H & 1) - (int)(total >> 1) - (int)(total & 1);
  else if (vjust > 0) v = r->top + H - (int)total;
  the_port->pen_v = (int16_t)(v + rd16s(f + 2));
  for (int i = 0; i < nl; i++)
  {
    const char *q = line[i];
    int m = len[i];
    if (hjust < 0 && q != s && q[0] == ' ' && q[-1] != '\r')  // a left-justified line does not start with its space
    {
      q++, m--;
      if (m && q[0] == ' ' && q[-2] == '.') q++, m--;
    }
    unsigned w = (unsigned)gfx_text_width(q, m);
    int h = r->left;
    if (hjust == 0) h = r->left + (W >> 1) - (int)(w >> 1);
    else if (hjust > 0) h = r->left + W - (int)w;
    the_port->pen_h = (int16_t)h;
    gfx_draw_text(q, m);
    the_port->pen_v = (int16_t)(the_port->pen_v + lh);
  }
  the_port->pen_v = (int16_t)save_v, the_port->pen_h = (int16_t)save_h;
}
void gfx_text_box_str(const char *s, int vjust, int hjust, const qrect *r) { gfx_text_box(s, (int)strlen(s), vjust, hjust, r); }
