#include <stdio.h>

int Stringcomp(char string1[], char string2[])
{
	int i = 0;

	while (string1[i] == string2[i])
	{
		if (string1[i++] == '\0')
			return 0;	
	}

	return (string1[i] < string2[i]) ? -1 : 1;
}

int main(void)
{
	char string1[80];
	char string2[80];

	scanf("%s", string1);
	scanf("%s", string2);

	printf("%d\n", Stringcomp(string1, string2));

	return 0;
}