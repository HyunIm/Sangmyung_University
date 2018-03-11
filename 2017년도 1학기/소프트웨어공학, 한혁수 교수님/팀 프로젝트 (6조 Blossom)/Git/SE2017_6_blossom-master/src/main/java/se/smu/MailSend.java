/**
 * @title : MailSend.java
 * @author : 임현 (201511054@sangmyung.kr)
 * @version : 1.0.2.
 * @since : 2017 - 05 - 31
 * @brief : 메일을 보내는 소스 코드
 * ------------------------------
 * @history
 	author		version		date		brief
 	임현			1.0.0.		2017-05-31	초안 작성
 	임현			1.0.1.		2017-06-04	데이터베이스 연동 수정
 	임현			1.0.2.		2017-06-04	데이터베이스 연동 수정
 * ------------------------------
 */

package se.smu;

import se.smu.*;
import java.sql.*;
import java.util.*;
import javax.mail.*;
import javax.mail.internet.*;

public class MailSend {	
	static String usermail;
	
	public MailSend(String usermail) {
		this.usermail = usermail;
		
		String ID = "이메일에 해당하는 아이디가 없습니다."; // 초기 값 (이메일이 없을 경우 초기 값 전송)
		String Password = null;
		
		try {
			
			Connection conn = null;
			String sql;
			Statement st = null;
			ResultSet rs = null;
			String cmd = null;
			
			// 데이터 베이스 연동
			Class.forName(DataBaseConn.forName);
			conn = DriverManager.getConnection(DataBaseConn.URL, DataBaseConn.ID, DataBaseConn.PASSWORD);
			
			st = conn.createStatement();
			sql = "USE MemberDB";
			st.execute(sql);
			cmd = ("select ID, Password from MemberInfo where email = '" + this.usermail + "'");
			rs = st.executeQuery(cmd); // 이메일로 데이터베이스 검색
			
			while(rs.next()) {
				ID=rs.getString("ID");
				Password=rs.getString("Password");
				}

			rs.close();
			st.close();
		} catch (ClassNotFoundException | SQLException e1) {
			e1.printStackTrace();
		}

		final String username = "Jelect.mail@gmail.com";
		final String password = "wkqkapdlf";

		Properties props = new Properties();
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.starttls.enable", "true");
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.port", "587");

		Session session = Session.getInstance(props,
		  new javax.mail.Authenticator() {
			protected PasswordAuthentication getPasswordAuthentication() {
				return new PasswordAuthentication(username, password);
			}
		  });

		try {
			Message message = new MimeMessage(session);
			message.setFrom(new InternetAddress("Blossom")); // 발신자
			message.setRecipients(Message.RecipientType.TO,
				InternetAddress.parse(this.usermail)); // 수신자
			message.setSubject("[Blossom] To do list 비밀번호 안내"); // 메일 제목
			message.setText( // 메일 내용
				"<6조 Blossom의 To do list 프로그램>" 
			+ "\nID : " + ID + "\nPassword : " + Password
			+ "\n\n기타 문의 사항이 있으시다면 (hyunzion@gmail.com)으로 연락바랍니다.");

			Transport.send(message);

			System.out.println("Done");

		} catch (MessagingException e) {
			throw new RuntimeException(e);
		}
	}

	public static void main(String[] args) {		
		new MailSend(usermail);
	}
}