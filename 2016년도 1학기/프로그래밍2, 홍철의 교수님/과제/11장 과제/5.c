// 5��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Search(int num[], int ip) // �˻��Լ�
{
	for (int i = 0; i < 10; i++) // num[0]���� num[9]����
	{
		if (num[i] == ip) // num[i]�� ip�� ���ٸ�
			return ip; // ip ��ȯ
	}
	return -1; // ã�� �� �� ��� -1 ��ȯ
}

int main(void)
{
	int num[10]; // 10���� ����
	int ip; // ã���� �ϴ� ��
	srand(time(NULL)); // ���� �߻�

	for (int i = 0; i < 10; i++) // ���� �߻��⸦ �̿��Ͽ� �迭�� ����
		num[i] = rand() % 100;

	scanf("%d", &ip); // ã���� �ϴ� �� �Է�

	printf("%d\n", Search(num, ip)); // ã�� �� ���

	/*for (int i = 0; i < 10; i++) // 10���� ���� ���
	printf("%d ", num[i]);*/

	return 0;
}