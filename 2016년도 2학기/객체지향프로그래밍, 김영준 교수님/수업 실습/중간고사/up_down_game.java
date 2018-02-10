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
			
			System.out.println("수를  결정하였습니다. 맞추어보세요");
			
			while (true) {
				System.out.println(low + "-" + high);
				cnt++;
				System.out.print(cnt + ">>");
				user = rd.nextInt();
				
				if (user > k) {
					System.out.println("더 낮게");
					high = user;
				}
				else if (user < k) {
					System.out.println("더 높게");
					low = user;
				}
				else {
					System.out.println("맞았습니다.");
					System.out.print("다시하시겠습니까(y/n)>>");
					
					if (rd.next().equals("y"))
						break;
					else
						yon = 'n'; break;
				}
			}
		}
	}		
}