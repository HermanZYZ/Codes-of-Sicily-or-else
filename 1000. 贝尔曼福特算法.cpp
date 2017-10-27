#include <cstdio>
#include <iostream>

const int MAX=1105;
const int INF=(1e9);

typedef struct Edge
{
	int u,v,weight;
}Edge;

Edge edge[MAX];
int dis[MAX];

int node,edgenum;

void init()
{
	scanf("%d %d\n",&node,&edgenum);
	for(int i=0;i<=node;i++)
		dis[i]=INF;
	dis[1]=0;
	for(int i=1;i<=edgenum;i++)
	{
		scanf("%d %d %d\n",&edge[i].u,&edge[i].v,&edge[i].weight);
		if(edge[i].u==1)
			dis[edge[i].v]=edge[i].weight;
	}
}

bool BF()
{
	for(int i=1;i<=node-1;i++)
		for(int j=1;j<=edgenum;j++)
			if(dis[edge[j].v] > dis[edge[j].u] + edge[j].weight)
				dis[edge[j].v] = dis[edge[j].u] + edge[j].weight;
	
	for(int j=1;j<=edgenum;j++)
		if(dis[edge[j].v] > dis[edge[j].u] + edge[j].weight)
			return 0;

	return 1;
}

int main()
{
	init();
	bool flag=BF();
	if(dis[node]==INF)
		printf("-1\n");
	else if(dis[node]<=0 || (!flag && dis[node]!=INF))
		printf("0\n");
	else
		printf("%d\n", dis[node]);
}