#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	unsigned short s;
	int i;
	char buf[80];

	if (argc < 3) {
		return -1;
	}

	i = atoi(argv[1]);

	/* ======== 1.2 취약점 완화 ======== */
	if (i == 0) {	// 0 혹은 string이 들어오면 예외 처리
		printf("Error(1.2) : argv[1] Input Positive Integer\n");
		return -1;
	}

	/* ======== 1.3 취약점 완화 ======== */
	if (i < 0) {	// minus 값이 들어오면 예외 처리
		printf("Error(1.3) : argv[1] Input Positive Integer\n");
		return -1;
	}

	/* ======== 1.1 취약점 완화 ======== */
	if (i >= 80) {	// short에 넣기 전에 예외 처리
		printf("Error(1.1) : Too big memory allocation\n");
		return -1;
	}

	s = i;

	printf("s = %d\n", s);

	/* ======== 2 취약점 완화 ======== */
	if (i < strlen(argv[2])) {	// 복사가 완전히 되지 않았다는 경고
		printf("Waring(2) : Not Completely Copied\n");
	}

	memcpy(buf, argv[2], i);
	buf[i] = '\0';
	printf("%s\n", buf);

	return 0;
}