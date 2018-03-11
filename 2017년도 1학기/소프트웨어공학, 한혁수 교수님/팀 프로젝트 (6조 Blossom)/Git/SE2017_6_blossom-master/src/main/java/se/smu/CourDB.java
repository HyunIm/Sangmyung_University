/**
 * @title : CourDB.java
 * @author : 황은선 (201511077@sangmyung.kr)
 * @version : 1.0.6.
 * @since : 2017 - 05 - 29
 * @brief : 과목정보 DB
 * ------------------------------
 * @history
 	author		version		date		brief
 	황은선		1.0.0.		2017-05-29	초안 작성
 	황은선	    1.0.1.		2017-05-29	주석 수정 및 코드 공백 정리
 	임현			1.0.2.		2017-05-30	history 주석 수정
 	임현			1.0.3.		2017-05-31	DB 연동
 	황은선		1.0.4.		2017-06-03	DB 중복 생성 수정
 	임현			1.0.5.		2017-06-04	데이터베이스 연동 수정
 	임현			1.0.6.		2017-06-04	데이터베이스 연동 수정
 * ------------------------------
 */

package se.smu;

import se.smu.*;
import java.sql.*;
import java.util.Scanner;

public class CourDB {
	void CourTable(String CourName, String CourProf, String CourDay, String CourTime, String CourYear,
			String CourSeme) {
		try {
			// 기본 변수 선언
			int Create_Flag = 0;
			String database;
			Scanner in = new Scanner(System.in);
			Connection conn = null;
			String sql;
			Statement st = null;
			PreparedStatement pst = null;
			ResultSet rs = null;

			// DB연동
			Class.forName(DataBaseConn.forName); // MySQL 드라이버 로드
			conn = DriverManager.getConnection(DataBaseConn.URL, DataBaseConn.ID, DataBaseConn.PASSWORD); // JDBC연결

			st = conn.createStatement();
			rs = st.executeQuery("SHOW DATABASES");

			while (rs.next()) {
				database = rs.getString("Database");
				if (database.equals("courdb"))
					Create_Flag = 1;
			}

			if (Create_Flag == 0)// 해당 DB가 없을 경우 DB생성, TABLE생성
			{
				sql = "CREATE DATABASE CourDB";
				st.execute(sql);
				sql = "USE CourDB";
				st.execute(sql);
				sql = "CREATE TABLE CourInfo (CourName char(25), CourProf char(20), CourDay char(10), CourTime char(20), CourYear char(20), CourSeme char(10))";
				st.execute(sql);
			}

			else {// 해당 DB가 존재할 경우
				sql = "USE CourDB";
				st.execute(sql);
				// 입력받은 과목정보를 DB에 삽입
				sql = "INSERT INTO CourInfo(CourName,CourProf,CourDay,CourTime,CourYear,CourSeme) values(?,?,?,?,?,?)";
				pst = conn.prepareStatement(sql);
				rs = pst.executeQuery("select CourName, CourProf, CourDay, CourTime, CourYear, CourSeme from CourInfo");
			}

			pst.setString(1, CourName);
			pst.setString(2, CourProf);
			pst.setString(3, CourDay);
			pst.setString(4, CourTime);
			pst.setString(5, CourYear);
			pst.setString(6, CourSeme);
			pst.executeUpdate();

			// 실행창 닫기
			rs.close();
			pst.close();

		} catch (ClassNotFoundException | SQLException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new CourDB();

	}
}