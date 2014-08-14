/*
 * SSD1289
 * Author: Szymon Kłos
*/

#ifndef _SSD1289_
#define _SSD1289_

#include <avr/io.h>
#include <util/delay.h>

#include "config.h"

enum
{
	COMMAND,
	DATA
};

void SSD1289_Write(short type, uint16_t data);
void SSD1289_WriteCommand(uint16_t address, uint16_t data);

void SSD1289_DisplayON(void);
void SSD1289_SleepMode(void);
void SSD1289_ReleaseFromSleep(void);

void SSD1289_Init(void);

void SetCursor(uint16_t x, uint16_t y);
void SetArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
					uint16_t color);
void FillScreen(uint16_t color);

#endif
