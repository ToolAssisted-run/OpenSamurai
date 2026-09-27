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

### 5.2 The battle (BATTLE.EXE) — simulation reconstructed in source/battle.c, verified

One step of the battle loop in main (1000:00A2-010F) runs every 17 video frames (its own INT 8 timer,
locked to the refresh as in the duel), about 4 steps per second. Units are rotated rectangles of 1-8
figures (64-byte records at DS:5E2A; positions in 1/16 pixel, angles in 1/65536 turn) over two 84x54 grids
of 4x4-pixel cells: the terrain (streams, slopes, marsh, woods, castle) and a visibility map rebuilt every
step from the units' footprints, through which the units cast rays to see each other. Each step: the
drawing pass (which also sets each unit's terrain modifier and speed and removes units that left the
field), then five passes over the records (state handlers, damage, morale, morale modifiers, rout/rally),
each followed by a call of the input handler, then the wait. Both sides run the same autonomous logic;
the player only gives orders (select 1-9 / 0 nearest / Enter under the cursor, then + or = turn and march,
- march without turning, * turn in place; R retreat) and the enemy's general only chooses the formation.
The geometry is 16-bit fixed point: a 257-entry sine table with interpolation, an octant-polynomial atan2,
Newton square roots, an approximate distance.

Verification: tests/battletest.c against 96 random captures of the two battle encounters (all
difficulties, random formation choices and random orders): 63,535 steps identical in every unit field,
the visibility map, the random seed and the order state, both step by step and free-running from the
first step. Captures: the whole data segment at 1000:00A9 (the top of each step), every consumed key at
1000:3935 (ax) and the pass boundaries at 1000:0170. Not yet covered by captures: musketeers, castles
(both only appear in the role-playing game's battles).

The set-up (source/battle_setup.c): the parameters from the shared block (+5A battle type, +38 rank,
+64/+66 army sizes, +6C/+6E generalship, +36 difficulty), the battlefield generator (seeded with the BIOS
tick count: a stream from one edge, 14/16 px per step with changing curvature, at most one tributary,
slopes along its banks, drying up into a marsh; woods grown from a random seed point; a castle block),
the enemy general's formation choice (each of the six candidates scored by the terrain under its figures,
cavalry in a marsh rejects it; all rejected: generate again) and the army placement from the formation
tables (variant by rank and army size; the player's army is the table turned round). tests/battlesetuptest.c
against 64 captures (the formation screen's data segment, the seed sampled at 1000:51DE, and the first
step): terrain, random numbers, enemy formation, candidate armies and placed armies identical.

### 5.3 The melee (MELEE.EXE) — reconstructed in source/melee_core.c over its data segment

MELEE keeps its whole state in parallel arrays at fixed places of its data segment: 7 entities (0 = the
player), 154 cells per floor (11 x 14, 7 bytes each, three floors at a stride of 180 cells: discovered,
two wall bytes, room id...), 77 x 98 collision tiles of 4 x 4 pixels, objects, corpses, and 77 countdown
timers (DS:0058, 11 groups of 7 words). Its INT 8 hook reprograms the PIT to 60 Hz and counts ticks at DS:0053;
the main loop (1000:006A-00A7) runs unthrottled (about 21 passes per tick in the oracle) and each pass
decrements every timer once per tick elapsed since the previous pass (1000:3BB8 / 07C2). All pacing
(movement, attacks, AI, reinforcements) is in those timers. Castles are built from 14 hand-made half-floor
templates seeded from the shared block (a castle keeps its layout between visits); villages and paddies
are random. The fog is per cell, with a whole room revealed when the player enters it. A CPU speed test at
start (1000:0708: fewer than 15,000 empty loops in 0.25 s) makes a "slow machine" melee (2-pixel steps, at
most 2 enemies at once); the oracle and the reconstruction are the fast case.

The reconstruction is the Ghidra decompilation translated mechanically into C over an image of that data
segment (the workspace's work/ghidra2c.py; the image's byte order, aliasing and 16-bit wrap-around are the 8086's), then
corrected by hand where the decompiler was wrong, each correction marked FIX. The classes of error found:

- bytes widened the wrong way: 14 functions return AL zero-extended (`sub ah,ah`) and 18 take byte
  parameters they zero-extend, all of which Ghidra typed `i8`, sign-extending cell numbers above 127 (found by
  the workspace's work/audit_ret.py and audit_params.py);
- arguments Ghidra lost, pushed before an inner call whose result is the next argument (22 calls, e.g.
  `f(g(x), y)` with y pushed first), and one tile type computed as `rand(2) + 1` whose `+ 1` it dropped;
- results Ghidra lost: computed into AX after the last call (1000:8A88, the tile of a cell's centre), or the
  value of a call in each branch (1000:7C84 turn, 4BA4 cell; work/audit_ax.py lists the functions whose
  assembly leaves a value in AX that a caller then uses);
- calls made without their arguments, whose callee then reads the caller's stack: 1000:50C6 calls 5222
  (pick a free cell for a reinforcement) with nothing pushed, so its "whole floor" flag is whatever the only
  path to it left in that stack word: the 100 that 1000:1726 pushes when the alarm is off, the cell counter of
  1000:4D4E in mission type 0x15, else the random remainder 1000:4E3E drew just before (recoverable from
  DS:9D8E); and 1000:8040 calls 8014 with the caller's saved SI, which is its own entity argument;
- the shared block: the program reaches it through a far pointer (DS:AE54, offset 0, segment from 0000:04F0),
  which the translation took for an offset into the data segment; its 51 accesses are SH8/SH16 (the block);
- the drivers: the MISC keyboard slot 90 answers 0 when a key is waiting, so the command-key poll
  (1000:BC52: Alt-Q, Alt-J, Alt-V, Space pause) is a FIX with no keys; the controls come from the host
  (DS:398C-398F, as the INT 9 hook leaves them) where the loop reads them (1000:9F8A direction, 9F4E fire).

Verification: tests/meleetest.c against captures that sample the whole data segment at every timer
decrement (1000:07C2, i.e. once per elapsed tick, with the instruction count), and the shared block, plus
every control read and every srand(). The samples of one pass form a group; the test resumes at a group's first decrement, finishes
that pass, runs the passes without a tick in between and starts the next pass up to its first decrement,
where it compares the whole segment except the interrupt handlers' own bytes (DS:398C-3995, 46AA-46CA), and
the shared block.
The mismatches were found with an instruction trace of the real game over the group (the oracle's `trace`)
reduced to the functions entered, compared with the C's own entries (each translated function calls
FN(address)), plus write watches on the first differing byte on both sides (the workspace's oracle/gtrace.sh).

Result: 48 captures (both encounters, "Outpost of Ishiyama Hongan-ji" and "Bodyguard vs the Gamblers", all
four difficulties, random directions and attacks from the start of the melee), 129,352 ticks, identical in
the whole data segment and the shared block, tick by tick and free-running from the first tick of each run.

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

- 2026-09-27: the melee translated over its data segment and corrected until it matched its captures.
- 2026-09-27: the battle's simulation reconstructed and verified against 96 captures (63,535 steps).
- 2026-09-27: the duel's simulation reconstructed and verified against 64 captures (211 duels).

- 2026-09-27: files inventoried, launcher protocol read, all programs and drivers unpacked and decompiled,
  oracle boots and plays a new game under script, catalog format verified.
