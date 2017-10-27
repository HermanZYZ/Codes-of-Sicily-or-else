
//提交之后WA

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define MAX 205
#define INF 205 

bool final[MAX];

int pre[MAX],dist[MAX];

string point[MAX];

int point_num;

struct Graph
{
	int vexnum;
	int adj[MAX][MAX];
};

Graph *G =new Graph;

int Locate(string node,int n)
{
	for(int i=1;i<=n;i++)
		if(point[i]==node)
			return i;
	return 0;
}

void Creat(int n)
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			G->adj[i][j]=-1; 
	string s,t;
	int x,y,d;
	point_num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t>>d;
		x=Locate(s,point_num);
		if(x==0)
		{
			point_num++;
			point[point_num]=s;
			x=point_num;
		}
		y=Locate(t,point_num);
		if(y==0)
		{
			point_num++;
			point[point_num]=t;
			y=point_num;
		}
		G->adj[x][y]=d;
		G->adj[y][x]=d;
	}
	
	G->vexnum=point_num;
}

void Dijkstra(Graph *G,int v)
{
	int j,k,m,min,f;
	for(j=1;j<=G->vexnum;j++)
	{
		pre[j]=v;
		final[j]=false;
		dist[j]=G->adj[v][j];
	}
	dist[v]=0;
	final[v]=true;
	for(f=1;f<=G->vexnum;f++)
	{
		m=1;
		while(final[m])
			m++;
		min=INF;
		for(k=1;k<=G->vexnum;k++)
		{
			if(!final[k] && dist[k]<min)
			{
				min=dist[k];
				m=k;
			}
		}
		final[m]=true;
		for(j=1;j<=G->vexnum;j++)
		{
			if(!final[j] && (dist[m]+G->adj[m][j]<dist[j]))
			{
				dist[j]=dist[m]+G->adj[m][j];
				pre[j]=m;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<MAX;i++)
			point[i]="";
		int n;
		cin>>n;
		Creat(n);
		string S,T;
		cin>>S>>T;
		int x,y;
		x=Locate(S,point_num);
		y=Locate(T,point_num);
		if(S == T && x==0)
		{
			cout<<"0"<<endl;
		} 
		else if(x==0 || y==0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			Dijkstra(G,x);
			cout<<dist[y]<<endl;
		}
		
	}
	return 0;
}
