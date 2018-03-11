#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int cnt;

	cnt = unlink("tmp.aaa");
	if (cnt == -1) {
		perror("Unlink tmp.aaa");
		exit(1);
	}

	printf("Unlink tmp.aaa success!!!\n");

	return 0;
}
