#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int val, i;
	char *mem;

	if (argc < 2)
		exit(1);

	/* ======== 10의 자리가 넘을 경우 예외 처리 ======== */
	if (strlen(argv[1]) >= 10) {
		printf("Error : Input less than 1,000,000,000\n");
		return -1;
	}

	val = atoi(argv[1]);

	if (val > 0) {
		mem = malloc(val * sizeof(char *));

		if (mem == NULL) {
			printf("Failure\n");
			exit(2);
		}
	}

	for (i = 0; i < val; i++) {
		mem[i] = 'A';
		printf("%c", mem[i]);
	}

	printf("\n");

	return 0;
}