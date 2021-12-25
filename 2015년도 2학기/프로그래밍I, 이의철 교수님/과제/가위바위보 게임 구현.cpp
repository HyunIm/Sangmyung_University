//201511054 컴퓨터과학과 임현

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ComRps(void) //컴퓨터의 가위바위보 결정
{
	int com;
	srand((unsigned)time(NULL));
	com = rand() % 3 + 1;
	return com;
}

int UserRps(void) //유저의 가위바위보 입력 및 결정
{
	int user;
	scanf("%d", &user);
	return user;
}

int HowManyTimes(void) //가위바위보 게임을 몇번 겨룰 것인지 입력 및 결정
{
	int times;
	printf("몇 번 대결하시겠습니까?  ");
	scanf("%d", &times);
	return times;
}

int RockPaperScissors(void) //가위바위보 게임
{
	int com, user, times;
	int count = 1, win = 0, lose = 0, draw = 0;
	printf("\n============ 가위바위보 게임 ============\n\n");
	times = HowManyTimes();
	printf("가위: 1, 바위: 2, 보: 3  ");

	for (; count <= times;) //가위바위보 게임을 몇번 겨룰 것인지 입력받은 횟수만큼 반복
	{	
		com = ComRps();
		user = UserRps();

		if (com == 1 && user == 1) //무승부
		{
			printf("%d번째 대결> %d COM: 가위  vs  USER: 가위 무승부!!\n", count, user);
			count++; draw++;
		}
		else if (com == 2 && user == 2)
		{
			printf("%d번째 대결> %d COM: 바위  vs  USER: 바위 무승부!!\n", count, user);
			count++; draw++;
		}
		else if (com == 3 && user == 3)
		{
			printf("%d번째 대결> %d COM: 보  vs  USER: 보 무승부!!\n", count, user);
			count++; draw++;
		}

		else if (com == 1 && user == 2) //승
		{
			printf("%d번째 대결> %d COM: 가위  vs  USER: 바위 승!!\n", count, user);
			count++; win++;
		}
		else if (com == 2 && user == 3)
		{
			printf("%d번째 대결> %d COM: 바위  vs  USER: 보 승!!\n", count, user);
			count++; win++;
		}
		else if (com == 3 && user == 1)
		{
			printf("%d번째 대결> %d COM: 보  vs  USER: 가위 승!!\n", count, user);
			count++; win++;
		}

		else if (com == 2 && user == 1) //패
		{
			printf("%d번째 대결> %d COM: 바위  vs  USER: 가위 패!!\n", count, user);
			count++; lose++;
		}
		else if (com == 3 && user == 2)
		{
			printf("%d번째 대결> %d COM: 보  vs  USER: 바위 패!!\n", count, user);
			count++; lose++;
		}
		else if (com == 1 && user == 3)
		{
			printf("%d번째 대결> %d COM: 가위  vs  USER: 보 패!!\n", count, user);
			count++; lose++;
		}

		else //1~3이 아닌 다를 숫자를 입력한 경우
		{
			printf("%d번째 대결> %d 잘못 입력하셨습니다!!\n", count, user);
		}
	}
	
	printf("최종성적: %d전 %d승 %d무 %d패 (승률 %.1f%%)", times, win, draw, lose, (double)win / times*100);

	return 0;
}

int main(void) //메인 함수
{
	RockPaperScissors();
}