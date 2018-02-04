#include <stdio.h>

int main(void)
{
	int snail[80][80];
	int i, j, n, m, x, y, a, k;
	x = 0, y = -1, a = 1, k = 0;

	printf("숫자를 입력하시오 : ");
	scanf("%d", &n);
	m = n;

	while (201511054)
	{
		for (i = 0; i < m; i++)
			snail[x][y += a] = ++k;
		m -= 1;

		if (k == n * n)
			break;

		for (i = 0; i < m; i++)
			snail[x += a][y] = ++k;
		a *= -1;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d  ", snail[i][j]);
		printf("\n");
	}

	return 0;
}