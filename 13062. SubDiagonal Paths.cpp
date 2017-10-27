#include<iostream>
#include<cstring>

using namespace std;

long long dp[35][35];

int main()
{
	int n;
	while(cin>>n && n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			dp[i][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
			}
		cout<<dp[n][n]<<endl;
	}
}
