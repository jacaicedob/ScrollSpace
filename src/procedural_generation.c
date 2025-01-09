#pragma bank 1

#include <stdint.h>

#include <gb/gb.h>
#include <rand.h>

#include "common.h"
#include "procedural_generation.h"

#define BIOME_COUNT 50
#define COLUMNS_PER_BIOME 20

// Data for biome columns
// Format: 20 [top, bottom] pairs for each biome
static const uint8_t biome_columns[BIOME_COUNT][COLUMNS_PER_BIOME * 2] = {
  {7, 11, 7, 11, 5, 9, 5, 9, 7, 11, 7, 11, 7, 11, 7, 12, 7, 12, 7, 13, 9, 15, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 8, 14, 6, 12, 4, 10},
  {4, 10, 2, 8, 2, 8, 1, 7, 3, 9, 5, 11, 5, 11, 5, 11, 7, 13, 9, 15, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16},
  {10, 15, 8, 13, 10, 15, 8, 13, 8, 12, 6, 10, 4, 8, 4, 9, 4, 10, 4, 10, 6, 12, 8, 14, 8, 14, 8, 14, 10, 16, 8, 14, 8, 14, 10, 16, 10, 16, 10, 16},
  {10, 16, 10, 16, 8, 14, 6, 12, 4, 10, 4, 10, 6, 12, 4, 9, 2, 7, 1, 6, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 6, 1, 6, 3, 8, 5, 10},
  {5, 10, 3, 8, 5, 10, 5, 11, 5, 11, 5, 11, 3, 8, 3, 7, 3, 7, 3, 8, 3, 9, 3, 9, 1, 7, 3, 9, 5, 11, 7, 13, 5, 11, 5, 11, 3, 9, 5, 11},
  {3, 9, 5, 11, 5, 11, 5, 11, 5, 11, 3, 9, 1, 7, 1, 7, 3, 9, 5, 11, 5, 11, 7, 13, 7, 13, 9, 15, 9, 15, 9, 15, 9, 15, 7, 13, 7, 13, 7, 13},
  {9, 15, 9, 15, 10, 16, 8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 8, 14, 8, 14, 8, 14, 10, 16},
  {10, 16, 10, 16, 8, 14, 8, 14, 8, 14, 8, 13, 6, 11, 6, 12, 6, 12, 6, 12, 4, 10, 2, 8, 2, 8, 1, 7, 1, 7, 1, 7, 1, 6, 1, 6, 1, 6, 1, 6},
  {3, 8, 1, 6, 1, 6, 3, 9, 3, 9, 5, 11, 5, 11, 3, 9, 3, 9, 3, 8, 1, 6, 1, 6, 1, 6, 1, 6, 1, 7, 1, 7, 1, 7, 3, 9, 1, 7, 1, 7},
  {3, 9, 3, 9, 1, 7, 1, 7, 1, 7, 1, 6, 1, 6, 1, 6, 1, 6, 1, 7, 3, 9, 3, 9, 5, 11, 3, 9, 3, 8, 1, 6, 1, 6, 1, 6, 1, 7, 1, 7},
  {1, 7, 1, 7, 3, 9, 3, 9, 3, 9, 3, 9, 3, 9, 3, 9, 1, 7, 1, 7, 1, 7, 3, 9, 3, 9, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 3, 9, 3, 9},
  {3, 9, 3, 9, 3, 9, 3, 9, 3, 9, 3, 9, 1, 7, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 5, 11, 7, 13, 9, 15, 7, 13, 9, 15, 9, 15, 10, 16, 10, 16},
  {10, 16, 10, 16, 8, 14, 6, 12, 8, 14, 6, 12, 4, 10, 4, 10, 6, 12, 6, 11, 4, 9, 6, 11, 6, 12, 4, 10, 2, 8, 2, 8, 4, 10, 6, 12, 8, 14, 8, 14},
  {8, 14, 8, 14, 10, 16, 10, 16, 8, 14, 6, 12, 8, 14, 10, 16, 10, 16, 10, 15, 10, 15, 8, 13, 8, 13, 8, 14, 8, 14, 6, 12, 6, 12, 4, 10, 2, 8, 4, 10},
  {4, 10, 2, 8, 1, 7, 1, 6, 1, 6, 3, 8, 3, 9, 5, 11, 3, 9, 3, 9, 5, 11, 7, 13, 7, 13, 7, 13, 5, 11, 3, 9, 3, 9, 1, 7, 1, 7, 1, 7},
  {1, 7, 1, 7, 1, 6, 1, 7, 1, 7, 1, 7, 1, 7, 3, 9, 3, 8, 5, 10, 5, 11, 5, 10, 5, 11, 5, 11, 3, 9, 3, 9, 5, 11, 7, 13, 7, 13, 9, 15},
  {7, 13, 9, 15, 9, 15, 10, 16, 10, 16, 10, 16, 10, 16, 10, 15, 8, 13, 8, 13, 8, 14, 8, 14, 8, 13, 10, 15, 10, 16, 8, 14, 8, 14, 10, 16, 10, 16, 10, 16},
  {10, 16, 10, 16, 10, 16, 8, 14, 6, 12, 8, 14, 8, 14, 8, 14, 10, 16, 8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16},
  {8, 14, 8, 14, 6, 12, 6, 12, 4, 10, 4, 10, 4, 10, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 4, 10, 4, 9, 4, 9, 6, 11, 6, 11, 6, 11, 4, 9, 4, 9},
  {4, 10, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 4, 10, 6, 12, 4, 10, 4, 10, 2, 8, 1, 7, 1, 7, 3, 9, 3, 8, 5, 10, 7, 12, 7, 12, 9, 14, 10, 15},
  {10, 15, 10, 15, 10, 15, 10, 16, 10, 16, 8, 14, 8, 14, 8, 14, 10, 16, 8, 14, 10, 16, 10, 16, 10, 16, 8, 14, 6, 12, 4, 10, 6, 12, 6, 12, 8, 14, 10, 16},
  {8, 13, 8, 13, 6, 11, 4, 9, 6, 11, 6, 12, 4, 10, 4, 10, 4, 10, 6, 12, 4, 10, 4, 10, 6, 12, 6, 12, 6, 12, 4, 10, 4, 10, 2, 8, 1, 7, 1, 7},
  {1, 7, 1, 7, 1, 7, 1, 6, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 3, 7, 3, 7, 3, 7, 3, 7, 3, 7, 5, 9, 7, 11, 5, 9, 7, 11},
  {7, 11, 7, 11, 9, 14, 7, 12, 7, 12, 5, 10, 3, 8, 5, 10, 7, 12, 9, 14, 10, 16, 10, 16, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 10, 16, 10, 16},
  {8, 14, 8, 14, 10, 16, 10, 16, 8, 14, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 4, 10, 2, 8},
  {1, 7, 1, 7, 3, 9, 3, 9, 5, 11, 7, 13, 9, 15, 9, 15, 9, 15, 9, 15, 9, 15, 9, 15, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16},
  {10, 16, 10, 16, 8, 14, 8, 14, 6, 12, 8, 14, 8, 14, 8, 14, 6, 12, 6, 12, 6, 12, 6, 12, 4, 10, 4, 10, 4, 9, 6, 11, 6, 11, 8, 13, 6, 11, 4, 9},
  {4, 9, 2, 7, 2, 7, 2, 8, 2, 7, 2, 8, 4, 10, 6, 12, 6, 12, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 6, 12, 6, 12, 8, 14},
  {6, 12, 4, 10, 6, 12, 8, 14, 10, 16, 10, 16, 8, 14, 8, 14, 6, 12, 6, 12, 8, 14, 8, 14, 8, 14, 8, 14, 6, 12, 6, 12, 6, 12, 4, 10, 4, 10, 6, 12},
  {8, 14, 8, 14, 8, 14, 8, 14, 6, 12, 6, 12, 6, 12, 8, 14, 8, 14, 8, 14, 8, 14, 8, 14, 6, 12, 6, 12, 6, 12, 6, 12, 8, 14, 8, 14, 8, 14, 8, 14},
  {8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 15, 10, 14, 10, 15, 8, 13, 10, 16, 10, 16, 10, 16, 10, 15, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16},
  {8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 8, 14, 6, 12, 6, 12, 4, 10, 2, 8, 4, 10, 6, 12, 6, 12, 6, 12, 6, 12, 8, 14},
  {8, 14, 8, 14, 8, 14, 10, 16, 8, 14, 6, 12, 4, 10, 6, 12, 4, 10, 6, 12, 6, 12, 6, 12, 6, 11, 6, 11, 6, 12, 4, 10, 4, 10, 4, 10, 4, 10, 4, 10},
  {4, 10, 4, 10, 2, 8, 2, 8, 2, 8, 2, 8, 2, 8, 2, 8, 1, 7, 3, 9, 5, 11, 7, 13, 7, 13, 9, 15, 9, 14, 7, 12, 7, 13, 9, 15, 9, 15, 9, 15},
  {7, 13, 7, 13, 7, 13, 5, 11, 5, 11, 7, 13, 7, 12, 7, 13, 7, 12, 5, 10, 7, 12, 5, 10, 3, 8, 5, 10, 7, 12, 5, 10, 5, 10, 5, 11, 3, 9, 5, 11},
  {3, 9, 3, 9, 3, 9, 1, 7, 1, 6, 3, 8, 1, 5, 1, 5, 1, 5, 1, 5, 1, 6, 1, 6, 1, 7, 3, 9, 3, 9, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7},
  {1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 3, 9},
  {3, 9, 3, 9, 3, 9, 3, 9, 5, 11, 7, 13, 9, 15, 10, 16, 10, 15, 10, 15, 8, 13, 10, 15, 10, 15, 10, 15, 10, 16, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16},
  {10, 16, 10, 16, 10, 16, 8, 14, 8, 14, 8, 14, 8, 14, 6, 12, 4, 10, 4, 10, 6, 11, 6, 11, 4, 9, 2, 7, 2, 7, 2, 8, 1, 7, 1, 7, 1, 7, 1, 7},
  {3, 9, 3, 9, 5, 11, 3, 9, 3, 9, 1, 7, 1, 7, 1, 6, 1, 6, 1, 6, 1, 6, 3, 8, 3, 8, 3, 8, 3, 9, 3, 9, 3, 9, 3, 9, 1, 7, 1, 7},
  {3, 9, 1, 7, 3, 9, 5, 11, 3, 9, 5, 11, 7, 13, 9, 15, 9, 15, 10, 15, 8, 13, 8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16},
  {10, 16, 8, 14, 8, 14, 10, 16, 8, 14, 6, 12, 6, 12, 8, 14, 6, 12, 6, 12, 6, 12, 4, 10, 4, 10, 4, 10, 4, 9, 6, 11, 6, 12, 8, 14, 8, 14, 6, 12},
  {8, 14, 6, 12, 8, 14, 8, 14, 8, 14, 8, 14, 10, 16, 10, 16, 8, 14, 8, 13, 10, 15, 8, 13, 8, 13, 8, 14, 10, 16, 8, 14, 8, 14, 8, 14, 6, 12, 6, 11},
  {4, 9, 6, 11, 4, 9, 6, 11, 6, 12, 4, 10, 6, 12, 6, 12, 6, 12, 6, 12, 4, 10, 4, 10, 6, 12, 8, 14, 8, 14, 8, 14, 8, 13, 8, 13, 8, 13, 8, 14},
  {8, 14, 8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 8, 14, 6, 12, 6, 12, 4, 10, 2, 8, 4, 10, 4, 10, 4, 10, 4, 10, 6, 12, 6, 12},
  {8, 14, 8, 14, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 8, 14, 10, 16, 10, 16, 10, 15, 10, 15, 10, 15, 10, 15, 10, 15, 10, 15, 10, 15, 8, 13, 8, 14},
  {8, 13, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 10, 16, 8, 14, 6, 12, 6, 12, 6, 12, 4, 10, 6, 12, 6, 12, 4, 10, 4, 10, 4, 10, 6, 12, 8, 14, 8, 14},
  {6, 12, 6, 12, 6, 12, 6, 12, 6, 12, 8, 14, 8, 14, 8, 14, 6, 12, 8, 14, 8, 14, 8, 14, 6, 12, 6, 12, 6, 12, 6, 12, 4, 10, 2, 8, 1, 7, 3, 9},
  {3, 9, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 3, 9, 1, 7, 3, 9, 3, 9, 5, 11, 5, 10, 7, 12, 5, 10, 3, 8, 5, 10, 3, 8, 3, 9},
  {3, 9, 5, 11, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 5, 11, 5, 11, 7, 13, 5, 11, 5, 11, 5, 11, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 5, 11, 5, 11}
};

// Which biomes can be used after the current biome
static const uint8_t next_possible_biomes[BIOME_COUNT][1] = {
  {1},
  {2},
  {3},
  {4},
  {5},
  {6},
  {7},
  {8},
  {9},
  {10},
  {11},
  {12},
  {13},
  {14},
  {15},
  {16},
  {17},
  {18},
  {19},
  {20},
  {21},
  {22},
  {23},
  {24},
  {25},
  {26},
  {27},
  {28},
  {29},
  {30},
  {31},
  {32},
  {33},
  {34},
  {35},
  {36},
  {37},
  {38},
  {39},
  {40},
  {41},
  {42},
  {43},
  {44},
  {45},
  {46},
  {47},
  {48},
  {49},
  {0}
};

// Current generation state variables
static uint8_t biome_id = 0;  // The ID of the biome that's currently being generated
static uint8_t biome_column_index = 0;  // The column index within the current biome being generated

void reset_generation_state(void) BANKED {
  biome_id = 0;
  biome_column_index = 0;
}

void generate_column(uint8_t column_idx) BANKED {
  // Add tiles to collision and background maps.
  uint8_t* coll_map = collision_map + column_idx;
  uint8_t* bkg_map = background_map + column_idx;
  uint8_t cave_top = biome_columns[biome_id][biome_column_index * 2];
  uint8_t cave_bottom = biome_columns[biome_id][biome_column_index * 2 + 1];

  for (uint16_t row = 0; row < COLUMN_HEIGHT; ++row) {
    // TODO: Add random variance.
    uint16_t map_index = MAP_INDEX_ROW_OFFSET(row);
    if (row < cave_top || row > cave_bottom) {
      // Create a block.
      coll_map[map_index] = BLOCK_HEALTH;
      bkg_map[map_index] = MAPBLOCK_IDX;
      continue;
    }

    uint16_t n = randw();
    if (n > 65300) {
      // Create a health tile.
      coll_map[map_index] = HEALTH_KIT_ID;
      bkg_map[map_index] = HEALTH_KIT_TILE;
    } else if (n > 65000) {
      // Create a shield tile.
      coll_map[map_index] = SHIELD_ID;
      bkg_map[map_index] = SHIELD_TILE;
    } else if (n > 60000) {
      // Create a mine tile.
      coll_map[map_index] = MINE_HEALTH;
      bkg_map[map_index] = MINE_IDX;
    } else {
      // Create an empty tile.
      coll_map[map_index] = 0;
      bkg_map[map_index] = EMPTY_TILE_IDX;
    }
  }

  // Update current generation state.
  if (++biome_column_index >= COLUMNS_PER_BIOME) {
    biome_id = next_possible_biomes[biome_id][0];  // TODO: Add randomness.
    biome_column_index = 0;
  }
}
