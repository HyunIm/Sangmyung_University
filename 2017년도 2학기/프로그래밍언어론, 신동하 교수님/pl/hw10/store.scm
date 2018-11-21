;; ----------------------------------------------------------------------

;; memory store
(define the-store 'uninitialized)

;; empty-store: () -> Store
(define empty-store
  (lambda () '()))

;; get-store: () -> Store
(define get-store
  (lambda () the-store))

;; initialize-store!: () -> Unspecified
(define initialize-store!
  (lambda ()
...))

;; reference?: SchemeVal -> Bool
(define reference?
  (lambda (v)
...))

;; newref: ExpVal -> Ref
(define newref
  (lambda (val)
...))

;; deref: Ref -> ExpVal
(define deref
  (lambda (ref)
...))

;; setref!: Ref x ExpVal -> Unspecified
(define setref!
  (lambda (ref val)
...))

(define store->string
  (lambda (store)
...))

;; ----------------------------------------------------------------------
