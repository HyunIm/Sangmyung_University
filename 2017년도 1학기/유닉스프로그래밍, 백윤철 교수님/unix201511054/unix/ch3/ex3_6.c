#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

int main(void) {
	int per;

	if (access("unix.bak", F_OK) == -1 && errno == ENOENT)
		printf("unix.bak:File not exist.\n");

	per = access("unix.txt", R_OK);
	if (per == 0)
		printf("unix.txt: Read permission is permitted.\n");
	else if (per == -1 && errno == EACCES)
		printf("unix.txt: Read permission is not permitted.\n");

	return 0;
}
