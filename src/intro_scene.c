#pragma bank 1

#include "intro_scene.h"

#include <gb/gb.h>
#include <hUGEDriver.h>
#include <stdint.h>
#include <string.h>

#include "common.h"
#include "display_effects.h"
#include "songs.h"
#include "sound_effects.h"
#include "sprite_data.h"
#include "tile_data.h"

// The below data is generated with a specific format and thus shouldn't be auto-formatted.
// clang-format off

static const uint8_t intro_player_heatshield_sprites_data[] = {
  0X00,0X00,0X00,0X14,0X00,0XA2,0X00,0X08,0X00,0X24,0X00,0X03,0X00,0X55,0X00,0X0F,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X00,0X00,0XA0,0X00,0X50,0X00,0XEC,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X2A,0X00,0X07,0X00,0X25,0X00,0X0F,0X00,0X07,0X01,0X06,0X01,0X02,0X00,0X03,
  0X60,0XFE,0XF8,0X9F,0X8E,0XF7,0XF1,0X8F,0XF1,0X8F,0X8F,0XF6,0XFE,0X99,0XF8,0X67,
  0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X40,0X80,0X40,0X00,0XC0,0X00,0XC0,0X00,0X80,
  0X00,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X60,0X9F,0X00,0X7E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X14,0X00,0XA2,0X00,0X08,0X00,0X24,0X00,0X02,0X00,0X55,0X00,0X0A,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X00,0X00,0XA0,0X00,0X50,0X00,0XA4,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X2A,0X00,0X05,0X00,0X25,0X00,0X0B,0X00,0X02,0X01,0X04,0X01,0X02,0X00,0X01,
  0X60,0XFA,0XF8,0X9D,0X8E,0XF7,0XF1,0X8F,0XF1,0X8F,0X8F,0XF6,0XFE,0X99,0XF8,0X66,
  0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X40,0X80,0X40,0X00,0XC0,0X00,0X00,0X00,0X00,
  0X00,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X60,0X9C,0X00,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X04,0X00,0X02,0X00,0X15,0X00,0X0A,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X00,0X40,0X00,0XA0,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X0A,0X00,0X01,0X00,0X04,0X00,0X01,0X00,0X02,0X00,0X01,0X00,0X01,0X00,0X00,
  0X60,0XF8,0XF8,0X9C,0X8E,0XF7,0XF1,0X8F,0XF1,0X8F,0X8E,0XF7,0XF8,0X9E,0X60,0XF8,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X00,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00
};

// 13 tiles
static const uint8_t intro_stars_tiles[] = {
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XEB,0XEB,0XF7,0XF7,0XEB,0XEB,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XF7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XF7,0XE3,0XE3,0XF7,0XF7,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XF7,0XFF,0XDD,0XF7,0XF7,0XEB,0X2A,0XF7,0XF7,0XFF,0XDD,0XFF,0XF7,0XFF,0XF7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XF7,0XF7,0XF7,0XF7,0XC9,0XC9,0XF7,0XF7,0XF7,0XF7,0XFF,0XFF,
  0XFF,0XF7,0XFF,0XF7,0XF7,0XD5,0XE3,0XE3,0XC9,0X08,0XE3,0XE3,0XF7,0XD5,0XFF,0XF7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XF7,0XF7,0XEB,0XEB,0XDD,0X5D,0XEB,0XEB,0XF7,0XF7,0XFF,0XFF,0XFF,0XF7,
  0XFF,0XF7,0XFF,0XDD,0XF7,0XF7,0XE3,0X2A,0XF7,0XF7,0XFF,0XDD,0XFF,0XF7,0XFF,0XF7,
  0XFF,0XF7,0XFF,0XF7,0XFF,0XDD,0XEB,0XEB,0XF7,0XF7,0XEB,0XEB,0XFF,0XDD,0XFF,0XF7
};

// 32x18 tile map
static const uint8_t intro_stars_map[] = {
  0X80,0X80,0X80,0X80,0X80,0X80,0X81,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X82,0X80,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X83,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X83,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X84,0X85,0X86,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X80,0X80,0X80,0X86,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X87,0X88,
  0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X82,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X82,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X83,0X80,
  0X80,0X8A,0X85,0X80,0X80,0X81,0X80,0X80,0X80,0X82,0X80,0X80,0X83,0X80,0X80,0X8A,0X85,0X80,0X80,0X81,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X8B,0X85,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X8C,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X80,0X82,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X8C,0X80,0X80,0X80,0X80,0X80,0X82,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X8C,0X80,0X80,0X80,0X80,0X80,0X82,0X80,0X80,0X8A,0X85,0X80,0X80,
  0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X84,0X85,0X80,0X80,0X80,0X80,0X80,0X80,0X89,
  0X80,0X80,0X80,0X80,0X80,0X84,0X85,0X80,0X89,0X80,0X80,0X80,0X87,0X88,0X80,0X80,0X80,0X80,0X80,0X86,
  0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X82,0X80,0X80,0X80,0X86,0X80,0X80,0X80,0X89,0X80,0X80,
  0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X8A,0X85,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X83,0X80,0X80,0X80,0X82,0X80,0X80,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X86,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X86,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X84,0X85,0X80,0X80,0X80,0X83,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X83,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X83,0X80,0X80,0X8C,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X83,0X80,0X80,0X8C,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,
  0X80,0X87,0X88,0X80,0X83,0X80,0X80,0X86,0X8C,0X80,0X80,0X80,0X80,0X82,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X80,0X8C,0X80,0X80,0X80,0X80,0X82,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,
  0X89,0X80,0X80,0X80,0X80,0X8A,0X85,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X8A,
  0X85,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X89,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
  0X80,0X86,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80
};

// 23 tiles
static const uint8_t intro_atmosphere_tiles[] = {
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XEB,0XEB,0XF7,0XF7,0XEB,0XEB,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XF7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XF7,0XE3,0XE3,0XF7,0XF7,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XF7,0XFF,0XDD,0XF7,0XF7,0XEB,0X2A,0XF7,0XF7,0XFF,0XDD,0XFF,0XF7,0XFF,0XF7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XFF,0XFF,0XFF,0XF7,0XF7,0XF7,0XF7,0XC9,0XC9,0XF7,0XF7,0XF7,0XF7,0XFF,0XFF,
  0XFF,0XF7,0XFF,0XF7,0XF7,0XD5,0XE3,0XE3,0XC9,0X08,0XE3,0XE3,0XF7,0XD5,0XF7,0XF7,
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
  0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
  0XFF,0XFF,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0XFF,0XFF,0X00,0XFF,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X78,0X00,0X86,0X00,0X01,0X00,0X00,0X00,0X01,0X00,0X0E,0X00,0X31,0X00,0X40,
  0X00,0X1C,0X00,0X63,0X00,0X80,0X00,0XF1,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X80,
  0X00,0X00,0X00,0X78,0X00,0X87,0X00,0X04,0X00,0X08,0X00,0X10,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X1F,0X00,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0XF0,0X00,0X0F,0X00,0X08,0X00,0X10,0X00,0X20,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X3F,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0XF0,0X00,0X0C,0X00,0X03,0X00,0X01,0X00,0X02,0X00,0X1C,0X00,0X62,0X00,0X81,
  0X00,0X38,0X00,0XC6,0X00,0X01,0X00,0XE2,0X00,0X10,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0XC0,0X00,0X3F,0X00,0X20,0X00,0X40,0X00,0X80,0X00,0X00,0X00,0X00,
  0X00,0X03,0X00,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X00,0X02
};

// 32x18 tile map
static const uint8_t intro_atmosphere_map[] = {
  0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8D,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8E,0X8C,
  0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8F,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,
  0X8C,0X8C,0X8F,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X90,0X91,0X92,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,
  0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X92,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X93,0X94,
  0X8C,0X8C,0X95,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X8C,0X96,0X96,0X96,0X96,
  0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,
  0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X96,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,
  0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,0X97,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X99,0X9A,0X9B,0X9C,
  0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,
  0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,
  0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0XA1,0XA2,
  0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,
  0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,
  0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,
  0X9D,0X9E,0XA1,0XA2,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,
  0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X99,0X9A,0X9B,0X9C,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,
  0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,0X9D,0X9E,0X9F,0XA0,
  0X9D,0X9E,0XA1,0XA2,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
  0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98
};

// clang-format on

// Swaps in the heat shield sprites, starting at the given sprite ID.
static void swap_in_heat_shield_sprites(uint8_t starting_id, uint8_t x, uint8_t y) {
  // Swap out current sprites.
  uint8_t i = (starting_id == 1) ? 0 : starting_id - 9;
  while (i < starting_id) {
    move_sprite(i, 0, 0);
    ++i;
  }

  // Swap in new sprites.
  move_sprite(starting_id++, x - 8, y - 8);  // top left
  move_sprite(starting_id++, x, y - 8);      // top middle
  move_sprite(starting_id++, x + 8, y - 8);  // top right
  move_sprite(starting_id++, x - 8, y);      // left of player
  move_sprite(starting_id++, x, y);          // player sprite
  move_sprite(starting_id++, x + 8, y);      // right of player
  move_sprite(starting_id++, x - 8, y + 8);  // bottom left
  move_sprite(starting_id++, x, y + 8);      // bottom middle
  move_sprite(starting_id, x + 8, y + 8);    // bottom right
}

// Scrolls the ship through the atmosphere to the given y position, updating the color palette
// along the way.
static void scroll_through_atmosphere(uint8_t end_y) {
  uint8_t i = 0;
  while (SCY_REG < end_y) {
    scroll_bkg(1, 1);
    vsync();
    i = MOD8(i + 1);
    if (i == 0) {
      OBP0_REG = 0x8C;  // 0b1000 1100 - dark gray, white, black, white
    } else {
      OBP0_REG = 0xE4;  // 0b1101 0000 - black, dark gray, light gray, white
    }
  }
  OBP0_REG = 0xE4;  // 0b1110 0100 - black, light gray, white, transparent
}

void show_intro_scene(void) BANKED {
  // Fill the background map with empty tiles
  memset(background_map, 0x98, COLUMN_HEIGHT * ROW_WIDTH);

  __critical {
    hUGE_init(&intro_song);
    add_VBL(hUGE_dosound);
  }
  play_all_channels();

  HIDE_BKG;
  // Load intro tiles and map into VRAM
  set_bkg_data(INTRO_SCENE_OFFSET, TILE_COUNT(intro_stars_tiles), intro_stars_tiles);
  set_bkg_data(INTRO_SCENE_STARS_OFFSET, TILE_COUNT(intro_atmosphere_tiles), intro_atmosphere_tiles);
  set_bkg_data(TITLE_SCREEN_OFFSET, TILE_COUNT(title_screen_tiles), title_screen_tiles);
  set_bkg_tiles(0, 0, 32, 18, intro_stars_map);
  set_bkg_tiles(0, 18, 32, 14, intro_atmosphere_map);

  // Load player sprite and set it to sprite 0
  set_sprite_data(0, 1, player_sprites);
  set_sprite_data(1, TILE_COUNT(intro_player_heatshield_sprites_data), intro_player_heatshield_sprites_data);
  for (uint8_t i = 0; i < 28; ++i) {
    set_sprite_tile(i, i);
  }

  // Move sprite to initial position
  uint8_t x = 24;
  uint8_t y = 72;
  move_sprite(0, x, y);
  fade_in();

  SHOW_BKG;
  SHOW_SPRITES;

  /*
   * Horizontal movement through space
   */
  for (uint8_t i = 0; i < 90; ++i) {
    vsync();
    scroll_bkg(4, 0);
  }
  for (uint8_t i = 0; i < 36; ++i) {
    vsync();
    scroll_bkg(3, 0);
  }
  for (uint8_t i = 0; i < 22; ++i) {
    vsync();
    scroll_bkg(2, 0);
  }

  /*
   * Enter planet animation
   * Move screen diagonally
   */
  // Align screen to the right
  while (SCY_REG < 112) {
    scroll_bkg(1, 1);
    vsync();
  }

  set_bkg_tiles(0, 0, 20, 14, background_map);
  set_bkg_tiles(20, 0, 12, 14, background_map);

  // Switch to heat shield sprites
  swap_in_heat_shield_sprites(1, x, y);

  hUGE_mute_channel(HT_CH4, HT_CH_MUTE);

  NR42_REG = 0x00;
  NR44_REG = 0x00;

  // Play sound effect.
  NR41_REG = 0x00;
  NR42_REG = 0xF7;
  NR43_REG = 0x81;
  NR44_REG = 0x80;

  scroll_through_atmosphere(176);

  // Switch to dissipated heat shield sprites
  swap_in_heat_shield_sprites(10, x, y);
  scroll_through_atmosphere(208);

  // Switch to almost gone dissipated heat shield sprites
  swap_in_heat_shield_sprites(19, x, y);
  scroll_through_atmosphere(224);

  set_bkg_tiles(0, 14, 20, 14, background_map);
  set_bkg_tiles(20, 14, 12, 14, background_map);

  while (SCY_REG < 240) {
    scroll_bkg(1, 1);
    vsync();
  }
  // Restart channel.
  hUGE_mute_channel(HT_CH4, HT_CH_PLAY);

  // Hide all sprites except the plane itself
  for (uint8_t i = 1; i < 28; ++i) {
    move_sprite(i, 0, 0);
  }
  move_sprite(0, x, y);

  set_bkg_tiles(0, 28, 20, 2, background_map);
  set_bkg_tiles(20, 28, 12, 2, background_map);

  // Fill in background map with block tiles
  memset(background_map, 0xA5, 144);

  while (SCX_REG != 0) {
    scroll_bkg(1, 1);
    vsync();
  }

  // Load title screen
  set_bkg_tiles(12, 13, 20, 18, title_screen_map);
  // Load the blocks into the missing side areas
  set_bkg_tiles(20, 1, 12, 12, background_map);
  set_bkg_tiles(3, 22, 9, 9, background_map);

  // Set the ship sprite's priority so that background tiles are drawn on top of the sprite.
  set_sprite_prop(0, 0x80);

  while (SCY_REG < 8) {
    scroll_bkg(0, 1);
    vsync();
  }

  while (SCX_REG < 96) {
    scroll_bkg(1, 1);
    vsync();
  }

  for (uint8_t i = 0; i < 12; ++i) {
    scroll_sprite(0, 2, 2);
    vsync();
  }

  // Fly off and spell PRESS START
  for (uint8_t i = 0; i < 116 / 4; ++i) {
    scroll_sprite(0, 4, 0);
    vsync();
  }

  // End of intro scene
  set_sprite_prop(0, 0);  // Reset sprite priority to default
  move_sprite(0, 0, 0);
  HIDE_SPRITES;
  move_bkg(0, 0);
  return;
}
