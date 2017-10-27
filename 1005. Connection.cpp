#include <bits/stdc++.h>

using namespace std;

std::vector<int> city[105];
bool visited[105];

void Visit(int index)
{
	for(int i=0;i<city[index].size();i++)
	{
		if(!visited[city[index][i]])
		{
			visited[city[index][i]]=true;
			Visit(city[index][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m)
	{
		if (n==m && n==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
			city[i].clear();
		memset(visited,0,sizeof(visited));
		int a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			city[a].push_back(b);
			city[b].push_back(a);
		}
		int result=0;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				result++;
				visited[i]=true;
				Visit(i);
			}
		}
		cout<<result-1<<endl;
	}
	return 0;
}