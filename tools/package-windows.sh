#!/bin/sh
# package-windows.sh [OUTDIR]: the Windows deliverable, OUTDIR/opensamurai-VERSION-windows-x86_64.zip (default OUTDIR:
# dist), cross-built with MinGW-w64 (tools/x86_64-w64-mingw32.ini): opensamurai.exe, one file with everything in it
# (SDL2 and the MT-32, Munt's libmt32emu from the extern/munt submodule, linked in), a roms folder for the player's
# MT-32 ROMs, the README, the license and the licenses of what is built in. SDL2's MinGW build (libsdl.org's release,
# its checksum checked) is fetched into ~/.cache/opensamurai the first time.
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
out=${1:-$root/dist}
version=$(sed -n "s/^ *version *: *'\([^']*\)'.*/\1/p" "$root/meson.build" | head -1)
name=opensamurai-$version-windows-x86_64
sdl=2.30.12
sdlSha=dddafbf0705a8cbe1f97c69680886ce147ed4d38f1d04e03523681298e081b0f
cache=${XDG_CACHE_HOME:-$HOME/.cache}/opensamurai
mkdir -p "$cache"
if [ ! -d "$cache/SDL2-$sdl" ]; then
  curl -sfL -o "$cache/SDL2-devel-$sdl-mingw.tar.gz" "https://github.com/libsdl-org/SDL/releases/download/release-$sdl/SDL2-devel-$sdl-mingw.tar.gz"
  echo "$sdlSha  $cache/SDL2-devel-$sdl-mingw.tar.gz" | sha256sum -c --quiet
  tar -C "$cache" -xzf "$cache/SDL2-devel-$sdl-mingw.tar.gz"
fi
sdlDir=$cache/SDL2-$sdl/x86_64-w64-mingw32
mkdir -p "$cache/pkgconfig"
sed "s|^prefix=.*|prefix=$sdlDir|" "$sdlDir/lib/pkgconfig/sdl2.pc" > "$cache/pkgconfig/sdl2.pc"
git -C "$root" submodule update --init extern/munt
build=$(mktemp -d)
stage=$(mktemp -d)
trap 'rm -rf "$build" "$stage"' EXIT
meson setup "$build" "$root" --cross-file "$root/tools/x86_64-w64-mingw32.ini" --buildtype=release -DbuildTests=false \
  -Dmt32=enabled -Dpkg_config_path="$cache/pkgconfig" > "$build/setup.log"
ninja -C "$build" frontend/opensamurai.exe > "$build/build.log"
d=$stage/$name
mkdir -p "$d/roms" "$d/licenses"
cp "$build/frontend/opensamurai.exe" "$d/"
x86_64-w64-mingw32-strip "$d/opensamurai.exe"
cp "$root/README.md" "$d/README.md"
cp "$root/LICENSE" "$d/LICENSE.txt"
cp "$root/extern/munt/mt32emu/COPYING.LESSER.txt" "$d/licenses/munt-libmt32emu-COPYING.LESSER.txt"
cp "$root/extern/munt/mt32emu/AUTHORS.txt" "$d/licenses/munt-libmt32emu-AUTHORS.txt"
cp "$cache/SDL2-$sdl/LICENSE.txt" "$d/licenses/SDL2-LICENSE.txt"
sed 's/$/\r/' "$root/tools/roms-README.txt" > "$d/roms/README.txt"
mkdir -p "$out"
python3 -c "
import os, sys, zipfile
stage, name, dst = sys.argv[1:4]
with zipfile.ZipFile(dst, 'w', zipfile.ZIP_DEFLATED) as z:
    for top, dirs, files in os.walk(os.path.join(stage, name)):
        for f in sorted(files):
            p = os.path.join(top, f); z.write(p, os.path.relpath(p, stage))
" "$stage" "$name" "$out/$name.zip"
echo "$out/$name.zip"
