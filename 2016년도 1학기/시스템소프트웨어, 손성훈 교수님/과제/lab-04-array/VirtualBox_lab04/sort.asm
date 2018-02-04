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
	mov	ebx, -1		; ebx = i
First:
	inc	ebx		; i++
	mov	edx, ebx	; edx = j
	cmp	ebx, 9		; 9 = [size] - 1
	je	End		; i < size - 1
	jmp	Second
Second:
	inc	edx			; j++
	mov	eax, [array+ebx*4]
	cmp	eax, [array+edx*4]	; if (array[i] > array[j])
	ja	Swap
	cmp	edx, [size]		; j < [size]
	jne	Second
	jmp	First
Swap:
	mov	ecx, [array+edx*4]	; temp = *a
	mov	[array+ebx*4], ecx	; *a = *b
	mov	[array+edx*4], eax	; *b = temp
	jmp	Second
End:	
	mov ebx, 0
Print:	
	mov	eax, [array+ebx*4]
	call	print_int
	mov	al, ' '
	call	print_char
	inc	ebx
	cmp	ebx, [size]
	jne	Print
	call print_nl

	popa
	mov	eax, 0
	leave
	ret
