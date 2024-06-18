#ifndef _ADAMANTIUM_ISR_H
#define _ADAMANTIUM_ISR_H

#ifndef INTn
#define INTn(n)								asm ( "int $"#n )
#endif

_noreturn
extern void exception_handler(void);

#endif
