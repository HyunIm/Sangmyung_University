/**
 * @title : DataBaseConn.java
 * @author : 임현 (201511054@sangmyung.kr)
 * @version : 1.2.2.
 * @since : 2017 - 06 - 04
 * @brief : 데이터 베이스 연동 String
 * ------------------------------
 * @history
 	author		version		date		brief
 	임현			1.0.0.		2017-06-04	초안 작성
 	임현			1.0.1.		2017-06-04	주석 오타 수정 및 주석 추가
 	임현			1.0.2.		2017-06-04	아이디, 비밀번호 추가
 	임현			1.1.0.		2017-06-04	MYSQL 다른 버전용 명령어 추가
 	임현			1.2.0.		2017-06-05	외부 MYSQL 서버 구축 자하랑 PC (H409)
 	임현			1.2.1.		2017-06-05	localhost 복구
 	임현			1.2.2.		2017-06-08	데이터베이스 변수 추가
 	임현			1.2.3.		2017-06-08	USE 추가
 * ------------------------------
 */

package se.smu;

public class DataBaseConn {
	public static String forName = "com.mysql.cj.jdbc.Driver";
	// public static String forName = "com.mysql.jdbc.Driver";
	
	// 자신의 컴퓨터로 접속
	public static String URL = "jdbc:mysql://localhost:3306/mysql?serverTimezone=UTC&useSSL=false";
	// public static String URL = "jdbc:mysql://localhost:3306/mysql?=UTC&useSSL=false";
	
	// 외부 서버(H409) 연결
	// public static String URL = "jdbc:mysql://192.168.0.35:3306/mysql?serverTimezone=UTC&useSSL=false";
	// public static String URL = "jdbc:mysql://192.168.0.35:3306/mysql?=UTC&useSSL=false";
	
	// 아이디
	public static String ID = "root";
	
	// 비밀번호
	public static String PASSWORD = "0000";
	
	public static String DATABASE = "USE BlossomDB";
}
