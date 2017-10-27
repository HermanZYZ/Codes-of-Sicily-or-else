#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int a[1005];
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int z=1;z<=n;z++)
			a[z]=1;
		cout<<"test case "<<i<<":"<<endl;
		if(n==1)
			cout<<n<<endl;
		else
		{
			for(int j=2;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(k%j==0)
						a[k]=abs(a[k]-1);
				}
			}
			int num=0;
			for(int j=1;j<=n;j++)
				num+=a[j];
			cout<<num<<endl; 
		}
	}
	return 0;
}
