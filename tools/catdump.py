#!/usr/bin/env python3
"""catdump.py FILE.CAT [OUTDIR]: list a catalog's entries, or extract them all into OUTDIR."""
import struct, sys, os


def read_catalog(path):
    d = open(path, 'rb').read()
    n = struct.unpack_from('<H', d, 0)[0]
    entries = []
    for i in range(n):
        off = 2 + 24 * i
        name = d[off:off + 12].split(b'\0')[0].decode('ascii', 'replace')
        t, dt, size, pos = struct.unpack_from('<HHII', d, off + 12)
        entries.append((name, size, pos, dt, t))
    return d, entries


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    d, entries = read_catalog(sys.argv[1])
    if len(sys.argv) > 2:
        os.makedirs(sys.argv[2], exist_ok=True)
        for name, size, pos, dt, t in entries:
            open(os.path.join(sys.argv[2], name), 'wb').write(d[pos:pos + size])
        print(f'extracted {len(entries)} files to {sys.argv[2]}')
        return 0
    print(f'{len(entries)} entries, {len(d)} bytes')
    for name, size, pos, dt, t in entries:
        print(f'{name:13s} {size:7d} @{pos:7d}  {1980 + (dt >> 9)}-{(dt >> 5) & 15:02d}-{dt & 31:02d} {t >> 11:02d}:{(t >> 5) & 63:02d}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
