#include<stdio.h>

int main()
{
	char a;
	float temp;

	printf("온도 변환 프로그램 작성\n\n");
	scanf("\n%c", &a);


	{
		scanf("%f", &temp);
	}


	printf(" (화씨) %f F\n", (5.0 / 9.0)*(temp - 32));

	return 0;
}