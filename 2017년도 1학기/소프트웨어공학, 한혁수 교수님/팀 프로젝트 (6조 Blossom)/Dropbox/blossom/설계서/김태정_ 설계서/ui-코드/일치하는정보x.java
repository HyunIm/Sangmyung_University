package 소공;

import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

import org.omg.PortableInterceptor.NON_EXISTENT;

public class 일치하는정보x extends JFrame {
	JButton jb1;
	JTextField jt1, jt2;
	JPasswordField jpw;
	JTextArea jta;

	일치하는정보x() {
		setTitle(" 오류");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);

		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		//Color oback =new Color(206,242,121);
		Color butt1 = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Color butt3 = new Color(236,235,255);
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		Container contentPane =getContentPane();
		//contentPane.setBackground(oback);
		jp1.setLocation(50, 50);
		jp1.setSize(300, 100);
		
		JLabel jb1 = new JLabel("일치하는 정보가 없습니다");
		ImageIcon img=new ImageIcon("image/dear.gif");
		JButton j = new JButton("확인");
		j.setBackground(butt2);
		jp1.add(jb1);
		jp2.setLocation(180,90);
		jp2.setSize(40,40);
		jp2.add(j);
		this.setIconImage(img.getImage());
		add(jp1);
		add(jp2);



		setSize(400, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new 일치하는정보x();
	}
}