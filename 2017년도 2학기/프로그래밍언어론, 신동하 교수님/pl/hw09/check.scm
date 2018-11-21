;; ======================================================================
;; @file : check.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 15
;; ======================================================================

;; ======================================================================

(define check	; 매개변수 string을 받아서 type을 check하는 함수
  (lambda (string)
    (type-of-program (scan&parse string))))

(define type-of-program	; program을 받아서 type을 check하는 함수
  (lambda (pgm)
    (cases program pgm
	   (a-program (exp1) (type-of exp1 (init-tenv))))))

(define type-of	; 매개변수 exp와 tenv를 받아서 type을 check하는 함수
  (lambda (exp tenv)
    (trace-check-enter exp tenv)
    (let ((val (type-of-1 exp tenv)))
      (trace-check-exit val)
      val)))

(define type-of-1	; exp와 tenv의 type을 check하는 함수
  (lambda (exp tenv)
    (cases expression exp
	   (const-exp (num) (int-type))
	   (var-exp (var) (apply-tenv tenv var))
	   (zero?-exp)
	   (diff-exp)
	   (if-exp)
	   (let-exp)
	   (call-exp)
	   (proc-exp)
	   (letrec-exp))))

;; ======================================================================
