#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ComNum(int com[]) // 컴퓨터의 숫자 결정
{
	for (int i = 0; i < 3; i++) {
		com[i] = rand() % 10;
		for (int j = 0; j < i; j++) {
			if (com[i] == com[j]) {
				i--;
				break;
			}
		}
	}
}

void UserNum(int user[]) // 사용자의 숫자 결정
{
	printf("3개의 숫자 선택 : ");
	scanf("%d %d %d", &user[0], &user[1], &user[2]);
}

int main(void)
{
	srand((unsigned)time(NULL));
	int user[3], com[3];
	int strike, ball, cnt = 0; // 스트라이크, 볼, 게임 횟수
	int i, j;
	ComNum(com);
	/*for (i = 0; i < 3; i++) // 컴퓨터 숫자 확인용
	printf("%d ", com[i]);*/
	printf("Strat Game! \n");
	while (201511054) // 스트라이크가 3이 될 때 까지 반복
	{
		strike = 0; // 값 초기화
		ball = 0; // 
		cnt++; // 게임 횟수 1 증가
		UserNum(user);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (user[i] == com[j] && i == j) // 자리도 같고, 값도 같은 경우
					strike++;
				if (user[i] == com[j] && i != j) // 자리는 다르나, 값은 같은 경우
					ball++;
			}
		}

		printf("%d번째 도전 결과 : %d strike, %d ball !!\n", cnt, strike, ball);
		
		if (strike == 3) // 스트라이크가 3개일 경우 탈출
			break;
	}
	printf("\nGame Over! \n");

	return 0;
}