; ----------------------------------------
; @title : xcount.scm
; @author : 임현 (201511054@sangmyung.kr)
; @since : 2017 - 09 - 25
; @brief : 어떤 list를 인수로 받아서 그 list를 구성하는 모든 요소의 개수를 return 한다.
; ----------------------------------------

(define xcount	; xcount Procedure
  (lambda (x)	; 정의
    (if (null? x)	; x가 null인가?
	0			; 참이면 0을 반환
	(if (list? (car x))	; 거짓이면, 첫번째 요소가 리스트인가?
	    (+ (xcount (car x)) (xcount (cdr x)))	; 참이면 첫번째 요소와 두번째 요소를 각각 재귀하고 더함
	    (+ 1 (xcount (cdr x)))))))			; 거짓이면 1을 더하고 두번째 요소를 재귀
