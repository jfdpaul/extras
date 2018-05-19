#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{
		for(j=i;j<n;j++)
		{
			printf("   ");
		}
		for(j=1;j<=i*2-1;j++)
		{
			printf(" %d ",j);
		}
		printf("\n");
	}
	printf("\n\n\n");
	for(i=n;i>0;i--)
	{
		for(j=1;j<i;j++)
		printf("   ");
		for(j=1;j<(n-i+1)+1;j++)
		{
			printf(" %d ",j);
		}
		for(j=(n-i);j>0;j--)
		{
			printf(" %d ",j);
		}
		printf("\n");
	}
}
