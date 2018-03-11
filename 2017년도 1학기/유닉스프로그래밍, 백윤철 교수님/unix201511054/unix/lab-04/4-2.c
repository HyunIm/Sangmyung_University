#include <pwd.h>
#include <stdio.h>

int main(void) {
	struct passwd *pw;

	pw = getpwnam("unix201511054");
	printf("UID : %d\n", (int)pw->pw_uid);
	printf("Comment : %s\n", pw->pw_gecos);
	printf("Home Directory : %s\n", pw->pw_dir);
	printf("Shell : %s\n", pw->pw_shell);

	return 0;
}
