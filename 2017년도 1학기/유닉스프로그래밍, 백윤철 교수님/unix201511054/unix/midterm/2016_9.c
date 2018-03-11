#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void cleanup (void) {
	printf("Cleanup id called\n");
}

int main (void) {

	int pid;

	atexit(cleanup);
	if(pid = fork()) {
		printf("%d forks %d\n", getpid(), pid);
		while(wait() != pid)
			continue;
		printf("%d exits\n", pid);
		printf("%d exits\n", getpid());
		exit(0);
	}
	else {
		printf("%d executes ls command\n", getpid());
		if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
				perror("execlp");
				exit(1);
		}
		printf("%d exits and returns to %d\n", getpid(), getppid());
		exit(2);
	}
	return 0;
}
