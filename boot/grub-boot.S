.set MULTIBOOT_ALIGN,		1 << 0
.set MEMINFO,				1 << 1
.set MULTIBOOT_FLAGS,		MULTIBOOT_ALIGN | MEMINFO
.set MULTIBOOT_MAGIC,		0x1BADB002
.set CHECKSUM,				-(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

.section .multiboot
.align	4
	.long MULTIBOOT_MAGIC
	.long MULTIBOOT_FLAGS
	.long CHECKSUM

.section .bss
.align	16
stack_end:
	.skip 16384
stack_begin:

.section .text
.globl _start
.type _start, @function
_start:
	mov $stack_begin, %esp
	call main
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
