
// 201511054 ��ǻ�Ͱ��а� ����

#include <stdio.h>

int main (void)
{
	int num1, num2, num3, num4, num5;
	double avr, vra;

	printf("ù��° �л� ���� : ");
	scanf("%d", &num1);

	printf("�ι�° �л� ���� : ");
	scanf("%d", &num2);

	printf("����° �л� ���� : ");
	scanf("%d", &num3);

	printf("�׹�° �л� ���� : ");
	scanf("%d", &num4);

	printf("�ټ���° �л� ���� : ");
	scanf("%d", &num5);

	avr = (num1 + num2 + num3 + num4 + num5)/(double)5;
	vra = ((num1-avr)*(num1-avr)+(num2-avr)*(num2-avr)+(num3-avr)*(num3-avr)+(num4-avr)*(num4-avr)+(num5-avr)*(num5-avr))/(double)4;

	printf("��� : %.3f", avr);
	printf("�л� : %.3f", vra);

	return 0;
}