#include <multiboot.h>
#include <vidmode.h>
#include <vga.h>
#include <kernel/tty.h>
#include <kernel/ioportctrl.h>
#include <kernel/cursor.h>
#include <kernel/i386/descriptors.h>
#include <kernel/i386/idt.h>
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
	
	// Check if the magic number is valid. If not, we're probably using our bootloader or something went wrong:
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		tty_set_foreground_color(&tty, SYSTEM_COLOR_RED);
		printf("[ERROR]: Invalid magic number: 0x%x\n", (unsigned)magic);
		return -1;
	}

	// Print our startup message:
	printf("== Adamantium Operating System v0.0.1a - Kernel Text Mode ==\n");

	// Get the address of the Multiboot info:
	mbi = (multiboot_info_t*)addr;

	// Print memory usage:
	printf("Memory Used: %uKB\n", mbi->mem_lower + mbi->mem_upper);

	// Install the descriptor tables:
	descriptors_init();

	asm("int $0x0");

	// Return as usual:
	return 0;
}
