// Retro8x16.c
// Font type    : Full (95 characters)
// Font size    : 8x16 pixels
// Memory usage : 1524 bytes

#include <stdint.h>

uint8_t Retro8x16[] = {
// 0x08,0x10,0x20,0x5F,
// 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // <space>
//0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x10,0x10,0x00,0x00,  // !
//0x24,0x24,0x24,0x24,0x24,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // "
//0x24,0x24,0x24,0x24,0x7E,0x7E,0x24,0x24,0x7E,0x7E,0x24,0x24,0x24,0x24,0x00,0x00,  // #
//0x10,0x10,0x3C,0x3C,0x50,0x50,0x38,0x38,0x14,0x14,0x78,0x78,0x10,0x10,0x00,0x00,  // $
//0x00,0x00,0x62,0x62,0x64,0x64,0x08,0x08,0x10,0x10,0x26,0x26,0x46,0x46,0x00,0x00,  // %
//0x30,0x30,0x48,0x48,0x48,0x48,0x30,0x30,0x4A,0x4A,0x44,0x44,0x3A,0x3A,0x00,0x00,  // &
//0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // '
//0x10,0x10,0x20,0x20,0x40,0x40,0x40,0x40,0x40,0x40,0x20,0x20,0x10,0x10,0x00,0x00,  // (
//0x10,0x10,0x08,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x08,0x08,0x10,0x10,0x00,0x00,  // )
//0x10,0x10,0x54,0x54,0x38,0x38,0x10,0x10,0x38,0x38,0x54,0x54,0x10,0x10,0x00,0x00,  // *
//0x00,0x00,0x10,0x10,0x10,0x10,0x7C,0x7C,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00,  // +
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x10,0x10,0x00,0x00,  // ,
//0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // -
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x00,  // .
//0x00,0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,0x00,  // /

//0x3C,0x3C,0x42,0x42,0x46,0x46,0x5A,0x5A,0x62,0x62,0x42,0x42,0x3C,0x3C,0x00,0x00,  // 0
//0x08,0x08,0x18,0x18,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x1C,0x00,0x00,  // 1
//0x3C,0x3C,0x42,0x42,0x02,0x02,0x1C,0x1C,0x20,0x20,0x40,0x40,0x7E,0x7E,0x00,0x00,  // 2
//0x7E,0x7E,0x02,0x02,0x04,0x04,0x1C,0x1C,0x02,0x02,0x42,0x42,0x3C,0x3C,0x00,0x00,  // 3
//0x04,0x04,0x0C,0x0C,0x14,0x14,0x24,0x24,0x7E,0x7E,0x04,0x04,0x04,0x04,0x00,0x00,  // 4
//0x7E,0x7E,0x40,0x40,0x7C,0x7C,0x02,0x02,0x02,0x02,0x42,0x42,0x3C,0x3C,0x00,0x00,  // 5
//0x1E,0x1E,0x20,0x20,0x40,0x40,0x7C,0x7C,0x42,0x42,0x42,0x42,0x3C,0x3C,0x00,0x00,  // 6
//0x7E,0x7E,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,  // 7
//0x3C,0x3C,0x42,0x42,0x42,0x42,0x3C,0x3C,0x42,0x42,0x42,0x42,0x3C,0x3C,0x00,0x00,  // 8
//0x3C,0x3C,0x42,0x42,0x42,0x42,0x3E,0x3E,0x02,0x02,0x04,0x04,0x78,0x78,0x00,0x00,  // 9
//0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,  // :
//0x00,0x00,0x00,0x00,0x08,0x08,0x00,0x00,0x08,0x08,0x08,0x08,0x10,0x00,0x00,0x00,  // ;
//0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x00,0x00,  // <
//0x00,0x00,0x00,0x00,0x7E,0x7E,0x00,0x00,0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,  // =
//0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x00,0x00,  // >
//0x20,0x20,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ?

//0x3C,0x3C,0x42,0x42,0x4A,0x4A,0x56,0x56,0x4C,0x4C,0x40,0x40,0x3E,0x3E,0x00,0x00,  // @
0x18,0x18,0x24,0x24,0x42,0x42,0x42,0x42,0x7E,0x7E,0x42,0x42,0x42,0x42,0x00,0x00,  // A
0x7C,0x7C,0x42,0x42,0x42,0x42,0x7C,0x7C,0x42,0x42,0x42,0x42,0x7C,0x7C,0x00,0x00,  // B
0x3C,0x3C,0x42,0x42,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0x42,0x3C,0x3C,0x00,0x00,  // C
0x7C,0x7C,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x7C,0x7C,0x00,0x00,  // D
0x7E,0x7E,0x40,0x40,0x40,0x40,0x7C,0x7C,0x40,0x40,0x40,0x40,0x7E,0x7E,0x00,0x00,  // E
0x7E,0x7E,0x40,0x40,0x40,0x40,0x7C,0x7C,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,  // F
0x3E,0x3E,0x40,0x40,0x40,0x40,0x40,0x4E,0x4E,0x42,0x42,0x42,0x3E,0x3E,0x00,0x00,  // G
0x42,0x42,0x42,0x42,0x42,0x42,0x7E,0x7E,0x42,0x42,0x42,0x42,0x42,0x42,0x00,0x00,  // H
0x38,0x38,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x38,0x00,0x00,  // I
0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x42,0x3C,0x3C,0x00,0x00,  // J
0x42,0x42,0x44,0x44,0x48,0x48,0x70,0x70,0x48,0x48,0x44,0x44,0x42,0x42,0x00,0x00,  // K
0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7E,0x7E,0x00,0x00,  // L
0x42,0x42,0x66,0x66,0x5A,0x5A,0x5A,0x5A,0x42,0x42,0x42,0x42,0x42,0x42,0x00,0x00,  // M
0x42,0x42,0x62,0x62,0x52,0x52,0x5A,0x5A,0x4A,0x4A,0x46,0x46,0x42,0x42,0x00,0x00,  // N
0x3C,0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x3C,0x00,0x00,  // O

0x7C,0x7C,0x42,0x42,0x42,0x42,0x7C,0x7C,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,  // P
0x3C,0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x4A,0x4A,0x44,0x44,0x3A,0x3A,0x00,0x00,  // Q
0x7C,0x7C,0x42,0x42,0x42,0x42,0x7C,0x7C,0x48,0x48,0x44,0x44,0x42,0x42,0x00,0x00,  // R
0x3C,0x3C,0x42,0x42,0x40,0x40,0x3C,0x3C,0x02,0x02,0x42,0x42,0x3C,0x3C,0x00,0x00,  // S
0x7C,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,  // T
0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x3C,0x00,0x00,  // U
0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x24,0x18,0x18,0x00,0x00,  // V
0x42,0x42,0x42,0x42,0x42,0x42,0x5A,0x5A,0x5A,0x5A,0x66,0x66,0x42,0x42,0x00,0x00,  // W
0x42,0x42,0x42,0x42,0x24,0x24,0x18,0x18,0x24,0x24,0x42,0x42,0x42,0x42,0x00,0x00,  // X
0x44,0x44,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,  // Y
0x7E,0x7E,0x02,0x02,0x04,0x04,0x18,0x18,0x20,0x20,0x40,0x40,0x7E,0x7E,0x00,0x00,  // Z
//0x7E,0x7E,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x7E,0x00,0x00,  // [
//0x00,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00,0x00,  // <backslash>
//0x7E,0x7E,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x7E,0x7E,0x00,0x00,  // ]
//0x00,0x00,0x00,0x00,0x10,0x10,0x28,0x28,0x44,0x44,0x00,0x00,0x00,0x00,0x00,0x00,  // ^
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7E,0x00,0x00,  // _
//0x20,0x20,0x10,0x10,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // `
//0x0E,0x0E,0x18,0x18,0x18,0x18,0x70,0x70,0x18,0x18,0x18,0x18,0x0E,0x0E,0x00,0x00,  // {
//0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,  // |
//0x70,0x70,0x18,0x18,0x18,0x18,0x0E,0x0E,0x18,0x18,0x18,0x18,0x70,0x70,0x00,0x00,  // }
//0x00,0x00,0x00,0x00,0x24,0x24,0x54,0x54,0x48,0x48,0x00,0x00,0x00,0x00,0x00,0x00,  // ~
};
