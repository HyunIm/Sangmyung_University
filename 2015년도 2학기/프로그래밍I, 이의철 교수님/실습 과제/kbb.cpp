#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int com, user;
	srand((unsigned)time(NULL)); // 랜덤함수 seed값 설정
	com = rand() % 3 + 1;
	printf("(가위: 1   바위: 2   보: 3) 입력하세요 > ");
	scanf("%d", &user);
	if(user > 3 || user < 0) 
	{
		printf("잘못 입력했습니다!\n");
		return -1;
	}
	//PrintStatus(com, user);
	printf("컴퓨터: %d vs 사용자: %d\n", com, user);
	if(com == user) // 비긴 경우
	{
		printf("비겼습니다\n");
	}
	else if((com == 1 && user == 2) || (com == 2 && user == 3) ||
		(com == 3 && user == 1)) // 이긴 경우
	{
		printf("이겼습니다\n");
	}
	else
	{
		printf("졌습니다\n");
	}
	return 0;
}
