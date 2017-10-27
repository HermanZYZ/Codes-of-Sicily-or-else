#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	while(a<=b)
	{
		if(a%2==1)
			cout<<a<<endl;
		a++;
	} 
	return 0;
}
