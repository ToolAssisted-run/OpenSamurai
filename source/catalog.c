// The game's resource catalogs. Format (from the files themselves, checked against every entry of the four
// catalogs): uint16 count, then count entries of 24 bytes: char name[12] (NUL padded), uint16 DOS time,
// uint16 DOS date, uint32 size, uint32 offset; the entries' bytes follow, in table order, without gaps.
#include "catalog.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRY_BYTES 24

static uint16_t rd16(const uint8_t *p) { return (uint16_t)(p[0] | (p[1] << 8)); }
static uint32_t rd32(const uint8_t *p) { return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24); }

int catalog_load(Catalog *cat, const char *path)
{
  memset(cat, 0, sizeof *cat);
  FILE *f = fopen(path, "rb");
  if (!f) return -1;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  if (n < 2) { fclose(f); return -1; }
  cat->file = malloc((size_t)n);
  cat->fileSize = (size_t)n;
  if (!cat->file || fread(cat->file, 1, cat->fileSize, f) != cat->fileSize) { fclose(f); catalog_free(cat); return -1; }
  fclose(f);

  cat->count = rd16(cat->file);
  if (2 + (size_t)cat->count * ENTRY_BYTES > cat->fileSize) { catalog_free(cat); return -1; }
  cat->entries = calloc((size_t)cat->count, sizeof *cat->entries);
  if (!cat->entries) { catalog_free(cat); return -1; }
  for (int i = 0; i < cat->count; i++)
  {
    const uint8_t *e = cat->file + 2 + i * ENTRY_BYTES;
    CatEntry *d = &cat->entries[i];
    memcpy(d->name, e, 12);
    d->name[12] = 0;
    d->time = rd16(e + 12);
    d->date = rd16(e + 14);
    d->size = rd32(e + 16);
    d->offset = rd32(e + 20);
    if ((size_t)d->offset + d->size > cat->fileSize) { catalog_free(cat); return -1; }
  }
  return 0;
}

void catalog_free(Catalog *cat)
{
  free(cat->entries);
  free(cat->file);
  memset(cat, 0, sizeof *cat);
}

const CatEntry *catalog_find(const Catalog *cat, const char *name)
{
  for (int i = 0; i < cat->count; i++)
  {
    const char *a = cat->entries[i].name, *b = name;
    while (*a && *b && toupper((unsigned char)*a) == toupper((unsigned char)*b)) a++, b++;
    if (!*a && !*b) return &cat->entries[i];
  }
  return NULL;
}

const uint8_t *catalog_data(const Catalog *cat, const CatEntry *entry) { return cat->file + entry->offset; }
