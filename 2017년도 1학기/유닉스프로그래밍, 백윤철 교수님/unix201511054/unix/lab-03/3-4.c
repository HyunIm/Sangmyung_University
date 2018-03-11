#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	struct stat buf;

	stat("password.txt", &buf);
	printf("Link Count before link()= %d\n", (int)buf.st_nlink);

	link("password.txt", "password.ln");

	stat("password.txt", &buf);
	printf("Link Count after link()= %d\n", (int)buf.st_nlink);

	stat("password.ln", &buf);
	printf("Link Count of password.ln= %d\n", (int)buf.st_nlink);

	symlink("password.txt", "password.sln");

	stat("password.txt", &buf);
	printf("Link Count of password.txt= %d\n", (int)buf.st_nlink);

	stat("password.sln", &buf);
	printf("Link Count of password.sln= %d\n", (int)buf.st_nlink);

	lstat("password.sln", &buf);
	printf("Link Count of password.sln itself= %d\n", (int)buf.st_nlink);

	return 0;
}
