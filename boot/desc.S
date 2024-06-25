	.code32
	.text
	.globl gdt_install
	
#include <kernel/i386/descriptors.h>

gdt_start:
	.quad	0x0
gdt_kernel_code:
	.word	0xFFFF
	.word	0x0000
	.byte	0x00
	.byte	0x9A
	.byte	0xCF
	.byte	0x00
gdt_kernel_data:
	.word	0xFFFF
	.word	0x0000
	.byte	0x00
	.byte	0x92
	.byte	0xCF
	.byte	0x00
gdt_end:
gdt_pointer:
	.word 	gdt_end - gdt_start
	.long 	gdt_start
gdt_install:
	movl 	$gdt_pointer, %eax
	lgdt 	(%eax)
	movw 	$GDT_KERNEL_DATA_SEGMENT, %ax
	movw 	%ax, %ds
	movw 	%ax, %es
	movw 	%ax, %fs
	movw 	%ax, %gs
	movw 	%ax, %ss
	ljmp	$GDT_KERNEL_CODE_SEGMENT, $.finish
.finish:
	ret
