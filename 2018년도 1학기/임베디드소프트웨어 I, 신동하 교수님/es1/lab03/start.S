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

	ldr	r4, _bss_start		// r4=bss_start
	ldr	r5, _bss_end		// r5=bss_end
	cmp	r4, r5			// if r4==r5
	beq	.L1 			// then goto .L1
	mov	r6, #0			// r6=0
.L0:
	str	r6, [r4]		// *r4=r6
	add	r4, r4, #4		// r4=r4+4
	cmp	r4, r5			// if r4!=r5
	bne	.L0			// then goto .L0
.L1:
	bl	main			// main(argc, argv);

	ldr	sp, _saved_sp		// restore u-boot sp
	pop	{pc}			// restore pc

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

# ======================================================================

_svc_stack:
	.word	0x82000000-0x00000000

# ======================================================================
