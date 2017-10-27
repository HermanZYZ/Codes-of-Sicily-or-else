#include <bits/stdc++.h>

using namespace std;

const int MAX=500;
const int INF=1<<9;

int dis[MAX][MAX];

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n&&n)
	{
		memset(dis,0,sizeof(dis));
		int Dis;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>Dis;
				if(Dis<0)
					Dis=INF;
				dis[i][j]=Dis;
			}

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				{
					if(dis[j][k]>dis[j][i]+dis[i][k])
						dis[j][k]=dis[j][i]+dis[i][k];
				}

		int result=2;
		for(int i=1;i<n-1;i++)
			if(dis[0][i]+dis[i][n-1]==dis[0][n-1])
				result++;

		cout<<result<<endl;
	}
	return 0;
}