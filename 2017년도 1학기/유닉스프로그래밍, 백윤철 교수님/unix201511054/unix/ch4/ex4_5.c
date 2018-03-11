#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("Link Max : %ld\n", pathconf(".", _PC_LINK_MAX));
	printf("Name Max : %ld\n", pathconf(".", _PC_NAME_MAX));
	printf("Path Max : %ld\n", pathconf(".", _PC_PATH_MAX));

	return 0;
}
