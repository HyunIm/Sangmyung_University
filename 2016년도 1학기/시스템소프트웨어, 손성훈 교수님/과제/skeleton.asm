%include "asm_io.inc"

	segment	.data

	segment	.text
	global 	main
main:
	enter	0,0
	pusha

	popa
	mov	eax, 0
	leave
	ret