#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring> 

using namespace std;

vector<int> ji[20005];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) !=EOF &&n&&m)
	{
		memset(ji,0,sizeof(ji));
		int u,v;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			ji[u].push_back(v);
			ji[v].push_back(u);
		}
		
		int total=0;
		int one=0;
		for(int i=0;i<=n;i++)
		{
			one=0;
			for(int j=0;j<ji[i].size();j++)
			{
				one+=ji[ji[i][j]].size();
			}
			total+=one;
		}
		printf("%d\n",total);
	}
}
