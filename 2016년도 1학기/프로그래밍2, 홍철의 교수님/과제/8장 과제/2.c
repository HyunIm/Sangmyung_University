// 2��
#include <stdio.h>

int main(void)
{
	int x, y, z, temp;

	while (201511054)
	{
		scanf("%d %d %d", &x, &y, &z); // �� ���� ���� �Է�
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

		if (x < 0 || y < 0 || z < 0) // ���� ���� �Էµ� �� ���α׷� ����
			return 0;
		
		if (x > 0 && y> 0 && z > 0) // �ﰢ�� ���� �˻�
		{
			if (x + y < z) // �ﰢ���� �� �� ����
				printf("�ﰢ���� �� �� �����ϴ�. \n");

			else // �ﰢ���� �� �� ����
			{
				if (x*x + y*y == z*z) // ���� �ﰢ��
					printf("���� �ﰢ���Դϴ�. \n");

				else if (x == y && y == z && z == x) // �� �ﰢ��
					printf("�� �ﰢ���Դϴ�. \n");

				else if (x == y || y == z) // (�� �ﰢ�� ���� �˻� ��) �̵ �ﰢ��
					printf("�̵ �ﰢ���Դϴ�. \n");

				else // �Ϲ� �ﰢ��
					printf("�Ϲ� �ﰢ���Դϴ�. \n");
			}
		}
	}
}