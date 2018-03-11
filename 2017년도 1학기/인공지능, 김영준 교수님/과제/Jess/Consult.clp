;***************************************
; @title : Consult.clp
; @author : ���� (201511054@sangmyung.kr)
; @since : 2017 - 05 - 01
; @brief : ������� ���α׷� ���� ����
;***************************************

; Savings �Ǵ�
(deffunction investment_savings ()
	(printout t "Savings(���� ����)�� ��õ�մϴ�." crlf crlf))

; Stocks �Ǵ�
(deffunction investment_stocks ()
	(printout t "Stocks(�ֽ� ����)�� ��õ�մϴ�." crlf crlf))

; Combination �Ǵ�
(deffunction investment_combination ()
	(printout t "Combination(����)�� ��õ�մϴ�." crlf crlf))

; ���� ��� �Ǵ�
(deffunction incomead (?x, ?y)
	(printout t "���� �������� " ?x "�̰�" crlf)
	(printout t "�ξ簡�� " ?y "���� �ξ��ϱ� ���� �ʿ�� �ϴ� ������" crlf)
	(printout t "��� ���θ� �Ǵ��ϴ� ������ " (+ 15000 (* 4000 ?y))
		"�̹Ƿ�" crlf)
	(printout t "������ ����� ������ �Ǵܵ˴ϴ�." crlf crlf))

; ���� ����� �Ǵ�
(deffunction incomein (?x, ?y)
	(printout t "���� �������� " ?x "�̰�" crlf)
	(printout t "�ξ簡�� " ?y "���� �ξ��ϱ� ���� �ʿ�� �ϴ� ������" crlf)
	(printout t "��� ���θ� �Ǵ��ϴ� ������ " (+ 15000 (* 4000 ?y))
		"�̹Ƿ�" crlf)
	(printout t "������ ������� ������ �Ǵܵ˴ϴ�." crlf crlf))

; ���� ���� ��� �Ǵ�
(deffunction savingsad (?x, ?y)
	(printout t "���� ���� ������ " ?x "�̰�" crlf)
	(printout t "�ξ簡�� " ?y "���� �ξ��ϱ� ���� �ʿ�� �ϴ� ������" crlf)
	(printout t "��� ���θ� �Ǵ��ϴ� ������ " (* 5000 ?y)
		"�̹Ƿ�" crlf)
	(printout t "���� ������ ����� ������ �Ǵܵ˴ϴ�." crlf crlf))

; ���� ���� ����� �Ǵ�
(deffunction savingsin (?x, ?y)
	(printout t "���� ���� ������ " ?x "�̰�" crlf)
	(printout t "�ξ簡�� " ?y "���� �ξ��ϱ� ���� �ʿ�� �ϴ� ������" crlf)
	(printout t "��� ���θ� �Ǵ��ϴ� ������ " (* 5000 ?y)
		"�̹Ƿ�" crlf)
	(printout t "���� ������ ������� ������ �Ǵܵ˴ϴ�." crlf crlf))

(defrule R1
	(savings_account ?x)
	(savings_account inadequate)
	(income ?y)
	=>
	(investment_savings)
	(assert (investment savings)))

(defrule R2
	(savings_account ?x)
	(savings_account adequate)
	(income ?y)
	(income adequate)
	=>
	(investment_stocks)
	(assert (investment stocks)))

(defrule R3
	(savings_account ?x)
	(savings_account adequate)
	(income ?y)
	(income inadequate)
	=>
	(investment_combination)
	(assert (investment combination)))

(defrule R4
	(amount_saved ?x)
	(dependents ?y&: (>= ?x (* 5000 ?y))) ; greater(X, minsavings(Y))
	=>
	(savingsad ?x ?y)
	(assert (savings_account adequate)))

(defrule R5
	(amount_saved ?x)
	(dependents ?y&: (< ?x (* 5000 ?y))) ; ��greater(X, minsavings(Y))
	=>
	(savingsin ?x ?y)
	(assert (savings_account inadequate)))

(defrule R6
	(earnings ?x steady)
	(dependents ?y&: (>= ?x (+ 15000 (* 4000 ?y)))) ; greater(X, minincome(Y))
	=>
	(incomead ?x ?y)
	(assert (income adequate)))

(defrule R7
	(earnings ?x steady)
	(dependents ?y&: (< ?x (+ 15000 (* 4000 ?y)))) ; ��greater(X, minincome(Y))
	=>
	(incomein ?x ?y)
	(assert (income inadequate)))

(defrule R8
	(earnings ?x unsteady)
	=>
	(incomein ?x ?y)
	(assert (income inadequate)))

(run)