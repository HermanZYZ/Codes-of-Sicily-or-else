#include<iostream>
#include<cstring>
using namespace std;
int a[10000001];

using namespace std;
int main()
{
	int k,p;
	while(cin>>k>>p)
	{
		memset(a,0,sizeof(a));
		a[2]=a[3]=1%p;
		for(int i=4;i<=k;i+=2)
		{
			a[i]=a[i+1]=(a[i/2]+a[i-1])%p;
		}
		cout<<a[k]<<endl;
	} 
}
