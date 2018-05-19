#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int n,m=0;
	int ar[20]={2,7,7,5,2,1,0,5,6,6,4,6,2,2,1,1,1,1};
	n=18;
	for(i=0;i<n;i++)
	{
		for(j=0;j<ar[i];j++)
		printf("*");
		printf("\n");
	}
	int up=0;
	int down=0;
	int flat=0;
	for(i=0;i<n;i++)
	{
		if(ar[i]<ar[i+1])
		{
			up=1;
			down=0;
		}
		if(ar[i]>ar[i+1])
		{
			down=1;
		
		if(up==1&&down==1)
		{m++;
		up=0;
		}
		
	    }
	}
	
	printf("\n%d",m );
	

	return 0;
}
