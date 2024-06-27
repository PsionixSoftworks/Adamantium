#define ASM_FILE							1
#define VIDEO_MODE_1024x768
#include <multiboot.h>
#include <vidmode.h>

#ifdef HAVE_ASM_USCORE
#define EXT_C( symbol )						_ ## symbol
#else
#define EXT_C( symbol )						symbol
#endif

#define STACK_SIZE							0x4000

#ifdef __ELF__
#define AOUT_KLUDGE							0x0
#else
#define AOUT_KLUDGE							MULTIBOOT_AOUT_KLUDGE
#endif
#define MULTIBOOT_HEADER_FLAGS				MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | /*MULTIBOOT_VIDEO_MODE |*/ AOUT_KLUDGE

.text
.globl start, _start
start:
_start:
	jmp multiboot_entry
	.align 4
multiboot_header:
	.long MULTIBOOT_HEADER_MAGIC
	.long MULTIBOOT_HEADER_FLAGS
	.long -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
#ifndef __ELF__
	.long multiboot_header
	.long _start
	.long _edata
	.long _end
	.long multiboot_entry
#else
	.long 	0
	.long 	0
	.long 	0
	.long	0
	.long	0
#endif
	.long	0
	.long	VIDEO_MODE_WIDTH
	.long	VIDEO_MODE_HEIGHT
	.long	32
multiboot_entry:
		movl	$(stack + STACK_SIZE), %esp
		pushl	%ebx
		pushl	%eax
		call	EXT_C(main)
loop: 	hlt
		jmp		loop
.comm stack, STACK_SIZE
