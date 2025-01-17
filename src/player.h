// Code that handles the player's ship.

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <stdbool.h>
#include <stdint.h>

#include <gb/gb.h>

#include "collision.h"
#include "common.h"
#include "sound_effects.h"
#include "sprites.h"

enum AnimationState {
  HIDDEN=0,
  SHOWN=1,
};

static uint8_t player_sprite_base_id = 0;
static bool shield_active = false;
// Used during the damage recovery to toggle between showing and hidding the player sprite.
static enum AnimationState damage_animation_state = HIDDEN;
// Invincibility frames counter, either from taking damage or picking up a shield.
static uint8_t iframes_counter = 0;
// Tile data for the health bar.
static uint8_t health_bar_window_tiles[8];

// Updates the health bar tiles based on the given health. Call `write_health_bar_to_window()` to
// write these tiles to the window.
void update_health_bar_tiles(int8_t health) {
  if (health == 100) {
    health_bar_window_tiles[0] = HEALTH_BAR_START;  // left edge of bar
    for (uint8_t i = 1; i < 7; ++i) {
      health_bar_window_tiles[i] = HEALTH_BAR_START + 1;  // center of bar
    }
    health_bar_window_tiles[7] = HEALTH_BAR_START + 2;  // right edge of bar
  }
  else if (health >= 88) {
    health_bar_window_tiles[0] = HEALTH_BAR_START;  // left edge of bar
    for (uint8_t i = 1; i < 7; ++i) {
      health_bar_window_tiles[i] = HEALTH_BAR_START + 1;  // center of bar
    }
    health_bar_window_tiles[7] = HEALTH_BAR_START + 5;  // right edge of bar
  }
  else if (health >= 16) {
    uint8_t idx = health / 12;
    health_bar_window_tiles[0] = HEALTH_BAR_START;  // left edge of bar
    for (uint8_t i = 1; i < 7; ++i) {
      if (i < idx) {
        health_bar_window_tiles[i] = HEALTH_BAR_START + 1;  // fill
      } else {
        health_bar_window_tiles[i] = HEALTH_BAR_START + 4;  // clear
      }
    }
    health_bar_window_tiles[7] = HEALTH_BAR_START + 5;  // clear right edge of bar
  }
  else if (health > 0) {
    health_bar_window_tiles[1] = HEALTH_BAR_START + 4;
    health_bar_window_tiles[0] = HEALTH_BAR_START;
  }
  else {
    health_bar_window_tiles[1] = HEALTH_BAR_START + 4;  // clear bottom 2 tiles
    health_bar_window_tiles[0] = HEALTH_BAR_START + 3;
  }
}

// Writes the health bar tiles to the window.
inline void write_health_bar_to_window(void) {
  set_win_tiles(0, 0, 8, 1, health_bar_window_tiles);
}

// Initializes the player's variables.
void init_player(void) {
  player_sprite.sprite_id = PLAYER_SPRITE_ID;
  player_sprite.sprite_tile_id = 0;
  player_sprite.x.w = PLAYER_START_X;
  player_sprite.y.w = PLAYER_START_Y;
  player_sprite.direction = RIGHT;
  player_sprite.cb_x_offset = 1;
  player_sprite.cb_y_offset = 2;
  player_sprite.cb.x = player_sprite.x.h + player_sprite.cb_x_offset;
  player_sprite.cb.y = player_sprite.y.h + player_sprite.cb_y_offset;
  player_sprite.cb.w = 5;
  player_sprite.cb.h = 4;
  player_sprite.health = PLAYER_MAX_HEALTH;
  player_sprite.lifespan = 0;  // Note: lifespan isn't used by the player sprite.
  player_sprite.active = true;
  player_sprite.collided = false;
  player_sprite.collided_row = 0;
  player_sprite.collided_col = 0;
  move_sprite(PLAYER_SPRITE_ID, player_sprite.x.h, player_sprite.y.h);

  player_sprite_base_id = 0;
  shield_active = false;
  damage_animation_state = HIDDEN;
  iframes_counter = 0;

  update_health_bar_tiles(PLAYER_MAX_HEALTH);

  if (game_mode == NORMAL) {
    player_sprite.speed.w = PLAYER_SPEED_NORMAL;
  } else if (game_mode == HARD) {
    player_sprite.speed.w = PLAYER_SPEED_HARD;
  } else {
    player_sprite.speed.w = PLAYER_SPEED_TURBO;
  }
}

// Moves the player's ship based on the given input.
void move_player(uint8_t input) {
  player_sprite.direction = RIGHT;
  player_sprite.sprite_tile_id = player_sprite_base_id;
  // Reset player collision box to default.
  player_sprite.cb_x_offset = 1;
  player_sprite.cb_y_offset = 2;
  player_sprite.cb.w = 5;
  player_sprite.cb.h = 4;

  // Check input. Note that the player can move in two directions, e.g. "up and right" or "down and left".
  if (KEY_PRESSED(input, J_RIGHT)) {
    player_sprite.x.w += player_sprite.speed.w;
    if (player_sprite.x.h > SCREEN_R) {
      player_sprite.x.w = ((uint16_t)(SCREEN_R) << 8);
    }
  } else if (KEY_PRESSED(input, J_LEFT)) {
    player_sprite.direction = LEFT;
    player_sprite.x.w -= player_sprite.speed.w;
    if (player_sprite.x.h < SCREEN_L) {
      player_sprite.x.w = ((uint16_t)(SCREEN_L) << 8);
    }
  }

  if (KEY_PRESSED(input, J_UP)) {
    player_sprite.direction |= UP;
    player_sprite.y.w -= player_sprite.speed.w;
    if (player_sprite.y.h < SCREEN_T) {
      player_sprite.y.w = ((uint16_t)(SCREEN_T) << 8);
    }
    player_sprite.sprite_tile_id = player_sprite_base_id + 1;

    // Make collision box smaller when plane is "tilted".
    player_sprite.cb_x_offset = 2;
    player_sprite.cb_y_offset = 3;
    player_sprite.cb.w = 3;
    player_sprite.cb.h = 1;
  } else if (KEY_PRESSED(input, J_DOWN)) {
    player_sprite.direction |= DOWN;
    player_sprite.y.w += player_sprite.speed.w;
    if (player_sprite.y.h > SCREEN_B) {
      player_sprite.y.w = ((uint16_t)(SCREEN_B) << 8);
    }
    player_sprite.sprite_tile_id = player_sprite_base_id + 2;

    // Make collision box smaller when plane is "tilted".
    player_sprite.cb_x_offset = 2;
    player_sprite.cb_y_offset = 4;
    player_sprite.cb.w = 3;
    player_sprite.cb.h = 1;
  }

  // Update the position of the collision box.
  player_sprite.cb.x = player_sprite.x.h + player_sprite.cb_x_offset;
  player_sprite.cb.y = player_sprite.y.h + player_sprite.cb_y_offset;

  // Move the player's sprite.
  set_sprite_tile(PLAYER_SPRITE_ID, player_sprite.sprite_tile_id);
  move_sprite(PLAYER_SPRITE_ID, player_sprite.x.h, player_sprite.y.h);
}

// Checks if the player collided with anything and updates the player's position (e.g. due to
// knockback) accordingly. Sets `player_sprite.collided` to true if the player collided with
// anything. Returns a bool specifying whether or not the player health changed.
bool handle_player_collisions(void) {
  bool health_changed = false;
  if (iframes_counter == 0) {
    // The player is *not* in the invincibility frames state.
    // First check if the damage animation or shield powerup is still active. If so, deactivate it.
    if (shield_active) {
      shield_active = false;
      player_sprite_base_id -= 10;
    }
    if (damage_animation_state == HIDDEN) {
      move_sprite(PLAYER_SPRITE_ID, player_sprite.x.h, player_sprite.y.h);
      damage_animation_state = SHOWN;
    }
    // Normal collision check for player
    uint16_t collision_idx = check_player_collisions(false);
    if (collision_idx != UINT16_MAX) {
      uint8_t collision_id = collision_map[collision_idx];
      switch (collision_id) {
        case HEALTH_KIT_ID:
          // Pick up health kit.
          collision_map[collision_idx] = 0;
          background_map[collision_idx] = 0;
          // Update player health.
          // When updating this code, be wary that the max value of an int8_t is 127.
          if (player_sprite.health < 20) {
            player_sprite.health += 4*HEALTH_KIT_VALUE;
          } else if (player_sprite.health < 50) {
            player_sprite.health += 2*HEALTH_KIT_VALUE;
          } else {
            player_sprite.health += HEALTH_KIT_VALUE;
            if (player_sprite.health > PLAYER_MAX_HEALTH) {
              player_sprite.health = PLAYER_MAX_HEALTH;
            }
          }
          health_changed = true;
          play_health_sound();
          break;
        case SHIELD_ID:
          // Pick up shield.
          collision_map[collision_idx] = 0;
          background_map[collision_idx] = 0;
          shield_active = true;
          iframes_counter = SHIELD_DURATION;
          player_sprite_base_id += 10;
          play_shield_sound();
          break;
        default:
          // The player hit a wall or a mine.
          player_sprite.health -= COLLISION_DAMAGE;
          health_changed = true;
          iframes_counter = COLLISION_TIMEOUT;
          if (collision_id <= PLAYER_COLLISION_DAMAGE) {
            // The wall or mine is destroyed.
            if (background_map[collision_idx] == MINE_TILE) {
              point_score += POINTS_PER_MINE;
            }
            collision_map[collision_idx] = 0;
            background_map[collision_idx] = 0;
          } else {
            // Apply damage to the wall or mine.
            collision_map[collision_idx] -= PLAYER_COLLISION_DAMAGE;
          }
          // Handle knockback: Push sprite in the opposite direction that it's moving.
          if (player_sprite.direction & RIGHT) {
            // Move the sprite to the left.
            player_sprite.x.w -= PLAYER_COLLISION_KNOCKBACK;
            if (player_sprite.x.h < SCREEN_L) {
              player_sprite.x.w = ((uint16_t)(SCREEN_L) << 8);
            }
            player_sprite.cb.x = player_sprite.x.h + player_sprite.cb_x_offset;
          } else if (player_sprite.direction & LEFT) {
            // Move the sprite to the right.
            player_sprite.x.w += PLAYER_COLLISION_KNOCKBACK;
            if (player_sprite.x.h > SCREEN_R) {
              player_sprite.x.w = ((uint16_t)(SCREEN_R) << 8);
            }
            player_sprite.cb.x = player_sprite.x.h + player_sprite.cb_x_offset;
          }
          if (player_sprite.direction & UP) {
            // Move the sprite down.
            player_sprite.y.w += PLAYER_COLLISION_KNOCKBACK;
            if (player_sprite.y.h > SCREEN_B) {
              player_sprite.y.w = ((uint16_t)(SCREEN_B) << 8);
            }
            player_sprite.cb.y = player_sprite.y.h + player_sprite.cb_y_offset;
          } else if (player_sprite.direction & DOWN) {
            // Move the sprite up.
            player_sprite.y.w -= PLAYER_COLLISION_KNOCKBACK;
            if (player_sprite.y.h < SCREEN_T) {
              player_sprite.y.w = ((uint16_t)(SCREEN_T) << 8);
            }
            player_sprite.cb.y = player_sprite.y.h + player_sprite.cb_y_offset;
          }
          move_sprite(PLAYER_SPRITE_ID, player_sprite.x.h, player_sprite.y.h);
          play_collision_sound();
          break;
      }
    }
  }
  else {
    // The player *is* in the invincibility frames state.
    --iframes_counter;
    if (!shield_active) {
      if (damage_animation_state == HIDDEN) {
        move_sprite(PLAYER_SPRITE_ID, player_sprite.x.h, player_sprite.y.h);
        damage_animation_state = SHOWN;
      } else {
        move_sprite(PLAYER_SPRITE_ID, 0, 0);
        damage_animation_state = HIDDEN;
      }
      // Check for collision and only process pickups if the shield is not active.
      // This will allow the player to pick up items while in the iframes state.
      uint16_t collision_idx = check_player_collisions(true);
      if (collision_idx != UINT16_MAX) {
        if (collision_map[collision_idx] == HEALTH_KIT_ID) {
          // Pick up health kit.
          collision_map[collision_idx] = 0;
          background_map[collision_idx] = 0;
          // Update player health.
          // When updating this code, be wary that the max value of an int8_t is 127.
          if (player_sprite.health < 20) {
            player_sprite.health += 4*HEALTH_KIT_VALUE;
          } else if (player_sprite.health < 50) {
            player_sprite.health += 2*HEALTH_KIT_VALUE;
          } else {
            player_sprite.health += HEALTH_KIT_VALUE;
            if (player_sprite.health > PLAYER_MAX_HEALTH) {
              player_sprite.health = PLAYER_MAX_HEALTH;
            }
          }
          health_changed = true;
          play_health_sound();
        }
        else {
          // Pick up shield.
          collision_map[collision_idx] = 0;
          background_map[collision_idx] = 0;
          shield_active = true;
          iframes_counter = SHIELD_DURATION;
          player_sprite_base_id += 10;
          play_shield_sound();
        }
      }
    }
  }

  if (health_changed) {
    // Update health bar after a collision.
    update_health_bar_tiles(player_sprite.health);
    // Update the ship sprite based on the current health.
    // TODO: Make these values consistent with the health pickup values above.
    if (player_sprite.health > 50) {
      player_sprite_base_id = 0;
    } else if (player_sprite.health > 25) {
      player_sprite_base_id = 3;
    } else {
      player_sprite_base_id = 6;
    }
  }

  return health_changed;
}

#endif
