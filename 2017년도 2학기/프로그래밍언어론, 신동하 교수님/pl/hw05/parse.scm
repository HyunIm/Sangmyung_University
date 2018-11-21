;; ======================================================================
;; @file : parse.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 05
;; @brief : 정의된 syntax를 가지는 언어 EXP에 대하여 프로그램 설명을 만족
;	하는 Scheme 프로그램
;; ======================================================================


;; ======================================================================

; Data type expression
(define-datatype exp exp?		; Abstract syntax
  (var-exp (var symbol?))		; var-exp (var)
  (abs-exp (var symbol?) (exp1 exp?))	; abs-exp (var exp1)
  (app-exp (exp1 exp?) (exp2 exp?)))	; app-exp (exp1 exp2)

;; ======================================================================

; Scanner Rules
(define scanner-rules	; 1) rule 이름, 2) rule 표현, 3) rule action으로 구성
  '((whitespace (whitespace) skip)	; ' ', '\n', '\r', '\t'를 skip 한다.
    (comment ("%" (arbno (not #\newline))) skip)	; % 뒤는 newline이 나올 때 까지 주석 처리
    (identifier (letter		; 변수
		 (arbno (or letter digit "_" "?")))	; 특수문자 허용
		symbol)))
; -----------	----------- ------------
; |rule 이름|	|rule 표현| |rule action|
; Rule 이름 	: Scheme symbol로 표현
; Rule 표현 	: regular expression으로 표현
; Rule action 	: 변환될 Scheme type을 기술


; Parser Rules
; 1) LHS, 2) RHS, 3) datatype의 variant 이름으로 구성
(define parser-rules					     ; Concrete syntax
  '((exp (identifier) var-exp)				     ; Exp ::= Var
    (exp ("(" "lambda" "(" identifier ")" exp ")") abs-exp)  ; Exp ::= (lambda (Var) Exp)
    (exp ("[" exp exp "]") app-exp)))			     ; Exp ::= [Exp Exp]
; -----		-----		--------------
; |LHS|		|RHS|		|variant 이름|

; scan&parse Function
(define scan&parse	; 함수를 만드는 함수
  (sllgen:make-string-parser scanner-rules parser-rules))

;; ======================================================================

; Abstract syntax to concrete syntax
(define exp->str
  (lambda (e)
    (cases exp e
	   (var-exp (var) (format "~a" var))
	   (abs-exp (var exp1)
		    (format "(lambda (~a) ~a)" var (exp->str exp1)))
	   (app-exp (exp1 exp2)
		    (format "[~a ~a]" (exp->str exp1) (exp->str exp2))))))

;; ======================================================================
