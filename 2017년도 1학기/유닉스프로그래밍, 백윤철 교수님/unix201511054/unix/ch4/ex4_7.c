#include <unistd.h>
#include <pwd.h>
#include <stdio.h>

int main(void) {
	struct passwd *pw;

	pw = getpwuid(getuid());
	printf("UID : %d\n", (int)pw->pw_uid);
	printf("Login Name : %s\n", pw->pw_name);

	return 0;
}
