#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i;
	char template[] = "/tmp/tempXXXXXX";
	char *fname = "/tmp/tempXXXXXX";

	i = mkstemp(template);

	write (i, fname, sizeof(fname)-1);
	printf("TMP File Name(mkstemp) : %s\n", fname);

	close(i);

	return 0;
}
