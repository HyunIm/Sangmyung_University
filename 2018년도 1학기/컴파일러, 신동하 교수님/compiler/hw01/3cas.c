// ========================================
// File : 3cas.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 03 - 23
// ========================================


// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 1024

#define ACCEPT 1	// DFA 인식
#define REJECT 0	// DFA 비인식

// ----------------------------------------

#define NO_ALPHABET 3	// 입력 심볼의 유한 집합 개수
#define NO_STATES 4	// 상태의 유한 집합 개수

int alphabet[NO_ALPHABET] = {'a', 'b', 'c'};	// 입력 심볼의 유한 집합

int starting_state = 0;	// 시작 상태

int accepting_states[NO_STATES] = {0, 0, 0, 1};	// 최종 상태들의 집합

// 상태 전이 함수
int transition_function[NO_STATES][NO_ALPHABET] = {
	{1, 0, 0},
	{2, 0, 0},
	{3, 0, 0},
	{3, 3, 3}
};

// ----------------------------------------

/**
  * @title : int symbol_index(char c)
  * @param
  	char c : 유한 집합 원소 중 하나 
  * @return
  	i : 유한 집합 안 원소의 index 번호
  * @brief : 해당 symbol이 몇 번째 index인지 반환해주는 함수
  */
int symbol_index(char c);

/**
  * @title : int dfa(char input_string[])
  * @param
  	char input_string[] : DFA에 인식되는지 확인할 언어 L집합
  * @return
  	ACCEPT(=1) : DFA에 인식
	REJCET(=0) : DFA에 비인식
  * @brief : 결정적 유한 자동 기계 함수
  */
int dfa(char input_string[]);

// ----------------------------------------

/**
  * @title : int main(void)
  * @param : 없음
  * @return
  	EXIT_SUCCES : 정상 종료
  */
int main(void)
{
	char input_string[BUFFER_LENGTH];
	int i = 0;	// getchar를 i++해주면서 문자열로 받음

	// gets함수를 쓰지 않은 이유는 보안이 취약해서
	// 그리고 EOF를 인식하기 위해서
	while ((input_string[i] = getchar()))
	{
		// End Of File (CTRL + D)
		if (input_string[i] == EOF)	// EOF 입력값이 들어오면
			return EXIT_SUCCESS;	// 프로그램 정상 종료

		// 개행 문자가 들어오면
		if (input_string[i] == '\n')
		{
			// 개행 문자를 null로 바꿔서 문자열로 만들어줌
			input_string[i] = '\0';

			// dfa 함수에 넣어서 ACCEPT 반환 여부 확인
			if (dfa(input_string) == ACCEPT)
				printf("accept: %s\n", input_string);
			else
				printf("reject: %s\n", input_string);

			i = -1;	// 새로운 문자열을 받기 위해 i 초기화
		}
		i++;	// i를 1씩 증가시키며 문자열을 만듬
	}

	return EXIT_SUCCESS;
}

// ----------------------------------------

int symbol_index(char c)
{
	int i;

	for (i = 0; i < NO_ALPHABET; i++)
	{
		// 해당 char가 몇 번째 index에 있는지 찾고 반환
		if (alphabet[i] == c)
			return i;
	}
}

// ----------------------------------------

int dfa(char input_string[]) {
	char c;	// 문자열을 char로 받을 때 쓰임
	int i = 0;	// 문자열을 char로 나누기 위해 쓰임
	// 현재 상태를 나타내는 변수, 현재는 시작 상태
	int state = starting_state;

	while(201511054)
	{
		c = input_string[i++];
		
		if (c == '\0') {	// 문자열이 끝났을 때
			if (accepting_states[state] == 1) // 상태가 최종 상태면 ACCEPT
				return ACCEPT;
			else
				return REJECT;	// 아니라면 REJECT
		} else
			// 문자열이 진행 중이라면
			// 현재 상태에 transition을 넣어 다음 상태를 구함
			state = transition_function[state][symbol_index(c)];
	}
}

// ----------------------------------------
