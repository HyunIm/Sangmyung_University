int push(short *stackx, short *stacky, int arr_size, short vx, short vy, int *top)
{
	if(*top>=arr_size) return(-1);
	(*top)++;
	stackx[*top]=vx;
	stacky[*top]=vy;
	return(1);
}

int pop(short *stackx, short *stacky, short *vx, short *vy, int *top)
{
	if(*top==0) return(-1);
	*vx = stackx[*top];
	*vy = stacky[*top];
	(*top)--;
	return(1);
}


// GlassFire 알고리즘을 이용한 라벨링 함수
void m_BlobColoring(BYTE* CutImage, int height, int width)
{
	int i, j, m, n, top, area, Out_Area, index, BlobArea[1000];	
	long k;
	short curColor=0, r, c;
//	BYTE** CutImage2;
	Out_Area=1;


	// 스택으로 사용할 메모리 할당
	short* stackx = new short[height*width];
	short* stacky = new short[height*width];
	short* coloring = new short[height*width];

	int arr_size = height * width;

	// 라벨링된 픽셀을 저장하기 위해 메모리 할당
	
	for(k=0; k<height*width; k++) coloring[k]=0;  // 메모리 초기화

	for(i=0; i<height; i++)
	{
		index = i*width;
		for(j=0; j<width; j++)
		{
			// 이미 방문한 점이거나 픽셀값이 255가 아니라면 처리 안함
			if(coloring[index+j]!=0 || CutImage[index+j]!=255) continue;
			r=i; c=j; top=0; area=1;
			curColor++;

			while(1)
			{
GRASSFIRE:
				for(m=r-1; m<=r+1; m++)
				{
					index = m*width;
					for(n=c-1; n<=c+1; n++)
					{
						//관심 픽셀이 영상경계를 벗어나면 처리 안함
						if(m<0 || m>=height || n<0 || n>=width) continue;

						if((int)CutImage[index+n]==255 && coloring[index+n]==0)
						{
							coloring[index+n] = curColor; // 현재 라벨로 마크
							if(push(stackx, stacky, arr_size, (short)m, (short)n, &top) == -1) continue;
							r=m; c=n; area++;
							goto GRASSFIRE;
						}
					}
				}
				if(pop(stackx, stacky, &r, &c, &top) == -1) break;
			}
			if(curColor<1000) BlobArea[curColor] = area;
		}
	}

	float grayGap = 255.0f / (float)curColor;

	// 가장 면적이 넓은 영역을 찾아내기 위함 
	/*for(i=1; i<=curColor; i++)
	{
		if(BlobArea[i]>=BlobArea[Out_Area]) Out_Area = i;
	}*/
	// CutImage 배열 클리어~
	for(k=0; k < width*height; k++) CutImage[k] = 255;

	// coloring에 저장된 라벨링 결과중 (Out_Area에 저장된) 영역이 가장 큰 것만 CutImage에 저장
	for(k=0; k < width*height; k++)
	{
		//if(coloring[k] == Out_Area) CutImage[k] = 0;  // 가장 큰 것만 저장
		CutImage[k] = (unsigned char)(coloring[k] * grayGap);
	}

	delete [] coloring;
	delete [] stackx;
	delete [] stacky;
}
// 라벨링 후 가장 넓은 영역에 대해서만 뽑아내는 코드 포함
