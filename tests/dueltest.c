// dueltest FRAMES.snap INPUTS.snap [step|run]: the duel against a capture of the real game.
// FRAMES.snap holds DUEL's whole data segment at the top of every iteration of the duel loop (a probe at
// 1000:20A4), INPUTS.snap the virtual joystick bytes where the loop reads them (1000:0A3E). The loop's
// locals live on the stack, inside the same segment, at fixed offsets from the loop's frame pointer.
//   step: every frame from the capture's own state, compared with the next capture (the default)
//   run:  from the first frame only, the whole duel free-running on the captured controls
#include "duel.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BP 0x6BDA  // the duel loop's frame pointer

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

static void from_ds(DuelState *d, const uint8_t *ds)
{
  for (int i = 0; i < 2; i++)
  {
    d->x[i] = W(ds, 0x4FC4 + 2 * i);
    d->y[i] = W(ds, 0x4FCE + 2 * i);
    d->state[i] = W(ds, 0x61F0 + 2 * i);
    d->wounds[i] = W(ds, 0x4DB8 + 2 * i);
    d->overshoulder[i] = W(ds, 0x4FC8 + 2 * i);
    d->target[i] = W(ds, 0x61FE + 2 * i);
    d->prev[i] = W(ds, BP - 0x6E + 2 * i);
    d->hold[i] = W(ds, BP - 0x84 + 2 * i);
    d->button[i] = W(ds, BP - 0x56 + 2 * i);
  }
  for (int k = 0; k < 16; k++)
  {
    d->history[0][k] = W(ds, BP - 0x2A + 2 * k);
    d->history[1][k] = W(ds, BP - 0x4A + 2 * k);
  }
  d->lane = W(ds, 0x4FC2);
  d->retreatFrames = W(ds, 0x4A70);
  d->result = W(ds, 0x61F4);
  d->skill = W(ds, 0x1E62);
  d->aggressionBias = W(ds, 0x4DBE);
  d->aiControlsPlayer = W(ds, 0x4A74);
  d->rng.holdrand = (uint16_t)W(ds, 0x2A66) | ((uint32_t)(uint16_t)W(ds, 0x2A68) << 16);
  d->frame = (uint16_t)W(ds, BP - 0x08);
  d->aiMode = W(ds, BP - 0x80);
}

// Fields compared (the ones that carry over to the next frame)
static int compare(const DuelState *a, const DuelState *b, int frameNo, int quiet)
{
  int bad = 0;
#define CMP(field) do { if (a->field != b->field) { if (!quiet) printf("  frame %d: " #field " C %d, game %d\n", frameNo, (int)a->field, (int)b->field); bad++; } } while (0)
  for (int i = 0; i < 2; i++)
  {
    CMP(x[i]); CMP(y[i]); CMP(state[i]); CMP(wounds[i]); CMP(overshoulder[i]); CMP(prev[i]); CMP(hold[i]); CMP(button[i]);
    if (i == 1) CMP(target[i]);
  }
  for (int k = 0; k < 16; k++) { CMP(history[0][k]); CMP(history[1][k]); }
  CMP(lane); CMP(retreatFrames); CMP(result); CMP(frame); CMP(aiMode); CMP(rng.holdrand);
#undef CMP
  return bad;
}

int main(int argc, char **argv)
{
  if (argc < 3) { fprintf(stderr, "usage: dueltest FRAMES.snap INPUTS.snap [step|run]\n"); return 2; }
  Snap fr, in;
  if (load_snap(&fr, argv[1]) || load_snap(&in, argv[2])) { fprintf(stderr, "cannot read the snapshots\n"); return 2; }
  int run = argc > 3 && !strcmp(argv[3], "run");
  // The input probe's address also runs in the programs before DUEL (they load at the same segment):
  // pair every frame with the first input read at or after its video frame.
  int *inputOf = malloc(sizeof(int) * fr.count);
  for (int k = 0, j = 0; k < fr.count; k++)
  {
    while (j < in.count && in.s[j].frame < fr.s[k].frame) j++;
    inputOf[k] = j < in.count && (k + 1 == fr.count || in.s[j].frame <= fr.s[k + 1].frame) ? j++ : -1;
  }
  int badFrames = 0, shown = 0, duels = 1, newDuel = 0;
  DuelState d;
  from_ds(&d, fr.s[0].data);
  for (int k = 0; k + 1 < fr.count; k++)
  {
    // a capture can hold several duels: after a result the next sample starts a new one
    if (!run || newDuel) from_ds(&d, fr.s[k].data);
    newDuel = 0;
    if (inputOf[k] < 0) { printf("frame %d: no input read\n", k); return 2; }
    const uint8_t *j = in.s[inputOf[k]].data;
    DuelInput input = { j[0], j[1], j[2], j[3] };
    if (duel_frame(&d, &input) != 0)
    {
      newDuel = 1;  // the loop returns after this frame
      if (k + 2 < fr.count) duels++;
      continue;
    }
    DuelState want;
    from_ds(&want, fr.s[k + 1].data);
    int bad = compare(&d, &want, k + 1, shown >= 10);
    if (bad)
    {
      badFrames++;
      if (shown++ < 10) printf("frame %d (video %u) differs in %d fields\n", k + 1, fr.s[k + 1].frame, bad);
      if (run) break;
    }
  }
  printf("%s: %d frames, %d duels, %d differ (%s)\n", argv[1], fr.count, duels, badFrames, run ? "run" : "step");
  return badFrames != 0;
}
