%include "asm_io.inc"

	segment	.text
	global 	main
main:
	enter	0,0
	pusha

	mov	eax, 0
	mov	ebx, 0
	mov	ecx, 2
	mov	edx, 0

repeat:	add	ebx, eax
	mov	eax, ebx
	mul	ecx
	mov	ebx, eax
	call	read_char
	mov	edx, eax
	sub	eax, 0x30
	cmp	edx, 0x0a
	jne	repeat

	mov	edx, 0
	mov	eax, ebx
	div	ecx

	call	print_int
	call	print_nl

	popa
	mov	eax, 0
	leave
	ret
