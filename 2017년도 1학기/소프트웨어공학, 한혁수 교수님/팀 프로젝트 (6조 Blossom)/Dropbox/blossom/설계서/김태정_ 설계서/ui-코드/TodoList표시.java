package 소공;

import java.util.*;
import javax.swing.*;
import javax.swing.border.Border;

import java.awt.*;
import java.awt.event.*;

public class TodoList표시 extends JFrame {
	JButton jb1, jb2, jb3;
	JTextField jt1, jt2, jt3;
	JTable jtb;
	JComboBox jcb;
	JCheckBox jck1, jck2;

	TodoList표시() {
		setTitle("To do List 표시");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		Container contentPane =getContentPane();
		Border bln;
		bln=BorderFactory.createLineBorder(Color.DARK_GRAY);
		
		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		JPanel jp4 = new JPanel();
		JPanel jp5 = new JPanel();
		JPanel jp6 = new JPanel();
		Color back =new Color(160,217,226);
		Color butt1 = new Color(255,255,233);
		Color butt2 = new Color(217, 229, 255);
		Color butt3 = new Color(236,235,255);
		//Color point = new Color(255,255,251);
		Color point = new Color(235,247,255);
		contentPane.setBackground(back);
		
		ImageIcon blo = new ImageIcon("Downloads/상사슴2.PNG");
		JLabel label=new JLabel(blo);
		//contentPane.add(label);
		
		jp1.setLocation(740,270);
		jp1.setSize(400, 30);
		jp1.setLayout(new GridLayout(1, 3));
		JButton jb1 = new JButton("추가");
		JButton jb2 = new JButton("변경");
		JButton jb3 = new JButton("삭제");
		jb1.setBackground(butt2);
		jb2.setBackground(butt2);
		jb3.setBackground(butt2);
		jp1.add(jb1);
		jp1.add(jb2);
		jp1.add(jb3);
		
		add(jp1);
		
		jp4.setLocation(790,330);
		jp4.setSize(300, 30);
		jp4.setLayout(new GridLayout(1, 2));
		JButton jb4 = new JButton("과목등록");
		JButton jb5 = new JButton("나의과목확인");
		jb4.setBackground(butt3);
		jb5.setBackground(butt3);
		jp4.add(jb4);
		jp4.add(jb5);
		
		add(jp4);
		
		jp2.setLocation(740, 50);
		jp2.setSize(90, 180);
		jp2.setLayout(new GridLayout(6, 1));
		JLabel jl1 = new JLabel("과목 명");
		JLabel jl2 = new JLabel("To do 항목 명");
		JLabel jl3 = new JLabel("마감기한");
		JLabel jl4 = new JLabel("실제 마감일");
		JLabel jl5 = new JLabel("완료 여부");
		JLabel jl6 = new JLabel("중요 여부");
		jl1.setBorder(bln);
		jl2.setBorder(bln);
		jl3.setBorder(bln);
		jl4.setBorder(bln);
		jl5.setBorder(bln);
		jl6.setBorder(bln);
		
		jp2.add(jl1);
		jp2.add(jl2);
		jp2.add(jl5);
		jp2.add(jl6);
		jp2.add(jl4);
		jp2.add(jl3);
		jp2.setBackground(butt1);
		add(jp2);
		
		jp3.setBackground(back);
		jp3.setLocation(860, 50);
		jp3.setSize(200, 120);
		jp3.setLayout(new GridLayout(4, 1));
		JComboBox jcb1 = new JComboBox();
	
		jcb1.addItem("소프트웨어공학"); // 과목 추가 요망

		JCheckBox jck1 = new JCheckBox(" 중요");
		JCheckBox jck2 = new JCheckBox(" 완료");
		jck2.setBackground(back);
		JSlider jslide = new JSlider(1, 5, 1);
		jslide.setPaintTicks(true);
		jslide.setPaintTicks(true);
		jslide.setMajorTickSpacing(1);
		jslide.setBackground(back);
		JTextField jt1 = new JTextField();
		JTextField jt2 = new JTextField();
		JTextField jt3 = new JTextField();
		jp3.add(jcb1);
		jp3.add(jt1);
		jp3.add(jck2);
		jp3.add(jslide);
		add(jp3);
		//날짜 넣기 
		JComboBox jcb2 = new JComboBox();
		JComboBox jcb3 = new JComboBox();
		JComboBox jcb4 = new JComboBox();
		JComboBox jcb5 = new JComboBox();
		JComboBox jcb6 = new JComboBox();
		JComboBox jcb7 = new JComboBox();
		
		jcb2.addItem("2017 년");
		jcb2.addItem("2018 년");
		jcb2.addItem("2019 년");
		
		jcb3.addItem("1 월");
		jcb3.addItem("2 월");
		jcb3.addItem("3 월");
		jcb3.addItem("4 월");
		jcb3.addItem("5 월");
		jcb3.addItem("6 월");
		jcb3.addItem("7 월");
		jcb3.addItem("8 월");
		jcb3.addItem("9 월");
		jcb3.addItem("10 월");
		jcb3.addItem("11 월");
		jcb3.addItem("12 월");
		
		jcb4.addItem("1 시");
		jcb4.addItem("2 시");
		jcb4.addItem("3 시");
		jcb4.addItem("4 시");
		jcb4.addItem("5 시");
		jcb4.addItem("6 시");
		jcb4.addItem("7 시");
		jcb4.addItem("8 시");
		jcb4.addItem("9 시");
		jcb4.addItem("10 시");
		jcb4.addItem("11 시");
		jcb4.addItem("12 시");
		jcb4.addItem("13 시");
		jcb4.addItem("14 시");
		jcb4.addItem("15 시");
		jcb4.addItem("16 시");
		jcb4.addItem("17 시");
		jcb4.addItem("18 시");
		jcb4.addItem("19 시");
		jcb4.addItem("20 시");
		jcb4.addItem("21 시");
		jcb4.addItem("21 시");
		jcb4.addItem("22 시");
		jcb4.addItem("23 시");
		jcb4.addItem("24 시");
		

		jcb5.addItem("2017 년");
		jcb5.addItem("2018 년");
		jcb5.addItem("2019 년");
		
		jcb6.addItem("1 월");
		jcb6.addItem("2 월");
		jcb6.addItem("3 월");
		jcb6.addItem("4 월");
		jcb6.addItem("5 월");
		jcb6.addItem("6 월");
		jcb6.addItem("7 월");
		jcb6.addItem("8 월");
		jcb6.addItem("9 월");
		jcb6.addItem("10 월");
		jcb6.addItem("11 월");
		jcb6.addItem("12 월");
	
		jcb7.addItem("1 시");
		jcb7.addItem("2 시");
		jcb7.addItem("3 시");
		jcb7.addItem("4 시");
		jcb7.addItem("5 시");
		jcb7.addItem("6 시");
		jcb7.addItem("7 시");
		jcb7.addItem("8 시");
		jcb7.addItem("9 시");
		jcb7.addItem("10 시");
		jcb7.addItem("11 시");
		jcb7.addItem("12 시");
		jcb7.addItem("13 시");
		jcb7.addItem("14 시");
		jcb7.addItem("15 시");
		jcb7.addItem("16 시");
		jcb7.addItem("17 시");
		jcb7.addItem("18 시");
		jcb7.addItem("19 시");
		jcb7.addItem("20 시");
		jcb7.addItem("21 시");
		jcb7.addItem("21 시");
		jcb7.addItem("22 시");
		jcb7.addItem("23 시");
		jcb7.addItem("24 시");
		
		jp6.setBackground(butt3);
		jp6.setLocation(860, 170);
		jp6.setSize(300, 60);
		jp6.setLayout(new GridLayout(2, 3));
		jp6.add(jcb2);
		jp6.add(jcb3);
		jp6.add(jcb4);
		jp6.add(jcb5);
		jp6.add(jcb6);
		jp6.add(jcb7);
		add(jp6);
		
		String row[] = 
			{"과목명", "To do List", "마감 기한", "실제 마감일", "완료 여부", "중요여부"};
		String column[][] = 
			{
					{"소프트웨어공학", "요구사항명세서 작성", "2017-04-28", "2017-04-28", "X", "***"},
					{"인공지능", "재정상담시스템 구현", "2017-05-01", "2017-05-02", "X", "**"}
			};
		JTable jtb = new JTable(column, row);
		jtb.setLocation(10, 20);
		jtb.setSize(700, 400);
		JScrollPane js = new JScrollPane(jtb);
		js.setBackground(point);
		js.setSize(700, 400);
		jtb.setBackground(point);
		
		add(js);

		setSize(1200, 400);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new TodoList표시();
	}
}