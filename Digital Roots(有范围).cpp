#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	{
		if(a==0)
		break;
		else if(a>=10)
		{
			int b=a,c=0;
			while(b>=10)
			{
				c=c+b%10;
				b=b/10;
				if(c>=10 && b<10)
				{
					c=c+b;
					b=c;
					c=0;
				}
				else
				{
					b=b+c;
					c=0;
				}
			}
			cout<<b<<endl;
		}
	}
}
