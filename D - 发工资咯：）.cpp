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
	while(cin>>n && n!=0)
	{
		int num=0,sal;
		for(int i=0;i<n;i++)
		{
			cin>>sal;
			num+=sal/100;
			sal%=100;
			num+=sal/50;
			sal%=50;
			num+=sal/10;
			sal%=10;
			num+=sal/5;
			sal%=5;
			num+=sal/2;
			sal%=2;
			num+=sal/1;
			sal%=1;
		}
		cout<<num<<endl;
	}
	
	return 0;
}
