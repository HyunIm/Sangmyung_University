
public class Circle {
	int radius;
	
	public Circle() {this.radius = 1;}
	public Circle(int radius) {
		this.radius = radius;
	}
	
	double getArea() {
		return 3.14 * this.radius * this.radius;
	}
	
	public static void main (String [] args) {
		Circle a = new Circle();
		
		System.out.println(a);
	}
}
