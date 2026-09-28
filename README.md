# OpenSamurai

OpenSamurai is an unofficial remake of *Sword of the Samurai* (MicroProse, DOS, 1989).

It is written in C and rebuilt from the original program, the way [SDLPoP2](https://github.com/ToolAssisted-run/SDLPoP2) was for Prince of Persia 2. It plays the original game's data files, so you need your own copy of the game.

The original game is a chain of separate DOS programs: a setup program, the title and character creation, the role-playing game, and one program each for duels, melees and battles. OpenSamurai is one program with all of them inside.

## Status

The whole game plays: the title, the crest quiz, character creation, the role-playing game, and the duels, battles and melees it leads to, with saved games. Each original program is rebuilt from its machine code and checked against the real game running in an emulator. The sound of the AdLib, the Roland MT-32, the IBM PC speaker and the Tandy is in; the joystick is not yet. The work is documented in [docs/FINDINGS.md](docs/FINDINGS.md).

## Building

    meson setup build -DgameDir=path/to/the/game
    meson compile -C build
    meson test -C build

`gameDir` is the folder with `SAMURAI.COM` (or `OLD.COM`) and the `.CAT` files. Without it, the tests that need the game's data are skipped. The game itself (`build/frontend/opensamurai`) needs SDL2. The MT-32's music needs [Munt](https://github.com/munt/munt)'s libmt32emu (not part of this project): if it is installed where pkg-config finds it, the game is built with it (for a copy of your own, `meson setup build -Dpkg_config_path=PREFIX/lib/pkgconfig`).

## Playing

    build/frontend/opensamurai path/to/the/game

Use the files of the original floppy disks: the copy protection (the crest quiz) is part of the game. Saved games (Alt-S at the Home Option scroll) are written to the game's folder, as the original does. After the folder, `/NT` skips the title, and `/A` and a letter chooses the sound as the original's setup does: `/AA` the AdLib (the default), `/AR` the Roland MT-32, `/AI` the IBM PC speaker, `/AT` the Tandy, `/AN` none. The MT-32 needs its ROMs (`MT32_CONTROL.ROM` and `MT32_PCM.ROM`, or Munt's names such as `mt32_ctrl_1_07.rom` and `mt32_pcm.rom`) in the game's folder, or in the folder `OPENSAMURAI_MT32ROMS` names. With the speaker the start-up program runs slower, as it does in the original (see docs/FINDINGS.md, 5.8). The AdLib driver is the later one (1-10-94) that the game's later releases have.

## License

GPL-3.0-or-later. See [LICENSE](LICENSE).

This is unofficial software, not affiliated with or endorsed by the game's rights holders. No game data is included.
