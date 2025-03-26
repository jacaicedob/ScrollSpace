#pragma bank 1

#include "mapgen_data.h"

#include <stdint.h>

// The below data is generated with a specific format and thus shouldn't be auto-formatted.
// clang-format off

const uint8_t biome_columns[BIOME_COUNT][COLUMNS_PER_BIOME] = {
  /* 00 MSSV */ { 0x54, 0x62, 0x84, 0x73, 0x71, 0x60, 0x50, 0x60, 0x70, 0x70, 0x60, 0x50, 0x42, 0x54, 0x45, 0x33, 0x45, 0x33, 0x25, 0x33 },
  /* 01 MSSV */ { 0x55, 0x43, 0x45, 0x37, 0x35, 0x25, 0x37, 0x49, 0x47, 0x67, 0x75, 0x85, 0x76, 0x85, 0x74, 0x94, 0x82, 0xA3, 0x81, 0x90 },
  /* 02 MSSV */ { 0x83, 0x74, 0x56, 0x48, 0x58, 0x76, 0x64, 0x72, 0x80, 0x72, 0x84, 0x85, 0x93, 0x81, 0x63, 0x51, 0x50, 0x52, 0x50, 0x40 },
  /* 03 MSSV */ { 0x73, 0x81, 0x93, 0x85, 0x74, 0x85, 0x84, 0x92, 0xA2, 0x90, 0x80, 0x92, 0x84, 0x94, 0x85, 0x94, 0x82, 0x70, 0x82, 0x74 },
  /* 04 MSSV */ { 0x83, 0x74, 0x76, 0x67, 0x76, 0x64, 0x53, 0x44, 0x52, 0x41, 0x50, 0x60, 0x62, 0x44, 0x32, 0x24, 0x32, 0x24, 0x32, 0x20 },
  /* 05 MSSV */ { 0x93, 0x85, 0x83, 0x91, 0x83, 0x94, 0xA2, 0xB0, 0x92, 0x91, 0xB0, 0xC1, 0xB2, 0xC1, 0xC0, 0xC0, 0xB0, 0xA2, 0x93, 0xA1 },
  /* 06 MSSV */ { 0x63, 0x64, 0x56, 0x48, 0x56, 0x74, 0x63, 0x55, 0x47, 0x38, 0x26, 0x24, 0x36, 0x28, 0x18, 0x26, 0x48, 0x58, 0x36, 0x34 },
  /* 07 MSSV */ { 0x54, 0x55, 0x57, 0x67, 0x58, 0x46, 0x38, 0x26, 0x14, 0x16, 0x04, 0x14, 0x34, 0x24, 0x14, 0x26, 0x38, 0x17, 0x09, 0x07 },
  /* 08 MSSV */ { 0x94, 0xA3, 0xB1, 0xA3, 0x94, 0x82, 0x70, 0x60, 0x50, 0x60, 0x70, 0x92, 0x94, 0x85, 0x94, 0x94, 0x92, 0x83, 0x75, 0x76 },
  /* 09 MSSV */ { 0x94, 0xA3, 0xB1, 0xB0, 0xA0, 0xB0, 0xA2, 0x90, 0xA0, 0xA2, 0xB0, 0xC1, 0xD0, 0xC0, 0xD0, 0xD0, 0xD0, 0xD0, 0xC0, 0xC0 },
  /* 10 MSSV */ { 0x94, 0x85, 0xA3, 0xB2, 0xA2, 0xB2, 0xB2, 0xC0, 0xB2, 0xA2, 0xB0, 0xA2, 0x94, 0xA3, 0xA3, 0xB2, 0xB0, 0xA0, 0xC0, 0xD0 },
  /* 11 MSSV */ { 0x94, 0x83, 0x94, 0x82, 0x94, 0x82, 0x94, 0xA3, 0x94, 0x84, 0x75, 0x85, 0x67, 0x58, 0x76, 0x94, 0xA3, 0xA1, 0x93, 0x85 },
  /* 12 MSSV */ { 0x92, 0x93, 0x81, 0x93, 0xA3, 0x91, 0x91, 0x90, 0x80, 0x90, 0xA0, 0xB2, 0xB2, 0xB2, 0xA0, 0xA2, 0xA2, 0x90, 0xB0, 0xC1 },
  /* 13 MSSV */ { 0x64, 0x52, 0x54, 0x45, 0x37, 0x25, 0x13, 0x13, 0x11, 0x03, 0x13, 0x21, 0x10, 0x00, 0x02, 0x14, 0x06, 0x04, 0x06, 0x08 },
  /* 14 MSSV */ { 0x94, 0x92, 0x84, 0x94, 0x94, 0xA3, 0x91, 0xA0, 0x91, 0xA0, 0x92, 0x94, 0xB2, 0xA0, 0xB0, 0xA2, 0xA3, 0x94, 0x83, 0x85 },
  /* 15 LSSS */ { 0xA3, 0x93, 0x83, 0x94, 0xA3, 0xA2, 0x83, 0x94, 0xA3, 0xB2, 0xC1, 0xB0, 0xA1, 0x80, 0x90, 0x80, 0x90, 0xA1, 0xB2, 0xA3 },
  /* 16 LSSS */ { 0x94, 0xB2, 0xA3, 0x94, 0x85, 0x94, 0x85, 0x94, 0x85, 0x74, 0x84, 0x94, 0xA3, 0xA3, 0xB2, 0xC1, 0xB2, 0xB1, 0xC0, 0xD0 },
  /* 17 LSSS */ { 0xA3, 0xA3, 0x93, 0xA3, 0x93, 0x83, 0x72, 0x81, 0x72, 0x82, 0x93, 0x72, 0x81, 0x92, 0xA2, 0xB2, 0xB1, 0xB1, 0xA0, 0xB0 },
  /* 18 LSSS */ { 0xD0, 0xC0, 0xC0, 0xB1, 0xC0, 0xC1, 0xD0, 0xD0, 0xC1, 0xC0, 0xB1, 0xC1, 0xB2, 0x94, 0xA2, 0x93, 0x84, 0x75, 0x84, 0x93 },
  /* 19 LSSS */ { 0xB2, 0xA2, 0xA3, 0xB2, 0xA3, 0x93, 0x92, 0x83, 0x72, 0x61, 0x70, 0x80, 0x90, 0x91, 0x80, 0xA2, 0xC1, 0xB2, 0xA3, 0xB2 },
  /* 20 HSSS */ { 0x03, 0x04, 0x03, 0x04, 0x14, 0x26, 0x27, 0x17, 0x08, 0x19, 0x08, 0x29, 0x2A, 0x29, 0x19, 0x1A, 0x1B, 0x09, 0x2A, 0x39 },
  /* 21 HSSS */ { 0x42, 0x53, 0x42, 0x23, 0x34, 0x53, 0x64, 0x65, 0x46, 0x38, 0x49, 0x48, 0x48, 0x37, 0x38, 0x49, 0x48, 0x49, 0x48, 0x38 },
  /* 22 HSSS */ { 0x13, 0x02, 0x02, 0x01, 0x03, 0x03, 0x04, 0x15, 0x24, 0x15, 0x24, 0x35, 0x44, 0x34, 0x23, 0x34, 0x25, 0x34, 0x45, 0x56 },
  /* 23 HSSS */ { 0x44, 0x34, 0x54, 0x45, 0x33, 0x22, 0x11, 0x10, 0x01, 0x02, 0x01, 0x00, 0x01, 0x11, 0x00, 0x10, 0x10, 0x01, 0x01, 0x01 },
  /* 24 HSSS */ { 0x32, 0x43, 0x54, 0x45, 0x36, 0x45, 0x55, 0x55, 0x45, 0x36, 0x25, 0x37, 0x47, 0x56, 0x67, 0x47, 0x48, 0x48, 0x37, 0x46 },
  /* 25 MSVV */ { 0x63, 0x85, 0x85, 0x67, 0x49, 0x67, 0x49, 0x3A, 0x1C, 0x0D, 0x0B, 0x2B, 0x09, 0x0B, 0x0D, 0x0D, 0x2B, 0x2B, 0x49, 0x49 },
  /* 26 MSVV */ { 0x72, 0x84, 0xA3, 0x84, 0x65, 0x43, 0x51, 0x73, 0x51, 0x30, 0x20, 0x02, 0x00, 0x12, 0x00, 0x02, 0x23, 0x01, 0x03, 0x25 },
  /* 27 MSVV */ { 0x62, 0x50, 0x32, 0x14, 0x33, 0x11, 0x00, 0x02, 0x00, 0x20, 0x02, 0x00, 0x00, 0x02, 0x01, 0x03, 0x05, 0x07, 0x05, 0x07 },
  /* 28 MSVV */ { 0x63, 0x82, 0xA3, 0x81, 0x60, 0x80, 0xA2, 0xC1, 0xD0, 0xB2, 0xB0, 0x90, 0x80, 0x80, 0x62, 0x60, 0x80, 0x62, 0x64, 0x85 },
  /* 29 MSVV */ { 0x54, 0x76, 0x54, 0x74, 0x56, 0x54, 0x72, 0x54, 0x36, 0x14, 0x36, 0x58, 0x46, 0x66, 0x44, 0x22, 0x00, 0x20, 0x02, 0x24 },
  /* 30 HSFS */ { 0x23, 0x34, 0x24, 0x24, 0x33, 0x22, 0x33, 0x44, 0x35, 0x36, 0x47, 0x56, 0x45, 0x54, 0x54, 0x54, 0x63, 0x64, 0x74, 0x85 },
  /* 31 HSFS */ { 0x42, 0x51, 0x42, 0x51, 0x40, 0x30, 0x40, 0x40, 0x40, 0x50, 0x61, 0x63, 0x54, 0x55, 0x46, 0x57, 0x56, 0x56, 0x65, 0x75 },
  /* 32 HSFS */ { 0x34, 0x43, 0x62, 0x70, 0x80, 0x90, 0x70, 0x91, 0xB1, 0xB1, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xB0, 0xB0, 0xC0, 0xC0 },
  /* 33 LSRS */ { 0xC1, 0xC0, 0xD0, 0xC1, 0xB0, 0xA0, 0x90, 0xA0, 0xA0, 0xB1, 0xB0, 0xB0, 0xB0, 0xB1, 0xA2, 0x93, 0x83, 0x73, 0x72, 0x73 },
  /* 34 LSRS */ { 0xA3, 0x91, 0x72, 0x72, 0x60, 0x60, 0x51, 0x52, 0x51, 0x40, 0x31, 0x22, 0x11, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00 },
  /* 35 LSRS */ { 0xC1, 0xB2, 0x93, 0x83, 0x84, 0x83, 0x84, 0x83, 0x74, 0x63, 0x43, 0x42, 0x41, 0x30, 0x21, 0x20, 0x11, 0x03, 0x02, 0x02 },
  /* 36 MSRW */ { 0x74, 0x75, 0x66, 0x66, 0x66, 0x58, 0x76, 0x67, 0x49, 0x49, 0x49, 0x49, 0x58, 0x58, 0x49, 0x39, 0x2A, 0x49, 0x2B, 0x0C },
  /* 37 MSRW */ { 0x84, 0xA3, 0x92, 0x82, 0x93, 0x83, 0x64, 0x63, 0x64, 0x75, 0x66, 0x57, 0x38, 0x26, 0x27, 0x18, 0x08, 0x09, 0x0A, 0x09 },
  /* 38 MSRW */ { 0x53, 0x53, 0x44, 0x34, 0x34, 0x25, 0x16, 0x06, 0x06, 0x06, 0x08, 0x09, 0x0A, 0x2B, 0x1B, 0x0C, 0x0D, 0x0D, 0x1C, 0x0C },
  /* 39 LSRW */ { 0xA3, 0x93, 0x82, 0x82, 0x73, 0x74, 0x76, 0x66, 0x56, 0x47, 0x45, 0x25, 0x16, 0x14, 0x05, 0x16, 0x07, 0x07, 0x07, 0x08 },
  /* 40 LSRW */ { 0xD0, 0xD0, 0xD0, 0xC1, 0xD0, 0xC0, 0xB1, 0xA0, 0x92, 0x83, 0x85, 0x76, 0x85, 0x84, 0x74, 0x85, 0x85, 0x85, 0x94, 0x85 },
  /* 41 HSSW */ { 0x12, 0x02, 0x03, 0x14, 0x26, 0x27, 0x17, 0x05, 0x06, 0x08, 0x09, 0x0B, 0x0C, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x1C },
  /* 42 HSSW */ { 0x23, 0x32, 0x42, 0x32, 0x31, 0x23, 0x34, 0x44, 0x64, 0x54, 0x45, 0x46, 0x67, 0x57, 0x38, 0x49, 0x3A, 0x58, 0x47, 0x37 },
  /* 43 HWFN */ { 0x25, 0x45, 0x54, 0x45, 0x43, 0x54, 0x54, 0x63, 0x73, 0x52, 0x60, 0x60, 0x60, 0x60, 0x70, 0x70, 0x72, 0x84, 0x94, 0xA3 },
  /* 44 HWFN */ { 0x17, 0x36, 0x35, 0x34, 0x43, 0x53, 0x62, 0x74, 0x74, 0x93, 0xA2, 0xA2, 0x81, 0x92, 0xB1, 0xA0, 0xC0, 0xC0, 0xB0, 0xC0 },
  /* 45 HWFN */ { 0x26, 0x34, 0x43, 0x52, 0x61, 0x62, 0x61, 0x60, 0x60, 0x60, 0x70, 0x60, 0x70, 0x90, 0x80, 0x91, 0xA0, 0xB0, 0xC1, 0xC0 },
  /* 46 HWSN */ { 0x45, 0x47, 0x26, 0x15, 0x34, 0x43, 0x35, 0x34, 0x23, 0x11, 0x20, 0x40, 0x50, 0x61, 0x60, 0x70, 0x80, 0x70, 0x61, 0x53 },
  /* 47 HWSN */ { 0x36, 0x25, 0x24, 0x23, 0x32, 0x40, 0x30, 0x40, 0x31, 0x23, 0x13, 0x05, 0x13, 0x13, 0x22, 0x21, 0x01, 0x20, 0x10, 0x10 },
  /* 48 HWFS */ { 0x26, 0x26, 0x25, 0x34, 0x45, 0x54, 0x76, 0x67, 0x76, 0x85, 0x93, 0xA2, 0xB1, 0xC0, 0xD0, 0xD0, 0xD0, 0xC0, 0xD0, 0xD0 },
  /* 49 HWFS */ { 0x45, 0x24, 0x14, 0x23, 0x31, 0x41, 0x50, 0x60, 0x70, 0x50, 0x41, 0x50, 0x60, 0x51, 0x52, 0x50, 0x60, 0x70, 0x80, 0x90 },
  /* 50 HWSS */ { 0x36, 0x37, 0x47, 0x38, 0x37, 0x27, 0x37, 0x46, 0x55, 0x67, 0x57, 0x58, 0x58, 0x57, 0x66, 0x54, 0x43, 0x63, 0x52, 0x43 },
  /* 51 HWSS */ { 0x36, 0x35, 0x26, 0x25, 0x24, 0x23, 0x22, 0x33, 0x12, 0x23, 0x12, 0x20, 0x10, 0x10, 0x20, 0x11, 0x20, 0x12, 0x01, 0x10 },
  /* 52 HWSS */ { 0x16, 0x16, 0x06, 0x15, 0x24, 0x32, 0x22, 0x13, 0x22, 0x23, 0x34, 0x24, 0x35, 0x27, 0x15, 0x26, 0x15, 0x16, 0x26, 0x17 },
  /* 53 HWSS */ { 0x15, 0x14, 0x02, 0x01, 0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x21, 0x20, 0x10, 0x10, 0x21, 0x13, 0x02, 0x11, 0x22 },
  /* 54 HWSS */ { 0x16, 0x07, 0x06, 0x05, 0x04, 0x14, 0x15, 0x03, 0x02, 0x21, 0x21, 0x10, 0x10, 0x10, 0x01, 0x02, 0x02, 0x13, 0x24, 0x32 },
  /* 55 HWSV */ { 0x15, 0x27, 0x17, 0x09, 0x07, 0x15, 0x05, 0x07, 0x18, 0x29, 0x49, 0x2B, 0x3A, 0x48, 0x36, 0x28, 0x1A, 0x0C, 0x1B, 0x29 },
  /* 56 HWSV */ { 0x06, 0x06, 0x14, 0x22, 0x34, 0x25, 0x23, 0x31, 0x23, 0x03, 0x05, 0x17, 0x07, 0x09, 0x1B, 0x0D, 0x0D, 0x0B, 0x0C, 0x1C },
  /* 57 HWSV */ { 0x07, 0x07, 0x09, 0x0B, 0x0D, 0x1B, 0x1C, 0x2A, 0x2B, 0x19, 0x07, 0x09, 0x07, 0x09, 0x18, 0x37, 0x27, 0x35, 0x47, 0x35 },
  /* 58 HWSV */ { 0x46, 0x36, 0x24, 0x32, 0x40, 0x50, 0x40, 0x32, 0x24, 0x16, 0x34, 0x23, 0x35, 0x44, 0x52, 0x60, 0x50, 0x70, 0x72, 0x61 },
  /* 59 HWSV */ { 0x26, 0x44, 0x56, 0x54, 0x62, 0x52, 0x64, 0x62, 0x82, 0x90, 0xA0, 0x90, 0xB0, 0xB2, 0xC0, 0xB2, 0xB0, 0x92, 0xA2, 0x92 },
  /* 60 HWRW */ { 0x27, 0x48, 0x38, 0x29, 0x2B, 0x3A, 0x2B, 0x49, 0x48, 0x38, 0x38, 0x28, 0x19, 0x1A, 0x0B, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D },
  /* 61 HWRW */ { 0x37, 0x18, 0x08, 0x27, 0x28, 0x48, 0x49, 0x39, 0x39, 0x1A, 0x1B, 0x1B, 0x1C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D },
  /* 62 HWRW */ { 0x45, 0x46, 0x57, 0x48, 0x29, 0x28, 0x29, 0x1A, 0x0A, 0x0B, 0x0C, 0x0C, 0x0D, 0x1C, 0x1C, 0x0D, 0x0D, 0x1C, 0x1C, 0x1C },
  /* 63 HWRW */ { 0x16, 0x07, 0x08, 0x09, 0x29, 0x17, 0x37, 0x27, 0x28, 0x19, 0x1B, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D, 0x0D, 0x0D },
};

const uint8_t next_possible_biomes[BIOME_COUNT][BIOME_CONNECTION_COUNT] = {
  /* 00 */ {  1,  6,  7, 13, 20, 21, 22, 24, 25, 27, 29, 32, 38, 41, 42, 43, 45, 46, 47, 48, 50, 51, 53, 54, 55, 56, 57, 58, 59, 60, 61, 63 },
  /* 01 */ {  0,  0,  2,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 16, 25, 26, 28, 29, 36, 37, 46, 47, 49, 50, 51, 58, 60, 61, 62 },
  /* 02 */ { 21, 21, 22, 22, 23, 23, 24, 30, 31, 32, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63 },
  /* 03 */ {  1,  2,  4,  6,  7,  8,  9, 12, 13, 19, 23, 25, 26, 27, 28, 34, 36, 37, 38, 39, 44, 45, 47, 48, 49, 50, 51, 57, 58, 59, 60, 61 },
  /* 04 */ { 20, 20, 22, 22, 30, 30, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 48, 48, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 59, 60, 63 },
  /* 05 */ {  1,  1,  2,  2,  3,  3,  4,  4,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 16, 17, 19, 34, 36, 37, 39, 58, 61 },
  /* 06 */ {  0,  1,  3,  7, 13, 20, 21, 22, 23, 24, 26, 29, 31, 32, 38, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 55, 58, 60, 61, 62, 63 },
  /* 07 */ {  0,  3,  6, 13, 20, 21, 22, 23, 25, 26, 27, 28, 29, 30, 31, 38, 42, 43, 45, 46, 47, 48, 49, 50, 51, 54, 55, 58, 59, 60, 61, 62 },
  /* 08 */ {  0,  1,  2,  3,  4,  6,  7,  9, 11, 14, 15, 18, 19, 25, 27, 28, 29, 32, 33, 34, 36, 37, 39, 43, 45, 50, 52, 57, 58, 59, 61, 62 },
  /* 09 */ {  5,  5,  5,  8,  8,  8, 10, 10, 10, 11, 11, 11, 14, 14, 15, 15, 16, 16, 17, 17, 19, 19, 33, 33, 34, 34, 35, 35, 37, 37, 39, 39 },
  /* 10 */ {  8,  8,  8,  9,  9,  9, 11, 11, 11, 14, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 33, 33, 34, 34, 35, 35, 39, 39, 40, 40 },
  /* 11 */ {  1,  2,  4,  5,  7,  8, 14, 15, 16, 17, 18, 19, 23, 25, 26, 27, 28, 29, 33, 35, 36, 37, 39, 40, 44, 47, 49, 50, 51, 58, 60, 62 },
  /* 12 */ {  5,  5,  8,  8,  9,  9, 10, 10, 11, 11, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 33, 33, 34, 34, 35, 35, 37, 37, 39, 40 },
  /* 13 */ {  1,  2,  4, 20, 21, 23, 24, 25, 26, 27, 28, 30, 32, 36, 37, 38, 42, 43, 46, 47, 48, 49, 50, 52, 54, 55, 56, 57, 58, 59, 61, 63 },
  /* 14 */ {  0,  1,  3,  4,  5,  6,  8,  9, 12, 15, 16, 17, 18, 23, 26, 28, 33, 35, 36, 38, 39, 40, 46, 47, 48, 49, 50, 51, 58, 59, 60, 61 },
  /* 15 */ {  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  8,  8,  9,  9, 10, 11, 12, 13, 14, 16, 17, 18, 19, 33, 34, 35, 36, 37, 39, 40, 58, 61 },
  /* 16 */ {  8,  8,  8,  9,  9,  9, 10, 10, 10, 11, 11, 11, 14, 14, 15, 15, 17, 17, 18, 18, 19, 19, 33, 33, 34, 34, 35, 35, 39, 39, 40, 40 },
  /* 17 */ {  2,  2,  4,  4,  5,  5,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 14, 14, 15, 15, 16, 16, 19, 19, 34, 34, 36, 36, 37, 37, 39, 39 },
  /* 18 */ {  0,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 19, 26, 28, 29, 34, 36, 37, 39, 46, 47, 49, 50, 58, 60, 61, 62 },
  /* 19 */ {  2,  2,  4,  4,  5,  5,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 14, 14, 15, 15, 16, 16, 17, 17, 18, 33, 34, 35, 36, 37, 39, 40 },
  /* 20 */ {  1,  4,  7,  8,  9, 11, 15, 16, 19, 22, 23, 24, 26, 27, 28, 29, 30, 32, 34, 36, 37, 39, 44, 45, 46, 50, 51, 53, 55, 56, 59, 63 },
  /* 21 */ {  1,  2,  5,  6,  7, 10, 11, 13, 14, 15, 19, 20, 22, 23, 27, 28, 29, 30, 32, 38, 39, 41, 42, 46, 47, 49, 52, 57, 58, 59, 60, 62 },
  /* 22 */ {  1,  3,  4,  8,  9, 12, 16, 17, 24, 26, 30, 31, 32, 34, 38, 39, 42, 43, 47, 48, 49, 51, 52, 53, 54, 57, 58, 59, 60, 61, 62, 63 },
  /* 23 */ { 20, 20, 20, 22, 22, 22, 41, 41, 41, 44, 44, 44, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 63, 63 },
  /* 24 */ {  0,  1,  2,  3,  5,  6,  7,  8, 10, 11, 12, 14, 15, 17, 25, 26, 27, 29, 31, 32, 36, 39, 45, 47, 50, 51, 56, 58, 59, 60, 62, 63 },
  /* 25 */ {  0,  2,  3,  4,  5,  6,  9, 10, 11, 18, 19, 21, 22, 24, 26, 31, 32, 33, 36, 38, 39, 44, 45, 48, 52, 53, 54, 55, 56, 59, 60, 63 },
  /* 26 */ {  0,  3,  6,  7, 13, 20, 21, 22, 23, 24, 25, 27, 28, 30, 31, 32, 41, 42, 46, 47, 48, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 63 },
  /* 27 */ {  0,  1,  6,  7, 13, 20, 21, 23, 24, 25, 26, 29, 30, 32, 36, 38, 41, 42, 45, 46, 47, 48, 50, 52, 53, 55, 56, 58, 59, 60, 61, 63 },
  /* 28 */ {  0,  1,  3,  4,  7,  8,  9, 10, 11, 12, 14, 15, 16, 17, 19, 23, 25, 27, 29, 33, 34, 38, 40, 44, 45, 47, 48, 49, 50, 51, 60, 62 },
  /* 29 */ {  1,  7, 13, 21, 22, 23, 24, 25, 27, 28, 30, 31, 32, 38, 41, 42, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 58, 60, 61 },
  /* 30 */ {  2,  3,  4,  5,  7,  8,  9, 10, 11, 12, 13, 14, 15, 19, 23, 25, 26, 28, 29, 33, 34, 35, 38, 39, 40, 45, 47, 48, 49, 50, 59, 60 },
  /* 31 */ {  0,  1,  2,  3,  4,  5,  6,  9, 10, 15, 16, 17, 19, 25, 26, 27, 28, 29, 34, 35, 37, 44, 45, 46, 47, 54, 57, 58, 59, 60, 61, 62 },
  /* 32 */ {  5,  5,  5,  8,  8,  8,  9,  9, 10, 10, 11, 11, 14, 14, 15, 15, 16, 16, 17, 17, 19, 19, 33, 33, 34, 34, 35, 35, 37, 37, 39, 39 },
  /* 33 */ {  1,  2,  3,  4,  6,  9, 10, 11, 13, 14, 15, 16, 23, 26, 27, 28, 32, 34, 36, 39, 45, 46, 47, 48, 49, 50, 51, 54, 57, 58, 59, 61 },
  /* 34 */ { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57 },
  /* 35 */ { 20, 20, 22, 22, 30, 30, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 48, 48, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 59, 60, 63 },
  /* 36 */ {  0,  1,  2,  3,  5,  9, 10, 13, 16, 21, 22, 24, 25, 28, 29, 30, 31, 34, 39, 42, 44, 45, 46, 50, 51, 53, 54, 55, 57, 60, 61, 63 },
  /* 37 */ {  5,  6,  8,  9, 10, 11, 14, 21, 22, 23, 25, 26, 30, 31, 32, 38, 42, 43, 44, 45, 46, 47, 50, 52, 53, 54, 56, 57, 59, 60, 61, 62 },
  /* 38 */ {  1,  4,  5,  6,  8, 12, 13, 14, 17, 19, 20, 22, 23, 27, 28, 30, 31, 32, 33, 35, 37, 39, 42, 46, 52, 55, 56, 57, 58, 59, 60, 63 },
  /* 39 */ {  0,  1,  2,  3,  4,  7, 20, 22, 23, 25, 27, 28, 30, 32, 37, 42, 45, 46, 47, 48, 49, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 62 },
  /* 40 */ {  0,  2,  4,  5,  6,  7,  9, 10, 11, 12, 13, 14, 15, 18, 19, 25, 26, 28, 29, 33, 35, 37, 38, 39, 46, 47, 48, 49, 50, 51, 58, 62 },
  /* 41 */ {  0,  2,  3,  4,  6,  7,  8,  9, 11, 12, 13, 15, 17, 20, 22, 23, 25, 26, 28, 29, 32, 34, 35, 37, 43, 44, 46, 47, 53, 54, 57, 60 },
  /* 42 */ {  0,  1,  4,  7,  9, 14, 16, 17, 23, 26, 27, 28, 34, 36, 37, 39, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53, 57, 58, 60, 61, 62, 63 },
  /* 43 */ {  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  8,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 33, 34, 35, 36, 37, 39, 40, 58, 61 },
  /* 44 */ {  5,  5,  5,  8,  8,  8,  9,  9, 10, 10, 11, 11, 14, 14, 15, 15, 16, 16, 17, 17, 19, 19, 33, 33, 34, 34, 35, 35, 37, 37, 39, 39 },
  /* 45 */ {  5,  5,  5,  8,  8,  8,  9,  9, 10, 10, 11, 11, 14, 14, 15, 15, 16, 16, 17, 17, 19, 19, 33, 33, 34, 34, 35, 35, 37, 37, 39, 39 },
  /* 46 */ {  0,  1,  2,  3,  4,  6,  7, 13, 21, 23, 24, 25, 26, 27, 28, 29, 30, 32, 37, 38, 42, 43, 44, 47, 50, 51, 52, 55, 56, 57, 59, 62 },
  /* 47 */ { 20, 20, 20, 22, 22, 22, 41, 41, 41, 44, 44, 44, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 63, 63 },
  /* 48 */ {  8,  8,  8,  9,  9,  9, 10, 10, 11, 11, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 33, 33, 34, 34, 35, 35, 39, 39, 40, 40 },
  /* 49 */ {  0,  0,  1,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 16, 25, 26, 28, 29, 36, 37, 46, 47, 50, 51, 58, 60, 61, 62 },
  /* 50 */ {  0,  3,  6,  7, 13, 21, 22, 23, 24, 25, 26, 28, 29, 30, 31, 32, 36, 38, 42, 43, 44, 45, 46, 47, 49, 51, 52, 53, 55, 57, 58, 61 },
  /* 51 */ { 20, 20, 20, 22, 22, 22, 41, 41, 41, 44, 44, 44, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 63, 63 },
  /* 52 */ {  0,  4,  6,  7, 20, 21, 22, 23, 24, 25, 26, 28, 29, 30, 31, 36, 37, 38, 41, 43, 44, 46, 48, 49, 50, 51, 54, 56, 58, 60, 62, 63 },
  /* 53 */ { 20, 20, 21, 21, 22, 23, 24, 30, 31, 32, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63 },
  /* 54 */ {  1,  7, 20, 21, 22, 23, 29, 30, 31, 32, 38, 41, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 55, 56, 57, 58, 59, 60, 61, 62, 63 },
  /* 55 */ {  1,  3,  7,  8,  9, 11, 15, 19, 20, 21, 22, 23, 25, 26, 27, 28, 29, 31, 32, 36, 37, 42, 44, 47, 49, 50, 51, 52, 54, 60, 62, 63 },
  /* 56 */ {  1,  2,  3,  5,  6,  7,  9, 11, 13, 14, 15, 19, 21, 22, 24, 26, 27, 29, 30, 33, 34, 38, 42, 45, 47, 50, 52, 54, 57, 58, 59, 60 },
  /* 57 */ {  0,  1,  3,  4,  6,  7, 13, 21, 22, 23, 24, 27, 30, 31, 32, 36, 41, 42, 44, 45, 46, 47, 49, 50, 51, 52, 53, 54, 55, 58, 59, 62 },
  /* 58 */ {  1,  3,  6,  7, 21, 23, 25, 26, 27, 28, 29, 31, 32, 36, 38, 43, 45, 46, 47, 49, 50, 51, 52, 53, 54, 55, 57, 59, 60, 61, 62, 63 },
  /* 59 */ {  0,  3,  4,  5,  6,  7,  8, 10, 11, 12, 13, 14, 15, 16, 17, 19, 25, 26, 28, 29, 34, 36, 39, 46, 47, 49, 50, 51, 58, 60, 61, 62 },
  /* 60 */ {  9, 10, 11, 12, 13, 14, 16, 17, 18, 20, 22, 23, 24, 25, 27, 29, 30, 35, 39, 40, 42, 44, 47, 49, 51, 52, 53, 54, 56, 57, 58, 63 },
  /* 61 */ {  1,  3,  4,  8,  9, 10, 11, 13, 14, 15, 18, 19, 20, 21, 22, 23, 26, 27, 28, 35, 38, 43, 44, 47, 48, 51, 52, 54, 57, 58, 59, 60 },
  /* 62 */ {  1,  3,  4,  5,  7, 13, 15, 16, 17, 19, 20, 23, 25, 27, 28, 29, 30, 38, 39, 40, 41, 42, 44, 47, 48, 51, 53, 54, 55, 56, 58, 60 },
  /* 63 */ {  0,  1,  3,  4,  6,  9, 10, 11, 12, 13, 15, 16, 17, 18, 20, 21, 27, 28, 29, 31, 33, 36, 39, 40, 48, 49, 52, 57, 58, 59, 60, 62 },
};
