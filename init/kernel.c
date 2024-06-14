#include <multiboot.h>
#include <vga.h>
#include <kernel/tty.h>
#include <stdio.h>

// Check bit flags:
#define CHECK_FLAG(flags, bit)				((flags) & (1 << (bit)))

// Initialize the errno var:
int errno = 0;
struct tty_handler tty;

// Entry point of the operating system kernel:
int main(unsigned long magic, unsigned long addr)
{
	// Setup multiboot:
	multiboot_info_t* mbi;

	tty_init(&tty);
	tty_set_background_color(&tty, SYSTEM_COLOR_BLACK);
	tty_set_foreground_color(&tty, SYSTEM_COLOR_GREEN);
	tty_clear_screen(&tty);

	// Print a test character:
	putchar('X');

	// Next, print a string:
	puts(" Testing...");
	
	// And print with a format:
	printf(" %s\n", "Testing printf...");

	tty_set_foreground_color(&tty, SYSTEM_COLOR_YELLOW);
	printf("Now I'm on the next line!\n");

	// Return as usual:
	return 0;
}
