/**
 * @file	Gonzalez.cpp
 * @author	임현 (201511054@sangmyung.kr)
 * @since	2017-10-15
 * @brief	Gonzalez 이진화 임계치 자동결정 프로그램 구현
			coin.bmp 영상에 대해, Gonzalez 방법으로 자동 결정된 임계치를 통해 이진화를 수행하여 output.bmp 파일로 출력하는 프로그램 (입실론 값은 2)
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>	// abs 함수

#define BLACK 0
#define WHITE 255

/**
 * @title	int Gonzalez(int ImgSize, BYTE * Image)
 * @param	int ImgSize (사진 크기)
			BYTE * Image (원본 사진)
 * @return	NewThreshold (곤잘레스 경계값)
 * @brief	곤잘레스 함수
*/
int Gonzalez(int ImgSize, BYTE * Image);

/**
 * @title	int Threshold_Init(int Histo[])
 * @param	int Histo[] (밝기값 히스토그램)
 * @return	(Low + High) / 2 (최소값과 최대값 사이의 중간점)
 * @brief	1. 경계값 T의 초기값을 추정
*/
int Threshold_Init(int Histo[]);

/**
 * @title	void Mean_Value(int Threshold, int ImgSize, BYTE * Image, int * M1, int * M2)
 * @param	int Threshold (경계값)
			int ImgSize (사진 크기)
			BYTE * Image (원본 사진)
			int * M1 (G1의 평균값)
			int * M2 (G2의 평균값)
 * @return	없음
 * @brief	2. 경계값 T로 이진화함
			3. 영역 G1과 G2에 대하여 화소들의 평균값을 계산함
*/
void Mean_Value(int Threshold, int ImgSize, BYTE * Image, int * M1, int * M2);

/**
 * @title	int New_Threshold(int M1, int M2)
 * @param	int M1 (G1의 평균값)
			int M2 (G2의 평균값)
 * @return	(M1 + M2) / 2 (새로운 경계값)
 * @brief	4. 연속적으로 새로운 경계값을 계산함
*/
int New_Threshold(int M1, int M2);

/**
 * @title	int Change(int NewThreshold, int Threshold)
 * @param	int NewThreshold (새로운 경계값)
			int Threshold (기존 경계값)
 * @return	(abs)(NewThreshold - Threshold) (오차값)
 * @brief	5. 연속적인 반복에서 경계 값의 변화가 미리 정의된 오차보다 작을 때까지 단계 2에서 4까지 반복함
*/
int Change(int NewThreshold, int Threshold);

void main()
{
	BITMAPFILEHEADER hf; // BMP 파일헤더 14Bytes
	BITMAPINFOHEADER hInfo; // BMP 인포헤더 40Bytes
	RGBQUAD hRGB[256]; // 팔레트 (256 * 4Bytes)
	FILE *fp;
	fp = fopen("coin.bmp", "rb");
	if(fp == NULL) return;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, fp);
	fread(hRGB, sizeof(RGBQUAD), 256, fp);
	int ImgSize = hInfo.biWidth * hInfo.biHeight;
	BYTE * Image = (BYTE *)malloc(ImgSize);
	BYTE * Output = (BYTE *)malloc(ImgSize);
	fread(Image, sizeof(BYTE), ImgSize, fp);
	fclose(fp);

	/* 영상처리 */

	int i;
	int GonVal;	// 곤잘레스 경계값

	// 곤잘레스 함수 호출
	GonVal = Gonzalez(ImgSize, Image);

	// 영상 이진화
	for (i = 0; i < ImgSize; i++) {
		if (Image[i] > GonVal)
			Output[i] = WHITE;
		else
			Output[i] = BLACK;
	}

	/* 영상처리 끝 */

	fp = fopen("output.bmp", "wb");
	fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
	fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
	fwrite(hRGB, sizeof(RGBQUAD), 256, fp);
	fwrite(Output, sizeof(BYTE), ImgSize, fp);
	fclose(fp);
	free(Image);
	free(Output);
}

int Gonzalez(int ImgSize, BYTE * Image)
{
	static int Upsilon = 2;	// 입실론 값(미리 정의된 오차ε)
	int i;
	int Threshold;	// 경계값 T
	int NewThreshold;	// 새로운 경계값 T
	int M1 = 0;	// G1의 평균값	(밝기값이 T보다 큰			화소들로 구성된 영역
	int M2 = 0;	// G2의 평균값	(밝기값이 T보다 작거나 같은	화소들로 구성된 영역)
	int Histo[256] = { 0 };	// 밝기값 히스토그램
		for (i = 0; i < ImgSize; i++)	// 밝기값 히스토그램 값
		Histo[Image[i]]++;

	/* 1. 경계값 T의 초기값을 추정 */
	Threshold = Threshold_Init(Histo);	// 초기값 : 93 (Low : 18, High : 168)

	while (201511054) {
		/* 2. 경계값 T로 이진화함 */
		/* 3. 영역 G1과 G2에 대하여 화소들의 평균값을 계산함 */
		Mean_Value(Threshold, ImgSize, Image, &M1, &M2);

		/* 4. 연속적으로 새로운 경계값을 계산함 */
		NewThreshold = New_Threshold(M1, M2);

		/* 5. 연속적인 반복에서 경계 값의 변화가 미리 정의된 오차보다 작을 때까지 단계 2에서 4까지 반복함 */
		if (Change(NewThreshold, Threshold) < Upsilon)		break;
		else Threshold = NewThreshold;
	}

	return NewThreshold;
}

int Threshold_Init(int Histo[])
{
	int i;
	int Low;	// 밝기의 최소값
	int High;	// 밝기의 최대값

	for (i = 0; i < 256; i++) {
		if (Histo[i] != 0) {
			Low = i;
			break;
		}
	}

	for (i = 255; i >= 0; i--) {
		if (Histo[i] != 0) {
			High = i;
			break;
		}
	}

	return (Low + High) / 2;
}

void Mean_Value(int Threshold, int ImgSize, BYTE * Image, int * M1, int * M2)
{
	int i;
	int cnt = 0;
	*M1 = 0;
	*M2 = 0;

	for (i = 0; i < ImgSize; i++) {
		if (Image[i] > Threshold) {
			*M1 += Image[i];
			cnt++;
		}
		else
			*M2 += Image[i];
	}

	*M1 /= cnt;
	*M2 /= (ImgSize - cnt);
}

int New_Threshold(int M1, int M2)
{
	return (M1 + M2) / 2;
}

int Change(int NewThreshold, int Threshold)
{
	return (abs)(NewThreshold - Threshold);
}