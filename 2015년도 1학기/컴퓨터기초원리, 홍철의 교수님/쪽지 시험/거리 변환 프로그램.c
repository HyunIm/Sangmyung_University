#include <stdio.h>

int main(void)
{
	double m1, m2;
	char ch1, ch2;
	printf("�Ÿ� �Է� :  ");
	scanf("%lf %c %c", &m1, &ch1, &ch2);
	if (ch1 == 'm' && ch2 == 'i')
	{
		m2 = m1 * 1.61;
		printf("%fmi -> %fkm", m1, m2);

	}
	else if (ch1 == 'k' && ch2 == 'm')
	{
		m2 = m1 / 1.61;
		printf("%fkm -> %fmi", m1, m2);

	}
	else
		printf("�� �� �Է��ϼ̽��ϴ�.");

	return 0;
}