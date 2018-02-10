import java.util.*;

class Student {
	String tel;
	String adr; // 주소
	public Student (String tel, String adr) { // 학생을 표현하는 클래스
		this.tel = tel; this.adr = adr;
	}
}

public class HashMapStudent {
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		// 학생 이름과 Student 객체를 쌍으로 저장하는 HashMap 컬렉션 생성
		HashMap<String, Student> map = new HashMap<String, Student> ();
		
		System.out.println("--------------------------------------------");
		System.out.println("전화번호 관리 프로그램을 시작합니다. 파일로 저장하지 않습니다.");
		System.out.println("--------------------------------------------");
		
		int num; // 삽입, 삭제, 찾기, 전체보기, 종료 변수
		String id; // 이름
		while (true) {
			System.out.print("삽입 : 0. 삭제 : 1, 찾기 : 2, 전체보기 : 3, 종료 : 4 >> ");
			num = rd.nextInt();
			
			if (num == 0) {
				System.out.println("이름, 전화번호, 주소를 입력해주십시오.");
				map.put(rd.next(), new Student(rd.next(), rd.next()));
			}
			
			if (num == 1) { // 삭제
				System.out.println("이름을 입력해주십시오.");
				map.remove(rd.next());
				System.out.println("삭제되었습니다.");
			}
			
			if (num == 2) { // 찾기
				System.out.println("이름을 입력해주십시오.");
				id = rd.next();
				Student student = map.get(id);
				System.out.println(id + " " + student.tel + " " + student.adr);
			}
			
			if (num == 3) {
				// 모든 학생 출력, map에 들어 있는 모든 (key, value) 쌍 출력
				// key 문자열을 가진 집합 Set 컬렉션 리턴
				Set<String> names = map.keySet();
				Vector <String> v = new Vector <String> ();
				v.addAll(names); // 벡터 안에 모든 값을 넣음
				Collections.sort(v);
				
				// key 문자열을 순서대로 접근할 수 있는 Iterator 리턴
				Iterator <String> it = v.iterator();
				while(it.hasNext()) {
					String name = it.next(); // 다음 키. 학생 이름
					Student student = map.get(name);
					System.out.println(name + " : " + student.tel + " " + student.adr);
				}
			}
			
			if (num == 4)
				break;
		}
		System.out.println("프로그램을 종료합니다...");
	}
}

/*int num; // 몇 명 받을건지
System.out.println("학생을 몇 명 입력할 것 인지 입력해주십시오.");
num = rd.nextInt();

System.out.println("학생 이름, 전화번호, 주소를 순서대로 입력해주십시오.");
for (int i = 0; i < num; i++) // 학생 정보 입력*/
