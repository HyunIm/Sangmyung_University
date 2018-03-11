#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf;

	stat("unixdir", &buf);
	printf("Mode = %o (16w진수 : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	if(S_ISFIFO(buf.st_mode)) printf("unix.txt : FIFO\n");
	if(S_ISDIR(buf.st_mode)) printf("unixdir : Directory\n");
	if(S_ISREG(buf.st_mode)) printf("unix.txt : Regualr File\n");

	return 0;
}
