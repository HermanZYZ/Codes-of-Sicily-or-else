#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	int a[105],b[105];
	while(cin>>n)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		int area=0;
		for(int i=1;i<=n;i++)
		{
			if(i==n)
				area+=a[i]*b[1]-a[1]*b[i];
			else
				area+=a[i]*b[i+1]-a[i+1]*b[i];
		}
		cout<<fixed<<setprecision(1)<<1.0*area/2<<endl;
	} 
	
	return 0;
}
