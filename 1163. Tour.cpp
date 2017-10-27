#include<bits/stdc++.h>

using namespace std;

double dp[55][55];
double d[55][55];
int x[55],y[55];

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=hypot(x[i]-x[j],y[i]-y[j]);
				
		dp[0][1]=d[0][1];
		for(int k=2;k<n;k++)
		{
			for(int i=0;i<k-1;i++)
				dp[i][k]=dp[i][k-1]+d[k-1][k];
			dp[k-1][k]=10000000;
			for(int i=0;i<k-1;i++)
				dp[k-1][k]=min(dp[k-1][k],dp[i][k-1]+d[i][k]);
			
		}
		cout<<fixed<<setprecision(2)<<dp[n-2][n-1]+d[n-2][n-1]<<endl;
	}
}
