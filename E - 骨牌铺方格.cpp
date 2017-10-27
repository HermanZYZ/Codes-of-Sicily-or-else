#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	long long arr[55]={0};
	arr[1]=1,arr[2]=2;
	for(int i=3;i<55;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	int n;
	while(cin>>n)
	{
		cout<<arr[n]<<endl;
	}
	return 0;
}
