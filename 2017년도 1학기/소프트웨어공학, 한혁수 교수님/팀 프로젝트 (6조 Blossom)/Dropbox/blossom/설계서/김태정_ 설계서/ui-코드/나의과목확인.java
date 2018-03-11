package 소공;

import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class 나의과목확인 extends JFrame {
	JButton jb1, jb2, jb3;
	JTextField jt1, jt2, jt3;
	JTable jtb;
	JComboBox jcb;
	JCheckBox jck1, jck2;

	나의과목확인() {
		setTitle("나의 과목 확인");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		Container contentPane =getContentPane();
		
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		Color back =new Color(160,217,226);
		Color butt1 = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Color butt3 = new Color(236,235,255);
		Color point = new Color(235,247,255);
		JPanel jp1 = new JPanel();
		contentPane.setBackground(back);
		
		jp1.setLocation(10, 400);
		jp1.setSize(90, 40);
		jp1.setLayout(new GridLayout(1, 2));
		JLabel jl1 = new JLabel("학점 :");
		JTextField jt1 = new JTextField();
		jp1.add(jl1);
		jp1.add(jt1);
		jp1.setBackground(back);
		add(jp1);
		
		String row[] = 
			{"과목명", "담당교수", "강의요일/시간", "수강년도/학기", "전공/교양", "학점"};
		String column[][] = 
			{
					{"소프트웨어공학", "한혁수", "월/2시", "2017-2", "전공", "3"},
					{"유닉스프로그래밍", "백윤철", "화목/2시", "2017-1", "전공", "3"}
			};
		JTable jtb = new JTable(column, row);
		jtb.setLocation(10, 20);
		jtb.setSize(700, 600);
		JScrollPane js = new JScrollPane(jtb);
		js.setBackground(point);
		js.setSize(700, 400);
		jtb.setBackground(point);
		
		add(js);

		setSize(720, 400);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new 나의과목확인();
	}
}