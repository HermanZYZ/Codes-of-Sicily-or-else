#include<bits/stdc++.h>

using namespace std;

int sum[3005];
vector<int> tree[3005];


int main()
{
	int n,k;
	scanf("%d %d\n",&n,&k);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d\n",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
}
