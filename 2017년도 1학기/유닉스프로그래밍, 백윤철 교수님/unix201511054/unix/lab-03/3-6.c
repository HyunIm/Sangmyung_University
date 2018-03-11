#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	// rename()을 이용하여 디렉토리 linux를 LINUX로 바꿈
	if (rename("linux", "LINUX") == -1) {
		perror("LINUX");
		exit(1);
	}

	return 0;
}
