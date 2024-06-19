	.code32
	.text
	.globl memcmp
	.type memcmp, @function
memcmp:
.begin:
	push	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl 	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	$0, -12(%ebp)
	jmp		1f
5:
	movl	-8(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %edx
	movl	-4(%ebp), %ecx
	movl	-12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	jnb		2f
	movl	$-1, %eax
	jmp		3f
2:
	movl	-4(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %edx
	movl	-8(%ebp), %ecx
	movl	-12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	jnb		4f
	movl	$1, %eax
	jmp 	3f
4:
	addl	$1, -12(%ebp)
1:
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb		5b
	movl	$0, %eax
3:
	leave
	ret
