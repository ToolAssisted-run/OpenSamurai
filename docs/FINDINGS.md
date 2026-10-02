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
EXEPACK "Packed file is corrupt" A20 bug). Unpacked copies are made with the workspace's `unexepack.py`.

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
  anything else "Invalid exit # from RP". After MELEE: if shared[+28] != 0 and shared[+2A] == 1 → `duel.EXE`
  directly (02BF: `cmp [es:28],0 / jz back`, `cmp [es:2A],1 / jz duel`), otherwise back to RP. SU sets +28 to 0
  (1 only with its `/S` option), and RP clears it while it runs a melee and then the duel itself (177D:3805), so in a
  normal game RP always runs a melee's duel, with its introduction. After DUEL/BATTLE: exit 0 quit, else RP.
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
emulation; a melee is followed by DUEL only by the launcher's rule (§2: SU's `/S`), RP running it otherwise. RP's saved games are
written to the game directory (Alt-S at the Home Option scroll). RP refuses to save on the original disk
(168c:0120 compares the drive's volume label with the floppy's): the game's directory is not it. The IBM speaker's and Tandy's
sounds are the frontend's `/AI` and `/AT` (5.8, 5.9), the AdLib's `/AA`, the default (5.10); the MT-32's `/AR` (5.11). The joystick (5.12).

Seed 14 (three sub-games in one tick) needed two things: the test replaying each sub-game's own results (the
shared block at RP's next main entry; the test had been falling back to the next tick's), and FileOnDisk's putting
back of the critical-error vector as the game does it: `mov ds, [05D2]` before `mov dx, [05D4]`, so the offset is
the word at 05D4 of the saved vector's segment (DOS's, 072F:05D4 = 0000), not the saved offset. After the first
disk check INT 24h is 072F:0000, and that is what the next check saves.

### 5.7a One source of randomness

Each original program seeds its MS C `rand()` from the clock: START (1000:035F, INT 1Ah's tick count) and RP
(1000:04CA, the tick count; then `rand(3)` (seed & 0xFFF) times) once, DUEL once (1000:200A, `time() & 0x7FFF`),
BATTLE before each battlefield (1000:51DE, the tick count at 0040:006C), MELEE at each of its six calls of 1000:4E5C
(`ftime()`'s milliseconds' low byte: 100 values). In OpenSamurai these seeds are all drawn from one generator
(splitmix64 in game.c) seeded once per game_run from GameHost.seed, which the frontend takes from the system's
clock at its start (`time()`) or from OPENSAMURAI_SEED, and prints. Each draw keeps the range the original's clock
gave; the programs' own generators and everything they decide are unchanged. START's and RP's hosts answer their
only tick reads with draws; DUEL, BATTLE and MELEE have an optional `seed` in their hosts (duelexe.h, battleexe.h,
meleeexe.h), called at the seeding site (du_seed, ba_bios_ticks, ml_seed): without it (the oracle tests' hosts) the
clock's value is used as before.

### 5.7b The melee's pace on a virtual clock, and a clean start

MELEE is the one program whose pace depends on the machine's speed: its start-up speed test (1000:0708) counts a
loop's passes until its timer has counted 15 ticks (15,000 passes or more make the fast machine's melee), and its
main loop's reinforcement countdown counts passes, not ticks. Both read the tick counter through the host (sites
0x072B and 0x3BC2), and GameHost.meleeTickRead is called just before each such read looks at the clock, so that a
host with a virtual clock can charge the read what it cost on the original machine. The frontend's virtual clock
(OPENSAMURAI_FAST) and gametest's charge 10 us at 0x072B and 690 us at 0x3BC2, 20 us for any other look: the fast
machine's melee, about 21 passes a tick as in the oracle (at 20 us for every read the scripted runs had the slow
machine's melee, flag DS:342A set, and about 700 passes a frame). A real clock needs nothing.

game_setup clears the sound driver's segment (D000:0000-FFFF) with the rest of memory, and the launcher's
read-ahead key and port 3DA's retrace toggle: the MT-32's driver reads a note table past its file's image, which a
game before it in the same process would otherwise have left there.

### 5.7c The dissolve's pace

MGRAPHIC's dissolve (slot 10, 0408) copies a page to the screen a byte at a time in a 16-bit LFSR's order (shift
right, 0xB400 on a carry, the values above 0xFA00 skipped, offset = value − 1). It is START's title and RP's windows
with a full-screen picture (window +31 or +37 = 2, drawn by 1EAA:04A2 through 1EAA:0B66 with page 1): the death
messages (windows 14, 17, 18, 59, 60, 64, 68, 71, 74, 119, 120, 124, 138, 149, 150, 173-175, 200, 220), where it is the
dead character's portrait dissolving away. Its pace is a busy wait (`mov ax,bx / dec ax / jnz`) calibrated on first
use: the smallest count bx with at most 0x215 (533) steps between two vertical retraces, each step reading 3DAh. So it
takes about two seconds on any machine fast enough, and was instant in OpenSamurai, where a busy wait costs nothing.
game.c runs it itself (`asm_graphics_slot`) at the oracle's pace: the title's first dissolve changes the screen from
frame 1953 to 2068 in DOSBox-X, 116 frames, 552 bytes a frame (the copy has no port read in its steps and runs a
little faster than the calibration's 533). A forced window 60 in RP now dissolves the portrait in 116 frames too.

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
started, the status read 200 times: C0h after, 00h before; else AX = 41h; it ends with 04h = 60h, and its "flags
reset" goes to register 60h instead of 04h, so only the chip's own rule, that a timer's mask bit clears its flag,
leaves the status 00h for the next start: the captures read 00h before every test, and a model without the rule
failed START's second test after a new game, "No AdLib sound board found"), the rhythm mode on (BDh = 20h); each
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

### 5.12 The joystick (MISC.EXE) — recompiled whole in source/misc.c

MISC's slots 95-97 are the joystick: 95 the button N (port 201h's bit 4 + N, low when pressed), 96 the centre, 97
the position. An axis is read by timing: a write to 201h starts the one-shots, and a loop counts the reads while
each axis's bit is 1 (the count grows with the stick's position; the loop gives up after 65535). The centre is the
count when 96 is called; 97 reports each axis as a signed byte, -127 to 127, against the most extreme count seen
on that side since the centre (a count past it is a new extreme, reported as -127 or 127). The setup asks "Do you
have a joystick" (shared+34 = 1), then "Center joystick, then press fire button 1" (the centre, 96) and the upper
left and the lower right (97 at each: the extremes), kept in MISC's data (MISC stays in memory): the programs read
the stick against the setup's calibration. Uncalibrated, a centred stick reads as far right and down (a centre of
0), and the strategic map's cursor runs off the map: its window list becomes a pointer to segment 0, which the
drawing loop (2339:070C) walks for ever. The launcher here calibrates as the setup does, before the first program. READ.ME: Alt-J turns the
joystick on and off in the game.

The frontend: a joystick plugged in makes the setup's answer yes (/NJ: no), and the setup's calibration is done with
the model's centre and corners; MISC's recompiled code answers slots
95-97 (the tests keep the captured answers), and the game port is modelled: after a write, each axis's bit reads 1
for 20 + the position x 400 / 65536 reads, the buttons' bits 0 while pressed, all 1s with no joystick plugged in;
a read of the port lets the time go on, as a look at the keyboard does. Not verified against the real game (the
oracle's DOSBox-X has no joystick to move); the same code and data as the real MISC.

### 5.13 The Windows build

Cross-built with MinGW-w64 (tools/x86_64-w64-mingw32.ini, tools/package-windows.sh): one opensamurai.exe with SDL2
(its static MinGW library), Munt and the C++ runtime linked in, a Windows (GUI) program: its messages in message
boxes, and started without a folder it takes its own as the game's if the game is there. What had to change: the
names of the MS C library's functions RP was recompiled with that MinGW's headers or Windows' libraries have too
(_filbuf, _flsbuf; FillRect, a Windows function) are renamed in rp_rt.h; the DOS seeks' offsets (CX:DX) are made
signed explicitly (a long is 32 bits on Windows, 64 on Linux).

Verification, under Wine: every oracle capture through the Windows build's tests and the Linux build's (780 runs:
START, DUEL, BATTLE, MELEE and RP, run and step, the battle's set-up, the duel's, the battle's and the melee's
simulations, the four sound drivers): the outputs the same, line for line; the scripted sessions of the game
(30,000 frames of random keys, each sound driver, with and without a joystick): every screenshot, the sound and the
MIDI the same, byte for byte, but the MT-32's sound (Munt's floating point with Windows' and Linux's C libraries:
0.9% of the samples differ, by an RMS of 1 in 212); a saved game written the same, and restored the same.

### 5.14 The rules, read out of the verified code (the game guide)

Read out of the recompiled programs (which run the captures identically) and the unpacked executables' data
segments while writing the game guide "Sword of the Samurai: The Hidden Game". Each item says how far it is
checked: *code* = read from the verified recompilation, with no capture made of the case; *reading* = an
interpretation of the code, not checked.

Chance (*code*). Every program uses MS C's `rand()` (state × 214013 + 2531011, bits 16-30), each seeded once:
START and RP from the BIOS ticks (RP once per career, then `rand(3)` (seed & 0xFFF) times), DUEL from `time()`
(whole seconds), BATTLE from the BIOS ticks, MELEE from `ftime()`'s milliseconds, which DOS counts in hundredths:
100 seeds. RP's generator state is in its data segment, saved across the fights: the fights do not disturb the
career's stream.

The crest quiz (*code*). shared+2E = 1 passed, 0 failed. RP sets the reign length DS:812E = 24 or 4; below daimyo
a countdown steps the reign counter every 15 turns; at length − 6 the lord falls ill, at − 3 worse, at length he
dies (passed: 270/315/360 turns = 27/31.5/36 years; failed: never/15/60 turns). A rival who succeeds a lord starts
the counter at 4. The succession (24E2:0004) tests shared+2E first and, when 0, goes to the game-over prompt
(1568:00E2): no succession, whichever way the lord goes. The rivals' action scores weight the temperament term by
(length − counter) / length, so it fades six times faster after a failed quiz. A failed quiz also skips the
province map: START forces Sagami (0x29, 1000:01F4).

Character creation (*code*). Name: at most 20 characters (62 pixels), empty = "Nameless One". Attributes:
`clamp(DS:0420[age group] + province value + DS:042C[rand(20)], 1, 128)` for swordsmanship (DS:1F64), generalship
(1F96) and land (1FFA); honor (1FC8) is clamped to 1..96 and then gains DS:0502[heir | female<<1 | hostage<<2]
(2, 8, 2, 0, 0, 0, 4, 0) for each family member whose holder is the character; troops = clamp(honor × land / 128,
1, 128). Age groups 15-20 .. 71-80: −32, −16, 0, +16, +32. The roll table: −48 5%, −32 10%, −16 15%, 0 40%,
+16 15%, +32 10%, +48 5%, and for the player (133F:08AE) a negative roll is 0. Every province's values add up to
256 but Mino (Oda) and Sagami (Hōjō), 272; the 120s are Izu's swordsmanship, Kai's generalship, Totomi's honor,
Mutsu's land. Difficulty 0..3 starts the score at −70/−40/−10/0 and turns an aggressive rival neutral on Tanto, a
cautious one neutral on No-Dachi. Temperament by age group (aggressive/neutral/cautious): 50/40/10, 40/40/20,
30/40/30, 20/40/40, 10/40/50 %. The age group (133F:0006) is rand(10) through the jump table at 133F:012C:
at rank 1, 20/30/30/10/10 % for groups 1-5 (at rank 2 group 1 becomes 2, at rank 3 groups 1-2 become 3). The player
draws one too, so a hidden −32..+32 shifts all four starting attributes, and 1E59 then sets the age word (+2, tenths
of a year) to 0x96, 15 years. The family advantage (shared+30E 0..3 → 1568:05E8 swordsmanship, 0614 generalship,
0434 honor, 0590 land) adds 32, clamped to 1..128 (honor 1..112), after 133F:063A computed the troops, so the first
troop count ignores it. At rank 1 the player is rolled first and each rival (all in the player's province, 1C39) is
rerolled while his score (133F:0D3C) is not above the player's (1D44); the advantage is already in, so an honor
advantage (+48 score) raises the bar far more than swordsmanship or generalship (+8). The set is rerolled unless
the player is fourth (1DFA), which the per-rival test already guarantees. Difficulty and name play no part. The
ceiling is 128/128/112/128 (honor gift only: the roll caps honor at 96, a rolled 80+ ends at 112), reachable in 10
provinces; exact odds over the age group and rolls: Sagami 1 in 4,444, Settsu 1 in 8,889, Hyuga/Etchu/Yamato 1 in
9,697, Mino never (land 40); with 96 troops too (rolled honor 96) Sagami 1 in 13,333, Hyuga/Etchu 1 in 19,512. A scan
of all 65,536 RP seeds (srand(ticks), then (ticks & 0xFFF) + 3 rand() calls before 133F:1B40; the harness matches the
w_V21 capture's four characters) with Hyuga + honor: 9 seeds give the ceiling, 3 with 96 troops (0DFA, 959F, FF94);
their rivals come out at 108 honor (wife + heir), 128 land, 108 troops. Played end to end (the frontend, OPENSAMURAI_SEED=7582,
fast mode: the quiz passed, Hyuga, Tanto, honor): RP gets 0DFA and the four characters are the scan's row. Best expected total: Sagami + honor 308 (troops
14), Mino + land or honor 306 (16); the best 256-point provinces reach 293 (Hyuga/Etchu + honor, troops 26).

The duel's opponent (*code*; the practice captures have equal swordsmanship, a bonus of 0). DUEL 1000:0010: skill =
clamp(2 × shared+36 + bitlength((unsigned)(shared+6A − shared+68) >> 4), 0, 7), where RP puts the player's
swordsmanship (DS:7CFA) at +68 and the opponent's at +6A (23BB:019E). The shift is `shr`: an opponent weaker by any
amount gives 0x0FFF, +12, skill 7 at every difficulty; 0-15 stronger +0, 16-31 +1, 32-63 +2, 64-127 +3. The
aggression bias DS:4DBE = clamp(shared+312 + skill/2 − 1, −1, 0), +312 = the opponent's temperament (0 for someone
without a record). Opponents: a rival or lord's own swordsmanship; the bold deed's swordsman DS:05FC[difficulty] =
77/90/102/115; road duellists DS:2360[rank] = 64/80/96 (the series of three: +0, +16, +32); kenjutsu (the player's
swordsmanship below 96) the player's + 16 with shared+36 lowered by one (not below 0) for the duel. The honor
reward of bold deeds and road encounters has the same `shr`: bonus = clamp(((DS:05FC or DS:2358[difficulty] (the
same values) − swordsmanship) >> 4) + 16, 12, 24), half of it gained: a weaker opponent gives the most (24/2 = 12),
a stronger one 8-11; the lower limit is never reached. The skill's effects (5.1): the reaction delay random(10 −
2 × skill) frames (0 from skill 5), the wind-up 5 − skill frames (0 from 5), the won't-guard windows
`DS:1E64[skill/2] & (frame >> 4)` (masks 0x841/0x101/0x001/0: for skill < 6 every odd 16-frame window, and for
skill 0-1 none of the windows 64-127 (102-205 s), skill 2-3 none from window 256 (410 s)). A parry: the attacker
holds 4 frames, the defender 2. An over-the-shoulder hack cannot be parried and wounds twice half of the time
(below 3 wounds). 32 state entries on the bottom line = retreat.

The melee (*code*). Enemy skill DS:355C = clamp(2 × shared+36 + (shared+3C == 5) + (mission == 5) + 2 × (DS:353A
== 2), 0, 7), but DS:353A (the location type, 2 = village) is read at 1000:0197 and only set at 1000:027B from
the mission table DS:3452: it still holds the image's 3, and the village's +2 never applies. (shared+3C = 5 as the
lord's castle: *reading*, from RP's place numbering.) Each guard's class DS:7353 = DS:410E[skill][rand(8)] (the
rows: s0 all 0; s1 1/8 class 1; s2 3/8; s3 5/8; s4 7/8; s5 6/8 class 1, 2/8 class 2; s6 3/8 class 1, 5/8 class 2;
s7 5/8 class 2, 3/8 class 3); the player, the tax collector and the rival lord are class 3 (1000:4AE6, 4A1A).
Wounds per blow DS:235E[class][rand(8 − v)] (rows 1,1,2,2,2,2,2,2 / 1,1,2,2,2,2,2,2 / 1,1,1,1,2,2,2,2 /
1,1,1,1,1,1,2,2), v = 3 for the player, the victim's class for a guard facing its attacker in a melee exchange,
else 0: the player always takes one wound; a guard dies of one blow with 75/71/33/0 % (facing) or 75/75/50/25 %
(not). Attack recovery (DS:2338[class] + DS:2332[weapon] + wounded + DS:233E[class][rand(8)] (+ rand(3) for the
AI)) × 12 ticks; weapons sword 2, spear 3, bow 6, musket 9, shuriken 1. Arrow hits ((class − 2 × offset) × 20 +
80) %. Recognition (7 − skill) × 30 + 180 ticks (+60 with the alarm). Guards aim at the player's tile (7 − skill)
entries back in an 8-entry history. Quotas: g = DS:3446[skill] (10..24) + rand(7), doubled at skill 6-7. The
reinforcement countdown DS:9D8E counts loop passes, so a faster CPU brings them sooner (*reading*: not measured on
a real machine). DS:3567 skips the player's wounds; its only write (1000:98D6) clears it: a debug switch that
cannot be turned on.

The battle (*code*, 5.2 and the workspace's reports/BATTLE.md). The enemy general only chooses the formation; the
units follow their routes or hold and react to what enters their ranges. Damage v = 4 ± (2 − difficulty) + (men −
64)/8 + the strength ratio + (morale − 64)/16 + (generalship − 64)/16 + 8 rear / 6 flank + 2 for musketeers >
cavalry > infantry > musketeers + 4 musketeers within 32 px + the footing in melee (to −16), clamped 0..12, +
`rand() & 7`, into a table, doubled with fewer than 5 units. A unit mostly in woods is out of the visibility map.
In a campaign (177D:0688) a defeat (shared+4E) is only message 0x4C; a concession (R) is −32 honor, message 0x3A
and the desertion check (1568:0818); the men of units that left the field are not losses.

The difficulty (*code*), shared+36 = 0..3 (Tanto, Wakizashi, Katana, No-Dachi), chosen in START, saved, copied to
RP's DS:853A, never changed. RP: the ending's score base DS:1F22 = −70/−40/−10/0 (Shogun points = score × 10 +
950) and its blade name (DS:1F2C), HONOR.SCL keeps it; the temperament filter of 133F:063A for every character
rolled; the capture check after fleeing (1568:03B0: released always / 2 in 3 / 1 in 3 / never, captured = seppuku
and the heir, no heir = game over); the bold deed's swordsman and the rivals' bold-deed odds `rand(DS:05FC[d]) <
rand(sword)` (a failing rival dies); the honor reward (DS:05FC/2358, above); kenjutsu one step lower. DUEL: skill base
2d. MELEE: skill base 2d (classes, muskets from skill 4, recognition, aim, room spawns (s × 10 + 20) %, castle
reinforcements (s × 10 + 10) %, quotas). BATTLE: 2 − d on each damage roll (+ for the player, − for the enemy),
enemy generalship 16d + 32 in battle types 0-3 and 7, else shared+6E × (1 − (2 − d) × 20 %). The starting morale
steps for generalship add up: −15 below 25, −5 at 25-48, +5 at 72-96, +15 above 96.

The challenge (*code*, 177D:16D0 (challenger c, target t)). The player's challenge first moves t's favour balance
towards him by 12 (1568:06FC(0, t, 12)). An NPC target decides with two simulations on the working block (saved
to 6C94 and restored): refusal = t's honor − clamp(honor_c, 32 + 6 × difficulty, 128), rescore (133F:09CA),
R = (128 − honor_t) × t.+5E / 128; fight = 133F:1456(t, 128·sword_c / (sword_c + sword_t + 1), 0) and
133F:1456(c, 128·sword_t / (… + 1), 1), rescore, F = t.+5E × honor_t / 128; t refuses when R > F (no random
number). The rescore makes +5E a deficit (≤ 0): Σ over the characters ranked above of (score_i − score_j) ×
DS:7F34 / 8, with score (133F:0D3C) = (land/4 + clamp(land, 0, troops' + 16)/3 + honor + troops') × 24/16 + gen/4 +
sword/4 − 2 × (16 − honor) below 16 honor (troops' = troops, ×2 at rank 3). So t refuses when (128 − h) ×
deficit(refuse) < h × deficit(fight): the honor weight multiplies the fight's loss, and an honorable target is the
one that refuses; a target first after the fight never refuses, one first only by refusing always does; with the
reign counter 7F34 = 0 every deficit is 0 and nobody refuses. 133F:1456 with an heir (1568:0048 ≠ −1) takes the
succession path whatever the percentage (the heir's stats 64..128/128 by heir age: < 15, 15, 21, 31, 51, 71 years),
so the swordsmanship ratio only counts for heirless characters. The difficulty floor 32 + 6d only matters when the
challenger's honor is below it. A real refusal costs t clamp(honor_c, 32, 128) honor (the floor has no difficulty term), message 0x5C
(player challenger, who is sent home, 1568:0964) or 0x58 (NPC challenger, sent home), and the desertion check
(1568:0818) for t. The player refusing an NPC's challenge (menu 0x5D): clamp(honor_c, 32, 128), message 0x5E,
desertion check. Accepted: the player's duel (23BB:019E, sword ±4 on return) — won: 0x66 and the opponent dies
(133F:1456(x, 128, 1)); fell: the capture check 1568:03B0; retreated: −32 honor, 0x3A, desertion check; NPC vs
NPC: `random(sword_t) < random(sword_c)` ⇒ the challenger wins (0x95, sword +4), else the target (0x96), the loser
dies. Every outcome ends in the tail (1B15): if ch[t].+34[c] > 0 the challenger loses twice it in honor, and both
entries are zeroed. The +34 table (1568:0670(a, b, v) moves ch[b].+34[a] − ch[a].+34[b] by v) is a ledger of who
owes whom: a caught kidnapper or traitor gets ch[culprit].+34[victim] += 16 (177D:1E87, 2224), the rival helped
in a defence ch[t].+34[helper] += half the troops lent (177D:08D5).

The ending (*code*, and seen: OpenSamurai running it with the player given all 48 provinces at rank 3, the score set
on the statistics screen). The scored ending 2567:0000 comes from the Shogun battle won (1B28:0148; lost: window
0x10E and the game-over prompt) or from the main loop at rank 3 on the player's turn when 1568:0BAC(0) (provinces
owned) = 48. Score DS:3DA2 = (signed byte) DS:1F22[d] (−70/−40/−10/0) + heir (1568:0048(0) ≠ −1: +50 if older
than 15 years, else +30) + Σ v × w / 128 (2567:0B2E, truncated) for honor 40, troops 44, land 34, generalship 34, +
(241 − S) × 54 / 241 if S < 241, S = the troops of characters 1..count−1 alive (shown × 100); no province term
(the manual's "Province Control" is only displayed). Shogun points = score × 10 + 950. The verdict windows
0x110..0x117 for score < 50, 51-80, 81-120, 121-152, 153-184, 185-224, 225-255, ≥ 256 — a score of exactly 50 has
none (seen: straight to the Scroll prompt) — each with its WINPIC picture SHOGUN01..08 (WINDEF +2C indexes the
WINPIC names directly). Honor is clamped to 1..112 by 1568:0434 before the family bonuses DS:0502 are added
back; the index is heir | female << 1 | bit 12 << 2, and bit 12 is set in a wife's word (0x1801 + …), so 4 is
the wife's bonus: wife 4 + heir 8 + two children 2 + 2 = 16 makes 128 honor possible, and the maximum score is
256 on No-Dachi (Tanto 186, Wakizashi 216, Katana 246). The other endings go to 1568:00E2 without a score: the
player's death without an heir (133F:0006 with index 0), refusing a demanded seppuku (window 0x87), a failed
usurpation or assassination of the lord (0x87, with 0x3D first when random(100) ≤ 66), conquered as daimyo
(0x134), the Shogun battle lost (0x10E), the lord's death after a failed quiz (24E2:0004). The pictures: MGRAPHIC's
slot 25 is a `retf` (the CGA palette tables are ignored); a 16-byte picture palette selects entries of the
driver's master table (its segment D5, offset CE, 128 × 3 bytes, the first 16 the EGA colours), and a
byte-per-pixel picture's values index that table.

Rebellions (*code*, 133F:0EBA, the empty rival slots filled on the player's turn at rank 3 when the countdown DS:631A
is 0, reset to random(2) while a slot stays empty): per empty slot, when DS:04BA == 1 (cleared at 48 provinces),
the player owns more than 8 provinces, DS:7B9A is even and random(400) > 2 × generalship + troops: a random
province of the player's other than the home one becomes the slot's (133F:0006(slot, 1, 3), favour −30 towards the
player through 1568:06FC), then N = (random(8) × 5 + 15) × provinces / 100 (at least 1) more, each the first
province of the player's (not the home one) adjacent to the rebel's (133F:13E4); 133F:063A rolls him for them;
window 0x10F. No cooldown: the countdown is only reset (random(2)) while a slot stays empty, and every empty slot is tried in the same call. Else a great clan (6/7, 1B28:1B68) or a new clan in a free province next to a daimyo's takes the
slot.

Ageing (*code*, 1568:013E every turn, characters 0..4 of the master block): family words + 0x2000 (a tenth of a
year); age (+02, tenths) + 1; when age % 10 == 0 (years = age / 10): character 4 honor +1 (0434), generalship +1
(0614), troops +2 (05BC, clamped to land), swordsmanship +1 (05E8); years ≥ 60 swordsmanship −4, ≥ 75 generalship
−4, ≥ 90 and the player DS:8546 = 1 (only Retire and Seppuku); then swordsmanship and generalship clamped 1..128.
The lord (5) does not age here.

Marriage (*code*). Courting the announced bride (119E:16FE, DS:7F4A = −1): random(100) < 50 ⇒ window 0xDF (item 0
= rescue): melee 0008(0x19, 0, 0, 0, DS:05FC[d]); won ⇒ the wedding; fell ⇒ 1568:03B0; ran away ⇒ −32, 0x3A,
desertion check. Else each rival without a wife (1568:009C = −1, 1568:0FD8 = 0) courts when random(128) ≤ DS:7B32 −
honor + 96 (he goes to the father, action 0x19); rescore (133F:09CA); the suitors (and the player) in rank order,
window 0xE0 with their names: the first wins (0xE2 the player, 0xE3 a rival: 23F7:0C88), 0xE1 when the player is
alone. The wedding 23F7:0D8C: the wife's age clamp(random(26) + 15, 15, the player's years); honor + (DS:7B32 −
1568:051E(0)) / 2 through 0434, then +4 directly; land − DS:792C (the dowry, DS:7B32 / 4); window 0x9B; the
desertion checks 1568:0788 and 0818. The offer (23F7 random event): DS:7B32 = 16 × random(6) + 20, 15 turns.

Taking the lord's place (*code*). Usurpation (177D:3132 at the lord's castle): battle 00BA(6, 5, troops, 7ED8)
lost ⇒ window 0x87 and game over; castle melee 0008(5, 5, 5, 1) with shared+28 cleared for it, player fallen or no
duel ⇒ (0x3D with the difficulty's odds) 0x87, game over; duel 019E(2, 5, 7EDA) lost ⇒ 0x3D, 0x87, game over; won ⇒
0x89 and 24E2:0004(1): window 0xCB and 133F:1B40(3), daimyo at once. Assassination of the lord (1B28, action 0x91,
t = 5): melee 0008(1, t, location, 1, 0, 2) (duel if it asks: 0x88, 019E(2, t, sword)); won ⇒ 0x89, DS:8F52 = 2
(murdered) and 24E2:0004(0), the ordinary succession: message 0xAE, then at rank 1 24E2:009B (the top-ranked
character becomes the lord) and at rank 2 24E2:014C (the succession crisis). 24E2:0004 tests shared+2E first in
both cases.

Promotions (*code*, 133F:1B40(rank)): the characters are regenerated from index 0 only at rank 1 (a new game), from
index 1 at a promotion, so the player keeps the record (name, age, family) and is scaled, clamped 1..128: to
hatamoto land × 2/10, troops × 2/10, honor × 75/100, swordsmanship × 6/10, generalship / 2; to daimyo honor ×
75/100, land / 2, troops = 1568:0A68 (the daimyo's limit), swordsmanship × 6/10, generalship / 2. The family
advantage (shared+30E) is applied inside the loop at index 0, so only at creation. The lord's five attributes are
set to 122.

Destinations (*code*, 261B:0136): the walk's tile becomes DS:80DE only on the home map (rank 1: 0x66..0x69 the four
estates, rank 2: 0x6A..0x6D) and for the lord (0x6A at rank 1, 0x1D at rank 2), and on the enemy clan's map
(0x66 / 0x6A ⇒ 4, DS:246 = 1); the loader turns every other castle and estate tile into 0x35. Terrain on the 48
maps (MAP1..48.DAT): every province has 1-4 cells of 0x14 (the bandits' fortress) except Izumi, the only one with
ferry tiles (0x28/0x29); bridges (0x13) 116 cells in all, 12 each in Omi and Mikawa.

The travel encounters (*code*; the terrain names from MAP1.DAT's grid against OpenSamurai's screen of Satsuma).
The walking loop 2706:0000 zeroes the trip's count DS:3DB4, and whenever `time()` passes a deadline 5 s ahead
(about every 5-6 s, walking or not) calls 2706:0C0A with the tile under the figure (grid 20 × 20, cell 16 × 10 px,
`map[(x/16)·20 + y/10]`): random(100) ≥ 50 ⇒ nothing; class by tile 0x35 open country 0, 0x34 road 1, 0x32
coast / 0x33 river 2, 0x08 forest and hills 3, 0x16/0x17 village 4, 0x14 the bandits' fortress 5, 0x18 shrine
6, 0x13 bridge 7, else 8; type = DS:2368[class][random(8)] (rows 1 1 2 7 / 2 7 10 10 / 1 2 6 6 / 1 1 5 8 9 /
2 2 3 4 / 1 5 5 5 5 5 / 7 9 / 6 7 7 8 / none, zero-padded); type 0 or 3 accepted this trip ⇒ nothing; menu window
DS:23F8[type] (0xF1..0xFA, item 1 = fight; only a fight counts). Types 1-6 and 10: melee DS:2424[type] (17, 18,
19, 20, 21, 22, 23) with enemy swordsmanship DS:2360[rank] (64 samurai, 80 hatamoto), type 6 with shared+60 = 1
and a duel with the pirate leader when the melee asks for one (window 0x101); types 7-9: duels (background
DS:243A: 0, 1, 1), type 8 three in a row (+0, +16, +32; windows 0x103-0x106, the reward doubled). Win: honor
clamp(((DS:2358[d] − sword) >> 4 unsigned) + 16, 12, 24) / 2 through 2706:1026, which halves any honor change with
troops (ch[0].+2C = 1) and zeroes it disguised (2); ran away (shared+62): message 0x3A and −32 through 1026,
skipped altogether when disguised; fell (shared+4E): the capture check 1568:03B0 (released on Tanto). Speed
classes 3DBE: 0x08/0x33 slow (1), 0x34/0x13 fast (4), others 2. The travel mode never changes the odds.

OpenSamurai gap: rp_rt.c's `rp_fopen` is a stub, so the Scroll of Honor (HONOR.SCL) is neither read nor written.

RP's random stream (*code*): the resume path after a fight (23BB:0222 after the context restore) does not call the
seeding (1000:04C4): the generator state (DS:34FC) comes back with the data segment, and the resume only draws
`random(8)` for the patience line. (reports/RP.md §6 says it reseeds; it does not.)

The machines (*code*, and 5.8 for START). The duel (7 frames) and the battle (17 frames) run by the retrace: at
60 Hz (CGA, EGA, Tandy) 8.6 frames and 3.5 steps a second against VGA's 10 and 4.1 (*reading*: not run at 60 Hz).
MELEE's retrace check scales by /32 where BATTLE's has /16 ((count × 17/32)/3977 = 2, outside 4..6), so it always
runs a plain 60 Hz timer. RSOUND's first note-off on each channel sends the setup's leftover byte (BA 69 0A E9 56 FF
07 CB) as the note; BAh, E9h, FFh and CBh are status bytes (what the MT-32 makes of them: *reading*). RP's Alt-J
recalibrates the joystick (1CEC:1938, only with shared+34 = 1); READ.ME says it switches it on and off. The real
game cannot reach the uncalibrated strategic-map hang of 5.12: the setup calibrates whenever it enables the
joystick.

### 5.15 Cheats (source/cheats.c) and two frontend fixes found with them

The in-game menu's cheats act on the original programs at the places the rules above name, through the recompiled
functions' entries (each program's FN hook, before the first instruction, SS:SP at the return address) or RP's frames.
Off, each changes nothing: with every cheat off the frontend shows the same frames as before them, and the oracle
comparisons give the same results. None touches the copy protection or its consequences (shared+2E, RP's DS:812E and
DS:7F34).

- Invulnerable (melee): MELEE's own debug switch DS:3567 (5.14), set at the entry of the wound 1000:A7CC, which skips
  the player's wound increment; the stagger (state 0x2C) remains.
- Invulnerable (duel): the wound 1000:1624(fighter) skipped for the player (fighter 0): no wound, no knock-back, no
  fall. DUEL's FN hook may skip a function (its functions are void; the hook pops the near return address).
- One-blow kills: the duel's opponent (fighter 1) enters the wound 1000:1624 with three wounds (DS:4DBA), so that
  the blow is his fourth and he falls; in the melee any entity but the player enters the wound 1000:A7CC with one
  (DS:9E18 + e), so that the blow (1 or 2 wounds, DS:235E) brings it to the 2 at which it dies (1000:13B8).
- Invulnerable troops / troops never rout (battle): at the damage pass 1000:0A1C(unit) a player unit's gathered
  damage (+2A) is zeroed; at the rout check 1000:2424(unit) a player unit's step morale (+30) below 0 is lifted to 0
  (a unit already routed, state 11, is left alone: the check would rally it). R's retreat sets state 11 and morale 0
  directly, so it still works. A unit that loses a figure and cannot fit its smaller block is removed by the damage
  routine itself (1000:0A1C's try_turn): a loss, not a rout.
- Faster troops (battle): every unit moves through 1000:2802(unit) (turn by at most the turn rate +22, march by the
  speed +20, or the formation route's pace DS:26D8 for state 4); for the player's units the speed (once a step: the
  drawing pass 1000:49C8 recomputes it), the turn rate (from the type's DS:1504 + 12 × type) and the route's pace are
  multiplied at the entry, the route's pace put back for the enemy's.
- Faster walk (map): the walking loop 2706:0000 waits for DS:3038 > 2 (three frames) before each step; k − 1 of every
  k steps go without the wait (the loop is known by its caller's return address, 3DE7:0214, at BP + 2).
- No travel encounters: the roll 2706:0C0A (every five seconds of the walk: random(100) < 50, then the tile class's
  row of types, random(8)) offers an encounter only while the trip's count of accepted ones, DS:3DB4 (zeroed at the
  walk's start, 2706:0006), is below 3: the roll finds it at 3 (the dice are thrown as before; the count it had comes
  back if the cheat goes off during the walk).
- Faster walk (melee): the player's sub-step 1000:876E(0) takes 2 or 4 pixels instead of DS:3564 (dividing what is
  left of the tile's four), the move timer DS:0058 shortened for the rest of the factor; the others keep DS:3564.
- Stop ageing: at the entry of the ageing 1568:013E, the tick it is about to add is taken back from the player's age
  (master block +02) and the family words it will age (the first n of the master block, n = the non-empty words of the
  working block, as 1568:000A counts them); an age on a whole year is let through one tick first, so that the year's
  changes (5.14) never come round.
- Max honor, troops, land, swordsmanship, generalship: held at 128 in both character blocks (master DS:653E, working
  DS:7CE8, player record +0E..+16) at every RP frame. 128 is every routine's cap: 1568:05BC (troops), 0590 (land),
  05E8, 0614 clamp to 1..128 at every rank; 1568:0434 clamps honor's base to 1..112 and adds the family's bonuses
  back (wife 4, heir 8, other children 2 each), so 128 is the most any character can hold.

Two frontend bugs the cheats' tests found:

- The battle never ran in the frontend: BATTLE's INT 8 handler is 1883:015F (its `sti`; the far pointer it installs
  is at 1883:015B), and game.c counted the battle's frames only while INT 8 pointed at 1883:0160, so the waits never
  ended after the formation screen (the battle tests answer the frame counter from their captures and did not see
  it).
- RP's keyboard joystick on the travel and strategic maps (168c:0D36 / 0D8E: its bytes DS:339A-33A3 cleared,
  NumLock off, INT 9 saved into the handler's chaining jump at 168c:0EC0 and pointed at 168c:0DA8) was a stub, so
  game.c's emulation of the handler never ran for RP: a held arrow walked only with the keyboard's repeated keys. The
  hook is now made; the handler's collapsing of repeated keys in the BIOS buffer is not emulated.

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

- 2026-10-02: the dissolve paced as in the original (5.7c: a dead character's portrait fades in two seconds); the
  launcher's MELEE → DUEL rule read the right way round (§2: the lord's assassination was fought twice).
- 2026-10-02: cheats (5.15); the battle runs in the frontend (its timer handler is 1883:015F, not 0160); RP's
  keyboard joystick hook made (the travel map's held keys).
- 2026-09-28: the rules read out of the verified code for the game guide (5.14): the duel's unsigned skill
  shift, the melee's dead village bonus, the campaign's concession price, the machines' differences.

- 2026-09-28: DUEL, BATTLE and MELEE recompiled whole and verified; the frontend plays the whole game (START, RP,
  the duel, the battle, the melee in the EGA's planar mode), saves included.
- 2026-09-28: START recompiled whole (the library too); 12 captures pass from main to exit.
- 2026-09-27: the melee translated over its data segment and corrected until it matched its captures.
- 2026-09-27: the battle's simulation reconstructed and verified against 96 captures (63,535 steps).
- 2026-09-27: the duel's simulation reconstructed and verified against 64 captures (211 duels).

- 2026-09-27: files inventoried, launcher protocol read, all programs and drivers unpacked and decompiled,
  oracle boots and plays a new game under script, catalog format verified.
