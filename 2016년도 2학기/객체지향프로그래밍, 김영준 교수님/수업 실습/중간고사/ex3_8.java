import java.util.Scanner;
public class ex3_8 {
	public static void main (String [] args) {
		Scanner rd = new Scanner (System.in);
		int intArr[] = new int [10];
		int sum = 0;
		
		for (int i = 0; i < intArr.length; i++) {
			intArr[i] = rd.nextInt();
			sum += intArr[i];
		}
		
		System.out.println("�迭 ������ ����� " + (sum/intArr.length) + "�Դϴ�.");
	}

}
