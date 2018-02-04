// 6번
#include <stdio.h>

int main(void)
{
	int y, m, d, tm; // 연도, 월, 일, 임시 월
	int order = 0; // 몇 번째 날
	scanf("%d %d %d", &y, &m, &d); // 연도, 월, 일 입력
	tm = m; // 출력하기 위한 m값을 tm에 저장
	
	for (int i = m; i > 0; i--)
	{
		m--;
		if (m == 4 || m == 6 || m == 9 || m == 11) // 4, 6, 9, 11월은 30일 까지
			order += 30;
		else if (m == 2) // 2월이 윤년인지, 아닌지
		{
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) // 4로 나누어 0, 100으로 나누어 0일 경우, 400으로 나누어 0일 경우 윤년
				order += 29;
			else // 윤년이 아닐 경우
				order += 28;
		}
		else // 1, 3, 5, 7, 8, 10, 12월은 31일 까지
			order += 31;
	}

	order += d; // 일 수 더하기
	order -= 31;

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		printf("%d년은 윤년이므로 %d월 %d일은 1년 중 %d번째 날입니다.", y, tm, d, order); // 윤년 여부 확인 후 출력
	else
		printf("%d년은 윤년이 아니므로 %d월 %d일은 1년 중 %d번째 날입니다.", y, tm, d, order);

	return 0;
}