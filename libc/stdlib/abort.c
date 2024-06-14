#include <stdlib.h>
#include <stdio.h>

NORETURN void abort(void)
{
	printf("[KERNEL]: !!Panic: abort()\n");

	while (1) {}
	__builtin_unreachable();
}
