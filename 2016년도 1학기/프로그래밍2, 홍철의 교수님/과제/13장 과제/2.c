#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[100];
	int max;
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
		num[i] = rand() % 100;

	max = num[0];

	for (int i = 1; i < 100; i++)
	{
		if (max < num[i])
			max = num[i];
	}

	printf("%d\n", max);

	/*for (int i = 0; i < 100; i++)
		printf("%d ", num[i]);*/

	return 0;
}