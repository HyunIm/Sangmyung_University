%include "asm_io.inc"

	segment	.data
array	dd	3, 1, 5, 7, 2, 8, 4, 9, 6, 10
size	dd	10

	segment	.text
	global 	main
main:
	enter	0,0
	pusha			; 201511054 Lim Hyun
				; This is Bubble Sort
	push	array		; parameter array [ebp + 12]
	push	size		; parameter size [ebp + 8]
	call	Sort		; call Sort
	add	esp, 8		; two parameter

	mov ebx, 0		; ebx = 0
Print:					; Print
	mov	eax, [array+ebx*4]
	call	print_int
	mov	al, ' '
	call	print_char
	inc	ebx
	cmp	ebx, [size]
	jne	Print
	call	print_nl

	popa
	mov	eax, 0
	leave
	ret

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
