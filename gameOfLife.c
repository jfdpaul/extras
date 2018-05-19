	/**
Date:10/06/15
Author: Jonathan Fidelis Paul
*/
#include<stdio.h>
#include<math.h>
#include<Windows.h>
/*
Rules:-
1>Any live cell with fewer than two live neighbours dies, as if caused by under-population.
2>Any live cell with two or three live neighbours lives on to the next generation.
3>Any live cell with more than three live neighbours dies, as if by overcrowding.
4>Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/
#define MAX 100
int showLife=1;
int wrap=1;
int n=50;//dimension to display
int limit=100;
int loadpos=2;

int simLife(int land[MAX][MAX]);
void initializeLand(int land[MAX][MAX],int num,int d);


void displayArray(int land[MAX][MAX],int num)
{
	int i,j;
	printf("\n\n");
	for(i=loadpos;i<num+loadpos;i++)
	{
		for(j=loadpos;j<num+loadpos;j++)
		printf("%d ",land[i][j]);
		printf("\n",land[i][j]);
	}
}
void display(int arr[MAX][MAX])
{ 
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]>0)
			printf("#");
			else
			printf(" ");
		}
		printf("|\n");
	}
	for(i=0;i<n;i++)
		printf("-");
}
void clearArray(int land[MAX][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			land[i][j]=0;
		}
	}
}

int neighbor2(int arr[MAX][MAX],int r,int c)
{
	int count=0;
	
	/**/
	if(arr[r-1][c-1]>0&&r>0&&c>0)
		count++;
	if(arr[r-1][c]>0&&r>0)
		count++;
	if(arr[r-1][c+1]>0&&r>0&&c<(n-1))
		count++;
	if(arr[r][c+1]>0&&c<(n-1))
		count++;
	if(arr[r+1][c+1]>0&&r<(n-1)&&c<(n-1))
		count++;
	if(arr[r+1][c]>0&&r<(n-1))
		count++;
	if(arr[r+1][c-1]>0&&r<(n-1)&&c>0)
		count++;
	if(arr[r][c-1]>0&&c>0)
		count++;
	
	if(wrap==1)
	{
		
		/*Conditions for warping*/	
		if(r==0&&c>0&&c<(n-1))
		{
			if(arr[n-1][c-1]>0)
			count++;
			if(arr[n-1][c]>0)
			count++;
			if(arr[n-1][c+1]>0)
			count++;
		}
		if(r==(n-1)&&c>0&&c<(n-1))
		{
			if(arr[0][c-1]>0)
			count++;
			if(arr[0][c]>0)
			count++;
			if(arr[0][c+1]>0)
			count++;
		}
		if(c==0&&r>0&&r<(n-1))
		{
			if(arr[r-1][n-1]>0)
			count++;
			if(arr[r][n-1]>0)
			count++;
			if(arr[r+1][n-1]>0)
			count++;
		}
		if(c==(n-1)&&r>0&&r<(n-1))
		{
			if(arr[r-1][0]>0)
			count++;
			if(arr[r][0]>0)
			count++;
			if(arr[r+1][0]>0)
			count++;
		}
		if(c==0&&r==0)
		{
			
			if(arr[n-1][n-1]>0)
			count++;
			if(arr[n-1][0]>0)
			count++;
			if(arr[n-1][1]>0)
			count++;
			if(arr[0][n-1]>0)
			count++;
			if(arr[1][n-1]>0)
			count++;
		}
		if(c==(n-1)&&r==(n-1))
		{
			if(arr[0][0]>0)
			count++;
			if(arr[0][n-1]>0)
			count++;
			if(arr[0][n-2]>0)
			count++;
			if(arr[n-1][0]>0)
			count++;
			if(arr[n-2][0]>0)
			count++;
		}
		if(c==(n-1)&&r==0)
		{
			if(arr[n-1][0]>0)
			count++;
			if(arr[n-1][n-2]>0)
			count++;
			if(arr[n-1][n-1]>0)
			count++;
			if(arr[0][0]>0)
			count++;
			if(arr[1][0]>0)
			count++;
		}
		if(c==0&&r==(n-1))
		{
			if(arr[0][n-1]>0)
			count++;
			if(arr[n-2][n-1]>0)
			count++;
			if(arr[n-1][n-1]>0)
			count++;
			if(arr[0][0]>0)
			count++;
			if(arr[0][1]>0)
			count++;
		}
	}

	return count;	
}

void loadSpc(int land[MAX][MAX],int spc[])
{
	int r,c,i,j,count,l,k;
	r=spc[0];
	c=spc[1];
	count=1;
	l=spc[2];
	k=3;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(spc[k]==count++)
			{
				land[i][j]=1;
				k++;
			}
		}
	}
}
void toStr(char str[MAX],int d)//Converts integer to string
{
	int i=0;
	while(d>0)
	{
		str[i++]=d%10+48;
		d=d/10;
	}
	str[i]='\0';
}

void loadSelected(int land[MAX][MAX],int ch)
{
	int i,j;
	char chr;
	int num;
	FILE *fp1,*fp2;
	int sp[MAX],l;
	int dec;
	char str[MAX];
	int gen;
	int no;
	
	switch(ch)
	{
		//Block
		case 1:
		n=3;
		land[0][0]=0;
		land[0][1]=1;
		land[0][2]=0;
		land[1][0]=0;
		land[1][1]=1;
		land[1][2]=0;
		land[2][0]=0;
		land[2][1]=1;
		land[2][2]=0;
		break;
		
		//Beehive
		case 2:
		n=4;
		land[0][0]=0;
		land[0][1]=0;
		land[0][2]=0;
		land[0][3]=0;
		land[1][0]=0;
		land[1][1]=1;
		land[1][2]=1;
		land[1][3]=0;
		land[2][0]=0;
		land[2][1]=1;
		land[2][2]=1;
		land[2][3]=0;
		land[3][0]=0;
		land[3][1]=0;
		land[3][2]=0;
		land[3][3]=0;
		break;
		
		//Loaf
		case 3:
		n=6;
		land[0][0]=0;
		land[0][1]=0;
		land[0][2]=0;
		land[0][3]=0;
		land[0][4]=0;
		land[0][5]=0;
	
		land[1][0]=0;
		land[1][1]=0;
		land[1][2]=1;
		land[1][3]=1;
		land[1][4]=0;
		land[1][5]=0;
	
		land[2][0]=0;
		land[2][1]=1;
		land[2][2]=0;
		land[2][3]=0;
		land[2][4]=1;
		land[2][5]=0;
	
		land[3][0]=0;
		land[3][1]=0;
		land[3][2]=1;
		land[3][3]=0;
		land[3][4]=1;
		land[3][5]=0;
	
		land[4][0]=0;
		land[4][1]=0;
		land[4][2]=0;
		land[4][3]=1;
		land[4][4]=0;
		land[4][5]=0;
	
		land[5][0]=0;
		land[5][1]=0;
		land[5][2]=0;
		land[5][3]=0;
		land[5][4]=0;
		land[5][5]=0;
		break;
		//Beacon
		case 4:
		n=6;
		land[0][0]=0;
		land[0][1]=0;
		land[0][2]=0;
		land[0][3]=0;
		land[0][4]=0;
		land[0][5]=0;
	
		land[1][0]=0;
		land[1][1]=1;
		land[1][2]=1;
		land[1][3]=0;
		land[1][4]=0;
		land[1][5]=0;
	
		land[2][0]=0;
		land[2][1]=1;
		land[2][2]=1;
		land[2][3]=0;
		land[2][4]=0;
		land[2][5]=0;
	
		land[3][0]=0;
		land[3][1]=0;
		land[3][2]=0;
		land[3][3]=1;
		land[3][4]=1;
		land[3][5]=0;
	
		land[4][0]=0;
		land[4][1]=0;
		land[4][2]=0;
		land[4][3]=1;
		land[4][4]=1;
		land[4][5]=0;
	
		land[5][0]=0;
		land[5][1]=0;
		land[5][2]=0;
		land[5][3]=0;
		land[5][4]=0;
		land[5][5]=0;
		break;
		
		//Glider
		case 5:
		n=10;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				land[i][j]=0;
			}
		}
		land[1][0]=1;
		land[0][2]=1;
		land[1][2]=1;
		land[2][2]=1;
		land[2][1]=1;
		break;
		
		//Gopher Gun
		case 6:
			n=50;
			sp[0]=11;
			sp[1]=38;
			sp[2]=36;
			sp[3]=64;
			sp[4]=100;
			sp[5]=102;
			sp[6]=128;
			sp[7]=129;
			sp[8]=136;
			sp[9]=137;
			sp[10]=150;
			sp[11]=151;
			sp[12]=165;
			sp[13]=169;
			sp[14]=174;
			sp[15]=175;
			sp[16]=188;
			sp[17]=189;
			sp[18]=192;
			sp[19]=193;
			sp[20]=202;
			sp[21]=208;
			sp[22]=212;
			sp[23]=213;
			sp[24]=230;
			sp[25]=231;
			sp[26]=240;
			sp[27]=244;
			sp[28]=246;
			sp[29]=247;
			sp[30]=252;
			sp[31]=254;
			sp[32]=278;
			sp[33]=284;
			sp[34]=292;
			sp[35]=317;
			sp[36]=321;
			sp[37]=356;
			sp[38]=357;
			loadSpc(land,sp);
			break;
		case 10:
			n=50;
			sp[0]=3;
			sp[1]=41;
			sp[2]=28;
			sp[3]=43;
			sp[4]=44;
			sp[5]=45;
			sp[6]=46;
			sp[7]=47;
			sp[8]=48;
			sp[9]=49;
			sp[10]=50;
			sp[11]=52;
			sp[12]=53;
			sp[13]=54;
			sp[14]=55;
			sp[15]=56;
			sp[16]=60;
			sp[17]=61;
			sp[18]=62;
			sp[19]=69;
			sp[20]=70;
			sp[21]=71;
			sp[22]=72;
			sp[23]=73;
			sp[24]=74;
			sp[25]=75;
			sp[26]=77;
			sp[27]=78;
			sp[28]=79;
			sp[29]=80;
			sp[30]=81;
			loadSpc(land,sp);
			break;
		case 7:
			n=30;
			fp1=fopen("record.dat","r");
			num=0; //Size
			
			//load size
			while(!feof(fp1))
			{
				chr=fgetc(fp1);
				if(chr>=48&&chr<=57)
				num=num*10+chr-48;
			}
			
			dec=(int)pow(2.0,(float)num*num); 
			i=0;
			fp2=fopen("log.txt","a");
			
			while(i<dec)
			{
				i++;
				printf("\n Number = %d",i);
				clearArray(land);
				initializeLand(land,num,i);
				displayArray(land,num);
				getch();
				gen=simLife(land);
				if(gen>limit)
				{
					printf("\n%d survived",i);
					toStr(str,i);
					fputs(str,fp2);
					fputc('\n',fp2);
					
				}
			}
			fclose(fp2);
			fclose(fp1);
			break;
		case 8:
			gen=0;
			printf("\nEnter the size of load matrix: ");
			scanf("%d",&num);
			printf("\nEnter the decimal number: ");
			scanf("%d",&no);
			
			initializeLand(land,num,no);
			displayArray(land,num);
			getch();
			
			break;	
		case 20:printf("\n\nEnter the grid size: ");
			scanf("%d",&n);
			break;
		case 21:wrap=1-wrap;
			break;
		case 22:showLife=1-showLife;
			break;
		case 23:printf("\nEnter the new Load Position: ");
			scanf("%d",&loadpos);
			break;
		case 24:
			printf("\nEnter the Upper Limit for generations: ");	
			scanf("%d",&limit);
			break;
		case 9:exit(1); 
		default:printf("\t Please Choose Correct Option!!\n\n");
			system("cls");
			break;
	}
}

void initializeLand(int land[MAX][MAX],int num,int d)
{
	int i,j;
	for(i=loadpos;i<n;i++)
	{
		for(j=loadpos;j<n;j++)
		{
			if(i<num+(loadpos)&&j<(num+loadpos))
			{
				land[i][j]=d%2;
				d=d/2;
			}
			else
			land[i][j]=0;;
				
		}
	}
}

int simLife(int land[MAX][MAX])  //Returns number of lives a species survived
{
	int i,j;
	char op;
	int no;
	int gen=0;
	int tr,ltr;
	int land2[MAX][MAX];
	
	while(1)
		{
			gen++;
			//sleep(1);
			system("cls");
			if(showLife==1)
			{
				display(land);
				printf("\nGeneration %d  --- PRESS q to exit Life ---",gen);
				op=getch();
				if(op=='q')
				break;
			}
			tr=0;
			ltr=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					no=neighbor2(land,i,j);
					//printf("%d",no);
					
					if(no==3&&land[i][j]==1||no==2&&land[i][j]==1||no==3&&land[i][j]==0)
					{
						tr=1;//condition to terminate empty land
						land2[i][j]=1;
					}
					else
					land2[i][j]=0;
					if(land[i][j]!=land2[i][j])
					{
						ltr=1;
					}
				}
				//printf("\n");
			}
			
			if(tr==0||gen>limit||ltr==0)
			break;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					land[i][j]=land2[i][j];
				}
			}
		}
		return gen;
}

void main()
{
	int ch;
	int i,j;
	int land[MAX][MAX];
	while(1)
	{
		printf("\nDefault Values:");
		printf("\n>Size of Display = %dx%d",n,n);
		printf("\t>Generation UpperLimit = %d",limit);
		printf("\n>World Wrapping = %d",wrap);
		printf("\t\t>Loading position = [%d,%d]",loadpos,loadpos);
		printf("\n>Simulation Display = %d",showLife);
		printf("\n\nChoose a species:\n");
		printf("\n1>Block    \t\t\t20>To change number of Size of display");
		printf("\n2>Beehive   \t\t\t21>Toggle Wrap");
		printf("\n3>Loaf       \t\t\t22>Toggle Show Life");
		printf("\n4>Beacon  \t\t\t23>To change LoadPosition");
		printf("\n5>Glider \t\t\t24>Change number of generations: ");
		printf("\n6>Gophers Gun");
		printf("\n7>Continue with Species Search");
		printf("\n8>Enter a Species (decimal)");
		printf("\n10>Linear Gun");
		printf("\n9>Exit");
		printf("\nCHOOSE : ");
		scanf("%d",&ch);
		clearArray(land);
		
		loadSelected(land,ch);
		
		simLife(land);
		//Infinite loop
				
	}
}
