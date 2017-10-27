#include<iostream>

using namespace std;

const int mod = 1000000000+7;

//matrix
//[a,b]
//[c,d]
struct FibMatrix
{
	long long a,b,c,d;
	FibMatrix(long long aa,long long bb,long long cc,long long dd):a(aa),b(bb),c(cc),d(dd)
	{
	}
};

FibMatrix Multiply(const FibMatrix m1,const FibMatrix m2)
{
	FibMatrix m3(1,1,1,0);
	m3.a = ((m1.a*m2.a)%mod+(m1.c*m2.b)%mod)%mod;
	m3.b = ((m1.b*m2.a)%mod+(m1.d*m2.b)%mod)%mod; 
	m3.c = ((m1.a*m2.c)%mod+(m1.c*m2.d)%mod)%mod;
	m3.d = ((m1.b*m2.c)%mod+(m1.d*m2.d)%mod)%mod;
	return m3;
}

FibMatrix Power(int n)
{
	FibMatrix m(1,1,1,0);
	if(n==1)
	{
		m=FibMatrix(1,1,1,0);
	}
	else if(n%2==0)
	{
		m=Power(n/2);
		m=Multiply(m,m);
	}
	else if(n%2==1)
	{
		m=Power((n-1)/2);
		m=Multiply(m,m);
		m=Multiply(m,FibMatrix(1,1,1,0));
	}
	return m;
}

long long Fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	FibMatrix m=Power(n-1);
	return m.a; 
}

int main()
{
	int n;
	while(cin>>n)
		cout<<Fib(n)<<endl;
}
