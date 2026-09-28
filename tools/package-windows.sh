#!/bin/sh
# package-windows.sh [OUTDIR]: the Windows deliverable, OUTDIR/opensamurai-VERSION-windows-x86_64.zip (default
# OUTDIR: dist): tools/build-bundle.sh's Windows bundle (one opensamurai.exe, cross-built with MinGW-w64), packed flat,
# to unpack into the game's folder
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
out=${1:-$root/dist}
version=$(sed -n "s/^ *version *: *'\([^']*\)'.*/\1/p" "$root/meson.build" | head -1)
stage=$(mktemp -d)
trap 'rm -rf "$stage"' EXIT
"$root/tools/build-bundle.sh" --platform windows --out "$stage/bundle" > /dev/null
mkdir -p "$out"
rm -f "$out/opensamurai-$version-windows-x86_64.zip"
python3 -c "
import os, sys, zipfile
src, dst = sys.argv[1], sys.argv[2]
with zipfile.ZipFile(dst, 'w', zipfile.ZIP_DEFLATED) as z:
    for d, _, files in os.walk(src):
        for f in sorted(files):
            p = os.path.join(d, f); z.write(p, os.path.relpath(p, src))
" "$stage/bundle" "$out/opensamurai-$version-windows-x86_64.zip"
echo "$out/opensamurai-$version-windows-x86_64.zip"
