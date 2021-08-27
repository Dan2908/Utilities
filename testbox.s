	.file	"testbox.cpp"
	.text
	.section .rdata,"dr"
	.align 4
_ZN4utilL11C_BIG_ARRAYE:
	.long	512
	.def	__main;	.scl	2;	.type	32;	.endef
.LC0:
	.ascii "COPY DUFFS DEVICE... \0"
	.align 8
.LC2:
	.ascii "it took %i ticks, or %f seconds.\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB59:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movl	$3000, -56(%rbp)
	movl	-56(%rbp), %edx
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
.LEHB0:
	call	_ZN4util13dynamic_arrayIiEC1Ei
.LEHE0:
	movl	-56(%rbp), %edx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
.LEHB1:
	call	_ZN4util13dynamic_arrayIiEC1Ei
.LEHE1:
	movl	$0, -52(%rbp)
.L3:
	movl	-52(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jge	.L2
	movl	-52(%rbp), %eax
	leal	(%rax,%rax), %ebx
	movl	-52(%rbp), %edx
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiE3getEi
	movq	%rax, %rdx
	leal	1(%rbx), %eax
	movl	%eax, (%rdx)
	movl	-52(%rbp), %edx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiE3getEi
	movq	%rax, %rdx
	movl	-52(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, (%rdx)
	addl	$1, -52(%rbp)
	jmp	.L3
.L2:
	leaq	.LC0(%rip), %rcx
.LEHB2:
	call	puts
	call	clock
	cltq
	movq	%rax, -64(%rbp)
	leaq	-96(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiE3getEi
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiE3getEi
	movq	%rax, %rcx
	movl	-56(%rbp), %eax
	movl	%eax, %r8d
	movq	%rbx, %rdx
	call	_ZN4util9duff_copyEPiS0_i
	call	clock
	cltq
	subq	-64(%rbp), %rax
	movq	%rax, -64(%rbp)
	cvtsi2ssq	-64(%rbp), %xmm0
	movss	.LC1(%rip), %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rax, %xmm0
	movq	-64(%rbp), %rax
	movq	%rdx, %xmm2
	movq	%xmm0, %r8
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
.LEHE2:
	movl	$0, %ebx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiED1Ev
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiED1Ev
	movl	%ebx, %eax
	jmp	.L9
.L8:
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiED1Ev
	jmp	.L6
.L7:
	movq	%rax, %rbx
.L6:
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4util13dynamic_arrayIiED1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L9:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA59:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE59-.LLSDACSB59
.LLSDACSB59:
	.uleb128 .LEHB0-.LFB59
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB59
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L7-.LFB59
	.uleb128 0
	.uleb128 .LEHB2-.LFB59
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L8-.LFB59
	.uleb128 0
	.uleb128 .LEHB3-.LFB59
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE59:
	.text
	.seh_endproc
	.section	.text$_ZN4util13dynamic_arrayIiEC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4util13dynamic_arrayIiEC1Ei
	.def	_ZN4util13dynamic_arrayIiEC1Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4util13dynamic_arrayIiEC1Ei
_ZN4util13dynamic_arrayIiEC1Ei:
.LFB62:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	cltq
	movabsq	$2305843009213693950, %rdx
	cmpq	%rdx, %rax
	ja	.L11
	salq	$2, %rax
	jmp	.L13
.L11:
	call	__cxa_throw_bad_array_new_length
.L13:
	movq	%rax, %rcx
	call	_Znay
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 8(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN4util13dynamic_arrayIiED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4util13dynamic_arrayIiED1Ev
	.def	_ZN4util13dynamic_arrayIiED1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4util13dynamic_arrayIiED1Ev
_ZN4util13dynamic_arrayIiED1Ev:
.LFB65:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L15
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L15
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	_ZdaPv
.L15:
	movq	16(%rbp), %rax
	movq	$0, (%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN4util13dynamic_arrayIiE3getEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4util13dynamic_arrayIiE3getEi
	.def	_ZN4util13dynamic_arrayIiE3getEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4util13dynamic_arrayIiE3getEi
_ZN4util13dynamic_arrayIiE3getEi:
.LFB66:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rdx
	movl	24(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC1:
	.long	1148846080
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	clock;	.scl	2;	.type	32;	.endef
	.def	_ZN4util9duff_copyEPiS0_i;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.def	_Znay;	.scl	2;	.type	32;	.endef
	.def	_ZdaPv;	.scl	2;	.type	32;	.endef
