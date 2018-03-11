#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	chmod("tmp.aaa", 0777);

	return 0;
}
