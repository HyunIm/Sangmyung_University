;; ======================================================================

(define-datatype program program?
...)

(define-datatype class-decl class-decl?
...)

(define-datatype method-decl method-decl?
...)

(define-datatype expression expression?
...)

;; ======================================================================

(define scanner-rules
  '((whitespace (whitespace) skip)
    (comment ("%" (arbno (not #\newline))) skip)
    (number (digit (arbno digit)) number)
    (number ("-" digit (arbno digit)) number)
    (identifier (letter (arbno (or letter digit "_" "-" "?"))) symbol)))

(define parser-rules
...)

(define scan&parse
  (sllgen:make-string-parser scanner-rules parser-rules))

;; ======================================================================

(define pgm->string
  (lambda (pgm)
...))

;; ======================================================================

(define class-decls->string
  (lambda (class-decls)
...))

;; ======================================================================

(define field-names->string
  (lambda (field-names)
...))

;; ======================================================================

(define method-decls->string
  (lambda (method-decls)
...))

;; ======================================================================

(define vars->string
  (lambda (vars)
...))

;; ======================================================================

(define exp->string
  (lambda (exp)
...))

;; ======================================================================
