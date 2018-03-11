#include <time.h>
#include <stdio.h>

char *output = "%G. %m. %d. (%a) %T KST";

int main(void) {
	struct tm *tm;
	int n;
	time_t t;
	char buf[33];

	time(&t);
	tm = localtime(&t);

	strftime(buf, sizeof(buf), output, tm);
	printf("%s\n", buf);

	return 0;
}
