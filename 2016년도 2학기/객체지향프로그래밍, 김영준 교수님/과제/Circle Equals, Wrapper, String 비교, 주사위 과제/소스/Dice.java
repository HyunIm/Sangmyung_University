// -------------------------------------------------------
// ���� �ڷῡ �ִ� Die.java
// 201511054 ��ǻ�Ͱ��а� ����
// -------------------------------------------------------

public class Dice {
	
	private final int MAX = 6; // �ֻ����� �ִ� ��
	private int faceValue; // �ֻ��� ��
	
	public Dice() { // �ֻ��� �ʱ�ȭ
		faceValue = 1;
	}
	
	public int roll() { // �ֻ��� ������
		faceValue = (int) (Math.random() * MAX) + 1;
		
		return faceValue;
	}
	
	/* public void setFaceValue (int value) { // �ֻ��� �� ����, �� ���������� ������� ����
		faceValue = value;
	} */
	
	public int getFaceValue() { // �ֻ��� �� �ޱ�
		return faceValue;
	}
	
	public String toString() { // toString�� �̿��� �ֻ��� �� �ݳ�
		String result = Integer.toString(faceValue);
		
		return result;
	}

}