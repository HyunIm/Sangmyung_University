%include "asm_io.inc"

	segment	.text
	global 	main
	extern	Calc_sum
main:
	enter	0,0		; 201511054 LimHyun
	pusha

	call	read_int	; input n
	mov	ebx, eax	; ebx = eax = n
	mov	eax, 0		; eax = 0
	push	ebx		; ebx = n, [ebp + 12]
	push	eax		; eax = *sump, [ebp + 8]
	call	Calc_sum	; call calc_sum
				; Return Address [ebp + 4]
	call	print_int	; printf("%d", eax);
	call	print_nl	; printf("\n");
	add	esp, 8		; two parameter

	popa
	mov	eax, 0
	leave
	ret
