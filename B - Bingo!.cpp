#include<iostream>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	int n,b;
	int a[95];
	int c[95];
	memset(a,0,sizeof(a));
	while(cin>>n>>b)
	{
		bool flag=1;
		if(n==0 && b==0)
			break;
		for(int i=0;i<b;i++)
		{
			cin>>c[i];
		}
		for(int i=0; i<b;i++)
		{
			for(int j=i;j<b;j++)
			{
				int temp = abs(c[i]-c[j]);
				a[temp]++;
			}
		}
		for(int i=0;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<"N"<<endl;
				flag=0;
				break;
			}
		}
		if(flag)
			cout<<"Y"<<endl;
		memset(a,0,sizeof(a));
	}
}
