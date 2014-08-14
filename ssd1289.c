/*
 * SSD1289
 * Author: Szymon Kłos
*/

#include "ssd1289.h"

void SSD1289_Write(short type, uint16_t data)
{
	if(type == COMMAND)
		_LCD_CONTROL_PORT &= ~(1 << _LCD_RS);
	else
		_LCD_CONTROL_PORT |= (1 << _LCD_RS);

	_LCD_HI_PORT = (data >> 8);
	_LCD_LO_PORT = data;

	_LCD_CONTROL_PORT &= ~(1 << _LCD_WR);
	_LCD_CONTROL_PORT |= (1 << _LCD_WR);
}

void SSD1289_WriteCommand(uint16_t address, uint16_t data)
{
	SSD1289_Write(COMMAND, address);
	SSD1289_Write(DATA, data);
}

void SSD1289_DisplayON(void)
{
	// Power supply setting
	SSD1289_WriteCommand(POWER_CONTROL_1, 0xA8A4);
	SSD1289_WriteCommand(POWER_CONTROL_2, 0x0000);
	SSD1289_WriteCommand(POWER_CONTROL_3, 0x000C);
	SSD1289_WriteCommand(POWER_CONTROL_4, 0x2B00);
	SSD1289_WriteCommand(POWER_CONTROL_5, 0x00B7);

	SSD1289_WriteCommand(DISPLAY_CONTROL, 0x0021);

	SSD1289_WriteCommand(OSCILATOR, 0x0001);

	SSD1289_WriteCommand(DISPLAY_CONTROL, 0x0023);

	// Exit sleep mode
	SSD1289_WriteCommand(SLEEP_MODE, 0x0000);
	_delay_ms(30);

	SSD1289_WriteCommand(DISPLAY_CONTROL, 0x0033);

	// Entry mode setting
	SSD1289_WriteCommand(ENTRY_MODE, 0x6070);

	// LCD driver AC setting
	SSD1289_WriteCommand(LCD_DRIVE_AC, 0x0600);

	// RAM data write
	SSD1289_Write(COMMAND, RAM_DATA);
	// start write to RAM
}

void SSD1289_SleepMode(void)
{
	SSD1289_WriteCommand(SLEEP_MODE, 0x0001);
}

void SSD1289_ReleaseFromSleep(void)
{
	SSD1289_WriteCommand(SLEEP_MODE, 0x0000);
}

void SSD1289_Init()
{
	// Configure IO
	_LCD_CONTROL_DDR |= (1 << _LCD_RS) |
						(1 << _LCD_WR) |
						(1 << _LCD_CS);
	_LCD_HI_DDR = 0xFF;
	_LCD_LO_DDR = 0xFF;

	#ifdef _LCD_RD
		_LCD_CONTROL_DDR |= (1 << _LCD_RD);
		_LCD_CONTROL_PORT |= (1 << _LCD_RD);
	#endif

	// Reset
	#ifdef _LCD_RESET
		_LCD_CONTROL_DDR |= (1 << _LCD_RESET);

		_LCD_CONTROL_PORT &= ~(1 << _LCD_RESET);
		_delay_ms(15);
		_LCD_CONTROL_PORT |= (1 << _LCD_RESET);
		_delay_ms(15);
	#endif

	SSD1289_DisplayON();
}
