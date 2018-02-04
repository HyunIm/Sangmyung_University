%include "asm_io.inc"

	segment	.bss
First	resd 32
Second	resd 32

	segment	.text
	global 	main
main:
	enter	0,0
	pusha

	call	read_int
	mov	dword[First], eax
	mov	edx, eax
	call	read_int
	mov	dword[Second], eax
	sub	dword[Second], 1
	mov	ecx, dword[Second]
Multi:
	add	dword[First], edx
	loop	Multi

	mov	eax, dword[First]
	call	print_int
	call	print_nl

	popa
	mov	eax, 0
	leave
	ret
