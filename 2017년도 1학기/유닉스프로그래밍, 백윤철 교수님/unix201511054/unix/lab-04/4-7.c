#include <stdio.h>

int main(void)
{
	int i;
	long s = 0;

	for (i = 0; i < 1000000; i++)
		s = s + i;
	printf("%ld\n", s);

	return 0;
}
