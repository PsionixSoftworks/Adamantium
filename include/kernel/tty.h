#ifndef _ADAMANTIUM_KERNEL_TTY_H
#define _ADAMANTIUM_KERNEL_TTY_H			1

#include <string.h>
#include <stdbool.h>
#include <vga.h>

struct tty_handler
{
	unsigned short* vga_addr;
	unsigned char fg_color;
	unsigned char bg_color;
	bool initialized;
	unsigned int cursor_x;
	unsigned int cursor_y;
};

extern unsigned char foreground_color;
extern unsigned char background_color;

static inline void tty_init(struct tty_handler* tty);
static inline void tty_set_foreground_color(struct tty_handler* tty, unsigned char fg);
static inline void tty_set_background_color(struct tty_handler* tty, unsigned char bg);
static inline void tty_clear_screen(struct tty_handler* tty);

static inline void tty_init(struct tty_handler* tty)
{
	tty->vga_addr = (unsigned short*)VGA_TEXT_COLOR;
	tty_set_background_color(tty, SYSTEM_COLOR_BLACK);
	tty_set_foreground_color(tty, SYSTEM_COLOR_LT_GRAY);
	tty_clear_screen(tty);

	tty->initialized = true;
}

static inline void tty_set_foreground_color(struct tty_handler* tty, unsigned char fg)
{
	tty->fg_color = fg;
}

static inline void tty_set_background_color(struct tty_handler* tty, unsigned char bg)
{
	tty->bg_color = bg;
}

static inline void tty_clear_screen(struct tty_handler* tty)
{
	for (size_t i = 0; i < TERMINAL_WIDTH * TERMINAL_HEIGHT; i++)
	{
		tty->vga_addr[i] = (' ' | (vga_set_terminal_colors(tty->bg_color, tty->fg_color) << 8));
	}
}

#endif
