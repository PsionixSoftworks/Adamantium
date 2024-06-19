#ifndef _ADAMANTIUM_ISR_H
#define _ADAMANTIUM_ISR_H

#include <stdint.h>

#ifndef INTn
#define INTn(n)								asm ( "int $"#n )
#endif

typedef struct
{
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
} registers_t;

typedef void(*isr_t)(registers_t);

_noreturn
extern void exception_handler(void);

_noreturn
extern void register_interrupt_handler(uint8_t n, isr_t hndl);

#endif
