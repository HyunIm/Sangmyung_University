// 3��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[10]; // 10���� ����
	int temp; // ��ȯ�� �� �ӽ��� ����
	srand(time(NULL)); // ���� �߻�

	for (int i = 0; i < 10; i++) // ���� �߻��⸦ �̿��Ͽ� �迭�� ����
		num[i] = rand() % 100;

	/*for (int i = 0; i < 10; i++) // ��ȯ �� 10���� ���� ���
		printf("%d  ", num[i]);
	printf("\n");*/

	for (int i = 0; i < 5; i++) // num[0]���� num[4]����
	{
		temp = num[i];
		num[i] = num[9 - i]; // 0�� 9, 1�� 8, ... ��ȯ
		num[9 - i] = temp;
	}

	/*for (int i = 0; i < 10; i++) // ��ȯ �� 10���� ���� ���
		printf("%d  ", num[i]);*/

	return 0;
}