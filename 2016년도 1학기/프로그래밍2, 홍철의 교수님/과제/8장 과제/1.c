// 1번
#include <stdio.h>

int main(void)
{
	int x, y, z, temp;

	scanf("%d %d %d", &x, &y, &z); //세 수 입력
	// 오름차순 정렬
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	if (x > z)
	{
		temp = x;
		x = z;
		z = temp;
	}

	if (y > z)
	{
		temp = y;
		y = z;
		z = temp;
	}

	printf("%d", z); //가장 큰 수 출력

	return 0;
}