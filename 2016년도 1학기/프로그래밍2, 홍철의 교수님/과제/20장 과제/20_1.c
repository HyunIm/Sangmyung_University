#include <stdio.h>

int main(void)
{
	int arr[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int rot[4][4];
	int i, j, k = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%2d  ", arr[i][j]);
		printf("\n");
	}
	printf("\n");

	while (k != 3)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				rot[j][3 - i] = arr[i][j];
		}

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				printf("%2d  ", rot[i][j]);
			printf("\n");
		}
		printf("\n");
		
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				arr[i][j] = rot[i][j];
		}

		k++;
	}

	return 0;
}