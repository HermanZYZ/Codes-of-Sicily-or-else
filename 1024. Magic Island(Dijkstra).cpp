#include<iostream>

using namespace std;

#define MAX 10005
#define INF -1

bool final[MAX];

int pre[MAX],dist[MAX];

struct Graph
{
	int vexnum;
	int adj[MAX][MAX];
};

Graph *G =new Graph;

void Creat(int n)
{
	int x,y,d;
	G->vexnum=n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>d;
		G->adj[x][y]=d;
		G->adj[y][x]=d;
	}
}

void Dijkstra(Graph *G,int v)
{
	int j,k,m,min;
	for(j=1;j<=G->vexnum;j++)
	{
		pre[j]=v;
		final[j]=false;
		dist[j]=G->adj[v][j];
	}
	dist[v]=0;
	final[v]=true;
	for(j=1;j<=G->vexnum;j++)
	{
		m=1;
		while(final[m])
			m++;
		min=INF;
		for(k=1;k<=G->vexnum;k++)
		{
			if(!final[k] && dist[k]>min)
			{
				min=dist[k];
				m=k;
			}
		}
		final[m]=true;
		for(j=1;j<=G->vexnum;j++)
		{
			if(!final[j] && (dist[m]+G->adj[m][j]>dist[j]))
			{
				dist[j]=dist[m]+G->adj[m][j];
				pre[j]=m;
			}
		}
	}
}

int main()
{
	int n,v;
	while(cin>>n>>v)
	{
		 Creat(n);
		 Dijkstra(G,v);
		 int max=0;
		 for(int i=1;i<=n;i++)
		 {
		 	if(max<dist[i])
		 		max=dist[i];
		 }
		 cout<<max<<endl;
	}
}
