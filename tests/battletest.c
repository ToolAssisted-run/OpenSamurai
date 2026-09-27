// battletest STEPS.snap EVENTS.txt [step|run]: the battle against a capture of the real game.
// STEPS.snap holds BATTLE's whole data segment at the top of every simulation step (a probe at 1000:00A9);
// EVENTS.txt the probe log of the unit passes (1000:0170, where the input handler is called after each
// pass) and of every key the battle consumed (1000:3935, ax = the key), in execution order: a key belongs to
// the step and pass of the last pass event before it.
//   step: every step from the capture's own state, compared with the next capture (the default)
//   run:  from the first step only, free-running on the captured keys
#include "battle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { uint32_t frame; uint8_t *data; } Sample;
typedef struct { uint32_t len; int count; Sample *s; } Snap;

static int load_snap(Snap *sn, const char *path)
{
  FILE *f = fopen(path, "rb");
  if (!f) return -1;
  char magic[4];
  if (fread(magic, 1, 4, f) != 4 || memcmp(magic, "SNP1", 4) || fread(&sn->len, 4, 1, f) != 1) { fclose(f); return -1; }
  sn->count = 0; sn->s = NULL;
  for (;;)
  {
    uint32_t fr;
    if (fread(&fr, 4, 1, f) != 1) break;
    uint8_t *d = malloc(sn->len);
    if (fread(d, 1, sn->len, f) != sn->len) { free(d); break; }
    sn->s = realloc(sn->s, sizeof(Sample) * (sn->count + 1));
    sn->s[sn->count++] = (Sample){ fr, d };
  }
  fclose(f);
  return 0;
}

static int16_t W(const uint8_t *ds, int off) { return (int16_t)(ds[off] | (ds[off + 1] << 8)); }

static void from_ds(BattleState *b, const uint8_t *ds)
{
  memset(b, 0, sizeof *b);
  memcpy(b->terrain, ds + 0x4A60, sizeof b->terrain);
  memcpy(b->visible, ds + 0x68A2, sizeof b->visible);
  for (int i = 0; i < BATTLE_RECORDS; i++)
  {
    int16_t *w = (int16_t *)&b->u[i];
    for (int k = 0; k < 32; k++) w[k] = W(ds, 0x5E2A + 0x40 * i + 2 * k);
  }
  b->rng = (uint16_t)W(ds, 0x1712) | ((uint32_t)(uint16_t)W(ds, 0x1714) << 16);
#define G(field, off) b->field = W(ds, off)
  G(running, 0x5C18); G(enemyMen, 0x5C1A); G(playerColumn, 0x5E1C); G(cga, 0x5E1E); G(general[0], 0x5E20); G(general[1], 0x5E22);
  G(enemySize, 0x5E24); G(playerMirror, 0x5E26); G(records, 0x5E28); G(enemyColumn, 0x646A); G(enemyFormation, 0x646C);
  G(retreat, 0x646E); G(cursorColour, 0x6472); G(enemyHasUnits, 0x6674); G(playerVariant, 0x6676); G(generalship[0], 0x6678);
  G(generalship[1], 0x667A); G(rank, 0x667C); G(playerGeneralship, 0x667E); G(playerHasUnits, 0x6680); G(playerMen, 0x6682);
  G(centreX, 0x6684); G(over, 0x6686); G(units, 0x6688); G(playerSize, 0x668A); G(centreY, 0x668C); G(enemyGeneralship, 0x6692);
  G(enemyVariant, 0x6694); G(enemyMirror, 0x6696); G(castle, 0x6698); G(playerFormation, 0x669E); G(difficultyBonus, 0x66A0);
  G(enemyRank, 0x7A5A); G(cursorX, 0x169C); G(cursorY, 0x169E); G(lastJoystickKey, 0x167A); G(cursorBlink, 0x16CA);
  G(pendingKey, 0x26D4); G(joystickButtons, 0x26D6); G(groupSpeed, 0x26D8); G(jingleBand, 0x26EA);
  static const int cornerOff[8] = { 0x26B4, 0x26B6, 0x26BA, 0x26BE, 0x26B8, 0x26BC, 0x26C0, 0x26C2 };
  for (int k = 0; k < 8; k++) b->corners[k] = W(ds, cornerOff[k]);
  for (int k = 0; k < 4; k++) { b->boxB[k] = W(ds, 0x26C4 + 2 * k); b->boxA[k] = W(ds, 0x26CC + 2 * k); }
  for (int k = 0; k < 5; k++) { b->rayDist[k] = W(ds, 0x26DA + 2 * k); b->rayId[k] = (int8_t)ds[0x26E4 + k]; }
#undef G
  int16_t sel = W(ds, 0x169A);
  b->selected = sel == 0 ? 0 : (int16_t)((sel - 0x5E2A) / 0x40);
}

static const char *fieldName[32] = { "id", "state", "flags", "men", "facing", "x", "y", "destX", "destY", "destFacing", "contactX",
  "contactY", "blocker", "terrainMod", "spriteBase", "target", "speed", "turnRate", "pendingTurn", "counter", "phase", "damage",
  "open", "morale", "effMorale", "unused32", "initialMen", "reactMen", "projectile", "wp2X", "wp2Y", "wp2Facing" };

static int compare(const BattleState *c, const BattleState *g, int step, int quiet)
{
  int bad = 0;
  for (int i = 1; i <= g->records && i < BATTLE_RECORDS; i++)
  {
    const int16_t *a = (const int16_t *)&c->u[i], *w = (const int16_t *)&g->u[i];
    for (int k = 0; k < 32; k++)
      if (a[k] != w[k] && k != 14)  // the sprite base is a drawing handle
      {
        if (!quiet) printf("  step %d: unit %d %s C %d, game %d\n", step, i, fieldName[k], a[k], w[k]);
        bad++;
      }
  }
  int vis = 0;
  for (int k = 0; k < BATTLE_MAP_W * BATTLE_MAP_H; k++) vis += c->visible[k] != g->visible[k];
  if (vis) { if (!quiet) printf("  step %d: %d visibility cells differ\n", step, vis); bad++; }
#define CMP(field) do { if (c->field != g->field) { if (!quiet) printf("  step %d: " #field " C %d, game %d\n", step, (int)c->field, (int)g->field); bad++; } } while (0)
  CMP(rng); CMP(selected); CMP(cursorX); CMP(cursorY); CMP(cursorBlink); CMP(groupSpeed); CMP(over); CMP(playerHasUnits);
  CMP(enemyHasUnits); CMP(retreat); CMP(jingleBand); CMP(centreX); CMP(centreY);
  for (int k = 0; k < 8; k++) CMP(corners[k]);
  for (int k = 0; k < 4; k++) { CMP(boxA[k]); CMP(boxB[k]); }
  for (int k = 0; k < 5; k++) { CMP(rayDist[k]); CMP(rayId[k]); }
#undef CMP
  return bad;
}

int main(int argc, char **argv)
{
  if (argc < 3) { fprintf(stderr, "usage: battletest STEPS.snap EVENTS.txt [step|run]\n"); return 2; }
  Snap st;
  if (load_snap(&st, argv[1])) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
  FILE *ev = fopen(argv[2], "r");
  if (!ev) { fprintf(stderr, "cannot read %s\n", argv[2]); return 2; }
  int run = argc > 3 && !strcmp(argv[3], "run");
  BattleKeys *keys = calloc(st.count + 1, sizeof *keys);
  char line[512];
  int passes = 0;
  while (fgets(line, sizeof line, ev))
  {
    if (strstr(line, " bt_pass ")) passes++;
    else if (strstr(line, " bt_key ") && passes > 0)
    {
      unsigned ax = 0;
      char *p = strstr(line, "ax=");
      if (p) sscanf(p + 3, "%x", &ax);
      int step = (passes - 1) / 5, pass = (passes - 1) % 5;
      if (step < st.count && keys[step].count < 64) keys[step].k[keys[step].count++] = (typeof(keys[0].k[0])){ pass, (uint16_t)ax };
    }
  }
  fclose(ev);
  int bad = 0, shown = 0;
  BattleState b, want;
  from_ds(&b, st.s[0].data);
  for (int k = 0; k + 1 < st.count; k++)
  {
    if (!run) from_ds(&b, st.s[k].data);
    battle_step(&b, &keys[k]);
    from_ds(&want, st.s[k + 1].data);
    int n = compare(&b, &want, k + 1, shown >= 6);
    if (n)
    {
      bad++;
      if (shown++ < 6) printf("step %d (video %u) differs in %d fields\n", k + 1, st.s[k + 1].frame, n);
      if (run) break;
    }
  }
  printf("%s: %d steps, %d differ (%s)\n", argv[1], st.count, bad, run ? "run" : "step");
  return bad != 0;
}
