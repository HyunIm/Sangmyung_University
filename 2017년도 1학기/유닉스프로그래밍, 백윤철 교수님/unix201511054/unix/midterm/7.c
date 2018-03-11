#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, i;
	int a, b;

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d + %d = %d\n", a, b, a+b);

	return 0;
}
