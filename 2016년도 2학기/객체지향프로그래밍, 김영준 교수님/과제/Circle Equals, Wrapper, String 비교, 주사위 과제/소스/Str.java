// -------------------------------------------------------
// ����ڷκ��� ���ڿ� 2���� �о, ������ �޼ҵ带 �̿��ؼ� ���� �� üũ�ϰ�, 
// ������� �޼ҵ带 ����Ͽ� ��� ���ڿ��� ������ �������� ����ϴ� ���α׷�
// 201511054 ��ǻ�Ͱ��а� ����
// -------------------------------------------------------

import java.util.Scanner;

public class Str {
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		
		String s1 = rd.next(); // ���ڿ� 2���� �޽��ϴ�.
		String s2 = rd.next();
		
		if (s1.equals(s2)) // �� ���ڿ��� ���� �� Ȯ���մϴ�.
			System.out.println("�� ���ڿ��� �����ϴ�.");
		else {
			int res = s1.compareTo(s2); // compareTo�� �̿��Ͽ� ���մϴ�.
			if (res < 0)
				System.out.println(s1 + " < " + s2);
			else if (res > 0)
				System.out.println(s1 + " > " + s2);
		}
	}
}