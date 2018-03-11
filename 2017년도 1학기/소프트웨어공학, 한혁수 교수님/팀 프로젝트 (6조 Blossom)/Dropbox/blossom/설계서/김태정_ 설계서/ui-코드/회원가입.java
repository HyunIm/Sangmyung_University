package 소공;

import java.util.*;
import javax.swing.*;
import javax.swing.border.Border;

import java.awt.*;
import java.awt.event.*;

public class 회원가입 extends JFrame {
	JButton jb1;
	JTextField jt1, jt2;
	JPasswordField jpw;
	JTextArea jta;

	회원가입() {
		setTitle("회원가입");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		Color back =new Color(160,217,226);
		Color butt1 = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Color butt3 = new Color(236,235,255);
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		Container contentPane =getContentPane();
		contentPane.setBackground(back);
		jp1.setLocation(50, 120);
		jp1.setSize(300, 100);
		JButton jb1 = new JButton("회원가입");
		jb1.setBackground(butt2);
		jp1.setBackground(back);
		jp1.add(jb1);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(90, 80);
		jp2.setLayout(new GridLayout(3, 1));
		JLabel jl1 = new JLabel("아이디");
		JLabel jl2 = new JLabel("비밀번호");
		JLabel jl3 = new JLabel("이메일");
		jl1.setBorder(bln);
		jl2.setBorder(bln);
		jl3.setBorder(bln);
		jp2.add(jl1);
		jp2.add(jl2);
		jp2.add(jl3);
		jp2.setBackground(butt1);
		add(jp2);

		jp3.setLocation(150, 10);
		jp3.setSize(200, 90);
		jp3.setLayout(new GridLayout(3, 1));
		JTextField jt1 = new JTextField();
		JTextField jt2 = new JTextField();
		JPasswordField jpw = new JPasswordField();
		jp3.add(jt1);
		jp3.add(jt2);
		jp3.add(jpw);
		add(jp3);

		setSize(400, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new 회원가입();
	}
}