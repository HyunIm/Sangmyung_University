#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54];
	int i, max, min, x, n;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	max = min = num[0];

	for (i = 0; i < 54; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			x = i;
		}
		if (min > num[i])
		{
			min = num[i];
			n = i;
		}
	}

	num[x] = min;
	num[n] = max;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}