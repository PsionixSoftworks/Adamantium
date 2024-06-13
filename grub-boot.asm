[BITS 32]

MULTIBOOT_ALIGN		EQU 1 << 0
MEMINFO				EQU 1 << 1
;VGA_GFX_MODE		EQU 1 << 2  ; Put this later as we need to test the kernel's functionality before we use graphic mode.
MULTIBOOT_FLAGS		EQU MULTIBOOT_ALIGN | MEMINFO ; | VGA_GFX_MODE
MULTIBOOT_MAGIC		EQU	0x1BADB002
CHECKSUM			EQU -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

SECTION .multiboot
ALIGN	4
		DD MULTIBOOT_MAGIC
		DD MULTIBOOT_FLAGS
		DD CHECKSUM

SECTION .bss
ALIGN	16
stack_bottom:
		resb 16384
stack_top:

SECTION .text
EXTERN main
GLOBAL _start:function (_start.end - _start)
_start:
		MOV ESP, stack_top
		CALL main

		; Temporarily disable interupts if we have no further instruction:
		CLI
		
; Run halt loop:
.hloop:	HLT
		JMP .hloop
.end:
