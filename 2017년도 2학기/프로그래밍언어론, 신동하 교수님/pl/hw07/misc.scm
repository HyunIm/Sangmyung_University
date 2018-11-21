;; ======================================================================
;; @file : misc.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 19
;; ======================================================================

;; ======================================================================

(define readfile
  (lambda (file)
    (let ((port (open-input-file file)))
      (readfile2 '() port))))

(define readfile2
  (lambda (charlist port)
    (let ((c (read-char port)))
      (if (eof-object? c)
          (list->string charlist)
          (readfile2 (append charlist (list c)) port)))))

;; ======================================================================

(define trace-flag #f)
(define trace-no-of-spaces 0)

(define trace-run-enter
  (lambda (exp env)
    (and trace-flag
	 (set! trace-no-of-spaces (+ trace-no-of-spaces 1))
	 (trace-run-spaces trace-no-of-spaces)
	 (display (format "+ exp=~a~n" (exp->string exp)))
	 (trace-run-spaces trace-no-of-spaces)
	 (display (format "| env=~a~n" (env->string-top env))))))

(define trace-run-exit
  (lambda (val)
    (and trace-flag
	 (trace-run-spaces trace-no-of-spaces)
	 (display (format "- val=~a~n" (expval->string val)))
	 (set! trace-no-of-spaces (- trace-no-of-spaces 1)))))

(define trace-run-spaces
  (lambda (n)
    (if (eqv? n 0)
	(display "")
	(begin (display "|")
	       (trace-run-spaces (- n 1))))))

;; ======================================================================
