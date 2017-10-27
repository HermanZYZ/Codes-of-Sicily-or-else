#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;
int arr1[1005],arr2[1005],arr3[1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr1[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>arr2[i];
	}
	for(int i=1;i<=n;i++)
	{
		arr3[i]=arr1[arr2[i]];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<arr3[i]<<endl;
	}
}
