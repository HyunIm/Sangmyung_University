#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int rfd, wfd, n;
	char buf[10];

	rfd = open("unix.txt", O_RDONLY);
	if (rfd == -1) {
		perror("Open unix.txt");
		exit(1);
	}

	wfd = open("unix.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (wfd == -1) {
	perror("Open unix.bak");
	exit(1);
	}

	while ((n = read(rfd, buf, 6)) > 0)
		if (write(wfd, buf, n) != n) perror("Write");

	if (n == -1) perror("Read");

	close (rfd);
	close (wfd);

	return 0;
}
