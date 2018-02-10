import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Human { // ��� Ŭ����
	String tel; // ��ȭ��ȣ
	String adr; // �ּ�

	public Human(String tel, String adr) { // ����� ǥ���ϴ� Ŭ����
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
		setTitle("��ȭ��ȣ��");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();

		jp1.setLocation(460, 50);
		jp1.setSize(400, 30);
		jp1.setLayout(new GridLayout(1, 4));
		JButton jb1 = new JButton("��ȸ");
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
		jp2.setLayout(new GridLayout(3, 1));
		jp2.add(new JLabel("��         ��"));
		jp2.add(new JLabel("��ȭ��ȣ"));
		jp2.add(new JLabel("��         ��"));
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
				v.addAll(names); // ���� �ȿ� ��� ���� ����
				Collections.sort(v);

				// key ���ڿ��� ������� ������ �� �ִ� Iterator ����
				Iterator<String> it = v.iterator();
				jta.append("\n");
				while (it.hasNext()) {
					String name = it.next(); // ���� Ű. ��� �̸�
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
				jta.append(jt1.getText() + " ����\n\n");
			}
		});

		jb4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				map.remove(jt1.getText());
				jta.append(jt1.getText() + " ����\n\n");
			}
		});
	}

	public static void main(String[] args) {
		new PhoneBook();
	}
}