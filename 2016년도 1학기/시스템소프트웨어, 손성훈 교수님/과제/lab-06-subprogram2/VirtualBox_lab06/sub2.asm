%include "asm_io.inc"

	segment	.txt
	global	Sort

Sort:
	push	ebp
	mov	ebp, esp
	sub	esp, 0		; zero local variable

	mov	edi, [ebp + 12]	; edi = array
	mov	esi, [ebp + 8] ; esi = size
	mov	ebx, 0		; ebx = i
First:
	mov	edx, ebx	; edx = j
	cmp	ebx, 9		; 9 = [size] - 1
	je	End		; i < size - 1
	jmp	Second
Second:
	inc	edx			; j++
	mov	eax, [edi+ebx*4]
	cmp	eax, [edi+edx*4]	; if (array[i] > array[j])
	ja	Swap
	cmp	edx, [esi]		; j < [size]
	jne	Second
	inc	ebx			; i ++
	jmp	First
Swap:					; Swap
	mov	ecx, [edi+edx*4]	; temp = *a
	mov	[edi+ebx*4], ecx	; *a = *b
	mov	[edi+edx*4], eax	; *b = temp
	jmp	Second
End:
	mov	esp, ebp
	pop	ebp
	ret
