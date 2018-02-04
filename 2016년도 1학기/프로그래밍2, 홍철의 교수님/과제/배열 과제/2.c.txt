#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54];
	int m, i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("정수 값 m을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		num[i] -= m;
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}