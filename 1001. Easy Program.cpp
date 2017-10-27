#include<iostream>

using namespace std;
int arr[1005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int num;
	for(int i=0;i<m;i++)
	{
		cin>>num;
		cout<<arr[num]<<endl;
	}
}
