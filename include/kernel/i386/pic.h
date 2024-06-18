#ifndef _ADAMANTIUM_PIC_H
#define _ADAMANTIUM_PIC_H

#define PIC1								0x20
#define PIC2								0xA0
#define PIC1_CMD							PIC1
#define PIC1_DATA							(PIC1 + 1)
#define PIC2_CMD							PIC2
#define PIC2_DATA							(PIC2 + 1)
#define PIC_EOI								0x20

#define ICW1_ICW4							0x01
#define ICW1_SINGLE							0x02
#define ICW1_INTERVAL4						0x04
#define ICW1_LEVEL							0x08
#define ICW1_INIT							0x10

#define ICW4_8086							0x01
#define ICW4_AUTO							0x02
#define ICW4_BUF_SLAVE						0x08
#define ICW4_BUF_MASTER						0x0C
#define ICW4_SFNM							0x10

#define PIC_READ_IRR						0x0A
#define PIC_READ_ISR						0x0B

extern void pic_send_eoi(unsigned char irq);
extern void pic_remap(int offset1, int offset2);
extern void pic_disable(void);
extern unsigned short pic_get_irr(void);
extern unsigned short pic_get_isr(void);

#endif
