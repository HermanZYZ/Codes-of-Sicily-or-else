#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Road
{
	int destination,distrance;
	Road(int de,int dis)
	{
		destination = de;
		distrance = dis;
	}
};

vector<Road> road[100001];
bool visited[100001];
int longest;

void DFS(int begin,int dis)
{
	if(dis > longest)
		longest = dis;
	visited[begin]=true;
	
	for(int i=0;i < (int)road[begin].size();i++)
	{
		if(!visited[road[begin][i].destination])
			DFS(road[begin][i].destination,dis + road[begin][i].distrance);
	}
}

int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		longest = 0;
		memset(visited,false,sizeof(visited));
		memset(road,0,sizeof(road));
		int x,y,d;
		
		for (int i = 0; i < n - 1; i++) {  
            cin>>x>>y>>d;  
            road[x].push_back(Road(y, d));//注意这里两点是互通的  
            road[y].push_back(Road(x, d));  
        } 
        
        DFS(k,0);
        cout<<longest<<endl;
	}
	return 0;
}
