#include<bits/stdc++.h>

using namespace std;

const double INF=10000000;

double a[25][25],dp[25][1100000];


struct Point
{
	int x,y;
}p[25];

double Distance(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int Set=1;
		for(int i=2;i<n;i++)
			Set<<=1;
		
		for(int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=Distance(p[i],p[j]);
		
		for(int i=0;i<n;i++)
			for(int j=0;j<Set;j++)
				dp[i][j]=INF;
				
		for(int i=0;i<n;i++)
			dp[i][0]=a[i][0];
		for(int i=1;i<Set;i++)
			for(int j=1;j<n-1;j++)
				for(int k=1;k<n-1;k++)
					if((1<<k-1) & i)
						dp[j][i]=min(dp[j][i],a[j][k]+dp[k][i-(1<<k-1)]);
		double result=INF;
		for(int i=1;i<n;i++)
			result=min(result,dp[i][Set-1]+a[i][n-1]);
		cout<<fixed<<setprecision(2)<<result<<endl;
		
	}
	return 0;
} 
