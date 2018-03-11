#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int a;
	a = system("ps - ef | grep sssh");
	printf("Return Value : %d\n", a);

	return 0;
}
