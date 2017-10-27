#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int base;
		cin>>base;
		string a,b;
		cin>>a>>b;
		long long c,d;
		char* stop;
		c=strtol(a.c_str(),&stop,base);
		d=strtol(b.c_str(),&stop,base);
		cout<<d<<endl;
		char e[105];
		cout<<itoa(c+d,e,base)<<endl;
	}
}
