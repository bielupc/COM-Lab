	.file	"fibonacci-orig.c"
	.text
	.comm	result,8,8
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L2
	cmpq	$1, -24(%rbp)
	jne	.L3
.L2:
	movq	-24(%rbp), %rax
	jmp	.L4
.L3:
	movq	-24(%rbp), %rax
	subq	$1, %rax
	movq	%rax, %rdi
	call	fibonacci
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	subq	$2, %rax
	movq	%rax, %rdi
	call	fibonacci
	addq	%rbx, %rax
.L4:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	fibonacci, .-fibonacci
	.section	.rodata
	.align 8
.LC0:
	.string	"Us: %s <number>\n   where <number> is the number from which to compute fibonacci(number).\n"
.LC1:
	.string	"fibonacci(%lu) = %lu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$2, -20(%rbp)
	je	.L6
	movq	-32(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$1, %edi
	call	exit
.L6:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	strtol
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fibonacci
	movq	%rax, result(%rip)
	movq	result(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
