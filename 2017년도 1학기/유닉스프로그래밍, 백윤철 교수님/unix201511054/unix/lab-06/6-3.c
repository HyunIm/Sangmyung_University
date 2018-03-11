#include <unistd.h>
#include <signal.h>
// #include <siginfo.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	void (*hand)(int);

	// siganl function
	// parameter : SIGINT(Ctrl+C), SIG_IGN(시그널 무시)
	hand = signal(SIGINT, SIG_IGN);
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
