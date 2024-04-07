#include <stdint.h>

enum direction{
  UP,
  RIGHT,
  DOWN,
  LEFT,
};

struct CollisionBox {
  uint8_t x;
  uint8_t y;
  uint8_t w;
  uint8_t h;
};

struct Player {
  uint8_t sprite_id;
  uint8_t sprite_tile_id;
  uint8_t x;
  uint8_t y;
  uint8_t speed;
  uint8_t cb_x_offset;
  uint8_t cb_y_offset;
  enum direction dir; 
  struct CollisionBox cb;
};

