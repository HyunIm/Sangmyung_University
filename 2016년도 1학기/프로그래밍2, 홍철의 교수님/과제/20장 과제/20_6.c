#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ComNum(int com[]) // ��ǻ���� ���� ����
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

void UserNum(int user[]) // ������� ���� ����
{
	printf("3���� ���� ���� : ");
	scanf("%d %d %d", &user[0], &user[1], &user[2]);
}

int main(void)
{
	srand((unsigned)time(NULL));
	int user[3], com[3];
	int strike, ball, cnt = 0; // ��Ʈ����ũ, ��, ���� Ƚ��
	int i, j;
	ComNum(com);
	/*for (i = 0; i < 3; i++) // ��ǻ�� ���� Ȯ�ο�
	printf("%d ", com[i]);*/
	printf("Strat Game! \n");
	while (201511054) // ��Ʈ����ũ�� 3�� �� �� ���� �ݺ�
	{
		strike = 0; // �� �ʱ�ȭ
		ball = 0; // 
		cnt++; // ���� Ƚ�� 1 ����
		UserNum(user);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (user[i] == com[j] && i == j) // �ڸ��� ����, ���� ���� ���
					strike++;
				if (user[i] == com[j] && i != j) // �ڸ��� �ٸ���, ���� ���� ���
					ball++;
			}
		}

		printf("%d��° ���� ��� : %d strike, %d ball !!\n", cnt, strike, ball);
		
		if (strike == 3) // ��Ʈ����ũ�� 3���� ��� Ż��
			break;
	}
	printf("\nGame Over! \n");

	return 0;
}