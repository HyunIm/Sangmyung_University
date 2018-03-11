#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf;

	chmod("unix.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);
	stat("unix.txt", &buf);
	printf("1. Mode = %d\n", (unsigned int)buf.st_mode);

	buf.st_mode |= S_IWGRP;
	buf.st_mode &= ~(S_IROTH);
	chmod("unix.txt", buf.st_mode);
	stat("unix.txt", &buf);
	printf("2. Mode = %d\n", (unsigned int)buf.st_mode);

	return 0;
}
