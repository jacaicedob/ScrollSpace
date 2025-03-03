// A small program to convert the old format for biome data to the new format.
//
// Old format: 20 [topRow, bottomRow] pairs for each biome
// New format: 20 uint8_t's for each biome. Each uint8_t contains two 4-bit numbers. The higher
// 4 bits is the cave's top row, and the lower 4 bits is the cave's width minus the MINIMUM_CAVE_WIDTH
//
// To run this program, simply run the following command:
//
//	go run biome_format_converter.go
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// Note: This value should match MINIMUM_CAVE_WIDTH in src/procedural_generation.c.
const minCaveWidth = 3

const biomesOldFormat = `
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
  {3, 9, 5, 11, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 5, 11, 5, 11, 7, 13, 5, 11, 5, 11, 5, 11, 3, 9, 3, 9, 5, 11, 5, 11, 5, 11, 5, 11, 5, 11},
`

func main() {
	fmt.Println("Converting biome data format...")

	lines := strings.Split(biomesOldFormat, "\n")
	fmt.Printf("Num input lines: %d\n", len(lines))
	biomes := [][]uint8{}
	for _, line := range lines {
		line = strings.TrimSpace(line)
		line = strings.ReplaceAll(line, "{", "")
		line = strings.ReplaceAll(line, "},", "")
		numStrs := strings.Split(line, ",")
		if len(numStrs) <= 1 {
			continue
		}
		biomes = append(biomes, []uint8{})
		var topRow uint8 = math.MaxUint8
		for _, numStr := range numStrs {
			numStr = strings.TrimSpace(numStr)
			if len(numStr) == 0 {
				continue
			}
			num, err := strconv.ParseUint(numStr, 10, 8)
			if err != nil {
				fmt.Printf("Failed to convert string to integer: %v\n", err)
				return
			}
			if topRow == math.MaxUint8 {
				topRow = uint8(num)
				continue
			}
			var botRow uint8 = uint8(num)
			// topRow must fit in a 4-bit unsigned integer.
			if topRow >= 16 {
				fmt.Printf("Invalid column data! (topRow, bottomRow) = (%d, %d)\n", topRow, botRow)
				return
			}
			var width uint8 = botRow - topRow + 1
			if width < minCaveWidth {
				fmt.Printf("Cave width (%d) too small! (topRow, bottomRow) = (%d, %d)\n", width, topRow, botRow)
				return
			}
			width -= minCaveWidth
			// width must fit in a 4-bit unsigned integer.
			if width >= 16 {
				fmt.Printf("Cave width (%d) too large! (topRow, bottomRow) = (%d, %d)\n", width, topRow, botRow)
				return
			}
			var combinedCol uint8 = topRow << 4
			combinedCol |= width
			biomes[len(biomes)-1] = append(biomes[len(biomes)-1], combinedCol)
			topRow = math.MaxUint8
		}
	}

	fmt.Printf("Num biomes: %d\n", len(biomes))
	for _, biome := range biomes {
		fmt.Printf("  { ")
		first := true
		for _, col := range biome {
			if first {
				fmt.Printf("0x%02X", col)
				first = false
				continue
			}
			fmt.Printf(", 0x%02X", col)
		}
		fmt.Printf(" },\n")
	}
}
