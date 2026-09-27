# Sword of the Samurai — everything found so far

The reference is *Sword of the Samurai* version 445.03 (MicroProse, DOS, 1989), the build in the disk images used
by the published tool-assisted speedrun. This file collects every finding about the original program: its
files, its memory, its mechanics and the methods used to find them. It is updated as the reconstruction goes.

## 1. Files and programs

| File | What |
|---|---|
| SAMURAI.COM | the launcher (in RawCopy-patched copies it is a TSR stub and the original launcher is `OLD.COM`) |
| SU.EXE | setup: joystick, graphics and sound driver choice; prints the version banner |
| START.EXE | title sequence, Career Choices (new game, restore, scroll of honor, six encounters), character creation |
| RP.EXE | the role-playing game (the strategy layer) |
| DUEL.EXE, MELEE.EXE, BATTLE.EXE | the three action games, run as separate programs |
| MISC.EXE | 468-byte overlay: keyboard (INT 16h) and joystick (port 201h) helpers, called through a far-pointer table |
| MGRAPHIC.EXE, EGRAPHIC.EXE, TGRAPHIC.EXE, CGRAPHIC.EXE | graphics drivers (VGA/MCGA, EGA, Tandy, CGA), MZ overlays with an entry table |
| CGRAPHIC.MEL, EGRAPHIC.MEL, TGRAPHIC.MEL | extra melee drawing code per video mode (MZ overlays) |
| NSOUND.SAM, ISOUND.SAM, TSOUND.SAM, ASOUND.SAM, RSOUND.SAM | sound drivers (none, IBM speaker, Tandy, AdLib, Roland MT-32), MZ overlays |
| FONTS.SAM | the fonts, loaded raw after the graphics driver |
| RP.CAT, START.CAT, DUEL.CAT, MELEE.CAT | resource catalogs (section 4.1) |
| ICONS.PIC | a picture used by BATTLE |
| HONOR.SCL | the scroll of honor (high scores) |
| TALLTALE.DAT | the saved game |
| READ.ME | 3/5/90 addendum: `/NT` skips the title, Alt-N new game, Alt-J joystick, the driver list |

All six programs are Microsoft C 5.1 (MELEE: 5.0) and EXEPACK'd. They need `loadfix` under DOSBox (the
EXEPACK "Packed file is corrupt" A20 bug). Unpacked copies are made with pop2dec's `unexepack.py`.

## 2. The launcher protocol

`OLD.COM` (2352 bytes; disassembly in the workspace, work/old.asm):

- saves the INT 1Bh/23h/08h vectors; allocates a 1 KB (0x40 paragraph) shared block and publishes its segment
  at 0000:04F0 (the BIOS inter-application area 40:F0), with 1 at 40:F2 and 0 at 40:F4;
- loads `misc.exe` as an overlay (INT 21h/4B03) → shared[+1E] = its segment;
- copies its own command tail (e.g. `/NT`) to every child;
- EXEC `SU.EXE`; exit code 0 → quit;
- reads the graphics driver name from shared[+00], loads it and appends `FONTS.SAM` raw after its image →
  shared[+1A]; reads the sound driver name from shared[+0D], loads it → shared[+1C]; allocates 0xB00
  paragraphs (44 KB) → shared[+20] (picture buffer);
- EXEC `START.EXE`; exit 0 → quit;
- loop: EXEC `RP.EXE`; exit code 0 quit, 1 `duel.EXE`, 2 `battle.EXE`, 3 `melee.EXE`, 4 `START.EXE` (new game),
  anything else "Invalid exit # from RP". After MELEE: if shared[+28] == 0 and shared[+2A] == 1 → `duel.EXE`
  directly (a melee that turns into a formal duel), otherwise back to RP. After DUEL/BATTLE: exit 0 quit, else RP.
- Unused strings: `ds.EXE`, `travel.exe` (programs that were merged into RP), `c:\c\bin\cv.exe` (CodeView).

The game state crosses the program boundary through the shared block and `TALLTALE.DAT`.

### 2.1 SU.EXE

Arguments after `/` or `-`: `J` joystick, `NJ` no joystick, `NT` no title, `A<letter>` sound driver,
`G<letter>` graphics driver (`V` = VGA: Mgraphic with mode 4), `P`, `S`, `V<0-2>` volume. Without `/J` or
`/NJ` it asks "Do you have a joystick (Y/N)?". The graphics menu numbers the drivers found (`?GRAPHIC.EXE`):
1 VGA (256 color), 2 MCGA (both Mgraphic), 3 EGA, 4 Tandy, 5 CGA; the sound menu: 1 none, 2 IBM, 3 Tandy,
4 AdLib, 5 Roland MT-32 (B = Innovation), "Sound driver ?" for unknown `.SAM` files.

Shared block fields written by SU: +00 graphics driver name, +0D sound driver name, +22 video mode (0 CGA,
1 Tandy, 2 EGA, 3 MCGA, 4 VGA, 5 Hercules), +26 (/N..), +28 (/S), +30 (Hercules), +34 joystick, +3E..+48 =
six words of -1, +7A (/P, default 1), +310 (/V), +31E = 0xFF, +2F6 and +30A = 1.

## 3. Memory

Runtime layout of a new game (VGA, no sound; RAM dump in the workspace, oracle/w_ng/ram10000.bin):

- shared block segment 1942; +1A 19BD graphics driver (FONTS.SAM raw at linear 1AD80 after it), +1C 19AA
  sound driver, +1E 1983 MISC, +20 1C72 the 44 KB buffer, +22 = 4 (VGA); the player's name at +2D4; six
  0x60-byte records at +80, +E0, +140, +1A0, +200, +260;
- RP.EXE: load segment 27CC, DGROUP (DS) 41E2. Ghidra loads the image at segment 1000, so a Ghidra address
  `seg:off` is at runtime `seg + 17CC : off`;
- `TALLTALE.DAT` = a 0x23-byte header (`d1 ae 01 00` + the rank name, e.g. "hatamoto") + a 1 KB copy of the
  shared block + RP's state.

## 4. Formats

### 4.1 Catalogs (.CAT)

`uint16 count`, then `count` entries of 24 bytes: `char name[12]` (8.3, NUL padded), `uint16 dos_time`,
`uint16 dos_date`, `uint32 size`, `uint32 offset` (from the file start). The entries' bytes follow the table
in order, without gaps (checked by tests/cattest.c). `source/catalog.c` reads them.

- RP.CAT (165): PLAYER.PIC, SAMH0-15 / HATAH0-15 / DAIH0-15 (portraits per rank), WOMAN0-5, BACKGND, BIRD,
  DRAGON, FUJI, HIDETORA, IRIS, MOUNTAIN, TREE2, WATER, WAVE, WIN01-56 (window art), BIGSHGN, SHOGUN01-08,
  FIGURE, MAP1-48.DAT (the 48 province travel maps, 700-1700 bytes each).
- START.CAT (21): WINLTS/WINMSG/WINPIC/WINDEF.DAT (the window and message definitions), POLMAP.DAT (the
  political map), CRESTSM1/2, RPICONS, TVLICONS, STICONS, TTLSTP01-09 (title steps), TTLICON1/2.
- DUEL.CAT (7): INSIDE/OUTSIDE/VILLAGE backgrounds, ENMYTOPS/ENMYLEGS, PLYRTOPS/PLYRLEGS sprite sheets.
- MELEE.CAT (3): MELEE0-2.PIC.

### 4.2 Pictures (.PIC)

Headers start with a word 0x06/0x07/0x0E/0x0F/0x16 then the width and height (e.g. 0x140 × 0xC8). Format
to be worked out from the drivers.

## 5. Mechanics

### 5.1 The duel (DUEL.EXE) — reconstructed in source/duel.c, verified

One iteration of the duel loop (1000:0594) is one game frame: the loop waits for 7 ticks of its own INT 8
timer, which it locks to the video refresh (70.086 Hz on VGA), so the duel runs at 10 frames per second.
Both fighters run one animation state machine: 133 states of 24 bytes (DS:0A8C: sprites, hold time, sprite
offsets, an "auto" transition taken while the sword button is held or released, and a next state for each
of the 9 controller directions). Movement happens when a state is entered (the move table DS:1704,
mirrored for the opponent). The opponent's AI (a 30-row response table at DS:17B2 keyed by the player's
state seen through a random reaction delay, the lane and a random mode re-rolled every 16 frames) picks a
target state and then the controls that reach it; skill 0..7 sets the reaction delay, a telegraph pause
before its swings, the aggression and periodic windows in which it won't parry. Impacts resolve against the
defender's guard side and the 16-pixel lane; an over-the-shoulder swing can't be parried and wounds twice
half of the time; four wounds and the fighter falls. Random numbers: MS C `rand()`, seeded with `time()`.

Verification: tests/dueltest.c against 64 random captures (encounter "Kenjutsu training" / "Musashi vs
Kojiro", all four difficulty levels): 89,273 frames in 211 duels, identical in every carried-over field
both frame by frame and free-running from each duel's first frame. Captures: a probe at 1000:20A4 (the
top of each iteration) sampling the whole data segment, and one at 1000:0A3E (where the loop reads the
virtual joystick, DS:22F2-22F5); the loop's locals are on the stack at the loop's frame pointer DS:6BDA.
The workspace's oracle/gen_duel.py makes the scripts.

## 6. Methods

The oracle is the real game in DOSBox-X headless (Chimera's core with the tracer branch, as for SDLPoP2).
Disk: a FAT16 image with the game folder (`fat16put.py`). Boot with `--autoexec 'c:' --autoexec 'cd samurai'
--autoexec 'loadfix old'`. With the RawCopy TSR stub (`samurai`) scripted keys never reach the game; the
original launcher works. Frames are 70.086 Hz VGA frames; keys held for 30 frames, 100 frames apart, are
reliable.

A scripted new game (workspace oracle/ng.script): n@700 (no joystick) → 1@1100 (VGA) → 1@1500 (no sound) →
title (~2300-3500) → Career Choices (~4400) → enter (New Game) → name, letters, enter → clan map (Satsuma /
Shimazu by default) enter → difficulty (Tanto) enter → family advantage (Swordsmanship) enter → RP.EXE
("Lord Kiyosuke, the hatamoto whom you will serve...") at ~7100.

The oracle is deterministic: two runs of the same script give identical screens and identical RAM after
13,600 frames (rp1.script: welcome text, the rivals' introductions, the home scroll, "Equip more samurai",
the rivals' news). RP's opening: "Lord Kiyosuke, the hatamoto whom you will serve, welcomes you..." → one
screen per rival ("Toshiro is a samurai of great renown. He controls a large fief, and commands 36 warriors;
he is known throughout the province as a samurai of commendable honor.") → the scroll "Considering the
situation, you decide to: Equip more samurai. / Practice kenjutsu. / Drill your troops. / Donate land to the
local Buddhist temple. / Raise the rice tax within your domain. / Travel."

While RP idles on a screen, only these bytes of its data segment change (RAM dumps 20-100 frames apart):
DS:3038-303C (five bytes, every sample), DS:3041, DS:3048 (a counter, +1 every ~20 frames), DS:304C (+1
every ~36 frames), DS:3056 (a 0/1 toggle), and the stack around DS:963C-96A0. The BIOS tick 0040:006C runs.

Timing: no program hooks INT 1Ch. RP reads the BIOS keyboard buffer (0040:001A/1C) itself and uses the
BIOS tick for key auto-repeat. DUEL (and presumably MELEE and BATTLE) hooks INT 8 and reprograms PIT
channel 0, restoring 18.2 Hz (count 0) at exit.

The published TAS (M6401, JPC-rr, 697 s of input, 2165 key presses) uses Enter (760), the arrows and the
keypad diagonals 7/9/1/3, keypad + - * and the digits 1-4 (battle unit orders), Backspace (duel parry),
F-keys not at all; decoded with the workspace's work/jrsrkeys.py.

## 7. Open

- The picture, font, map and window formats.
- Everything about the mechanics.
- What `SAMURAI.CLK` (3780 bytes) is: no program names it; possibly part of the RawCopy patch.

## 8. Log

- 2026-09-27: the duel's simulation reconstructed and verified against 64 captures (211 duels).

- 2026-09-27: files inventoried, launcher protocol read, all programs and drivers unpacked and decompiled,
  oracle boots and plays a new game under script, catalog format verified.
