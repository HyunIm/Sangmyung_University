// 201511054 ��ǻ�Ͱ��а� ����

#include <stdio.h>

int Eucl(int i, int j) // ��Ŭ���� �˰��� (�ִ����� �Լ�)
{
	int tmp;
	tmp = i%j; // i ������ j�� ������ ��

	if (tmp == 0) // �������� 0�� �� �� ����
		return j;
	else
		return Eucl(j, tmp); // �ٽ� �� �� �Լ���
}

int main(void)
{
	int a, b; // �� ��
	int temp; // ū �� ��
	scanf("%d %d", &a, &b); // �� �� �Է�

	if (a < b) // ���� b�� �� Ŭ ��� ��ü
	{
		temp = a;
		a = b;
		b = temp;
	}

	printf("%d\n", Eucl(a, b)); // �ִ����� ���

	return 0;
}