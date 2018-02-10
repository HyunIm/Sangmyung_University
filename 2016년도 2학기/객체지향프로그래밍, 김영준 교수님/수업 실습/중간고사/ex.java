import java.util.Scanner;
public class ex {
	public static void main (String [] args) {
		Scanner rd = new Scanner (System.in);
		int a = 1, b = 1;
		
		while (true) {
			System.out.println("첫번째로 더할 정수 입력 : ");
			a = rd.nextInt();
			System.out.println("두번째로 더할 정수 입력 : ");
			b = rd.nextInt();
			
			System.out.println(a + "+" + b + "=" + (a + b));
			
			if (a == 0 || b == 0)
				break;
		}
	}
	
}
