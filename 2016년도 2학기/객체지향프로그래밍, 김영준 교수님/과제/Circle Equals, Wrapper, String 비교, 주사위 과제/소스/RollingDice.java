// -------------------------------------------------------
// �ֻ��� 2���� ���� ������, ��������� �ֻ��� 2���� �� �� �����İ� ��� ��,
// ������ �� ù ��° �ֻ��� ��, �� ��° �ֻ��� ��, �׸��� ���� ����ϰ�,
// ���� ���� �� �� ���� ����ϴ� ���α׷�
// 201511054 ��ǻ�Ͱ��а� ����
// -------------------------------------------------------

import java.util.Scanner;

public class RollingDice { // �ֻ��� ������
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		Dice dice1, dice2; // �ֻ��� 2�� ����
		int sum; // �� �ֻ����� ��
		int num; // �� �� ���� �� ����
		int count [] = new int [13]; // �� �ֻ����� ���� 2 ~ 12
		
		dice1 = new Dice();
		dice2 = new Dice();
		
		num = rd.nextInt(); // �� �� ���� �� ���� �Է�
		
		for (int i = 0; i < num; i++) { // num�� ������
			dice1.roll(); // �ֻ��� ������
			dice2.roll();
			sum = dice1.getFaceValue() + dice2.getFaceValue(); // �� �ֻ��� ��
			
			System.out.println("ù ��° �ֻ��� : " + dice1 + ", �� ��° �ֻ��� : " + dice2 + ", �� : " + sum);
			
			count[sum]++; // �տ� �ش�Ǵ� ���� �迭�� ����
		}
		
		for (int i = 2; i < 13; i++) {
			System.out.print("�� " + i + " : " + count[i] + "��, ");
		}
	}

}