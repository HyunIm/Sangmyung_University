/**
* ----------------------------------------
*  @title : reset_log.c
*  @author : ���� (201511054@sangmyung.kr)
*  @since : 2017-06-09
*  @brief : log.txt(���� ���) �ʱ�ȭ ���α׷�
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

	// ���� ���� (oflag = ��� ����ų�, ������ ����), (���ٱ��� : 0644)
	fd = open("log.txt", O_TRUNC | O_CREAT, 0644);
	if (fd == -1) {
		perror("Open");
		exit(1);
	}

	close(fd);
}

