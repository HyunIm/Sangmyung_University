// 2번
#include <stdio.h>

int main(void)
{
	int x, y, z, temp;

	while (201511054)
	{
		scanf("%d %d %d", &x, &y, &z); // 세 개의 정수 입력
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

		if (x < 0 || y < 0 || z < 0) // 음의 값이 입력될 시 프로그램 종료
			return 0;
		
		if (x > 0 && y> 0 && z > 0) // 삼각형 조건 검사
		{
			if (x + y < z) // 삼각형이 될 수 없음
				printf("삼각형이 될 수 없습니다. \n");

			else // 삼각형이 될 수 있음
			{
				if (x*x + y*y == z*z) // 직각 삼각형
					printf("직각 삼각형입니다. \n");

				else if (x == y && y == z && z == x) // 정 삼각형
					printf("정 삼각형입니다. \n");

				else if (x == y || y == z) // (정 삼각형 조건 검사 후) 이등변 삼각형
					printf("이등변 삼각형입니다. \n");

				else // 일반 삼각형
					printf("일반 삼각형입니다. \n");
			}
		}
	}
}