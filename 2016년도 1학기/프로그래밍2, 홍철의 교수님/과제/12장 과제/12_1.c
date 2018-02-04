#include <stdio.h>

int main(void)
{
	char a[3];
	short b[3];
	int c[3];
	long d[3];
	long long e[3];
	float f[3];
	double g[3];
	long double h[3];

	printf("char : %p %p %p\n", a, a + 1, a + 2);
	printf("short : %p %p %p\n", b, b + 1, b + 2);
	printf("int : %p %p %p\n", c, c + 1, c + 2);
	printf("long : %p %p %p\n", d, d + 1, d + 2);
	printf("long long : %p %p %p\n", e, e + 1, e + 2);
	printf("float : %p %p %p\n", f, f + 1, f + 2);
	printf("double : %p %p %p\n", g, g + 1, g + 2);
	printf("long double : %p %p %p\n", h, h + 1, h + 2);

	printf("\n");

	printf("char : %d\n", (unsigned)(&a[1]) - (unsigned)(&a[0]));
	printf("short : %d\n", (unsigned)(&b[1]) - (unsigned)(&b[0]));
	printf("int : %d\n", (unsigned)(&c[1]) - (unsigned)(&c[0]));
	printf("long : %d\n", (unsigned)(&d[1]) - (unsigned)(&d[0]));
	printf("long long : %d\n", (unsigned)(&e[1]) - (unsigned)(&e[0]));
	printf("float : %d\n", (unsigned)(&f[1]) - (unsigned)(&f[0]));
	printf("double : %d\n", (unsigned)(&g[1]) - (unsigned)(&g[0]));
	printf("long double : %d\n", (unsigned)(&h[1]) - (unsigned)(&h[0]));

	return 0;
}