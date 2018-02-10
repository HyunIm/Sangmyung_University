class A {
	public int p;
	private int n;
	public void setN (int n) {
		this.n = n;
	}
	public int getN() {
		return n;
	}
}

class B extends A {
	private int m;
	public void setM(int m) {
		this.m = m;
	}
	public int getM() {
		return m;
	}
	public String toString() {
		String s = getN() + " " + getM();
		return s;
	}
}


public class MemberAccesExample {
	public static void main (String [] args) {
		A a = new A();
		B b = new B();
		
		a.p = 5;
		// a.n = 5; // n은 private 멤버, 컴파일 오류 발생
		
		b.p = 5;
		// b.n = 5; // n은 private 멤버, 컴파일 오류 발생
		b.setN(10);
		int i = b.getN(); // i는 10
		
		// b.m = 20; // m은 private 멤버, 컴파일 오류 발생
		b.setM(20);
		System.out.println(b.toString());
		// 화면에 10 20이 출력됨
	}
}
