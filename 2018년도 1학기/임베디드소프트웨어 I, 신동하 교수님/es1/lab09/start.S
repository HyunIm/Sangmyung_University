# ======================================================================
# File: start.S
# ======================================================================

.globl _start
_start:
	ldr	pc, _reset
	ldr	pc, _undefined_instruction
	ldr	pc, _software_interrupt
	ldr	pc, _prefetch_abort
	ldr	pc, _data_abort
	ldr	pc, _not_used
	ldr	pc, _irq
	ldr	pc, _fiq

# ======================================================================

_reset:
	.word	reset
_undefined_instruction:
	.word	hang
_software_interrupt:
	.word	hang
_prefetch_abort:
	.word	hang
_data_abort:
	.word	hang
_not_used:
	.word	hang
_irq:
	.word	OS_CPU_IRQ_ISR
_fiq:
	.word	OS_CPU_FIQ_ISR

# ======================================================================

.globl reset
reset:
	mov	r4, #0x82000000		// build new vector base register
	mcr	p15, #0, r4, c12, c0, #0

	mrs	r4, cpsr		// r4=cpsr

	bic	r5, r4, #0x1f		// set svc stack
	orr	r5, r5, #0x13
	msr	cpsr, r5
	ldr	sp, _svc_stack

	bic	r5, r4, #0x1f		// set fiq stack
	orr	r5, r5, #0x11
	msr	cpsr, r5
	ldr	sp, _fiq_stack

	bic	r5, r4, #0x1f		// set irq stack
	orr	r5, r5, #0x12
	msr	cpsr, r5
	ldr	sp, _irq_stack

	bic	r5, r4, #0x1f		// set abort stack
	orr	r5, r5, #0x17
	msr	cpsr, r5
	ldr	sp, _abort_stack

	bic	r5, r4, #0x1f		// set undefined stack
	orr	r5, r5, #0x1b
	msr	cpsr, r5
	ldr	sp, _undefined_stack

	bic	r5, r4, #0x1f		// set user stack
	orr	r5, r5, #0x1f
	msr	cpsr, r5
	ldr	sp, _user_stack

	bic	r5, r4, #0x1f		// goto svc mode
	orr	r5, r5, #0x13
	msr	cpsr, r5

	ldr	r4, _bss_start		// r4=bss_start
	ldr	r5, _bss_end		// r5=bss_end
	cmp	r4, r5			// if r4==r5
	beq	.L1 			// then goto .L1
	mov	r6, #0x00000000		// r6=0
.L0:
	str	r6, [r4]		// *r4=r6
	add	r4, r4, #4		// r4=r4+4
	cmp	r4, r5			// if r4!=r5
	bne	.L0			// then goto .L0
.L1:
	bl	TIMER_init		// TIMER_init();
	bl	main			// main(argc, argv);

# ======================================================================

hang:
	b	hang			// hang

# ======================================================================

.globl _bss_start
_bss_start:
	.word	__bss_start
.globl _bss_end
_bss_end:
	.word	_end

# ======================================================================

_fiq_stack:
	.word	0x82000000-0x00000000
_irq_stack:
	.word	0x82000000-0x00001000
_abort_stack:
	.word	0x82000000-0x00002000
_undefined_stack:
	.word	0x82000000-0x00003000
_user_stack:
	.word	0x82000000-0x00004000
_svc_stack:
	.word	0x82000000-0x00005000

# ======================================================================
