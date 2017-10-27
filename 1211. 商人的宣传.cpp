#include<iostream>
#include<cstring>
using namespace std;
#define MAX 105

int road1[MAX][MAX]={0};
int road2[MAX][MAX]={0};
int road3[MAX][MAX]={0};

int main()
{
	int n,m,l;
	cin>>n>>m>>l;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		road1[x][y]++;
		road2[x][y]++;
	}
	
	for(int i=0;i<l-1;i++)
	{
		memset(road3, 0, sizeof(road3));
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				for(int k=1;k<=n;k++)
					road3[x][y] += road1[x][k] * road2[k][y];
			}
		}
		memcpy(road1, road3, sizeof(road1));
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<road3[x][y]<<endl;
	} 
	
} 


