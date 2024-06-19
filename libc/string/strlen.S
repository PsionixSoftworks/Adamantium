	.code32
	.text
	.globl	strlen
	.type	strlen, @function
strlen:
.begin:
	movl	4(%esp), %edx
	xorl	%eax, %eax
	cmpb	$0, (%edx)
	je		.return
.loop:
	addl	$1, %eax
	cmpb	$0, (%edx,%eax)
	jne		.loop
	ret
.return:
	ret
