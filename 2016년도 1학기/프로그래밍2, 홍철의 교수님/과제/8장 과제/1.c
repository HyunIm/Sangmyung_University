// 1��
#include <stdio.h>

int main(void)
{
	int x, y, z, temp;

	scanf("%d %d %d", &x, &y, &z); //�� �� �Է�
	// �������� ����
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	if (x > z)
	{
		temp = x;
		x = z;
		z = temp;
	}

	if (y > z)
	{
		temp = y;
		y = z;
		z = temp;
	}

	printf("%d", z); //���� ū �� ���

	return 0;
}