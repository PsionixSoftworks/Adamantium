#include "multiboot.h"
#include "vga.h"

// Entry point of the operating system kernel:
int main(void)
{
	// Text mode video address buffer:
	unsigned short* vga_buffer = (unsigned short*)0x000B8000;

	// Return as usual:
	return 0;
}
