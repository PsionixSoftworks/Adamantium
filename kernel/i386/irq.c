#include <kernel/i386/irq.h>

unsigned long irq_disable(void)
{
	unsigned long flags;
	asm volatile ( "pushf\n\tcli\n\tpop %0" : "=r"(flags) : : "memory" );
	return flags;
}

void irq_restore(unsigned long flags)
{
	asm ( "push %0\n\tpopf" : : "rm"(flags) : "memory", "cc" );
}
