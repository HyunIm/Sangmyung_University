#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buffer[100];
	char addr[100];

	static char ok_chars[] = "abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQSTUVWXYZ"
		"123456788_-.@";

	gets(addr);

	char *cp = addr;
	const char *end = addr + strlen(addr);

	for (cp += strspn(cp, ok_chars); cp != end; cp += strspn(cp, ok_chars))
	{
		*cp = '_';
	}

	sprintf(buffer, "mail -s \"First Letter\" %s < .bashrc", addr);
	system(buffer);

	return 0;
}