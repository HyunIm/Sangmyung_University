// 3번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[10]; // 10개의 정수
	int temp; // 교환할 때 임시의 변수
	srand(time(NULL)); // 난수 발생

	for (int i = 0; i < 10; i++) // 난수 발생기를 이용하여 배열에 저장
		num[i] = rand() % 100;

	/*for (int i = 0; i < 10; i++) // 교환 전 10개의 정수 출력
		printf("%d  ", num[i]);
	printf("\n");*/

	for (int i = 0; i < 5; i++) // num[0]부터 num[4]까지
	{
		temp = num[i];
		num[i] = num[9 - i]; // 0과 9, 1과 8, ... 교환
		num[9 - i] = temp;
	}

	/*for (int i = 0; i < 10; i++) // 교환 후 10개의 정수 출력
		printf("%d  ", num[i]);*/

	return 0;
}