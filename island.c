//Program to find:
/// Number of islands 
/// Length of island
///
#include<stdio.h>
#define M 100
void main()
{
	int i,j,r,c,count=0,n,is;
	int island[M][M];
	int island2[M][M];
	int I[M];
	int J[M];
	int Length[M];
	int top=-1;
	
	
	

	n=6;
	island[0][0]=0;
	island[0][1]=0;
	island[0][2]=0;
	island[0][3]=0;
	island[0][4]=0;
	island[0][5]=0;

	island[1][0]=0;
	island[1][1]=1;
	island[1][2]=1;
	island[1][3]=0;
	island[1][4]=0;
	island[1][5]=0;

	island[2][0]=0;
	island[2][1]=1;
	island[2][2]=0;
	island[2][3]=0;
	island[2][4]=0;
	island[2][5]=0;

	island[3][0]=0;
	island[3][1]=0;
	island[3][2]=0;
	island[3][3]=1;
	island[3][4]=1;
	island[3][5]=0;

	island[4][0]=0;
	island[4][1]=0;
	island[4][2]=0;
	island[4][3]=1;
	island[4][4]=1;
	island[4][5]=0;

	island[5][0]=1;
	island[5][1]=1;
	island[5][2]=0;
	island[5][3]=0;
	island[5][4]=0;
	island[5][5]=0;
	
	/*
	n=3;
	island[0][0]=1;
	island[0][1]=0;
	island[0][2]=1;
	island[1][0]=0;
	island[1][1]=0;
	island[1][2]=1;
	island[2][0]=1;
	island[2][1]=1;
	island[2][2]=1;
	*/
		printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d",island[i][j]);
		printf("\n");
	}
	i=0;
	j=0;
	while(1)
	{
		///printf("\n%d %d",i,j);
		if(island[i][j]==1)
		{
			I[++top]=i;
			J[top]=j;
			is=0;
			///printf("\n%d %d",i,j);
			while(top>-1)
			{
			///	printf("\nr=%d c=%d top=%d",r,c,top);
		
				r=I[top];
				c=J[top--];
				island[r][c]=0;
				is++;
				if(island[r-1][c-1]>0&&r>0&&c>0)
				{
					I[++top]=r-1;
					J[top]=c-1;
				}
				if(island[r-1][c]>0&&r>0)
				{
					I[++top]=r-1;
					J[top]=c;
					
				}
				if(island[r-1][c+1]>0&&r>0&&c<(n-1))
				{
					I[++top]=r-1;
					J[top]=c+1;
					
				}
				if(island[r][c+1]>0&&c<(n-1))
				{
					I[++top]=r;
					J[top]=c+1;
				}
				if(island[r+1][c+1]>0&&r<(n-1)&&c<(n-1))
				{
					I[++top]=r+1;
					J[top]=c+1;
				}
				if(island[r+1][c]>0&&r<(n-1))
				{
					I[++top]=r+1;
					J[top]=c;
				}
				if(island[r+1][c-1]>0&&r<(n-1)&&c>0)
				{
					I[++top]=r+1;
					J[top]=c-1;
				}
				if(island[r][c-1]>0&&c>0)
				{
					I[++top]=r;
					J[top]=c-1;
				}
			}
			Length[count++]=is;
		//	printf("\n%d",is);
		}
		else
		{
			j++;
			if(j==n)
			{
				i++;
				j=0;
			}
		}
		if(i==n)
		break;
	}
	printf("\n%d",count);
	
}
