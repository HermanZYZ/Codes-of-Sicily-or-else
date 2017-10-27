#include<iostream>

using namespace std;
int main()
{
	long long s[100001];
	s[0]=1,s[1]=2;
	int i=2;
	while(i<=50)
	{
		s[i]=s[i-1]+s[i-2];
		i+=1;
	}
	int n,a,b,c;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		c = b - a;
		cout << s[c-1] << endl;
	}
	
	return 0;
}

