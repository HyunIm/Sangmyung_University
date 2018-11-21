;; ======================================================================

(define-datatype expval expval?
...)

(define-datatype proc proc?
...)

;; ======================================================================

(define expval->num
  (lambda (val)
...))

(define expval->bool
  (lambda (val)
...))

(define expval->proc
  (lambda (val)
...))

(define expval->obj
  (lambda (val)
...))

;; ======================================================================

(define expval->string
  (lambda (val)
...))

(define list-val->string
  (lambda (lst)
...))

;; ======================================================================
