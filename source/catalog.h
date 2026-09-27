// The game's resource catalogs (RP.CAT, START.CAT, DUEL.CAT, MELEE.CAT): a count, a table of entries and the
// files' bytes one after another.
#ifndef OPENSAMURAI_CATALOG_H
#define OPENSAMURAI_CATALOG_H

#include <stddef.h>
#include <stdint.h>

typedef struct
{
  char     name[13];  // 8.3 name, NUL terminated (the file stores 12 bytes, NUL padded)
  uint16_t time;      // DOS time and date of the packed file
  uint16_t date;
  uint32_t size;      // bytes
  uint32_t offset;    // from the start of the catalog file
} CatEntry;

typedef struct
{
  int       count;
  CatEntry *entries;
  uint8_t  *file;     // the whole catalog file
  size_t    fileSize;
} Catalog;

// Reads a catalog file. Returns 0 on success, -1 if the file cannot be read or is not a catalog.
int catalog_load(Catalog *cat, const char *path);
void catalog_free(Catalog *cat);

// Finds an entry by name, case-insensitively (the programs ask for "player.pic", the table says "PLAYER.PIC").
const CatEntry *catalog_find(const Catalog *cat, const char *name);

// The bytes of an entry (inside the loaded file).
const uint8_t *catalog_data(const Catalog *cat, const CatEntry *entry);

#endif
