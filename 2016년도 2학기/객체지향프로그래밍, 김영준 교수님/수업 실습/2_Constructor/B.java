class A {
	int i;
	protected int pro;
	private int pri;
	public int pub;
}

public class B extends A {
	void set() {
		i = 1; // default ��� ���� ����
		pro = 2; // protected ��� ���� ����
		// pri = 3; // private ��� ���� �Ұ�, ������ ���� �߻�
		pub = 4; // public ��� ���� ����
	}
	public static void main (String [] args) {
		B b = new B();
		b.set();
	}

}
