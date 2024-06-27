#ifndef _ADAMANTIUM_IDT_H
#define _ADAMANTIUM_IDT_H					1

#include <compiler.h>
#include <stdint.h>
#include "isr.h"

typedef struct idt_entry_struct
{
	uint16_t 	base_low;
	uint16_t 	selector;
	uint8_t		zero;
	uint8_t		flags;
	uint16_t	base_high;
} _packed idt_entry_t;

typedef struct idt_ptr_struct
{
	uint16_t	limit;
	uint32_t	base;
} _packed idt_ptr_t;

#endif
