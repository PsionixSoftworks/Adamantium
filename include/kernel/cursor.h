#ifndef _ADAMANTIUM_CURSOR_H
#define _ADAMANTIUM_CURSOR_H				1

#include <kernel/ioportctrl.h>
#include <vga.h>

static inline void cursor_enable(unsigned char start, unsigned char end)
{
	outb(0x03D4, 0x0A);
	outb(0x03D5, (inb(0x03D5) & 0xC0) | start);

	outb(0x03D4, 0x0B);
	outb(0x03D5, (inb(0x03D5) & 0xE0) | end);
}

static inline void cursor_disable(void)
{
	outb(0x03D4, 0x0A);
	outb(0x03D5, 0x20);
}

static inline void currsor_set_pos(unsigned int x, unsigned int y)
{
	unsigned short pos = y * TERMINAL_WIDTH + x;

	outb(0x03D4, 0x0F);
	outb(0x03D5, (unsigned char)(pos & 0xFF));
	outb(0x03D4, 0x0E);
	outb(0x03D5, (unsigned char)((pos >> 8) & 0xFF));
}

#endif
