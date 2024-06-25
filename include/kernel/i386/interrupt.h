#ifndef _ADAMANTIUM_INTERRUPT_H
#define _ADAMANTIUM_INTERRUPT_H

#include <compiler.h>
#include <stdbool.h>

#ifndef MAX_INTERRUPTS
#define MAX_INTERRUPTS						256
#endif

extern void cli(void);
extern void sti(void);
extern void nmi_disable(void);
extern void nmi_enable(void);

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
