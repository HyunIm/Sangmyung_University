#include <stdlib.h>
#include <stdio.h>

typedef struct grade { // 성적
	char name[5];
	int score;
	int avg;
} grade;

int main(void) {
	FILE *rfp, *wfp;
	char c;
	int i, j, k = 0;
	int cmb = 0; // 점수 문자를 합치기 위한 변수
	int check = 0; // 점수 입력 확인
	int report[15]; // 성적표
	int sum = 0;
	grade student[5];
	grade subject[3];
	grade tmp; // swap 용

	if ((rfp = fopen("2-8.dat", "r")) == NULL) {
		perror("fopen: 2-8.dat");
		exit(1);
	}

	if ((wfp = fopen("2-8.out", "w")) == NULL) {
		perror("fopen: 2-8.out");
		exit(1);
	}

	for (i = 0; i < 5; i++) { // 이름 초기화
		for (j = 0; j < 5; j++)
			student[i].name[j] = '\0';
	}

	i = -1, j = 0;
	while ((c = fgetc(rfp)) != EOF) {
		if (c == '\n') // 개행
			i++;

		if (c >= '0' && c <= '9') { // 점수
			cmb = cmb * 10 + c - '0'; // atoi
			check = 1;
		}

		// 이름
		else if ((c>='a' && c<='z') || (c>='A' && c<='Z')) {
			student[i].name[j] = c; // 이름 입력
			j++;
		}

		else {
			if (check == 1) {
				report[k] = cmb;
				cmb = 0; check = 0;
				k++;
			}
			j = 0;
		}
	}

	for (i = 0; i < 5; i++) { // 학생 성적
		for (j = 0; j < 3; j++)
			sum += report[i * 3 + j]; // 2차원 배열
		student[i].score = sum;
		student[i].avg = student[i].score / 3;
		sum = 0;
	}

	for (i = 0; i < 3; i++) { // 과목별 성적
		for (j = 0; j < 5; j++)
			sum += report[j * 3 + i];
		subject[i].score = sum;
		subject[i].avg = subject[i].score / 5;
		sum = 0;
	}

	for (i = 0; i < 4; i++) { // 성적순 정렬 (버블)
		for (j = i + 1; j < 5; j++) {
			if (student[i].score < student[j].score) {
				tmp = student[i];
				student[i] = student[j];
				student[j] = tmp;
			}
		}
	}

	for (i = 0; i < 5; i++) // 출력
		fprintf(wfp, "이름 : %s\t 합 : %d\t 평균 : %d\n", student[i].name, student[i].score, student[i].avg);
		
	fprintf(wfp, "\n과목별 평균\n 국어 : %d\t 영어 : %d\t 수학 : %d\n", subject[0].avg, subject[1].avg, subject[2].avg);

	fclose(rfp);
	fclose(wfp);

	return 0;
}
