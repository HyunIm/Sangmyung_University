#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int num;
	int user;
	int a = 1, b = 50;
	srand((unsigned)time(NULL));
	num = rand() % 50 + 1;
	printf("========== 숫자맞추기 ==========\n");
	i = 0;
	printf("컴퓨터가 생각한 1 ~ 50사이의 숫자를 맞춰보세요.\n");
	while (201511054)
	{
		i++;
		scanf("%d", &user);
		if (user > b || user < a)
		{
			printf("%d번째 시도> %d Stupid!! 벌점횟수가 부여됩니다.\n", i, user);
		}
		else
		{
			if (user < num)
			{
				a = user;
				printf("%d번째 시도> %d Up!!\n", i, user);
			}
			else if (num < user)
			{
				b = user;
				printf("%d번째 시도> %d Down!!\n", i, user);
			}
			else
			{
				printf("%d번째 시도> %d Correct!!\n", i, user);
				break;
			}
		}
		}
	printf("%번째 시도만에 맞췄습니다.\n", i);

	return 0;
}