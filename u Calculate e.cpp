#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
int main()
{
	double e=1;
	int i;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	cout<<"0 1"<<endl;
	for(i=1;i<=9;i++)
	{
		int k=i;
		double b=1;
		while(k>0)
		{
			b=b*k;
			k-=1;
		}
		e=e+1/b;
		if(i<3)
		cout<<i<<" "<<e<<endl;
		else
		cout<<fixed<<setprecision(9)<<i<<" "<<e<<endl;
	}
	return 0;
}
