// cattest GAMEDIR: loads the four catalogs and checks that their entries tile the files exactly, with the
// entries the programs ask for present.
#include "catalog.h"

#include <stdio.h>
#include <string.h>

static int fails = 0;

static void check(int ok, const char *what)
{
  if (!ok) { printf("FAIL: %s\n", what); fails++; }
}

int main(int argc, char **argv)
{
  if (argc < 2) { fprintf(stderr, "usage: cattest GAMEDIR\n"); return 2; }
  static const struct { const char *file; int count; const char *mustHave; } cats[] = {
    { "RP.CAT", 165, "backgnd.pic" }, { "START.CAT", 21, "windef.dat" }, { "DUEL.CAT", 7, "plyrtops.pic" }, { "MELEE.CAT", 3, "melee0.pic" },
  };
  for (size_t i = 0; i < sizeof cats / sizeof *cats; i++)
  {
    char path[1024];
    snprintf(path, sizeof path, "%s/%s", argv[1], cats[i].file);
    Catalog cat;
    if (catalog_load(&cat, path) != 0) { printf("FAIL: cannot load %s\n", path); fails++; continue; }
    check(cat.count == cats[i].count, cats[i].file);
    // the entries follow the table in order, without gaps, up to the end of the file
    size_t pos = 2 + (size_t)cat.count * 24;
    for (int e = 0; e < cat.count; e++)
    {
      check(cat.entries[e].offset == pos, cat.entries[e].name);
      pos += cat.entries[e].size;
    }
    check(pos == cat.fileSize, "catalog end");
    check(catalog_find(&cat, cats[i].mustHave) != NULL, cats[i].mustHave);
    printf("%s: %d entries, %zu bytes\n", cats[i].file, cat.count, cat.fileSize);
    catalog_free(&cat);
  }
  printf(fails ? "%d failures\n" : "all good\n", fails);
  return fails ? 1 : 0;
}
