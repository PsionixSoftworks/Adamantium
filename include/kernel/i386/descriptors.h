#ifndef _ADAMANTIUM_DESCRIPTORS_H
#define _ADAMANTIUM_DESCRIPTORS_H

#include <kernel/tty.h>
#include <vga.h>
#include <stdio.h>

extern void gdt_install(void);
extern struct tty_handler tty;

static void descriptor_tables_install(void)
{
	// Install the GDT:
	gdt_install();

	// Print out that the descriptor tables have been installed:
	tty_set_foreground_color(&tty, SYSTEM_COLOR_LT_GREEN);
	printf("[INFO]: Successfully installed GDT...\n");
	tty_set_foreground_color(&tty, SYSTEM_COLOR_GRAY);
}

#endif
