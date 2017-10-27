#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	int arr[105];
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(abs(arr[i]) < abs(arr[j]))
				{
					swap(arr[i],arr[j]);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i==0)
				cout<<arr[i];
			else if(i==n-1)
				cout<<" "<<arr[i]<<endl;
			else
				cout<<" "<<arr[i];
		}
	}
	
	return 0;
}
