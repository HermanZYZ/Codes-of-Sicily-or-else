#include<iostream>

using namespace std;

int main()
{
	int a[101]={0};
	a[0]=0;
	a[1]=1;
	int nn=1000000000+7;
	int n;
	while(cin>>n)
	{
		for(int i=2;i<=n;i++)
		{
			a[i]=(a[i-1]%nn+a[i-2]%nn)%nn;
		}
		cout<<a[n]<<endl;
	}
	
} 
