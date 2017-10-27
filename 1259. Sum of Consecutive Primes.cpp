#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;
bool composite[MAX];
int prime[MAX],Index=0;
long long sum[MAX];

void Prime()
{
	memset(composite,false,sizeof(composite));
	for(int i = 2;i < MAX;i++)
	{
		if(composite[i])
			continue;
		prime[++Index]=i;
		for( int j = 2*i;j < MAX;j+=i)
			composite[j] = 1;
	}
	sum[0]=prime[0]=0;
	for(int i=1; i<Index;i++)
		sum[i]=sum[i-1]+prime[i];
}

int Result(int n)
{
	int result = 0;
	for (int i = 1; i <= Index; ++i)
	 {
	 	int j=lower_bound(sum,sum+Index,n+sum[i-1]) - sum;//lower_bound 返回的是指针
	 	if(j == Index || sum[j] - sum[i-1] > n)
	 		continue;
	 	result++;
	 } 
	 return result;
}

int main()
{
	int n;
	Prime();
	while(~scanf("%d",&n) && n)
	{
		printf("%d\n", Result(n));
	}
}