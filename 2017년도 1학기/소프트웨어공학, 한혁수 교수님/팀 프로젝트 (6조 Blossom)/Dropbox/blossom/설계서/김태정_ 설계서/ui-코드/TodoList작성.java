package 소공;

import javax.swing.*;
import javax.swing.border.Border;

import java.awt.*;
import java.awt.event.*;

public class TodoList작성 extends JFrame {
	JButton jb1;
	JTextField jt1, jt2, jt3;
	JTextArea jta;
	JComboBox jcb;
	JCheckBox jck1, jck2;
	
	
	TodoList작성() {
		setTitle("To do List 작성");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		Color back =new Color(160,217,226);
		Color butt1 = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Color butt3 = new Color(236,235,255);
		Container contentPane =getContentPane();
		contentPane.setBackground(back);
		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		jp1.setLocation(20, 200);
		jp1.setSize(300, 100);
		JButton jb1 = new JButton("입력");
		jb1.setBackground(butt2);
		jp1.add(jb1);
		jp1.setBackground(back);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(90, 180);
		jp2.setLayout(new GridLayout(6, 1));
		
		JLabel jl1 = new JLabel("과목 명");
		JLabel jl2 = new JLabel("To do 항목 명");
		JLabel jl3 = new JLabel("마감기한");
		JLabel jl4 = new JLabel("실제 마감일");
		JLabel jl5 = new JLabel("완료 여부");
		JLabel jl6 = new JLabel("중요 여부");
		jl1.setBorder(bln);
		jl2.setBorder(bln);
		jl3.setBorder(bln);
		jl4.setBorder(bln);
		jl5.setBorder(bln);
		jl6.setBorder(bln);
		jp2.setBackground(butt1);
		jp2.add(jl1);
		jp2.add(jl2);
		jp2.add(jl3);
		jp2.add(jl4);
		jp2.add(jl5);
		jp2.add(jl6);
		add(jp2);

		jp3.setLocation(150, 10);
		jp3.setSize(200, 180);
		jp3.setLayout(new GridLayout(6, 1));
		JComboBox jcb = new JComboBox();
		jcb.addItem("소프트웨어공학"); // 과목 추가 요망
		jcb.addItem("이산수학");
		JCheckBox jck1 = new JCheckBox(" 완료");
		JCheckBox jck2 = new JCheckBox(" 중요");
		jck1.setBackground(back);
		jck2.setBackground(back);
		JTextField jt1 = new JTextField();
		JTextField jt2 = new JTextField();
		JTextField jt3 = new JTextField();
		jp3.add(jcb);
		jp3.add(jt1);
		jp3.add(jt2);
		jp3.add(jt3);
		jp3.add(jck1);
		jp3.add(jck2);
		add(jp3);

		setSize(400, 300);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new TodoList작성();
	}
}