#include<iostream>
#include<cstdio> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i=2;
	while(n!=1)
	{
		while(n%i==0)
		{
			printf("%d\n",i);
			n/=i;
		}
		i++;
	}
	return 0;
} 
