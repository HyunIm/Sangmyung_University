#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	if (mkdir("han", 0755) == -1) {
		perror("han");
		exit(1);
	}

	if (mkdir("bit", 0755) == -1) {
		perror("bit");
		exit(1);
	}

	if (rename("han", "hanbit") == -1) {
		perror("hanbit");
		exit(1);
	}

	if (rmdir("bit") == -1) {
		perror("bit");
		exit(1);
	}

	return 0;
}
