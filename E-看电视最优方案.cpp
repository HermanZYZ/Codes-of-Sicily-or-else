#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int a[105],b[105];
		for(int i=0;i<n;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<n;i++)
 		for(int j=0;j<n-i;j++)
		if(b[j]>b[j+1])
		{
			swap(b[j],b[j+1]);
 			swap(a[j],a[j+1]);
		}
		int t=b[0],num=1;
		for(int i=0;i<n-1;i++)
		{
			if(t<=a[i+1])
			{
				num++;
				t=b[i+1];
			}
		}
		cout<<num<<endl;
	}
	
	return 0;
}
