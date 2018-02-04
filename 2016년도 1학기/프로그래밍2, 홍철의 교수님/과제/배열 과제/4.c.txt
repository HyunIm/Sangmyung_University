#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[54];
	int i;
	int sum = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
		sum += num[i];

	printf("배열에 저장된 값의 합 : %d \n", sum);

	return 0;
}