import java.util.*;

public class VectorEx {
	public static void main (String [] args) {
		// 문자열만 삽입 가능한 Vector 컬렉션 생성
		Vector <String> v = new Vector <String>();
		
		// 키보드로부터 4개의 이름 입력받아 Vector에 삽입
		Scanner rd = new Scanner(System.in);
		for (int i = 0; i < 4; i++) {
			System.out.println("이름을 입력하세요>>");
			String s = rd.next(); // 키보드로부터 이름 입력
			v.add(s); // Vector 컬렉션에 삽입
		}
		
		// Vector에 들어 있는 모든 이름 출력
		for (int i = 0; i < v.size(); i++) {
			// Vector의 i 번째 문자열 얻어오기
			String name = v.get(i);
			System.out.println(name + " ");
		}
		
		// 가장 긴 이름 출력
		int longestIndex = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v.get(longestIndex).length() < v.get(i).length())
				longestIndex = i;
		}
		System.out.println("\n 가장 긴 이름은 : " + v.get(longestIndex));
	}
}
