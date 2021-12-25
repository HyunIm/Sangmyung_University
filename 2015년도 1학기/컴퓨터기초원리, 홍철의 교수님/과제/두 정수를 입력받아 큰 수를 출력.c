#include <stdio.h>
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	if (m > n)
		printf("%d\n", m);
	else
		printf("%d\n", n);

	return 0;
}