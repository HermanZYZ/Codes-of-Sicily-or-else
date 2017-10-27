#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
	int k;
	while(cin>>k && k)
	{
		int ahead=k,back=k;
		while(back && !isPrime(back))
			back--;
		while(!isPrime(ahead))
			ahead++;
		cout<<(back == 0 ? 0 :ahead - back)<<endl;
	}
}