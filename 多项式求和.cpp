#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int m;
	int n;
	cin>>m;
	while(m--)
	{
		int i;
		double sum=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			sum=sum+1.0*pow(-1,i+1)*1/i;
		}
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	return 0;
}
