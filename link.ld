OUTPUT_FORMAT(elf32-i386)
ENTRY(_start)
SECTIONS
{
	. = 2M;
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	.rodata	: { *(.rodata) }
	.data	: { *(.data) }
	.bss	: { *(.bss) }
}
