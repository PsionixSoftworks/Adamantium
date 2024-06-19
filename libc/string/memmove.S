	.code32
	.text
	.globl	memmove
	.type	memmove, @function
memmove:
.begin:
	pushl	%esi
	pushl	%ebx
	movl	12(%esp), %ebx
	movl	16(%esp), %edx
	movl	20(%esp), %eax
	cmpl	%edx, %ebx
	jb		1f
	testl	%eax, %eax
	je		3f
2:
	subl	$1, %eax
	movzbl	(%edx,%eax), %ecx
	movb	%cl, (%ebx,%eax)
	jne		2b
3:
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	ret
1:
	testl	%eax, %eax
	je		3b
	movl	%ebx, %ecx
	leal	(%eax,%edx), %esi
4:
	movzbl	(%edx), %eax
	addl	$1, %edx
	addl	$1, %ecx
	movb	%al, -1(%ecx)
	cmpl	%esi, %edx
	jne		4b
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	ret
