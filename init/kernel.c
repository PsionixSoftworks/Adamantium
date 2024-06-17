#include <multiboot.h>
#include <vga.h>
#include <kernel/tty.h>
#include <kernel/ioportctrl.h>
#include <kernel/cursor.h>
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
	
	cursor_enable(0x0, 0xF);

	tty_init(&tty);
	tty_set_background_color(&tty, SYSTEM_COLOR_BLACK);
	tty_set_foreground_color(&tty, SYSTEM_COLOR_LT_GRAY);
	tty_clear_screen(&tty);
	
	// And print with a format:
	printf("%s\n", "This is a string...");
	printf("%d\n", 550011);

	// Return as usual:
	return 0;
}
