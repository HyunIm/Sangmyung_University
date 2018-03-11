#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	pid_t pid;

	switch (pid = fork()) {
		case -1 : /* fork failed */
			perror("fork");
			exit(1);
			break;
		case 0 : /* child process */
			printf("Child Process - My PID:%d, My Parent's PID:%d\n", 
					(int)getpid(), (int)getppid());
			break;
		default : /* parent process */
			printf("Parent process - My PID:%d, My Parent's PID:%d, " "My Child's PID:%d\n", 
					(int)getpid(), (int)getppid(), (int)pid);
			break;
	}

	printf("End of fork\n");

	return 0;
}
