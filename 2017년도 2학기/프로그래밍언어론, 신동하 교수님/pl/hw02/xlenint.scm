; ----------------------------------------
; @title : xlenint.scm
; @author : 임현 (201511054@sangmyung.kr)
; @since : 2017 - 09 - 24
; @brief : 어떤 list를 인수로 받아서 그 list를 구성하는 요소 중 정수의 개수를 return 한다.
; ----------------------------------------

(define xlenint	; xlenint Procedure
  (lambda (x)	; 정의
    (if (null? x)	; x가 null인가?
	0			; 참이면 0을 반환
	(if (integer? (car x))	; 거짓이면, 첫번째 요소가 정수인가?
	    (+ 1 (xlenint (cdr x)))	; 참이면 1을 더하고 두번째 요소를 재귀
	    (xlenint (cdr x))))))	; 거짓이면 그대로 두번째 요소를 재귀
