#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u,v,weight;	//起点、终点、权值
}edge[200005];

bool cmp(Edge a,Edge b)//升序排序
{
	return a.weight < b.weight;
}

int x[200005];//用来做端点集合标记，标记两个端点是否在同一集合

int main()
{
	int m,n;
	while(~scanf("%d %d",&m,&n))//m为顶点数，n为边数
	{
		if(m==0 && n==0)
			break;

		for(int i=0;i<=m;i++)//初始化集合
			x[i]=i;
		int total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].weight);
			total+=edge[i].weight;//总权值
		}
		sort(edge,edge+n,cmp);
		int min=0,num=0;//最小权值及边数
		int k,g;
		for(int i=0;i<n && num < m-1;i++)
		{
			//printf("%d\n", edge[i].weight);
			for(k=edge[i].u;x[k]!=k;k=x[k])//判断线段的起始点所在的集合
				x[k]=x[x[k]];
			for(g=edge[i].v;x[g]!=g;g=x[g])//判断线段的终点所在的集合  
				x[g]=x[x[g]];

			if(k!=g)//如果线段的两个端点所在的集合不一样 
			{
				x[g]=k;
				min+=edge[i].weight;
				num++;
				//printf("$$$%d %d\n", edge[i].u,edge[i].v);
			}
		}

		printf("%d\n", total - min);
	}
}