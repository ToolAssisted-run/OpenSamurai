// oplrender SND.TXT OUT.RAW FIRST LAST: the AdLib's writes of a capture (oracle/snd_ev.py: its o 388 / o 389
// events) through the OPL2 model (opl.c), each at its video frame's start, rendered from frame FIRST to LAST:
// signed 16-bit mono at 44100 Hz (to set against DOSBox-X's own sound of the same frames: oracle-run's audio)
#include <stdio.h>
#include <stdlib.h>

#include "opl.h"

#define FRAME_CLOCKS 17024

int main(int argc, char **argv)
{
  if (argc < 5) { fprintf(stderr, "usage: oplrender SND.TXT OUT.RAW FIRST LAST\n"); return 2; }
  FILE *f = fopen(argv[1], "r"), *o = fopen(argv[2], "wb");
  if (!f || !o) { fprintf(stderr, "cannot open the files\n"); return 2; }
  long first = atol(argv[3]), last = atol(argv[4]), frame = 0;
  char line[128];
  int k = 0;
  static int16_t buf[4096];
  opl_reset();
  uint64_t rendered = 0;
  while (fgets(line, sizeof line, f))
  {
    unsigned port, v;
    if (line[0] == 'F')
    {
      long nf = atol(line + 2);
      // the frames before: rendered (from FIRST on)
      for (; frame < nf; frame++)
        if (frame >= first && frame < last)
        {
          uint64_t t = (uint64_t)(frame - first + 1) * FRAME_CLOCKS;
          int n;
          while ((n = opl_render(t, 44100, buf, 4096)) > 0) fwrite(buf, 2, (size_t)n, o), rendered += (uint64_t)n;
          for (int i = 0; i < 4096; i++) buf[i] = 0;
        }
      k = 0;
      continue;
    }
    if (line[0] == 'o' && sscanf(line + 2, "%x %x", &port, &v) == 2 && (port == 0x388 || port == 0x389))
    {
      uint64_t t = frame >= first ? (uint64_t)(frame - first) * FRAME_CLOCKS + 24 * (uint64_t)k++ : 0;
      opl_out((uint16_t)port, (uint8_t)v, t);
    }
  }
  fclose(f);
  fclose(o);
  printf("%llu samples\n", (unsigned long long)rendered);
  return 0;
}
