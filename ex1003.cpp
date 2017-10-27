#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int arr[5005];
int main()
{
	int n,rank=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j]>arr[i])
			{
				rank++;
			}
		}
		cout<<rank<<endl;
		rank=1;
	}
	
	return 0;
} 
