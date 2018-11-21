;; ======================================================================
;; File: ~/hw-03/test.scm
;; ======================================================================

;; ======================================================================
;; define variables

(require (lib "pretty.ss"))

(define exp1 '())
(define exp2 '())
(define exp3 '())
(define exp4 '())
(define exp5 '())
(define exp6 '())
(define exp7 '())
(define exp8 '())

;; ======================================================================
;; test main function

(define test
  (lambda ()
    (printf "========================================~n")
    (printf "1. Constructor test~n")
    (set! exp1 (const-exp 7))
    (set! exp2 (const-exp 13))
    (set! exp3 (add-exp exp1 exp2))
    (set! exp4 (par-exp exp3))
    (set! exp5 (multi-exp exp2 exp4))
    (set! exp6 (add-exp exp4 exp5))
    (set! exp7 (multi-exp exp5 exp6))
    (set! exp8 (par-exp exp6))
    (pretty-print exp1)
    (pretty-print exp2)
    (pretty-print exp3)
    (pretty-print exp4)
    (pretty-print exp5)
    (pretty-print exp6)
    (pretty-print exp7)
    (pretty-print exp8)
    
    (printf "========================================~n")
    (printf "2. Predicates test~n")
    (pretty-print (const-exp? exp1))
    (pretty-print (const-exp? exp3))
    (pretty-print (add-exp? exp3))
    (pretty-print (add-exp? exp5))
    (pretty-print (multi-exp? exp4))
    (pretty-print (multi-exp? exp5))
    (pretty-print (par-exp? exp5))
    (pretty-print (par-exp? exp6))
    
    (printf "========================================~n")
    (printf "3. Extractors test~n")
    (pretty-print (exp->num exp1))
    (pretty-print (exp->num exp2))
    (pretty-print (exp->exp1 exp3))
    (pretty-print (exp->exp1 exp4))
    (pretty-print (exp->exp1 exp5))
    (pretty-print (exp->exp2 exp4))
    (pretty-print (exp->exp2 exp6))
    (pretty-print (exp->exp2 exp7))
    
    (printf "========================================~n")
    (printf "4. Function exp->string test~n")
    (pretty-print (exp->string exp1))
    (pretty-print (exp->string exp2))
    (pretty-print (exp->string exp3))
    (pretty-print (exp->string exp4))
    (pretty-print (exp->string exp5))
    (pretty-print (exp->string exp6))
    (pretty-print (exp->string exp7))
    (pretty-print (exp->string exp8))))

;; ======================================================================
