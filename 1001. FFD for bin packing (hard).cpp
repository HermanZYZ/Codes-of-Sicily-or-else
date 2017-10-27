#include <bits/stdc++.h>

using namespace std;

int item[1000005];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,q,result=0;
	multiset<int> bins;
	while(~scanf("%d%d",&n,&q))
	{
		result=0;
		bins.clear();
		for(int i=0;i<1005;i++)
			item[i]=q;

		for(int i=0;i<n;i++)
			scanf("%d",&item[i]);
		sort(item,item+n,cmp);

		multiset<int>::iterator it=bins.end();
		for(int i=0;i<n;i++)
		{
			it=bins.lower_bound(item[i]);
			
			if(it==bins.end())
			{
				result++;
				bins.insert(q-item[i]);
			}
			else
			{
				int temp=(*it)-item[i];
				bins.erase(it);
				if(temp!=0)
					bins.insert(temp);
			}
		}
		printf("%d\n", result);
	}
}