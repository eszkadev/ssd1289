/*
 * SSD1289 example
 * Author: Szymon Kłos
*/

#include "ssd1289.h"

int main(void)
{
	SSD1289_Init();
	_delay_ms(1000);
	SSD1289_SleepMode();
	_delay_ms(1000);
	SSD1289_ReleaseFromSleep();

	return 0;
}
