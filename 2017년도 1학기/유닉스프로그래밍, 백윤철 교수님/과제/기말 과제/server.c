/**
* ----------------------------------------
* @title : server.c
* @author : ���� (201511054@sangmyung.kr)
* @since : 2017 - 06 - 08
* @brief : ���ͳ� ����(����) ���������� ����
* ----------------------------------------
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h> // FileIO
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h> // rand
#include <fcntl.h> // FileIO

// 201511054 ��ǻ�Ͱ��а� ���� ������Ʈ ��ȣ
#define PORTNUM 50013

// ����, ����, ��
static const char *RPS[] = { "����", "����", "��" };
// �¸�, �й�, ���º�
static const char *RESULT[] = { "�¸�", "�й�", "���º�" };

/**
* @title : int ComRps(void)
* @brief : ��ǻ���� ���������� �� ����
*/
int ComRps(void);

/**
* @title : int RpsResult(int user, int com);
* @brief : ��ǻ�Ϳ� ������� ���������� ���
*/
int RpsResult(int user, int com);

/**
* @title : void WriteLog(char str[]);
* @brief : ���� ����� ���Ͽ� �Է��ϴ� �Լ� (�ʱ�ȭ X, ���� �ʱ�ȭ)
*/
void WriteLog(char str[]);

/**
* @title : void MyStat(int win, int lose, int draw, int count);
* @brief : ���� ����� ���Ͽ� �Է��ϴ� �Լ� (���� �簡���� �ʱ�ȭ)
*/
void MyStat(int win, int lose, int draw, int count);

int main(void) {
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);
	int com, user; // ��ǻ�� �� ������� ���������� ��, [����(1), ����(2), ��(3)]
	int win = 0; // �¸� Ƚ��
	int lose = 0; // �й� Ƚ��
	int draw = 0; // ���º� Ƚ��
	int count = 0; // ���� Ƚ��
	int i; // �¸�(1), �й�(2), ���º�(3)

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

	// ���� ���� ����ڸ� ������ IP �ּ�/��Ʈ ��ȣ�� ����(bind)
	if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}

	// Ŭ���̾�Ʈ�� ���� ��û ���
	if (listen(sd, 5)) {
		perror("listen");
		exit(1);
	}

	// �ݺ� ����
	while (201511054) {
		// Ŭ���̾�Ʈ�� ���� ���
		if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
			perror("accept");
			exit(1);
		}

		// ���������� ���� ���� ���
		sprintf(buf, "\n===============���������� ����===============\n\n1(����), 2(>����), 3(��) �� �ϳ��� �Է��Ͻʽÿ�.\n");
		// ������ �۽� (���� ȭ�� ���)
		if (send(ns, buf, strlen(buf) + 1, 0) == -1) {
			perror("send");
			exit(1);
		}

		// ������ ���� (buf ��(����, ����, ��)�� ������)
		if (recv(ns, buf, sizeof(buf), 0) == -1) {
			perror("recv");
			exit(1);
		}

		user = atoi(buf); // ����� ���������� �� ���� (�ƽ�Ű -> ��Ƽ��)
		com = ComRps(); // ��ǻ�� ���������� �� ���� (rand�Լ�)
						// ���������� ���
		i = RpsResult(user, com);

		// ���������� ��� ���
		sprintf(buf, "\n����� : %s vs ��ǻ�� : %s \n%s �ϼ̽��ϴ�!\n", RPS[user - 1], RPS[com - 1], RESULT[i - 1]);
		// ������ �۽� (���������� ��� ���� ����)
		if (send(ns, buf, strlen(buf) + 1, 0) == -1) {
			perror("send");
			exit(1);
		}

		// �α� ��� �Լ�
		WriteLog(buf);

		// ��, ��, ��, �� ����
		switch (i) {
		case 1: win++; break;
		case 2: lose++; break;
		case 3: draw++; break;
		}
		count++;

		// ���� ��� �Լ�
		MyStat(win, lose, draw, count);
	}

	// ���� ���� ����� ����
	close(ns);
	close(sd);

	return 0;
}

// ��ǻ���� ���������� �� ����
int ComRps(void) {
	int com; // ��ǻ���� ���������� ��
	srand((unsigned)time(NULL));
	com = rand() % 3 + 1; // 1 ~ 3 ������ ���� ����

	return com;
}

// ��ǻ�Ϳ� ������� ���������� ���
int RpsResult(int user, int com) {
	int i;

	if (user == com) // ���º� (���� ���)
		i = 3;

	else { // ���ºΰ� �ƴ� ���
		switch (user) { // ������� ���� ����
		case 1: i = (com == 3 ? 1 : 2); break;
		case 2: i = (com == 1 ? 1 : 2); break;
		case 3: i = (com == 2 ? 1 : 2); break;
		}
	}

	// i = 1(�¸�), i = 2(�й�), i = 3(���º�)
	return i;
}

// ���� ����� ���Ͽ� �Է��ϴ� �Լ�
void WriteLog(char str[]) {
	int fd;
	int n;

	// log.txt ���Ͽ� �Է�
	fd = open("log.txt", O_WRONLY | O_APPEND); // ���� ����, �̾� ����
	if (fd == -1) {
		perror("Open");
		exit(1);
	}

	// buf��(���������� ��� ��)�� ���Ͽ� ����
	n = write(fd, str, strlen(str));
	if (n != strlen(str)) {
		perror("Write");
		exit(2);
	}
	close(fd);
}

// ���� ����� ���Ͽ� �Է��ϴ� �Լ�
void MyStat(int win, int lose, int draw, int count) {
	int fd;
	int n;
	char str[256];

	// ��, ��, ��, ��, �·� ���
	sprintf(str, "%d �� \t %d �� \t %d �� \t %d �� \n�·� : %1.f%%\n", count, win, draw, lose, (double)win / count * 100);

	// mystat.txt ���Ͽ� �Է�
	fd = open("mystat.txt", O_WRONLY); // ���� ����
	if (fd == -1) {
		perror("Open");
		exit(1);
	}

	// ������ ���Ͽ� ����
	n = write(fd, str, strlen(str));
	if (n != strlen(str)) {
		perror("Write");
		exit(2);
	}
	close(fd);
}
