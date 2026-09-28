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
cat > "$d/roms/README.txt" <<'EOT'
The Roland MT-32's ROMs go here: a control ROM and a PCM ROM, as files of any names (they are recognized by their
contents; an original MT-32's, versions 1.04 to 1.07, is the sound the game was made for; a later MT-32's or a
CM-32L's also work). They are not included: they are Roland's, and you need your own.

Then start the game with the MT-32: opensamurai GAMEDIR /AR

The ROMs are also looked for in your own data folder (on Linux ~/.local/share/OpenSamurai/roms), in the folder the
OPENSAMURAI_MT32ROMS environment variable names, and in the game's folder. Without them, /AR plays the AdLib's
sound instead.
EOT
mkdir -p "$out"
tar -C "$stage" -czf "$out/$name.tar.gz" "$name"
echo "$out/$name.tar.gz"
