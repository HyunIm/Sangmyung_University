// 2��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num[10]; // 10���� ����
	int even = 0, odd = 0; // ¦��, Ȧ���� ��
	srand(time(NULL)); // ���� �߻�

	for (int i = 0; i < 10; i++) // ���� �߻��⸦ �̿��Ͽ� �迭�� ����
		num[i] = rand() % 100;

	for (int i = 0; i < 10; i++) // num[0]���� num[9]����
	{
		if (num[i] % 2 == 0) // num[i]�� 2�� ���� �������� 0�̸� ¦��
			even += num[i];
		else // �ƴϸ� Ȧ��
			odd += num[i];
	}

	printf("Ȧ���� �� : %d, ¦���� �� : %d\n", odd, even); // Ȧ���� �հ� ¦���� �� ���

	/*for (int i = 0; i < 10; i++) // 10���� ���� ���
		printf("%d ", num[i]);*/

	return 0;
}