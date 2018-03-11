package 소공;

import java.util.*;
import javax.swing.*;
import javax.swing.border.Border;

import java.awt.*;
import java.awt.event.*;

public class 로그인문제해결 extends JFrame {
	JButton jb1;
	JTextField jt1;
	JTextArea jta;

	로그인문제해결() {
		setTitle("비밀번호 찾기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		Container contentPane =getContentPane();
		Color back =new Color(160,217,226);
		Color butt = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Font font1=new Font("Serif", Font.BOLD, 10);
		contentPane.setBackground(back);
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		
		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		JPanel jp4 = new JPanel();
		JPanel jp5 = new JPanel();
		
		
		jp1.setLocation(50, 90);
		jp1.setSize(300, 100);
		JButton jb1 = new JButton("입력");
		jb1.setBackground(butt2);
		jb1.getColorModel();
		jp1.add(jb1);
		jp1.setBackground(back);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(90,30 );
		jp2.add(new JLabel("이메일"));
		jp2.setBackground(butt);
		jp2.setBorder(bln);
		//jp2.setFont(font1);
		add(jp2);

		jp3.setLocation(130, 10);
		jp3.setSize(200, 30);
		jp3.setLayout(new GridLayout(1, 1));
		JTextField jt1 = new JTextField();
		jp3.add(jt1);
		jp3.setBackground(back);
		add(jp3);
		
		jp4.setLocation(10, 45);
		jp4.setSize(90,30 );
		jp4.add(new JLabel("아이디"));
		jp4.setBackground(butt);
		jp4.setBorder(bln);
		add(jp4);
		
		jp5.setLocation(130, 45);
		jp5.setSize(200, 30);
		jp5.setLayout(new GridLayout(1, 1));
		JTextField jt2 = new JTextField();
		jp5.add(jt2);
		jp5.setBackground(back);
		add(jp5);
		
		setSize(400, 150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new 로그인문제해결();
	}
}