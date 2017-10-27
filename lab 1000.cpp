#include<iostream>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		double sum=0,ave=0;
		double arr[110];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		ave=sum/n;
		int tol=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>ave)
				tol++;
		}
		cout<<tol<<endl;
	}
}
