;; ======================================================================
;; @file : datatype.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 10 - 23
;; @brief : 언어 Expression의 abstract syntax를 표현하는 datatype인 
;	expression을 정의하고 datatype을 다루는 8개의 함수를 프로그램하라
;; ======================================================================


;; ======================================================================
;; Data type expression.

(define-datatype expression expression?	; 새로운 data type을 정의하는 도구
  (const-exp (num number?))
  (add-exp (exp1 expression?)
	   (exp2 expression?))
  (multi-exp (exp1 expression?)
	     (exp2 expression?))
  (par-exp (exp1 expression?)))

;; ======================================================================
;; Predicates.

(define const-exp?
  (lambda (exp)
    (cases expression exp	; 변수 exp가 expression 형일 때 ...
	   (const-exp (num) #t)	; 만약 변수 exp가 const-exp이면, 변수 num은 const-exp의 num field 값으로 정의되고, #t를 return함
	   (else #f))))		; 그렇지 않으면, #f를 return함

(define add-exp?
  (lambda (exp)
    (cases expression exp
	   (add-exp (exp1 exp2) #t)
	   (else #f))))

(define multi-exp?
  (lambda (exp)
    (cases expression exp
	   (multi-exp (exp1 exp2) #t)
	   (else #f))))

(define par-exp?
  (lambda (exp)
    (cases expression exp
	   (par-exp (exp1) #t)
	   (else #f))))

;; ======================================================================
;; Extractors.

(define exp->num
  (lambda (exp)
    (cases expression exp		; 변수 exp가 expression 형일 때...
	   (const-exp (num) num)	; 만약 변수 exp가 const-exp이면, 변수 num은 const-exp의 num field 값으로 정의되고, 변수 num을 return 함
	   (else #f))))			; 그렇지 않으면, #f를 return함

(define exp->exp1
  (lambda (exp)
    (cases expression exp
	   (add-exp (exp1 exp2) exp1)
	   (multi-exp (exp1 exp2) exp1)
	   (par-exp (exp1) exp1)
	   (else #f))))

(define exp->exp2
  (lambda (exp)
    (cases expression exp
	   (add-exp (exp1 exp2) exp2)
	   (multi-exp (exp1 exp2) exp2)
	   (else #f))))

;; ======================================================================
;; exp->string: exp -> string
;; Abstract syntax to concrete syntax.

(define exp->string
  (lambda (exp)
    (cond ((const-exp? exp)
	   (format "~a" (exp->num exp)))
	  ((add-exp? exp)
	   (format "~a+~a" (exp->string (exp->exp1 exp))
		   (exp->string (exp->exp2 exp))))
	  ((multi-exp? exp)
	   (format "~a*~a" (exp->string (exp->exp1 exp))
		   (exp->string (exp->exp2 exp))))
	  ((par-exp? exp)
	   (format "(~a)" (exp->string (exp->exp1 exp)))))))

;; ======================================================================
