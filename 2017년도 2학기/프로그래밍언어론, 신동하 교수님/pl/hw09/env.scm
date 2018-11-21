;; ======================================================================
;; @file : env.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 15
;; ======================================================================

;; ======================================================================

(define-datatype environment environment?
  (empty-env)
  (extend-env (var symbol?) (val expval?)
	      (env environment?))
  (extend-env-rec
   (p-result-type type?)
   (p-name symbol?)
   (b-var symbol?)
   (b-var-type type?)
   (body expression?)
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
	   (extend-env-rec (p-result-type p-name b-var b-var-type p-body saved-env)
			   (if (eqv? search-symbol p-name)
			       (proc-val (procedure b-var b-var-type p-body env))
			       (apply-env saved-env search-symbol))))))

(define init-env
  (lambda ()
    (let* ((tmp (empty-env))
	   (tmp (extend-env 'i (num-val 1) tmp))
	   (tmp (extend-env 'v (num-val 5) tmp))
	   (tmp (extend-env 'x (num-val 10) tmp)))
      tmp)))

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
	   (extend-env-rec (p-name b-var p-body saved-env)
			   (format "~a(~a)=~a~a"
				   p-name b-var (exp->string p-body)
				   (exp->sring saved-env))))))

(define empty-env?
  (lambda (env)
    (cases environment env
	   (empty-env () #t)
	   (else #f))))

;; ======================================================================
