import java.util.Scanner;
public class Six { // 201511054 컴퓨터과학과 임현
	public static void main (String args[]) {
		Scanner scanner = new Scanner (System.in);
		
		int yy, mm, dd; // 년, 월, 일
		int day = 0; // 1900년 1월 1일 월요일 기준
		int week; // day%7
		
		yy = scanner.nextInt(); // 년, 월, 일 입력
		mm = scanner.nextInt();
		dd = scanner.nextInt();
		
		if ((yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0)) // 윤년 조건문
			System.out.println("윤년입니다.\n");
		else
			System.out.println("윤년이 아닙니다.\n");
		
		for (int i = 1900; i < yy; i++) { // 윤년 일시 +366, 아닐 시 +365
			if ((yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0))
				day += 366;
			else
				day += 365;
		}
		
		for (int i = 1; i < mm; i++) // 월 별 일 수
		{
			if ((mm == 4) || (mm == 6) || (mm == 9) || (mm == 11))
				day +=30;
			else if (mm == 2)
				day += 28;
			else
				day += 31;
		}
		
		day += dd; // 일
		
		if ((mm == 1 || mm == 2) && (yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0)) // 윤년인데 1월 2월 달 일 시 day--
			day--;
		
		week = day % 7; // day 나머지를 이용한 요일 계산
		
		switch (week) { // switch 문을 이용한 요일 출력
		case 1:
			System.out.println("월요일입니다.\n");
			break;
		case 2:
			System.out.println("화요일입니다.\n");
			break;
		case 3:
			System.out.println("수요일입니다.\n");
			break;
		case 4:
			System.out.println("목요일입니다.\n");
			break;
		case 5:
			System.out.println("금요일입니다.\n");
			break;
		case 6:
			System.out.println("토요일입니다.\n");
			break;
		case 0:
			System.out.println("일요일입니다.\n");
			break;
		}
	}
}