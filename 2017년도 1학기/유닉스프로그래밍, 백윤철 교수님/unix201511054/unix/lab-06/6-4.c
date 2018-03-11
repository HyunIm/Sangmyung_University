#include <unistd.h>
#include <signal.h>
// #include <siginfo.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int signo) {
	printf("\ncatch SIGINT...\n");
}

int main(void)
{
	int i;
	void (*hand)(int);

	// siganl function
	// parameter : SIGINT(Ctrl+C), handler(시그널 핸들러의 주소)
	hand = signal(SIGINT, handler);
	if (hand == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	for (i = 0; i < 20; i++) {
		printf("sleep 1 second...\n");
		sleep(1);
	}
	return 0;
}
