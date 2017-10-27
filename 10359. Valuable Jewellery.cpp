#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>

using namespace std;

struct Jewellery
{
	int w,v;
};

Jewellery jew[303000];

bool cmp(Jewellery a,Jewellery b)
{
	if(a.v!=b.v)
		return a.v>b.v;
	if(a.w!=b.w)
		return a.w>b.w;
}
int main()
{
	multiset<int> bag;
	int n,k;
	while(~scanf("%d%d",&n,&k)) 
	{
		long long value=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&jew[i].w,&jew[i].v);
		}
		for(int i=0;i<k;i++)  
        {
        	int temp; 
        	scanf("%d",&temp);
        	bag.insert(temp);
		} 
		sort(jew,jew+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(bag.lower_bound(jew[i].w)!=bag.end())
			{
				value+=jew[i].v;
				bag.erase(bag.lower_bound(jew[i].w));
			}
		}
		
		cout<<value<<endl;
		bag.clear();
	}
}
