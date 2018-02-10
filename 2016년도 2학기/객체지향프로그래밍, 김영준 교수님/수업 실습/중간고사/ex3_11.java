
public class ex3_11 {
	public static void main (String [] args) {
		int arr[][] = new int [4][];
		arr[0] = new int [3];
		arr[1] = new int [2];
		arr[2] = new int [3];
		arr[3] = new int [2];
		
		for (int i = 0; i < arr.length; i++)
			for (int j = 0; j < arr.length; j++)
				arr[i][j] = (i+1) * 10 + j;
		
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
	}
}
