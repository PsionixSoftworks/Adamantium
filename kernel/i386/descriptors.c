#include <kernel/i386/descriptors.h>

// Install the GDT. Located in file boot/desc.S
extern void gdt_install(void);

void descriptors_init(void)
{
	gdt_install();
}
