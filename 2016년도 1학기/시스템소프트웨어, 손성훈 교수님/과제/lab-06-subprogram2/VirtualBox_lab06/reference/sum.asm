%include "asm_io.inc"

	segment	.data

	segment	.text
	global 	main
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

Calc_sum:
	push	ebp
	mov	ebp, esp
	sub	esp, 8		; two local variable

	mov	dword[ebp - 4], 0	; int i = 0
	mov	dword[ebp - 8], 0	; int sum = 0

Sum_loop:
	inc	dword[ebp - 4]		; i++;
	mov	ecx, dword[ebp - 4]	; ecx = i;
	add	dword[ebp - 8], ecx	; sum = sum + i;
	cmp	ecx, [ebp + 12]		; for (i = 1; i <= n; i++)
	jne	Sum_loop

	mov	eax, dword[ebp - 8]	; *sump = sum;

	mov	esp, ebp
	pop	ebp
	ret
