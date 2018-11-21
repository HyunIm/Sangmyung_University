;; ======================================================================
;; @file : run.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 15
;; ======================================================================

;; ======================================================================

(define runfile
  (lambda (file)
    (let ((string (readfile file)))
      (display string)
      (display (format "~a~n" (type->string (check string))))
      (set! trace-flag #f)
      (display (format "~a" (expval->string (run string))))
      (newline))))

(define run
  (lambda (string)
    (value-of-program (scan&parse string))))

(define value-of-program
  (lambda (pgm)
    (cases program pgm
	   (a-program (exp1)
		      (value-of exp1 (init-env))))))

(define value-of
  (lambda (exp env)
    (trace-run-enter exp env)
    (let ((val (value-of-1 exp env)))
      (trace-run-exit val)
      val)))

(define value-of-1
  (lambda (exp env)
    (cases expression exp
	   (const-exp (num)
		      (num-val num))
	   (var-exp (var)
		    (apply-env env var))
	   (zero?-exp (exp1)
		      (let ((val1 (value-of exp1 env)))
			(if (expval->bool val)
			    (value-of exp2 env)
			    (value-of exp3 env))))
	   (diff-exp (exp1 exp2)
		     (let ((num1 (expval->num (value-of exp1 env)))
			   (num2 (expval->num (value-of exp2 env))))
		       (num-val (- num1 num2))))
	   (if-exp (exp1 exp2 exp3)
		   (let ((val (value-of exp1 env)))
		     (if (expval->bool val)
			 (value-of exp2 env)
			 (value-of exp3 env))))
	   (let-exp (var exp1 body)
		    (let ((val1 (value-of exp1 env)))
		      (value-of body (extend-env var val1 env))))
	   (proc-exp (var body)
		     (proc-val (procedure var body env)))
	   (call-exp (rator rand)
		     (let ((proc
			    (expval->proc (value-of rator env)))
			   (arg (value-of rand env)))
		       (apply-procedure proc arg)))
	   (letrec-exp (p-result-type p-name b-var b-var-type p-pody letrec-body)
		       (value-of letrec-body
				 (extend-env-rec p-result-type p-name b-var b-var-type p-body env))))))

(define apply-procedure
  (lambda (proc1 val)
    (cases proc proc1
	   (procedure (var body saved-env)
		      (value-of body (extend-env var val saved-env))))))

;; ======================================================================
