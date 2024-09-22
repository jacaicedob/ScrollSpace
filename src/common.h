#ifndef _COMMON_H_
#define _COMMON_H_

#define KEY_PRESSED(K) (current_input & K)
#define KEY_HELD(K) ((current_input & K) && (old_input & K))
#define KEY_FIRST_PRESS(K) ((current_input & K) && !(old_input & K))
#define FONT_OFFSET 36
#define EMPTY_TILE_IDX 0
#define MAPBLOCK_IDX  FONT_OFFSET
#define MINE_IDX MAPBLOCK_IDX+2
#define CRATERBLOCK_IDX MAPBLOCK_IDX+3
#define SCREEN_T  16
#define SCREEN_B 144
#define SCREEN_L 8
#define SCREEN_R 160
#define SCREEN_TILE_WIDTH 20
#define ROW_WIDTH 32
#define COLUMN_HEIGHT 17
#define BULLET_ARR_SIZE 9
#define MAX_BULLETS 3 // Cannot exceed BULLET_ARR_SIZE
#define MAX_BOMBS 1
#define BLOCK_HEALTH 3
#define MINE_HEALTH 1

enum powerup{
  GUN=0,
  BOMB=1,
  SHIELD=2,
  HEALTH=3
};

enum animation_state{
  HIDDEN=0,
  SHOWN=1
};

#endif