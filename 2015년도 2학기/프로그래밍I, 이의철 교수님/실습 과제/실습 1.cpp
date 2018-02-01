
// 201511054 컴퓨터과학과 임현

#include <stdio.h>

int main (void)
{
	int num1, num2, num3, num4, num5;
	double avr, vra;

	printf("첫번째 학생 점수 : ");
	scanf("%d", &num1);

	printf("두번째 학생 점수 : ");
	scanf("%d", &num2);

	printf("세번째 학생 점수 : ");
	scanf("%d", &num3);

	printf("네번째 학생 점수 : ");
	scanf("%d", &num4);

	printf("다섯번째 학생 점수 : ");
	scanf("%d", &num5);

	avr = (num1 + num2 + num3 + num4 + num5)/(double)5;
	vra = ((num1-avr)*(num1-avr)+(num2-avr)*(num2-avr)+(num3-avr)*(num3-avr)+(num4-avr)*(num4-avr)+(num5-avr)*(num5-avr))/(double)4;

	printf("평균 : %.3f", avr);
	printf("분산 : %.3f", vra);

	return 0;
}