#include <bits/stdc++.h>

using namespace std;

const double Distance = sqrt(2.0)/2*10;
double Min,pos_x,pos_y;
int _Time;

double Dist(double x,double y,double a,double b)
{
	return sqrt((x-a)*(x-a) + (y-b)*(y-b));
}

void dfs(double x,double y,int dir,int t)
{
	double dis=Dist(x,y,pos_x,pos_y);
	dir%=8;
	if(dis < Min)
		Min = dis;
	if(t >= _Time || (dis-10*(_Time -t) > Min))
		return ;
	switch(dir)
	{
		case 0 : dfs(x+10,y,dir,t+1);break;
		case 1 : dfs(x+Distance,y-Distance,dir,t+1);break;
		case 2 : dfs(x,y-10,dir,t+1);break;
		case 3 : dfs(x-Distance,y-Distance,dir,t+1);break;
		case 4 : dfs(x-10,y,dir,t+1);break;
		case 5 : dfs(x-Distance,y+Distance,dir,t+1);break;
		case 6 : dfs(x,y+10,dir,t+1);break;
		case 7 : dfs(x+Distance,y+Distance,dir,t+1);break;
	}
	dfs(x,y,dir+1,t+1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lf%lf",&_Time,&pos_x,&pos_y);
		Min=Dist(0,0,pos_x,pos_y);
		dfs(0,0,0,0);
		printf("%.6lf\n",Min);
	}
}