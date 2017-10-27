#include<iostream>

using namespace std;

int main()
{
	int n;
	while(cin>>n && n)
	{
		long long temp[4];
		for(int i=0;i<n;i++)
		{
			cin>>temp[i];
		}
		long long max=temp[0];
		for(int i=1;i<n;i++)
		{
			if(temp[i]>max)
				max=temp[i];
		}
		cout<<max<<endl;
	}
} 
