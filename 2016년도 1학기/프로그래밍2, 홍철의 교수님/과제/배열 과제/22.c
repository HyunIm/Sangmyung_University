#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54], frq[110];
	int i, j, n, m = 0, max;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 110; i++)
		frq[i] = 0;

	for (i = 0; i < 53; i++)
	{
		for (j = i+1; j < 54; j++)
		{
			if (num[i] == num[j])
			{
				n = num[i];
				frq[n] += 1;
			}
		}
	}

	max = frq[0];
	for (i = 1; i < 110; i++)
	{
		if (max < frq[i])
		{
			max = frq[i];
			m = i;
		}
	}

	printf("빈도수가 가장 많은 값은 %d입니다\n", m);

	return 0;
}