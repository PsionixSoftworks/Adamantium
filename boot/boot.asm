; This bootloader will eventually replace GRUB as the primary bootloader, keeping everything as proprietary as possible.
; GRUB is just a starting point to get an MVP (or Minimum Viable Product) and test out the functionality of the kernel
; as it's being developed. GRUB is not affiliated or owned by Psionix Softworks LLC. The source used in multiboot.h is
; considered public domain and is used as intended by its creator(s). Use it as you wish within the short license given
; within the source file located at include/multiboot.h.

; We must start with 16-bit to get to protected mode (32-bit) on legacy machines. UEFI has a different setup, but it is
; still possible with most BIOS to access legacy support and boot from this code. Psionix Softworks LLC is not responsible
; for any damages and is implied without warranty just like multiboot.h. None of the source code contained within is
; allowed to be used for commercial purposes. This file and all of this bootloader and kernel is licensed under the
; Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International Public License. That means you may not use
; any of this code to make money, or change it in any way. You may re-distribute it as long as it remains open-source and
; contains no changes or financial gain.

; Tell the assembler we're in 16-bit mode for now:
[BITS 16]

; Set the origin point:
[ORG 0x7C00]
[GLOBAL _start]
_start:					; Finally, let's start
		; Begin 40x25 Text Mode:
		MOV AX, 0x00	; Set text mode 40x25 mode
		INT 10h			; Call interrupt 10h

		; Make block cursor:
		mov AH, 0x01	; Set cursor shape
		mov CH, 0x0000	; Start at 0
		mov CL, 0x0007	; End at 7 (block cursor)
		int 10h

		MOV AL, 'X'		; Put an X in memory
		MOV AH, 0x0E	; 
		INT 10h

		CLI
.hloop:	HLT
		JMP .hloop
TIMES 510-($-$$) DB 0
DW 0xAA55

; To test this file (not yet in Makefile), run commands:
	; nasm -fbin boot/boot.asm -o boot.o
	; qemu-system-i386 -fda boot.bin
; You must have NASM and QEmu installed.
