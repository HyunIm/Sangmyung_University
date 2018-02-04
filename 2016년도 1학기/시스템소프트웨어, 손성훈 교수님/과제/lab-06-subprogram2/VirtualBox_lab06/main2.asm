%include "asm_io.inc"

	segment	.data
array	dd	3, 1, 5, 7, 2, 8, 4, 9, 6, 10
size	dd	10

	segment	.text
	global 	main
	extern	Sort
main:
	enter	0,0
	pusha			; 201511054 Lim Hyun
				; This is Bubble Sort
	push	array		; parameter array [ebp + 12]
	push	size		; parameter size [ebp + 8]
	call	Sort		; call Sort
	add	esp, 8		; two parameter

	mov	ebx, 0		; ebx = 0
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
