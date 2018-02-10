// -------------------------------------------------------
// 강의 자료에 있는 Die.java
// 201511054 컴퓨터과학과 임현
// -------------------------------------------------------

public class Dice {
	
	private final int MAX = 6; // 주사위의 최대 값
	private int faceValue; // 주사위 값
	
	public Dice() { // 주사위 초기화
		faceValue = 1;
	}
	
	public int roll() { // 주사위 굴리기
		faceValue = (int) (Math.random() * MAX) + 1;
		
		return faceValue;
	}
	
	/* public void setFaceValue (int value) { // 주사위 값 설정, 본 과제에서는 사용하지 않음
		faceValue = value;
	} */
	
	public int getFaceValue() { // 주사위 값 받기
		return faceValue;
	}
	
	public String toString() { // toString을 이용한 주사위 값 반납
		String result = Integer.toString(faceValue);
		
		return result;
	}

}