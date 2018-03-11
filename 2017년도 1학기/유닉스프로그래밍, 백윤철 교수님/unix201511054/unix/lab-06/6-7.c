#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // strcpy 헤더 파일

/**
 * 함수명 : int ChangeAlphabet(char x);
 * 설명 : 대소문자를 바꿔주는 함수
 */
int ChangeAlphabet(char x);

int main(int argc, char *argv[]) {
	int fd;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;
	int i;

	if (argc != 2) {
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(1);
	}

	if (stat(argv[1], &statbuf) == -1) {
		perror("stat");
		exit(1);
	}

	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror("open");
		exit(1);
	}

	addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE,
			MAP_SHARED, fd, (off_t)0);
	if (addr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
	close(fd);

	switch (pid = fork()) {
		case -1 : /* fork failed */
			perror("fork");
			exit(1);
			break;
		case 0 : /* child process */
			strcpy(addr, "Child test string\n"); // 문자열 써넣기
			break;
		default : /* parent process */
			while (addr[i] != '\0') { // 문자열이 끝날 때 까지
				addr[i] = ChangeAlphabet(addr[i]); // 대소문자 변환
				i++;
			}
			fprintf(stdout, "%s", addr); // stdout으로 출력
			break;
	}

	return 0;
}

int ChangeAlphabet(char x) {
	char y;

	if (x >= 'a' && x <= 'z')
		y = x - 32;
	else if (x >= 'A' && x <= 'Z')
		y = x + 32;
	else
		y = x;

	return y;
}
