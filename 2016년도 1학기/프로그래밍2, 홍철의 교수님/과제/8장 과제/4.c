// 4번
#include <stdio.h>

int main(void)
{
	int num;

	scanf("%d", &num); // 임의의 양의 정수 입력

	if (num > 0) // 양의 정수
	{
		for (int i = 2; i < num; i++) // 2부터 num까지
		{
			if (num%i == 0) // 소수가 아닌 조건
			{
				printf("입력한 수 %d은 소수가 아닙니다.\n", num);
				return 0;
			}
		}

		printf("입력한 수 %d은 소수입니다.\n", num); // 소수 조건
		return 0;
	}

	else // 양의 정수가 아닌 값을 입력
		printf("입력한 수 %d은 양의 정수가 아닙니다.\n", num);
	return 0;
}