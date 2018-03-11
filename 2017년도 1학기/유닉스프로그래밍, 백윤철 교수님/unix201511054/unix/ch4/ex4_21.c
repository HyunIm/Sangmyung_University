#include <time.h>
#include <stdio.h>

int main(void) {
	time_t t;

	time(&t);

	printf("Time(sec) : %d\n", (int)t);
	printf("Time(date) : %s\n", ctime(&t));

	return 0;
}
