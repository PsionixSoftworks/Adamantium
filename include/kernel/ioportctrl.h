#ifndef _ADAMANTIUM_IOPORTCTRL_H
#define _ADAMANTIUM_IOPORTCTRL_H			1

#define outb( portno, val )					__out_portb( portno, val )
#define inb( portno )						__in_portb( portno )

static inline void __out_portb(unsigned short portno, unsigned char val)
{
	asm volatile(
		"outb %b0, %w1" : : "a"(val), "Nd"(portno) : "memory"
	);
}

static inline unsigned char __in_portb(unsigned short portno)
{
	unsigned char val=0;
	asm volatile(
		"inb %w1, %b0"
		: "=a"(val)
		: "Nd"(portno)
		: "memory"
	);
	return val;
}

static inline void io_wait(void)
{
	outb(0x80, 0);
}

#endif
