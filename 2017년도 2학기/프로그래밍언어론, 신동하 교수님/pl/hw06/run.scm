;; ======================================================================
;; @file : run.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 10
;; ======================================================================

;; ======================================================================

(define runfile
  (lambda (file)
    (let ((string (readfile file)))
      (display string)
      (display (format "~a" (expval->string (run (readfile file)))))
      (newline))))

(define run
  (lambda (string)
    (value-of-program (scan&parse string))))

(define value-of-program
  (lambda (pgm)
    (cases program pgm
	   (a-program (exp1)
		      (value-of exp1 (init-env))))))

(define value-of
  (lambda (exp env)
    (trace-run-enter exp env)
    (let ((val (value-of-1 exp env)))
      (trace-run-exit val)
      val)))

(define value-of-1
  (lambda (exp env)	; 매개변수 exp, env
    (cases expression exp
	   (const-exp (num)	; R-const
		      (num-val num))
	   (var-exp (var)	; R-var
		    (apply-env env var))
	   (zero?-exp (exp1)	; R-zero?
		      (let ((val1 (value-of exp1 env)))
			(let ((num1 (expval->num val1)))
			  (if (zero? num1)
			      (bool-val #t)
			      (bool-val #f)))))
	   (diff-exp (exp1 exp2)	; R-diff
		     (let ((num1 (expval->num (value-of exp1 env)))
			   (num2 (expval->num (value-of exp2 env))))
		       (num-val (- num1 num2))))
	   (if-exp (exp1 exp2 exp3)	; R-if
		   (let ((val (value-of exp1 env)))
		     (if (expval->bool val)
			 (value-of exp2 env)
			 (value-of exp3 env))))
	   (let-exp (var exp1 body)	; R-let
		    (let ((val1 (value-of exp1 env)))
		      (value-of body (extend-env var val1 env)))))))

; 매개변수 : exp, env
; exp의 데이터타입이 expression인 경우
; const-exp (num)인 경우 num-val인 num을 반환
; var-exp (var)인 경우 apply-env에 env와 var를 넣고 수행
	; 이유는 variable 값이 아닌 value 값을 반환하기 위해서
; zero?-exp (exp1)인 경우 
	; value-of 함수에 exp1과 env를 넣고 반환되는 값을 val1로 하고
	; expval->num 함수에 val1을 넣고 반환되는 값을 num1으로 한뒤
		; zero? 함수에 num1을 넣고
		; 참이면 #t를, 거짓이면 #f를 반환한다.
	; 이유는 zero? 함수의 매개변수 데이터 타입은 num이기 때문
; diff-exp (exp1 exp2)인 경우
	; value-of 함수에 exp와 env를 넣고 반환되는 값을
	; expval->num 함수에 넣은 뒤 데이터 타입이 number인 num을 반환하고
	; num1에서 num2를 뺀 값을 반환한다
	; 이유는 zero?-exp처럼 두 값을 빼려면 데이터 타입이 number여야 하기 때문
; if-exp (exp1 exp2 exp3)인 경우
	; value-of 함수에 exp1과 env를 넣고 반환된 값을 val로 하고
	; val값의 boolean값이 #t이면 exp2를 value-of에 넣고
	; val값이 boolean값이 #f이면 exp3를 value-of에 넣음
	; 이 때 val값이 boolean타입이 아닌 경우 에러
; let-exp (var exp1 body)인 경우
	; value-of 함수에 exp1과 env를 넣고 반환된 값을 val로 하고
	; value-of 함수에 body와 새로운 env를 생성해서 넣음
	; 이 때 body expression이 실행되고 종료되면, 
	; 새 env는 지역변수이므로 사라지게 됨

;; ======================================================================
