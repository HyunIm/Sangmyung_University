//3��
#include <stdio.h>

int main(void)
{
	int i, j; // �� ���� ����
	int temp; // i�� �� Ŭ ��� �ٲ��� ����
	int sum = 0; // ��� Ȧ���� ��

	scanf("%d %d", &i, &j); // �� ���� ���� �Է�

	if (i > j) // i�� �� Ŭ ��� i�� j�� ���� �ٲ���
	{
		temp = i;
		i = j;
		j = temp;
	}

	for (; i < j; i++) // i���� j����
	{
		if (i % 2 == 1) // Ȧ�� ����
			sum += i; // i�� �տ� ������
	}

	printf("%d\n", sum); // �� ���

	return 0;
}