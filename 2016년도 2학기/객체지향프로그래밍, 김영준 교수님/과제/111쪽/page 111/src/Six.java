import java.util.Scanner;
public class Six { // 201511054 ��ǻ�Ͱ��а� ����
	public static void main (String args[]) {
		Scanner scanner = new Scanner (System.in);
		
		int yy, mm, dd; // ��, ��, ��
		int day = 0; // 1900�� 1�� 1�� ������ ����
		int week; // day%7
		
		yy = scanner.nextInt(); // ��, ��, �� �Է�
		mm = scanner.nextInt();
		dd = scanner.nextInt();
		
		if ((yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0)) // ���� ���ǹ�
			System.out.println("�����Դϴ�.\n");
		else
			System.out.println("������ �ƴմϴ�.\n");
		
		for (int i = 1900; i < yy; i++) { // ���� �Ͻ� +366, �ƴ� �� +365
			if ((yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0))
				day += 366;
			else
				day += 365;
		}
		
		for (int i = 1; i < mm; i++) // �� �� �� ��
		{
			if ((mm == 4) || (mm == 6) || (mm == 9) || (mm == 11))
				day +=30;
			else if (mm == 2)
				day += 28;
			else
				day += 31;
		}
		
		day += dd; // ��
		
		if ((mm == 1 || mm == 2) && (yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0)) // �����ε� 1�� 2�� �� �� �� day--
			day--;
		
		week = day % 7; // day �������� �̿��� ���� ���
		
		switch (week) { // switch ���� �̿��� ���� ���
		case 1:
			System.out.println("�������Դϴ�.\n");
			break;
		case 2:
			System.out.println("ȭ�����Դϴ�.\n");
			break;
		case 3:
			System.out.println("�������Դϴ�.\n");
			break;
		case 4:
			System.out.println("������Դϴ�.\n");
			break;
		case 5:
			System.out.println("�ݿ����Դϴ�.\n");
			break;
		case 6:
			System.out.println("������Դϴ�.\n");
			break;
		case 0:
			System.out.println("�Ͽ����Դϴ�.\n");
			break;
		}
	}
}