#include <stdio.h>
#include <vga.h>

int putchar(int chr)
{
	static unsigned int x = 0;
	static unsigned int y = 0;
	static unsigned int index = 0;
	char c = (char)chr;

	if (c == '\n')
	{
		x = 0;
		y++;
		index = y * TERMINAL_WIDTH + x;
	}
	else
	{
		video_addr[index++] = c | SYSTEM_COLOR_YELLOW << 8;
	}
	return chr;
}
