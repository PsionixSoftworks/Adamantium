#include <kernel/i386/pic.h>
#include <kernel/ioportctrl.h>
#include <stdio.h>

static unsigned short pic_get_irq_reg(int ocw3);

void pic_send_eoi(unsigned char irq)
{
	if (irq >= 8)
		outb(PIC2_CMD, PIC_EOI);
	outb(PIC1_CMD, PIC_EOI);
}

void pic_remap(int offset1, int offset2)
{
	unsigned char a1, a2;
	a1 = inb(PIC1_DATA);
	a2 = inb(PIC2_DATA);

	outb(PIC1_CMD, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC2_CMD, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, offset1);
	io_wait();
	outb(PIC2_DATA, offset2);
	io_wait();
	outb(PIC1_DATA, 0x04);
	io_wait();
	outb(PIC2_DATA, 0x02);
	io_wait();

	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC1_DATA, ICW4_8086);
	io_wait();

	outb(PIC1_DATA, a1);
	outb(PIC2_DATA, a2);
}

void pic_disable(void)
{
	outb(PIC1_DATA, 0xFF);
	outb(PIC2_DATA, 0xFF);
}

unsigned short pic_get_irr(void)
{
	return pic_get_irq_reg(PIC_READ_IRR);
}

unsigned short pic_get_isr(void)
{
	return pic_get_irq_reg(PIC_READ_ISR);
}

static unsigned short pic_get_irq_reg(int ocw3)
{
	outb(PIC1_CMD, ocw3);
	outb(PIC2_CMD, ocw3);
	return (inb(PIC2_CMD) << 0x08) | inb(PIC1_CMD);
}
