#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int com, user;
	srand((unsigned)time(NULL)); // �����Լ� seed�� ����
	com = rand() % 3 + 1;
	printf("(����: 1   ����: 2   ��: 3) �Է��ϼ��� > ");
	scanf("%d", &user);
	if(user > 3 || user < 0) 
	{
		printf("�߸� �Է��߽��ϴ�!\n");
		return -1;
	}
	//PrintStatus(com, user);
	printf("��ǻ��: %d vs �����: %d\n", com, user);
	if(com == user) // ��� ���
	{
		printf("�����ϴ�\n");
	}
	else if((com == 1 && user == 2) || (com == 2 && user == 3) ||
		(com == 3 && user == 1)) // �̱� ���
	{
		printf("�̰���ϴ�\n");
	}
	else
	{
		printf("�����ϴ�\n");
	}
	return 0;
}
