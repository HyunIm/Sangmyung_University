%include "asm_io.inc"

	segment	.text
	global 	main
main:
	enter	0,0		; 201511054 LimHyun
	pusha

	push	dword 3		; EBP + 16
	push	dword 2		; EBP + 12
	push	dword 1		; EBP + 8

	call	subpr
				; Return Address (= EBP + 4)
	add	esp, 12

	popa
	mov	eax, 0
	leave
	ret

subpr:
	push	ebp
	mov	ebp, esp
	sub	esp, 8

	mov	ecx, 5			; ecx = 5
Stack:					; High -> Low
	mov	eax, dword[ebp + ecx * 4 - 4]	; EBP + 16 -> EBP
	call	print_int		; printf("%d", eax);
	call	print_nl		; printf("\n");
	loop	Stack		; for (ecx = 5; ecx !=0; ecx--)

	mov	esp, ebp
	pop	ebp

	ret
