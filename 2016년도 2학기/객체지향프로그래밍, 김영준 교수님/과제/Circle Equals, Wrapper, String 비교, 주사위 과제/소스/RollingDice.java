// -------------------------------------------------------
// 주사위 2개를 만든 다음에, 사용자한테 주사위 2개를 몇 번 던지냐고 물어본 후,
// 던졌을 때 첫 번째 주사위 값, 두 번째 주사위 값, 그리고 합을 출력하고,
// 각각 합이 몇 개 인지 출력하는 프로그램
// 201511054 컴퓨터과학과 임현
// -------------------------------------------------------

import java.util.Scanner;

public class RollingDice { // 주사위 굴리기
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		Dice dice1, dice2; // 주사위 2개 생성
		int sum; // 두 주사위의 합
		int num; // 몇 번 던질 것 인지
		int count [] = new int [13]; // 두 주사위의 합인 2 ~ 12
		
		dice1 = new Dice();
		dice2 = new Dice();
		
		num = rd.nextInt(); // 몇 번 던질 것 인지 입력
		
		for (int i = 0; i < num; i++) { // num번 던지기
			dice1.roll(); // 주사위 던지기
			dice2.roll();
			sum = dice1.getFaceValue() + dice2.getFaceValue(); // 두 주사위 합
			
			System.out.println("첫 번째 주사위 : " + dice1 + ", 두 번째 주사위 : " + dice2 + ", 합 : " + sum);
			
			count[sum]++; // 합에 해당되는 값의 배열을 증가
		}
		
		for (int i = 2; i < 13; i++) {
			System.out.print("합 " + i + " : " + count[i] + "개, ");
		}
	}

}