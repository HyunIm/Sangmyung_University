#include <stdlib.h>
#include <stdio.h>

int main(void)	{
	FILE *rfp, *wfp;
	char buf[BUFSIZ];
	int n;

	if ((rfp = fopen("2-1.txt", "r")) == NULL) {
		perror("fopen: 2-1.txt");
		exit(1);
	}

	if ((wfp = fopen("2-5.txt", "w")) == NULL) {
		perror("fopen: 2-5.txt");
		exit(1);
	}

	while ((n = fread(buf, sizeof(char)*2, 3, rfp)) > 0) {
		fwrite(buf, sizeof(char)*2, n, wfp);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}
