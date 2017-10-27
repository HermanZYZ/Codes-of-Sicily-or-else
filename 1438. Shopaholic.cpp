#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int price[20005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&price[i]);
		sort(price,price+n,greater<int>());
		int result=0;
		for(int i=2;i<n;i+=3)
			result+=price[i];
		cout<<result<<endl;
	}
} 
