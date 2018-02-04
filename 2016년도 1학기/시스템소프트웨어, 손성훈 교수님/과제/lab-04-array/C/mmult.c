#include <stdio.h>

int main(void)
{
	int a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	int b[3][4] = { { 7, 8, 9, 1 }, { 2, 3, 4, 5 }, { 6, 7, 8, 9 } };
	int c[2][4];
	int i, j, k;
	int sum;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			sum = 0;
			for (k = 0; k < 3; k++)
				sum = sum + a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%2d  ", c[i][j]);
		printf("\n");
	}

	return 0;
}