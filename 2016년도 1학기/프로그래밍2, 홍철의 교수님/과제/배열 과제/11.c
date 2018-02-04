#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54];
	int s, i;
	int j = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("특정 값 입력 : ");
	scanf("%d", &s);
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (num[i] == s)
		{
			printf("num[%d] ", i);
		}
		else if (num[i] != s)
			j++;
	}

	if (j == 54)
		printf("특정 값이 배열 내에 없습니다.");

	printf("\n");

	return 0;
}