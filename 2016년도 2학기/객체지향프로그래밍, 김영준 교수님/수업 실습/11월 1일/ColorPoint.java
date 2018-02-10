class Point {
	int x, y; // 한 점을 구성하는 x, y 좌표
	void set(int x, int y) {
		this.x = x; this.y = y;
	}
	void showPoint() { // 점의 좌표 출력
		System.out.println("(" + x + "," + y + ")");
	}
}


public class ColorPoint extends Point {
	// Point를 상속받은 ColorPoint 선언
	String color; // 점의 색
	void setColor (String color) {
		this.color = color;
	}
	void showColorPoint() { // 컬러 점의 좌표 출력
		System.out.print(color);
		showPoint(); // Point 클래스의 showPoint() 호출
	}
	
	public static void main (String [] args) {
		ColorPoint cp = new ColorPoint();
		cp.set(3, 4); // Point 클래스의 set() 메소드 호출
		cp.setColor("red"); // 색 지정
		cp.showColorPoint(); // 컬러 점의 좌표 출력
	}

}
