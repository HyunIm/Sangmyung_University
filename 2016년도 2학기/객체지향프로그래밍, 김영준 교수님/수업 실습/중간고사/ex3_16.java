
public class ex3_16 {
	public static void main (String [] args) {
		String[] stringNumber = {"23", "12", "998", "3.141592"};
		try {
			for (int i = 0; i < stringNumber.length; i++) {
				int j = Integer.parseInt(stringNumber[i]);
				System.out.println("���ڷ� ��ȯ�� ���� " + j);
			}
		}
		
		catch (NumberFormatException e) {
			System.out.println("������ ��ȯ�� �� �����ϴ�.");
		}
	}
}
