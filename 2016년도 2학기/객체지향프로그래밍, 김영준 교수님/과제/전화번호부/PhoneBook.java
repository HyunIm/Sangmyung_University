import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Human { // 사람 클래스
	String tel; // 전화번호
	String adr; // 주소

	public Human(String tel, String adr) { // 사람을 표현하는 클래스
		this.tel = tel;
		this.adr = adr;
	}
}

public class PhoneBook extends JFrame {

	Scanner rd = new Scanner(System.in);
	HashMap<String, Human> map = new HashMap<String, Human>();
	String id;

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
		jp1.setLayout(new GridLayout(1, 4));
		JButton jb1 = new JButton("조회");
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
		jp2.setLayout(new GridLayout(3, 1));
		jp2.add(new JLabel("이         름"));
		jp2.add(new JLabel("전화번호"));
		jp2.add(new JLabel("주         소"));
		add(jp2);

		jp3.setLocation(540, 150);
		jp3.setSize(300, 90);
		jp3.setLayout(new GridLayout(3, 1));
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

		jb1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Set<String> names = map.keySet();
				Vector<String> v = new Vector<String>();
				v.addAll(names); // 벡터 안에 모든 값을 넣음
				Collections.sort(v);

				// key 문자열을 순서대로 접근할 수 있는 Iterator 리턴
				Iterator<String> it = v.iterator();
				jta.append("\n");
				while (it.hasNext()) {
					String name = it.next(); // 다음 키. 사람 이름
					Human human = map.get(name);
					jta.append(name + " : " + human.tel + " " + human.adr + "\n");
				}
				jta.append("\n");
			}
		});

		jb2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				id = jt1.getText();
				Human human = map.get(id);
				jta.append(id + " " + human.tel + " " + human.adr + "\n\n")	;
			}
		});

		jb3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				map.put(jt1.getText(), new Human(jt2.getText(), jt3.getText()));
				jta.append(jt1.getText() + " 삽입\n\n");
			}
		});

		jb4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				map.remove(jt1.getText());
				jta.append(jt1.getText() + " 삭제\n\n");
			}
		});
	}

	public static void main(String[] args) {
		new PhoneBook();
	}
}