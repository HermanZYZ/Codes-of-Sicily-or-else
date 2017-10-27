#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,a,b;
		cin>>n>>m;
		for(int i=0;i<m;i++)
			cin>>a>>b;
		cout<<n-1<<endl;
	}
}