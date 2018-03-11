#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SOCKET_NAME	"hbsocket"

int main(void) {
	unlink(SOCKET_NAME);

	return 0;
}
