
public class ex3_15 {
	public static void main (String [] args) {
		int [] intArray = new int[5];
		intArray[0] = 0;
		try {
			for (int i = 0; i < 5; i++) {
				intArray[i+1] = i + 1 + intArray[i];
				System.out.println("intArray [ " + i + " ]" + " = " + intArray[i]);
			}
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("�迭�� �ε����� ������ ������ϴ�.");
		}
	}

}
