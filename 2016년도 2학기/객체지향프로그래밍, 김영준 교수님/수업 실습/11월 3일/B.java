class A {
	int i;
	protected int pro;
	private int pri;
	public int pub;
}

public class B extends A {
	void set() {
		i = 1; // default 멤버 접근 가능
		pro = 2; // protected 멤버 접근 가능
		// pri = 3; // private 멤버 접근 불가, 컴파일 오류 발생
		pub = 4; // public 멤버 접근 가능
	}
	public static void main (String [] args) {
		B b = new B();
		b.set();
	}

}
