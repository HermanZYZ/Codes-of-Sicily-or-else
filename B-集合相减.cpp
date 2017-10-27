#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int a[105],b[105];
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&m==0)
			break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			cin>>b[i];
		int tmp=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i]==b[j])
				{
					tmp++;
					a[i]=0;
				}
			}
		}
		if(tmp==n)
			cout<<"NULL";
		else
		{
			int t=0;
			sort(a,a+n);
			for(int i=0;i<n;i++)
			{
				if(a[i]!=0)
					cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
