class Point {
	int x, y; // �� ���� �����ϴ� x, y ��ǥ
	void set(int x, int y) {
		this.x = x; this.y = y;
	}
	void showPoint() { // ���� ��ǥ ���
		System.out.println("(" + x + "," + y + ")");
	}
}


public class ColorPoint extends Point {
	// Point�� ��ӹ��� ColorPoint ����
	String color; // ���� ��
	void setColor (String color) {
		this.color = color;
	}
	void showColorPoint() { // �÷� ���� ��ǥ ���
		System.out.print(color);
		showPoint(); // Point Ŭ������ showPoint() ȣ��
	}
	
	public static void main (String [] args) {
		ColorPoint cp = new ColorPoint();
		cp.set(3, 4); // Point Ŭ������ set() �޼ҵ� ȣ��
		cp.setColor("red"); // �� ����
		cp.showColorPoint(); // �÷� ���� ��ǥ ���
	}

}
