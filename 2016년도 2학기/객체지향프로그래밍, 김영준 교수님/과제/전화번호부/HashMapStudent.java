import java.util.*;

class Student {
	String tel;
	String adr; // �ּ�
	public Student (String tel, String adr) { // �л��� ǥ���ϴ� Ŭ����
		this.tel = tel; this.adr = adr;
	}
}

public class HashMapStudent {
	public static void main (String [] args) {
		Scanner rd = new Scanner(System.in);
		// �л� �̸��� Student ��ü�� ������ �����ϴ� HashMap �÷��� ����
		HashMap<String, Student> map = new HashMap<String, Student> ();
		
		System.out.println("--------------------------------------------");
		System.out.println("��ȭ��ȣ ���� ���α׷��� �����մϴ�. ���Ϸ� �������� �ʽ��ϴ�.");
		System.out.println("--------------------------------------------");
		
		int num; // ����, ����, ã��, ��ü����, ���� ����
		String id; // �̸�
		while (true) {
			System.out.print("���� : 0. ���� : 1, ã�� : 2, ��ü���� : 3, ���� : 4 >> ");
			num = rd.nextInt();
			
			if (num == 0) {
				System.out.println("�̸�, ��ȭ��ȣ, �ּҸ� �Է����ֽʽÿ�.");
				map.put(rd.next(), new Student(rd.next(), rd.next()));
			}
			
			if (num == 1) { // ����
				System.out.println("�̸��� �Է����ֽʽÿ�.");
				map.remove(rd.next());
				System.out.println("�����Ǿ����ϴ�.");
			}
			
			if (num == 2) { // ã��
				System.out.println("�̸��� �Է����ֽʽÿ�.");
				id = rd.next();
				Student student = map.get(id);
				System.out.println(id + " " + student.tel + " " + student.adr);
			}
			
			if (num == 3) {
				// ��� �л� ���, map�� ��� �ִ� ��� (key, value) �� ���
				// key ���ڿ��� ���� ���� Set �÷��� ����
				Set<String> names = map.keySet();
				Vector <String> v = new Vector <String> ();
				v.addAll(names); // ���� �ȿ� ��� ���� ����
				Collections.sort(v);
				
				// key ���ڿ��� ������� ������ �� �ִ� Iterator ����
				Iterator <String> it = v.iterator();
				while(it.hasNext()) {
					String name = it.next(); // ���� Ű. �л� �̸�
					Student student = map.get(name);
					System.out.println(name + " : " + student.tel + " " + student.adr);
				}
			}
			
			if (num == 4)
				break;
		}
		System.out.println("���α׷��� �����մϴ�...");
	}
}

/*int num; // �� �� ��������
System.out.println("�л��� �� �� �Է��� �� ���� �Է����ֽʽÿ�.");
num = rd.nextInt();

System.out.println("�л� �̸�, ��ȭ��ȣ, �ּҸ� ������� �Է����ֽʽÿ�.");
for (int i = 0; i < num; i++) // �л� ���� �Է�*/
