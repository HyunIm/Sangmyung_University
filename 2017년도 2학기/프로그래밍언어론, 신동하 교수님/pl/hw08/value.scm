;; ======================================================================
;; @file : value.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 05
;; ======================================================================

;; ======================================================================

(define-datatype expval expval?
  (num-val (num number?))
  (bool-val (bool boolean?))
  (proc-val (proc proc?)))

(define-datatype proc proc?
  (procedure (var symbol?) (body expression?)
	     (saved-env environment?)))

;; ======================================================================

(define expval->num
  (lambda (val)
    (cases expval val
	   (num-val (num) num)
	   (else (eopl:error 'expval->num "arg=~a" val)))))

(define expval->bool
  (lambda (val)
    (cases expval val
	   (bool-val (bool) bool)
	   (else (eopl:error 'expval->bool "arg=~a" val)))))

(define expval->proc
  (lambda (val)
    (cases expval val
	   (proc-val (proc) proc)
	   (else (eopl:error 'expval->proc "arg=~a" val)))))

(define expval->string
  (lambda (val)
    (cases expval val
	   (num-val (num) (format "~a" num))
	   (bool-val (bool) (format "~a" bool))
	   (proc-val (proc1)
		     (cases proc proc1
			    (procedure (var body saved-env)
				       (format "proc(~a)~a~a"
					       var (exp->string body)
					       (env->string-top saved-env))))))))

;; ======================================================================
