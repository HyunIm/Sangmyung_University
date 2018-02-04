%include "asm_io.inc"

	segment	.data
a	dd	1, 2, 3, 4, 5, 6
rows_a	dd	2
cols_a	dd	3

b	dd	7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9
rows_b	dd	3
cols_b	dd	4

	segment .bss
c	resd	8
rows_c	resd	1
cols_c	resd	1
i	resd	1			; i
j	resd	1			; j
k	resd	1			; k
i2	resd	1			; i2 <= because a[i][k]
k2	resd	1			; k2 <= because b[k][j]
i3	resd	1			; i3 <= because c[i][j]
sum	resd	1			; sum

	segment	.text
	global 	main
main:
	enter	0,0			; 201511054 Lim Hyun
	pusha

	mov	dword[i], -1		; i = 0
	mov	dword[i2], -12		; i2 = 0
	mov	dword[i3], -16		; i3 = 0

I:					; I = for (i)
	add	dword[i], 1		; i++
	add	dword[i2], 12		; i2++
	add	dword[i3], 16		; i3++
	mov	dword[j], -1		; j = 0
	mov	ebx, dword[i]		; ebx = i
	cmp	ebx, [rows_a]		; i < 2
	jl	J			; for (j)
	jmp	Final			; Final

J:					; J = for (j)
	add	dword[j], 1		; j++
	mov	dword[sum], 0		; sum = 0
	mov	dword[k], -1		; k = 0
	mov	dword[k2], -16		; k2 = 0
	jmp	K			; for (k)
J2:					; J2 = for (j2)
	mov	ebx, dword[i3]		; ebx = i3
	mov	ecx, dword[j]		; ecx = j
	mov	edx, dword[sum]		; edx = sum
	mov	dword[c+4*ecx+ebx], edx	; c[i][j] = sum
	cmp	ecx, [cols_b]		; j < 4
	jg	I			; for (i)
	jmp	J			; for (j)

K:					; K = for (k)
	add	dword[k], 1		; k++
	add	dword[k2], 16		; k2++
	mov	ebx, dword[i2]		; ebx = i2
	mov	ecx, dword[k]		; ecx = k
	mov	eax, dword[a+4*ecx+ebx]	; eax = a[i][k]
	mov	ebx, dword[k2]		; ebx = k2
	mov	ecx, dword[j]		; ecx = j
	mov	edi, dword[b+4*ecx+ebx]	; edi = b[k][j]
	mul	edi			; eax = eax * edi = a[i][k] * b[k][j]
	mov	esi, dword[sum]		; esi = sum
	add	eax, esi		; eax = sum + (a[i][k] * b[k][j])
	mov	dword[sum], eax		; sum = sum + a[i][k] * b[k][j]
	mov	ebx, dword[k]		; ebx = k
	cmp	ebx, 2			; k<3
	je	J2			; for (j2)
	jmp	K			; for (k)

Final:					; Final
	mov	dword[i3], -16		; i3 = 0


Print1:					; for (i)
	add	dword[i3], 16		; i3++
	mov	ebx, dword[i3]		; ebx = i3
	cmp	ebx, 32			; i3 < 2
	je	End			; End
	mov	dword[k], -1		; k = 0

Print2:					; for (k)
	add	dword[k], 1		; k++
	mov	ebx, dword[i3]		; ebx = i3
	mov	ecx, dword[k]		; ecx = k
	mov	eax, dword[c+4*ecx+ebx]	; %d = c[i][k]
	call	print_int		; printf("%d", eax);
	mov	al, ' '			; " "
	call	print_char		; printf(" ");
	cmp	ecx, 3			; k < 4
	jl	Print2			; for (k)
	call	print_nl		; \n
	jmp	Print1			; for (i)

End:					; End
	popa
	mov	eax, 0
	leave
	ret
