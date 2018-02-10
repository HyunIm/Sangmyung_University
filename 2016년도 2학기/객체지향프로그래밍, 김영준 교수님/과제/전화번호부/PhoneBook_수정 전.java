import java.util.*;
import javax.swing.*;
import java.awt.*;

class Human { // 사람 클래스
	String tel; // 전화번호
	String adr; // 주소
	public Human (String tel, String adr) { // 사람을 표현하는 클래스
		this.tel = tel; this.adr = adr;
	}
}

public class PhoneBook extends JFrame {
	
	JButton jb1, jb2, jb3, jb4;
	JTextField jt1, jt2, jt3;
	JTextArea jta;
	
	PhoneBook() {
		setTitle("전화번호부");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		
		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		
		jp1.setLocation(460, 50);
		jp1.setSize(400, 30);
		jp1.setLayout(new GridLayout(1,4));
		JButton jb1 = new JButton("조회"); // 수정할 예정
		JButton jb2 = new JButton("검색");
		JButton jb3 = new JButton("삽입");
		JButton jb4 = new JButton("삭제");
		jp1.add(jb1);
		jp1.add(jb2);
		jp1.add(jb3);
		jp1.add(jb4);
		add(jp1);
		
		jp2.setLocation(460, 150);
		jp2.setSize(90, 80);
		jp2.setLayout(new GridLayout(3,1));
		jp2.add(new JLabel("이         름"));
		jp2.add(new JLabel("전화번호"));
		jp2.add(new JLabel("주         소"));
		add(jp2);
		
		jp3.setLocation(540, 150);
		jp3.setSize(300, 90);
		jp3.setLayout(new GridLayout(3,1));
		JTextField jt1 = new JTextField();
		JTextField jt2 = new JTextField();
		JTextField jt3 = new JTextField();
		jp3.add(jt1);
		jp3.add(jt2);
		jp3.add(jt3);
		add(jp3);
		
		JTextArea jta = new JTextArea();
		jta.setLocation(10, 10);
		jta.setSize(430, 300);
		JScrollPane js = new JScrollPane(jta);
		js.setSize(430, 300);
		add(js);
		
		setSize(900, 350);
		setVisible(true);		
	}
	
	public static void main (String [] args) {
		new PhoneBook();
		
		/* Scanner rd = new Scanner(System.in);
		// 사람 이름과 Human 객체를 쌍으로 저장하는 HashMap 컬렉션 생성
		HashMap<String, Human> map = new HashMap<String, Human> ();
		
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
				map.put(rd.next(), new Human(rd.next(), rd.next()));
			}
			
			if (num == 1) { // 삭제
				System.out.println("이름을 입력해주십시오.");
				map.remove(rd.next());
				System.out.println("삭제되었습니다.");
			}
			
			if (num == 2) { // 찾기
				System.out.println("이름을 입력해주십시오.");
				id = rd.next();
				Human human = map.get(id);
				System.out.println(id + " " + human.tel + " " + human.adr);
			}
			
			if (num == 3) {
				// 모든 사람 출력, map에 들어 있는 모든 (key, value) 쌍 출력
				// key 문자열을 가진 집합 Set 컬렉션 리턴
				Set<String> names = map.keySet();
				Vector <String> v = new Vector <String> ();
				v.addAll(names); // 벡터 안에 모든 값을 넣음
				Collections.sort(v);
				
				// key 문자열을 순서대로 접근할 수 있는 Iterator 리턴
				Iterator <String> it = v.iterator();
				while(it.hasNext()) {
					String name = it.next(); // 다음 키. 사람 이름
					Human human = map.get(name);
					System.out.println(name + " : " + human.tel + " " + human.adr);
				}
			}
			
			if (num == 4)
				break;
		}
		System.out.println("프로그램을 종료합니다..."); */
	}
}