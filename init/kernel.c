#include <multiboot.h>
#include <vga.h>
#include <stdio.h>

// Check bit flags:
#define CHECK_FLAG(flags, bit)				((flags) & (1 << (bit)))

// Initialize the errno var:
int errno = 0;

// Entry point of the operating system kernel:
int main(unsigned long magic, unsigned long addr)
{
	// Setup multiboot:
	multiboot_info_t* mbi;

	// Text mode video address buffer:
	unsigned short* vga_buffer = (unsigned short*)0x000B8000;

	// Print a test character:
	putchar('X');

	// Next, print a string:
	puts(" Testing...");
	
	// And print with a format:
	printf(" %s\n", "Testing printf...");
	printf("Now I'm on the next line!\n");

	// Return as usual:
	return 0;
}
