#include<bits/stdc++.h>

using namespace std;

const int maxn = 501;
const int INF = 1<<30;
int n,m;
int a[maxn],b[maxn];
int f[maxn][maxn];

int minimal()
{
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(i==0&&j==0)
				f[i][j]=0;
			else if(j<i)
				f[i][j]=INF;
			else
			{
				f[i][j]=INF;
				if(i>0)
				{
					f[i][j]=min(f[i][j],f[i-1][j-1]+abs(a[i]-b[j]));
				}
				if(j>0)
				{
					f[i][j]=min(f[i][j],f[i][j-1]);
				}
					
			}
	return f[n][m];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int j=1;j<=m;j++)
			cin>>b[j];
			
		cout<<minimal()<<endl;
	}
}
