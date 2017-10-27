#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,k,v,num=0;
		cin>>n>>m>>v>>k;
		if(n<=m)
			cout<<"0"<<endl;
		else
		{
			if(m>=((m-v)*k))
			{
				cout<<"-1"<<endl;
			}
			else
			{
				while(m<n)
				{
					m=(m-v)*k;
					num++;
				}
				cout<<num<<endl;
			}
		}
	}
	
	return 0;
}
