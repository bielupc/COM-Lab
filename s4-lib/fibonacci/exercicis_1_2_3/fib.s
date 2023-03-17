	.file	"fib.c"
	.text
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci:
.LFB0:
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
.LFE0:
	.size	fibonacci, .-fibonacci
	.ident	"GCC: (SUSE Linux) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
