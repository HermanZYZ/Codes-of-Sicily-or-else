#include<bits/stdc++.h>

using namespace std;

long long dp[1005][5];

void init()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<1005;i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
		if(i>1)
			dp[i][0]+=dp[i-2][0];
		dp[i][1]=dp[i-1][0]+dp[i-1][2];
		dp[i][2]=dp[i-1][0]+dp[i-1][1];
		dp[i][3]=dp[i-1][0]+dp[i-1][4];
		dp[i][4]=dp[i-1][3];
	}
} 

int main()
{
	int t,n;
	init();
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		cout<<i<<" "<<dp[n][0]<<endl;
	}
		
}
