;; ======================================================================

(require (lib "pretty.ss"))
(pretty-print-columns 10)

;; ======================================================================

(define exp1 "x")
(define exp2 "(lambda (x) x)")
(define exp3 "[f x]")
(define exp4 "[(lambda (x) x) y]")
(define exp5 "(lambda (f) (lambda (x) [f x]))")
(define exp6 "[[(lambda (f) (lambda (x) [f x])) g] y]")

;; ======================================================================

(define test-one
  (lambda (exp)
    (let ((ast '()) (str '()))
      (printf "concrete: \"~a\"~n" exp)
      (set! ast (scan&parse exp))
      (printf "abstract: ")
      (pretty-display ast)
      (set! str (exp->str ast))
      (printf "string: \"~a\"~n" str)
      (if (equal? exp str)
	  (printf "ok~n")
	  (printf "***fail!***~n")))))  

;; ======================================================================

(define test
  (lambda ()
    (printf "==================== exp1 ====================~n")
    (test-one exp1)
    (printf "==================== exp2 ====================~n")
    (test-one exp2)
    (printf "==================== exp3 ====================~n")
    (test-one exp3)
    (printf "==================== exp4 ====================~n")
    (test-one exp4)
    (printf "==================== exp5 ====================~n")
    (test-one exp5)
    (printf "==================== exp6 ====================~n")
    (test-one exp6)
    ))

;; ======================================================================
