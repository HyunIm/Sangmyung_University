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
	{
		if (i % 2 == 1)
			sum += num[i];
	}

	printf("홀수 번째에 저장된 배열 원소의 합 : %d \n", sum);

	return 0;
}