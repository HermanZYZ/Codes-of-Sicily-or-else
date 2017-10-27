#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a,b;
	cin>>a>>b;
	if(abs(a-b)<0.000001)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	return 0;
} 
