#include<iostream>
using namespace std;
int arr[10005];
int main()
{
	int n;
	while(cin>>n)
	{
		int i=0;
		while(i<n)
		{
			int a;
			cin>>a;
			arr[i]=a;
			i++;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(arr[i]>arr[j])
				swap(arr[i],arr[j]);
			}
		}
		cout<<arr[n/2]<<endl;
	}
	return 0;
}
