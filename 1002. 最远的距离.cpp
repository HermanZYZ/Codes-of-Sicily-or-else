#include <iostream>

using namespace std;

const int MAX=30;
const int INF=1e9;

int road[30][30];

void init()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(i==j)
				road[i][j]=0;
			else
				road[i][j]=INF;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		init();
		int n;
		cin>>n;
		int a,b;
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b;
			road[a][b]=1;
			road[b][a]=1;//无向图
		}
		for(int k_=1;k_<=n;k_++)   
			for(int i=1;i<=n;i++)   
			    for(int j=1;j<=n;j++)   
					if(road[i][j]>road[i][k_]+road[k_][j])   
					   {
					   		road[i][j]=road[i][k_]+road[k_][j]; 
					   		//cout<<road[i][j]<<"*"<<i<<" "<<j<<endl;;
					   }

		int longest=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(road[i][j]>longest && road[i][j]!=INF)
					longest=road[i][j];
		cout<<longest<<endl;
	}
}
