// 4��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Swap(int *a, int *b) // a�� b�� ���� ��ȯ���ִ� �Լ�
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int num[10]; // 10���� ����
	srand(time(NULL)); //���� �߻�

	for (int i = 0; i < 10; i++) // ���� �߻��⸦ �̿��Ͽ� �迭�� ����
		num[i] = rand() % 100;

	/*for (int i = 0; i < 10; i++) // ��ȯ �� 10���� ���� ���
		printf("%d ", num[i]);
	printf("\n");*/

	for (int i = 0; i < 10; i++) // Bubble Sorting �������� ����
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (num[i] > num[j])
				Swap(&num[i], &num[j]);
		}
	}

	printf("2��°�� ū �� : %d\n", num[8]); // 2��°�� ū �� ���

	/*for (int i = 0; i < 10; i++) // ��ȯ �� 10���� ���� ���
		printf("%d ", num[i]);*/

	return 0;
}