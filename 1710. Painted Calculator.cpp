#include <bits/stdc++.h>

using namespace std;

int result[25][25][25];
int cost[10]={6,2,5,5,4,5,6,3,7,6};

int GetCost(int n)
{
	if (n == 0)
		return 6;
	int r = 0;
	if(n < 0)
	{
		r=1;
		n=-n;
	}
	while(n)
	{
		r+=cost[n%10];
		n/=10;
	}
	return r;
}

void init()
{
	int a,b,c;
	for(int i=-999;i<1000;i++)
	{
		a=GetCost(i);
		for(int j=-999;j<1000;j++)
		{
			b=GetCost(j);
			c=i+j;
			if(-999<=c && c<=1000)
				result[a][b][GetCost(c)]++;
			c=i-j;
			if(-999<=c && c<=1000)
				result[a][b][GetCost(c)]++;
			c=i*j;
			if(-999<=c && c<=1000)
				result[a][b][GetCost(c)]++;
			if(j==0)
				continue;
			c=i/j;
			if(-999<=c && c<=1000)
				result[a][b][GetCost(c)]++;
		}
	}
}

int main()
{
	init();
	int a,b,c;
	while(~scanf("%d",&a) && a)
	{
		scanf("%d %d",&b,&c);
		if(a>110 || b>110 || c>110)
			printf("0 solutions for %d %d %d\n",a,b,c );
		else if(result[a/5][b/5][c/5]==1)
			printf("1 solution for %d %d %d\n",a,b,c );
		else 
			printf("%d solutions for %d %d %d\n",result[a/5][b/5][c/5],a,b,c );
	}
	return 0;
}