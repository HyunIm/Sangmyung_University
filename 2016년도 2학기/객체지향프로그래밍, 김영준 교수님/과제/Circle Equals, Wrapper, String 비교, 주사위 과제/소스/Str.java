// -------------------------------------------------------
// 사용자로부터 문자열 2개를 읽어서, 이퀄스 메소드를 이용해서 같은 지 체크하고, 
// 컴페어투 메소드를 사용하여 어느 문자열이 앞으로 나오는지 출력하는 프로그램
// 201511054 컴퓨터과학과 임현
// -------------------------------------------------------

import java.util.Scanner;

public class Str {
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		
		String s1 = rd.next(); // 문자열 2개를 받습니다.
		String s2 = rd.next();
		
		if (s1.equals(s2)) // 두 문자열이 같은 지 확인합니다.
			System.out.println("두 문자열이 같습니다.");
		else {
			int res = s1.compareTo(s2); // compareTo를 이용하여 비교합니다.
			if (res < 0)
				System.out.println(s1 + " < " + s2);
			else if (res > 0)
				System.out.println(s1 + " > " + s2);
		}
	}
}