
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
		pizza.name = "�ڹ�����";
		donut.radius = 2;
		donut.name = "�ڹٵ���";
		
		System.out.println(pizza.name + "�� ������ " + pizza.getArea());
		System.out.println(donut.name + "�� ������ " + donut.getArea());
	}

}
