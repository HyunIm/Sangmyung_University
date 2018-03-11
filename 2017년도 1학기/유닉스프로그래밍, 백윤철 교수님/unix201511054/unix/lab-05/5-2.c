#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	pid_t pid;

	printf("Before fork ...\n");

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}
	if (pid > 0)
		printf("Parent process has pid = %d ppid = %d\n",
				(int)getpid(), (int)getppid());
	else
		printf("Child process has pid = %d ppid = %d\n",
				(int)getpid(), (int)getppid());

	printf("End of fork ...\n");

	return 0;
}
