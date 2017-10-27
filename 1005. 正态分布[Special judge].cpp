#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define PI 3.141592684590
#define e 2.7182818253589
using namespace std;
double f(double i,double a,double dx)
{
	return pow(e,(-(a+i*dx)*(a+i*dx)/2))/pow(2*PI,0.5);
}
int main()
{
	double a,b,sum1=0,sum2=0,n,dx,k,i;
	while(cin>>a>>b>>n)
	{
		sum1=0,sum2=0;
		dx=(b-a)/n;
		for(int i=1;i<=n-1;i+=2)
			sum1+=f(i,a,dx);
		for(int i=2;i<=n-2;i+=2)
			sum2+=f(i,a,dx);
		k=dx*(f(0,a,dx)+f(n,a,dx)+4*sum1+2*sum2)/3;
		printf("%.2lf\n",k);
	}
} 
