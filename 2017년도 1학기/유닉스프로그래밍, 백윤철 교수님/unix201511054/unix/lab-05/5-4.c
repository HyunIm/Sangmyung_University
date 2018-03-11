#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	pid_t pid;
	char *a[3];

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}
	if (pid > 0) {
		printf("Parent %d executes.\n", (int)getpid());
	}
	else
	{
		printf("Child %d executes.\n", (int)getpid());
		a[0] = "ls";
		a[1] = "-a";
		a[2] = NULL;
		if(execv("/bin/ls", a) == -1) {
			perror("exec");
			exit(2);
		}
	}

	return 0;
}
