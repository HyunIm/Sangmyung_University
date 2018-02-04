#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54], inv[54];
	int i, j = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
		inv[i] = num[i];

	for (i = 53; i >= 0; i--, j++)
		num[i] = inv[j];

	for (i = 0; i < 54; i++)
	printf("%d ", num[i]);
	printf("\n");

	return 0;
}