#include<bits/stdc++.h>

using namespace std;

int f[35],g[35];

void init()
{
	f[0]=1;
	g[0]=0;
	for(int i=1;i<16;i++)
	{
		f[i]=3*f[i-1]+g[i-1];
		g[i]=2*f[i-1]+g[i-1]; 
	}
}

int main()
{
	int n;
	init();
	while(cin>>n && n!=-1)
	{
		if(n%2==0)
			cout<<f[n/2]<<endl;
		else
			cout<<0<<endl;
	}
}
