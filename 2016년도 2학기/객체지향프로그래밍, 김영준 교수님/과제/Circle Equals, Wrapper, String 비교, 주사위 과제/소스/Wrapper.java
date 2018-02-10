import java.util.Scanner;

public class Wrapper {
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		Integer arr[] = new Integer [10];
		int sum = 0;
		
		for (int i = 0; i < 10; i++) {
			arr[i] = rd.nextInt();
			sum += arr[i];
		}
		System.out.print("arr [10] = ");
		for (int i = 0; i < 10; i ++)
			System.out.print(arr[i] + " ");
		System.out.println(" ");
		System.out.println("sum = " + sum);
	}
}
