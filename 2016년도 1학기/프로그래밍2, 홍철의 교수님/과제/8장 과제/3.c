//3번
#include <stdio.h>

int main(void)
{
	int i, j; // 두 개의 정수
	int temp; // i가 더 클 경우 바꿔줄 변수
	int sum = 0; // 모든 홀수의 합

	scanf("%d %d", &i, &j); // 두 개의 정수 입력

	if (i > j) // i가 더 클 경우 i와 j의 값을 바꿔줌
	{
		temp = i;
		i = j;
		j = temp;
	}

	for (; i < j; i++) // i부터 j까지
	{
		if (i % 2 == 1) // 홀수 조건
			sum += i; // i를 합에 더해줌
	}

	printf("%d\n", sum); // 합 출력

	return 0;
}