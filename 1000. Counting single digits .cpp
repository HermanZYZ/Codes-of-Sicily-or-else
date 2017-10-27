#include<iostream>
#include<string>
#include<cstdio> 
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[11];
		memset(arr,0,sizeof(arr));
		int num;
		while(n--)
		{
			cin>>num;
			arr[num]++;
		}
		for(int i=0;i<10;i++)
		{
			if(arr[i])
				cout<<i<<" "<<arr[i]<<endl;
		}
	}
}
