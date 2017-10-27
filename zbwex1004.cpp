#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long N,M,i=1;
	long long b,c=1,d=0,e,f,g,h;
	scanf("%lld%lld",&N,&M);
	long long n=N-1;
	long long a[n+1];
	long long t;
	long long ans = 0;
	a[0] = 0;
	while(i<=N)
	{
		scanf("%lld",&t);
		a[i] = a[i-1] + t;
		i++;
	}
	while(M--)
	{
		scanf("%lld",&b);
		if(b==1)
		{
			c *= -1;
			d *= -1;
		}
		if(b==2)
		{
			scanf("%lld",&e);
			d += e;
		}
		if(b==3)
		{
		    scanf("%lld%lld",&g,&h);
			ans = (a[h] - a[g-1]) * c + d * (h-g+1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

