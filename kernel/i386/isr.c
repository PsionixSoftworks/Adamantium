#include <compiler.h>
#include <kernel/i386/isr.h>

void exception_handler(void)
{
	asm volatile( "cli; hlt" );
}
