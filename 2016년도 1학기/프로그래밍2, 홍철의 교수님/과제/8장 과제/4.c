// 4��
#include <stdio.h>

int main(void)
{
	int num;

	scanf("%d", &num); // ������ ���� ���� �Է�

	if (num > 0) // ���� ����
	{
		for (int i = 2; i < num; i++) // 2���� num����
		{
			if (num%i == 0) // �Ҽ��� �ƴ� ����
			{
				printf("�Է��� �� %d�� �Ҽ��� �ƴմϴ�.\n", num);
				return 0;
			}
		}

		printf("�Է��� �� %d�� �Ҽ��Դϴ�.\n", num); // �Ҽ� ����
		return 0;
	}

	else // ���� ������ �ƴ� ���� �Է�
		printf("�Է��� �� %d�� ���� ������ �ƴմϴ�.\n", num);
	return 0;
}