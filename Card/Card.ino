
#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>

#define DEG "\xa7" "C"

SSD1306_Mini oled;

//byte array of bitmap 5x24px
const unsigned char  img_thermometer[] PROGMEM = {
/*--  调入了一幅图像：C:\Users\luooove\Desktop\空间\中美胸牌\Untitled.bmp  --*/
/*--  宽度x高度=128x64  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xC0,0x80,0x00,0x00,
0xC0,0x20,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,
0x00,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,
0x00,0x00,0xE0,0x60,0xC0,0x00,0x00,0x00,0x80,0x40,0xE0,0x00,0x00,0x00,0x80,0x80,
0x80,0x00,0x00,0xF0,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x80,
0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x1E,0x01,
0x00,0x00,0x80,0x0F,0x19,0x10,0x10,0x99,0x0F,0x00,0x0F,0x10,0x10,0x10,0x1F,0x80,
0x00,0x1F,0x01,0x00,0x00,0x1F,0x00,0x00,0x4F,0x50,0x50,0x50,0x3F,0x00,0x00,0x00,
0x00,0x00,0x1F,0x00,0x03,0x0F,0x18,0x0E,0x03,0x00,0x1F,0x00,0x00,0x1C,0x12,0x12,
0x1F,0x00,0x00,0x1F,0x06,0x0D,0x18,0x10,0x00,0x0F,0x1A,0x12,0x12,0x0B,0x00,0x1F,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x7C,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0x7C,0x00,0x00,
0xA2,0xAA,0xAA,0xAB,0xFE,0xAB,0xAB,0xAA,0xAA,0xA2,0x00,0x11,0xF5,0x55,0x55,0x5F,
0x55,0x55,0x55,0xF5,0x11,0x90,0x88,0xF6,0x93,0x92,0x92,0xFE,0x92,0x92,0x92,0x82,
0x10,0xFC,0x92,0x91,0xF2,0x04,0x08,0xFE,0x00,0xFF,0x00,0x40,0x56,0xD2,0xCE,0xDA,
0xAB,0xAB,0xAA,0xDA,0xCA,0x46,0x48,0x08,0x08,0x88,0x48,0x3F,0x48,0x88,0x08,0x08,
0x08,0x00,0x93,0x55,0xD5,0x7F,0x55,0xD5,0x7F,0xD5,0x55,0x93,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x02,0x02,0x01,0x01,0x01,0x02,0x02,0x02,0x02,0x00,0x00,0x03,0x01,0xC1,0xC1,
0x01,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,
0x00,0x03,0x02,0x02,0x02,0x03,0x00,0x02,0x02,0x03,0x00,0x00,0xC0,0x83,0x02,0x02,
0x02,0x02,0x02,0x02,0x03,0x00,0x02,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x02,
0x02,0x00,0x02,0x02,0x03,0x02,0x01,0x01,0x01,0x01,0x02,0x02,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x03,0x03,0x1B,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDF,0xDF,
0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0x1B,0x03,0x03,0x00,0x00,0x00,
0x7E,0x7E,0x06,0x06,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0xC7,0xC7,0xC6,
0x66,0x66,0x66,0x66,0x66,0x46,0x06,0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xC0,0xC0,0xC0,0xC0,0xDF,0xDF,0xCC,0xCC,0xCC,0xFC,0xEC,0xCC,0xCC,0xCC,0xCC,
0xCC,0xCC,0xCC,0xEC,0xFC,0xCC,0xCC,0xCC,0xDF,0xDF,0xC0,0xC0,0xC0,0xC0,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0xF8,0xF8,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x0C,0x8C,0xCC,0xEC,0x7C,0x3F,0x0F,0x0C,0x0C,0x0C,0x8C,0xFC,0xFC,0x00,
0x00,0xFC,0xFC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xFC,0xFC,0x00,0x00,0x00,0x06,
0x06,0x86,0x86,0xC6,0xC7,0xC7,0x66,0x66,0x36,0x26,0x06,0x06,0x06,0x06,0x06,0x26,
0x37,0x67,0x66,0xC6,0xC6,0x86,0x86,0x86,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x03,0x01,0x01,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x01,0x00,0x00,
0x00,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00,0x01,
0x03,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00



};

const unsigned char  img_thermometer2[] PROGMEM = {
/*--  调入了一幅图像：C:\Users\luooove\Desktop\空间\中美胸牌\Untitled.bmp  --*/
/*--  宽度x高度=128x64  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,
0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x06,0x78,
0x04,0x03,0x00,0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00,0x3E,0x40,0x40,0x40,0x7E,
0x00,0x00,0x7E,0x04,0x02,0x02,0x7C,0x00,0x00,0x3C,0x42,0x42,0x42,0xFE,0x00,0x00,
0x00,0x00,0x00,0x7F,0x01,0x0F,0x3C,0x60,0x38,0x0E,0x01,0x7F,0x00,0x00,0x70,0x4A,
0x4A,0x7E,0x00,0x00,0x7F,0x18,0x34,0x62,0x40,0x00,0x3C,0x6A,0x4A,0x4A,0x2C,0x00,
0x7E,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x82,0xC2,0x62,0x1E,0x42,0x42,0x42,0x42,0x3E,
0x00,0x00,0x00,0xFC,0x00,0x00,0xFF,0x00,0x00,0x00,0xF8,0x08,0x08,0x08,0xFF,0x08,
0x08,0x08,0xF8,0x00,0x00,0x00,0xFC,0x04,0x06,0x05,0x04,0x04,0xFC,0x40,0x30,0x88,
0x06,0x05,0x04,0x04,0x04,0xFC,0x00,0x00,0x00,0x20,0x18,0x0E,0xE7,0x1C,0x34,0x04,
0x04,0xD0,0x4C,0x46,0x47,0x5C,0x74,0x44,0xC4,0x04,0x00,0x00,0x00,0x02,0x02,0x02,
0x02,0x02,0x02,0x02,0xC2,0x62,0x32,0x1A,0x1A,0x0E,0x06,0x02,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x3E,0x60,0xC0,0xFF,0x08,0x08,0x08,0x00,0x7F,0x21,0x21,0x21,0x21,0x21,0x7F,
0x00,0x00,0x00,0x1F,0x00,0xC0,0x3F,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0xFF,0x40,
0x40,0x40,0x3F,0x00,0x00,0x00,0xFF,0x02,0x02,0x02,0x02,0x02,0xFF,0x00,0x00,0x00,
0x03,0x06,0x0C,0x18,0x00,0xFF,0x00,0x00,0x00,0xC1,0x31,0x0D,0xFF,0x05,0x09,0x11,
0x00,0xFF,0x12,0x12,0x12,0x12,0x12,0x12,0xFF,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x00,0x00,0x00,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x01,0x01,0x01,0x01,0x03,0x00,0x00,0x00,
0x02,0x02,0x02,0x02,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,
0x00,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00


};
//byte array of bitmap 17x16 px
const unsigned char  img_heart_small[] PROGMEM = {

  0x20, 0x24, 0x24, 0x24, 0xFE, 0x23, 0x22, 0x20, 0x20, 0xFF, 0x20, 0x22, 0x2C, 0xA0, 0x20, 0x00,
  0x00, 0x08, 0x48, 0x84, 0x7F, 0x02, 0x41, 0x40, 0x20, 0x13, 0x0C, 0x14, 0x22, 0x41, 0xF8, 0x00
};

//byte array of bitmap 17x16 px
const unsigned char  img_heart_big[] PROGMEM = {

  0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00
};

//Byte array of bitmap of 76 x 56 px:
const unsigned char img_logo [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x30, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x07, 0xc3, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0x07, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xe1, 0xc3, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0xe3, 0xc7, 0xc7, 0xc7, 0xc7, 0xe3, 0xe0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x03, 0x7f, 0x7f, 0x7f, 0x7f, 0x03, 0xe3, 0x03, 0x7f, 0x7f, 0x7f, 0x03, 0xe3, 0x03, 0x7f, 0x7f, 0x7f, 0x7f, 0x03, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x0f, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x8f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x8f, 0x8f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0xc0, 0xc0, 0xf0, 0xff, 0xff, 0xf9, 0xf1, 0x01, 0x01, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf1, 0x01, 0x01, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x03, 0xe3, 0xf1, 0xf1, 0xf1, 0xf1, 0x01, 0x03, 0xff, 0xff, 0xff, 0xff, 0x07, 0x03, 0xe1, 0xf1, 0xf1, 0xf1, 0xf1, 0xe1, 0x03, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3, 0xf7, 0xff, 0xff, 0xf0, 0xe0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xf1, 0xe3, 0xe3, 0xe3, 0xe3, 0xf1, 0xf0, 0xf8, 0xff, 0xff, 0xff, 0xff
};





void splash() {

  oled.startScreen();
  oled.clear();

  oled.drawImage( img_logo, 20, 0, 76, 7 );
  oled.cursorTo(0, 7);
  oled.printString( "http://CoPiino.cc");

  delay(5000);

  oled.clear();
  oled.cursorTo(15, 1);
  oled.printString( "SSD1306+ATTiny");

  oled.cursorTo(30, 3);
  oled.printString( "Library");


  oled.cursorTo(0, 7);
  oled.printString( "http://CoPiino.cc");



}


void heartBeat() {
  static char big = 1;
  static long startTime = 0;
  long currentTime;

  // get current time
  currentTime = millis();

  // update if 1000ms passed
  if ((currentTime - startTime) > 200) {
    startTime = currentTime;


    // ---
    big = 1 - big;
    if (big) {
      oled.drawImage( img_heart_big, 10, 5, 17, 2);
    } else {
      oled.drawImage( img_heart_small, 10, 5, 17, 2);
    }

  }
}


void prepareDisplay() {

  unsigned int i, k;
  unsigned char ch[5];

  oled.clear();
  oled.startScreen();


  oled.cursorTo(0, 0);
  oled.printString( "ATTiny");
  oled.cursorTo(5, 1);
  oled.printString( "Standard Font");
  oled.cursorTo(10, 2);
  oled.printString( "abcdef...xyz");

  oled.drawImage( img_thermometer, 50, 4, 5, 3 );
  oled.cursorTo(60, 5);
  oled.printString( "+15" DEG );
  oled.cursorTo(67, 6);
  oled.printString( "63%");

  oled.drawImage( img_heart_small, 10, 5, 17, 2);


}

char getTemperature() {
  return random(-30, 30);
}

char getHumidity() {
  return random(0, 99);
}


void logo_luo()
{
  oled.clear();
  oled.startScreen();
  oled.cursorTo(0, 0);
 // oled.printString( "China-US Young Maker Competition");
  oled.drawImage( img_thermometer, 0, 0, 128, 8  );
  //delay(1000);
  //oled.clear();
 // oled.startScreen();
  //oled.cursorTo(0, 0);
  //oled.drawImage( img_thermometer2, 0, 0, 128, 8  );
 // delay(1000);
}
void setup() {
  pinMode(3, INPUT);

  oled.init(0x3c);
  oled.clear();
  
logo_luo();
}


void loop() {

  static long startTime = 0;
  long currentTime;

  
  
  //  // get current time
  //  currentTime= millis();
  //
  //  // update if 1000ms passed
  //  if ((currentTime - startTime) > 1000){
  //    startTime= currentTime;
  //    char buf[10];
  //
  //    // ---
  //    // update temperature
  //    char temperature= getTemperature();
  //
  //    sprintf(buf, "%+0.2hd" DEG , temperature);
  //
  //    // set cursor
  //    oled.cursorTo(60, 5);
  //
  //    // print to display
  //    oled.printString( buf );
  //
  //
  //    // ---
  //    // update humidity
  //    char humidity= getHumidity();
  //
  //    sprintf(buf, "%0.2hd\%", humidity);
  //
  //    // set cursor
  //    oled.cursorTo(67, 6);
  //
  //    // print to display
  //    oled.printString( buf );
  //
  //
  //
  //  }
  //
  //  heartBeat();


}

