import java.util.Scanner;
public class ex {
	public static void main (String [] args) {
		Scanner rd = new Scanner (System.in);
		int a = 1, b = 1;
		
		while (true) {
			System.out.println("ù��°�� ���� ���� �Է� : ");
			a = rd.nextInt();
			System.out.println("�ι�°�� ���� ���� �Է� : ");
			b = rd.nextInt();
			
			System.out.println(a + "+" + b + "=" + (a + b));
			
			if (a == 0 || b == 0)
				break;
		}
	}
	
}
