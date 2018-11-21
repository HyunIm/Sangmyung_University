;; ======================================================================
;; @file : value.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 10
;; ======================================================================

;; ======================================================================

(define-datatype expval expval?	; Abstract syntax
  (num-val (num number?))	; num-val (num)
  (bool-val (bool boolean?)))	; bool-val (bool)

;; ======================================================================

(define expval->num	; expval을 num으로 변환하는 함수
  (lambda (val)
    (cases expval val
	   (num-val (num) num)
	   (else (eopl:error 'expval->num "arg=~a" val)))))

(define expval->bool	; expval을 bool로 변환하는 함수
  (lambda (val)
    (cases expval val
	   (bool-val (bool) bool)
	   (else (eopl:error 'expval->bool "arg=~a" val)))))

(define expval->string	; expval을 string으로 변환하는 함수
  (lambda (val)
    (cases expval val
	   (num-val (num) (format "~a" num))
	   (bool-val (bool) (format "~a" bool)))))

;; ======================================================================
