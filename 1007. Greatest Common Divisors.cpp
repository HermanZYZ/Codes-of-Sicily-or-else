#include <bits/stdc++.h>

using namespace std;

bool solve[1005];

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		memset(solve,0,sizeof(solve));
		int a,b,low,high;
		cin>>a>>b>>low>>high;
		for(int i=1;i<=min(a,b);i++)
		{
			if(a%i==0 && b%i==0)
				solve[i]=1;
		}
		bool flag = false;
		int greatest=0;
		for(int i=low;i<=high;i++)
			if(solve[i])
			{
				greatest=max(greatest,i);
				flag=true;
			}
		if(!flag)
			cout<<"No answer"<<endl;
		else
			cout<<greatest<<endl;
	}
}