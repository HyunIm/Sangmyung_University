%include "asm_io.inc"

	segment	.text
	global 	main
main:
	enter	0,0		; 201511054 LimHyun
	pusha

	mov	ecx, [ebp + 12]	; ecx = pointer to argument vector
	mov	ebx, [ecx + 4]	; arg1\0

	mov	eax, 0		; AtoI sum
	mov	ecx, 10		; 10
	mov	edx, 0		; dl = [ebx + edi]
	mov	edi, 0		; edi = 0 
AtoI:				; atoi.asm (lab03)
	mov	dl, [ebx + edi]	; ebx = [ecx + 4] = arg1\0
	cmp	dl, 0		; \0
	je	Exit		; AtoI Exit
	sub	dl, 0x30	; '0' ASCII code : 0x30
	add	eax, edx	; eax = atoi sum
	mul	ecx		; sum *= 10
	inc	edi		; edi++
	jmp	AtoI		; jump AtoI
Exit:
	div	ecx		; sum /= 10

	mov	ebx, eax	; ebx = eax = arg1
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
	jne	Sum_loop		; if not equal Sum_loop

	mov	eax, dword[ebp - 8]	; *sump = sum;

	mov	esp, ebp
	pop	ebp
	ret
