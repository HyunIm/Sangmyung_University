class CurrencyConverter {
	private static double rate; // 한국 원화에 대한 환율
	public static double toDollar(double won) {
		return won/rate; // 한국 원화를 달러로 변환
	}
	public static double toKWR(double dollar) {
		return dollar * rate; // 달러를 한국 원화로 변환
	}
	public static void setRate(double r) {
		rate = r; // 환율 설정. KWR/$1
	}
}

public class StaticMember {
	public static void main (String [] args) {
		CurrencyConverter.setRate(1121); // 미국 달러 환율 설정
		System.out.println("백만원은 " + CurrencyConverter.toDollar(1000000) + "달러입니다.");
		System.out.println("백달러는 " + CurrencyConverter.toKWR(100) + "원입니다.");
	}

}
