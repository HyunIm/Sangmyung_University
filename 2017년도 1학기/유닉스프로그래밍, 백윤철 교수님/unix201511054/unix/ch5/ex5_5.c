#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(void) {
	char **env;

	env = environ;
	while (*env) {
		printf("%s\n", *env);
		env++;
	}

	return 0;
}
