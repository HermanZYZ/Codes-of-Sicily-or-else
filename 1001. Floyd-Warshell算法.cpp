#include <iostream>
#include <cstdio>

using namespace std;

const int MAX=105;
const int INF=1e9;

int dis[MAX][MAX];


int main()
{
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	///////////////////////////
	//初始化
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=INF;
	///////////////////////////
	int i_,j_,d;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d %d",&i_,&j_,&d);
		if(dis[i_][j_]>d)//多重边考虑
			dis[i_][j_]=d;
	}
	////////////////////////////
	//主要部分
	for(int k_=1;k_<=n;k_++)   
		for(int i=1;i<=n;i++)   
		    for(int j=1;j<=n;j++)   
				if(dis[i][j]>dis[i][k_]+dis[k_][j])   
				    dis[i][j]=dis[i][k_]+dis[k_][j]; 
	////////////////////////////
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&i_,&j_);
		if(dis[i_][j_]!=INF)
			printf("%d\n",dis[i_][j_]);
		else
			printf("-1\n");
	}
}