%include "asm_io.inc"

	segment	.data
	outA db "Enter a number(A) : ", 0x00
	outB db "Enter a number(B) : ", 0x00
	outResult db "A + B = ", 0x00
	outResult2 db "A - B = ", 0x00
	outResult3 db "A * B = ", 0x00
	outResult4 db "A / B = ", 0x00
	;
	; initialized data is put in the data segment here
	;

	segment	.text
	global 	main
main:
	enter	0,0		; setup stack frame
	pusha

	mov eax, outA
	call print_string
	call read_int
	mov ebx, eax
	mov eax, outB
	call print_string
	call read_int
	mov ecx, eax
	mov eax, ecx
	add eax, ebx
	mov edx, eax
	mov eax, outResult
	call print_string
	mov eax, edx
	call print_int
	call print_nl

	mov eax, ebx
	sub eax, ecx
	mov edx, eax
	mov eax, outResult2
	call print_string
	mov eax, edx
	call print_int
	call print_nl

	mov eax, outResult3
	call print_string
	mov eax, ebx
	mul ecx
	call print_int
	call print_nl

	mov eax, outResult4
	call print_string
	mov eax, ebx
	div ecx
	call print_int
	mov al, 44
	call print_char
	mov eax, edx
	call print_int
	call print_nl
	;
	; code is put in the text segment. Do not modify the code before
	; or after this comment.
	;

	popa
	mov	eax, 0	; return value
	leave			; leave stack frame
	ret
