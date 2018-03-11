#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	if (mkdir("linux", 0755) == -1) {
		perror("linux");
		exit(1);
	}

	if (mkdir("programming", 0644) == -1) {
		perror("programming");
		exit(1);
	}

	return 0;
}
