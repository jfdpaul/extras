#include<stdio.h>
#define M 50

int space[M][M];
int space2[M][M];

int len=12;

void init()
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			space[i][j]=2;
		}
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			space2[i][j]=2;
		}
	}
	for(i=0;i<len;i++)
	{
		space[11][i]=3;
		space2[11][i]=3;
		space[9][i]=3;
		space2[9][i]=3;
		space[8][i]=3;
		space2[8][i]=3;
		space[7][i]=3;
		space2[7][i]=3;
		space[6][i]=3;
		space2[6][i]=3;
	
	}
	
	space[11][1]=3;
	
	
	space[9][4]=2;
	space[8][6]=2;
	space[8][4]=2;
	
	space[7][7]=2;
	space[7][6]=2;
	space[7][5]=2;
	space[7][4]=2;
	space[7][3]=2;
	
	space[6][7]=2;
	space[6][6]=2;
	space[6][5]=2;
	space[6][4]=2;
	space[6][3]=2;
	
	
	space2[11][1]=3;
	
	
	space2[9][4]=2;
	space2[8][6]=2;
	space2[8][4]=2;
	
	space2[7][7]=2;
	space2[7][6]=2;
	space2[7][5]=2;
	space2[7][4]=2;
	space2[7][3]=2;
	
	space2[6][7]=2;
	space2[6][6]=2;
	space2[6][5]=2;
	space2[6][4]=2;
	space2[6][3]=2;
	
}

void display()
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(space[i][j]==1)
				printf(".");
			if(space[i][j]==2)
				printf(" ");
			if(space[i][j]==0)
				printf("o");
			if(space[i][j]==3)
				printf("-");
		}
		printf("\n");
	}
	/*
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			printf("%d",space[i][j]);
		}
		printf("\n");
	}*/
}
void addWater()
{
	int i;
	//add water
	for(i=0;i<len;i++)
		space[0][i]=1;
}
void increment()
{
	int i,j,k,tr,lvl;
	//3 -land; 1 -water ;2-air 
	for(i=len-1;i>=0;i--)
	{
		lvl=1;
		for(j=len-1;j>=0;j--)
		{
			if(space[i][j]==1&&space2[i+1][j]==2)
			{
				space2[i][j]=2;
				space2[i+1][j]=1;
			}
			else if(space[i][j]==1&&space[i+1][j+1]==2&&space[i][j+1]==2&&space2[i+1][j+1]==2)//right gap
			{
				space2[i][j]=2;
				space2[i+1][j+1]=1;
			}
			else if(space[i][j]==1&&space[i+1][j-1]==2&&space[i][j-1]==2&&space2[i+1][j-1]==2)//right gap
			{
				space2[i][j]=2;
				space2[i+1][j-1]=1;
			}
			else if(space[i][j]==1&&space[i+1][j]==1&&lvl)
			{
				tr=1;
				for(k=j+1;k<len;k++)
				{
					if(space[i+1][k]==3)
					break;
					if(space[i+1][k]==2&&space2[i+1][k]==2)
					{
						space2[i][j]=2;
						space2[i+1][k]=1;
						tr=0;
						lvl=0;
						break;
					}
				}
				if(tr)
				for(k=j-1;k>=0;k--)
				{
					if(space[i+1][k]==3)
					break;
					if(space[i+1][k]==2&&space2[i+1][k]==2)
					{
						space2[i][j]=2;
						space2[i+1][k]=1;
						lvl=0;
						break;
					}
				}
			}
			else if(space[i+1][j]==0&&space[i][j]==1&&(i+1)<(len))
			{
				space2[i][j]=2;
			}
		}
	}
	//copy to space
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			space[i][j]=space2[i][j];
		}
	}

}

void simLife()
{
	char ch;
	while(1)
	{
		system("cls");
		display();
		ch=getch();
		increment();
		if(ch=='i')
			addWater();
	}
}
int main()
{
	init();
	simLife();
	return 0;
}
