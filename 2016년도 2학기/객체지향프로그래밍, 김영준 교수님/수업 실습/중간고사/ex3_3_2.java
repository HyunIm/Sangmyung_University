import java.util.Scanner;
public class ex3_3_2 {
	public static void main (String [] args) {
		Scanner rd = new Scanner (System.in);
		String n;
		int a;
		int sum = 0;
		
		do {
			n = rd.next();
			a = Integer.parseInt(n);
			sum += a;
			
		} while(a < 50);
		
		System.out.println("입력에 대한 합산은 : " + sum);
	}
}

