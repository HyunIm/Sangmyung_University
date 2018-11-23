# ======================================================================
# File: start.S
# ======================================================================

.globl _start
_start:
	mov	r4, #0			// r4=0
	mcr	p15, #0, r4, c7, c5, #0	// invalidate i-cache
	dsb				// data synchronization barrier
	mcr	p15, #0, r4, c7, c5, #4	// flush prefetch buffer

	push	{lr}			// save lr
	str	sp, _saved_sp		// save u-boot sp
	ldr	sp, _svc_stack		// set svc stack

	mrc	p15, #0, r4, c12, c0, #0	// save vector base register
	str	r4, _saved_vector_base_register
	ldr	r4, _new_vector_base	// build new vector base register
	mcr	p15, #0, r4, c12, c0, #0

	mrs	r4, cpsr		// r4=cpsr

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
	bl	main			// main(argc, argv);

	ldr	r4, _saved_vector_base_register	// restore vector base register
	mcr	p15, #0, r4, c12, c0, #0

	ldr	sp, _saved_sp		// restore u-boot sp
	pop	{pc}			// restore pc

# ======================================================================

.align 5

new_vector_base:
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
	.word	undefined_instruction
_software_interrupt:
	.word	software_interrupt
_prefetch_abort:
	.word	prefetch_abort
_data_abort:
	.word	data_abort
_not_used:
	.word	_not_used
_irq:
	.word	irq
_fiq:
	.word	fiq

# ======================================================================

reset:
	b	reset

undefined_instruction:
	stmfd	sp!, {r0-r12, lr}	// save r0-r12, lr
	mov	r0, sp			// r0=sp
	mrs	r1, spsr		// r1=spsr
	bl	handle_undefined_instruction	// call C handler
	ldmfd	sp!, {r0-r12, pc}^	// restore r0-r12, pc, cpsr

software_interrupt:
	stmfd	sp!, {r0-r12, lr}	// save r0-r12, lr
	mov	r0, sp			// r0=sp
	mrs	r1, spsr		// r1=spsr
	bl	handle_software_interrupt	// call C handler
	ldmfd	sp!, {r0-r12, pc}^	// restore r0-r12, pc, cpsr

prefetch_abort:
	stmfd	sp!, {r0-r12, lr}	// save r0-r12, lr
	mov	r0, sp			// r0=sp
	mrs	r1, spsr		// r1=spsr
	bl	handle_prefetch_abort	// call C handler
	ldmfd	sp!, {r0-r12, pc}^	// restore r0-r12, pc, cpsr

data_abort:
	sub	lr, lr, #4		// lr=lr-4
	stmfd	sp!, {r0-r12, lr}	// save r0-r12, lr
	mov	r0, sp			// r0=sp
	mrs	r1, spsr		// r1=spsr
	bl	handle_data_abort	// call C handler
	ldmfd	sp!, {r0-r12, pc}^	// restore r0-r12, pc, cpsr

irq:
	sub	lr, lr, #4		// lr=lr-4
	stmfd	sp!, {r0-r12, lr}	// save r0-r12, lr
	mov	r0, sp			// r0=sp
	mrs	r1, spsr		// r1=spsr
	bl	handle_irq		// call C handler
	ldmfd	sp!, {r0-r12, pc}^	// restore r0-r12, pc, cpsr

fiq:
	sub	lr, lr, #4		// lr=lr-4
	stmfd	sp!, {r0-r8, lr}	// save r0-r7, lr
	mov	r0, sp			// r0=sp
	mrs	r1, spsr		// r1=spsr
	bl	handle_fiq		// call C handler
	ldmfd	sp!, {r0-r8, pc}^	// restore r0-r7, pc, cpsr

# ======================================================================

.globl _bss_start
_bss_start:
	.word	__bss_start

.globl _bss_end
_bss_end:
	.word	_end

# ======================================================================

_saved_sp:
	.word	0x00000000

_new_vector_base:
	.word	new_vector_base

_saved_vector_base_register:
	.word	0x00000000

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
