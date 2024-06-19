	.code32
	.text
	.globl	memcpy
	.type	memcpy, @function
memcpy:
.begin:
	pushl	%esi
	pushl	%ebx
	movl	20(%esp), %ebx
	movl	12(%esp), %esi

	testl	%ebx, %ebx
	je		1f
	movl	16(%esp), %eax
	movl	%esi, %edx
	addl	%eax, %ebx
2:
	movzbl	(%eax), %ecx
	addl	$1, %eax
	addl	$1, %edx
	movb	%cl, -1(%edx)
	cmpl	%ebx, %eax
	jne		2b
1:
	movl	%esi, %eax
	popl	%ebx
	popl	%esi

	ret
