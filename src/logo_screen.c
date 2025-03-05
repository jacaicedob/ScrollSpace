#pragma bank 2

#include <gb/gb.h>

#include "common.h"
#include "display_effects.h"
#include "logo_screen.h"
#include "sound_effects.h"
#include "wait.h"

// 49 tiles
static const uint8_t cailan_games_logo_tiles[] = {
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X03,0X03,0X03,0X03,0X03,0X03,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0XF0,0XF0,0XF0,0XF0,0XF0,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X0F,0X0F,0X0F,0X0F,0X0F,0X0F,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X80,0X80,0X80,0X80,0X80,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X71,0X71,0X71,0X71,0X71,0X71,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0XFC,0XFC,0XFC,0XFC,0XFC,0XFC,0XFC,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X0F,0X0F,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,
  0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,
  0XE3,0XE3,0XE3,0XE3,0XE3,0XE3,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0X80,0X80,0X80,0X80,0X80,0X80,0X8F,0X8F,0X8F,0X8F,
  0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0X01,0X01,0X01,0X01,0X01,0X01,0XF1,0XF1,0XF1,0XF1,
  0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,
  0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,
  0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,
  0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,
  0X0F,0X0F,0X0F,0X0F,0X71,0X71,0X71,0X71,0X7E,0X7E,0X7E,0X7E,0X7E,0X7E,0X7F,0X7F,
  0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0X0F,0X0F,0X0F,0X0F,0X0F,0X0F,0X8F,0X8F,
  0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X03,0X03,0X03,0X03,0X03,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XF1,0XF1,0XF1,0XF1,0XF1,0XF1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X80,0X80,0X80,0X80,0X80,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X70,0X70,0X70,0X70,0X70,0X70,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X38,0X38,0X38,0X38,0X38,0X38,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0X9F,0X9F,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X03,0X03,0X03,0X03,0X03,0X03,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC7,0XC7,0XC7,0XC7,0XC7,0XC7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X1F,0X1F,0X1F,0X1F,0X1F,
  0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0X9F,0XE0,0XE0,
  0XFF,0XFF,0XFF,0XFF,0X83,0X83,0X83,0X83,0XE3,0XE3,0XE3,0XE3,0XE3,0XE3,0X1F,0X1F,
  0XC1,0XC1,0XC1,0XC1,0XC1,0XC1,0XC6,0XC6,0XC6,0XC6,0XC7,0XC7,0XC7,0XC7,0XC7,0XC7,
  0XF8,0XF8,0XF8,0XF8,0XF8,0XF8,0X07,0X07,0X07,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFC,0XFC,0XFC,0XFC,0XFC,0XFC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X80,0X80,0X80,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0X7F,0X7F,0X7F,0X8F,0X8F,0X8F,0X8F,0X8F,0X8F,
  0XE0,0XE0,0XE0,0XE0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X1F,0X1F,0X1F,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XC7,0XC7,0XC7,0XC7,0XC7,0XC7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF
};

// 20x18 tile map
static const uint8_t cailan_games_logo_map[] = {
  0X00,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X02,0X03,0X04,0X05,0X06,0X07,0X01,0X01,0X08,0X09,0X0A,0X0B,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X0C,0X0D,0X0E,0X0F,0X10,0X11,0X01,0X12,0X13,0X14,0X15,0X16,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X17,0X18,0X19,0X1A,0X1B,0X1C,0X1D,0X1E,0X01,0X1F,0X20,0X19,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X21,0X22,0X04,0X05,0X23,0X01,0X24,0X08,0X25,0X06,0X05,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X26,0X27,0X0E,0X0F,0X28,0X29,0X14,0X2A,0X2B,0X2C,0X2D,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X2E,0X2F,0X19,0X1A,0X30,0X01,0X1F,0X1D,0X1F,0X1D,0X20,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01
};

static const uint8_t logo_cursor_sprites[] = {
  0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0X00
};

void show_logo_screen(void) BANKED {
  HIDE_BKG;

  // Load logo tiles and map into VRAM 
  set_bkg_data(0, sizeof(cailan_games_logo_tiles)/TILE_SIZE_BYTES, cailan_games_logo_tiles);
  set_bkg_tiles(0, 0, SCREEN_TILE_WIDTH, SCREEN_TILE_HEIGHT, cailan_games_logo_map);
  
  // Load the cursor sprite into VRAM
  set_sprite_data(0, 1, logo_cursor_sprites);
  set_sprite_tile(0, 0);
  set_sprite_tile(1, 0);
  
  // Enable music
  play_all_channels();
  wait_frames(60);
  fade_in();
  SHOW_BKG;

  // The cursor has two sprites: A top half and a bottom half. The below code controls both halves
  // and blinks them while the logo screen is playing.
  move_sprite(0, 119+8, 75+17);
  move_sprite(1, 119+8, 83+17);
  SHOW_SPRITES;
  play_health_sound();
  for (uint8_t i=0; i<150; i++) {
    if ((i == 30) || (i == 90) || (i == 149)) {
      move_sprite(0, 0, 0);
      move_sprite(1, 0, 0);
    }
    else if ((i == 60) || (i == 120)) {
      move_sprite(0, 119+8, 75+17);
      move_sprite(1, 119+8, 83+17);
    }
    vsync();
  }

  vsync();
  mute_all_channels();

  fade_out();
  HIDE_SPRITES;
}
