# OpenSamurai

OpenSamurai is an unofficial remake of *Sword of the Samurai* (MicroProse, DOS, 1989).

It is written in C and rebuilt from the original program, the way [SDLPoP2](https://github.com/ToolAssisted-run/SDLPoP2) was for Prince of Persia 2. It plays the original game's data files, so you need your own copy of the game.

The original game is a chain of separate DOS programs: a setup program, the title and character creation, the role-playing game, and one program each for duels, melees and battles. OpenSamurai is one program with all of them inside.

## Status

The whole game plays: the title, the crest quiz, character creation, the role-playing game, and the duels, battles and melees it leads to, with saved games. Each original program is rebuilt from its machine code and checked against the real game running in an emulator. The sound of the AdLib, the IBM PC speaker and the Tandy is in; the Roland MT-32 and the joystick are not yet. The work is documented in [docs/FINDINGS.md](docs/FINDINGS.md).

## Building

    meson setup build -DgameDir=path/to/the/game
    meson compile -C build
    meson test -C build

`gameDir` is the folder with `SAMURAI.COM` (or `OLD.COM`) and the `.CAT` files. Without it, the tests that need the game's data are skipped. The game itself (`build/frontend/opensamurai`) needs SDL2.

## Playing

    build/frontend/opensamurai path/to/the/game

Use the files of the original floppy disks: the copy protection (the crest quiz) is part of the game. Saved games (Alt-S at the Home Option scroll) are written to the game's folder, as the original does. After the folder, `/NT` skips the title, and `/A` and a letter chooses the sound as the original's setup does: `/AA` the AdLib (the default), `/AI` the IBM PC speaker, `/AT` the Tandy, `/AN` none. With the speaker the start-up program runs slower, as it does in the original (see docs/FINDINGS.md, 5.8). The AdLib driver is the later one (1-10-94) that the game's later releases have.

## License

GPL-3.0-or-later. See [LICENSE](LICENSE).

This is unofficial software, not affiliated with or endorsed by the game's rights holders. No game data is included.
