/***
 * 작성자 : 201511054 컴퓨터과학과 임현
 * 날  짜 : 2017 - 03 - 15
 * 파일명 : 1-2.c
*/

#include <stdio.h>
#include <stdlib.h>	// atoi, strtol 함수 헤더 파일.

int main(int argc, char *argv[])
{
	int i, n;
	int sum = 0;	// 두 변수의 합.

	if (argc == 3)	// 옵션이 없을 경우.
	{
		for (i = 0; i < argc; i++)	// 아스키 값을 정수로 바꿔줌.
			sum += atoi(argv[i]);

		printf("%d %X\n", sum, sum);	// sum의 10진수, 16진수 출력.
	}

	while ((n = getopt(argc, argv, "x:")) != -1)	// 'x' 옵션을 사용할 것.
	{
		switch(n)
		{
			case 'x':	// 옵션에 'x'가 나올 경우
				for (i = 0; i < argc; i++)	// 16진수 아스키 값을 정수로 바꿔줌.
					sum += (int)strtol(argv[i], NULL, 16);

				printf("%d %X\n", sum, sum);	// sum의 10진수, 16진수 출력.
				break;

			default:	// 'x'를 제외한 다른 옵션이 나올 경우.
				printf("Usage: 1-2 [-x] n1 n2\n");
				break;
		}
	}

	return 0;
}
