/**
* ----------------------------------------
* @title : client.c
* @author : 임현 (201511054@sangmyung.kr)
* @since : 2017 - 06 - 08
* @brief : 인터넷 소켓(클라이언트) 가위바위보 게임
* ----------------------------------------
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 201511054 컴퓨터과학과 임현 개인포트 번호
#define PORTNUM 50013

/**
* @title : void Rule(int argc, char *argv[]);
* @brief : 가위바위보 규칙을 설명해주는 함수 (-h 옵션)
*/
void Rule(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	int sd;
	char buf[256];
	struct sockaddr_in sin;

	// 가위바위보 규칙 (옵션 -h 사용 시 출력)
	Rule(argc, argv);

	// 소켓 파일 기술자 생성
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	// 소켓 경로명 지정
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM); // 50013
	sin.sin_addr.s_addr = inet_addr("117.16.42.29"); // apple.smu.ac.kr

													 // 클라이언트가 서버에 접속 요청
	if (connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("connect");
		exit(1);
	}

	// 데이터 수신 (가위바위보 게임 시작 출력을 받아옴)
	if (recv(sd, buf, sizeof(buf), 0) == -1) {
		perror("recv");
		exit(1);
	}
	printf("%s\n", buf);

	// buf에 입력
	printf("입력 : ");
	scanf("%s", &buf);

	// 데이터 송신 (buf 값을 보냄)
	if (send(sd, buf, strlen(buf) + 1, 0) == -1) {
		perror("send");
		exit(1);
	}

	// 데이터 수신 (가위바위보 결과 값을 받아옴)
	if (recv(sd, buf, sizeof(buf), 0) == -1) {
		perror("recv");
		exit(1);
	}
	printf("%s\n", buf);

	// 소켓 파일 기술자 종료
	close(sd);

	return 0;
}

// 가위바위보 규칙을 설명해주는 함수 (-h 옵션)
void Rule(int argc, char *argv[]) {
	int n;

	// getopt 함수로 인자가 있는지 확인
	while ((n = getopt(argc, argv, "h")) != -1) {
		switch (n) { // 옵션별 기능 수행
		case 'h': // -h 옵션
			printf("\n");
			printf(" ========가위바위보 규칙=========\n");
			printf(" | 가위는 보자기를 자르고,      |\n");
			printf(" | 보자기는 바위를 감싸고,      |\n");
			printf(" | 바위는 가위로 자를 수 없다.  |\n");
			printf(" | 즉, 가위>보자기>바위>가위... |\n");
			printf(" --------------------------------\n");

			break;
		}
	}
}
