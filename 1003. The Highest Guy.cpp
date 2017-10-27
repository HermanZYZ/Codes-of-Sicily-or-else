#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[n]=a[n];
	for(int i=n-1;i>0;i--)
	{
		if(a[i]>b[i+1])
			b[i]=a[i];
		else
			b[i]=b[i+1];
	}
	while(m--)
	{
		int num;
		scanf("%d",&num);
		printf("%d\n",b[num]);
	}
}
