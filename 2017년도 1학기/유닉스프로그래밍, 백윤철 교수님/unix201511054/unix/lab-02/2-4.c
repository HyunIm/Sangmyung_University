#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)	{
	int fd, n;
	off_t start, cur;
	char buf[256];

	fd = open("2-1.txt", O_RDONLY);
	if (fd == -1)	{
		perror("Open unix.txt");
		exit(1);
	}

	start = lseek(fd, 0, SEEK_CUR);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start=%d, Read Str=%s, n=%d\n", (int) start, buf, n);
	cur = lseek(fd, 0, SEEK_CUR);
	printf("Offset cur=%d\n", (int)cur);

	start = lseek(fd, 7, SEEK_SET);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start=%d, Read Str=%s", (int)start, buf);

	close (fd);

	return 0;
}
