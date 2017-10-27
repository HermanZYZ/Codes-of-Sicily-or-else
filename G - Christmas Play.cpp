#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int kid[20000]={0};

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&kid[i]);
		int min=0;
		sort(kid,kid+n,cmp);
		min=kid[0]-kid[k-1];
		for(int i=1;i+k-1<n;i++)
		{
			if(kid[i]-kid[i+k-1]<min)
				min=kid[i]-kid[i+k-1];
		}
		printf("%d\n",min);
	}
}
