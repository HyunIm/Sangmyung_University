// ========================================
// File : gen.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 03 - 23
// ========================================

// ----------------------------------------

#include <stdio.h>	// 표준 입출력
#include <stdlib.h>	// 동적할당, atoi 함수 등
#include <string.h>	// str 함수들

// ----------------------------------------

// 집합 개수
#define NO_ALPHABET 3

// 집합
char alphabet[NO_ALPHABET] = {'a', 'b', 'c'};

// ----------------------------------------

/**
  * @title : int gen(char * str, int n)
  * @param
  	char * str : old_string + new_char(alphabet 집합)
	int n : 스트링의 길이
  * @return : 없음
  * @brief : 	integer n에 대하여 0<=|s|<=n을 만족하는 
  		모든 스트링을 lexicographic order로 한 줄에 하나씩
		표준 출력으로 출력하는 함수
  */
void gen(char * str, int n);

// ----------------------------------------

/**
  * @title : int main(int argc, char *argv[])
  * @param
  	int argc : 명령행 인수의 개수
	char *argv[] : 명령행 인수의 문자열들
  * @return
  	EXIT_SUCCESS(= 0) : 인수가 2개 일 때
	EXIT_FAILURE(= 1) : 인수가 2개 아닐 때
  */
int main(int argc, char *argv[])
{
	int i;	// for문을 위한 변수
	int n;	// argv[1](아스키)값을 int 데이터 타입으로 바꿔줌

	// 명령행 인수가 2개가 아닐 경우 사용법 출력
	if (argc != 2)
	{
		printf("Usage : gen length\n");

		// 프로그램 비정상 종료
		return EXIT_FAILURE;
	}

	// 명령행 인수가 2개일 경우
	// 데이터 타입을 아스키에서 인티져로 바꿈
	else
		n = atoi(argv[1]);

	// 길이가 n인 스트링 집합이 나올 때 까지 반복
	for (i = 0; i <= n; i++)
		gen ("", i);

	// 프로그램 정상 종료
	return EXIT_SUCCESS;
}

// ----------------------------------------

void gen(char * str, int n)
{
	int i;	// for문을 위한 변수
	int len;	// str길이를 판단하기 위한 변수
	// old_string과 new_char를 붙이기 위한 변수
	char *new_str = malloc(sizeof(char) * 20);

	// Base Case
	// n이 0이면 현재의 String을 출력한다. 
	if (n == 0)
		printf("%s\n", str);

	// Induction Step
	// n이 0이 아니면
	// 원래 있던 String에 각각 알파벳 char(a, b, c)를 붙인
	// String이 된다
	else
	{
		for (i = 0; i < NO_ALPHABET; i++)
		{
			strcpy(new_str, "");
			strcat(new_str, str);

			len = strlen(new_str);
			new_str[len] = alphabet[i];
			new_str[len+1] = '\0';
			
			// n값을 1씩 줄여나가며 재귀호출
			gen(new_str, n - 1);
		}
	}
}

// ----------------------------------------
