#include <stdio.h>
#include <stdlib.h>
//실습) 숫자 7개를 1차원 배열에 입력 받아, 버블소팅 방법으로 오름차순 정렬하여,정렬 전과 후를 출력하시오.
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSorting(int * p, int ArrLength, int mode) // mode: 0 => 오름차순, 1 => 내림차순
{
	for(int i=0; i<ArrLength-1; i++){ // Pivot 인덱스 변경
		for(int j=i+1; j<ArrLength; j++){ // 비교대상 인덱스 변경
			if(mode == 0){ // 오름차순
				if(p[i] > p[j]) swap(&p[i], &p[j]); // 만약 비교대상값이 작다면 두 값을 교체
			}
			else if(mode == 1){ // 내림차순
				if(p[i] < p[j]) swap(&p[i], &p[j]); // 만약 비교대상값이 크다면 두 값을 교체
			} 
		}
	}
}
void InputArray(int * p, int length){
	printf("값을 입력하세요: ");
	for(int i=0; i<length; i++){
		scanf("%d", &p[i]); // 7개의 숫자를 입력받음
	}
}
void PrintArray(int * p, int length){
	for(int i=0; i<length; i++){ // 정렬 전 7개의 숫자 출력
		printf("%d   ", p[i]);
	}
	printf("\n");
}

void main() {
	int num[7];
	InputArray(num,  sizeof(num)/sizeof(int));
	printf("정렬전: ");
	PrintArray(num, sizeof(num)/sizeof(int));
	system("pause");
	BubbleSorting(num, sizeof(num)/sizeof(int), 0);
	printf("정렬후: ");
	PrintArray(num, sizeof(num)/sizeof(int));
}