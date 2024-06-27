#include <compiler.h>
#include <kernel/i386/isr.h>
#include <kernel/i386/interrupt.h>
#include <stdio.h>

/*static const char* exception_messages[MAX_INTERRUPTS] =
{
	"EXCEPTION_RAISED! : [Division by zero]...",
	"EXCEPTION_RAISED! : [Single-step Interrupt]",
	"EXCEPTION_RAISED! : [NMI Exception]",
	"EXCEPTION_RAISED! : [Breakpoint Exception]",
	"EXCEPTION_RAISED! : [Detected Overflow Exception]",
	"EXCEPTION_RAISED! : [Out Of Bounds Exception]",
	"EXCEPTION_RAISED! : [Invalid Opcode Exception]",
	"EXCEPTION_RAISED! : [No Available Coprocessor Exception]",
	"EXCEPTION_RAISED! : [Double Fault Exception]",
	"EXCEPTION_RAISED! : [Coprocessor Segment Overrun Exception]",
	"EXCEPTION_RAISED! : [Invalid TSS Exception]",
	"EXCEPTION_RAISED! : [Segment Not Present Exception]",
	"EXCEPTION_RAISED! : [Stack Fault Exception]",
	"EXCEPTION_RAISED! : [General Protection Fault Exception]",
	"EXCEPTION_RAISED! : [Page Fault Exception]",
	"EXCEPTION_RAISED! : [Reserved Interrupt Exception]",
	"EXCEPTION_RAISED! : [Math Fault Exception]",
	"EXCEPTION_RAISED! : [Alignment Check Exception]",
	"EXCEPTION_RAISED! : [Machine Check Exception]",
	"EXCEPTION_RAISED! : [SIMD Floating-Point Exception]",
	"EXCEPTION_RAISED! : [Virtualization Exception]",
	"EXCEPTION_RAISED! : [Control Protection Exception]",
};*/

isr_t interrupt_handler[MAX_INTERRUPTS];

//static void fault_handler(registers_t regs);

void exception_handler(void)
{
	printf("Adamantium Exception Raised!\n");
	asm volatile( "cli; hlt" );
}

void register_interrupt_handler(uint8_t n, isr_t hndl)
{
	interrupt_handler[n] = hndl;
}

void isr_handler(registers_t regs)
{
	printf("Received Intno: 0x%x\n", regs.int_no);

	/* // Check if the input handler has encountered an interrupt 
	if (interrupt_handler[regs.int_no] != 0)
	{
		// Handle the interrupt so we don't crash or triple fault 
		isr_t hndl = interrupt_handler[regs.int_no];
		hndl(regs);
	}
	else
	{
		// Call our fault handler: 
		fault_handler(regs);
	}*/
}

/*static void fault_handler(registers_t regs)
{
	// Make sure it's within the bounds of the ISR's (0-31) 
	if (regs.int_no < 32)
	{
		// Print the exception message 
		printf("%s, int_no: 0x%x\n", exception_messages[regs.int_no], regs.int_no);

		// Check if the exception is an errcode
		if (regs.err_code)
		{
			// Print out the error code:
			printf("ERROR_CODE: 0x%x\n");
		}
	}
}*/
