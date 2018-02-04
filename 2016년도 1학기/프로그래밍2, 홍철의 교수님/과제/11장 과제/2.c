// 2번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[10]; // 10개의 정수
	int even = 0, odd = 0; // 짝수, 홀수의 합
	srand(time(NULL)); // 난수 발생

	for (int i = 0; i < 10; i++) // 난수 발생기를 이용하여 배열에 저장
		num[i] = rand() % 100;

	for (int i = 0; i < 10; i++) // num[0]부터 num[9]까지
	{
		if (num[i] % 2 == 0) // num[i]를 2로 나눈 나머지가 0이면 짝수
			even += num[i];
		else // 아니면 홀수
			odd += num[i];
	}

	printf("홀수의 합 : %d, 짝수의 합 : %d\n", odd, even); // 홀수의 합과 짝수의 합 출력

	/*for (int i = 0; i < 10; i++) // 10개의 정수 출력
		printf("%d ", num[i]);*/

	return 0;
}