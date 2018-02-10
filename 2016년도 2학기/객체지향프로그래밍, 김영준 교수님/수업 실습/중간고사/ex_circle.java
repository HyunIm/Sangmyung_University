
public class ex_circle {
	int radius;
	String name;
	double getArea() {
		return (3.14 * radius * radius);
	}
	
	public static void main (String [] args) {
		ex_circle pizza = new ex_circle();
		ex_circle donut = new ex_circle();
		
		pizza.radius = 10;
		pizza.name = "자바피자";
		donut.radius = 2;
		donut.name = "자바도넛";
		
		System.out.println(pizza.name + "의 면적은 " + pizza.getArea());
		System.out.println(donut.name + "의 면적은 " + donut.getArea());
	}

}
