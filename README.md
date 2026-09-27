# OpenSamurai

OpenSamurai is an unofficial remake of *Sword of the Samurai* (MicroProse, DOS, 1989).

It is written in C and rebuilt from the original program, the way [SDLPoP2](https://github.com/ToolAssisted-run/SDLPoP2) was for Prince of Persia 2. It plays the original game's data files, so you need your own copy of the game.

The original game is a chain of separate DOS programs: a setup program, the title and character creation, the role-playing game, and one program each for duels, melees and battles. OpenSamurai is one program with all of them inside.

## Status

Early. The original programs have been taken apart and the work is documented in [docs/FINDINGS.md](docs/FINDINGS.md). Nothing plays yet.

## Building

    meson setup build -DgameDir=path/to/the/game
    meson compile -C build
    meson test -C build

`gameDir` is the folder with `SAMURAI.COM` (or `OLD.COM`) and the `.CAT` files. Without it, the tests that need the game's data are skipped.

## License

GPL-3.0-or-later. See [LICENSE](LICENSE).

This is unofficial software, not affiliated with or endorsed by the game's rights holders. No game data is included.
