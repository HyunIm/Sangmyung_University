//201511054 ��ǻ�Ͱ��а� ����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ComRps(void) //��ǻ���� ���������� ����
{
	int com;
	srand((unsigned)time(NULL));
	com = rand() % 3 + 1;
	return com;
}

int UserRps(void) //������ ���������� �Է� �� ����
{
	int user;
	scanf("%d", &user);
	return user;
}

int HowManyTimes(void) //���������� ������ ��� �ܷ� ������ �Է� �� ����
{
	int times;
	printf("�� �� ����Ͻðڽ��ϱ�?  ");
	scanf("%d", &times);
	return times;
}

int RockPaperScissors(void) //���������� ����
{
	int com, user, times;
	int count = 1, win = 0, lose = 0, draw = 0;
	printf("\n============ ���������� ���� ============\n\n");
	times = HowManyTimes();
	printf("����: 1, ����: 2, ��: 3  ");

	for (; count <= times;) //���������� ������ ��� �ܷ� ������ �Է¹��� Ƚ����ŭ �ݺ�
	{	
		com = ComRps();
		user = UserRps();

		if (com == 1 && user == 1) //���º�
		{
			printf("%d��° ���> %d COM: ����  vs  USER: ���� ���º�!!\n", count, user);
			count++; draw++;
		}
		else if (com == 2 && user == 2)
		{
			printf("%d��° ���> %d COM: ����  vs  USER: ���� ���º�!!\n", count, user);
			count++; draw++;
		}
		else if (com == 3 && user == 3)
		{
			printf("%d��° ���> %d COM: ��  vs  USER: �� ���º�!!\n", count, user);
			count++; draw++;
		}

		else if (com == 1 && user == 2) //��
		{
			printf("%d��° ���> %d COM: ����  vs  USER: ���� ��!!\n", count, user);
			count++; win++;
		}
		else if (com == 2 && user == 3)
		{
			printf("%d��° ���> %d COM: ����  vs  USER: �� ��!!\n", count, user);
			count++; win++;
		}
		else if (com == 3 && user == 1)
		{
			printf("%d��° ���> %d COM: ��  vs  USER: ���� ��!!\n", count, user);
			count++; win++;
		}

		else if (com == 2 && user == 1) //��
		{
			printf("%d��° ���> %d COM: ����  vs  USER: ���� ��!!\n", count, user);
			count++; lose++;
		}
		else if (com == 3 && user == 2)
		{
			printf("%d��° ���> %d COM: ��  vs  USER: ���� ��!!\n", count, user);
			count++; lose++;
		}
		else if (com == 1 && user == 3)
		{
			printf("%d��° ���> %d COM: ����  vs  USER: �� ��!!\n", count, user);
			count++; lose++;
		}

		else //1~3�� �ƴ� �ٸ� ���ڸ� �Է��� ���
		{
			printf("%d��° ���> %d �߸� �Է��ϼ̽��ϴ�!!\n", count, user);
		}
	}
	
	printf("��������: %d�� %d�� %d�� %d�� (�·� %.1f%%)", times, win, draw, lose, (double)win / times*100);

	return 0;
}

int main(void) //���� �Լ�
{
	RockPaperScissors();
}