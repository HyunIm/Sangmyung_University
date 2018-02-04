#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void One(void)
{
	int num[54];
	int m, i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("정수 값 m을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		num[i] += m;
		printf("%d ", num[i]);
	}
	printf("\n");
}

void Two(void)
{
	int num[54];
	int m, i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("정수 값 m을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		num[i] -= m;
		printf("%d ", num[i]);
	}
	printf("\n");
}

void Three(void)
{
	int num[54];
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		num[i] += i;
		printf("%d ", num[i]);
	}
	printf("\n");
}

void Four(void)
{
	int num[54];
	int i;
	int sum = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
		sum += num[i];

	printf("배열에 저장된 값의 합 : %d \n", sum);
}

void Five(void)
{
	int num[54];
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (num[i] % 2 == 1)
			printf("%d ", num[i]);
	}
	printf("\n");
}

void Six(void)
{
	int num[54];
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (num[i] % 2 == 0)
			printf("%d ", num[i]);
	}
	printf("\n");
}

void Seven(void)
{
	int num[54];
	int i;
	int sum = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (i % 2 == 1)
			sum += num[i];
	}

	printf("홀수 번째에 저장된 배열 원소의 합 : %d \n", sum);
}

void Eight(void)
{
	int num[54];
	int i;
	int sum = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (i % 2 == 0) // 0은 짝수일 때
			sum += num[i];
	}

	printf("짝수 번째에 저장된 배열 원소의 합 : %d \n", sum);
}

void Nine(void)
{
	int num[54];
	int m, i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("정수 값 m을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (i%m == 0 && i != 0)
			printf("%d ", num[i]);
	}
	printf("\n");
}

void Ten(void)
{
	int num[54];
	int m, i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("정수 값 m을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	for (i = 53; i >= 0; i--)
	{
		if (i%m == 0 && i != 0)
			printf("%d ", num[i]);
	}
	printf("\n");
}

void Eleven(void)
{
	int num[54];
	int s, i;
	int j = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("특정 값 입력 : ");
	scanf("%d", &s);
	printf("\n");

	for (i = 0; i < 54; i++)
	{
		if (num[i] == s)
		{
			printf("num[%d] ", i);
		}
		else if (num[i] != s)
			j++;
	}

	if (j == 54)
		printf("특정 값이 배열 내에 없습니다.");

	printf("\n");
}

void Twelve(void)
{
	int num[54];
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 53; i >= 0; i--)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}

void Thirteen(void)
{
	int num[54];
	int m, i, swap;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("m값을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	while (201511054)
	{
		if (m > 53)
		{
			printf("m 값이 53보다 큽니다. 다시 입력해주세요. (최댓값 : 53)\n");
			printf("m 값을 입력 : ");
			scanf("%d", &m);
			printf("\n");
		}
		else
			break;
	}

	swap = num[m];
	num[m] = num[i - 1 - m];
	num[i - 1 - m] = swap;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");
}

void Fourteen(void)
{
	int num[54];
	int i, max, min, x, n;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	max = min = num[0];

	for (i = 0; i < 54; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			x = i;
		}
		if (min > num[i])
		{
			min = num[i];
			n = i;
		}
	}

	printf("배열에 저장된 값 중 가장 큰 값이 있는 위치 : num[%d] = %d\n", x, max);
	printf("배열에 저장된 값 중 가장 작은 값이 있는 위치 : num[%d] = %d\n", n, min);
}

void Fifteen(void)
{
	int num[54];
	int i, max, min, x, n;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	max = min = num[0];

	for (i = 0; i < 54; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			x = i;
		}
		if (min > num[i])
		{
			min = num[i];
			n = i;
		}
	}

	num[x] = min;
	num[n] = max;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");
}

void Sixteen(void)
{
	int num[54];
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 53; i++)
		num[i] += num[i + 1];

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");
}

void Seventeen(void)
{
	int num[54];
	int i, f;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	f = num[0];

	for (i = 0; i < 53; i++)
		num[i] = num[i + 1];

	num[i] = f;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");
}

void Eighteen(void)
{
	int num[54], inv[54];
	int i, j = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
		inv[i] = num[i];

	for (i = 53; i >= 0; i--, j++)
		num[i] = inv[j];

	/*for (i = 0; i < 54; i++)
	printf("%d ", num[i]);
	printf("\n");*/
}

void Nineteen(void)
{
	int num[54];
	int m, i, swap;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	printf("m값을 입력 : ");
	scanf("%d", &m);
	printf("\n");

	while (201511054)
	{
		if (m > 53)
		{
			printf("m 값이 53보다 큽니다. 다시 입력해주세요. (최댓값 : 53)\n");
			printf("m 값을 입력 : ");
			scanf("%d", &m);
			printf("\n");
		}
		else
			break;
	}

	swap = num[m];
	num[m] = num[i - 1 - m];
	num[i - 1 - m] = swap;

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");
}

void Max_Min(int num[], int * max, int * min, int * x, int * n)
{
	int i;
	*max = *min = num[0];

	for (i = 0; i < 54; i++)
	{
		if (*max < num[i])
		{
			*max = num[i];
			*x = i;
		}
		if (*min > num[i])
		{
			*min = num[i];
			*n = i;
		}
	}
}

void Twenty(void)
{
	int num[54];
	int i, max, min, x, n;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	Max_Min(num, &max, &min, &x, &n);

	printf("배열에 저장된 값 중 가장 큰 값이 있는 위치 : num[%d] = %d\n", x, max);
	printf("배열에 저장된 값 중 가장 작은 값이 있는 위치 : num[%d] = %d\n", n, min);

	num[x] = min;
	num[n] = max;
}

void TwentyOne(void)
{
	int num[54], inv[54];
	int i, j = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 54; i++)
		inv[i] = num[i];

	for (i = 53; i >= 0; i--, j++)
		num[i] = inv[j];

	for (i = 0; i < 54; i++)
		printf("%d ", num[i]);
	printf("\n");
}

void TwentyTwo(void)
{
	int num[54], frq[110];
	int i, j, n, m = 0, max;

	srand((unsigned)time(NULL));
	for (i = 0; i < 54; i++)
	{
		num[i] = rand() % 110;
		printf("%d ", num[i]);
	}
	printf("\n");

	for (i = 0; i < 110; i++)
		frq[i] = 0;

	for (i = 0; i < 53; i++)
	{
		for (j = i + 1; j < 54; j++)
		{
			if (num[i] == num[j])
			{
				n = num[i];
				frq[n] += 1;
			}
		}
	}

	max = frq[0];
	for (i = 1; i < 110; i++)
	{
		if (max < frq[i])
		{
			max = frq[i];
			m = i;
		}
	}

	printf("빈도수가 가장 많은 값은 %d입니다\n", m);
}

void TwentyThree(void)
{
	int num[5][5];
	int i, j, sum;

	srand((unsigned)time(NULL));
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			num[i][j] = rand() % 10;
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 4; j++)
			sum += num[i][j];
		num[i][4] = sum;
	}

	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 4; j++)
			sum += num[j][i];
		num[4][i] = sum;
	}

	num[4][4] = 0;

	for (i = 0; i < 4; i++)
		num[4][4] += num[i][4];

	/*for (i = 0; i < 5; i++)
	{
	for (j = 0; j < 5; j++)
	printf("%d ", num[i][j]);
	printf("\n");
	}
	printf("\n");*/

	for (i = 0; i < 4; i++)
		printf("%d번째 행의 합 : %d\n", i + 1, num[i][4]);
	printf("\n");
	for (i = 0; i < 4; i++)
		printf("%d번째 열의 합 : %d\n", i + 1, num[4][i]);
	printf("\n");
	printf("총 합 : %d\n", num[4][4]);
	printf("\n");
}


int main(void)
{
	int number;
	printf("과제명 : 배열 과제\n");
	printf("교과목명 : 프로그래밍2, 홍철의 교수님\n");
	printf("201511054 컴퓨터과학과 임현\n\n");

	while (201511054)
	{
		printf("\n\n원하시는 과제 번호를 입력해주세요. (1~23번까지, 0을 누를 때 까지 반복됩니다.)\n");
		printf("과제 번호 : ");
		scanf("%d", &number);
		system("cls");

		printf("\n과제 번호 : %d\n\n", number);

		if (number == 0)
			break;

		else if (number == 1)
			One();
		else if (number == 2)
			Two();
		else if (number == 3)
			Three();
		else if (number == 4)
			Four();
		else if (number == 5)
			Five();
		else if (number == 6)
			Six();
		else if (number == 7)
			Seven();
		else if (number == 8)
			Eight();
		else if (number == 9)
			Nine();
		else if (number == 10)
			Ten();
		else if (number == 11)
			Eleven();
		else if (number == 12)
			Twelve();
		else if (number == 13)
			Thirteen();
		else if (number == 14)
			Fourteen();
		else if (number == 15)
			Fifteen();
		else if (number == 16)
			Sixteen();
		else if (number == 17)
			Seventeen();
		else if (number == 18)
			Eighteen();
		else if (number == 19)
			Nineteen();
		else if (number == 20)
			Twenty();
		else if (number == 21)
			TwentyOne();
		else if (number == 22)
			TwentyTwo();
		else if (number == 23)
			TwentyThree();
		else
			printf("1~23 사이의 값을 입력해주세요.");
	}
	return 0;
}