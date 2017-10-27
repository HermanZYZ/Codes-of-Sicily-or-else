#include<iostream>

using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a*b-a-b<<" "<<(a-1)*(b-1)/2<<endl;
	}
	return 0;
}
