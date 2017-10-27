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
	long long arr[60];
	arr[1]=3,arr[2]=6,arr[3]=6;
	for(int i=4;i<60;i++)
	{
		arr[i]=arr[i-1]+2*arr[i-2];
	}
	int n;
	while(cin>>n)
	{
		cout<<arr[n]<<endl;
	}
}
