/**
 * @title : SortList.java
 * @author : 황은선 (201511077@sangmyung.kr)
 * @version : 1.0.5.
 * @since : 2017 - 05 - 29
 * @brief : 리스트 정렬 코드
 * ------------------------------
 * @history
 	author		version		date		brief
 	황은선		1.0.0.		2017-05-29	초안 작성
 	임현			1.0.1.		2017-05-30	if문 주석 처리
 	임현			1.0.2.		2017-05-30	오타 수정
 	임현			1.0.3.		2017-05-30	brief 추가
 	임현			1.0.4.		2017-05-30	오타 수정
 	임현			1.0.5.		2017-06-04	데이터베이스 연동 수정
 * ------------------------------
 */

package se.smu;

import se.smu.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;
import java.sql.*;

public class SortList {
	public static void main(String[] args) {
			try {
				// 기본 변수 선언
				Connection conn = null;
				String sql;
				Statement st = null;
				PreparedStatement pst = null;
				ResultSet rs = null;

				// DB연동
				Class.forName(DataBaseConn.forName); // MySQL 드라이버 로드
				conn = DriverManager.getConnection(DataBaseConn.URL, DataBaseConn.ID, DataBaseConn.PASSWORD); // JDBC 연결

				// 사용할 DB설정, 회원정보에서 ID와 Password불러오기
				st = conn.createStatement();
				sql = "USE ListDB";
				st.execute(sql);
				
				/*주의: 정렬된 내용이 DB저장이 아니라 출력물에만 나타남*/
				
				/*
				if(항목명 정렬버튼을 한번클릭했을경우)
				{
					sql="SELECT ListName, DeadLine, Importance, FinishDay, Finish"
					   +"FROM ListInfo"
					   +"ORDER BY ListName asc";
				}
				else if(마감기한 정렬버튼을 한번클릭했을경우)
				{
					sql="SELECT ListName, DeadLine, Importance, FinishDay, Finish"
					   +"FROM ListInfo"
					   +"ORDER BY DeadLine asc";
				}
				else if(실제마감일 정렬버튼을 한번클릭했을경우)
				{
					sql="SELECT ListName, DeadLine, Importance, FinishDay, Finish"
					   +"FROM ListInfo"
					   +"ORDER BY FinishDay asc";
				}
				else if(완료여부 정렬버튼을 한번클릭했을경우)
				{
					sql="SELECT ListName, DeadLine, Importance, FinishDay, Finish"
					   +"FROM ListInfo"
					   +"ORDER BY Finish asc";
				}
				*/
				
				st.execute(sql);

				
				rs = st.executeQuery("select ID,Password from MemberInfo");

				// 실행창 닫기
				rs.close();
				st.close();

			} catch (ClassNotFoundException | SQLException e) {
				e.printStackTrace();
			}

		}

}
