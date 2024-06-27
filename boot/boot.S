#define ASM_FILE			1
#include <multiboot.h>

#ifdef __ELF__
#define AOUT_KLUDGE			0
#else
#define AOUT_KLUDGE			MULTIBOOT_AOUT_KLUDGE
#endif	// !__ELF__

#define STACK_SZ			0x4000

.set MULTIBOOT_ALIGN,		1 << 0
.set MULTIBOOT_MEMINFO,		1 << 1
.set MULTIBOOT_FLAGS,		MULTIBOOT_ALIGN | MULTIBOOT_MEMINFO
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
	movl $stack_begin, %esp

	pushl $0
	popf

	pushl %ebx
	pushl %eax
	
	sti
	call main
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
