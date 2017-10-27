#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int n,m;
	int vec[1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>vec[i];
	}
	int l,r;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		for(;l<r;l++,r--)
			swap(vec[l],vec[r]);
	}
	cout<<vec[1];
	for(int i=2;i<=n;i++)
		cout<<" "<<vec[i];
	cout<<endl;
}
