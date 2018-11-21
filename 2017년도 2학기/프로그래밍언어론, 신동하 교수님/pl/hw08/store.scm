;; ----------------------------------------------------------------------
;; @file : store.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 05
;; ----------------------------------------------------------------------

;; ----------------------------------------------------------------------

(define the-store 'uninitialized)

(define empty-store
  (lambda () '()))

(define get-store
  (lambda () the-store))

(define initialize-store!
  (lambda ()
    (set! the-store (empty-store))))

(define reference?
  (lambda (v)
    (integer? v)))

(define newref
  (lambda (val)
    (let ((next-ref (length the-store)))
      (set! the-store (append the-store (list val)))
      next-ref)))

(define deref
  (lambda (ref)
    (list-ref the-store ref)))

(define setref!
  (lambda (ref val)
    (set! the-store
	  (letrec
	      ((setref-inner
		(lambda (store1 ref1)
		  (cond ((null? store1)
			 (report-invalid-reference ref the-store))
			 ((zero? ref1)
			  (cons val (cdr store1)))
			 (else
			  (cons (car store1)
				(setref-inner (cdr store1)
					      (- ref1 1))))))))
	    (setref-inner the-store ref)))))

(define store->string-top
  (lambda (store)
    (format "(~a)" (store->string store))))

(define store->string
  (lambda (store)
    (if (null? (cdr store))
	(format "~a" (expval->string (car store)))
	(format "~a,~a" (expval->string (car store))
		(store->string (cdr store))))))

;; ----------------------------------------------------------------------
