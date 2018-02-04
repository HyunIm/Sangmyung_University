%include "asm_io.inc"

	segment	.text
	global	Calc_sum

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
