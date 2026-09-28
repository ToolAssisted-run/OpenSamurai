#!/bin/sh
# package.sh [OUTDIR]: the Linux deliverable, OUTDIR/opensamurai-VERSION-linux-x86_64.tar.gz (default OUTDIR: dist):
# tools/build-bundle.sh's Linux bundle (the program needs only the C library), packed flat, to unpack into the game's
# folder
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
out=${1:-$root/dist}
version=$(sed -n "s/^ *version *: *'\([^']*\)'.*/\1/p" "$root/meson.build" | head -1)
stage=$(mktemp -d)
trap 'rm -rf "$stage"' EXIT
"$root/tools/build-bundle.sh" --platform linux --out "$stage/bundle" > /dev/null
mkdir -p "$out"
tar -C "$stage/bundle" -czf "$out/opensamurai-$version-linux-x86_64.tar.gz" .
echo "$out/opensamurai-$version-linux-x86_64.tar.gz"
