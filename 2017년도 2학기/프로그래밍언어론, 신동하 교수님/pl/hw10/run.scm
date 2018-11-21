;; ======================================================================
;; for displaying class environment

(require (lib "pretty.ss"))
(pretty-print-columns 80)

;; ======================================================================

(define runfile
  (lambda (file)
    (let ((string (readfile file)))
      (display string)
      (display (format "~a" (expval->string (run string))))
      (newline))))

(define run
  (lambda (string)
    (value-of-program (scan&parse string))))

(define value-of-program 
  (lambda (pgm)
    (initialize-store!)             
    (cases program pgm
	   (a-program (class-decls body)
		      (initialize-class-env! class-decls)
;		      (pretty-display the-class-env)
		      (value-of body (init-env))))))

(define value-of
  (lambda (exp env)
    (trace-run-enter exp env)
    (let ((val (value-of-1 exp env)))
      (trace-run-exit val)
      val)))

(define value-of-1
  (lambda (exp env)
...))

(define values-of-exps
  (lambda (exps env)
    (map (lambda (exp) (value-of exp env)) exps)))

(define apply-procedure
  (lambda (proc1 vals)
...))

(define apply-method                    
  (lambda (m self args)
...))

;; ======================================================================
