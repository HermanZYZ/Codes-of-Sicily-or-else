#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<stack>
#include <cstdlib> 
using namespace std;
int main()
{
	int arr[40][40];
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
			arr[i][j]=0;
	}
	for(int i=1;i<32;i++)
	{
		arr[i][1]=1;
		for(int j=2;j<=i;j++)
		{
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<arr[i][1];
			for(int j=2;j<=i;j++)
			{
				cout<<" "<<arr[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
