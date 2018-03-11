/**
 * @title : MailSend.java
 * @author : 임현 (201511054@sangmyung.kr)
 * @version : 1.0.0.
 * @since : 2017 - 05 - 31
 * @brief : 메일을 보내는 소스 코드
 * ------------------------------
 * @history
 	author		version		date		brief
 	임현			1.0.0.		2017-05-31	초안 작성
 * ------------------------------
 */

package se.smu;

import java.util.*;
import javax.mail.*;
import javax.mail.internet.*;

public class MailSend {
	public static void main(String[] args) {

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
			message.setFrom(new InternetAddress("Jelect.mail@gmail.com"));
			message.setRecipients(Message.RecipientType.TO,
				InternetAddress.parse("hyunzion@naver.com"));
			message.setSubject("Testing Subject");
			message.setText("Dear Mail Crawler,"
				+ "\n\n No spam to my email, please!");

			Transport.send(message);

			System.out.println("Done");

		} catch (MessagingException e) {
			throw new RuntimeException(e);
		}
	}
}