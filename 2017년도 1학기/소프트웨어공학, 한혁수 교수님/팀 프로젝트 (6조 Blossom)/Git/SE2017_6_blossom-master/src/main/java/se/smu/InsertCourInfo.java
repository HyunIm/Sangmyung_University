/**
 * @title : InsertCourInfo.java
 * @author : 황은선 (201511077@sangmyung.kr)
 * @version : 1.1.1.
 * @since : 2017 - 05 - 29
 * @brief : 과목정보 입력 코드
 * ------------------------------
 * @history
 	author		version		date		brief
 	황은선		1.0.0.		2017-05-29	초안 작성
 	황은선	    1.0.1.		2017-05-29	주석 수정 및 코드 공백 정리
 	임현			1.0.2.		2017-05-30	history 주석 수정
 	임현			1.1.0.		2017-06-03	UI 구현 및 기능 연동
 	임현			1.1.1.		2017-06-03	버튼 누를시 UI invisible
 * ------------------------------
 */

package se.smu;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.sql.*;
import se.smu.CourDB;

public class InsertCourInfo extends JFrame{
	// 기본 변수 선언
	static String CourName;
	static String CourProf;
	static String CourDay;
	static String CourTime;
	static String CourYear;
	static String CourSeme;
	
	JButton jb1;
	JTextField jt1, jt2, jt3, jt4, jt5, jt6;

	// 과목정보 입력받기
	public InsertCourInfo() {
		setTitle("수강과목등록");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();

		jp1.setLocation(10, 220);
		jp1.setSize(300, 100);
		JButton jb1 = new JButton("입력");
		jp1.add(jb1);
		add(jp1);

		jp2.setLocation(10, 10);
		jp2.setSize(90, 180);
		jp2.setLayout(new GridLayout(6, 1));
		jp2.add(new JLabel("과목 명"));
		jp2.add(new JLabel("담당 교수"));
		jp2.add(new JLabel("강의 요일"));
		jp2.add(new JLabel("강의 시간"));
		jp2.add(new JLabel("수강 년도"));
		jp2.add(new JLabel("수강 학기"));
		add(jp2);

		jp3.setLocation(150, 10);
		jp3.setSize(200, 190);
		jp3.setLayout(new GridLayout(6, 1));
		JTextField jt1 = new JTextField();
		JTextField jt2 = new JTextField();
		JTextField jt3 = new JTextField();
		JTextField jt4 = new JTextField();
		JTextField jt5 = new JTextField();
		JTextField jt6 = new JTextField();
		jp3.add(jt1);
		jp3.add(jt2);
		jp3.add(jt3);
		jp3.add(jt4);
		jp3.add(jt5);
		jp3.add(jt6);
		add(jp3);

		setSize(400, 300);
		setVisible(true);
		
		jb1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CourName = jt1.getText();
				CourProf = jt2.getText();
				CourDay = jt3.getText();
				CourTime = jt4.getText();
				CourYear = jt5.getText();
				CourSeme = jt6.getText();
				
				CourDB courdb = new CourDB();
				courdb.CourTable(CourName, CourProf, CourDay, CourTime, CourYear, CourSeme);
				setVisible(false);
			}
		});
	}

	public static void main(String[] args) {
		new InsertCourInfo();
	}
}