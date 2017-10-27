#include<iostream>
#include<algorithm>

using namespace std;

int maxvet(int a,int b)
{
	int t;
	if(a==0 || b==0)
		return max(a,b);
	while(b)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
} 

int main()
{
	int n;
	while(cin>>n)
	{
		long long maxmul=1;
		while(n--)
		{
			int a;
			cin>>a;
			maxmul=a*maxmul/maxvet(a,maxmul);
		}
		cout<<maxmul<<endl;
	}
}
