#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf;

	stat("unix.txt", &buf);

	printf("Inode = %d\n", (int)buf.st_ino);
	printf("Mode = %d\n", (unsigned int)buf.st_mode);
	printf("Nlink = %o\n", (unsigned int) buf.st_nlink);
	printf("UID = %d\n", (int)buf.st_uid);
	printf("GID = %d\n", (int) buf.st_gid);
	printf("SIZE = %d\n", (int)buf.st_size);
	printf("Atime = %d\n", (int)buf.st_atime);
	printf("Mtime = %d\n", (int)buf.st_mtime);
	printf("CTime = %d\n", (int)buf.st_ctime);
	printf("Blksize = %d\n", (int)buf.st_blksize);
	printf("Blocks = %d\n", (int)buf.st_blocks);
	// printf("FStype = %s\n", buf.st_fstype);

	return 0;
}
