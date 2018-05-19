#include<stdio.h>
#include<conio.h>
#define M 9

int count;
void init(int arr[M][M])
{
	int i,j;
	//Initialise all to Zero
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		arr[i][j]=0;
	}
}

void insert(int arr[M][M])
{
	arr[0][0]=0;
	arr[0][1]=3;
	arr[0][2]=0;
	arr[0][3]=0;
	arr[0][4]=7;
	arr[0][5]=0;
	arr[0][6]=0;
	arr[0][7]=4;
	arr[0][8]=0;
	
	arr[1][0]=7;
	arr[1][1]=0;
	arr[1][2]=0;
	arr[1][3]=6;
	arr[1][4]=0;
	arr[1][5]=3;
	arr[1][6]=0;
	arr[1][7]=0;
	arr[1][8]=8;
	
	arr[2][0]=0;
	arr[2][1]=0;
	arr[2][2]=8;
	arr[2][3]=0;
	arr[2][4]=0;
	arr[2][5]=0;
	arr[2][6]=3;
	arr[2][7]=0;
	arr[2][8]=0;
	
	arr[3][0]=0;
	arr[3][1]=5;
	arr[3][2]=0;
	arr[3][3]=0;
	arr[3][4]=4;
	arr[3][5]=0;
	arr[3][6]=0;
	arr[3][7]=1;
	arr[3][8]=0;
	
	arr[4][0]=4;
	arr[4][1]=0;
	arr[4][2]=0;
	arr[4][3]=7;
	arr[4][4]=0;
	arr[4][5]=5;
	arr[4][6]=0;
	arr[4][7]=0;
	arr[4][8]=3;
	
	arr[5][0]=0;
	arr[5][1]=8;
	arr[5][2]=0;
	arr[5][3]=0;
	arr[5][4]=6;
	arr[5][5]=0;
	arr[5][6]=0;
	arr[5][7]=9;
	arr[5][8]=0;
	
	arr[6][0]=0;
	arr[6][1]=0;
	arr[6][2]=5;
	arr[6][3]=0;
	arr[6][4]=0;
	arr[6][5]=0;
	arr[6][6]=4;
	arr[6][7]=0;
	arr[6][8]=0;
	
	arr[7][0]=8;
	arr[7][1]=0;
	arr[7][2]=0;
	arr[7][3]=2;
	arr[7][4]=0;
	arr[7][5]=7;
	arr[7][6]=0;
	arr[7][7]=0;
	arr[7][8]=1;
	
	arr[8][0]=0;
	arr[8][1]=1;
	arr[8][2]=0;
	arr[8][3]=0;
	arr[8][4]=9;
	arr[8][5]=0;
	arr[8][6]=0;
	arr[8][7]=6;
	arr[8][8]=0;
	
	count=28;
	/*
	arr[0][0]=0;
	arr[0][1]=0;
	arr[0][2]=0;
	arr[0][3]=2;
	arr[0][4]=6;
	arr[0][5]=0;
	arr[0][6]=7;
	arr[0][7]=0;
	arr[0][8]=1;
	
	arr[1][0]=6;
	arr[1][1]=8;
	arr[1][2]=0;
	arr[1][3]=0;
	arr[1][4]=7;
	arr[1][5]=0;
	arr[1][6]=0;
	arr[1][7]=9;
	arr[1][8]=0;
	
	arr[2][0]=1;
	arr[2][1]=9;
	arr[2][2]=0;
	arr[2][3]=0;
	arr[2][4]=0;
	arr[2][5]=4;
	arr[2][6]=5;
	arr[2][7]=0;
	arr[2][8]=0;
	
	arr[3][0]=8;
	arr[3][1]=2;
	arr[3][2]=0;
	arr[3][3]=1;
	arr[3][4]=0;
	arr[3][5]=0;
	arr[3][6]=0;
	arr[3][7]=4;
	arr[3][8]=0;
	
	arr[4][0]=0;
	arr[4][1]=0;
	arr[4][2]=4;
	arr[4][3]=6;
	arr[4][4]=0;
	arr[4][5]=2;
	arr[4][6]=9;
	arr[4][7]=0;
	arr[4][8]=0;
	
	arr[5][0]=0;
	arr[5][1]=5;
	arr[5][2]=0;
	arr[5][3]=0;
	arr[5][4]=0;
	arr[5][5]=3;
	arr[5][6]=0;
	arr[5][7]=2;
	arr[5][8]=8;
	
	arr[6][0]=0;
	arr[6][1]=0;
	arr[6][2]=9;
	arr[6][3]=3;
	arr[6][4]=0;
	arr[6][5]=0;
	arr[6][6]=0;
	arr[6][7]=7;
	arr[6][8]=4;
	
	arr[7][0]=0;
	arr[7][1]=4;
	arr[7][2]=0;
	arr[7][3]=0;
	arr[7][4]=5;
	arr[7][5]=0;
	arr[7][6]=0;
	arr[7][7]=3;
	arr[7][8]=6;
	
	arr[8][0]=7;
	arr[8][1]=0;
	arr[8][2]=3;
	arr[8][3]=0;
	arr[8][4]=1;
	arr[8][5]=8;
	arr[8][6]=0;
	arr[8][7]=0;
	arr[8][8]=0;
	
	count=36;
	*/

}
int checkRow(int arr[M][M],int n,int row)
{
	int i,j;
	for(i=0;i<M;i++)
	{
		if(arr[row][i]==n)
		return 0;
	}
	return 1;
}

int checkCol(int arr[M][M],int n,int col)
{
	int i;
	for(i=0;i<M;i++)
	{
		if(arr[i][col]==n)
		return 0;
	}
	return 1;
}

int checkBox(int arr[M][M],int n,int row,int col)
{
	int si,ei,sj,ej,j;
	si=row/3;
	si*=3;
	ei=si+3;
	sj=col/3;
	sj*=3;
	ej=sj+3;
	for(;si<ei;si++)
	{
		for(j=sj;j<ej;j++)
		{
			if(arr[si][j]==n)
			return 0;
		}
	}
	return 1;
}
void display(int arr[M][M])
{
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		printf("%d ",arr[i][j]);
		printf("\n");
	}
}

void solve(int arr[M][M])
{
	int i,j,k,c,n;
	int no[]={1,2,3,4,5,6,7,8,9};
	while(count<81)
	{
		for(i=0;i<M;i++)
		{
			for(j=0;j<M;j++)
			{
				c=0;
				for(k=0;k<M;k++)
				{
					if(arr[i][j]==0)
					{
						if(checkRow(arr,no[k],i)&&checkCol(arr,no[k],j)&&checkBox(arr,no[k],i,j))
						{
							c++;
							n=no[k];
						}
					}
				}
				if(c==1)
				{
					arr[i][j]=n;
					count++;
					display(arr);
					printf("\n\n");
					getch();
				}
			}
		}
	}
}

int main()
{
	int arr[M][M];
	//init();
	insert(&arr);
	solve(&arr);
	display(arr);
	getch();
	return 0;
}
