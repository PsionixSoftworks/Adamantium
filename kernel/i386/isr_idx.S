.code32
.globl isr0
.globl isr1
.globl isr2
.globl isr3
.globl isr4
.globl isr5
.globl isr6
.globl isr7
.globl isr8
.globl isr9
.globl isr10
.globl isr11
.globl isr12
.globl isr13
.globl isr14
.globl isr15
.globl isr16
.globl isr17
.globl isr18
.globl isr19
.globl isr20
.globl isr21
.globl isr22
.globl isr23
.globl isr24
.globl isr25
.globl isr26
.globl isr27
.globl isr28
.globl isr29
.globl isr30
.globl isr31
isr0:
	cli
	push $0x00
	push $0x00
	jmp isr_common_stub
isr1:
	cli
	push $0x00
	push $0x01
	jmp isr_common_stub
isr2:
	cli
	push $0x00
	push $0x02
	jmp isr_common_stub
isr3:
	cli
	push $0x00
	push $0x03
	jmp isr_common_stub
isr4:
	cli
	push $0x00
	push $0x04
	jmp isr_common_stub
isr5:
	cli
	push $0x00
	push $0x05
	jmp isr_common_stub
isr6:
	cli
	push $0x00
	push $0x06
	jmp isr_common_stub
isr7:
	cli
	push $0x00
	push $0x07
	jmp isr_common_stub
isr8:
	cli
	push $0x08
	jmp isr_common_stub
isr9:
	cli
	push $0x00
	push $0x09
	jmp isr_common_stub
isr10:
	cli
	push $0x0A
	jmp isr_common_stub
isr11:
	cli
	push $0x0B
	jmp isr_common_stub
isr12:
	cli
	push $0x0C
	jmp isr_common_stub
isr13:
	cli
	push $0x0D
	jmp isr_common_stub
isr14:
	cli
	push $0x0E
	jmp isr_common_stub
isr15:
	cli
	push $0x00
	push $0x0F
	jmp isr_common_stub
isr16:
	cli
	push $0x00
	push $0x10
	jmp isr_common_stub
isr17:
	cli
	push $0x11
	jmp isr_common_stub
isr18:
	cli
	push $0x00
	push $0x12
	jmp isr_common_stub
isr19:
	cli
	push $0x00
	push $0x13
	jmp isr_common_stub
isr20:
	cli
	push $0x00
	push $0x14
	jmp isr_common_stub
isr21:
	cli
	push $0x00
	push $0x15
	jmp isr_common_stub
isr22:
	cli
	push $0x00
	push $0x16
	jmp isr_common_stub
isr23:
	cli
	push $0x00
	push $0x17
	jmp isr_common_stub
isr24:
	cli
	push $0x00
	push $0x18
	jmp isr_common_stub
isr25:
	cli
	push $0x00
	push $0x19
	jmp isr_common_stub
isr26:
	cli
	push $0x00
	push $0x1A
	jmp isr_common_stub
isr27:
	cli
	push $0x00
	push $0x1B
	jmp isr_common_stub
isr28:
	cli
	push $0x00
	push $0x1C
	jmp isr_common_stub
isr29:
	cli
	push $0x00
	push $0x1D
	jmp isr_common_stub
isr30:
	cli
	push $0x1E
	jmp isr_common_stub
isr31:
	cli
	push $0x00
	push $0x1F
	jmp isr_common_stub

.extern isr_handler
isr_common_stub:
	pusha

	movw %ds, %ax
	push %eax

	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs

	call isr_handler

	pop %ebx
	movw %bx, %ds
	movw %bx, %es
	movw %bx, %fs
	movw %bx, %gs

	popa
	add $0x08, %esp
	iret
