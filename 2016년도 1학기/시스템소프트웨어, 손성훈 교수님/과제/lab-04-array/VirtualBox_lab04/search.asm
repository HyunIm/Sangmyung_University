%include "asm_io.inc"

	segment	.data
array	dd	3, 1, 5, 7, 2, 8, 4, 9, 6, 10
size	dd	10

	segment	.text
	global 	main
main:
	enter	0,0
	pusha

	mov	ebx, -1
	mov	ecx, [size]

	call	read_int

Search:
	inc	ebx
	cmp	eax, [array+ebx*4]
	je	Find
	loop	Search
	jmp	None

Find:
	mov	eax, ebx
	call	print_int
	call	print_nl
	jmp	End

None:
	mov	eax, -1
	call	print_int
	call	print_nl

End:
	popa
	mov	eax, 0
	leave
	ret
