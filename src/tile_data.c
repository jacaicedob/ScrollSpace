#pragma bank 1

#include <stdint.h>

// 4 tiles
const uint8_t block_tiles[] = {
  0X10,0XEF,0X42,0XB9,0X08,0XD7,0X44,0XBA,0X10,0XEB,0X49,0XB6,0X02,0XD9,0X10,0XEF,
  0X00,0X7E,0X3C,0XC3,0X5A,0XA5,0X66,0X99,0X66,0X99,0X5A,0XA5,0X3C,0XC3,0X00,0X7E,
  0X00,0X81,0X00,0X5A,0X18,0X24,0X24,0X5A,0X24,0X5A,0X18,0X24,0X00,0X5A,0X00,0X81,
  0X00,0X00,0X00,0X10,0X00,0X44,0X00,0X10,0X00,0X4A,0X00,0X00,0X00,0X14,0X00,0X00
};

// 7 tiles
const uint8_t health_bar_tiles[] = {
  0X7E,0X7E,0X7E,0X42,0X24,0X24,0X18,0X18,0X18,0X18,0X3C,0X24,0X42,0X42,0X7E,0X7E,
  0X00,0X00,0X0F,0X0F,0X10,0X10,0X1F,0X10,0X1F,0X10,0X10,0X1F,0X0F,0X0F,0X00,0X00,
  0X00,0X00,0XFF,0XFF,0X00,0X00,0XFF,0X00,0XFF,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,
  0X00,0X00,0XF0,0XF0,0X08,0X08,0XF8,0X08,0XF8,0X08,0X08,0XF8,0XF0,0XF0,0X00,0X00,
  0X00,0X00,0X0F,0X0F,0X10,0X1F,0X10,0X1F,0X10,0X1F,0X10,0X1F,0X0F,0X0F,0X00,0X00,
  0X00,0X00,0XFF,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0X00,0XFF,0XFF,0XFF,0X00,0X00,
  0X00,0X00,0XF0,0XF0,0X08,0XF8,0X08,0XF8,0X08,0XF8,0X08,0XF8,0XF0,0XF0,0X00,0X00
};

// 9 tiles
const uint8_t powerup_tiles[] = {
  0X00,0X00,0X28,0X28,0X54,0X54,0X7C,0X54,0X7C,0X54,0X7C,0X54,0X7C,0X7C,0X00,0X00,
  0X00,0X00,0X10,0X00,0X38,0X38,0X5C,0X5C,0X7C,0X7C,0X7C,0X7C,0X38,0X38,0X00,0X00,
  0X00,0X00,0X3C,0X7E,0X46,0X5A,0X46,0X6A,0X46,0X7A,0X2C,0X34,0X18,0X18,0X00,0X00,
  0X00,0X00,0X22,0X3E,0X7C,0X46,0X6C,0X02,0X44,0X02,0X6E,0X02,0X7C,0X44,0X00,0X00,
  0X00,0XFF,0X28,0XD7,0X54,0XAB,0X54,0X83,0X54,0X83,0X54,0X83,0X7C,0X83,0X00,0XFF,
  0X00,0XFF,0X00,0XEF,0X38,0XC7,0X5C,0XA3,0X7C,0X83,0X7C,0X83,0X38,0XC7,0X00,0XFF,
  0X00,0XFF,0X7E,0XC3,0X5A,0XB9,0X6A,0XB9,0X7A,0XB9,0X34,0XD3,0X18,0XE7,0X00,0XFF,
  0X00,0XFF,0X3E,0XDD,0X46,0X83,0X02,0X93,0X02,0XBB,0X02,0X91,0X44,0X83,0X00,0XFF,
  0X00,0X81,0X10,0X42,0X18,0X3C,0X4C,0X5C,0X74,0X7C,0X58,0X7C,0X38,0X7A,0X00,0X81
};

// 1 tile
const uint8_t lock_tiles[] = {
  0X3C,0X3C,0X42,0X42,0X42,0X42,0XFF,0XFF,0XB1,0X8F,0XF1,0X8F,0XF1,0X8F,0X7E,0X7E
};

// 2 tiles
const uint8_t font_extras_tiles[] = {
  0X00,0X00,0X00,0X00,0X10,0X10,0X00,0X00,0X00,0X00,0X10,0X10,0X00,0X00,0X00,0X00,
  0X00,0X00,0X60,0X60,0X70,0X70,0X78,0X78,0X7C,0X7C,0X78,0X78,0X70,0X70,0X60,0X60,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X40,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X20,0X20,0X20,0X20,0X40,0X40,
  0X00,0X00,0X1C,0X1C,0X22,0X22,0X0C,0X0C,0X08,0X08,0X00,0X00,0X08,0X08,0X00,0X00
};

// 20x18 tile map
// TODO: Get rid of this.
const uint8_t gameover_screen_map[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x11,0x0B,0x17,0x0F,0x00,0x19,0x20,0x0F,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0F,0x1D,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// 8 tiles
const uint8_t tutorial_screen_tiles[] = {
  0X10,0XEF,0X42,0XB9,0X08,0XD7,0X44,0XBA,0X10,0XEB,0X49,0XB6,0X02,0XD9,0X10,0XEF,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7E,0X7E,0X81,0X81,
  0X01,0X01,0X02,0X02,0X02,0X02,0X02,0X02,0X02,0X02,0X02,0X02,0X02,0X02,0X01,0X01,
  0X80,0X80,0X40,0X40,0X40,0X40,0X40,0X40,0X40,0X40,0X40,0X40,0X40,0X40,0X80,0X80,
  0X81,0X81,0X7E,0X7E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,
  0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00
};

// 20x17 tile map
const uint8_t tutorial_screen_map[] = {
  0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X40,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X41,0X3F,0X42,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X43,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X40,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X41,0X3F,0X42,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X43,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X44,0X44,0X44,0X44,0X44,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X41,0X3F,0X3F,0X3F,0X3F,0X3F,0X42,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X45,0X45,0X45,0X45,0X45,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F,
  0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E
};

const uint8_t title_screen_tiles[] = {
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X10,0XEF,0X42,0XB9,0X08,0XD7,0X44,0XBA,0X10,0XEB,0X49,0XB6,0X02,0XD9,0X10,0XEF,
  0X00,0X00,0X07,0X07,0X0F,0X0F,0X1F,0X1F,0X1E,0X1E,0X1E,0X1E,0X1F,0X1F,0X1F,0X1F,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,
  0X00,0X00,0XF8,0XF8,0XF9,0XF9,0XF3,0XF3,0X03,0X03,0X03,0X03,0XC3,0XC3,0XF3,0XF3,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,
  0X00,0X00,0XFE,0XFE,0XFE,0XFE,0XFC,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X01,
  0X00,0X00,0X7F,0X7F,0XFF,0XFF,0XFF,0XFF,0XF0,0XF0,0XF0,0XF0,0XFF,0XFF,0XFF,0XFF,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X07,0X07,0X07,0X07,0XFF,0XFF,0XFF,0XFF,
  0X00,0X00,0X0F,0X0F,0X9F,0X9F,0X9F,0X9F,0XBC,0XBC,0XBC,0XBC,0XBC,0XBC,0X3C,0X3C,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0X00,0X00,0XF1,0XF1,0XF9,0XF9,0XF9,0XF9,0X79,0X79,0X79,0X79,0X79,0X79,0X7B,0X7B,
  0X00,0X00,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XC0,0XC0,
  0X00,0X00,0X01,0X01,0X01,0X01,0X01,0X01,0X03,0X03,0X03,0X03,0X03,0X03,0X03,0X03,
  0X00,0X00,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,
  0X0F,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X00,0X00,
  0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0XF7,0XF7,0XF7,0XF7,0XF7,0XF7,0XF7,0XF7,0XE7,0XE7,0XE7,0XE7,0XC3,0XC3,0X00,0X00,
  0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0XF9,0XF9,0XFB,0XFB,0XFB,0XFB,0X00,0X00,
  0XFF,0XFF,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XC0,0XC0,0XC0,0XC0,0X00,0X00,
  0XFE,0XFE,0X78,0X78,0X3C,0X3C,0X3C,0X3C,0X3C,0X3C,0X1E,0X1E,0X1E,0X1E,0X00,0X00,
  0X38,0X38,0X78,0X78,0X78,0X78,0X78,0X78,0X7F,0X7F,0X7F,0X7F,0X3F,0X3F,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0X73,0X73,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XE7,0XE7,0XC7,0XC7,0X00,0X00,
  0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0X03,0X03,0X03,0X03,0X03,0X03,0X03,0X03,0XF3,0XF3,0XF7,0XF7,0XF7,0XF7,0X00,0X00,
  0XC0,0XC0,0XC0,0XC0,0X80,0X80,0X80,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF0,0XF0,0XF0,0XF0,0XF0,0XF0,0X00,0X00,
  0X00,0X00,0X1F,0X1F,0X3F,0X3F,0X7F,0X7F,0X78,0X78,0X78,0X78,0X7F,0X7F,0X7F,0X7F,
  0X00,0X00,0XCF,0XCF,0XCF,0XCF,0X8F,0X8F,0X0F,0X0F,0X0F,0X0F,0X1F,0X1F,0X9F,0X9F,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,
  0X00,0X00,0XF0,0XF0,0XF8,0XF8,0XF8,0XF8,0X78,0X78,0XF1,0XF1,0XF3,0XF3,0XF3,0XF3,
  0X00,0X00,0X1E,0X1E,0X3E,0X3E,0X7F,0X7F,0XFF,0XFF,0XF7,0XF7,0XE7,0XE7,0XC3,0XC3,
  0X00,0X00,0X00,0X00,0X01,0X01,0X03,0X03,0X03,0X03,0X83,0X83,0X83,0X83,0XC7,0XC7,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XC0,0XC0,0XC0,0XC0,0XC0,0X80,0X80,
  0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFE,0XFE,0X00,0X00,0X00,0X00,0XFC,0XFC,0XFC,0XFC,
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X01,0X01,0X01,0X01,0X01,0X00,0X00,
  0X3F,0X3F,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0XFF,0XFF,0X07,0X07,0X07,0X07,0X07,0X07,0XFF,0XFF,0XFF,0XFF,0XFE,0XFE,0X00,0X00,
  0X9F,0X9F,0X9F,0X9F,0X9E,0X9E,0X9E,0X9E,0XBC,0XBC,0X3C,0X3C,0X3C,0X3C,0X00,0X00,
  0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0XE7,0XE7,0XCF,0XCF,0X1E,0X1E,0X3E,0X3E,0X7C,0X7C,0XF8,0XF8,0XF0,0XF0,0X00,0X00,
  0X83,0X83,0X01,0X01,0X01,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  0XC7,0XC7,0XE7,0XE7,0XE7,0XE7,0XF7,0XF7,0XF7,0XF7,0XFB,0XFB,0X79,0X79,0X00,0X00,
  0XFF,0XFF,0XE0,0XE0,0XE0,0XE0,0XE0,0XE0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
  0XFC,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0XFC,0XFC,0XFC,0XFC,0XFC,0XFC,0X00,0X00
};

// 20x18 tile map
const uint8_t title_screen_map[] = {
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,0XA5,0XA5,
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,
  0XA4,0XA6,0XA7,0XA8,0XA9,0XAA,0XAB,0XAC,0XAD,0XAE,0XAF,0XB0,0XB1,0XB2,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,
  0XA4,0XB3,0XB4,0XB5,0XB6,0XB7,0XB8,0XB9,0XBA,0XBB,0XBC,0XBD,0XBE,0XBF,0XC0,0XA4,0XA4,0XA4,0XA4,0XA4,
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XC1,0XA7,0XC2,0XC3,0XC4,0XC5,0XC6,0XC7,0XAA,0XAB,0XC8,0XA4,
  0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XC9,0XCA,0XCB,0XCC,0XCD,0XCE,0XCF,0XD0,0XB6,0XB7,0XD1,0XD2,0XA4,
  0XA5,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,
  0XA5,0XA5,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,
  0XA5,0XA5,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,
  0XA5,0XA5,0XA5,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,
  0XA5,0XA5,0XA5,0XA5,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,
  0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,0XA5,
  0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA4,0XA4,0XA4,0XA4,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,
  0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,
  0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5,0XA5
};

// 49 tiles
const uint8_t cailan_games_logo_tiles[] = {
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
const uint8_t cailan_games_logo_map[] = {
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

// 13 tiles
const uint8_t intro_stars_tiles[] = {
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
const uint8_t intro_stars_map[] = {
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
const uint8_t intro_atmosphere_tiles[] = {
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
const uint8_t intro_atmosphere_map[] = {
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

// 32x18 tile map
// TODO: Use background_map for this instead.
const uint8_t empty_screen_map[] = {
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,
  0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98,0x98
};
