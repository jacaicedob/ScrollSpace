#include <gb/gb.h>
#include <gbdk/bcd.h>
#include <gbdk/font.h>
#include <hUGEDriver.h>
#include <rand.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "collision.h"
#include "common.h"
#include "display_effects.h"
#include "intro_scene.h"
#include "logo_screen.h"
#include "player.h"
#include "procedural_generation.h"
#include "score.h"
#include "songs.h"
#include "sound_effects.h"
#include "sprite_data.h"
#include "sprites.h"
#include "tile_data.h"
#include "title_screen.h"
#include "wait.h"
#include "weapons.h"

enum GameMode game_mode = NORMAL;
struct Sprite player_sprite;
uint8_t collision_map[COLUMN_HEIGHT * ROW_WIDTH];
uint8_t background_map[COLUMN_HEIGHT * ROW_WIDTH];
fixed scroll_speed;
uint16_t point_score = 0;

static bool rand_initialized = false;
static bool hard_mode_unlocked = false;
static bool turbo_mode_unlocked = false;
static bool upgrade_sprite_unlocked = false;
static bool game_paused = true;
// Whether or not to show the timer-based score. If false, the points-based score is shown instead.
// Note: The value of this variable is kept between runs of the game.
static bool show_timer_score = false;
static bool timer_score_changed = false;

#if ENABLE_SCORING
// Increments the timer score. To be called during an ISR (interrupt service routine).
static void increment_timer_score_isr(void) {
  if (game_paused) {
    return;
  }
  timer_score_changed = increment_timer_score();
}
#endif

// Loads the title screen tiles.
static void load_title_screen(void) {
  set_bkg_data(TITLE_SCREEN_OFFSET, TILE_COUNT(title_screen_tiles), title_screen_tiles);
}

// Loads font data.
static void load_font(void) {
  // Load font tiles to background map.
  font_init();
  font_t min_font = font_load(font_min);
  font_set(min_font);
}

// Loads sprite data.
static void load_sprite_data(void) {
  set_sprite_data(0, 10, player_sprites);
  set_sprite_data(10, 9, player_shield_sprites);
  set_sprite_data(19, 3, projectile_sprites);
}

// Loads background tile data.
static void load_tile_data(void) {
  uint8_t tile_index = WALL_BLOCK_TILE;
  set_bkg_data(tile_index, TILE_COUNT(block_tiles), block_tiles);
  tile_index += TILE_COUNT(block_tiles);
  set_bkg_data(tile_index, TILE_COUNT(powerup_tiles), powerup_tiles);
  tile_index += TILE_COUNT(powerup_tiles);
  set_bkg_data(tile_index, TILE_COUNT(health_bar_tiles), health_bar_tiles);
  tile_index += TILE_COUNT(health_bar_tiles);
  set_bkg_data(tile_index, TILE_COUNT(font_extras_tiles), font_extras_tiles);
  tile_index += TILE_COUNT(font_extras_tiles);
  set_bkg_data(tile_index, TILE_COUNT(tutorial_screen_tiles), tutorial_screen_tiles);
  tile_index += TILE_COUNT(tutorial_screen_tiles);
  set_bkg_data(tile_index, TILE_COUNT(lock_tiles), lock_tiles);
  tile_index += TILE_COUNT(lock_tiles);
}

// Displays a confirmation prompt to the player to confirm whether or not they want to perform an
// action. Returns true if the player confirmed the action, false otherwise.
static bool confirm_action(void) {
  vsync();
  set_win_tiles(0, 0, UINT8_ARRARY_SIZE(confirmation_prompt_text), 1, confirmation_prompt_text);
  set_win_tiles(0, 1, UINT8_ARRARY_SIZE(yes_or_no_text), 1, yes_or_no_text);
  move_win(7, 128);  // Need 2 rows in the window for the confirmation prompt.
  wait_for_keys_released(J_START | J_A);

  bool yes_highlighted = false;
  bool update_cursor = false;
  uint8_t prev_input = 0;
  while (true) {
    vsync();
    if (update_cursor) {
      if (yes_highlighted) {
        set_win_tile_xy(3, 1, CHAR_CURSOR);
        set_win_tile_xy(12, 1, EMPTY_TILE);
      } else {
        set_win_tile_xy(3, 1, EMPTY_TILE);
        set_win_tile_xy(12, 1, CHAR_CURSOR);
      }
      update_cursor = false;
    }

    uint8_t input = joypad();
    if (KEY_FIRST_PRESS(input, prev_input, J_RIGHT) && yes_highlighted) {
      yes_highlighted = false;
      update_cursor = true;
    } else if (KEY_FIRST_PRESS(input, prev_input, J_LEFT) && !yes_highlighted) {
      yes_highlighted = true;
      update_cursor = true;
    } else if (KEY_FIRST_PRESS(input, prev_input, J_START) || KEY_FIRST_PRESS(input, prev_input, J_A)) {
      move_win(7, 136);
      return yes_highlighted;
    }
    prev_input = input;
  }
}

// Shows the mode selection screen and stores the mode chosen by the player in `game_mode`.
static void show_mode_selection_screen(void) {
  if (upgrade_sprite_unlocked) {
    set_sprite_data(0, 10, player_upgrade_sprites);
    set_sprite_data(10, 9, player_upgrade_shield_sprites);
  }

  // Add walls at the top and bottom of the screen.
  uint16_t row_offset = MAP_INDEX_ROW_OFFSET(COLUMN_HEIGHT - 1);
  for (uint8_t i = 0; i < SCREEN_TILE_WIDTH; ++i) {
    background_map[i] = WALL_BLOCK_TILE;
    background_map[row_offset + i] = WALL_BLOCK_TILE;
  }

  // Write "NORMAL".
  background_map[MAP_INDEX(3, 7)] = CHAR_N;
  background_map[MAP_INDEX(3, 8)] = CHAR_O;
  background_map[MAP_INDEX(3, 9)] = CHAR_R;
  background_map[MAP_INDEX(3, 10)] = CHAR_M;
  background_map[MAP_INDEX(3, 11)] = CHAR_A;
  background_map[MAP_INDEX(3, 12)] = CHAR_L;

  // Write "HARD".
  background_map[MAP_INDEX(6, 7)] = CHAR_H;
  background_map[MAP_INDEX(6, 8)] = CHAR_A;
  background_map[MAP_INDEX(6, 9)] = CHAR_R;
  background_map[MAP_INDEX(6, 10)] = CHAR_D;

  // Write "TURBO".
  background_map[MAP_INDEX(9, 7)] = CHAR_T;
  background_map[MAP_INDEX(9, 8)] = CHAR_U;
  background_map[MAP_INDEX(9, 9)] = CHAR_R;
  background_map[MAP_INDEX(9, 10)] = CHAR_B;
  background_map[MAP_INDEX(9, 11)] = CHAR_O;

  // Write "CLEAR DATA".
  background_map[MAP_INDEX(14, 7)] = CHAR_C;
  background_map[MAP_INDEX(14, 8)] = CHAR_L;
  background_map[MAP_INDEX(14, 9)] = CHAR_E;
  background_map[MAP_INDEX(14, 10)] = CHAR_A;
  background_map[MAP_INDEX(14, 11)] = CHAR_R;
  background_map[MAP_INDEX(14, 12)] = 0;
  background_map[MAP_INDEX(14, 13)] = CHAR_D;
  background_map[MAP_INDEX(14, 14)] = CHAR_A;
  background_map[MAP_INDEX(14, 15)] = CHAR_T;
  background_map[MAP_INDEX(14, 16)] = CHAR_A;

  if (game_mode == TITLE_SCREEN) {
    game_mode = NORMAL;
  }
  // Note that the previous value of `game_mode` is used here. For convenience, we want to remember
  // which mode the player selected last and default the cursor to that mode.
  uint8_t y = (game_mode == NORMAL) ? 40 : (game_mode == HARD) ? 64
                                                               : 88;

  vsync();
  set_bkg_tiles(0, 0, ROW_WIDTH, COLUMN_HEIGHT, background_map);
  set_sprite_tile(PLAYER_SPRITE_ID, 0);
  move_sprite(PLAYER_SPRITE_ID, 32, y);
  SHOW_SPRITES;
  SHOW_WIN;

  uint8_t prev_input = 0;
  uint8_t prev_y = 0;  // Note that y != prev_y for the first frame so that the window is updated properly.
  bool update_locks = true;
  while (true) {
    vsync();
    // Update displays.
    if (update_locks) {
      set_bkg_tile_xy(5, 6, hard_mode_unlocked ? EMPTY_TILE : LOCK_TILE);
      set_bkg_tile_xy(5, 9, turbo_mode_unlocked ? EMPTY_TILE : LOCK_TILE);
      update_locks = false;
    }
    if (y != prev_y) {
      // Update the window message.
      if (game_mode == CLEAR_DATA) {
        display_clear_data_msg();
      } else if (game_mode == HARD && !hard_mode_unlocked) {
        display_hardmode_unlock_msg();
      } else if (game_mode == TURBO && !turbo_mode_unlocked) {
        display_turbomode_unlock_msg();
      } else {
        display_highscores();
      }
      prev_y = y;
    }

    // Handle input.
    uint8_t input = joypad();
    if (KEY_PRESSED(input, J_SELECT)) {
      // It's cheatin' time!
      if (KEY_PRESSED(input, J_UP) && KEY_PRESSED(input, J_A) && (!hard_mode_unlocked || !turbo_mode_unlocked)) {
        // Unlock hard and turbo modes.
        hard_mode_unlocked = true;
        turbo_mode_unlocked = true;
        update_locks = true;
        prev_y = 0;  // Updates the window.
        play_bomb_sound();
      }
    } else if (KEY_FIRST_PRESS(input, prev_input, J_UP)) {
      if (game_mode == HARD) {
        game_mode = NORMAL;
        y = 40;
        move_sprite(PLAYER_SPRITE_ID, 32, y);
      } else if (game_mode == TURBO) {
        game_mode = HARD;
        y = 64;
        move_sprite(PLAYER_SPRITE_ID, 32, y);
      } else if (game_mode == CLEAR_DATA) {
        game_mode = TURBO;
        y = 88;
        move_sprite(PLAYER_SPRITE_ID, 32, y);
      }
      play_mode_selection_sound();
    } else if (KEY_FIRST_PRESS(input, prev_input, J_DOWN)) {
      if (game_mode == NORMAL) {
        game_mode = HARD;
        y = 64;
        move_sprite(PLAYER_SPRITE_ID, 32, y);
      } else if (game_mode == HARD) {
        game_mode = TURBO;
        y = 88;
        move_sprite(PLAYER_SPRITE_ID, 32, y);
      } else if (game_mode == TURBO) {
        game_mode = CLEAR_DATA;
        y = 128;
        move_sprite(PLAYER_SPRITE_ID, 32, y);
      }
      play_mode_selection_sound();
    } else if (KEY_FIRST_PRESS(input, prev_input, J_START) || KEY_FIRST_PRESS(input, prev_input, J_A)) {
      if (game_mode == CLEAR_DATA) {
        if (confirm_action()) {
          play_bomb_sound();
          clear_score_data();
          set_sprite_data(0, 10, player_sprites);
          set_sprite_data(10, 9, player_shield_sprites);
          hard_mode_unlocked = false;
          turbo_mode_unlocked = false;
          upgrade_sprite_unlocked = false;
          update_locks = true;
        }
        prev_y = 0;                    // Updates the window.
        prev_input = (J_START | J_A);  // Makes sure these keys are released before triggering this again.
        continue;
      } else if ((game_mode == HARD && !hard_mode_unlocked) || (game_mode == TURBO && !turbo_mode_unlocked)) {
        // Mode not unlocked yet. Let the player know by shaking the ship and playing a sound.
        play_collision_sound();
        for (uint8_t i = 0; i < 2; ++i) {
          move_sprite(PLAYER_SPRITE_ID, 34, y);
          wait_frames(2);
          move_sprite(PLAYER_SPRITE_ID, 32, y);
          wait_frames(2);
          move_sprite(PLAYER_SPRITE_ID, 30, y);
          wait_frames(2);
          move_sprite(PLAYER_SPRITE_ID, 32, y);
          wait_frames(2);
        }
      } else {
        play_flyaway_sound();
        // Make sprite fly off the screen
        for (uint8_t i = 0; i < 144 / 8; i++) {
          scroll_sprite(PLAYER_SPRITE_ID, 8, 0);
          vsync();
        }
        break;
      }
    } else if (KEY_FIRST_PRESS(input, prev_input, J_B)) {
      game_mode = TITLE_SCREEN;
      break;
    }

    prev_input = input;
  }
  HIDE_SPRITES;
}

#if ENABLE_COLLISIONS
// Shows the game over screen.
static void show_gameover_screen(void) {
  HIDE_WIN;
  clear_window();
  for (uint8_t row = 0; row < SCREEN_TILE_HEIGHT; ++row) {
    for (uint8_t col = 0; col < SCREEN_TILE_WIDTH; ++col) {
      if ((row == 0) || (row == 17)) {
        // Top and bottom block border
        background_map[row * SCREEN_TILE_WIDTH + col] = 0x25;
      } else {
        background_map[row * SCREEN_TILE_WIDTH + col] = 0x0;
      }
    }
  }
  // Write GAME OVER
  uint16_t start_idx = 3 * SCREEN_TILE_WIDTH + 5;
  background_map[start_idx++] = CHAR_G;
  background_map[start_idx++] = CHAR_A;
  background_map[start_idx++] = CHAR_M;
  background_map[start_idx++] = CHAR_E;
  background_map[start_idx++] = CHAR_SPACE;
  background_map[start_idx++] = CHAR_O;
  background_map[start_idx++] = CHAR_V;
  background_map[start_idx++] = CHAR_E;
  background_map[start_idx++] = CHAR_R;

  // Write SCORE
  start_idx = 5 * SCREEN_TILE_WIDTH + 2;
  background_map[start_idx++] = CHAR_S;
  background_map[start_idx++] = CHAR_C;
  background_map[start_idx++] = CHAR_O;
  background_map[start_idx++] = CHAR_R;
  background_map[start_idx++] = CHAR_E;

  // Write BEST
  start_idx = 8 * SCREEN_TILE_WIDTH + 3;
  background_map[start_idx++] = CHAR_B;
  background_map[start_idx++] = CHAR_E;
  background_map[start_idx++] = CHAR_S;
  background_map[start_idx++] = CHAR_T;

  // WRITE TIP
  start_idx = 13 * SCREEN_TILE_WIDTH + 2;
  background_map[start_idx++] = CHAR_T;
  background_map[start_idx++] = CHAR_I;
  background_map[start_idx++] = CHAR_P;
  background_map[start_idx++] = CHAR_COLON;

  // Write the tip message
  uint8_t rdn = MOD8(rand());
  uint8_t tip_idx = 0;
  start_idx = 14 * SCREEN_TILE_WIDTH + 3;
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];

  start_idx = 15 * SCREEN_TILE_WIDTH + 3;
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];
  background_map[start_idx++] = tips[rdn * 25 + (tip_idx++)];

  set_bkg_tiles(0, 0, SCREEN_TILE_WIDTH, SCREEN_TILE_HEIGHT, background_map);
  move_bkg(0, 0);

  display_gameover_scores();

  SHOW_BKG;
  fade_in();
  wait_for_keys_pressed(J_START | J_A | J_B);
  wait_for_keys_released(J_START | J_A | J_B);

  bool ret = update_modes_unlocked(&hard_mode_unlocked, &turbo_mode_unlocked, &upgrade_sprite_unlocked);

  if (ret) {
    show_reward_screen();
  }

  fade_out();
  HIDE_BKG;
  SHOW_WIN;
}

// Handles a game over, including transitioning to the game over screen.
static void handle_gameover(void) {
  game_paused = true;
  mute_all_channels();
  remove_VBL(hUGE_dosound);

  set_sprite_tile(PLAYER_SPRITE_ID, DEATH_SPRITE);
  wait_frames(10);
  HIDE_BKG;
  play_gameover_sound();
  fade_out();
  HIDE_SPRITES;

  // Hide the bullet sprites so that they don't appear later in the title screens.
  hide_bullet_sprites();
  update_health_bar_tiles(0);
  write_health_bar_to_window();

  // Show gameover screen, then transition to the title screen.
  show_gameover_screen();
  show_title_screen(true);
}
#endif

// Incrementally increases the difficulty of the game, e.g. by increasing the scroll speed.
static void increase_difficulty(void) {
  scroll_speed.w += SCROLL_SPEED_INCREASE;
  player_sprite.speed.w += PLAYER_SPEED_INCREASE;
  if (game_mode == NORMAL) {
    if (scroll_speed.w > SCROLL_SPEED_HARD) {
      scroll_speed.w = SCROLL_SPEED_HARD;
    }
    if (player_sprite.speed.w > PLAYER_SPEED_HARD) {
      player_sprite.speed.w = PLAYER_SPEED_HARD;
    }
  } else if (game_mode == HARD) {
    if (scroll_speed.w > SCROLL_SPEED_TURBO) {
      scroll_speed.w = SCROLL_SPEED_TURBO;
    }
    if (player_sprite.speed.w > PLAYER_SPEED_TURBO) {
      player_sprite.speed.w = PLAYER_SPEED_TURBO;
    }
  } else {
    if (scroll_speed.w > SCROLL_SPEED_TURBO_MAX) {
      scroll_speed.w = SCROLL_SPEED_TURBO_MAX;
    }
    if (player_sprite.speed.w > PLAYER_SPEED_TURBO_MAX) {
      player_sprite.speed.w = PLAYER_SPEED_TURBO_MAX;
    }
  }
}

void main(void) {
#if ENABLE_MUSIC
  // Enable sound playback.
  NR52_REG = 0x80;
  NR51_REG = 0xFF;
  NR50_REG = 0x33;
  // Mute all channels.
  mute_all_channels();
#endif

#if ENABLE_INTRO
  /*
   * LOGO SCREEN
   */
  // The logo screen code is in ROM bank 2.
  SWITCH_ROM(2);
  show_logo_screen();

  /*
   * INTRO SCENE
   */
  // From here on, we only use ROM banks 0 and 1.
  SWITCH_ROM(1);
  show_intro_scene();
#endif

  /*
   * SETUP GAME ASSETS
   */
  load_font();
  load_sprite_data();
  load_tile_data();
  load_title_screen();
  // Load Window.
  move_win(7, 136);
  // Initialize high scores.
  init_highscores();
  update_modes_unlocked(&hard_mode_unlocked, &turbo_mode_unlocked, &upgrade_sprite_unlocked);

#if ENABLE_SCORING
  // Add timer score incrementer to VBL interrupt handler.
  add_VBL(increment_timer_score_isr);
#endif

  /*
   * TITLE SCREEN
   */
  show_title_screen(false);

  // Get the high byte of the random seed right after the user has pressed START to continue past
  // the title screen.
  uint16_t rand_seed = DIV_REG;
  rand_seed <<= 8;

  fixed screen_pos_x;            // The x position of the screen (high 8 bits: pixels, low 8 bits: subpixels)
  uint8_t input;                 // The joypad input of this frame
  uint8_t prev_input;            // The joypad input of the previous frame
  uint8_t prev_left_column;      // The left-most column on the screen in the previous frame. Used to track when the background has scrolled a full column's worth of pixels.
  uint8_t column_count;          // How many columns have been scrolled in the current screen
  uint8_t difficulty_countdown;  // A count-down of the number of screens before a difficulty increase
  bool generated_column;         // Whether or not a column was generated this frame
  uint8_t generated_column_idx;  // The index of the generated column
  bool update_window_score;      // Whether or not the score in the window needs to be updated
  uint8_t prev_timer_seconds;    // The `timer_seconds` of the previous frame. Used to determine whether or not to update the window score tiles.
  uint16_t prev_point_score;     // The `point_score` of the previous frame. Used to determine whether or not to update the window score tiles.

  while (true) {
    /*
     * Set up for main game loop.
     */

    // Clear collision and background maps.
    for (uint16_t ii = 0; ii < COLUMN_HEIGHT * ROW_WIDTH; ++ii) {
      collision_map[ii] = 0;
      background_map[ii] = 0;
    }

    // Initialize other variables.
    screen_pos_x.w = 0x0000;
    input = 0;
    prev_input = 0;
    prev_left_column = 0;
    column_count = 0;
    difficulty_countdown = DIFFICULTY_INCREASE_SCREEN_COUNT;
    generated_column = false;
    generated_column_idx = 0;
    update_window_score = false;
    prev_timer_seconds = UINT8_MAX;
    prev_point_score = UINT16_MAX;

    /*
     * MODE SELECTION SCREEN
     */
    show_mode_selection_screen();
    if (game_mode == NORMAL) {
      scroll_speed.w = SCROLL_SPEED_NORMAL;
    } else if (game_mode == HARD) {
      scroll_speed.w = SCROLL_SPEED_HARD;
    } else if (game_mode == TURBO) {
      scroll_speed.w = SCROLL_SPEED_TURBO;
    } else {
      show_title_screen(false);
      continue;
    }

    fade_out();
    // initrand() needs to be called with a 16-bit random seed. We produce this seed by polling the
    // 8-bit DIV_REG register at two different, non-deterministic times: Once after the title screen,
    // and once after the mode selection screen. Both of these are non-deterministic because they
    // require the user to press a button in order to continue.
    if (!rand_initialized) {
      rand_seed |= DIV_REG;
      initrand(rand_seed);
      rand_initialized = true;
    }

    // Reset the procedural generation state. (Needs to be called after initrand() has been called.)
    reset_generation_state();

    // Copy tutorial screen tiles to the background.
    for (uint8_t i = 0; i < COLUMN_HEIGHT; ++i) {
      for (uint8_t j = 0; j < SCREEN_TILE_WIDTH; ++j) {
        background_map[i * ROW_WIDTH + j] = tutorial_screen_map[i * SCREEN_TILE_WIDTH + j];
      }
    }

    // Add text to tutorial screen
    background_map[5 * ROW_WIDTH + 7] = CHAR_A;
    background_map[5 * ROW_WIDTH + 10] = CHAR_S;
    background_map[5 * ROW_WIDTH + 11] = CHAR_H;
    background_map[5 * ROW_WIDTH + 12] = CHAR_O;
    background_map[5 * ROW_WIDTH + 13] = CHAR_O;
    background_map[5 * ROW_WIDTH + 14] = CHAR_T;

    background_map[8 * ROW_WIDTH + 7] = CHAR_B;
    background_map[8 * ROW_WIDTH + 10] = CHAR_B;
    background_map[8 * ROW_WIDTH + 11] = CHAR_O;
    background_map[8 * ROW_WIDTH + 12] = CHAR_M;
    background_map[8 * ROW_WIDTH + 13] = CHAR_B;

    background_map[11 * ROW_WIDTH + 3] = CHAR_S;
    background_map[11 * ROW_WIDTH + 4] = CHAR_T;
    background_map[11 * ROW_WIDTH + 5] = CHAR_A;
    background_map[11 * ROW_WIDTH + 6] = CHAR_R;
    background_map[11 * ROW_WIDTH + 7] = CHAR_T;
    background_map[11 * ROW_WIDTH + 10] = CHAR_P;
    background_map[11 * ROW_WIDTH + 11] = CHAR_A;
    background_map[11 * ROW_WIDTH + 12] = CHAR_U;
    background_map[11 * ROW_WIDTH + 13] = CHAR_S;
    background_map[11 * ROW_WIDTH + 14] = CHAR_E;

    set_bkg_tiles(0, 0, ROW_WIDTH, COLUMN_HEIGHT, background_map);

    // Reset the window tiles.
    clear_window();

    init_player();
    write_health_bar_to_window();
    init_weapons();
    update_bomb_ready_icon();

#if ENABLE_MUSIC
    mute_all_channels();
#endif

    wait_frames(10);

#if ENABLE_MUSIC
    if (game_mode == NORMAL) {
      hUGE_init(&main_song);
    } else {
      hUGE_init(&main_song_fast);
    }
    play_all_channels();
#endif

    generated_column_idx = SCREEN_TILE_WIDTH - 1;
    for (uint8_t i = 0; i < ROW_WIDTH - SCREEN_TILE_WIDTH; ++i) {
      generated_column_idx = MOD32(generated_column_idx + 1);  // MOD32 is for screen wrap-around.
      generate_column(generated_column_idx);
    }
    set_bkg_tiles(0, 0, ROW_WIDTH, COLUMN_HEIGHT, background_map);

    wait_frames(15);

    // Reset scores and window tiles.
    reset_scores();
    write_score_to_window();

    // Unpausing the game turns on the timer, so this should be done as close as possible to the
    // main game loop.
    game_paused = false;

    SHOW_SPRITES;
    SHOW_WIN;
    fade_in();

    /*
     * MAIN GAME LOOP
     */
    while (true) {
      /*
       * HANDLE INPUT
       */
      input = joypad();

      if (KEY_PRESSED(input, J_START)) {
        game_paused = true;
#if ENABLE_MUSIC
        mute_all_channels();
#endif
        wait_for_keys_released(J_START);
        wait_for_keys_pressed(J_START);
        wait_for_keys_released(J_START);
#if ENABLE_MUSIC
        play_all_channels();
#endif
        game_paused = false;
        continue;
      }

      if (KEY_FIRST_PRESS(input, prev_input, J_SELECT)) {
        show_timer_score = !show_timer_score;
        // Make sure that the score in the window is updated.
        prev_timer_seconds = UINT8_MAX;
        prev_point_score = point_score - 1;
      }

      // Update the player sprite and weapons based on the input.
      move_player(input);
#if ENABLE_WEAPONS
      update_weapons(input, prev_input);
#endif
#if ENABLE_COLLISIONS
      bool health_changed = handle_player_collisions();
      if (health_changed) {
        if (player_sprite.health <= 0) {
          handle_gameover();
          break;
        }
      }
#endif

      prev_input = input;

      // Update screen position and generate a new column, if necessary.
      screen_pos_x.w += scroll_speed.w;
      uint8_t left_column = screen_pos_x.h >> 3;
      if (left_column != prev_left_column) {
        prev_left_column = left_column;
        generated_column_idx = MOD32(generated_column_idx + 1);  // MOD32 is for screen wrap-around.
        generate_column(generated_column_idx);
        generated_column = true;

        ++column_count;
        if (column_count == COLUMNS_PER_SCREEN) {
          column_count = 0;
          point_score += POINTS_PER_SCREEN_SCROLLED;

          --difficulty_countdown;
          if (difficulty_countdown == 0) {
            increase_difficulty();
            difficulty_countdown = DIFFICULTY_INCREASE_SCREEN_COUNT;
          }
        }
      }

#if ENABLE_SCORING
      // Update the score tiles, if necessary.
      if (show_timer_score) {
        if (timer_score_changed) {
          update_timer_score_tiles();
          update_window_score = true;
          timer_score_changed = false;
        }
      } else {
        if (point_score != prev_point_score) {
          update_point_score_tiles();
          update_window_score = true;
        }
        prev_point_score = point_score;
      }
#endif

      // Wait for the frame to finish drawing.
      vsync();

      /*
       * COPY TO VRAM
       */
      // Scroll the background.
      SCX_REG = screen_pos_x.h;

      // Update tiles for background objects that sprites collided with.
      if (player_sprite.collided) {
        set_bkg_tile_xy(player_sprite.collided_col, player_sprite.collided_row, background_map[MAP_INDEX(player_sprite.collided_row, player_sprite.collided_col)]);
        player_sprite.collided = false;
      }
      update_tiles_hit_by_weapons();

      // Update background tiles when a new column is generated.
      if (generated_column) {
        set_bkg_submap(generated_column_idx, 0, 1, COLUMN_HEIGHT, background_map, ROW_WIDTH);
        generated_column = false;
      }

      // Write health bar tiles to the window layer, if necessary.
      if (health_changed) {
        write_health_bar_to_window();
      }

#if ENABLE_SCORING
      // Write the score tiles to the window layer, if necessary.
      if (update_window_score) {
        write_score_to_window();
        update_window_score = false;
      }
#endif

      // Update the "bomb ready" icon in the window layer, if necessary.
      update_bomb_ready_icon();
    }
  }
}
