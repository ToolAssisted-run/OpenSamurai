// DOS (INT 21h) for the recompiled programs: files from the game directory (read only; handles from 5 on, as
// DOS gives them), the FCB functions the disk checks use (parse a name, find it), the version, the console's
// messages, device information; the clock and kbhit are the host's answers, exit the host's.
#include "dos.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "asm2c.h"
#include "exe.h"

static const DosHost *host;
static FILE *files[20];
static int debugFiles = -1;
#define DEBUG_FILES (debugFiles < 0 ? (debugFiles = getenv("DOS_DEBUG") ? atoi(getenv("DOS_DEBUG")) : 0) : debugFiles)

void dos_attach(const DosHost *h) { host = h; }

void dos_close_all(void)
{
  for (int k = 0; k < 20; k++)
    if (files[k]) fclose(files[k]), files[k] = NULL;
}

static bool find_game_file(const char *name, char *path, size_t n)
{
  const char *dir = host && host->gameDir ? host->gameDir : ".";
  DIR *d = opendir(dir);
  if (!d) return false;
  struct dirent *e;
  bool found = false;
  while ((e = readdir(d)))
    if (!strcasecmp(e->d_name, name))
    {
      snprintf(path, n, "%s/%s", dir, e->d_name);
      found = true;
      break;
    }
  closedir(d);
  return found;
}

static FILE *open_game_file(const char *name)
{
  char path[1024];
  return find_game_file(name, path, sizeof path) ? fopen(path, "rb") : NULL;
}

static void dos_error(u16 code)
{
  R.ax = code;
  R.cf = 1;
}

static u8 upper(u8 c) { return (u8)(c >= 'a' && c <= 'z' ? c - 32 : c); }

// INT 21h 29h: DS:SI's name into the FCB at ES:DI (drive, 8 + 3 characters, blank-padded)
static void parse_fcb(void)
{
  u8 al = (u8)R.ax;
  u8 *fcb = far_ptr(R.es, R.di);
  u16 si = R.si;
  if (al & 1)
    while (*far_ptr(R.ds, si) == ' ' || *far_ptr(R.ds, si) == '\t') si++;
  bool wild = false;
  if (far_ptr(R.ds, (u16)(si + 1))[0] == ':')
  {
    fcb[0] = (u8)(upper(*far_ptr(R.ds, si)) - 'A' + 1);
    si += 2;
  }
  else if (!(al & 2)) fcb[0] = 0;
  if (!(al & 4)) memset(fcb + 1, ' ', 8);
  if (!(al & 8)) memset(fcb + 9, ' ', 3);
  int k = 0;
  for (u8 c; (c = *far_ptr(R.ds, si)) > ' ' && c != '.' && c != '/' && c != '\\'; si++)
    if (k < 8) fcb[1 + k++] = upper(c), wild |= c == '*' || c == '?';
  if (*far_ptr(R.ds, si) == '.')
  {
    si++;
    k = 0;
    for (u8 c; (c = *far_ptr(R.ds, si)) > ' ' && c != '.' && c != '/' && c != '\\'; si++)
      if (k < 3) fcb[9 + k++] = upper(c), wild |= c == '*' || c == '?';
  }
  R.si = si;
  R.ax = (u16)((R.ax & 0xFF00) | (wild ? 1 : 0));
}

// INT 21h 11h: the file of the FCB at DS:DX in the game directory (no wildcards): AL 0 found, FFh not
static void find_fcb(void)
{
  const u8 *fcb = far_ptr(R.ds, R.dx);
  char name[13];
  int k = 0;
  for (int j = 0; j < 8 && fcb[1 + j] != ' '; j++) name[k++] = (char)fcb[1 + j];
  if (fcb[9] != ' ')
  {
    name[k++] = '.';
    for (int j = 0; j < 3 && fcb[9 + j] != ' '; j++) name[k++] = (char)fcb[9 + j];
  }
  name[k] = 0;
  char path[1024];
  bool found = find_game_file(name, path, sizeof path);
  if (DEBUG_FILES) fprintf(stderr, "dos: find %s -> %s\n", name, found ? "found" : "not found");
  R.ax = (u16)((R.ax & 0xFF00) | (found ? 0x00 : 0xFF));
}

bool dos_int21(void)
{
  u8 ah = (u8)(R.ax >> 8), al = (u8)R.ax;
  if (DEBUG_FILES > 1) fprintf(stderr, "dos: int 21h AX=%04X BX=%04X CX=%04X DX=%04X\n", R.ax, R.bx, R.cx, R.dx);
  switch (ah)
  {
  case 0x07:  // a character from the keyboard (no echo): the host's
  case 0x08:
    R.ax = (u16)((R.ax & 0xFF00) | ((host && host->answer ? host->answer(host->ctx, ah) : 0) & 0xFF));
    return true;
  case 0x29:  // parse a file name into an FCB
    parse_fcb();
    return true;
  case 0x11:  // find a file (FCB)
    find_fcb();
    return true;
  case 0x4B:  // an overlay (AL 3): the executable at DS:DX loaded at the parameter block's segment (ES:BX), relocated
    if (al == 0x03)
    {
      char name[80], path[1024];
      int k = 0;
      for (; k < 79 && *far_ptr(R.ds, (u16)(R.dx + k)); k++) name[k] = (char)*far_ptr(R.ds, (u16)(R.dx + k));
      name[k] = 0;
      ExeInfo e;
      u16 seg = *(u16a *)far_ptr(R.es, R.bx);
      bool ok = find_game_file(name, path, sizeof path) && exe_load(path, seg, &e);
      if (DEBUG_FILES) fprintf(stderr, "dos: overlay %s at %04X -> %s\n", name, seg, ok ? "ok" : "not found");
      if (!ok) dos_error(2);
      else R.cf = 0;
      return true;
    }
    break;
  case 0x19:  // the current drive: C:
    R.ax = (u16)((R.ax & 0xFF00) | 2);
    return true;
  case 0x30:  // DOS's version: 5.0 (DOSBox-X's)
    R.ax = 0x0005;
    R.bx = R.cx = 0;
    return true;
  case 0x09:  // a '$' message
    if (DEBUG_FILES)
    {
      for (u16 k = R.dx; *far_ptr(R.ds, k) != '$'; k++) fputc(*far_ptr(R.ds, k), stderr);
      fputc('\n', stderr);
    }
    return true;
  case 0x2A:  // the date and the time (time())
  case 0x2C:
  {
    u32 v = host && host->answer ? host->answer(host->ctx, ah) : 0;
    R.cx = (u16)(v >> 16);
    R.dx = (u16)v;
    return true;
  }
  case 0x0B:  // a character waiting on the standard input (kbhit())
    R.ax = (u16)((R.ax & 0xFF00) | ((host && host->answer ? host->answer(host->ctx, ah) : 0) & 0xFF));
    return true;
  case 0x25:  // set an interrupt vector (the timer's, Ctrl-Break's: their handlers are the host's)
    *(u16a *)far_ptr(0, (u16)(al * 4)) = R.dx;
    *(u16a *)far_ptr(0, (u16)(al * 4 + 2)) = R.ds;
    return true;
  case 0x35:  // get one
    R.bx = *(u16a *)far_ptr(0, (u16)(al * 4));
    R.es = *(u16a *)far_ptr(0, (u16)(al * 4 + 2));
    return true;
  case 0x3D:  // open
  {
    char name[80];
    int k = 0;
    for (; k < 79 && *far_ptr(R.ds, (u16)(R.dx + k)); k++) name[k] = (char)*far_ptr(R.ds, (u16)(R.dx + k));
    name[k] = 0;
    FILE *f = open_game_file(name);
    if (DEBUG_FILES) fprintf(stderr, "dos: open %s -> %s\n", name, f ? "ok" : "not found");
    if (!f)
    {
      dos_error(2);
      return true;
    }
    for (int h = 5; h < 20; h++)
      if (!files[h])
      {
        files[h] = f;
        R.ax = (u16)h;
        R.cf = 0;
        return true;
      }
    fclose(f);
    dos_error(4);
    return true;
  }
  case 0x3E:  // close
    if (R.bx >= 20 || !files[R.bx])
    {
      if (R.bx >= 5) dos_error(6);
      else R.cf = 0;
      return true;
    }
    fclose(files[R.bx]);
    files[R.bx] = NULL;
    R.cf = 0;
    return true;
  case 0x3F:  // read
  {
    if (R.bx >= 20 || !files[R.bx])
    {
      dos_error(6);
      return true;
    }
    u16 k = 0;
    for (int c; k < R.cx && (c = fgetc(files[R.bx])) != EOF; k++) *far_ptr(R.ds, (u16)(R.dx + k)) = (u8)c;
    if (DEBUG_FILES) fprintf(stderr, "dos: read %d %04X:%04X %u -> %u\n", R.bx, R.ds, R.dx, R.cx, k);
    R.ax = k;
    R.cf = 0;
    return true;
  }
  case 0x40:  // write: the console's messages (the tests write no files)
    if (DEBUG_FILES && R.bx < 5)
      for (u16 k = 0; k < R.cx; k++) fputc(*far_ptr(R.ds, (u16)(R.dx + k)), stderr);
    R.ax = R.cx;
    R.cf = 0;
    return true;
  case 0x42:  // seek
  {
    if (R.bx >= 20 || !files[R.bx])
    {
      dos_error(6);
      return true;
    }
    long pos = (long)(((u32)R.cx << 16) | R.dx);
    fseek(files[R.bx], pos, al == 0 ? SEEK_SET : al == 1 ? SEEK_CUR : SEEK_END);
    long now = ftell(files[R.bx]);
    R.ax = (u16)now;
    R.dx = (u16)(now >> 16);
    R.cf = 0;
    return true;
  }
  case 0x44:  // device information: the console for the standard handles, a file on C: for the others
    if (al == 0x00)
    {
      R.dx = R.bx < 5 ? 0x80D3 : 0x0002;
      R.ax = R.dx;
      R.cf = 0;
      return true;
    }
    break;
  case 0x43:  // a file's attributes (the library's open(): read-only or not): an archive
    if (al == 0x00)
    {
      R.cx = 0x20;
      R.cf = 0;
      return true;
    }
    break;
  case 0x4C:  // the end
    if (host && host->exit) host->exit(al);
    return true;
  default:
    break;
  }
  return false;
}
