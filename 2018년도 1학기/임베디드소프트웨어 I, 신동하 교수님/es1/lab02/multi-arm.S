# ======================================================================
# File: multi-arm.S
# Author : 임현 (201511054@sangmyung.kr)
# Since : 2018 - 03 - 27
# ======================================================================

# The function "multi" can not use "mul" instruction!

# @title : unsigned int multi(unsigned int i, unsigned int j)
# @param
#	unsigned int i : 2 ~ 9 (Register 0)
#	unsigned int j : 1 ~ 9 (Register 1)
# @return : i * j (Register 0)
#	Base Case : i
#	Induction Step : i + multi(i, j - 1)



.globl multi
multi:
	cmp	r1, #1		@ if (j == 1)
	beq	exit		@ j는 1일 때부터 j일 때까지 한 번에 계산
	push	{lr}		@ 스택에 복귀주소 push
	sub	r1, #1		@ j = j - 1
	push	{r0}		@ 스택에 i값 push (이유는 r0값이 바껴서)
	bl	multi		@ multi (i, j - 1) 호출
	pop	{r4}		@ 더할 i값을 r4에 pop
	add	r0, r4		@ i(j는 1일때) + i(...) + i(j는 j일때)
	pop	{pc}		@ multi(i, j + 1) 복귀 주소 pop
				@ 마지막은 main함수 복귀 주소 pop
exit:
	mov	pc, lr		@ pc에 multi(i, 2) 복귀주소를 넣음

# ======================================================================

