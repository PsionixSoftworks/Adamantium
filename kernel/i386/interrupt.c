#include <kernel/i386/interrupt.h>
#include <kernel/i386/pic.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool vectors[IDT_MAX_DESCRIPTORS];
extern void* isr_stub_table[];

void idt_set_descriptor(unsigned char vector, void* isr, unsigned char flags)
{
	idt_t* descriptor = &idt[vector];

	descriptor->isr_low		= (unsigned long long)isr & 0xFFFF;
	descriptor->kernel_cs	= GDT_OFFSET_KERNEL_CODE;
	descriptor->attributes	= flags;
	descriptor->isr_high	= (unsigned int)isr >> 16;
	descriptor->reserved	= 0;
}

void idt_init(void)
{
	pidt.base 	= (unsigned int)&idt[0];
	pidt.limit	= (unsigned short)sizeof(idt_t) * IDT_MAX_DESCRIPTORS - 1;

	memset(&idt, 0, sizeof(idt_t) * IDT_MAX_DESCRIPTORS);

	pic_remap(0x20, 0x28);

	for (unsigned char vector = 0; vector < 32; vector++)
	{
		idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
		vectors[vector] = true;
	}

	asm volatile ( "lidt %0" : : "m"(pidt) );
	asm volatile ( "sti" );
}
