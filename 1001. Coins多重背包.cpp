#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>

using namespace std;

struct coin
{
	int weigth;
	double value;
};

coin coins[7];

double Max[7][10005];

int main()
{
	
	coins[1].weigth=3,coins[1].value=0.01;
	coins[2].weigth=5,coins[2].value=0.05;
	coins[3].weigth=2,coins[3].value=0.10;
	coins[4].weigth=6,coins[4].value=0.25;
	coins[5].weigth=11,coins[5].value=0.50;
	coins[6].weigth=8,coins[6].value=1;
	int m;
	int a[7];
	a[0]=0;
	while(cin>>m)
	{
		memset(Max,0,sizeof(Max));
		for(int i=1;i<=6;i++)
			cin>>a[i];
		for(int i=0;i<=6;i++)
			Max[i][0]=0;
		for(int i=0;i<=m;i++)
			Max[0][i]=0;
		for(int i=1;i<=6;i++)
		for(int w=0;w<=m;w++)
		{
			Max[i][w]=0;
			int num=min(a[i],w/coins[i].weigth);
			for(int j=0;j<=num;j++)
				Max[i][w]=max(Max[i][w],Max[i-1][w-j*coins[i].weigth]+j*1.0*coins[i].value);
		}
		cout<<"$"<<fixed<<setprecision(2)<<Max[6][m]<<endl;
	}
}
