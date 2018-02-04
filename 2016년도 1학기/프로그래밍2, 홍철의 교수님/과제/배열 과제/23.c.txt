#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[5][5];
	int i, j, sum;

	srand((unsigned)time(NULL));
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			num[i][j] = rand() % 10;
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 4; j++)
			sum += num[i][j];
		num[i][4] = sum;
	}

	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 4; j++)
			sum += num[j][i];
		num[4][i] = sum;
	}

	num[4][4] = 0;

	for (i = 0; i < 4; i++)
		num[4][4] += num[i][4];

	/*for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d ", num[i][j]);
		printf("\n");
	}
	printf("\n");*/

	for (i = 0; i < 4; i++)
		printf("%d번째 행의 합 : %d\n", i+1, num[i][4]);
	printf("\n");
	for (i = 0; i < 4; i++)
		printf("%d번째 열의 합 : %d\n", i + 1, num[4][i]);
	printf("\n");
	printf("총 합 : %d\n", num[4][4]);
	printf("\n");

	return 0;
}