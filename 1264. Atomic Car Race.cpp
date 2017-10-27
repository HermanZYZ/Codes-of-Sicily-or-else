#include<bits/stdc++.h>

using namespace std;

int a[100];
double f[10001];
double g[10001];

int main()
{
	int n;
	while(cin>>n && n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		double b,e,f_,v,r;
		cin>>b>>r>>v>>e>>f_;
		
		g[0]=0;
		for(int i=0;i<a[n-1];i++)
		{
			g[i+1]=g[i]+(i<r? 1.0/(v-f_*(r-i)) : 1.0/(v-e*(i-r)));
			//cout<<g[i+1]<<endl;
		}
		f[0]=0;
		for(int i=0;i<n;i++)
		{
			f[i]=g[a[i]];
			for(int j=0;j<i;j++)
				f[i]=min(f[i],f[j]+g[a[i]-a[j]]+b);
			//cout<<f[i]<<endl;
		}
		cout<<fixed<<setprecision(4)<<f[n-1]<<endl;
	}
}
