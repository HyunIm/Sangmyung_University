%include "asm_io.inc"

	segment	.data
	outA db "Enter a number(A) : ", 0x00
	outB db "Enter a number(B) : ", 0x00
	outResult db "A + B = ", 0x00
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
	add ecx, ebx
	mov eax, outResult
	call print_string
	mov eax, ecx
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
