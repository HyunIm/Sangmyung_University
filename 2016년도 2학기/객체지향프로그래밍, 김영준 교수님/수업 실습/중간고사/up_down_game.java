import java.util.Scanner;
import java.util.Random;

public class up_down_game {
	public static void main (String [] args) {
		Scanner rd = new Scanner (System.in);
		Random r = new Random();
		
		char yon = 'l';
		
		while (true) {
			int user;
			int low = 0;
			int high = 99;
			int cnt = 0;
			int k = r.nextInt(100);
			
			if (yon == 'n')
				break;
			
			System.out.println("����  �����Ͽ����ϴ�. ���߾����");
			
			while (true) {
				System.out.println(low + "-" + high);
				cnt++;
				System.out.print(cnt + ">>");
				user = rd.nextInt();
				
				if (user > k) {
					System.out.println("�� ����");
					high = user;
				}
				else if (user < k) {
					System.out.println("�� ����");
					low = user;
				}
				else {
					System.out.println("�¾ҽ��ϴ�.");
					System.out.print("�ٽ��Ͻðڽ��ϱ�(y/n)>>");
					
					if (rd.next().equals("y"))
						break;
					else
						yon = 'n'; break;
				}
			}
		}
	}		
}