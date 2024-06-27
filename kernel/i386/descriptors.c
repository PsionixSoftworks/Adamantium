#include <kernel/i386/descriptors.h>
#include <kernel/i386/idt.h>
#include <kernel/i386/pic.h>
#include <string.h>

// Install the GDT. Located in file boot/desc.S
extern void gdt_install(void);
static void idt_install(void);

static void gdt_init(void);
static void idt_init(void);
static void idt_set_gate(uint8_t, uint32_t, uint16_t, uint8_t);

idt_entry_t	idt_entries[MAX_IDT_ENTRIES];
idt_ptr_t	idt_ptr;

void descriptors_init(void)
{
	gdt_init();
	idt_init();
}

static void gdt_init(void)
{
	gdt_install();
}

static void idt_init(void)
{
	idt_ptr.limit	= sizeof(idt_entry_t) * MAX_IDT_ENTRIES - 1;
	idt_ptr.base	= (uint32_t)&idt_entries;

	memset(&idt_entries, 0, sizeof(idt_entry_t) * MAX_IDT_ENTRIES);

	idt_set_gate(0x00, (uint32_t)isr0, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x01, (uint32_t)isr1, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x02, (uint32_t)isr2, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x03, (uint32_t)isr3, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x04, (uint32_t)isr4, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x05, (uint32_t)isr5, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x06, (uint32_t)isr6, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x07, (uint32_t)isr7, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x08, (uint32_t)isr8, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x09, (uint32_t)isr9, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x0A, (uint32_t)isr10, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x0B, (uint32_t)isr11, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x0C, (uint32_t)isr12, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x0D, (uint32_t)isr13, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x0E, (uint32_t)isr14, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x0F, (uint32_t)isr15, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x10, (uint32_t)isr16, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x11, (uint32_t)isr17, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x12, (uint32_t)isr18, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x13, (uint32_t)isr19, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x14, (uint32_t)isr20, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x15, (uint32_t)isr21, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x16, (uint32_t)isr22, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x17, (uint32_t)isr23, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x18, (uint32_t)isr24, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x19, (uint32_t)isr25, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x1A, (uint32_t)isr26, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x1B, (uint32_t)isr27, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x1C, (uint32_t)isr28, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x1D, (uint32_t)isr29, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x1E, (uint32_t)isr30, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	idt_set_gate(0x1F, (uint32_t)isr31, GDT_KERNEL_CODE_SEGMENT, 0x8E);
	
	__asm__ volatile ( "lidt %0" : : "m"(idt_ptr) );
}

static void idt_set_gate(uint8_t index, uint32_t base, uint16_t selector, uint8_t flags)
{
	idt_entries[index].base_low		= base & 0xFFFF;
	idt_entries[index].base_high	= (base >> 16) & 0xFFFF;
	idt_entries[index].selector		= selector;
	idt_entries[index].zero			= 0x00;
	idt_entries[index].flags		= flags;
}

static void idt_install(void)
{
	
}
