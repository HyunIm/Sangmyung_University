import java.util.Scanner;
public class Three { // 201511054 ��ǻ�Ͱ��а� ����
	public static void main (String args[]) {
		Scanner scanner = new Scanner (System.in);
		
		int money; // �Է¹޴� �׼�
		int FiftyThousand, TenThousand, OneThousand, FiveHundred, OneHundred, Fifty, Ten, One; // ���� ��, �� ��, õ ��, 500��, 100��, 50��, 10��, 1��
		money = scanner.nextInt();
		
		FiftyThousand = money / 50000;
		money %= 50000;
		TenThousand = money / 10000;
		money %= 10000;
		OneThousand = money / 1000;
		money %= 1000;
		FiveHundred = money / 500;
		money %= 500;
		OneHundred = money / 100;
		money %= 100;
		Fifty = money / 50;
		money %= 50;
		Ten = money / 10;
		money %= 10;
		One = money;
		
		System.out.println("���� ���� " + FiftyThousand + "��, �� ���� " + TenThousand + "��, õ ���� " + OneThousand + "��, 500��¥�� ���� " + FiveHundred + "��, 100��¥�� ���� " + OneHundred + "��, 50��¥�� ���� " + Fifty + "��, 10��¥�� ���� " + Ten + "��, 1��¥�� ���� " + One + "���̴�.");
	}
}