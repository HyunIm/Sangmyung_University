#include<stdio.h>

int main()
{
	char a;
	float temp;

	printf("�µ� ��ȯ ���α׷� �ۼ�\n\n");
	scanf("\n%c", &a);


	{
		scanf("%f", &temp);
	}


	printf(" (ȭ��) %f F\n", (5.0 / 9.0)*(temp - 32));

	return 0;
}