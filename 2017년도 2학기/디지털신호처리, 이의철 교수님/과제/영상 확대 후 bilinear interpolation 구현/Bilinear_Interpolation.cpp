/**
 * @file	Bilinear_Interpolation.cpp
 * @author	���� (201511054@sangmyung.kr)
 * @since	2017-12-02
 * @brief	���� Ȯ�� �� bilinear interpolation ����
			lenna.bmp �Ǵ� coin.bmp ������ ���� ���� �� 3�� ������ ��� Ȯ���ϰ�,
			�� �κ�(hole)�� bilinear interpolation���� ä��� ���α׷��� ����.
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

/**
 * @title	void Bilinear_Interpolation(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
 * @param	BYTE * Image (���� ����)
			BYTE * Output (��� ����)
			int SCALE (Ȯ�� ũ��)
			int W, int H (����, ����)
 * @return	����
 * @brief	�缱�� ������
*/
void Bilinear_Interpolation(BYTE * Image, BYTE * Output, int SCALE, int W, int H);

/**
 * @title	void Scaling(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
 * @param	BYTE * Image (���� ����)
			BYTE * Output (��� ����)
			int SCALE (Ȯ�� ũ��)
			int W, int H (����, ����)
 * @return	����
 * @brief	������ ��� Ȯ��
*/
void Scaling(BYTE * Image, BYTE * Output, int SCALE, int W, int H);

void main()
{
	BITMAPFILEHEADER hf; // BMP ������� 14Bytes
	BITMAPINFOHEADER hInfo; // BMP ������� 40Bytes
	RGBQUAD hRGB[256]; // �ȷ�Ʈ (256 * 4Bytes)
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

	/* ����ó�� */

	// 3�� ������ ��� Ȯ��
	const int SCALE = 3;

	// �缱�� ������ �Լ� ȣ��
	Bilinear_Interpolation(Image, Output, SCALE, W, H);

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

void Bilinear_Interpolation(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
{
	int i, j, k;	// for���� ���� ����

	// ������ ��� Ȯ�� �Լ� ȣ��
	Scaling(Image, Output, SCALE, W, H);

	// X�� ���� ȭ�Ҹ� ���ϴ� �ݺ���
	// E = A + ��(B - A), F = C + ��(D - C)
	for (i = 0; i < H - SCALE; i += SCALE)
		for (j = 0; j < W; j += SCALE)
			for (k = j; k < j + SCALE; k++)
				Output[i * W + k] = (BYTE)(Output[i * W + j] + (((k - j) / (float)SCALE) * (Output[i * W + (j + SCALE)] - Output[i * W + j])));
	
	// ���� ���� ȭ�Ҹ� ���ϴ� �ݺ���
	// X = E + ��(F - E)
	for (i = 0; i < H - SCALE; i += SCALE)
		for (j = 0; j < W; j++)
			for (k = i; k < i + SCALE; k++)
				Output[k * W + j] = (BYTE)(Output[i * W + j] + (((k - i) / (float)SCALE) * (Output[(i + SCALE) * W + j] - Output[i * W + j])));
}


void Scaling(BYTE * Image, BYTE * Output, int SCALE, int W, int H)
{
	int i, j;	// for���� ���� ����
	int X, Y;	// SCALE * (i or j)
	int cX = W / 2;	// �̹����� x�� �߾�(center) ��
	int cY = H / 2;	// �̹����� y�� �߾�(center) ��
	int sX = cX - W / (SCALE * 2);	// Ȯ���� �̹����� ���� x�� ��
	int sY = cY - H / (SCALE * 2);	// Ȯ���� �̹����� ���� y�� ��

	// ���� �߾� Ȯ�� �ݺ���
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			X = SCALE * i;
			Y = SCALE * j;

			// X Ȥ�� Y�� H Ȥ�� W�� ������ ���� ��� �Ÿ�
			if (X < H && Y < W)
				Output[X * W + Y] = Image[(i + sY) * W + j + sX];
		}
	}
}