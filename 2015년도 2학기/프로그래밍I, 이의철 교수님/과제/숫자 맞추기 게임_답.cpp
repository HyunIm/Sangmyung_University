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
	printf("��ǻ�Ͱ� 1~50 ������ ���� �ϳ��� �����߽��ϴ�!\n"); 
	for(i=1; ;i++) 
	{ 
		printf("%d��° �õ�> ���ڸ� �Է��ϼ���: ", i); 
		scanf("%d", &user); 
		if(user < num) printf("Up!\n"); 
		else if(user > num) printf("Down!\n"); 
		else{ 
			printf("Bingo!!!\n"); 
			break; 
		} 
	} 
	printf("��ǻ�Ͱ� ������ %d��� ���ڸ� %d�� �õ����� ���߼̳׿�!\n", num, i); 
	return 0; 
} 
