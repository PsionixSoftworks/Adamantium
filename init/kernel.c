#include <multiboot.h>
#include <vga.h>

// Check bit flags:
#define CHECK_FLAG(flags, bit)				((flags) & (1 << (bit)))

// Entry point of the operating system kernel:
int main(unsigned long magic, unsigned long addr)
{
	// Setup multiboot:
	multiboot_info_t* mbi;

	// Text mode video address buffer:
	unsigned short* vga_buffer = (unsigned short*)0x000B8000;

	// Render a character to the screen to visually test the output:
	vga_buffer[0] = 'X' | SYSTEM_COLOR_YELLOW << 8;

	// Return as usual:
	return 0;
}
