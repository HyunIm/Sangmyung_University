// 4번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Swap(int *a, int *b) // a와 b의 값을 교환해주는 함수
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int num[10]; // 10개의 정수
	srand(time(NULL)); //난수 발생

	for (int i = 0; i < 10; i++) // 난수 발생기를 이용하여 배열에 저장
		num[i] = rand() % 100;

	/*for (int i = 0; i < 10; i++) // 교환 전 10개의 정수 출력
		printf("%d ", num[i]);
	printf("\n");*/

	for (int i = 0; i < 10; i++) // Bubble Sorting 오름차순 정렬
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (num[i] > num[j])
				Swap(&num[i], &num[j]);
		}
	}

	printf("2번째로 큰 수 : %d\n", num[8]); // 2번째로 큰 수 출력

	/*for (int i = 0; i < 10; i++) // 교환 후 10개의 정수 출력
		printf("%d ", num[i]);*/

	return 0;
}