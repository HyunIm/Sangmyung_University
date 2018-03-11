#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	pid_t pid;
	int i, status;

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}
	if (pid > 0) {
		printf("Parent %d waits child %d\n", (int)getpid(), (int)pid);
		wait(&status);
		printf("Child's exit status = %x\n", status);
	}
	else
	{
		for (i = 0; i < 5; i++) {
			printf("Child %d executes.\n", (int)getpid());
			sleep(1);
		}
		exit(3);
	}

	return 0;
}
