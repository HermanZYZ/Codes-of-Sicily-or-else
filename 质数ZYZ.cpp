#include <iostream>
using namespace std;
int arr[10001];
int main()
{
	int n;
	cin>>n;
	int i,j=2,k=3;
	cout<<"2";
	for(i=3;i<=n;i++)
	{
		if(i%j!=0)
		arr[i]=i;
		if(i=n)
		{
			int number=3;
			for(k=number;k<=n;k++)
			{
				if(arr[k]!=0 && k!=n)
				{
					number++;
					break;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(arr[i]!=0)
		cout<<" "<<arr[i];
	}
} 
