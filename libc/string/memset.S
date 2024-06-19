	.code32
	.text
	.globl	memset
	.type	memset, @function
memset:
.begin:
	pushl	%esi
	pushl	%ebx
	movl	12(%esp), %ebx
	movl	20(%esp), %esi
	movzbl	16(%esp), %ecx
	leal	(%esi,%ebx), %edx
	testl	%esi, %esi
	je		2f
	movl	%ebx, %eax
1:
	movb	%cl, (%eax)
	addl	$1, %eax
	cmpl	%edx, %eax
	jne		1b
2:
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	ret
	