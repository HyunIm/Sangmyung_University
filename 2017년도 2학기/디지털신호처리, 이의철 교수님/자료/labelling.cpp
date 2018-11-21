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


// GlassFire �˰����� �̿��� �󺧸� �Լ�
void m_BlobColoring(BYTE* CutImage, int height, int width)
{
	int i, j, m, n, top, area, Out_Area, index, BlobArea[1000];	
	long k;
	short curColor=0, r, c;
//	BYTE** CutImage2;
	Out_Area=1;


	// �������� ����� �޸� �Ҵ�
	short* stackx = new short[height*width];
	short* stacky = new short[height*width];
	short* coloring = new short[height*width];

	int arr_size = height * width;

	// �󺧸��� �ȼ��� �����ϱ� ���� �޸� �Ҵ�
	
	for(k=0; k<height*width; k++) coloring[k]=0;  // �޸� �ʱ�ȭ

	for(i=0; i<height; i++)
	{
		index = i*width;
		for(j=0; j<width; j++)
		{
			// �̹� �湮�� ���̰ų� �ȼ����� 255�� �ƴ϶�� ó�� ����
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
						//���� �ȼ��� �����踦 ����� ó�� ����
						if(m<0 || m>=height || n<0 || n>=width) continue;

						if((int)CutImage[index+n]==255 && coloring[index+n]==0)
						{
							coloring[index+n] = curColor; // ���� �󺧷� ��ũ
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

	// ���� ������ ���� ������ ã�Ƴ��� ���� 
	/*for(i=1; i<=curColor; i++)
	{
		if(BlobArea[i]>=BlobArea[Out_Area]) Out_Area = i;
	}*/
	// CutImage �迭 Ŭ����~
	for(k=0; k < width*height; k++) CutImage[k] = 255;

	// coloring�� ����� �󺧸� ����� (Out_Area�� �����) ������ ���� ū �͸� CutImage�� ����
	for(k=0; k < width*height; k++)
	{
		//if(coloring[k] == Out_Area) CutImage[k] = 0;  // ���� ū �͸� ����
		CutImage[k] = (unsigned char)(coloring[k] * grayGap);
	}

	delete [] coloring;
	delete [] stackx;
	delete [] stacky;
}
// �󺧸� �� ���� ���� ������ ���ؼ��� �̾Ƴ��� �ڵ� ����
