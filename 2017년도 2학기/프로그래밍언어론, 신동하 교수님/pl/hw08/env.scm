;; ======================================================================
;; @file : env.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 05
;; ======================================================================

;; ======================================================================

(define-datatype environment environment?
  (empty-env)
  (extend-env
   (var symbol?)
   (val reference?)
   (env environment?))
  (extend-env-rec*
   (p-names (list-of symbol?))
   (b-vars (list-of symbol?))
   (p-bodies (list-of expression?))
   (env environment?)))

;; ======================================================================

(define apply-env
  (lambda (env search-var)
    (cases environment env
	   (empty-env ()
		      (eopl:error 'apply-env "undefined ~a" search-var))
	   (extend-env (bvar bval saved-env)
		       (if (eqv? bvar search-var)
			   bval
			   (apply-env saved-env search-var)))
	   (extend-env-rec* (p-names b-vars p-bodies saved-env)
			    (let ((n (location search-var p-names)))
			      (if n
				  (newref
				   (proc-val
				    (procedure
				     (list-ref b-vars n)
				     (list-ref p-bodies n)
				     env)))
				  (apply-env saved-env search-var)))))))

(define init-env
  (lambda ()
    (let* ((tmp (empty-env))
	   (tmp (extend-env 'i (newref (num-val 1)) tmp))
	   (tmp (extend-env 'v (newref (num-val 5)) tmp))
	   (tmp (extend-env 'x (newref (num-val 10)) tmp)))
      tmp)))

(define location
  (lambda (search-var p-names)
    (cond ((null? p-names)
	   #f)
	  ((eqv? search-var (car p-names))
	   0)
	  ((location search-var (cdr p-names))
	   => (lambda (n)
		(+ n 1)))
	  (else #f))))

(define env->string-top
  (lambda (env)
    (format "[~a]" (env->string env))))

(define env->string
  (lambda (env)
    (cases environment env
	   (empty-env () (format ""))
	   (extend-env (var val env)
		      (if (empty-env? env)
			  (format "~a=~a~a"
				  var (expval->string val)
				  (env->string env))
			  (format "~a=~a,~a"
				  var (expval->string val)
				  (env->string env))))
	   (extend-env-rec* (p-names b-vars p-bodies saved-env)
			    (if (empty-env? saved-env)
				(format "~a(~a)=~a~a"
					p-names b-vars
					(exp->string p-bodies)
					(exp->string saved-env))
				(format "~a(~a)=~a,~a"
					p-names b-vars
					(exp->string p-bodies)
					(exp->string saved-env)))))))

(define empty-env?
  (lambda (env)
    (cases environment env
	   (empty-env () #t)
	   (else #f))))

;; ======================================================================
