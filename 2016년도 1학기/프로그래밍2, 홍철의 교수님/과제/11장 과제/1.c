// 201511054 컴퓨터과학과 임현
// 1번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[10]; // 10개의 정수
	int max, min; // 최댓값, 최솟값
	srand(time(NULL)); // 난수 발생

	for (int i = 0; i < 10; i++) // 난수 발생기를 이용하여 배열에 저장
		num[i] = rand() % 100;

	max = min = num[0]; // 최댓값, 최솟값을 배열의 첫 번째 값으로 저장

	for (int i = 1; i < 10; i++) // num[1]부터 num[9]까지
	{
		if (max < num[i]) // num[i]가 max보다 크다면 값을 교환
			max = num[i];
		if (min > num[i]) // num[i]가 min보다 작다면 값을 교환
			min = num[i];
	}

	printf("최댓값 : %d, 최솟값 : %d\n", max, min); // 최댓값, 최솟값 출력

	/*for (int i = 0; i < 10; i++) // 10개의 정수 출력
		printf("%d ", num[i]);*/

	return 0;
}