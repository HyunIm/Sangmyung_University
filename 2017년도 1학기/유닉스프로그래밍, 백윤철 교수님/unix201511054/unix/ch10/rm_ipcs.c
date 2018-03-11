#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	key_t key;
	int msgid;

	key = ftok("shmfile", 1);
	msgid = msgget(key, IPC_CREAT|0644);
	if (msgid == -1) {
		perror("msgget");
		exit(1);
	}

	printf("Before IPC_RMID\n");
	system("ipcs -qc");
	msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL);
	printf("After IPC_RMID\n");
	system("ipcs -qc");

	return 0;
}
