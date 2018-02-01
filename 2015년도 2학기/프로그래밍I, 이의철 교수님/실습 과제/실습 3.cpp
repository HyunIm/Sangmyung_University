#include <stdio.h>

int main (void)
{
	int num1;
	int num2 = 8;
	int num4;

	printf("0~255 사이의 정수를 입력하시오. : ");
	scanf("%d", &num1);

	int num3 = num1 & num2;
	num4 = num3>>3;

	printf("LSB로부터 4번째 비트의 값이 %d으로 set 되어있습니다.", num4);
	return 0;
}