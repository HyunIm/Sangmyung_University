// 5��
#include <stdio.h>

int main(void)
{
	int num; // ���� n
	int fgr; // ���ڸ�
	int sum = 0; // �� �ڸ��� ��

	scanf("%d", &num); // ���� n �Է�

	do
	{
		fgr = num % 10; // fgr�� num�� ���ڸ�
		num -= fgr; // num���� fgr�� ���� ���ڸ��� 0���� ����
		num /= 10; // num�� 10���� ������ �ڸ����� ����
		sum += fgr; // sum ���� fgr�� ����
	} while (num > 0); // ���ǹ�

	printf("%d\n", sum); // �� �ڸ����� ��

	return 0;
}