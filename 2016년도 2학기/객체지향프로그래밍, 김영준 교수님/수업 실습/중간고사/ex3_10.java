
public class ex3_10 {
	public static void main (String [] args) {
		int arr[][] = {{90, 90, 110, 110}, {120, 110, 100, 110}, {120, 140, 130, 150}};
		double sum = 0;
		
		for (int i = 0; i < arr.length; i++)
			for (int j = 0; j < arr[i].length; j++)
			sum += arr[i][j];
			
			System.out.println("지난 3년간 매출 총액은 " + sum + "이며 연평균 매출은 " + sum/arr.length + "입니다.");	
		}
	}
