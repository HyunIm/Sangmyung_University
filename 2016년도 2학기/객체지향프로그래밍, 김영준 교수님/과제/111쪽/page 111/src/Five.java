import java.util.Scanner;
public class Five { // 201511054 ��ǻ�Ͱ��а� ����
	public static void main (String args[]) {
		Scanner scanner = new Scanner (System.in);
		
		int x, y, z; // ���� 3��
		int temp; // �� ������ �ٲٱ� ���� ����
		
		x = scanner.nextInt();
		y = scanner.nextInt();
		z = scanner.nextInt();
		
		if (x < y) { // ���� ū ���� z�� �ϱ� ���� ���ǹ�
			temp = x;
			x = y;
			y = temp;
		}
		if (x > z) {
			temp = x;
			x = z;
			z = temp;
		}
		
		if (x + y > z) { // �ﰢ���� �Ǳ� ���� ����
			if (x == y && y == z && z == x)
				System.out.println("���ﰢ���Դϴ�.");
			else if (x == y || y == z || z == x)
				System.out.println("�̵�ﰢ���Դϴ�.");
			else if (x * x + y * y == z * z)
				System.out.println("�����ﰢ���Դϴ�.");
			else
				System.out.println("�Ϲݻﰢ���Դϴ�.");
		}
		else
			System.out.println("�ﰢ���� �� �� �����ϴ�.");
	}
}