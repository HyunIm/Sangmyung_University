import java.util.Scanner;
public class Three { // 201511054 컴퓨터과학과 임현
	public static void main (String args[]) {
		Scanner scanner = new Scanner (System.in);
		
		int money; // 입력받는 액수
		int FiftyThousand, TenThousand, OneThousand, FiveHundred, OneHundred, Fifty, Ten, One; // 오만 원, 만 원, 천 원, 500원, 100원, 50원, 10원, 1원
		money = scanner.nextInt();
		
		FiftyThousand = money / 50000;
		money %= 50000;
		TenThousand = money / 10000;
		money %= 10000;
		OneThousand = money / 1000;
		money %= 1000;
		FiveHundred = money / 500;
		money %= 500;
		OneHundred = money / 100;
		money %= 100;
		Fifty = money / 50;
		money %= 50;
		Ten = money / 10;
		money %= 10;
		One = money;
		
		System.out.println("오만 원권 " + FiftyThousand + "매, 만 원권 " + TenThousand + "매, 천 원권 " + OneThousand + "매, 500원짜리 동전 " + FiveHundred + "개, 100원짜리 동전 " + OneHundred + "개, 50원짜리 동전 " + Fifty + "개, 10원짜리 동전 " + Ten + "개, 1원짜리 동전 " + One + "개이다.");
	}
}