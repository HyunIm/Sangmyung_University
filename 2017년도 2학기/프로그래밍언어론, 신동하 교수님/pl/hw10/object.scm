;; ======================================================================

(define-datatype object object? 
  (an-object (class-name symbol?) (fields (list-of reference?))))

;; ======================================================================

(define new-object                      
  (lambda (class-name)
...))

(define object->string
  (lambda (obj)
...))

;; ======================================================================

(define-datatype class class?
...)

;; ======================================================================

(define the-class-env '())

(define add-to-class-env!
  (lambda (class-name class)
...))

(define lookup-class                    
  (lambda (name)
...))

(define report-unknown-class
  (lambda (name)
...))

(define initialize-class-env!
  (lambda (c-decls)
...))

(define initialize-class-decl!
  (lambda (c-decl)
...))

(define class->super-name
  (lambda (c-struct)
...))

(define class->field-names
  (lambda (c-struct)
...))

(define class->method-env
  (lambda (c-struct)
...))

(define object->class-name
  (lambda (obj)
...))

(define object->fields
  (lambda (obj)
...))

(define fresh-identifier-no
...)

(define fresh-identifier
  (lambda (identifier)
...))  

(define maybe
  (lambda (pred)
...))

;; ======================================================================

(define-datatype method method?
...)

;; ======================================================================

(define method-environment?
...)

(define assq-method-env
  (lambda (m-env id)
...))

(define find-method
  (lambda (c-name name)
...))

(define report-method-not-found
  (lambda (name)
...))

(define merge-method-envs
  (lambda (super-m-env new-m-env)
...))

(define method-decls->method-env
  (lambda (m-decls super-name field-names)
...))

;; ======================================================================
