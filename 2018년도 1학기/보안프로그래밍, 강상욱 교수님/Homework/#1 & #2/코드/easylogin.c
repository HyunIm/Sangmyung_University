#include <unistd.h>

int main(int argc, char *argv[])
{
	execl("/bin/login", "login",
		"-p",
		"-f", argv[1],
		NULL);

	return 0;
}