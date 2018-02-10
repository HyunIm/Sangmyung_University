
class MyInt {
	int val;
	MyInt(int i) {
		val = i;
	}
}

public class CallByValueObject {
	public static void main (String args []) {
		Person aPerson = new Person("ȫ�浿");
		MyInt a = new MyInt(33);
		
		aPerson.setAge(a);
		
		System.out.println(a.val);
	}
}

class Person {
	public String name;
	public int age;
	public Person(String s) {
		name = s;
	}
	
	public void setAge(MyInt i) {
		age = i.val;
		i.val++;
	}
}