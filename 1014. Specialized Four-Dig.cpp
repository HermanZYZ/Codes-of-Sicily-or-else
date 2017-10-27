#include <iostream>

using namespace std;

int Sum(int n,int base)
{
	int sum=0;
	while(n)
	{
		sum+=n%base;
		n/=base;
	}
	return sum;
}

int main()
{
	int n=1000;
	while(n<10000)
	{
		if(Sum(n,10)==Sum(n,12) && Sum(n,10)==Sum(n,16))
			cout<<n<<endl;
		n++;
	}
	return 0;
}