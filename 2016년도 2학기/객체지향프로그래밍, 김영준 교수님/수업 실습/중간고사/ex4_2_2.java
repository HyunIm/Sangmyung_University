
public class ex4_2_2 {
	int base;
	int exp;
	int getValue() {
		int res = 1;
		for (int i = 0; i < exp; i++)
			res = res * base;
		return res;
	}
	
	public static void main (String [] args) {
		ex4_2_2 number1 = new ex4_2_2();
		ex4_2_2 number2 = new ex4_2_2();
		
		number1.base = 2;
		number1.exp = 3;
		number2.base = 3;
		number2.exp = 4;
		
		System.out.println(number1.getValue());
		System.out.println(number2.getValue());
	}

}
