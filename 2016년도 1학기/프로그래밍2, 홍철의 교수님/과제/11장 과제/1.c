// 201511054 ��ǻ�Ͱ��а� ����
// 1��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[10]; // 10���� ����
	int max, min; // �ִ�, �ּڰ�
	srand(time(NULL)); // ���� �߻�

	for (int i = 0; i < 10; i++) // ���� �߻��⸦ �̿��Ͽ� �迭�� ����
		num[i] = rand() % 100;

	max = min = num[0]; // �ִ�, �ּڰ��� �迭�� ù ��° ������ ����

	for (int i = 1; i < 10; i++) // num[1]���� num[9]����
	{
		if (max < num[i]) // num[i]�� max���� ũ�ٸ� ���� ��ȯ
			max = num[i];
		if (min > num[i]) // num[i]�� min���� �۴ٸ� ���� ��ȯ
			min = num[i];
	}

	printf("�ִ� : %d, �ּڰ� : %d\n", max, min); // �ִ�, �ּڰ� ���

	/*for (int i = 0; i < 10; i++) // 10���� ���� ���
		printf("%d ", num[i]);*/

	return 0;
}