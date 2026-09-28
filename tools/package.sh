#!/bin/sh
# package.sh [OUTDIR]: the deliverable, OUTDIR/opensamurai-VERSION-SYSTEM-MACHINE.tar.gz (default OUTDIR: dist):
# a release build of the game with the MT-32 built in (Munt's libmt32emu, from the extern/munt submodule, and its C++
# runtime), and next to it: a roms folder for the player's MT-32 ROMs (they are not ours to give:
# the player provides them), the README, the license, and the licenses of what is built in. The game's own files
# are the player's too. The program needs SDL2 on the system.
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
out=${1:-$root/dist}
version=$(sed -n "s/^ *version *: *'\([^']*\)'.*/\1/p" "$root/meson.build" | head -1)
name=opensamurai-$version-$(uname -s | tr A-Z a-z)-$(uname -m)
git -C "$root" submodule update --init extern/munt
build=$(mktemp -d)
stage=$(mktemp -d)
trap 'rm -rf "$build" "$stage"' EXIT
meson setup "$build" "$root" --buildtype=release -DbuildTests=false -Dmt32=enabled > "$build/setup.log"
ninja -C "$build" frontend/opensamurai > "$build/build.log"
d=$stage/$name
mkdir -p "$d/roms" "$d/licenses"
cp "$build/frontend/opensamurai" "$d/"
strip "$d/opensamurai"
cp "$root/README.md" "$root/LICENSE" "$d/"
cp "$root/extern/munt/mt32emu/COPYING.LESSER.txt" "$d/licenses/munt-libmt32emu-COPYING.LESSER.txt"
cp "$root/extern/munt/mt32emu/AUTHORS.txt" "$d/licenses/munt-libmt32emu-AUTHORS.txt"
cp "$root/tools/roms-README.txt" "$d/roms/README.txt"
mkdir -p "$out"
tar -C "$stage" -czf "$out/$name.tar.gz" "$name"
echo "$out/$name.tar.gz"
