package Circle;

public class Circle {
	int radius;
	public Circle(int radius) {
		this.radius = radius;
	}
	public boolean equals(Circle p) {
		if (radius == p.radius)
			return true;
		else
			return false;
	}
}
