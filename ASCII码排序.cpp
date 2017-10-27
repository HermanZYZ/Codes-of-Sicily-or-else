#include<iostream>
using namespace std;
int main()
{
	char a,b,c;
	char max,min;
	while(cin>>a>>b>>c)
	{
		if(a>b)
		{
			if(c>a)
			cout<<b<<" "<<a<<" "<<c<<endl;
			else if(c<b)
			cout<<c<<" "<<b<<" "<<a<<endl;
			else
			cout<<b<<" "<<c<<" "<<a<<endl;
		}
		else
		{
			if(c>b)
			cout<<a<<" "<<b<<" "<<c<<endl;
			else if(c<a)
			cout<<c<<" "<<a<<" "<<b<<endl;
			else
			cout<<a<<" "<<c<<" "<<b<<endl;
		}
	}
	return 0;
} 
