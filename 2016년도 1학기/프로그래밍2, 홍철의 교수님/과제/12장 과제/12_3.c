#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void min_max(int arr[], int *ptr)
{
	int max, min;

	// 2.1
	/*max = min = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}*/

	// 2.2
	/*max = min = *(arr);
	for (int i = 1; i < 10; i++)
	{
		if (max < *(arr + i))
			max = *(arr + i);
		if (min > *(arr + i))
			min = *(arr + i);
	}*/

	// 2.3
	/*max = min = *(ptr);
	for (int i = 1; i < 10; i++)
	{
		if (max < *(ptr + i))
			max = *(ptr + i);
		if (min > *(ptr + i))
			min = *(ptr + i);
	}*/

	// 2.4
	/*max = min = ptr[0];
	for (int i = 1; i < 10; i++)
	{
		if (max < ptr[i])
			max = ptr[i];
		if (min > ptr[i])
			min = ptr[i];
	}*/

	// 2.5
	/*max = min = *(ptr);
	for (int i = 0; i < 10; i++)
	{
		if (max < *(ptr))
			max = *(ptr);
		if (min > *(ptr))
			min = *(ptr);
		ptr++;
	}*/

	//printf("max : %d, min : %d\n", max, min);
}

int main(void)
{
	int arr[10];
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100;

	int *ptr = arr;

	min_max(arr, ptr);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}