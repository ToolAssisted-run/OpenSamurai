# OpenSamurai

OpenSamurai is an unofficial remake of *Sword of the Samurai* (MicroProse, DOS, 1989).

It is written in C and rebuilt from the original program, the way [SDLPoP2](https://github.com/ToolAssisted-run/SDLPoP2) was for Prince of Persia 2. It plays the original game's data files, so you need your own copy of the game.

The original game is a chain of separate DOS programs: a setup program, the title and character creation, the role-playing game, and one program each for duels, melees and battles. OpenSamurai is one program with all of them inside.

## Status

The whole game plays: the title, the crest quiz, character creation, the role-playing game, and the duels, battles and melees it leads to, with saved games. Each original program is rebuilt from its machine code and checked against the real game running in an emulator. The sound of the AdLib, the Roland MT-32, the IBM PC speaker and the Tandy is in; the joystick is not yet. The work is documented in [docs/FINDINGS.md](docs/FINDINGS.md).

## Building

    git submodule update --init
    meson setup build -DgameDir=path/to/the/game
    meson compile -C build
    meson test -C build

`gameDir` is the folder with `SAMURAI.COM` (or `OLD.COM`) and the `.CAT` files. Without it, the tests that need the game's data are skipped. The game itself (`build/frontend/opensamurai`) needs SDL2. The MT-32 is [Munt](https://github.com/munt/munt)'s libmt32emu (LGPL-2.1-or-later), a git submodule in `extern/munt`, built with the game and linked into it (CMake is needed to build it; `-Dmt32=disabled` leaves it out).

`tools/package.sh` makes the deliverable, `dist/opensamurai-VERSION-SYSTEM-MACHINE.tar.gz`: the program (it needs only SDL2 on the system), an empty `roms` folder for the MT-32's ROMs, this file, the license, and Munt's license.

## Playing

    build/frontend/opensamurai path/to/the/game

Use the files of the original floppy disks: the copy protection (the crest quiz) is part of the game. Saved games (Alt-S at the Home Option scroll) are written to the game's folder, as the original does. After the folder, `/NT` skips the title, and `/A` and a letter chooses the sound as the original's setup does: `/AA` the AdLib (the default), `/AR` the Roland MT-32, `/AI` the IBM PC speaker, `/AT` the Tandy, `/AN` none. The MT-32 needs its ROMs, a control ROM and a PCM ROM, which are Roland's and not included: you provide your own. Put the two files (any names: they are recognized by their contents) in one of these folders, looked at in this order: the folder the `OPENSAMURAI_MT32ROMS` environment variable names; your data folder's `roms` (on Linux `~/.local/share/OpenSamurai/roms`, on Windows `%APPDATA%\OpenSamurai\roms`); the `roms` folder next to the program; the game's folder. An original MT-32's ROMs (versions 1.04 to 1.07) are the sound the game was made for; a later MT-32's or a CM-32L's work too. Without them `/AR` plays the AdLib's sound, and says where it looked. With the speaker the start-up program runs slower, as it does in the original (see docs/FINDINGS.md, 5.8). The AdLib driver is the later one (1-10-94) that the game's later releases have.

## License

GPL-3.0-or-later. See [LICENSE](LICENSE).

This is unofficial software, not affiliated with or endorsed by the game's rights holders. No game data is included.
