;; ======================================================================
;; @file : parse.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 19
;; ======================================================================

;; ======================================================================

(define-datatype program program?
  (a-program (exp1 expression?)))

(define-datatype expression expression?
  (const-exp (num number?))
  (var-exp (var symbol?))
  (zero?-exp (exp1 expression?))
  (diff-exp (exp1 expression?) (exp2 expression?))
  (if-exp (exp1 expression?) (exp2 expression?)
	  (exp3 expression?))
  (let-exp (var symbol?) (exp1 expression?)
	   (exp2 expression?))
  (proc-exp (var symbol?) (body expression?))
  (call-exp (rator expression?) (rand expression?))
  (letrec-exp (p-name symbol?) (b-var symbol?)
	      (p-body expression?) (letrec-body expression?))
  (multi-exp (exp1 expression?) (exp2 expression?)))

;; ======================================================================

(define scanner-rules
  '((whitespace (whitespace) skip)
    (comment ("%" (arbno (not #\newline))) skip)
    (identifier (letter
		 (arbno (or letter digit "_" "?")))
		symbol)
    (number (digit (arbno digit)) number)
    (number ("-" digit (arbno digit)) number)))

(define parser-rules
  '((program (expression) a-program)
    (expression (number) const-exp)
    (expression (identifier) var-exp)
    (expression ("zero?" "(" expression ")") zero?-exp)
    (expression ("-" "(" expression "," expression ")") diff-exp)
    (expression ("if" expression "then" expression "else" expression)
		if-exp)
    (expression ("let" identifier "=" expression "in" expression)
		let-exp)
    (expression ("proc" "(" identifier ")" expression) proc-exp)
    (expression ("(" expression expression ")") call-exp)
    (expression ("letrec" identifier "(" identifier ")" "=" expression
		 "in" expression) letrec-exp)
    (expression ("*" "(" expression "," expression ")") multi-exp)))

(define scan&parse
  (sllgen:make-string-parser scanner-rules parser-rules))

;; ======================================================================

(define pgm->string
  (lambda (pgm)
    (cases program pgm
	   (a-program (exp1) (format "~a" (exp->string exp1))))))

(define exp->string
  (lambda (exp)
    (cases expression exp
	   (const-exp (num) (format "~a" num))
	   (var-exp (var) (format "~a" var))
	   (zero?-exp (exp1) (format "zero? (~a)" (exp->string exp1)))
	   (diff-exp (exp1 exp2)
		     (format "- (~a, ~a)"
			     (exp->string exp1) (exp->string exp2)))
	   (if-exp (exp1 exp2 exp3)
		   (format "if ~a then ~a else ~a"
			   (exp->string exp1) (exp->string exp2)
			   (exp->string exp3)))
	   (let-exp (var exp1 body)
		    (format "let ~a = ~a in ~a"
			    var (exp->string exp1) (exp->string body)))
	   (proc-exp (var body)
		     (format "proc (~a) ~a" var (exp->string body)))
	   (call-exp (rator rand)
		     (format "(~a ~a)"
			     (exp->string rator) (exp->string rand)))
	   (letrec-exp (p-name b-var p-body letrec-body)
		       (format "letrec ~a (~a) = ~a in ~a"
			       p-name b-var (exp->string p-body)
			       (exp->string letrec-body)))
	   (multi-exp (exp1 exp2)
		      (format "*(~a, ~a)"
			      (exp->string exp1) (exp->string exp2))))))

;; ======================================================================
