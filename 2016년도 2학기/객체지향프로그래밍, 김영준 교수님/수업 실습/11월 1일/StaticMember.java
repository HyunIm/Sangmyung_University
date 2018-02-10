class CurrencyConverter {
	private static double rate; // �ѱ� ��ȭ�� ���� ȯ��
	public static double toDollar(double won) {
		return won/rate; // �ѱ� ��ȭ�� �޷��� ��ȯ
	}
	public static double toKWR(double dollar) {
		return dollar * rate; // �޷��� �ѱ� ��ȭ�� ��ȯ
	}
	public static void setRate(double r) {
		rate = r; // ȯ�� ����. KWR/$1
	}
}

public class StaticMember {
	public static void main (String [] args) {
		CurrencyConverter.setRate(1121); // �̱� �޷� ȯ�� ����
		System.out.println("�鸸���� " + CurrencyConverter.toDollar(1000000) + "�޷��Դϴ�.");
		System.out.println("��޷��� " + CurrencyConverter.toKWR(100) + "���Դϴ�.");
	}

}
