#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ComRps(void) // 컴퓨터의 가위바위보 결정
{
	int com;
	com = rand() % 3 + 1;
	return com;
}

int UserRps(void) // 사용자의 가위바위보 결정
{
	int user;
	printf("바위는 1, 가위는 2, 보는 3: ");
	scanf("%d", &user);
	return user;
}

int main(void)
{
	srand((unsigned)time(NULL));
	int user, com;
	int win = 0, draw = 0;

	while (201511054) // 질 때까지 반복
	{
		com = ComRps();
		user = UserRps();

		if (user == 1 && com == 1){
			printf("당신은 바위 선택, 컴퓨터는 바위 선택, 비겼습니다!\n"); draw++;	// 무승부
		}
		else if (user == 2 && com == 2){
			printf("당신은 가위 선택, 컴퓨터는 가위 선택, 비겼습니다!\n"); draw++;
		}
		else if (user == 3 && com == 3){
			printf("당신은 보 선택, 컴퓨터는 보 선택, 비겼습니다!\n"); draw++;
		}
		else if (user == 1 && com == 2){
			printf("당신은 바위 선택, 컴퓨터는 가위 선택, 이겼습니다!\n"); win++;  // 승리
		}
		else if (user == 2 && com == 3){
			printf("당신은 가위 선택, 컴퓨터는 보 선택, 이겼습니다!\n"); win++;
		}
		else if (user == 3 && com == 1){
			printf("당신은 보 선택, 컴퓨터는 바위 선택, 이겼습니다!\n"); win++;
		}
		else if (user == 1 && com == 3){
			printf("당신은 바위 선택, 컴퓨터는 보 선택, 졌습니다!\n"); break; // 패배
		}
		else if (user == 2 && com == 1){
			printf("당신은 가위 선택, 컴퓨터는 주먹 선택, 졌습니다!\n"); break;
		}
		else if (user == 3 && com == 2){
			printf("당신은 보 선택, 컴퓨터는 바위 선택, 졌습니다!\n"); break;
		}
	}

	printf("게임의 결과 : %d승, %d무\n", win, draw); // 결과 값 출력

	return 0;
}