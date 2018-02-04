#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54];
	int i, f;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	f = num[0];

	for (i = 0; i < 53; i++)
		num[i] = num[i + 1];

	num[i] = f;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}