; ----------------------------------------
; @title : xsumint.scm
; @author : 임현 (201511054@sangmyung.kr)
; @since : 2017 - 09 - 24
; @brief : 어떤 list를 인수로 받아서 그 list를 구성하는 요소 중 정수의 합한 값을 return한다.
; ----------------------------------------

(define xsumint	; xsumint Procedure
  (lambda (x)	; 정의
    (if (null? x)	; x가 null인가?
	0			; 참이면 0을 반환
	(if (integer? (car x))	; 거짓이면, 첫번째 요소가 정수인가? 
		      (+ (car x) (xsumint (cdr x)))	; 참이면 첫번째 요소를 더하고 두번째 요소를 재귀
		      (xsumint (cdr x))))))		; 거짓이면 그대로 두번째 요소를 재귀
