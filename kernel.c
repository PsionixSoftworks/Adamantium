#include "multiboot.h"
#include "vga.h"

// Entry point of the operating system kernel:
int main(void)
{
	// Text mode video address buffer:
	unsigned short* vga_buffer = (unsigned short*)0x000B8000;

	// Render a character to the screen to visually test the output:
	vga_buffer[0] = 'X' | 0x0F << 8;

	// Return as usual:
	return 0;
}
