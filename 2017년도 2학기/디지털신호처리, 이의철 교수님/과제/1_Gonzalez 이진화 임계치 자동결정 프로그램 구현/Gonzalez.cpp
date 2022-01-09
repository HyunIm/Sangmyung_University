/**
 * @file	Gonzalez.cpp
 * @author	���� (201511054@sangmyung.kr)
 * @since	2017-10-15
 * @brief	Gonzalez ����ȭ �Ӱ�ġ �ڵ����� ���α׷� ����
			coin.bmp ���� ����, Gonzalez ������� �ڵ� ������ �Ӱ�ġ�� ���� ����ȭ�� �����Ͽ� output.bmp ���Ϸ� ����ϴ� ���α׷� (�ԽǷ� ���� 2)
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>	// abs �Լ�

#define BLACK 0
#define WHITE 255

/**
 * @title	int Gonzalez(int ImgSize, BYTE * Image)
 * @param	int ImgSize (���� ũ��)
			BYTE * Image (���� ����)
 * @return	NewThreshold (���߷��� ��谪)
 * @brief	���߷��� �Լ�
*/
int Gonzalez(int ImgSize, BYTE * Image);

/**
 * @title	int Threshold_Init(int Histo[])
 * @param	int Histo[] (��Ⱚ ������׷�)
 * @return	(Low + High) / 2 (�ּҰ��� �ִ밪 ������ �߰���)
 * @brief	1. ��谪 T�� �ʱⰪ�� ����
*/
int Threshold_Init(int Histo[]);

/**
 * @title	void Mean_Value(int Threshold, int ImgSize, BYTE * Image, int * M1, int * M2)
 * @param	int Threshold (��谪)
			int ImgSize (���� ũ��)
			BYTE * Image (���� ����)
			int * M1 (G1�� ��հ�)
			int * M2 (G2�� ��հ�)
 * @return	����
 * @brief	2. ��谪 T�� ����ȭ��
			3. ���� G1�� G2�� ���Ͽ� ȭ�ҵ��� ��հ��� �����
*/
void Mean_Value(int Threshold, int ImgSize, BYTE * Image, int * M1, int * M2);

/**
 * @title	int New_Threshold(int M1, int M2)
 * @param	int M1 (G1�� ��հ�)
			int M2 (G2�� ��հ�)
 * @return	(M1 + M2) / 2 (���ο� ��谪)
 * @brief	4. ���������� ���ο� ��谪�� �����
*/
int New_Threshold(int M1, int M2);

/**
 * @title	int Change(int NewThreshold, int Threshold)
 * @param	int NewThreshold (���ο� ��谪)
			int Threshold (���� ��谪)
 * @return	(abs)(NewThreshold - Threshold) (������)
 * @brief	5. �������� �ݺ����� ��� ���� ��ȭ�� �̸� ���ǵ� �������� ���� ������ �ܰ� 2���� 4���� �ݺ���
*/
int Change(int NewThreshold, int Threshold);

void main()
{
	BITMAPFILEHEADER hf; // BMP ������� 14Bytes
	BITMAPINFOHEADER hInfo; // BMP ������� 40Bytes
	RGBQUAD hRGB[256]; // �ȷ�Ʈ (256 * 4Bytes)
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

	/* ����ó�� */

	int i;
	int GonVal;	// ���߷��� ��谪

	// ���߷��� �Լ� ȣ��
	GonVal = Gonzalez(ImgSize, Image);

	// ���� ����ȭ
	for (i = 0; i < ImgSize; i++) {
		if (Image[i] > GonVal)
			Output[i] = WHITE;
		else
			Output[i] = BLACK;
	}

	/* ����ó�� �� */

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
	static int Upsilon = 2;	// �ԽǷ� ��(�̸� ���ǵ� ������)
	int i;
	int Threshold;	// ��谪 T
	int NewThreshold;	// ���ο� ��谪 T
	int M1 = 0;	// G1�� ��հ�	(��Ⱚ�� T���� ū			ȭ�ҵ�� ������ ����
	int M2 = 0;	// G2�� ��հ�	(��Ⱚ�� T���� �۰ų� ����	ȭ�ҵ�� ������ ����)
	int Histo[256] = { 0 };	// ��Ⱚ ������׷�
		for (i = 0; i < ImgSize; i++)	// ��Ⱚ ������׷� ��
		Histo[Image[i]]++;

	/* 1. ��谪 T�� �ʱⰪ�� ���� */
	Threshold = Threshold_Init(Histo);	// �ʱⰪ : 93 (Low : 18, High : 168)

	while (201511054) {
		/* 2. ��谪 T�� ����ȭ�� */
		/* 3. ���� G1�� G2�� ���Ͽ� ȭ�ҵ��� ��հ��� ����� */
		Mean_Value(Threshold, ImgSize, Image, &M1, &M2);

		/* 4. ���������� ���ο� ��谪�� ����� */
		NewThreshold = New_Threshold(M1, M2);

		/* 5. �������� �ݺ����� ��� ���� ��ȭ�� �̸� ���ǵ� �������� ���� ������ �ܰ� 2���� 4���� �ݺ��� */
		if (Change(NewThreshold, Threshold) < Upsilon)		break;
		else Threshold = NewThreshold;
	}

	return NewThreshold;
}

int Threshold_Init(int Histo[])
{
	int i;
	int Low;	// ����� �ּҰ�
	int High;	// ����� �ִ밪

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