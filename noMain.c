#include<stdio.h>
#define fn(e,d,b,c,f,a) a##b##c##d
#define no_main() fn(o,n,a,i,d,m)()
void no_main()
{
	printf("Hello Universe");
}
