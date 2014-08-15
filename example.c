/*
 * SSD1289 example
 * Author: Szymon Kłos
*/

#include "ssd1289.h"

int main(void)
{
	SSD1289_Init();

	for(int y = 0; y < 100; y++)
		for(int x = 0; x < 100; x++)
			DrawPixel(x, y, 0xFFFF);

	DrawRectangle(100, 100, 200, 200, 0x0000);

	_delay_ms(1000);
	FillScreen(RGB(255, 0, 0));
	_delay_ms(1000);
	FillScreen(RGB(0, 255, 0));
	_delay_ms(1000);
	FillScreen(RGB(0, 0, 255));

	return 0;
}
