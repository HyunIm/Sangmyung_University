#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	// rmdir()을 이용하여 디렉토리 programming을 지움
	if (rmdir("programming") == -1) {
		perror("programming");
		exit(1);
	}

	return 0;
}
