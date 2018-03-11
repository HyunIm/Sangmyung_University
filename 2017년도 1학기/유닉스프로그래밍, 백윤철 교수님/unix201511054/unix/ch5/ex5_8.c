#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char *val;

	val = getenv("SHELL");
	if (val == NULL)
		printf("SHELL not defined\n");
	else
		printf("1. SHELL = %s\n", val);

	putenv("SHELL=/usr/bin/csh");

	val = getenv("SHELL");
	printf("2. SHELL = %s\n", val);

	return 0;
}
