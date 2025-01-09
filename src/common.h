// Code and values that are widely used across files.

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>

#include "sprites.h"

// The following are used for performance testing of individual components.
#define ENABLE_SCORING 1
#define ENABLE_MUSIC 1
#define ENABLE_WEAPONS 1
#define ENABLE_COLLISIONS 1
#define ENABLE_INTRO 1

/*
 * Keys
 */
#define KEY_PRESSED(input, key) (input & key)
#define KEY_HELD(input, old_input, key) ((input & key) && (old_input & key))
#define KEY_FIRST_PRESS(input, old_input, key) ((input & key) && !(old_input & key))

/*
 * Screen
 */
// The top of the *visible* screen is 16 pixels from the actual top of the screen.
#define SCREEN_T  16
#define SCREEN_B 144
// The left side of the *visible* screen is 8 pixels from the actual left side of the screen.
#define SCREEN_L 8
#define SCREEN_R 160
#define SCREEN_TILE_WIDTH 20
#define SCREEN_TILE_HEIGHT 18
#define SCREEN_SCROLL_WIDTH (SCREEN_TILE_WIDTH+2)
#define ROW_WIDTH 32
#define COLUMN_HEIGHT 17
#define PIXELS_PER_COLUMN 8
#define COLUMNS_PER_SCREEN 20

/*
 * Tiles
 */
#define TILE_SIZE_BYTES 16
// Bit-shift by 5 is equivalent to multiply by 32, which is the ROW_WIDTH.
#define MAP_INDEX(row, column) (((row) << 5) + column)
#define MAP_INDEX_ROW_OFFSET(row) ((row) << 5)
#define EMPTY_TILE_IDX 0
// Indexes 1-36 are used for fonts.
#define MAPBLOCK_IDX 37
#define MINE_IDX (MAPBLOCK_IDX+2)
#define CRATERBLOCK_IDX (MAPBLOCK_IDX+3)
#define BOMB_READY_ICON (MAPBLOCK_IDX+5)
#define SHIELD_TILE (MAPBLOCK_IDX+6)
#define HEALTH_KIT_TILE (MAPBLOCK_IDX+7)
#define HEALTH_BAR_START (MAPBLOCK_IDX+14)
#define COLON_FONT_IDX 57
#define LOCK_TILE 67

/*
 * Sprites
 */
#define PLAYER_SPRITE_ID 0
#define DEATH_SPRITE 9
#define BULLET_SPRITE 19

/*
 * Tunable parameters
 */
#define MAX_BULLETS 3
#define BLOCK_HEALTH 4
#define MINE_HEALTH 2
#define POWERUP_RESERVED_IDS 235
#define SHIELD_ID 254
#define SHIELD_DURATION (8*20)
#define HEALTH_KIT_ID 255
#define HEALTH_KIT_VALUE 5
#define COLLISION_DAMAGE 3
#define COLLISION_TIMEOUT 60
// A BOMB_RADIUS of N will create square bomb explosions of (2*N+1, 2*N+1) size in tiles. The +1 is
// for the center row, which is centered on the ship.
#define BOMB_RADIUS 3
#define BOMB_LENGTH (BOMB_RADIUS*2 + 1)
#define BOMB_COOLDOWN_FRAMES 420
#define BULLET_LIFESPAN 20
#define BULLET_DAMAGE 1
#define BULLET_COLLISION_X_OFFSET 0
#define BULLET_COLLISION_Y_OFFSET 2
#define PLAYER_START_X 20
#define PLAYER_START_Y 80
#define PLAYER_MAX_HEALTH 100
#define PLAYER_COLLISION_DAMAGE 2
// In pixels
#define PLAYER_COLLISION_KNOCKBACK 8
// All speeds are in pixels per frame.
#define PLAYER_SPEED 1
#define SCROLL_SPEED_NORMAL 1
#define SCROLL_SPEED_HARD 2
#define SCROLL_SPEED_TURBO 3
#define POINTS_PER_MINE 2
#define POINTS_PER_SCREEN_SCROLLED 5

/*
 * Font
 */
#define CHAR_A 0x0B
#define CHAR_B 0x0C
#define CHAR_C 0x0D
#define CHAR_D 0x0E
#define CHAR_E 0x0F
#define CHAR_F 0x10
#define CHAR_G 0x11
#define CHAR_H 0x12
#define CHAR_I 0x13
#define CHAR_J 0x14
#define CHAR_K 0x15
#define CHAR_L 0x16
#define CHAR_M 0x17
#define CHAR_N 0x18
#define CHAR_O 0x19
#define CHAR_P 0x1A
#define CHAR_Q 0x1B
#define CHAR_R 0x1C
#define CHAR_S 0x1D
#define CHAR_T 0x1E
#define CHAR_U 0x1F
#define CHAR_V 0x20
#define CHAR_W 0x21
#define CHAR_X 0x22
#define CHAR_Y 0x23
#define CHAR_Z 0x24

/*
 * Math
 */
#define MOD4(n) ((n) & 0x3)
#define MOD8(n) ((n) & 0x7)
#define MOD32(n) ((n) & 0x1F)

/*
 * Game Modes 
 */
enum GameMode {
  NORMAL=0,
  HARD=1,
  TURBO=2,
};

/*
 * Other declarations
 */
extern struct Sprite player_sprite;
extern uint8_t collision_map[COLUMN_HEIGHT*ROW_WIDTH];
extern uint8_t background_map[COLUMN_HEIGHT*ROW_WIDTH];
extern uint16_t point_score;
extern enum GameMode game_mode;

extern void wait_frames(uint8_t n);

#endif
