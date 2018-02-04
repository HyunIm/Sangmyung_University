#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54];
	int m, i, swap;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("m값을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	while (201511054)
	{
		if (m > 53)
		{
			printf("m 값이 53보다 큽니다. 다시 입력해주세요. (최댓값 : 53)\n");
			printf("m 값을 입력 : ");
			scanf("%d", &m);
			printf("\n");
		}
		else
			break;
	}

	swap = num[m];
	num[m] = num[i - 1 - m];
	num[i - 1 - m] = swap;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}