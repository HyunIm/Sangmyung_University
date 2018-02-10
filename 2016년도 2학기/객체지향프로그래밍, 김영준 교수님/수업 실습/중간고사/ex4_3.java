import java.util.Scanner;

public class ex4_3 {
	public static void main (String [] args) {
		Goods [] goodsArray = new Goods [3];
		Scanner rd = new Scanner (System.in);

		for (int i = 0; i < goodsArray.length; i++) {
			String name = rd.next();
			int price = rd.nextInt();
			int n = rd.nextInt();
			int sold = rd.nextInt();
			goodsArray[i] = new Goods(name, price, n, sold);
		}
		
		for (int i = 0; i < goodsArray.length; i++) {
			System.out.print(goodsArray[i].getName() + " ");
			System.out.print(goodsArray[i].getPrice() + " ");
			
			System.out.print(goodsArray[i].getNumberOfStock() + " ");
			System.out.println(goodsArray[i].getSold());
		}
	}
}

class Goods {
	private String name;
	private int price;
	private int numberOfStock;
	private int sold;
	
	Goods(String n, int p, int nStock, int s) {
		name = n;
		price = p;
		numberOfStock = nStock;
		sold = s;
	}
	
	String getName() {return name;}
	int getPrice() {return price;}
	int getNumberOfStock() {return numberOfStock;}
	int getSold() {return sold;}
}