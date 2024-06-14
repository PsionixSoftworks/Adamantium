#ifndef _VGA_H
#define _VGA_H

#ifndef SYSTEM_COLORS
#define SYSTEM_COLOR_BLACK					0x00
#define SYSTEM_COLOR_BLUE					0x01
#define SYSTEM_COLOR_GREEN					0x02
#define SYSTEM_COLOR_CYAN					0x03
#define SYSTEM_COLOR_RED					0x04
#define SYSTEM_COLOR_MAGENTA				0x05
#define SYSTEM_COLOR_ORANGE					0x06
#define SYSTEM_COLOR_LT_GRAY				0x07
#define SYSTEM_COLOR_GRAY					0x08
#define SYSTEM_COLOR_LT_BLUE				0x09
#define SYSTEM_COLOR_LT_GREEN				0x0A
#define SYSTEM_COLOR_LT_CYAN				0x0B
#define SYSTEM_COLOR_LT_RED					0x0C
#define SYSTEM_COLOR_LT_MAGENTA				0x0D
#define SYSTEM_COLOR_YELLOW					0x0E
#define SYSTEM_COLOR_WHITE					0x0F
#endif

// This is dependant on the bootloader settings. With GRUB, it sets the default to 80x25 because that is the higher resolution. In the custom bootloader,
// we will have the power to set this at startup. With that in mind, we need to check for the resolution in color text mode:
#ifdef TEXT_MODE_COLOR_40x25
#define TERMINAL_WIDTH						40
#define TERMINAL_HEIGHT						25
#else
#define TERMINAL_WIDTH						80
#define TERMINAL_HEIGHT						25
#endif	// !TEXT_MODE_COLOR_40x25

// Each of these have there uses:
#define VGA_GFX_MODE						0x000A0000		// Graphic Mode
#define VGA_TEXT_MONO						0x000B0000		// (Deprecated)
#define VGA_TEXT_COLOR						0x000B8000		// Video Text Mode

static inline unsigned char vga_set_terminal_colors(unsigned char bg, unsigned char fg)
{
	return fg | bg << 4;
}

#endif	// !_VGA_H
