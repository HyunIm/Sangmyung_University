/**
 * ----------------------------------------
 *  @title : reset_log.c
 *  @author : 임현 (201511054@sangmyung.kr)
 *  @since : 2017-06-09
 *  @brief : log.txt(게임 기록) 초기화 프로그램
 *  ----------------------------------------
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd;

	// 파일 열기 (oflag = 모두 지우거나, 파일을 만듬), (접근권한 : 0644)
	fd = open("log.txt", O_TRUNC | O_CREAT, 0644);
	if (fd == -1) {
		perror("Open");
		exit(1);
	}

	close (fd);
}

