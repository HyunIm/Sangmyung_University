; ----------------------------------------
; @title : xadd.scm
; @author : 임현 (201511054@sangmyung.kr)
; @since : 2017 - 09 - 25
; @brief : 정수의 list를 인수로 받아서 그 list를 구성하는 정수를 1 증가하여 만들어진 list를 return한다.
; ----------------------------------------

(define xadd	; xadd Procedure
  (lambda (x)	; 정의
    (if (null? x)	; x가 null인가?
	()					; 참이면 ()를 반환
	(cons (+ 1 (car x)) (xadd (cdr x))))))	; 거짓이면 첫번째 요소에 1을 더하고 두번째 요소를 재귀
