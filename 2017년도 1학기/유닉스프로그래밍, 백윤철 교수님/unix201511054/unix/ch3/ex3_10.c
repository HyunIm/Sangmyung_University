#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	struct stat buf;
	char bufc[BUFSIZ];

	printf("1. stat : unix.txt ---\n");
	stat("unix.txt", &buf);
	printf("unix.txt : Link Count = %d\n", (int)buf.st_nlink);
	printf("unix.txt : Inode %d\n", (int)buf.st_ino);

	printf("2. stat : unix.sym ---\n");
	stat("unix.sym", &buf);
	printf("unix.sym : Link Count = %d\n", (int)buf.st_nlink);
	printf("unix.sym : Inode = %d\n", (int)buf.st_ino);

	printf("3. lstat : unix.sym ---\n");
	lstat("unix.sym", &buf);
	printf("unix.sym : Link Count = %d\n", (int)buf.st_nlink);
	printf("unix.sym : Inode = %d\n", (int)buf.st_ino);

	realpath("unix.sym", bufc);
	printf("unix.sym : REALPATH = %s\n", bufc);

	return 0;
}
