#include <netdb.h>
#include <stdio.h>

int main(void) {
	struct servent *port;
	int n;

	setservent(0);

	for (n = 0; n < 5; n++) {
		port = getservent();
		printf("Name=%s, Port=%d\n", port->s_name, port->s_port);
	}

	endservent();

	return 0;
}
