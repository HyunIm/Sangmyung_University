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
	printf("========== ���ڸ��߱� ==========\n");
	i = 0;
	printf("��ǻ�Ͱ� ������ 1 ~ 50������ ���ڸ� ���纸����.\n");
	while (201511054)
	{
		i++;
		scanf("%d", &user);
		if (user > b || user < a)
		{
			printf("%d��° �õ�> %d Stupid!! ����Ƚ���� �ο��˴ϴ�.\n", i, user);
		}
		else
		{
			if (user < num)
			{
				a = user;
				printf("%d��° �õ�> %d Up!!\n", i, user);
			}
			else if (num < user)
			{
				b = user;
				printf("%d��° �õ�> %d Down!!\n", i, user);
			}
			else
			{
				printf("%d��° �õ�> %d Correct!!\n", i, user);
				break;
			}
		}
		}
	printf("%��° �õ����� ������ϴ�.\n", i);

	return 0;
}