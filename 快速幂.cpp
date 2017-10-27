#include<iostream>
using namespace std;
int main()
{
	int a,b,p;
	cin>>a>>b>>p;
	long long r=1,base=a;
	while(b)
	{
		if(b%2)
			r*=base;
		base*=base;
		r%=p;
		base%=p;
		b/=2;
		
	}
	;
}
