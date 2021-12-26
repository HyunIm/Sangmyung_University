// 201511054 컴퓨터과학과 임현

#include <stdio.h>

int Eucl(int i, int j) // 유클리드 알고리즘 (최대공약수 함수)
{
	int tmp;
	tmp = i%j; // i 나누기 j의 나머지 값

	if (tmp == 0) // 나머지가 0이 될 때 까지
		return j;
	else
		return Eucl(j, tmp); // 다시 한 번 함수로
}

int main(void)
{
	int a, b; // 두 수
	int temp; // 큰 값 비교
	scanf("%d %d", &a, &b); // 두 수 입력

	if (a < b) // 만약 b가 더 클 경우 교체
	{
		temp = a;
		a = b;
		b = temp;
	}

	printf("%d\n", Eucl(a, b)); // 최대공약수 출력

	return 0;
}