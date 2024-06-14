#include <stdio.h>
#include <vga.h>
#include <kernel/tty.h>
#include <kernel/cursor.h>

unsigned char background_color;
unsigned char foreground_color;
extern struct tty_handler tty;

int putchar(int chr)
{
	static unsigned int index = 0;
	char c = (char)chr;

	if (c == '\n')
	{
		tty.cursor_x = 0;
		tty.cursor_y++;
		index = tty.cursor_y * TERMINAL_WIDTH + tty.cursor_x;
	}
	else
	{
		tty.vga_addr[index++] = c | vga_set_terminal_colors(tty.bg_color, tty.fg_color) << 8;
	}
	currsor_set_pos(tty.cursor_x, tty.cursor_y);
	return chr;
}
