/**
 * @title : ShowCour.java
 * @author : 임현 (201511054@sangmyung.kr)
 * @version : 1.0.0.
 * @since : 2017 - 06 - 06
 * @brief : 과목 정보 표시
 * ------------------------------
 * @history
 	author		version		date		brief
 	임현			1.0.0.		2017-06-06	초안 작성
 	임현			1.0.1.		2017-06-06	확인 버튼 등록
 * ------------------------------
 */

package se.smu;

import se.smu.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.table.*;

public class ShowCour extends JFrame {
	JTable jtb;
	JButton jb;
	
	ShowCour() {
		
		setTitle("과목 정보");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		
		// 기본 변수 선언
		String row[]={"  B l o s s o m", "과목 명", "담당 교수", "강의 요일", "강의 시간", "수강 년도", "수강 학기"};
		Connection conn = null;
		String sql;
		String str=null;
		Statement st = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		DefaultTableModel model = new DefaultTableModel(row, 0);
		int i;

		try{
			// DB연동
			Class.forName(DataBaseConn.forName);
			conn = DriverManager.getConnection(DataBaseConn.URL, DataBaseConn.ID, DataBaseConn.PASSWORD);

			// 사용할 DB설정, 리스트 정보 불러오기
			st = conn.createStatement();
			sql = "USE CourDB";
			st.execute(sql);
			rs = st.executeQuery("select * from Courinfo");
			
			while(rs.next())
			{
				for(i = 1; i < 7; i++)
				{
					row[i]=rs.getString(i);
				}
				model.addRow(row);
			}
			rs.close();
			st.close();
		}
		catch (ClassNotFoundException | SQLException e1) {
			e1.printStackTrace();
		}
		
		// 테이블 첫번째 값 해결 가능 시 해결 요망
		JTable jtb = new JTable(model);
		jtb.setLocation(10, 10);;
		jtb.setSize(700, 340);
		JScrollPane js = new JScrollPane(jtb);
		js.setSize(700, 340);
		add(js);
		JButton jb = new JButton("확인");
		jb.setLocation(710, 30);
		jb.setSize(80, 50);
		add(jb);
		
		setSize(820, 400);
		setVisible(true);
		
		jb.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);				
			}
		});
	}
	
	public static void main(String[] args) {
		new ShowCour();
	}
}
