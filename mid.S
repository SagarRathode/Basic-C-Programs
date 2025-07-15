	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -116(%rbp)
	movq	l___const.main.a(%rip), %rax
	movq	%rax, -48(%rbp)
	movq	l___const.main.a+8(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	l___const.main.a+16(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	l___const.main.a+24(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	$4, -120(%rbp)
	movslq	-120(%rbp), %rax
	movl	-48(%rbp,%rax,4), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	%eax, -132(%rbp)        ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -128(%rbp)
	jg	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-124(%rbp), %eax
	imull	-128(%rbp), %eax
	movl	%eax, -124(%rbp)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-128(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -128(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	-124(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	leaq	-112(%rbp), %rdi
	movl	$50, %edx
	movl	%eax, -136(%rbp)        ## 4-byte Spill
	callq	_memset
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	-112(%rbp), %rsi
	leaq	L_.str.3(%rip), %rdi
	movl	%eax, -140(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	-112(%rbp), %rdx
	movq	%rdx, %rdi
	movl	%eax, -144(%rbp)        ## 4-byte Spill
	movq	%rdx, -152(%rbp)        ## 8-byte Spill
	callq	_strlen
	leaq	L_.str.4(%rip), %rdi
	movq	-152(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, %rdx
	movl	$50, %ecx
	movb	$0, %al
	callq	_printf
	movl	-116(%rbp), %r8d
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -156(%rbp)        ## 4-byte Spill
	movl	%r8d, -160(%rbp)        ## 4-byte Spill
	jne	LBB0_6
## %bb.5:
	movl	-160(%rbp), %eax        ## 4-byte Reload
	addq	$160, %rsp
	popq	%rbp
	retq
LBB0_6:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4               ## @__const.main.a
l___const.main.a:
	.long	1                       ## 0x1
	.long	2                       ## 0x2
	.long	3                       ## 0x3
	.long	4                       ## 0x4
	.long	5                       ## 0x5
	.long	6                       ## 0x6
	.long	7                       ## 0x7
	.long	8                       ## 0x8

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"fact=%d"

L_.str.2:                               ## @.str.2
	.asciz	"\n Kindly enter your name\n"

L_.str.3:                               ## @.str.3
	.asciz	"%s"

L_.str.4:                               ## @.str.4
	.asciz	"\nYour Name \t: %s\nName Length \t: %ld\nArray Size \t: %ld \n"


.subsections_via_symbols
