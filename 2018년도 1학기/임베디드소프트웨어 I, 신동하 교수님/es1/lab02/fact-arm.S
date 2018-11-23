# ======================================================================
# File: fact-arm.S
# Author : 임현 (201511054@sangmyung.kr)
# Since : 2018 - 03 - 27
# ======================================================================

# @title : unsigned int fact(unsigned int n)
# @param
#	unsigned int n : 0 ~ 9 (Register 0)
# @return : n! (Register 0)
#	Base case : 1
#	Induction step : n * fact(n - 1)

.globl fact
fact:
	cmp	r0, #1		@ if (n <= 1)
	ble	exit		@ n = 1
	push	{lr}		@ 스택에 복귀주소 push
	push	{r0}		@ 스택에 n값 push (이유는 r0값이 바껴서)
	sub	r0, #1		@ n = n - 1
	bl	fact		@ fact (n - 1) 호출
	pop	{r4}		@ 곱할 값을 r4에 pop
	mul	r0, r4		@ 1(n=1) * 2(n=2) * ... * n(n=n)
	pop	{pc}		@ fact(n + 1) 복귀 주소 pop
				@ 마지막은 main함수 복귀 주소 pop
exit:
	mov	r0, #1		@ n이 1이하일 땐 1값을 넣음
	mov	pc, lr		@ pc에 fact(2) 복귀주소를 넣음

# ======================================================================
