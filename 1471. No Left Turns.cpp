#include <bits/stdc++.h>

using namespace std;

const int Max = (1<<9);

char key[21][21];
int dis[21][21][4];
int start_x,start_y,finish_x,finish_y;

struct Node
{
	int x,y,dir;//0:up 1:right 2:dowm 3:left
	Node(int a,int b,int c):x(a),y(b),dir(c){}
};
queue <Node> q;

void init(int r,int c)
{
	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			for(int k=0;k<4;k++)
				dis[i][j][k]=Max;
	char temp;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			temp=getchar();
			if(temp=='F')
			{
				finish_x=i;
				finish_y=j;
				key[i][j]='F';
			}
			else if(temp=='S')
			{
				start_y=j;
				start_x=i;
				key[i][j]=' ';
			}
			else
				key[i][j]=temp;
		}
		getchar();
	}
}

void bfs()
{
	for(int i=0;i<4;i++)
	{
		q.push(Node(start_x,start_y,i));
		dis[start_x][start_y][i]=0;
	}
	
	while(!q.empty())//改进：利用数组来保存方向、保存每个点的耗时然后判断来选择是否入列
	{
		Node node = q.front();
		q.pop();

		if(node.dir==0)
		{
			if(key[node.x-1][node.y]==' ')
			{	//cout<<node.x<<" "<<node.y<<" "<<node.dir<<endl;
				if(dis[node.x-1][node.y][0]==Max)
					q.push(Node(node.x-1,node.y,0));
				if(dis[node.x-1][node.y][1]==Max)
					q.push(Node(node.x-1,node.y,1));
				
				dis[node.x-1][node.y][0]=min(dis[node.x-1][node.y][0],dis[node.x][node.y][0]+1);
				dis[node.x-1][node.y][1]=min(dis[node.x-1][node.y][1],dis[node.x][node.y][0]+1);
			}
			else if(key[node.x-1][node.y]=='F')
				dis[node.x-1][node.y][0]=min(dis[node.x-1][node.y][0],dis[node.x][node.y][0]+1);
		}
		else if(node.dir==1)
		{
			if(key[node.x][node.y+1]==' ')
			{	//cout<<node.x<<" "<<node.y<<" "<<node.dir<<endl;
				if(dis[node.x][node.y+1][1]==Max)
					q.push(Node(node.x,node.y+1,1));
				if(dis[node.x][node.y+1][2]==Max)
					q.push(Node(node.x,node.y+1,2));

				dis[node.x][node.y+1][1]=min(dis[node.x][node.y+1][1],dis[node.x][node.y][1]+1);
				dis[node.x][node.y+1][2]=min(dis[node.x][node.y+1][2],dis[node.x][node.y][1]+1);

			}
			else if(key[node.x][node.y+1]=='F')
				dis[node.x][node.y+1][1]=min(dis[node.x][node.y+1][1],dis[node.x][node.y][1]+1);
		}
		else if(node.dir==2)
		{
			if(key[node.x+1][node.y]==' ')
			{	//cout<<node.x<<" "<<node.y<<" "<<node.dir<<endl;
				if(dis[node.x+1][node.y][2]==Max)
					q.push(Node(node.x+1,node.y,2));
				if(dis[node.x+1][node.y][3]==Max)
					q.push(Node(node.x+1,node.y,3));

				dis[node.x+1][node.y][2]=min(dis[node.x+1][node.y][2],dis[node.x][node.y][2]+1);
				dis[node.x+1][node.y][3]=min(dis[node.x+1][node.y][3],dis[node.x][node.y][2]+1);
			}
			else if(key[node.x+1][node.y]=='F')
				dis[node.x+1][node.y][2]=min(dis[node.x+1][node.y][2],dis[node.x][node.y][2]+1);
		}
		else if(node.dir==3)
		{
			if(key[node.x][node.y-1]==' ')
			{	//cout<<node.x<<" "<<node.y<<" "<<node.dir<<endl;
				if(dis[node.x][node.y-1][3]==Max)
					q.push(Node(node.x,node.y-1,3));
				if(dis[node.x][node.y-1][0]==Max)
					q.push(Node(node.x,node.y-1,0));

				dis[node.x][node.y-1][3]=min(dis[node.x][node.y-1][3],dis[node.x][node.y][3]+1);
				dis[node.x][node.y-1][0]=min(dis[node.x][node.y-1][0],dis[node.x][node.y][3]+1);
			}
			else if(key[node.x][node.y-1]=='F')
				dis[node.x][node.y-1][3]=min(dis[node.x][node.y-1][3],dis[node.x][node.y][3]+1);
		}
	}
}

int main()
{
	int t,r,c;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d %d\n",&c,&r);
		init(c,r);
		bfs();
		int Min = 1<<9;
		for(int i=0;i<4;i++)
		{
			if(Min>dis[finish_x][finish_y][i])
				Min=dis[finish_x][finish_y][i];
		}
		printf("%d\n", Min);
	}
}