
public class ex4_2 {
	int width;
	int height;
	int getArea() {
		return (width * height);
	}
	public static void main (String [] args) {
		ex4_2 Rectangle = new ex4_2();
		
		Rectangle.width = 4;
		Rectangle.height = 5;
		
		System.out.println("사각형의 면적은 " + Rectangle.getArea());
	}
}
