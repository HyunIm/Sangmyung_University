; text section must have an GLOBAL entry point 'main'
; text section must end with 'ret' instruction
; must include "asm_io.inc"
;	% nasm -f elf sample_io.asm
;	% nasm -f elf -d ELF_TYPE asm_io.asm
;	% gcc -o sample_io sample_io.o asm_io.o	
;	% ./sample_io

%include "asm_io.inc"
	
	section .data
msg	db	"asm_io library test", 0x0a, 0x00

	section .bss
string	resb	12

	section .text
	global main
main:
	enter	0,0

	dump_regs	1
	;print out a new line character
	call	print_nl

	; print out a character whose ASCII value stored in AL
	mov	al, 'A'
	call	print_char	
	call	print_nl
	dump_regs	2
	;print out a new line character
	call	print_nl

	; print out value of integer stored in EAL
        mov     eax,1024*1024*2
        call	print_int
	call	print_nl
	dump_regs	3
	;print out a new line character
	call	print_nl

	; print out the contents of the string at the address 
	; stored in EAX
	mov	eax, msg
	call	print_string
	dump_regs	4
	;print out a new line character
	call	print_nl

	call	read_int
	call	print_int
	call	print_nl

	leave
	ret
