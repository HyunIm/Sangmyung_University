#include <stdio.h>

int main(void)
{
	int array[10] = { 3, 1, 5, 7, 2, 8, 4, 9, 6, 10 };
	int size = 10;
	int eax, i;
	int ebx = 0;

	scanf("%d", &eax);

	for (i = 0; i < size; i++)
	{
		if (eax == array[i])
			printf("%d\n", i);
		else
			ebx++;
	}
	
	if (ebx == size)
		printf("-1\n");

	return 0;
}