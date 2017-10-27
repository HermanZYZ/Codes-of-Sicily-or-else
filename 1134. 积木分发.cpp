#include<iostream>
#include<algorithm>

using namespace std;

struct Pancakes
{
	int has;
	int need;
};

bool cmp(Pancakes a,Pancakes b)
{
	return a.need<b.need;
}

int main()
{
	int n,s,kids[10001];
	Pancakes pan[10001];
	while(cin>>n>>s && n)
	{
		for(int i=0;i<n;i++)
			cin>>pan[i].has>>pan[i].need;
		sort(pan,pan+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(s+kids[i]<pan[i].need)
			{
				cout<<"NO"<<endl;
				break;
			}
			else
			{
				kids[i+1]=kids[i]+pan[i].has;
				if(i==n-1)
					cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}
