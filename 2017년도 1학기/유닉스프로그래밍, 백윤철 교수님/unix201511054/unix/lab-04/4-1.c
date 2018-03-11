#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("Max Arg Lenght : %ld\n", sysconf(_SC_ARG_MAX));
	printf("Max Processes UID : %ld\n", sysconf(_SC_CHILD_MAX));
	printf("Clock Tick : %ld\n", sysconf(_SC_CLK_TCK));
	printf("Max Open File : %ld\n", sysconf(_SC_OPEN_MAX));
	printf("Indicates Posix Version : %ld\n", sysconf(_SC_VERSION));
	
	return 0;
}
