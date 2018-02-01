#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PrintString(int val)
{
	if(val == 1) printf("����");
	else if(val == 2) printf("����");
	else if(val == 3) printf("��");
}
void PrintStatus(int com, int user)
{
	printf("��ǻ��: ");
	PrintString(com);
	printf("vs �����: ");
	PrintString(user);
	printf("\n\n");
}
void DetermWDL(int com, int user, int *W, int *D, int *L)
{
	if(com == user) // ��� ���
	{
		printf("�����ϴ�\n");
		(*D)++;
	}
	else if((com == 1 && user == 2) || (com == 2 && user == 3) ||
		(com == 3 && user == 1)) // �̱� ���
	{
		printf("�̰���ϴ�\n");
		(*W)++;
	}
	else
	{
		printf("�����ϴ�\n");
		(*L)++;
	}
}
void PrintWDL(int W, int D, int L)
{
	printf("%d�� %d�� %d�� %d�� (�·�: %.2f)\n", 
		W+D+L, W, D, L, (double)W/(W+D+L));
}
int main()
{
	int com, user;
	int W = 0, D = 0, L = 0;
	int repeat;
	srand((unsigned)time(NULL)); // �����Լ� seed�� ����
	printf("==========================\n");
	printf("==    ���� ���� �� ���� Ver 0.1  ==\n");
	printf("==========================\n\n\n");
	system("pause");
	printf("�� �� �����Ͻðڽ��ϱ�? ");
	scanf("%d", &repeat);
	for(int i=1; i<=repeat; i++)
	{
		printf("\a[%d��° �º�] (����: 1   ����: 2   ��: 3) �Է��ϼ��� > ", i);
		com = rand() % 3 + 1;
		scanf("%d", &user);	
		if(user > 3 || user < 0) 
		{
			printf("�߸� �Է��߽��ϴ�!\n");
			i--;
			continue;
		}
		PrintStatus(com, user);
		DetermWDL(com, user, &W, &D, &L);
	}
	PrintWDL(W, D, L);
	return 0;
}
