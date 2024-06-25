#include <kernel/i386/interrupt.h>
#include <kernel/i386/pic.h>
#include <kernel/ioportctrl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void cli(void)
{
	asm volatile ( "cli" );
}

void sti(void)
{
	asm volatile ( "sti" );
}

void nmi_disable(void)
{
	outb(0x70, inb(0x70) & 0x80);
	inb(0x71);
}

void nmi_enable(void)
{
	outb(0x70, inb(0x70) & 0x7F);
	inb(0x71);
}
