#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	in_addr_t addr;
	struct hostent *hp;
	struct in_addr in;

	if ((addr = inet_addr("117.16.42.29")) == (in_addr_t)-1) {
		printf("Error : inet_addr(117.16.65.4\n");
		exit(1);
	}

	hp = gethostbyaddr((char *)&addr, 4, AF_INET);
	if (hp == NULL) {
		(void) printf("Host information not found\n");
		exit(2);
	}

	printf("Name = %s\n", hp->h_name);

	(void) memcpy(&in.s_addr, *hp->h_addr_list, sizeof (in.s_addr)); 0;
	printf("IP = %s\n", inet_ntoa(in));

	return 0;
}
