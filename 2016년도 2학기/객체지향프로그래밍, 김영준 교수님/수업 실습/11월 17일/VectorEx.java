import java.util.*;

public class VectorEx {
	public static void main (String [] args) {
		// ���ڿ��� ���� ������ Vector �÷��� ����
		Vector <String> v = new Vector <String>();
		
		// Ű����κ��� 4���� �̸� �Է¹޾� Vector�� ����
		Scanner rd = new Scanner(System.in);
		for (int i = 0; i < 4; i++) {
			System.out.println("�̸��� �Է��ϼ���>>");
			String s = rd.next(); // Ű����κ��� �̸� �Է�
			v.add(s); // Vector �÷��ǿ� ����
		}
		
		// Vector�� ��� �ִ� ��� �̸� ���
		for (int i = 0; i < v.size(); i++) {
			// Vector�� i ��° ���ڿ� ������
			String name = v.get(i);
			System.out.println(name + " ");
		}
		
		// ���� �� �̸� ���
		int longestIndex = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v.get(longestIndex).length() < v.get(i).length())
				longestIndex = i;
		}
		System.out.println("\n ���� �� �̸��� : " + v.get(longestIndex));
	}
}
