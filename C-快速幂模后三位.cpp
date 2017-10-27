#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==0 && b==0)
			break;
		long long r=1,base=a;
		while(b)
		{
			if(b%2)
				r*=base;
			base*=base;
			r%=1000;
			base%=1000;
			b/=2;
		}
		cout<<r<<endl;
	}
}
