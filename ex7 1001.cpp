#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n,maxnum;
	cin>>n;
	cin>>maxnum;
	n=n-1;
	while(n--)
	{
		int a;
		cin>>a;
		maxnum=max(a,maxnum);
	}
	cout<<maxnum<<endl;
	return 0;
}
