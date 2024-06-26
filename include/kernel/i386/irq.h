#ifndef _ADAMANTIUM_IRQ_H
#define _ADAMANTIUM_IRQ_H

#define IRQ0								0x20
#define IRQ1								0x21
#define IRQ2								0x22
#define IRQ3								0x23
#define IRQ4								0x24
#define IRQ5								0x25
#define IRQ6								0x26
#define IRQ7								0x27
#define IRQ8								0x28
#define IRQ9								0x29
#define IRQ10								0x2A
#define IRQ11								0x2B
#define IRQ12								0x2C
#define IRQ13								0x2D
#define IRQ14								0x2E
#define IRQ15								0x2F

extern unsigned long irq_disable(void);
extern void irq_restore(unsigned long flags);

#endif
