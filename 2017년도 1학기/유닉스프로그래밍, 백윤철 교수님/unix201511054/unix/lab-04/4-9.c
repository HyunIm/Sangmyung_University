#include <sys/types.h>
#include <sys/times.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CLK_TCK ((clock_t) sysconf(3))

int main(void)
{
	int i;
	time_t t;
	struct tms mytms;
	clock_t t1, t2;

	if ((t1 = times(&mytms)) == -1) {
		perror("times 1");
		exit(1);
	}

	for (i = 0; i < 1000000; i++) {
		printf("%d\n", i);
		time(&t);
	}

	if ((t2 = times(&mytms)) == -1) {
		perror("times 2");
		exit(1);
	}

	printf("real\t%.3fs\n", (double)(t2 - t1) / CLK_TCK);
	printf("user\t%.3fs\n", (double)mytms.tms_utime / CLK_TCK);
	printf("sys\t%.3fs\n", (double)mytms.tms_stime / CLK_TCK);

	return 0;
}
