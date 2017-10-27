#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	long long a,b;
	while(cin>>a>>b)
	{
		if(a<b)
		swap(a,b);
		long long j=a-b;
		a=(j*(1+sqrt(5))/2.0);
		if(a==b)
         printf("0\n");
        else
         printf("1\n");
	}
	return 0;
}




