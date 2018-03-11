package 소공;

import java.util.*;
import javax.swing.*;
import javax.swing.border.Border;

import java.awt.*;
import java.awt.event.*;

public class 수강과목등록 extends JFrame {
	JButton jb1;
	JTextField jt1, jt2, jt3, jt4;
	JTextArea jta;
	
	수강과목등록() {
		setTitle("수강과목등록");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		JPanel jp4 = new JPanel();
		
		Color back =new Color(160,217,226);
		Color butt1 = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Color butt3 = new Color(236,235,255);
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		Container contentPane =getContentPane();
		contentPane.setBackground(back);
		
		jp1.setLocation(10, 120);
		jp1.setSize(300, 100);
		JButton jb1 = new JButton("입력");
		jb1.setBackground(butt2);
		jp1.add(jb1);
		jp1.setBackground(back);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(110, 100);
		jp2.setLayout(new GridLayout(5, 1));
	
		JLabel jl1 = new JLabel("  과목 명");
		JLabel jl2 = new JLabel("  담당 교수");
		JLabel jl3 = new JLabel("  강의 요일/시간");
		JLabel jl4 = new JLabel("  수강 년도/학기");
		JLabel jl5 = new JLabel("  학점");
		jl1.setBorder(bln);
		jl2.setBorder(bln);
		jl3.setBorder(bln);
		jl4.setBorder(bln);
		jl5.setBorder(bln);
		jp2.add(jl1);
		jp2.add(jl2);
		jp2.add(jl5);
		jp2.add(jl3);
		jp2.add(jl4);
		
		
		jp2.setBackground(butt1);
		add(jp2);

		jp3.setLocation(150, 10);
		jp3.setSize(200, 60);
		jp3.setLayout(new GridLayout(3, 1));
		JTextField jt1 = new JTextField();
		JTextField jt2 = new JTextField();
		JTextField jt3 = new JTextField();
		JTextField jt4 = new JTextField();
		jp3.add(jt1);
		jp3.add(jt2);
		jp3.add(jt3);
		add(jp3);
		
		JComboBox jcb1 = new JComboBox();
		JComboBox jcb2 = new JComboBox();
		JComboBox jcb3 = new JComboBox();
		JComboBox jcb4 = new JComboBox();
		
		jcb1.addItem("1학기");
		jcb1.addItem("2학기");
		
		jcb2.addItem("2017 년");
		jcb2.addItem("2018 년");
		jcb2.addItem("2019 년");
		
		jcb3.addItem("월요일");
		jcb3.addItem("화요일");
		jcb3.addItem("수요일");
		jcb3.addItem("목요일");
		jcb3.addItem("금요일");
		jcb3.addItem("토요일");
		jcb3.addItem("일요일");

		jcb4.addItem("1 시");
		jcb4.addItem("2 시");
		jcb4.addItem("3 시");
		jcb4.addItem("4 시");
		jcb4.addItem("5 시");
		jcb4.addItem("6 시");
		jcb4.addItem("7 시");
		jcb4.addItem("8 시");
		jcb4.addItem("9 시");
		jcb4.addItem("10 시");
		jcb4.addItem("11 시");
		jcb4.addItem("12 시");
		jcb4.addItem("13 시");
		jcb4.addItem("14 시");
		jcb4.addItem("15 시");
		jcb4.addItem("16 시");
		jcb4.addItem("17 시");
		jcb4.addItem("18 시");
		jcb4.addItem("19 시");
		jcb4.addItem("20 시");
		jcb4.addItem("21 시");
		jcb4.addItem("21 시");
		jcb4.addItem("22 시");
		jcb4.addItem("23 시");
		jcb4.addItem("24 시");
		
		jp4.setBackground(butt3);
		jp4.setLocation(150, 70);
		jp4.setSize(200, 40);
		jp4.setLayout(new GridLayout(2, 2));
		jp4.add(jcb3);
		jp4.add(jcb4);
		jp4.add(jcb2);
		jp4.add(jcb1);
		add(jp4);
		
		setSize(400, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new 수강과목등록();
	}
}