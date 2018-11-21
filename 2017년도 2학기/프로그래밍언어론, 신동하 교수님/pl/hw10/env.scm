;; ======================================================================

(define-datatype environment environment?
  (empty-env)
  (extend-env* (vars (list-of symbol?))
	       (vals (list-of reference?))
	       (env environment?))
  (extend-env-rec** (p-names (list-of symbol?))
		    (b-varss (list-of (list-of symbol?)))
		    (p-bodies (list-of expression?))
		    (env environment?))
  (extend-env-with-self-and-super (self object?)
				  (super-name symbol?)
				  (saved-env environment?)))

;; ======================================================================

(define apply-env
  (lambda (env search-sym)
...))

(define init-env 
  (lambda ()
    (empty-env)))

(define location
  (lambda (sym syms)
...))

;; ======================================================================

(define env->string-top
  (lambda (env)
    (format "[~a]" (env->string env))))

(define env->string
  (lambda (env)
    (cases environment env
	   (empty-env () "")
...)))

;; ======================================================================
