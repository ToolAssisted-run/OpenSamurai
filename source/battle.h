// The army battle (BATTLE.EXE). Units are rectangles of 1-8 figures on a 320x200 field (positions in
// 1/16 pixel, angles in 1/65536 turn); every step (about 17 video frames) each unit runs its state
// handler, damage is applied and morale checked. The player only gives orders to his units; the enemy
// side runs on the same autonomous logic after its general picked a formation.
#ifndef OPENSAMURAI_BATTLE_H
#define OPENSAMURAI_BATTLE_H

#include <stdint.h>

#define BATTLE_MAP_W 84          // terrain and visibility grids: 4x4-pixel cells with a 2-cell border
#define BATTLE_MAP_H 54
#define BATTLE_RECORDS 25        // unit records 0..24 (0 unused)
#define BATTLE_TABLES_SIZE 0x1B28

// A unit record, 64 bytes, laid out as in the original (DS:5E2A + 0x40 * index)
typedef struct
{
  int16_t id;          // +00 own index
  int16_t state;       // +02 0 free/dead, 1 defending, 2 idle, 3 selected, 4 formation route, 5 ordered move,
                       //     6 projectile flying, 8 turning to an attacker, 10 archers falling back,
                       //     11 routed, 12 charging, 13 melee, 14 shooting
  int16_t flags;       // +04 bits 0-2 type (1 infantry, 2 cavalry, 3 archers, 4 musketeers, 5 arrows,
                       //     6 musket balls), bit 3 enemy side
  int16_t men;         // +06
  int16_t facing;      // +08
  int16_t x, y;        // +0A
  int16_t destX, destY;// +0E
  int16_t destFacing;  // +12
  int16_t contactX, contactY; // +14 last contact point in the unit's own frame
  int16_t blocker;     // +18
  int16_t terrainMod;  // +1A
  int16_t spriteBase;  // +1C
  int16_t target;      // +1E
  int16_t speed;       // +20
  int16_t turnRate;    // +22
  int16_t pendingTurn; // +24
  int16_t counter;     // +26
  int16_t phase;       // +28
  int16_t damage;      // +2A incoming damage
  int16_t open;        // +2C open formation this step
  int16_t morale;      // +2E
  int16_t effMorale;   // +30
  int16_t unused32;    // +32
  int16_t initialMen;  // +34
  int16_t reactMen;    // +36
  int16_t projectile;  // +38 own volley record, -1 for a volley record
  int16_t wp2X, wp2Y;  // +3A second waypoint
  int16_t wp2Facing;   // +3E
} BattleUnit;

typedef struct
{
  // the field
  int8_t  terrain[BATTLE_MAP_H * BATTLE_MAP_W];   // DS:4A60
  uint8_t visible[BATTLE_MAP_H * BATTLE_MAP_W];   // DS:68A2 unit id per cell, rebuilt every step
  BattleUnit u[BATTLE_RECORDS];                   // DS:5E2A
  uint32_t rng;                                   // DS:1712
  // the armies and the battle
  int16_t running;          // 5C18
  int16_t enemyMen;         // 5C1A
  int16_t playerColumn;     // 5E1C
  int16_t cga;              // 5E1E
  int16_t general[2];       // 5E20
  int16_t enemySize;        // 5E24
  int16_t playerMirror;     // 5E26
  int16_t records;          // 5E28 units + volley records
  int16_t enemyColumn;      // 646A
  int16_t enemyFormation;   // 646C
  int16_t retreat;          // 646E
  int16_t cursorColour;     // 6472
  int16_t enemyHasUnits;    // 6674
  int16_t playerVariant;    // 6676
  int16_t generalship[2];   // 6678
  int16_t rank;             // 667C
  int16_t playerGeneralship;// 667E
  int16_t playerHasUnits;   // 6680
  int16_t playerMen;        // 6682
  int16_t centreX;          // 6684 the other unit's centre in the frame of the first (collision tests)
  int16_t over;             // 6686
  int16_t units;            // 6688
  int16_t playerSize;       // 668A
  int16_t centreY;          // 668C
  int16_t enemyGeneralship; // 6692
  int16_t enemyVariant;     // 6694
  int16_t enemyMirror;      // 6696
  int16_t castle;           // 6698
  int16_t playerFormation;  // 669E
  int16_t difficultyBonus;  // 66A0
  int16_t enemyRank;        // 7A5A
  // orders
  int16_t selected;         // 169A record index (the original keeps a pointer)
  int16_t cursorX, cursorY; // 169C
  int16_t lastJoystickKey;  // 167A
  int16_t cursorBlink;      // 16CA
  int16_t pendingKey;       // 26D4
  int16_t joystickButtons;  // 26D6
  // scratch the original keeps in its data segment
  int16_t corners[8];       // 26B4.. corners of B in A's frame: x1 26B4, x2 26B6, x3 26BA, x4 26BE / y1 26B8, y2 26BC, y3 26C0, y4 26C2
  int16_t boxB[4];          // 26C4 xmin, 26C6 ymin, 26C8 xmax, 26CA ymax
  int16_t boxA[4];          // 26CC xmin, 26CE ymin, 26D0 xmax, 26D2 ymax
  int16_t groupSpeed;       // 26D8
  int16_t rayDist[5];       // 26DA
  int8_t  rayId[5];         // 26E4
  int16_t jingleBand;       // 26EA
  // terrain generator state
  int16_t streamLine;       // 2C92
  int16_t slopeStep;        // 2C94
  int16_t bankSlope[2];     // 2C96 left, 2C98 right
  int16_t slopeWobble;      // 2C9A
  int16_t streamEnd[4];     // 2C9C x, y, heading, initial heading
  int16_t wobbleTarget;     // 2CA4
  int16_t streamWidth;      // 2CA6
  int16_t branches;         // 2CA8
  int16_t streamCentre;     // 2CAA
  int16_t woodsColour;      // 2CAC
  int16_t slopeColour;      // 2CAE
  int16_t marshColour;      // 2CB0
  int16_t background;       // 2CB2
  int16_t slopeDistance;    // 2CB4
  int16_t season;           // 2CB6
  int16_t branchSide;       // 2CB8
  int16_t slopeCounter;     // 2CBA
  int16_t bankCounter;      // 2CBC
  int16_t tuftColour;       // 2CC0
  int16_t depth;            // 2CC2
  int16_t shared36, sharedSound; // shared block values read during the battle (+36 unused here, +310)
} BattleState;

// The original program's initialised data (DS:0000-1B27): formation tables, unit types, geometry, sines
extern const uint8_t battle_tables[BATTLE_TABLES_SIZE];

// A word of the tables at its DS offset
static inline int16_t battle_t16(int off) { return (int16_t)(battle_tables[off] | (battle_tables[off + 1] << 8)); }

// Geometry (battle_math.c)
int16_t battle_sin_mul(int16_t v, uint16_t a);
int16_t battle_cos_mul(int16_t v, uint16_t a);
uint16_t battle_atan2(int16_t x, int16_t y);
uint16_t battle_hypot(int16_t x, int16_t y);
uint16_t battle_distance(int16_t x, int16_t y, uint16_t exactBelow);

// Keys as the battle sees them (INT 16h: scan code << 8 | ASCII)
typedef struct
{
  int count;
  struct { int pass; uint16_t key; } k[64];  // pass 0-4: after that unit pass; 5: while waiting
} BattleKeys;

// Terrain generation from the seed (the BIOS tick count), 1000:51DE (battle_terrain.c)
void battle_generate_terrain(BattleState *b, uint32_t seed);

// One simulation step (the body of the battle loop in main, 1000:00A2-010F) with the keys the input
// handler consumed during it. Returns 1 when the battle is over.
int battle_step(BattleState *b, const BattleKeys *keys);

#endif
