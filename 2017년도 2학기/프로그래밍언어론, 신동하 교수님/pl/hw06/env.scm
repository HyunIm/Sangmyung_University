;; ======================================================================
;; @file : env.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 11 - 10
;; ======================================================================

;; ======================================================================

; Data type expression
; 여러 변수들이 가지는 값을 표현하는 자료구조인 environment의 식을 정의
(define-datatype environment environment? ; Abstract syntax
  (empty-env)		; empty-env ()
  (extend-env		; extend-env (var val env)
   (var symbol?)
   (val expval?)
   (env environment?)))

;; ======================================================================

; LET Environment의 interface

; 특정 변수를 찾는 함수
; 매개변수 : env, 찾을 변수인 search-sym
; env의 데이터 타입이 environment일 경우
	; empty-env일 경우 에러 메세지를 출력하고
	; extend-env일 경우 bvar과 search-sym이 같은지 검사하고
		; 같을 경우 bval을 반환하고
		; 다를 경우 apply-env를 재귀호출하여 다음 env를 검사
; 위처럼 할 수 있는 이유는 env에 있는 변수들을 하나씩 넘어가며,
; 다시 한 번 apply-env를 호출해주기 때문에 마지막엔 결국 base-step인
; empty-env를 만나게 된다
(define apply-env
  (lambda (env search-sym)
    (cases environment env
	   (empty-env ()
		      (eopl:error 'apply-env "undefined ~a" search-sym))
	   (extend-env (bvar bval saved-env)
		       (if (eqv? bvar search-sym)
			   bval
			   (apply-env saved-env search-sym))))))

; 과제 요구사항 대로 초기 environment를 [x=10, v=5, i=1]으로 정의한다.
(define init-env
  (lambda ()
    (let* ((tmp (empty-env))
	   (tmp (extend-env 'i (num-val 1) tmp))
	   (tmp (extend-env 'v (num-val 5) tmp))
	   (tmp (extend-env 'x (num-val 10) tmp)))
      tmp)))

(define env->string-top
  (lambda (env)
    (format "[~a]" (env->string env))))

; env를 string으로 변환하는 함수
; 매개변수 : env
; env의 데이터 타입이 environment일 경우
	; empty-env인 경우 ""를 반환하고,
	; extend-env인 경우 env가 empty-env인지 검사하고 반환
(define env->string
  (lambda (env)
    (cases environment env
	   (empty-env () (format ""))
	   (extend-env (var val env)
		       (if (empty-env? env)
			   (format "~a=~a~a"
				   var (expval->string val) (env->string env))
			   (format "~a=~a,~a"
				   var (expval->string val) (env->string env)))))))

; env가 empty-env인지 검사하는 함수
; 매개변수 : env
; env의 데이터 타입이 environment일 경우
	; empty-env일 경우 boolean 타입인 #t를
	; 아닐 경우 #f를 반환
(define empty-env?
  (lambda (env)
    (cases environment env
	   (empty-env () #t)
	   (else #f))))

;; ======================================================================
