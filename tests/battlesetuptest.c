// battlesetuptest SETUP.snap STEPS.snap SEEDS.txt: the battle's set-up against a capture of the real game.
// SETUP.snap: the data segment when the formation screen starts (1000:004D), after the battlefield loop in
// main (generate from the BIOS tick, let the enemy general choose, again while every choice is rejected);
// SEEDS.txt: the tick each generation started from (a probe at 1000:51DE sampling 0040:006C); STEPS.snap:
// the first simulation step, after the player's formation choice. Checked: the terrain map, the random
// numbers, the enemy's formation and the candidate armies it placed, then the two armies as placed for
// the battle (before any step ran).
#include "battle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_first(const char *path, uint32_t *len)
{
  FILE *f = fopen(path, "rb");
  if (!f) return NULL;
  char magic[4];
  uint32_t fr;
  if (fread(magic, 1, 4, f) != 4 || memcmp(magic, "SNP1", 4) || fread(len, 4, 1, f) != 1 || fread(&fr, 4, 1, f) != 1) { fclose(f); return NULL; }
  uint8_t *d = malloc(*len);
  if (fread(d, 1, *len, f) != *len) { free(d); d = NULL; }
  fclose(f);
  return d;
}

static int16_t W(const uint8_t *ds, int off) { return (int16_t)(ds[off] | (ds[off + 1] << 8)); }

static void unit_from(BattleUnit *u, const uint8_t *ds, int i)
{
  int16_t *w = (int16_t *)u;
  for (int k = 0; k < 32; k++) w[k] = W(ds, 0x5E2A + 0x40 * i + 2 * k);
}

static int compare_units(const BattleState *b, const uint8_t *ds, int n, const char *what, int skipPass)
{
  int bad = 0;
  for (int i = 1; i <= n; i++)
  {
    BattleUnit g;
    unit_from(&g, ds, i);
    const int16_t *a = (const int16_t *)&b->u[i], *w = (const int16_t *)&g;
    for (int k = 0; k < 32; k++)
    {
      if (k == 14) continue;  // sprite base: a drawing handle
      if (skipPass && (k == 10 || k == 11 || k == 12 || k == 24)) continue;  // contact point, blocker, effective morale: stale values
      if (a[k] != w[k])
      {
        if (bad < 12) printf("  %s: unit %d word %d (+%02X) C %d, game %d\n", what, i, k, 2 * k, a[k], w[k]);
        bad++;
      }
    }
  }
  return bad;
}

int main(int argc, char **argv)
{
  if (argc < 4) { fprintf(stderr, "usage: battlesetuptest SETUP.snap STEPS.snap SEEDS.txt\n"); return 2; }
  uint32_t len, len2;
  uint8_t *setup = load_first(argv[1], &len), *step = load_first(argv[2], &len2);
  FILE *sf = fopen(argv[3], "r");
  if (!setup || !step || !sf) { fprintf(stderr, "cannot read the capture\n"); return 2; }
  uint32_t seeds[16];
  int nseeds = 0;
  char line[512];
  while (fgets(line, sizeof line, sf) && nseeds < 16)
  {
    char *p = strstr(line, "mem=");
    unsigned b0, b1, b2, b3;
    if (p && sscanf(p + 4, "%2x%2x%2x%2x", &b0, &b1, &b2, &b3) == 4) seeds[nseeds++] = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
  }
  fclose(sf);
  if (nseeds == 0) { fprintf(stderr, "no seed\n"); return 2; }

  // the parameters as the program derived them, from the snapshot
  BattleState b;
  memset(&b, 0, sizeof b);
#define G(field, off) b.field = W(setup, off)
  G(rank, 0x667C); G(playerGeneralship, 0x667E); G(playerSize, 0x668A); G(playerColumn, 0x5E1C); G(playerVariant, 0x6676);
  G(enemyRank, 0x7A5A); G(difficultyBonus, 0x66A0); G(enemyGeneralship, 0x6692); G(enemySize, 0x5E24); G(enemyColumn, 0x646A);
  G(enemyVariant, 0x6694); G(generalship[0], 0x6678); G(generalship[1], 0x667A); G(playerMen, 0x6682); G(enemyMen, 0x5C1A);
  G(playerFormation, 0x669E); G(castle, 0x6698); G(cga, 0x5E1E);
#undef G
  int attempt = 0;
  do battle_generate_terrain(&b, seeds[attempt]);
  while (!battle_choose_enemy_formation(&b) && ++attempt < nseeds);
  int bad = 0;
  int terr = 0;
  for (int k = 0; k < BATTLE_MAP_W * BATTLE_MAP_H; k++) terr += b.terrain[k] != (int8_t)setup[0x4A60 + k];
  if (terr) { printf("  %d terrain cells differ\n", terr); bad++; }
  uint32_t rng = (uint16_t)W(setup, 0x1712) | ((uint32_t)(uint16_t)W(setup, 0x1714) << 16);
  if (b.rng != rng) { printf("  rng C %08X, game %08X\n", b.rng, rng); bad++; }
  if (b.enemyFormation != W(setup, 0x646C) || b.enemyMirror != W(setup, 0x6696))
  {
    printf("  enemy formation C %d/%d, game %d/%d\n", b.enemyFormation, b.enemyMirror, W(setup, 0x646C), W(setup, 0x6696));
    bad++;
  }
  if (b.units != W(setup, 0x6688)) { printf("  candidate units C %d, game %d\n", b.units, W(setup, 0x6688)); bad++; }
  else bad += compare_units(&b, setup, b.units, "candidates", 1) != 0;

  // the battle's armies with the player's choice
  b.playerFormation = W(step, 0x669E);
  b.playerMirror = W(step, 0x5E26);
  battle_place_armies(&b);
  battle_setup_frame(&b);
  if (b.records != W(step, 0x5E28)) { printf("  records C %d, game %d\n", b.records, W(step, 0x5E28)); bad++; }
  else bad += compare_units(&b, step, b.records, "armies", 1) != 0;
  printf("%s: %s (%d generation%s)\n", argv[1], bad ? "DIFFERS" : "identical", attempt + 1, attempt ? "s" : "");
  return bad != 0;
}
