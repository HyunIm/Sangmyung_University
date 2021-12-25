#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PrintString(int val)
{
	if(val == 1) printf("가위");
	else if(val == 2) printf("바위");
	else if(val == 3) printf("보");
}
void PrintStatus(int com, int user)
{
	printf("컴퓨터: ");
	PrintString(com);
	printf("vs 사용자: ");
	PrintString(user);
	printf("\n\n");
}
void DetermWDL(int com, int user, int *W, int *D, int *L)
{
	if(com == user) // 비긴 경우
	{
		printf("비겼습니다\n");
		(*D)++;
	}
	else if((com == 1 && user == 2) || (com == 2 && user == 3) ||
		(com == 3 && user == 1)) // 이긴 경우
	{
		printf("이겼습니다\n");
		(*W)++;
	}
	else
	{
		printf("졌습니다\n");
		(*L)++;
	}
}
void PrintWDL(int W, int D, int L)
{
	printf("%d전 %d승 %d무 %d패 (승률: %.2f)\n", 
		W+D+L, W, D, L, (double)W/(W+D+L));
}
int main()
{
	int com, user;
	int W = 0, D = 0, L = 0;
	int repeat;
	srand((unsigned)time(NULL)); // 랜덤함수 seed값 설정
	printf("==========================\n");
	printf("==    가위 바위 보 게임 Ver 0.1  ==\n");
	printf("==========================\n\n\n");
	system("pause");
	printf("몇 번 게임하시겠습니까? ");
	scanf("%d", &repeat);
	for(int i=1; i<=repeat; i++)
	{
		printf("\a[%d번째 승부] (가위: 1   바위: 2   보: 3) 입력하세요 > ", i);
		com = rand() % 3 + 1;
		scanf("%d", &user);	
		if(user > 3 || user < 0) 
		{
			printf("잘못 입력했습니다!\n");
			i--;
			continue;
		}
		PrintStatus(com, user);
		DetermWDL(com, user, &W, &D, &L);
	}
	PrintWDL(W, D, L);
	return 0;
}
