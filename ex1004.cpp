#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;
long long arr[100005],sum[1000005]={0};
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
		sum[i]=sum[i-1]+arr[i];
		 
	}
	long long a,x=0,l,r,record1=1,record2=0;
	for(long long i=0;i<m;i++)
	{
		scanf("%lld",&a);
		if(a==1)
		{
			record1=0-record1;
			record2=record2*(-1);//
		}
		if(a==2)
		{
			scanf("%d",&x);
			record2=record2+x;	
		}
		
		
		if(a==3)
		{
			long long s=0;
			scanf("%lld%lld",&l,&r);
			s=(sum[r]-sum[l-1])*record1+(r-l+1)*record2;
			printf("%lld\n",s);
		}
	}
	
	return 0;
} 
