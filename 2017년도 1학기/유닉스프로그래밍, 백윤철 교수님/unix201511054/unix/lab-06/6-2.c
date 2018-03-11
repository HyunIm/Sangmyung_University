#include <stdio.h>

int main(void)
{
	int i;
	
	for (i = 0; i < 20; i++) {
		printf("sleep 1 second...\n");
		sleep(1);
	}
	return 0;
}
