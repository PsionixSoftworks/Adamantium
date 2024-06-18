#ifndef _ADAMANTIUM_DESCRIPTORS_H
#define _ADAMANTIUM_DESCRIPTORS_H

#include <kernel/tty.h>
#include <vga.h>
#include <stdio.h>
#include "interrupt.h"

extern void gdt_install(void);
extern struct tty_handler tty;

static void gdt_init(void);

static void descriptor_tables_install(void)
{
	// Install the GDT:
	gdt_init();
	idt_init();

	// Print out that the descriptor tables have been installed:
	tty_set_foreground_color(&tty, SYSTEM_COLOR_LT_GREEN);
	printf("[INFO]: Successfully installed descriptor tables...\n");
	tty_set_foreground_color(&tty, SYSTEM_COLOR_GRAY);
}

static void gdt_init(void)
{
	gdt_install();
}

#endif
