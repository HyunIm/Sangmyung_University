#include <stdio.h>

int main (void)
{
	int	slp1, slp2, itc1, itc2;
	double x, y;

	printf("ù��° ������ ���� : ");
	scanf("%d", &slp1);

	printf("ù��° ������ y���� : ");
	scanf("%d", &itc1);

	printf("�ι�° ������ ���� : ");
	scanf("%d", &slp2);

	printf("�ι�° ������ y���� : ");
	scanf("%d", &itc2);

	x = (itc2-itc1)/(double)(slp1-slp2);
	y = slp1*x+itc1;

	printf("y=%dx+%d �� y=%dx+%d �� ������ ��ǥ�� (%.3f, %.3f)�Դϴ�.\n", slp1, itc1, slp2, itc2, x, y);

	return 0;
}
