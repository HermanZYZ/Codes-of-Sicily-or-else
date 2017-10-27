#include<iostream>
#include<cmath>  
#include<cstdio>  
#include<algorithm>  
using namespace std;

double dis[105][105];
double x[105], y[105];
double leng[105];

void CalDis(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			double dx = x[i] - x[j];
			double dy = y[i] - y[j];
			double len = sqrt(dx*dx+ dy*dy);
			dis[i][j] = dis[j][i] = len;
		}
	}
}

int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		for(int i=0;i<n;i++)
			cin >> x[i] >> y[i];
		CalDis(n);
		int left=n;
		int edges=0;
		while(left>1)
		{
			double min=10000;
			int pos=0; //prim算法
			for(int i=0;i<n;i++)
			{
				if(dis[0][i]<min&&dis[0][i]>0)
				{
					min = dis[0][i];
					pos = i;	
				}	
			} 
			leng[edges++]=min;
			left--; 
			dis[0][pos]=dis[pos][0]=0;
			
			for(int i=0;i<n;i++)
			{  //定位新连入的点的所有边中最短的边 
				if(dis[pos][i]<dis[0][i]&&dis[pos][i]!=0)
					dis[0][i]=dis[pos][i]; 
			} 
		} 
		sort(leng,leng+edges);
		double ans= leng[edges-k+1]; 
		printf("%.2f\n",ans); 
		
	}
}
