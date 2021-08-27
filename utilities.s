	.file	"utilities.cpp"
	.text
	.section .rdata,"dr"
	.align 4
_ZN4utilL11C_BIG_ARRAYE:
	.long	512
	.text
	.globl	_ZN4util9duff_copyEPiS0_i
	.def	_ZN4util9duff_copyEPiS0_i;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4util9duff_copyEPiS0_i
_ZN4util9duff_copyEPiS0_i:
.LFB51:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	32(%rbp), %eax
	addl	$7, %eax
	leal	7(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$3, %eax
	movl	%eax, -4(%rbp)
	movl	32(%rbp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$29, %eax
	addl	%eax, %edx
	andl	$7, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$7, %eax
	ja	.L12
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L4(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L4:
	.long	.L11-.L4
	.long	.L10-.L4
	.long	.L9-.L4
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L13:
	nop
.L11:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L3:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L5:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L6:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L7:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L8:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L9:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L10:
	movq	16(%rbp), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, 24(%rbp)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	subl	$1, -4(%rbp)
	cmpl	$0, -4(%rbp)
	setne	%al
	testb	%al, %al
	jne	.L13
.L12:
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN4util10copy_arrayEPiS0_i
	.def	_ZN4util10copy_arrayEPiS0_i;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4util10copy_arrayEPiS0_i
_ZN4util10copy_arrayEPiS0_i:
.LFB52:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	$0, -4(%rbp)
.L16:
	movl	-4(%rbp), %eax
	cmpl	32(%rbp), %eax
	jge	.L17
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
	jmp	.L16
.L17:
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
