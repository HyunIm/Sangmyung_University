/**
 * @file	Bilinear_Interpolation.cpp
 * @author	임현 (201511054@sangmyung.kr)
 * @since	2017-12-02
 * @brief	영상 확대 후 bilinear interpolation 구현
			lenna.bmp 또는 coin.bmp 영상을 가로 세로 각 3배 순방향 사상 확대하고,
			빈 부분(hole)을 bilinear interpolation으로 채우는 프로그램을 구현.
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

/**
 * @title	void Bilinear_Interpolation(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
 * @param	BYTE * Image (원본 사진)
			BYTE * Output (출력 사진)
			int SCALE (확대 크기)
			int W, int H (가로, 새로)
 * @return	없음
 * @brief	양선형 보간법
*/
void Bilinear_Interpolation(BYTE * Image, BYTE * Output, int SCALE, int W, int H);

/**
 * @title	void Scaling(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
 * @param	BYTE * Image (원본 사진)
			BYTE * Output (출력 사진)
			int SCALE (확대 크기)
			int W, int H (가로, 새로)
 * @return	없음
 * @brief	순방향 사상 확대
*/
void Scaling(BYTE * Image, BYTE * Output, int SCALE, int W, int H);

void main()
{
	BITMAPFILEHEADER hf; // BMP 파일헤더 14Bytes
	BITMAPINFOHEADER hInfo; // BMP 인포헤더 40Bytes
	RGBQUAD hRGB[256]; // 팔레트 (256 * 4Bytes)
	FILE *fp;
	fp = fopen("LENNA.bmp", "rb");
	if (fp == NULL) return;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, fp);
	fread(hRGB, sizeof(RGBQUAD), 256, fp);
	int ImgSize = hInfo.biWidth * hInfo.biHeight;
	int W = hInfo.biWidth, H = hInfo.biHeight;
	BYTE * Image = (BYTE *)malloc(ImgSize);
	BYTE * Output = (BYTE *)malloc(ImgSize);
	fread(Image, sizeof(BYTE), ImgSize, fp);
	fclose(fp);

	/* 영상처리 */

	// 3배 순방향 사상 확대
	const int SCALE = 3;

	// 양선형 보간법 함수 호출
	Bilinear_Interpolation(Image, Output, SCALE, W, H);

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

void Bilinear_Interpolation(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
{
	int i, j, k;	// for문에 쓰일 변수

	// 순방향 사상 확대 함수 호출
	Scaling(Image, Output, SCALE, W, H);

	// X축 보간 화소를 구하는 반복문
	// E = A + α(B - A), F = C + α(D - C)
	for (i = 0; i < H - SCALE; i += SCALE)
		for (j = 0; j < W; j += SCALE)
			for (k = j; k < j + SCALE; k++)
				Output[i * W + k] = (BYTE)(Output[i * W + j] + (((k - j) / (float)SCALE) * (Output[i * W + (j + SCALE)] - Output[i * W + j])));
	
	// 최종 보간 화소를 구하는 반복문
	// X = E + β(F - E)
	for (i = 0; i < H - SCALE; i += SCALE)
		for (j = 0; j < W; j++)
			for (k = i; k < i + SCALE; k++)
				Output[k * W + j] = (BYTE)(Output[i * W + j] + (((k - i) / (float)SCALE) * (Output[(i + SCALE) * W + j] - Output[i * W + j])));
}


void Scaling(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
{
	int i, j;	// for문에 쓰일 변수
	int X, Y;	// SCALE * (i or j)
	int cX = W / 2;	// 이미지의 x축 중앙(center) 값
	int cY = H / 2;	// 이미지의 y축 중앙(center) 값
	int sX = cX - W / (SCALE * 2);	// 확대할 이미지의 시작 x축 값
	int sY = cY - H / (SCALE * 2);	// 확대할 이미지의 시작 y축 값

	// 영상 중앙 확대 반복문
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			X = SCALE * i;
			Y = SCALE * j;

			// X 혹은 Y가 H 혹은 W의 범위를 넘을 경우 거름
			if (X < H && Y < W)
				Output[X * W + Y] = Image[(i + sY) * W + j + sX];
		}
	}
}