// 5번
#include <stdio.h>

int main(void)
{
	int num; // 정수 n
	int fgr; // 끝자리
	int sum = 0; // 각 자릿수 합

	scanf("%d", &num); // 정수 n 입력

	do
	{
		fgr = num % 10; // fgr은 num의 끝자리
		num -= fgr; // num에서 fgr을 빼서 끝자리를 0으로 만듬
		num /= 10; // num을 10으로 나눠서 자리수를 빼줌
		sum += fgr; // sum 값에 fgr값 저장
	} while (num > 0); // 조건문

	printf("%d\n", sum); // 각 자릿수의 합

	return 0;
}