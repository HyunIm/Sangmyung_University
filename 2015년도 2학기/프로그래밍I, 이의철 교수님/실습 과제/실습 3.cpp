#include <stdio.h>

int main (void)
{
	int num1;
	int num2 = 8;
	int num4;

	printf("0~255 ������ ������ �Է��Ͻÿ�. : ");
	scanf("%d", &num1);

	int num3 = num1 & num2;
	num4 = num3>>3;

	printf("LSB�κ��� 4��° ��Ʈ�� ���� %d���� set �Ǿ��ֽ��ϴ�.", num4);
	return 0;
}