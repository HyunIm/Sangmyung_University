#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int main(void) 
{ 
	int i; 
	int num; 
	int user; 
	srand((unsigned)time(NULL)); 
	num = rand() % 50 + 1; 
	printf("컴퓨터가 1~50 사이의 숫자 하나를 결정했습니다!\n"); 
	for(i=1; ;i++) 
	{ 
		printf("%d번째 시도> 숫자를 입력하세요: ", i); 
		scanf("%d", &user); 
		if(user < num) printf("Up!\n"); 
		else if(user > num) printf("Down!\n"); 
		else{ 
			printf("Bingo!!!\n"); 
			break; 
		} 
	} 
	printf("컴퓨터가 생각한 %d라는 숫자를 %d번 시도만에 맞추셨네요!\n", num, i); 
	return 0; 
} 
