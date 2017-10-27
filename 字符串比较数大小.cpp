#include<cmath>
#include<string>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<iostream>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	string ta,tb;
	if(a.size()>b.size())
	{
		for(int i=0;i<a.size()-b.size();i++)
			tb+='0';
		for(int i=0;i<b.size();i++)
			tb+=b[i];
		ta=a;
	}
	else if(b.size()>a.size())
	{
		for(int i=0;i<b.size()-a.size();i++)
			ta+='0';
		for(int i=0;i<a.size();i++)
			ta+=a[i];
		tb=b;
	}
	else
	{
		ta=a;
		tb=b;
	}
	if(ta>tb)
		cout<<">"<<endl;
	else if(ta==tb)
		cout<<"="<<endl;
	else
		cout<<"<"<<endl; 
	
}
