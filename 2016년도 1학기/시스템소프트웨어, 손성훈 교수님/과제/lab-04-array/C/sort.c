#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int array[10] = { 3, 1, 5, 7, 2, 8, 4, 9, 6, 10 };
	int size = 10;
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
				swap(&array[i], &array[j]);
		}
	}

	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}