package Equals;

import Circle.Circle;

public class Equals {
	public static void main (String [] args) {
		Circle a = new Circle(2);
		Circle b = new Circle(2);
		Circle c = new Circle(3);
		
		if (a.equals(b)) System.out.println("a is equal to b");
		if (a.equals(c)) System.out.println("a is eqaul to c");
		if (b.equals(c)) System.out.println("b is equal to c");
	}
}
