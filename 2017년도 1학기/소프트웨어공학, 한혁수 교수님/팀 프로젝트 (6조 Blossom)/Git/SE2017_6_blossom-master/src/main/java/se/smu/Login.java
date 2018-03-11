/**
 * @title : Login.java
 * @author : 황은선 (201511077@sangmyung.kr)
 * @version : 1.5.0.
 * @since : 2017 - 05 - 29
 * @brief : 로그인 코드
 * ------------------------------
 * @history
 	author		version		date		brief
 	황은선		1.0.0.		2017-05-29	초안 작성
 	황은선	    1.0.1.		2017-05-29	주석 수정 및 코드 공백 정리
 	임현			1.0.2.		2017-05-30	history 주석 수정
 	임현			1.0.3.		2017-05-30	DB연동 시도
 	임현			1.0.4.		2017-05-31	Passward 오타 수정
 	임현			1.1.0.		2017-05-31	UI, DB, 기능 연동
 	임현			1.2.0.		2017-05-31	회원가입 연동
 	임현			1.3.0.		2017-05-31	로그인 문제 해결 구현
 	임현			1.3.1.		2017-05-31	로그인 성공/실패 조건문 작성
 	임현			1.3.2.		2017-06-03	ID가 2개일 경우 로그인 해결
 	임현			1.4.0.		2017-06-03	로그인 성공 할 시 TodoList, 실패 할 시 ErrorMessage
 	임현			1.4.1.		2017-06-04	데이터베이스 연동 수정
 	임현			1.4.2.		2017-06-04	데이터베이스 연동 수정
 	임현			1.5.0.		2017-06-05	탈퇴된 계정 복구 삭제
 * ------------------------------
 */

package se.smu;

import se.smu.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.sql.*;

public class Login extends JFrame{
	// 기본 변수 선언
	Connection conn = null;
	String sql;
	Statement st = null;
	PreparedStatement pst = null;
	ResultSet rs = null;
	
	Scanner in = new Scanner(System.in);
	static String ID;
	static String Password;
	static String InputID;
	static String InputPassword;
	static Boolean pass = false;
	
	// UI 변수 선언
	JButton jb1, jb2, jb3;
	JTextField jt;
	JPasswordField jpw;

	// 로그인 할 ID와 Password 입력받기
	public Login() {
		setTitle("회원 로그인");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		
		jp1.setLocation(10, 120);
		jp1.setSize(300, 100);
		jp1.setLayout(new GridLayout(3, 1));
		JButton jb1 = new JButton("로그인");
		JButton jb2 = new JButton("회원가입");
		JButton jb3 = new JButton("로그인 문제 해결");
		jp1.add(jb1);
		jp1.add(jb2);
		jp1.add(jb3);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(90, 80);
		jp2.setLayout(new GridLayout(2, 1));
		jp2.add(new JLabel("아이디"));
		jp2.add(new JLabel("비밀번호"));
		add(jp2);

		jp3.setLocation(70, 10);
		jp3.setSize(200, 90);
		jp3.setLayout(new GridLayout(2, 1));
		JTextField jt = new JTextField();
		JPasswordField jpw = new JPasswordField();
		jp3.add(jt);
		jp3.add(jpw);
		add(jp3);

		setSize(350, 300);
		setVisible(true);
		
		jb1.addActionListener(new ActionListener() { // 로그인
			public void actionPerformed(ActionEvent e) {
				try {
					InputID = jt.getText();
					InputPassword = new String(jpw.getPassword());
					
					// DB연동
					Class.forName(DataBaseConn.forName);
					conn = DriverManager.getConnection(DataBaseConn.URL, DataBaseConn.ID, DataBaseConn.PASSWORD);

					// 사용할 DB설정, 회원정보에서 ID와 Password불러오기
					st = conn.createStatement();
					sql = "USE MemberDB";
					st.execute(sql);
					rs = st.executeQuery("select ID,Password from MemberInfo where ID = '" + InputID + "'");

					while(rs.next()) {
					ID=rs.getString("ID");
					Password=rs.getString("Password");
					}
					
					if ((InputID.equals(ID)) && (InputPassword.equals(Password))) { // 입력한 값과 데이터베이스 값이 같은 경우
						pass = true;
						new TodoList();
						setVisible(false);
					}
					else {
						pass = false;
						new ErrorMessage();
					}
					
					System.out.println("Login " + pass); // 로그인 성공 유무 확인
					// 실행창 닫기
					rs.close();
					st.close();
				} catch (ClassNotFoundException | SQLException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		jb2.addActionListener(new ActionListener() { // 회원가입
			public void actionPerformed(ActionEvent e) {
				new Join();
			}
		});
		
		jb3.addActionListener(new ActionListener() { // 로그인 문제해결
			public void actionPerformed(ActionEvent e) {
				new LoginSolution();
			}
		});
	}

	public static void main(String[] args) {
		new Login();
	}
}
