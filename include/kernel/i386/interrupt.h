#ifndef _ADAMANTIUM_INTERRUPT_H
#define _ADAMANTIUM_INTERRUPT_H

#include <compiler.h>
#include <stdbool.h>

#ifndef MAX_INTERRUPTS
#define MAX_INTERRUPTS						256
#endif

#define IDT_MAX_DESCRIPTORS					MAX_INTERRUPTS
#define GDT_OFFSET_KERNEL_CODE				0x08
#define GDT_OFFSET_KERNEL_DATA				0x10

typedef struct
{
	unsigned short isr_low;
	unsigned short kernel_cs;
	unsigned char reserved;
	unsigned char attributes;
	unsigned short isr_high;
} _packed idt_t;

typedef struct
{
	unsigned short limit;
	unsigned char base;
} _packed pidt_t;

_align(16)
static idt_t idt[MAX_INTERRUPTS];
static pidt_t pidt;

extern void idt_set_descriptor(unsigned char vector, void* isr, unsigned char flags);
extern void idt_init(void);
extern void cli(void);
extern void sti(void);

static inline bool interrupts_enabled(void)
{
	unsigned long flags;
	asm volatile ( 
		"pushf\n\t"
		"pop %0"
		: "=g"(flags)
	);
	return flags & (1 << 9);
}

#endif
