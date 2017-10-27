#include<bits/stdc++.h>

using namespace std;

int dp[105][105];

void init()
{
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
		for(int i=1;i<105;i++)
			for(int j=0;j<i;j++)
			{
				//if(j==0) 
					//dp[i][j]=1; 
				//else
				//{
					dp[i+1][j]+=(dp[i][j]*(j+1)%2007);
					dp[i+1][j]%=2007;
					dp[i+1][j+1]+=(dp[i][j]*(i-j)%2007);
					dp[i+1][j+1]%=2007;
				//}
				
			}
}

int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		
		init();
		cout<<dp[n][k]<<endl;
	}
} 
