#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
	symlink("unix.txt", "unix.sym");

	return 0;
}
