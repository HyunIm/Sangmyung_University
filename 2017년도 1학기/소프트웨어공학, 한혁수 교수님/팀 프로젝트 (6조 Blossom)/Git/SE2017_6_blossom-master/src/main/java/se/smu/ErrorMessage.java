/**
 * @title : ErrorMessage.java
 * @author : 임현 (201511054@sangmyung.kr)
 * @version : 1.0.0.
 * @since : 2017 - 06 - 03
 * @brief : 오류 메시지
 * ------------------------------
 * @history
 	author		version		date		brief
 	임현			1.0.0.		2017-06-03	초안 작성
 * ------------------------------
 */

package se.smu;

import java.awt.GridLayout;
import java.awt.event.*;
import javax.swing.*;

public class ErrorMessage extends JFrame {
	JButton jb;
	
	public ErrorMessage() {
		setTitle("오류 메시지");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		
		JPanel jp = new JPanel();
		
		jp.setLocation(10, 10);
		jp.setSize(200, 50);
		jp.setLayout(new GridLayout(2, 1));		
		JButton jb = new JButton("확인");
		jp.add(new JLabel("일치하는 정보가 없습니다."));
		jp.add(jb);
		add(jp);
		
		setSize(240, 120);
		setVisible(true);
		
		jb.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
			}
		});
	}
	
	public static void main(String[] args) {
		new ErrorMessage();
	}
}
