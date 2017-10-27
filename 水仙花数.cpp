#include<stdio.h>
int main()
{
	int n,m,a;
	int i=1;
	scanf("%d%d",&n,&m);
	do
	{
		a=n/10;
		i++;
	}while(a>10);
	a=n>>2;
	printf("%d%d",i,a);
	return 0;
} 
