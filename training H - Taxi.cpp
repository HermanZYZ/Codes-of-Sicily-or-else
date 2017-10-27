#include<iostream>

using namespace std;
int main()
{
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		if(a>=c)
			cout<<a<<endl;
		else
		while(a<=c)
		{
			if((a+b)<c)
				a+=b;
			else
			{
				cout<<c<<endl;
				break;
			}
			if((c-d)>a)
				c-=d;
			else
			{
				cout<<a<<endl;
				break;
			}
		}
	}
}
