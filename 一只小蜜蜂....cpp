#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n;
	long long arr[51]={0,1,2,3};
	for(int i=4;i<51;i++)
	arr[i]=arr[i-1]+arr[i-2];
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		cout<<arr[abs(b-a)]<<endl;
	}
	return 0;
}
