# OpenSamurai

OpenSamurai is an unofficial remake of *Sword of the Samurai* (MicroProse, DOS, 1989).

It is written in C and rebuilt from the original program, the way [SDLPoP2](https://github.com/ToolAssisted-run/SDLPoP2) was for Prince of Persia 2. It plays the original game's data files, so you need your own copy of the game.

The original game is a chain of separate DOS programs: a setup program, the title and character creation, the role-playing game, and one program each for duels, melees and battles. OpenSamurai is one program with all of them inside.

## Status

The whole game plays: the title, the crest quiz, character creation, the role-playing game, and the duels, battles and melees it leads to, with saved games. Each original program is rebuilt from its machine code and checked against the real game running in an emulator. The IBM PC speaker's sound is in; the other sound boards and the joystick are not yet. The work is documented in [docs/FINDINGS.md](docs/FINDINGS.md).

## Building

    meson setup build -DgameDir=path/to/the/game
    meson compile -C build
    meson test -C build

`gameDir` is the folder with `SAMURAI.COM` (or `OLD.COM`) and the `.CAT` files. Without it, the tests that need the game's data are skipped. The game itself (`build/frontend/opensamurai`) needs SDL2.

## Playing

    build/frontend/opensamurai path/to/the/game

Use the files of the original floppy disks: the copy protection (the crest quiz) is part of the game. Saved games (Alt-S at the Home Option scroll) are written to the game's folder, as the original does. After the folder, `/NT` skips the title and `/AI` plays the sound through the IBM PC speaker's driver (the setup's "IBM" choice; without it there is no sound, as with the setup's "none"). With the speaker's driver the start-up program runs slower, as it does in the original (see docs/FINDINGS.md, 5.8).

## License

GPL-3.0-or-later. See [LICENSE](LICENSE).

This is unofficial software, not affiliated with or endorsed by the game's rights holders. No game data is included.
