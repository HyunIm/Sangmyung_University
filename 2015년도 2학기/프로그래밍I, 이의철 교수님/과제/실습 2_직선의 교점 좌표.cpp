#include <stdio.h>

int main (void)
{
	int	slp1, slp2, itc1, itc2;
	double x, y;

	printf("첫번째 직선의 기울기 : ");
	scanf("%d", &slp1);

	printf("첫번째 직선의 y절편 : ");
	scanf("%d", &itc1);

	printf("두번째 직선의 기울기 : ");
	scanf("%d", &slp2);

	printf("두번째 직선의 y절편 : ");
	scanf("%d", &itc2);

	x = (itc2-itc1)/(double)(slp1-slp2);
	y = slp1*x+itc1;

	printf("y=%dx+%d 과 y=%dx+%d 의 교점의 좌표는 (%.3f, %.3f)입니다.\n", slp1, itc1, slp2, itc2, x, y);

	return 0;
}
