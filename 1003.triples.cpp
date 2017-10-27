#include<iostream>
#include<cstdio>
using namespace std;
int arr[205][205][205]={};
int main()
{
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d%d%d",&a,&b,&c);
		arr[a][b][c]=1;
	}
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(arr[a][b][c]==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
