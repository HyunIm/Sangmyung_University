/**
 * @title : LoginSolution.java
 * @author : 임현 (201511054@sangmyung.kr)
 * @version : 1.0.0.
 * @since : 2017 - 05 - 31
 * @brief : 로그인 문제 해결 코드
 * ------------------------------
 * @history
 	author		version		date		brief
 	임현			1.0.0.		2017-05-31	초안 작성
 * ------------------------------
 */

package se.smu;

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import se.smu.*;

public class LoginSolution extends JFrame{
	String usermail;
	JButton jb1;
	JTextField jt1;

	LoginSolution() {
		setTitle("로그인문제해결");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();

		jp1.setLocation(50, 60);
		jp1.setSize(300, 100);
		JButton jb1 = new JButton("입력");
		jp1.add(jb1);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(90, 80);
		jp2.add(new JLabel("이메일"));
		add(jp2);

		jp3.setLocation(150, 10);
		jp3.setSize(200, 30);
		jp3.setLayout(new GridLayout(1, 1));
		JTextField jt = new JTextField();
		jp3.add(jt);
		add(jp3);

		setSize(400, 150);
		setVisible(true);
		
		jb1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				usermail = jt.getText(); // 텍스트 필드에 있는 값을 가져옴
				new MailSend(usermail); // user의 mail에 메일 전송
				setVisible(false);
			}
		});
	}
	
	public static void main(String[] args) {
		new LoginSolution();
	}
}