/**
* ----------------------------------------
* @title : client.c
* @author : ���� (201511054@sangmyung.kr)
* @since : 2017 - 06 - 08
* @brief : ���ͳ� ����(Ŭ���̾�Ʈ) ���������� ����
* ----------------------------------------
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 201511054 ��ǻ�Ͱ��а� ���� ������Ʈ ��ȣ
#define PORTNUM 50013

/**
* @title : void Rule(int argc, char *argv[]);
* @brief : ���������� ��Ģ�� �������ִ� �Լ� (-h �ɼ�)
*/
void Rule(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	int sd;
	char buf[256];
	struct sockaddr_in sin;

	// ���������� ��Ģ (�ɼ� -h ��� �� ���)
	Rule(argc, argv);

	// ���� ���� ����� ����
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	// ���� ��θ� ����
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM); // 50013
	sin.sin_addr.s_addr = inet_addr("117.16.42.29"); // apple.smu.ac.kr

													 // Ŭ���̾�Ʈ�� ������ ���� ��û
	if (connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("connect");
		exit(1);
	}

	// ������ ���� (���������� ���� ���� ����� �޾ƿ�)
	if (recv(sd, buf, sizeof(buf), 0) == -1) {
		perror("recv");
		exit(1);
	}
	printf("%s\n", buf);

	// buf�� �Է�
	printf("�Է� : ");
	scanf("%s", &buf);

	// ������ �۽� (buf ���� ����)
	if (send(sd, buf, strlen(buf) + 1, 0) == -1) {
		perror("send");
		exit(1);
	}

	// ������ ���� (���������� ��� ���� �޾ƿ�)
	if (recv(sd, buf, sizeof(buf), 0) == -1) {
		perror("recv");
		exit(1);
	}
	printf("%s\n", buf);

	// ���� ���� ����� ����
	close(sd);

	return 0;
}

// ���������� ��Ģ�� �������ִ� �Լ� (-h �ɼ�)
void Rule(int argc, char *argv[]) {
	int n;

	// getopt �Լ��� ���ڰ� �ִ��� Ȯ��
	while ((n = getopt(argc, argv, "h")) != -1) {
		switch (n) { // �ɼǺ� ��� ����
		case 'h': // -h �ɼ�
			printf("\n");
			printf(" ========���������� ��Ģ=========\n");
			printf(" | ������ ���ڱ⸦ �ڸ���,      |\n");
			printf(" | ���ڱ�� ������ ���ΰ�,      |\n");
			printf(" | ������ ������ �ڸ� �� ����.  |\n");
			printf(" | ��, ����>���ڱ�>����>����... |\n");
			printf(" --------------------------------\n");

			break;
		}
	}
}
