#include <sys/types.h>
#include <utmpx.h>
#include <stdio.h>

int main(void) {
	struct utmpx *utx;

	while ((utx=getutxent()) != NULL) {
		if (utx->ut_type != USER_PROCESS)
			continue;

		printf("%s %s %d\n", utx->ut_user, utx->ut_line, (int)utx->ut_pid);
	}

	return 0;
}
