#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{ 
	return b ? gcd(b,a%b):a;
}

int main()
{
	int a,b,n;
	while(cin >> a >> b >> n)
	{
		int d = gcd(a,n);
		if(b % d == 0) 
			cout << d<<endl;
		else 
			cout << 0 << endl;
	}
}