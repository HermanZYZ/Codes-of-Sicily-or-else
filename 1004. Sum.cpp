#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100005]={0,0,};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d",&num);
		a[i]=a[i-1]+num;
	}
	int l,r;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",a[r]-a[l-1]);
	}
}
