;----------------------------------------
; @title : xlen.scm
; @author : 임현 (201511054@sangmyung.kr)
; @since : 2017 - 09 - 24
; @brief : 어떤 list를 인수로 받아서 그 list를 구성하는 요소의 개수를 return 한다.
; ---------------------------------------- 

(define xlen	; xlen Procedure
  (lambda (x)	; 정의
    (if (null? x)	; x가 null인가?
	0			; 참이면 0을 반환
	(+ 1 (xlen (cdr x))))))	; 거짓이면 1을 더하고 다음 요소를 재귀
