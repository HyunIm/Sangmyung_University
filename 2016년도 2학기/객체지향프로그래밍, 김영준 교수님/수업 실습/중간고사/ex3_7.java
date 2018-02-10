import java.util.Scanner;
public class ex3_7 {
	public static void main (String [] args) {
		Scanner rd = new Scanner (System.in);
		int intArr [] = new int [5];
		int max = 0;
		
		for (int i = 0; i < intArr.length; i++) {
			intArr[i] = rd.nextInt();
			if (max < intArr[i])
				max = intArr[i];
		}
		
		System.out.println("입력된 수에서 가장 큰 수는 " + max + "입니다.");
	}

}
