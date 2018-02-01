#include <stdio.h>
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	if (m > n)
		printf("%d\n", m - n);
	else
		printf("%d\n", n - m);
	return 0;
}