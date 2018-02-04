%include "asm_io.inc"

	segment	.bss
string	resb	32

	segment	.text
	global 	main
main:
	enter	0,0
	pusha

	mov	edx, 0
repeat: call	read_char
	mov	byte [string+edx], al
	inc	edx
	cmp	al, 0x0a
	jne	repeat
	mov	byte [string+edx-1], 0

	mov	eax, string
	call	print_string
	call	print_nl

	popa
	mov	eax, 0
	leave
	ret
