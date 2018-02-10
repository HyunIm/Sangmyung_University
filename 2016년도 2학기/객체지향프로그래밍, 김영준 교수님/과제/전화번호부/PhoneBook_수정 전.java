import java.util.*;
import javax.swing.*;
import java.awt.*;

class Human { // ��� Ŭ����
	String tel; // ��ȭ��ȣ
	String adr; // �ּ�
	public Human (String tel, String adr) { // ����� ǥ���ϴ� Ŭ����
		this.tel = tel; this.adr = adr;
	}
}

public class PhoneBook extends JFrame {
	
	JButton jb1, jb2, jb3, jb4;
	JTextField jt1, jt2, jt3;
	JTextArea jta;
	
	PhoneBook() {
		setTitle("��ȭ��ȣ��");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		
		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		
		jp1.setLocation(460, 50);
		jp1.setSize(400, 30);
		jp1.setLayout(new GridLayout(1,4));
		JButton jb1 = new JButton("��ȸ"); // ������ ����
		JButton jb2 = new JButton("�˻�");
		JButton jb3 = new JButton("����");
		JButton jb4 = new JButton("����");
		jp1.add(jb1);
		jp1.add(jb2);
		jp1.add(jb3);
		jp1.add(jb4);
		add(jp1);
		
		jp2.setLocation(460, 150);
		jp2.setSize(90, 80);
		jp2.setLayout(new GridLayout(3,1));
		jp2.add(new JLabel("��         ��"));
		jp2.add(new JLabel("��ȭ��ȣ"));
		jp2.add(new JLabel("��         ��"));
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
		// ��� �̸��� Human ��ü�� ������ �����ϴ� HashMap �÷��� ����
		HashMap<String, Human> map = new HashMap<String, Human> ();
		
		System.out.println("--------------------------------------------");
		System.out.println("��ȭ��ȣ ���� ���α׷��� �����մϴ�. ���Ϸ� �������� �ʽ��ϴ�.");
		System.out.println("--------------------------------------------");
		
		int num; // ����, ����, ã��, ��ü����, ���� ����
		String id; // �̸�
		while (true) {
			System.out.print("���� : 0. ���� : 1, ã�� : 2, ��ü���� : 3, ���� : 4 >> ");
			num = rd.nextInt();
			
			if (num == 0) {
				System.out.println("�̸�, ��ȭ��ȣ, �ּҸ� �Է����ֽʽÿ�.");
				map.put(rd.next(), new Human(rd.next(), rd.next()));
			}
			
			if (num == 1) { // ����
				System.out.println("�̸��� �Է����ֽʽÿ�.");
				map.remove(rd.next());
				System.out.println("�����Ǿ����ϴ�.");
			}
			
			if (num == 2) { // ã��
				System.out.println("�̸��� �Է����ֽʽÿ�.");
				id = rd.next();
				Human human = map.get(id);
				System.out.println(id + " " + human.tel + " " + human.adr);
			}
			
			if (num == 3) {
				// ��� ��� ���, map�� ��� �ִ� ��� (key, value) �� ���
				// key ���ڿ��� ���� ���� Set �÷��� ����
				Set<String> names = map.keySet();
				Vector <String> v = new Vector <String> ();
				v.addAll(names); // ���� �ȿ� ��� ���� ����
				Collections.sort(v);
				
				// key ���ڿ��� ������� ������ �� �ִ� Iterator ����
				Iterator <String> it = v.iterator();
				while(it.hasNext()) {
					String name = it.next(); // ���� Ű. ��� �̸�
					Human human = map.get(name);
					System.out.println(name + " : " + human.tel + " " + human.adr);
				}
			}
			
			if (num == 4)
				break;
		}
		System.out.println("���α׷��� �����մϴ�..."); */
	}
}