#include<iostream>
#include<cstring>

using namespace std;

long long dp[15][2005];
long long f[15][2005];

int main()
{
	int c,n,m;
	cin>>c;
	for(int Case=1;Case<=c;Case++)
	{
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++)
		{
			f[1][i]=1;
			dp[1][i]=i;
		}
		
		for(int i=2;i<=n;i++)
		{
			f[i][0]=dp[i][0]=0;
			for(int j=1;j<=m;j++)
			{
				f[i][j]=dp[i-1][j/2];
				dp[i][j]=dp[i][j-1]+f[i][j];
			}
		}
		cout<<"Case "<<Case<<": n = "<<n<<", m = "<<m<<", # lists = "<<dp[n][m]<<endl;
	}
}
