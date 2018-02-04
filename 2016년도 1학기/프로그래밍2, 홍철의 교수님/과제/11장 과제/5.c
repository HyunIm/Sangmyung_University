// 5번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Search(int num[], int ip) // 검색함수
{
	for (int i = 0; i < 10; i++) // num[0]부터 num[9]까지
	{
		if (num[i] == ip) // num[i]와 ip가 같다면
			return ip; // ip 반환
	}
	return -1; // 찾지 못 할 경우 -1 반환
}

int main(void)
{
	int num[10]; // 10개의 정수
	int ip; // 찾고자 하는 값
	srand(time(NULL)); // 난수 발생

	for (int i = 0; i < 10; i++) // 난수 발생기를 이용하여 배열에 저장
		num[i] = rand() % 100;

	scanf("%d", &ip); // 찾고자 하는 값 입력

	printf("%d\n", Search(num, ip)); // 찾은 값 출력

	/*for (int i = 0; i < 10; i++) // 10개의 정수 출력
	printf("%d ", num[i]);*/

	return 0;
}