#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("PID : %d\n", (int)getpid());
	printf("PPID : %d\n", (int)getppid());

	return 0;
}
