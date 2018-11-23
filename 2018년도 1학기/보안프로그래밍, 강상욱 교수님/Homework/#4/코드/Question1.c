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

	/* ======== 1.2 ����� ��ȭ ======== */
	if (i == 0) {	// 0 Ȥ�� string�� ������ ���� ó��
		printf("Error(1.2) : argv[1] Input Positive Integer\n");
		return -1;
	}

	/* ======== 1.3 ����� ��ȭ ======== */
	if (i < 0) {	// minus ���� ������ ���� ó��
		printf("Error(1.3) : argv[1] Input Positive Integer\n");
		return -1;
	}

	/* ======== 1.1 ����� ��ȭ ======== */
	if (i >= 80) {	// short�� �ֱ� ���� ���� ó��
		printf("Error(1.1) : Too big memory allocation\n");
		return -1;
	}

	s = i;

	printf("s = %d\n", s);

	/* ======== 2 ����� ��ȭ ======== */
	if (i < strlen(argv[2])) {	// ���簡 ������ ���� �ʾҴٴ� ���
		printf("Waring(2) : Not Completely Copied\n");
	}

	memcpy(buf, argv[2], i);
	buf[i] = '\0';
	printf("%s\n", buf);

	return 0;
}