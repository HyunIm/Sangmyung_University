;; ======================================================================
;; @file : env.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 19
;; ======================================================================

;; ======================================================================

(define-datatype environment environment?
  (empty-env)
  (extend-env
   (var symbol?)
   (val expval?)
   (env environment?))
  (extend-env-rec	; extend-env (p-name b-var body env)
   (p-name symbol?)
   (b-var symbol?)
   (body expression?)
   (env environment?)))

;; ======================================================================

	; extend-env-rec일 경우 p-name과 search-sym이 같은지 검사하고
		; 같을 경우 proc-val을 반환하고
		; 다를 경우 apply-env를 재귀호출하여 다음 env를 검사
(define apply-env
  (lambda (env search-sym)
    (cases environment env
	   (empty-env ()
		      (eopl:error 'apply-env "undefined ~a" search-sym))
	   (extend-env (bvar bval saved-env)
		       (if (eqv? bvar search-sym)
			   bval
			   (apply-env saved-env search-sym)))
	   (extend-env-rec (p-name b-var p-body saved-env)
			   (if (eqv? search-sym p-name)
			       (proc-val (procedure b-var p-body env))
			       (apply-env saved-env search-sym))))))

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

	; extend-env-rec인 경우 해당 출력 형식을 반환
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
				   (exp->string saved-env))))))

(define empty-env?
  (lambda (env)
    (cases environment env
	   (empty-env () #t)
	   (else #f))))

;; ======================================================================
