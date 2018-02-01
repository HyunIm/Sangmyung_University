#include <stdio.h>
#include <stdlib.h>
//�ǽ�) ���� 7���� 1���� �迭�� �Է� �޾�, ������� ������� �������� �����Ͽ�,���� ���� �ĸ� ����Ͻÿ�.
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSorting(int * p, int ArrLength, int mode) // mode: 0 => ��������, 1 => ��������
{
	for(int i=0; i<ArrLength-1; i++){ // Pivot �ε��� ����
		for(int j=i+1; j<ArrLength; j++){ // �񱳴�� �ε��� ����
			if(mode == 0){ // ��������
				if(p[i] > p[j]) swap(&p[i], &p[j]); // ���� �񱳴���� �۴ٸ� �� ���� ��ü
			}
			else if(mode == 1){ // ��������
				if(p[i] < p[j]) swap(&p[i], &p[j]); // ���� �񱳴���� ũ�ٸ� �� ���� ��ü
			} 
		}
	}
}
void InputArray(int * p, int length){
	printf("���� �Է��ϼ���: ");
	for(int i=0; i<length; i++){
		scanf("%d", &p[i]); // 7���� ���ڸ� �Է¹���
	}
}
void PrintArray(int * p, int length){
	for(int i=0; i<length; i++){ // ���� �� 7���� ���� ���
		printf("%d   ", p[i]);
	}
	printf("\n");
}

void main() {
	int num[7];
	InputArray(num,  sizeof(num)/sizeof(int));
	printf("������: ");
	PrintArray(num, sizeof(num)/sizeof(int));
	system("pause");
	BubbleSorting(num, sizeof(num)/sizeof(int), 0);
	printf("������: ");
	PrintArray(num, sizeof(num)/sizeof(int));
}