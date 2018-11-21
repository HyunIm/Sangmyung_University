;; ======================================================================
;; @file : tenv.scm
;; @author : 임현 (201511054@sangmyung.kr)
;; @since : 2017 - 12 - 15
;; ======================================================================

;; ======================================================================

; Type environment는 변수의 정보를 저장하고 있음
(define-datatype type-environment type-environment?
  (empty-tenv)
  (extend-tenv (var symbol?)
	       (type type?)
	       (tenv type-environment?)))

;; ======================================================================

; Type environment에서 변수의 type을 찾기 위한 함수 apply-tenv가 필요함
; 매개변수 : tenv, search-sym(찾을 변수)
; tenv의 데이터 타입이 type-environment일 경우
	; empty-tenv ()일 경우 (Base Case)
		; 에러 메시지를 출력 (search-sym을 찾을 수 없다는 메시지)
	; extend-tenv (var type saved-tenv)일 경우 (Induction Step)
		; var과 search-sym이 같은지 검사
			; 같은 경우 변수의 type을 반환
			; 다를 경우 apply-tenv를 재귀호출하여 다음 tenv를 검사
; 여기서 empty-tenv는 베이스 케이스이고,
; extend-tenv는 인덕션 스텝임
(define apply-tenv
  (lambda (tenv search-sym)
    (cases type-environment tenv
	   (empty-tenv ()
		       (eopl:error 'apply-tenv "undefined ~a" search-sym))
	   (extend-tenv (var type saved-tenv)
			(if (eqv? var search-sym)
			    type
			    (apply-tenv saved-tenv search-sym))))))

; 초기 type-environment는 [x=int, v=int, i=int]으로 정의
(define init-tenv
  (lambda ()
    (let* ((tmp (empty-tenv))
	   (tmp (extend-tenv 'i (int-type) tmp))
	   (tmp (extend-tenv 'v (int-type) tmp))
	   (tmp (extend-tenv 'x (int-type) tmp)))
      tmp)))

; tenv를 string으로 변환하여 출력하는 함수
(define tenv->string-top
  (lambda (tenv)
    (format "[~a]" (tenv->string tenv))))

; tenv를 string으로 변환하는 함수
; 매개변수 : tenv
; tenv의 데이터 타입이 type-environment일 경우
	; empty-env ()일 경우 ""를 반환
	; extend-env (var type saved-tenv)일 경우
		; saved-tenv가 empty-tenv인지 검사
			; 맞을 경우 마지막 출력 포맷(,가 없음)을 반환
			; 아닐 경우 중간 출력 포맷(,가 있음)을 반환
(define tenv->string
  (lambda (tenv)
    (cases type-environment tenv
	   (empty-tenv () (format ""))
	   (extend-tenv (var type saved-tenv)
			(if (empty-tenv? saved-tenv)
			    (format "~a=~a~a"
				    var (type->string type)
				    (tenv->string saved-tenv))
			    (format "~a=~a,~a"
				    var (type->string type)
				    (tenv->string saved-tenv)))))))

; tenv가 empty-tenv인지 검사하는 함수
; 매개변수 : tenv
; tenv의 데이터 타입이 type-environment일 경우
	; empty-tenv일 경우 boolean 타입인 #t를 반환
	; 아닐 경우 boolean 타입인 #f를 반환
(define empty-tenv?
  (lambda (tenv)
    (cases type-environment tenv
	   (empty-tenv () #t)
	   (else #f))))

;; ======================================================================
