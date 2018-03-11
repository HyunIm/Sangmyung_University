#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd, fd1;

	fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Create tmp.aaa");
		exit(1);
	}
	printf("fd of tmp.aaa = %d\n", fd);
	close(1);
	fd1 = dup(fd);
	printf("dup fd = %d\n", fd1);
	printf("Output\n");
	close(fd);

	return 0;
}
