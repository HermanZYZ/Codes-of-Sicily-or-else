#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c==a+b || b==a+c || a==b+c)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	
	return 0;
} 
