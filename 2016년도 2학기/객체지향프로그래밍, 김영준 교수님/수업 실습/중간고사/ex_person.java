
public class ex_person {
	int age;
	
	public static void main (String [] args) {
		ex_person[] pa = new ex_person[10];
		
		for (int i = 0; i < pa.length; i++) {
			pa [i] = new ex_person();
			pa [i].age = 30 + i;
		}
		
		for (int i = 0; i < pa.length; i++)
			System.out.print(pa[i].age + " ");
	}
}
