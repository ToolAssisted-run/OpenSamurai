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

### 5.4 The role-playing game (RP.EXE) — recompiled in source/rp_core.c, verification in progress

RP is a medium-model program (26 code segments, one data segment: DS:0000-5BBF data, 5BC0-8F5F game state,
8F60-975F the stack) that reaches the shared block through a far pointer (DS:8540) and runs its sub-games by
hibernating: 23bb:0222 saves its data segment into the picture buffer (168c:00CA), exits with the sub-game's
code, and when the launcher runs it again, main restores it (168c:00EE) and continues after the save.

Ghidra's decompilation of RP is unusable in many places even after its library routines were given their
prototypes and every function's parameters were committed (work/ApplySigs.java, CommitParams.java): jump
tables, functions whose results or arguments go through registers, varargs message functions that walk their
stack arguments, stack variables it cannot place, assembly routines that pop their own return address. So RP
is **recompiled from its machine code** (the workspace's work/asm2c.py): every function becomes C over emulated
8086 registers (source/asm2c.h), the data segment image and the stack inside it, statement for statement,
decoded by recursive descent (tables inside the code are not taken for instructions; jump tables become
switches). Calls between recompiled functions keep the original's stack exactly -- the arguments as pushed, the
real return address -- so every stack address the program stores, and every stale stack word it reads, is the
original's. The translated C (work/ghidra2c.py) is kept beside it for the functions where it is right, and is
to replace the recompiled code function by function where the captures still pass.

Not recompiled: the MS C run-time library (strings, long arithmetic, rand at DS:34FC, files on the game
directory, DOS memory as DOS's own first-fit arena so that buffers get the segments they got in the real game),
the picture decoder (2965, a stack-switching coroutine: written in C with the original's state in the data
segment, source/lzw.c, which START shares), AllocBuffer and friends (29fd), the delay (29f7:0048). The graphics driver (MGRAPHIC.EXE) is
recompiled whole, as one function with a dispatch for returns (its routines pop their own return addresses and
jump into each other's epilogues): source/mgraphic.c, over its own segments, as loaded in the oracle.

Verification: tests/rptest.c against captures of the main loop's tick (106a:0048): the data segment, the shared
block and all of conventional memory, plus every time() result, key poll and key read, frame wait (with the bytes
the interrupt handlers keep) and srand() in execution order, which the C must ask for in the same order. The
captures are driven by random menu keys from a new game (the workspace's oracle/gen_rp.py). Divergences are found
by comparing the functions entered and the events served with the real game's instruction trace, filtered
through a FIFO (oracle/rtrace.sh).

Results (2026-09-28): all 16 captures of 20,000 frames from a new game pass tick by tick and in one run
(141 ticks, 20 of them across a sub-game); the key-waiting and key answers are the MISC calls' return values at
their return sites (probing the BIOS buffer at the stub's entry raced the keyboard interrupt). From main's entry
(its state captured there) to the first tick passes too: RP's start-up, with the pieces the C had stood in for
made faithful -- the drivers' stubs filled from the overlay headers (168c:0CE7), FileOnDisk's saved critical-error
vector and FCB (the vector as DOS's INT 21h 35h reports it: 072F:0110, not the IVT's 072F:0000 in DOSBox-X),
time()'s once-only tzset flag (DS:5BB4), int86()'s carry (set by its own compare for n < 25h and kept by the BIOS:
int86(10h) always ends in _dosmaperr(AL), errno 22).
- 1000:05BF (after flush_keys' read) is also flush_keys' entry, as START's 04A1.
- When a program ends, DOS puts INT 22h-24h back from its PSP: after a sub-game the critical-error vector is the
  launcher's again.

### 5.5 The start-up program (START.EXE) — recompiled in source/start_core.c, verified

START is the floppy's program (445.03), with its copy protection: the crest quiz runs while shared+0x2E is 0
(the provided game directory has a cracked START.EXE that sets the flag and skips it; the floppy prevails).
A small-model program with two assembly modules linked in (1694 drawing, timer and Ctrl-Break helpers; 1757 the
picture decoder) and the MS C 5.1 library. It is **recompiled whole from its machine code**, the library too
(the workspace's work/start_rec.sh; the generated source is not edited): time() runs the library's own code over
DOS's date and time, so its time-zone state in the data segment is the original's. Kept in C (source/start_rt.c):
the picture decoder (source/lzw.c, with START's offsets), int86() (it builds its INT instruction on the stack and
calls it), exit(). Not recompiled: the divide-error handler 1694:01BD (asm_divide_error emulates it, as RP's)
and the interrupt handlers (INT 8, the frame timer; INT 1Bh, Ctrl-Break): the host gives their effects.

- setjmp()/longjmp() (the title's skip: a key during any wait ends the whole sequence) stay recompiled, so that
  the jump buffer in the data segment is the original's; the host's setjmp at the call site and longjmp after
  the recompiled one take the C back into the function that called setjmp.
- The frame waits: three loops poll the frame counter DS:1BA8 that the timer's handler increments (1000:199B
  the province map, 24A8 menu_select, 4E46 wait_ticks); those polls ask the host, which sets the handler's bytes
  DS:1BA8-1BC7 as they were when the real wait ended. Code that reads DS:1BAA between the polls (the menu
  pointer's blink) sees the value of the last wait.
- MISC's answers (slot 90 key waiting, 91 the key, 95-97 the joystick), DOS's clock (INT 21h 2Ah/2Ch) and the
  BIOS ticks (INT 1Ah: the seed) come from the host; DOS's files (3Dh-42h, 44h) from the game directory, DOS's
  memory from the arena (source/dosmem.c, shared with RP).
- 1000:04A1 is both the return point of flush_keys' key read (049C) and flush_keys' entry (and its first jump's
  target): a capture's probe there is a key read only after a "key waiting" answer at 04A6.

- The picture decoder's table reset (when the codes outgrow 12 bits) counts its loops in CX, which then holds
  the code just read: the "previous code" stored after the reset is therefore 0, and the next string (code 256)
  gets prefix 0. RP's decoder is the same module (the fix is in the shared source/lzw.c).
- The library's open() jumps back into shared error code below its entry (5A69): the recompiled function enters
  at its entry (asm2c now emits the jump when code precedes the entry; RP's functions are regenerated alike).

Verification: tests/starttest.c runs START from main (its state captured there: the data segment, the shared
block, all of conventional memory) to exit() on a capture's answers, and compares the data segment and the shared
block at every frame wait's end and at exit(). Each kind of answer is a queue of its own; a run of equal answers
carries the number of frame waits before it, so an answer the C takes at another frame is reported where it
happens. Excluded from the comparison: the stack (DS:4F90-578F: the uninitialized locals hold what the timer
interrupt pushed there in the real game) and the picture decoder's private stack. Captures: the workspace's
oracle/gen_start.py, st_ev.py, cap_start.sh (random menu keys, letters and digits from the setup on, on a disk
built from the floppy's files; with QUIZ=3 the quiz answered right: skip at 1900 and 2300, three downs, Enter --
the Date clan's crest is the fourth that run). 12 captures pass from main to exit(1), 38,000 frame waits: the
title, the credits, the quiz failed (8) and passed (4), the career menu, the Scroll of Honor, Restore, the name,
the province map, difficulty, family advantage. Not covered yet: the encounters of the career menu, the
joystick (the captures have none), the sound boards.

### 5.6 The action programs as programs (DUEL.EXE, BATTLE.EXE, MELEE.EXE) — recompiled whole, verified

For the one executable the action games run as the programs they are (their screens, their input), beside the
readable reconstructions of their simulations (5.1, 5.2): recompiled whole like START (the workspace's
work/duel_rec.sh, battle_rec.sh; source/duelexe_core.c, battleexe_core.c, generated), their runtimes in
duelexe_rt.c and battleexe_rt.c (the picture decoder and exit in C; the DOS emulation shared in source/dos.c).

- DUEL: the frame wait (the duel loop until 7 ticks, the getter 1000:20A0) and the keyboard joystick's reads
  (1000:0A3E, 109D; the INT 9 handler's bytes DS:22F2-22FB) ask the host; its own disk check uses DOS's FCB
  functions (29h, 11h). The start-up's _setargv pops its return address into a word and jumps through it. The
  decoder is an older version: no 128-byte palette.
- BATTLE: the waits are busy loops reading the frame counter (the getter 1000:681E) and polling the keys: the host
  answers each read with the value the game read; a checkpoint at each simulation step (the counter's reset,
  1000:6822). The terrain's seed reads the BIOS ticks at 0040:006C itself. Ghidra's function list misses the unit
  state handlers of the table at DS:0042 (states 0, 1, 9, 13), the damage routine 1000:0A1C and 1000:8804; they
  are reached through pointers (near calls through a pointer go through a dispatcher of the segment's functions).
- MELEE: loads its own graphics driver (EGRAPHIC.MEL on VGA, INT 21h 4B03 at 4887): the EGA's planar mode 0Dh
  with a 320x400 virtual page it scrolls with the CRTC's start address (source/vga.c emulates the planes, the
  latches, the write and read modes, the registers). The main loop runs unthrottled and reads the tick counter
  DS:53 (the timer's callback 1FE7:043E counts it while DS:57 says so) on each pass; a speed calibration counts
  its own loop's passes for 15 ticks: the host answers every read with the game's value. Its keyboard joystick
  is DUEL's (DS:398C-3996). time() goes through intdos.
- Verified: 9 duels (3,580 frame waits), 9 battles (1,300 steps) and 9 melees (46,000 ticks) from main to exit (or
  the capture's end), the data segment and the shared block equal at every checkpoint, the interrupt handlers'
  bytes (the timers', the keyboard joysticks') set from the capture at the checkpoints.

### 5.7 The launcher and the frontend (source/game.c, frontend/main.c)

The launcher (SAMURAI.COM) in C with the original's memory layout: the shared block at 1942, MISC.EXE at 1983,
NSOUND.SAM at 19AA, MGRAPHIC.EXE at 19BD with FONTS.SAM after its image, the picture buffer at 1C72; each program's
environment at 2773, its PSP at 27BC, the program at 27CC, DOS's arena from its control blocks; INT 22h-24h copied
into the PSP and put back when the program ends. The setup's choices: VGA, no sound, no joystick. START runs from
its C library start-up (its state at main equals the real game's), RP from main with its start-up's effects in C
(to its first tick equal to the real game's), DUEL and BATTLE from their start-ups; RP's sub-game exits run the
action program and then RP again from main, whose resume goes back into the hibernated run's C stack.
Frames pass with the frontend's clock (70.086 Hz) whenever a program looks at the time; the timer's interrupts
come from a model of the PIT (5.8), and the running program's handler runs at each once it has hooked INT 8; RP's and DUEL's INT 9 handlers (a keyboard joystick) are emulated
from the frontend's scan codes. frontend/main.c: SDL2, mode 13h through the DAC, the BIOS's keys; scripted runs
(OPENSAMURAI_KEYS, _SCANS, _SHOTS, _FRAMES, _FAST). The melee runs with its EGA driver, shown through the VGA
emulation; a melee that turns into a duel runs the duel after it (the launcher's rule). RP's saved games are
written to the game directory (Alt-S at the Home Option scroll). RP refuses to save on the original disk
(168c:0120 compares the drive's volume label with the floppy's): the game's directory is not it. The IBM speaker's and Tandy's
sounds are the frontend's `/AI` and `/AT` (5.8, 5.9), the AdLib's `/AA`, the default (5.10); the MT-32's `/AR` (5.11). Not yet: the joystick.

Seed 14 (three sub-games in one tick) needed two things: the test replaying each sub-game's own results (the
shared block at RP's next main entry; the test had been falling back to the next tick's), and FileOnDisk's putting
back of the critical-error vector as the game does it: `mov ds, [05D2]` before `mov dx, [05D4]`, so the offset is
the word at 05D4 of the saved vector's segment (DOS's, 072F:05D4 = 0000), not the saved offset. After the first
disk check INT 24h is 072F:0000, and that is what the next check saves.

### 5.8 Sound: the IBM speaker (ISOUND.SAM) — recompiled whole in source/isound.c, verified

The sound drivers are overlays with seven slots (the stubs' 100-106): 0 start, 1 play sound N (N even, to 56h:
a routine from the table at cs:0041), 2 the tick, 3 the fast tick, 4 and 6 nothing, 5 0. ISOUND.SAM has two ways
of sounding. The effects are tones on channel 2 of the PIT (mode 3, the speaker's gate and data bits of port 61h
open): a sound is a list of 10-byte steps (length, pitch, a random or swept part), advanced by the tick; the
fast tick moves the pitch between ticks. The songs are a three-voice PWM player that takes the machine over:
channel 0 becomes a 9470 Hz sample clock (mode 2, count 7Eh, the timer interrupt masked at the PIC), and a loop
polls its count for each sample and sets port 61h's two bits to the voices' mix, note by note, until the song
ends or a key is in the BIOS's buffer (or the joystick's button). The driver writes its own code at the start:
the joystick's read jumped over when there is none (0478), the PWM loop's latch of channel 0 made NOPs when
channel 2 does not count (04A4), and a song's `mov al, 7Bh` gets port 61h's other bits (04E1): in the C the last
reads the byte from memory, the other two keep their effect without the patch.

The timer handler (the library's, in every program: its bytes at a block B in the program's data segment, see
rp_rt.c) runs the frame routine every n interrupts; the frame routine calls the tick (at a fast rate of 4, the
VGA's, every 7th is left out: the sound's 60 a second), and a tick's answer asks for the fast rate (the interrupts
n times a frame, the fast tick at each; DUEL's handler has no fast tick) or back. The rate comes from the
program's start: it measures the frame's length with channel 0's count at 17 retraces. On a VGA with no sound
that is 17024 ticks (4 fast interrupts of ~3977), and the timer runs in step with the retrace, 70 a second.
The speaker's driver sets channel 0 to 19600 at its first start (a test of the chip it does once: a flag in its
code, cs:00FD), which START does just before it measures: the readings alias, the length comes out 24450 (or
23014, with the phase), the fast rate 6, and START's timer runs at 48.8 a second, set again to the retrace every
20 frame routines: about 46 frame routines a second instead of 70. START runs slower with the IBM sound, as in the
real game (DOSBox-X's START measures 24450 and 6, and runs 46.7 a second; the model of the PIT here gives the same
24450 and 6, and 45). The later programs' starts of the driver leave the chip alone: they measure the BIOS's rate
(START's end puts it back) and run at the VGA's 70 (DOSBox-X's RP: 17143 ticks, 4, 66.7 frame routines a second:
its interrupts come just before the retrace, and every 20th waits for it and loses one; here they come on it).

The frontend's timer is the PIT's: channel 0 as it is set gives the interrupts, and the running program's
handler is modelled from its block (the frame routine's counters as before); the PWM loop's polls move the time
on, the frames with it at the host's pace. The sound is the speaker cone's position averaged over each output
sample (44100 Hz), less its steady level. The IBM speaker's driver sits at D000 in the reconstruction (in the
real game it is at 19AA, where the no-sound driver is, and the programs higher by its size: every other segment
stays where the no-sound layout has it).

Verification: tests/soundtest.c replays the driver's calls from captures of the real game (oracle/cap_snd.sh,
snd_ev.py: every slot call with its sound, every port read and write, the ticks' answers, the songs' key checks;
the timer's interrupts that came inside a call run at its next port access) and compares every port write:
the title song under START (3378 calls, 130,393 events, the song's 116,000 samples) and 16 captures of 20,000
frames of the role-playing game from a new game (about 18,700 calls and 350,000 events each: 15 sounds, songs
ended by keys, 138 changes to and from the fast rate) identical.

### 5.9 Sound: Tandy's (TSOUND.SAM) — recompiled whole in source/tsound.c, verified

The Tandy driver writes the SN76489 at port C0h (three square waves and a noise, each with a 2 dB-step
attenuation), all from the tick: its tick never asks for the fast rate. Its start asks the BIOS for Tandy sound
(INT 1Ah AH=81h) and keeps the answer at [00CF], which nothing reads. Slot 4 selects a music (0-5); for 0 and 5 it
waits, in a loop, until the tick has silenced channels 0 and 1: the reconstruction's interrupts come when the host's
time goes on, so the loop's back jump (075A) calls asm_idle, where the frontend runs to the next frame (the drivers'
waits for their tick are patched so by work/snd_rec.sh). source/tandy.c models the chip (its channels at 3/16 of a
PIT tick). Verification: tests/soundtest.c on the title (4519 calls) and 8 captures of 20,000 frames of the
role-playing game (about 21,500 calls each, 22 sounds and musics) identical.

### 5.10 Sound: the AdLib (ASOUND.SAM of 1-10-94) — recompiled whole in source/asound.c, verified

The game directory's AdLib driver is a later one (AdLibSamurai 1-10-94) than the floppy's (10-25-89); the later one
is the reconstruction's. It drives an OPL2 at 388h/389h: at its start the chip's test (timer 1 set to FFh and
started, the status read 200 times: C0h after, 00h before; else AX = 41h), the rhythm mode on (BDh = 20h); each
write is delayed by status reads (30 before the register, 5 before the value). Its tick runs a sequencer of six
voices on a stack of its own (its data segment's) and asks for the fast rate while a pitch sweep runs; the fast
tick moves the sweeps. Its voices call routines through [bx+16h] (0310h, 075Bh: roots of the recompilation, with
its 47 sounds' table at cs:07FB). Slot 4 waits for the tick for musics 0 and 5 (the back jump at 0923, as Tandy's).
(The floppy's driver times a loop with the PIT at its start instead, and divides by the time: a PIT read here
takes a tick.)

source/opl.c is a model of the OPL2 from its documented workings (the log-sine and exponential tables, the
envelope's rates, the key scaling, the tremolo and vibrato, feedback and connection, the rhythm mode's phases
and noise, the timers), at the chip's 49716 samples a second. Verification: tests/soundtest.c on the title (4867
calls) and 8 captures of the role-playing game (about 21,200 calls each) identical; the chip model's sound of the
title's writes (tests/oplrender.c) against DOSBox-X's recording of the same frames (oracle-run's audio): the
short-time log spectra's correlation 0.984 (median of 810 windows of 93 ms), the same pitches, the same loudness.

### 5.11 Sound: the Roland MT-32 (RSOUND.SAM) — recompiled whole in source/rsound.c, verified

The MT-32's driver (MIDI_Samurai 10-30-89) talks to an MPU-401 at [137C] (330h): its hardware start (slot 5)
resets it (FFh to 331h, the acknowledgement FEh read from 330h) and puts it in the UART mode (3Fh, acknowledged);
each MIDI byte waits for the status's bit 6, is written to 330h, and what the interface sends back is read while
bit 7 says so. Like the floppy's AdLib driver it times a loop with the PIT and divides by the time (a delay's
count for its SysEx messages). Its voices call routines through [bx+1Ch] (03A5h, 07CBh: roots); slot 4 waits for
the tick for musics 0 and 5 (0x09C1). Its note table (DS:2816, a byte a channel) lies past its file's image, in
memory the launcher leaves as it was (the setup program's leftovers: in the real game BA 69 0A E9 56 FF 07 CB): the
first note off on a channel sends that byte as the note (E9h: not even a data byte). The reconstruction's memory
there is zeros: its first note offs are of note 0. source/mpu401.c models the interface; the MIDI goes to the host
(GameHost.midi) with its time, and the frontend plays it through Munt's libmt32emu (the extern/munt submodule, built
and linked in; the player's ROMs, recognized by their contents, from OPENSAMURAI_MT32ROMS, the user's data folder,
the program's roms folder or the game's), mixed with the rest in stereo; OPENSAMURAI_MIDI writes it to a MIDI file. The game's first SysEx writes "Sword of the Samurai"
on the MT-32's display. Verification: tests/soundtest.c on 8 captures of the role-playing game (about 21,400 calls each), the
driver's memory past its image as the real game's (MEM=, a dump of the oracle's memory before the driver starts):
identical.

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

- 2026-09-28: DUEL, BATTLE and MELEE recompiled whole and verified; the frontend plays the whole game (START, RP,
  the duel, the battle, the melee in the EGA's planar mode), saves included.
- 2026-09-28: START recompiled whole (the library too); 12 captures pass from main to exit.
- 2026-09-27: the melee translated over its data segment and corrected until it matched its captures.
- 2026-09-27: the battle's simulation reconstructed and verified against 96 captures (63,535 steps).
- 2026-09-27: the duel's simulation reconstructed and verified against 64 captures (211 duels).

- 2026-09-27: files inventoried, launcher protocol read, all programs and drivers unpacked and decompiled,
  oracle boots and plays a new game under script, catalog format verified.
