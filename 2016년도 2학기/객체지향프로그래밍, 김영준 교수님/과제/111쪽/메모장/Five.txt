import java.util.Scanner;
public class Five { // 201511054 컴퓨터과학과 임현
	public static void main (String args[]) {
		Scanner scanner = new Scanner (System.in);
		
		int x, y, z; // 정수 3개
		int temp; // 두 정수를 바꾸기 위한 변수
		
		x = scanner.nextInt();
		y = scanner.nextInt();
		z = scanner.nextInt();
		
		if (x < y) { // 가장 큰 값을 z로 하기 위한 조건문
			temp = x;
			x = y;
			y = temp;
		}
		if (x > z) {
			temp = x;
			x = z;
			z = temp;
		}
		
		if (x + y > z) { // 삼각형이 되기 위한 조건
			if (x == y && y == z && z == x)
				System.out.println("정삼각형입니다.");
			else if (x == y || y == z || z == x)
				System.out.println("이등변삼각형입니다.");
			else if (x * x + y * y == z * z)
				System.out.println("직각삼각형입니다.");
			else
				System.out.println("일반삼각형입니다.");
		}
		else
			System.out.println("삼각형이 될 수 없습니다.");
	}
}