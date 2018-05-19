#include<stdio.h>
int main()
{
	
	int i=0,j=0;
	int n=6;
	
	/*BOX*/
	for(i=0;i<n;i++)
	{
		printf("*");
	}
	printf("\n");
	for(i=0;i<n-2;i++)
	{
		printf("*");
		for(j=0;j<n-2;j++)
		printf(" ");
		
		printf("*\n");
	}
	
	for(i=0;i<n;i++)
	{
		printf("*");
	}
	
	/*Right Diagonal*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(j==n-i)
		printf("*");
		else
		printf(" ");
		printf("\n");
	}
	/* X */
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(i==j)
		printf("*");
		else
	    printf(" ");
	    
		for(j=0;j<n;j++)
		if(n-i==j)
		printf("*");
		else
		printf(" ");
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(n-i==j)
		printf("*");
		else
		printf(" ");
		
		for(j=0;j<n;j++)
		if(i==j)
		printf("*");
		else
	    printf(" ");
	    printf("\n");
	    
	}
	return 0;
}
