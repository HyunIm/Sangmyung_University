
public class Book {
	String title;
	String author;
	//int ISBN;
	/*public Book (String title, String author, int ISBN) {
		this.title = title;
		this.author = author;
		this.ISBN = ISBN;
	}*/
	
	public Book (String title, String author) {
		this.title = title;
		this.author = author;
	}
	
	public Book (String title) {
		this.title = title;
		this.author = " ";
	}
	
	

public static void main (String [] args) {
	//Book javaBook = new Book("Java JDK", "황기태", 3333);
	Book javaBook = new Book("Java", "황기태");
	Book bible = new Book("Bible");
	
	System.out.println(javaBook.title + " " + javaBook.author);
	System.out.println(bible.title + " " + bible.author);
	}
}
