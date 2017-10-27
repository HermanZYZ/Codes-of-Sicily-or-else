#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int arr[45],t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			arr[i]=i+1;
		while(n--)
		{
			int tmp=arr[1];
			cout<<arr[0]<<" ";
			for(int i=2;i<=n;i++)
				arr[i-2]=arr[i];
			arr[n-1]=tmp;
		}
		cout<<endl;
	}
	return 0;
}
