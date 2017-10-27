#include <bits/stdc++.h>

using namespace std;

int item[1005],bins[1005];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,q,result=0;
	while(cin>>n>>q)
	{
		result=0;
		for(int i=0;i<1005;i++)
			bins[i]=q;

		for(int i=0;i<n;i++)
			cin>>item[i];
		sort(item,item+n,cmp);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<1005;j++)
			{
				if(bins[j]==q)
				{
					bins[j]-=item[i];
					result++;
					break;
				}
				else if(bins[j]>=item[i])
				{
					bins[j]-=item[i];
					break;
				}
			}
		}
		cout<<result<<endl;
	}
}