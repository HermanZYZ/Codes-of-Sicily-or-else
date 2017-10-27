#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<stack>
using namespace std;


int main()
{
	int n;
	int arr[105];
	while(cin>>n)
	{
		int min;
		for(int i=0;i<n;i++)
			arr[i]=0;
		if(n==0)
			break;
		else
		{
			int k=0;
			cin>>arr[0];
			min=arr[0];
			for(int i=1;i<n;i++)
			{
				cin>>arr[i];
				if(arr[i]<min)
				{
					min=arr[i];
					k=i;
				}
			}
			swap(arr[k],arr[0]);
			cout<<arr[0];
			for(int i=1;i<n;i++)
			{
				cout<<" "<<arr[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
