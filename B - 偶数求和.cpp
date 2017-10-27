#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int sum1=0,sum2=0;
		if(n<=m)
		{
			for(int i=0;i<n;i++)
			{
				sum1+=2;
				sum2+=sum1;
			}
			cout<<sum2/n<<endl;
		}
		else
		{
			int mul,j=0;
			mul=n/m;
			while(j<mul)
			{
				for(int i=0;i<m;i++)
				{
					sum1+=2;
					sum2+=sum1;
				}
				if(j==0)
					cout<<sum2/m;
				else
					cout<<" "<<sum2/m;
				sum2=0;
				j++;
			}
			for(int i=0;i<n%m;i++)
			{
				sum1+=2;
				sum2+=sum1;
				
			}
			if(sum2)
			{
				cout<<" "<<sum2/(n%m);
			}
			cout<<endl;
		}
	}
	
	return 0;
}
